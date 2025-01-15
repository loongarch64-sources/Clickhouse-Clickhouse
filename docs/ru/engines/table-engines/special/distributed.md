---
toc_priority: 33
toc_title: Distributed
---

# Distributed {#distributed}

**Движок Distributed не хранит данные самостоятельно**, а позволяет обрабатывать запросы распределённо, на нескольких серверах. Чтение автоматически распараллеливается. При чтении будут использованы индексы таблиц на удалённых серверах, если есть.

Движок Distributed принимает параметры: 

-   имя кластера в конфигурационном файле сервера

-   имя удалённой базы данных

-   имя удалённой таблицы

-   (не обязательно) ключ шардирования.

-   (не обязательно) имя политики, оно будет использоваться для хранения временных файлов для асинхронной отправки

    Смотрите также:

    -  настройка `insert_distributed_sync` 
    -   [MergeTree](../mergetree-family/mergetree.md#table_engine-mergetree-multiple-volumes) для примера

Пример:

``` sql
Distributed(logs, default, hits[, sharding_key[, policy_name]])
```

данные будут читаться со всех серверов кластера logs, из таблицы default.hits, расположенной на каждом сервере кластера.
Данные не только читаются, но и частично (настолько, насколько это возможно) обрабатываются на удалённых серверах.
Например, при запросе с GROUP BY, данные будут агрегированы на удалённых серверах, промежуточные состояния агрегатных функций будут отправлены на запросивший сервер; затем данные будут доагрегированы.

Вместо имени базы данных может использоваться константное выражение, возвращающее строку. Например, currentDatabase().

logs - имя кластера в конфигурационном файле сервера.

Кластеры задаются следующим образом:

``` xml
<remote_servers>
    <logs>
        <shard>
            <!-- Не обязательно. Вес шарда при записи данных. По умолчанию, 1. -->
            <weight>1</weight>
            <!-- Не обязательно. Записывать ли данные только на одну, любую из реплик. По умолчанию, false - записывать данные на все реплики. -->
            <internal_replication>false</internal_replication>
            <replica>
                <!-- Не обязательно. Приоритет реплики для балансировки нагрузки (смотрите также настройку load_balancing). По умолчанию : 1 (меньшее значение - больший приоритет). -->
                <priority>1</priority>
                <host>example01-01-1</host>
                <port>9000</port>
            </replica>
            <replica>
                <host>example01-01-2</host>
                <port>9000</port>
            </replica>
        </shard>
        <shard>
            <weight>2</weight>
            <internal_replication>false</internal_replication>
            <replica>
                <host>example01-02-1</host>
                <port>9000</port>
            </replica>
            <replica>
                <host>example01-02-2</host>
                <port>9000</port>
            </replica>
        </shard>
    </logs>
</remote_servers>
```

Здесь задан кластер с именем logs, состоящий из двух шардов, каждый из которых состоит из двух реплик.
Шардами называются серверы, содержащие разные части данных (чтобы прочитать все данные, нужно идти на все шарды).
Репликами называются дублирующие серверы (чтобы прочитать данные, можно идти за данными на любую из реплик).

Имя кластера не должно содержать точки.

В качестве параметров для каждого сервера указываются `host`, `port` и, не обязательно, `user`, `password`, `secure`, `compression`:
- `host` - адрес удалённого сервера. Может быть указан домен, или IPv4 или IPv6 адрес. В случае указания домена, при старте сервера делается DNS запрос, и результат запоминается на всё время работы сервера. Если DNS запрос неуспешен, то сервер не запускается. Если вы изменяете DNS-запись, перезапустите сервер.
- `port` - TCP-порт для межсерверного взаимодействия (в конфиге - tcp_port, обычно 9000). Не перепутайте с http_port.
- `user` - имя пользователя для соединения с удалённым сервером. по умолчанию - default. Этот пользователь должен иметь доступ для соединения с указанным сервером. Доступы настраиваются в файле users.xml, подробнее смотрите в разделе [Права доступа](../../../operations/access-rights.md).
- `password` - пароль для соединения с удалённым сервером, в открытом виде. по умолчанию - пустая строка.
- `secure` - Использовать шифрованное соединение ssl, Обычно используется с портом `port` = 9440. Сервер должен слушать порт `<tcp_port_secure>9440</tcp_port_secure>` с корректными настройками сертификатов.
- `compression` - Использовать сжатие данных. По умолчанию: true.

При указании реплик, для каждого из шардов, при чтении, будет выбрана одна из доступных реплик. Можно настроить алгоритм балансировки нагрузки (то есть, предпочтения, на какую из реплик идти) - см. настройку [load_balancing](../../../operations/settings/settings.md#settings-load_balancing).
Если соединение с сервером не установлено, то будет произведена попытка соединения с небольшим таймаутом. Если соединиться не удалось, то будет выбрана следующая реплика, и так для всех реплик. Если попытка соединения для всех реплик не удалась, то будут снова произведены попытки соединения по кругу, и так несколько раз.
Это работает в пользу отказоустойчивости, хотя и не обеспечивает полную отказоустойчивость: удалённый сервер может принять соединение, но не работать, или плохо работать.

Можно указать от одного шарда (в таком случае, обработку запроса стоит называть удалённой, а не распределённой) до произвольного количества шардов. В каждом шарде можно указать от одной до произвольного числа реплик. Можно указать разное число реплик для каждого шарда.

Вы можете прописать сколько угодно кластеров в конфигурации.

Для просмотра имеющихся кластеров, вы можете использовать системную таблицу system.clusters.

Движок Distributed позволяет работать с кластером, как с локальным сервером. При этом, кластер является неэластичным: вы должны прописать его конфигурацию в конфигурационный файл сервера (лучше всех серверов кластера).

Как видно, движок Distributed требует прописывания кластера в конфигурационный файл; кластера из конфигурационного файла обновляются налету, без перезапуска сервера. Если вам необходимо каждый раз отправлять запрос на неизвестный набор шардов и реплик, вы можете не создавать Distributed таблицу, а воспользоваться табличной функцией remote. Смотрите раздел [Табличные функции](../../../engines/table-engines/special/distributed.md).

Есть два способа записывать данные на кластер:

Во-первых, вы можете самостоятельно определять, на какие серверы какие данные записывать, и выполнять запись непосредственно на каждый шард. То есть, делать INSERT в те таблицы, на которые «смотрит» распределённая таблица. Это наиболее гибкое решение поскольку вы можете использовать любую схему шардирования, которая может быть нетривиальной из-за требований предметной области.
Также это является наиболее оптимальным решением, так как данные могут записываться на разные шарды полностью независимо.

Во-вторых, вы можете делать INSERT в Distributed таблицу. В этом случае, таблица будет сама распределять вставляемые данные по серверам. Для того, чтобы писать в Distributed таблицу, у неё должен быть задан ключ шардирования (последний параметр). Также, если шард всего-лишь один, то запись работает и без указания ключа шардирования (так как в этом случае он не имеет смысла).

У каждого шарда в конфигурационном файле может быть задан «вес» (weight). По умолчанию, вес равен единице. Данные будут распределяться по шардам в количестве, пропорциональном весу шарда. Например, если есть два шарда, и у первого выставлен вес 9, а у второго 10, то на первый будет отправляться 9 / 19 доля строк, а на второй - 10 / 19.

У каждого шарда в конфигурационном файле может быть указан параметр internal_replication.

Если он выставлен в true, то для записи будет выбираться первая живая реплика и данные будут писаться на неё. Этот вариант следует использовать, если Distributed таблица «смотрит» на реплицируемые таблицы. То есть, если таблица, в которую будут записаны данные, будет сама заниматься их репликацией.

Если он выставлен в false (по умолчанию), то данные будут записываться на все реплики. По сути, это означает, что Distributed таблица занимается репликацией данных самостоятельно. Это хуже, чем использование реплицируемых таблиц, так как не контролируется консистентность реплик, и они со временем будут содержать немного разные данные.

Для выбора шарда, на который отправляется строка данных, вычисляется выражение шардирования, и берётся его остаток от деления на суммарный вес шардов. Строка отправляется на шард, соответствующий полуинтервалу остатков от prev_weights до prev_weights + weight, где prev_weights - сумма весов шардов с меньшим номером, а weight - вес этого шарда. Например, если есть два шарда, и у первого выставлен вес 9, а у второго 10, то строка будет отправляться на первый шард для остатков из диапазона \[0, 9), а на второй - для остатков из диапазона \[9, 19).

Выражением шардирование может быть произвольное выражение от констант и столбцов таблицы, возвращающее целое число. Например, вы можете использовать выражение rand() для случайного распределения данных, или UserID - для распределения по остатку от деления идентификатора посетителя (тогда данные одного посетителя будут расположены на одном шарде, что упростит выполнение IN и JOIN по посетителям). Если распределение какого-либо столбца недостаточно равномерное, вы можете обернуть его в хэш функцию: intHash64(UserID).

Простой остаток от деления является довольно ограниченным решением для шардирования и подходит не для всех случаев. Он подходит для среднего и большого объёма данных (десятки серверов), но не для очень больших объёмов данных (сотни серверов и больше). В последнем случае, лучше использовать схему шардирования, продиктованную требованиями предметной области, и не использовать возможность записи в Distributed таблицы.

Запросы SELECT отправляются на все шарды, и работают независимо от того, каким образом данные распределены по шардам (они могут быть распределены полностью случайно). При добавлении нового шарда, можно не переносить на него старые данные, а записывать новые данные с большим весом - данные будут распределены слегка неравномерно, но запросы будут работать корректно и достаточно эффективно.

Беспокоиться о схеме шардирования имеет смысл в следующих случаях:
- используются запросы, требующие соединение данных (IN, JOIN) по определённому ключу - тогда если данные шардированы по этому ключу, то можно использовать локальные IN, JOIN вместо GLOBAL IN, GLOBAL JOIN, что кардинально более эффективно.
- используется большое количество серверов (сотни и больше) и большое количество маленьких запросов (запросы отдельных клиентов - сайтов, рекламодателей, партнёров) - тогда, для того, чтобы маленькие запросы не затрагивали весь кластер, имеет смысл располагать данные одного клиента на одном шарде, или (вариант, который используется в Яндекс.Метрике) сделать двухуровневое шардирование: разбить весь кластер на «слои», где слой может состоять из нескольких шардов; данные для одного клиента располагаются на одном слое, но в один слой можно по мере необходимости добавлять шарды, в рамках которых данные распределены произвольным образом; создаются распределённые таблицы на каждый слой и одна общая распределённая таблица для глобальных запросов.

Запись данных осуществляется полностью асинхронно. При вставке в таблицу, блок данных сначала записывается в файловую систему. Затем, в фоновом режиме отправляются на удалённые серверы при первой возможности. Период отправки регулируется настройками [distributed_directory_monitor_sleep_time_ms](../../../operations/settings/settings.md#distributed_directory_monitor_sleep_time_ms) и [distributed_directory_monitor_max_sleep_time_ms](../../../operations/settings/settings.md#distributed_directory_monitor_max_sleep_time_ms). Движок таблиц `Distributed` отправляет каждый файл со вставленными данными отдельно, но можно включить пакетную отправку данных настройкой [distributed_directory_monitor_batch_inserts](../../../operations/settings/settings.md#distributed_directory_monitor_batch_inserts). Эта настройка улучшает производительность кластера за счет более оптимального использования ресурсов сервера-отправителя и сети. Необходимо проверять, что данные отправлены успешно, для этого проверьте список файлов (данных, ожидающих отправки) в каталоге таблицы `/var/lib/clickhouse/data/database/table/`. Количество потоков для выполнения фоновых задач можно задать с помощью настройки [background_distributed_schedule_pool_size](../../../operations/settings/settings.md#background_distributed_schedule_pool_size).

Если после INSERT-а в Distributed таблицу, сервер перестал существовать или был грубо перезапущен (например, в следствие аппаратного сбоя), то записанные данные могут быть потеряны. Если в директории таблицы обнаружен повреждённый кусок данных, то он переносится в поддиректорию broken и больше не используется.

При выставлении опции max_parallel_replicas выполнение запроса распараллеливается по всем репликам внутри одного шарда. Подробнее смотрите раздел [max_parallel_replicas](../../../operations/settings/settings.md#settings-max_parallel_replicas).
