begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_function_decl
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function_decl
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{previous declaration is here}}
end_comment

begin_function_decl
name|void
name|foo
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{conflicting types for 'foo'}}
end_comment

begin_function
name|int
name|funcdef
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
name|int
name|funcdef
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|funcdef2
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_function
name|int
name|funcdef2
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// expected-error {{redefinition of 'funcdef2'}}
end_comment

begin_comment
comment|// PR2502
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|2
argument|) )
argument_list|)
name|int
name|Vi2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|2
argument|) )
argument_list|)
name|float
name|Vf2
typedef|;
end_typedef

begin_decl_stmt
name|Vf2
name|g0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_decl_stmt
name|Vi2
name|g0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{redefinition of 'g0'}}
end_comment

begin_decl_stmt
specifier|_Complex
name|int
name|g1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_decl_stmt
specifier|_Complex
name|float
name|g1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{redefinition of 'g1'}}
end_comment

begin_comment
comment|// rdar://6096412
end_comment

begin_decl_stmt
specifier|extern
name|char
name|i6096412
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|i6096412
index|[]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo6096412
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|x
init|=
sizeof|sizeof
argument_list|(
name|i6096412
argument_list|)
decl_stmt|;
block|}
end_function

end_unit

