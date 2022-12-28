/************************************************************************************************
 * DEBUG Statements seem to break the runttime code on embedded device. 
 *
 ************************************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pb_decode.h>
#include <pb_encode.h>
#include <tahu.h>
#include <tahu.pb.h>

int add_metric_to_payload(org_eclipse_tahu_protobuf_Payload *payload,
                          org_eclipse_tahu_protobuf_Payload_Metric *metric) {
    
    // DEBUG_PRINT("Adding metric to payload...\n");
    const int old_count = payload->metrics_count;
    const int new_count = (old_count + 1);
    const size_t new_allocation_size = sizeof(org_eclipse_tahu_protobuf_Payload_Metric) * new_count;
    void *realloc_result = realloc(payload->metrics, new_allocation_size);
    // DEBUG_PRINT("realloc_result=%p\n", realloc_result);
    if (realloc_result == NULL) {
        fprintf(stderr, "realloc failed in add_metric_to_payload\n");
        return -1;
    }
    payload->metrics = realloc_result;
    payload->metrics_count = new_count;
    memcpy(&payload->metrics[old_count], metric, sizeof(org_eclipse_tahu_protobuf_Payload_Metric));
    return 0;
}