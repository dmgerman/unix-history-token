begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, Stefan Esser<se@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_comment
comment|/*  * Describe a hardware interrupt handler.  *  * Multiple interrupt handlers for a specific vector can be chained  * together.  */
end_comment

begin_struct
struct|struct
name|intrhand
block|{
name|driver_intr_t
modifier|*
name|ih_handler
decl_stmt|;
comment|/* Handler function. */
name|void
modifier|*
name|ih_argument
decl_stmt|;
comment|/* Argument to pass to handler. */
name|int
name|ih_flags
decl_stmt|;
specifier|const
name|char
modifier|*
name|ih_name
decl_stmt|;
comment|/* Name of handler. */
name|struct
name|ithd
modifier|*
name|ih_ithread
decl_stmt|;
comment|/* Ithread we are connected to. */
name|int
name|ih_need
decl_stmt|;
comment|/* Needs service. */
name|TAILQ_ENTRY
argument_list|(
argument|intrhand
argument_list|)
name|ih_next
expr_stmt|;
comment|/* Next handler for this vector. */
name|u_char
name|ih_pri
decl_stmt|;
comment|/* Priority of this handler. */
block|}
struct|;
end_struct

begin_comment
comment|/* Interrupt handle flags kept in ih_flags */
end_comment

begin_define
define|#
directive|define
name|IH_FAST
value|0x00000001
end_define

begin_comment
comment|/* Fast interrupt. */
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
comment|/*  * Describe an interrupt thread.  There is one of these per interrupt vector.  * Note that this actually describes an interrupt source.  There may or may  * not be an actual kernel thread attached to a given source.  */
end_comment

begin_struct
struct|struct
name|ithd
block|{
name|struct
name|mtx
name|it_lock
decl_stmt|;
name|struct
name|thread
modifier|*
name|it_td
decl_stmt|;
comment|/* Interrupt process. */
name|LIST_ENTRY
argument_list|(
argument|ithd
argument_list|)
name|it_list
expr_stmt|;
comment|/* All interrupt threads. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|intrhand
argument_list|)
name|it_handlers
expr_stmt|;
comment|/* Interrupt handlers. */
name|struct
name|ithd
modifier|*
name|it_interrupted
decl_stmt|;
comment|/* Who we interrupted. */
name|void
function_decl|(
modifier|*
name|it_disable
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/* Enable interrupt source. */
name|void
function_decl|(
modifier|*
name|it_enable
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/* Disable interrupt source. */
name|void
modifier|*
name|it_md
decl_stmt|;
comment|/* Hook for MD interrupt code. */
name|int
name|it_flags
decl_stmt|;
comment|/* Interrupt-specific flags. */
name|int
name|it_need
decl_stmt|;
comment|/* Needs service. */
name|int
name|it_vector
decl_stmt|;
name|char
name|it_name
index|[
name|MAXCOMLEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Interrupt thread flags kept in it_flags */
end_comment

begin_define
define|#
directive|define
name|IT_SOFT
value|0x000001
end_define

begin_comment
comment|/* Software interrupt. */
end_comment

begin_define
define|#
directive|define
name|IT_ENTROPY
value|0x000002
end_define

begin_comment
comment|/* Interrupt is an entropy source. */
end_comment

begin_define
define|#
directive|define
name|IT_DEAD
value|0x000004
end_define

begin_comment
comment|/* Thread is waiting to exit. */
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
comment|/*  * Software interrupt bit numbers in priority order.  The priority only  * determines which swi will be dispatched next; a higher priority swi  * may be dispatched when a nested h/w interrupt handler returns.  */
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
name|SWI_CAMNET
value|2
end_define

begin_define
define|#
directive|define
name|SWI_CAMBIO
value|3
end_define

begin_define
define|#
directive|define
name|SWI_VM
value|4
end_define

begin_define
define|#
directive|define
name|SWI_TQ
value|5
end_define

begin_define
define|#
directive|define
name|SWI_CLOCK
value|6
end_define

begin_decl_stmt
specifier|extern
name|struct
name|ithd
modifier|*
name|tty_ithd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ithd
modifier|*
name|clk_ithd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|net_ih
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|softclock_ih
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
name|eintrcnt
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of intrcnt[] */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|eintrnames
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of intrnames[] */
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

begin_function_decl
name|int
name|ithread_create
parameter_list|(
name|struct
name|ithd
modifier|*
modifier|*
name|ithread
parameter_list|,
name|int
name|vector
parameter_list|,
name|int
name|flags
parameter_list|,
name|void
function_decl|(
modifier|*
name|disable
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|enable
function_decl|)
parameter_list|(
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
function_decl|6
operator|,
function_decl|7
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|ithread_destroy
parameter_list|(
name|struct
name|ithd
modifier|*
name|ithread
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_char
name|ithread_priority
parameter_list|(
name|enum
name|intr_type
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ithread_add_handler
parameter_list|(
name|struct
name|ithd
modifier|*
name|ithread
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
name|ithread_remove_handler
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ithread_schedule
parameter_list|(
name|struct
name|ithd
modifier|*
name|ithread
parameter_list|,
name|int
name|do_switch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swi_add
parameter_list|(
name|struct
name|ithd
modifier|*
modifier|*
name|ithdp
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

