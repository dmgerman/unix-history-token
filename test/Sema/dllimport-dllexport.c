begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-mingw32 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-mingw32 -fsyntax-only -verify %s
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
comment|// expected-warning{{'dllexport' attribute only applies to variables and functions}}
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
comment|// expected-warning{{'dllimport' attribute only applies to variables and functions}}
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

begin_comment
comment|// PR6269
end_comment

begin_function
specifier|inline
name|void
name|__declspec
parameter_list|(
name|dllexport
parameter_list|)
function|foo7
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning{{dllexport attribute ignored}}
end_comment

begin_function
specifier|inline
name|void
name|__declspec
parameter_list|(
name|dllimport
parameter_list|)
function|foo8
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning{{dllimport attribute ignored}}
end_comment

begin_function
name|void
name|__declspec
parameter_list|(
name|dllimport
parameter_list|)
function|foo9
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-error{{dllimport attribute can be applied only to symbol declaration}}
end_comment

begin_function_decl
name|void
name|__declspec
parameter_list|(
name|dllimport
parameter_list|)
function_decl|__declspec
parameter_list|(
name|dllexport
parameter_list|)
function_decl|foo10
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{dllimport attribute ignored}}
end_comment

begin_function_decl
name|void
name|__declspec
parameter_list|(
name|dllexport
parameter_list|)
function_decl|foo11
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__declspec
parameter_list|(
name|dllimport
parameter_list|)
function_decl|foo11
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{dllimport attribute ignored}}
end_comment

begin_typedef
typedef|typedef
name|int
name|__declspec
argument_list|(
name|dllexport
argument_list|)
name|type1
typedef|;
end_typedef

begin_comment
comment|// expected-warning{{'dllexport' attribute only applies to variables and functions}}
end_comment

begin_typedef
typedef|typedef
name|int
name|__declspec
argument_list|(
name|dllimport
argument_list|)
name|type2
typedef|;
end_typedef

begin_comment
comment|// expected-warning{{'dllimport' attribute only applies to variables and functions}}
end_comment

begin_function_decl
name|void
name|__declspec
parameter_list|(
name|dllimport
parameter_list|)
function_decl|foo12
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|foo12
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning {{'foo12' redeclared without dllimport attribute: previous dllimport ignored}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
name|foo13
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
name|foo13
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|foo14
name|__attribute__
argument_list|(
operator|(
name|dllexport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|foo14
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{dllimport attribute ignored}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|foo15
init|=
literal|54
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'dllimport' attribute cannot be specified on a definition}}
end_comment

begin_extern
extern|extern __declspec(dllimport
end_extern

begin_decl_stmt
unit|)
name|int
name|foo17
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|foo17
init|=
literal|54
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'dllimport' attribute cannot be specified on a definition}}
end_comment

end_unit

