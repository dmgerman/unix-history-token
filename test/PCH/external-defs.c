begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin9 -emit-pch -o %t.pch %S/external-defs.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin9 -include-pch %t.pch -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep "@x = common global i32 0" %t | count 1
end_comment

begin_comment
comment|// RUN: grep "@z" %t | count 0
end_comment

begin_comment
comment|// RUN: grep "@x2 = global i32 19" %t | count 1
end_comment

begin_decl_stmt
name|int
name|x2
init|=
literal|19
decl_stmt|;
end_decl_stmt

begin_comment
comment|// RUN: grep "@incomplete_array = common global .*1 x i32" %t | count 1
end_comment

begin_comment
comment|// RUN: grep "@incomplete_array2 = common global .*17 x i32" %t | count 1
end_comment

begin_decl_stmt
name|int
name|incomplete_array2
index|[
literal|17
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// RUN: grep "@incomplete_array3 = common global .*1 x i32" %t | count 1
end_comment

begin_decl_stmt
name|int
name|incomplete_array3
index|[]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|S
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
struct|;
end_struct

end_unit

