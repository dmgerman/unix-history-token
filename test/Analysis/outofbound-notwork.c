begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -Wno-array-bounds -analyzer-checker=core,alpha.security.ArrayBound -analyzer-store=region -verify %s
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// Once we better handle modeling of sizes of VLAs, we can pull this back
end_comment

begin_comment
comment|// into outofbound.c.
end_comment

begin_function
name|void
name|sizeof_vla
parameter_list|(
name|int
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
operator|==
literal|5
condition|)
block|{
name|char
name|x
index|[
name|a
index|]
decl_stmt|;
name|int
name|y
index|[
sizeof|sizeof
argument_list|(
name|x
argument_list|)
index|]
decl_stmt|;
name|y
index|[
literal|4
index|]
operator|=
literal|4
expr_stmt|;
comment|// no-warning
name|y
index|[
literal|5
index|]
operator|=
literal|5
expr_stmt|;
comment|// expected-warning{{out-of-bound}}
block|}
block|}
end_function

begin_function
name|void
name|sizeof_vla_2
parameter_list|(
name|int
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
operator|==
literal|5
condition|)
block|{
name|char
name|x
index|[
name|a
index|]
decl_stmt|;
name|int
name|y
index|[
sizeof|sizeof
argument_list|(
name|x
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|char
argument_list|)
index|]
decl_stmt|;
name|y
index|[
literal|4
index|]
operator|=
literal|4
expr_stmt|;
comment|// no-warning
name|y
index|[
literal|5
index|]
operator|=
literal|5
expr_stmt|;
comment|// expected-warning{{out-of-bound}}
block|}
block|}
end_function

begin_function
name|void
name|sizeof_vla_3
parameter_list|(
name|int
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
operator|==
literal|5
condition|)
block|{
name|char
name|x
index|[
name|a
index|]
decl_stmt|;
name|int
name|y
index|[
sizeof|sizeof
argument_list|(
operator|*
operator|&
operator|*
operator|&
operator|*
operator|&
name|x
argument_list|)
index|]
decl_stmt|;
name|y
index|[
literal|4
index|]
operator|=
literal|4
expr_stmt|;
comment|// no-warning
name|y
index|[
literal|5
index|]
operator|=
literal|5
expr_stmt|;
comment|// expected-warning{{out-of-bound}}
block|}
block|}
end_function

end_unit

