begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: parse_units.h,v 1.6 1999/12/02 16:58:51 joda Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PARSE_UNITS_H__
end_ifndef

begin_define
define|#
directive|define
name|__PARSE_UNITS_H__
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_struct
struct|struct
name|units
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|mult
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|units
name|units
typedef|;
end_typedef

begin_function_decl
name|int
name|parse_units
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
specifier|const
name|struct
name|units
modifier|*
name|units
parameter_list|,
specifier|const
name|char
modifier|*
name|def_unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_units_table
parameter_list|(
specifier|const
name|struct
name|units
modifier|*
name|units
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_flags
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
specifier|const
name|struct
name|units
modifier|*
name|units
parameter_list|,
name|int
name|orig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|unparse_units
parameter_list|(
name|int
name|num
parameter_list|,
specifier|const
name|struct
name|units
modifier|*
name|units
parameter_list|,
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|unparse_units_approx
parameter_list|(
name|int
name|num
parameter_list|,
specifier|const
name|struct
name|units
modifier|*
name|units
parameter_list|,
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|unparse_flags
parameter_list|(
name|int
name|num
parameter_list|,
specifier|const
name|struct
name|units
modifier|*
name|units
parameter_list|,
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_flags_table
parameter_list|(
specifier|const
name|struct
name|units
modifier|*
name|units
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PARSE_UNITS_H__ */
end_comment

end_unit

