#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pb_decode.h>
#include <pb_encode.h>
#include <tahu.h>
#include <tahu.pb.h>

ssize_t decode_payload(org_eclipse_tahu_protobuf_Payload *payload,
                       const uint8_t *in_buffer,
                       size_t buffer_length) {
    DEBUG_PRINT("Decoding payload...\n");
    pb_istream_t node_stream = pb_istream_from_buffer(in_buffer, buffer_length);
    memset(payload, 0, sizeof(org_eclipse_tahu_protobuf_Payload));
    const bool decode_result = pb_decode(&node_stream, org_eclipse_tahu_protobuf_Payload_fields, payload);

    if (!decode_result) {
        fprintf(stderr, "Decoding failed: %s\n", PB_GET_ERROR(&node_stream));
        return -1;
    }

#ifdef SPARKPLUG_DEBUG
    // Print the message data
    print_payload(payload);
#endif

    return node_stream.bytes_left;
}