begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm-unknown-unknown -target-abi apcs-gnu -fsyntax-only -verify %s
end_comment

begin_struct
struct|struct
name|s0
block|{
name|double
name|f0
decl_stmt|;
name|int
name|f1
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|char
name|chk0
index|[
name|__alignof__
argument_list|(
expr|struct
name|s0
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

