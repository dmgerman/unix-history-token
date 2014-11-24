begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple mips-none-linux-gnu -emit-llvm -w -o - %s | FileCheck --check-prefix=ALL --check-prefix=O32 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64-none-linux-gnu -emit-llvm -w -target-abi n32 -o - %s | FileCheck --check-prefix=ALL --check-prefix=N32 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64-none-linux-gnu -emit-llvm -w -o - %s | FileCheck --check-prefix=ALL --check-prefix=N64 %s
end_comment

begin_function
name|int
name|check_char
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|char
argument_list|)
return|;
comment|// ALL: ret i32 1
block|}
end_function

begin_function
name|int
name|check_short
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|short
argument_list|)
return|;
comment|// ALL: ret i32 2
block|}
end_function

begin_function
name|int
name|check_int
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|int
argument_list|)
return|;
comment|// ALL: ret i32 4
block|}
end_function

begin_function
name|int
name|check_long
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|long
argument_list|)
return|;
comment|// O32: ret i32 4
comment|// N32: ret i32 4
comment|// N64: ret i32 8
block|}
end_function

begin_function
name|int
name|check_longlong
parameter_list|()
block|{
return|return
expr|sizeof
operator|(
name|long
name|long
operator|)
return|;
comment|// ALL: ret i32 8
block|}
end_function

begin_function
name|int
name|check_fp16
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|__fp16
argument_list|)
return|;
comment|// ALL: ret i32 2
block|}
end_function

begin_function
name|int
name|check_float
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|float
argument_list|)
return|;
comment|// ALL: ret i32 4
block|}
end_function

begin_function
name|int
name|check_double
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|double
argument_list|)
return|;
comment|// ALL: ret i32 8
block|}
end_function

begin_function
name|int
name|check_longdouble
parameter_list|()
block|{
return|return
expr|sizeof
operator|(
name|long
name|double
operator|)
return|;
comment|// O32: ret i32 8
comment|// N32: ret i32 16
comment|// N64: ret i32 16
block|}
end_function

begin_function
name|int
name|check_floatComplex
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|float
specifier|_Complex
argument_list|)
return|;
comment|// ALL: ret i32 8
block|}
end_function

begin_function
name|int
name|check_doubleComplex
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|double
specifier|_Complex
argument_list|)
return|;
comment|// ALL: ret i32 16
block|}
end_function

begin_function
name|int
name|check_longdoubleComplex
parameter_list|()
block|{
return|return
expr|sizeof
operator|(
name|long
name|double
specifier|_Complex
operator|)
return|;
comment|// O32: ret i32 16
comment|// N32: ret i32 32
comment|// N64: ret i32 32
block|}
end_function

begin_function
name|int
name|check_bool
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|_Bool
argument_list|)
return|;
comment|// ALL: ret i32 1
block|}
end_function

begin_function
name|int
name|check_wchar
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|__WCHAR_TYPE__
argument_list|)
return|;
comment|// ALL: ret i32 4
block|}
end_function

begin_function
name|int
name|check_wchar_is_unsigned
parameter_list|()
block|{
return|return
operator|(
name|__WCHAR_TYPE__
operator|)
operator|-
literal|1
operator|>
operator|(
name|__WCHAR_TYPE__
operator|)
literal|0
return|;
comment|// ALL: ret i32 0
block|}
end_function

begin_function
name|int
name|check_ptr
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
return|;
comment|// O32: ret i32 4
comment|// N32: ret i32 4
comment|// N64: ret i32 8
block|}
end_function

end_unit

