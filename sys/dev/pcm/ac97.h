begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Cameron Grant<gandalf@vilnya.demon.co.uk>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
function_decl|(
name|ac97_read
function_decl|)
parameter_list|(
name|void
modifier|*
name|devinfo
parameter_list|,
name|int
name|regno
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|ac97_write
function_decl|)
parameter_list|(
name|void
modifier|*
name|devinfo
parameter_list|,
name|int
name|regno
parameter_list|,
name|u_int32_t
name|data
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|snd_mixer
name|ac97_mixer
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|ac97_info
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|ac97_info
modifier|*
name|ac97_create
parameter_list|(
name|void
modifier|*
name|devinfo
parameter_list|,
name|ac97_read
modifier|*
name|rd
parameter_list|,
name|ac97_write
modifier|*
name|wr
parameter_list|)
function_decl|;
end_function_decl

end_unit

