begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(unused
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(unused
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|foo
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(constructor
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{must precede definition}}
end_comment

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|bar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bar
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bar
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bar
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bar
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_decl_stmt
name|int
name|bar
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{must precede definition}}
end_comment

begin_decl_stmt
name|int
name|bar
decl_stmt|;
end_decl_stmt

end_unit

