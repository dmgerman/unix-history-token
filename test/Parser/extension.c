begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 %s -fsyntax-only -pedantic -verify -std=c89  */
end_comment

begin_comment
comment|/* Top level extension marker. */
end_comment

begin_macro
name|__extension__
end_macro

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|long
name|int
name|quot
decl_stmt|;
name|long
name|long
name|int
name|rem
decl_stmt|;
block|}
name|lldiv_t
typedef|;
end_typedef

begin_comment
comment|/* Decl/expr __extension__ marker. */
end_comment

begin_function
name|void
name|bar
parameter_list|()
block|{
name|__extension__
name|int
name|i
decl_stmt|;
name|int
name|j
decl_stmt|;
name|__extension__
argument_list|(
name|j
operator|=
literal|10LL
argument_list|)
expr_stmt|;
name|__extension__
name|j
init|=
literal|10LL
decl_stmt|;
comment|/* expected-warning {{'long long' is an extension}} */
block|}
end_function

end_unit

