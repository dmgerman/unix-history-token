begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_pragma
pragma|#
directive|pragma
name|weak
name|vfork
name|=
name|_vfork
end_pragma

begin_function
name|int
name|_vfork
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|fork
argument_list|()
operator|)
return|;
block|}
end_function

end_unit

