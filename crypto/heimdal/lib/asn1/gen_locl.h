begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2005 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GEN_LOCL_H__
end_ifndef

begin_define
define|#
directive|define
name|__GEN_LOCL_H__
end_define

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_include
include|#
directive|include
file|"hash.h"
end_include

begin_include
include|#
directive|include
file|"symbol.h"
end_include

begin_include
include|#
directive|include
file|"asn1-common.h"
end_include

begin_include
include|#
directive|include
file|"der.h"
end_include

begin_include
include|#
directive|include
file|"der-private.h"
end_include

begin_function_decl
name|void
name|generate_type
parameter_list|(
specifier|const
name|Symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generate_constant
parameter_list|(
specifier|const
name|Symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generate_type_encode
parameter_list|(
specifier|const
name|Symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generate_type_decode
parameter_list|(
specifier|const
name|Symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generate_type_free
parameter_list|(
specifier|const
name|Symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generate_type_length
parameter_list|(
specifier|const
name|Symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generate_type_copy
parameter_list|(
specifier|const
name|Symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generate_type_seq
parameter_list|(
specifier|const
name|Symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generate_glue
parameter_list|(
specifier|const
name|Type
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|classname
parameter_list|(
name|Der_class
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|valuename
parameter_list|(
name|Der_class
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gen_compare_defval
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|value
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gen_assign_defval
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|value
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_generate
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|get_filename
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|close_generate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_import
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_export
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_export
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yyparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_primitive_type
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|preserve_type
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|seq_type
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generate_header_of_codefile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|close_codefile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_template_compat
parameter_list|(
specifier|const
name|Symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generate_template
parameter_list|(
specifier|const
name|Symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gen_template_import
parameter_list|(
specifier|const
name|Symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|privheaderfile
decl_stmt|,
modifier|*
name|headerfile
decl_stmt|,
modifier|*
name|codefile
decl_stmt|,
modifier|*
name|logfile
decl_stmt|,
modifier|*
name|templatefile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|support_ber
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|template_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rfc1510_bitstring
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|one_code_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|error_flag
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GEN_LOCL_H__ */
end_comment

end_unit

