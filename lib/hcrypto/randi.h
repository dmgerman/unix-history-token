begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HEIM_RANDI_H
end_ifndef

begin_define
define|#
directive|define
name|_HEIM_RANDI_H
value|1
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|RAND_METHOD
name|hc_rand_fortuna_method
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|RAND_METHOD
name|hc_rand_unix_method
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|RAND_METHOD
name|hc_rand_egd_method
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|RAND_METHOD
name|hc_rand_timer_method
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|RAND_METHOD
name|hc_rand_w32crypto_method
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|const
name|RAND_METHOD
modifier|*
name|RAND_timer_method
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_hc_unix_device_fd
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _HEIM_RANDI_H */
end_comment

end_unit

