begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// $Header: /home/daffy/u0/vern/flex/RCS/FlexLexer.h,v 1.19 96/05/25 20:43:02 vern Exp $
end_comment

begin_comment
comment|// $FreeBSD$
end_comment

begin_comment
comment|// FlexLexer.h -- define interfaces for lexical analyzer classes generated
end_comment

begin_comment
comment|//		  by flex
end_comment

begin_comment
comment|// Copyright (c) 1993 The Regents of the University of California.
end_comment

begin_comment
comment|// All rights reserved.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This code is derived from software contributed to Berkeley by
end_comment

begin_comment
comment|// Kent Williams and Tom Epperly.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Redistribution and use in source and binary forms are permitted provided
end_comment

begin_comment
comment|// that: (1) source distributions retain this entire copyright notice and
end_comment

begin_comment
comment|// comment, and (2) distributions including binaries display the following
end_comment

begin_comment
comment|// acknowledgement:  ``This product includes software developed by the
end_comment

begin_comment
comment|// University of California, Berkeley and its contributors'' in the
end_comment

begin_comment
comment|// documentation or other materials provided with the distribution and in
end_comment

begin_comment
comment|// all advertising materials mentioning features or use of this software.
end_comment

begin_comment
comment|// Neither the name of the University nor the names of its contributors may
end_comment

begin_comment
comment|// be used to endorse or promote products derived from this software without
end_comment

begin_comment
comment|// specific prior written permission.
end_comment

begin_comment
comment|// THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
end_comment

begin_comment
comment|// WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
end_comment

begin_comment
comment|// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
end_comment

begin_comment
comment|// This file defines FlexLexer, an abstract class which specifies the
end_comment

begin_comment
comment|// external interface provided to flex C++ lexer objects, and yyFlexLexer,
end_comment

begin_comment
comment|// which defines a particular lexer class.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If you want to create multiple lexer classes, you use the -P flag
end_comment

begin_comment
comment|// to rename each yyFlexLexer to some other xxFlexLexer.  You then
end_comment

begin_comment
comment|// include<FlexLexer.h> in your other sources once per lexer class:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//	#undef yyFlexLexer
end_comment

begin_comment
comment|//	#define yyFlexLexer xxFlexLexer
end_comment

begin_comment
comment|//	#include<FlexLexer.h>
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//	#undef yyFlexLexer
end_comment

begin_comment
comment|//	#define yyFlexLexer zzFlexLexer
end_comment

begin_comment
comment|//	#include<FlexLexer.h>
end_comment

begin_comment
comment|//	...
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FLEX_LEXER_H
end_ifndef

begin_comment
comment|// Never included before - need to define base class.
end_comment

begin_define
define|#
directive|define
name|__FLEX_LEXER_H
end_define

begin_include
include|#
directive|include
file|<iostream.h>
end_include

begin_extern
extern|extern
literal|"C++"
block|{
struct_decl|struct
name|yy_buffer_state
struct_decl|;
typedef|typedef
name|int
name|yy_state_type
typedef|;
name|class
name|FlexLexer
block|{
name|public
label|:
name|virtual
operator|~
name|FlexLexer
argument_list|()
block|{ }
specifier|const
name|char
operator|*
name|YYText
argument_list|()
block|{
return|return
name|yytext
return|;
block|}
name|int
name|YYLeng
parameter_list|()
block|{
return|return
name|yyleng
return|;
block|}
name|virtual
name|void
name|yy_switch_to_buffer
parameter_list|(
name|struct
name|yy_buffer_state
modifier|*
name|new_buffer
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|struct
name|yy_buffer_state
modifier|*
name|yy_create_buffer
parameter_list|(
name|istream
modifier|*
name|s
parameter_list|,
name|int
name|size
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|yy_delete_buffer
parameter_list|(
name|struct
name|yy_buffer_state
modifier|*
name|b
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|yyrestart
parameter_list|(
name|istream
modifier|*
name|s
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|int
name|yylex
parameter_list|()
init|=
literal|0
function_decl|;
comment|// Call yylex with new input/output sources.
name|int
name|yylex
parameter_list|(
name|istream
modifier|*
name|new_in
parameter_list|,
name|ostream
modifier|*
name|new_out
init|=
literal|0
parameter_list|)
block|{
name|switch_streams
argument_list|(
name|new_in
argument_list|,
name|new_out
argument_list|)
expr_stmt|;
return|return
name|yylex
argument_list|()
return|;
block|}
comment|// Switch to new input/output streams.  A nil stream pointer
comment|// indicates "keep the current one".
name|virtual
name|void
name|switch_streams
parameter_list|(
name|istream
modifier|*
name|new_in
init|=
literal|0
parameter_list|,
name|ostream
modifier|*
name|new_out
init|=
literal|0
parameter_list|)
init|=
literal|0
function_decl|;
name|int
name|lineno
argument_list|()
specifier|const
block|{
return|return
name|yylineno
return|;
block|}
name|int
name|debug
argument_list|()
specifier|const
block|{
return|return
name|yy_flex_debug
return|;
block|}
name|void
name|set_debug
parameter_list|(
name|int
name|flag
parameter_list|)
block|{
name|yy_flex_debug
operator|=
name|flag
expr_stmt|;
block|}
name|protected
label|:
name|char
modifier|*
name|yytext
decl_stmt|;
name|int
name|yyleng
decl_stmt|;
name|int
name|yylineno
decl_stmt|;
comment|// only maintained if you use %option yylineno
name|int
name|yy_flex_debug
decl_stmt|;
comment|// only has effect with -d or "%option debug"
block|}
empty_stmt|;
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|yyFlexLexer
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|yyFlexLexerOnce
argument_list|)
end_if

begin_comment
comment|// Either this is the first time through (yyFlexLexerOnce not defined),
end_comment

begin_comment
comment|// or this is a repeated include to define a different flavor of
end_comment

begin_comment
comment|// yyFlexLexer, as discussed in the flex man page.
end_comment

begin_define
define|#
directive|define
name|yyFlexLexerOnce
end_define

begin_decl_stmt
name|class
name|yyFlexLexer
range|:
name|public
name|FlexLexer
block|{
name|public
operator|:
comment|// arg_yyin and arg_yyout default to the cin and cout, but we
comment|// only make that assignment when initializing in yylex().
name|yyFlexLexer
argument_list|(
name|istream
operator|*
name|arg_yyin
operator|=
literal|0
argument_list|,
name|ostream
operator|*
name|arg_yyout
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|yyFlexLexer
argument_list|()
block|;
name|void
name|yy_switch_to_buffer
argument_list|(
expr|struct
name|yy_buffer_state
operator|*
name|new_buffer
argument_list|)
block|; 	struct
name|yy_buffer_state
operator|*
name|yy_create_buffer
argument_list|(
argument|istream* s
argument_list|,
argument|int size
argument_list|)
block|;
name|void
name|yy_delete_buffer
argument_list|(
expr|struct
name|yy_buffer_state
operator|*
name|b
argument_list|)
block|;
name|void
name|yyrestart
argument_list|(
name|istream
operator|*
name|s
argument_list|)
block|;
name|virtual
name|int
name|yylex
argument_list|()
block|;
name|virtual
name|void
name|switch_streams
argument_list|(
name|istream
operator|*
name|new_in
argument_list|,
name|ostream
operator|*
name|new_out
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|int
name|LexerInput
argument_list|(
argument|char* buf
argument_list|,
argument|int max_size
argument_list|)
block|;
name|virtual
name|void
name|LexerOutput
argument_list|(
argument|const char* buf
argument_list|,
argument|int size
argument_list|)
block|;
name|virtual
name|void
name|LexerError
argument_list|(
specifier|const
name|char
operator|*
name|msg
argument_list|)
block|;
name|void
name|yyunput
argument_list|(
argument|int c
argument_list|,
argument|char* buf_ptr
argument_list|)
block|;
name|int
name|yyinput
argument_list|()
block|;
name|void
name|yy_load_buffer_state
argument_list|()
block|;
name|void
name|yy_init_buffer
argument_list|(
expr|struct
name|yy_buffer_state
operator|*
name|b
argument_list|,
name|istream
operator|*
name|s
argument_list|)
block|;
name|void
name|yy_flush_buffer
argument_list|(
expr|struct
name|yy_buffer_state
operator|*
name|b
argument_list|)
block|;
name|int
name|yy_start_stack_ptr
block|;
name|int
name|yy_start_stack_depth
block|;
name|int
operator|*
name|yy_start_stack
block|;
name|void
name|yy_push_state
argument_list|(
argument|int new_state
argument_list|)
block|;
name|void
name|yy_pop_state
argument_list|()
block|;
name|int
name|yy_top_state
argument_list|()
block|;
name|yy_state_type
name|yy_get_previous_state
argument_list|()
block|;
name|yy_state_type
name|yy_try_NUL_trans
argument_list|(
argument|yy_state_type current_state
argument_list|)
block|;
name|int
name|yy_get_next_buffer
argument_list|()
block|;
name|istream
operator|*
name|yyin
block|;
comment|// input source for default LexerInput
name|ostream
operator|*
name|yyout
block|;
comment|// output sink for default LexerOutput
block|struct
name|yy_buffer_state
operator|*
name|yy_current_buffer
block|;
comment|// yy_hold_char holds the character lost when yytext is formed.
name|char
name|yy_hold_char
block|;
comment|// Number of characters read into yy_ch_buf.
name|int
name|yy_n_chars
block|;
comment|// Points to current character in buffer.
name|char
operator|*
name|yy_c_buf_p
block|;
name|int
name|yy_init
block|;
comment|// whether we need to initialize
name|int
name|yy_start
block|;
comment|// start state number
comment|// Flag which is used to allow yywrap()'s to do buffer switches
comment|// instead of setting up a fresh yyin.  A bit of a hack ...
name|int
name|yy_did_buffer_switch_on_eof
block|;
comment|// The following are not always needed, but may be depending
comment|// on use of certain flex features (like REJECT or yymore()).
name|yy_state_type
name|yy_last_accepting_state
block|;
name|char
operator|*
name|yy_last_accepting_cpos
block|;
name|yy_state_type
operator|*
name|yy_state_buf
block|;
name|yy_state_type
operator|*
name|yy_state_ptr
block|;
name|char
operator|*
name|yy_full_match
block|;
name|int
operator|*
name|yy_full_state
block|;
name|int
name|yy_full_lp
block|;
name|int
name|yy_lp
block|;
name|int
name|yy_looking_for_trail_begin
block|;
name|int
name|yy_more_flag
block|;
name|int
name|yy_more_len
block|;
name|int
name|yy_more_offset
block|;
name|int
name|yy_prev_more_offset
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

