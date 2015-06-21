begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -pedantic -fsyntax-only -Wno-gnu-statement-expression
end_comment

begin_function_decl
name|int
name|stmtexpr_fn
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|stmtexprs
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|__builtin_assume
argument_list|(
argument|({
literal|1
argument|; })
argument_list|)
empty_stmt|;
comment|// no warning about "side effects"
name|__builtin_assume
argument_list|(
argument|({ if (i) { (void)
literal|0
argument|; };
literal|42
argument|; })
argument_list|)
empty_stmt|;
comment|// no warning about "side effects"
comment|// expected-warning@+1 {{the argument to '__builtin_assume' has side effects that will be discarded}}
name|__builtin_assume
argument_list|(
argument|({ if (i) ({ stmtexpr_fn(); });
literal|1
argument|; })
argument_list|)
empty_stmt|;
block|}
end_function

end_unit

