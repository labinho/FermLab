#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pb_decode.h>
#include <pb_encode.h>
#include <tahu.h>
#include <tahu.pb.h>

int add_simple_metric(org_eclipse_tahu_protobuf_Payload *payload,
                      const char *name,
                      bool has_alias,
                      uint64_t alias,
                      uint64_t datatype,
                      bool is_historical,
                      bool is_transient,
                      const void *value,
                      size_t size_of_value) {

    // DEBUG_PRINT("Add simple metric...\n");
    org_eclipse_tahu_protobuf_Payload_Metric new_metric;

    // void * memset ( void * ptr, int value, size_t num );
    // Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char).
    memset(&new_metric, 0, sizeof(new_metric)); // <-- critical
    
    if (name != NULL) {
        // char * strdup( const char *str1 );
        // Returns a pointer to a null-terminated byte string, which is a duplicate of the string pointed to by str1.
        // The returned pointer must be passed to free to avoid a memory leak.
        new_metric.name = strdup(name); // <-- critical
        
        if (new_metric.name == NULL) {
            fprintf(stderr, "strdup name failed in add_simple_metric\n"); // <-- critical
            return -1;
        }
        
    }

    // declarations
    new_metric.has_alias = has_alias;
    new_metric.alias = alias;
    new_metric.has_timestamp = true;
    new_metric.timestamp = get_current_timestamp(); // <-- critical
    new_metric.has_datatype = true;
    new_metric.datatype = datatype;
    if (is_historical) {
        new_metric.has_is_historical = true;
        new_metric.is_historical = true;
    }
    if (is_transient) {
        new_metric.has_is_transient = true;
        new_metric.is_transient = true;
    }
    if (value == NULL) {
        new_metric.has_is_null = true;
        new_metric.is_null = true;
    } else {
        set_metric_value(&new_metric, datatype, value, size_of_value); // <-- critical
    }

    add_metric_to_payload(payload, &new_metric); // <-- critical
    return 0;
}