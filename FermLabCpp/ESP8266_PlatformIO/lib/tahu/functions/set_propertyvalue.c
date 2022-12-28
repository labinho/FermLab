#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pb_decode.h>
#include <pb_encode.h>
#include <tahu.h>
#include <tahu.pb.h>

int set_propertyvalue(org_eclipse_tahu_protobuf_Payload_PropertyValue *propertyvalue,
                      uint32_t datatype,
                      const void *value,
                      size_t size) {
    DEBUG_PRINT("Set property value...\n");
    switch (datatype) {
    case PROPERTY_DATA_TYPE_INT8:
        propertyvalue->which_value = org_eclipse_tahu_protobuf_Payload_PropertyValue_int_value_tag;
        propertyvalue->value.int_value = *(int8_t *)value;
        break;
    case PROPERTY_DATA_TYPE_INT16:
        propertyvalue->which_value = org_eclipse_tahu_protobuf_Payload_PropertyValue_int_value_tag;
        propertyvalue->value.int_value = *(int16_t *)value;
        break;
    case PROPERTY_DATA_TYPE_INT32:
        propertyvalue->which_value = org_eclipse_tahu_protobuf_Payload_PropertyValue_int_value_tag;
        propertyvalue->value.int_value = *(int32_t *)value;
        break;
    case PROPERTY_DATA_TYPE_INT64:
        propertyvalue->which_value = org_eclipse_tahu_protobuf_Payload_PropertyValue_long_value_tag;
        propertyvalue->value.long_value = *(int64_t *)value;
        break;
    case PROPERTY_DATA_TYPE_UINT8:
        propertyvalue->which_value = org_eclipse_tahu_protobuf_Payload_PropertyValue_int_value_tag;
        propertyvalue->value.int_value = *(uint8_t *)value;
        break;
    case PROPERTY_DATA_TYPE_UINT16:
        propertyvalue->which_value = org_eclipse_tahu_protobuf_Payload_PropertyValue_int_value_tag;
        propertyvalue->value.int_value = *(uint16_t *)value;
        break;
    case PROPERTY_DATA_TYPE_UINT32:
        propertyvalue->which_value = org_eclipse_tahu_protobuf_Payload_PropertyValue_long_value_tag;
        propertyvalue->value.long_value = *(uint32_t *)value;
        break;
    case PROPERTY_DATA_TYPE_UINT64:
    case PROPERTY_DATA_TYPE_DATETIME:
        propertyvalue->which_value = org_eclipse_tahu_protobuf_Payload_PropertyValue_long_value_tag;
        propertyvalue->value.long_value = *(uint64_t *)value;
        break;
    case PROPERTY_DATA_TYPE_FLOAT:
        propertyvalue->which_value = org_eclipse_tahu_protobuf_Payload_PropertyValue_float_value_tag;
        propertyvalue->value.float_value = *(float *)value;
        break;
    case PROPERTY_DATA_TYPE_DOUBLE:
        propertyvalue->which_value = org_eclipse_tahu_protobuf_Payload_PropertyValue_double_value_tag;
        propertyvalue->value.double_value = *(double *)value;
        break;
    case PROPERTY_DATA_TYPE_BOOLEAN:
        propertyvalue->which_value = org_eclipse_tahu_protobuf_Payload_PropertyValue_boolean_value_tag;
        propertyvalue->value.boolean_value = *(bool *)value;
        break;
    case PROPERTY_DATA_TYPE_STRING:
    case PROPERTY_DATA_TYPE_TEXT:
        propertyvalue->which_value = org_eclipse_tahu_protobuf_Payload_PropertyValue_string_value_tag;
        propertyvalue->value.string_value = strndup(value, size);
        break;
    default:
        fprintf(stderr, "Invalid datatype(%u) in set_propertyvalue\n", datatype);
        return -1;
    }
    return 0;
}