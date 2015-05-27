begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple s390x-linux-gnu -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// SystemZ prefers to align all global variables to two bytes.
end_comment

begin_struct
struct|struct
name|test
block|{
name|signed
name|char
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DAG: @c = common global i8 0, align 2
end_comment

begin_decl_stmt
name|struct
name|test
name|s
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DAG: @s = common global %struct.test zeroinitializer, align 2
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ec
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DAG: @ec = external global i8, align 2
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|test
name|es
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DAG: @es = external global %struct.test, align 2
end_comment

begin_comment
comment|// Dummy function to make sure external symbols are used.
end_comment

begin_function
name|void
name|func
parameter_list|(
name|void
parameter_list|)
block|{
name|c
operator|=
name|ec
expr_stmt|;
name|s
operator|=
name|es
expr_stmt|;
block|}
end_function

end_unit

