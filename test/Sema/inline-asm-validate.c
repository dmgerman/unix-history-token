begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-macosx10.8.0 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_decl_stmt
name|unsigned
name|t
decl_stmt|,
name|r
decl_stmt|,
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( "stxr   %w[_t], %[_r], [%[_p]]" : [_t] "=&r" (t) : [_p] "p" (p), [_r] "r" (r) : "memory");
return|return
literal|1
return|;
block|}
end_function

end_unit

