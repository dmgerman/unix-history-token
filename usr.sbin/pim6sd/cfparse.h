begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1999 WIDE Project.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|YIPS_DEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|DP
parameter_list|(
name|str
parameter_list|)
value|YIPSDEBUG(DEBUG_CONF, cfdebug_print(str, yytext, yyleng))
end_define

begin_define
define|#
directive|define
name|YYD_ECHO
define|\
value|{ YIPSDEBUG(DEBUG_CONF, printf("<%d>", yy_start); ECHO ; printf("\n");); }
end_define

begin_define
define|#
directive|define
name|YIPSDP
parameter_list|(
name|cmd
parameter_list|)
value|YIPSDEBUG(DEBUG_CONF, cmd)
end_define

begin_define
define|#
directive|define
name|PLOG
value|printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DP
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|YYD_ECHO
end_define

begin_define
define|#
directive|define
name|YIPSDP
parameter_list|(
name|cmd
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PLOG
parameter_list|(
name|cmd
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(YIPS_DEBUG) */
end_comment

begin_comment
comment|/* cfparse.y */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cf_init
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|re_cfparse
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|cf_post_config
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yyparse
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cftoken.l */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|yyerror
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|yywarn
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cfparse
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

