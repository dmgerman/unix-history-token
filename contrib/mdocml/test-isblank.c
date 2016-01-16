begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|!
name|isblank
argument_list|(
literal|' '
argument_list|)
operator|||
operator|!
name|isblank
argument_list|(
literal|'\t'
argument_list|)
operator|||
name|isblank
argument_list|(
literal|'_'
argument_list|)
return|;
block|}
end_function

end_unit

