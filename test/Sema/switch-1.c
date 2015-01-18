begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple x86_64-apple-darwin10 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -fsyntax-only -verify -triple x86_64-apple-darwin10 %s
end_comment

begin_comment
comment|// rdar://11577384
end_comment

begin_comment
comment|// rdar://13423975
end_comment

begin_function
name|int
name|f
parameter_list|(
name|int
name|i
parameter_list|)
block|{
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|2147483647
operator|+
literal|2
case|:
comment|// expected-warning {{overflow in expression; result is -2147483647 with type 'int'}}
return|return
literal|1
return|;
case|case
literal|9223372036854775807L
operator|*
literal|4
case|:
comment|// expected-warning {{overflow in expression; result is -4 with type 'long'}}
return|return
literal|2
return|;
case|case
operator|(
literal|123456
operator|*
literal|789012
operator|)
operator|+
literal|1
case|:
comment|// expected-warning {{overflow in expression; result is -1375982336 with type 'int'}}
return|return
literal|3
return|;
case|case
operator|(
literal|2147483647
operator|*
literal|4
operator|)
operator|/
literal|4
case|:
comment|// expected-warning {{overflow in expression; result is -4 with type 'int'}}
case|case
operator|(
literal|2147483647
operator|*
literal|4
operator|)
operator|%
literal|4
case|:
comment|// expected-warning {{overflow in expression; result is -4 with type 'int'}}
return|return
literal|4
return|;
case|case
literal|2147483647
case|:
return|return
literal|0
return|;
block|}
return|return
operator|(
name|i
operator|,
literal|65537
operator|)
operator|*
literal|65537
return|;
comment|// expected-warning {{overflow in expression; result is 131073 with type 'int'}} \
comment|// expected-warning {{expression result unused}}
block|}
end_function

begin_comment
comment|// rdar://18405357
end_comment

begin_decl_stmt
name|unsigned
name|long
name|long
name|l
init|=
literal|65536
operator|*
literal|65536
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{overflow in expression; result is 0 with type 'int'}}
end_comment

begin_decl_stmt
name|unsigned
name|long
name|long
name|l2
init|=
literal|65536
operator|*
operator|(
name|unsigned
operator|)
literal|65536
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|long
name|l3
init|=
literal|65536
operator|*
literal|65536ULL
decl_stmt|;
end_decl_stmt

end_unit

