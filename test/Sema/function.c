begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -pedantic
end_comment

begin_comment
comment|// PR1892
end_comment

begin_function_decl
name|void
name|f
parameter_list|(
name|double
name|a
index|[
specifier|restrict
index|]
index|[
literal|5
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// should promote to restrict ptr.
end_comment

begin_decl_stmt
name|void
name|f
argument_list|(
name|double
argument_list|(
operator|*
specifier|restrict
name|a
argument_list|)
index|[
literal|5
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|foo
parameter_list|(
name|__const
name|char
modifier|*
name|__path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|foo
parameter_list|(
name|__const
name|char
modifier|*
name|__restrict
name|__file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|func
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{previous declaration is here}}
end_comment

begin_function_decl
name|void
name|func
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{conflicting types for 'func'}}
end_comment

begin_function_decl
name|void
name|g
parameter_list|(
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|g
parameter_list|(
name|int
function_decl|(
modifier|*
name|compar
function_decl|)
parameter_list|()
parameter_list|)
block|{ }
end_function

begin_function_decl
name|void
name|h
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{previous declaration is here}}
end_comment

begin_function
name|void
name|h
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-error{{conflicting types for 'h'}}
end_comment

begin_comment
comment|// PR1965
end_comment

begin_function_decl
name|int
name|t5
parameter_list|(
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{parameter list without types}}
end_comment

begin_function_decl
name|int
name|t6
parameter_list|(
name|int
name|x
parameter_list|,
name|g
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{type specifier missing, defaults to 'int'}}
end_comment

begin_function_decl
name|int
name|t7
parameter_list|(
parameter_list|,
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{expected parameter declarator}} expected-error {{expected parameter declarator}}
end_comment

begin_function_decl
name|int
name|t8
parameter_list|(
parameter_list|,
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{expected parameter declarator}}
end_comment

begin_function_decl
name|int
name|t9
parameter_list|(
name|int
name|a
parameter_list|,
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{expected parameter declarator}}
end_comment

begin_comment
comment|// PR2042
end_comment

begin_function
name|void
name|t10
parameter_list|()
block|{}
end_function

begin_function
name|void
name|t11
parameter_list|()
block|{
name|t10
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning{{too many arguments}}
end_comment

begin_comment
comment|// PR3208
end_comment

begin_function
name|void
name|t12
parameter_list|(
name|int
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-error{{parameter name omitted}}
end_comment

begin_comment
comment|// PR2790
end_comment

begin_function
name|void
name|t13
parameter_list|()
block|{
return|return
literal|0
return|;
comment|// expected-warning {{void function 't13' should not return a value}}
block|}
end_function

begin_function
name|int
name|t14
parameter_list|()
block|{
return|return;
comment|// expected-warning {{non-void function 't14' should return a value}}
block|}
end_function

begin_comment
comment|//<rdar://problem/6097326>
end_comment

begin_macro
name|y
argument_list|(
argument|y
argument_list|)
end_macro

begin_block
block|{
return|return
name|y
return|;
block|}
end_block

begin_comment
comment|// expected-warning{{parameter 'y' was not declared, defaulting to type 'int'}} \
end_comment

begin_comment
comment|// expected-warning{{type specifier missing, defaults to 'int'}}
end_comment

begin_comment
comment|// PR3137,<rdar://problem/6127293>
end_comment

begin_function_decl
specifier|extern
name|int
name|g0_3137
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f0_3137
parameter_list|()
block|{
name|int
name|g0_3137
argument_list|(
name|void
argument_list|)
decl_stmt|;
block|}
end_function

begin_function
name|void
name|f1_3137
parameter_list|()
block|{
name|int
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|g0_3137
function_decl|;
block|}
end_function

begin_function
name|void
name|f1static
parameter_list|()
block|{
specifier|static
name|void
name|f2static
argument_list|(
name|int
argument_list|)
decl_stmt|;
comment|// expected-error{{function declared in block scope cannot have 'static' storage class}}
specifier|register
name|void
name|f2register
argument_list|(
name|int
argument_list|)
decl_stmt|;
comment|// expected-error{{illegal storage class on function}}
block|}
end_function

begin_function
name|struct
name|incomplete_test
name|a
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-error{{incomplete result type 'struct incomplete_test' in function definition}} \
end_comment

begin_comment
comment|// expected-note{{forward declaration of 'struct incomplete_test'}}
end_comment

begin_decl_stmt
specifier|extern
name|__inline
name|__attribute__
argument_list|(
operator|(
name|__gnu_inline__
operator|)
argument_list|)
name|void
name|gnu_inline1
argument_list|()
block|{}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|__gnu_inline__
operator|)
argument_list|)
comment|// expected-warning {{'gnu_inline' attribute requires function to be marked 'inline', attribute ignored}}
name|gnu_inline2
argument_list|()
block|{}
end_decl_stmt

begin_comment
comment|// rdar://6802350
end_comment

begin_function
specifier|inline
name|foo_t
name|invalid_type
parameter_list|()
block|{
comment|// expected-error {{unknown type name 'foo_t'}}
block|}
end_function

begin_typedef
typedef|typedef
name|void
name|fn_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|fn_t
name|t17
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR4049
end_comment

begin_function
name|unknown_type
name|t18
parameter_list|(
name|void
modifier|*
parameter_list|)
block|{
comment|// expected-error {{unknown type name 'unknown_type'}} expected-error{{parameter name omitted}}
block|}
end_function

begin_function
name|unknown_type
name|t19
parameter_list|(
name|int
modifier|*
name|P
parameter_list|)
block|{
comment|// expected-error {{unknown type name 'unknown_type'}}
name|P
operator|=
name|P
operator|+
literal|1
expr_stmt|;
comment|// no warning.
block|}
end_function

begin_comment
comment|// missing ',' before '...'
end_comment

begin_function
name|void
name|t20
parameter_list|(
name|int
name|i
modifier|...
parameter_list|)
block|{ }
end_function

begin_comment
comment|// expected-error {{requires a comma}}
end_comment

end_unit

