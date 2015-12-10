//The code below is a parallel version of std::accumulate. It divides the work among the threads, with a minimum number of elements per thread.

#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>

using namespace std;

template<typename Iterator, typename T>
struct accumulate_block
{
    void operator()(Iterator first, Iterator last, T& result)
    {
        result=std::accumulate(first, last, result);
    }
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
    unsigned long const length = std::distance(first, last);

        // If the input range is empty, just return the initial value init.
    if(!length) return init;

    unsigned long const min_per_thread = 50;

        // Otherwise, there is at least one element in the range, 
        // divide the number of elements to process by the minimum block size 
        // in order to give the maximum number of threads
    unsigned long const max_threads =
        (length+min_per_thread-1)/min_per_thread;

        // std::thread::hardware_ concurrency() function returns the number of threads 
        // that can run concurrently for a given execution.
    unsigned long const hardware_threads =
            thread::hardware_concurrency();

        // The number of threads to run is the minimum of our calculated maximum and
        // the number of hardware threads
        // If the call to thread::hardware_concurrency() returned 0, we simply substitute it with 2.
    unsigned long const num_threads =
        std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);

        // The number of entries for each thread to process is 
        // the length of the range divided by the number of threads
    unsigned long const block_size = length / num_threads;

        // To know how many threads we have, we can create a std::vector
    vector<T> results(num_threads);

        // Launch one fewer thread than num_threads, because we already have one.
    vector<thread> threads(num_threads-1);

    Iterator block_start = first;

        // Launching the threads with a loop 
    for(unsigned long i=0; i < num_threads - 1; ++i)
    {
        Iterator block_end = block_start;

                // advance the block_end iterator to the end of the current block
        std::advance(block_end, block_size);

                // launch a new thread to accumulate the results for the block
        threads[i] = thread(accumulate_block<Iterator, T>(),
                block_start, block_end, std::ref(results[i]));
 
                // The start of the next block is the end of this block
        block_start = block_end;
    }

        // After the launch of all the threads, 
        // this thread can then process the final block
    accumulate_block<Iterator, T>()(
            block_start, last, results[num_threads-1]);

        // Once accumulated the results for the last block, 
        // we can wait for all the threads 
    std::for_each(threads.begin(), threads.end(),
                std::mem_fn(&std::thread::join));

        // add up the results with a final call to std::accumulate
    return std::accumulate(results.begin(), results.end(), init);
}


void init() {
    srand(time(0));
}

int randomnum(int n) {
    return rand() % n;
}

int main() {

    //init();
    
    const int MAXINT = 100;
    const int NUM = 50000000;
    
    vector<int> vec;
    
    for(int i = 0; i < NUM; i++) {
        // cout << randomnum(MAXINT) << " ";
        vec.push_back(randomnum(MAXINT));
    }
    
    int res = accumulate(vec.begin(), vec.end(), 0);
    //int res = parallel_accumulate(vec.begin(), vec.end(), 0);
    cout << res << endl;
    
    return 0;
}