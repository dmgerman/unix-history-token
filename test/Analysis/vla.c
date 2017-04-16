begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -verify %s
end_comment

begin_comment
comment|// Zero-sized VLAs.
end_comment

begin_function
name|void
name|check_zero_sized_VLA
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
condition|)
return|return;
name|int
name|vla
index|[
name|x
index|]
decl_stmt|;
comment|// expected-warning{{Declared variable-length array (VLA) has zero size}}
block|}
end_function

begin_function
name|void
name|check_uninit_sized_VLA
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|int
name|vla
index|[
name|x
index|]
decl_stmt|;
comment|// expected-warning{{Declared variable-length array (VLA) uses a garbage value as its size}}
block|}
end_function

begin_comment
comment|// Negative VLAs.
end_comment

begin_function
specifier|static
name|void
name|vla_allocate_signed
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|vla
index|[
name|x
index|]
decl_stmt|;
comment|// expected-warning{{Declared variable-length array (VLA) has negative size}}
block|}
end_function

begin_function
specifier|static
name|void
name|vla_allocate_unsigned
parameter_list|(
name|unsigned
name|int
name|x
parameter_list|)
block|{
name|int
name|vla
index|[
name|x
index|]
decl_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|check_negative_sized_VLA_1
parameter_list|()
block|{
name|vla_allocate_signed
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|check_negative_sized_VLA_2
parameter_list|()
block|{
name|vla_allocate_unsigned
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|check_negative_sized_VLA_3
parameter_list|()
block|{
name|int
name|x
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|vla
index|[
name|x
index|]
decl_stmt|;
comment|// expected-warning{{Declared variable-length array (VLA) has negative size}}
block|}
end_function

begin_function
name|void
name|check_negative_sized_VLA_4
parameter_list|()
block|{
name|unsigned
name|int
name|x
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|vla
index|[
name|x
index|]
decl_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|check_negative_sized_VLA_5
parameter_list|()
block|{
name|signed
name|char
name|x
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|vla
index|[
name|x
index|]
decl_stmt|;
comment|// expected-warning{{Declared variable-length array (VLA) has negative size}}
block|}
end_function

begin_function
name|void
name|check_negative_sized_VLA_6
parameter_list|()
block|{
name|unsigned
name|char
name|x
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|vla
index|[
name|x
index|]
decl_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|check_negative_sized_VLA_7
parameter_list|()
block|{
name|signed
name|char
name|x
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|vla
index|[
name|x
operator|+
literal|2
index|]
decl_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|check_negative_sized_VLA_8
parameter_list|()
block|{
name|signed
name|char
name|x
init|=
literal|1
decl_stmt|;
name|int
name|vla
index|[
name|x
operator|-
literal|2
index|]
decl_stmt|;
comment|// expected-warning{{Declared variable-length array (VLA) has negative size}}
block|}
end_function

begin_function
name|void
name|check_negative_sized_VLA_9
parameter_list|()
block|{
name|int
name|x
init|=
literal|1
decl_stmt|;
name|int
name|vla
index|[
name|x
index|]
decl_stmt|;
comment|// no-warning
block|}
end_function

begin_function
specifier|static
name|void
name|check_negative_sized_VLA_10_sub
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|vla
index|[
name|x
index|]
decl_stmt|;
comment|// expected-warning{{Declared variable-length array (VLA) has negative size}}
block|}
end_function

begin_function
name|void
name|check_negative_sized_VLA_10
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
operator|<
literal|0
condition|)
name|check_negative_sized_VLA_10_sub
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|check_negative_sized_VLA_11_sub
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|vla
index|[
name|x
index|]
decl_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|check_negative_sized_VLA_11
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
operator|>
literal|0
condition|)
name|check_negative_sized_VLA_11_sub
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

