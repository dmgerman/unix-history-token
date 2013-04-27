begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Anish Gupta (akgupt3@gmail.com)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVM_H_
end_define

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|n
parameter_list|)
value|(1ULL<< n)
end_define

begin_define
define|#
directive|define
name|ERR
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|printf("SVM ERROR:%s " fmt "\n", __func__, ##args);
end_define

begin_comment
comment|/*  * Software saved machine state for guest and host.   */
end_comment

begin_comment
comment|/* Additional guest register state */
end_comment

begin_struct
struct|struct
name|svm_gctx
block|{
name|register_t
name|sctx_rdx
decl_stmt|;
name|register_t
name|sctx_rdi
decl_stmt|;
name|register_t
name|sctx_rsi
decl_stmt|;
comment|/* Points to host context area. */
name|register_t
name|sctx_hostctx_base
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Additional host register state */
end_comment

begin_struct
struct|struct
name|svm_hctx
block|{
name|uint16_t
name|sctx_fs
decl_stmt|;
name|uint16_t
name|sctx_gs
decl_stmt|;
name|register_t
name|sctx_rsp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Common register context area for guest and host. */
end_comment

begin_struct
struct|struct
name|svm_regctx
block|{
name|register_t
name|sctx_rbp
decl_stmt|;
name|register_t
name|sctx_rbx
decl_stmt|;
name|register_t
name|sctx_rcx
decl_stmt|;
name|register_t
name|sctx_r8
decl_stmt|;
name|register_t
name|sctx_r9
decl_stmt|;
name|register_t
name|sctx_r10
decl_stmt|;
name|register_t
name|sctx_r11
decl_stmt|;
name|register_t
name|sctx_r12
decl_stmt|;
name|register_t
name|sctx_r13
decl_stmt|;
name|register_t
name|sctx_r14
decl_stmt|;
name|register_t
name|sctx_r15
decl_stmt|;
union|union
block|{
name|struct
name|svm_hctx
name|h
decl_stmt|;
comment|/* host-specific register state */
name|struct
name|svm_gctx
name|g
decl_stmt|;
comment|/* guest-specific register state */
block|}
name|e
union|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|svm_launch
parameter_list|(
name|uint64_t
name|pa
parameter_list|,
name|struct
name|svm_regctx
modifier|*
parameter_list|,
name|struct
name|svm_regctx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|disable_gintr
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("clgi" : : :);
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|enable_gintr
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("stgi" : : :);
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|save_cr2
parameter_list|(
name|uint64_t
modifier|*
name|cr2
parameter_list|)
block|{
asm|__asm __volatile(
literal|"mov %%cr2, %%rax; movq %%rax, %0"
operator|:
literal|"=m"
operator|(
operator|*
name|cr2
operator|)
operator|:
operator|:
literal|"rax"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|load_cr2
parameter_list|(
name|uint64_t
modifier|*
name|cr2
parameter_list|)
block|{
asm|__asm __volatile(
literal|"movq %0, %%rax; movq %%rax, %%cr2"
operator|:
operator|:
literal|"m"
operator|(
operator|*
name|cr2
operator|)
operator|:
literal|"rax"
block|)
function|;
end_function

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SVM_H_ */
end_comment

end_unit

