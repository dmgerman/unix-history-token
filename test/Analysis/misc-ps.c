begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -analyze -disable-free -analyzer-eagerly-assume -analyzer-checker=core -analyzer-checker=deadcode -verify %s
end_comment

begin_function_decl
name|unsigned
name|long
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|size_rdar9373039
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|rdar9373039
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|int
name|j
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size_rdar9373039
condition|;
operator|++
name|i
control|)
name|x
operator|=
literal|1
expr_stmt|;
comment|// strlen doesn't invalidate the value of 'size_rdar9373039'.
name|int
name|extra
init|=
operator|(
literal|2
operator|+
name|strlen
argument_list|(
literal|"Clang"
argument_list|)
operator|+
operator|(
operator|(
literal|4
operator|-
operator|(
call|(
name|unsigned
name|int
call|)
argument_list|(
literal|2
operator|+
name|strlen
argument_list|(
literal|"Clang"
argument_list|)
argument_list|)
operator|%
literal|4
operator|)
operator|)
operator|%
literal|4
operator|)
operator|)
operator|+
operator|(
literal|2
operator|+
name|strlen
argument_list|(
literal|"1.0"
argument_list|)
operator|+
operator|(
operator|(
literal|4
operator|-
operator|(
call|(
name|unsigned
name|int
call|)
argument_list|(
literal|2
operator|+
name|strlen
argument_list|(
literal|"1.0"
argument_list|)
argument_list|)
operator|%
literal|4
operator|)
operator|)
operator|%
literal|4
operator|)
operator|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size_rdar9373039
condition|;
operator|++
name|i
control|)
name|j
operator|+=
name|x
expr_stmt|;
comment|// no-warning
return|return
name|j
return|;
block|}
end_function

begin_function_decl
name|int
name|foo_rdar9373039
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|rdar93730392
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|int
name|j
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size_rdar9373039
condition|;
operator|++
name|i
control|)
name|x
operator|=
literal|1
expr_stmt|;
name|int
name|extra
init|=
operator|(
literal|2
operator|+
name|foo_rdar9373039
argument_list|(
literal|"Clang"
argument_list|)
operator|+
operator|(
operator|(
literal|4
operator|-
operator|(
call|(
name|unsigned
name|int
call|)
argument_list|(
literal|2
operator|+
name|foo_rdar9373039
argument_list|(
literal|"Clang"
argument_list|)
argument_list|)
operator|%
literal|4
operator|)
operator|)
operator|%
literal|4
operator|)
operator|)
operator|+
operator|(
literal|2
operator|+
name|foo_rdar9373039
argument_list|(
literal|"1.0"
argument_list|)
operator|+
operator|(
operator|(
literal|4
operator|-
operator|(
call|(
name|unsigned
name|int
call|)
argument_list|(
literal|2
operator|+
name|foo_rdar9373039
argument_list|(
literal|"1.0"
argument_list|)
argument_list|)
operator|%
literal|4
operator|)
operator|)
operator|%
literal|4
operator|)
operator|)
decl_stmt|;
comment|// expected-warning {{never read}}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size_rdar9373039
condition|;
operator|++
name|i
control|)
name|j
operator|+=
name|x
expr_stmt|;
comment|// expected-warning {{garbage}}
return|return
name|j
return|;
block|}
end_function

begin_function
name|int
name|PR8962
parameter_list|(
name|int
modifier|*
name|t
parameter_list|)
block|{
comment|// This should look through the __extension__ no-op.
if|if
condition|(
name|__extension__
argument_list|(
name|t
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
operator|*
name|t
return|;
comment|// expected-warning {{null pointer}}
block|}
end_function

begin_function
name|int
name|PR8962_b
parameter_list|(
name|int
modifier|*
name|t
parameter_list|)
block|{
comment|// This should still ignore the nested casts
comment|// which aren't handled by a single IgnoreParens()
if|if
condition|(
operator|(
call|(
name|int
call|)
argument_list|(
operator|(
name|int
operator|)
name|t
argument_list|)
operator|)
condition|)
return|return
literal|0
return|;
return|return
operator|*
name|t
return|;
comment|// expected-warning {{null pointer}}
block|}
end_function

begin_function
name|int
name|PR8962_c
parameter_list|(
name|int
modifier|*
name|t
parameter_list|)
block|{
comment|// If the last element in a StmtExpr was a ParenExpr, it's still live
if|if
condition|(
operator|(
block|{
operator|(
name|t
condition|?
operator|(
name|_Bool
operator|)
literal|0
else|:
operator|(
name|_Bool
operator|)
literal|1
operator|)
expr_stmt|;
block|}
block|)
end_function

begin_return
unit|)
return|return
literal|0
return|;
end_return

begin_return
return|return
operator|*
name|t
return|;
end_return

begin_comment
comment|// no-warning
end_comment

begin_macro
unit|}  int
name|PR8962_d
argument_list|(
argument|int *t
argument_list|)
end_macro

begin_block
block|{
comment|// If the last element in a StmtExpr is an __extension__, it's still live
if|if
condition|(
operator|(
block|{
name|__extension__
argument_list|(
name|t
condition|?
operator|(
name|_Bool
operator|)
literal|0
else|:
operator|(
name|_Bool
operator|)
literal|1
argument_list|)
expr_stmt|;
block|}
block|)
end_block

begin_return
unit|)
return|return
literal|0
return|;
end_return

begin_return
return|return
operator|*
name|t
return|;
end_return

begin_comment
comment|// no-warning
end_comment

begin_macro
unit|}  int
name|PR8962_e
argument_list|(
argument|int *t
argument_list|)
end_macro

begin_block
block|{
comment|// Redundant casts can mess things up!
comment|// Environment used to skip through NoOp casts, but LiveVariables didn't!
if|if
condition|(
operator|(
block|{
operator|(
name|t
condition|?
call|(
name|int
call|)
argument_list|(
name|int
argument_list|)
literal|0L
else|:
call|(
name|int
call|)
argument_list|(
name|int
argument_list|)
literal|1L
operator|)
expr_stmt|;
block|}
block|)
end_block

begin_return
unit|)
return|return
literal|0
return|;
end_return

begin_return
return|return
operator|*
name|t
return|;
end_return

begin_comment
comment|// no-warning
end_comment

begin_macro
unit|}  int
name|PR8962_f
argument_list|(
argument|int *t
argument_list|)
end_macro

begin_block
block|{
comment|// The StmtExpr isn't a block-level expression here,
comment|// the __extension__ is. But the value should be attached to the StmtExpr
comment|// anyway. Make sure the block-level check is /before/ IgnoreParens.
if|if
condition|(
name|__extension__
argument_list|(
argument|{     _Bool r;     if (t) r =
literal|0
argument|;     else r =
literal|1
argument|;     r;   }
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
operator|*
name|t
return|;
comment|// no-warning
block|}
end_block

end_unit

