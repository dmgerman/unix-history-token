begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include %S/line-directive.h -fsyntax-only %s 2>&1|grep "25:5"
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t %S/line-directive.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t -fsyntax-only %s 2>&1|grep "25:5"
end_comment

begin_decl_stmt
name|double
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redefinition of 'x' with a different type}}
end_comment

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

end_unit

