//
//  KSThread.h
//
//  Created by Karl Stenerud on 2012-01-29.
//
//  Copyright (c) 2012 Karl Stenerud. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall remain in place
// in this source code.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef HDR_KSThread_h
#define HDR_KSThread_h

#ifdef __cplusplus
extern "C" {
#endif


#include "KSArchSpecific.h"

#include <mach/mach_types.h>
#include <stdbool.h>


/** Get a thread's name. Internally, a thread name will
 * never be more than 64 characters long.
 *
 * @param thread The thread whose name to get.
 *
 * @oaram buffer Buffer to hold the name.
 *
 * @param bufLength The length of the buffer.
 *
 * @return true if a name was found.
 */
bool ksthread_getThreadName(const thread_t thread, char* const buffer, int bufLength);

/** Get the name of a thread's dispatch queue. Internally, a queue name will
 * never be more than 64 characters long.
 *
 * @param thread The thread whose queue name to get.
 *
 * @oaram buffer Buffer to hold the name.
 *
 * @param bufLength The length of the buffer.
 *
 * @return true if a name or label was found.
 */
bool ksthread_getQueueName(thread_t thread, char* buffer, int bufLength);

/* Get the current mach thread ID.
 * mach_thread_self() receives a send right for the thread port which needs to
 * be deallocated to balance the reference count. This function takes care of
 * all of that for you.
 *
 * @return The current thread ID.
 */
thread_t ksthread_self();

/** Suspend all threads except for the current one.
 *
 * @return true if thread suspention was at least partially successful.
 */
bool ksthread_suspendAllThreads(void);

/** Suspend all threads except for the current one and the specified threads.
 *
 * @param exceptThreads The threads to avoid suspending.
 *
 * @param exceptThreadsCount The number of threads to avoid suspending.
 *
 * @return true if thread suspention was at least partially successful.
 */
bool ksthread_suspendAllThreadsExcept(thread_t* exceptThreads, int exceptThreadsCount);

/** Resume all threads except for the current one.
 *
 * @return true if thread resumption was at least partially successful.
 */
bool ksthread_resumeAllThreads(void);

/** Resume all threads except for the current one and the specified threads.
 *
 * @param exceptThreads The threads to avoid resuming.
 *
 * @param exceptThreadsCount The number of threads to avoid resuming.
 *
 * @return true if thread resumption was at least partially successful.
 */
bool ksthread_resumeAllThreadsExcept(thread_t* exceptThreads, int exceptThreadsCount);


#ifdef __cplusplus
}
#endif

#endif // HDR_KSThread_h