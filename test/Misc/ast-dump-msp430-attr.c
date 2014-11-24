begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple msp430-unknown-unknown -ast-dump -ast-dump-filter Test %s | FileCheck --strict-whitespace %s
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|12
argument|))
argument_list|)
end_macro

begin_function_decl
name|void
name|Test
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: FunctionDecl{{.*}}Test
end_comment

begin_comment
comment|// CHECK-NEXT: MSP430InterruptAttr
end_comment

end_unit

