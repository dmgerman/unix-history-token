begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -verify -pedantic
end_comment

begin_macro
name|foo
argument_list|()
end_macro

begin_block
block|{
comment|// expected-warning {{type specifier missing, defaults to 'int'}}
return|return
literal|0
return|;
block|}
end_block

begin_expr_stmt
name|y
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{type specifier missing, defaults to 'int'}}
end_comment

begin_comment
comment|// rdar://6131634
end_comment

begin_decl_stmt
name|void
name|f
argument_list|(
operator|(
name|x
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{type specifier missing, defaults to 'int'}}
end_comment

begin_comment
comment|// PR3702
end_comment

begin_define
define|#
directive|define
name|PAD
parameter_list|(
name|ms10
parameter_list|)
value|{ \     register i;     \ }
end_define

begin_define
define|#
directive|define
name|ILPAD
parameter_list|()
value|PAD((NROW - tt.tt_row) * 10)
end_define

begin_comment
comment|/* 1 ms per char */
end_comment

begin_function
name|void
name|h19_insline
parameter_list|(
name|n
parameter_list|)
comment|// expected-warning {{parameter 'n' was not declared, defaulting to type 'int'}}
block|{
name|ILPAD
argument_list|()
expr_stmt|;
comment|// expected-warning {{type specifier missing, defaults to 'int'}}
block|}
end_function

begin_struct
struct|struct
name|foo
block|{
name|__extension__
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|x
range|:
literal|4
decl_stmt|;
block|}
struct|;
end_struct

end_unit

