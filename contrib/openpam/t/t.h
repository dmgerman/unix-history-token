begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: t.h 657 2013-03-06 22:59:05Z des $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|T_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|T_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|<security/openpam_attr.h>
end_include

begin_struct
struct|struct
name|t_test
block|{
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|T_FUNC
parameter_list|(
name|n
parameter_list|,
name|d
parameter_list|)
define|\
value|static int t_ ## n ## _func(void *);	\ 	static const struct t_test t_ ## n =	\ 	    { t_ ## n ## _func, d, NULL };	\ 	static int t_ ## n ## _func(OPENPAM_UNUSED(void *arg))
end_define

begin_define
define|#
directive|define
name|T_FUNC_ARG
parameter_list|(
name|n
parameter_list|,
name|d
parameter_list|,
name|a
parameter_list|)
define|\
value|static int t_ ## n ## _func(void *);	\ 	static const struct t_test t_ ## n =	\ 	    { t_ ## n ## _func, d, a };		\ 	static int t_ ## n ## _func(void *arg)
end_define

begin_define
define|#
directive|define
name|T
parameter_list|(
name|n
parameter_list|)
define|\
value|&t_ ## n
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|t_progname
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|const
name|struct
name|t_test
modifier|*
modifier|*
name|t_prepare
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
name|t_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t_verbose
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|OPENPAM_FORMAT
parameter_list|(
function_decl|(__printf__
operator|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Convenience functions for temp files  */
end_comment

begin_struct
struct|struct
name|t_file
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|FILE
modifier|*
name|file
decl_stmt|;
name|struct
name|t_file
modifier|*
name|prev
decl_stmt|,
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|t_file
modifier|*
name|t_fopen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t_fprintf
parameter_list|(
name|struct
name|t_file
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t_ferror
parameter_list|(
name|struct
name|t_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t_feof
parameter_list|(
name|struct
name|t_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t_frewind
parameter_list|(
name|struct
name|t_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t_fclose
parameter_list|(
name|struct
name|t_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t_fcloseall
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

