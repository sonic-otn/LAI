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
 * @file    laiaps.h
 * @brief   This module defines the APS for the LAI
 */

#if !defined (__LAIAPS_H_)
#define __LAIAPS_H_

#include <laitypes.h>

/** @brief APS type */
typedef enum _lai_aps_type_t
{
    LAI_APS_TYPE_APS,
} lai_aps_type_t;

/** @brief APS force to port */
typedef enum _lai_aps_force_to_port_t
{
    LAI_APS_FORCE_TO_PORT_NONE,
    LAI_APS_FORCE_TO_PORT_PRIMARY,
    LAI_APS_FORCE_TO_PORT_SECONDARY,
} lai_aps_force_to_port_t;

/** @brief APS active path */
typedef enum _lai_aps_active_path_t
{
    LAI_APS_ACTIVE_PATH_PRIMARY,
    LAI_APS_ACTIVE_PATH_SECONDARY,

} lai_aps_active_path_t;

typedef enum _lai_olp_switch_reason_t
{
    LAI_OLP_SWITCH_REASON_AUTO_ABSOLUTE,
    LAI_OLP_SWITCH_REASON_AUTO_RELATIVE,
    LAI_OLP_SWITCH_REASON_MANUAL_CMD,
    LAI_OLP_SWITCH_REASON_FORCE_CMD,
    LAI_OLP_SWITCH_REASON_BUTTON_TRIGGER,

} lai_olp_switch_reason_t;

typedef enum _lai_olp_switch_operate_t
{
    LAI_OLP_SWITCH_OPERATE_PRIMARY_TO_SECONDARY,
    LAI_OLP_SWITCH_OPERATE_SECONDARY_TO_PRIMARY,

} lai_olp_switch_operate_t;

typedef enum _lai_olp_switch_interval_t
{
    LAI_OLP_SWITCH_INTERVAL_1MS,
    LAI_OLP_SWITCH_INTERVAL_2MS,
    LAI_OLP_SWITCH_INTERVAL_10MS,

} lai_olp_switch_interval_t;

typedef struct _lai_olp_switch_power_info_t
{
    lai_double_t common_out;
    lai_double_t primary_in;
    lai_double_t secondary_in;
} lai_olp_switch_power_info_t;

typedef struct _lai_olp_switch_info_t
{
    lai_uint16_t index;
    lai_olp_switch_reason_t reason;
    lai_olp_switch_operate_t operate;
    lai_uint64_t time_stamp;
    lai_olp_switch_power_info_t before[40];
    lai_olp_switch_power_info_t switching;
    lai_olp_switch_power_info_t after[40];
} lai_olp_switch_info_t;

typedef struct _lai_olp_switch_t
{
    lai_uint8_t num;
    lai_uint8_t type;
    lai_uint8_t interval;
    lai_uint16_t pointers;
    lai_uint8_t channel_id;
    lai_olp_switch_info_t info[10];
} lai_olp_switch_t;

/**
 * @brief APS report switch info notification
 *
 * @param[in] aps_id APS Id
 * @param[in] switch_info Switch info
 */
typedef void (*lai_aps_report_switch_info_fn)(
        _In_ lai_object_id_t aps_id,
        _In_ lai_olp_switch_t switch_info);

/**
 * @defgroup LAIAPS LAI - APS specific API definitions
 *
 * @{
 */

/**
 * @brief APS attribute IDs
 */
typedef enum _lai_aps_attr_t
{
    /**
     * @brief Start of attributes
     */
    LAI_APS_ATTR_START,

    /**
     * @brief ID
     *
     * @type lai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_APS_ATTR_ID = LAI_APS_ATTR_START,

    /**
     * @brief Empty
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_APS_ATTR_EMPTY,

    /**
     * @brief Removable
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_APS_ATTR_REMOVABLE,

    /**
     * @brief Serial no
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_APS_ATTR_SERIAL_NO,

    /**
     * @brief Equipment failure
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_APS_ATTR_EQUIPMENT_FAILURE,

    /**
     * @brief Equipment mismatch
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_APS_ATTR_EQUIPMENT_MISMATCH,

    /**
     * @brief Hardware version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_APS_ATTR_HARDWARE_VERSION,

    /**
     * @brief Admin state
     *
     * @type lai_admin_state_t
     * @flags READ_ONLY
     */
    LAI_APS_ATTR_ADMIN_STATE,

    /**
     * @brief Operational status
     *
     * @type lai_oper_status_t
     * @flags READ_ONLY
     */
    LAI_APS_ATTR_OPER_STATUS,

    /**
     * @brief Part no
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_APS_ATTR_PART_NO,

    /**
     * @brief Mfg name
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_APS_ATTR_MFG_NAME,

    /**
     * @brief Manufacture date
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_APS_ATTR_MFG_DATE,

    /**
     * @brief Software version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_APS_ATTR_SOFTWARE_VERSION,

    /**
     * @brief Firmware version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_APS_ATTR_FIRMWARE_VERSION,

    /**
     * @brief Type
     *
     * @type lai_aps_type_t
     * @flags CREATE_AND_SET
     */
    LAI_APS_ATTR_TYPE,

    /**
     * @brief Revertive
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    LAI_APS_ATTR_REVERTIVE,

    /**
     * @brief Wait to restore time
     *
     * @type lai_uint32_t
     * @flags CREATE_AND_SET
     */
    LAI_APS_ATTR_WAIT_TO_RESTORE_TIME,

    /**
     * @brief Hold off time
     *
     * @type lai_uint32_t
     * @flags CREATE_AND_SET
     */
    LAI_APS_ATTR_HOLD_OFF_TIME,

    /**
     * @brief Primary switch threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_APS_ATTR_PRIMARY_SWITCH_THRESHOLD,

    /**
     * @brief Primary switch hysteresis
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_APS_ATTR_PRIMARY_SWITCH_HYSTERESIS,

    /**
     * @brief Secondary switch threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_APS_ATTR_SECONDARY_SWITCH_THRESHOLD,

    /**
     * @brief Relative switch threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_APS_ATTR_RELATIVE_SWITCH_THRESHOLD,

    /**
     * @brief Relative switch threshold offset
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_APS_ATTR_RELATIVE_SWITCH_THRESHOLD_OFFSET,

    /**
     * @brief Force to port
     *
     * @type lai_aps_force_to_port_t
     * @flags CREATE_AND_SET
     */
    LAI_APS_ATTR_FORCE_TO_PORT,

    /**
     * @brief Active path
     *
     * @type lai_aps_active_path_t
     * @flags CREATE_AND_SET
     * @isrecoverable false
     */
    LAI_APS_ATTR_ACTIVE_PATH,

    /**
     * @brief Alarm hysteresis
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_APS_ATTR_ALARM_HYSTERESIS,

    /**
     * @brief Switch info notify
     *
     * @type lai_pointer_t lai_aps_report_switch_info_fn
     * @flags CREATE_ONLY
     * @default NULL
     */
    LAI_APS_ATTR_SWITCH_INFO_NOTIFY,

    /**
     * @brief Collect switch info
     *
     * @type bool
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_APS_ATTR_COLLECT_SWITCH_INFO,

    /**
     * @brief End of attributes
     */
    LAI_APS_ATTR_END,

    /** Custom range base value */
    LAI_APS_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    LAI_APS_ATTR_CUSTOM_RANGE_END

} lai_aps_attr_t;

/**
 * @brief APS stat IDs
 *
 * @flags Contains flags
 */
typedef enum _lai_aps_stat_t
{
    /**
     * @brief Start of statistics
     */
    LAI_APS_STAT_START,

    /**
     * @brief A placeholder
     *
     * @type lai_uint64_t
     */
    LAI_APS_STAT_NOT_USE = LAI_APS_STAT_START,

    /**
     * @brief End of statistics
     */
    LAI_APS_STAT_END,

} lai_aps_stat_t;

/**
 * @brief Create APS.
 *
 * Allocates and initializes a APS.
 *
 * @param[out] aps_id APS id
 * @param[in] linecard_id Linecard id on which the APS exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_create_aps_fn)(
        _Out_ lai_object_id_t *aps_id,
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Remove APS
 *
 * @param[in] aps_id APS id
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_remove_aps_fn)(
        _In_ lai_object_id_t aps_id);

/**
 * @brief Set APS attribute
 *
 * @param[in] aps_id APS id
 * @param[in] attr Attribute
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_set_aps_attribute_fn)(
        _In_ lai_object_id_t aps_id,
        _In_ const lai_attribute_t *attr);

/**
 * @brief Get APS attribute
 *
 * @param[in] aps_id APS id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_aps_attribute_fn)(
        _In_ lai_object_id_t aps_id,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

/**
 * @brief Get APS statistics.
 *
 * @param[in] aps_id APS id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_aps_stats_fn)(
        _In_ lai_object_id_t aps_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Get APS statistics extended.
 *
 * @param[in] aps_id APS id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_aps_stats_ext_fn)(
        _In_ lai_object_id_t aps_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _In_ lai_stats_mode_t mode,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Clear APS statistics counters.
 *
 * @param[in] aps_id APS id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_clear_aps_stats_fn)(
        _In_ lai_object_id_t aps_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with lai_api_query()
 */
typedef struct _lai_aps_api_t
{
    lai_create_aps_fn                create_aps;
    lai_remove_aps_fn                remove_aps;
    lai_set_aps_attribute_fn         set_aps_attribute;
    lai_get_aps_attribute_fn         get_aps_attribute;
    lai_get_aps_stats_fn             get_aps_stats;
    lai_get_aps_stats_ext_fn         get_aps_stats_ext;
    lai_clear_aps_stats_fn           clear_aps_stats;
} lai_aps_api_t;

/**
 * @}
 */
#endif /** __LAIAPS_H_ */
