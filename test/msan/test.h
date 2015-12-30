begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|__LP64__
end_if

begin_define
define|#
directive|define
name|SANITIZER_WORDSIZE
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_WORDSIZE
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// This is a simplified version of GetMaxVirtualAddress function.
end_comment

begin_function
name|unsigned
name|long
name|SystemVMA
parameter_list|()
block|{
if|#
directive|if
name|SANITIZER_WORDSIZE
operator|==
literal|64
name|unsigned
name|long
name|vma
init|=
operator|(
name|unsigned
name|long
operator|)
name|__builtin_frame_address
argument_list|(
literal|0
argument_list|)
decl_stmt|;
return|return
name|SANITIZER_WORDSIZE
operator|-
name|__builtin_clzll
argument_list|(
name|vma
argument_list|)
return|;
else|#
directive|else
return|return
name|SANITIZER_WORDSIZE
return|;
endif|#
directive|endif
block|}
end_function

end_unit

