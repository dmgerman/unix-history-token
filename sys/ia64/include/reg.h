begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_REG_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_IA64_FPREG_DEFINED
end_ifndef

begin_struct
struct|struct
name|ia64_fpreg
block|{
name|uint64_t
name|fpr_bits
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__aligned
argument_list|(
literal|16
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|_IA64_FPREG_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|reg
block|{
name|uint64_t
name|r_gr
index|[
literal|128
index|]
decl_stmt|;
name|uint64_t
name|r_br
index|[
literal|8
index|]
decl_stmt|;
name|uint64_t
name|r_cfm
decl_stmt|;
name|uint64_t
name|r_ip
decl_stmt|;
comment|/* Bits 0-3 encode the slot number */
name|uint64_t
name|r_pr
decl_stmt|;
name|uint64_t
name|r_psr
decl_stmt|;
comment|/* User mask */
name|uint64_t
name|r_ar_rsc
decl_stmt|;
name|uint64_t
name|r_ar_bsp
decl_stmt|;
name|uint64_t
name|r_ar_bspstore
decl_stmt|;
name|uint64_t
name|r_ar_rnat
decl_stmt|;
name|uint64_t
name|r_ar_ccv
decl_stmt|;
name|uint64_t
name|r_ar_unat
decl_stmt|;
name|uint64_t
name|r_ar_fpsr
decl_stmt|;
name|uint64_t
name|r_ar_pfs
decl_stmt|;
name|uint64_t
name|r_ar_lc
decl_stmt|;
name|uint64_t
name|r_ar_ec
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fpreg
block|{
name|struct
name|ia64_fpreg
name|fpr_regs
index|[
literal|128
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dbreg
block|{
name|uint64_t
name|dbr_data
index|[
literal|8
index|]
decl_stmt|;
name|uint64_t
name|dbr_inst
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|restorehighfp
parameter_list|(
name|struct
name|ia64_fpreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|savehighfp
parameter_list|(
name|struct
name|ia64_fpreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * XXX these interfaces are MI, so they should be declared in a MI place.  */
end_comment

begin_function_decl
name|int
name|fill_regs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|reg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_regs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|reg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fill_fpregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|fpreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_fpregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|fpreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fill_dbregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|dbreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_dbregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|dbreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_REG_H_ */
end_comment

end_unit

