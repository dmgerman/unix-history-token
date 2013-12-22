begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -fdiagnostics-parseable-fixits -x c++ %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// expected-note@+1 2{{previous definition is here}}
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// expected-error@+2 {{static declaration of 'main' follows non-static declaration}}
end_comment

begin_comment
comment|// expected-warning@+1 {{'main' should not be declared static}}
end_comment

begin_function
specifier|static
name|int
name|main
parameter_list|()
block|{
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:1-[[@LINE-1]]:8}:""
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// expected-error@+2 {{redefinition of 'main'}}
end_comment

begin_comment
comment|// expected-error@+1 {{'main' is not allowed to be declared inline}}
end_comment

begin_function
specifier|inline
name|int
name|main
parameter_list|()
block|{
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:1-[[@LINE-1]]:8}:""
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// expected-warning@+5 {{function 'main' declared 'noreturn' should not return}}
end_comment

begin_comment
comment|// expected-warning@+2 {{'main' is not allowed to be declared _Noreturn}}
end_comment

begin_comment
comment|// expected-note@+1 {{remove '_Noreturn'}}
end_comment

begin_function
specifier|_Noreturn
name|int
name|main
parameter_list|()
block|{
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:1-[[@LINE-1]]:11}:""
return|return
literal|0
return|;
block|}
end_function

end_unit

