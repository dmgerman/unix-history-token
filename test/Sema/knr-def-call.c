begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-unknown -Wconversion -Wliteral-conversion -fsyntax-only -verify %s
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

begin_comment
comment|//<rdar://problem/8193107>
end_comment

begin_function
name|void
name|f4
parameter_list|()
block|{
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
block|}
end_function

begin_function
name|char
modifier|*
name|rindex
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
specifier|register
name|char
modifier|*
name|s
decl_stmt|,
name|c
decl_stmt|;
comment|// expected-warning{{promoted type 'char *' of K&R function parameter is not compatible with the parameter type 'const char *' declared in a previous prototype}}
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// PR8314
end_comment

begin_function_decl
name|void
name|proto
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|proto
parameter_list|(
name|x
parameter_list|)
name|int
name|x
decl_stmt|;
block|{ }
end_function

begin_function
name|void
name|use_proto
parameter_list|()
block|{
name|proto
argument_list|(
literal|42.1
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicit conversion from 'double' to 'int' changes value from 42.1 to 42}}
call|(
modifier|&
name|proto
call|)
argument_list|(
literal|42.1
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicit conversion from 'double' to 'int' changes value from 42.1 to 42}}
block|}
end_function

begin_comment
comment|// PR31020
end_comment

begin_function_decl
name|void
name|func
parameter_list|(
name|short
name|d
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(cdecl
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|cdecl
operator|)
argument_list|)
name|func
argument_list|(
name|d
argument_list|)
name|short
name|d
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{promoted type 'int' of K&R function parameter is not compatible with the parameter type 'short' declared in a previous prototype}}
end_comment

begin_block
block|{}
end_block

end_unit

