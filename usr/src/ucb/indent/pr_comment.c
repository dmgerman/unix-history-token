begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)pr_comment.c	4.1	(Berkeley)	10/21/82"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  			  Copyright (C) 1976 				by the 			  Board of Trustees 				of the 			University of Illinois  			 All rights reserved   NAME: 	pr_comment  FUNCTION: 	This routine takes care of scanning and printing comments.  ALGORITHM: 	1) Decide where the comment should be aligned, and if lines should 	   be broken. 	2) If lines should not be broken and filled, just copy up to end of 	   comment. 	3) If lines should be filled, then scan thru input_buffer copying 	   characters to com_buf.  Remember where the last blank, tab, or 	   newline was.  When line is filled, print up to last blank and  	   continue copying.  PARAMETERS: 	None  RETURNS: 	Nothing  GLOBALS: 	combuf = 	s_com 	e_com =  	buf_ptr = 	buf_end  	bl_line 	col_1 	com_col = 	com_ind 	decl_com_ind 	decl_on_line 	had_eof 	ind_level 	ind_size 	line_no = 	max_col 	out_com =	Count number of comments 	unindent_displace 	use_ff =  CALLS: 	count_spaces 	dump_line 	fill_buffer 	printf		(lib)  CALLED BY: 	main  HISTORY: 	November 1976	D A Willcox of CAC	Initial coding 	12/6/76		D A Willcox of CAC	Modification to handle  						UNIX-style comments  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* this routine processes comments.  It makes an attempt to keep comments from    going over the max line length.  If a line is too long, it moves everything    from the last blank to the next comment line.  Blanks and tabs from the    beginning of the input line are removed */
end_comment

begin_include
include|#
directive|include
file|"indent_globs.h"
include|;
end_include

begin_macro
name|pr_comment
argument_list|()
end_macro

begin_block
block|{
name|int
name|now_col
decl_stmt|;
comment|/* column we are in now */
name|int
name|box_com
decl_stmt|;
comment|/* set to true when we are in a "boxed" comment. In that case, the first     non-blank char should be lined up with the / in /* */
name|int
name|col_1_com
decl_stmt|;
comment|/* this comment should not be touched */
name|char
modifier|*
name|last_bl
decl_stmt|;
comment|/* points to the last blank in the output buffer */
name|char
name|achar
decl_stmt|;
name|char
modifier|*
name|t_ptr
decl_stmt|;
comment|/* used for movinf string */
name|int
name|unix_comment
decl_stmt|;
comment|/* tri-state variable used to decide if it is a unix-style comment. 0 means     only blanks since /*, 1 means regular style comment, 2 means unix style     comment */
name|last_bl
operator|=
literal|0
expr_stmt|;
comment|/* no blanks found so far */
name|box_com
operator|=
name|col_1_com
operator|=
name|false
expr_stmt|;
comment|/* at first, assume that we are not in a boxed comment or some other comment     that should not be touched */
operator|++
name|out_coms
expr_stmt|;
comment|/* keep track of number of comments */
name|unix_comment
operator|=
literal|0
expr_stmt|;
comment|/* set flag to let us figure out if there is a 			          unix-style comment */
comment|/*----------------------------------------------------------*\  |   Figure where to align and how to treat the comment \*----------------------------------------------------------*/
if|if
condition|(
name|col_1
condition|)
block|{
comment|/* if comment starts in column 1 it should not 			          be touched */
name|col_1_com
operator|=
name|box_com
operator|=
name|true
expr_stmt|;
name|com_col
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|*
name|buf_ptr
operator|==
literal|'-'
condition|)
name|box_com
operator|=
name|true
expr_stmt|;
comment|/* a comment with a '-' immediately after the /* 			          is assumed to be a boxed comment */
if|if
condition|(
comment|/* bl_line&& */
operator|(
name|s_lab
operator|==
name|e_lab
operator|)
operator|&&
operator|(
name|s_code
operator|==
name|e_code
operator|)
condition|)
block|{
comment|/* klg: check only if this line is blank */
comment|/*  	 * If this (*and previous lines are*) blank, 	 * don't put comment way out at left 	 */
name|com_col
operator|=
operator|(
name|ind_level
operator|-
name|unindent_displace
operator|)
operator|*
name|ind_size
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|com_col
operator|<=
literal|1
condition|)
name|com_col
operator|=
literal|2
expr_stmt|;
block|}
else|else
block|{
name|com_col
operator|=
operator|(
name|decl_on_line
operator|||
name|ind_level
operator|==
literal|0
condition|?
name|decl_com_ind
else|:
name|com_ind
operator|)
expr_stmt|;
block|}
block|}
operator|*
name|e_com
operator|++
operator|=
literal|'/'
expr_stmt|;
comment|/* put '/*' into buffer */
operator|*
name|e_com
operator|++
operator|=
literal|'*'
expr_stmt|;
if|if
condition|(
operator|*
name|buf_ptr
operator|!=
literal|' '
operator|&&
operator|!
name|box_com
condition|)
operator|*
name|e_com
operator|++
operator|=
literal|' '
expr_stmt|;
operator|*
name|e_com
operator|=
literal|'\0'
expr_stmt|;
name|now_col
operator|=
name|count_spaces
argument_list|(
name|com_col
argument_list|,
name|s_com
argument_list|)
expr_stmt|;
comment|/* figure where what column we would be in if we printed the comment now */
comment|/*----------------------------------------------------------*\  |    Start to copy the comment \*----------------------------------------------------------*/
while|while
condition|(
literal|1
condition|)
block|{
comment|/* this loop will go until the comment is copied  			       */
switch|switch
condition|(
operator|*
name|buf_ptr
condition|)
block|{
comment|/* this checks for various spcl cases */
case|case
literal|014
case|:
comment|/* check for a form feed */
if|if
condition|(
operator|!
name|box_com
condition|)
block|{
comment|/* in a text comment, break the line here */
name|use_ff
operator|=
name|true
expr_stmt|;
comment|/* fix so dump_line uses a form feed */
name|dump_line
argument_list|()
expr_stmt|;
name|last_bl
operator|=
literal|0
expr_stmt|;
operator|*
name|e_com
operator|++
operator|=
literal|' '
expr_stmt|;
operator|*
name|e_com
operator|++
operator|=
literal|' '
expr_stmt|;
operator|*
name|e_com
operator|++
operator|=
literal|' '
expr_stmt|;
do|do
block|{
comment|/* get rid of leading blanks */
if|if
condition|(
operator|++
name|buf_ptr
operator|>=
name|buf_end
condition|)
name|fill_buffer
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
operator|*
name|buf_ptr
operator|==
literal|' '
operator|||
operator|*
name|buf_ptr
operator|==
literal|'\t'
condition|)
do|;
block|}
else|else
block|{
if|if
condition|(
operator|++
name|buf_ptr
operator|>=
name|buf_end
condition|)
name|fill_buffer
argument_list|()
expr_stmt|;
operator|*
name|e_com
operator|++
operator|=
literal|014
expr_stmt|;
block|}
break|break;
case|case
literal|'\n'
case|:
if|if
condition|(
name|had_eof
condition|)
block|{
comment|/* check for unexpected eof */
name|printf
argument_list|(
literal|"Unterminated comment\n"
argument_list|)
expr_stmt|;
operator|*
name|e_com
operator|=
literal|'\0'
expr_stmt|;
name|dump_line
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|box_com
condition|)
block|{
comment|/* if this is a boxed comment, we don't ignore 			          the newline */
operator|*
name|e_com
operator|=
literal|'\0'
expr_stmt|;
name|dump_line
argument_list|()
expr_stmt|;
operator|++
name|line_no
expr_stmt|;
name|now_col
operator|=
name|com_col
expr_stmt|;
if|if
condition|(
operator|!
name|col_1_com
condition|)
block|{
comment|/* if merely a boxed comment, we should line up first 		       non-blank character */
do|do
block|{
comment|/* flush leading non-blanks */
if|if
condition|(
operator|++
name|buf_ptr
operator|>=
name|buf_end
condition|)
name|fill_buffer
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
operator|*
name|buf_ptr
operator|==
literal|' '
operator|||
operator|*
name|buf_ptr
operator|==
literal|'\t'
condition|)
do|;
block|}
else|else
block|{
comment|/* make sure we at least flush the blank */
if|if
condition|(
operator|++
name|buf_ptr
operator|>=
name|buf_end
condition|)
name|fill_buffer
argument_list|()
expr_stmt|;
block|}
break|break;
block|}
if|if
condition|(
name|unix_comment
operator|!=
literal|1
condition|)
block|{
comment|/* we are in unix_style comment */
if|if
condition|(
name|unix_comment
operator|==
literal|0
operator|&&
name|s_code
operator|==
name|e_code
condition|)
block|{
comment|/* if it is a UNIX-style comment, ignore the requirement 		       that pervious line be blank for unindention */
name|com_col
operator|=
operator|(
name|ind_level
operator|-
name|unindent_displace
operator|)
operator|*
name|ind_size
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|com_col
operator|<=
literal|1
condition|)
name|com_col
operator|=
literal|2
expr_stmt|;
block|}
name|unix_comment
operator|=
literal|2
expr_stmt|;
comment|/* permanently remember that we are in this type of comment */
name|dump_line
argument_list|()
expr_stmt|;
operator|++
name|line_no
expr_stmt|;
name|now_col
operator|=
name|com_col
expr_stmt|;
operator|*
name|e_com
operator|++
operator|=
literal|' '
expr_stmt|;
comment|/* fix so that the star at the start of the line will line up  		*/
do|do
comment|/* flush leading white space */
if|if
condition|(
operator|++
name|buf_ptr
operator|>=
name|buf_end
condition|)
name|fill_buffer
argument_list|()
expr_stmt|;
do|while
condition|(
operator|*
name|buf_ptr
operator|==
literal|' '
operator|||
operator|*
name|buf_ptr
operator|==
literal|'\t'
condition|)
do|;
break|break;
block|}
if|if
condition|(
operator|*
operator|(
name|e_com
operator|-
literal|1
operator|)
operator|==
literal|' '
operator|||
operator|*
operator|(
name|e_com
operator|-
literal|1
operator|)
operator|==
literal|'\t'
condition|)
name|last_bl
operator|=
name|e_com
operator|-
literal|1
expr_stmt|;
comment|/* if there was a space at the end of the last line, remember where 	       it was */
else|else
block|{
comment|/* otherwise, insert one */
name|last_bl
operator|=
name|e_com
expr_stmt|;
operator|*
name|e_com
operator|++
operator|=
literal|' '
expr_stmt|;
operator|++
name|now_col
expr_stmt|;
block|}
operator|++
name|line_no
expr_stmt|;
comment|/* keep track of input line number */
do|do
block|{
comment|/* copy any blanks and/or tabs at start of next 			          line */
if|if
condition|(
operator|++
name|buf_ptr
operator|>=
name|buf_end
condition|)
name|fill_buffer
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
operator|*
name|buf_ptr
operator|==
literal|' '
operator|||
operator|*
name|buf_ptr
operator|==
literal|'\t'
condition|)
do|;
break|break;
comment|/* end of case for newline */
case|case
literal|'*'
case|:
comment|/* must check for possibility of being at end of 			          comment */
if|if
condition|(
operator|++
name|buf_ptr
operator|>=
name|buf_end
condition|)
comment|/* get to next char after * */
name|fill_buffer
argument_list|()
expr_stmt|;
if|if
condition|(
name|unix_comment
operator|==
literal|0
condition|)
comment|/* set flag to show we are not in unix-style 			          comment */
name|unix_comment
operator|=
literal|1
expr_stmt|;
if|if
condition|(
operator|*
name|buf_ptr
operator|==
literal|'/'
condition|)
block|{
comment|/* it is the end!!! */
if|if
condition|(
operator|++
name|buf_ptr
operator|>=
name|buf_end
condition|)
name|fill_buffer
argument_list|()
expr_stmt|;
if|if
condition|(
operator|*
operator|(
name|e_com
operator|-
literal|1
operator|)
operator|!=
literal|' '
operator|&&
operator|!
name|box_com
condition|)
block|{
comment|/* insure blank before end */
operator|*
name|e_com
operator|++
operator|=
literal|' '
expr_stmt|;
operator|++
name|now_col
expr_stmt|;
block|}
if|if
condition|(
name|now_col
operator|>
name|max_col
operator|-
literal|2
operator|&&
operator|!
name|box_com
condition|)
block|{
comment|/* check if star-slash will go over line */
operator|*
name|e_com
operator|=
literal|'\0'
expr_stmt|;
comment|/* it will */
name|dump_line
argument_list|()
expr_stmt|;
name|now_col
operator|=
name|com_col
expr_stmt|;
block|}
operator|*
name|e_com
operator|++
operator|=
literal|'*'
expr_stmt|;
comment|/* move end of comment */
operator|*
name|e_com
operator|++
operator|=
literal|'/'
expr_stmt|;
operator|*
name|e_com
operator|=
literal|'\0'
expr_stmt|;
return|return;
comment|/* we is done */
block|}
comment|/* end of end of comment */
else|else
block|{
comment|/* handle isolated '*' */
operator|*
name|e_com
operator|++
operator|=
literal|'*'
expr_stmt|;
operator|++
name|now_col
expr_stmt|;
break|break;
block|}
comment|/* end of processing of * */
default|default:
comment|/* we have a random char */
if|if
condition|(
name|unix_comment
operator|==
literal|0
operator|&&
operator|*
name|buf_ptr
operator|!=
literal|' '
operator|&&
operator|*
name|buf_ptr
operator|!=
literal|'\t'
condition|)
name|unix_comment
operator|=
literal|1
expr_stmt|;
comment|/* we are not in unix-style comment */
operator|*
name|e_com
operator|=
operator|*
name|buf_ptr
operator|++
expr_stmt|;
if|if
condition|(
name|buf_ptr
operator|>=
name|buf_end
condition|)
name|fill_buffer
argument_list|()
expr_stmt|;
if|if
condition|(
operator|*
name|e_com
operator|==
literal|'\t'
condition|)
comment|/* keep track of column */
name|now_col
operator|=
operator|(
operator|(
name|now_col
operator|-
literal|1
operator|)
operator|&
name|tabmask
operator|)
operator|+
name|tabsize
operator|+
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
operator|*
name|e_com
operator|==
literal|'
literal|'
condition|)
comment|/* this is a backspace */
operator|--
name|now_col
expr_stmt|;
else|else
operator|++
name|now_col
expr_stmt|;
if|if
condition|(
operator|*
name|e_com
operator|==
literal|' '
operator|||
operator|*
name|e_com
operator|==
literal|'\t'
condition|)
name|last_bl
operator|=
name|e_com
expr_stmt|;
comment|/* remember we saw a blank */
operator|++
name|e_com
expr_stmt|;
if|if
condition|(
name|now_col
operator|>
name|max_col
operator|&&
operator|!
name|box_com
operator|&&
name|unix_comment
operator|==
literal|1
condition|)
block|{
comment|/* the comment is too long, it must be broken up */
if|if
condition|(
name|last_bl
operator|==
literal|0
condition|)
block|{
comment|/* we have seen no blanks */
name|printf
argument_list|(
literal|"%d: Comment too long\n"
argument_list|,
name|line_no
argument_list|)
expr_stmt|;
name|last_bl
operator|=
name|e_com
expr_stmt|;
comment|/* fake it */
operator|*
name|e_com
operator|++
operator|=
literal|' '
expr_stmt|;
block|}
operator|*
name|e_com
operator|=
literal|'\0'
expr_stmt|;
comment|/* print what we have */
operator|*
name|last_bl
operator|=
literal|'\0'
expr_stmt|;
name|e_com
operator|=
name|last_bl
expr_stmt|;
name|dump_line
argument_list|()
expr_stmt|;
operator|*
name|e_com
operator|++
operator|=
literal|' '
expr_stmt|;
comment|/* add blanks for continuation */
operator|*
name|e_com
operator|++
operator|=
literal|' '
expr_stmt|;
operator|*
name|e_com
operator|++
operator|=
literal|' '
expr_stmt|;
name|t_ptr
operator|=
name|last_bl
operator|+
literal|1
expr_stmt|;
name|last_bl
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|*
name|t_ptr
operator|!=
literal|'\0'
condition|)
block|{
comment|/* move unprinted pare of comment down in buffer */
if|if
condition|(
operator|*
name|t_ptr
operator|==
literal|' '
operator|||
operator|*
name|t_ptr
operator|==
literal|'\t'
condition|)
name|last_bl
operator|=
name|e_com
expr_stmt|;
operator|*
name|e_com
operator|++
operator|=
operator|*
name|t_ptr
operator|++
expr_stmt|;
block|}
operator|*
name|e_com
operator|=
literal|'\0'
expr_stmt|;
name|now_col
operator|=
name|count_spaces
argument_list|(
name|com_col
argument_list|,
name|s_com
argument_list|)
expr_stmt|;
comment|/* recompute current position */
block|}
comment|/* end of code for splitting a comment */
break|break;
comment|/* end of default case */
block|}
comment|/* end of switch */
block|}
comment|/* end of while (1) */
block|}
end_block

begin_comment
comment|/* end of pr_comment */
end_comment

end_unit

