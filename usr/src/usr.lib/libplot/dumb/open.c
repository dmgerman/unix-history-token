begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)open.c	5.1 (Berkeley) 5/7/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * This accepts plot file formats and produces the appropriate plots  * for dumb terminals.  It can also be used for printing terminals and  * lineprinter listings, although there is no way to specify number of  * lines and columns different from your terminal.  This would be easy  * to change, and is left as an exercise for the reader.  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"dumb.h"
end_include

begin_decl_stmt
name|int
name|minX
decl_stmt|,
name|rangeX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* min and range of x */
end_comment

begin_decl_stmt
name|int
name|minY
decl_stmt|,
name|rangeY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* min and range of y */
end_comment

begin_decl_stmt
name|int
name|currentx
decl_stmt|,
name|currenty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|COLS
decl_stmt|,
name|LINES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A very large screen! (probably should use malloc) */
end_comment

begin_decl_stmt
name|char
name|screenmat
index|[
name|MAXCOLS
index|]
index|[
name|MAXLINES
index|]
decl_stmt|;
end_decl_stmt

begin_macro
name|openpl
argument_list|()
end_macro

begin_block
block|{
name|int
name|closepl
parameter_list|()
function_decl|;
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
name|char
modifier|*
name|term
decl_stmt|,
modifier|*
name|getenv
argument_list|()
decl_stmt|;
name|char
name|bp
index|[
literal|1024
index|]
decl_stmt|;
name|term
operator|=
name|getenv
argument_list|(
literal|"TERM"
argument_list|)
expr_stmt|;
name|tgetent
argument_list|(
name|bp
argument_list|,
name|term
argument_list|)
expr_stmt|;
name|COLS
operator|=
name|tgetnum
argument_list|(
literal|"co"
argument_list|)
expr_stmt|;
if|if
condition|(
name|COLS
operator|>
name|MAXCOLS
condition|)
name|COLS
operator|=
name|MAXCOLS
expr_stmt|;
if|if
condition|(
name|COLS
operator|<
literal|0
condition|)
name|COLS
operator|=
literal|48
expr_stmt|;
comment|/* lower bound on # of cols? */
name|COLS
operator|--
expr_stmt|;
comment|/* prevent auto wrap */
name|LINES
operator|=
name|tgetnum
argument_list|(
literal|"li"
argument_list|)
expr_stmt|;
if|if
condition|(
name|LINES
operator|>
name|MAXLINES
condition|)
name|LINES
operator|=
name|MAXLINES
expr_stmt|;
if|if
condition|(
name|LINES
operator|<
literal|0
condition|)
name|LINES
operator|=
literal|20
expr_stmt|;
comment|/* lower bound on # of lines? */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|COLS
condition|;
name|i
operator|++
control|)
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|LINES
condition|;
name|j
operator|++
control|)
name|screenmat
index|[
name|i
index|]
index|[
name|j
index|]
operator|=
literal|' '
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|closepl
argument_list|)
expr_stmt|;
name|currentx
operator|=
name|currenty
operator|=
literal|0
expr_stmt|;
block|}
end_block

end_unit

