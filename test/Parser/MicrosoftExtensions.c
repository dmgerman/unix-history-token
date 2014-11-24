begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-mingw32 -fsyntax-only -Wno-missing-declarations -verify -fms-extensions  %s
end_comment

begin_function_decl
name|__stdcall
name|int
name|func0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__stdcall
name|func
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
name|__cdecl
modifier|*
name|tptr
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
function_decl|(
modifier|*
name|__fastcall
name|fastpfunc
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern __declspec(dllimport
end_extern

begin_function_decl
unit|)
name|void
name|__stdcall
name|VarR4FromDec
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|deprecated
argument_list|)
end_macro

begin_macro
name|__declspec
argument_list|(
argument|deprecated
argument_list|)
end_macro

begin_function_decl
name|char
modifier|*
name|__cdecl
name|ltoa
parameter_list|(
name|long
name|_Val
parameter_list|,
name|char
modifier|*
name|_DstBuf
parameter_list|,
name|int
name|_Radix
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|safebuffers
argument_list|)
end_macro

begin_macro
name|__declspec
argument_list|(
argument|noalias
argument_list|)
end_macro

begin_macro
name|__declspec
argument_list|(
argument|restrict
argument_list|)
end_macro

begin_function_decl
name|void
modifier|*
name|__cdecl
name|xxx
parameter_list|(
name|void
modifier|*
name|_Memory
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* expected-warning{{__declspec attribute 'safebuffers' is not supported}} expected-warning{{__declspec attribute 'noalias' is not supported}} expected-warning{{__declspec attribute 'restrict' is not supported}} */
end_comment

begin_typedef
typedef|typedef
name|__w64
name|unsigned
name|long
name|ULONG_PTR
typedef|,
modifier|*
name|PULONG_PTR
typedef|;
end_typedef

begin_function
name|void
modifier|*
name|__ptr64
name|PtrToPtr64
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
operator|(
name|void
operator|*
name|__ptr64
operator|)
operator|(
name|unsigned
name|__int64
operator|)
operator|(
name|ULONG_PTR
operator|)
name|p
operator|)
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|__ptr32
name|PtrToPtr32
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
operator|(
name|void
operator|*
name|__ptr32
operator|)
operator|(
name|unsigned
name|__int32
operator|)
operator|(
name|ULONG_PTR
operator|)
name|p
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Both inline and __forceinline is OK. */
end_comment

begin_function
specifier|inline
name|void
name|__forceinline
name|pr8264
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function
name|__forceinline
name|void
specifier|inline
name|pr8264_1
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function
name|void
specifier|inline
name|__forceinline
name|pr8264_2
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function
name|void
name|__forceinline
specifier|inline
name|pr8264_3
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|/* But duplicate __forceinline causes warning. */
end_comment

begin_function
name|void
name|__forceinline
name|__forceinline
name|pr8264_4
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* expected-warning{{duplicate '__forceinline' declaration specifier}} */
block|}
end_function

begin_function
name|_inline
name|int
name|foo99
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|99
return|;
block|}
end_function

begin_function
name|void
name|test_ms_alignof_alias
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|int
name|s
init|=
name|_alignof
argument_list|(
name|int
argument_list|)
decl_stmt|;
name|s
operator|=
name|__builtin_alignof
argument_list|(
name|int
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Charify extension. */
end_comment

begin_define
define|#
directive|define
name|FOO
parameter_list|(
name|x
parameter_list|)
value|#@x
end_define

begin_decl_stmt
name|char
name|x
init|=
name|FOO
argument_list|(
name|a
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
enum|enum
name|E
block|{
name|e1
block|}
empty_stmt|;
end_typedef

begin_function
name|enum
name|__declspec
function|(
name|deprecated
function|) E2
block|{
name|i
operator|,
name|j
operator|,
name|k
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* expected-note {{'E2' has been explicitly marked deprecated here}} */
end_comment

begin_expr_stmt
name|__declspec
argument_list|(
name|deprecated
argument_list|)
expr|enum
name|E3
block|{
name|a
block|,
name|b
block|,
name|c
block|}
name|e
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* expected-note {{'e' has been explicitly marked deprecated here}} */
end_comment

begin_function
name|void
name|deprecated_enum_test
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Test to make sure the deprecated warning follows the right thing */
name|enum
name|E2
name|e1
decl_stmt|;
comment|/* expected-warning {{'E2' is deprecated}} */
name|enum
name|E3
name|e2
decl_stmt|;
comment|/* No warning expected, the deprecation follows the variable */
name|enum
name|E3
name|e3
init|=
name|e
decl_stmt|;
comment|/* expected-warning {{'e' is deprecated}} */
block|}
end_function

begin_comment
comment|/* Microsoft attribute tests */
end_comment

begin_expr_stmt
index|[
name|returnvalue
operator|:
name|SA_Post
argument_list|(
name|attr
operator|=
literal|1
argument_list|)
index|]
name|int
name|foo1
argument_list|(
index|[
name|SA_Post
argument_list|(
name|attr
operator|=
literal|1
argument_list|)
index|]
name|void
operator|*
name|param
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|ms_intrinsics
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|__noop
argument_list|()
expr_stmt|;
name|__assume
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|__debugbreak
argument_list|()
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|__declspec
argument_list|(
argument|frobble
argument_list|)
name|S1
block|{}
struct|;
end_struct

begin_comment
comment|/* expected-warning {{__declspec attribute 'frobble' is not supported}} */
end_comment

begin_struct
struct|struct
name|__declspec
argument_list|(
literal|12
argument_list|)
name|S2
block|{}
struct|;
end_struct

begin_comment
comment|/* expected-error {{__declspec attributes must be an identifier or string literal}} */
end_comment

begin_struct
struct|struct
name|__declspec
argument_list|(
literal|"testing"
argument_list|)
name|S3
block|{}
struct|;
end_struct

begin_comment
comment|/* expected-warning {{__declspec attribute '"testing"' is not supported}} */
end_comment

begin_comment
comment|/* declspecs with arguments cannot have an empty argument list, even if the    arguments are optional. */
end_comment

begin_macro
name|__declspec
argument_list|(
argument|deprecated()
argument_list|)
end_macro

begin_function_decl
name|void
name|dep_func_test
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* expected-error {{parentheses must be omitted if 'deprecated' attribute's argument list is empty}} */
end_comment

begin_macro
name|__declspec
argument_list|(
argument|deprecated
argument_list|)
end_macro

begin_function_decl
name|void
name|dep_func_test2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|deprecated(
literal|""
argument|)
argument_list|)
end_macro

begin_function_decl
name|void
name|dep_func_test3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Ensure multiple declspec attributes are supported */
end_comment

begin_struct
struct|struct
name|__declspec
argument_list|(
argument|align(
literal|8
argument|) deprecated
argument_list|)
name|S4
block|{}
struct|;
end_struct

begin_comment
comment|/* But multiple declspecs must still be legal */
end_comment

begin_struct
struct|struct
name|__declspec
argument_list|(
argument|deprecated frobble
literal|"testing"
argument_list|)
name|S5
block|{}
struct|;
end_struct

begin_comment
comment|/* expected-warning {{__declspec attribute 'frobble' is not supported}} expected-warning {{__declspec attribute '"testing"' is not supported}} */
end_comment

begin_struct
struct|struct
name|__declspec
argument_list|(
argument|unknown(
literal|12
argument|) deprecated
argument_list|)
name|S6
block|{}
struct|;
end_struct

begin_comment
comment|/* expected-warning {{__declspec attribute 'unknown' is not supported}}*/
end_comment

begin_decl_stmt
name|int
modifier|*
name|__sptr
name|psp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|__uptr
name|pup
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Either ordering is acceptable */
end_comment

begin_decl_stmt
name|int
modifier|*
name|__ptr32
name|__sptr
name|psp32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|__ptr32
name|__uptr
name|pup32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|__sptr
name|__ptr64
name|psp64
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|__uptr
name|__ptr64
name|pup64
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Legal to have nested pointer attributes */
end_comment

begin_decl_stmt
name|int
modifier|*
name|__sptr
modifier|*
name|__ptr32
name|ppsp32
decl_stmt|;
end_decl_stmt

end_unit

