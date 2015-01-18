begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-win32     -fsyntax-only -verify -std=c99 -DMS %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-win32   -fsyntax-only -verify -std=c11 -DMS %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-mingw32   -fsyntax-only -verify -std=c11 -DGNU %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-mingw32 -fsyntax-only -verify -std=c99 -DGNU %s
end_comment

begin_comment
comment|// Invalid usage.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_typedef
typedef|typedef
name|int
name|typedef1
typedef|;
end_typedef

begin_comment
comment|// expected-warning{{'dllimport' attribute only applies to variables and functions}}
end_comment

begin_typedef
typedef|typedef
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
name|int
name|typedef2
typedef|;
end_typedef

begin_comment
comment|// expected-warning{{'dllimport' attribute only applies to variables and functions}}
end_comment

begin_typedef
typedef|typedef
name|int
name|__declspec
argument_list|(
name|dllimport
argument_list|)
name|typedef3
typedef|;
end_typedef

begin_comment
comment|// expected-warning{{'dllimport' attribute only applies to variables and functions}}
end_comment

begin_typedef
typedef|typedef
name|__declspec
function_decl|(
name|dllimport
function_decl|)
name|void
argument_list|(
argument|*FunTy
argument_list|)
parameter_list|()
function_decl|;
end_typedef

begin_comment
comment|// expected-warning{{'dllimport' attribute only applies to variables and functions}}
end_comment

begin_function
name|enum
name|__declspec
function|(
name|dllimport
function|) Enum
block|{
name|EnumVal
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning{{'dllimport' attribute only applies to variables and functions}}
end_comment

begin_struct
struct|struct
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
name|Record
block|{}
struct|;
end_struct

begin_comment
comment|// expected-warning{{'dllimport' attribute only applies to variables and functions}}
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
comment|// Import declaration.
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
name|ExternGlobalDecl
decl_stmt|;
end_decl_stmt

begin_comment
comment|// dllimport implies a declaration.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|GlobalDecl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
modifier|*
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
modifier|*
name|GlobalDeclChunkAttr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|GlobalDeclAttr
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Address of variables can't be used for initialization in C language modes.
end_comment

begin_decl_stmt
name|int
modifier|*
name|VarForInit
init|=
operator|&
name|GlobalDecl
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{initializer element is not a compile-time constant}}
end_comment

begin_comment
comment|// Not allowed on definitions.
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
name|ExternGlobalInit
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{definition of dllimport data}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|GlobalInit1
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{definition of dllimport data}}
end_comment

begin_decl_stmt
name|int
name|__declspec
argument_list|(
name|dllimport
argument_list|)
name|GlobalInit2
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{definition of dllimport data}}
end_comment

begin_comment
comment|// Declare, then reject definition.
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
name|ExternGlobalDeclInit
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous declaration is here}} expected-note{{previous attribute is here}}
end_comment

begin_decl_stmt
name|int
name|ExternGlobalDeclInit
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'ExternGlobalDeclInit' redeclared without 'dllimport' attribute: previous 'dllimport' ignored}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|GlobalDeclInit
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous declaration is here}} expected-note{{previous attribute is here}}
end_comment

begin_decl_stmt
name|int
name|GlobalDeclInit
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'GlobalDeclInit' redeclared without 'dllimport' attribute: previous 'dllimport' ignored}}
end_comment

begin_decl_stmt
name|int
modifier|*
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
name|GlobalDeclChunkAttrInit
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous declaration is here}} expected-note{{previous attribute is here}}
end_comment

begin_decl_stmt
name|int
modifier|*
name|GlobalDeclChunkAttrInit
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'GlobalDeclChunkAttrInit' redeclared without 'dllimport' attribute: previous 'dllimport' ignored}}
end_comment

begin_decl_stmt
name|int
name|GlobalDeclAttrInit
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous declaration is here}} expected-note{{previous attribute is here}}
end_comment

begin_decl_stmt
name|int
name|GlobalDeclAttrInit
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'GlobalDeclAttrInit' redeclared without 'dllimport' attribute: previous 'dllimport' ignored}}
end_comment

begin_comment
comment|// Redeclarations
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
name|GlobalRedecl1
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
name|GlobalRedecl1
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
name|GlobalRedecl2a
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
name|GlobalRedecl2a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
name|GlobalRedecl2b
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
name|GlobalRedecl2b
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|GlobalRedecl2c
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|GlobalRedecl2c
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// NB: MSVC issues a warning and makes GlobalRedecl3 dllexport. We follow GCC
end_comment

begin_comment
comment|// and drop the dllimport with a warning.
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
name|GlobalRedecl3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous declaration is here}} expected-note{{previous attribute is here}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|GlobalRedecl3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'GlobalRedecl3' redeclared without 'dllimport' attribute: previous 'dllimport' ignored}}
end_comment

begin_comment
comment|// Adding an attribute on redeclaration.
end_comment

begin_decl_stmt
specifier|extern
name|int
name|GlobalRedecl4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_function
name|int
name|useGlobalRedecl4
parameter_list|()
block|{
return|return
name|GlobalRedecl4
return|;
block|}
end_function

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|GlobalRedecl4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redeclaration of 'GlobalRedecl4' cannot add 'dllimport' attribute}}
end_comment

begin_comment
comment|// Allow with a warning if the decl hasn't been used yet.
end_comment

begin_decl_stmt
specifier|extern
name|int
name|GlobalRedecl5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous declaration is here}}
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
name|GlobalRedecl5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{redeclaration of 'GlobalRedecl5' should not add 'dllimport' attribute}}
end_comment

begin_comment
comment|// External linkage is required.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
specifier|static
name|int
name|StaticGlobal
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{'StaticGlobal' must have external linkage when declared 'dllimport'}}
end_comment

begin_comment
comment|// Thread local variables are invalid.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|__thread
name|int
name|ThreadLocalGlobal
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{'ThreadLocalGlobal' cannot be thread local when declared 'dllimport'}}
end_comment

begin_comment
comment|// Import in local scope.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|float
name|LocalRedecl1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|float
name|LocalRedecl2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|float
name|LocalRedecl3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|float
name|LocalRedecl4
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|functionScope
parameter_list|()
block|{
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
name|int
name|LocalRedecl1
decl_stmt|;
comment|// expected-error{{redefinition of 'LocalRedecl1' with a different type: 'int' vs 'float'}}
name|int
modifier|*
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
name|LocalRedecl2
decl_stmt|;
comment|// expected-error{{redefinition of 'LocalRedecl2' with a different type: 'int *' vs 'float'}}
name|int
name|LocalRedecl3
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
decl_stmt|;
comment|// expected-error{{redefinition of 'LocalRedecl3' with a different type: 'int' vs 'float'}}
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
name|int
name|LocalVarDecl
decl_stmt|;
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
name|int
name|LocalVarDef
init|=
literal|1
decl_stmt|;
comment|// expected-error{{definition of dllimport data}}
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
specifier|extern
name|int
name|ExternLocalVarDecl
decl_stmt|;
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
specifier|extern
name|int
name|ExternLocalVarDef
init|=
literal|1
decl_stmt|;
comment|// expected-error{{definition of dllimport data}}
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
specifier|static
name|int
name|StaticLocalVar
decl_stmt|;
comment|// expected-error{{'StaticLocalVar' must have external linkage when declared 'dllimport'}}
comment|// Local extern redeclaration does not drop the attribute.
specifier|extern
name|float
name|LocalRedecl4
decl_stmt|;
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
comment|// Import function declaration. Check different placements.
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(dllimport)
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
argument|dllimport
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
name|dllimport
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
name|dllimport
parameter_list|)
function_decl|decl2B
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Address of functions can be used for initialization in C language modes.
end_comment

begin_comment
comment|// However, the address of the thunk wrapping the function is used instead of
end_comment

begin_comment
comment|// the address in the import address table.
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|FunForInit
function_decl|)
parameter_list|()
init|=
operator|&
name|decl2A
function_decl|;
end_function_decl

begin_comment
comment|// Not allowed on function definitions.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function
name|void
name|def
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-error{{dllimport cannot be applied to non-inline function definition}}
end_comment

begin_comment
comment|// Import inline function.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GNU
end_ifdef

begin_comment
comment|// expected-warning@+3{{'dllimport' attribute ignored on inline function}}
end_comment

begin_comment
comment|// expected-warning@+3{{'dllimport' attribute ignored on inline function}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function
specifier|inline
name|void
name|inlineFunc1
parameter_list|()
block|{}
end_function

begin_decl_stmt
specifier|inline
name|void
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
name|inlineFunc2
argument_list|()
block|{}
end_decl_stmt

begin_comment
comment|// Redeclarations
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
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
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl1
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// NB: MSVC issues a warning and makes redecl2/redecl3 dllexport. We follow GCC
end_comment

begin_comment
comment|// and drop the dllimport with a warning.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl2
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{previous declaration is here}} expected-note{{previous attribute is here}}
end_comment

begin_function_decl
name|void
name|redecl2
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{'redecl2' redeclared without 'dllimport' attribute: previous 'dllimport' ignored}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl3
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{previous declaration is here}} expected-note{{previous attribute is here}}
end_comment

begin_function
name|void
name|redecl3
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning{{'redecl3' redeclared without 'dllimport' attribute: previous 'dllimport' ignored}}
end_comment

begin_function_decl
name|void
name|redecl4
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_function
name|void
name|useRedecl4
parameter_list|()
block|{
name|redecl4
argument_list|()
expr_stmt|;
block|}
end_function

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl4
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{redeclaration of 'redecl4' cannot add 'dllimport' attribute}}
end_comment

begin_comment
comment|// Allow with a warning if the decl hasn't been used yet.
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
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl5
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{redeclaration of 'redecl5' should not add 'dllimport' attribute}}
end_comment

begin_comment
comment|// Inline redeclarations.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GNU
end_ifdef

begin_comment
comment|// expected-warning@+3{{'redecl6' redeclared inline; 'dllimport' attribute ignored}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl6
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|inline
name|void
name|redecl6
parameter_list|()
block|{}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|MS
end_ifdef

begin_comment
comment|// expected-note@+5{{previous declaration is here}}
end_comment

begin_comment
comment|// expected-warning@+5{{redeclaration of 'redecl7' should not add 'dllimport' attribute}}
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// expected-warning@+3{{'dllimport' attribute ignored on inline function}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|redecl7
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function
specifier|inline
name|void
name|redecl7
parameter_list|()
block|{}
end_function

begin_comment
comment|// External linkage is required.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
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
comment|// expected-error{{'staticFunc' must have external linkage when declared 'dllimport'}}
end_comment

end_unit

