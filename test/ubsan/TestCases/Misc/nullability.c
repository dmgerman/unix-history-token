begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -w -fsanitize=nullability-arg,nullability-assign,nullability-return %s -O3 -o %t
end_comment

begin_comment
comment|// RUN: %run %t foo 2>&1 | count 0
end_comment

begin_comment
comment|// RUN: %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: nullability.c:[[@LINE+2]]:51: runtime error: null pointer returned from function declared to never return null
end_comment

begin_comment
comment|// CHECK-NEXT: nullability.c:[[@LINE+1]]:6: note: _Nonnull return type annotation specified here
end_comment

begin_function
name|int
modifier|*
name|_Nonnull
name|nonnull_retval1
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
return|return
name|p
return|;
block|}
end_function

begin_comment
comment|// CHECK: nullability.c:1001:22: runtime error: null pointer passed as argument 2, which is declared to never be null
end_comment

begin_comment
comment|// CHECK-NEXT: nullability.c:[[@LINE+1]]:56: note: _Nonnull type annotation specified here
end_comment

begin_function
name|int
modifier|*
name|_Nonnull
name|nonnull_retval2
parameter_list|(
name|int
modifier|*
name|_Nonnull
name|arg1
parameter_list|,
name|int
modifier|*
name|_Nonnull
name|arg2
parameter_list|,
name|int
modifier|*
name|_Nullable
name|arg3
parameter_list|,
name|int
modifier|*
name|arg4
parameter_list|,
name|int
name|arg5
parameter_list|,
modifier|...
parameter_list|)
block|{
return|return
name|arg1
return|;
block|}
end_function

begin_comment
comment|// CHECK: nullability.c:1002:15: runtime error: null pointer passed as argument 1, which is declared to never be null
end_comment

begin_comment
comment|// CHECK-NEXT: nullability.c:[[@LINE+1]]:23: note: _Nonnull type annotation specified here
end_comment

begin_function
name|void
name|nonnull_arg
parameter_list|(
name|int
modifier|*
name|_Nonnull
name|p
parameter_list|)
block|{}
end_function

begin_function
name|void
name|nonnull_assign1
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|int
modifier|*
name|_Nonnull
name|local
decl_stmt|;
comment|// CHECK: nullability.c:[[@LINE+1]]:9: runtime error: _Nonnull binding to null pointer of type 'int * _Nonnull'
name|local
operator|=
name|p
expr_stmt|;
block|}
end_function

begin_function
name|void
name|nonnull_assign2
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|int
modifier|*
name|_Nonnull
name|arr
index|[
literal|1
index|]
decl_stmt|;
comment|// CHECK: nullability.c:[[@LINE+1]]:10: runtime error: _Nonnull binding to null pointer of type 'int * _Nonnull'
name|arr
index|[
literal|0
index|]
operator|=
name|p
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|S1
block|{
name|int
modifier|*
name|_Nonnull
name|mptr
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|nonnull_assign3
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|struct
name|S1
name|s
decl_stmt|;
comment|// CHECK: nullability.c:[[@LINE+1]]:10: runtime error: _Nonnull binding to null pointer of type 'int * _Nonnull'
name|s
operator|.
name|mptr
operator|=
name|p
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: nullability.c:[[@LINE+1]]:52: runtime error: _Nonnull binding to null pointer of type 'int * _Nonnull'
end_comment

begin_function
name|void
name|nonnull_init1
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|int
modifier|*
name|_Nonnull
name|local
init|=
name|p
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: nullability.c:[[@LINE+2]]:53: runtime error: _Nonnull binding to null pointer of type 'int * _Nonnull'
end_comment

begin_comment
comment|// CHECK: nullability.c:[[@LINE+1]]:56: runtime error: _Nonnull binding to null pointer of type 'int * _Nonnull'
end_comment

begin_function
name|void
name|nonnull_init2
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|int
modifier|*
name|_Nonnull
name|arr
index|[]
init|=
block|{
name|p
block|,
name|p
block|}
decl_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
modifier|*
name|p
init|=
operator|(
name|argc
operator|>
literal|1
operator|)
condition|?
operator|&
name|argc
else|:
operator|(
operator|(
name|int
operator|*
operator|)
literal|0
operator|)
decl_stmt|;
line|#
directive|line
number|1000
name|nonnull_retval1
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|nonnull_retval2
argument_list|(
name|p
argument_list|,
name|p
argument_list|,
name|p
argument_list|,
name|p
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|nonnull_arg
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|nonnull_assign1
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|nonnull_assign2
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|nonnull_assign3
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|nonnull_init1
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|nonnull_init2
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

