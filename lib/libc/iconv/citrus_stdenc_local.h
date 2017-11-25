begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: citrus_stdenc_local.h,v 1.4 2008/02/09 14:56:20 junyoung Exp $ */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause  *  * Copyright (c)2003 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_STDENC_LOCAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_CITRUS_STDENC_LOCAL_H_
end_define

begin_include
include|#
directive|include
file|<iconv.h>
end_include

begin_include
include|#
directive|include
file|"citrus_module.h"
end_include

begin_define
define|#
directive|define
name|_CITRUS_STDENC_GETOPS_FUNC_BASE
parameter_list|(
name|n
parameter_list|)
define|\
value|int n(struct _citrus_stdenc_ops *, size_t)
end_define

begin_define
define|#
directive|define
name|_CITRUS_STDENC_GETOPS_FUNC
parameter_list|(
name|_e_
parameter_list|)
define|\
value|_CITRUS_STDENC_GETOPS_FUNC_BASE(_citrus_##_e_##_stdenc_getops)
end_define

begin_typedef
typedef|typedef
name|_CITRUS_STDENC_GETOPS_FUNC_BASE
argument_list|(
operator|(
operator|*
name|_citrus_stdenc_getops_t
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|_CITRUS_STDENC_DECLS
parameter_list|(
name|_e_
parameter_list|)
define|\
value|static int	 _citrus_##_e_##_stdenc_init				\ 		    (struct _citrus_stdenc * __restrict,		\ 		    const void * __restrict, size_t,			\ 		    struct _citrus_stdenc_traits * __restrict);		\ static void	 _citrus_##_e_##_stdenc_uninit(struct _citrus_stdenc *);\ static int	 _citrus_##_e_##_stdenc_init_state			\ 		    (struct _citrus_stdenc * __restrict,		\ 		    void * __restrict);					\ static int	 _citrus_##_e_##_stdenc_mbtocs				\ 		    (struct _citrus_stdenc * __restrict,		\ 		    _citrus_csid_t * __restrict,			\ 		    _citrus_index_t * __restrict,			\ 		    char ** __restrict, size_t,				\ 		    void * __restrict, size_t * __restrict,		\ 		    struct iconv_hooks *);				\ static int	 _citrus_##_e_##_stdenc_cstomb				\ 		    (struct _citrus_stdenc * __restrict,		\ 		    char * __restrict, size_t, _citrus_csid_t,		\ 		    _citrus_index_t, void * __restrict,			\ 		    size_t * __restrict, struct iconv_hooks *);		\ static int	 _citrus_##_e_##_stdenc_mbtowc				\ 		    (struct _citrus_stdenc * __restrict,		\ 		    _citrus_wc_t * __restrict,				\ 		    char ** __restrict, size_t,				\ 		    void * __restrict, size_t * __restrict,		\ 		    struct iconv_hooks *);				\ static int	 _citrus_##_e_##_stdenc_wctomb				\ 		    (struct _citrus_stdenc * __restrict,		\ 		    char * __restrict, size_t, _citrus_wc_t,		\ 		    void * __restrict, size_t * __restrict,		\ 		    struct iconv_hooks *);				\ static int	 _citrus_##_e_##_stdenc_put_state_reset			\ 		    (struct _citrus_stdenc * __restrict,		\ 		    char * __restrict, size_t, void * __restrict,	\ 		    size_t * __restrict);				\ static int	 _citrus_##_e_##_stdenc_get_state_desc			\ 		    (struct _citrus_stdenc * __restrict,		\ 		    void * __restrict, int,				\ 		    struct _citrus_stdenc_state_desc * __restrict)
end_define

begin_define
define|#
directive|define
name|_CITRUS_STDENC_DEF_OPS
parameter_list|(
name|_e_
parameter_list|)
define|\
value|extern struct _citrus_stdenc_ops _citrus_##_e_##_stdenc_ops;		\ struct _citrus_stdenc_ops _citrus_##_e_##_stdenc_ops = {		\
comment|/* eo_init */
value|&_citrus_##_e_##_stdenc_init,		\
comment|/* eo_uninit */
value|&_citrus_##_e_##_stdenc_uninit,		\
comment|/* eo_init_state */
value|&_citrus_##_e_##_stdenc_init_state,	\
comment|/* eo_mbtocs */
value|&_citrus_##_e_##_stdenc_mbtocs,		\
comment|/* eo_cstomb */
value|&_citrus_##_e_##_stdenc_cstomb,		\
comment|/* eo_mbtowc */
value|&_citrus_##_e_##_stdenc_mbtowc,		\
comment|/* eo_wctomb */
value|&_citrus_##_e_##_stdenc_wctomb,		\
comment|/* eo_put_state_reset */
value|&_citrus_##_e_##_stdenc_put_state_reset,\
comment|/* eo_get_state_desc */
value|&_citrus_##_e_##_stdenc_get_state_desc	\ }
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|_citrus_stdenc_init_t
function_decl|)
parameter_list|(
name|struct
name|_citrus_stdenc
modifier|*
name|__reatrict
parameter_list|,
specifier|const
name|void
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|_citrus_stdenc_traits
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
name|_citrus_stdenc_uninit_t
function_decl|)
parameter_list|(
name|struct
name|_citrus_stdenc
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
name|_citrus_stdenc_init_state_t
function_decl|)
parameter_list|(
name|struct
name|_citrus_stdenc
modifier|*
name|__restrict
parameter_list|,
name|void
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
name|_citrus_stdenc_mbtocs_t
function_decl|)
parameter_list|(
name|struct
name|_citrus_stdenc
modifier|*
name|__restrict
parameter_list|,
name|_citrus_csid_t
modifier|*
name|__restrict
parameter_list|,
name|_citrus_index_t
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
name|__restrict
parameter_list|,
name|size_t
modifier|*
name|__restrict
parameter_list|,
name|struct
name|iconv_hooks
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|_citrus_stdenc_cstomb_t
function_decl|)
parameter_list|(
name|struct
name|_citrus_stdenc
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|,
name|_citrus_csid_t
parameter_list|,
name|_citrus_index_t
parameter_list|,
name|void
modifier|*
name|__restrict
parameter_list|,
name|size_t
modifier|*
name|__restrict
parameter_list|,
name|struct
name|iconv_hooks
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|_citrus_stdenc_mbtowc_t
function_decl|)
parameter_list|(
name|struct
name|_citrus_stdenc
modifier|*
name|__restrict
parameter_list|,
name|_citrus_wc_t
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
name|__restrict
parameter_list|,
name|size_t
modifier|*
name|__restrict
parameter_list|,
name|struct
name|iconv_hooks
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|_citrus_stdenc_wctomb_t
function_decl|)
parameter_list|(
name|struct
name|_citrus_stdenc
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|,
name|_citrus_wc_t
parameter_list|,
name|void
modifier|*
name|__restrict
parameter_list|,
name|size_t
modifier|*
name|__restrict
parameter_list|,
name|struct
name|iconv_hooks
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|_citrus_stdenc_put_state_reset_t
function_decl|)
parameter_list|(
name|struct
name|_citrus_stdenc
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
name|__restrict
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
name|_citrus_stdenc_get_state_desc_t
function_decl|)
parameter_list|(
name|struct
name|_citrus_stdenc
modifier|*
name|__restrict
parameter_list|,
name|void
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|,
name|struct
name|_citrus_stdenc_state_desc
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|_citrus_stdenc_ops
block|{
name|_citrus_stdenc_init_t
name|eo_init
decl_stmt|;
name|_citrus_stdenc_uninit_t
name|eo_uninit
decl_stmt|;
name|_citrus_stdenc_init_state_t
name|eo_init_state
decl_stmt|;
name|_citrus_stdenc_mbtocs_t
name|eo_mbtocs
decl_stmt|;
name|_citrus_stdenc_cstomb_t
name|eo_cstomb
decl_stmt|;
name|_citrus_stdenc_mbtowc_t
name|eo_mbtowc
decl_stmt|;
name|_citrus_stdenc_wctomb_t
name|eo_wctomb
decl_stmt|;
name|_citrus_stdenc_put_state_reset_t
name|eo_put_state_reset
decl_stmt|;
comment|/* version 0x00000002 */
name|_citrus_stdenc_get_state_desc_t
name|eo_get_state_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_citrus_stdenc_traits
block|{
comment|/* version 0x00000001 */
name|size_t
name|et_state_size
decl_stmt|;
name|size_t
name|et_mb_cur_max
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_citrus_stdenc
block|{
comment|/* version 0x00000001 */
name|struct
name|_citrus_stdenc_ops
modifier|*
name|ce_ops
decl_stmt|;
name|void
modifier|*
name|ce_closure
decl_stmt|;
name|_citrus_module_t
name|ce_module
decl_stmt|;
name|struct
name|_citrus_stdenc_traits
modifier|*
name|ce_traits
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_CITRUS_DEFAULT_STDENC_NAME
value|"NONE"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

