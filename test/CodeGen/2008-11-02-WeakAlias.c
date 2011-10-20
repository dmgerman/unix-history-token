begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=i686-pc-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// PR2691
end_comment

begin_comment
comment|// CHECK: weak
end_comment

begin_function_decl
name|void
name|init_IRQ
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak
operator|,
function_decl|alias
parameter_list|(
function_decl|"native_init_IRQ"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|native_init_IRQ
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

end_unit

