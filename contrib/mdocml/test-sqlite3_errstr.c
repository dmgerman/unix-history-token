begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sqlite3.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|strcmp
argument_list|(
name|sqlite3_errstr
argument_list|(
name|SQLITE_OK
argument_list|)
argument_list|,
literal|"not an error"
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

