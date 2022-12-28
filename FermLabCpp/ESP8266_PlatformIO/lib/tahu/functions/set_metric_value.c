#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pb_decode.h>
#include <pb_encode.h>
#include <tahu.h>
#include <tahu.pb.h>

int set_metric_value(org_eclipse_tahu_protobuf_Payload_Metric *metric, uint32_t datatype, const void *value, size_t size) {
    DEBUG_PRINT("Set metric value...\n");
    switch (datatype) {
    case METRIC_DATA_TYPE_INT8:
        metric->which_value = org_eclipse_tahu_protobuf_Payload_Metric_int_value_tag;
        metric->value.int_value = *(int8_t *)value;
        break;
    case METRIC_DATA_TYPE_INT16:
        metric->which_value = org_eclipse_tahu_protobuf_Payload_Metric_int_value_tag;
        metric->value.int_value = *(int16_t *)value;
        break;
    case METRIC_DATA_TYPE_INT32:
        metric->which_value = org_eclipse_tahu_protobuf_Payload_Metric_int_value_tag;
        metric->value.int_value = *(int32_t *)value;
        break;
    case METRIC_DATA_TYPE_INT64:
        metric->which_value = org_eclipse_tahu_protobuf_Payload_Metric_long_value_tag;
        metric->value.long_value = *(int64_t *)value;
        break;
    case METRIC_DATA_TYPE_UINT8:
        metric->which_value = org_eclipse_tahu_protobuf_Payload_Metric_int_value_tag;
        metric->value.int_value = *(uint8_t *)value;
        break;
    case METRIC_DATA_TYPE_UINT16:
        metric->which_value = org_eclipse_tahu_protobuf_Payload_Metric_int_value_tag;
        metric->value.int_value = *(uint16_t *)value;
        break;
    case METRIC_DATA_TYPE_UINT32:
        metric->which_value = org_eclipse_tahu_protobuf_Payload_Metric_long_value_tag;
        metric->value.long_value = *(uint32_t *)value;
        break;
    case METRIC_DATA_TYPE_UINT64:
    case METRIC_DATA_TYPE_DATETIME:
        metric->which_value = org_eclipse_tahu_protobuf_Payload_Metric_long_value_tag;
        metric->value.long_value = *(uint64_t *)value;
        break;
    case METRIC_DATA_TYPE_FLOAT:
        metric->which_value = org_eclipse_tahu_protobuf_Payload_Metric_float_value_tag;
        metric->value.float_value = *(float *)value;
        break;
    case METRIC_DATA_TYPE_DOUBLE:
        metric->which_value = org_eclipse_tahu_protobuf_Payload_Metric_double_value_tag;
        metric->value.double_value = *(double *)value;
        break;
    case METRIC_DATA_TYPE_BOOLEAN:
        metric->which_value = org_eclipse_tahu_protobuf_Payload_Metric_boolean_value_tag;
        metric->value.boolean_value = *(bool *)value;
        break;
    case METRIC_DATA_TYPE_STRING:
    case METRIC_DATA_TYPE_TEXT:
    case METRIC_DATA_TYPE_UUID:
        metric->which_value = org_eclipse_tahu_protobuf_Payload_Metric_string_value_tag;
        metric->value.string_value = strndup(value, size);
        break;
    case METRIC_DATA_TYPE_DATASET:
        metric->which_value = org_eclipse_tahu_protobuf_Payload_Metric_dataset_value_tag;
        memcpy(&metric->value.dataset_value, value, sizeof(metric->value.dataset_value));
        break;
    case METRIC_DATA_TYPE_TEMPLATE:
        metric->which_value = org_eclipse_tahu_protobuf_Payload_Metric_template_value_tag;
        memcpy(&metric->value.template_value, value, sizeof(metric->value.template_value));
        break;
    case METRIC_DATA_TYPE_BYTES:
    case METRIC_DATA_TYPE_FILE:
    case METRIC_DATA_TYPE_UNKNOWN:
    default:
        fprintf(stderr, "Unhandled datatype(%u) in set_metric_value\n", datatype);
        return -1;
    }
    return 0;
}