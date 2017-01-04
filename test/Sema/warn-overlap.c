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

begin_enum
enum|enum
name|Choices
block|{
name|CHOICE_0
init|=
literal|0
block|,
name|CHOICE_1
init|=
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|Unchoices
block|{
name|UNCHOICE_0
init|=
literal|0
block|,
name|UNCHOICE_1
init|=
literal|1
block|}
enum|;
end_enum

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
if|if
condition|(
name|x
operator|!=
name|CHOICE_0
operator|||
name|x
operator|!=
name|CHOICE_1
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to true}}
if|if
condition|(
name|x
operator|==
name|CHOICE_0
operator|&&
name|x
operator|==
name|CHOICE_1
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to false}}
comment|// Don't warn if comparing x to different types
if|if
condition|(
name|x
operator|==
name|CHOICE_0
operator|&&
name|x
operator|==
literal|1
condition|)
block|{ }
if|if
condition|(
name|x
operator|!=
name|CHOICE_0
operator|||
name|x
operator|!=
literal|1
condition|)
block|{ }
comment|// "Different types" includes different enums
if|if
condition|(
name|x
operator|==
name|CHOICE_0
operator|&&
name|x
operator|==
name|UNCHOICE_1
condition|)
block|{ }
if|if
condition|(
name|x
operator|!=
name|CHOICE_0
operator|||
name|x
operator|!=
name|UNCHOICE_1
condition|)
block|{ }
block|}
end_function

begin_function
name|void
name|enums
parameter_list|(
name|enum
name|Choices
name|c
parameter_list|)
block|{
if|if
condition|(
name|c
operator|!=
name|CHOICE_0
operator|||
name|c
operator|!=
name|CHOICE_1
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to true}}
if|if
condition|(
name|c
operator|==
name|CHOICE_0
operator|&&
name|c
operator|==
name|CHOICE_1
condition|)
block|{ }
comment|// expected-warning {{overlapping comparisons always evaluate to false}}
comment|// Don't warn if comparing x to different types
if|if
condition|(
name|c
operator|==
name|CHOICE_0
operator|&&
name|c
operator|==
literal|1
condition|)
block|{ }
if|if
condition|(
name|c
operator|!=
name|CHOICE_0
operator|||
name|c
operator|!=
literal|1
condition|)
block|{ }
comment|// "Different types" includes different enums
if|if
condition|(
name|c
operator|==
name|CHOICE_0
operator|&&
name|c
operator|==
name|UNCHOICE_1
condition|)
block|{ }
if|if
condition|(
name|c
operator|!=
name|CHOICE_0
operator|||
name|c
operator|!=
name|UNCHOICE_1
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

begin_function
name|void
name|bool_contexts
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
operator|>
literal|4
operator|||
name|x
operator|<
literal|10
condition|)
block|{}
comment|// expected-warning@-1{{overlapping comparisons always evaluate to true}}
for|for
control|(
init|;
name|x
operator|>
literal|4
operator|||
name|x
operator|<
literal|10
condition|;
control|)
block|{}
comment|// expected-warning@-1{{overlapping comparisons always evaluate to true}}
while|while
condition|(
name|x
operator|>
literal|4
operator|||
name|x
operator|<
literal|10
condition|)
block|{}
comment|// expected-warning@-1{{overlapping comparisons always evaluate to true}}
do|do
block|{}
do|while
condition|(
name|x
operator|>
literal|4
operator|||
name|x
operator|<
literal|10
condition|)
do|;
comment|// expected-warning@-1{{overlapping comparisons always evaluate to true}}
name|x
operator|=
operator|(
name|x
operator|>
literal|4
operator|||
name|x
operator|<
literal|10
operator|)
condition|?
literal|1
else|:
literal|2
expr_stmt|;
comment|// expected-warning@-1{{overlapping comparisons always evaluate to true}}
if|if
condition|(
operator|(
name|void
operator|)
literal|5
operator|,
name|x
operator|>
literal|4
operator|||
name|x
operator|<
literal|10
condition|)
block|{}
comment|// expected-warning@-1{{overlapping comparisons always evaluate to true}}
block|}
end_function

begin_function
name|void
name|assignment
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|a
init|=
name|x
operator|>
literal|4
operator|||
name|x
operator|<
literal|10
decl_stmt|;
comment|// expected-warning@-1{{overlapping comparisons always evaluate to true}}
name|int
name|b
init|=
name|x
operator|<
literal|2
operator|&&
name|x
operator|>
literal|5
decl_stmt|;
comment|// expected-warning@-1{{overlapping comparisons always evaluate to false}}
name|int
name|c
init|=
name|x
operator|!=
literal|1
operator|||
name|x
operator|!=
literal|3
decl_stmt|;
comment|// expected-warning@-1{{overlapping comparisons always evaluate to true}}
name|int
name|d
init|=
name|x
operator|==
literal|1
operator|&&
name|x
operator|==
literal|2
decl_stmt|;
comment|// expected-warning@-1{{overlapping comparisons always evaluate to false}}
name|int
name|e
init|=
name|x
operator|<
literal|1
operator|||
name|x
operator|!=
literal|0
decl_stmt|;
comment|// expected-warning@-1{{overlapping comparisons always evaluate to true}}
block|}
end_function

begin_function
name|int
name|returns
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
operator|>
literal|4
operator|||
name|x
operator|<
literal|10
return|;
comment|// expected-warning@-1{{overlapping comparisons always evaluate to true}}
return|return
name|x
operator|<
literal|2
operator|&&
name|x
operator|>
literal|5
return|;
comment|// expected-warning@-1{{overlapping comparisons always evaluate to false}}
return|return
name|x
operator|!=
literal|1
operator|||
name|x
operator|!=
literal|3
return|;
comment|// expected-warning@-1{{overlapping comparisons always evaluate to true}}
return|return
name|x
operator|==
literal|1
operator|&&
name|x
operator|==
literal|2
return|;
comment|// expected-warning@-1{{overlapping comparisons always evaluate to false}}
return|return
name|x
operator|<
literal|1
operator|||
name|x
operator|!=
literal|0
return|;
comment|// expected-warning@-1{{overlapping comparisons always evaluate to true}}
block|}
end_function

end_unit

