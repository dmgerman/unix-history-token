begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: citrus_aliasname_local.h,v 1.2 2009/01/11 02:46:24 christos Exp $ */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause  *  * Copyright (c)2008 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_ALIASNAME_LOCAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_CITRUS_ALIASNAME_LOCAL_H_
end_define

begin_function
specifier|static
name|__inline
specifier|const
name|char
modifier|*
name|__unaliasname
parameter_list|(
specifier|const
name|char
modifier|*
name|dbname
parameter_list|,
specifier|const
name|char
modifier|*
name|alias
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|bufsize
parameter_list|)
block|{
return|return
operator|(
name|_lookup_simple
argument_list|(
name|dbname
argument_list|,
name|alias
argument_list|,
name|buf
argument_list|,
name|bufsize
argument_list|,
name|_LOOKUP_CASE_SENSITIVE
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|__isforcemapping
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
return|return
operator|(
name|_bcs_strcasecmp
argument_list|(
literal|"/force"
argument_list|,
name|name
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_CITRUS_ALIASNAME_LOCAL_H_*/
end_comment

end_unit

