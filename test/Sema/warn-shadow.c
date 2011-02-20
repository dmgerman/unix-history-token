begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fsyntax-only -fblocks -Wshadow %s
end_comment

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note 3 {{previous declaration is here}}
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
name|pass1
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|// expected-warning {{declaration shadows a variable in the global scope}} \
comment|// expected-note {{previous declaration is here}}
block|{
name|int
name|pass2
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|// expected-warning {{declaration shadows a local variable}} \
comment|// expected-note {{previous declaration is here}}
block|{
name|int
name|pass3
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|// expected-warning {{declaration shadows a local variable}}
block|}
block|}
name|int
name|sin
decl_stmt|;
comment|// okay; 'sin' has not been declared, even though it's a builtin.
block|}
end_function

begin_comment
comment|//<rdar://problem/7677531>
end_comment

begin_function_decl
name|void
function_decl|(
modifier|^
name|test1
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
lambda|^
parameter_list|(
name|int
name|i
parameter_list|)
block|{
comment|// expected-warning {{declaration shadows a variable in the global scope}} \
comment|// expected-note{{previous declaration is here}}
block|{
name|int
name|i
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{declaration shadows a local variable}} \
end_comment

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_expr_stmt
operator|(
lambda|^
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|i
return|;
block|}
operator|)
operator|(
name|i
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//expected-warning {{declaration shadows a local variable}}
end_comment

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|test2
block|{
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|test3
parameter_list|(
name|void
parameter_list|)
block|{
struct|struct
name|test4
block|{
name|int
name|i
decl_stmt|;
block|}
struct|;
block|}
end_function

begin_function
name|void
name|test4
parameter_list|(
name|int
name|i
parameter_list|)
block|{
comment|// expected-warning {{declaration shadows a variable in the global scope}}
block|}
end_function

begin_comment
comment|// Don't warn about shadowing for function declarations.
end_comment

begin_function_decl
name|void
name|test5
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test6
parameter_list|(
name|void
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|int
name|i
parameter_list|)
parameter_list|)
block|{}
end_function

begin_function
name|void
name|test7
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
parameter_list|)
block|{}
end_function

begin_decl_stmt
specifier|extern
name|int
name|bob
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous declaration is here}}
end_comment

begin_comment
comment|// rdar://8883302
end_comment

begin_function
name|void
name|rdar8883302
parameter_list|()
block|{
specifier|extern
name|int
name|bob
decl_stmt|;
comment|// don't warn for shadowing.
block|}
end_function

begin_function
name|void
name|test8
parameter_list|()
block|{
name|int
name|bob
decl_stmt|;
comment|// expected-warning {{declaration shadows a variable in the global scope}}
block|}
end_function

end_unit

