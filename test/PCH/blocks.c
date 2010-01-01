begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fblocks -include %S/blocks.h -fsyntax-only -emit-llvm -o - %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -fblocks -o %t %S/blocks.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fblocks -include-pch %t -fsyntax-only -emit-llvm -o - %s
end_comment

begin_function
name|int
name|do_add
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
return|return
name|add
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|do_scaled_add
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|s
parameter_list|)
block|{
return|return
name|scaled_add
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|s
argument_list|)
return|;
block|}
end_function

end_unit

