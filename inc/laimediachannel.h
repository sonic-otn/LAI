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
 * @file    laimediachannel.h
 * @brief   This module defines the media channel for the LAI
 */

#if !defined (__LAIMEDIACHANNEL_H_)
#define __LAIMEDIACHANNEL_H_

#include <laitypes.h>

/**
 * @defgroup LAIMEDIACHANNEL LAI - media channel specific API definitions
 *
 * @{
 */

/**
 * @brief The attenuation control modes on a media channel.
 */
typedef enum _lai_mediachannel_attenuation_control_mode_t
{
    LAI_MEDIACHANNEL_ATTENUATION_CONTROL_MODE_ATTENUATION_FIXED_LOSS,
    LAI_MEDIACHANNEL_ATTENUATION_CONTROL_MODE_ATTENUATION_DYNAMIC_LOSS,
    LAI_MEDIACHANNEL_ATTENUATION_CONTROL_MODE_ATTENUATION_DYNAMIC_LOSS_DAMPED,
    LAI_MEDIACHANNEL_ATTENUATION_CONTROL_MODE_MAX,
} lai_mediachannel_attenuation_control_mode_t;

/**
 * @brief Media channel attribute IDs
 */
typedef enum _lai_mediachannel_attr_t
{
    /**
     * @brief Start of attributes
     */
    LAI_MEDIACHANNEL_ATTR_START,

    /**
     * @brief ID
     *
     * @type lai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_MEDIACHANNEL_ATTR_ID = LAI_MEDIACHANNEL_ATTR_START,

    /**
     * @brief Lower frequency
     *
     * @type lai_uint64_t
     * @flags CREATE_AND_SET
     */
    LAI_MEDIACHANNEL_ATTR_LOWER_FREQUENCY,

    /**
     * @brief Upper frequency
     *
     * @type lai_uint64_t
     * @flags CREATE_AND_SET
     */
    LAI_MEDIACHANNEL_ATTR_UPPER_FREQUENCY,

    /**
     * @brief Admin status
     *
     * @type lai_admin_status_t
     * @flags CREATE_AND_SET
     */
    LAI_MEDIACHANNEL_ATTR_ADMIN_STATUS,

    /**
     * @brief Super channel
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    LAI_MEDIACHANNEL_ATTR_SUPER_CHANNEL,

    /**
     * @brief Super channel parent
     *
     * @type lai_uint32_t
     * @flags CREATE_AND_SET
     */
    LAI_MEDIACHANNEL_ATTR_SUPER_CHANNEL_PARENT,

    /**
     * @brief Attenuation control mode
     *
     * @type lai_mediachannel_attenuation_control_mode_t
     * @flags CREATE_AND_SET
     */
    LAI_MEDIACHANNEL_ATTR_ATTENUATION_CONTROL_MODE,

    /**
     * @brief Source port name
     *
     * @type char
     * @flags CREATE_AND_SET
     */
    LAI_MEDIACHANNEL_ATTR_SOURCE_PORT_NAME,

    /**
     * @brief Destination port name
     *
     * @type char
     * @flags CREATE_AND_SET
     */
    LAI_MEDIACHANNEL_ATTR_DEST_PORT_NAME,

    /**
     * @brief Operational state
     *
     * @type lai_oper_status_t
     * @flags READ_ONLY
     */
    LAI_MEDIACHANNEL_ATTR_OPER_STATUS,

    /**
     * @brief Attenuation value
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_MEDIACHANNEL_ATTR_ATTENUATION_VALUE,

    /**
     * @brief Wait to restore time
     *
     * @type lai_uint32_t
     * @flags CREATE_AND_SET
     */
    LAI_MEDIACHANNEL_ATTR_WAIT_TO_RESTORE_TIME,

    /**
     * @brief Target power
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_MEDIACHANNEL_ATTR_TARGET_POWER,

    /**
     * @brief End of attributes
     */
    LAI_MEDIACHANNEL_ATTR_END,

    /** Custom range base value */
    LAI_MEDIACHANNEL_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    LAI_MEDIACHANNEL_ATTR_CUSTOM_RANGE_END

} lai_mediachannel_attr_t;

/**
 * @brief Media channel stat IDs
 *
 * @flags Contains flags
 */
typedef enum _lai_mediachannel_stat_t
{
    /**
     * @brief Start of statistics
     */
    LAI_MEDIACHANNEL_STAT_START,

    /**
     * @brief Actual attenuation
     *
     * @type lai_double_t
     * @unit dB
     * @precision precision2
     * @iscounter false
     */
    LAI_MEDIACHANNEL_STAT_ACTUAL_ATTENUATION = LAI_ATTENUATOR_STAT_START,

    /**
     * @brief Input power
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_MEDIACHANNEL_STAT_INPUT_POWER,

    /**
     * @brief Output power
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_MEDIACHANNEL_STAT_OUTPUT_POWER,

    /**
     * @brief End of statistics
     */
    LAI_MEDIACHANNEL_STAT_END,

} lai_mediachannel_stat_t;

/**
 * @brief Create media channel.
 *
 * Allocates and initializes a media channel.
 *
 * @param[out] mediachannel_id Media channel id
 * @param[in] linecard_id Linecard id on which the media channel exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_create_mediachannel_fn)(
        _Out_ lai_object_id_t *mediachannel_id,
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Remove media channel
 *
 * @param[in] mediachannel_id Media channel id
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_remove_mediachannel_fn)(
        _In_ lai_object_id_t mediachannel_id);

/**
 * @brief Set media channel attribute
 *
 * @param[in] mediachannel_id Media channel id
 * @param[in] attr Attribute
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_set_mediachannel_attribute_fn)(
        _In_ lai_object_id_t mediachannel_id,
        _In_ const lai_attribute_t *attr);

/**
 * @brief Get media channel attribute
 *
 * @param[in] mediachannel_id Media channel id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_mediachannel_attribute_fn)(
        _In_ lai_object_id_t mediachannel_id,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

/**
 * @brief Get media channel statistics.
 *
 * @param[in] mediachannel_id Media channel id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_mediachannel_stats_fn)(
        _In_ lai_object_id_t mediachannel_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Get media channel statistics extended.
 *
 * @param[in] mediachannel_id Media channel id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_mediachannel_stats_ext_fn)(
        _In_ lai_object_id_t mediachannel_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _In_ lai_stats_mode_t mode,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Clear media channel statistics counters.
 *
 * @param[in] mediachannel_id Media channel id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_clear_mediachannel_stats_fn)(
        _In_ lai_object_id_t mediachannel_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with lai_api_query()
 */
typedef struct _lai_mediachannel_api_t
{
    lai_create_mediachannel_fn                create_mediachannel;
    lai_remove_mediachannel_fn                remove_mediachannel;
    lai_set_mediachannel_attribute_fn         set_mediachannel_attribute;
    lai_get_mediachannel_attribute_fn         get_mediachannel_attribute;
    lai_get_mediachannel_stats_fn             get_mediachannel_stats;
    lai_get_mediachannel_stats_ext_fn         get_mediachannel_stats_ext;
    lai_clear_mediachannel_stats_fn           clear_mediachannel_stats;
} lai_mediachannel_api_t;

/**
 * @}
 */
#endif /** __LAIMEDIACHANNEL_H_ */
