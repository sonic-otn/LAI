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
 * @file    lailinecard.h
 *
 * @brief   This module defines LAI Linecard interface
 */

#if !defined (__LAILINECARD_H_)
#define __LAILINECARD_H_

#include <laitypes.h>

/**
 * @defgroup LAILINECARD LAI - Linecard specific API definitions
 *
 * @{
 */

/**
 * @brief Maximum Number of Linecards
 */
#define LAI_MAX_LINECARDS                         8

/**
 * @brief Maximum Hardware ID Length
 */
#define LAI_MAX_HARDWARE_ID_LEN                 255

/**
 * @brief Attribute data for #LAI_LINECARD_ATTR_LINECARD_TYPE
 */
typedef enum _lai_linecard_type_t
{
    LAI_LINECARD_TYPE_T340CE,
    LAI_LINECARD_TYPE_P230C,
    LAI_LINECARD_TYPE_E100C,
    LAI_LINECARD_TYPE_E110C,
    LAI_LINECARD_TYPE_E120C,
    LAI_LINECARD_TYPE_OA2325,
    LAI_LINECARD_TYPE_OA2335,
    LAI_LINECARD_TYPE_OCM8,
    LAI_LINECARD_TYPE_OTDR8,

} lai_linecard_type_t;

/**
 * @brief The board mode of the linecard
 */
typedef enum _lai_linecard_board_mode_t
{
    LAI_LINECARD_BOARD_MODE_LA_400G_CA_200GE,
    LAI_LINECARD_BOARD_MODE_L1_400G_CA_100GE,
    LAI_LINECARD_BOARD_MODE_L2_400G_CA_100GE,
    LAI_LINECARD_BOARD_MODE_LA_400G_RELAY,
    LAI_LINECARD_BOARD_MODE_LA_400G_SNCP_CA_100GE,
    LAI_LINECARD_BOARD_MODE_LA_400G_SNCP_C12_200GE,
    LAI_LINECARD_BOARD_MODE_LA_400G_SNCP_C34_200GE,
    LAI_LINECARD_BOARD_MODE_LA_200G_CA_100GE_QPSK,
    LAI_LINECARD_BOARD_MODE_MAX,
} lai_linecard_board_mode_t;

/**
 * @brief Power admin state of the linecard
 */
typedef enum _lai_linecard_power_admin_state_t
{
    LAI_LINECARD_POWER_ADMIN_STATE_ENABLED,
    LAI_LINECARD_POWER_ADMIN_STATE_DISABLED,
    LAI_LINECARD_POWER_ADMIN_STATE_MAX,
} lai_linecard_power_admin_state_t;

/**
 * @brief The reset type of the linecard
 */
typedef enum _lai_linecard_reset_t
{
    LAI_LINECARD_RESET_WARM,
    LAI_LINECARD_RESET_COLD,
    LAI_LINECARD_RESET_FORCE,
    LAI_LINECARD_RESET_MAX,
} lai_linecard_reset_t;

/**
 * @brief Linecard upgrade state
 */
typedef enum _lai_linecard_upgrade_state_t
{
    LAI_LINECARD_UPGRADE_STATE_IDLE,
    LAI_LINECARD_UPGRADE_STATE_DOWNLOADING,
    LAI_LINECARD_UPGRADE_STATE_DOWNLOAD_FINISH,
    LAI_LINECARD_UPGRADE_STATE_COMMITING,
    LAI_LINECARD_UPGRADE_STATE_COMMIT_FINISH,
    LAI_LINECARD_UPGRADE_STATE_REBOOTING,
    LAI_LINECARD_UPGRADE_STATE_COMMIT_PAUSE,
    LAI_LINECARD_UPGRADE_STATE_ROLLBACKING,
    LAI_LINECARD_UPGRADE_STATE_COMMIT_ERROR,
    LAI_LINECARD_UPGRADE_STATE_REBOOT_ERROR,
    LAI_LINECARD_UPGRADE_STATE_COMMIT_STOP,
    LAI_LINECARD_UPGRADE_STATE_MAX,

} lai_linecard_upgrade_state_t;

/**
 * @brief Linecard baud rate
 */
typedef enum _lai_linecard_baud_rate_t
{
    LAI_LINECARD_BAUD_RATE_9600,
    LAI_LINECARD_BAUD_RATE_19200,
    LAI_LINECARD_BAUD_RATE_38400,
    LAI_LINECARD_BAUD_RATE_57600,
    LAI_LINECARD_BAUD_RATE_115200,
} lai_linecard_baud_rate_t;

/**
 * @brief Linecard operational state change notification
 *
 * @param[in] linecard_id Linecard Id
 * @param[in] linecard_oper_status New linecard operational state
 */
typedef void (*lai_linecard_state_change_notification_fn)(
        _In_ lai_object_id_t linecard_id,
        _In_ lai_oper_status_t linecard_oper_status);

/**
 * @brief Linecard alarm notification
 *
 * @param[in] linecard_id Linecard Id
 * @param[in] alarm_type Alarm type
 * @param[in] alarm_info Alarm info
 */
typedef void (*lai_linecard_alarm_notification_fn)(
        _In_ lai_object_id_t linecard_id,
        _In_ lai_alarm_type_t alarm_type,
        _In_ lai_alarm_info_t alarm_info);

/**
 * @brief Attribute Id in lai_set_linecard_attribute() and
 *        lai_get_linecard_attribute() calls.
 */
typedef enum _lai_linecard_attr_t
{
    /**
     * @brief Start of attributes
     */
    LAI_LINECARD_ATTR_START,

    /**
     * @brief Linecard type
     *
     * @type lai_linecard_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_AND_SET
     * @default empty
     */
    LAI_LINECARD_ATTR_LINECARD_TYPE = LAI_LINECARD_ATTR_START,

    /**
     * @brief The admin state of the linecard
     *
     * @type lai_admin_state_t
     * @flags CREATE_AND_SET
     */
    LAI_LINECARD_ATTR_ADMIN_STATE,

    /**
     * @brief The board mode of the linecard
     *
     * @type lai_linecard_board_mode_t
     * @flags CREATE_AND_SET
     */
    LAI_LINECARD_ATTR_BOARD_MODE,

    /**
     * @brief The operational state of the linecard
     *
     * @type lai_oper_status_t
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_OPER_STATUS,

    /**
     * @brief Relay
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    LAI_LINECARD_ATTR_RELAY,

    /**
     * @brief Whether the linecard is present or not
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_EMPTY,

    /**
     * @brief Whether the linecard is removable
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_REMOVABLE,

    /**
     * @brief The reset type of the linecard
     *
     * @type lai_linecard_reset_t
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_RESET,

    /**
     * @brief The power admin state of the linecard
     *
     * @type lai_linecard_power_admin_state_t
     * @flags CREATE_AND_SET
     */
    LAI_LINECARD_ATTR_POWER_ADMIN_STATE,

    /**
     * @brief Host name
     *
     * @type char
     * @flags CREATE_AND_SET
     */
    LAI_LINECARD_ATTR_HOSTNAME,

    /**
     * @brief Serial number
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_SERIAL_NO,

    /**
     * @brief Part number
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_PART_NO,

    /**
     * @brief Hardware version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_HARDWARE_VERSION,

    /**
     * @brief Software version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_SOFTWARE_VERSION,

    /**
     * @brief CPLD version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_CPLD_VERSION,

    /**
     * @brief Script version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_SCRIPT_VERSION,

    /**
     * @brief Manufacture date
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_MFG_DATE,

    /**
     * @brief Manufacture name
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_MFG_NAME,

    /**
     * @brief Set to linecard initialization or connect to linecard.
     *
     * TRUE - Initialize linecard.
     * FALSE - Connect to initialized linecard.
     *
     * @type bool
     * @flags CREATE_ONLY
     */
    LAI_LINECARD_ATTR_INIT_LINECARD,

    /**
     * @brief Linecard alarm notification
     *
     * @type lai_pointer_t lai_linecard_alarm_notification_fn
     * @flags CREATE_ONLY
     * @default NULL
     */
    LAI_LINECARD_ATTR_LINECARD_ALARM_NOTIFY,

    /**
     * @brief Collect linecard alarm.
     *
     * @type bool
     * @flags SET_ONLY
     */
    LAI_LINECARD_ATTR_COLLECT_LINECARD_ALARM,

    /**
     * @brief Collect linecard log.
     *
     * @type bool
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_COLLECT_LINECARD_LOG,

    /**
     * @brief Linecard operational state change notification
     *
     * @type lai_pointer_t lai_linecard_state_change_notification_fn
     * @flags CREATE_ONLY
     * @default NULL
     */
    LAI_LINECARD_ATTR_LINECARD_STATE_CHANGE_NOTIFY,

    /**
     * @brief Led mode
     *
     * @type lai_led_mode_t
     * @flags CREATE_AND_SET
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_LED_MODE,

    /**
     * @brief Led flash interval
     *
     * @type lai_uint16_t
     * @flags CREATE_AND_SET
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_LED_FLASH_INTERVAL,

    /**
     * @brief Led color
     *
     * @type lai_led_color_t
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_LED_COLOR,

    /**
     * @brief Baud rate
     *
     * @type lai_linecard_baud_rate_t
     * @flags CREATE_AND_SET
     */
    LAI_LINECARD_ATTR_BAUD_RATE,

    /**
     * @brief Host IPv4 address
     *
     * @type lai_uint32_t
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_HOST_IP,

    /**
     * @brief User name
     *
     * @type char
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_USER_NAME,

    /**
     * @brief User password
     *
     * @type char
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_USER_PASSWORD,

    /**
     * @brief Linecard upgrade file name
     *
     * @type char
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_UPGRADE_FILE_NAME,

    /**
     * @brief Linecard upgrade file path
     *
     * @type char
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_UPGRADE_FILE_PATH,

    /**
     * @brief Upgrade download
     *
     * @type bool
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_UPGRADE_DOWNLOAD,

    /**
     * @brief Upgrade commit
     *
     * @type bool
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_UPGRADE_COMMIT,

    /**
     * @brief Upgrade commit pause
     *
     * @type bool
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_UPGRADE_COMMIT_PAUSE,

    /**
     * @brief Upgrade commit resume
     *
     * @type bool
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_UPGRADE_COMMIT_RESUME,

    /**
     * @brief Upgrade rollback
     *
     * @type bool
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_UPGRADE_ROLLBACK,

    /**
     * @brief Upgrade reboot
     *
     * @type bool
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_UPGRADE_REBOOT,

    /**
     * @brief Upgrade auto
     *
     * @type bool
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_UPGRADE_AUTO,

    /**
     * @brief Upgrade state
     *
     * @type lai_linecard_upgrade_state_t
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_UPGRADE_STATE,

    /**
     * @brief FPGA version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_FPGA_VERSION,

    /**
     * @brief UCD version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_UCD_VERSION,

    /**
     * @brief Temperature high alarm threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_LINECARD_ATTR_TEMP_HIGH_ALARM_THRESHOLD,

    /**
     * @brief Temperature high warn threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_LINECARD_ATTR_TEMP_HIGH_WARN_THRESHOLD,

    /**
     * @brief Temperature low alarm threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_LINECARD_ATTR_TEMP_LOW_ALARM_THRESHOLD,

    /**
     * @brief Temperature low warn threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_LINECARD_ATTR_TEMP_LOW_WARN_THRESHOLD,

    /**
     * @brief Slot id
     *
     * @type lai_int32_t
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_SLOT_ID,

    /**
     * @brief Equipment failure
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_EQUIPMENT_FAILURE,

    /**
     * @brief Equipment mismatch
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_LINECARD_ATTR_EQUIPMENT_MISMATCH,

    /**
     * @brief Start Pre-configuration
     *
     * @type bool
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_START_PRE_CONFIGURATION,

    /**
     * @brief Stop Pre-configuration
     *
     * @type bool
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_STOP_PRE_CONFIGURATION,

    /**
     * @brief Led name
     *
     * @type char
     * @flags CREATE_AND_SET
     * @isrecoverable false
     */
    LAI_LINECARD_ATTR_LED_NAME,

    /**
     * @brief End of attributes
     */
    LAI_LINECARD_ATTR_END,

    /** Custom range base value */
    LAI_LINECARD_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    LAI_LINECARD_ATTR_CUSTOM_RANGE_END

} lai_linecard_attr_t;

/**
 * @brief Linecard counter IDs in lai_get_linecard_stats() call
 *
 * @flags Contains flags
 */
typedef enum _lai_linecard_stat_t
{
    /**
     * @brief Start of statistics
     */
    LAI_LINECARD_STAT_START,

    /**
     * @brief Memory available
     *
     * @type lai_uint64_t
     * @iscounter false
     */
    LAI_LINECARD_STAT_MEMORY_AVAILABLE = LAI_LINECARD_STAT_START,

    /**
     * @brief Memory utilized
     *
     * @type lai_uint64_t
     * @iscounter false
     */
    LAI_LINECARD_STAT_MEMORY_UTILIZED,

    /**
     * @brief CPU utilization
     *
     * @type lai_uint32_t
     * @iscounter false
     */
    LAI_LINECARD_STAT_CPU_UTILIZATION,

    /**
     * @brief Temperature
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_LINECARD_STAT_TEMPERATURE,

    /**
     * @brief End of statistics
     */
    LAI_LINECARD_STAT_END,

} lai_linecard_stat_t;

/**
 * @def LAI_KEY_BOOT_TYPE
 *
 * 0: cold boot. Initialize NPU and external phys.
 * 1: warm boot. Do not re-initialize NPU or external phys, reconstruct LAI/SDK state from stored state.
 * 2: fast boot. Only initialize NPU. LAI/SDK state should not be persisted except for those related
 *    to physical port attributes such as SPEED, AUTONEG mode, admin state, operational status.
 */
#define LAI_KEY_BOOT_TYPE                         "LAI_BOOT_TYPE"

/**
 * @def LAI_KEY_WARM_BOOT_READ_FILE
 * The file to recover LAI/NPU state from
 */
#define LAI_KEY_WARM_BOOT_READ_FILE               "LAI_WARM_BOOT_READ_FILE"

/**
 * @def LAI_KEY_WARM_BOOT_WRITE_FILE
 * The file to write LAI/NPU state to
 */
#define LAI_KEY_WARM_BOOT_WRITE_FILE              "LAI_WARM_BOOT_WRITE_FILE"

/**
 * @def LAI_KEY_HW_PORT_PROFILE_ID_CONFIG_FILE
 * Vendor specific Configuration file for Hardware Port Profile ID parameters.
 * HW port profile ID can be used to set vendor specific port attributes based on
 * the transceiver type plugged in to the port
 */
#define LAI_KEY_HW_PORT_PROFILE_ID_CONFIG_FILE    "LAI_HW_PORT_PROFILE_ID_CONFIG_FILE"

/**
 * @brief Create linecard
 *
 * @param[out] linecard_id The Linecard Object ID
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes to set during initialization
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_create_linecard_fn)(
        _Out_ lai_object_id_t *linecard_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Remove/disconnect Linecard
 *
 * Release all resources associated with a currently created linecard
 *
 * @param[in] linecard_id The Linecard id
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_remove_linecard_fn)(
        _In_ lai_object_id_t linecard_id);

/**
 * @brief Set linecard attribute value
 *
 * @param[in] linecard_id Linecard id
 * @param[in] attr Linecard attribute
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_set_linecard_attribute_fn)(
        _In_ lai_object_id_t linecard_id,
        _In_ const lai_attribute_t *attr);

/**
 * @brief Get linecard attribute value
 *
 * @param[in] linecard_id Linecard id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of linecard attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_linecard_attribute_fn)(
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

/**
 * @brief Get linecard counters. Deprecated for backward compatibility.
 *
 * @param[in] linecard_id Linecard id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_linecard_stats_fn)(
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Get linecard statistics counters extended.
 *
 * @param[in] linecard_id Linecard id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_linecard_stats_ext_fn)(
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _In_ lai_stats_mode_t mode,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Clear linecard statistics counters.
 *
 * @param[in] linecard_id Linecard id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_clear_linecard_stats_fn)(
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids);

/**
 * @brief Get linecard alarms.
 *
 * @param[in] linecard_id Linecard id
 * @param[in] number_of_alarms Number of alarms in the array
 * @param[in] alarm_ids Specifies the array of alarm ids
 * @param[out] alarm_info Array of resulting alarm info.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_linecard_alarms_fn)(
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t number_of_alarms,
        _In_ const lai_alarm_type_t *alarm_ids,
        _Out_ lai_alarm_info_t *alarm_info);

/**
 * @brief Clear linecard alarms.
 *
 * @param[in] linecard_id Linecard id
 * @param[in] number_of_alarms Number of alarms in the array
 * @param[in] alarm_ids Specifies the array of alarm ids
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_clear_linecard_alarms_fn)(
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t number_of_alarms,
        _In_ const lai_alarm_type_t *alarm_ids);

/**
 * @brief Linecard method table retrieved with lai_api_query()
 */
typedef struct _lai_linecard_api_t
{
    lai_create_linecard_fn            create_linecard;
    lai_remove_linecard_fn            remove_linecard;
    lai_set_linecard_attribute_fn     set_linecard_attribute;
    lai_get_linecard_attribute_fn     get_linecard_attribute;
    lai_get_linecard_stats_fn         get_linecard_stats;
    lai_get_linecard_stats_ext_fn     get_linecard_stats_ext;
    lai_clear_linecard_stats_fn       clear_linecard_stats;
    lai_get_linecard_alarms_fn        get_linecard_alarms;
    lai_clear_linecard_alarms_fn      clear_linecard_alarms;
} lai_linecard_api_t;

/**
 * @}
 */
#endif /** __LAILINECARD_H_ */
