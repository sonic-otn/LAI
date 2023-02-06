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
 * @file    laitransceiver.h
 * @brief   This module defines the transceiver for the LAI
 */

#if !defined (__LAITRANSCEIVER_H_)
#define __LAITRANSCEIVER_H_

#include <laitypes.h>

/**
 * @defgroup LAITRANSCEIVER LAI - Transceiver specific API definitions
 *
 * @{
 */

/** @brief Transceiver FEC mode */
typedef enum _lai_transceiver_fec_mode_t
{
    /** System will determine whether to enable or disable FEC on a transceiver. */
    LAI_TRANSCEIVER_FEC_MODE_FEC_AUTO,

    /** FEC is administratively enabled. */
    LAI_TRANSCEIVER_FEC_MODE_FEC_ENABLED,

    /** FEC is administratively disabled. */
    LAI_TRANSCEIVER_FEC_MODE_FEC_DISABLED,
} lai_transceiver_fec_mode_t;

/** @brief Transceiver FEC status */
typedef enum _lai_transceiver_fec_status_t
{
    /** FEC is operationally locked. */
    LAI_TRANSCEIVER_FEC_STATUS_LOCKED,

    /** FEC is operationally unlocked. */
    LAI_TRANSCEIVER_FEC_STATUS_UNLOCKED,
} lai_transceiver_fec_status_t;

/** @brief Transceiver present status */
typedef enum _lai_transceiver_present_t
{
    LAI_TRANSCEIVER_PRESENT_PRESENT,
    LAI_TRANSCEIVER_PRESENT_NOT_PRESENT,
} lai_transceiver_present_t;

/** @brief Type definition for transceiver module functional types. */
typedef enum _lai_transceiver_module_functional_type_t
{
    /**
     * @brief Standard optic
     *
     * Standard optic using a grey wavelength (i.e. 1310, 1550, etc.)
     * and on-off-keying modulation.
     */
    LAI_TRANSCEIVER_MODULE_FUNCTIONAL_TYPE_STANDARD_OPTIC,

    /**
     * @brief Digital coherent optic
     *
     * Digital coherent module which transmits a phase / amplitude
     * modulated signal and uses a digital signal processor to receive
     * and decode the received signal.
     */
    LAI_TRANSCEIVER_MODULE_FUNCTIONAL_TYPE_DIGITAL_COHERENT_OPTIC,
} lai_transceiver_module_functional_type_t;

/** @brief Transceiver form factor. */
typedef enum _lai_transceiver_form_factor_t
{
    LAI_TRANSCEIVER_FORM_FACTOR_CFP,
    LAI_TRANSCEIVER_FORM_FACTOR_CFP2,
    LAI_TRANSCEIVER_FORM_FACTOR_CFP2_ACO,
    LAI_TRANSCEIVER_FORM_FACTOR_CFP4,
    LAI_TRANSCEIVER_FORM_FACTOR_QSFP,
    LAI_TRANSCEIVER_FORM_FACTOR_QSFP_PLUS,
    LAI_TRANSCEIVER_FORM_FACTOR_QSFP28,
    LAI_TRANSCEIVER_FORM_FACTOR_QSFP56_DD_TYPE1,
    LAI_TRANSCEIVER_FORM_FACTOR_QSFP56_DD_TYPE2,
    LAI_TRANSCEIVER_FORM_FACTOR_QSFP112,
    LAI_TRANSCEIVER_FORM_FACTOR_CPAK,
    LAI_TRANSCEIVER_FORM_FACTOR_SFP,
    LAI_TRANSCEIVER_FORM_FACTOR_SFP_PLUS,
    LAI_TRANSCEIVER_FORM_FACTOR_XFP,
    LAI_TRANSCEIVER_FORM_FACTOR_X2,
    LAI_TRANSCEIVER_FORM_FACTOR_OSFP,
    LAI_TRANSCEIVER_FORM_FACTOR_NON_PLUGGABLE,
    LAI_TRANSCEIVER_FORM_FACTOR_OTHER,
} lai_transceiver_form_factor_t;

/** @brief Ethernet compliance codes supported by transceivers */
typedef enum _lai_transceiver_ethernet_pmd_t
{
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_10GBASE_LRM,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_10GBASE_LR,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_10GBASE_ZR,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_10GBASE_ER,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_10GBASE_SR,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_40GBASE_CR4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_40GBASE_SR4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_40GBASE_LR4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_40GBASE_ER4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_40GBASE_PSM4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_4X10GBASE_LR,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_4X10GBASE_SR,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_100G_AOC,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_100G_ACC,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_100GBASE_SR10,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_100GBASE_SR4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_100GBASE_LR4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_100GBASE_ER4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_100GBASE_CWDM4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_100GBASE_CLR4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_100GBASE_PSM4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_100GBASE_CR4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_100GBASE_FR,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_100GBASE_4WDM10,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_400GBASE_ZR,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_400GBASE_LR4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_400GBASE_FR4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_400GBASE_LR8,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_400GBASE_DR4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_200GBASE_SR4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_200GBASE_DR4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_200GBASE_FR4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_200GBASE_EFR4,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_AUTO,
    LAI_TRANSCEIVER_ETHERNET_PMD_ETH_UNDEFINED,
} lai_transceiver_ethernet_pmd_t;

typedef enum _lai_transceiver_connector_type_t
{
    LAI_TRANSCEIVER_CONNECTOR_TYPE_SC_CONNECTOR,
    LAI_TRANSCEIVER_CONNECTOR_TYPE_LC_CONNECTOR,
    LAI_TRANSCEIVER_CONNECTOR_TYPE_MPO_CONNECTOR,
    LAI_TRANSCEIVER_CONNECTOR_TYPE_AOC_CONNECTOR,
    LAI_TRANSCEIVER_CONNECTOR_TYPE_DAC_CONNECTOR,
} lai_transceiver_connector_type_t;

typedef enum _lai_transceiver_power_mode_t
{
    LAI_TRANSCEIVER_POWER_MODE_NORMAL,
    LAI_TRANSCEIVER_POWER_MODE_LOW_POWER,
} lai_transceiver_power_mode_t;

typedef enum _lai_transceiver_flash_partition_t
{
    LAI_TRANSCEIVER_FLASH_PARTITION_A,
    LAI_TRANSCEIVER_FLASH_PARTITION_B,
} lai_transceiver_flash_partition_t;

typedef enum _lai_transceiver_upgrade_state_t
{
    LAI_TRANSCEIVER_UPGRADE_STATE_IDLE,
    LAI_TRANSCEIVER_UPGRADE_STATE_DOWNLOADING,
    LAI_TRANSCEIVER_UPGRADE_STATE_SWITCHING,
    LAI_TRANSCEIVER_UPGRADE_STATE_BACKUPING,
} lai_transceiver_upgrade_state_t;

typedef enum _lai_transceiver_power_class_t
{
    LAI_TRANSCEIVER_POWER_CLASS_BELOW_9W,
    LAI_TRANSCEIVER_POWER_CLASS_BELOW_12W,
    LAI_TRANSCEIVER_POWER_CLASS_BELOW_15W,
    LAI_TRANSCEIVER_POWER_CLASS_ABOVE_15W,
} lai_transceiver_power_class_t;

typedef enum _lai_transceiver_extend_module_code_t
{
    LAI_TRANSCEIVER_EXTEND_MODULE_CODE_SDR,
    LAI_TRANSCEIVER_EXTEND_MODULE_CODE_DDR,
    LAI_TRANSCEIVER_EXTEND_MODULE_CODE_QDR,
    LAI_TRANSCEIVER_EXTEND_MODULE_CODE_FDR,
    LAI_TRANSCEIVER_EXTEND_MODULE_CODE_EDR
} lai_transceiver_extend_module_code_t;

typedef enum _lai_transceiver_data_status_t
{
    LAI_TRANSCEIVER_DATA_STATUS_NOT_READY,
    LAI_TRANSCEIVER_DATA_STATUS_READY
} lai_transceiver_data_status_t;

typedef enum _lai_transceiver_encode_t
{
    LAI_TRANSCEIVER_ENCODE_UNSPECIFIED,
    LAI_TRANSCEIVER_ENCODE_8B_10B,
    LAI_TRANSCEIVER_ENCODE_4B_5B,
    LAI_TRANSCEIVER_ENCODE_NRZ,
    LAI_TRANSCEIVER_ENCODE_SONET_SCRAMBLED,
    LAI_TRANSCEIVER_ENCODE_64B_66B,
    LAI_TRANSCEIVER_ENCODE_MANCHESTER,
    LAI_TRANSCEIVER_ENCODE_256B_257B,
    LAI_TRANSCEIVER_ENCODE_PAM4
} lai_transceiver_encode_t;

/**
 * @brief Transceiver attribute IDs
 */
typedef enum _lai_transceiver_attr_t
{
    /**
     * @brief Start of attributes
     */
    LAI_TRANSCEIVER_ATTR_START,

    /**
     * @brief Client port or line port.
     *
     * @type lai_port_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_TRANSCEIVER_ATTR_PORT_TYPE = LAI_TRANSCEIVER_ATTR_START,

    /**
     * @brief Port ID.
     *
     * @type lai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_TRANSCEIVER_ATTR_PORT_ID,

    /**
     * @brief Turns power on / off to the transceiver
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    LAI_TRANSCEIVER_ATTR_ENABLED,

    /**
     * @brief The operational state of the transceiver
     *
     * @type lai_oper_status_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_OPER_STATUS,

    /**
     * @brief FEC mode
     *
     * @type lai_transceiver_fec_mode_t
     * @flags CREATE_AND_SET
     */
    LAI_TRANSCEIVER_ATTR_FEC_MODE,

    /**
     * @brief Indicates whether a transceiver is present in
     * the specified client port.
     *
     * @type lai_transceiver_present_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_PRESENT,

    /**
     * @brief Indicates the type of optical transceiver used on this
     * port.
     *
     * @type lai_transceiver_form_factor_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_FORM_FACTOR,

    /**
     * @brief Vendor expect
     *
     * @type char
     * @flags CREATE_AND_SET
     */
    LAI_TRANSCEIVER_ATTR_VENDOR_EXPECT,

    /**
     * @brief Vendor
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_VENDOR,

    /**
     * @brief Vendor part
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_VENDOR_PART,

    /**
     * @brief Part no
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_PART_NO,

    /**
     * @brief Vendor revision
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_VENDOR_REV,

    /**
     * @brief Date code
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_DATE_CODE,

    /**
     * @brief Manufacture name
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_MFG_NAME,

    /**
     * @brief Manufacture date
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_MFG_DATE,

    /**
     * @brief Hardware version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_HARDWARE_VERSION,

    /**
     * @brief Firmware version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_FIRMWARE_VERSION,

    /**
     * @brief Ethernet PMD (physical medium dependent sublayer) that the
     * transceiver supports.
     *
     * @type lai_transceiver_ethernet_pmd_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_ETHERNET_PMD,

    /**
     * @brief Pre-configuring a port/transceiver with the expected PMD
     *
     * @type lai_transceiver_ethernet_pmd_t
     * @flags CREATE_AND_SET
     */
    LAI_TRANSCEIVER_ATTR_ETHERNET_PMD_PRECONF,

    /**
     * @brief Indicates if a fault condition exists in the transceiver
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_FAULT_CONDITION,

    /**
     * @brief Removable
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_REMOVABLE,

    /**
     * @brief Connector type
     *
     * @type lai_transceiver_connector_type_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_CONNECTOR_TYPE,

    /**
     * @brief Serial No
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_SERIAL_NO,

    /**
     * @brief Power mode
     *
     * @type lai_transceiver_power_mode_t
     * @flags CREATE_AND_SET
     */
    LAI_TRANSCEIVER_ATTR_POWER_MODE,

    /**
     * @brief Reset
     *
     * @type bool
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_TRANSCEIVER_ATTR_RESET,

    /**
     * @brief Number of lane.
     *
     * @type lai_uint32_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_NUM_OF_LANE,

    /**
     * @brief Upgrade download
     *
     * @type bool
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_TRANSCEIVER_ATTR_UPGRADE_DOWNLOAD,

    /**
     * @brief Switch flash partition
     *
     * @type lai_transceiver_flash_partition_t
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_TRANSCEIVER_ATTR_SWITCH_FLASH_PARTITION,

    /**
     * @brief Backup flash partition
     *
     * @type lai_transceiver_flash_partition_t
     * @flags SET_ONLY
     * @isrecoverable false
     */
    LAI_TRANSCEIVER_ATTR_BACKUP_FLASH_PARTITION,

    /**
     * @brief Upgrade state.
     *
     * @type lai_transceiver_upgrade_state_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_UPGRADE_STATE,

    /**
     * @brief Laser age
     *
     * @type lai_int32_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_LASER_AGE,

    /**
     * @brief Operate time
     *
     * @type lai_int32_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_OPERATE_TIME,

    /**
     * @brief Lot code
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_LOT_CODE,

    /**
     * @brief CLEI code
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_CLEI_CODE,

    /**
     * @brief Power class
     *
     * @type lai_transceiver_power_class_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_POWER_CLASS,

    /**
     * @brief New work bit rate
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_NEWWORK_BIT_RATE,

    /**
     * @brief Host bit rate
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_HOST_BIT_RATE,

    /**
     * @brief Sm fiber length
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_SM_FIBER_LEN,

    /**
     * @brief Mm fiber length
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_MM_FIBER_LEN,

    /**
     * @brief Copper cable length
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_COPPER_CABLE_LEN,

    /**
     * @brief Max wave length
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_MAX_WAVELENGTH,

    /**
     * @brief Min wave length
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_MIN_WAVELENGTH,

    /**
     * @brief Max tx power
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_MAX_TX_POWER,

    /**
     * @brief Max rx power
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_MAX_RX_POWER,

    /**
     * @brief Max operational temp
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_MAX_OPER_TEMP,

    /**
     * @brief Min operational temp
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_MIN_OPER_TEMP,

    /**
     * @brief VCC high alarm threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_VCC_HIGH_ALARM_THRESHOLD,

    /**
     * @brief VCC high warn threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_VCC_HIGH_WARN_THRESHOLD,

    /**
     * @brief VCC low alarm threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_VCC_LOW_ALARM_THRESHOLD,

    /**
     * @brief VCC low warn threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_VCC_LOW_WARN_THRESHOLD,

    /**
     * @brief Rx total power high alarm threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_RX_TOTAL_POWER_HIGH_ALARM_THRESHOLD,

    /**
     * @brief Rx total power high warn threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_RX_TOTAL_POWER_HIGH_WARN_THRESHOLD,

    /**
     * @brief Rx total power low alarm threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_RX_TOTAL_POWER_LOW_ALARM_THRESHOLD,

    /**
     * @brief Rx total power low warn threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_RX_TOTAL_POWER_LOW_WARN_THRESHOLD,

    /**
     * @brief OA pump current  high alarm threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_OA_PUMP_CURRENT_HIGH_ALARM_THRESHOLD,

    /**
     * @brief OA pump current high warn threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_OA_PUMP_CURRENT_HIGH_WARN_THRESHOLD,

    /**
     * @brief OA pump current low alarm threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_OA_PUMP_CURRENT_LOW_ALARM_THRESHOLD,

    /**
     * @brief OA pump current low warn threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_OA_PUMP_CURRENT_LOW_WARN_THRESHOLD,

    /**
     * @brief Tx BAIS high alarm threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_TX_BAIS_HIGH_ALARM_THRESHOLD,

    /**
     * @brief Tx BAIS high warn threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_TX_BAIS_HIGH_WARN_THRESHOLD,

    /**
     * @brief Tx BAIS low alarm threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_TX_BAIS_LOW_ALARM_THRESHOLD,

    /**
     * @brief Tx BAIS low warn threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_TX_BAIS_LOW_WARN_THRESHOLD,

    /**
     * @brief Extend module code
     *
     * @type lai_transceiver_extend_module_code_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_EXTEND_MODULE_CODE,

    /**
     * @brief Data status
     *
     * @type lai_transceiver_data_status_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_DATA_STATUS,

    /**
     * @brief Encode
     *
     * @type lai_transceiver_encode_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_ENCODE,

    /**
     * @brief Bit rate
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_BITRATE,

    /**
     * @brief Extend bit rate
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_EXTEND_BIT_RATE,

    /**
     * @brief Wavelength
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_WAVELENGTH,

    /**
     * @brief Wavelength tolerance
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_WAVELENGTH_TOLERANCE,

    /**
     * @brief OUI
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_OUI,

    /**
     * @brief Rn
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_RN,

    /**
     * @brief Identifier
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_IDENTIFIER,

    /**
     * @brief CMIS revision
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_CMIS_REVISION,

    /**
     * @brief Tx power high alarm threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_TX_POWER_HIGH_ALARM_THRESHOLD,

    /**
     * @brief Tx power low alarm threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_TX_POWER_LOW_ALARM_THRESHOLD,

    /**
     * @brief Tx power high warn threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_TX_POWER_HIGH_WARN_THRESHOLD,

    /**
     * @brief Tx power low warn threshold
     *
     * @type lai_double_t
     * @flags READ_ONLY
     */
    LAI_TRANSCEIVER_ATTR_TX_POWER_LOW_WARN_THRESHOLD,

    /**
     * @brief Frequency range
     *
     * @type char
     * @flags CREATE_AND_SET
     */
    LAI_TRANSCEIVER_ATTR_FREQUENCY_RANGE,

    /**
     * @brief Temperature high alarm threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_TRANSCEIVER_ATTR_TEMP_HIGH_ALARM_THRESHOLD,

    /**
     * @brief Temperature high warn threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_TRANSCEIVER_ATTR_TEMP_HIGH_WARN_THRESHOLD,

    /**
     * @brief Temperature low alarm threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_TRANSCEIVER_ATTR_TEMP_LOW_ALARM_THRESHOLD,

    /**
     * @brief Temperature low warn threshold
     *
     * @type lai_double_t
     * @flags CREATE_AND_SET
     */
    LAI_TRANSCEIVER_ATTR_TEMP_LOW_WARN_THRESHOLD,

    /**
     * @brief End of attributes
     */
    LAI_TRANSCEIVER_ATTR_END,

    /** Custom range base value */
    LAI_TRANSCEIVER_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    LAI_TRANSCEIVER_ATTR_CUSTOM_RANGE_END

} lai_transceiver_attr_t;

/**
 * @brief Transceiver counter IDs in lai_get_transceiver_stats() call
 *
 * @flags Contains flags
 */
typedef enum _lai_transceiver_stat_t
{
    /**
     * @brief Start of statistics
     */
    LAI_TRANSCEIVER_STAT_START,

    /**
     * @brief FEC uncorrectable words
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_TRANSCEIVER_STAT_FEC_UNCORRECTABLE_WORDS = LAI_TRANSCEIVER_STAT_START,

    /**
     * @brief Input power
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_TRANSCEIVER_STAT_INPUT_POWER,

    /**
     * @brief Output power
     *
     * @type lai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    LAI_TRANSCEIVER_STAT_OUTPUT_POWER,

    /**
     * @brief Laser bias current
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_TRANSCEIVER_STAT_LASER_BIAS_CURRENT,

    /**
     * @brief Transceiver temperature
     *
     * @type lai_double_t
     * @precision precision1
     * @iscounter false
     */
    LAI_TRANSCEIVER_STAT_TEMPERATURE,

    /**
     * @brief Bit error rate before forward error correction
     *
     * @type lai_double_t
     * @precision precision18
     * @iscounter false
     */
    LAI_TRANSCEIVER_STAT_PRE_FEC_BER,

    /**
     * @brief Bit error rate after forward error correction
     *
     * @type lai_double_t
     * @precision precision18
     * @iscounter false
     */
    LAI_TRANSCEIVER_STAT_POST_FEC_BER,

    /**
     * @brief EDFA bias current
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_TRANSCEIVER_STAT_EDFA_BIAS_CURRENT,

    /**
     * @brief Laser bias voltage
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_TRANSCEIVER_STAT_LASER_BIAS_VOLTAGE,

    /**
     * @brief Case temperature
     *
     * @type lai_double_t
     * @precision precision1
     * @iscounter false
     */
    LAI_TRANSCEIVER_STAT_CASE_TEMPERATURE,

    /**
     * @brief Power consumption
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_TRANSCEIVER_STAT_POWER_CONSUMPTION,

    /**
     * @brief Tx mod bias XI
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_TRANSCEIVER_STAT_TX_MOD_BIAS_XI,

    /**
     * @brief Tx mod bias XQ
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_TRANSCEIVER_STAT_TX_MOD_BIAS_XQ,

    /**
     * @brief Tx mod bias YI
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_TRANSCEIVER_STAT_TX_MOD_BIAS_YI,

    /**
     * @brief Tx mod bias YQ
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_TRANSCEIVER_STAT_TX_MOD_BIAS_YQ,

    /**
     * @brief Tx mod bias XPH
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_TRANSCEIVER_STAT_TX_MOD_BIAS_XPH,

    /**
     * @brief Tx mod bias YPH
     *
     * @type lai_double_t
     * @precision precision2
     * @iscounter false
     */
    LAI_TRANSCEIVER_STAT_TX_MOD_BIAS_YPH,

    /**
     * @brief Loss time
     *
     * @type lai_uint64_t
     * @iscounter true
     */
    LAI_TRANSCEIVER_STAT_LOSS_TIME,

    /**
     * @brief End of statistics
     */
    LAI_TRANSCEIVER_STAT_END,

} lai_transceiver_stat_t;

/**
 * @brief Create Transceiver.
 *
 * Allocates and initializes a transceiver.
 *
 * @param[out] transceiver_id Transceiver id
 * @param[in] linecard_id Linecard id on which the transceiver exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_create_transceiver_fn)(
        _Out_ lai_object_id_t *transceiver_id,
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Remove transceiver
 *
 * @param[in] transceiver_id Transceiver id
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_remove_transceiver_fn)(
        _In_ lai_object_id_t transceiver_id);

/**
 * @brief Set transceiver attribute
 *
 * @param[in] transceiver_id Transceiver id
 * @param[in] attr Attribute
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_set_transceiver_attribute_fn)(
        _In_ lai_object_id_t transceiver_id,
        _In_ const lai_attribute_t *attr);

/**
 * @brief Get transceiver attribute
 *
 * @param[in] transceiver_id Transceiver id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_transceiver_attribute_fn)(
        _In_ lai_object_id_t transceiver_id,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

/**
 * @brief Get transceiver counters. Deprecated for backward compatibility.
 *
 * @param[in] transceiver_id Transceiver id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_transceiver_stats_fn)(
        _In_ lai_object_id_t transceiver_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Get transceiver statistics counters extended.
 *
 * @param[in] transceiver_id Transceiver id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_transceiver_stats_ext_fn)(
        _In_ lai_object_id_t transceiver_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _In_ lai_stats_mode_t mode,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Clear transceiver statistics counters.
 *
 * @param[in] transceiver_id Transceiver id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_clear_transceiver_stats_fn)(
        _In_ lai_object_id_t transceiver_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with lai_api_query()
 */
typedef struct _lai_transceiver_api_t
{
    lai_create_transceiver_fn                create_transceiver;
    lai_remove_transceiver_fn                remove_transceiver;
    lai_set_transceiver_attribute_fn         set_transceiver_attribute;
    lai_get_transceiver_attribute_fn         get_transceiver_attribute;
    lai_get_transceiver_stats_fn             get_transceiver_stats;
    lai_get_transceiver_stats_ext_fn         get_transceiver_stats_ext;
    lai_clear_transceiver_stats_fn           clear_transceiver_stats;
} lai_transceiver_api_t;

/**
 * @}
 */
#endif /** __LAITRANSCEIVER_H_ */
