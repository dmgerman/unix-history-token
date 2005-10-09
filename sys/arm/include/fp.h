begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: fp.h,v 1.1 2001/01/10 19:02:06 bjh21 Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1995 Mark Brinicombe.  * Copyright (c) 1995 Brini.  * All rights reserved.  *  * This code is derived from software written for Brini by Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Brini.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BRINI ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BRINI OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RiscBSD kernel project  *  * fp.h  *  * FP info  *  * Created      : 10/10/95  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_FP_H
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_FP_H
end_define

begin_comment
comment|/*  * An extended precision floating point number  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|fp_extended_precision
block|{
name|u_int32_t
name|fp_exponent
decl_stmt|;
name|u_int32_t
name|fp_mantissa_hi
decl_stmt|;
name|u_int32_t
name|fp_mantissa_lo
decl_stmt|;
block|}
name|fp_extended_precision_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fp_extended_precision
name|fp_reg_t
typedef|;
end_typedef

begin_comment
comment|/*  * Information about the FPE-SP state that is stored in the pcb  *  * This needs to move and be hidden from userland.  */
end_comment

begin_struct
struct|struct
name|fpe_sp_state
block|{
name|unsigned
name|int
name|fp_flags
decl_stmt|;
name|unsigned
name|int
name|fp_sr
decl_stmt|;
name|unsigned
name|int
name|fp_cr
decl_stmt|;
name|fp_reg_t
name|fp_registers
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Type for a saved FP context, if we want to translate the context to a  * user-readable form  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|fpsr
decl_stmt|;
name|fp_extended_precision_t
name|regs
index|[
literal|8
index|]
decl_stmt|;
block|}
name|fp_state_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_FP_H_ */
end_comment

begin_comment
comment|/* End of fp.h */
end_comment

end_unit

