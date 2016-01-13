begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir %t
end_comment

begin_comment
comment|// RUN: echo 'struct a;'> %t/a.h
end_comment

begin_comment
comment|// RUN: echo 'struct b {}; void foo(struct b*);'> %t/b.h
end_comment

begin_comment
comment|// RUN: echo 'module X { module a { header "a.h" } module b { header "b.h" } }'> %t/x.modulemap
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fmodules-cache-path=%t -fmodule-map-file=%t/x.modulemap %s -I%t -verify
end_comment

begin_include
include|#
directive|include
file|"a.h"
end_include

begin_function_decl
name|void
name|f
parameter_list|(
name|struct
name|a
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// FIXME: We should warn that 'b' will not be visible outside of this function,
end_comment

begin_comment
comment|// but we merge this 'b' with X.b's 'b' because we don't yet implement C's
end_comment

begin_comment
comment|// "compatible types" rule.
end_comment

begin_function_decl
name|void
name|g
parameter_list|(
name|struct
name|b
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|b
name|b
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{definition of 'b' must be imported from module 'X.b' before it is required}}
end_comment

begin_comment
comment|// expected-note@b.h:1 {{here}}
end_comment

end_unit

