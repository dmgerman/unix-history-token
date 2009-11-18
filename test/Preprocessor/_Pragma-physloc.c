begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -E | grep '#pragma x y z'
end_comment

begin_comment
comment|// RUN: clang-cc %s -E | grep '#pragma a b c'
end_comment

begin_macro
name|_Pragma
argument_list|(
literal|"x y z"
argument_list|)
end_macro

begin_macro
name|_Pragma
argument_list|(
literal|"a b c"
argument_list|)
end_macro

end_unit

