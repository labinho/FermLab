#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pb_decode.h>
#include <pb_encode.h>
#include <tahu.h>
#include <tahu.pb.h>

static uint8_t payload_sequence;

int get_next_payload(org_eclipse_tahu_protobuf_Payload *payload) {

    // Initialize payload
    DEBUG_PRINT("Current Sequence Number: %u\n", payload_sequence);
    memset(payload, 0, sizeof(org_eclipse_tahu_protobuf_Payload));
    payload->has_timestamp = true;
    payload->timestamp = get_current_timestamp();
    payload->has_seq = true;
    payload->seq = payload_sequence;

    // Increment/wrap the sequence number (stored in a U8, so it
    // will wrap 255-to-0 automatically)
    payload_sequence++;
    return 0;
}