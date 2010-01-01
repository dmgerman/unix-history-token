begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -pedantic -verify %s
end_comment

begin_decl_stmt
name|int
name|test
index|[
literal|'\\'
operator|==
literal|92
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
name|test
index|[
literal|'\"'
operator|==
literal|34
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
name|test
index|[
literal|'\''
operator|==
literal|39
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
name|test
index|[
literal|'\?'
operator|==
literal|63
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
name|test
index|[
literal|'\a'
operator|==
literal|7
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
name|test
index|[
literal|'\b'
operator|==
literal|8
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
name|test
index|[
literal|'\e'
operator|==
literal|27
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{non-standard escape}}
end_comment

begin_decl_stmt
name|int
name|test
index|[
literal|'\E'
operator|==
literal|27
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{non-standard escape}}
end_comment

begin_decl_stmt
name|int
name|test
index|[
literal|'\f'
operator|==
literal|12
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
name|test
index|[
literal|'\n'
operator|==
literal|10
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
name|test
index|[
literal|'\r'
operator|==
literal|13
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
name|test
index|[
literal|'\t'
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
name|test
index|[
literal|'\v'
operator|==
literal|11
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
name|test
index|[
literal|'\xa'
operator|==
literal|10
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
name|test
index|[
literal|'\1'
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

begin_decl_stmt
name|int
name|test
index|[
literal|'\('
operator|==
literal|40
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{non-standard escape}}
end_comment

begin_decl_stmt
name|int
name|test
index|[
literal|'\{'
operator|==
literal|123
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{non-standard escape}}
end_comment

begin_decl_stmt
name|int
name|test
index|[
literal|'\['
operator|==
literal|91
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{non-standard escape}}
end_comment

begin_decl_stmt
name|int
name|test
index|[
literal|'\%'
operator|==
literal|37
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{non-standard escape}}
end_comment

end_unit

