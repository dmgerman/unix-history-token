begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple s390x-linux-gnu -fsyntax-only -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// SystemZ prefers to align all global variables to two bytes,
end_comment

begin_comment
comment|// but this should *not* be reflected in the ABI alignment as
end_comment

begin_comment
comment|// retrieved via __alignof__.
end_comment

begin_struct
struct|struct
name|test
block|{
name|signed
name|char
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|test
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|chk1
index|[
name|__alignof__
argument_list|(
name|c
argument_list|)
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
name|chk2
index|[
name|__alignof__
argument_list|(
name|s
argument_list|)
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

