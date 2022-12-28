#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pb_decode.h>
#include <pb_encode.h>
#include <tahu.h>
#include <tahu.pb.h>

int add_metadata_to_metric(org_eclipse_tahu_protobuf_Payload_Metric *metric,
                           org_eclipse_tahu_protobuf_Payload_MetaData *metadata) {
    DEBUG_PRINT("Adding metadata...\n");
    metric->has_metadata = true;
    memcpy(&metric->metadata, metadata, sizeof(metric->metadata));
    return 0;
}