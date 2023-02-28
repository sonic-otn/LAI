/**
 * Copyright (c) 2021 Alibaba Group.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 * @file    laioa.h
 * @brief   This module defines the OA for the LAI
 */

#if !defined (__LAIOA_H_)
#define __LAIOA_H_

#include <laitypes.h>

/**
 * @defgroup LAIOA LAI - OA specific API definitions
 *
 * @{
 */

/** @brief OA type */
typedef enum _lai_oa_type_t
{
    LAI_OA_TYPE_EDFA,
    LAI_OA_TYPE_FORWARD_RAMAN,
    LAI_OA_TYPE_BACKWARD_RAMAN,
    LAI_OA_TYPE_HYBRID,
} lai_oa_type_t;

/** @brief OA gain range */
typedef enum _lai_oa_gain_range_t
{
    LAI_OA_GAIN_RANGE_LOW_GAIN_RANGE,
    LAI_OA_GAIN_RANGE_MID_GAIN_RANGE,
    LAI_OA_GAIN_RANGE_HIGH_GAIN_RANGE,
    LAI_OA_GAIN_RANGE_FIXED_GAIN_RANGE,
} lai_oa_gain_range_t;

/** @brief OA amp mode */
typedef enum _lai_oa_amp_mode_t
{
    LAI_OA_AMP_MODE_CONSTANT_POWER,
    LAI_OA_AMP_MODE_CONSTANT_GAIN,
    LAI_OA_AMP_MODE_DYNAMIC_GAIN,
} lai_oa_amp_mode_t;

/** @brief OA fiber type profile */
typedef enum _lai_oa_fiber_type_profile_t
{
    LAI_OA_FIBER_TYPE_PROFILE_DSF,
    LAI_OA_FIBER_TYPE_PROFILE_LEAF,
    LAI_OA_FIBER_TYPE_PROFILE_SSMF,
    LAI_OA_FIBER_TYPE_PROFILE_TWC,
    LAI_OA_FIBER_TYPE_PROFILE_TWRS,
} lai_oa_fiber_type_profile_t;

/** @brief OA working state */
typedef enum _lai_oa_working_state_t
{
    LAI_OA_WORKING_STATE_LOS_A,
    LAI_OA_WORKING_STATE_LOS_N,
} lai_oa_working_state_t;

/**
 * @brief OA attribute IDs
 */
typedef enum _lai_oa_attr_t
{
    /**
     * @brief Start of attributes
     */
    LAI_OA_ATTR_START,

    /**
     * @brief ID
     *
     * @type lai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_OA_ATTR_ID = LAI_OA_ATTR_START,

    /**
     * @brief Empty
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_EMPTY,

    /**
     * @brief Removable
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_REMOVABLE,

    /**
     * @brief Serial no
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_SERIAL_NO,

    /**
     * @brief Equipment failure
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_EQUIPMENT_FAILURE,

    /**
     * @brief Equipment mismatch
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_EQUIPMENT_MISMATCH,

    /**
     * @brief Hardware version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_HARDWARE_VERSION,

    /**
     * @brief Admin state
     *
     * @type lai_admin_state_t
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_ADMIN_STATE,

    /**
     * @brief Operational status
     *
     * @type lai_oper_status_t
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_OPER_STATUS,

    /**
     * @brief Part no
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_PART_NO,

    /**
     * @brief Mfg name
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_MFG_NAME,

    /**
     * @brief Manufacture date
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_MFG_DATE,

    /**
     * @brief Type
     *
     * @type lai_oa_type_t
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_TYPE,

    /**
     * @brief Software version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_SOFTWARE_VERSION,

    /**
     * @brief Firmware version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_FIRMWARE_VERSION,

    /**
     * @brief Target gain
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_TARGET_GAIN,

    /**
     * @brief Min gain
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_MIN_GAIN,

    /**
     * @brief Max gain
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_MAX_GAIN,

    /**
     * @brief Target gain tilt
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_TARGET_GAIN_TILT,

    /**
     * @brief Gain range
     *
     * @type lai_oa_gain_range_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_GAIN_RANGE,

    /**
     * @brief Amp mode
     *
     * @type lai_oa_amp_mode_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_AMP_MODE,

    /**
     * @brief Target output power
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_TARGET_OUTPUT_POWER,

    /**
     * @brief Max output power
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_MAX_OUTPUT_POWER,

    /**
     * @brief Enabled
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_ENABLED,

    /**
     * @brief Fiber type profile
     *
     * @type lai_oa_fiber_type_profile_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_FIBER_TYPE_PROFILE,

    /**
     * @brief Ingress port
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_INGRESS_PORT,

    /**
     * @brief Egress port
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_EGRESS_PORT,

    /**
     * @brief Working state
     *
     * @type lai_oa_working_state_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_WORKING_STATE,

    /**
     * @brief Input LOS threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_INPUT_LOS_THRESHOLD,

    /**
     * @brief Input LOS hysteresis
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_INPUT_LOS_HYSTERESIS,

    /**
     * @brief Output LOS threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_OUTPUT_LOS_THRESHOLD,

    /**
     * @brief Output LOS hysteresis
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_OUTPUT_LOS_HYSTERESIS,

    /**
     * @brief Gain low threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_GAIN_LOW_THRESHOLD,

    /**
     * @brief Gain low hysteresis
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_GAIN_LOW_HYSTERESIS,

    /**
     * @brief Input low threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_INPUT_LOW_THRESHOLD,

    /**
     * @brief Output low threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_OUTPUT_LOW_THRESHOLD,

    /**
     * @brief LOS ASE delay
     *
     * @type lai_int32_t
     * @flags CREATE_AND_SET
     */
    LAI_OA_ATTR_LOS_ASE_DELAY,

    /**
     * @brief Input offset primary-line rx
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_INPUT_OFFSET_LINEP_RX,

    /**
     * @brief Output offset primary-line tx
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_OUTPUT_OFFSET_LINEP_TX,

    /**
     * @brief Input offset secondary-line rx
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_INPUT_OFFSET_LINES_RX,

    /**
     * @brief Output offset secondary-line tx
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_OA_ATTR_OUTPUT_OFFSET_LINES_TX,

    /**
     * @brief End of attributes
     */
    LAI_OA_ATTR_END,

    /** Custom range base value */
    LAI_OA_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    LAI_OA_ATTR_CUSTOM_RANGE_END

} lai_oa_attr_t;

/**
 * @brief OA stat IDs
 *
 * @flags Contains flags
 */
typedef enum _lai_oa_stat_t
{
    /**
     * @brief Start of statistics
     */
    LAI_OA_STAT_START,

    /**
     * @brief Temperature
     *
     * @type lai_double_t
     * @precision precision1
     * @iscounter false
     */
    LAI_OA_STAT_TEMPERATURE = LAI_OA_STAT_START,

    /**
     * @brief Actual gain
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_OA_STAT_ACTUAL_GAIN,

    /**
     * @brief Actual gain tilt
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_OA_STAT_ACTUAL_GAIN_TILT,

    /**
     * @brief Input power total
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_OA_STAT_INPUT_POWER_TOTAL,

    /**
     * @brief Input power C band
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_OA_STAT_INPUT_POWER_C_BAND,

    /**
     * @brief Input power L band
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_OA_STAT_INPUT_POWER_L_BAND,

    /**
     * @brief Output power total
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_OA_STAT_OUTPUT_POWER_TOTAL,

    /**
     * @brief Output power C band
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_OA_STAT_OUTPUT_POWER_C_BAND,

    /**
     * @brief Output power L band
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_OA_STAT_OUTPUT_POWER_L_BAND,

    /**
     * @brief Laser bias current
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_OA_STAT_LASER_BIAS_CURRENT,

    /**
     * @brief Optical return loss
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_OA_STAT_OPTICAL_RETURN_LOSS,

    /**
     * @brief Laser temperature
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_OA_STAT_LASER_TEMPERATURE,

    /**
     * @brief Panel input power primary-line rx
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_OA_STAT_PANEL_INPUT_POWER_LINEP_RX,

    /**
     * @brief Panel output power primary-line tx
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_OA_STAT_PANEL_OUTPUT_POWER_LINEP_TX,

    /**
     * @brief Panel input power secondary-line rx
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_OA_STAT_PANEL_INPUT_POWER_LINES_RX,

    /**
     * @brief Panel output power secondary-line tx
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_OA_STAT_PANEL_OUTPUT_POWER_LINES_TX,

    /**
     * @brief Laser TEC current
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_OA_STAT_LASER_TEC_CURRENT,

    /**
     * @brief Ingress VOA attenuation
     *
     * @type lai_double_t
     * @unit dB
     * @precision precision2
     * @iscounter false
     */
    LAI_OA_STAT_INGRESS_VOA_ATTEN,

    /**
     * @brief End of statistics
     */
    LAI_OA_STAT_END,

} lai_oa_stat_t;

/**
 * @brief Create OA.
 *
 * Allocates and initializes a OA.
 *
 * @param[out] oa_id OA id
 * @param[in] linecard_id Linecard id on which the OA exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_create_oa_fn)(
        _Out_ lai_object_id_t *oa_id,
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Remove OA
 *
 * @param[in] oa_id OA id
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_remove_oa_fn)(
        _In_ lai_object_id_t oa_id);

/**
 * @brief Set OA attribute
 *
 * @param[in] oa_id OA id
 * @param[in] attr Attribute
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_set_oa_attribute_fn)(
        _In_ lai_object_id_t oa_id,
        _In_ const lai_attribute_t *attr);

/**
 * @brief Get OA attribute
 *
 * @param[in] oa_id OA id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_oa_attribute_fn)(
        _In_ lai_object_id_t oa_id,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

/**
 * @brief Get OA statistics.
 *
 * @param[in] oa_id OA id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_oa_stats_fn)(
        _In_ lai_object_id_t oa_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Get OA statistics extended.
 *
 * @param[in] oa_id OA id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_oa_stats_ext_fn)(
        _In_ lai_object_id_t oa_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _In_ lai_stats_mode_t mode,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Clear OA statistics counters.
 *
 * @param[in] oa_id OA id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_clear_oa_stats_fn)(
        _In_ lai_object_id_t oa_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with lai_api_query()
 */
typedef struct _lai_oa_api_t
{
    lai_create_oa_fn                create_oa;
    lai_remove_oa_fn                remove_oa;
    lai_set_oa_attribute_fn         set_oa_attribute;
    lai_get_oa_attribute_fn         get_oa_attribute;
    lai_get_oa_stats_fn             get_oa_stats;
    lai_get_oa_stats_ext_fn         get_oa_stats_ext;
    lai_clear_oa_stats_fn           clear_oa_stats;
} lai_oa_api_t;

/**
 * @}
 */
#endif /** __LAIOA_H_ */
