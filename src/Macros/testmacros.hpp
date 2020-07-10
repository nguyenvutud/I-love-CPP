/*
 * testmacros.hpp
 *
 *  Created on: Dec 9, 2016
 *      Author: nguyenvu
 */

#ifndef MACROS_TESTMACROS_HPP_
#define MACROS_TESTMACROS_HPP_
#include <iostream>
#include <assert.h>
using namespace std;
#define DEBUG
// Define the name of the benchmark class
#define BENCHMARK_NAME_(testcase, benchmark) testcase ## _ ## benchmark ## _Benchmark

#define BENCHMARK_CLASS_(testcase, benchmark, fixture, __runs)                \
    class BENCHMARK_NAME_(testcase, benchmark)					              \
    {                                                                         \
    public:                                                                   \
                                                                              \
        std::string testcase_name() const                                     \
        { return #testcase; }                                                 \
                                                                              \
        std::string benchmark_name() const                                    \
        { return #benchmark; }                                                \
                                                                              \
        uint32_t runs() const                                         \
        {                                                                     \
            assert(__runs > 0);                                               \
            return __runs;                                                    \
        }                                                                     \
                                                                              \
        static uint32_t benchmark_id()                                        \
        {                                                                     \
            static uint32_t id = 1234;                 \
            return id;                                                        \
        }                                                                     \
    };

class testmacros{
public:
	void displayresult(){
		char* x_y_Benchmark="Test Macro";
		cout<<BENCHMARK_NAME_(x,y)<<endl;
		using benchmarkclass = BENCHMARK_CLASS_(a,b,abc,10);
		benchmarkclass m;
		cout<<m.runs();
	}
};
#endif /* MACROS_TESTMACROS_HPP_ */
