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

begin_comment
comment|/*  * Describe a hardware interrupt handler.  *  * Multiple interrupt handlers for a specific vector can be chained  * together via the 'next' pointer.  */
end_comment

begin_struct
struct|struct
name|intrhand
block|{
name|driver_intr_t
modifier|*
name|ih_handler
decl_stmt|;
comment|/* code address of handler */
name|void
modifier|*
name|ih_argument
decl_stmt|;
comment|/* argument to pass to handler */
name|enum
name|intr_type
name|ih_flags
decl_stmt|;
comment|/* flag bits (sys/bus.h) */
name|char
modifier|*
name|ih_name
decl_stmt|;
comment|/* name of handler */
name|struct
name|ithd
modifier|*
name|ih_ithd
decl_stmt|;
comment|/* handler we're connected to */
name|struct
name|intrhand
modifier|*
name|ih_next
decl_stmt|;
comment|/* next handler for this irq */
name|int
name|ih_need
decl_stmt|;
comment|/* need interrupt */
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|ithread_priority
name|__P
argument_list|(
operator|(
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sched_swi
name|__P
argument_list|(
operator|(
expr|struct
name|intrhand
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SWI_SWITCH
value|0x1
end_define

begin_define
define|#
directive|define
name|SWI_NOSWITCH
value|0x2
end_define

begin_define
define|#
directive|define
name|SWI_DELAY
value|0x4
end_define

begin_comment
comment|/* implies NOSWITCH */
end_comment

begin_decl_stmt
name|struct
name|intrhand
modifier|*
name|sinthand_add
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
expr|struct
name|ithd
operator|*
operator|*
operator|,
name|driver_intr_t
operator|,
name|void
operator|*
name|arg
operator|,
name|int
name|pri
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|struct
name|intrhand
modifier|*
name|net_ih
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|intrhand
modifier|*
name|softclock_ih
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|intrhand
modifier|*
name|vm_ih
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

