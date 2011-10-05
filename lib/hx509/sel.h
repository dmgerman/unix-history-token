begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_enum
enum|enum
name|hx_expr_op
block|{
name|op_TRUE
block|,
name|op_FALSE
block|,
name|op_NOT
block|,
name|op_AND
block|,
name|op_OR
block|,
name|op_COMP
block|,
name|comp_EQ
block|,
name|comp_NE
block|,
name|comp_IN
block|,
name|comp_TAILEQ
block|,
name|expr_NUMBER
block|,
name|expr_STRING
block|,
name|expr_FUNCTION
block|,
name|expr_VAR
block|,
name|expr_WORDS
block|}
enum|;
end_enum

begin_struct
struct|struct
name|hx_expr
block|{
name|enum
name|hx_expr_op
name|op
decl_stmt|;
name|void
modifier|*
name|arg1
decl_stmt|;
name|void
modifier|*
name|arg2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hx_expr_input
block|{
specifier|const
name|char
modifier|*
name|buf
decl_stmt|;
name|size_t
name|length
decl_stmt|;
name|size_t
name|offset
decl_stmt|;
name|struct
name|hx_expr
modifier|*
name|expr
decl_stmt|;
name|char
modifier|*
name|error
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|hx_expr_input
name|_hx509_expr_input
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|yyparse
value|_hx509_sel_yyparse
end_define

begin_define
define|#
directive|define
name|yylex
value|_hx509_sel_yylex
end_define

begin_define
define|#
directive|define
name|yyerror
value|_hx509_sel_yyerror
end_define

begin_define
define|#
directive|define
name|yylval
value|_hx509_sel_yylval
end_define

begin_define
define|#
directive|define
name|yychar
value|_hx509_sel_yychar
end_define

begin_define
define|#
directive|define
name|yydebug
value|_hx509_sel_yydebug
end_define

begin_define
define|#
directive|define
name|yynerrs
value|_hx509_sel_yynerrs
end_define

begin_define
define|#
directive|define
name|yywrap
value|_hx509_sel_yywrap
end_define

begin_function_decl
name|int
name|_hx509_sel_yyparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_hx509_sel_yylex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_hx509_sel_yyerror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

