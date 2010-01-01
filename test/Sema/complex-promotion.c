begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_decl_stmt
name|float
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|b
index|[
name|__builtin_classify_type
argument_list|(
name|a
operator|+
literal|1i
argument_list|)
operator|==
literal|9
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|c
index|[
name|__builtin_classify_type
argument_list|(
literal|1i
operator|+
name|a
argument_list|)
operator|==
literal|9
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|d
decl_stmt|;
end_decl_stmt

begin_macro
name|__typeof__
argument_list|(
argument|d +
literal|1i
argument_list|)
end_macro

begin_expr_stmt
name|e
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|f
index|[
sizeof|sizeof
argument_list|(
name|e
argument_list|)
operator|==
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|double
argument_list|)
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|g
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|h
index|[
name|__builtin_classify_type
argument_list|(
name|g
operator|+
literal|1.0i
argument_list|)
operator|==
literal|9
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i
index|[
name|__builtin_classify_type
argument_list|(
literal|1.0i
operator|+
name|a
argument_list|)
operator|==
literal|9
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

end_unit

