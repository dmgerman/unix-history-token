begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wlogical-not-parentheses -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wlogical-not-parentheses -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck %s
end_comment

begin_function_decl
name|int
name|getInt
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|test1
parameter_list|(
name|int
name|i1
parameter_list|,
name|int
name|i2
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|ret
operator|=
operator|!
name|i1
operator|==
name|i2
expr_stmt|;
comment|// expected-warning@-1 {{logical not is only applied to the left hand side of this comparison}}
comment|// expected-note@-2 {{add parentheses after the '!' to evaluate the comparison first}}
comment|// expected-note@-3 {{add parentheses around left hand side expression to silence this warning}}
comment|// CHECK: warn-logical-not-compare.c:[[line:[0-9]*]]:9: warning
comment|// CHECK: to evaluate the comparison first
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:10-[[line]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:18-[[line]]:18}:")"
comment|// CHECK: to silence this warning
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:9-[[line]]:9}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:12-[[line]]:12}:")"
name|ret
operator|=
operator|!
name|i1
operator|!=
name|i2
expr_stmt|;
comment|//expected-warning@-1 {{logical not is only applied to the left hand side of this comparison}}
comment|// expected-note@-2 {{add parentheses after the '!' to evaluate the comparison first}}
comment|// expected-note@-3 {{add parentheses around left hand side expression to silence this warning}}
comment|// CHECK: warn-logical-not-compare.c:[[line:[0-9]*]]:9: warning
comment|// CHECK: to evaluate the comparison first
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:10-[[line]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:18-[[line]]:18}:")"
comment|// CHECK: to silence this warning
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:9-[[line]]:9}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:12-[[line]]:12}:")"
name|ret
operator|=
operator|!
name|i1
operator|<
name|i2
expr_stmt|;
comment|//expected-warning@-1 {{logical not is only applied to the left hand side of this comparison}}
comment|// expected-note@-2 {{add parentheses after the '!' to evaluate the comparison first}}
comment|// expected-note@-3 {{add parentheses around left hand side expression to silence this warning}}
comment|// CHECK: warn-logical-not-compare.c:[[line:[0-9]*]]:9: warning
comment|// CHECK: to evaluate the comparison first
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:10-[[line]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:17-[[line]]:17}:")"
comment|// CHECK: to silence this warning
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:9-[[line]]:9}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:12-[[line]]:12}:")"
name|ret
operator|=
operator|!
name|i1
operator|>
name|i2
expr_stmt|;
comment|//expected-warning@-1 {{logical not is only applied to the left hand side of this comparison}}
comment|// expected-note@-2 {{add parentheses after the '!' to evaluate the comparison first}}
comment|// expected-note@-3 {{add parentheses around left hand side expression to silence this warning}}
comment|// CHECK: warn-logical-not-compare.c:[[line:[0-9]*]]:9: warning
comment|// CHECK: to evaluate the comparison first
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:10-[[line]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:17-[[line]]:17}:")"
comment|// CHECK: to silence this warning
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:9-[[line]]:9}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:12-[[line]]:12}:")"
name|ret
operator|=
operator|!
name|i1
operator|<=
name|i2
expr_stmt|;
comment|//expected-warning@-1 {{logical not is only applied to the left hand side of this comparison}}
comment|// expected-note@-2 {{add parentheses after the '!' to evaluate the comparison first}}
comment|// expected-note@-3 {{add parentheses around left hand side expression to silence this warning}}
comment|// CHECK: warn-logical-not-compare.c:[[line:[0-9]*]]:9: warning
comment|// CHECK: to evaluate the comparison first
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:10-[[line]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:18-[[line]]:18}:")"
comment|// CHECK: to silence this warning
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:9-[[line]]:9}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:12-[[line]]:12}:")"
name|ret
operator|=
operator|!
name|i1
operator|>=
name|i2
expr_stmt|;
comment|//expected-warning@-1 {{logical not is only applied to the left hand side of this comparison}}
comment|// expected-note@-2 {{add parentheses after the '!' to evaluate the comparison first}}
comment|// expected-note@-3 {{add parentheses around left hand side expression to silence this warning}}
comment|// CHECK: warn-logical-not-compare.c:[[line:[0-9]*]]:9: warning
comment|// CHECK: to evaluate the comparison first
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:10-[[line]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:18-[[line]]:18}:")"
comment|// CHECK: to silence this warning
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:9-[[line]]:9}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:12-[[line]]:12}:")"
name|ret
operator|=
name|i1
operator|==
name|i2
expr_stmt|;
name|ret
operator|=
name|i1
operator|!=
name|i2
expr_stmt|;
name|ret
operator|=
name|i1
operator|<
name|i2
expr_stmt|;
name|ret
operator|=
name|i1
operator|>
name|i2
expr_stmt|;
name|ret
operator|=
name|i1
operator|<=
name|i2
expr_stmt|;
name|ret
operator|=
name|i1
operator|>=
name|i2
expr_stmt|;
comment|// Warning silenced by parens.
name|ret
operator|=
operator|(
operator|!
name|i1
operator|)
operator|==
name|i2
expr_stmt|;
name|ret
operator|=
operator|(
operator|!
name|i1
operator|)
operator|!=
name|i2
expr_stmt|;
name|ret
operator|=
operator|(
operator|!
name|i1
operator|)
operator|<
name|i2
expr_stmt|;
name|ret
operator|=
operator|(
operator|!
name|i1
operator|)
operator|>
name|i2
expr_stmt|;
name|ret
operator|=
operator|(
operator|!
name|i1
operator|)
operator|<=
name|i2
expr_stmt|;
name|ret
operator|=
operator|(
operator|!
name|i1
operator|)
operator|>=
name|i2
expr_stmt|;
name|ret
operator|=
operator|!
name|getInt
argument_list|()
operator|==
name|i1
expr_stmt|;
comment|// expected-warning@-1 {{logical not is only applied to the left hand side of this comparison}}
comment|// expected-note@-2 {{add parentheses after the '!' to evaluate the comparison first}}
comment|// expected-note@-3 {{add parentheses around left hand side expression to silence this warning}}
comment|// CHECK: warn-logical-not-compare.c:[[line:[0-9]*]]:9: warning
comment|// CHECK: to evaluate the comparison first
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:10-[[line]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:24-[[line]]:24}:")"
comment|// CHECK: to silence this warning
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:9-[[line]]:9}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:18-[[line]]:18}:")"
name|ret
operator|=
operator|(
operator|!
name|getInt
argument_list|()
operator|)
operator|==
name|i1
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_enum
enum|enum
name|E
block|{
name|e1
block|,
name|e2
block|}
enum|;
end_enum

begin_function_decl
name|enum
name|E
name|getE
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|test2
parameter_list|(
name|enum
name|E
name|e
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|ret
operator|=
name|e
operator|==
name|e1
expr_stmt|;
name|ret
operator|=
name|e
operator|==
name|getE
argument_list|()
expr_stmt|;
name|ret
operator|=
name|getE
argument_list|()
operator|==
name|e1
expr_stmt|;
name|ret
operator|=
name|getE
argument_list|()
operator|==
name|getE
argument_list|()
expr_stmt|;
name|ret
operator|=
operator|!
name|e
operator|==
name|e1
expr_stmt|;
comment|// expected-warning@-1 {{logical not is only applied to the left hand side of this comparison}}
comment|// expected-note@-2 {{add parentheses after the '!' to evaluate the comparison first}}
comment|// expected-note@-3 {{add parentheses around left hand side expression to silence this warning}}
comment|// CHECK: warn-logical-not-compare.c:[[line:[0-9]*]]:9: warning
comment|// CHECK: to evaluate the comparison first
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:10-[[line]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:17-[[line]]:17}:")"
comment|// CHECK: to silence this warning
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:9-[[line]]:9}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:11-[[line]]:11}:")"
name|ret
operator|=
operator|!
name|e
operator|==
name|getE
argument_list|()
expr_stmt|;
comment|// expected-warning@-1 {{logical not is only applied to the left hand side of this comparison}}
comment|// expected-note@-2 {{add parentheses after the '!' to evaluate the comparison first}}
comment|// expected-note@-3 {{add parentheses around left hand side expression to silence this warning}}
comment|// CHECK: warn-logical-not-compare.c:[[line:[0-9]*]]:9: warning
comment|// CHECK: to evaluate the comparison first
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:10-[[line]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:21-[[line]]:21}:")"
comment|// CHECK: to silence this warning
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:9-[[line]]:9}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:11-[[line]]:11}:")"
name|ret
operator|=
operator|!
name|getE
argument_list|()
operator|==
name|e1
expr_stmt|;
comment|// expected-warning@-1 {{logical not is only applied to the left hand side of this comparison}}
comment|// expected-note@-2 {{add parentheses after the '!' to evaluate the comparison first}}
comment|// expected-note@-3 {{add parentheses around left hand side expression to silence this warning}}
comment|// CHECK: warn-logical-not-compare.c:[[line:[0-9]*]]:9: warning
comment|// CHECK: to evaluate the comparison first
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:10-[[line]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:22-[[line]]:22}:")"
comment|// CHECK: to silence this warning
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:9-[[line]]:9}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:16-[[line]]:16}:")"
name|ret
operator|=
operator|!
name|getE
argument_list|()
operator|==
name|getE
argument_list|()
expr_stmt|;
comment|// expected-warning@-1 {{logical not is only applied to the left hand side of this comparison}}
comment|// expected-note@-2 {{add parentheses after the '!' to evaluate the comparison first}}
comment|// expected-note@-3 {{add parentheses around left hand side expression to silence this warning}}
comment|// CHECK: warn-logical-not-compare.c:[[line:[0-9]*]]:9: warning
comment|// CHECK: to evaluate the comparison first
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:10-[[line]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:26-[[line]]:26}:")"
comment|// CHECK: to silence this warning
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:9-[[line]]:9}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[line]]:16-[[line]]:16}:")"
name|ret
operator|=
operator|!
operator|(
name|e
operator|==
name|e1
operator|)
expr_stmt|;
name|ret
operator|=
operator|!
operator|(
name|e
operator|==
name|getE
argument_list|()
operator|)
expr_stmt|;
name|ret
operator|=
operator|!
operator|(
name|getE
argument_list|()
operator|==
name|e1
operator|)
expr_stmt|;
name|ret
operator|=
operator|!
operator|(
name|getE
argument_list|()
operator|==
name|getE
argument_list|()
operator|)
expr_stmt|;
name|ret
operator|=
operator|(
operator|!
name|e
operator|)
operator|==
name|e1
expr_stmt|;
name|ret
operator|=
operator|(
operator|!
name|e
operator|)
operator|==
name|getE
argument_list|()
expr_stmt|;
name|ret
operator|=
operator|(
operator|!
name|getE
argument_list|()
operator|)
operator|==
name|e1
expr_stmt|;
name|ret
operator|=
operator|(
operator|!
name|getE
argument_list|()
operator|)
operator|==
name|getE
argument_list|()
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
name|int
name|PR16673
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
comment|// Make sure we don't emit a fixit for the left paren, but not the right paren.
define|#
directive|define
name|X
parameter_list|(
name|x
parameter_list|)
value|x
name|ret
operator|=
name|X
argument_list|(
operator|!
name|x
operator|==
literal|1
operator|&&
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{logical not is only applied to the left hand side of this comparison}}
comment|// expected-note@-2 {{add parentheses after the '!' to evaluate the comparison first}}
comment|// expected-note@-3 {{add parentheses around left hand side expression to silence this warning}}
comment|// CHECK: warn-logical-not-compare.c:[[line:[0-9]*]]:11: warning
comment|// CHECK: to evaluate the comparison first
comment|// CHECK-NOT: fix-it
comment|// CHECK: to silence this warning
comment|// CHECK-NOT: fix-it
return|return
name|ret
return|;
block|}
end_function

begin_function
name|int
name|compare_pointers
parameter_list|(
name|int
modifier|*
name|a
parameter_list|,
name|int
modifier|*
name|b
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|ret
operator|=
operator|!
operator|!
name|a
operator|==
operator|!
operator|!
name|b
expr_stmt|;
name|ret
operator|=
operator|!
operator|!
name|a
operator|!=
operator|!
operator|!
name|b
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

end_unit

