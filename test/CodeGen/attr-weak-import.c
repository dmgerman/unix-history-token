begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-darwin-apple -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// rdar://9538608
end_comment

begin_decl_stmt
specifier|extern
name|int
name|A
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|A
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|B
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|B
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|C
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|C
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|D
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|D
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|D
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|E
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|E
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|E
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @A = global i32
end_comment

begin_comment
comment|// CHECK-NOT: @B =
end_comment

begin_comment
comment|// CHECK: @C = common global i32
end_comment

begin_comment
comment|// CHECK: @D = global i32
end_comment

begin_comment
comment|// CHECK: @E = global i32
end_comment

end_unit

