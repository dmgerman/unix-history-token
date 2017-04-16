begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -fms-extensions -emit-llvm< %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @a1 = global i32 1, align 1
end_comment

begin_decl_stmt
name|__unaligned
name|int
name|a1
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @a2 = global i32 1, align 1
end_comment

begin_decl_stmt
name|int
name|__unaligned
name|a2
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @a3 = {{.*}} align 1
end_comment

begin_decl_stmt
name|__unaligned
name|int
name|a3
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @a4 = {{.*}} align 1
end_comment

begin_decl_stmt
name|int
name|__unaligned
name|a4
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @p1 = {{.*}} align 1
end_comment

begin_decl_stmt
name|int
modifier|*
name|__unaligned
name|p1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @p2 = {{.*}} align 8
end_comment

begin_decl_stmt
name|int
name|__unaligned
modifier|*
name|p2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @p3 = {{.*}} align 1
end_comment

begin_decl_stmt
name|int
name|__unaligned
modifier|*
name|__unaligned
name|p3
decl_stmt|;
end_decl_stmt

end_unit

