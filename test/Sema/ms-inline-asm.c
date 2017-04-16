begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-apple-darwin10 -fms-extensions -fasm-blocks -Wno-microsoft -Wunused-label -verify -fsyntax-only
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
asm|expected-error {{unable to lookup expression}} expected-error {{use of undeclared label 'bar'}}
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
asm|__asm {
asm|mov eax, arr[ebp + 1 + (2 * 5) - 3 + 1<<1]
asm|}
comment|// expected-error@+1 {{cannot use index register with variable reference}}
asm|__asm {
asm|mov eax, arr[esi * 4]
asm|}
comment|// expected-error@+1 {{cannot use more than one symbol in memory operand}}
asm|__asm {
asm|mov eax, arr[i]
asm|}
comment|// expected-error@+1 {{cannot use more than one symbol in memory operand}}
asm|__asm {
asm|mov eax, global[i]
asm|}
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
asm|__asm {
asm|mov eax, [eax] UndeclaredId
asm|}
comment|// expected-error {{unknown token in expression}} expected-error {{use of undeclared label 'UndeclaredId'}}
comment|// FIXME: Only emit one diagnostic here.
comment|// expected-error@+3 {{use of undeclared label 'A'}}
comment|// expected-error@+2 {{unexpected type name 'A': expected expression}}
comment|// expected-error@+1 {{unknown token in expression}}
asm|__asm {
asm|mov eax, [eax] A
asm|}
block|}
end_function

begin_function
name|void
name|t4
parameter_list|()
block|{
comment|// The dot in the "intel dot operator" is optional in MSVC.  MSVC also does
comment|// global field lookup, but we don't.
asm|__asm {
asm|mov eax, [0] A.a
asm|}
asm|__asm {
asm|mov eax, [0].A.a
asm|}
asm|__asm {
asm|mov eax, [0].a
asm|}
comment|// expected-error {{Unable to lookup field reference!}}
asm|__asm {
asm|mov eax, fs:[0] A.a
asm|}
asm|__asm {
asm|mov eax, fs:[0].A.a
asm|}
asm|__asm {
asm|mov eax, fs:[0].a
asm|}
comment|// expected-error {{Unable to lookup field reference!}}
asm|__asm {
asm|mov eax, fs:[0]. A.a
asm|}
comment|// expected-error {{Unexpected token type!}}
block|}
end_function

begin_function
name|void
name|test_operand_size
parameter_list|()
block|{
asm|__asm {
asm|call word t4
asm|}
comment|// expected-error {{Expected 'PTR' or 'ptr' token!}}
block|}
end_function

begin_macro
name|__declspec
argument_list|(
argument|naked
argument_list|)
end_macro

begin_function
name|int
name|t5
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// expected-note {{attribute is here}}
name|asm
block|{
name|movl
name|eax
decl_stmt|,
name|x
block|}
comment|// expected-error {{parameter references not allowed in naked functions}} expected-error {{use of undeclared label 'x'}}
name|asm
block|{
name|retl
block|}
block|}
end_function

begin_decl_stmt
name|int
name|y
decl_stmt|;
end_decl_stmt

begin_macro
name|__declspec
argument_list|(
argument|naked
argument_list|)
end_macro

begin_function
name|int
name|t6
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|asm
block|{
name|mov
name|eax
decl_stmt|,
name|y
block|}
comment|// No error.
name|asm
block|{
name|ret
block|}
block|}
end_function

begin_function
name|void
name|t7
parameter_list|()
block|{
asm|__asm {
asm|foo:
comment|//
asm|expected-note {{inline assembly label 'foo' declared here}}
asm|mov eax, 0
asm|}
goto|goto
name|foo
goto|;
comment|// expected-error {{cannot jump from this goto statement to label 'foo' inside an inline assembly block}}
block|}
end_function

begin_function
name|void
name|t8
parameter_list|()
block|{
asm|__asm foo:
comment|//
asm|expected-note {{inline assembly label 'foo' declared here}}
asm|__asm mov eax, 0
goto|goto
name|foo
goto|;
comment|// expected-error {{cannot jump from this goto statement to label 'foo' inside an inline assembly block}}
block|}
end_function

begin_function
name|void
name|t9
parameter_list|()
block|{
goto|goto
name|foo
goto|;
comment|// expected-error {{cannot jump from this goto statement to label 'foo' inside an inline assembly block}}
asm|__asm {
asm|foo:
comment|//
asm|expected-note {{inline assembly label 'foo' declared here}}
asm|mov eax, 0
asm|}
block|}
end_function

begin_function
name|void
name|t10
parameter_list|()
block|{
goto|goto
name|foo
goto|;
comment|// expected-error {{cannot jump from this goto statement to label 'foo' inside an inline assembly block}}
asm|__asm foo:
comment|//
asm|expected-note {{inline assembly label 'foo' declared here}}
asm|__asm mov eax, 0
block|}
end_function

begin_function
name|void
name|t11
parameter_list|()
block|{
name|foo
label|:
asm|__asm mov eax, foo
comment|//
asm|expected-error {{use of undeclared label 'foo'}} expected-warning {{unused label 'foo'}}
block|}
end_function

begin_function
name|void
name|t12
parameter_list|()
block|{
asm|__asm foo:
asm|__asm bar:
comment|//
asm|expected-warning {{unused label 'bar'}}
asm|__asm jmp foo
block|}
end_function

end_unit

