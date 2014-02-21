begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2008 Edwin Groothuis. All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Options  */
end_comment

begin_function_decl
name|void
name|init_options
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|make_options
parameter_list|(
name|int
name|peer
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|,
name|uint16_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_options
parameter_list|(
name|int
name|peer
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|,
name|uint16_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Call back functions */
end_comment

begin_function_decl
name|int
name|option_tsize
parameter_list|(
name|int
name|peer
parameter_list|,
name|struct
name|tftphdr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|option_timeout
parameter_list|(
name|int
name|peer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|option_blksize
parameter_list|(
name|int
name|peer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|option_blksize2
parameter_list|(
name|int
name|peer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|option_rollover
parameter_list|(
name|int
name|peer
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|options_extra_enabled
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|options_rfc_enabled
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|options
block|{
specifier|const
name|char
modifier|*
name|o_type
decl_stmt|;
name|char
modifier|*
name|o_request
decl_stmt|;
name|char
modifier|*
name|o_reply
decl_stmt|;
name|int
function_decl|(
modifier|*
name|o_handler
function_decl|)
parameter_list|(
name|int
name|peer
parameter_list|)
function_decl|;
name|int
name|rfc
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|options
name|options
index|[]
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|opt_enum
block|{
name|OPT_TSIZE
init|=
literal|0
block|,
name|OPT_TIMEOUT
block|,
name|OPT_BLKSIZE
block|,
name|OPT_BLKSIZE2
block|,
name|OPT_ROLLOVER
block|, }
enum|;
end_enum

end_unit

