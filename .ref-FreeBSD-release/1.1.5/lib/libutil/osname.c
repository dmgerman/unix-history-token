begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file is in the public domain.  * Written by Garrett A. Wollman<wollman@freefall.cdrom.com>.  *  * $Id$  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_comment
comment|/*  * _osname - return the name of the current operating system.  */
end_comment

begin_function
name|char
modifier|*
name|_osname
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|struct
name|utsname
name|uts
decl_stmt|;
if|if
condition|(
name|uname
argument_list|(
operator|&
name|uts
argument_list|)
condition|)
return|return
literal|"unknown"
return|;
else|else
return|return
name|uts
operator|.
name|sysname
return|;
block|}
end_function

begin_comment
comment|/*  * _osnamever - return the name and version of the current operating system.  */
end_comment

begin_function
name|char
modifier|*
name|_osnamever
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|struct
name|utsname
name|uts
decl_stmt|;
specifier|static
name|char
name|name
index|[
literal|2
operator|*
name|SYS_NMLN
operator|+
literal|1
index|]
decl_stmt|;
if|if
condition|(
name|uname
argument_list|(
operator|&
name|uts
argument_list|)
condition|)
block|{
return|return
literal|"unknown"
return|;
block|}
else|else
block|{
name|strcpy
argument_list|(
name|name
argument_list|,
name|uts
operator|.
name|sysname
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|name
argument_list|,
literal|" "
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|name
argument_list|,
name|uts
operator|.
name|release
argument_list|)
expr_stmt|;
return|return
name|name
return|;
block|}
block|}
end_function

end_unit

