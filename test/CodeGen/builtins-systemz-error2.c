begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: systemz-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple s390x-ibm-linux -S -emit-llvm %s -verify -o -
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|char
name|v16i8
typedef|;
end_typedef

begin_function
name|v16i8
name|f0
parameter_list|(
name|v16i8
name|a
parameter_list|,
name|v16i8
name|b
parameter_list|)
block|{
name|__builtin_tbegin
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{'__builtin_tbegin' needs target feature transactional-execution}}
name|v16i8
name|tmp
init|=
name|__builtin_s390_vaq
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
decl_stmt|;
comment|// expected-error {{'__builtin_s390_vaq' needs target feature vector}}
return|return
name|tmp
return|;
block|}
end_function

end_unit

