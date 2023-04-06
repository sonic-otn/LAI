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
 * @file    laiwss.h
 * @brief   This module defines the WSS for the LAI
 */

#if !defined (__LAIWSS_H_)
#define __LAIWSS_H_

#include <laitypes.h>

/**
 * @defgroup LAIWSS LAI - WSS specific API definitions
 *
 * @{
 */

/**
 * @brief WSS attribute IDs
 */
typedef enum _lai_wss_attr_t
{
    /**
     * @brief Start of attributes
     */
    LAI_WSS_ATTR_START,

    /**
     * @brief ID
     *
     * @type lai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    LAI_WSS_ATTR_ID = LAI_WSS_ATTR_START,

    /**
     * @brief Serial No
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_WSS_ATTR_SERIAL_NO,

    /**
     * @brief Part no
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_WSS_ATTR_PART_NO,

    /**
     * @brief Manufacture name
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_WSS_ATTR_MFG_NAME,

    /**
     * @brief Manufacture date
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_WSS_ATTR_MFG_DATE,

    /**
     * @brief Hardware version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_WSS_ATTR_HARDWARE_VERSION,

    /**
     * @brief The operational state of the WSS
     *
     * @type lai_oper_status_t
     * @flags READ_ONLY
     */
    LAI_WSS_ATTR_OPER_STATUS,

    /**
     * @brief Whether the WSS is present or not
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_WSS_ATTR_EMPTY,

    /**
     * @brief Whether the WSS is removable
     *
     * @type bool
     * @flags READ_ONLY
     */
    LAI_WSS_ATTR_REMOVABLE,

    /**
     * @brief Software version
     *
     * @type char
     * @flags READ_ONLY
     */
    LAI_WSS_ATTR_SOFTWARE_VERSION,

    /**
     * @brief End of attributes
     */
    LAI_WSS_ATTR_END,

    /** Custom range base value */
    LAI_WSS_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    LAI_WSS_ATTR_CUSTOM_RANGE_END

} lai_wss_attr_t;

/**
 * @brief WSS stat IDs
 *
 * @flags Contains flags
 */
typedef enum _lai_wss_stat_t
{
    /**
     * @brief Start of statistics
     */
    LAI_WSS_STAT_START,

    /**
     * @brief A placeholder
     *
     * @type lai_uint64_t
     */
    LAI_WSS_STAT_NOT_USE = LAI_WSS_STAT_START,

    /**
     * @brief End of statistics
     */
    LAI_WSS_STAT_END,

} lai_wss_stat_t;

/**
 * @brief Create WSS.
 *
 * Allocates and initializes a WSS.
 *
 * @param[out] wss_id WSS id
 * @param[in] linecard_id Linecard id on which the WSS exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_create_wss_fn)(
        _Out_ lai_object_id_t *wss_id,
        _In_ lai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

/**
 * @brief Remove WSS
 *
 * @param[in] wss_id WSS id
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_remove_wss_fn)(
        _In_ lai_object_id_t wss_id);

/**
 * @brief Set WSS attribute
 *
 * @param[in] wss_id WSS id
 * @param[in] attr Attribute
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_set_wss_attribute_fn)(
        _In_ lai_object_id_t wss_id,
        _In_ const lai_attribute_t *attr);

/**
 * @brief Get WSS attribute
 *
 * @param[in] wss_id WSS id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_wss_attribute_fn)(
        _In_ lai_object_id_t wss_id,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

/**
 * @brief Get WSS statistics.
 *
 * @param[in] wss_id WSS id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_wss_stats_fn)(
        _In_ lai_object_id_t wss_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Get WSS statistics extended.
 *
 * @param[in] wss_id WSS id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_get_wss_stats_ext_fn)(
        _In_ lai_object_id_t wss_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _In_ lai_stats_mode_t mode,
        _Out_ lai_stat_value_t *counters);

/**
 * @brief Clear WSS statistics counters.
 *
 * @param[in] wss_id WSS id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef lai_status_t (*lai_clear_wss_stats_fn)(
        _In_ lai_object_id_t wss_id,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with lai_api_query()
 */
typedef struct _lai_wss_api_t
{
    lai_create_wss_fn                create_wss;
    lai_remove_wss_fn                remove_wss;
    lai_set_wss_attribute_fn         set_wss_attribute;
    lai_get_wss_attribute_fn         get_wss_attribute;
    lai_get_wss_stats_fn             get_wss_stats;
    lai_get_wss_stats_ext_fn         get_wss_stats_ext;
    lai_clear_wss_stats_fn           clear_wss_stats;
} lai_wss_api_t;

/**
 * @}
 */
#endif /** __LAIWSS_H_ */
