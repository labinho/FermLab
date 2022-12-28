#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pb_decode.h>
#include <pb_encode.h>
#include <tahu.h>
#include <tahu.pb.h>

ssize_t encode_payload(uint8_t *out_buffer,
                       size_t buffer_length,
                       const org_eclipse_tahu_protobuf_Payload *payload) {
    // Use a different stream if the user wants a normal encode or just a size check
    pb_ostream_t sizing_stream = PB_OSTREAM_SIZING;
    pb_ostream_t buffer_stream = pb_ostream_from_buffer(out_buffer, buffer_length);
    pb_ostream_t *node_stream = ((out_buffer == NULL) ? &sizing_stream : &buffer_stream);

    // Encode the payload
    DEBUG_PRINT("Encoding payload...\n");
    const bool encode_result = pb_encode(node_stream, org_eclipse_tahu_protobuf_Payload_fields, payload);
    const size_t message_length = node_stream->bytes_written;
    DEBUG_PRINT("Message length: %zd\n", message_length);

    // Error Check
    if (!encode_result) {
        fprintf(stderr, "Encoding failed: %s\n", PB_GET_ERROR(node_stream));
        return -1;
    }

    DEBUG_PRINT("Encoding succeeded\n");
    return message_length;
}