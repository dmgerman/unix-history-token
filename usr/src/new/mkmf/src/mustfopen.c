begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: mustfopen.c,v 1.2 85/03/17 12:51:04 nicklin Exp $ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * mustfopen() opens a file in the manner of fopen(3). However, if the file  * cannot be accessed, exit(1) is called.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|PGN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program name */
end_comment

begin_function
name|FILE
modifier|*
name|mustfopen
parameter_list|(
name|filename
parameter_list|,
name|mode
parameter_list|)
name|char
modifier|*
name|filename
decl_stmt|;
name|char
modifier|*
name|mode
decl_stmt|;
block|{
name|FILE
modifier|*
name|stream
decl_stmt|;
comment|/* file stream */
if|if
condition|(
operator|(
name|stream
operator|=
name|fopen
argument_list|(
name|filename
argument_list|,
name|mode
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
operator|*
name|PGN
operator|!=
literal|'\0'
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|PGN
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"can't open %s\n"
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|stream
operator|)
return|;
block|}
end_function

end_unit

