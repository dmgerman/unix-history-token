begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o -  %s -fpascal-strings -fshort-wchar  | FileCheck %s
end_comment

begin_comment
comment|// rdar://8020384
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_function_decl
specifier|extern
name|void
name|abort
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|unsigned
name|short
name|UInt16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UInt16
name|UniChar
typedef|;
end_typedef

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|char
name|st
index|[]
init|=
literal|"\pfoo"
decl_stmt|;
comment|// pascal string
name|UniChar
name|wt
index|[]
init|=
literal|L"\pbar"
decl_stmt|;
comment|// pascal Unicode string
name|UniChar
name|wt1
index|[]
init|=
literal|L"\p"
decl_stmt|;
name|UniChar
name|wt2
index|[]
init|=
literal|L"\pgorf"
decl_stmt|;
if|if
condition|(
name|st
index|[
literal|0
index|]
operator|!=
literal|3
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|wt
index|[
literal|0
index|]
operator|!=
literal|3
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|wt1
index|[
literal|0
index|]
operator|!=
literal|0
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|wt2
index|[
literal|0
index|]
operator|!=
literal|4
condition|)
name|abort
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: c"\03\00b\00a\00r\00\00\00"
end_comment

begin_comment
comment|// CHECK: c"\04\00g\00o\00r\00f\00\00\00"
end_comment

begin_comment
comment|// PR8856 - -fshort-wchar makes wchar_t be unsigned.
end_comment

begin_comment
comment|// CHECK: @test2
end_comment

begin_comment
comment|// CHECK: volatile store i32 1, i32* %isUnsigned
end_comment

begin_function
name|void
name|test2
parameter_list|()
block|{
specifier|volatile
name|int
name|isUnsigned
init|=
operator|(
name|wchar_t
operator|)
operator|-
literal|1
operator|>
operator|(
name|wchar_t
operator|)
literal|0
decl_stmt|;
block|}
end_function

end_unit

