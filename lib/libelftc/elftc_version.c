begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<libelftc.h>
end_include

begin_function
specifier|const
name|char
modifier|*
name|elftc_version
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|"elftoolchain r3520M"
return|;
block|}
end_function

end_unit

