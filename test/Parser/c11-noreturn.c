begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c11 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -std=c99 -pedantic -fsyntax-only %s 2>&1 | FileCheck -check-prefix=CHECK-EXT %s
end_comment

begin_function_decl
specifier|_Noreturn
name|int
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
specifier|_Noreturn
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{previous}}
end_comment

begin_function_decl
name|int
name|f
function_decl|_Noreturn();
end_function_decl

begin_comment
comment|// expected-error {{expected ';'}} expected-error 2{{}}
end_comment

begin_expr_stmt
name|int
name|f
argument_list|()
specifier|_Noreturn
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{'_Noreturn' keyword must precede function declarator}}
end_comment

begin_decl_stmt
specifier|_Noreturn
name|char
name|c1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'_Noreturn' can only appear on functions}}
end_comment

begin_decl_stmt
name|char
specifier|_Noreturn
name|c2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'_Noreturn' can only appear on functions}}
end_comment

begin_typedef
typedef|typedef
specifier|_Noreturn
name|int
name|g
parameter_list|()
function_decl|;
end_typedef

begin_comment
comment|// expected-error {{'_Noreturn' can only appear on functions}}
end_comment

begin_expr_stmt
specifier|_Noreturn
name|int
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{'_Noreturn' can only appear on functions}} expected-warning {{does not declare anything}}
end_comment

begin_struct_decl
specifier|_Noreturn
struct_decl|struct
name|S
struct_decl|;
end_struct_decl

begin_comment
comment|// expected-error {{'_Noreturn' can only appear on functions}}
end_comment

begin_enum
specifier|_Noreturn
enum|enum
name|E
block|{
name|e
block|}
enum|;
end_enum

begin_comment
comment|// expected-error {{'_Noreturn' can only appear on functions}}
end_comment

begin_comment
comment|// CHECK-EXT: _Noreturn functions are a C11-specific feature
end_comment

end_unit

