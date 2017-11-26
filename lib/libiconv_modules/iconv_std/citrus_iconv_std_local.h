begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: citrus_iconv_std_local.h,v 1.2 2003/07/01 09:42:16 tshiozak Exp $	*/
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause  *  * Copyright (c)2003 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_ICONV_STD_LOCAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_CITRUS_ICONV_STD_LOCAL_H_
end_define

begin_comment
comment|/*  * encoding  */
end_comment

begin_struct
struct|struct
name|_citrus_iconv_std_encoding
block|{
name|struct
name|_citrus_stdenc
modifier|*
name|se_handle
decl_stmt|;
name|void
modifier|*
name|se_ps
decl_stmt|;
name|void
modifier|*
name|se_pssaved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * dst  */
end_comment

begin_struct
struct|struct
name|_citrus_iconv_std_dst
block|{
name|TAILQ_ENTRY
argument_list|(
argument|_citrus_iconv_std_dst
argument_list|)
name|sd_entry
expr_stmt|;
name|struct
name|_citrus_csmapper
modifier|*
name|sd_mapper
decl_stmt|;
name|_citrus_csid_t
name|sd_csid
decl_stmt|;
name|unsigned
name|long
name|sd_norm
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|_citrus_iconv_std_dst_list
argument_list|,
name|_citrus_iconv_std_dst
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * src  */
end_comment

begin_struct
struct|struct
name|_citrus_iconv_std_src
block|{
name|TAILQ_ENTRY
argument_list|(
argument|_citrus_iconv_std_src
argument_list|)
name|ss_entry
expr_stmt|;
name|struct
name|_citrus_iconv_std_dst_list
name|ss_dsts
decl_stmt|;
name|_citrus_csid_t
name|ss_csid
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|_citrus_iconv_std_src_list
argument_list|,
name|_citrus_iconv_std_src
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * iconv_std handle  */
end_comment

begin_struct
struct|struct
name|_citrus_iconv_std_shared
block|{
name|struct
name|_citrus_stdenc
modifier|*
name|is_dst_encoding
decl_stmt|;
name|struct
name|_citrus_stdenc
modifier|*
name|is_src_encoding
decl_stmt|;
name|struct
name|_citrus_iconv_std_src_list
name|is_srcs
decl_stmt|;
name|_citrus_wc_t
name|is_invalid
decl_stmt|;
name|int
name|is_use_invalid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iconv_std context  */
end_comment

begin_struct
struct|struct
name|_citrus_iconv_std_context
block|{
name|struct
name|_citrus_iconv_std_encoding
name|sc_dst_encoding
decl_stmt|;
name|struct
name|_citrus_iconv_std_encoding
name|sc_src_encoding
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

