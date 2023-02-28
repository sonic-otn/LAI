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
 * @file    laitypes.h
 *
 * @brief   This module defines LAI portable types
 */

#if !defined (__LAITYPES_H_)
#define __LAITYPES_H_

/**
 * @defgroup LAITYPES LAI - Types definitions
 *
 * @{
 */

#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

typedef int32_t  lai_status_t;
typedef uint32_t lai_linecard_profile_id_t;
typedef uint32_t lai_attr_id_t;
typedef uint32_t lai_stat_id_t;

#define _In_
#define _Out_
#define _Inout_
#define _In_reads_z_(_LEN_)
#define _In_reads_opt_z_(_LEN_)

/*
 * New common definitions
 */

typedef uint64_t lai_uint64_t;
typedef int64_t lai_int64_t;
typedef uint32_t lai_uint32_t;
typedef int32_t lai_int32_t;
typedef uint16_t lai_uint16_t;
typedef int16_t lai_int16_t;
typedef uint8_t lai_uint8_t;
typedef int8_t lai_int8_t;
typedef float lai_float_t;
typedef double lai_double_t;
typedef size_t lai_size_t;
typedef uint64_t lai_object_id_t;
typedef void *lai_pointer_t;

typedef struct _lai_spectrum_power_t
{
    lai_uint64_t lower_frequency;
    lai_uint64_t upper_frequency;
    lai_double_t power;
} lai_spectrum_power_t;

/**
 * @def LAI_NULL_OBJECT_ID
 * LAI NULL object ID
 */
#define LAI_NULL_OBJECT_ID 0L

/**
 * @brief Defines a list of LAI object ids used as LAI attribute value.
 *
 * In set attribute function call, the count member defines the number of
 * objects.
 *
 * In get attribute function call, the function call returns a list of objects
 * to the caller in the list member. The caller is responsible for allocating
 * the buffer for the list member and set the count member to the size of
 * allocated object list. If the size is large enough to accommodate the list of
 * object id, the callee will then fill the list member and set the count member
 * to the actual number of objects. If the list size is not large enough, the
 * callee will set the count member to the actual number of object id and return
 * #LAI_STATUS_BUFFER_OVERFLOW. Once the caller gets such return code, it should
 * use the returned count member to re-allocate list and retry.
 */
typedef struct _lai_object_list_t
{
    uint32_t count;
    lai_object_id_t *list;
} lai_object_list_t;

/**
 * @brief LAI common API type
 */
typedef enum _lai_common_api_t
{
    LAI_COMMON_API_CREATE      = 0,
    LAI_COMMON_API_REMOVE      = 1,
    LAI_COMMON_API_SET         = 2,
    LAI_COMMON_API_GET         = 3,
    LAI_COMMON_API_BULK_CREATE = 4,
    LAI_COMMON_API_BULK_REMOVE = 5,
    LAI_COMMON_API_BULK_SET    = 6,
    LAI_COMMON_API_BULK_GET    = 7,
    LAI_COMMON_API_MAX         = 8,
} lai_common_api_t;

/**
 * @brief LAI object type
 */
typedef enum _lai_object_type_t
{
    LAI_OBJECT_TYPE_NULL                     =  0, /**< invalid object type */
    LAI_OBJECT_TYPE_LINECARD                 =  1,
    LAI_OBJECT_TYPE_PORT                     =  2,
    LAI_OBJECT_TYPE_TRANSCEIVER              =  3,
    LAI_OBJECT_TYPE_LOGICALCHANNEL           =  4,
    LAI_OBJECT_TYPE_OTN                      =  5,
    LAI_OBJECT_TYPE_ETHERNET                 =  6,
    LAI_OBJECT_TYPE_PHYSICALCHANNEL          =  7,
    LAI_OBJECT_TYPE_OCH                      =  8,
    LAI_OBJECT_TYPE_LLDP                     =  9,
    LAI_OBJECT_TYPE_ASSIGNMENT               =  10,
    LAI_OBJECT_TYPE_INTERFACE                =  11,
    LAI_OBJECT_TYPE_OA                       =  12,
    LAI_OBJECT_TYPE_OSC                      =  13,
    LAI_OBJECT_TYPE_APS                      =  14,
    LAI_OBJECT_TYPE_APSPORT                  =  15,
    LAI_OBJECT_TYPE_ATTENUATOR               =  16,
    LAI_OBJECT_TYPE_WSS                      =  17,
    LAI_OBJECT_TYPE_MEDIACHANNEL             =  18,
    LAI_OBJECT_TYPE_OCM                      =  19,
    LAI_OBJECT_TYPE_OTDR                     =  20,
    LAI_OBJECT_TYPE_MAX                      =  21,
} lai_object_type_t;

typedef struct _lai_u8_list_t
{
    uint32_t count;
    uint8_t *list;
} lai_u8_list_t;

typedef struct _lai_s8_list_t
{
    uint32_t count;
    int8_t *list;
} lai_s8_list_t;

typedef struct _lai_u16_list_t
{
    uint32_t count;
    uint16_t *list;
} lai_u16_list_t;

typedef struct _lai_s16_list_t
{
    uint32_t count;
    int16_t *list;
} lai_s16_list_t;

typedef struct _lai_u32_list_t
{
    uint32_t count;
    uint32_t *list;
} lai_u32_list_t;

typedef struct _lai_s32_list_t
{
    uint32_t count;
    int32_t *list;
} lai_s32_list_t;

typedef struct _lai_spectrum_power_list_t
{
    uint32_t count;
    lai_spectrum_power_t *list;
} lai_spectrum_power_list_t;

typedef struct _lai_u32_range_t
{
    uint32_t min;
    uint32_t max;
} lai_u32_range_t;

typedef struct _lai_s32_range_t
{
    int32_t min;
    int32_t max;
} lai_s32_range_t;

/**
 * @brief Data Type
 *
 * To use enum values as attribute value is lai_int32_t s32
 *
 * @extraparam const lai_attr_metadata_t *meta
 */
typedef union _lai_attribute_value_t
{
    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_BOOL */
    bool booldata;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_CHARDATA */
    char chardata[512];

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_UINT8 */
    lai_uint8_t u8;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_INT8 */
    lai_int8_t s8;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_UINT16 */
    lai_uint16_t u16;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_INT16 */
    lai_int16_t s16;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_UINT32 */
    lai_uint32_t u32;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_INT32 */
    lai_int32_t s32;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_UINT64 */
    lai_uint64_t u64;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_INT64 */
    lai_int64_t s64;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_DOUBLE */
    lai_double_t d64;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_POINTER */
    lai_pointer_t ptr;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_OBJECT_ID */
    lai_object_id_t oid;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_OBJECT_LIST */
    lai_object_list_t objlist;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_UINT8_LIST */
    lai_u8_list_t u8list;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_INT8_LIST */
    lai_s8_list_t s8list;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_UINT16_LIST */
    lai_u16_list_t u16list;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_INT16_LIST */
    lai_s16_list_t s16list;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_UINT32_LIST */
    lai_u32_list_t u32list;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_INT32_LIST */
    lai_s32_list_t s32list;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_UINT32_RANGE */
    lai_u32_range_t u32range;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_INT32_RANGE */
    lai_s32_range_t s32range;

    /** @validonly meta->attrvaluetype == LAI_ATTR_VALUE_TYPE_SPECTRUM_POWER_LIST */
    lai_spectrum_power_list_t spectrumpowerlist;

} lai_attribute_value_t;

typedef struct _lai_attribute_t
{
    lai_attr_id_t id;
    lai_attribute_value_t value;
} lai_attribute_t;

typedef union _lai_stat_value_t
{
    /** @validonly meta->statvaluetype == LAI_STAT_VALUE_TYPE_INT32 */
    lai_int32_t s32;

    /** @validonly meta->statvaluetype == LAI_STAT_VALUE_TYPE_UINT32 */
    lai_uint32_t u32;

    /** @validonly meta->statvaluetype == LAI_STAT_VALUE_TYPE_INT64 */
    lai_int64_t s64;

    /** @validonly meta->statvaluetype == LAI_STAT_VALUE_TYPE_UINT64 */
    lai_uint64_t u64;

    /** @validonly meta->statvaluetype == LAI_STAT_VALUE_TYPE_DOUBLE */
    lai_double_t d64;
} lai_stat_value_t;

typedef enum _lai_bulk_op_error_mode_t
{
    /**
     * @brief Bulk operation error handling mode where operation stops on the first failed creation
     *
     * Rest of objects will use LAI_STATUS_NON_EXECUTED return status value.
     */
    LAI_BULK_OP_ERROR_MODE_STOP_ON_ERROR,

    /**
     * @brief Bulk operation error handling mode where operation ignores the failures and continues to create other objects
     */
    LAI_BULK_OP_ERROR_MODE_IGNORE_ERROR,
} lai_bulk_op_error_mode_t;

/**
 * @brief LAI statistics modes
 *
 * Used in get statistics extended or query statistics capabilities
 * Note enum values must be powers of 2 to be used as bit mask for query statistics capabilities
 *
 * @flags Contains flags
 */
typedef enum _lai_stats_mode_t
{
    /**
     * @brief Read statistics
     */
    LAI_STATS_MODE_READ = 1 << 0,

    /**
     * @brief Read and clear after reading
     */
    LAI_STATS_MODE_READ_AND_CLEAR = 1 << 1,
} lai_stats_mode_t;

/** @brief Operational status */
typedef enum _lai_oper_status_t
{
    LAI_OPER_STATUS_ACTIVE,
    LAI_OPER_STATUS_INACTIVE,
    LAI_OPER_STATUS_DISABLED,
} lai_oper_status_t;

/** @brief Scanning status */
typedef enum _lai_scanning_status_t
{
    LAI_SCANNING_STATUS_ACTIVE,
    LAI_SCANNING_STATUS_INACTIVE,
} lai_scanning_status_t;

/** @brief Admin state */
typedef enum _lai_admin_state_t
{
    LAI_ADMIN_STATE_ENABLED,
    LAI_ADMIN_STATE_DISABLED,
    LAI_ADMIN_STATE_MAINT,
} lai_admin_state_t;

/** @brief Admin status */
typedef enum _lai_admin_status_t
{
    LAI_ADMIN_STATUS_ENABLED,
    LAI_ADMIN_STATUS_DISABLED,
    LAI_ADMIN_STATUS_MAINT,
} lai_admin_status_t;

/**
 * @brief The type of the port
 */
typedef enum _lai_port_type_t
{
    LAI_PORT_TYPE_INVALID,
    LAI_PORT_TYPE_CLIENT,
    LAI_PORT_TYPE_LINE,
    LAI_PORT_TYPE_LINE_IN,
    LAI_PORT_TYPE_LINE_OUT,
    LAI_PORT_TYPE_EDFA_IN,
    LAI_PORT_TYPE_EDFA_OUT,
    LAI_PORT_TYPE_MD_IN,
    LAI_PORT_TYPE_MD_OUT,
    LAI_PORT_TYPE_MD_EXP_IN,
    LAI_PORT_TYPE_MD_EXP_OUT,
    LAI_PORT_TYPE_OLP_PRI_IN,
    LAI_PORT_TYPE_OLP_PRI_OUT,
    LAI_PORT_TYPE_OLP_SEC_IN,
    LAI_PORT_TYPE_OLP_SEC_OUT,
    LAI_PORT_TYPE_OLP_COM_IN,
    LAI_PORT_TYPE_OLP_COM_OUT,
    LAI_PORT_TYPE_CLIENT_IN,
    LAI_PORT_TYPE_CLIENT_OUT,

} lai_port_type_t;

/**
 * @brief Led mode
 */
typedef enum _lai_led_mode_t
{
    LAI_LED_MODE_AUTO,
    LAI_LED_MODE_FORCE_FLASH,
} lai_led_mode_t;

/**
 * @brief Led color
 */
typedef enum _lai_led_color_t
{
    LAI_LED_COLOR_RED,
    LAI_LED_COLOR_GREEN,
    LAI_LED_COLOR_YELLOW,
    LAI_LED_COLOR_RED_FLASH,
    LAI_LED_COLOR_GREEN_FLASH,
    LAI_LED_COLOR_RED_GREEN_FLASH,
    LAI_LED_COLOR_OFF,
    LAI_LED_COLOR_ABNORMAL,
    LAI_LED_COLOR_YELLOW_FLASH,
} lai_led_color_t;

/**
 * @brief Alarm type of the linecard
 */
typedef enum _lai_alarm_type_t
{
    LAI_ALARM_TYPE_BOARD_INIT,
    LAI_ALARM_TYPE_BOARD_LOAD_FILE_FAILED,
    LAI_ALARM_TYPE_BOARD_LOADING,
    LAI_ALARM_TYPE_BOARD_LOAD_FAILED,
    LAI_ALARM_TYPE_BOARD_LOAD_ACTIVE,
    LAI_ALARM_TYPE_BOARD_MIN_FPGA_MISSING,
    LAI_ALARM_TYPE_BOARD_READY,
    LAI_ALARM_TYPE_BOARD_NEED_POWER_CYCLE,
    LAI_ALARM_TYPE_BOARD_MAX_FPGA_MISSING,
    LAI_ALARM_TYPE_BOARD_BOOT_FAILED,
    LAI_ALARM_TYPE_BOARD_CLEAN_UP_FOLDER,
    LAI_ALARM_TYPE_BOARD_RESET_CONSOLE,
    LAI_ALARM_TYPE_HARD_BAD,
    LAI_ALARM_TYPE_FPGA_MAX_TEMPERATURE_HIGH_ALARM,
    LAI_ALARM_TYPE_FPGA_MAX_TEMPERATURE_HIGH_WARN,
    LAI_ALARM_TYPE_FPGA_MAX_TEMPERATURE_LOW_WARN,
    LAI_ALARM_TYPE_FPGA_MAX_TEMPERATURE_LOW_ALARM,
    LAI_ALARM_TYPE_BOARD_MODE_SWITCH,
    LAI_ALARM_TYPE_BOARD_UPGRADE_DONE,
    LAI_ALARM_TYPE_AC1200_MISSING,
    LAI_ALARM_TYPE_AC1200_COMMUNICATION_FAILED,
    LAI_ALARM_TYPE_HIGH_TEMPERATURE_ALARM,
    LAI_ALARM_TYPE_LOW_TEMPERATURE_ALARM,
    LAI_ALARM_TYPE_HIGH_TEMPERATURE_WARN,
    LAI_ALARM_TYPE_LOW_TEMPERATURE_WARN,
    LAI_ALARM_TYPE_WL5E_FAULT,
    LAI_ALARM_TYPE_WL5E_ABNORMAL,
    LAI_ALARM_TYPE_LOOPBACK_TERMINAL,
    LAI_ALARM_TYPE_LOOPBACK_FACILITY,
    LAI_ALARM_TYPE_TRANSCEIVER_FAILED,
    LAI_ALARM_TYPE_RX_LOS,
    LAI_ALARM_TYPE_RX_LOL,
    LAI_ALARM_TYPE_TX_FAIL,
    LAI_ALARM_TYPE_TX_LOS,
    LAI_ALARM_TYPE_TX_PWR_LOW,
    LAI_ALARM_TYPE_TX_PWR_HIGH,
    LAI_ALARM_TYPE_RX_PWR_LOW,
    LAI_ALARM_TYPE_RX_PWR_HIGH,
    LAI_ALARM_TYPE_PORT_INIT,
    LAI_ALARM_TYPE_XCVR_MISSING,
    LAI_ALARM_TYPE_XCVR_UNSUPPORTED,
    LAI_ALARM_TYPE_XCVR_MISMATCH,
    LAI_ALARM_TYPE_XCVR_COMMUNICATION_FAILED,
    LAI_ALARM_TYPE_INVALID_CROSS_BAR,
    LAI_ALARM_TYPE_INVALID_WORKING_MODE,
    LAI_ALARM_TYPE_VENDOR_MISMATCH,
    LAI_ALARM_TYPE_FLEXO_RX_SM_BIP8,
    LAI_ALARM_TYPE_FLEXO_RX_SM_BEI,
    LAI_ALARM_TYPE_FLEXO_RX_OTN_LOF,
    LAI_ALARM_TYPE_FLEXO_RX_OTN_OOF,
    LAI_ALARM_TYPE_FLEXO_RX_OTN_LOM,
    LAI_ALARM_TYPE_FLEXO_RX_OTN_OOM,
    LAI_ALARM_TYPE_FLEXO_RX_SM_BDI,
    LAI_ALARM_TYPE_FLEXO_RX_ODU_AIS,
    LAI_ALARM_TYPE_FLEXO_RX_ODU_LCK,
    LAI_ALARM_TYPE_FLEXO_RX_FEC_UNCORRECT,
    LAI_ALARM_TYPE_FLEXO_RX_FEC_SD,
    LAI_ALARM_TYPE_FLEXO_RX_FEC_SF,
    LAI_ALARM_TYPE_FLEXO_TX_FEC_SD,
    LAI_ALARM_TYPE_FLEXO_TX_FEC_SF,
    LAI_ALARM_TYPE_FLEXO_RX_ALGNMENT_ERR,
    LAI_ALARM_TYPE_FLEXO_RX_CD_DEG,
    LAI_ALARM_TYPE_FLEXO_RX_PDL_DEG,
    LAI_ALARM_TYPE_FLEXO_RX_PMD_DEG,
    LAI_ALARM_TYPE_FLEXO_RX_FOFF_DEG,
    LAI_ALARM_TYPE_FLEXO_RX_SOP_CHANGE_RATE_DEG,
    LAI_ALARM_TYPE_FLEXO_TX_FORCE_AIS,
    LAI_ALARM_TYPE_FLEXO_TX_FORCE_LCK,
    LAI_ALARM_TYPE_FLEXO_ABNORMAL_STATE,
    LAI_ALARM_TYPE_FLEXO_LINE_PRBS_ENABLE,
    LAI_ALARM_TYPE_FLEXO_LINE_RX_TTI_MISMATCH,
    LAI_ALARM_TYPE_FLEXO_TX_FORCE_OCI,
    LAI_ALARM_TYPE_FLEXO_RX_BER_FDD,
    LAI_ALARM_TYPE_FLEXO_RX_BER_FED,
    LAI_ALARM_TYPE_FLEXO_RX_GIDM,
    LAI_ALARM_TYPE_FLEXO_RX_LDI_LD,
    LAI_ALARM_TYPE_FLEXO_RX_LDI_RD,
    LAI_ALARM_TYPE_FLEXO_RX_LOFLOM,
    LAI_ALARM_TYPE_FLEXO_RX_PMM,
    LAI_ALARM_TYPE_FLEXO_RX_RPF,
    LAI_ALARM_TYPE_RX_DISPERSION_POST_COMP_OOR,
    LAI_ALARM_TYPE_CLIENT_LASER_OFF_BY_ALS,
    LAI_ALARM_TYPE_CLIENT_LASER_OFF_BY_DISABLED,
    LAI_ALARM_TYPE_CLIENT_POWER_MODE_ERROR,
    LAI_ALARM_TYPE_CLIENT_QSFP28_PNCODE_ERR,
    LAI_ALARM_TYPE_CLIENT_RX_PLL_FLT,
    LAI_ALARM_TYPE_CLIENT_SERDES_PRBS_ENABLE,
    LAI_ALARM_TYPE_CRYPT_KEY_ID,
    LAI_ALARM_TYPE_CLIENT_MODULE_HOST_PRBS_ENABLE,
    LAI_ALARM_TYPE_CLIENT_MODULE_MEDIA_PRBS_ENABLE,
    LAI_ALARM_TYPE_CLIENT_MODULE_HOST_LOOPBACK,
    LAI_ALARM_TYPE_CLIENT_MODULE_MEDIA_LOOPBACK,
    LAI_ALARM_TYPE_CLIENT_RX_FEC_BER_SD_ALARM,
    LAI_ALARM_TYPE_CLIENT_RX_FEC_BER_SF_ALARM,
    LAI_ALARM_TYPE_GE_TX_FORCE_LF,
    LAI_ALARM_TYPE_GE_TX_FORCE_RF,
    LAI_ALARM_TYPE_GE_TX_FORCE_IDLE,
    LAI_ALARM_TYPE_GE_RX_NO_PACKET,
    LAI_ALARM_TYPE_GE_RX_LF,
    LAI_ALARM_TYPE_GE_TX_LF,
    LAI_ALARM_TYPE_GE_RX_RF,
    LAI_ALARM_TYPE_GE_TX_RF,
    LAI_ALARM_TYPE_GE_RX_BLK_LCK_FLT,
    LAI_ALARM_TYPE_GE_RX_AM_LCK_FLT,
    LAI_ALARM_TYPE_GE_TX_BLK_LCK_FLT,
    LAI_ALARM_TYPE_GE_TX_AM_LCK_FLT,
    LAI_ALARM_TYPE_GE_RX_PCS_ERR_FLT,
    LAI_ALARM_TYPE_GE_RX_PCS_BIP_FLT,
    LAI_ALARM_TYPE_GE_TX_PCS_ERR_FLT,
    LAI_ALARM_TYPE_GE_TX_PCS_BIP_FLT,
    LAI_ALARM_TYPE_GE_RX_PCS_LOA,
    LAI_ALARM_TYPE_GE_TX_PCS_LOA,
    LAI_ALARM_TYPE_GE_RX_PCS_HI_BER,
    LAI_ALARM_TYPE_GE_RX_LOSS_OF_SYNC,
    LAI_ALARM_TYPE_GE_TX_LOSS_OF_SYNC,
    LAI_ALARM_TYPE_OTUCN_IAE,
    LAI_ALARM_TYPE_OTUCN_LOFLOM,
    LAI_ALARM_TYPE_OTUCN_ODU_AIS,
    LAI_ALARM_TYPE_OTUCN_ODU_LCK,
    LAI_ALARM_TYPE_OTUCN_ODU_OCI,
    LAI_ALARM_TYPE_OTUCN_ODU_SD,
    LAI_ALARM_TYPE_OTUCN_OOF,
    LAI_ALARM_TYPE_OTUCN_OOM,
    LAI_ALARM_TYPE_OTUCN_OPU_AIS,
    LAI_ALARM_TYPE_OTUCN_OPU_CRC5,
    LAI_ALARM_TYPE_OTUCN_OPU_CRC8,
    LAI_ALARM_TYPE_OTUCN_OPU_CSF,
    LAI_ALARM_TYPE_OTUCN_OPU_LOCM,
    LAI_ALARM_TYPE_OTUCN_OPU_PLM,
    LAI_ALARM_TYPE_OTUCN_OTU_SD,
    LAI_ALARM_TYPE_OTUCN_PM_BDI,
    LAI_ALARM_TYPE_OTUCN_PM_BEI_ALARM,
    LAI_ALARM_TYPE_OTUCN_PM_BIP8_ALARM,
    LAI_ALARM_TYPE_OTUCN_PM_SSF,
    LAI_ALARM_TYPE_OTUCN_PM_TSF,
    LAI_ALARM_TYPE_OTUCN_SM_BDI,
    LAI_ALARM_TYPE_OTUCN_SM_BEI_ALARM,
    LAI_ALARM_TYPE_OTUCN_SM_BIAE,
    LAI_ALARM_TYPE_OTUCN_SM_BIP8_ALARM,
    LAI_ALARM_TYPE_OTUCN_SM_SSF,
    LAI_ALARM_TYPE_OTUCN_SM_TSF,
    LAI_ALARM_TYPE_OTN_AM_SF_0,
    LAI_ALARM_TYPE_OTN_AM_SF_2,
    LAI_ALARM_TYPE_OTN_ASSERTING_AM_SF_1,
    LAI_ALARM_TYPE_OTN_IAE,
    LAI_ALARM_TYPE_OTN_LOFLOM,
    LAI_ALARM_TYPE_OTN_LRC,
    LAI_ALARM_TYPE_OTN_ODU_AIS,
    LAI_ALARM_TYPE_OTN_ODU_LCK,
    LAI_ALARM_TYPE_OTN_ODU_OCI,
    LAI_ALARM_TYPE_OTN_ODU_SD,
    LAI_ALARM_TYPE_OTN_OOF,
    LAI_ALARM_TYPE_OTN_OOM,
    LAI_ALARM_TYPE_OTN_OPU_AIS,
    LAI_ALARM_TYPE_OTN_OPU_CRC5,
    LAI_ALARM_TYPE_OTN_OPU_CRC8,
    LAI_ALARM_TYPE_OTN_OPU_CSF,
    LAI_ALARM_TYPE_OTN_OPU_LOCM,
    LAI_ALARM_TYPE_OTN_OPU_PLM,
    LAI_ALARM_TYPE_OTN_OTU_SD,
    LAI_ALARM_TYPE_OTN_PM_BDI,
    LAI_ALARM_TYPE_OTN_PM_BEI_ALARM,
    LAI_ALARM_TYPE_OTN_PM_BIP8_ALARM,
    LAI_ALARM_TYPE_OTN_PM_SSF,
    LAI_ALARM_TYPE_OTN_PM_TSF,
    LAI_ALARM_TYPE_OTN_RECEIVE_CDL_1,
    LAI_ALARM_TYPE_OTN_SM_BDI,
    LAI_ALARM_TYPE_OTN_SM_BEI_ALARM,
    LAI_ALARM_TYPE_OTN_SM_BIAE,
    LAI_ALARM_TYPE_OTN_SM_BIP8_ALARM,
    LAI_ALARM_TYPE_OTN_SM_SSF,
    LAI_ALARM_TYPE_OTN_SM_TSF,
    LAI_ALARM_TYPE_OLP_SWITCH_TO_PRIMARY,
    LAI_ALARM_TYPE_OLP_SWITCH_TO_SECONDARY,
    LAI_ALARM_TYPE_OLP_FORCE_TO_PRIMARY,
    LAI_ALARM_TYPE_OLP_FORCE_TO_SECONDARY,
    LAI_ALARM_TYPE_EDFA_SATURATED,
    LAI_ALARM_TYPE_EDFA_GAIN_LOW,
    LAI_ALARM_TYPE_OTDR_LOS_CHANGE,
    LAI_ALARM_TYPE_OTDR_TEST_FAILURE,
    LAI_ALARM_TYPE_OTDR_REPORT_IN,
    LAI_ALARM_TYPE_OTDR_LENGTH_BENEATH,
    LAI_ALARM_TYPE_OTDR_LOSS_EXCEED,
    LAI_ALARM_TYPE_WSS_TRIB_INPUT_LOS,
    LAI_ALARM_TYPE_WSS_TRIB_OUTPUT_LOS,
    LAI_ALARM_TYPE_WSS_TRIB_INPUT_LOW,
    LAI_ALARM_TYPE_WSS_TRIB_INPUT_HIGH,
    LAI_ALARM_TYPE_WSS_PORT_MISMATCH,
    LAI_ALARM_TYPE_MEDIACHANNEL_TARGETPOWER_OUTOFREACH,
    LAI_ALARM_TYPE_MEDIACHANNEL_INPUT_LOS,
    LAI_ALARM_TYPE_ASE_TARGET_PSD_NOT_REACHABLE,
    LAI_ALARM_TYPE_CRD_REBOOT,
    LAI_ALARM_TYPE_TRANS_FAIL,
    LAI_ALARM_TYPE_UPGRADE_IP,
    LAI_ALARM_TYPE_UPGRADE_FAIL,
    LAI_ALARM_TYPE_UPGRADE_ACTIVE,
    LAI_ALARM_TYPE_CRD_READY,
    LAI_ALARM_TYPE_SLOT_COMM_FAIL,
    LAI_ALARM_TYPE_TX_PWR_NOT_MATCH,

    LAI_ALARM_TYPE_MAX,
} lai_alarm_type_t;

/**
 * @brief Alarm status
 */
typedef enum _lai_alarm_status_t
{
    LAI_ALARM_STATUS_ACTIVE,          /**< Alarm is active */
    LAI_ALARM_STATUS_INACTIVE,        /**< Alarm is inactive */
    LAI_ALARM_STATUS_TRANSIENT,       /**< Alarm is transient */
    LAI_ALARM_STATUS_MAX,             /**< Number of alarm states */
} lai_alarm_status_t;

/**
 * @brief Alarm severity
 */
typedef enum _lai_alarm_severity_t
{
    LAI_ALARM_SEVERITY_UNKNOWN,          /**< Unknown */
    LAI_ALARM_SEVERITY_NOT_ALARMED,      /**< Not alarmed */
    LAI_ALARM_SEVERITY_CLEARED,          /**< Cleared */
    LAI_ALARM_SEVERITY_NOT_REPORT,       /**< Not report */
    LAI_ALARM_SEVERITY_MINOR,            /**< Minor */
    LAI_ALARM_SEVERITY_WARNING,          /**< Warning */
    LAI_ALARM_SEVERITY_MAJOR,            /**< Major */
    LAI_ALARM_SEVERITY_CRITICAL,         /**< Critical */
} lai_alarm_severity_t;

/**
 * @brief Structure for alarm info
 */
typedef struct _lai_alarm_info_t
{
    /**
     * @brief Status
     */
    lai_alarm_status_t status;

    /**
     * @brief Time created
     */
    uint64_t time_created;

    /**
     * @brief Text
     */
    lai_s8_list_t text;

    /**
     * @brief Resource object id
     */
    lai_object_id_t resource_oid;

    /**
     * @brief Severity
     */
    lai_alarm_severity_t severity;

} lai_alarm_info_t;

/**
 * @}
 */
#endif /** __LAITYPES_H_ */
