begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=i686-linux-gnu -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Check types are the same through redeclaration
end_comment

begin_decl_stmt
name|unsigned
name|long
name|x
decl_stmt|;
end_decl_stmt

begin_macro
name|__typeof
argument_list|(
literal|1u
argument|+
literal|1l
argument_list|)
end_macro

begin_expr_stmt
name|x
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|unsigned
name|y
decl_stmt|;
end_decl_stmt

begin_macro
name|__typeof
argument_list|(
literal|1
argument|+
literal|1u
argument_list|)
end_macro

begin_expr_stmt
name|y
expr_stmt|;
end_expr_stmt

begin_macro
name|__typeof
argument_list|(
literal|1u
argument|+
literal|1
argument_list|)
end_macro

begin_expr_stmt
name|y
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|long
name|long
name|z
decl_stmt|;
end_decl_stmt

begin_macro
name|__typeof
argument_list|(
literal|1ll
argument|+
literal|1u
argument_list|)
end_macro

begin_expr_stmt
name|z
expr_stmt|;
end_expr_stmt

end_unit

