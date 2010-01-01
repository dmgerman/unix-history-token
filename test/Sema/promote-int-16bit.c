begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -triple pic16-unknown-unknown
end_comment

begin_comment
comment|// Check that unsigned short promotes to unsigned int on targets where
end_comment

begin_comment
comment|// sizeof(unsigned short) == sizeof(unsigned int)
end_comment

begin_macro
name|__typeof
argument_list|(
literal|1
argument|+(unsigned short)
literal|1
argument_list|)
end_macro

begin_expr_stmt
name|x
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|unsigned
name|x
decl_stmt|;
end_decl_stmt

end_unit

