begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wuninitialized-experimental -fsyntax-only -fblocks %s -verify
end_comment

begin_function
name|int
name|test1
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
comment|// expected-note{{variable 'x' is declared here}} expected-note{{add initialization to silence this warning}}
return|return
name|x
return|;
comment|// expected-warning{{variable 'x' is possibly uninitialized when used here}}
block|}
end_function

begin_function
name|int
name|test2
parameter_list|()
block|{
name|int
name|x
init|=
literal|0
decl_stmt|;
return|return
name|x
return|;
comment|// no-warning
block|}
end_function

begin_function
name|int
name|test3
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|x
operator|=
literal|0
expr_stmt|;
return|return
name|x
return|;
comment|// no-warning
block|}
end_function

begin_function
name|int
name|test4
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
comment|// expected-note{{variable 'x' is declared here}} expected-note{{add initialization to silence this warning}}
operator|++
name|x
expr_stmt|;
comment|// expected-warning{{variable 'x' is possibly uninitialized when used here}}
return|return
name|x
return|;
block|}
end_function

begin_function
name|int
name|test5
parameter_list|()
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|// expected-note{{variable 'y' is declared here}} expected-note{{add initialization to silence this warning}}
name|x
operator|=
name|y
expr_stmt|;
comment|// expected-warning{{variable 'y' is possibly uninitialized when used here}}
return|return
name|x
return|;
block|}
end_function

begin_function
name|int
name|test6
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
comment|// expected-note{{variable 'x' is declared here}} expected-note{{add initialization to silence this warning}}
name|x
operator|+=
literal|2
expr_stmt|;
comment|// expected-warning{{variable 'x' is possibly uninitialized when used here}}
return|return
name|x
return|;
block|}
end_function

begin_function
name|int
name|test7
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|int
name|x
decl_stmt|;
comment|// expected-note{{variable 'x' is declared here}} expected-note{{add initialization to silence this warning}}
if|if
condition|(
name|y
condition|)
name|x
operator|=
literal|1
expr_stmt|;
return|return
name|x
return|;
comment|// expected-warning{{variable 'x' is possibly uninitialized when used here}}
block|}
end_function

begin_function
name|int
name|test8
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|int
name|x
decl_stmt|;
if|if
condition|(
name|y
condition|)
name|x
operator|=
literal|1
expr_stmt|;
else|else
name|x
operator|=
literal|0
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_function
name|int
name|test9
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|int
name|x
decl_stmt|;
comment|// expected-note{{variable 'x' is declared here}} expected-note{{add initialization to silence this warning}}
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
operator|==
name|n
operator|-
literal|1
condition|)
break|break;
name|x
operator|=
literal|1
expr_stmt|;
block|}
return|return
name|x
return|;
comment|// expected-warning{{variable 'x' is possibly uninitialized when used here}}
block|}
end_function

begin_function
name|int
name|test10
parameter_list|(
name|unsigned
name|n
parameter_list|)
block|{
name|int
name|x
decl_stmt|;
comment|// expected-note{{variable 'x' is declared here}} expected-note{{add initialization to silence this warning}}
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
block|{
name|x
operator|=
literal|1
expr_stmt|;
block|}
return|return
name|x
return|;
comment|// expected-warning{{variable 'x' is possibly uninitialized when used here}}
block|}
end_function

begin_function
name|int
name|test11
parameter_list|(
name|unsigned
name|n
parameter_list|)
block|{
name|int
name|x
decl_stmt|;
comment|// expected-note{{variable 'x' is declared here}} expected-note{{add initialization to silence this warning}}
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<=
name|n
condition|;
operator|++
name|i
control|)
block|{
name|x
operator|=
literal|1
expr_stmt|;
block|}
return|return
name|x
return|;
comment|// expected-warning{{variable 'x' is possibly uninitialized when used here}}
block|}
end_function

begin_function
name|void
name|test12
parameter_list|(
name|unsigned
name|n
parameter_list|)
block|{
for|for
control|(
name|unsigned
name|i
init|;
name|n
condition|;
operator|++
name|i
control|)
empty_stmt|;
comment|// expected-warning{{variable 'i' is possibly uninitialized when used here}} expected-note{{variable 'i' is declared here}} expected-note{{add initialization to silence this warning}}
block|}
end_function

begin_function
name|int
name|test13
parameter_list|()
block|{
specifier|static
name|int
name|i
decl_stmt|;
return|return
name|i
return|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Simply don't crash on this test case.
end_comment

begin_function
name|void
name|test14
parameter_list|()
block|{
specifier|const
name|char
modifier|*
name|p
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{}
block|}
end_function

begin_function
name|void
name|test15
parameter_list|()
block|{
name|int
name|x
init|=
name|x
decl_stmt|;
comment|// expected-warning{{variable 'x' is possibly uninitialized when used here}} expected-note{{variable 'x' is declared here}} expected-note{{add initialization to silence this warning}}
block|}
end_function

begin_comment
comment|// Don't warn in the following example; shows dataflow confluence.
end_comment

begin_function_decl
name|char
modifier|*
name|test16_aux
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test16
parameter_list|()
block|{
name|char
modifier|*
name|p
init|=
name|test16_aux
argument_list|()
decl_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|100
condition|;
name|i
operator|++
control|)
name|p
index|[
name|i
index|]
operator|=
literal|'a'
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|test17
parameter_list|()
block|{
comment|// Don't warn multiple times about the same uninitialized variable
comment|// along the same path.
name|int
modifier|*
name|x
decl_stmt|;
comment|// expected-note{{variable 'x' is declared here}} expected-note{{add initialization to silence this warning}}
operator|*
name|x
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{variable 'x' is possibly uninitialized when used here}}
operator|*
name|x
operator|=
literal|1
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|int
name|test18
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|int
name|z
decl_stmt|;
if|if
condition|(
name|x
operator|&&
name|y
operator|&&
operator|(
name|z
operator|=
literal|1
operator|)
condition|)
block|{
return|return
name|z
return|;
comment|// no-warning
block|}
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
name|int
name|test19_aux1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test19_aux2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test19_aux3
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test19
parameter_list|()
block|{
name|int
name|z
decl_stmt|;
if|if
condition|(
name|test19_aux1
argument_list|()
operator|+
name|test19_aux2
argument_list|()
operator|&&
name|test19_aux1
argument_list|()
operator|&&
name|test19_aux3
argument_list|(
operator|&
name|z
argument_list|)
condition|)
return|return
name|z
return|;
comment|// no-warning
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|test20
parameter_list|()
block|{
name|int
name|z
decl_stmt|;
comment|// expected-note{{variable 'z' is declared here}} expected-note{{add initialization to silence this warning}}
if|if
condition|(
operator|(
name|test19_aux1
argument_list|()
operator|+
name|test19_aux2
argument_list|()
operator|&&
name|test19_aux1
argument_list|()
operator|)
operator|||
name|test19_aux3
argument_list|(
operator|&
name|z
argument_list|)
condition|)
return|return
name|z
return|;
comment|// expected-warning{{variable 'z' is possibly uninitialized when used here}}
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|test21
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|int
name|z
decl_stmt|;
comment|// expected-note{{variable 'z' is declared here}} expected-note{{add initialization to silence this warning}}
if|if
condition|(
operator|(
name|x
operator|&&
name|y
operator|)
operator|||
name|test19_aux3
argument_list|(
operator|&
name|z
argument_list|)
operator|||
name|test19_aux2
argument_list|()
condition|)
return|return
name|z
return|;
comment|// expected-warning{{variable 'z' is possibly uninitialized when used here}}
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|test22
parameter_list|()
block|{
name|int
name|z
decl_stmt|;
while|while
condition|(
name|test19_aux1
argument_list|()
operator|+
name|test19_aux2
argument_list|()
operator|&&
name|test19_aux1
argument_list|()
operator|&&
name|test19_aux3
argument_list|(
operator|&
name|z
argument_list|)
condition|)
return|return
name|z
return|;
comment|// no-warning
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|test23
parameter_list|()
block|{
name|int
name|z
decl_stmt|;
for|for
control|(
init|;
name|test19_aux1
argument_list|()
operator|+
name|test19_aux2
argument_list|()
operator|&&
name|test19_aux1
argument_list|()
operator|&&
name|test19_aux3
argument_list|(
operator|&
name|z
argument_list|)
condition|;
control|)
return|return
name|z
return|;
comment|// no-warning
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// The basic uninitialized value analysis doesn't have enough path-sensitivity
end_comment

begin_comment
comment|// to catch initializations relying on control-dependencies spanning multiple
end_comment

begin_comment
comment|// conditionals.  This possibly can be handled by making the CFG itself
end_comment

begin_comment
comment|// represent such control-dependencies, but it is a niche case.
end_comment

begin_function
name|int
name|test24
parameter_list|(
name|int
name|flag
parameter_list|)
block|{
name|unsigned
name|val
decl_stmt|;
comment|// expected-note{{variable 'val' is declared here}} expected-note{{add initialization to silence this warning}}
if|if
condition|(
name|flag
condition|)
name|val
operator|=
literal|1
expr_stmt|;
if|if
condition|(
operator|!
name|flag
condition|)
name|val
operator|=
literal|1
expr_stmt|;
return|return
name|val
return|;
comment|// expected-warning{{variable 'val' is possibly uninitialized when used here}}
block|}
end_function

begin_function
name|float
name|test25
parameter_list|()
block|{
name|float
name|x
decl_stmt|;
comment|// expected-note{{variable 'x' is declared here}} expected-note{{add initialization to silence this warning}}
return|return
name|x
return|;
comment|// expected-warning{{variable 'x' is possibly uninitialized when used here}}
block|}
end_function

begin_typedef
typedef|typedef
name|int
name|MyInt
typedef|;
end_typedef

begin_function
name|MyInt
name|test26
parameter_list|()
block|{
name|MyInt
name|x
decl_stmt|;
comment|// expected-note{{variable 'x' is declared here}} expected-note{{add initialization to silence this warning}}
return|return
name|x
return|;
comment|// expected-warning{{variable 'x' is possibly uninitialized when used here}}
block|}
end_function

begin_comment
comment|// Test handling of sizeof().
end_comment

begin_function
name|int
name|test27
parameter_list|()
block|{
struct|struct
name|test_27
block|{
name|int
name|x
decl_stmt|;
block|}
modifier|*
name|y
struct|;
return|return
sizeof|sizeof
argument_list|(
name|y
operator|->
name|x
argument_list|)
return|;
comment|// no-warning
block|}
end_function

begin_function
name|int
name|test28
parameter_list|()
block|{
name|int
name|len
decl_stmt|;
comment|// expected-note{{variable 'len' is declared here}} expected-note{{add initialization to silence this warning}}
return|return
sizeof|sizeof
argument_list|(
name|int
index|[
name|len
index|]
argument_list|)
return|;
comment|// expected-warning{{variable 'len' is possibly uninitialized when used here}}
block|}
end_function

begin_function
name|void
name|test29
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
comment|// expected-note{{variable 'x' is declared here}} expected-note{{add initialization to silence this warning}}
operator|(
name|void
operator|)
lambda|^
block|{
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
expr_stmt|;
comment|// expected-warning{{variable 'x' is possibly uninitialized when captured by block}}
block|}
end_function

begin_function
name|void
name|test30
parameter_list|()
block|{
specifier|static
name|int
name|x
decl_stmt|;
comment|// no-warning
operator|(
name|void
operator|)
lambda|^
block|{
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test31
parameter_list|()
block|{
specifier|__block
name|int
name|x
decl_stmt|;
comment|// no-warning
operator|(
name|void
operator|)
lambda|^
block|{
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|int
name|test32_x
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test32
parameter_list|()
block|{
operator|(
name|void
operator|)
lambda|^
block|{
operator|(
name|void
operator|)
name|test32_x
expr_stmt|;
block|}
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|test_33
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
comment|// no-warning
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
end_function

begin_function
name|int
name|test_34
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
comment|// expected-note{{variable 'x' is declared here}} expected-note{{add initialization to silence this warning}}
operator|(
name|void
operator|)
name|x
expr_stmt|;
return|return
name|x
return|;
comment|// expected-warning{{variable 'x' is possibly uninitialized when used here}}
block|}
end_function

begin_comment
comment|// Test that this case doesn't crash.
end_comment

begin_function
name|void
name|test35
parameter_list|(
name|int
name|x
parameter_list|)
block|{
specifier|__block
name|int
name|y
init|=
literal|0
decl_stmt|;
lambda|^
block|{
name|y
operator|=
operator|(
name|x
operator|==
literal|0
operator|)
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// Test handling of indirect goto.
end_comment

begin_function
name|void
name|test36
parameter_list|()
block|{
name|void
modifier|*
modifier|*
name|pc
decl_stmt|;
comment|// expected-note{{variable 'pc' is declared here}} expected-note{{add initialization to silence this warning}}
name|void
modifier|*
name|dummy
index|[]
init|=
block|{
operator|&&
name|L1
block|,
operator|&&
name|L2
block|}
decl_stmt|;
name|L1
label|:
goto|goto *
name|pc
goto|;
comment|// expected-warning{{variable 'pc' is possibly uninitialized when used here}}
name|L2
label|:
goto|goto *
name|pc
goto|;
block|}
end_function

begin_comment
comment|// Test&& nested in ||.
end_comment

begin_function_decl
name|int
name|test37_a
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test37_b
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|test37
parameter_list|()
block|{
name|int
name|identifier
decl_stmt|;
if|if
condition|(
operator|(
name|test37_a
argument_list|()
operator|&&
operator|(
name|identifier
operator|=
literal|1
operator|)
operator|)
operator|||
operator|(
name|test37_b
argument_list|()
operator|&&
operator|(
name|identifier
operator|=
literal|2
operator|)
operator|)
condition|)
block|{
return|return
name|identifier
return|;
comment|// no-warning
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// Test merging of path-specific dataflow values (without asserting).
end_comment

begin_function
name|int
name|test38
parameter_list|(
name|int
name|r
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|int
name|z
decl_stmt|;
return|return
operator|(
operator|(
name|r
operator|<
literal|0
operator|)
operator|||
operator|(
operator|(
name|r
operator|==
literal|0
operator|)
operator|&&
operator|(
name|x
operator|<
name|y
operator|)
operator|)
operator|)
return|;
block|}
end_function

end_unit

