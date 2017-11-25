begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: citrus_mapper_local.h,v 1.2 2008/02/09 14:56:20 junyoung Exp $ */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause  *  * Copyright (c)2003 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_MAPPER_LOCAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_CITRUS_MAPPER_LOCAL_H_
end_define

begin_define
define|#
directive|define
name|_CITRUS_MAPPER_GETOPS_FUNC_BASE
parameter_list|(
name|_n_
parameter_list|)
define|\
value|int _n_(struct _citrus_mapper_ops *)
end_define

begin_define
define|#
directive|define
name|_CITRUS_MAPPER_GETOPS_FUNC
parameter_list|(
name|_n_
parameter_list|)
define|\
value|_CITRUS_MAPPER_GETOPS_FUNC_BASE(_citrus_##_n_##_mapper_getops)
end_define

begin_define
define|#
directive|define
name|_CITRUS_MAPPER_DECLS
parameter_list|(
name|_m_
parameter_list|)
define|\
value|static int	 _citrus_##_m_##_mapper_init				\ 		    (struct _citrus_mapper_area *__restrict,		\ 		    struct _citrus_mapper * __restrict,			\ 		    const char * __restrict, const void * __restrict,	\ 		    size_t, struct _citrus_mapper_traits * __restrict,	\ 		    size_t);						\ static void	 _citrus_##_m_##_mapper_uninit(				\ 		    struct _citrus_mapper *);				\ static int	 _citrus_##_m_##_mapper_convert				\ 		    (struct _citrus_mapper * __restrict,		\ 		    _citrus_index_t * __restrict, _citrus_index_t,	\ 		    void * __restrict);					\ static void	 _citrus_##_m_##_mapper_init_state			\ 		    (void);
end_define

begin_define
define|#
directive|define
name|_CITRUS_MAPPER_DEF_OPS
parameter_list|(
name|_m_
parameter_list|)
define|\
value|extern struct _citrus_mapper_ops _citrus_##_m_##_mapper_ops;		\ struct _citrus_mapper_ops _citrus_##_m_##_mapper_ops = {		\
comment|/* mo_init */
value|&_citrus_##_m_##_mapper_init,		\
comment|/* mo_uninit */
value|&_citrus_##_m_##_mapper_uninit,		\
comment|/* mo_convert */
value|&_citrus_##_m_##_mapper_convert,	\
comment|/* mo_init_state */
value|&_citrus_##_m_##_mapper_init_state	\ }
end_define

begin_typedef
typedef|typedef
name|_CITRUS_MAPPER_GETOPS_FUNC_BASE
argument_list|(
operator|(
operator|*
name|_citrus_mapper_getops_t
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|_citrus_mapper_init_t
function_decl|)
parameter_list|(
name|struct
name|_citrus_mapper_area
modifier|*
name|__restrict
parameter_list|,
name|struct
name|_citrus_mapper
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|void
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|_citrus_mapper_traits
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|_citrus_mapper_uninit_t
function_decl|)
parameter_list|(
name|struct
name|_citrus_mapper
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|_citrus_mapper_convert_t
function_decl|)
parameter_list|(
name|struct
name|_citrus_mapper
modifier|*
name|__restrict
parameter_list|,
name|_citrus_index_t
modifier|*
name|__restrict
parameter_list|,
name|_citrus_index_t
parameter_list|,
name|void
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|_citrus_mapper_init_state_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|_citrus_mapper_ops
block|{
name|_citrus_mapper_init_t
name|mo_init
decl_stmt|;
name|_citrus_mapper_uninit_t
name|mo_uninit
decl_stmt|;
name|_citrus_mapper_convert_t
name|mo_convert
decl_stmt|;
name|_citrus_mapper_init_state_t
name|mo_init_state
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_citrus_mapper_traits
block|{
comment|/* version 0x00000001 */
name|size_t
name|mt_state_size
decl_stmt|;
name|size_t
name|mt_src_max
decl_stmt|;
name|size_t
name|mt_dst_max
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_citrus_mapper
block|{
name|struct
name|_citrus_mapper_ops
modifier|*
name|cm_ops
decl_stmt|;
name|void
modifier|*
name|cm_closure
decl_stmt|;
name|_citrus_module_t
name|cm_module
decl_stmt|;
name|struct
name|_citrus_mapper_traits
modifier|*
name|cm_traits
decl_stmt|;
name|_CITRUS_HASH_ENTRY
argument_list|(
argument|_citrus_mapper
argument_list|)
name|cm_entry
expr_stmt|;
name|int
name|cm_refcount
decl_stmt|;
name|char
modifier|*
name|cm_key
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

