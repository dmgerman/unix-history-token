begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Werror -triple thumbv7-windows-itanium -mfloat-abi hard -emit-llvm %s -o - | FileCheck %s
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|export_int
decl_stmt|;
end_decl_stmt

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|import_int
decl_stmt|;
end_decl_stmt

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function_decl
name|void
name|export_declared_function
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function
name|void
name|export_implemented_function
parameter_list|()
block|{ }
end_function

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|void
name|import_function
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|call_imported_function
parameter_list|()
block|{
name|export_declared_function
argument_list|()
expr_stmt|;
return|return
name|import_function
argument_list|(
name|import_int
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: @import_int = external dllimport global i32
end_comment

begin_comment
comment|// CHECK: @export_int = common dllexport global i32 0, align 4
end_comment

begin_comment
comment|// CHECK: define dllexport arm_aapcs_vfpcc void @export_implemented_function()
end_comment

begin_comment
comment|// CHECK: declare dllimport arm_aapcs_vfpcc void @import_function(i32)
end_comment

end_unit

