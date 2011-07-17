begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=gnu89 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>=
literal|199901
end_if

begin_define
define|#
directive|define
name|GNU_INLINE
value|__attribute((__gnu_inline__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GNU_INLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PR5253
end_comment

begin_comment
comment|// rdar://9559708 (same extension in C99 mode)
end_comment

begin_comment
comment|// GNU Extension: check that we can redefine an extern inline function
end_comment

begin_function
name|GNU_INLINE
specifier|extern
specifier|inline
name|int
name|f
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|a
return|;
block|}
end_function

begin_function
name|int
name|f
parameter_list|(
name|int
name|b
parameter_list|)
block|{
return|return
name|b
return|;
block|}
end_function

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

begin_comment
comment|// And now check that we can't redefine a normal function
end_comment

begin_function
name|int
name|f
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|c
return|;
block|}
end_function

begin_comment
comment|// expected-error{{redefinition of 'f'}}
end_comment

begin_comment
comment|// Check that we can redefine an extern inline function as a static function
end_comment

begin_function
name|GNU_INLINE
specifier|extern
specifier|inline
name|int
name|g
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|a
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|g
parameter_list|(
name|int
name|b
parameter_list|)
block|{
return|return
name|b
return|;
block|}
end_function

begin_comment
comment|// Check that we ensure the types of the two definitions are the same
end_comment

begin_function
name|GNU_INLINE
specifier|extern
specifier|inline
name|int
name|h
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|a
return|;
block|}
end_function

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

begin_function
name|int
name|h
parameter_list|(
name|short
name|b
parameter_list|)
block|{
return|return
name|b
return|;
block|}
end_function

begin_comment
comment|// expected-error{{conflicting types for 'h'}}
end_comment

end_unit

