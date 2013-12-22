begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wused-but-marked-unused -Wunused-function -Wunneeded-internal-declaration -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wunused %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wall %s
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{}
end_function

begin_function
specifier|static
name|void
name|f2
parameter_list|()
block|{}
end_function

begin_function
specifier|static
name|void
name|f1
parameter_list|()
block|{
name|f2
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning{{unused}}
end_comment

begin_function
specifier|static
name|int
name|f0
parameter_list|()
block|{
return|return
literal|17
return|;
block|}
end_function

begin_comment
comment|// expected-warning{{not needed and will not be emitted}}
end_comment

begin_decl_stmt
name|int
name|x
init|=
sizeof|sizeof
argument_list|(
name|f0
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|f3
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|extern
name|void
name|f3
parameter_list|()
block|{ }
end_function

begin_comment
comment|// expected-warning{{unused}}
end_comment

begin_function_decl
specifier|inline
specifier|static
name|void
name|f4
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|f4
parameter_list|()
block|{ }
end_function

begin_comment
comment|// expected-warning{{unused}}
end_comment

begin_decl_stmt
specifier|static
name|void
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
name|f5
argument_list|()
block|{}
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|f6
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|void
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
name|f6
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|f6
parameter_list|()
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|static
name|void
name|f7
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f8
parameter_list|(
name|void
function_decl|(
modifier|*
name|a0
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f9
parameter_list|(
name|void
parameter_list|)
block|{
name|f8
argument_list|(
name|f7
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|f7
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(unused)
argument_list|)
end_macro

begin_function_decl
specifier|static
name|void
name|bar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|bar
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(constructor)
argument_list|)
end_macro

begin_function_decl
specifier|static
name|void
name|bar2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|bar2
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(destructor)
argument_list|)
end_macro

begin_function_decl
specifier|static
name|void
name|bar3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|bar3
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function_decl
specifier|static
name|void
name|f10
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{unused}}
end_comment

begin_function_decl
specifier|static
name|void
name|f10
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|f11
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|f11
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|// expected-warning{{unused}}
end_comment

begin_function
specifier|static
name|void
name|f12
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|// expected-warning{{unused}}
end_comment

begin_function_decl
specifier|static
name|void
name|f12
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// PR7923
end_comment

begin_function
specifier|static
name|void
name|unused
parameter_list|(
name|void
parameter_list|)
block|{
name|unused
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning{{not needed and will not be emitted}}
end_comment

begin_comment
comment|// rdar://8728293
end_comment

begin_function
specifier|static
name|void
name|cleanupMalloc
parameter_list|(
name|char
modifier|*
specifier|const
modifier|*
specifier|const
name|allocation
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|f13
parameter_list|(
name|void
parameter_list|)
block|{
name|char
modifier|*
specifier|const
name|__attribute__
argument_list|(
operator|(
name|cleanup
argument_list|(
name|cleanupMalloc
argument_list|)
operator|)
argument_list|)
name|a
decl_stmt|;
operator|(
name|void
operator|)
name|a
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://12233989
end_comment

begin_function_decl
specifier|extern
name|void
name|a
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(unused
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|b
parameter_list|(
name|void
parameter_list|)
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
name|b
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|a
parameter_list|(
name|void
parameter_list|)
block|{
name|b
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

