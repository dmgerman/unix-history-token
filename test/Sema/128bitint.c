begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple x86_64-apple-darwin9 -fms-extensions %s
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

begin_comment
comment|// PR11916: Support for libstdc++ 4.7
end_comment

begin_decl_stmt
name|__int128
name|i
init|=
operator|(
name|__int128
operator|)
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|__int128
name|u
init|=
operator|(
name|unsigned
name|__int128
operator|)
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|long
name|SignedTooBig
init|=
literal|123456789012345678901234567890
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{integer constant is too large for its type}}
end_comment

begin_decl_stmt
name|__int128_t
name|Signed128
init|=
literal|123456789012345678901234567890i
literal|128
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|long
name|Signed64
init|=
literal|123456789012345678901234567890i
literal|128
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{implicit conversion from '__int128' to 'long long' changes value from 123456789012345678901234567890 to -4362896299872285998}}
end_comment

begin_decl_stmt
name|unsigned
name|long
name|long
name|UnsignedTooBig
init|=
literal|123456789012345678901234567890
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{integer constant is too large for its type}}
end_comment

begin_decl_stmt
name|__uint128_t
name|Unsigned128
init|=
literal|123456789012345678901234567890Ui128
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|long
name|Unsigned64
init|=
literal|123456789012345678901234567890Ui128
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{implicit conversion from 'unsigned __int128' to 'unsigned long long' changes value from 123456789012345678901234567890 to 14083847773837265618}}
end_comment

end_unit

