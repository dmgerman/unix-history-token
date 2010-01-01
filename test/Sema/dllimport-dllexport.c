begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_decl_stmt
specifier|inline
name|void
name|__attribute__
argument_list|(
operator|(
name|dllexport
operator|)
argument_list|)
name|foo1
argument_list|()
block|{}
end_decl_stmt

begin_comment
comment|// expected-warning{{dllexport attribute ignored}}
end_comment

begin_decl_stmt
specifier|inline
name|void
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
name|foo2
argument_list|()
block|{}
end_decl_stmt

begin_comment
comment|// expected-warning{{dllimport attribute ignored}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
name|foo3
argument_list|()
block|{}
end_decl_stmt

begin_comment
comment|// expected-error{{dllimport attribute can be applied only to symbol declaration}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|,
name|dllexport
operator|)
argument_list|)
name|foo4
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{dllimport attribute ignored}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllexport
operator|)
argument_list|)
name|foo5
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
name|foo5
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{dllimport attribute ignored}}
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|dllexport
operator|)
argument_list|)
name|type6
typedef|;
end_typedef

begin_comment
comment|// expected-warning{{'dllexport' attribute only applies to variable and function types}}
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
name|type7
typedef|;
end_typedef

begin_comment
comment|// expected-warning{{'dllimport' attribute only applies to variable and function}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
name|foo6
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo6
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning {{'foo6' redeclared without dllimport attribute: previous dllimport ignored}}
end_comment

end_unit

