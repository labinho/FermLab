#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pb_decode.h>
#include <pb_encode.h>
#include <tahu.h>
#include <tahu.pb.h>

int add_property_to_set(org_eclipse_tahu_protobuf_Payload_PropertySet *propertyset,
                        const char *key,
                        uint32_t datatype,
                        const void *value,
                        size_t size_of_value) {
    DEBUG_PRINT("Add property to set...\n");
    if (propertyset->keys_count != propertyset->values_count) {
        fprintf(stderr, "Mismatched key/value counts in add_property_to_set\n");
        return -1;
    }
    const int old_count = propertyset->keys_count;
    const int new_count = (old_count + 1);
    const size_t key_allocation_size = sizeof(char *) * new_count;
    const size_t value_allocation_size = sizeof(org_eclipse_tahu_protobuf_Payload_PropertyValue) * new_count;
    void *key_allocation_result = realloc(propertyset->keys, key_allocation_size);
    void *value_allocation_result = realloc(propertyset->values, value_allocation_size);
    //DEBUG_PRINT("key=%p value=%p\n", key_allocation_result, value_allocation_result);
    if ((key_allocation_result == NULL) || (value_allocation_result == NULL)) {
        fprintf(stderr, "realloc failed in add_metric_to_payload\n");
        return -1;
    }
    propertyset->keys = key_allocation_result;
    propertyset->keys_count = new_count;
    propertyset->values = value_allocation_result;
    propertyset->values_count = new_count;
    propertyset->keys[old_count] = strdup(key);
    if (propertyset->keys[old_count] == NULL) {
        fprintf(stderr, "strdup failed in add_metric_to_payload\n");
        return -1;
    }
    memset(&propertyset->values[old_count], 0, sizeof(org_eclipse_tahu_protobuf_Payload_PropertyValue));
    propertyset->values[old_count].has_type = true;
    propertyset->values[old_count].type = datatype;
    if (value == NULL) {
        propertyset->values[old_count].has_is_null = true;
        propertyset->values[old_count].is_null = true;
    } else {
        set_propertyvalue(&propertyset->values[old_count], datatype, value, size_of_value);
    }
    return 0;
}