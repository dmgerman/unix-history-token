begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* add.c   not copyrighted (n) 1993 by Mark Adler */
end_comment

begin_comment
comment|/* version 1.1   11 Jun 1993 */
end_comment

begin_comment
comment|/* This filter reverses the effect of the sub filter.  It requires no    arguments, since sub puts the information necessary for extraction    in the stream.  See sub.c for what the filtering is and what it's    good for. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|MAGIC1
value|'S'
end_define

begin_comment
comment|/* sub data */
end_comment

begin_define
define|#
directive|define
name|MAGIC2
value|26
end_define

begin_comment
comment|/* ^Z */
end_comment

begin_define
define|#
directive|define
name|MAX_DIST
value|16384
end_define

begin_decl_stmt
name|char
name|a
index|[
name|MAX_DIST
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last byte buffer for up to MAX_DIST differences */
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|n
decl_stmt|;
comment|/* number of differences */
name|int
name|i
decl_stmt|;
comment|/* difference counter */
name|int
name|c
decl_stmt|;
comment|/* byte from input */
comment|/* check magic word */
if|if
condition|(
name|getchar
argument_list|()
operator|!=
name|MAGIC1
operator|||
name|getchar
argument_list|()
operator|!=
name|MAGIC2
condition|)
block|{
name|fputs
argument_list|(
literal|"add: input stream not made by sub\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* get number of differences from data */
if|if
condition|(
operator|(
name|n
operator|=
name|getchar
argument_list|()
operator|)
operator|==
name|EOF
operator|||
operator|(
name|i
operator|=
name|getchar
argument_list|()
operator|)
operator|==
name|EOF
condition|)
block|{
name|fputs
argument_list|(
literal|"add: unexpected end of file\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|n
operator|+=
operator|(
name|i
operator|<<
literal|8
operator|)
expr_stmt|;
if|if
condition|(
name|n
operator|<=
literal|0
operator|||
name|n
operator|>
name|MAX_DIST
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"add: incorrect distance %d\n"
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* initialize last byte */
name|i
operator|=
name|n
expr_stmt|;
do|do
block|{
name|a
index|[
operator|--
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
do|while
condition|(
name|i
condition|)
do|;
comment|/* read differenced data and restore original */
while|while
condition|(
operator|(
name|c
operator|=
name|getchar
argument_list|()
operator|)
operator|!=
name|EOF
condition|)
block|{
name|c
operator|=
operator|(
name|a
index|[
name|i
operator|++
index|]
operator|+=
name|c
operator|)
operator|&
literal|0xff
expr_stmt|;
comment|/* restore data, save last byte */
name|putchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* write original */
if|if
condition|(
name|i
operator|==
name|n
condition|)
comment|/* cycle on n differences */
name|i
operator|=
literal|0
expr_stmt|;
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
comment|/* avoid warning */
block|}
end_function

end_unit

