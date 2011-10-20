begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_struct
struct|struct
name|U
block|{
name|char
name|a
decl_stmt|;
name|short
name|b
decl_stmt|;
name|int
name|c
range|:
literal|25
decl_stmt|;
name|char
name|d
decl_stmt|;
block|}
name|u
struct|;
end_struct

end_unit

