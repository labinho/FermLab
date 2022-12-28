#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pb_decode.h>
#include <pb_encode.h>
#include <tahu.h>
#include <tahu.pb.h>

static uint8_t payload_sequence;

void reset_sparkplug_sequence(void) {
    payload_sequence = 0;
}