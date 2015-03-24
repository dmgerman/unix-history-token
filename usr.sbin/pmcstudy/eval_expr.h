begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__eval_expr_h__
end_ifndef

begin_define
define|#
directive|define
name|__eval_expr_h__
end_define

begin_comment
comment|/*-  * Copyright (c) 2015 Netflix Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_enum
enum|enum
name|exptype
block|{
name|TYPE_OP_PLUS
block|,
name|TYPE_OP_MINUS
block|,
name|TYPE_OP_MULT
block|,
name|TYPE_OP_DIVIDE
block|,
name|TYPE_PARN_OPEN
block|,
name|TYPE_PARN_CLOSE
block|,
name|TYPE_VALUE_CON
block|,
name|TYPE_VALUE_PMC
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|STATE_UNSET
value|0
end_define

begin_comment
comment|/* We have no setting yet in value */
end_comment

begin_define
define|#
directive|define
name|STATE_FILLED
value|1
end_define

begin_comment
comment|/* We have filled in value */
end_comment

begin_struct
struct|struct
name|expression
block|{
name|struct
name|expression
modifier|*
name|next
decl_stmt|;
comment|/* Next in expression. */
name|struct
name|expression
modifier|*
name|prev
decl_stmt|;
comment|/* Prev in expression. */
name|double
name|value
decl_stmt|;
comment|/* If there is a value to set */
name|enum
name|exptype
name|type
decl_stmt|;
comment|/* What is it */
name|uint8_t
name|state
decl_stmt|;
comment|/* Current state if value type */
name|char
name|name
index|[
literal|252
index|]
decl_stmt|;
comment|/* If a PMC whats the name, con value*/
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|expression
modifier|*
name|parse_expression
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|run_expr
parameter_list|(
name|struct
name|expression
modifier|*
name|exp
parameter_list|,
name|int
name|initial_call
parameter_list|,
name|struct
name|expression
modifier|*
modifier|*
name|lastone
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_exp
parameter_list|(
name|struct
name|expression
modifier|*
name|exp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

