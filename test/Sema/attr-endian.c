begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_decl_stmt
name|int
name|p1
name|__attribute__
argument_list|(
operator|(
name|endian
argument_list|(
name|host
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{unknown attribute 'endian' ignored}}
end_comment

end_unit

