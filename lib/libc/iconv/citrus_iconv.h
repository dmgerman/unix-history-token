begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: citrus_iconv.h,v 1.5 2008/02/09 14:56:20 junyoung Exp $ */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause  *  * Copyright (c)2003 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_ICONV_H_
end_ifndef

begin_define
define|#
directive|define
name|_CITRUS_ICONV_H_
end_define

begin_struct_decl
struct_decl|struct
name|_citrus_iconv_shared
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_citrus_iconv_ops
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_citrus_iconv
struct_decl|;
end_struct_decl

begin_function_decl
name|__BEGIN_DECLS
name|int
name|_citrus_iconv_open
parameter_list|(
name|struct
name|_citrus_iconv
modifier|*
name|__restrict
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_citrus_iconv_close
parameter_list|(
name|struct
name|_citrus_iconv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|_citrus_iconv_canonicalize
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|__END_DECLS
include|#
directive|include
file|"citrus_iconv_local.h"
define|#
directive|define
name|_CITRUS_ICONV_F_HIDE_INVALID
value|0x0001
comment|/*  * _citrus_iconv_convert:  *	convert a string.  */
specifier|static
name|__inline
name|int
name|_citrus_iconv_convert
parameter_list|(
name|struct
name|_citrus_iconv
modifier|*
name|__restrict
name|cv
parameter_list|,
name|char
modifier|*
name|__restrict
modifier|*
name|__restrict
name|in
parameter_list|,
name|size_t
modifier|*
name|__restrict
name|inbytes
parameter_list|,
name|char
modifier|*
name|__restrict
modifier|*
name|__restrict
name|out
parameter_list|,
name|size_t
modifier|*
name|__restrict
name|outbytes
parameter_list|,
name|uint32_t
name|flags
parameter_list|,
name|size_t
modifier|*
name|__restrict
name|nresults
parameter_list|)
block|{
return|return
call|(
modifier|*
name|cv
operator|->
name|cv_shared
operator|->
name|ci_ops
operator|->
name|io_convert
call|)
argument_list|(
name|cv
argument_list|,
name|in
argument_list|,
name|inbytes
argument_list|,
name|out
argument_list|,
name|outbytes
argument_list|,
name|flags
argument_list|,
name|nresults
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

