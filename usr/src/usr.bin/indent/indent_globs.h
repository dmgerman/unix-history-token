begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * Copyright (c) 1976 Board of Trustees of the University of Illinois.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley and the University of  * Illinois at Urbana.  The name of either University may not be used  * to endorse or promote products derived from this software without  * specific prior written permission. This software is provided  * ``as is'' without express or implied warranty.  *  *	@(#)indent_globs.h	5.5 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* FILE NAME: 	indent_globs.h  PURPOSE: 	This include file contains the declarations for all global variables 	used in indent.  GLOBALS: 	The names of all of the variables will not be repeated here.  The  	declarations start on the next page.  FUNCTIONS: 	None */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|BACKSLASH
value|'\\'
end_define

begin_define
define|#
directive|define
name|bufsize
value|600
end_define

begin_comment
comment|/* size of internal buffers */
end_comment

begin_define
define|#
directive|define
name|inp_bufs
value|600
end_define

begin_comment
comment|/* size of input buffer */
end_comment

begin_define
define|#
directive|define
name|sc_size
value|5000
end_define

begin_comment
comment|/* size of save_com buffer */
end_comment

begin_define
define|#
directive|define
name|label_offset
value|2
end_define

begin_comment
comment|/* number of levels a label is placed to left of code  		   */
end_comment

begin_define
define|#
directive|define
name|tabsize
value|8
end_define

begin_comment
comment|/* the size of a tab */
end_comment

begin_define
define|#
directive|define
name|tabmask
value|0177770
end_define

begin_comment
comment|/* mask used when figuring length of lines with tabs */
end_comment

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_decl_stmt
name|FILE
modifier|*
name|input
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the fid for the input file */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|output
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the output file */
end_comment

begin_decl_stmt
name|char
name|labbuf
index|[
name|bufsize
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for label */
end_comment

begin_decl_stmt
name|char
modifier|*
name|s_lab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start ... */
end_comment

begin_decl_stmt
name|char
modifier|*
name|e_lab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* .. and end of stored label */
end_comment

begin_decl_stmt
name|char
name|codebuf
index|[
name|bufsize
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for code section */
end_comment

begin_decl_stmt
name|char
modifier|*
name|s_code
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start ... */
end_comment

begin_decl_stmt
name|char
modifier|*
name|e_code
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* .. and end of stored code */
end_comment

begin_decl_stmt
name|char
name|combuf
index|[
name|bufsize
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for comments */
end_comment

begin_decl_stmt
name|char
modifier|*
name|s_com
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start ... */
end_comment

begin_decl_stmt
name|char
modifier|*
name|e_com
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ... and end of stored comments */
end_comment

begin_decl_stmt
name|char
name|in_buffer
index|[
name|inp_bufs
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input buffer */
end_comment

begin_decl_stmt
name|char
modifier|*
name|buf_ptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to next character to be taken from in_buffer */
end_comment

begin_decl_stmt
name|char
modifier|*
name|buf_end
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to first after last char in in_buffer */
end_comment

begin_decl_stmt
name|char
name|save_com
index|[
name|sc_size
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input text is saved here when looking for the brace 		      after an if, while, etc */
end_comment

begin_decl_stmt
name|char
modifier|*
name|sc_end
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer into save_com buffer */
end_comment

begin_decl_stmt
name|char
modifier|*
name|bp_save
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* saved value of buf_ptr when taking input from 		      save_com */
end_comment

begin_decl_stmt
name|char
modifier|*
name|be_save
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* similarly saved value of buf_end */
end_comment

begin_decl_stmt
name|char
name|token
index|[
name|bufsize
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the last token scanned */
end_comment

begin_decl_stmt
name|int
name|blanklines_after_declarations
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|blanklines_before_blockcomments
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|blanklines_after_procs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|swallow_optional_blanklines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|n_real_blanklines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|prefix_blankline_requested
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|postfix_blankline_requested
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|break_comma
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when true and not in parens, break after a comma */
end_comment

begin_decl_stmt
name|int
name|btype_2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when true, brace should be on same line as if, 		      while, etc */
end_comment

begin_decl_stmt
name|float
name|case_ind
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* indentation level to be used for a "case n:" */
end_comment

begin_decl_stmt
name|int
name|code_lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of lines with code */
end_comment

begin_decl_stmt
name|int
name|had_eof
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to true when input is exhausted */
end_comment

begin_decl_stmt
name|int
name|line_no
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the current line number. */
end_comment

begin_decl_stmt
name|int
name|max_col
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the maximum allowable line length */
end_comment

begin_decl_stmt
name|int
name|pointer_as_binop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when true, "->" is treated as a binary 				   operator (giving, e.g., "p -> f") */
end_comment

begin_decl_stmt
name|int
name|verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when true, non-essential error messages are printed  		   */
end_comment

begin_decl_stmt
name|int
name|cuddle_else
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if else should cuddle up to '}' */
end_comment

begin_decl_stmt
name|int
name|star_comment_cont
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true iff comment continuation lines should 				   have stars at the beginning of each line. 				   */
end_comment

begin_decl_stmt
name|int
name|comment_delimiter_on_blankline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|troff
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true iff were generating troff input */
end_comment

begin_decl_stmt
name|int
name|procnames_start_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if true, the names of procedures being 				   defined get placed in column 1 (ie. a 				   newline is placed between the type of the 				   procedure and its name) */
end_comment

begin_decl_stmt
name|int
name|proc_calls_space
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If true, procedure calls look like: 				   foo(bar) rather than foo (bar) */
end_comment

begin_decl_stmt
name|int
name|format_col1_comments
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If comments which start in column 1 are to 				   be magically reformatted (just like comments that 				   begin in later columns) */
end_comment

begin_decl_stmt
name|int
name|inhibit_formatting
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if INDENT OFF is in effect */
end_comment

begin_decl_stmt
name|int
name|suppress_blanklines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set iff following blanklines should be 				   suppressed */
end_comment

begin_decl_stmt
name|int
name|continuation_indent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to the indentation between the edge of 				   code and continuation lines */
end_comment

begin_decl_stmt
name|int
name|lineup_to_parens
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if true, continued code within parens will 				   be lined up to the open paren */
end_comment

begin_decl_stmt
name|int
name|block_comment_max_col
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|parser_state
block|{
name|int
name|last_token
decl_stmt|;
name|int
name|p_stack
index|[
literal|50
index|]
decl_stmt|;
comment|/* this is the parsers stack */
name|int
name|il
index|[
literal|50
index|]
decl_stmt|;
comment|/* this stack stores indentation levels */
name|float
name|cstk
index|[
literal|50
index|]
decl_stmt|;
comment|/* used to store case stmt indentation 				 * levels */
name|int
name|box_com
decl_stmt|;
comment|/* set to true when we are in a "boxed" 				 * comment. In that case, the first 				 * non-blank char should be lined up with 				 * the / in /* */
name|int
name|comment_delta
decl_stmt|,
name|n_comment_delta
decl_stmt|;
name|int
name|cast_mask
decl_stmt|;
comment|/* indicates which close parens close off 				 * casts */
name|int
name|sizeof_mask
decl_stmt|;
comment|/* indicates which close parens close off 				   sizeof''s */
name|int
name|block_init
decl_stmt|;
comment|/* true iff inside a block initialization */
name|int
name|last_nl
decl_stmt|;
comment|/* this is true if the last thing scanned 				 * was a newline */
name|int
name|in_or_st
decl_stmt|;
comment|/* Will be true iff there has been a 				 * declarator (e.g. int or char) and no 				 * left paren since the last semicolon. 				 * When true, a '{' is starting a 				 * structure definition or an 				 * initialization list */
name|int
name|bl_line
decl_stmt|;
comment|/* set to 1 by dump_line if the line is 				 * blank */
name|int
name|col_1
decl_stmt|;
comment|/* set to true if the last token started 				 * in column 1 */
name|int
name|com_col
decl_stmt|;
comment|/* this is the column in which the current 				 * coment should start */
name|int
name|com_ind
decl_stmt|;
comment|/* the column in which comments to the 				 * right of code should start */
name|int
name|com_lines
decl_stmt|;
comment|/* the number of lines with comments, set 				 * by dump_line */
name|int
name|dec_nest
decl_stmt|;
comment|/* current nesting level for structure or 				 * init */
name|int
name|decl_com_ind
decl_stmt|;
comment|/* the column in which comments after 				 * declarations should be put */
name|int
name|decl_on_line
decl_stmt|;
comment|/* set to true if this line of code has 				 * part of a declaration on it */
name|int
name|i_l_follow
decl_stmt|;
comment|/* the level to which ind_level should be 				 * set after the current line is printed */
name|int
name|in_decl
decl_stmt|;
comment|/* set to true when we are in a 				 * declaration stmt.  The processing of 				 * braces is then slightly different */
name|int
name|in_stmt
decl_stmt|;
comment|/* set to 1 while in a stmt */
name|int
name|ind_level
decl_stmt|;
comment|/* the current indentation level */
name|int
name|ind_size
decl_stmt|;
comment|/* the size of one indentation level */
name|int
name|ind_stmt
decl_stmt|;
comment|/* set to 1 if next line should have an 				 * extra indentation level because we are 				 * in the middle of a stmt */
name|int
name|last_u_d
decl_stmt|;
comment|/* set to true after scanning a token 				 * which forces a following operator to be 				 * unary */
name|int
name|leave_comma
decl_stmt|;
comment|/* if true, never break declarations after 				 * commas */
name|int
name|ljust_decl
decl_stmt|;
comment|/* true if declarations should be left 				 * justified */
name|int
name|out_coms
decl_stmt|;
comment|/* the number of comments processed, set 				 * by pr_comment */
name|int
name|out_lines
decl_stmt|;
comment|/* the number of lines written, set by 				 * dump_line */
name|int
name|p_l_follow
decl_stmt|;
comment|/* used to remember how to indent 				 * following statement */
name|int
name|paren_level
decl_stmt|;
comment|/* parenthesization level. used to indent 				 * within stmts */
name|short
name|paren_indents
index|[
literal|20
index|]
decl_stmt|;
comment|/* column positions of each paren */
name|int
name|pcase
decl_stmt|;
comment|/* set to 1 if the current line label is a 				 * case.  It is printed differently from  				 * a regular label */
name|int
name|search_brace
decl_stmt|;
comment|/* set to true by parse when it is 				 * necessary to buffer up all info up to 				 * the start of a stmt after an if, while, 				 * etc */
name|int
name|unindent_displace
decl_stmt|;
comment|/* comments not to the right of 					 * code will be placed this many 					 * indentation levels to the left 					 * of code */
name|int
name|use_ff
decl_stmt|;
comment|/* set to one if the current line should 				 * be terminated with a form feed */
name|int
name|want_blank
decl_stmt|;
comment|/* set to true when the following token 				 * should be prefixed by a blank. (Said 				 * prefixing is ignored in some cases.) */
name|int
name|else_if
decl_stmt|;
comment|/* True iff else if pairs should be 				 * handled specially */
name|int
name|decl_indent
decl_stmt|;
comment|/* column to indent declared identifiers 				 * to */
name|int
name|its_a_keyword
decl_stmt|;
name|int
name|sizeof_keyword
decl_stmt|;
name|int
name|dumped_decl_indent
decl_stmt|;
name|float
name|case_indent
decl_stmt|;
comment|/* The distance to indent case labels from 				 * the switch statement */
name|int
name|in_parameter_declaration
decl_stmt|;
name|int
name|indent_parameters
decl_stmt|;
name|int
name|tos
decl_stmt|;
comment|/* pointer to top of stack */
name|char
name|procname
index|[
literal|100
index|]
decl_stmt|;
comment|/* The name of the current procedure */
name|int
name|just_saw_decl
decl_stmt|;
block|}
name|ps
struct|;
end_struct

begin_decl_stmt
name|int
name|ifdef_level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|parser_state
name|state_stack
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|parser_state
name|match_state
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

end_unit

