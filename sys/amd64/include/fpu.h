begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)npx.h	5.3 (Berkeley) 1/18/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Floating Point Data Structures and Constants  * W. Jolitz 1/90  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_FPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_FPU_H_
end_define

begin_comment
comment|/* Contents of each x87 floating point accumulator */
end_comment

begin_struct
struct|struct
name|fpacc87
block|{
name|uint8_t
name|fp_bytes
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Contents of each SSE extended accumulator */
end_comment

begin_struct
struct|struct
name|xmmacc
block|{
name|uint8_t
name|xmm_bytes
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Contents of the upper 16 bytes of each AVX extended accumulator */
end_comment

begin_struct
struct|struct
name|ymmacc
block|{
name|uint8_t
name|ymm_bytes
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|envxmm
block|{
name|uint16_t
name|en_cw
decl_stmt|;
comment|/* control word (16bits) */
name|uint16_t
name|en_sw
decl_stmt|;
comment|/* status word (16bits) */
name|uint8_t
name|en_tw
decl_stmt|;
comment|/* tag word (8bits) */
name|uint8_t
name|en_zero
decl_stmt|;
name|uint16_t
name|en_opcode
decl_stmt|;
comment|/* opcode last executed (11 bits ) */
name|uint64_t
name|en_rip
decl_stmt|;
comment|/* floating point instruction pointer */
name|uint64_t
name|en_rdp
decl_stmt|;
comment|/* floating operand pointer */
name|uint32_t
name|en_mxcsr
decl_stmt|;
comment|/* SSE sontorol/status register */
name|uint32_t
name|en_mxcsr_mask
decl_stmt|;
comment|/* valid bits in mxcsr */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|savefpu
block|{
name|struct
name|envxmm
name|sv_env
decl_stmt|;
struct|struct
block|{
name|struct
name|fpacc87
name|fp_acc
decl_stmt|;
name|uint8_t
name|fp_pad
index|[
literal|6
index|]
decl_stmt|;
comment|/* padding */
block|}
name|sv_fp
index|[
literal|8
index|]
struct|;
name|struct
name|xmmacc
name|sv_xmm
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|sv_pad
index|[
literal|96
index|]
decl_stmt|;
block|}
name|__aligned
argument_list|(
literal|16
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|xstate_hdr
block|{
name|uint64_t
name|xstate_bv
decl_stmt|;
name|uint8_t
name|xstate_rsrv0
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|xstate_rsrv
index|[
literal|40
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|savefpu_xstate
block|{
name|struct
name|xstate_hdr
name|sx_hd
decl_stmt|;
name|struct
name|ymmacc
name|sx_ymm
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|savefpu_ymm
block|{
name|struct
name|envxmm
name|sv_env
decl_stmt|;
struct|struct
block|{
name|struct
name|fpacc87
name|fp_acc
decl_stmt|;
name|int8_t
name|fp_pad
index|[
literal|6
index|]
decl_stmt|;
comment|/* padding */
block|}
name|sv_fp
index|[
literal|8
index|]
struct|;
name|struct
name|xmmacc
name|sv_xmm
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|sv_pad
index|[
literal|96
index|]
decl_stmt|;
name|struct
name|savefpu_xstate
name|sv_xstate
decl_stmt|;
block|}
name|__aligned
argument_list|(
literal|64
argument_list|)
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|fpu_kern_ctx
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|PCB_USER_FPU
parameter_list|(
name|pcb
parameter_list|)
value|(((pcb)->pcb_flags& PCB_KERNFPU) == 0)
end_define

begin_define
define|#
directive|define
name|XSAVE_AREA_ALIGN
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The hardware default control word for i387's and later coprocessors is  * 0x37F, giving:  *  *	round to nearest  *	64-bit precision  *	all exceptions masked.  *  * FreeBSD/i386 uses 53 bit precision for things like fadd/fsub/fsqrt etc  * because of the difference between memory and fpu register stack arguments.  * If its using an intermediate fpu register, it has 80/64 bits to work  * with.  If it uses memory, it has 64/53 bits to work with.  However,  * gcc is aware of this and goes to a fair bit of trouble to make the  * best use of it.  *  * This is mostly academic for AMD64, because the ABI prefers the use  * SSE2 based math.  For FreeBSD/amd64, we go with the default settings.  */
end_comment

begin_define
define|#
directive|define
name|__INITIAL_FPUCW__
value|0x037F
end_define

begin_define
define|#
directive|define
name|__INITIAL_FPUCW_I386__
value|0x127F
end_define

begin_define
define|#
directive|define
name|__INITIAL_MXCSR__
value|0x1F80
end_define

begin_define
define|#
directive|define
name|__INITIAL_MXCSR_MASK__
value|0xFFBF
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|fpudna
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fpudrop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fpuexit
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpuformat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpugetregs
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fpuinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fpusave
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpusetregs
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|savefpu
modifier|*
name|addr
parameter_list|,
name|char
modifier|*
name|xfpustate
parameter_list|,
name|size_t
name|xfpustate_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpusetxstate
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|char
modifier|*
name|xfpustate
parameter_list|,
name|size_t
name|xfpustate_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fpususpend
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fputrap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fpuuserinited
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fpu_kern_ctx
modifier|*
name|fpu_kern_alloc_ctx
parameter_list|(
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fpu_kern_free_ctx
parameter_list|(
name|struct
name|fpu_kern_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpu_kern_enter
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|fpu_kern_ctx
modifier|*
name|ctx
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpu_kern_leave
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|fpu_kern_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpu_kern_thread
parameter_list|(
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_fpu_kern_thread
parameter_list|(
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Flags for fpu_kern_alloc_ctx(), fpu_kern_enter() and fpu_kern_thread().  */
end_comment

begin_define
define|#
directive|define
name|FPU_KERN_NORMAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|FPU_KERN_NOWAIT
value|0x0001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_FPU_H_ */
end_comment

end_unit

