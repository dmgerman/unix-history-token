begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -triple x86_64-unknown-unknown -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -triple arm64-unknown-unknown -verify
end_comment

begin_typedef
typedef|typedef
name|void
name|typedef_fun_t
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|preserve_most
operator|)
argument_list|)
name|foo
argument_list|(
name|void
operator|*
name|ptr
argument_list|)
block|{ }
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|preserve_most
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
name|foo1
argument_list|(
name|void
operator|*
name|ptr
argument_list|)
block|{
comment|// expected-error {{'preserve_most' attribute takes no arguments}}
block|}
end_decl_stmt

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|preserve_most
operator|)
argument_list|)
operator|*
name|pfoo1
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|=
name|foo
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|cdecl
operator|)
argument_list|)
operator|*
name|pfoo2
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|=
name|foo
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{incompatible pointer types initializing 'void (*)(void *) __attribute__((cdecl))' with an expression of type 'void (void *) __attribute__((preserve_most))'}}
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|pfoo3
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
init|=
name|foo
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{incompatible pointer types initializing 'void (*)(void *)' with an expression of type 'void (void *) __attribute__((preserve_most))'}}
end_comment

begin_decl_stmt
name|typedef_fun_t
name|typedef_fun_foo
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous declaration is here}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|preserve_most
operator|)
argument_list|)
name|typedef_fun_foo
argument_list|(
name|int
name|x
argument_list|)
block|{ }
end_decl_stmt

begin_comment
comment|// expected-error {{function declared 'preserve_most' here was previously declared without calling convention}}
end_comment

begin_struct
struct|struct
name|type_test_foo
block|{}
name|__attribute__
argument_list|(
operator|(
name|preserve_most
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|// expected-warning {{'preserve_most' attribute only applies to functions and methods}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|preserve_all
operator|)
argument_list|)
name|boo
argument_list|(
name|void
operator|*
name|ptr
argument_list|)
block|{ }
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|preserve_all
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
name|boo1
argument_list|(
name|void
operator|*
name|ptr
argument_list|)
block|{
comment|// expected-error {{'preserve_all' attribute takes no arguments}}
block|}
end_decl_stmt

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|preserve_all
operator|)
argument_list|)
operator|*
name|pboo1
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|=
name|boo
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|cdecl
operator|)
argument_list|)
operator|*
name|pboo2
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|=
name|boo
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{incompatible pointer types initializing 'void (*)(void *) __attribute__((cdecl))' with an expression of type 'void (void *) __attribute__((preserve_all))'}}
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|pboo3
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
init|=
name|boo
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{incompatible pointer types initializing 'void (*)(void *)' with an expression of type 'void (void *) __attribute__((preserve_all))'}}
end_comment

begin_decl_stmt
name|typedef_fun_t
name|typedef_fun_boo
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous declaration is here}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|preserve_all
operator|)
argument_list|)
name|typedef_fun_boo
argument_list|(
name|int
name|x
argument_list|)
block|{ }
end_decl_stmt

begin_comment
comment|// expected-error {{function declared 'preserve_all' here was previously declared without calling convention}}
end_comment

begin_struct
struct|struct
name|type_test_boo
block|{}
name|__attribute__
argument_list|(
operator|(
name|preserve_all
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|// expected-warning {{'preserve_all' attribute only applies to functions and methods}}
end_comment

end_unit

