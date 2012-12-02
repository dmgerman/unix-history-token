begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: mips-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips-unknown-linux-gnu -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
comment|// MIPS DSP Rev 1
name|int
name|a
init|=
literal|3
decl_stmt|;
name|__builtin_mips_wrdsp
argument_list|(
literal|2052
argument_list|,
name|a
argument_list|)
expr_stmt|;
comment|// expected-error{{argument to '__builtin_mips_wrdsp' must be a constant integer}}
name|__builtin_mips_rddsp
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// expected-error{{argument to '__builtin_mips_rddsp' must be a constant integer}}
name|__builtin_mips_wrdsp
argument_list|(
literal|2052
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error{{argument should be a value from 0 to 63}}
name|__builtin_mips_rddsp
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error{{argument should be a value from 0 to 63}}
name|__builtin_mips_wrdsp
argument_list|(
literal|2052
argument_list|,
literal|64
argument_list|)
expr_stmt|;
comment|// expected-error{{argument should be a value from 0 to 63}}
name|__builtin_mips_rddsp
argument_list|(
literal|64
argument_list|)
expr_stmt|;
comment|// expected-error{{argument should be a value from 0 to 63}}
comment|// MIPS DSP Rev 2
name|__builtin_mips_append
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|a
argument_list|)
expr_stmt|;
comment|// expected-error{{argument to '__builtin_mips_append' must be a constant integer}}
name|__builtin_mips_balign
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|a
argument_list|)
expr_stmt|;
comment|// expected-error{{argument to '__builtin_mips_balign' must be a constant integer}}
name|__builtin_mips_precr_sra_ph_w
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|a
argument_list|)
expr_stmt|;
comment|// expected-error{{argument to '__builtin_mips_precr_sra_ph_w' must be a constant integer}}
name|__builtin_mips_precr_sra_r_ph_w
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|a
argument_list|)
expr_stmt|;
comment|// expected-error{{argument to '__builtin_mips_precr_sra_r_ph_w' must be a constant integer}}
name|__builtin_mips_prepend
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|a
argument_list|)
expr_stmt|;
comment|// expected-error{{argument to '__builtin_mips_prepend' must be a constant integer}}
name|__builtin_mips_append
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error{{argument should be a value from 0 to 31}}
name|__builtin_mips_append
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|32
argument_list|)
expr_stmt|;
comment|// expected-error{{argument should be a value from 0 to 31}}
name|__builtin_mips_balign
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error{{argument should be a value from 0 to 3}}
name|__builtin_mips_balign
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-error{{argument should be a value from 0 to 3}}
name|__builtin_mips_precr_sra_ph_w
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error{{argument should be a value from 0 to 31}}
name|__builtin_mips_precr_sra_ph_w
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|32
argument_list|)
expr_stmt|;
comment|// expected-error{{argument should be a value from 0 to 31}}
name|__builtin_mips_precr_sra_r_ph_w
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error{{argument should be a value from 0 to 31}}
name|__builtin_mips_precr_sra_r_ph_w
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|32
argument_list|)
expr_stmt|;
comment|// expected-error{{argument should be a value from 0 to 31}}
name|__builtin_mips_prepend
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error{{argument should be a value from 0 to 31}}
name|__builtin_mips_prepend
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error{{argument should be a value from 0 to 31}}
block|}
end_function

end_unit

