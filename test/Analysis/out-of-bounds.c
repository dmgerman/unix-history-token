begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Wno-array-bounds -analyze -analyzer-check-objc-mem -analyzer-check-buffer-overflows -verify %s
end_comment

begin_comment
comment|// Tests doing an out-of-bounds access after the end of an array using:
end_comment

begin_comment
comment|// - constant integer index
end_comment

begin_comment
comment|// - constant integer size for buffer
end_comment

begin_function
name|void
name|test1
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|buf
index|[
literal|100
index|]
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Out of bound memory access}}
block|}
end_function

begin_function
name|void
name|test1_ok
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|buf
index|[
literal|99
index|]
operator|=
literal|1
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
specifier|const
name|char
name|test1_strings_underrun
parameter_list|(
name|int
name|x
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|mystr
init|=
literal|"mary had a little lamb"
decl_stmt|;
return|return
name|mystr
index|[
operator|-
literal|1
index|]
return|;
comment|// expected-warning{{Out of bound memory access}}
block|}
end_function

begin_function
specifier|const
name|char
name|test1_strings_overrun
parameter_list|(
name|int
name|x
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|mystr
init|=
literal|"mary had a little lamb"
decl_stmt|;
return|return
name|mystr
index|[
literal|1000
index|]
return|;
comment|// expected-warning{{Out of bound memory access}}
block|}
end_function

begin_function
specifier|const
name|char
name|test1_strings_ok
parameter_list|(
name|int
name|x
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|mystr
init|=
literal|"mary had a little lamb"
decl_stmt|;
return|return
name|mystr
index|[
literal|5
index|]
return|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Tests doing an out-of-bounds access after the end of an array using:
end_comment

begin_comment
comment|// - indirect pointer to buffer
end_comment

begin_comment
comment|// - constant integer index
end_comment

begin_comment
comment|// - constant integer size for buffer
end_comment

begin_function
name|void
name|test1_ptr
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|int
modifier|*
name|p
init|=
name|buf
decl_stmt|;
name|p
index|[
literal|101
index|]
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Out of bound memory access}}
block|}
end_function

begin_function
name|void
name|test1_ptr_ok
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|int
modifier|*
name|p
init|=
name|buf
decl_stmt|;
name|p
index|[
literal|99
index|]
operator|=
literal|1
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Tests doing an out-of-bounds access before the start of an array using:
end_comment

begin_comment
comment|// - indirect pointer to buffer, manipulated using simple pointer arithmetic
end_comment

begin_comment
comment|// - constant integer index
end_comment

begin_comment
comment|// - constant integer size for buffer
end_comment

begin_function
name|void
name|test1_ptr_arith
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|int
modifier|*
name|p
init|=
name|buf
decl_stmt|;
name|p
operator|=
name|p
operator|+
literal|100
expr_stmt|;
name|p
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Out of bound memory access}}
block|}
end_function

begin_function
name|void
name|test1_ptr_arith_ok
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|int
modifier|*
name|p
init|=
name|buf
decl_stmt|;
name|p
operator|=
name|p
operator|+
literal|99
expr_stmt|;
name|p
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|test1_ptr_arith_bad
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|int
modifier|*
name|p
init|=
name|buf
decl_stmt|;
name|p
operator|=
name|p
operator|+
literal|99
expr_stmt|;
name|p
index|[
literal|1
index|]
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Out of bound memory access}}
block|}
end_function

begin_function
name|void
name|test1_ptr_arith_ok2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|int
modifier|*
name|p
init|=
name|buf
decl_stmt|;
name|p
operator|=
name|p
operator|+
literal|99
expr_stmt|;
name|p
index|[
operator|-
literal|1
index|]
operator|=
literal|1
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Tests doing an out-of-bounds access before the start of an array using:
end_comment

begin_comment
comment|// - constant integer index
end_comment

begin_comment
comment|// - constant integer size for buffer
end_comment

begin_function
name|void
name|test2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|buf
index|[
operator|-
literal|1
index|]
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Out of bound memory access}}
block|}
end_function

begin_comment
comment|// Tests doing an out-of-bounds access before the start of an array using:
end_comment

begin_comment
comment|// - indirect pointer to buffer
end_comment

begin_comment
comment|// - constant integer index
end_comment

begin_comment
comment|// - constant integer size for buffer
end_comment

begin_function
name|void
name|test2_ptr
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|int
modifier|*
name|p
init|=
name|buf
decl_stmt|;
name|p
index|[
operator|-
literal|1
index|]
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Out of bound memory access}}
block|}
end_function

begin_comment
comment|// ** FIXME ** Doesn't work yet because we don't support pointer arithmetic.
end_comment

begin_comment
comment|// Tests doing an out-of-bounds access before the start of an array using:
end_comment

begin_comment
comment|// - indirect pointer to buffer, manipulated using simple pointer arithmetic
end_comment

begin_comment
comment|// - constant integer index
end_comment

begin_comment
comment|// - constant integer size for buffer
end_comment

begin_function
name|void
name|test2_ptr_arith
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|int
modifier|*
name|p
init|=
name|buf
decl_stmt|;
operator|--
name|p
expr_stmt|;
name|p
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Tests doing an out-of-bounds access before the start of a multi-dimensional
end_comment

begin_comment
comment|// array using:
end_comment

begin_comment
comment|// - constant integer indices
end_comment

begin_comment
comment|// - constant integer sizes for the array
end_comment

begin_function
name|void
name|test2_multi
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|buf
index|[
literal|100
index|]
index|[
literal|100
index|]
decl_stmt|;
name|buf
index|[
literal|0
index|]
index|[
operator|-
literal|1
index|]
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Out of bound memory access}}
block|}
end_function

begin_comment
comment|// Tests doing an out-of-bounds access before the start of a multi-dimensional
end_comment

begin_comment
comment|// array using:
end_comment

begin_comment
comment|// - constant integer indices
end_comment

begin_comment
comment|// - constant integer sizes for the array
end_comment

begin_function
name|void
name|test2_multi_b
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|buf
index|[
literal|100
index|]
index|[
literal|100
index|]
decl_stmt|;
name|buf
index|[
operator|-
literal|1
index|]
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Out of bound memory access}}
block|}
end_function

begin_function
name|void
name|test2_multi_ok
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|buf
index|[
literal|100
index|]
index|[
literal|100
index|]
decl_stmt|;
name|buf
index|[
literal|0
index|]
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// *** FIXME ***
end_comment

begin_comment
comment|// We don't get a warning here yet because our symbolic constraint solving
end_comment

begin_comment
comment|// doesn't handle:  (symbol * constant)< constant
end_comment

begin_function
name|void
name|test3
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|buf
index|[
literal|100
index|]
decl_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
name|buf
index|[
name|x
index|]
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|// *** FIXME ***
end_comment

begin_comment
comment|// We don't get a warning here yet because our symbolic constraint solving
end_comment

begin_comment
comment|// doesn't handle:  (symbol * constant)< constant
end_comment

begin_function
name|void
name|test4
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|buf
index|[
literal|100
index|]
decl_stmt|;
if|if
condition|(
name|x
operator|>
literal|99
condition|)
name|buf
index|[
name|x
index|]
operator|=
literal|1
expr_stmt|;
block|}
end_function

end_unit

