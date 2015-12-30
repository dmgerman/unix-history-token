begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -write-pch %t.pch -x c %S/Inputs/c-index-pch.h
end_comment

begin_comment
comment|// RUN: c-index-test -write-pch %t.ast -Xclang -include-pch -Xclang %t.pch -x c %s
end_comment

begin_comment
comment|// RUN: c-index-test -test-load-tu %t.ast all | FileCheck -check-prefix=ALL %s
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

