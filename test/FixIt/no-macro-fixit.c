begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -pedantic -fixit -x c %s
end_comment

begin_comment
comment|// rdar://9091893
end_comment

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
value|__builtin_va_arg(ap, type)
end_define

begin_typedef
typedef|typedef
name|__builtin_va_list
name|va_list
typedef|;
end_typedef

begin_function
name|void
name|myFunc
parameter_list|()
block|{
name|va_list
name|values
decl_stmt|;
name|int
name|value
decl_stmt|;
while|while
condition|(
name|value
operator|=
name|va_arg
argument_list|(
name|values
argument_list|,
name|int
argument_list|)
condition|)
block|{
comment|// expected-warning {{using the result of an assignment as a condition without parentheses}} \
comment|// expected-note {{use '==' to turn this assignment into an equality comparison}} \
comment|// expected-note {{place parentheses around the assignment to silence this warning}}
block|}
block|}
end_function

end_unit

