begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2000 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: hdb_locl.h,v 1.13 2000/02/06 05:17:05 assar Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HDB_LOCL_H__
end_ifndef

begin_define
define|#
directive|define
name|__HDB_LOCL_H__
end_define

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FCNTL_H
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FILE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_include
include|#
directive|include
file|<openssl/des.h>
end_include

begin_include
include|#
directive|include
file|<krb5.h>
end_include

begin_include
include|#
directive|include
file|<hdb.h>
end_include

begin_include
include|#
directive|include
file|<hdb-private.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DB_185_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<db_185.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_DB_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_NDBM_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<ndbm.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_GDBM_NDBM_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<gdbm/ndbm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|hdb_principal2key
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_principal
parameter_list|,
name|krb5_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hdb_key2principal
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_data
modifier|*
parameter_list|,
name|krb5_principal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|hdb_lock
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|hdb_unlock
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|_hdb_fetch
parameter_list|(
name|krb5_context
parameter_list|,
name|HDB
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|hdb_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|_hdb_store
parameter_list|(
name|krb5_context
parameter_list|,
name|HDB
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|hdb_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|_hdb_remove
parameter_list|(
name|krb5_context
parameter_list|,
name|HDB
modifier|*
parameter_list|,
name|hdb_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HDB_LOCL_H__ */
end_comment

end_unit

