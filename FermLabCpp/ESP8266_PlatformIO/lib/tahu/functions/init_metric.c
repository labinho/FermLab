#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pb_decode.h>
#include <pb_encode.h>
#include <tahu.h>
#include <tahu.pb.h>

int init_metric(org_eclipse_tahu_protobuf_Payload_Metric *metric,
                const char *name,
                bool has_alias,
                uint64_t alias,
                uint64_t datatype,
                bool is_historical,
                bool is_transient,
                const void *value,
                size_t size_of_value) {
    DEBUG_PRINT("Init metric...\n");
    memset(metric, 0, sizeof(org_eclipse_tahu_protobuf_Payload_Metric));
    if (name != NULL) {
        metric->name = strdup(name);
        if (metric->name == NULL) {
            fprintf(stderr, "strdup failed to copy metric name\n");
            return -1;
        }
    }
    if (has_alias) {
        metric->has_alias = true;
        metric->alias = alias;
    }
    if (is_historical && !is_transient) {
        metric->has_timestamp = true;
        metric->timestamp = get_current_timestamp();
    }
    metric->has_datatype = true;
    metric->datatype = datatype;
    if (is_historical) {
        metric->has_is_historical = true;
        metric->is_historical = true;
    }
    if (is_transient) {
        metric->has_is_transient = true;
        metric->is_transient = true;
    }
    if (value == NULL) {
        metric->has_is_null = true;
        metric->is_null = true;
    } else {
        return set_metric_value(metric, datatype, value, size_of_value);
    }
    // No support for metadata or properties in this function...
    return 0;
}