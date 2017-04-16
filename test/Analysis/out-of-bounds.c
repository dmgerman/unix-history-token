begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -Wno-array-bounds -analyzer-checker=core,alpha.security.ArrayBoundV2,debug.ExprInspection -verify %s
end_comment

begin_function_decl
name|void
name|clang_analyzer_eval
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

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
comment|// expected-warning {{Out of bound memory access (accessed memory precedes memory block)}}
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
comment|// expected-warning{{Out of bound memory access}}
block|}
end_function

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
comment|// expected-warning{{Out of bound memory access}}
block|}
end_function

begin_function
name|void
name|test_assume_after_access
parameter_list|(
name|unsigned
name|long
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
name|x
index|]
operator|=
literal|1
expr_stmt|;
name|clang_analyzer_eval
argument_list|(
name|x
operator|<=
literal|99
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
block|}
end_function

begin_comment
comment|// Don't warn when indexing below the start of a symbolic region's whose
end_comment

begin_comment
comment|// base extent we don't know.
end_comment

begin_function_decl
name|int
modifier|*
name|get_symbolic
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test_index_below_symboloc
parameter_list|()
block|{
name|int
modifier|*
name|buf
init|=
name|get_symbolic
argument_list|()
decl_stmt|;
name|buf
index|[
operator|-
literal|1
index|]
operator|=
literal|0
expr_stmt|;
comment|// no-warning;
block|}
end_function

begin_function
name|void
name|test_incomplete_struct
parameter_list|()
block|{
specifier|extern
name|struct
name|incomplete
name|incomplete
decl_stmt|;
name|int
modifier|*
name|p
init|=
operator|(
name|int
operator|*
operator|)
operator|&
name|incomplete
decl_stmt|;
name|p
index|[
literal|1
index|]
operator|=
literal|42
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|test_extern_void
parameter_list|()
block|{
specifier|extern
name|void
name|v
decl_stmt|;
name|int
modifier|*
name|p
init|=
operator|(
name|int
operator|*
operator|)
operator|&
name|v
decl_stmt|;
name|p
index|[
literal|1
index|]
operator|=
literal|42
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|test_assume_after_access2
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|)
block|{
name|char
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|buf
index|[
name|x
index|]
operator|=
literal|1
expr_stmt|;
name|clang_analyzer_eval
argument_list|(
name|x
operator|<=
literal|99
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
block|}
end_function

end_unit

