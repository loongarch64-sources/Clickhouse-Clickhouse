﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/location/LocationService_EXPORTS.h>
#include <aws/location/LocationServiceRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/location/model/PricingPlan.h>
#include <utility>

namespace Aws
{
namespace LocationService
{
namespace Model
{

  /**
   */
  class AWS_LOCATIONSERVICE_API CreateTrackerRequest : public LocationServiceRequest
  {
  public:
    CreateTrackerRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "CreateTracker"; }

    Aws::String SerializePayload() const override;


    /**
     * <p>An optional description for the tracker resource.</p>
     */
    inline const Aws::String& GetDescription() const{ return m_description; }

    /**
     * <p>An optional description for the tracker resource.</p>
     */
    inline bool DescriptionHasBeenSet() const { return m_descriptionHasBeenSet; }

    /**
     * <p>An optional description for the tracker resource.</p>
     */
    inline void SetDescription(const Aws::String& value) { m_descriptionHasBeenSet = true; m_description = value; }

    /**
     * <p>An optional description for the tracker resource.</p>
     */
    inline void SetDescription(Aws::String&& value) { m_descriptionHasBeenSet = true; m_description = std::move(value); }

    /**
     * <p>An optional description for the tracker resource.</p>
     */
    inline void SetDescription(const char* value) { m_descriptionHasBeenSet = true; m_description.assign(value); }

    /**
     * <p>An optional description for the tracker resource.</p>
     */
    inline CreateTrackerRequest& WithDescription(const Aws::String& value) { SetDescription(value); return *this;}

    /**
     * <p>An optional description for the tracker resource.</p>
     */
    inline CreateTrackerRequest& WithDescription(Aws::String&& value) { SetDescription(std::move(value)); return *this;}

    /**
     * <p>An optional description for the tracker resource.</p>
     */
    inline CreateTrackerRequest& WithDescription(const char* value) { SetDescription(value); return *this;}


    /**
     * <p>Specifies the pricing plan for your tracker resource. There's three pricing
     * plan options:</p> <ul> <li> <p> <code>RequestBasedUsage</code> — Selects the
     * "Request-Based Usage" pricing plan.</p> </li> <li> <p>
     * <code>MobileAssetTracking</code> — Selects the "Mobile Asset Tracking" pricing
     * plan.</p> </li> <li> <p> <code>MobileAssetManagement</code> — Selects the
     * "Mobile Asset Management" pricing plan.</p> </li> </ul> <p>For additional
     * details and restrictions on each pricing plan option, see the <a
     * href="https://aws.amazon.com/location/pricing/">Amazon Location Service pricing
     * page</a>.</p>
     */
    inline const PricingPlan& GetPricingPlan() const{ return m_pricingPlan; }

    /**
     * <p>Specifies the pricing plan for your tracker resource. There's three pricing
     * plan options:</p> <ul> <li> <p> <code>RequestBasedUsage</code> — Selects the
     * "Request-Based Usage" pricing plan.</p> </li> <li> <p>
     * <code>MobileAssetTracking</code> — Selects the "Mobile Asset Tracking" pricing
     * plan.</p> </li> <li> <p> <code>MobileAssetManagement</code> — Selects the
     * "Mobile Asset Management" pricing plan.</p> </li> </ul> <p>For additional
     * details and restrictions on each pricing plan option, see the <a
     * href="https://aws.amazon.com/location/pricing/">Amazon Location Service pricing
     * page</a>.</p>
     */
    inline bool PricingPlanHasBeenSet() const { return m_pricingPlanHasBeenSet; }

    /**
     * <p>Specifies the pricing plan for your tracker resource. There's three pricing
     * plan options:</p> <ul> <li> <p> <code>RequestBasedUsage</code> — Selects the
     * "Request-Based Usage" pricing plan.</p> </li> <li> <p>
     * <code>MobileAssetTracking</code> — Selects the "Mobile Asset Tracking" pricing
     * plan.</p> </li> <li> <p> <code>MobileAssetManagement</code> — Selects the
     * "Mobile Asset Management" pricing plan.</p> </li> </ul> <p>For additional
     * details and restrictions on each pricing plan option, see the <a
     * href="https://aws.amazon.com/location/pricing/">Amazon Location Service pricing
     * page</a>.</p>
     */
    inline void SetPricingPlan(const PricingPlan& value) { m_pricingPlanHasBeenSet = true; m_pricingPlan = value; }

    /**
     * <p>Specifies the pricing plan for your tracker resource. There's three pricing
     * plan options:</p> <ul> <li> <p> <code>RequestBasedUsage</code> — Selects the
     * "Request-Based Usage" pricing plan.</p> </li> <li> <p>
     * <code>MobileAssetTracking</code> — Selects the "Mobile Asset Tracking" pricing
     * plan.</p> </li> <li> <p> <code>MobileAssetManagement</code> — Selects the
     * "Mobile Asset Management" pricing plan.</p> </li> </ul> <p>For additional
     * details and restrictions on each pricing plan option, see the <a
     * href="https://aws.amazon.com/location/pricing/">Amazon Location Service pricing
     * page</a>.</p>
     */
    inline void SetPricingPlan(PricingPlan&& value) { m_pricingPlanHasBeenSet = true; m_pricingPlan = std::move(value); }

    /**
     * <p>Specifies the pricing plan for your tracker resource. There's three pricing
     * plan options:</p> <ul> <li> <p> <code>RequestBasedUsage</code> — Selects the
     * "Request-Based Usage" pricing plan.</p> </li> <li> <p>
     * <code>MobileAssetTracking</code> — Selects the "Mobile Asset Tracking" pricing
     * plan.</p> </li> <li> <p> <code>MobileAssetManagement</code> — Selects the
     * "Mobile Asset Management" pricing plan.</p> </li> </ul> <p>For additional
     * details and restrictions on each pricing plan option, see the <a
     * href="https://aws.amazon.com/location/pricing/">Amazon Location Service pricing
     * page</a>.</p>
     */
    inline CreateTrackerRequest& WithPricingPlan(const PricingPlan& value) { SetPricingPlan(value); return *this;}

    /**
     * <p>Specifies the pricing plan for your tracker resource. There's three pricing
     * plan options:</p> <ul> <li> <p> <code>RequestBasedUsage</code> — Selects the
     * "Request-Based Usage" pricing plan.</p> </li> <li> <p>
     * <code>MobileAssetTracking</code> — Selects the "Mobile Asset Tracking" pricing
     * plan.</p> </li> <li> <p> <code>MobileAssetManagement</code> — Selects the
     * "Mobile Asset Management" pricing plan.</p> </li> </ul> <p>For additional
     * details and restrictions on each pricing plan option, see the <a
     * href="https://aws.amazon.com/location/pricing/">Amazon Location Service pricing
     * page</a>.</p>
     */
    inline CreateTrackerRequest& WithPricingPlan(PricingPlan&& value) { SetPricingPlan(std::move(value)); return *this;}


    /**
     * <p>The name for the tracker resource.</p> <p>Requirements:</p> <ul> <li>
     * <p>Contain only alphanumeric characters (A-Z, a-z, 0-9) , hyphens (-) and
     * underscores (_).</p> </li> <li> <p>Must be a unique tracker resource name.</p>
     * </li> <li> <p>No spaces allowed. For example, <code>ExampleTracker</code>.</p>
     * </li> </ul>
     */
    inline const Aws::String& GetTrackerName() const{ return m_trackerName; }

    /**
     * <p>The name for the tracker resource.</p> <p>Requirements:</p> <ul> <li>
     * <p>Contain only alphanumeric characters (A-Z, a-z, 0-9) , hyphens (-) and
     * underscores (_).</p> </li> <li> <p>Must be a unique tracker resource name.</p>
     * </li> <li> <p>No spaces allowed. For example, <code>ExampleTracker</code>.</p>
     * </li> </ul>
     */
    inline bool TrackerNameHasBeenSet() const { return m_trackerNameHasBeenSet; }

    /**
     * <p>The name for the tracker resource.</p> <p>Requirements:</p> <ul> <li>
     * <p>Contain only alphanumeric characters (A-Z, a-z, 0-9) , hyphens (-) and
     * underscores (_).</p> </li> <li> <p>Must be a unique tracker resource name.</p>
     * </li> <li> <p>No spaces allowed. For example, <code>ExampleTracker</code>.</p>
     * </li> </ul>
     */
    inline void SetTrackerName(const Aws::String& value) { m_trackerNameHasBeenSet = true; m_trackerName = value; }

    /**
     * <p>The name for the tracker resource.</p> <p>Requirements:</p> <ul> <li>
     * <p>Contain only alphanumeric characters (A-Z, a-z, 0-9) , hyphens (-) and
     * underscores (_).</p> </li> <li> <p>Must be a unique tracker resource name.</p>
     * </li> <li> <p>No spaces allowed. For example, <code>ExampleTracker</code>.</p>
     * </li> </ul>
     */
    inline void SetTrackerName(Aws::String&& value) { m_trackerNameHasBeenSet = true; m_trackerName = std::move(value); }

    /**
     * <p>The name for the tracker resource.</p> <p>Requirements:</p> <ul> <li>
     * <p>Contain only alphanumeric characters (A-Z, a-z, 0-9) , hyphens (-) and
     * underscores (_).</p> </li> <li> <p>Must be a unique tracker resource name.</p>
     * </li> <li> <p>No spaces allowed. For example, <code>ExampleTracker</code>.</p>
     * </li> </ul>
     */
    inline void SetTrackerName(const char* value) { m_trackerNameHasBeenSet = true; m_trackerName.assign(value); }

    /**
     * <p>The name for the tracker resource.</p> <p>Requirements:</p> <ul> <li>
     * <p>Contain only alphanumeric characters (A-Z, a-z, 0-9) , hyphens (-) and
     * underscores (_).</p> </li> <li> <p>Must be a unique tracker resource name.</p>
     * </li> <li> <p>No spaces allowed. For example, <code>ExampleTracker</code>.</p>
     * </li> </ul>
     */
    inline CreateTrackerRequest& WithTrackerName(const Aws::String& value) { SetTrackerName(value); return *this;}

    /**
     * <p>The name for the tracker resource.</p> <p>Requirements:</p> <ul> <li>
     * <p>Contain only alphanumeric characters (A-Z, a-z, 0-9) , hyphens (-) and
     * underscores (_).</p> </li> <li> <p>Must be a unique tracker resource name.</p>
     * </li> <li> <p>No spaces allowed. For example, <code>ExampleTracker</code>.</p>
     * </li> </ul>
     */
    inline CreateTrackerRequest& WithTrackerName(Aws::String&& value) { SetTrackerName(std::move(value)); return *this;}

    /**
     * <p>The name for the tracker resource.</p> <p>Requirements:</p> <ul> <li>
     * <p>Contain only alphanumeric characters (A-Z, a-z, 0-9) , hyphens (-) and
     * underscores (_).</p> </li> <li> <p>Must be a unique tracker resource name.</p>
     * </li> <li> <p>No spaces allowed. For example, <code>ExampleTracker</code>.</p>
     * </li> </ul>
     */
    inline CreateTrackerRequest& WithTrackerName(const char* value) { SetTrackerName(value); return *this;}

  private:

    Aws::String m_description;
    bool m_descriptionHasBeenSet;

    PricingPlan m_pricingPlan;
    bool m_pricingPlanHasBeenSet;

    Aws::String m_trackerName;
    bool m_trackerNameHasBeenSet;
  };

} // namespace Model
} // namespace LocationService
} // namespace Aws
