begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|progname
decl_stmt|;
name|progname
operator|=
name|getprogname
argument_list|()
expr_stmt|;
return|return
name|progname
operator|==
name|NULL
return|;
block|}
end_function

end_unit

