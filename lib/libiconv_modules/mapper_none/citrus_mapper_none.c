begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: citrus_mapper_none.c,v 1.2 2003/06/27 17:53:31 tshiozak Exp $	*/
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
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
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
file|"citrus_module.h"
end_include

begin_include
include|#
directive|include
file|"citrus_hash.h"
end_include

begin_include
include|#
directive|include
file|"citrus_mapper.h"
end_include

begin_include
include|#
directive|include
file|"citrus_mapper_none.h"
end_include

begin_comment
comment|/* ---------------------------------------------------------------------- */
end_comment

begin_expr_stmt
name|_CITRUS_MAPPER_DECLS
argument_list|(
name|mapper_none
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_CITRUS_MAPPER_DEF_OPS
argument_list|(
name|mapper_none
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* ---------------------------------------------------------------------- */
end_comment

begin_function
name|int
name|_citrus_mapper_none_mapper_getops
parameter_list|(
name|struct
name|_citrus_mapper_ops
modifier|*
name|ops
parameter_list|)
block|{
name|memcpy
argument_list|(
name|ops
argument_list|,
operator|&
name|_citrus_mapper_none_mapper_ops
argument_list|,
sizeof|sizeof
argument_list|(
name|_citrus_mapper_none_mapper_ops
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
comment|/*ARGSUSED*/
name|_citrus_mapper_none_mapper_init
parameter_list|(
name|struct
name|_citrus_mapper_area
modifier|*
name|__restrict
name|ma
name|__unused
parameter_list|,
name|struct
name|_citrus_mapper
modifier|*
name|__restrict
name|cm
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
name|dir
name|__unused
parameter_list|,
specifier|const
name|void
modifier|*
name|__restrict
name|var
name|__unused
parameter_list|,
name|size_t
name|lenvar
name|__unused
parameter_list|,
name|struct
name|_citrus_mapper_traits
modifier|*
name|__restrict
name|mt
parameter_list|,
name|size_t
name|lenmt
parameter_list|)
block|{
if|if
condition|(
name|lenmt
operator|<
sizeof|sizeof
argument_list|(
operator|*
name|mt
argument_list|)
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
name|cm
operator|->
name|cm_closure
operator|=
name|NULL
expr_stmt|;
name|mt
operator|->
name|mt_src_max
operator|=
name|mt
operator|->
name|mt_dst_max
operator|=
literal|1
expr_stmt|;
comment|/* 1:1 converter */
name|mt
operator|->
name|mt_state_size
operator|=
literal|0
expr_stmt|;
comment|/* stateless */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
comment|/*ARGSUSED*/
name|_citrus_mapper_none_mapper_uninit
parameter_list|(
name|struct
name|_citrus_mapper
modifier|*
name|cm
name|__unused
parameter_list|)
block|{  }
end_function

begin_function
specifier|static
name|int
comment|/*ARGSUSED*/
name|_citrus_mapper_none_mapper_convert
parameter_list|(
name|struct
name|_citrus_mapper
modifier|*
name|__restrict
name|cm
name|__unused
parameter_list|,
name|_citrus_index_t
modifier|*
name|__restrict
name|dst
parameter_list|,
name|_citrus_index_t
name|src
parameter_list|,
name|void
modifier|*
name|__restrict
name|ps
name|__unused
parameter_list|)
block|{
operator|*
name|dst
operator|=
name|src
expr_stmt|;
return|return
operator|(
name|_CITRUS_MAPPER_CONVERT_SUCCESS
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
comment|/*ARGSUSED*/
name|_citrus_mapper_none_mapper_init_state
parameter_list|(
name|void
parameter_list|)
block|{  }
end_function

end_unit

