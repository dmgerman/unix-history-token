begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * configyyrename.h -- renames for config file yy values to avoid conflicts.  *  * Copyright (c) 2001-2006, NLnet Labs. All rights reserved.  *  * See LICENSE for the license.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_CONFIGYYRENAME_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_CONFIGYYRENAME_H
end_define

begin_comment
comment|/* defines to change symbols so that no yacc/lex symbols clash */
end_comment

begin_define
define|#
directive|define
name|yymaxdepth
value|ub_c_maxdepth
end_define

begin_define
define|#
directive|define
name|yyparse
value|ub_c_parse
end_define

begin_define
define|#
directive|define
name|yylex
value|ub_c_lex
end_define

begin_define
define|#
directive|define
name|yyerror
value|ub_c_error
end_define

begin_define
define|#
directive|define
name|yylval
value|ub_c_lval
end_define

begin_define
define|#
directive|define
name|yychar
value|ub_c_char
end_define

begin_define
define|#
directive|define
name|yydebug
value|ub_c_debug
end_define

begin_define
define|#
directive|define
name|yypact
value|ub_c_pact
end_define

begin_define
define|#
directive|define
name|yyr1
value|ub_c_r1
end_define

begin_define
define|#
directive|define
name|yyr2
value|ub_c_r2
end_define

begin_define
define|#
directive|define
name|yydef
value|ub_c_def
end_define

begin_define
define|#
directive|define
name|yychk
value|ub_c_chk
end_define

begin_define
define|#
directive|define
name|yypgo
value|ub_c_pgo
end_define

begin_define
define|#
directive|define
name|yyact
value|ub_c_act
end_define

begin_define
define|#
directive|define
name|yyexca
value|ub_c_exca
end_define

begin_define
define|#
directive|define
name|yyerrflag
value|ub_c_errflag
end_define

begin_define
define|#
directive|define
name|yynerrs
value|ub_c_nerrs
end_define

begin_define
define|#
directive|define
name|yyps
value|ub_c_ps
end_define

begin_define
define|#
directive|define
name|yypv
value|ub_c_pv
end_define

begin_define
define|#
directive|define
name|yys
value|ub_c_s
end_define

begin_define
define|#
directive|define
name|yy_yys
value|ub_c_yys
end_define

begin_define
define|#
directive|define
name|yystate
value|ub_c_state
end_define

begin_define
define|#
directive|define
name|yytmp
value|ub_c_tmp
end_define

begin_define
define|#
directive|define
name|yyv
value|ub_c_v
end_define

begin_define
define|#
directive|define
name|yy_yyv
value|ub_c_yyv
end_define

begin_define
define|#
directive|define
name|yyval
value|ub_c_val
end_define

begin_define
define|#
directive|define
name|yylloc
value|ub_c_lloc
end_define

begin_define
define|#
directive|define
name|yyreds
value|ub_c_reds
end_define

begin_define
define|#
directive|define
name|yytoks
value|ub_c_toks
end_define

begin_define
define|#
directive|define
name|yyin
value|ub_c_in
end_define

begin_define
define|#
directive|define
name|yyout
value|ub_c_out
end_define

begin_define
define|#
directive|define
name|yywrap
value|ub_c_wrap
end_define

begin_define
define|#
directive|define
name|yy_load_buffer_state
value|ub_c_load_buffer_state
end_define

begin_define
define|#
directive|define
name|yy_switch_to_buffer
value|ub_c_switch_to_buffer
end_define

begin_define
define|#
directive|define
name|yy_flush_buffer
value|ub_c_flush_buffer
end_define

begin_define
define|#
directive|define
name|yy_init_buffer
value|ub_c_init_buffer
end_define

begin_define
define|#
directive|define
name|yy_scan_buffer
value|ub_c_scan_buffer
end_define

begin_define
define|#
directive|define
name|yy_scan_bytes
value|ub_c_scan_bytes
end_define

begin_define
define|#
directive|define
name|yy_scan_string
value|ub_c_scan_string
end_define

begin_define
define|#
directive|define
name|yy_create_buffer
value|ub_c_create_buffer
end_define

begin_define
define|#
directive|define
name|yyrestart
value|ub_c_restart
end_define

begin_define
define|#
directive|define
name|yy_delete_buffer
value|ub_c_delete_buffer
end_define

begin_define
define|#
directive|define
name|yypop_buffer_state
value|ub_c_pop_buffer_state
end_define

begin_define
define|#
directive|define
name|yypush_buffer_state
value|ub_c_push_buffer_state
end_define

begin_define
define|#
directive|define
name|yyunput
value|ub_c_unput
end_define

begin_define
define|#
directive|define
name|yyset_in
value|ub_c_set_in
end_define

begin_define
define|#
directive|define
name|yyget_in
value|ub_c_get_in
end_define

begin_define
define|#
directive|define
name|yyset_out
value|ub_c_set_out
end_define

begin_define
define|#
directive|define
name|yyget_out
value|ub_c_get_out
end_define

begin_define
define|#
directive|define
name|yyget_lineno
value|ub_c_get_lineno
end_define

begin_define
define|#
directive|define
name|yyset_lineno
value|ub_c_set_lineno
end_define

begin_define
define|#
directive|define
name|yyset_debug
value|ub_c_set_debug
end_define

begin_define
define|#
directive|define
name|yyget_debug
value|ub_c_get_debug
end_define

begin_define
define|#
directive|define
name|yy_flex_debug
value|ub_c_flex_debug
end_define

begin_define
define|#
directive|define
name|yylex_destroy
value|ub_c_lex_destroy
end_define

begin_define
define|#
directive|define
name|yyfree
value|ub_c_free
end_define

begin_define
define|#
directive|define
name|yyrealloc
value|ub_c_realloc
end_define

begin_define
define|#
directive|define
name|yyalloc
value|ub_c_alloc
end_define

begin_define
define|#
directive|define
name|yymalloc
value|ub_c_malloc
end_define

begin_define
define|#
directive|define
name|yyget_leng
value|ub_c_get_leng
end_define

begin_define
define|#
directive|define
name|yylineno
value|ub_c_lineno
end_define

begin_define
define|#
directive|define
name|yyget_text
value|ub_c_get_text
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_CONFIGYYRENAME_H */
end_comment

end_unit

