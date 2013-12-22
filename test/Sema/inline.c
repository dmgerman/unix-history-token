begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INCLUDE
argument_list|)
end_if

begin_comment
comment|// -------
end_comment

begin_comment
comment|// This section acts like a header file.
end_comment

begin_comment
comment|// -------
end_comment

begin_comment
comment|// Check the use of static variables in non-static inline functions.
end_comment

begin_decl_stmt
specifier|static
name|int
name|staticVar
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note + {{'staticVar' declared here}}
end_comment

begin_function_decl
specifier|static
name|int
name|staticFunction
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-note + {{'staticFunction' declared here}}
end_comment

begin_struct
specifier|static
struct|struct
block|{
name|int
name|x
decl_stmt|;
block|}
name|staticStruct
struct|;
end_struct

begin_comment
comment|// expected-note + {{'staticStruct' declared here}}
end_comment

begin_function
specifier|inline
name|int
name|useStatic
parameter_list|()
block|{
comment|// expected-note 3 {{use 'static' to give inline function 'useStatic' internal linkage}}
name|staticFunction
argument_list|()
expr_stmt|;
comment|// expected-warning{{static function 'staticFunction' is used in an inline function with external linkage}}
operator|(
name|void
operator|)
name|staticStruct
operator|.
name|x
expr_stmt|;
comment|// expected-warning{{static variable 'staticStruct' is used in an inline function with external linkage}}
return|return
name|staticVar
return|;
comment|// expected-warning{{static variable 'staticVar' is used in an inline function with external linkage}}
block|}
end_function

begin_function
specifier|extern
specifier|inline
name|int
name|useStaticFromExtern
parameter_list|()
block|{
comment|// no suggestions
name|staticFunction
argument_list|()
expr_stmt|;
comment|// expected-warning{{static function 'staticFunction' is used in an inline function with external linkage}}
return|return
name|staticVar
return|;
comment|// expected-warning{{static variable 'staticVar' is used in an inline function with external linkage}}
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|useStaticFromStatic
parameter_list|()
block|{
name|staticFunction
argument_list|()
expr_stmt|;
comment|// no-warning
return|return
name|staticVar
return|;
comment|// no-warning
block|}
end_function

begin_function
specifier|extern
specifier|inline
name|int
name|useStaticInlineFromExtern
parameter_list|()
block|{
comment|// Heuristic: if the function we're using is also inline, don't warn.
comment|// This can still be wrong (in this case, we end up inlining calls to
comment|// staticFunction and staticVar) but this got very noisy even using
comment|// standard headers.
return|return
name|useStaticFromStatic
argument_list|()
return|;
comment|// no-warning
block|}
end_function

begin_function_decl
specifier|static
name|int
name|constFunction
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(const
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
specifier|inline
name|int
name|useConst
parameter_list|()
block|{
return|return
name|constFunction
argument_list|()
return|;
comment|// no-warning
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|// -------
end_comment

begin_comment
comment|// This is the main source file.
end_comment

begin_comment
comment|// -------
end_comment

begin_define
define|#
directive|define
name|INCLUDE
end_define

begin_include
include|#
directive|include
file|"inline.c"
end_include

begin_comment
comment|// Check that we don't allow illegal uses of inline
end_comment

begin_decl_stmt
specifier|inline
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{'inline' can only appear on functions}}
end_comment

begin_typedef
typedef|typedef
specifier|inline
name|int
name|b
typedef|;
end_typedef

begin_comment
comment|// expected-error{{'inline' can only appear on functions}}
end_comment

begin_function_decl
name|int
name|d
parameter_list|(
specifier|inline
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{'inline' can only appear on functions}}
end_comment

begin_comment
comment|// Check that the warnings from the "header file" aren't on by default in
end_comment

begin_comment
comment|// the main source file.
end_comment

begin_function
specifier|inline
name|int
name|useStaticMainFile
parameter_list|()
block|{
name|staticFunction
argument_list|()
expr_stmt|;
comment|// no-warning
return|return
name|staticVar
return|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Check that the warnings show up when explicitly requested.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|push
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|warning
literal|"-Wstatic-in-inline"
end_pragma

begin_function
specifier|inline
name|int
name|useStaticAgain
parameter_list|()
block|{
comment|// expected-note 2 {{use 'static' to give inline function 'useStaticAgain' internal linkage}}
name|staticFunction
argument_list|()
expr_stmt|;
comment|// expected-warning{{static function 'staticFunction' is used in an inline function with external linkage}}
return|return
name|staticVar
return|;
comment|// expected-warning{{static variable 'staticVar' is used in an inline function with external linkage}}
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
end_pragma

begin_function
specifier|inline
name|void
name|defineStaticVar
parameter_list|()
block|{
comment|// expected-note {{use 'static' to give inline function 'defineStaticVar' internal linkage}}
specifier|static
specifier|const
name|int
name|x
init|=
literal|0
decl_stmt|;
comment|// ok
specifier|static
name|int
name|y
init|=
literal|0
decl_stmt|;
comment|// expected-warning {{non-constant static local variable in inline function may be different in different files}}
block|}
end_function

begin_function
specifier|extern
specifier|inline
name|void
name|defineStaticVarInExtern
parameter_list|()
block|{
specifier|static
specifier|const
name|int
name|x
init|=
literal|0
decl_stmt|;
comment|// ok
specifier|static
name|int
name|y
init|=
literal|0
decl_stmt|;
comment|// ok
block|}
end_function

begin_comment
comment|// Check behavior of line markers.
end_comment

begin_empty
empty|# 1 "XXX.h" 1
end_empty

begin_function
specifier|inline
name|int
name|useStaticMainFileInLineMarker
parameter_list|()
block|{
comment|// expected-note 2 {{use 'static' to give inline function 'useStaticMainFileInLineMarker' internal linkage}}
name|staticFunction
argument_list|()
expr_stmt|;
comment|// expected-warning{{static function 'staticFunction' is used in an inline function with external linkage}}
return|return
name|staticVar
return|;
comment|// expected-warning{{static variable 'staticVar' is used in an inline function with external linkage}}
block|}
end_function

begin_empty
empty|# 100 "inline.c" 2
end_empty

begin_function
specifier|inline
name|int
name|useStaticMainFileAfterLineMarker
parameter_list|()
block|{
name|staticFunction
argument_list|()
expr_stmt|;
comment|// no-warning
return|return
name|staticVar
return|;
comment|// no-warning
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

