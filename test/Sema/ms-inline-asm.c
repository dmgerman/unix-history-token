begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-apple-darwin10 -fasm-blocks -Wno-microsoft -verify -fsyntax-only
end_comment

begin_function
name|void
name|t1
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm
asm|__asm
comment|//
asm|expected-error {{__asm used with no assembly instructions}}
block|}
end_function

begin_function
name|void
name|f
parameter_list|()
block|{
name|int
name|foo
decl_stmt|;
asm|__asm {
asm|mov eax, eax
asm|.unknowndirective
comment|//
asm|expected-error {{unknown directive}}
asm|}
name|f
argument_list|()
expr_stmt|;
asm|__asm {
asm|mov eax, 1+=2
comment|//
asm|expected-error {{unknown token in expression}}
asm|}
name|f
argument_list|()
expr_stmt|;
asm|__asm {
asm|mov eax, 1+++
comment|//
asm|expected-error {{unknown token in expression}}
asm|}
name|f
argument_list|()
expr_stmt|;
asm|__asm {
asm|mov eax, LENGTH bar
comment|//
asm|expected-error {{unable to lookup expression}}
asm|}
name|f
argument_list|()
expr_stmt|;
asm|__asm {
asm|mov eax, SIZE bar
comment|//
asm|expected-error {{unable to lookup expression}}
asm|}
name|f
argument_list|()
expr_stmt|;
asm|__asm {
asm|mov eax, TYPE bar
comment|//
asm|expected-error {{unable to lookup expression}}
asm|}
block|}
end_function

begin_function
name|void
name|rdar15318432
parameter_list|(
name|void
parameter_list|)
block|{
comment|// We used to crash on this.  When LLVM called back to Clang to parse a name
comment|// and do name lookup, if parsing failed, we did not restore the lexer state
comment|// properly.
asm|__asm {
asm|and ecx, ~15
asm|}
name|int
name|x
init|=
literal|0
decl_stmt|;
asm|__asm {
asm|and ecx, x
asm|and ecx, ~15
asm|}
block|}
end_function

begin_decl_stmt
specifier|static
name|int
name|global
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|t2
parameter_list|(
name|int
modifier|*
name|arr
parameter_list|,
name|int
name|i
parameter_list|)
block|{
asm|__asm {
asm|mov eax, arr;
asm|mov eax, arr[0];
asm|mov eax, arr[1 + 2];
asm|mov eax, arr[1 + (2 * 5) - 3 + 1<<1];
asm|}
comment|// expected-error@+1 {{cannot use base register with variable reference}}
asm|__asm mov eax, arr[ebp + 1 + (2 * 5) - 3 + 1<<1]
comment|// expected-error@+1 {{cannot use index register with variable reference}}
asm|__asm mov eax, arr[esi * 4]
comment|// expected-error@+1 {{cannot use more than one symbol in memory operand}}
asm|__asm mov eax, arr[i]
comment|// expected-error@+1 {{cannot use more than one symbol in memory operand}}
asm|__asm mov eax, global[i]
comment|// FIXME: Why don't we diagnose this?
comment|// expected-Xerror@+1 {{cannot reference multiple local variables in assembly operand}}
comment|//__asm mov eax, [arr + i];
return|return
literal|0
return|;
block|}
end_function

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
name|A
typedef|;
end_typedef

begin_function
name|void
name|t3
parameter_list|()
block|{
asm|__asm mov eax, [eax] UndeclaredId
comment|//
asm|expected-error {{unknown token in expression}}
comment|// FIXME: Only emit one diagnostic here.
comment|// expected-error@+2 {{unexpected type name 'A': expected expression}}
comment|// expected-error@+1 {{unknown token in expression}}
asm|__asm mov eax, [eax] A
block|}
end_function

begin_function
name|void
name|t4
parameter_list|()
block|{
comment|// The dot in the "intel dot operator" is optional in MSVC.  MSVC also does
comment|// global field lookup, but we don't.
asm|__asm mov eax, [0] A.a
asm|__asm mov eax, [0].A.a
asm|__asm mov eax, [0].a
comment|//
asm|expected-error {{Unable to lookup field reference!}}
asm|__asm mov eax, fs:[0] A.a
asm|__asm mov eax, fs:[0].A.a
asm|__asm mov eax, fs:[0].a
comment|//
asm|expected-error {{Unable to lookup field reference!}}
asm|__asm mov eax, fs:[0]. A.a
comment|//
asm|expected-error {{Unexpected token type!}}
block|}
end_function

end_unit

