begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: ndbm_wrap.h,v 1.1 2002/04/30 16:37:20 joda Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ndbm_wrap_h__
end_ifndef

begin_define
define|#
directive|define
name|__ndbm_wrap_h__
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|dbm_rename
end_ifndef

begin_define
define|#
directive|define
name|dbm_rename
parameter_list|(
name|X
parameter_list|)
value|__roken_ ## X
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|dbm_open
value|dbm_rename(dbm_open)
end_define

begin_define
define|#
directive|define
name|dbm_close
value|dbm_rename(dbm_close)
end_define

begin_define
define|#
directive|define
name|dbm_delete
value|dbm_rename(dbm_delete)
end_define

begin_define
define|#
directive|define
name|dbm_fetch
value|dbm_rename(dbm_fetch)
end_define

begin_define
define|#
directive|define
name|dbm_get
value|dbm_rename(dbm_get)
end_define

begin_define
define|#
directive|define
name|dbm_firstkey
value|dbm_rename(dbm_firstkey)
end_define

begin_define
define|#
directive|define
name|dbm_nextkey
value|dbm_rename(dbm_nextkey)
end_define

begin_define
define|#
directive|define
name|dbm_store
value|dbm_rename(dbm_store)
end_define

begin_define
define|#
directive|define
name|dbm_error
value|dbm_rename(dbm_error)
end_define

begin_define
define|#
directive|define
name|dbm_clearerr
value|dbm_rename(dbm_clearerr)
end_define

begin_define
define|#
directive|define
name|datum
value|dbm_rename(datum)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|dptr
decl_stmt|;
name|size_t
name|dsize
decl_stmt|;
block|}
name|datum
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DBM_REPLACE
value|1
end_define

begin_typedef
typedef|typedef
name|struct
name|DBM
name|DBM
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|typedef struct {     int dummy; } DBM;
endif|#
directive|endif
end_endif

begin_function_decl
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
name|mode_t
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ndbm_wrap_h__ */
end_comment

end_unit

