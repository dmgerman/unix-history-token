begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -emit-llvm %s -o -
end_comment

begin_comment
comment|// PR4214
end_comment

begin_typedef
typedef|typedef
name|void
name|vt
typedef|;
end_typedef

begin_function_decl
name|void
function_decl|(
modifier|*
name|func_ptr
function_decl|)
parameter_list|(
name|vt
name|my_vt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {argument may not have 'void' type}
end_comment

end_unit

