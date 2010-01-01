begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -fms-extensions -x objective-c++ %s
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

end_unit

