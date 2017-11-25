begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: citrus_db_file.h,v 1.4 2008/02/10 05:58:22 junyoung Exp $ */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause  *  * Copyright (c)2003 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_DB_FILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_CITRUS_DB_FILE_H_
end_define

begin_comment
comment|/*  * db format:  *  +---  *  | header  *  |  - magic  *  |  - num entries  *  +---  *  | entry directory  *  |  +------------  *  |  | entry0  *  |  |  - hash value  *  |  |  - next entry  *  |  |  - key offset  *  |  |  - key len  *  |  |  - data offset  *  |  |  - data size  *  |  |---  *  |  | entry1  *  |  | ..  *  |  | entryN  *  |  +---  *  +---  *  | key table  *  |  - key0  *  |   ...  *  |  - keyN  *  +---  *  | data table  *  |  - data0  *  |   ...  *  |  - dataN  *  +---  */
end_comment

begin_define
define|#
directive|define
name|_CITRUS_DB_MAGIC_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|_CITRUS_DB_HEADER_SIZE
value|16
end_define

begin_struct
struct|struct
name|_citrus_db_header_x
block|{
name|char
name|dhx_magic
index|[
name|_CITRUS_DB_MAGIC_SIZE
index|]
decl_stmt|;
name|uint32_t
name|dhx_num_entries
decl_stmt|;
name|uint32_t
name|dhx_entry_offset
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|_citrus_db_entry_x
block|{
name|uint32_t
name|dex_hash_value
decl_stmt|;
name|uint32_t
name|dex_next_offset
decl_stmt|;
name|uint32_t
name|dex_key_offset
decl_stmt|;
name|uint32_t
name|dex_key_size
decl_stmt|;
name|uint32_t
name|dex_data_offset
decl_stmt|;
name|uint32_t
name|dex_data_size
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|_CITRUS_DB_ENTRY_SIZE
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

