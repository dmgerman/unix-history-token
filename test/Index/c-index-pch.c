begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-pch -x c -o %t.pch %S/Inputs/c-index-pch.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t.pch -x c -emit-pch -o %t.ast %s
end_comment

begin_comment
comment|// RUN: c-index-test -test-load-tu %t.ast all | FileCheck -check-prefix=ALL %s
end_comment

begin_comment
comment|// RUN: c-index-test -test-load-tu %t.ast local | FileCheck -check-prefix=LOCAL %s
end_comment

begin_comment
comment|// ALL: FunctionDecl=foo
end_comment

begin_comment
comment|// ALL: VarDecl=bar
end_comment

begin_comment
comment|// ALL: FunctionDecl=wibble
end_comment

begin_comment
comment|// ALL: FunctionDecl=wonka
end_comment

begin_comment
comment|// LOCAL-NOT: FunctionDecl=foo
end_comment

begin_comment
comment|// LOCAL-NOT: VarDecl=bar
end_comment

begin_comment
comment|// LOCAL: FunctionDecl=wibble
end_comment

begin_comment
comment|// LOCAL: FunctionDecl=wonka
end_comment

begin_function_decl
name|void
name|wibble
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wonka
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

end_unit

