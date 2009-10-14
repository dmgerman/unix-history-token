begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -emit-llvm -o %t %s&&
end_comment

begin_comment
comment|// RUN: grep 'define signext i8 @f0(i32 %x) nounwind' %t&&
end_comment

begin_comment
comment|// RUN: grep 'define zeroext i8 @f1(i32 %x) nounwind' %t&&
end_comment

begin_comment
comment|// RUN: grep 'define void @f2(i8 signext %x) nounwind' %t&&
end_comment

begin_comment
comment|// RUN: grep 'define void @f3(i8 zeroext %x) nounwind' %t&&
end_comment

begin_comment
comment|// RUN: grep 'define signext i16 @f4(i32 %x) nounwind' %t&&
end_comment

begin_comment
comment|// RUN: grep 'define zeroext i16 @f5(i32 %x) nounwind' %t&&
end_comment

begin_comment
comment|// RUN: grep 'define void @f6(i16 signext %x) nounwind' %t&&
end_comment

begin_comment
comment|// RUN: grep 'define void @f7(i16 zeroext %x) nounwind' %t&&
end_comment

begin_function
name|signed
name|char
name|f0
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_function
name|unsigned
name|char
name|f1
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_function
name|void
name|f2
parameter_list|(
name|signed
name|char
name|x
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|f3
parameter_list|(
name|unsigned
name|char
name|x
parameter_list|)
block|{ }
end_function

begin_function
name|signed
name|short
name|f4
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_function
name|unsigned
name|short
name|f5
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_function
name|void
name|f6
parameter_list|(
name|signed
name|short
name|x
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|f7
parameter_list|(
name|unsigned
name|short
name|x
parameter_list|)
block|{ }
end_function

begin_comment
comment|// RUN: grep 'define void @f8() nounwind alwaysinline' %t&&
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|always_inline
operator|)
argument_list|)
name|f8
argument_list|(
name|void
argument_list|)
block|{ }
end_decl_stmt

begin_comment
comment|// RUN: grep 'call void @f9_t() noreturn' %t&&
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
name|f9_t
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f9
parameter_list|(
name|void
parameter_list|)
block|{
name|f9_t
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// FIXME: We should be setting nounwind on calls.
end_comment

begin_comment
comment|// RUN: grep 'call i32 @f10_t() readnone' %t&&
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
name|f10_t
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f10
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|f10_t
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|f11
parameter_list|(
name|void
parameter_list|)
block|{
name|exit
label|:
return|return
name|f10_t
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|f12
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
return|return
name|arg
condition|?
literal|0
else|:
name|f10_t
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// RUN: grep 'define void @f13() nounwind readnone' %t&&
end_comment

begin_function_decl
name|void
name|f13
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(pure
end_function_decl

begin_expr_stmt
unit|))
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|f13
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// Ensure that these get inlined: rdar://6853279
end_comment

begin_comment
comment|// RUN: not grep '@ai_' %t&&
end_comment

begin_decl_stmt
specifier|static
name|__inline__
name|__attribute__
argument_list|(
operator|(
name|always_inline
operator|)
argument_list|)
name|int
name|ai_1
argument_list|()
block|{
return|return
literal|4
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|__attribute__
argument_list|(
operator|(
name|always_inline
operator|)
argument_list|)
decl|struct
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|,
name|e
decl_stmt|;
block|}
end_decl_stmt

begin_macro
name|ai_2
argument_list|()
end_macro

begin_block
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_block

begin_function
name|int
name|foo
parameter_list|()
block|{
name|ai_2
argument_list|()
expr_stmt|;
return|return
name|ai_1
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// RUN: true
end_comment

end_unit

