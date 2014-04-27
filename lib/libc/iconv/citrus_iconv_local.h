begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: citrus_iconv_local.h,v 1.3 2008/02/09 14:56:20 junyoung Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c)2003 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_ICONV_LOCAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_CITRUS_ICONV_LOCAL_H_
end_define

begin_include
include|#
directive|include
file|<iconv.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_define
define|#
directive|define
name|_CITRUS_ICONV_GETOPS_FUNC_BASE
parameter_list|(
name|_n_
parameter_list|)
define|\
value|int _n_(struct _citrus_iconv_ops *)
end_define

begin_define
define|#
directive|define
name|_CITRUS_ICONV_GETOPS_FUNC
parameter_list|(
name|_n_
parameter_list|)
define|\
value|_CITRUS_ICONV_GETOPS_FUNC_BASE(_citrus_##_n_##_iconv_getops)
end_define

begin_define
define|#
directive|define
name|_CITRUS_ICONV_DECLS
parameter_list|(
name|_m_
parameter_list|)
define|\
value|static int	 _citrus_##_m_##_iconv_init_shared			\ 		    (struct _citrus_iconv_shared * __restrict,		\ 	 	    const char * __restrict, const char * __restrict);	\ static void	 _citrus_##_m_##_iconv_uninit_shared			\ 		    (struct _citrus_iconv_shared *);			\ static int	 _citrus_##_m_##_iconv_convert				\ 		    (struct _citrus_iconv * __restrict,			\ 		    const char * __restrict * __restrict,		\ 		    size_t * __restrict,				\ 		    char * __restrict * __restrict,			\ 		    size_t * __restrict outbytes,			\ 	 	    uint32_t, size_t * __restrict);			\ static int	 _citrus_##_m_##_iconv_init_context			\ 		    (struct _citrus_iconv *);				\ static void	 _citrus_##_m_##_iconv_uninit_context			\ 		    (struct _citrus_iconv *)
end_define

begin_define
define|#
directive|define
name|_CITRUS_ICONV_DEF_OPS
parameter_list|(
name|_m_
parameter_list|)
define|\
value|extern struct _citrus_iconv_ops _citrus_##_m_##_iconv_ops;		\ struct _citrus_iconv_ops _citrus_##_m_##_iconv_ops = {			\
comment|/* io_init_shared */
value|&_citrus_##_m_##_iconv_init_shared,	\
comment|/* io_uninit_shared */
value|&_citrus_##_m_##_iconv_uninit_shared,	\
comment|/* io_init_context */
value|&_citrus_##_m_##_iconv_init_context,	\
comment|/* io_uninit_context */
value|&_citrus_##_m_##_iconv_uninit_context,	\
comment|/* io_convert */
value|&_citrus_##_m_##_iconv_convert		\ }
end_define

begin_typedef
typedef|typedef
name|_CITRUS_ICONV_GETOPS_FUNC_BASE
argument_list|(
operator|(
operator|*
name|_citrus_iconv_getops_t
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|_citrus_iconv_init_shared_t
function_decl|)
parameter_list|(
name|struct
name|_citrus_iconv_shared
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
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|_citrus_iconv_uninit_shared_t
function_decl|)
parameter_list|(
name|struct
name|_citrus_iconv_shared
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|_citrus_iconv_convert_t
function_decl|)
parameter_list|(
name|struct
name|_citrus_iconv
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
modifier|*
name|__restrict
parameter_list|,
name|size_t
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
name|__restrict
modifier|*
name|__restrict
parameter_list|,
name|size_t
modifier|*
name|__restrict
parameter_list|,
name|uint32_t
parameter_list|,
name|size_t
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|_citrus_iconv_init_context_t
function_decl|)
parameter_list|(
name|struct
name|_citrus_iconv
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|_citrus_iconv_uninit_context_t
function_decl|)
parameter_list|(
name|struct
name|_citrus_iconv
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|_citrus_iconv_ops
block|{
name|_citrus_iconv_init_shared_t
name|io_init_shared
decl_stmt|;
name|_citrus_iconv_uninit_shared_t
name|io_uninit_shared
decl_stmt|;
name|_citrus_iconv_init_context_t
name|io_init_context
decl_stmt|;
name|_citrus_iconv_uninit_context_t
name|io_uninit_context
decl_stmt|;
name|_citrus_iconv_convert_t
name|io_convert
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_citrus_iconv_shared
block|{
name|struct
name|_citrus_iconv_ops
modifier|*
name|ci_ops
decl_stmt|;
name|void
modifier|*
name|ci_closure
decl_stmt|;
name|_CITRUS_HASH_ENTRY
argument_list|(
argument|_citrus_iconv_shared
argument_list|)
name|ci_hash_entry
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|_citrus_iconv_shared
argument_list|)
name|ci_tailq_entry
expr_stmt|;
name|_citrus_module_t
name|ci_module
decl_stmt|;
name|unsigned
name|int
name|ci_used_count
decl_stmt|;
name|char
modifier|*
name|ci_convname
decl_stmt|;
name|bool
name|ci_discard_ilseq
decl_stmt|;
name|struct
name|iconv_hooks
modifier|*
name|ci_hooks
decl_stmt|;
name|bool
name|ci_ilseq_invalid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_citrus_iconv
block|{
name|struct
name|_citrus_iconv_shared
modifier|*
name|cv_shared
decl_stmt|;
name|void
modifier|*
name|cv_closure
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

