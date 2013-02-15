begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Just a replacement, if the original isascii is not    present */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<ldns/config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|isascii
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* true if character is ascii. */
end_comment

begin_function
name|int
name|isascii
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|c
operator|>=
literal|0
operator|&&
name|c
operator|<
literal|128
return|;
block|}
end_function

end_unit

