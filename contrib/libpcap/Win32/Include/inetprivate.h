begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 - 2003  * NetGroup, Politecnico di Torino (Italy)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  * 3. Neither the name of the Politecnico di Torino nor the names of its  * contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
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
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<net/netdb.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_function_decl
specifier|extern
name|void
name|_sethtent
parameter_list|(
name|int
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_endhtent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|hostent
modifier|*
name|_gethtent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|hostent
modifier|*
name|_gethtbyname
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|hostent
modifier|*
name|_gethtbyaddr
parameter_list|(
specifier|const
name|char
modifier|*
name|addr
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_validuser
parameter_list|(
name|FILE
modifier|*
name|hostf
parameter_list|,
specifier|const
name|char
modifier|*
name|rhost
parameter_list|,
specifier|const
name|char
modifier|*
name|luser
parameter_list|,
specifier|const
name|char
modifier|*
name|ruser
parameter_list|,
name|int
name|baselen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_checkhost
parameter_list|(
specifier|const
name|char
modifier|*
name|rhost
parameter_list|,
specifier|const
name|char
modifier|*
name|lhost
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern void putlong(u_long l, u_char *msgp); extern void putshort(u_short l, u_char *msgp); extern u_int32_t _getlong(register const u_char *msgp); extern u_int16_t _getshort(register const u_char *msgp); extern void p_query(char *msg); extern void fp_query(char *msg, FILE *file); extern char *p_cdname(char *cp, char *msg, FILE *file); extern char *p_rr(char *cp, char *msg, FILE *file); extern char *p_type(int type); extern char * p_class(int class); extern char *p_time(u_long value);
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|hostalias
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sethostfile
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_res_close
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ruserpass
parameter_list|(
specifier|const
name|char
modifier|*
name|host
parameter_list|,
name|char
modifier|*
modifier|*
name|aname
parameter_list|,
name|char
modifier|*
modifier|*
name|apass
parameter_list|)
function_decl|;
end_function_decl

end_unit

