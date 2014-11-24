begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 %s -std=c89 -pedantic -fsyntax-only -verify -Wimplicit-function-declaration  */
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
block|{
name|int
name|i
decl_stmt|;
name|i
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|int
name|j
decl_stmt|;
comment|/* expected-warning {{mixing declarations and code}} */
block|}
block|{
name|__extension__
name|int
name|i
decl_stmt|;
name|i
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|int
name|j
decl_stmt|;
comment|/* expected-warning {{mixing declarations and code}} */
block|}
block|{
name|int
name|i
decl_stmt|;
name|i
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|__extension__
name|int
name|j
decl_stmt|;
comment|/* expected-warning {{mixing declarations and code}} */
block|}
block|}
end_function

begin_decl_stmt
name|long
name|long
name|test2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expected-warning {{extension}} */
end_comment

begin_function
name|void
name|test3
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|int
name|A
index|[
name|i
index|]
decl_stmt|;
comment|/* expected-warning {{variable length array}} */
block|}
end_function

begin_decl_stmt
name|int
name|test4
init|=
literal|0LL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expected-warning {{long long}} */
end_comment

begin_comment
comment|/* PR1999 */
end_comment

begin_function_decl
name|void
name|test5
parameter_list|(
specifier|register
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* PR2041 */
end_comment

begin_expr_stmt
name|int
operator|*
specifier|restrict
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
modifier|*
name|__restrict
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expected-error {{expected identifier}} */
end_comment

begin_comment
comment|/* Implicit int, always ok */
end_comment

begin_macro
name|test6
argument_list|()
end_macro

begin_block
block|{
return|return
literal|0
return|;
block|}
end_block

begin_comment
comment|/* PR2012 */
end_comment

begin_expr_stmt
name|test7
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* expected-warning {{declaration specifier missing, defaulting to 'int'}} */
end_comment

begin_function_decl
name|void
name|test8
parameter_list|(
name|int
parameter_list|,
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* expected-warning {{declaration specifier missing, defaulting to 'int'}} */
end_comment

begin_typedef
typedef|typedef
name|int
name|sometype
typedef|;
end_typedef

begin_function
name|int
name|a
parameter_list|(
name|sometype
parameter_list|,
name|y
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* expected-warning {{declaration specifier missing, defaulting to 'int'}} \                                    expected-error {{parameter name omitted}}*/
end_comment

begin_function_decl
name|void
name|bar
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f11
parameter_list|(
name|z
parameter_list|)
comment|/* expected-error {{may not have 'void' type}} */
name|void
name|z
decl_stmt|;
block|{
name|bar
argument_list|(
operator|&
name|z
argument_list|)
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|void
name|T
typedef|;
end_typedef

begin_function_decl
name|void
name|foo
parameter_list|(
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* typedef for void is allowed */
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|/* PR2759 */
end_comment

begin_function_decl
name|void
name|test10
parameter_list|(
name|int
name|x
index|[
operator|*
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* expected-warning {{variable length arrays are a C99 feature}} */
end_comment

begin_function_decl
name|void
name|test11
parameter_list|(
name|int
name|x
index|[
specifier|static
literal|4
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* expected-warning {{static array size is a C99 feature}} */
end_comment

begin_function
name|void
name|test12
parameter_list|(
name|int
name|x
index|[
specifier|const
literal|4
index|]
parameter_list|)
block|{
comment|/* expected-warning {{qualifier in array size is a C99 feature}} */
name|int
name|Y
index|[
name|x
index|[
literal|1
index|]
index|]
decl_stmt|;
comment|/* expected-warning {{variable length arrays are a C99 feature}} */
block|}
end_function

begin_comment
comment|/* PR4074 */
end_comment

begin_struct
struct|struct
name|test13
block|{
name|int
name|X
index|[
literal|23
index|]
decl_stmt|;
block|}
name|test13a
argument_list|()
struct|;
end_struct

begin_function
name|void
name|test13b
parameter_list|()
block|{
name|int
name|a
init|=
name|test13a
argument_list|()
operator|.
name|X
index|[
literal|1
index|]
decl_stmt|;
comment|/* expected-warning {{ISO C90 does not allow subscripting non-lvalue array}} */
name|int
name|b
init|=
literal|1
index|[
name|test13a
argument_list|()
operator|.
name|X
index|]
decl_stmt|;
comment|/* expected-warning {{ISO C90 does not allow subscripting non-lvalue array}} */
block|}
end_function

begin_comment
comment|/* Make sure we allow *test14 as a "function designator" */
end_comment

begin_function
name|int
name|test14
parameter_list|()
block|{
return|return
call|(
modifier|&
modifier|*
name|test14
call|)
argument_list|()
return|;
block|}
end_function

begin_decl_stmt
name|int
name|test15
index|[
literal|5
index|]
init|=
block|{
index|[
literal|2
index|]
operator|=
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expected-warning {{designated initializers are a C99 feature}} */
end_comment

begin_function_decl
specifier|extern
name|int
name|printf
parameter_list|(
name|__const
name|char
modifier|*
name|__restrict
name|__format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Warn, but don't suggest typo correction. */
end_comment

begin_function
name|void
name|test16
parameter_list|()
block|{
name|printg
argument_list|(
literal|"Hello, world!\n"
argument_list|)
expr_stmt|;
comment|/* expected-warning {{implicit declaration of function 'printg'}} */
block|}
end_function

begin_struct
struct|struct
name|x
block|{
name|int
name|x
decl_stmt|,
name|y
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* expected-warning {{flexible array members are a C99 feature}} */
end_comment

begin_comment
comment|/* Duplicated type-qualifiers aren't allowed by C90 */
end_comment

begin_decl_stmt
specifier|const
specifier|const
name|int
name|c_i
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expected-warning {{duplicate 'const' declaration specifier}} */
end_comment

begin_typedef
typedef|typedef
specifier|volatile
name|int
name|vol_int
typedef|;
end_typedef

begin_decl_stmt
specifier|volatile
name|vol_int
name|volvol_i
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expected-warning {{duplicate 'volatile' declaration specifier}} */
end_comment

begin_typedef
typedef|typedef
specifier|volatile
name|vol_int
name|volvol_int
typedef|;
end_typedef

begin_comment
comment|/* expected-warning {{duplicate 'volatile' declaration specifier}} */
end_comment

begin_decl_stmt
specifier|const
name|int
modifier|*
specifier|const
name|c
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
specifier|const
name|int
name|CI
typedef|;
end_typedef

begin_decl_stmt
specifier|const
name|CI
name|mine1
index|[
literal|5
index|]
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expected-warning {{duplicate 'const' declaration specifier}} */
end_comment

begin_typedef
typedef|typedef
name|CI
name|array_of_CI
index|[
literal|5
index|]
typedef|;
end_typedef

begin_decl_stmt
specifier|const
name|array_of_CI
name|mine2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expected-warning {{duplicate 'const' declaration specifier}} */
end_comment

begin_typedef
typedef|typedef
name|CI
modifier|*
name|array_of_pointer_to_CI
index|[
literal|5
index|]
typedef|;
end_typedef

begin_decl_stmt
specifier|const
name|array_of_pointer_to_CI
name|mine3
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|main
parameter_list|()
block|{}
end_function

begin_comment
comment|/* expected-error {{'main' must return 'int'}} */
end_comment

begin_function
specifier|const
name|int
name|main
parameter_list|()
block|{}
end_function

begin_comment
comment|/* expected-error {{'main' must return 'int'}} */
end_comment

begin_decl_stmt
name|long
name|long
name|ll1
init|=
comment|/* expected-warning {{'long long' is an extension when C99 mode is not enabled}} */
operator|-
literal|42LL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expected-warning {{'long long' is an extension when C99 mode is not enabled}} */
end_comment

begin_decl_stmt
name|unsigned
name|long
name|long
name|ull1
init|=
comment|/* expected-warning {{'long long' is an extension when C99 mode is not enabled}} */
literal|42ULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expected-warning {{'long long' is an extension when C99 mode is not enabled}} */
end_comment

begin_struct
struct|struct
name|Test17
block|{
name|int
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|Test17
name|test17_aux
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test17
parameter_list|(
name|int
name|v
parameter_list|,
name|int
name|w
parameter_list|)
block|{
name|int
name|a
index|[
literal|2
index|]
init|=
block|{
name|v
block|,
name|w
block|}
decl_stmt|;
comment|/* expected-warning {{initializer for aggregate is not a compile-time constant}} */
name|struct
name|Test17
name|t0
init|=
block|{
name|v
block|}
decl_stmt|;
comment|/* expected-warning {{initializer for aggregate is not a compile-time constant}} */
name|struct
name|Test17
name|t1
init|=
name|test17_aux
argument_list|()
decl_stmt|;
comment|/* this is allowed */
block|}
end_function

end_unit

