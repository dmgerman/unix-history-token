begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Antoine Brodin  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/stack.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<machine/stack.h>
end_include

begin_comment
comment|/*  * This code makes assumptions about the stack layout. These are correct  * when using APCS (the old ABI), but are no longer true with AAPCS and the  * ARM EABI. There is also an issue with clang and llvm when building for  * APCS where it lays out the stack incorrectly. Because of this we disable  * this when building for ARM EABI or when building with clang.  */
end_comment

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|kernel_vm_end
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|stack_capture
parameter_list|(
name|struct
name|stack
modifier|*
name|st
parameter_list|,
name|u_int32_t
modifier|*
name|frame
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|stack_save_td
parameter_list|(
name|struct
name|stack
modifier|*
name|st
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
name|u_int32_t
modifier|*
name|frame
decl_stmt|;
if|if
condition|(
name|TD_IS_SWAPPED
argument_list|(
name|td
argument_list|)
condition|)
name|panic
argument_list|(
literal|"stack_save_td: swapped"
argument_list|)
expr_stmt|;
if|if
condition|(
name|TD_IS_RUNNING
argument_list|(
name|td
argument_list|)
condition|)
name|panic
argument_list|(
literal|"stack_save_td: running"
argument_list|)
expr_stmt|;
comment|/* 	 * This register, the frame pointer, is incorrect for the ARM EABI 	 * as it doesn't have a frame pointer, however it's value is not used 	 * when building for EABI. 	 */
name|frame
operator|=
operator|(
name|u_int32_t
operator|*
operator|)
name|td
operator|->
name|td_pcb
operator|->
name|pcb_regs
operator|.
name|sf_r11
expr_stmt|;
name|stack_zero
argument_list|(
name|st
argument_list|)
expr_stmt|;
name|stack_capture
argument_list|(
name|st
argument_list|,
name|frame
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|stack_save_td_running
parameter_list|(
name|struct
name|stack
modifier|*
name|st
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
return|return
operator|(
name|EOPNOTSUPP
operator|)
return|;
block|}
end_function

begin_function
name|void
name|stack_save
parameter_list|(
name|struct
name|stack
modifier|*
name|st
parameter_list|)
block|{
name|u_int32_t
modifier|*
name|frame
decl_stmt|;
name|frame
operator|=
operator|(
name|u_int32_t
operator|*
operator|)
name|__builtin_frame_address
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|stack_zero
argument_list|(
name|st
argument_list|)
expr_stmt|;
name|stack_capture
argument_list|(
name|st
argument_list|,
name|frame
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

