begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_struct
struct|struct
name|s
block|{}
struct|;
end_struct

begin_comment
comment|// FIXME: should warn that declaration attribute in type position is
end_comment

begin_comment
comment|// being applied to the declaration instead?
end_comment

begin_decl_stmt
name|struct
name|s
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
name|foo
decl_stmt|;
end_decl_stmt

begin_comment
comment|// FIXME: Should warn that type attribute in declaration position is
end_comment

begin_comment
comment|// being applied to the type instead?
end_comment

begin_decl_stmt
name|struct
name|s
modifier|*
name|bar
name|__attribute__
argument_list|(
operator|(
name|address_space
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Should not warn because type attribute is in type position.
end_comment

begin_decl_stmt
name|struct
name|s
modifier|*
name|__attribute__
argument_list|(
operator|(
name|address_space
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
name|baz
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Should not warn because declaration attribute is in declaration position.
end_comment

begin_decl_stmt
name|struct
name|s
modifier|*
name|quux
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

