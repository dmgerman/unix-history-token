begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the Kungliga Tekniska  *      Högskolan and its contributors.  *   * 4. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: krb4.h,v 1.10 1997/04/01 08:17:22 joda Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KRB4_H__
end_ifndef

begin_define
define|#
directive|define
name|__KRB4_H__
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|auth_complete
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|sec_status
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|prot_clear
block|,
name|prot_safe
block|,
name|prot_confidential
block|,
name|prot_private
block|}
enum|;
end_enum

begin_function_decl
name|void
name|sec_prot
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sec_getc
parameter_list|(
name|FILE
modifier|*
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sec_putc
parameter_list|(
name|int
name|c
parameter_list|,
name|FILE
modifier|*
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sec_fflush
parameter_list|(
name|FILE
modifier|*
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sec_read
parameter_list|(
name|int
name|fd
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sec_write
parameter_list|(
name|int
name|fd
parameter_list|,
name|char
modifier|*
name|data
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb4_getc
parameter_list|(
name|FILE
modifier|*
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb4_read
parameter_list|(
name|int
name|fd
parameter_list|,
name|char
modifier|*
name|data
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sec_set_protection_level
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sec_request_prot
parameter_list|(
name|char
modifier|*
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kauth
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|klist
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|krb4_quit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb4_write_enc
parameter_list|(
name|FILE
modifier|*
name|F
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb4_read_msg
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|int
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb4_read_mic
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb4_read_enc
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_klogin
parameter_list|(
name|char
modifier|*
name|host
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KRB4_H__ */
end_comment

end_unit

