#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pb_decode.h>
#include <pb_encode.h>
#include <tahu.h>
#include <tahu.pb.h>

int free_payload(org_eclipse_tahu_protobuf_Payload *payload) {
    DEBUG_PRINT("Free payload memory...\n");
    pb_release(org_eclipse_tahu_protobuf_Payload_fields, payload);
    return 0;
}