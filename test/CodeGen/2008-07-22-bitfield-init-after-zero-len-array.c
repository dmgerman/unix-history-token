begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=i686-apple-darwin9 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_struct
struct|struct
name|et7
block|{
name|float
name|lv7
index|[
literal|0
index|]
decl_stmt|;
name|char
name|mv7
range|:
literal|6
decl_stmt|;
block|}
name|yv7
init|=
block|{
block|{}
block|,
literal|52
block|,  }
struct|;
end_struct

begin_comment
comment|// CHECK: @yv7 = global
end_comment

begin_comment
comment|// CHECK: i8 52,
end_comment

end_unit

