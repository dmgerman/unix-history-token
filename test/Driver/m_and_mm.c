begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### \
end_comment

begin_comment
comment|// RUN:   -M -MM %s 2> %t
end_comment

begin_comment
comment|// RUN: not grep '"-sys-header-deps"' %t
end_comment

begin_comment
comment|// RUN: %clang -M -MM %s 2> %t
end_comment

begin_comment
comment|// RUN: not grep "warning" %t
end_comment

begin_comment
comment|// RUN: %clang -MMD -MD %s 2> %t || true
end_comment

begin_comment
comment|// RUN: grep "warning" %t
end_comment

begin_warning
warning|#
directive|warning
literal|"This warning shouldn't show up with -M and -MM"
end_warning

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

