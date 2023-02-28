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
 * @file    laiocm.h
 * @brief   This module defines the OCM for the LAI
 */

#if !defined (__LAIOCM_H_)
#define __LAIOCM_H_

#include <laitypes.h>

/**
 * @defgroup LAIOCM LAI - OCM specific API definitions
 *
 * @{
 */

/**
 * @brief OCM attribute IDs
 */
typedef enum _lai_ocm_attr_t
{
    /**
     * @brief Start of attributes
     */
    LAI_OCM_ATTR_START,

    /**
     * @brief Id
     *
     * @type lai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_OCM_ATTR_ID = LAI_OCM_ATTR_START,

    /**
     * @brief Monitor port
     *
     * @type char
     * @flags CREATE_AND_SET
     */
    LAI_OCM_ATTR_MONITOR_PORT,

    /**
     * @brief Serial No
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OCM_ATTR_SERIAL_NO,

    /**
     * @brief Part no
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OCM_ATTR_PART_NO,

    /**
     * @brief Manufacture name
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OCM_ATTR_MFG_NAME,

    /**
     * @brief Manufacture date
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OCM_ATTR_MFG_DATE,

    /**
     * @brief Hardware version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OCM_ATTR_HARDWARE_VERSION,

    /**
     * @brief The operational state of the OCM
     *
     * @type lai_oper_status_t
     * @flags READ_ONLY
     */
    LAI_OCM_ATTR_OPER_STATUS,

    /**
     * @brief Whether the OCM is present or not
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_OCM_ATTR_EMPTY,

    /**
     * @brief Whether the OCM is removable
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_OCM_ATTR_REMOVABLE,

    /**
     * @brief Software version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_OCM_ATTR_SOFTWARE_VERSION,

    /**
     * @brief Spectrum power
     *
     * @type lai_spectrum_power_list_t
     * @flags READ_ONLY
     */
    LAI_OCM_ATTR_SPECTRUM_POWER,

    /**
     * @brief End of attributes
     */
    LAI_OCM_ATTR_END,

    /** Custom range base value */
    LAI_OCM_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    LAI_OCM_ATTR_CUSTOM_RANGE_END

} lai_ocm_attr_t;

/**
 * @brief OCM stat IDs
 *
 * @flags Contains flags
 */
typedef enum _lai_ocm_stat_t
{
    /**
     * @brief Start of statistics
     */
    LAI_OCM_STAT_START,

    /**
     * @brief A placeholder
     *
     * @type lai_uint64_t
     */
    LAI_OCM_STAT_NOT_USE = LAI_OCM_STAT_START,

    /**
     * @brief End of statistics
     */
    LAI_OCM_STAT_END,

} lai_ocm_stat_t;

/**
 * @brief Create OCM.
 *
 * Allocates and initializes a OCM.
 *
 * @param[out] ocm_id OCM id
 * @param[in] linecard_id Linecard id on which the OCM exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_create_ocm_fn)(
        _Out_ lai_object_id_t *ocm_id,
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Remove OCM
 *
 * @param[in] ocm_id OCM id
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_remove_ocm_fn)(
        _In_ lai_object_id_t ocm_id);

/**
 * @brief Set OCM attribute
 *
 * @param[in] ocm_id OCM id
 * @param[in] attr Attribute
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_set_ocm_attribute_fn)(
        _In_ lai_object_id_t ocm_id,
        _In_ const lai_attribute_t *attr);

/**
 * @brief Get OCM attribute
 *
 * @param[in] ocm_id OCM id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_ocm_attribute_fn)(
        _In_ lai_object_id_t ocm_id,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

/**
 * @brief Get OCM statistics.
 *
 * @param[in] ocm_id OCM id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_ocm_stats_fn)(
        _In_ lai_object_id_t ocm_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Get OCM statistics extended.
 *
 * @param[in] ocm_id OCM id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_ocm_stats_ext_fn)(
        _In_ lai_object_id_t ocm_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _In_ lai_stats_mode_t mode,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Clear OCM statistics counters.
 *
 * @param[in] ocm_id OCM id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_clear_ocm_stats_fn)(
        _In_ lai_object_id_t ocm_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with lai_api_query()
 */
typedef struct _lai_ocm_api_t
{
    lai_create_ocm_fn                create_ocm;
    lai_remove_ocm_fn                remove_ocm;
    lai_set_ocm_attribute_fn         set_ocm_attribute;
    lai_get_ocm_attribute_fn         get_ocm_attribute;
    lai_get_ocm_stats_fn             get_ocm_stats;
    lai_get_ocm_stats_ext_fn         get_ocm_stats_ext;
    lai_clear_ocm_stats_fn           clear_ocm_stats;
} lai_ocm_api_t;

/**
 * @}
 */
#endif /** __LAIOCM_H_ */
