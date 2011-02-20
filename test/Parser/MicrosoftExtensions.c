begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-mingw32 -fsyntax-only -verify -fms-extensions  -Wno-missing-declarations -x objective-c++ %s
end_comment

begin_function_decl
name|__stdcall
name|int
name|func0
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__stdcall
name|func
parameter_list|()
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
parameter_list|()
function_decl|;
end_typedef

begin_function_decl
name|void
function_decl|(
modifier|*
name|__fastcall
name|fastpfunc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|__declspec
argument_list|(
name|uuid
argument_list|(
literal|"00000000-0000-0000-C000-000000000046"
argument_list|)
argument_list|)
name|__declspec
argument_list|(
name|novtable
argument_list|)
name|IUnknown
block|{}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern __declspec(dllimport
end_extern

begin_function_decl
unit|)
name|void
name|__stdcall
name|VarR4FromDec
parameter_list|()
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
name|__forceinline
name|InterlockedBitTestAndSet
parameter_list|(
name|long
modifier|*
name|Base
parameter_list|,
name|long
name|Bit
parameter_list|)
block|{
asm|__asm {
asm|mov eax, Bit
asm|mov ecx, Base
asm|lock bts [ecx], eax
asm|setc al
asm|};
block|}
end_function

begin_function
name|_inline
name|int
name|foo99
parameter_list|()
block|{
return|return
literal|99
return|;
block|}
end_function

begin_function_decl
name|void
modifier|*
name|_alloca
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|()
block|{
name|__declspec
argument_list|(
argument|align(
literal|16
argument|)
argument_list|)
name|int
modifier|*
name|buffer
init|=
operator|(
name|int
operator|*
operator|)
name|_alloca
argument_list|(
literal|9
argument_list|)
decl_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|bool
function_decl|(
name|__stdcall
name|__stdcall
modifier|*
name|blarg
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_function
name|void
name|local_callconv
parameter_list|()
block|{
name|bool
function_decl|(
name|__stdcall
modifier|*
name|p
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
block|}
end_function

begin_comment
comment|// Charify extension.
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

begin_comment
comment|/* Microsoft attribute tests */
end_comment

begin_expr_stmt
index|[
name|repeatable
index|]
index|[
name|source_annotation_attribute
argument_list|(
name|Parameter
operator||
name|ReturnValue
argument_list|)
index|]
expr|struct
name|SA_Post
block|{
name|SA_Post
argument_list|()
block|;
name|int
name|attr
block|; }
expr_stmt|;
end_expr_stmt

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
block|}
end_function

end_unit

