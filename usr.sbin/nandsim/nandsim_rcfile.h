begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1999, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  * from: FreeBSD: src/lib/libncp/ncpl_rcfile.c,v 1.5 2007/01/09 23:27:39 imp Exp  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIMRC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SIMRC_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct
struct|struct
name|rckey
block|{
name|SLIST_ENTRY
argument_list|(
argument|rckey
argument_list|)
name|rk_next
expr_stmt|;
name|char
modifier|*
name|rk_name
decl_stmt|;
comment|/* key name */
name|char
modifier|*
name|rk_value
decl_stmt|;
comment|/* key value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rcsection
block|{
name|SLIST_ENTRY
argument_list|(
argument|rcsection
argument_list|)
name|rs_next
expr_stmt|;
name|SLIST_HEAD
argument_list|(
argument|rckey_head
argument_list|,
argument|rckey
argument_list|)
name|rs_keys
expr_stmt|;
comment|/* key list */
name|char
modifier|*
name|rs_name
decl_stmt|;
comment|/* section name */
name|int
name|rs_id
decl_stmt|;
comment|/* allow few same named */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rcfile
block|{
name|SLIST_ENTRY
argument_list|(
argument|rcfile
argument_list|)
name|rf_next
expr_stmt|;
name|SLIST_HEAD
argument_list|(
argument|rcsec_head
argument_list|,
argument|rcsection
argument_list|)
name|rf_sect
expr_stmt|;
comment|/* sections list */
name|char
modifier|*
name|rf_name
decl_stmt|;
comment|/* file name */
name|FILE
modifier|*
name|rf_f
decl_stmt|;
comment|/* file desc */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|rc_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|rcfile
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rc_close
parameter_list|(
name|struct
name|rcfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rc_getstringptr
parameter_list|(
name|struct
name|rcfile
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rc_getstring
parameter_list|(
name|struct
name|rcfile
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rc_getint
parameter_list|(
name|struct
name|rcfile
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rc_getbool
parameter_list|(
name|struct
name|rcfile
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rc_getsectionscount
parameter_list|(
name|struct
name|rcfile
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|rc_getkeys
parameter_list|(
name|struct
name|rcfile
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
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
comment|/* _SIMRC_H_ */
end_comment

end_unit

