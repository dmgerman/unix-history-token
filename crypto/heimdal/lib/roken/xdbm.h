begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 - 2001 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: xdbm.h,v 1.14 2001/09/03 05:03:00 assar Exp $ */
end_comment

begin_comment
comment|/* Generic *dbm include file */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XDBM_H__
end_ifndef

begin_define
define|#
directive|define
name|__XDBM_H__
end_define

begin_if
if|#
directive|if
name|HAVE_DB_NDBM
end_if

begin_define
define|#
directive|define
name|DB_DBM_HSEARCH
value|1
end_define

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_elif
elif|#
directive|elif
name|HAVE_NDBM
end_elif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_GDBM_NDBM_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<gdbm/ndbm.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_NDBM_H
argument_list|)
end_elif

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
name|HAVE_DBM_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<dbm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NDBM */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Macros to convert ndbm names to dbm names.  * Note that dbm_nextkey() cannot be simply converted using a macro, since  * it is invoked giving the database, and nextkey() needs the previous key.  *  * Instead, all routines call "dbm_next" instead.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NDBM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_DB_H
argument_list|)
end_if

begin_define
unit|typedef char DBM;
define|#
directive|define
name|dbm_open
parameter_list|(
name|file
parameter_list|,
name|flags
parameter_list|,
name|mode
parameter_list|)
value|((dbminit(file) == 0)?"":((char *)0))
end_define

begin_define
define|#
directive|define
name|dbm_fetch
parameter_list|(
name|db
parameter_list|,
name|key
parameter_list|)
value|fetch(key)
end_define

begin_define
define|#
directive|define
name|dbm_store
parameter_list|(
name|db
parameter_list|,
name|key
parameter_list|,
name|content
parameter_list|,
name|flag
parameter_list|)
value|store(key, content)
end_define

begin_define
define|#
directive|define
name|dbm_delete
parameter_list|(
name|db
parameter_list|,
name|key
parameter_list|)
value|delete(key)
end_define

begin_define
define|#
directive|define
name|dbm_firstkey
parameter_list|(
name|db
parameter_list|)
value|firstkey()
end_define

begin_define
define|#
directive|define
name|dbm_next
parameter_list|(
name|db
parameter_list|,
name|key
parameter_list|)
value|nextkey(key)
end_define

begin_define
define|#
directive|define
name|dbm_close
parameter_list|(
name|db
parameter_list|)
value|dbmclose()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dbm_next
parameter_list|(
name|db
parameter_list|,
name|key
parameter_list|)
value|dbm_nextkey(db)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XDBM_H__ */
end_comment

end_unit

