begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_function_decl
name|void
name|c1
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|g1
name|__attribute
argument_list|(
operator|(
name|cleanup
argument_list|(
name|c1
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{cleanup attribute ignored}}
end_comment

begin_decl_stmt
name|int
name|g2
name|__attribute
argument_list|(
operator|(
name|cleanup
argument_list|(
name|c1
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{cleanup attribute ignored}}
end_comment

begin_decl_stmt
specifier|static
name|int
name|g3
name|__attribute
argument_list|(
operator|(
name|cleanup
argument_list|(
name|c1
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{cleanup attribute ignored}}
end_comment

begin_function
name|void
name|t1
parameter_list|()
block|{
name|int
name|v1
name|__attribute
argument_list|(
operator|(
name|cleanup
operator|)
argument_list|)
decl_stmt|;
comment|// expected-error {{attribute requires 1 argument(s)}}
name|int
name|v2
name|__attribute
argument_list|(
operator|(
name|cleanup
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
operator|)
argument_list|)
decl_stmt|;
comment|// expected-error {{attribute requires 1 argument(s)}}
specifier|static
name|int
name|v3
name|__attribute
argument_list|(
operator|(
name|cleanup
argument_list|(
name|c1
argument_list|)
operator|)
argument_list|)
decl_stmt|;
comment|// expected-warning {{cleanup attribute ignored}}
name|int
name|v4
name|__attribute
argument_list|(
operator|(
name|cleanup
argument_list|(
name|h
argument_list|)
operator|)
argument_list|)
decl_stmt|;
comment|// expected-error {{'cleanup' argument 'h' not found}}
name|int
name|v5
name|__attribute
argument_list|(
operator|(
name|cleanup
argument_list|(
name|c1
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|int
name|v6
name|__attribute
argument_list|(
operator|(
name|cleanup
argument_list|(
name|v3
argument_list|)
operator|)
argument_list|)
decl_stmt|;
comment|// expected-error {{'cleanup' argument 'v3' is not a function}}
block|}
end_function

begin_struct
struct|struct
name|s
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|c2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|c3
parameter_list|(
name|struct
name|s
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|t2
parameter_list|()
block|{
name|int
name|v1
name|__attribute__
argument_list|(
operator|(
name|cleanup
argument_list|(
name|c2
argument_list|)
operator|)
argument_list|)
decl_stmt|;
comment|// expected-error {{'cleanup' function 'c2' must take 1 parameter}}
name|int
name|v2
name|__attribute__
argument_list|(
operator|(
name|cleanup
argument_list|(
name|c3
argument_list|)
operator|)
argument_list|)
decl_stmt|;
comment|// expected-error {{'cleanup' function 'c3' parameter has type 'struct s' which is incompatible with type 'int *'}}
block|}
end_function

begin_comment
comment|// This is a manufactured testcase, but gcc accepts it...
end_comment

begin_function_decl
name|void
name|c4
parameter_list|(
name|_Bool
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|t4
parameter_list|()
block|{
name|__attribute
argument_list|(
argument|(cleanup(c4))
argument_list|)
name|void
modifier|*
name|g
decl_stmt|;
block|}
end_function

end_unit

