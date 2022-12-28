#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pb_decode.h>
#include <pb_encode.h>
#include <tahu.h>
#include <tahu.pb.h>

int add_propertyset_to_metric(org_eclipse_tahu_protobuf_Payload_Metric *metric,
                              org_eclipse_tahu_protobuf_Payload_PropertySet *properties) {
    DEBUG_PRINT("Add propertyset to metric...\n");
    metric->has_properties = true;
    memcpy(&metric->properties, properties, sizeof(metric->properties));
    return 0;
}