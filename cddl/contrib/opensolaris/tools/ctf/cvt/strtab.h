begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 by Sun Microsystems, Inc.  * All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STRTAB_H
end_ifndef

begin_define
define|#
directive|define
name|_STRTAB_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
typedef|typedef
struct|struct
name|strhash
block|{
specifier|const
name|char
modifier|*
name|str_data
decl_stmt|;
comment|/* pointer to actual string data */
name|ulong_t
name|str_buf
decl_stmt|;
comment|/* index of string data buffer */
name|size_t
name|str_off
decl_stmt|;
comment|/* offset in bytes of this string */
name|size_t
name|str_len
decl_stmt|;
comment|/* length in bytes of this string */
name|struct
name|strhash
modifier|*
name|str_next
decl_stmt|;
comment|/* next string in hash chain */
block|}
name|strhash_t
typedef|;
typedef|typedef
struct|struct
name|strtab
block|{
name|strhash_t
modifier|*
modifier|*
name|str_hash
decl_stmt|;
comment|/* array of hash buckets */
name|ulong_t
name|str_hashsz
decl_stmt|;
comment|/* size of hash bucket array */
name|char
modifier|*
modifier|*
name|str_bufs
decl_stmt|;
comment|/* array of buffer pointers */
name|char
modifier|*
name|str_ptr
decl_stmt|;
comment|/* pointer to current buffer location */
name|ulong_t
name|str_nbufs
decl_stmt|;
comment|/* size of buffer pointer array */
name|size_t
name|str_bufsz
decl_stmt|;
comment|/* size of individual buffer */
name|ulong_t
name|str_nstrs
decl_stmt|;
comment|/* total number of strings in strtab */
name|size_t
name|str_size
decl_stmt|;
comment|/* total size of strings in bytes */
block|}
name|strtab_t
typedef|;
specifier|extern
name|void
name|strtab_create
parameter_list|(
name|strtab_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|strtab_destroy
parameter_list|(
name|strtab_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|size_t
name|strtab_insert
parameter_list|(
name|strtab_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|size_t
name|strtab_size
parameter_list|(
specifier|const
name|strtab_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|ssize_t
name|strtab_write
parameter_list|(
specifier|const
name|strtab_t
modifier|*
parameter_list|,
name|ssize_t
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|strtab_print
parameter_list|(
specifier|const
name|strtab_t
modifier|*
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STRTAB_H */
end_comment

end_unit

