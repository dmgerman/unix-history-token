begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -S -debug-info-kind=standalone -emit-llvm -o - %s -finstrument-functions | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @test1
end_comment

begin_function
name|int
name|test1
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// CHECK: call void @__cyg_profile_func_enter({{.*}}, !dbg
comment|// CHECK: call void @__cyg_profile_func_exit({{.*}}, !dbg
comment|// CHECK: ret
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test2
end_comment

begin_function_decl
name|int
name|test2
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(no_instrument_function
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|test2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// CHECK-NOT: __cyg_profile_func_enter
comment|// CHECK-NOT: __cyg_profile_func_exit
comment|// CHECK: ret
return|return
name|x
return|;
block|}
end_function

end_unit

