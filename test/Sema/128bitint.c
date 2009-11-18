begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -verify -triple x86_64-apple-darwin9 %s
end_comment

begin_typedef
typedef|typedef
name|int
name|i128
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|TI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|u128
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|TI
typedef|)));
end_typedef

begin_decl_stmt
name|int
name|a
index|[
operator|(
operator|(
name|i128
operator|)
operator|-
literal|1
operator|^
operator|(
name|i128
operator|)
operator|-
literal|2
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

begin_decl_stmt
name|int
name|a
index|[
operator|(
name|u128
operator|)
operator|-
literal|1
operator|>
literal|1LL
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR5435
end_comment

begin_decl_stmt
name|__uint128_t
name|b
init|=
operator|(
name|__uint128_t
operator|)
operator|-
literal|1
decl_stmt|;
end_decl_stmt

end_unit

