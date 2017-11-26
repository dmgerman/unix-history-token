begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: citrus_mapper_std_file.h,v 1.3 2006/09/09 14:35:17 tnozaki Exp $	*/
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause  *  * Copyright (c)2003, 2006 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_MAPPER_STD_FILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_CITRUS_MAPPER_STD_FILE_H_
end_define

begin_define
define|#
directive|define
name|_CITRUS_MAPPER_STD_MAGIC
value|"MAPPER\0\0"
end_define

begin_define
define|#
directive|define
name|_CITRUS_MAPPER_STD_SYM_TYPE
value|"type"
end_define

begin_define
define|#
directive|define
name|_CITRUS_MAPPER_STD_SYM_INFO
value|"info"
end_define

begin_define
define|#
directive|define
name|_CITRUS_MAPPER_STD_SYM_TABLE
value|"table"
end_define

begin_define
define|#
directive|define
name|_CITRUS_MAPPER_STD_TYPE_ROWCOL
value|"rowcol"
end_define

begin_struct
struct|struct
name|_citrus_mapper_std_rowcol_info_x
block|{
name|uint32_t
name|rcx_src_rowcol_bits
decl_stmt|;
name|uint32_t
name|rcx_dst_invalid
decl_stmt|;
define|#
directive|define
name|_CITRUS_MAPPER_STD_ROWCOL_MAX
value|4
struct|struct
block|{
name|uint32_t
name|begin
decl_stmt|;
name|uint32_t
name|end
decl_stmt|;
block|}
name|__packed
name|rcx_src_rowcol
index|[
name|_CITRUS_MAPPER_STD_ROWCOL_MAX
index|]
struct|;
name|uint32_t
name|rcx_dst_unit_bits
decl_stmt|;
name|uint32_t
name|rcx_src_rowcol_len
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|_CITRUS_MAPPER_STD_ROWCOL_INFO_SIZE
value|48
end_define

begin_comment
comment|/* old file layout */
end_comment

begin_struct
struct|struct
name|_citrus_mapper_std_rowcol_info_compat_x
block|{
name|uint32_t
name|rcx_src_col_bits
decl_stmt|;
name|uint32_t
name|rcx_dst_invalid
decl_stmt|;
name|uint32_t
name|rcx_src_row_begin
decl_stmt|;
name|uint32_t
name|rcx_src_row_end
decl_stmt|;
name|uint32_t
name|rcx_src_col_begin
decl_stmt|;
name|uint32_t
name|rcx_src_col_end
decl_stmt|;
name|uint32_t
name|rcx_dst_unit_bits
decl_stmt|;
name|uint32_t
name|rcx_pad
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|_CITRUS_MAPPER_STD_ROWCOL_INFO_COMPAT_SIZE
value|32
end_define

begin_comment
comment|/* rowcol oob extension info */
end_comment

begin_define
define|#
directive|define
name|_CITRUS_MAPPER_STD_SYM_ROWCOL_EXT_ILSEQ
value|"rowcol_ext_ilseq"
end_define

begin_struct
struct|struct
name|_citrus_mapper_std_rowcol_ext_ilseq_info_x
block|{
define|#
directive|define
name|_CITRUS_MAPPER_STD_OOB_NONIDENTICAL
value|0
define|#
directive|define
name|_CITRUS_MAPPER_STD_OOB_ILSEQ
value|1
name|uint32_t
name|eix_oob_mode
decl_stmt|;
name|uint32_t
name|eix_dst_ilseq
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|_CITRUS_MAPPER_STD_ROWCOL_EXT_ILSEQ_SIZE
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

