begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This should be replaced by whatever namespace-clean    version of strerror you have available. */
end_comment

begin_include
include|#
directive|include
file|"libioP.h"
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strerror
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|_IO_strerror
parameter_list|(
name|errnum
parameter_list|)
name|int
name|errnum
decl_stmt|;
block|{
return|return
name|strerror
argument_list|(
name|errnum
argument_list|)
return|;
block|}
end_function

end_unit

