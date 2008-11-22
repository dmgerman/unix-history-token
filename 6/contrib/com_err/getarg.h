begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. All advertising materials mentioning features or use of this software   *    must display the following acknowledgement:   *      This product includes software developed by Kungliga Tekniska   *      Högskolan and its contributors.   *  * 4. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: getarg.h,v 1.5 1998/08/18 20:26:11 assar Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GETARG_H__
end_ifndef

begin_define
define|#
directive|define
name|__GETARG_H__
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)>(b))?(a):(b))
end_define

begin_struct
struct|struct
name|getargs
block|{
specifier|const
name|char
modifier|*
name|long_name
decl_stmt|;
name|char
name|short_name
decl_stmt|;
enum|enum
block|{
name|arg_integer
block|,
name|arg_string
block|,
name|arg_flag
block|,
name|arg_negative_flag
block|,
name|arg_strings
block|}
name|type
enum|;
name|void
modifier|*
name|value
decl_stmt|;
specifier|const
name|char
modifier|*
name|help
decl_stmt|;
specifier|const
name|char
modifier|*
name|arg_help
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|ARG_ERR_NO_MATCH
init|=
literal|1
block|,
name|ARG_ERR_BAD_ARG
block|,
name|ARG_ERR_NO_ARG
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|getarg_strings
block|{
name|int
name|num_strings
decl_stmt|;
name|char
modifier|*
modifier|*
name|strings
decl_stmt|;
block|}
name|getarg_strings
typedef|;
end_typedef

begin_function_decl
name|int
name|getarg
parameter_list|(
name|struct
name|getargs
modifier|*
name|args
parameter_list|,
name|size_t
name|num_args
parameter_list|,
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|int
modifier|*
name|optind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arg_printusage
parameter_list|(
name|struct
name|getargs
modifier|*
name|args
parameter_list|,
name|size_t
name|num_args
parameter_list|,
specifier|const
name|char
modifier|*
name|progname
parameter_list|,
specifier|const
name|char
modifier|*
name|extra_string
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GETARG_H__ */
end_comment

end_unit

