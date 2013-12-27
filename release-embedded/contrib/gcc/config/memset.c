begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Public domain.  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_function
name|void
modifier|*
name|memset
parameter_list|(
name|void
modifier|*
name|dest
parameter_list|,
name|int
name|val
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
name|unsigned
name|char
modifier|*
name|ptr
init|=
name|dest
decl_stmt|;
while|while
condition|(
name|len
operator|--
operator|>
literal|0
condition|)
operator|*
name|ptr
operator|++
operator|=
name|val
expr_stmt|;
return|return
name|dest
return|;
block|}
end_function

end_unit

