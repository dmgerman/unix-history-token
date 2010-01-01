begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_struct
struct|struct
name|frk
block|{
name|float
specifier|_Complex
name|c
decl_stmt|;
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|faz
block|{
name|struct
name|frk
name|f
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuz
block|{
name|struct
name|faz
name|f
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|struct
name|fuz
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|X
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|frk
name|F
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
specifier|_Complex
name|C
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: define void @bar
end_comment

begin_function
name|void
name|bar
parameter_list|(
name|void
parameter_list|)
block|{
name|X
operator|=
name|foo
argument_list|()
operator|.
name|f
operator|.
name|f
operator|.
name|x
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: define void @bun
end_comment

begin_function
name|void
name|bun
parameter_list|(
name|void
parameter_list|)
block|{
name|F
operator|=
name|foo
argument_list|()
operator|.
name|f
operator|.
name|f
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: define void @ban
end_comment

begin_function
name|void
name|ban
parameter_list|(
name|void
parameter_list|)
block|{
name|C
operator|=
name|foo
argument_list|()
operator|.
name|f
operator|.
name|f
operator|.
name|c
expr_stmt|;
block|}
end_function

end_unit

