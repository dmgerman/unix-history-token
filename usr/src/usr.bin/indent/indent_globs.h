begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)indent_globs.h	4.1	(Berkeley)	%G%	*/
end_comment

begin_comment
comment|/*  			  Copyright (C) 1976 				by the 			  Board of Trustees 				of the 			University of Illinois  			 All rights reserved  FILE NAME: 	indent_globs.h  PURPOSE: 	This include file contains the declarations for all global variables 	used in indent.  GLOBALS: 	The names of all of the variables will not be repeated here.  The  	declarations start on the next page.  FUNCTIONS: 	None */
end_comment

begin_escape
end_escape

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
value|512
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
name|d_ljust
value|0
end_define

begin_comment
comment|/* default for ljust_decl */
end_comment

begin_define
define|#
directive|define
name|d_max_col
value|75
end_define

begin_comment
comment|/* default for max_col */
end_comment

begin_define
define|#
directive|define
name|d_com_ind
value|33
end_define

begin_comment
comment|/* default com_ind */
end_comment

begin_define
define|#
directive|define
name|d_ind_size
value|4
end_define

begin_comment
comment|/* default ind_size */
end_comment

begin_define
define|#
directive|define
name|d_verbose
value|0
end_define

begin_comment
comment|/* default verbose */
end_comment

begin_define
define|#
directive|define
name|d_unindent
value|1
end_define

begin_comment
comment|/* default value for unindent_displace */
end_comment

begin_define
define|#
directive|define
name|d_leave_comma
value|0
end_define

begin_comment
comment|/* default value for leave_comma */
end_comment

begin_define
define|#
directive|define
name|d_btype_2
value|1
end_define

begin_comment
comment|/* default value for btype_2 */
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
name|int
name|input
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the fid for the input file */
end_comment

begin_decl_stmt
name|int
name|output
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the fid for the output file */
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
name|bl_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 by dump_line if the line is blank */
end_comment

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
name|int
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
name|col_1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to true if the last token started in column 1 */
end_comment

begin_decl_stmt
name|int
name|com_col
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this is the column in which the current coment 		      should start */
end_comment

begin_decl_stmt
name|int
name|com_ind
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the column in which comments to the right of code 		      should start */
end_comment

begin_decl_stmt
name|int
name|com_lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the number of lines with comments, set by dump_line  		   */
end_comment

begin_decl_stmt
name|int
name|dec_nest
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current nesting level for structure or init */
end_comment

begin_decl_stmt
name|int
name|decl_com_ind
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the column in which comments after declarations 		      should be put */
end_comment

begin_decl_stmt
name|int
name|decl_on_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to true if this line of code has part of a 		      declaration on it */
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
name|i_l_follow
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the level to which ind_level should be set after the 		      current line is printed */
end_comment

begin_decl_stmt
name|int
name|in_decl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to true when we are in a declaration stmt.  The 		      processing of braces is then slightly different */
end_comment

begin_decl_stmt
name|int
name|in_stmt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 while in a stmt */
end_comment

begin_decl_stmt
name|int
name|ind_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the current indentation level */
end_comment

begin_decl_stmt
name|int
name|ind_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the size of one indentation level */
end_comment

begin_decl_stmt
name|int
name|ind_stmt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 if next line should have an extra 		      indentation level because we are in the middle of a 		      stmt */
end_comment

begin_decl_stmt
name|int
name|last_u_d
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to true after scanning a token which forces a 		      following operator to be unary */
end_comment

begin_decl_stmt
name|int
name|leave_comma
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if true, never break declarations after commas */
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
name|ljust_decl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if declarations should be left justified */
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
name|out_coms
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the number of comments processed, set by pr_comment  		   */
end_comment

begin_decl_stmt
name|int
name|out_lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the number of lines written, set by dump_line */
end_comment

begin_decl_stmt
name|int
name|p_l_follow
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to remember how to indent following statement  		   */
end_comment

begin_decl_stmt
name|int
name|paren_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* parenthesization level. used to indent within stmts  		   */
end_comment

begin_decl_stmt
name|int
name|pcase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 if the current line label is a case.  It is 		      printed differently from  a regular label */
end_comment

begin_decl_stmt
name|int
name|search_brace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to true by parse when it is necessary to buffer 		      up all info up to the start of a stmt after an if, 		      while, etc */
end_comment

begin_decl_stmt
name|int
name|unindent_displace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* comments not to the right of code will be placed 		      this many indentation levels to the left of code */
end_comment

begin_decl_stmt
name|int
name|use_ff
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to one if the current line should be terminated 		      with a form feed */
end_comment

begin_decl_stmt
name|int
name|verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when true, non-essential error messages are printed  		   */
end_comment

end_unit

