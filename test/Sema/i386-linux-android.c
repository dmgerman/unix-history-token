begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-linux-android -fsyntax-only -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_extern
extern|extern int a1_0[sizeof(long double
end_extern

begin_expr_stmt
unit|)
operator|==
literal|8
condition|?
literal|1
else|:
operator|-
literal|1
expr|]
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|a1_i
index|[
name|__alignof
argument_list|(
argument|long double
argument_list|)
operator|==
literal|4
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

end_unit

