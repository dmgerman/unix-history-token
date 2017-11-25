begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: citrus_db_hash.c,v 1.5 2008/02/09 14:56:20 junyoung Exp $ */
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
file|"citrus_bcs.h"
end_include

begin_include
include|#
directive|include
file|"citrus_region.h"
end_include

begin_include
include|#
directive|include
file|"citrus_db_hash.h"
end_include

begin_function
name|uint32_t
name|_citrus_db_hash_std
parameter_list|(
name|struct
name|_region
modifier|*
name|r
parameter_list|)
block|{
specifier|const
name|uint8_t
modifier|*
name|p
decl_stmt|;
name|uint32_t
name|hash
decl_stmt|,
name|tmp
decl_stmt|;
name|size_t
name|i
decl_stmt|;
name|hash
operator|=
literal|0
expr_stmt|;
name|p
operator|=
name|_region_head
argument_list|(
name|r
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|_region_size
argument_list|(
name|r
argument_list|)
init|;
name|i
operator|>
literal|0
condition|;
name|i
operator|--
control|)
block|{
name|hash
operator|<<=
literal|4
expr_stmt|;
name|hash
operator|+=
name|_bcs_tolower
argument_list|(
operator|*
name|p
argument_list|)
expr_stmt|;
name|tmp
operator|=
name|hash
operator|&
literal|0xF0000000
expr_stmt|;
if|if
condition|(
name|tmp
operator|!=
literal|0
condition|)
block|{
name|hash
operator|^=
name|tmp
expr_stmt|;
name|hash
operator|^=
name|tmp
operator|>>
literal|24
expr_stmt|;
block|}
name|p
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|hash
operator|)
return|;
block|}
end_function

end_unit

