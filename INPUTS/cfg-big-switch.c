begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|EXPAND_2_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|CASE(i, x, y);             CASE(i + 1, x, y);
end_define

begin_define
define|#
directive|define
name|EXPAND_4_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_2_CASES(i, x, y)    EXPAND_2_CASES(i + 2, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_8_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_4_CASES(i, x, y)    EXPAND_4_CASES(i + 4, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_16_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_8_CASES(i, x, y)    EXPAND_8_CASES(i + 8, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_32_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_16_CASES(i, x, y)   EXPAND_16_CASES(i + 16, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_64_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_32_CASES(i, x, y)   EXPAND_32_CASES(i + 32, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_128_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_64_CASES(i, x, y)   EXPAND_64_CASES(i + 64, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_256_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_128_CASES(i, x, y)  EXPAND_128_CASES(i + 128, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_512_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_256_CASES(i, x, y)  EXPAND_256_CASES(i + 256, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_1024_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_512_CASES(i, x, y)  EXPAND_512_CASES(i + 512, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_2048_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_1024_CASES(i, x, y) EXPAND_1024_CASES(i + 1024, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_4096_CASES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_2048_CASES(i, x, y) EXPAND_2048_CASES(i + 2048, x, y)
end_define

begin_comment
comment|// This has a *monstrous* single fan-out in the CFG, across 8000 blocks inside
end_comment

begin_comment
comment|// the while loop.
end_comment

begin_function
name|unsigned
name|cfg_big_switch
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
name|CASE
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|case i: { int case_var = 3*x + i; y += case_var - 1; break; }
name|EXPAND_4096_CASES
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

