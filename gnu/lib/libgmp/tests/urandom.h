begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|__alpha__
argument_list|)
end_if

begin_comment
comment|/* HPUX lacks random().  DEC Alpha's random() returns a double.  */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|urandom
parameter_list|()
block|{
return|return
name|mrand48
argument_list|()
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function_decl
name|long
name|random
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|urandom
parameter_list|()
block|{
comment|/* random() returns 31 bits, we want 32.  */
return|return
name|random
argument_list|()
operator|^
operator|(
name|random
argument_list|()
operator|<<
literal|1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

