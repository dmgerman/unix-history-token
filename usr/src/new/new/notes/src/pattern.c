begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)pattern.c	1.1\t1/23/83"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"parms.h"
end_include

begin_include
include|#
directive|include
file|"structs.h"
end_include

begin_comment
comment|/*  *	dopat - matches notesfile names and calls the desired routine with  *	each matched arguement!  *  *	Ray Essick			Feb 25, 1982  */
end_comment

begin_function_decl
name|FILE
modifier|*
name|popen
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* declare the function! */
end_comment

begin_macro
name|dopat
argument_list|(
argument|p
argument_list|,
argument|what
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the pattern to match */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|what
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routine to be called */
end_comment

begin_block
block|{
name|char
name|cmd
index|[
name|CMDLEN
index|]
decl_stmt|;
name|int
name|c
decl_stmt|,
name|i
decl_stmt|;
name|FILE
modifier|*
name|zfile
decl_stmt|;
name|sprintf
argument_list|(
name|cmd
argument_list|,
literal|"(cd %s;echo %s)"
argument_list|,
name|MSTDIR
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|zfile
operator|=
name|popen
argument_list|(
name|cmd
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
comment|/* read what it has to say */
do|do
block|{
name|i
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|zfile
argument_list|)
operator|)
operator|!=
literal|' '
operator|&&
operator|(
name|c
operator|!=
literal|'\n'
operator|)
operator|&&
operator|(
name|c
operator|!=
name|EOF
operator|)
condition|)
block|{
name|cmd
index|[
name|i
operator|++
index|]
operator|=
name|c
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|==
literal|0
condition|)
block|{
break|break;
block|}
name|cmd
index|[
name|i
operator|++
index|]
operator|=
literal|'\0'
expr_stmt|;
name|i
operator|=
call|(
modifier|*
name|what
call|)
argument_list|(
name|cmd
argument_list|)
expr_stmt|;
comment|/* call his routine for him */
block|}
do|while
condition|(
operator|(
name|c
operator|!=
name|EOF
operator|)
operator|&&
operator|(
name|i
operator|!=
name|QUITFAST
operator|)
operator|&&
operator|(
name|i
operator|!=
name|QUITUPD
operator|)
condition|)
do|;
name|pclose
argument_list|(
name|zfile
argument_list|)
expr_stmt|;
comment|/* close that file! */
return|return
operator|(
name|i
operator|)
return|;
comment|/* return the return code */
block|}
end_block

end_unit

