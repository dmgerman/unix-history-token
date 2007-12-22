begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998, 1999 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: gss_common.h,v 1.5 1999/12/02 17:04:56 joda Exp $ */
end_comment

begin_function_decl
name|void
name|write_token
parameter_list|(
name|int
name|sock
parameter_list|,
name|gss_buffer_t
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_token
parameter_list|(
name|int
name|sock
parameter_list|,
name|gss_buffer_t
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gss_print_errors
parameter_list|(
name|int
name|min_stat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gss_verr
parameter_list|(
name|int
name|exitval
parameter_list|,
name|int
name|status
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|gss_err
parameter_list|(
name|int
name|exitval
parameter_list|,
name|int
name|status
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

end_unit

