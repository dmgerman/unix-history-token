begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=alpha.core.SizeofPtr -verify %s
end_comment

begin_struct
struct|struct
name|s
block|{ }
struct|;
end_struct

begin_function
name|int
name|f
parameter_list|(
name|struct
name|s
modifier|*
name|p
parameter_list|)
block|{
return|return
sizeof|sizeof
argument_list|(
name|p
argument_list|)
return|;
comment|// expected-warning{{The code calls sizeof() on a pointer type. This can produce an unexpected result}}
block|}
end_function

end_unit

