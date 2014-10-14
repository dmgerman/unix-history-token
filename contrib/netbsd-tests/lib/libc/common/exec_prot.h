begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: exec_prot.h,v 1.1 2011/07/18 23:16:11 jym Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2011 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jean-Yves Migeon.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TESTS_EXEC_PROT_H_
end_ifndef

begin_define
define|#
directive|define
name|_TESTS_EXEC_PROT_H_
end_define

begin_comment
comment|/*  * Prototype definitions of external helper functions for executable  * mapping tests.  */
end_comment

begin_comment
comment|/*  * Trivial MD shellcode that justs returns 1.  */
end_comment

begin_function_decl
name|int
name|return_one
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* begin marker -- shellcode entry */
end_comment

begin_function_decl
name|int
name|return_one_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* end marker */
end_comment

begin_comment
comment|/*  * MD callback to verify whether host offers executable space protection.  * Returns execute protection level.  */
end_comment

begin_function_decl
name|int
name|exec_prot_support
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* execute protection level */
end_comment

begin_enum
enum|enum
block|{
name|NOTIMPL
init|=
operator|-
literal|1
block|,
comment|/* callback not implemented */
name|NO_XP
block|,
comment|/* no execute protection */
name|PERPAGE_XP
block|,
comment|/* per-page execute protection */
name|PARTIAL_XP
comment|/* partial execute protection. Depending on where the 			 page is located in virtual memory, executable space 			 protection may be enforced or not. */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

end_unit

