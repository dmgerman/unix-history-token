begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: compile_et.h,v 1.4 1999/12/02 16:58:38 joda Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__COMPILE_ET_H__
end_ifndef

begin_define
define|#
directive|define
name|__COMPILE_ET_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_decl_stmt
specifier|extern
name|long
name|base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|number
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|prefix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|name
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|id_str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|filename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|numerror
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|error_code
block|{
name|unsigned
name|number
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|string
decl_stmt|;
name|struct
name|error_code
modifier|*
name|next
decl_stmt|,
modifier|*
modifier|*
name|tail
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|error_code
modifier|*
name|codes
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|APPEND
parameter_list|(
name|L
parameter_list|,
name|V
parameter_list|)
define|\
value|do {						\     if((L) == NULL) {				\ 	(L) = (V);				\ 	(L)->tail =&(V)->next;			\ 	(L)->next = NULL;			\     }else{					\ 	*(L)->tail = (V);			\ 	(L)->tail =&(V)->next;			\     }						\ }while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __COMPILE_ET_H__ */
end_comment

end_unit

