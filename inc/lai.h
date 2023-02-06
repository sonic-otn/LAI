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
 * @file    lai.h
 *
 * @brief   This module defines an entry point into LAI-2.0
 */

#if !defined (__LAI_H_)
#define __LAI_H_

#include "laiobject.h"
#include "lailinecard.h"
#include "laiport.h"
#include "laitransceiver.h"
#include "lailogicalchannel.h"
#include "laiotn.h"
#include "laiethernet.h"
#include "laiphysicalchannel.h"
#include "laioch.h"
#include "lailldp.h"
#include "laiassignment.h"
#include "laistatus.h"
#include "laitypes.h"
#include "laiaps.h"
#include "laiapsport.h"
#include "laiattenuator.h"
#include "laiinterface.h"
#include "laioa.h"
#include "laiosc.h"
#include "laiwss.h"
#include "laimediachannel.h"
#include "laiocm.h"
#include "laiotdr.h"

/**
 * @defgroup LAI LAI - Entry point specific API definitions.
 *
 * @{
 */

/**
 * @brief Defined API sets have assigned IDs.
 *
 * If specific API method table changes in any way (method signature, number of
 * methods), a new ID needs to be created (e.g. PORT2) and old API still may
 * need to be supported for compatibility with older adapter hosts.
 */
typedef enum _lai_api_t
{
    LAI_API_UNSPECIFIED      =  0, /**< unspecified API */
    LAI_API_LINECARD         =  1, /**< lai_linecard_api_t */
    LAI_API_PORT             =  2, /**< lai_port_api_t */
    LAI_API_TRANSCEIVER      =  3, /**< lai_transceiver_api_t */
    LAI_API_LOGICALCHANNEL   =  4, /**< lai_logicalchannel_api_t */
    LAI_API_OTN              =  5, /**< lai_otn_api_t */
    LAI_API_ETHERNET         =  6, /**< lai_ethernet_api_t */
    LAI_API_PHYSICALCHANNEL  =  7, /**< lai_physicalchannel_api_t */
    LAI_API_OCH              =  8, /**< lai_och_api_t */
    LAI_API_LLDP             =  9, /**< lai_lldp_api_t */
    LAI_API_ASSIGNMENT       =  10, /**< lai_assignment_api_t */
    LAI_API_INTERFACE        =  11, /**< lai_interface_api_t */
    LAI_API_OA               =  12, /**< lai_oa_api_t */
    LAI_API_OSC              =  13, /**< lai_osc_api_t */
    LAI_API_APS              =  14, /**< lai_aps_api_t */
    LAI_API_APSPORT          =  15, /**< lai_apsport_api_t */
    LAI_API_ATTENUATOR       =  16, /**< lai_attenuator_api_t */
    LAI_API_WSS              =  17, /**< lai_wss_api_t */
    LAI_API_MEDIACHANNEL     =  18, /**< lai_mediachannel_api_t */
    LAI_API_OCM              =  19, /**< lai_ocm_api_t */
    LAI_API_OTDR             =  20, /**< lai_otdr_api_t */
    LAI_API_MAX              =  21, /**< total number of APIs */
} lai_api_t;

/**
 * @brief Defines the logging level.
 */
typedef enum _lai_log_level_t
{
    LAI_LOG_LEVEL_DEBUG,        /**< Debug logging level */
    LAI_LOG_LEVEL_INFO,         /**< Info logging level */
    LAI_LOG_LEVEL_NOTICE,       /**< Notice logging level */
    LAI_LOG_LEVEL_WARN,         /**< Warning logging level */
    LAI_LOG_LEVEL_ERROR,        /**< Error logging level */
    LAI_LOG_LEVEL_CRITICAL,     /**< Critical logging level */
    LAI_LOG_LEVEL_MAX           /**< Number of logging levels */
} lai_log_level_t;

typedef const char* (*lai_profile_get_value_fn)(
        _In_ lai_linecard_profile_id_t profile_id,
        _In_ const char *variable);

typedef int (*lai_profile_get_next_value_fn)(
        _In_ lai_linecard_profile_id_t profile_id,
        _Out_ const char **variable,
        _Out_ const char **value);

/**
 * @brief Method table that contains function pointers for services exposed by
 * adapter host for adapter.
 */
typedef struct _lai_service_method_table_t
{
    /**
     * @brief Get variable value given its name
     */
    lai_profile_get_value_fn        profile_get_value;

    /**
     * @brief Enumerate all the K/V pairs in a profile.
     *
     * Pointer to NULL passed as variable restarts enumeration. Function
     * returns 0 if next value exists, -1 at the end of the list.
     */
    lai_profile_get_next_value_fn   profile_get_next_value;

} lai_service_method_table_t;

/**
 * @brief Adapter linecard initialization call
 *
 * This is NOT for SDK initialization. This function allows the adapter to
 * initialize any data/control structures that may be necessary during
 * subsequent LAI operations.
 *
 * @param[in] flags Reserved for future use, must be zero
 * @param[in] services Methods table with services provided by adapter host
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
lai_status_t lai_api_initialize(
        _In_ uint64_t flags,
        _In_ const lai_service_method_table_t *services);

/**
 * @brief Retrieve a pointer to the C-style method table for desired LAI
 * functionality as specified by the given lai_api_id.
 *
 * @param[in] api The API ID whose method table is being retrieved.
 * @param[out] api_method_table Caller allocated method table. The table must
 * remain valid until the lai_api_uninitialize() is called.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
lai_status_t lai_api_query(
        _In_ lai_api_t api,
        _Out_ void **api_method_table);

/**
 * @brief Uninitialize adapter linecard. LAI functionalities,
 * retrieved via lai_api_query() cannot be used after this call.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
lai_status_t lai_api_uninitialize(void);

/**
 * @brief Set log level for LAI API module
 *
 * The default log level is #LAI_LOG_LEVEL_WARN.
 *
 * @param[in] api The API ID whose logging level is being set
 * @param[in] log_level Log level
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
lai_status_t lai_log_set(
        _In_ lai_api_t api,
        _In_ lai_log_level_t log_level);

/**
 * @brief Query LAI object type.
 *
 * @param[in] object_id Object id
 *
 * @return #LAI_OBJECT_TYPE_NULL when lai_object_id is not valid.
 * Otherwise, return a valid LAI object type LAI_OBJECT_TYPE_XXX.
 */
lai_object_type_t lai_object_type_query(
        _In_ lai_object_id_t object_id);

/**
 * @brief Query LAI linecard id.
 *
 * @param[in] object_id Object id
 *
 * @return #LAI_NULL_OBJECT_ID when lai_object_id is not valid.
 * Otherwise, return a valid LAI_OBJECT_TYPE_LINECARD object on which provided
 * object id belongs. If valid linecard id object is provided as input parameter
 * it should return itself.
 */
lai_object_id_t lai_linecard_id_query(
        _In_ lai_object_id_t object_id);

/**
 * @brief Link check.
 *
 * @param[out] up Whether link is up or not.
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
lai_status_t lai_link_check(
        _Out_ bool *up);

/**
 * @brief Generate dump file. The dump file may include LAI state information
 *        and vendor SDK information.
 *
 * @param[in] dump_file_name Full path for dump file
 *
 * @return #LAI_STATUS_SUCCESS on success, failure status code on error
 */
lai_status_t lai_dbg_generate_dump(
        _In_ const char *dump_file_name);

/**
 * @brief Get LAI object type resource availability.
 *
 * @param[in] linecard_gid LAI Linecard object id
 * @param[in] object_type LAI object type
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list List of attributes that to distinguish resource
 * @param[out] count Available objects left
 *
 * @return #LAI_STATUS_NOT_SUPPORTED if the given object type does not support resource accounting.
 * Otherwise, return #LAI_STATUS_SUCCESS.
 */
lai_status_t lai_object_type_get_availability(
        _In_ lai_object_id_t linecard_gid,
        _In_ lai_object_type_t object_type,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list,
        _Out_ uint64_t *count);

/**
 * @}
 */
#endif /** __LAI_H_ */
