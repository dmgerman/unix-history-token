begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include %S/builtins.h -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t %S/builtins.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|hello
parameter_list|()
block|{
name|printf
argument_list|(
literal|"Hello, World!"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

