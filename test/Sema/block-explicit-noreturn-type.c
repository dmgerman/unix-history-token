begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -fblocks
end_comment

begin_comment
comment|// rdar://10466373
end_comment

begin_typedef
typedef|typedef
name|short
name|SHORT
typedef|;
end_typedef

begin_function
name|void
name|f0
parameter_list|()
block|{
operator|(
name|void
operator|)
lambda|^
block|{
if|if
condition|(
literal|1
condition|)
return|return
operator|(
name|float
operator|)
literal|1.0
return|;
elseif|else
if|if
condition|(
literal|2
condition|)
return|return
operator|(
name|double
operator|)
literal|2.0
return|;
comment|// expected-error {{return type 'double' must match previous return type 'float' when block literal has}}
else|else
return|return
operator|(
name|SHORT
operator|)
literal|3
return|;
comment|// expected-error {{return type 'SHORT' (aka 'short') must match previous return type 'float' when}}
block|}
expr_stmt|;
block|}
end_function

end_unit

