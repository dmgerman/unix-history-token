begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-win32     -fsyntax-only -verify -std=c99 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-win32   -fsyntax-only -verify -std=c11 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-mingw32   -fsyntax-only -verify -std=c11 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-mingw32 -fsyntax-only -verify -std=c99 %s
end_comment

begin_comment
comment|// Invalid usage.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_typedef
typedef|typedef
name|int
name|typedef1
typedef|;
end_typedef

begin_comment
comment|// expected-warning{{'dllexport' attribute only applies to variables and functions}}
end_comment

begin_typedef
typedef|typedef
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
name|int
name|typedef2
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
name|dllexport
argument_list|)
name|typedef3
typedef|;
end_typedef

begin_comment
comment|// expected-warning{{'dllexport' attribute only applies to variables and functions}}
end_comment

begin_typedef
typedef|typedef
name|__declspec
function_decl|(
name|dllexport
function_decl|)
name|void
argument_list|(
argument|*FunTy
argument_list|)
parameter_list|()
function_decl|;
end_typedef

begin_comment
comment|// expected-warning{{'dllexport' attribute only applies to variables and functions}}
end_comment

begin_function
name|enum
name|__declspec
function|(
name|dllexport
function|) Enum
block|{
name|EnumVal
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning{{'dllexport' attribute only applies to variables and functions}}
end_comment

begin_struct
struct|struct
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
name|Record
block|{}
struct|;
end_struct

begin_comment
comment|// expected-warning{{'dllexport' attribute only applies to variables and functions}}
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Globals
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Export declaration.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|ExternGlobalDecl
decl_stmt|;
end_decl_stmt

begin_comment
comment|// dllexport implies a definition.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|GlobalDef
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Export definition.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|GlobalInit1
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__declspec
argument_list|(
name|dllexport
argument_list|)
name|GlobalInit2
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Declare, then export definition.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|GlobalDeclInit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|GlobalDeclInit
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Redeclarations
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|GlobalRedecl1
decl_stmt|;
end_decl_stmt

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|GlobalRedecl1
decl_stmt|;
end_decl_stmt

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|GlobalRedecl2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|GlobalRedecl2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|GlobalRedecl3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|GlobalRedecl3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redeclaration of 'GlobalRedecl3' cannot add 'dllexport' attribute}}
end_comment

begin_comment
comment|// External linkage is required.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
specifier|static
name|int
name|StaticGlobal
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{'StaticGlobal' must have external linkage when declared 'dllexport'}}
end_comment

begin_comment
comment|// Export in local scope.
end_comment

begin_function
name|void
name|functionScope
parameter_list|()
block|{
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
name|int
name|LocalVarDecl
decl_stmt|;
comment|// expected-error{{'LocalVarDecl' must have external linkage when declared 'dllexport'}}
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
name|int
name|LocalVarDef
init|=
literal|1
decl_stmt|;
comment|// expected-error{{'LocalVarDef' must have external linkage when declared 'dllexport'}}
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
specifier|extern
name|int
name|ExternLocalVarDecl
decl_stmt|;
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
specifier|static
name|int
name|StaticLocalVar
decl_stmt|;
comment|// expected-error{{'StaticLocalVar' must have external linkage when declared 'dllexport'}}
block|}
end_function

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Functions
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Export function declaration. Check different placements.
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(dllexport)
argument_list|)
end_macro

begin_function_decl
name|void
name|decl1A
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Sanity check with __attribute__
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function_decl
name|void
name|decl1B
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllexport
operator|)
argument_list|)
name|decl2A
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|__declspec
parameter_list|(
name|dllexport
parameter_list|)
function_decl|decl2B
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Export function definition.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function
name|void
name|def
parameter_list|()
block|{}
end_function

begin_comment
comment|// Export inline function.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function
specifier|inline
name|void
name|inlineFunc1
parameter_list|()
block|{}
end_function

begin_function_decl
specifier|extern
name|void
name|inlineFunc1
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|inline
name|void
name|__attribute__
argument_list|(
operator|(
name|dllexport
operator|)
argument_list|)
name|inlineFunc2
argument_list|()
block|{}
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|inlineFunc2
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Redeclarations
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl1
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl1
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|redecl2
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl3
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|redecl3
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|redecl4
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl4
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{redeclaration of 'redecl4' cannot add 'dllexport' attribute}}
end_comment

begin_function_decl
name|void
name|redecl5
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function
specifier|inline
name|void
name|redecl5
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-error{{redeclaration of 'redecl5' cannot add 'dllexport' attribute}}
end_comment

begin_comment
comment|// External linkage is required.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function_decl
specifier|static
name|int
name|staticFunc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{'staticFunc' must have external linkage when declared 'dllexport'}}
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Precedence
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// dllexport takes precedence over dllimport if both are specified.
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(dllimport, dllexport)
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|PrecedenceExternGlobal1A
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|PrecedenceExternGlobal1B
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(dllexport, dllimport)
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|PrecedenceExternGlobal2A
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|PrecedenceExternGlobal2B
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(dllimport, dllexport)
argument_list|)
end_macro

begin_decl_stmt
name|int
name|PrecedenceGlobal1A
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|PrecedenceGlobal1B
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(dllexport, dllimport)
argument_list|)
end_macro

begin_decl_stmt
name|int
name|PrecedenceGlobal2A
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|PrecedenceGlobal2B
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|PrecedenceExternGlobalRedecl1
decl_stmt|;
end_decl_stmt

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|PrecedenceExternGlobalRedecl1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|PrecedenceExternGlobalRedecl2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|PrecedenceExternGlobalRedecl2
decl_stmt|;
end_decl_stmt

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|PrecedenceGlobalRedecl1
decl_stmt|;
end_decl_stmt

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|PrecedenceGlobalRedecl1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|PrecedenceGlobalRedecl2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|PrecedenceGlobalRedecl2
decl_stmt|;
end_decl_stmt

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
name|precedence1A
argument_list|()
block|{}
end_decl_stmt

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

begin_function
name|void
name|__declspec
parameter_list|(
name|dllimport
parameter_list|)
function|__declspec
parameter_list|(
name|dllexport
parameter_list|)
function|precedence1B
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllexport
operator|,
name|dllimport
operator|)
argument_list|)
name|precedence2A
argument_list|()
block|{}
end_decl_stmt

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

begin_function
name|void
name|__declspec
parameter_list|(
name|dllexport
parameter_list|)
function|__declspec
parameter_list|(
name|dllimport
parameter_list|)
function|precedence2B
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

begin_function_decl
name|void
name|__declspec
parameter_list|(
name|dllimport
parameter_list|)
function_decl|precedenceRedecl1
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

begin_function
name|void
name|__declspec
parameter_list|(
name|dllexport
parameter_list|)
function|precedenceRedecl1
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|__declspec
parameter_list|(
name|dllexport
parameter_list|)
function_decl|precedenceRedecl2
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|__declspec
parameter_list|(
name|dllimport
parameter_list|)
function|precedenceRedecl2
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning{{'dllimport' attribute ignored}}
end_comment

end_unit

