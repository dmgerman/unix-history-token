begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)ARGV.c 1.1 %G%"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_include
include|#
directive|include
file|"h01errs.h"
end_include

begin_macro
name|ARGV
argument_list|(
argument|subscript
argument_list|,
argument|var
argument_list|,
argument|size
argument_list|)
end_macro

begin_decl_stmt
name|int
name|subscript
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* subscript into argv */
end_comment

begin_decl_stmt
specifier|register
name|char
modifier|*
name|var
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to pascal char array */
end_comment

begin_decl_stmt
specifier|register
name|int
name|size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sizeof(var) */
end_comment

begin_block
block|{
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
if|if
condition|(
name|subscript
operator|>=
name|_argc
condition|)
block|{
name|ERROR
argument_list|(
name|EARGV
argument_list|,
name|subscript
argument_list|)
expr_stmt|;
return|return;
block|}
name|cp
operator|=
name|_argv
index|[
name|subscript
index|]
expr_stmt|;
do|do
block|{
operator|*
name|var
operator|++
operator|=
operator|*
name|cp
operator|++
expr_stmt|;
block|}
do|while
condition|(
operator|--
name|size
operator|&&
operator|*
name|cp
condition|)
do|;
while|while
condition|(
name|size
operator|--
condition|)
operator|*
name|var
operator|++
operator|=
literal|' '
expr_stmt|;
block|}
end_block

end_unit

