begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	help.c		Larn is copyrighted 1986 by Noah Morgan. */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|"header.h"
end_include

begin_comment
comment|/*  *	help function to display the help info  *  *	format of the .larn.help file  *  *	1st character of file:	# of pages of help available (ascii digit)  *	page (23 lines) for the introductory message (not counted in above)  *	pages of help text (23 lines per page)  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|helpfile
index|[]
decl_stmt|;
end_decl_stmt

begin_macro
name|help
argument_list|()
end_macro

begin_block
block|{
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
ifndef|#
directive|ifndef
name|VT100
name|char
name|tmbuf
index|[
literal|128
index|]
decl_stmt|;
comment|/* intermediate translation buffer when not a VT100 */
endif|#
directive|endif
comment|/* VT100 */
if|if
condition|(
operator|(
name|j
operator|=
name|openhelp
argument_list|()
operator|)
operator|<
literal|0
condition|)
return|return;
comment|/* open the help file and get # pages */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|23
condition|;
name|i
operator|++
control|)
name|lgetl
argument_list|()
expr_stmt|;
comment|/* skip over intro message */
for|for
control|(
init|;
name|j
operator|>
literal|0
condition|;
name|j
operator|--
control|)
block|{
name|clear
argument_list|()
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|23
condition|;
name|i
operator|++
control|)
ifdef|#
directive|ifdef
name|VT100
name|lprcat
argument_list|(
name|lgetl
argument_list|()
argument_list|)
expr_stmt|;
comment|/* print out each line that we read in */
else|#
directive|else
comment|/* VT100 */
block|{
name|tmcapcnv
argument_list|(
name|tmbuf
argument_list|,
name|lgetl
argument_list|()
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
name|tmbuf
argument_list|)
expr_stmt|;
block|}
comment|/* intercept \33's */
endif|#
directive|endif
comment|/* VT100 */
if|if
condition|(
name|j
operator|>
literal|1
condition|)
block|{
name|lprcat
argument_list|(
literal|"    ---- Press "
argument_list|)
expr_stmt|;
name|standout
argument_list|(
literal|"return"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|" to exit, "
argument_list|)
expr_stmt|;
name|standout
argument_list|(
literal|"space"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|" for more help ---- "
argument_list|)
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|i
operator|!=
literal|' '
operator|)
operator|&&
operator|(
name|i
operator|!=
literal|'\n'
operator|)
operator|&&
operator|(
name|i
operator|!=
literal|'\33'
operator|)
condition|)
name|i
operator|=
name|getchar
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|i
operator|==
literal|'\n'
operator|)
operator|||
operator|(
name|i
operator|==
literal|'\33'
operator|)
condition|)
block|{
name|lrclose
argument_list|()
expr_stmt|;
name|setscroll
argument_list|()
expr_stmt|;
name|drawscreen
argument_list|()
expr_stmt|;
return|return;
block|}
block|}
block|}
name|lrclose
argument_list|()
expr_stmt|;
name|retcont
argument_list|()
expr_stmt|;
name|drawscreen
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  *	function to display the welcome message and background  */
end_comment

begin_macro
name|welcome
argument_list|()
end_macro

begin_block
block|{
name|int
name|i
decl_stmt|;
ifndef|#
directive|ifndef
name|VT100
name|char
name|tmbuf
index|[
literal|128
index|]
decl_stmt|;
comment|/* intermediate translation buffer when not a VT100 */
endif|#
directive|endif
comment|/* VT100 */
if|if
condition|(
name|openhelp
argument_list|()
operator|<
literal|0
condition|)
return|return;
comment|/* open the help file */
name|clear
argument_list|()
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|23
condition|;
name|i
operator|++
control|)
ifdef|#
directive|ifdef
name|VT100
name|lprcat
argument_list|(
name|lgetl
argument_list|()
argument_list|)
expr_stmt|;
comment|/* print out each line that we read in */
else|#
directive|else
comment|/* VT100 */
block|{
name|tmcapcnv
argument_list|(
name|tmbuf
argument_list|,
name|lgetl
argument_list|()
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
name|tmbuf
argument_list|)
expr_stmt|;
block|}
comment|/* intercept \33's */
endif|#
directive|endif
comment|/* VT100 */
name|lrclose
argument_list|()
expr_stmt|;
name|retcont
argument_list|()
expr_stmt|;
comment|/* press return to continue */
block|}
end_block

begin_comment
comment|/*  *	function to say press return to continue and reset scroll when done  */
end_comment

begin_macro
name|retcont
argument_list|()
end_macro

begin_block
block|{
name|cursor
argument_list|(
literal|1
argument_list|,
literal|24
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|"Press "
argument_list|)
expr_stmt|;
name|standout
argument_list|(
literal|"return"
argument_list|)
expr_stmt|;
name|lprcat
argument_list|(
literal|" to continue: "
argument_list|)
expr_stmt|;
while|while
condition|(
name|getchar
argument_list|()
operator|!=
literal|'\n'
condition|)
empty_stmt|;
name|setscroll
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  *	routine to open the help file and return the first character - '0'  */
end_comment

begin_macro
name|openhelp
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|lopen
argument_list|(
name|helpfile
argument_list|)
operator|<
literal|0
condition|)
block|{
name|lprintf
argument_list|(
literal|"Can't open help file \"%s\" "
argument_list|,
name|helpfile
argument_list|)
expr_stmt|;
name|lflush
argument_list|()
expr_stmt|;
name|sleep
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|drawscreen
argument_list|()
expr_stmt|;
name|setscroll
argument_list|()
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|resetscroll
argument_list|()
expr_stmt|;
return|return
operator|(
name|lgetc
argument_list|()
operator|-
literal|'0'
operator|)
return|;
block|}
end_block

end_unit

