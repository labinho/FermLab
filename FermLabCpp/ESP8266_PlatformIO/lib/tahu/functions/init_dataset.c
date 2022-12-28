#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pb_decode.h>
#include <pb_encode.h>
#include <tahu.h>
#include <tahu.pb.h>

int init_dataset(org_eclipse_tahu_protobuf_Payload_DataSet *dataset,
                 uint64_t num_of_rows,
                 uint64_t num_of_columns,
                 const uint32_t datatypes[],
                 const char *column_keys[],
                 const org_eclipse_tahu_protobuf_Payload_DataSet_Row row_data[]) {
    DEBUG_PRINT("Init dataset...\n");
    memset(dataset, 0, sizeof(org_eclipse_tahu_protobuf_Payload_DataSet));
    dataset->has_num_of_columns = true;
    dataset->num_of_columns = num_of_columns;
    dataset->columns_count = num_of_columns;
    const size_t key_size = num_of_columns * sizeof(char *);
    dataset->columns = malloc(key_size);
    if (dataset->columns == NULL) {
        fprintf(stderr, "malloc(%lu) failure in init_dataset\n", key_size);
        return -1;
    }
    for (int i = 0; i < num_of_columns; i++) {
        dataset->columns[i] = strdup(column_keys[i]);
        if (dataset->columns[i] == NULL) {
            fprintf(stderr, "strdup failed in init_dataset\n");
            return -1;
        }
    }
    dataset->types_count = num_of_columns;
    const size_t datatypes_size = num_of_columns * sizeof(uint32_t);
    dataset->types = malloc(datatypes_size);
    if (dataset->types == NULL) {
        fprintf(stderr, "malloc(%lu) failure in init_dataset\n", datatypes_size);
        return -1;
    }
    memcpy(dataset->types, datatypes, datatypes_size);
    dataset->rows_count = num_of_rows;
    const size_t row_data_size = num_of_rows * sizeof(org_eclipse_tahu_protobuf_Payload_DataSet_Row);
    dataset->rows = malloc(row_data_size);
    if (dataset->rows == NULL) {
        fprintf(stderr, "malloc(%lu) failure in init_dataset\n", row_data_size);
        return -1;
    }
    memcpy(dataset->rows, row_data, row_data_size);
    return 0;
}