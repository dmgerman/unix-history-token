begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7-unknown-unknown -target-abi apcs-gnu %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-unknown-unknown -target-abi aapcs %s -verify
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_EABI__
end_ifdef

begin_struct
struct|struct
name|s0
block|{
name|char
name|field0
decl_stmt|;
name|double
name|field1
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|g0
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|s0
argument_list|)
operator|==
literal|16
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|s1
block|{
name|char
name|field0
decl_stmt|;
name|long
name|double
name|field1
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|g1
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|s1
argument_list|)
operator|==
literal|16
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|s0
block|{
name|char
name|field0
decl_stmt|;
name|double
name|field1
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|g0
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|s0
argument_list|)
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

begin_struct
struct|struct
name|s1
block|{
name|char
name|field0
decl_stmt|;
name|long
name|double
name|field1
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|g1
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|s1
argument_list|)
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

