begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, Stefan Esser<se@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_INTERRUPT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_INTERRUPT_H_
end_define

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_struct_decl
struct_decl|struct
name|intr_event
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|intr_thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Describe a hardware interrupt handler.  *  * Multiple interrupt handlers for a specific event can be chained  * together.  */
end_comment

begin_struct
struct|struct
name|intr_handler
block|{
name|driver_filter_t
modifier|*
name|ih_filter
decl_stmt|;
comment|/* Filter handler function. */
name|driver_intr_t
modifier|*
name|ih_handler
decl_stmt|;
comment|/* Threaded handler function. */
name|void
modifier|*
name|ih_argument
decl_stmt|;
comment|/* Argument to pass to handlers. */
name|int
name|ih_flags
decl_stmt|;
name|char
name|ih_name
index|[
name|MAXCOMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Name of handler. */
name|struct
name|intr_event
modifier|*
name|ih_event
decl_stmt|;
comment|/* Event we are connected to. */
name|int
name|ih_need
decl_stmt|;
comment|/* Needs service. */
name|TAILQ_ENTRY
argument_list|(
argument|intr_handler
argument_list|)
name|ih_next
expr_stmt|;
comment|/* Next handler for this event. */
name|u_char
name|ih_pri
decl_stmt|;
comment|/* Priority of this handler. */
name|struct
name|intr_thread
modifier|*
name|ih_thread
decl_stmt|;
comment|/* Ithread for filtered handler. */
block|}
struct|;
end_struct

begin_comment
comment|/* Interrupt handle flags kept in ih_flags */
end_comment

begin_define
define|#
directive|define
name|IH_EXCLUSIVE
value|0x00000002
end_define

begin_comment
comment|/* Exclusive interrupt. */
end_comment

begin_define
define|#
directive|define
name|IH_ENTROPY
value|0x00000004
end_define

begin_comment
comment|/* Device is a good entropy source. */
end_comment

begin_define
define|#
directive|define
name|IH_DEAD
value|0x00000008
end_define

begin_comment
comment|/* Handler should be removed. */
end_comment

begin_define
define|#
directive|define
name|IH_MPSAFE
value|0x80000000
end_define

begin_comment
comment|/* Handler does not need Giant. */
end_comment

begin_comment
comment|/*  * Describe an interrupt event.  An event holds a list of handlers.  * The 'pre_ithread', 'post_ithread', 'post_filter', and 'assign_cpu'  * hooks are used to invoke MD code for certain operations.  *  * The 'pre_ithread' hook is called when an interrupt thread for  * handlers without filters is scheduled.  It is responsible for  * ensuring that 1) the system won't be swamped with an interrupt  * storm from the associated source while the ithread runs and 2) the  * current CPU is able to receive interrupts from other interrupt  * sources.  The first is usually accomplished by disabling  * level-triggered interrupts until the ithread completes.  The second  * is accomplished on some platforms by acknowledging the interrupt  * via an EOI.  *  * The 'post_ithread' hook is invoked when an ithread finishes.  It is  * responsible for ensuring that the associated interrupt source will  * trigger an interrupt when it is asserted in the future.  Usually  * this is implemented by enabling a level-triggered interrupt that  * was previously disabled via the 'pre_ithread' hook.  *  * The 'post_filter' hook is invoked when a filter handles an  * interrupt.  It is responsible for ensuring that the current CPU is  * able to receive interrupts again.  On some platforms this is done  * by acknowledging the interrupts via an EOI.  *  * The 'assign_cpu' hook is used to bind an interrupt source to a  * specific CPU.  If the interrupt cannot be bound, this function may  * return an error.  *  * Note that device drivers may also use interrupt events to manage  * multiplexing interrupt interrupt handler into handlers for child  * devices.  In that case, the above hooks are not used.  The device  * can create an event for its interrupt resource and register child  * event handlers with that event.  It can then use  * intr_event_execute_handlers() to execute non-filter handlers.  * Currently filter handlers are not supported by this, but that can  * be added by splitting out the filter loop from intr_event_handle()  * if desired.  */
end_comment

begin_struct
struct|struct
name|intr_event
block|{
name|TAILQ_ENTRY
argument_list|(
argument|intr_event
argument_list|)
name|ie_list
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|intr_handler
argument_list|)
name|ie_handlers
expr_stmt|;
comment|/* Interrupt handlers. */
name|char
name|ie_name
index|[
name|MAXCOMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Individual event name. */
name|char
name|ie_fullname
index|[
name|MAXCOMLEN
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|mtx
name|ie_lock
decl_stmt|;
name|void
modifier|*
name|ie_source
decl_stmt|;
comment|/* Cookie used by MD code. */
name|struct
name|intr_thread
modifier|*
name|ie_thread
decl_stmt|;
comment|/* Thread we are connected to. */
name|void
function_decl|(
modifier|*
name|ie_pre_ithread
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ie_post_ithread
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ie_post_filter
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ie_assign_cpu
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
name|ie_flags
decl_stmt|;
name|int
name|ie_count
decl_stmt|;
comment|/* Loop counter. */
name|int
name|ie_warncnt
decl_stmt|;
comment|/* Rate-check interrupt storm warns. */
name|struct
name|timeval
name|ie_warntm
decl_stmt|;
name|int
name|ie_irq
decl_stmt|;
comment|/* Physical irq number if !SOFT. */
name|int
name|ie_cpu
decl_stmt|;
comment|/* CPU this event is bound to. */
block|}
struct|;
end_struct

begin_comment
comment|/* Interrupt event flags kept in ie_flags. */
end_comment

begin_define
define|#
directive|define
name|IE_SOFT
value|0x000001
end_define

begin_comment
comment|/* Software interrupt. */
end_comment

begin_define
define|#
directive|define
name|IE_ENTROPY
value|0x000002
end_define

begin_comment
comment|/* Interrupt is an entropy source. */
end_comment

begin_define
define|#
directive|define
name|IE_ADDING_THREAD
value|0x000004
end_define

begin_comment
comment|/* Currently building an ithread. */
end_comment

begin_comment
comment|/* Flags to pass to sched_swi. */
end_comment

begin_define
define|#
directive|define
name|SWI_DELAY
value|0x2
end_define

begin_comment
comment|/*  * Software interrupt numbers in priority order.  The priority determines  * the priority of the corresponding interrupt thread.  */
end_comment

begin_define
define|#
directive|define
name|SWI_TTY
value|0
end_define

begin_define
define|#
directive|define
name|SWI_NET
value|1
end_define

begin_define
define|#
directive|define
name|SWI_CAMBIO
value|2
end_define

begin_define
define|#
directive|define
name|SWI_VM
value|3
end_define

begin_define
define|#
directive|define
name|SWI_CLOCK
value|4
end_define

begin_define
define|#
directive|define
name|SWI_TQ_FAST
value|5
end_define

begin_define
define|#
directive|define
name|SWI_TQ
value|6
end_define

begin_define
define|#
directive|define
name|SWI_TQ_GIANT
value|6
end_define

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|intr_event
modifier|*
name|tty_intr_event
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|intr_event
modifier|*
name|clk_intr_event
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|vm_ih
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Counts and names for statistics (defined in MD code). */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|intrcnt
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* counts for for each device and stray */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|intrnames
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string table containing device names */
end_comment

begin_decl_stmt
specifier|extern
name|size_t
name|sintrcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of intrcnt table */
end_comment

begin_decl_stmt
specifier|extern
name|size_t
name|sintrnames
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of intrnames table */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_function_decl
name|void
name|db_dump_intr_event
parameter_list|(
name|struct
name|intr_event
modifier|*
name|ie
parameter_list|,
name|int
name|handlers
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|u_char
name|intr_priority
parameter_list|(
name|enum
name|intr_type
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_event_add_handler
parameter_list|(
name|struct
name|intr_event
modifier|*
name|ie
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|driver_filter_t
name|filter
parameter_list|,
name|driver_intr_t
name|handler
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|u_char
name|pri
parameter_list|,
name|enum
name|intr_type
name|flags
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_event_bind
parameter_list|(
name|struct
name|intr_event
modifier|*
name|ie
parameter_list|,
name|int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_event_bind_irqonly
parameter_list|(
name|struct
name|intr_event
modifier|*
name|ie
parameter_list|,
name|int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_event_bind_ithread
parameter_list|(
name|struct
name|intr_event
modifier|*
name|ie
parameter_list|,
name|int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_event_create
parameter_list|(
name|struct
name|intr_event
modifier|*
modifier|*
name|event
parameter_list|,
name|void
modifier|*
name|source
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|irq
parameter_list|,
name|void
function_decl|(
modifier|*
name|pre_ithread
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|post_ithread
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|post_filter
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
name|assign_cpu
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|9
operator|,
function_decl|10
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|intr_event_describe_handler
parameter_list|(
name|struct
name|intr_event
modifier|*
name|ie
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|,
specifier|const
name|char
modifier|*
name|descr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_event_destroy
parameter_list|(
name|struct
name|intr_event
modifier|*
name|ie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intr_event_execute_handlers
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|intr_event
modifier|*
name|ie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_event_handle
parameter_list|(
name|struct
name|intr_event
modifier|*
name|ie
parameter_list|,
name|struct
name|trapframe
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_event_remove_handler
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_getaffinity
parameter_list|(
name|int
name|irq
parameter_list|,
name|int
name|mode
parameter_list|,
name|void
modifier|*
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|intr_handler_source
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_setaffinity
parameter_list|(
name|int
name|irq
parameter_list|,
name|int
name|mode
parameter_list|,
name|void
modifier|*
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_intr_drain
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Linux compat only. */
end_comment

begin_function_decl
name|int
name|swi_add
parameter_list|(
name|struct
name|intr_event
modifier|*
modifier|*
name|eventp
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|driver_intr_t
name|handler
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|pri
parameter_list|,
name|enum
name|intr_type
name|flags
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swi_sched
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swi_remove
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

