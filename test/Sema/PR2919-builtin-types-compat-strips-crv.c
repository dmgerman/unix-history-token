begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s
end_comment

begin_typedef
typedef|typedef
name|struct
name|foo
name|T0
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|foo
name|T1
typedef|;
end_typedef

begin_decl_stmt
name|int
name|a0
index|[
name|__builtin_types_compatible_p
argument_list|(
name|T0
argument_list|,
specifier|const
name|T1
argument_list|)
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

end_unit

