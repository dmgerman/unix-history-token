begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: intr.h,v 1.5 1996/05/13 06:11:28 mycroft Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996 Charles M. Hannum.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Charles M. Hannum.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	JNPR: intr.h,v 1.4 2007/08/09 11:23:32 katta  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_INTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_INTR_H_
end_define

begin_comment
comment|/* Interrupt sharing types. */
end_comment

begin_define
define|#
directive|define
name|IST_NONE
value|0
end_define

begin_comment
comment|/* none */
end_comment

begin_define
define|#
directive|define
name|IST_PULSE
value|1
end_define

begin_comment
comment|/* pulsed */
end_comment

begin_define
define|#
directive|define
name|IST_EDGE
value|2
end_define

begin_comment
comment|/* edge-triggered */
end_comment

begin_define
define|#
directive|define
name|IST_LEVEL
value|3
end_define

begin_comment
comment|/* level-triggered */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
end_ifndef

begin_comment
comment|/*  * Index into intrcnt[], which is defined in exceptions.S  *	Index # = irq # - 1  */
end_comment

begin_define
define|#
directive|define
name|INTRCNT_HARDCLOCK
value|0
end_define

begin_define
define|#
directive|define
name|INTRCNT_RTC
value|1
end_define

begin_define
define|#
directive|define
name|INTRCNT_SIO
value|2
end_define

begin_comment
comment|/* irq 3 */
end_comment

begin_define
define|#
directive|define
name|INTRCNT_PE
value|3
end_define

begin_comment
comment|/* irq 4 */
end_comment

begin_define
define|#
directive|define
name|INTRCNT_PICNIC
value|4
end_define

begin_comment
comment|/* irq 5 */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|idle_mask
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|mips_ack_interrupt
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
name|ih_func_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct_decl
struct_decl|struct
name|intr_event
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|mips_intr_handler
block|{
name|int
function_decl|(
modifier|*
name|ih_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|ih_arg
decl_stmt|;
name|struct
name|intr_event
modifier|*
name|ih_event
decl_stmt|;
name|u_int
name|ih_flags
decl_stmt|;
specifier|volatile
name|long
modifier|*
name|ih_count
decl_stmt|;
name|int
name|ih_level
decl_stmt|;
name|int
name|ih_irq
decl_stmt|;
name|void
modifier|*
name|frame
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|mips_intr_handler
name|intr_handlers
index|[]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|mask_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|mips_mask_irq
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mips_unmask_irq
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|mips_set_intr
parameter_list|(
name|int
name|pri
parameter_list|,
name|uint32_t
name|mask
parameter_list|,
name|uint32_t
function_decl|(
modifier|*
name|int_hand
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|mips_handle_interrupts
parameter_list|(
name|uint32_t
name|pending
parameter_list|,
name|struct
name|trapframe
modifier|*
name|cf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intr_enable_source
parameter_list|(
name|uintptr_t
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|trapframe
modifier|*
name|mips_get_trapframe
parameter_list|(
name|void
modifier|*
name|ih_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inthand_add
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|u_int
name|irq
parameter_list|,
name|void
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
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
name|inthand_remove
parameter_list|(
name|u_int
name|irq
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bvif_attach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_INTR_H_ */
end_comment

end_unit

