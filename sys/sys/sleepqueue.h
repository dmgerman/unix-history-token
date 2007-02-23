begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 John Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SLEEPQUEUE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SLEEPQUEUE_H_
end_define

begin_comment
comment|/*  * Sleep queue interface.  Sleep/wakeup and condition variables use a sleep  * queue for the queue of threads blocked on a sleep channel.  *  * A thread calls sleepq_lock() to lock the sleep queue chain associated  * with a given wait channel.  A thread can then call call sleepq_add() to  * add themself onto a sleep queue and call one of the sleepq_wait()  * functions to actually go to sleep.  If a thread needs to abort a sleep  * operation it should call sleepq_release() to unlock the associated sleep  * queue chain lock.  If the thread also needs to remove itself from a queue  * it just enqueued itself on, it can use sleepq_remove() instead.  *  * If the thread only wishes to sleep for a limited amount of time, it can  * call sleepq_set_timeout() after sleepq_add() to setup a timeout.  It  * should then use one of the sleepq_timedwait() functions to block.  *  * If the thread wants to the sleep to be interruptible by signals, it can  * call sleepq_catch_signals() after sleepq_add().  It should then use  * one of the sleepq_wait_sig() functions to block.  After the thread has  * been resumed, it should call sleepq_calc_signal_retval() to determine  * if it should return EINTR or ERESTART passing in the value returned from  * the earlier call to sleepq_catch_signals().  *  * A thread is normally resumed from a sleep queue by either the  * sleepq_signal() or sleepq_broadcast() functions.  Sleepq_signal() wakes  * the thread with the highest priority that is sleeping on the specified  * wait channel.  Sleepq_broadcast() wakes all threads that are sleeping  * on the specified wait channel.  A thread sleeping in an interruptible  * sleep can be interrupted by calling sleepq_abort().  A thread can also  * be removed from a specified sleep queue using the sleepq_remove()  * function.  Note that the sleep queue chain must first be locked via  * sleepq_lock() when calling sleepq_signal() and sleepq_broadcast().  *  * Each thread allocates a sleep queue at thread creation via sleepq_alloc()  * and releases it at thread destruction via sleepq_free().  Note that  * a sleep queue is not tied to a specific thread and that the sleep queue  * released at thread destruction may not be the same sleep queue that the  * thread allocated when it was created.  *  * XXX: Some other parts of the kernel such as ithread sleeping may end up  * using this interface as well (death to TDI_IWAIT!)  */
end_comment

begin_struct_decl
struct_decl|struct
name|lock_object
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sleepqueue
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|SLEEPQ_TYPE
value|0x0ff
end_define

begin_comment
comment|/* Mask of sleep queue types. */
end_comment

begin_define
define|#
directive|define
name|SLEEPQ_MSLEEP
value|0x00
end_define

begin_comment
comment|/* Used by msleep/wakeup. */
end_comment

begin_define
define|#
directive|define
name|SLEEPQ_CONDVAR
value|0x01
end_define

begin_comment
comment|/* Used for a cv. */
end_comment

begin_define
define|#
directive|define
name|SLEEPQ_PAUSE
value|0x02
end_define

begin_comment
comment|/* Used by pause. */
end_comment

begin_define
define|#
directive|define
name|SLEEPQ_INTERRUPTIBLE
value|0x100
end_define

begin_comment
comment|/* Sleep is interruptible. */
end_comment

begin_function_decl
name|void
name|init_sleepqueues
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sleepq_abort
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|intrval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sleepq_add
parameter_list|(
name|void
modifier|*
name|wchan
parameter_list|,
name|struct
name|lock_object
modifier|*
name|lock
parameter_list|,
specifier|const
name|char
modifier|*
name|wmesg
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sleepqueue
modifier|*
name|sleepq_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sleepq_broadcast
parameter_list|(
name|void
modifier|*
name|wchan
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|pri
parameter_list|,
name|int
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sleepq_free
parameter_list|(
name|struct
name|sleepqueue
modifier|*
name|sq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sleepq_lock
parameter_list|(
name|void
modifier|*
name|wchan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sleepqueue
modifier|*
name|sleepq_lookup
parameter_list|(
name|void
modifier|*
name|wchan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sleepq_release
parameter_list|(
name|void
modifier|*
name|wchan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sleepq_remove
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|void
modifier|*
name|wchan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sleepq_signal
parameter_list|(
name|void
modifier|*
name|wchan
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|pri
parameter_list|,
name|int
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sleepq_set_timeout
parameter_list|(
name|void
modifier|*
name|wchan
parameter_list|,
name|int
name|timo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sleepq_timedwait
parameter_list|(
name|void
modifier|*
name|wchan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sleepq_timedwait_sig
parameter_list|(
name|void
modifier|*
name|wchan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sleepq_wait
parameter_list|(
name|void
modifier|*
name|wchan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sleepq_wait_sig
parameter_list|(
name|void
modifier|*
name|wchan
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SLEEPQUEUE_H_ */
end_comment

end_unit

