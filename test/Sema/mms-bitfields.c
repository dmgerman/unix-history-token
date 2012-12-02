begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -mms-bitfields -fsyntax-only -verify -triple x86_64-apple-darwin9 %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// The -mms-bitfields commandline parameter should behave the same
end_comment

begin_comment
comment|// as the ms_struct attribute.
end_comment

begin_struct
struct|struct
block|{
name|int
name|a
range|:
literal|1
decl_stmt|;
name|short
name|b
range|:
literal|1
decl_stmt|;
block|}
name|t
struct|;
end_struct

begin_comment
comment|// MS pads out bitfields between different types.
end_comment

begin_decl_stmt
specifier|static
name|int
name|arr
index|[
operator|(
sizeof|sizeof
argument_list|(
name|t
argument_list|)
operator|==
literal|8
operator|)
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

end_unit

