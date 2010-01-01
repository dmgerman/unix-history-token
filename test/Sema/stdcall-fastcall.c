begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// CC qualifier can be applied only to functions
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|var1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'stdcall' attribute only applies to function types}}
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|var2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'fastcall' attribute only applies to function types}}
end_comment

begin_comment
comment|// Different CC qualifiers are not compatible
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|,
name|fastcall
operator|)
argument_list|)
name|foo3
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{stdcall and fastcall attributes are not compatible}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|foo4
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|foo4
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{fastcall and stdcall attributes are not compatible}}
end_comment

end_unit

