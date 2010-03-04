begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: fpu_extern.h,v 1.3 2005/12/11 12:18:42 christos Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1995 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fpreg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_union_decl
union_decl|union
name|instr
union_decl|;
end_union_decl

begin_struct_decl
struct_decl|struct
name|fpemu
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fpn
struct_decl|;
end_struct_decl

begin_comment
comment|/* fpu.c */
end_comment

begin_function_decl
name|int
name|fpu_emulate
parameter_list|(
name|struct
name|trapframe
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
name|fpu_execute
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|,
name|struct
name|fpemu
modifier|*
parameter_list|,
name|union
name|instr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fpu_explode.c */
end_comment

begin_function_decl
name|int
name|fpu_itof
parameter_list|(
name|struct
name|fpn
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpu_xtof
parameter_list|(
name|struct
name|fpn
modifier|*
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpu_stof
parameter_list|(
name|struct
name|fpn
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpu_dtof
parameter_list|(
name|struct
name|fpn
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fpu_implode.c */
end_comment

begin_function_decl
name|u_int
name|fpu_ftoi
parameter_list|(
name|struct
name|fpemu
modifier|*
parameter_list|,
name|struct
name|fpn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|fpu_ftox
parameter_list|(
name|struct
name|fpemu
modifier|*
parameter_list|,
name|struct
name|fpn
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|fpu_ftos
parameter_list|(
name|struct
name|fpemu
modifier|*
parameter_list|,
name|struct
name|fpn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|fpu_ftod
parameter_list|(
name|struct
name|fpemu
modifier|*
parameter_list|,
name|struct
name|fpn
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

