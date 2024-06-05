// Priority queue implementation using max heap

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>

// Priority Queue ADT
class priority_queue {
    public:
        // build()
        priority_queue(int initial_values[], int init_length);

        // insert()
        void insert(int new_key);

        // delete_max()
        int delete_max();

        // data accessor methods
        int get_data(int index) const;
        int get_data_size() const;

    private:
        void max_heapify_up(int index);
        void max_heapify_down(int index);
        int data_length;
        std::vector<int> data;
};

#endif
