begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|EXPAND_2_BRANCHES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|BRANCH(i, x, y);              BRANCH(i + 1, x, y);
end_define

begin_define
define|#
directive|define
name|EXPAND_4_BRANCHES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_2_BRANCHES(i, x, y)    EXPAND_2_BRANCHES(i + 2, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_8_BRANCHES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_4_BRANCHES(i, x, y)    EXPAND_4_BRANCHES(i + 4, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_16_BRANCHES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_8_BRANCHES(i, x, y)    EXPAND_8_BRANCHES(i + 8, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_32_BRANCHES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_16_BRANCHES(i, x, y)   EXPAND_16_BRANCHES(i + 16, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_64_BRANCHES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_32_BRANCHES(i, x, y)   EXPAND_32_BRANCHES(i + 32, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_128_BRANCHES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_64_BRANCHES(i, x, y)   EXPAND_64_BRANCHES(i + 64, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_256_BRANCHES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_128_BRANCHES(i, x, y)  EXPAND_128_BRANCHES(i + 128, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_512_BRANCHES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_256_BRANCHES(i, x, y)  EXPAND_256_BRANCHES(i + 256, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_1024_BRANCHES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_512_BRANCHES(i, x, y)  EXPAND_512_BRANCHES(i + 512, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_2048_BRANCHES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_1024_BRANCHES(i, x, y) EXPAND_1024_BRANCHES(i + 1024, x, y)
end_define

begin_define
define|#
directive|define
name|EXPAND_4096_BRANCHES
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|EXPAND_2048_BRANCHES(i, x, y) EXPAND_2048_BRANCHES(i + 2048, x, y)
end_define

begin_function
name|unsigned
name|cfg_long_chain_multiple_exit
parameter_list|(
name|unsigned
name|x
parameter_list|)
block|{
name|unsigned
name|y
init|=
literal|0
decl_stmt|;
define|#
directive|define
name|BRANCH
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|if (((x % 13171) + ++y)< i) { int var = x / 13171 + y; return var; }
name|EXPAND_4096_BRANCHES
argument_list|(
literal|1
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|BRANCH
return|return
literal|42
return|;
block|}
end_function

end_unit

