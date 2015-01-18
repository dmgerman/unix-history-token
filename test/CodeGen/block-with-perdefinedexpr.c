begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -fblocks -triple x86_64-apple-darwin10 | FileCheck %s
end_comment

begin_comment
comment|// rdar://18961148
end_comment

begin_function_decl
name|void
name|syslog
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|handler
parameter_list|( )
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|^
name|spd
function_decl|)
parameter_list|()
init|=
lambda|^
parameter_list|()
block|{
name|handler
argument_list|(
lambda|^
parameter_list|()
block|{
name|syslog
argument_list|(
literal|"%s"
argument_list|,
name|__FUNCTION__
argument_list|)
function_decl|;
end_function_decl

begin_empty_stmt
unit|} )
empty_stmt|;
end_empty_stmt

begin_comment
unit|};
comment|// CHECK: @__FUNCTION__.spd_block_invoke_2 = private unnamed_addr constant [19 x i8] c"spd_block_invoke_2\00"
end_comment

begin_comment
comment|// CHECK: define internal void @spd_block_invoke_2
end_comment

begin_comment
comment|// CHECK: @__FUNCTION__.spd_block_invoke_2
end_comment

end_unit

