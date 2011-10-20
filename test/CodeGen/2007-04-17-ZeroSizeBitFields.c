begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// PR 1332
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o /dev/null
end_comment

begin_struct
struct|struct
name|Z
block|{
name|int
name|a
range|:
literal|1
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|int
name|c
range|:
literal|1
decl_stmt|;
block|}
name|z
struct|;
end_struct

end_unit

