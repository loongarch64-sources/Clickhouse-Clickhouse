﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/robomaker/RoboMaker_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace RoboMaker
{
namespace Model
{

  /**
   * <p>Configuration information for a world.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/robomaker-2018-06-29/WorldConfig">AWS
   * API Reference</a></p>
   */
  class AWS_ROBOMAKER_API WorldConfig
  {
  public:
    WorldConfig();
    WorldConfig(Aws::Utils::Json::JsonView jsonValue);
    WorldConfig& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The world generated by Simulation WorldForge.</p>
     */
    inline const Aws::String& GetWorld() const{ return m_world; }

    /**
     * <p>The world generated by Simulation WorldForge.</p>
     */
    inline bool WorldHasBeenSet() const { return m_worldHasBeenSet; }

    /**
     * <p>The world generated by Simulation WorldForge.</p>
     */
    inline void SetWorld(const Aws::String& value) { m_worldHasBeenSet = true; m_world = value; }

    /**
     * <p>The world generated by Simulation WorldForge.</p>
     */
    inline void SetWorld(Aws::String&& value) { m_worldHasBeenSet = true; m_world = std::move(value); }

    /**
     * <p>The world generated by Simulation WorldForge.</p>
     */
    inline void SetWorld(const char* value) { m_worldHasBeenSet = true; m_world.assign(value); }

    /**
     * <p>The world generated by Simulation WorldForge.</p>
     */
    inline WorldConfig& WithWorld(const Aws::String& value) { SetWorld(value); return *this;}

    /**
     * <p>The world generated by Simulation WorldForge.</p>
     */
    inline WorldConfig& WithWorld(Aws::String&& value) { SetWorld(std::move(value)); return *this;}

    /**
     * <p>The world generated by Simulation WorldForge.</p>
     */
    inline WorldConfig& WithWorld(const char* value) { SetWorld(value); return *this;}

  private:

    Aws::String m_world;
    bool m_worldHasBeenSet;
  };

} // namespace Model
} // namespace RoboMaker
} // namespace Aws