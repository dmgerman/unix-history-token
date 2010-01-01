begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test for absence of crash reported in PR 2923:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  http://llvm.org/bugs/show_bug.cgi?id=2923
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Previously we had a crash when deallocating the FunctionDecl for 'bar'
end_comment

begin_comment
comment|// because FunctionDecl::getNumParams() just used the type of foo to determine
end_comment

begin_comment
comment|// the number of parameters it has.  In the case of 'bar' there are no
end_comment

begin_comment
comment|// ParmVarDecls.
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
return|return
name|x
operator|+
name|y
return|;
block|}
end_function

begin_extern
extern|extern typeof(foo
end_extern

begin_expr_stmt
unit|)
name|bar
expr_stmt|;
end_expr_stmt

end_unit

