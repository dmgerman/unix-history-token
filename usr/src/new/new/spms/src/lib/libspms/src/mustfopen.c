begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
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
name|fatal
argument_list|(
literal|"can't open %s"
argument_list|,
name|filename
argument_list|)
expr_stmt|;
return|return
operator|(
name|stream
operator|)
return|;
block|}
end_function

end_unit

