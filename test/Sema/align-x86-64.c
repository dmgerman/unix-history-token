begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -fsyntax-only -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// PR5637
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(aligned(
literal|16
argument|))
argument_list|)
struct|struct
block|{
name|unsigned
name|long
name|long
name|w
index|[
literal|3
index|]
decl_stmt|;
block|}
name|UINT192
typedef|;
end_typedef

begin_decl_stmt
name|UINT192
name|ten2mk192M
index|[]
init|=
block|{
block|{
block|{
literal|0xcddd6e04c0592104ULL
block|,
literal|0x0fcf80dc33721d53ULL
block|,
literal|0xa7c5ac471b478423ULL
block|}
block|}
block|,
block|{
block|{
literal|0xcddd6e04c0592104ULL
block|,
literal|0x0fcf80dc33721d53ULL
block|,
literal|0xa7c5ac471b478423ULL
block|}
block|}
block|,
block|{
block|{
literal|0xcddd6e04c0592104ULL
block|,
literal|0x0fcf80dc33721d53ULL
block|,
literal|0xa7c5ac471b478423ULL
block|}
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|chk1
index|[
sizeof|sizeof
argument_list|(
name|ten2mk192M
argument_list|)
operator|==
literal|80
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

end_unit

