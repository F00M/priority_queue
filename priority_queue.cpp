#include <cmath>
#include <iostream>
#include <vector>

#include "priority_queue.h"

priority_queue::priority_queue(int initial_values[], int init_length) {
    // insert elements unordered
    data_length = 0;
    for (int i = 0; i < init_length; i++) {
        data.push_back(initial_values[i]);
        data_length++;
    }
    // heapify
    max_heapify_down(0);
}

void priority_queue::insert(int new_key) {
    // insert new key at end of heap
    data.push_back(new_key);
    data_length++;
    // heapify up
    max_heapify_down(0);
}

int priority_queue::delete_max() {
    // swap first and last elements
    int old_data = data[0];
    data[0] = data[data_length-1];
    data[data_length-1] = old_data;

    data.pop_back();
    data_length--;

    // now, re-heapify
    max_heapify_down(0);

    // return deleted element
    return old_data;
}

void priority_queue::max_heapify_up(int index) {
    int parent_index;
    for (int i = 1; i < data_length; i++) {
        parent_index = (i % 2 == 0) ? floor((i - 2)/2) : floor((i - 1)/2);

        if (data[parent_index] < data[i]) {
            int old_data = data[parent_index];
            data[parent_index] = data[i];
            data[i] = old_data;
        }
    }
}

void priority_queue::max_heapify_down(int index) {
    int first_parent_index = ceil((data_length-1)/2.0) - 1.0;
    for (int i = first_parent_index; i >= 0; i--) {
        int largest_child_index;
        if (i * 2 + 1 < data_length && i * 2 + 2 < data_length) {
        largest_child_index = (data[i * 2 + 1] > data[i * 2 + 2]) ? i * 2 + 1 : i * 2 + 2;
        }
        else if (i * 2 + 1 > data_length && i * 2 + 2 < data_length) {
            largest_child_index = i * 2 + 2;
        }
        else {
            largest_child_index = i * 2 + 1;
        }

        if (data[largest_child_index] > data[i]) {
            int old_data = data[i];
            data[i] = data[largest_child_index];
            data[largest_child_index] = old_data;

            if (largest_child_index <= first_parent_index) {
                i = largest_child_index + 1;
            }
        }
    }
}

int priority_queue::get_data(int index) const {
    return data[index];
}

int priority_queue::get_data_size() const {
    return data.size();
}
