begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.1 $ ** */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_comment
comment|/* **  Open a file in append mode.  Since not all fopen's set the O_APPEND **  flag, we do it by hand. */
end_comment

begin_function
name|FILE
modifier|*
name|xfopena
parameter_list|(
name|p
parameter_list|)
name|char
modifier|*
name|p
decl_stmt|;
block|{
name|int
name|fd
decl_stmt|;
comment|/* We can't trust stdio to really use O_APPEND, so open, then fdopen. */
name|fd
operator|=
name|open
argument_list|(
name|p
argument_list|,
name|O_WRONLY
operator||
name|O_APPEND
operator||
name|O_CREAT
argument_list|,
literal|0666
argument_list|)
expr_stmt|;
return|return
name|fd
operator|>=
literal|0
condition|?
name|fdopen
argument_list|(
name|fd
argument_list|,
literal|"a"
argument_list|)
else|:
name|NULL
return|;
block|}
end_function

end_unit

