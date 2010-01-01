begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// C DR #316, PR 3626.
end_comment

begin_function
name|void
name|f0
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|;
block|{}
end_function

begin_function
name|void
name|t0
parameter_list|(
name|void
parameter_list|)
block|{
name|f0
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{too few arguments}}
block|}
end_function

begin_function
name|void
name|f1
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{}
end_function

begin_function
name|void
name|t1
parameter_list|(
name|void
parameter_list|)
block|{
name|f1
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// expected-warning{{too many arguments}}
block|}
end_function

begin_function_decl
name|void
name|f2
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_function
name|void
name|f2
parameter_list|(
name|x
parameter_list|)
name|float
name|x
decl_stmt|;
block|{ }
end_function

begin_comment
comment|// expected-warning{{promoted type 'double' of K&R function parameter is not compatible with the parameter type 'float' declared in a previous prototype}}
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|f3
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function
name|f3
name|t3
parameter_list|(
name|int
name|b
parameter_list|)
block|{
return|return
name|b
condition|?
name|f0
else|:
name|f1
return|;
block|}
end_function

begin_comment
comment|// okay
end_comment

end_unit

