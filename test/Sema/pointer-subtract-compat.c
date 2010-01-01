begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -pedantic
end_comment

begin_typedef
typedef|typedef
specifier|const
name|char
name|rchar
typedef|;
end_typedef

begin_function
name|int
name|a
parameter_list|(
name|char
modifier|*
name|a
parameter_list|,
name|rchar
modifier|*
name|b
parameter_list|)
block|{
return|return
name|a
operator|-
name|b
return|;
block|}
end_function

begin_comment
comment|//<rdar://problem/6520707>
end_comment

begin_function
name|void
name|f0
parameter_list|(
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
name|int
name|x
init|=
name|fp
operator|-
name|fp
decl_stmt|;
comment|// expected-warning{{arithmetic on pointer to function type 'void (*)(void)' is a GNU extension}}
block|}
end_function

end_unit

