begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2012 Semihalf.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|__UTILS_H
end_define

begin_struct
struct|struct
name|cmd_param
block|{
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
name|char
name|value
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|char
modifier|*
name|param_get_string
parameter_list|(
name|struct
name|cmd_param
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|param_get_int
parameter_list|(
name|struct
name|cmd_param
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|param_get_intx
parameter_list|(
name|struct
name|cmd_param
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|param_get_boolean
parameter_list|(
name|struct
name|cmd_param
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|param_has_value
parameter_list|(
name|struct
name|cmd_param
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|param_get_count
parameter_list|(
name|struct
name|cmd_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|perrorf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hexdumpoffset
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hexdump
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|xmalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Command handlers */
end_comment

begin_function_decl
name|int
name|nand_read
parameter_list|(
name|struct
name|cmd_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nand_write
parameter_list|(
name|struct
name|cmd_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nand_read_oob
parameter_list|(
name|struct
name|cmd_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nand_write_oob
parameter_list|(
name|struct
name|cmd_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nand_erase
parameter_list|(
name|struct
name|cmd_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nand_info
parameter_list|(
name|struct
name|cmd_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __UTILS_H */
end_comment

end_unit

