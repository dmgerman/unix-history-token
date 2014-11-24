begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wtautological-overlap-compare %s
end_comment

begin_define
define|#
directive|define
name|mydefine
value|2
end_define

begin_function
name|void
name|f
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|y
init|=
literal|0
decl_stmt|;
comment|//> ||<
if|if
condition|(
name|x
operator|>
literal|2
operator|||
name|x
operator|<
literal|1
condition|)
block|{ }
if|if
condition|(
name|x
operator|>
literal|2
operator|||
name|x
operator|<
literal|2
condition|)
block|{ }
if|if
condition|(
name|x
operator|!=
literal|2
operator|||
name|x
operator|!=
literal|3
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to true}}
if|if
condition|(
name|x
operator|>
literal|2
operator|||
name|x
operator|<
literal|3
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to true}}
if|if
condition|(
name|x
operator|>
literal|0
operator|||
name|x
operator|<
literal|0
condition|)
block|{ }
if|if
condition|(
name|x
operator|>
literal|2
operator|||
name|x
operator|<=
literal|1
condition|)
block|{ }
if|if
condition|(
name|x
operator|>
literal|2
operator|||
name|x
operator|<=
literal|2
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to true}}
if|if
condition|(
name|x
operator|>
literal|2
operator|||
name|x
operator|<=
literal|3
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to true}}
if|if
condition|(
name|x
operator|>=
literal|2
operator|||
name|x
operator|<
literal|1
condition|)
block|{ }
if|if
condition|(
name|x
operator|>=
literal|2
operator|||
name|x
operator|<
literal|2
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to true}}
if|if
condition|(
name|x
operator|>=
literal|2
operator|||
name|x
operator|<
literal|3
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to true}}
if|if
condition|(
name|x
operator|>=
literal|2
operator|||
name|x
operator|<=
literal|1
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to true}}
if|if
condition|(
name|x
operator|>=
literal|2
operator|||
name|x
operator|<=
literal|2
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to true}}
if|if
condition|(
name|x
operator|>=
literal|2
operator|||
name|x
operator|<=
literal|3
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to true}}
if|if
condition|(
name|x
operator|>=
literal|0
operator|||
name|x
operator|<=
literal|0
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to true}}
comment|//>&&<
if|if
condition|(
name|x
operator|>
literal|2
operator|&&
name|x
operator|<
literal|1
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to false}}
if|if
condition|(
name|x
operator|>
literal|2
operator|&&
name|x
operator|<
literal|2
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to false}}
if|if
condition|(
name|x
operator|>
literal|2
operator|&&
name|x
operator|<
literal|3
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to false}}
if|if
condition|(
name|x
operator|>
literal|0
operator|&&
name|x
operator|<
literal|1
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to false}}
if|if
condition|(
name|x
operator|>
literal|2
operator|&&
name|x
operator|<=
literal|1
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to false}}
if|if
condition|(
name|x
operator|>
literal|2
operator|&&
name|x
operator|<=
literal|2
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to false}}
if|if
condition|(
name|x
operator|>
literal|2
operator|&&
name|x
operator|<=
literal|3
condition|)
block|{ }
if|if
condition|(
name|x
operator|>=
literal|2
operator|&&
name|x
operator|<
literal|1
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to false}}
if|if
condition|(
name|x
operator|>=
literal|2
operator|&&
name|x
operator|<
literal|2
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to false}}
if|if
condition|(
name|x
operator|>=
literal|2
operator|&&
name|x
operator|<
literal|3
condition|)
block|{ }
if|if
condition|(
name|x
operator|>=
literal|0
operator|&&
name|x
operator|<
literal|0
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to false}}
if|if
condition|(
name|x
operator|>=
literal|2
operator|&&
name|x
operator|<=
literal|1
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to false}}
if|if
condition|(
name|x
operator|>=
literal|2
operator|&&
name|x
operator|<=
literal|2
condition|)
block|{ }
if|if
condition|(
name|x
operator|>=
literal|2
operator|&&
name|x
operator|<=
literal|3
condition|)
block|{ }
comment|// !=, ==, ..
if|if
condition|(
name|x
operator|!=
literal|2
operator|||
name|x
operator|!=
literal|3
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to true}}
if|if
condition|(
name|x
operator|!=
literal|2
operator|||
name|x
operator|<
literal|3
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to true}}
if|if
condition|(
name|x
operator|==
literal|2
operator|&&
name|x
operator|==
literal|3
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to false}}
if|if
condition|(
name|x
operator|==
literal|2
operator|&&
name|x
operator|>
literal|3
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to false}}
if|if
condition|(
name|x
operator|==
literal|3
operator|&&
name|x
operator|<
literal|0
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to false}}
if|if
condition|(
literal|3
operator|==
name|x
operator|&&
name|x
operator|<
literal|0
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to false}}
if|if
condition|(
name|x
operator|==
name|mydefine
operator|&&
name|x
operator|>
literal|3
condition|)
block|{ }
if|if
condition|(
name|x
operator|==
operator|(
name|mydefine
operator|+
literal|1
operator|)
operator|&&
name|x
operator|>
literal|3
condition|)
block|{ }
block|}
end_function

begin_comment
comment|// Don't generate a warning here.
end_comment

begin_function
name|void
name|array_out_of_bounds
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|int
name|buffer
index|[
literal|4
index|]
decl_stmt|;
name|x
operator|=
operator|(
operator|-
literal|7
operator|>
literal|0
operator|)
condition|?
operator|(
name|buffer
index|[
operator|-
literal|7
index|]
operator|)
else|:
literal|0
expr_stmt|;
block|}
end_function

end_unit

