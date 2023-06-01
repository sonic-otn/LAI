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
 * @file    laimetadatatypes.h
 *
 * @brief   This module defines LAI Metadata Types
 */

#ifndef __LAIMETADATATYPES_H_
#define __LAIMETADATATYPES_H_

/**
 * @defgroup LAIMETADATATYPES LAI - Metadata Types Definitions
 *
 * @{
 */

/**
 * @def LAI_INVALID_ATTRIBUTE_ID
 */
#define LAI_INVALID_ATTRIBUTE_ID ((lai_attr_id_t)-1)

/**
 * @brief Defines object metadata key.
 */
typedef struct _lai_object_meta_key_t
{
    /**
     * @brief Object type.
     */
    lai_object_type_t           objecttype;

    /**
     * @brief The key.
     *
     * @passparam objecttype
     */
    lai_object_key_t            objectkey;

} lai_object_meta_key_t;

/**
 * @brief Defines attribute value type.
 * Can be used when serializing attributes.
 */
typedef enum _lai_attr_value_type_t
{
    /**
     * @brief Attribute value is unspecified
     */
    LAI_ATTR_VALUE_TYPE_UNSPECIFIED,

    /**
     * @brief Attribute value is bool.
     */
    LAI_ATTR_VALUE_TYPE_BOOL,

    /**
     * @brief Attribute value is char data.
     */
    LAI_ATTR_VALUE_TYPE_CHARDATA,

    /**
     * @brief Attribute value is 8 bit unsigned integer.
     */
    LAI_ATTR_VALUE_TYPE_UINT8,

    /**
     * @brief Attribute value is 8 bit signed integer.
     */
    LAI_ATTR_VALUE_TYPE_INT8,

    /**
     * @brief Attribute value is 16 bit unsigned integer.
     */
    LAI_ATTR_VALUE_TYPE_UINT16,

    /**
     * @brief Attribute value is 16 bit signed integer.
     */
    LAI_ATTR_VALUE_TYPE_INT16,

    /**
     * @brief Attribute value is 32 bit unsigned integer.
     */
    LAI_ATTR_VALUE_TYPE_UINT32,

    /**
     * @brief Attribute value is 32 bit signed integer.
     */
    LAI_ATTR_VALUE_TYPE_INT32,

    /**
     * @brief Attribute value is 64 bit unsigned integer.
     */
    LAI_ATTR_VALUE_TYPE_UINT64,

    /**
     * @brief Attribute value is 64 bit signed integer.
     */
    LAI_ATTR_VALUE_TYPE_INT64,

    /**
     * @brief Attribute value is double.
     */
    LAI_ATTR_VALUE_TYPE_DOUBLE,

    /**
     * @brief Attribute value is pointer address.
     */
    LAI_ATTR_VALUE_TYPE_POINTER,

    /**
     * @brief Attribute value is object id.
     */
    LAI_ATTR_VALUE_TYPE_OBJECT_ID,

    /**
     * @brief Attribute value is object list.
     */
    LAI_ATTR_VALUE_TYPE_OBJECT_LIST,

    /**
     * @brief Attribute value is list of 8 bit unsigned integers.
     */
    LAI_ATTR_VALUE_TYPE_UINT8_LIST,

    /**
     * @brief Attribute value is list of 8 bit signed integers.
     */
    LAI_ATTR_VALUE_TYPE_INT8_LIST,

    /**
     * @brief Attribute value is list of 16 bit unsigned integers.
     */
    LAI_ATTR_VALUE_TYPE_UINT16_LIST,

    /**
     * @brief Attribute value is list of 16 bit signed integers.
     */
    LAI_ATTR_VALUE_TYPE_INT16_LIST,

    /**
     * @brief Attribute value is list of 32 bit unsigned integers.
     */
    LAI_ATTR_VALUE_TYPE_UINT32_LIST,

    /**
     * @brief Attribute value is list of 32 bit signed integers.
     */
    LAI_ATTR_VALUE_TYPE_INT32_LIST,

    /**
     * @brief Attribute value is 32 bit unsigned integer range.
     */
    LAI_ATTR_VALUE_TYPE_UINT32_RANGE,

    /**
     * @brief Attribute value is 32 bit signed integer range.
     */
    LAI_ATTR_VALUE_TYPE_INT32_RANGE,

    /**
     * @brief Attribute value is spectrum power list.
     */
    LAI_ATTR_VALUE_TYPE_SPECTRUM_POWER_LIST,

} lai_attr_value_type_t;

/**
 * @brief Defines statistics value type.
 */
typedef enum _lai_stat_value_type_t
{
    /**
     * @brief Statistics value is 32 bit signed integer.
     */
    LAI_STAT_VALUE_TYPE_INT32,

    /**
     * @brief Statistics value is 32 bit unsigned integer.
     */
    LAI_STAT_VALUE_TYPE_UINT32,

    /**
     * @brief Statistics value is 64 bit signed integer.
     */
    LAI_STAT_VALUE_TYPE_INT64,

    /**
     * @brief Statistics value is 64 bit unsigned integer.
     */
    LAI_STAT_VALUE_TYPE_UINT64,

    /**
     * @brief Statistics value is double.
     */
    LAI_STAT_VALUE_TYPE_DOUBLE,

} lai_stat_value_type_t;

/**
 * @brief Defines statistics value unit.
 */
typedef enum _lai_stat_value_unit_t
{
    /**
     * @brief Value unit is not dBm or dB.
     */
    LAI_STAT_VALUE_UNIT_NORMAL,

    /**
     * @brief Value unit is dBm.
     */
    LAI_STAT_VALUE_UNIT_DBM,

    /**
     * @brief Value unit is dB.
     */
    LAI_STAT_VALUE_UNIT_DB,

} lai_stat_value_unit_t;

/**
 * @brief Defines statistics value precision.
 */
typedef enum _lai_stat_value_precision_t
{
    /**
     * @brief Value with 0 decimal precision.
     */
    LAI_STAT_VALUE_PRECISION_0,

    /**
     * @brief Value with 1 decimal precision.
     */
    LAI_STAT_VALUE_PRECISION_1,

    /**
     * @brief Value with 2 decimal precision.
     */
    LAI_STAT_VALUE_PRECISION_2,

    /**
     * @brief Value with 18 decimal precision.
     */
    LAI_STAT_VALUE_PRECISION_18,

} lai_stat_value_precision_t;

/**
 * @brief Attribute flags.
 *
 * @flags Contains flags
 */
typedef enum _lai_attr_flags_t
{
    /**
     * @brief Mandatory on create flag.
     *
     * Attribute with this flag is mandatory when calling CREATE API, unless
     * this attribute is marked as conditional. Must be combined with
     * CREATE_ONLY or CREATE_AND_SET flag.
     */
    LAI_ATTR_FLAGS_MANDATORY_ON_CREATE = (1 << 0),

    /**
     * @brief Create only flag.
     *
     * Attribute with this flag can only be created and its value cannot be
     * changed by SET API. Can be combined with MANDATORY flag. If
     * attribute is not combined with MANDATORY flag then DEFAULT value must be
     * provided for this attribute.
     */
    LAI_ATTR_FLAGS_CREATE_ONLY         = (1 << 1),

    /**
     * @brief Create and set flag.
     *
     * Attribute with this flag can be created and after creation value may be
     * modified using SET API. Can be combined with MANDATORY flag. If
     * attribute is not combined with MANDATORY flag then DEFAULT value must be
     * provided for this attribute.
     */
    LAI_ATTR_FLAGS_CREATE_AND_SET      = (1 << 2),

    /**
     * @brief Read only flag.
     *
     * Attribute with this flag can only be read using GET API. Creation and
     * modification is not possible. Can be combined with DYNAMIC flag for
     * example counter attribute.
     */
    LAI_ATTR_FLAGS_READ_ONLY           = (1 << 3),

    /**
     * @brief Key flag.
     *
     * Attribute with this flag is treated as unique key (can only be combined
     * with MANDATORY and CREATE_ONLY flags. This flag will indicate that
     * creating new object with the same key will fail (for example VLAN).
     * There may be more than one key in attributes when creating object. Key
     * should be used only on primitive attribute values (like enum or int).
     * In some cases it may be supported on list (for port lanes) but then
     * extra logic is needed to compute and handle that key.
     *
     * If multiple keys are provided, meta key is created as combination of
     * keys in order attribute ids are declared (internal details).
     */
    LAI_ATTR_FLAGS_KEY                 = (1 << 4),

    /**
     * @brief Dynamic flag.
     *
     * Attribute with this flag indicates that value of the attribute is
     * dynamic and can change in time (like an attribute counter value, or port
     * operational status). Change may happen independently or when other
     * attribute was created or modified (creating vlan member will change vlan
     * member list). Can be combined with READ_ONLY flag.
     */
    LAI_ATTR_FLAGS_DYNAMIC             = (1 << 5),

    /**
     * @brief Special flag.
     *
     * Attribute with this flag will indicate that this attribute is special
     * and it needs extended logic to be handled. This flag can only be
     * standalone.
     */
    LAI_ATTR_FLAGS_SPECIAL             = (1 << 6),

    /**
     * @brief Set only flag.
     *
     * Attribute with this flag can only be wrote using SET API. Read is not
     * possible.
     */
    LAI_ATTR_FLAGS_SET_ONLY           = (1 << 7),

} lai_attr_flags_t;

/**
 * @def Defines helper to check if mandatory on create flag is set.
 */
#define LAI_HAS_FLAG_MANDATORY_ON_CREATE(x)   (((x) & LAI_ATTR_FLAGS_MANDATORY_ON_CREATE) == LAI_ATTR_FLAGS_MANDATORY_ON_CREATE)

/**
 * @def Defines helper to check if create only flag is set.
 */
#define LAI_HAS_FLAG_CREATE_ONLY(x)           (((x) & LAI_ATTR_FLAGS_CREATE_ONLY) == LAI_ATTR_FLAGS_CREATE_ONLY)

/**
 * @def Defines helper to check if create and set flag is set.
 */
#define LAI_HAS_FLAG_CREATE_AND_SET(x)        (((x) & LAI_ATTR_FLAGS_CREATE_AND_SET) == LAI_ATTR_FLAGS_CREATE_AND_SET)

/**
 * @def Defines helper to check if read only flag is set.
 */
#define LAI_HAS_FLAG_READ_ONLY(x)             (((x) & LAI_ATTR_FLAGS_READ_ONLY) == LAI_ATTR_FLAGS_READ_ONLY)

/**
 * @def Defines helper to check if write only flag is set.
 */
#define LAI_HAS_FLAG_SET_ONLY(x)             (((x) & LAI_ATTR_FLAGS_SET_ONLY) == LAI_ATTR_FLAGS_SET_ONLY)

/**
 * @def Defines helper to check if key flag is set.
 */
#define LAI_HAS_FLAG_KEY(x)                   (((x) & LAI_ATTR_FLAGS_KEY) == LAI_ATTR_FLAGS_KEY)

/**
 * @def Defines helper to check if dynamic flag is set.
 */
#define LAI_HAS_FLAG_DYNAMIC(x)               (((x) & LAI_ATTR_FLAGS_DYNAMIC) == LAI_ATTR_FLAGS_DYNAMIC)

/**
 * @def Defines helper to check if special flag is set.
 */
#define LAI_HAS_FLAG_SPECIAL(x)               (((x) & LAI_ATTR_FLAGS_SPECIAL) == LAI_ATTR_FLAGS_SPECIAL)

/**
 * @brief Defines default value type.
 */
typedef enum _lai_default_value_type_t
{
    /**
     * @brief There is no default value.
     *
     * This must be assigned on MANDATORY_ON_CREATE
     * attributes.
     */
    LAI_DEFAULT_VALUE_TYPE_NONE = 0,

    /**
     * @brief Default value is just a const value.
     */
    LAI_DEFAULT_VALUE_TYPE_CONST,

    /**
     * @brief Value must be in range provided by other attribute.
     *
     * Usually value is provided by module object.
     * Range can be obtained by GET API.
     * Usually default value is minimum of range.
     */
    LAI_DEFAULT_VALUE_TYPE_ATTR_RANGE,

    /**
     * @brief Default value is equal to other attribute value.
     *
     * Usually value is provided by module object.
     * Can be obtained using GET API.
     */
    LAI_DEFAULT_VALUE_TYPE_ATTR_VALUE,

    /**
     * @brief Default value is just empty list.
     */
    LAI_DEFAULT_VALUE_TYPE_EMPTY_LIST,

    /**
     * @brief Default value is vendor specific.
     *
     * This value is assigned by module vendor
     * like default module MAC address.
     *
     * It can also be default created object
     * like default hash.
     *
     * Vendor specific should be different
     * from default objects that are created
     * by default.
     */
    LAI_DEFAULT_VALUE_TYPE_VENDOR_SPECIFIC,

    /**
     * @brief This object is created by default
     * inside linecard (hidden object, like default hash or port).
     *
     * Should be used only on object id types.
     */
    LAI_DEFAULT_VALUE_TYPE_LINECARD_INTERNAL,

} lai_default_value_type_t;

/**
 * @brief Defines attribute condition type.
 */
typedef enum _lai_attr_condition_type_t
{
    /**
     * @brief This attribute is not conditional attribute
     */
    LAI_ATTR_CONDITION_TYPE_NONE = 0,

    /**
     * @brief Any condition that will be true will make
     * this attribute mandatory.
     */
    LAI_ATTR_CONDITION_TYPE_OR,

    /**
     * @brief All conditions must meet for this attribute
     * to be mandatory on create.
     */
    LAI_ATTR_CONDITION_TYPE_AND,

} lai_attr_condition_type_t;

/**
 * @brief Defines attribute condition.
 */
typedef struct _lai_attr_condition_t
{
    /**
     * @brief Specifies valid attribute id for this object type.
     * Attribute is for the same object type.
     */
    lai_attr_id_t                       attrid;

    /**
     * @brief Condition value that attribute will be mandatory
     * then default value must be provided for attribute.
     */
    const lai_attribute_value_t         condition;

    /*
     * In future we can add condition operator like equal, not equal, etc.
     */

} lai_attr_condition_t;

/**
 * @brief Defines enum metadata information.
 */
typedef struct _lai_enum_metadata_t
{
    /**
     * @brief String representation of enum type definition.
     */
    const char* const               name;

    /**
     * @brief Values count in enum.
     */
    const size_t                    valuescount;

    /**
     * @brief Array of enum values.
     */
    const int* const                values;

    /**
     * @brief Array of enum values string names.
     */
    const char* const* const        valuesnames;

    /**
     * @brief Array of enum values string short names.
     */
    const char* const* const        valuesshortnames;

    /**
     * @brief Indicates whether enumeration contains flags.
     *
     * When set to true numbers of enumeration are not continuous.
     */
    bool                            containsflags;

    /**
     * @brief Array of enum ignored values.
     */
    const int* const                ignorevalues;

    /**
     * @brief Array of enum ignored values string names.
     */
    const char* const* const        ignorevaluesnames;

} lai_enum_metadata_t;

/**
 * @brief Defines attribute capability metadata.
 */
typedef struct _lai_attr_capability_metadata_t
{
    /**
     * @brief Vendor ID.
     *
     * Used to distinguish different capabilities of
     * the same attribute for different ASIC instances.
     */
    uint64_t                    vendorid;

    /**
     * @brief Operation capability.
     *
     * Defines which operation is supported on specific attribute.
     */
    lai_attr_capability_t       operationcapability;

    /**
     * @brief Enum values count.
     *
     * When attribute is and enum, this list defines
     * enum values supported by vendor on that attribute.
     */
    const size_t                enumvaluescount;

    /**
     * @brief Enum values count.
     */
    const int* const            enumvalues;

} lai_attr_capability_metadata_t;

/**
 * @brief Defines statistics metadata.
 */
typedef struct _lai_stat_metadata_t
{
    /**
     * @brief Specifies valid LAI object type.
     */
    lai_object_type_t                           objecttype;

    /**
     * @brief Specifies valid statistics id for this object type.
     */
    lai_stat_id_t                               statid;

    /**
     * @brief Specifies valid statistics id name for this object type.
     */
    const char* const                           statidname;

    /**
     * @brief Specifies valid statistics id name of kebab case naming style.
     */
    const char* const                           statidkebabname;

    /**
     * @brief Specifies valid statistics id name of camel case naming style.
     */
    const char* const                           statidcamelname;

    /**
     * @brief Specifies value type for this statistics.
     */
    lai_stat_value_type_t                       statvaluetype;

    /**
     * @brief Specifies value unit for this statistics.
     */
    lai_stat_value_unit_t                       statvalueunit;

    /**
     * @brief Specifies value precision for this statistics.
     */
    lai_stat_value_precision_t                  statvalueprecision;

    /**
     * @brief Determines whether value is counter.
     */
    bool                                        statvalueiscounter;

} lai_stat_metadata_t;

/**
 * @brief Defines attribute metadata.
 */
typedef struct _lai_attr_metadata_t
{
    /**
     * @brief Specifies valid LAI object type.
     */
    lai_object_type_t                           objecttype;

    /**
     * @brief Specifies valid attribute id for this object type.
     */
    lai_attr_id_t                               attrid;

    /**
     * @brief Specifies valid attribute id name for this object type.
     */
    const char* const                           attridname;

    /**
     * @brief Specifies valid short attribute id name for this object type.
     */
    const char* const                           attridshortname;

    /**
     * @brief Extracted brief description from Doxygen comment.
     */
    const char* const                           brief;

    /**
     * @brief Specifies attribute value type for this attribute.
     */
    lai_attr_value_type_t                       attrvaluetype;

    /**
     * @brief Specifies internal attribute value type for attr list attribute.
     */
    lai_attr_value_type_t                       attrlistvaluetype;

    /**
     * @brief Specifies flags for this attribute.
     */
    lai_attr_flags_t                            flags;

    /**
     * @brief Specified allowed object types.
     *
     * If object attr value type is OBJECT_ID
     * this list specifies what object type can be used.
     */
    const lai_object_type_t* const              allowedobjecttypes;

    /**
     * @brief Length of allowed object types.
     */
    size_t                                      allowedobjecttypeslength;

    /**
     * @brief Allows repetitions on object list.
     *
     * Can be useful when using object id list.
     */
    bool                                        allowrepetitiononlist;

    /**
     * @brief Allows mixed object id types on list
     * like port and LAG.
     */
    bool                                        allowmixedobjecttypes;

    /**
     * @brief Allows empty list to be set on list value type.
     */
    bool                                        allowemptylist;

    /**
     * @brief Allows null object id to be passed.
     *
     * If object attr value type is OBJECT_ID
     * it tells whether LAI_NULL_OBJECT_ID can be used
     * as actual id.
     */
    bool                                        allownullobjectid;

    /**
     * @brief Determines whether attribute contains OIDs
     */
    bool                                        isoidattribute;

    /**
     * @brief Specifies default value type.
     *
     * Default value can be a const assigned by module
     * (which is not known at compile), can be obtained
     * by GET API, or a min/max value in specific
     * range also assigned by module at run time.
     *
     * Default value can be also an object id.
     */
    const lai_default_value_type_t              defaultvaluetype;

    /**
     * @brief Provides default value.
     *
     * If creation flag is CREATE_ONLY or CREATE_AND_SET
     * then default value must be provided for attribute.
     *
     * @note Default value may not apply for ACL field
     * or ACL entry, need special care.
     */
    const lai_attribute_value_t* const          defaultvalue;

    /**
     * @brief Default value object type.
     *
     * Required when default value type is pointing to
     * different object type.
     */
    lai_object_type_t                           defaultvalueobjecttype;

    /**
     * @brief Default value object id.
     *
     * Required when default value type is pointing to
     * different object attribute.
     */
    lai_attr_id_t                               defaultvalueattrid;

    /**
     * @brief Indicates whether default value needs to be saved.
     *
     * When module is created some objects are created internally like vlan 1,
     * vlan members, bridge port, virtual router etc. Some of those objects
     * has attributes assigned by vendor like module MAC address. When user
     * changes that value then there is no way to go back and set it's previous
     * value if user didn't query it first. This member will indicate whether
     * user needs to query it first (and store) before change, if he wants to
     * bring original attribute value later.
     *
     * Some of those attributes can be OID attributes with flags
     * MANDATORY_ON_CREATE and CREATE_AND_SET.
     */
    bool                                        storedefaultvalue;

    /**
     * @brief Indicates whether attribute is enum value.
     *
     * Attribute type must be set as INT32.
     *
     * @note Could be deduced from enum type string or
     * enum vector values and attr value type.
     */
    bool                                        isenum;

    /**
     * @brief Indicates whether attribute is enum list value.
     *
     * Attribute value must be set INT32 LIST.
     *
     * @note Could be deduced from enum type string or
     * enum vector values and attr value type.
     */
    bool                                        isenumlist;

    /**
     * @brief Provides enum metadata if attribute
     * is enum or enum list.
     */
    const lai_enum_metadata_t* const            enummetadata;

    /**
     * @brief Specifies condition type of attribute.
     *
     * @note Currently all conditions are "OR" conditions
     * so we can deduce if this is conditional type
     * if any conditions are defined.
     */
    lai_attr_condition_type_t                   conditiontype;

    /**
     * @brief Provide conditions for attribute under
     * which this attribute will be mandatory on create.
     */
    const lai_attr_condition_t* const* const    conditions;

    /**
     * @brief Length of the conditions.
     */
    size_t                                      conditionslength;

    /**
     * @brief Indicates whether attribute is conditional.
     */
    bool                                        isconditional;

    /**
     * @brief Specifies valid only type of attribute.
     *
     * @note Currently all valid only are "OR" conditions
     * so we can deduce if this is conditional type
     * if any conditions are defined.
     */
    lai_attr_condition_type_t                   validonlytype;

    /**
     * @brief Provides conditions when this attribute is valid.
     *
     * If conditions are specified (OR condition assumed)
     * then this attribute is only valid when different
     * attribute has condition value set. Valid only
     * attribute (against we check) can be dynamic so
     * this attribute can't be marked as MANDATORY on
     * create since default value will be required.
     *
     * @note There is only handful of attributes with
     * valid only mark. For now we will check that in
     * specific attribute logic.
     */
    const lai_attr_condition_t* const* const    validonly;

    /**
     * @brief Length of the valid only when conditions.
     */
    size_t                                      validonlylength;

    /**
     * @brief Indicates whether attribute is valid only.
     */
    bool                                        isvalidonly;

    /**
     * @brief When calling GET API result will be put
     * in local db for future use (extra logic).
     *
     * This flag must be taken with care, since when set
     * on dynamic attribute it may provide inconsistent data.
     *
     * Value should be updated after successful set or remove.
     */
    bool                                        getsave;

    /**
     * @brief Determines whether value is vlan.
     *
     * Can only be set on lai_uint16_t value type.
     */
    bool                                        isvlan;

    /**
     * @brief Determines whether attribute is ACL field
     *
     * This will become handy for fast determination whether
     * default value is present.
     */
    bool                                        isaclfield;

    /**
     * @brief Determines whether attribute is ACL action
     *
     * This will become handy for fast determination whether
     * default value is present.
     */
    bool                                        isaclaction;

    /**
     * @brief Determines whether attribute is mandatory on create
     */
    bool                                        ismandatoryoncreate;

    /**
     * @brief Determines whether attribute is create only
     */
    bool                                        iscreateonly;

    /**
     * @brief Determines whether attribute is create and set
     */
    bool                                        iscreateandset;

    /**
     * @brief Determines whether attribute is read only
     */
    bool                                        isreadonly;

    /**
     * @brief Determines whether attribute is set only
     */
    bool                                        issetonly;

    /**
     * @brief Determines whether attribute is key
     */
    bool                                        iskey;

    /**
     * @brief Determines whether attribute value is primitive.
     *
     * Primitive values will not contain any pointers so value can be
     * transferred by regular assignment operator.
     */
    bool                                        isprimitive;

    /**
     * @brief Notification type
     *
     * If attribute value type is POINTER then attribute
     * value is pointer to module notification.
     * Enum lai_module_notification_type_t is auto generated
     * so it can't be used here, int will be used instead.
     */
    int                                         notificationtype;

    /**
     * @brief Is callback function.
     *
     * Set to true if attribute is callback function but not notification.
     */
    bool                                        iscallback;

    /**
     * @brief Attribute capabilities.
     *
     * Represents attribute capability for each specific ASIC. Since each
     * vendor may support different capabilities for each attribute, this field
     * is optional. Also, since LAI API supports multiple modules (module ids)
     * at the same time, then modules may support different capabilities on
     * different attributes. Vendor ID is provided inside capability struct for
     * difference.
     *
     * This data is designed for vendor internal usage.
     */
    const lai_attr_capability_metadata_t* const* const capability;

    /**
     * @brief Length of attribute capabilities.
     */
    size_t                                      capabilitylength;

    /**
     * @brief Indicates whether attribute is extension attribute.
     */
    bool                                        isextensionattr;

    /**
     * @brief Tells if attribute is a resource type.
     *
     * If true, attribute is used in getting object type availability
     * to distinguish between pools of resources.
     */
    bool                                        isresourcetype;

    /**
     * @brief Indicates whether attribute is deprecated.
     *
     * If true, attribute is deprecated and should not be used. Is up to vendor
     * to check this field and give run time warning about this attribute.
     */
    bool                                        isdeprecated;

    /**
     * @brief Specifies kebab name for this object type.
     */
    const char* const                           attridkebabname;

    /**
     * @brief Indicates whether attribute is recoverable.
     *
     * If true, when calling SET API successfully, the value will be saved in local
     * db for warm-reboot (or cold-reboot) flow to recover this configuration.
     */
    bool                                        isrecoverable;

} lai_attr_metadata_t;

/*
 * TODO since non object id members can have different type and can be located
 * at different object_key union position, we need to find a way to extract
 * those for automatic serialize/deserialize for example extracting value as
 * lai_attribute_value_t and pointing to right serialize/deserialize functions.
 * Also, an automatic generated functions for serialize/deserialize for those non
 * object id structures must be generated, we don't want to update them manually.
 */

/**
 * @brief Function definition for getting object id from non object
 * id structure member.
 *
 * @param[in] object_meta_key Object meta key
 *
 * @return Object id from struct member
 */
typedef lai_object_id_t (*lai_meta_get_struct_member_oid_fn)(
        _In_ const lai_object_meta_key_t *object_meta_key);

/**
 * @brief Function definition for setting object id from non object
 * id structure member.
 *
 * @param[inout] object_meta_key Object meta key
 * @param[in] object_id Object id to be set
 */
typedef void (*lai_meta_set_struct_member_oid_fn)(
        _Inout_ lai_object_meta_key_t *object_meta_key,
        _In_ lai_object_id_t object_id);

/**
 * @brief Defines struct member info for
 * non object id object type
 */
typedef struct _lai_struct_member_info_t
{
    /**
     * @brief Member value type
     */
    lai_attr_value_type_t                               membervaluetype;

    /**
     * @brief Member name
     */
    const char* const                                   membername;

    /**
     * @brief Specified allowed object types.
     *
     * If object attr value type is OBJECT_ID
     * this list specifies what object type can be used.
     */
    const lai_object_type_t* const                      allowedobjecttypes;

    /**
     * @brief Length of allowed object types.
     */
    size_t                                              allowedobjecttypeslength;

    /**
     * @brief Indicates whether member is enum value.
     *
     * Type must be set as INT32.
     *
     * @note Could be deduced from enum type string or
     * enum vector values and attr value type.
     */
    bool                                                isenum;

    /**
     * @brief Provides enum metadata if member is enum
     */
    const lai_enum_metadata_t* const                    enummetadata;

    /**
     * @brief If struct member is OID this function
     * will get its value.
     */
    const lai_meta_get_struct_member_oid_fn             getoid;

    /**
     * @brief If struct member is OID this function
     * will set its value.
     */
    const lai_meta_set_struct_member_oid_fn             setoid;

    /**
     * @brief Member offset from the struct beginning in bytes.
     *
     * Macro offsetof is used to calculate this field, and it value can be
     * different depending on compiler setting for struct packing.
     */
    size_t                                              offset;

    /**
     * @brief Member size using sizeof operator.
     */
    size_t                                              size;

} lai_struct_member_info_t;

/**
 * @brief LAI reverse graph member
 */
typedef struct _lai_rev_graph_member_t
{
    /**
     * @brief Defines main object type which is used
     * by dependency object type.
     */
    lai_object_type_t                       objecttype;

    /**
     * @brief Defines dependency object type on which
     * is object type defined above is used.
     */
    lai_object_type_t                       depobjecttype;

    /**
     * @brief Defines attribute metadata for object type
     *
     * This can be NULL if dependency object type
     * is non object id type and dependency is on
     * defined struct.
     */
    const lai_attr_metadata_t* const        attrmetadata;

    /**
     * @brief Defines struct member for non object
     * id object type.
     *
     * This member can be NULL if dependency object type
     * is object attribute, and is not NULL id object
     * dependency is non object id struct member.
     */
    const lai_struct_member_info_t* const   structmember;

} lai_rev_graph_member_t;

/*
 * Generic QUAD API definitions. All APIs can be called using this quad generic
 * functions.
 *
 * When creating module object or non object id module_id parameter is ignored,
 * and can be NULL. Currently object type inside lai_object_meta_key_t is
 * ignored and can be skipped.
 *
 * This generic quad API will help us later to call any API, without doing any
 * module cases for calling different signature functions including non object
 * id structures. Also, later we will generate automatic serialize and
 * deserialize methods for non object id which will deserialize data to object
 * union in lai_object_meta_key_t to right place.
 */

typedef lai_status_t (*lai_meta_generic_create_fn)(
        _Inout_ lai_object_meta_key_t *meta_key,
        _In_ lai_object_id_t module_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

typedef lai_status_t (*lai_meta_generic_remove_fn)(
        _In_ const lai_object_meta_key_t *meta_key);

typedef lai_status_t (*lai_meta_generic_set_fn)(
        _In_ const lai_object_meta_key_t *meta_key,
        _In_ const lai_attribute_t *attr);

typedef lai_status_t (*lai_meta_generic_get_fn)(
        _In_ const lai_object_meta_key_t *meta_key,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

typedef lai_status_t (*lai_meta_generic_get_stats_fn)(
        _In_ const lai_object_meta_key_t *meta_key,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _Out_ lai_stat_value_t *counters);

typedef lai_status_t (*lai_meta_generic_get_stats_ext_fn)(
        _In_ const lai_object_meta_key_t *meta_key,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids,
        _In_ lai_stats_mode_t mode,
        _Out_ lai_stat_value_t *counters);

typedef lai_status_t (*lai_meta_generic_clear_stats_fn)(
        _In_ const lai_object_meta_key_t *meta_key,
        _In_ uint32_t number_of_counters,
        _In_ const lai_stat_id_t *counter_ids);

typedef lai_status_t (*lai_generic_create_fn)(
        _Out_ lai_object_id_t *object_id,
        _In_ lai_object_id_t module_id,
        _In_ uint32_t attr_count,
        _In_ const lai_attribute_t *attr_list);

typedef lai_status_t (*lai_generic_remove_fn)(
        _In_ lai_object_id_t object_id);

typedef lai_status_t (*lai_generic_set_fn)(
        _In_ lai_object_id_t object_id,
        _In_ const lai_attribute_t *attr);

typedef lai_status_t (*lai_generic_get_fn)(
        _In_ lai_object_id_t object_id,
        _In_ uint32_t attr_count,
        _Inout_ lai_attribute_t *attr_list);

/**
 * @brief LAI object type information
 */
typedef struct _lai_object_type_info_t
{
    /**
     * @brief Object Type
     */
    lai_object_type_t                               objecttype;

    /**
     * @brief Object Type name
     */
    const char* const                               objecttypename;

    /**
     * @brief Start of attributes *_START
     */
    lai_attr_id_t                                   attridstart;

    /**
     * @brief End of attributes *_END
     */
    lai_attr_id_t                                   attridend;

    /**
     * @brief Provides enum metadata if attribute
     * is enum or enum list.
     */
    const lai_enum_metadata_t* const                enummetadata;

    /**
     * @brief Attributes metadata
     */
    const lai_attr_metadata_t* const* const         attrmetadata;

    /**
     * @brief Attributes metadata length.
     */
    size_t                                          attrmetadatalength;

    /**
     * @brief Indicates if object is using struct
     * instead of actual object id
     */
    bool                                            isnonobjectid;

    /**
     * @brief Indicates if object is OID object
     */
    bool                                            isobjectid;

    /**
     * @brief Defines all struct members
     */
    const lai_struct_member_info_t* const* const    structmembers;

    /**
     * @brief Defines count of struct members
     */
    size_t                                          structmemberscount;

    /**
     * @brief Defines reverse dependency graph members
     */
    const lai_rev_graph_member_t* const* const      revgraphmembers;

    /**
     * @brief Defines reverse dependency graph members count.
     */
    size_t                                          revgraphmemberscount;

    /**
     * @brief Create function pointer.
     */
    const lai_meta_generic_create_fn                create;

    /**
     * @brief Remove function pointer.
     */
    const lai_meta_generic_remove_fn                remove;

    /**
     * @brief Set function pointer.
     */
    const lai_meta_generic_set_fn                   set;

    /**
     * @brief Get function pointer
     */
    const lai_meta_generic_get_fn                   get;

    /**
     * @brief Get stats function pointer.
     */
    const lai_meta_generic_get_stats_fn             getstats;

    /**
     * @brief Get stats extended function pointer.
     */
    const lai_meta_generic_get_stats_ext_fn         getstatsext;

    /**
     * @brief Clear stats function pointer
     */
    const lai_meta_generic_clear_stats_fn           clearstats;

    /**
     * @brief Indicates whether object type is experimental.
     */
    bool                                            isexperimental;

    /**
     * @brief Points to enum lai_OBJECT_TYPE_stat_t if object supports stats.
     */
    const lai_enum_metadata_t* const                statenum;

    /**
     * @brief Points to enum lai_OBJECT_TYPE_alarm_t if object supports alarms.
     */
    const lai_enum_metadata_t* const                alarmenum;

} lai_object_type_info_t;

/**
 * @}
 */
#endif /** __LAIMETADATATYPES_H_ */
