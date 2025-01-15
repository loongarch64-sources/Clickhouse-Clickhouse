---
toc_priority: 40
toc_title: "Настройка внешнего словаря"
---

# Настройка внешнего словаря {#dicts-external-dicts-dict}

XML-конфигурация словаря имеет следующую структуру:

``` xml
<dictionary>
    <name>dict_name</name>

    <structure>
      <!-- Complex key configuration -->
    </structure>

    <source>
      <!-- Source configuration -->
    </source>

    <layout>
      <!-- Memory layout configuration -->
    </layout>

    <lifetime>
      <!-- Lifetime of dictionary in memory -->
    </lifetime>
</dictionary>
```

Соответствующий [DDL-запрос](../../statements/create/dictionary.md#create-dictionary-query) имеет следующий вид:

``` sql
CREATE DICTIONARY dict_name
(
    ... -- attributes
)
PRIMARY KEY ... -- complex or single key configuration
SOURCE(...) -- Source configuration
LAYOUT(...) -- Memory layout configuration
LIFETIME(...) -- Lifetime of dictionary in memory
```

-   `name` — Идентификатор, под которым словарь будет доступен для использования. Используйте символы `[a-zA-Z0-9_\-]`.
-   [source](external-dicts-dict-sources.md) — Источник словаря.
-   [layout](external-dicts-dict-layout.md) — Размещение словаря в памяти.
-   [structure](external-dicts-dict-structure.md) — Структура словаря. Ключ и атрибуты, которые можно получить по ключу.
-   [lifetime](external-dicts-dict-lifetime.md) — Периодичность обновления словарей.
