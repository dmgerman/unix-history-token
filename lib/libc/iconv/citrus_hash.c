begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: citrus_hash.c,v 1.3 2008/02/09 14:56:20 junyoung Exp $ */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause  *  * Copyright (c)2003 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"citrus_namespace.h"
end_include

begin_include
include|#
directive|include
file|"citrus_types.h"
end_include

begin_include
include|#
directive|include
file|"citrus_region.h"
end_include

begin_include
include|#
directive|include
file|"citrus_hash.h"
end_include

begin_include
include|#
directive|include
file|"citrus_db_hash.h"
end_include

begin_function
name|int
name|_citrus_string_hash_func
parameter_list|(
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|int
name|hashsize
parameter_list|)
block|{
name|struct
name|_region
name|r
decl_stmt|;
name|_region_init
argument_list|(
operator|&
name|r
argument_list|,
name|__DECONST
argument_list|(
name|void
operator|*
argument_list|,
name|key
argument_list|)
argument_list|,
name|strlen
argument_list|(
name|key
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
call|(
name|int
call|)
argument_list|(
name|_db_hash_std
argument_list|(
operator|&
name|r
argument_list|)
operator|%
operator|(
name|uint32_t
operator|)
name|hashsize
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

