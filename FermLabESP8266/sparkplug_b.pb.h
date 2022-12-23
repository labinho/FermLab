/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.7-dev */

#ifndef PB_ORG_ECLIPSE_TAHU_PROTOBUF_SPARKPLUG_B_PB_H_INCLUDED
#define PB_ORG_ECLIPSE_TAHU_PROTOBUF_SPARKPLUG_B_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _org_eclipse_tahu_protobuf_DataType { /* Indexes of Data Types */
    /* Unknown placeholder for future expansion. */
    org_eclipse_tahu_protobuf_DataType_Unknown = 0,
    /* Basic Types */
    org_eclipse_tahu_protobuf_DataType_Int8 = 1,
    org_eclipse_tahu_protobuf_DataType_Int16 = 2,
    org_eclipse_tahu_protobuf_DataType_Int32 = 3,
    org_eclipse_tahu_protobuf_DataType_Int64 = 4,
    org_eclipse_tahu_protobuf_DataType_UInt8 = 5,
    org_eclipse_tahu_protobuf_DataType_UInt16 = 6,
    org_eclipse_tahu_protobuf_DataType_UInt32 = 7,
    org_eclipse_tahu_protobuf_DataType_UInt64 = 8,
    org_eclipse_tahu_protobuf_DataType_Float = 9,
    org_eclipse_tahu_protobuf_DataType_Double = 10,
    org_eclipse_tahu_protobuf_DataType_Boolean = 11,
    org_eclipse_tahu_protobuf_DataType_String = 12,
    org_eclipse_tahu_protobuf_DataType_DateTime = 13,
    org_eclipse_tahu_protobuf_DataType_Text = 14,
    /* Additional Metric Types */
    org_eclipse_tahu_protobuf_DataType_UUID = 15,
    org_eclipse_tahu_protobuf_DataType_DataSet = 16,
    org_eclipse_tahu_protobuf_DataType_Bytes = 17,
    org_eclipse_tahu_protobuf_DataType_File = 18,
    org_eclipse_tahu_protobuf_DataType_Template = 19,
    /* Additional PropertyValue Types */
    org_eclipse_tahu_protobuf_DataType_PropertySet = 20,
    org_eclipse_tahu_protobuf_DataType_PropertySetList = 21,
    /* Array Types */
    org_eclipse_tahu_protobuf_DataType_Int8Array = 22,
    org_eclipse_tahu_protobuf_DataType_Int16Array = 23,
    org_eclipse_tahu_protobuf_DataType_Int32Array = 24,
    org_eclipse_tahu_protobuf_DataType_Int64Array = 25,
    org_eclipse_tahu_protobuf_DataType_UInt8Array = 26,
    org_eclipse_tahu_protobuf_DataType_UInt16Array = 27,
    org_eclipse_tahu_protobuf_DataType_UInt32Array = 28,
    org_eclipse_tahu_protobuf_DataType_UInt64Array = 29,
    org_eclipse_tahu_protobuf_DataType_FloatArray = 30,
    org_eclipse_tahu_protobuf_DataType_DoubleArray = 31,
    org_eclipse_tahu_protobuf_DataType_BooleanArray = 32,
    org_eclipse_tahu_protobuf_DataType_StringArray = 33,
    org_eclipse_tahu_protobuf_DataType_DateTimeArray = 34
} org_eclipse_tahu_protobuf_DataType;

/* Struct definitions */
typedef struct _org_eclipse_tahu_protobuf_Payload {
    bool has_timestamp;
    uint64_t timestamp; /* Timestamp at message sending time */
    pb_callback_t metrics; /* Repeated forever - no limit in Google Protobufs */
    bool has_seq;
    uint64_t seq; /* Sequence number */
    pb_callback_t uuid; /* UUID to track message type in terms of schema definitions */
    pb_callback_t body; /* To optionally bypass the whole definition above */
    pb_extension_t *extensions;
} org_eclipse_tahu_protobuf_Payload;

typedef struct _org_eclipse_tahu_protobuf_Payload_Template {
    pb_callback_t version; /* The version of the Template to prevent mismatches */
    pb_callback_t metrics; /* Each metric includes a name, datatype, and optionally a value */
    pb_callback_t parameters;
    pb_callback_t template_ref; /* MUST be a reference to a template definition if this is an instance (i.e. the name of the template definition) - MUST be omitted for template definitions */
    bool has_is_definition;
    bool is_definition;
    pb_extension_t *extensions;
} org_eclipse_tahu_protobuf_Payload_Template;

typedef struct _org_eclipse_tahu_protobuf_Payload_Template_Parameter_ParameterValueExtension {
    pb_extension_t *extensions;
} org_eclipse_tahu_protobuf_Payload_Template_Parameter_ParameterValueExtension;

typedef struct _org_eclipse_tahu_protobuf_Payload_Template_Parameter {
    pb_callback_t name;
    bool has_type;
    uint32_t type;
    pb_size_t which_value;
    union {
        uint32_t int_value;
        uint64_t long_value;
        float float_value;
        double double_value;
        bool boolean_value;
        pb_callback_t string_value;
        org_eclipse_tahu_protobuf_Payload_Template_Parameter_ParameterValueExtension extension_value;
    } value;
} org_eclipse_tahu_protobuf_Payload_Template_Parameter;

typedef struct _org_eclipse_tahu_protobuf_Payload_DataSet {
    bool has_num_of_columns;
    uint64_t num_of_columns;
    pb_callback_t columns;
    pb_callback_t types;
    pb_callback_t rows;
    pb_extension_t *extensions;
} org_eclipse_tahu_protobuf_Payload_DataSet;

typedef struct _org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_DataSetValueExtension {
    pb_extension_t *extensions;
} org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_DataSetValueExtension;

typedef struct _org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue {
    pb_size_t which_value;
    union {
        uint32_t int_value;
        uint64_t long_value;
        float float_value;
        double double_value;
        bool boolean_value;
        pb_callback_t string_value;
        org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_DataSetValueExtension extension_value;
    } value;
} org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue;

typedef struct _org_eclipse_tahu_protobuf_Payload_DataSet_Row {
    pb_callback_t elements;
    pb_extension_t *extensions;
} org_eclipse_tahu_protobuf_Payload_DataSet_Row;

typedef struct _org_eclipse_tahu_protobuf_Payload_PropertyValue_PropertyValueExtension {
    pb_extension_t *extensions;
} org_eclipse_tahu_protobuf_Payload_PropertyValue_PropertyValueExtension;

typedef struct _org_eclipse_tahu_protobuf_Payload_PropertySet {
    pb_callback_t keys; /* Names of the properties */
    pb_callback_t values;
    pb_extension_t *extensions;
} org_eclipse_tahu_protobuf_Payload_PropertySet;

typedef struct _org_eclipse_tahu_protobuf_Payload_PropertySetList {
    pb_callback_t propertyset;
    pb_extension_t *extensions;
} org_eclipse_tahu_protobuf_Payload_PropertySetList;

typedef struct _org_eclipse_tahu_protobuf_Payload_PropertyValue {
    bool has_type;
    uint32_t type;
    bool has_is_null;
    bool is_null;
    pb_size_t which_value;
    union {
        uint32_t int_value;
        uint64_t long_value;
        float float_value;
        double double_value;
        bool boolean_value;
        pb_callback_t string_value;
        org_eclipse_tahu_protobuf_Payload_PropertySet propertyset_value;
        org_eclipse_tahu_protobuf_Payload_PropertySetList propertysets_value; /* List of Property Values */
        org_eclipse_tahu_protobuf_Payload_PropertyValue_PropertyValueExtension extension_value;
    } value;
} org_eclipse_tahu_protobuf_Payload_PropertyValue;

typedef struct _org_eclipse_tahu_protobuf_Payload_MetaData {
    /* Bytes specific metadata */
    bool has_is_multi_part;
    bool is_multi_part;
    /* General metadata */
    pb_callback_t content_type; /* Content/Media type */
    bool has_size;
    uint64_t size; /* File size, String size, Multi-part size, etc */
    bool has_seq;
    uint64_t seq; /* Sequence number for multi-part messages */
    /* File metadata */
    pb_callback_t file_name; /* File name */
    pb_callback_t file_type; /* File type (i.e. xml, json, txt, cpp, etc) */
    pb_callback_t md5; /* md5 of data */
    /* Catchalls and future expansion */
    pb_callback_t description; /* Could be anything such as json or xml of custom properties */
    pb_extension_t *extensions;
} org_eclipse_tahu_protobuf_Payload_MetaData;

typedef struct _org_eclipse_tahu_protobuf_Payload_Metric_MetricValueExtension {
    pb_extension_t *extensions;
} org_eclipse_tahu_protobuf_Payload_Metric_MetricValueExtension;

typedef struct _org_eclipse_tahu_protobuf_Payload_Metric {
    pb_callback_t name; /* Metric name - should only be included on birth */
    bool has_alias;
    uint64_t alias; /* Metric alias - tied to name on birth and included in all later DATA messages */
    bool has_timestamp;
    uint64_t timestamp; /* Timestamp associated with data acquisition time */
    bool has_datatype;
    uint32_t datatype; /* DataType of the metric/tag value */
    bool has_is_historical;
    bool is_historical; /* If this is historical data and should not update real time tag */
    bool has_is_transient;
    bool is_transient; /* Tells consuming clients such as MQTT Engine to not store this as a tag */
    bool has_is_null;
    bool is_null; /* If this is null - explicitly say so rather than using -1, false, etc for some datatypes. */
    bool has_metadata;
    org_eclipse_tahu_protobuf_Payload_MetaData metadata; /* Metadata for the payload */
    bool has_properties;
    org_eclipse_tahu_protobuf_Payload_PropertySet properties;
    pb_size_t which_value;
    union {
        uint32_t int_value;
        uint64_t long_value;
        float float_value;
        double double_value;
        bool boolean_value;
        pb_callback_t string_value;
        pb_callback_t bytes_value; /* Bytes, File */
        org_eclipse_tahu_protobuf_Payload_DataSet dataset_value;
        org_eclipse_tahu_protobuf_Payload_Template template_value;
        org_eclipse_tahu_protobuf_Payload_Metric_MetricValueExtension extension_value;
    } value;
} org_eclipse_tahu_protobuf_Payload_Metric;


#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _org_eclipse_tahu_protobuf_DataType_MIN org_eclipse_tahu_protobuf_DataType_Unknown
#define _org_eclipse_tahu_protobuf_DataType_MAX org_eclipse_tahu_protobuf_DataType_DateTimeArray
#define _org_eclipse_tahu_protobuf_DataType_ARRAYSIZE ((org_eclipse_tahu_protobuf_DataType)(org_eclipse_tahu_protobuf_DataType_DateTimeArray+1))

















/* Initializer values for message structs */
#define org_eclipse_tahu_protobuf_Payload_init_default {false, 0, {{NULL}, NULL}, false, 0, {{NULL}, NULL}, {{NULL}, NULL}, NULL}
#define org_eclipse_tahu_protobuf_Payload_Template_init_default {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false, 0, NULL}
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_init_default {{{NULL}, NULL}, false, 0, 0, {0}}
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_ParameterValueExtension_init_default {NULL}
#define org_eclipse_tahu_protobuf_Payload_DataSet_init_default {false, 0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, NULL}
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_init_default {0, {0}}
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_DataSetValueExtension_init_default {NULL}
#define org_eclipse_tahu_protobuf_Payload_DataSet_Row_init_default {{{NULL}, NULL}, NULL}
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_init_default {false, 0, false, 0, 0, {0}}
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_PropertyValueExtension_init_default {NULL}
#define org_eclipse_tahu_protobuf_Payload_PropertySet_init_default {{{NULL}, NULL}, {{NULL}, NULL}, NULL}
#define org_eclipse_tahu_protobuf_Payload_PropertySetList_init_default {{{NULL}, NULL}, NULL}
#define org_eclipse_tahu_protobuf_Payload_MetaData_init_default {false, 0, {{NULL}, NULL}, false, 0, false, 0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, NULL}
#define org_eclipse_tahu_protobuf_Payload_Metric_init_default {{{NULL}, NULL}, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, org_eclipse_tahu_protobuf_Payload_MetaData_init_default, false, org_eclipse_tahu_protobuf_Payload_PropertySet_init_default, 0, {0}}
#define org_eclipse_tahu_protobuf_Payload_Metric_MetricValueExtension_init_default {NULL}
#define org_eclipse_tahu_protobuf_Payload_init_zero {false, 0, {{NULL}, NULL}, false, 0, {{NULL}, NULL}, {{NULL}, NULL}, NULL}
#define org_eclipse_tahu_protobuf_Payload_Template_init_zero {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false, 0, NULL}
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_init_zero {{{NULL}, NULL}, false, 0, 0, {0}}
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_ParameterValueExtension_init_zero {NULL}
#define org_eclipse_tahu_protobuf_Payload_DataSet_init_zero {false, 0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, NULL}
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_init_zero {0, {0}}
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_DataSetValueExtension_init_zero {NULL}
#define org_eclipse_tahu_protobuf_Payload_DataSet_Row_init_zero {{{NULL}, NULL}, NULL}
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_init_zero {false, 0, false, 0, 0, {0}}
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_PropertyValueExtension_init_zero {NULL}
#define org_eclipse_tahu_protobuf_Payload_PropertySet_init_zero {{{NULL}, NULL}, {{NULL}, NULL}, NULL}
#define org_eclipse_tahu_protobuf_Payload_PropertySetList_init_zero {{{NULL}, NULL}, NULL}
#define org_eclipse_tahu_protobuf_Payload_MetaData_init_zero {false, 0, {{NULL}, NULL}, false, 0, false, 0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, NULL}
#define org_eclipse_tahu_protobuf_Payload_Metric_init_zero {{{NULL}, NULL}, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, org_eclipse_tahu_protobuf_Payload_MetaData_init_zero, false, org_eclipse_tahu_protobuf_Payload_PropertySet_init_zero, 0, {0}}
#define org_eclipse_tahu_protobuf_Payload_Metric_MetricValueExtension_init_zero {NULL}

/* Field tags (for use in manual encoding/decoding) */
#define org_eclipse_tahu_protobuf_Payload_timestamp_tag 1
#define org_eclipse_tahu_protobuf_Payload_metrics_tag 2
#define org_eclipse_tahu_protobuf_Payload_seq_tag 3
#define org_eclipse_tahu_protobuf_Payload_uuid_tag 4
#define org_eclipse_tahu_protobuf_Payload_body_tag 5
#define org_eclipse_tahu_protobuf_Payload_Template_version_tag 1
#define org_eclipse_tahu_protobuf_Payload_Template_metrics_tag 2
#define org_eclipse_tahu_protobuf_Payload_Template_parameters_tag 3
#define org_eclipse_tahu_protobuf_Payload_Template_template_ref_tag 4
#define org_eclipse_tahu_protobuf_Payload_Template_is_definition_tag 5
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_name_tag 1
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_type_tag 2
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_int_value_tag 3
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_long_value_tag 4
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_float_value_tag 5
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_double_value_tag 6
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_boolean_value_tag 7
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_string_value_tag 8
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_extension_value_tag 9
#define org_eclipse_tahu_protobuf_Payload_DataSet_num_of_columns_tag 1
#define org_eclipse_tahu_protobuf_Payload_DataSet_columns_tag 2
#define org_eclipse_tahu_protobuf_Payload_DataSet_types_tag 3
#define org_eclipse_tahu_protobuf_Payload_DataSet_rows_tag 4
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_int_value_tag 1
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_long_value_tag 2
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_float_value_tag 3
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_double_value_tag 4
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_boolean_value_tag 5
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_string_value_tag 6
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_extension_value_tag 7
#define org_eclipse_tahu_protobuf_Payload_DataSet_Row_elements_tag 1
#define org_eclipse_tahu_protobuf_Payload_PropertySet_keys_tag 1
#define org_eclipse_tahu_protobuf_Payload_PropertySet_values_tag 2
#define org_eclipse_tahu_protobuf_Payload_PropertySetList_propertyset_tag 1
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_type_tag 1
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_is_null_tag 2
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_int_value_tag 3
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_long_value_tag 4
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_float_value_tag 5
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_double_value_tag 6
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_boolean_value_tag 7
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_string_value_tag 8
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_propertyset_value_tag 9
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_propertysets_value_tag 10
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_extension_value_tag 11
#define org_eclipse_tahu_protobuf_Payload_MetaData_is_multi_part_tag 1
#define org_eclipse_tahu_protobuf_Payload_MetaData_content_type_tag 2
#define org_eclipse_tahu_protobuf_Payload_MetaData_size_tag 3
#define org_eclipse_tahu_protobuf_Payload_MetaData_seq_tag 4
#define org_eclipse_tahu_protobuf_Payload_MetaData_file_name_tag 5
#define org_eclipse_tahu_protobuf_Payload_MetaData_file_type_tag 6
#define org_eclipse_tahu_protobuf_Payload_MetaData_md5_tag 7
#define org_eclipse_tahu_protobuf_Payload_MetaData_description_tag 8
#define org_eclipse_tahu_protobuf_Payload_Metric_name_tag 1
#define org_eclipse_tahu_protobuf_Payload_Metric_alias_tag 2
#define org_eclipse_tahu_protobuf_Payload_Metric_timestamp_tag 3
#define org_eclipse_tahu_protobuf_Payload_Metric_datatype_tag 4
#define org_eclipse_tahu_protobuf_Payload_Metric_is_historical_tag 5
#define org_eclipse_tahu_protobuf_Payload_Metric_is_transient_tag 6
#define org_eclipse_tahu_protobuf_Payload_Metric_is_null_tag 7
#define org_eclipse_tahu_protobuf_Payload_Metric_metadata_tag 8
#define org_eclipse_tahu_protobuf_Payload_Metric_properties_tag 9
#define org_eclipse_tahu_protobuf_Payload_Metric_int_value_tag 10
#define org_eclipse_tahu_protobuf_Payload_Metric_long_value_tag 11
#define org_eclipse_tahu_protobuf_Payload_Metric_float_value_tag 12
#define org_eclipse_tahu_protobuf_Payload_Metric_double_value_tag 13
#define org_eclipse_tahu_protobuf_Payload_Metric_boolean_value_tag 14
#define org_eclipse_tahu_protobuf_Payload_Metric_string_value_tag 15
#define org_eclipse_tahu_protobuf_Payload_Metric_bytes_value_tag 16
#define org_eclipse_tahu_protobuf_Payload_Metric_dataset_value_tag 17
#define org_eclipse_tahu_protobuf_Payload_Metric_template_value_tag 18
#define org_eclipse_tahu_protobuf_Payload_Metric_extension_value_tag 19

/* Struct field encoding specification for nanopb */
#define org_eclipse_tahu_protobuf_Payload_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT64,   timestamp,         1) \
X(a, CALLBACK, REPEATED, MESSAGE,  metrics,           2) \
X(a, STATIC,   OPTIONAL, UINT64,   seq,               3) \
X(a, CALLBACK, OPTIONAL, STRING,   uuid,              4) \
X(a, CALLBACK, OPTIONAL, BYTES,    body,              5) \
X(a, CALLBACK, OPTIONAL, EXTENSION, extensions,        6)
#define org_eclipse_tahu_protobuf_Payload_CALLBACK pb_default_field_callback
#define org_eclipse_tahu_protobuf_Payload_DEFAULT NULL
#define org_eclipse_tahu_protobuf_Payload_metrics_MSGTYPE org_eclipse_tahu_protobuf_Payload_Metric

#define org_eclipse_tahu_protobuf_Payload_Template_FIELDLIST(X, a) \
X(a, CALLBACK, OPTIONAL, STRING,   version,           1) \
X(a, CALLBACK, REPEATED, MESSAGE,  metrics,           2) \
X(a, CALLBACK, REPEATED, MESSAGE,  parameters,        3) \
X(a, CALLBACK, OPTIONAL, STRING,   template_ref,      4) \
X(a, STATIC,   OPTIONAL, BOOL,     is_definition,     5) \
X(a, CALLBACK, OPTIONAL, EXTENSION, extensions,        6)
#define org_eclipse_tahu_protobuf_Payload_Template_CALLBACK pb_default_field_callback
#define org_eclipse_tahu_protobuf_Payload_Template_DEFAULT NULL
#define org_eclipse_tahu_protobuf_Payload_Template_metrics_MSGTYPE org_eclipse_tahu_protobuf_Payload_Metric
#define org_eclipse_tahu_protobuf_Payload_Template_parameters_MSGTYPE org_eclipse_tahu_protobuf_Payload_Template_Parameter

#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_FIELDLIST(X, a) \
X(a, CALLBACK, OPTIONAL, STRING,   name,              1) \
X(a, STATIC,   OPTIONAL, UINT32,   type,              2) \
X(a, STATIC,   ONEOF,    UINT32,   (value,int_value,value.int_value),   3) \
X(a, STATIC,   ONEOF,    UINT64,   (value,long_value,value.long_value),   4) \
X(a, STATIC,   ONEOF,    FLOAT,    (value,float_value,value.float_value),   5) \
X(a, STATIC,   ONEOF,    DOUBLE,   (value,double_value,value.double_value),   6) \
X(a, STATIC,   ONEOF,    BOOL,     (value,boolean_value,value.boolean_value),   7) \
X(a, CALLBACK, ONEOF,    STRING,   (value,string_value,value.string_value),   8) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,extension_value,value.extension_value),   9)
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_CALLBACK pb_default_field_callback
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_DEFAULT NULL
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_value_extension_value_MSGTYPE org_eclipse_tahu_protobuf_Payload_Template_Parameter_ParameterValueExtension

#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_ParameterValueExtension_FIELDLIST(X, a) \
X(a, CALLBACK, OPTIONAL, EXTENSION, extensions,        1)
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_ParameterValueExtension_CALLBACK pb_default_field_callback
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_ParameterValueExtension_DEFAULT NULL

#define org_eclipse_tahu_protobuf_Payload_DataSet_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT64,   num_of_columns,    1) \
X(a, CALLBACK, REPEATED, STRING,   columns,           2) \
X(a, CALLBACK, REPEATED, UINT32,   types,             3) \
X(a, CALLBACK, REPEATED, MESSAGE,  rows,              4) \
X(a, CALLBACK, OPTIONAL, EXTENSION, extensions,        5)
#define org_eclipse_tahu_protobuf_Payload_DataSet_CALLBACK pb_default_field_callback
#define org_eclipse_tahu_protobuf_Payload_DataSet_DEFAULT NULL
#define org_eclipse_tahu_protobuf_Payload_DataSet_rows_MSGTYPE org_eclipse_tahu_protobuf_Payload_DataSet_Row

#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    UINT32,   (value,int_value,value.int_value),   1) \
X(a, STATIC,   ONEOF,    UINT64,   (value,long_value,value.long_value),   2) \
X(a, STATIC,   ONEOF,    FLOAT,    (value,float_value,value.float_value),   3) \
X(a, STATIC,   ONEOF,    DOUBLE,   (value,double_value,value.double_value),   4) \
X(a, STATIC,   ONEOF,    BOOL,     (value,boolean_value,value.boolean_value),   5) \
X(a, CALLBACK, ONEOF,    STRING,   (value,string_value,value.string_value),   6) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,extension_value,value.extension_value),   7)
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_CALLBACK pb_default_field_callback
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_DEFAULT NULL
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_value_extension_value_MSGTYPE org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_DataSetValueExtension

#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_DataSetValueExtension_FIELDLIST(X, a) \
X(a, CALLBACK, OPTIONAL, EXTENSION, extensions,        1)
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_DataSetValueExtension_CALLBACK pb_default_field_callback
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_DataSetValueExtension_DEFAULT NULL

#define org_eclipse_tahu_protobuf_Payload_DataSet_Row_FIELDLIST(X, a) \
X(a, CALLBACK, REPEATED, MESSAGE,  elements,          1) \
X(a, CALLBACK, OPTIONAL, EXTENSION, extensions,        2)
#define org_eclipse_tahu_protobuf_Payload_DataSet_Row_CALLBACK pb_default_field_callback
#define org_eclipse_tahu_protobuf_Payload_DataSet_Row_DEFAULT NULL
#define org_eclipse_tahu_protobuf_Payload_DataSet_Row_elements_MSGTYPE org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue

#define org_eclipse_tahu_protobuf_Payload_PropertyValue_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT32,   type,              1) \
X(a, STATIC,   OPTIONAL, BOOL,     is_null,           2) \
X(a, STATIC,   ONEOF,    UINT32,   (value,int_value,value.int_value),   3) \
X(a, STATIC,   ONEOF,    UINT64,   (value,long_value,value.long_value),   4) \
X(a, STATIC,   ONEOF,    FLOAT,    (value,float_value,value.float_value),   5) \
X(a, STATIC,   ONEOF,    DOUBLE,   (value,double_value,value.double_value),   6) \
X(a, STATIC,   ONEOF,    BOOL,     (value,boolean_value,value.boolean_value),   7) \
X(a, CALLBACK, ONEOF,    STRING,   (value,string_value,value.string_value),   8) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,propertyset_value,value.propertyset_value),   9) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,propertysets_value,value.propertysets_value),  10) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,extension_value,value.extension_value),  11)
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_CALLBACK pb_default_field_callback
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_DEFAULT NULL
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_value_propertyset_value_MSGTYPE org_eclipse_tahu_protobuf_Payload_PropertySet
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_value_propertysets_value_MSGTYPE org_eclipse_tahu_protobuf_Payload_PropertySetList
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_value_extension_value_MSGTYPE org_eclipse_tahu_protobuf_Payload_PropertyValue_PropertyValueExtension

#define org_eclipse_tahu_protobuf_Payload_PropertyValue_PropertyValueExtension_FIELDLIST(X, a) \
X(a, CALLBACK, OPTIONAL, EXTENSION, extensions,        1)
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_PropertyValueExtension_CALLBACK pb_default_field_callback
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_PropertyValueExtension_DEFAULT NULL

#define org_eclipse_tahu_protobuf_Payload_PropertySet_FIELDLIST(X, a) \
X(a, CALLBACK, REPEATED, STRING,   keys,              1) \
X(a, CALLBACK, REPEATED, MESSAGE,  values,            2) \
X(a, CALLBACK, OPTIONAL, EXTENSION, extensions,        3)
#define org_eclipse_tahu_protobuf_Payload_PropertySet_CALLBACK pb_default_field_callback
#define org_eclipse_tahu_protobuf_Payload_PropertySet_DEFAULT NULL
#define org_eclipse_tahu_protobuf_Payload_PropertySet_values_MSGTYPE org_eclipse_tahu_protobuf_Payload_PropertyValue

#define org_eclipse_tahu_protobuf_Payload_PropertySetList_FIELDLIST(X, a) \
X(a, CALLBACK, REPEATED, MESSAGE,  propertyset,       1) \
X(a, CALLBACK, OPTIONAL, EXTENSION, extensions,        2)
#define org_eclipse_tahu_protobuf_Payload_PropertySetList_CALLBACK pb_default_field_callback
#define org_eclipse_tahu_protobuf_Payload_PropertySetList_DEFAULT NULL
#define org_eclipse_tahu_protobuf_Payload_PropertySetList_propertyset_MSGTYPE org_eclipse_tahu_protobuf_Payload_PropertySet

#define org_eclipse_tahu_protobuf_Payload_MetaData_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, BOOL,     is_multi_part,     1) \
X(a, CALLBACK, OPTIONAL, STRING,   content_type,      2) \
X(a, STATIC,   OPTIONAL, UINT64,   size,              3) \
X(a, STATIC,   OPTIONAL, UINT64,   seq,               4) \
X(a, CALLBACK, OPTIONAL, STRING,   file_name,         5) \
X(a, CALLBACK, OPTIONAL, STRING,   file_type,         6) \
X(a, CALLBACK, OPTIONAL, STRING,   md5,               7) \
X(a, CALLBACK, OPTIONAL, STRING,   description,       8) \
X(a, CALLBACK, OPTIONAL, EXTENSION, extensions,        9)
#define org_eclipse_tahu_protobuf_Payload_MetaData_CALLBACK pb_default_field_callback
#define org_eclipse_tahu_protobuf_Payload_MetaData_DEFAULT NULL

#define org_eclipse_tahu_protobuf_Payload_Metric_FIELDLIST(X, a) \
X(a, CALLBACK, OPTIONAL, STRING,   name,              1) \
X(a, STATIC,   OPTIONAL, UINT64,   alias,             2) \
X(a, STATIC,   OPTIONAL, UINT64,   timestamp,         3) \
X(a, STATIC,   OPTIONAL, UINT32,   datatype,          4) \
X(a, STATIC,   OPTIONAL, BOOL,     is_historical,     5) \
X(a, STATIC,   OPTIONAL, BOOL,     is_transient,      6) \
X(a, STATIC,   OPTIONAL, BOOL,     is_null,           7) \
X(a, STATIC,   OPTIONAL, MESSAGE,  metadata,          8) \
X(a, STATIC,   OPTIONAL, MESSAGE,  properties,        9) \
X(a, STATIC,   ONEOF,    UINT32,   (value,int_value,value.int_value),  10) \
X(a, STATIC,   ONEOF,    UINT64,   (value,long_value,value.long_value),  11) \
X(a, STATIC,   ONEOF,    FLOAT,    (value,float_value,value.float_value),  12) \
X(a, STATIC,   ONEOF,    DOUBLE,   (value,double_value,value.double_value),  13) \
X(a, STATIC,   ONEOF,    BOOL,     (value,boolean_value,value.boolean_value),  14) \
X(a, CALLBACK, ONEOF,    STRING,   (value,string_value,value.string_value),  15) \
X(a, CALLBACK, ONEOF,    BYTES,    (value,bytes_value,value.bytes_value),  16) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,dataset_value,value.dataset_value),  17) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,template_value,value.template_value),  18) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,extension_value,value.extension_value),  19)
#define org_eclipse_tahu_protobuf_Payload_Metric_CALLBACK pb_default_field_callback
#define org_eclipse_tahu_protobuf_Payload_Metric_DEFAULT NULL
#define org_eclipse_tahu_protobuf_Payload_Metric_metadata_MSGTYPE org_eclipse_tahu_protobuf_Payload_MetaData
#define org_eclipse_tahu_protobuf_Payload_Metric_properties_MSGTYPE org_eclipse_tahu_protobuf_Payload_PropertySet
#define org_eclipse_tahu_protobuf_Payload_Metric_value_dataset_value_MSGTYPE org_eclipse_tahu_protobuf_Payload_DataSet
#define org_eclipse_tahu_protobuf_Payload_Metric_value_template_value_MSGTYPE org_eclipse_tahu_protobuf_Payload_Template
#define org_eclipse_tahu_protobuf_Payload_Metric_value_extension_value_MSGTYPE org_eclipse_tahu_protobuf_Payload_Metric_MetricValueExtension

#define org_eclipse_tahu_protobuf_Payload_Metric_MetricValueExtension_FIELDLIST(X, a) \
X(a, CALLBACK, OPTIONAL, EXTENSION, extensions,        1)
#define org_eclipse_tahu_protobuf_Payload_Metric_MetricValueExtension_CALLBACK pb_default_field_callback
#define org_eclipse_tahu_protobuf_Payload_Metric_MetricValueExtension_DEFAULT NULL

extern const pb_msgdesc_t org_eclipse_tahu_protobuf_Payload_msg;
extern const pb_msgdesc_t org_eclipse_tahu_protobuf_Payload_Template_msg;
extern const pb_msgdesc_t org_eclipse_tahu_protobuf_Payload_Template_Parameter_msg;
extern const pb_msgdesc_t org_eclipse_tahu_protobuf_Payload_Template_Parameter_ParameterValueExtension_msg;
extern const pb_msgdesc_t org_eclipse_tahu_protobuf_Payload_DataSet_msg;
extern const pb_msgdesc_t org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_msg;
extern const pb_msgdesc_t org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_DataSetValueExtension_msg;
extern const pb_msgdesc_t org_eclipse_tahu_protobuf_Payload_DataSet_Row_msg;
extern const pb_msgdesc_t org_eclipse_tahu_protobuf_Payload_PropertyValue_msg;
extern const pb_msgdesc_t org_eclipse_tahu_protobuf_Payload_PropertyValue_PropertyValueExtension_msg;
extern const pb_msgdesc_t org_eclipse_tahu_protobuf_Payload_PropertySet_msg;
extern const pb_msgdesc_t org_eclipse_tahu_protobuf_Payload_PropertySetList_msg;
extern const pb_msgdesc_t org_eclipse_tahu_protobuf_Payload_MetaData_msg;
extern const pb_msgdesc_t org_eclipse_tahu_protobuf_Payload_Metric_msg;
extern const pb_msgdesc_t org_eclipse_tahu_protobuf_Payload_Metric_MetricValueExtension_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define org_eclipse_tahu_protobuf_Payload_fields &org_eclipse_tahu_protobuf_Payload_msg
#define org_eclipse_tahu_protobuf_Payload_Template_fields &org_eclipse_tahu_protobuf_Payload_Template_msg
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_fields &org_eclipse_tahu_protobuf_Payload_Template_Parameter_msg
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_ParameterValueExtension_fields &org_eclipse_tahu_protobuf_Payload_Template_Parameter_ParameterValueExtension_msg
#define org_eclipse_tahu_protobuf_Payload_DataSet_fields &org_eclipse_tahu_protobuf_Payload_DataSet_msg
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_fields &org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_msg
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_DataSetValueExtension_fields &org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_DataSetValueExtension_msg
#define org_eclipse_tahu_protobuf_Payload_DataSet_Row_fields &org_eclipse_tahu_protobuf_Payload_DataSet_Row_msg
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_fields &org_eclipse_tahu_protobuf_Payload_PropertyValue_msg
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_PropertyValueExtension_fields &org_eclipse_tahu_protobuf_Payload_PropertyValue_PropertyValueExtension_msg
#define org_eclipse_tahu_protobuf_Payload_PropertySet_fields &org_eclipse_tahu_protobuf_Payload_PropertySet_msg
#define org_eclipse_tahu_protobuf_Payload_PropertySetList_fields &org_eclipse_tahu_protobuf_Payload_PropertySetList_msg
#define org_eclipse_tahu_protobuf_Payload_MetaData_fields &org_eclipse_tahu_protobuf_Payload_MetaData_msg
#define org_eclipse_tahu_protobuf_Payload_Metric_fields &org_eclipse_tahu_protobuf_Payload_Metric_msg
#define org_eclipse_tahu_protobuf_Payload_Metric_MetricValueExtension_fields &org_eclipse_tahu_protobuf_Payload_Metric_MetricValueExtension_msg

/* Maximum encoded size of messages (where known) */
/* org_eclipse_tahu_protobuf_Payload_size depends on runtime parameters */
/* org_eclipse_tahu_protobuf_Payload_Template_size depends on runtime parameters */
/* org_eclipse_tahu_protobuf_Payload_Template_Parameter_size depends on runtime parameters */
/* org_eclipse_tahu_protobuf_Payload_DataSet_size depends on runtime parameters */
/* org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_size depends on runtime parameters */
/* org_eclipse_tahu_protobuf_Payload_DataSet_Row_size depends on runtime parameters */
/* org_eclipse_tahu_protobuf_Payload_PropertyValue_size depends on runtime parameters */
/* org_eclipse_tahu_protobuf_Payload_PropertySet_size depends on runtime parameters */
/* org_eclipse_tahu_protobuf_Payload_PropertySetList_size depends on runtime parameters */
/* org_eclipse_tahu_protobuf_Payload_MetaData_size depends on runtime parameters */
/* org_eclipse_tahu_protobuf_Payload_Metric_size depends on runtime parameters */
#define org_eclipse_tahu_protobuf_Payload_DataSet_DataSetValue_DataSetValueExtension_size 0
#define org_eclipse_tahu_protobuf_Payload_Metric_MetricValueExtension_size 0
#define org_eclipse_tahu_protobuf_Payload_PropertyValue_PropertyValueExtension_size 0
#define org_eclipse_tahu_protobuf_Payload_Template_Parameter_ParameterValueExtension_size 0

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
