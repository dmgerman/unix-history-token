begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: cflib.h,v 1.3 2000/07/11 01:51:49 bp Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_zzzzzz_RCFILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_zzzzzz_RCFILE_H_
end_define

begin_struct_decl
struct_decl|struct
name|rcfile
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * A unified options parser  */
end_comment

begin_enum
enum|enum
name|opt_argtype
block|{
name|OPTARG_STR
block|,
name|OPTARG_INT
block|,
name|OPTARG_BOOL
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|opt_args
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|opt_callback_t
parameter_list|(
name|struct
name|opt_args
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|OPTFL_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|OPTFL_HAVEMIN
value|0x0001
end_define

begin_define
define|#
directive|define
name|OPTFL_HAVEMAX
value|0x0002
end_define

begin_define
define|#
directive|define
name|OPTFL_MINMAX
value|NAFL_HAVEMIN | NAFL_HAVEMAX
end_define

begin_struct
struct|struct
name|opt_args
block|{
name|enum
name|opt_argtype
name|type
decl_stmt|;
name|int
name|opt
decl_stmt|;
comment|/* command line option */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* rc file equiv */
name|int
name|flag
decl_stmt|;
comment|/* OPTFL_* */
name|int
name|ival
decl_stmt|;
comment|/* int/bool values, or max len for str value */
name|char
modifier|*
name|str
decl_stmt|;
comment|/* string value */
name|int
name|min
decl_stmt|;
comment|/* min for ival */
name|int
name|max
decl_stmt|;
comment|/* max for ival */
name|opt_callback_t
modifier|*
name|fn
decl_stmt|;
comment|/* call back to validate */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|cf_opterr
decl_stmt|,
name|cf_optind
decl_stmt|,
name|cf_optopt
decl_stmt|,
name|cf_optreset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|cf_optarg
decl_stmt|;
end_decl_stmt

begin_function_decl
name|__BEGIN_DECLS
name|int
name|opt_args_parse
parameter_list|(
name|struct
name|rcfile
modifier|*
parameter_list|,
name|struct
name|opt_args
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|opt_callback_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|opt_args_parseopt
parameter_list|(
name|struct
name|opt_args
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|opt_callback_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cf_getopt
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
specifier|const
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
name|rc_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|rcfile
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rc_close
parameter_list|(
name|struct
name|rcfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rc_merge
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|rcfile
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rc_getstringptr
parameter_list|(
name|struct
name|rcfile
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rc_getstring
parameter_list|(
name|struct
name|rcfile
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rc_getint
parameter_list|(
name|struct
name|rcfile
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rc_getbool
parameter_list|(
name|struct
name|rcfile
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _zzzzzz_RCFILE_H_ */
end_comment

end_unit

