begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fsyntax-only -verify -triple arm %s
end_comment

begin_function
name|void
name|string_literal
parameter_list|(
name|unsigned
name|v
parameter_list|)
block|{
name|__builtin_arm_wsr
argument_list|(
literal|0
argument_list|,
name|v
argument_list|)
expr_stmt|;
comment|// expected-error {{expression is not a string literal}}
block|}
end_function

begin_function
name|void
name|wsr_1
parameter_list|(
name|unsigned
name|v
parameter_list|)
block|{
name|__builtin_arm_wsr
argument_list|(
literal|"sysreg"
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|wsrp_1
parameter_list|(
name|void
modifier|*
name|v
parameter_list|)
block|{
name|__builtin_arm_wsrp
argument_list|(
literal|"sysreg"
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|wsr64_1
parameter_list|(
name|unsigned
name|long
name|v
parameter_list|)
block|{
name|__builtin_arm_wsr64
argument_list|(
literal|"sysreg"
argument_list|,
name|v
argument_list|)
expr_stmt|;
comment|//expected-error {{invalid special register for builtin}}
block|}
end_function

begin_function
name|unsigned
name|rsr_1
parameter_list|()
block|{
return|return
name|__builtin_arm_rsr
argument_list|(
literal|"sysreg"
argument_list|)
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|rsrp_1
parameter_list|()
block|{
return|return
name|__builtin_arm_rsrp
argument_list|(
literal|"sysreg"
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|rsr64_1
parameter_list|()
block|{
return|return
name|__builtin_arm_rsr64
argument_list|(
literal|"sysreg"
argument_list|)
return|;
comment|//expected-error {{invalid special register for builtin}}
block|}
end_function

begin_function
name|void
name|wsr_2
parameter_list|(
name|unsigned
name|v
parameter_list|)
block|{
name|__builtin_arm_wsr
argument_list|(
literal|"cp0:1:c2:c3:4"
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|wsrp_2
parameter_list|(
name|void
modifier|*
name|v
parameter_list|)
block|{
name|__builtin_arm_wsrp
argument_list|(
literal|"cp0:1:c2:c3:4"
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|wsr64_2
parameter_list|(
name|unsigned
name|long
name|v
parameter_list|)
block|{
name|__builtin_arm_wsr64
argument_list|(
literal|"cp0:1:c2:c3:4"
argument_list|,
name|v
argument_list|)
expr_stmt|;
comment|//expected-error {{invalid special register for builtin}}
block|}
end_function

begin_function
name|unsigned
name|rsr_2
parameter_list|()
block|{
return|return
name|__builtin_arm_rsr
argument_list|(
literal|"cp0:1:c15:c15:4"
argument_list|)
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|rsrp_2
parameter_list|()
block|{
return|return
name|__builtin_arm_rsrp
argument_list|(
literal|"cp0:1:c2:c3:4"
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|rsr64_2
parameter_list|()
block|{
return|return
name|__builtin_arm_rsr64
argument_list|(
literal|"cp0:1:c2:c3:4"
argument_list|)
return|;
comment|//expected-error {{invalid special register for builtin}}
block|}
end_function

begin_function
name|void
name|wsr_3
parameter_list|(
name|unsigned
name|v
parameter_list|)
block|{
name|__builtin_arm_wsr
argument_list|(
literal|"cp0:1:c2"
argument_list|,
name|v
argument_list|)
expr_stmt|;
comment|//expected-error {{invalid special register for builtin}}
block|}
end_function

begin_function
name|void
name|wsrp_3
parameter_list|(
name|void
modifier|*
name|v
parameter_list|)
block|{
name|__builtin_arm_wsrp
argument_list|(
literal|"cp0:1:c2"
argument_list|,
name|v
argument_list|)
expr_stmt|;
comment|//expected-error {{invalid special register for builtin}}
block|}
end_function

begin_function
name|void
name|wsr64_3
parameter_list|(
name|unsigned
name|long
name|v
parameter_list|)
block|{
name|__builtin_arm_wsr64
argument_list|(
literal|"cp0:1:c2"
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|unsigned
name|rsr_3
parameter_list|()
block|{
return|return
name|__builtin_arm_rsr
argument_list|(
literal|"cp0:1:c2"
argument_list|)
return|;
comment|//expected-error {{invalid special register for builtin}}
block|}
end_function

begin_function
name|void
modifier|*
name|rsrp_3
parameter_list|()
block|{
return|return
name|__builtin_arm_rsrp
argument_list|(
literal|"cp0:1:c2"
argument_list|)
return|;
comment|//expected-error {{invalid special register for builtin}}
block|}
end_function

begin_function
name|unsigned
name|long
name|rsr64_3
parameter_list|()
block|{
return|return
name|__builtin_arm_rsr64
argument_list|(
literal|"cp0:1:c15"
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|rsr_4
parameter_list|()
block|{
return|return
name|__builtin_arm_rsr
argument_list|(
literal|"0:1:2:3:4"
argument_list|)
return|;
comment|//expected-error {{invalid special register for builtin}}
block|}
end_function

begin_function
name|unsigned
name|rsr_5
parameter_list|()
block|{
return|return
name|__builtin_arm_rsr
argument_list|(
literal|"cp0:1:c2:c3:8"
argument_list|)
return|;
comment|//expected-error {{invalid special register for builtin}}
block|}
end_function

begin_function
name|unsigned
name|rsr_6
parameter_list|()
block|{
return|return
name|__builtin_arm_rsr
argument_list|(
literal|"cp0:8:c1:c2:3"
argument_list|)
return|;
comment|//expected-error {{invalid special register for builtin}}
block|}
end_function

begin_function
name|unsigned
name|rsr_7
parameter_list|()
block|{
return|return
name|__builtin_arm_rsr
argument_list|(
literal|"cp0:1:c16:c16:2"
argument_list|)
return|;
comment|//expected-error {{invalid special register for builtin}}
block|}
end_function

begin_function
name|void
modifier|*
name|rsrp_4
parameter_list|()
block|{
return|return
name|__builtin_arm_rsrp
argument_list|(
literal|"0:1:2:3:4"
argument_list|)
return|;
comment|//expected-error {{invalid special register for builtin}}
block|}
end_function

begin_function
name|unsigned
name|long
name|rsr64_4
parameter_list|()
block|{
return|return
name|__builtin_arm_rsr64
argument_list|(
literal|"0:1:2"
argument_list|)
return|;
comment|//expected-error {{invalid special register for builtin}}
block|}
end_function

begin_function
name|unsigned
name|long
name|rsr64_5
parameter_list|()
block|{
return|return
name|__builtin_arm_rsr64
argument_list|(
literal|"cp0:8:c1"
argument_list|)
return|;
comment|//expected-error {{invalid special register for builtin}}
block|}
end_function

begin_function
name|unsigned
name|long
name|rsr64_6
parameter_list|()
block|{
return|return
name|__builtin_arm_rsr64
argument_list|(
literal|"cp0:1:c16"
argument_list|)
return|;
comment|//expected-error {{invalid special register for builtin}}
block|}
end_function

end_unit

