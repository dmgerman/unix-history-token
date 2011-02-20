begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -fblocks -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// pr8707
end_comment

begin_comment
comment|// CHECK: @__block_global_0.test = internal global i32
end_comment

begin_function_decl
name|int
function_decl|(
modifier|^
name|block
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
specifier|static
name|int
name|test
operator|=
literal|0
function_decl|;
end_function_decl

begin_return
return|return
name|test
return|;
end_return

begin_comment
unit|};
comment|// CHECK: @__block_global_1.test = internal global i32
end_comment

begin_function_decl
name|void
function_decl|(
modifier|^
name|block1
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
specifier|static
name|int
name|test
operator|=
literal|2
function_decl|;
end_function_decl

begin_return
return|return;
end_return

begin_comment
unit|};
comment|// CHECK: @__block_global_2.test = internal global i32
end_comment

begin_function_decl
name|int
function_decl|(
modifier|^
name|block2
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
specifier|static
name|int
name|test
operator|=
literal|5
function_decl|;
end_function_decl

begin_return
return|return
name|test
return|;
end_return

unit|};
end_unit

