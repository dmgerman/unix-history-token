begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_include
include|#
directive|include
file|<ansidecl.h>
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
name|file
parameter_list|,
name|format
parameter_list|,
name|ap
parameter_list|)
name|FILE
modifier|*
name|file
decl_stmt|;
specifier|const
name|char
modifier|*
name|format
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
block|{
return|return
name|_doprnt
argument_list|(
name|format
argument_list|,
name|ap
argument_list|,
name|file
argument_list|)
return|;
block|}
end_function

end_unit

