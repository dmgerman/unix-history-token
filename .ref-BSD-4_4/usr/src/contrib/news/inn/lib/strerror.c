begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.1 $ ** **  Only<errno.h> is needed; the others are just to get the right sprintf() **  declaration, sigh. */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"configdata.h"
end_include

begin_include
include|#
directive|include
file|"clibrary.h"
end_include

begin_comment
comment|/* **  Return a string representation of errno. */
end_comment

begin_function
name|char
modifier|*
name|strerror
parameter_list|(
name|e
parameter_list|)
name|int
name|e
decl_stmt|;
block|{
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
specifier|static
name|char
name|buff
index|[
literal|30
index|]
decl_stmt|;
if|if
condition|(
name|e
operator|>=
literal|0
operator|&&
name|e
operator|<
name|sys_nerr
condition|)
return|return
name|sys_errlist
index|[
name|e
index|]
return|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buff
argument_list|,
literal|"Error code %d\n"
argument_list|,
name|e
argument_list|)
expr_stmt|;
return|return
name|buff
return|;
block|}
end_function

end_unit

