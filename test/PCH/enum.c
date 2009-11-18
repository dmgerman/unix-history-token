begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: clang-cc -include %S/enum.h -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: clang-cc -emit-pch -o %t %S/enum.h
end_comment

begin_comment
comment|// RUN: clang-cc -include-pch %t -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|int
name|i
init|=
name|Red
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|return_enum_constant
parameter_list|()
block|{
name|int
name|result
init|=
name|aRoundShape
decl_stmt|;
return|return
name|result
return|;
block|}
end_function

begin_decl_stmt
name|enum
name|Shape
name|s
init|=
name|Triangle
decl_stmt|;
end_decl_stmt

end_unit

