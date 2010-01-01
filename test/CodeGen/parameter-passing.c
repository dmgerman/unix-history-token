begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check the various ways in which the three classes of values
end_comment

begin_comment
comment|// (scalar, complex, aggregate) interact with parameter passing
end_comment

begin_comment
comment|// (function entry, function return, call argument, call result).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// We also check _Bool and empty structures, as these can have annoying
end_comment

begin_comment
comment|// corner cases.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-unknown-unknown -O3 -emit-llvm -o %t
end_comment

begin_comment
comment|// RUN: not grep '@g0' %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-unknown-unknown -O3 -emit-llvm -o %t
end_comment

begin_comment
comment|// RUN: not grep '@g0' %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple powerpc-unknown-unknown -O3 -emit-llvm -o %t
end_comment

begin_comment
comment|// RUN: not grep '@g0' %t
end_comment

begin_typedef
typedef|typedef
name|_Bool
name|BoolTy
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ScalarTy
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|_Complex
name|int
name|ComplexTy
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
block|}
name|AggrTy
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|a
index|[
literal|0
index|]
decl_stmt|;
block|}
name|EmptyTy
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|int
name|result
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|BoolTy
name|bool_id
parameter_list|(
name|BoolTy
name|a
parameter_list|)
block|{
return|return
name|a
return|;
block|}
end_function

begin_function
specifier|static
name|AggrTy
name|aggr_id
parameter_list|(
name|AggrTy
name|a
parameter_list|)
block|{
return|return
name|a
return|;
block|}
end_function

begin_function
specifier|static
name|EmptyTy
name|empty_id
parameter_list|(
name|EmptyTy
name|a
parameter_list|)
block|{
return|return
name|a
return|;
block|}
end_function

begin_function
specifier|static
name|ScalarTy
name|scalar_id
parameter_list|(
name|ScalarTy
name|a
parameter_list|)
block|{
return|return
name|a
return|;
block|}
end_function

begin_function
specifier|static
name|ComplexTy
name|complex_id
parameter_list|(
name|ComplexTy
name|a
parameter_list|)
block|{
return|return
name|a
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|bool_mul
parameter_list|(
name|BoolTy
name|a
parameter_list|)
block|{
name|result
operator|*=
name|a
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|aggr_mul
parameter_list|(
name|AggrTy
name|a
parameter_list|)
block|{
name|result
operator|*=
name|a
operator|.
name|a
operator|*
name|a
operator|.
name|b
operator|*
name|a
operator|.
name|c
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|empty_mul
parameter_list|(
name|EmptyTy
name|a
parameter_list|)
block|{
name|result
operator|*=
literal|53
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|scalar_mul
parameter_list|(
name|ScalarTy
name|a
parameter_list|)
block|{
name|result
operator|*=
name|a
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|complex_mul
parameter_list|(
name|ComplexTy
name|a
parameter_list|)
block|{
name|result
operator|*=
name|__real
name|a
operator|*
name|__imag
name|a
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|g0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f0
parameter_list|(
name|void
parameter_list|)
block|{
name|result
operator|=
literal|1
expr_stmt|;
name|bool_mul
argument_list|(
name|bool_id
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|aggr_mul
argument_list|(
name|aggr_id
argument_list|(
operator|(
name|AggrTy
operator|)
block|{
literal|2
block|,
literal|3
block|,
literal|5
block|}
argument_list|)
argument_list|)
expr_stmt|;
name|empty_mul
argument_list|(
name|empty_id
argument_list|(
operator|(
name|EmptyTy
operator|)
block|{}
argument_list|)
argument_list|)
expr_stmt|;
name|scalar_mul
argument_list|(
name|scalar_id
argument_list|(
literal|7
argument_list|)
argument_list|)
expr_stmt|;
name|complex_mul
argument_list|(
name|complex_id
argument_list|(
literal|11 + 13i
argument_list|)
argument_list|)
expr_stmt|;
comment|// This call should be eliminated.
if|if
condition|(
name|result
operator|!=
literal|2
operator|*
literal|3
operator|*
literal|5
operator|*
literal|7
operator|*
literal|11
operator|*
literal|13
operator|*
literal|53
condition|)
name|g0
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

