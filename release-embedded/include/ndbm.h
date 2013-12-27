begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Margo Seltzer.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ndbm.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NDBM_H_
end_ifndef

begin_define
define|#
directive|define
name|_NDBM_H_
end_define

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_comment
comment|/* Map dbm interface onto db(3). */
end_comment

begin_define
define|#
directive|define
name|DBM_RDONLY
value|O_RDONLY
end_define

begin_comment
comment|/* Flags to dbm_store(). */
end_comment

begin_define
define|#
directive|define
name|DBM_INSERT
value|0
end_define

begin_define
define|#
directive|define
name|DBM_REPLACE
value|1
end_define

begin_comment
comment|/*  * The db(3) support for ndbm always appends this suffix to the  * file name to avoid overwriting the user's original database.  */
end_comment

begin_define
define|#
directive|define
name|DBM_SUFFIX
value|".db"
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|dptr
decl_stmt|;
name|int
name|dsize
decl_stmt|;
block|}
name|datum
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|DB
name|DBM
typedef|;
end_typedef

begin_define
define|#
directive|define
name|dbm_pagfno
parameter_list|(
name|a
parameter_list|)
value|DBM_PAGFNO_NOT_AVAILABLE
end_define

begin_function_decl
name|__BEGIN_DECLS
name|int
name|dbm_clearerr
parameter_list|(
name|DBM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbm_close
parameter_list|(
name|DBM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dbm_delete
parameter_list|(
name|DBM
modifier|*
parameter_list|,
name|datum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dbm_error
parameter_list|(
name|DBM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|dbm_fetch
parameter_list|(
name|DBM
modifier|*
parameter_list|,
name|datum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|dbm_firstkey
parameter_list|(
name|DBM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|long
name|dbm_forder
parameter_list|(
name|DBM
modifier|*
parameter_list|,
name|datum
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|datum
name|dbm_nextkey
parameter_list|(
name|DBM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DBM
modifier|*
name|dbm_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dbm_store
parameter_list|(
name|DBM
modifier|*
parameter_list|,
name|datum
parameter_list|,
name|datum
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|int
name|dbm_dirfno
parameter_list|(
name|DBM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NDBM_H_ */
end_comment

end_unit

