begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux  -fsyntax-only -verify -emit-llvm-only %s
end_comment

begin_function_decl
name|void
name|f1
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"g1"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|g1
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function_decl
name|void
name|f2
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"g2"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{alias must point to a defined variable or function}}
end_comment

begin_function_decl
name|void
name|f3
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"g3"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{alias must point to a defined variable or function}}
end_comment

begin_function_decl
name|void
name|g3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f4
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"g4"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|g4
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|h4
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"f4"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f5
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"g5"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|h5
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"f5"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|g5
parameter_list|()
block|{}
end_function

begin_function
name|void
name|g6
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|f6
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"g6"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|h6
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"f6"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|g7
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|h7
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"f7"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f7
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"g7"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|h8
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"f8"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|g8
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|f8
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"g8"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|h9
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"f9"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f9
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"g9"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|g9
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|f10
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"g10"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{alias definition is part of a cycle}}
end_comment

begin_function_decl
name|void
name|g10
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"f10"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{alias definition is part of a cycle}}
end_comment

begin_comment
comment|// FIXME: This could be a bit better, h10 is not part of the cycle, it points
end_comment

begin_comment
comment|// to it.
end_comment

begin_function_decl
name|void
name|h10
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"g10"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{alias definition is part of a cycle}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|a1
name|__attribute__
argument_list|(
operator|(
name|alias
argument_list|(
literal|"b1"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|b1
init|=
literal|42
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|a2
name|__attribute__
argument_list|(
operator|(
name|alias
argument_list|(
literal|"b2"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{alias must point to a defined variable or function}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|a3
name|__attribute__
argument_list|(
operator|(
name|alias
argument_list|(
literal|"b3"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{alias must point to a defined variable or function}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|b3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|a4
name|__attribute__
argument_list|(
operator|(
name|alias
argument_list|(
literal|"b4"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{alias must point to a defined variable or function}}
end_comment

begin_typedef
typedef|typedef
name|int
name|b4
typedef|;
end_typedef

begin_function
name|void
name|test2_bar
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|test2_foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(weak
operator|,
function_decl|alias
parameter_list|(
function_decl|"test2_bar"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|test2_zed
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"test2_foo"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{alias will always resolve to test2_bar even if weak definition of alias test2_foo is overridden}}
end_comment

begin_function
name|void
name|test3_bar
parameter_list|()
block|{ }
end_function

begin_function_decl
name|void
name|test3_foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(section
parameter_list|(
function_decl|"test"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{alias will not be in section 'test' but in the same section as the aliasee}}
end_comment

begin_function_decl
name|void
name|test3_foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"test3_bar"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_macro
name|__attribute__
argument_list|(
argument|(section(
literal|"test"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|test4_bar
parameter_list|()
block|{ }
end_function

begin_function_decl
name|void
name|test4_foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(section
parameter_list|(
function_decl|"test"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|test4_foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"test4_bar"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|int
name|test5_bar
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|incomplete_type
name|test5_foo
name|__attribute__
argument_list|(
operator|(
name|alias
argument_list|(
literal|"test5_bar"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

