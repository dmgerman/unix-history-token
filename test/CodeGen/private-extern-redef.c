begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-darwin-apple -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// rdar://9609649
end_comment

begin_decl_stmt
name|__private_extern__
specifier|const
name|int
name|I
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__private_extern__
specifier|const
name|int
name|J
init|=
literal|927
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__private_extern__
specifier|const
name|int
name|K
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|K
init|=
literal|37
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|L
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__private_extern__
specifier|const
name|int
name|L
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__private_extern__
name|int
name|M
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|M
init|=
literal|20
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__private_extern__
name|int
name|N
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|N
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__private_extern__
name|int
name|O
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|O
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__private_extern__
name|int
name|P
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|P
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|bar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|()
block|{
name|bar
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @J = hidden constant
end_comment

begin_comment
comment|// CHECK: @K = hidden constant
end_comment

begin_comment
comment|// CHECK: @L = constant
end_comment

begin_comment
comment|// CHECK: @M = hidden global
end_comment

begin_comment
comment|// CHECK: @O = hidden global
end_comment

begin_comment
comment|// CHECK: @I = external hidden
end_comment

begin_comment
comment|// CHECK: @N = common hidden global
end_comment

begin_comment
comment|// CHECK-NOT: @P
end_comment

end_unit

