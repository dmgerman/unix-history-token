begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|EXPAND_2_INNER_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|INNER_CASE(i, x, y);             INNER_CASE(i + 1, x, y);
end_define

begin_define
define|#
directive|define
name|EXPAND_4_INNER_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_2_INNER_CASES(i, x, y)    EXPAND_2_INNER_CASES(i + 2, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_8_INNER_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_4_INNER_CASES(i, x, y)    EXPAND_4_INNER_CASES(i + 4, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_16_INNER_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_8_INNER_CASES(i, x, y)    EXPAND_8_INNER_CASES(i + 8, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_32_INNER_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_16_INNER_CASES(i, x, y)   EXPAND_16_INNER_CASES(i + 16, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_64_INNER_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_32_INNER_CASES(i, x, y)   EXPAND_32_INNER_CASES(i + 32, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_2_OUTER_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|OUTER_CASE(i, x, y);             OUTER_CASE(i + 1, x, y);
end_define

begin_define
define|#
directive|define
name|EXPAND_4_OUTER_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_2_OUTER_CASES(i, x, y)    EXPAND_2_OUTER_CASES(i + 2, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_8_OUTER_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_4_OUTER_CASES(i, x, y)    EXPAND_4_OUTER_CASES(i + 4, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_16_OUTER_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_8_OUTER_CASES(i, x, y)    EXPAND_8_OUTER_CASES(i + 8, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_32_OUTER_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_16_OUTER_CASES(i, x, y)   EXPAND_16_OUTER_CASES(i + 16, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_64_OUTER_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_32_OUTER_CASES(i, x, y)   EXPAND_32_OUTER_CASES(i + 32, x, y)
end_define

begin_comment
comment|// Rather than a single monstrous fan-out, this fans out in smaller increments,
end_comment

begin_comment
comment|// but to a similar size.
end_comment

begin_function
name|unsigned
name|cfg_nested_switch
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|unsigned
name|y
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|x
operator|>
literal|0
condition|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
define|#
directive|define
name|INNER_CASE
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|case i: { int case_var = 3*x + i; y += case_var - 1; break; }
define|#
directive|define
name|OUTER_CASE
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|case i: { \         int case_var = y>> 8; \         switch (case_var) { \           EXPAND_64_INNER_CASES(0, x, y); \         } \         break; \       }
name|EXPAND_64_OUTER_CASES
argument_list|(
literal|0
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
operator|--
name|x
expr_stmt|;
block|}
return|return
name|y
return|;
block|}
end_function

end_unit

