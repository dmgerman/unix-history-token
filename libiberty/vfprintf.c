begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Provide a version vfprintf in terms of _doprnt.    By Kaveh Ghazi  (ghazi@caip.rutgers.edu)  3/29/98    Copyright (C) 1998 Free Software Foundation, Inc.  */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_undef
undef|#
directive|undef
name|vfprintf
end_undef

begin_function
name|int
name|vfprintf
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|ap
parameter_list|)
block|{
return|return
name|_doprnt
argument_list|(
name|format
argument_list|,
name|ap
argument_list|,
name|stream
argument_list|)
return|;
block|}
end_function

end_unit

