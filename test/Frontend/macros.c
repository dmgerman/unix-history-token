begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -DA= -DB=1 -verify -fsyntax-only %s
end_comment

begin_decl_stmt
name|int
name|a
index|[
operator|(
name|B
name|A
operator|)
operator|==
literal|1
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

end_unit

