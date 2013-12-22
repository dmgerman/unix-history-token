begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple mipsel-linux-gnu -fsyntax-only -verify %s
end_comment

begin_function_decl
name|void
name|foo32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|foo16
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|nomips16
operator|)
argument_list|)
name|foo32
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|mips16
operator|)
argument_list|)
name|foo16
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|nomips16
operator|)
argument_list|)
name|foo32_
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|mips16
operator|)
argument_list|)
name|foo16_
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|foo32_
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|foo16_
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|foo32__
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(nomips16
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|foo32__
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(mips16
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|foo32a
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(nomips16
parameter_list|(
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'nomips16' attribute takes no arguments}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|mips16
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
name|foo16a
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'mips16' attribute takes no arguments}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|nomips16
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
operator|)
argument_list|)
name|foo32b
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'nomips16' attribute takes no arguments}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|mips16
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
operator|)
argument_list|)
name|foo16b
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'mips16' attribute takes no arguments}}
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(nomips16)
argument_list|)
end_macro

begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{attribute only applies to functions}}
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(mips16)
argument_list|)
end_macro

begin_decl_stmt
name|int
name|b
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{attribute only applies to functions}}
end_comment

end_unit

