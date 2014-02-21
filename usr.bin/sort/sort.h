begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 2009 Gabor Kovesdan<gabor@FreeBSD.org>  * Copyright (C) 2012 Oleg Moskalenko<mom040267@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__BSD_SORT_H__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__BSD_SORT_H__
end_define

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<md5.h>
end_include

begin_define
define|#
directive|define
name|VERSION
value|"2.3-FreeBSD"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WITHOUT_NLS
end_ifdef

begin_define
define|#
directive|define
name|getstr
parameter_list|(
name|n
parameter_list|)
value|nlsstr[n]
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<nl_types.h>
end_include

begin_decl_stmt
specifier|extern
name|nl_catd
name|catalog
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|getstr
parameter_list|(
name|n
parameter_list|)
value|catgets(catalog, 1, n, nlsstr[n])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|nlsstr
index|[]
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SORT_THREADS
argument_list|)
end_if

begin_define
define|#
directive|define
name|MT_SORT_THRESHOLD
value|(10000)
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|ncpu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|nthreads
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If true, we output some debug information.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|debug_sort
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * MD5 context for random hash function  */
end_comment

begin_decl_stmt
specifier|extern
name|MD5_CTX
name|md5_ctx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * sort.c  */
end_comment

begin_comment
comment|/*  * This structure holds main sort options which are NOT affecting the sort ordering.  */
end_comment

begin_struct
struct|struct
name|sort_opts
block|{
name|wint_t
name|field_sep
decl_stmt|;
name|int
name|sort_method
decl_stmt|;
name|bool
name|cflag
decl_stmt|;
name|bool
name|csilentflag
decl_stmt|;
name|bool
name|kflag
decl_stmt|;
name|bool
name|mflag
decl_stmt|;
name|bool
name|sflag
decl_stmt|;
name|bool
name|uflag
decl_stmt|;
name|bool
name|zflag
decl_stmt|;
name|bool
name|tflag
decl_stmt|;
name|bool
name|complex_sort
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Key value structure forward declaration  */
end_comment

begin_struct_decl
struct_decl|struct
name|key_value
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Cmp function  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|cmpcoll_t
function_decl|)
parameter_list|(
name|struct
name|key_value
modifier|*
name|kv1
parameter_list|,
name|struct
name|key_value
modifier|*
name|kv2
parameter_list|,
name|size_t
name|offset
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * This structure holds "sort modifiers" - options which are affecting the sort ordering.  */
end_comment

begin_struct
struct|struct
name|sort_mods
block|{
name|cmpcoll_t
name|func
decl_stmt|;
name|bool
name|bflag
decl_stmt|;
name|bool
name|dflag
decl_stmt|;
name|bool
name|fflag
decl_stmt|;
name|bool
name|gflag
decl_stmt|;
name|bool
name|iflag
decl_stmt|;
name|bool
name|Mflag
decl_stmt|;
name|bool
name|nflag
decl_stmt|;
name|bool
name|rflag
decl_stmt|;
name|bool
name|Rflag
decl_stmt|;
name|bool
name|Vflag
decl_stmt|;
name|bool
name|hflag
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|bool
name|need_hint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sort_opts
name|sort_opts_vals
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sort_mods
modifier|*
specifier|const
name|default_sort_mods
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_SORT_H__ */
end_comment

end_unit

