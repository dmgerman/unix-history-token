begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios7.1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
asm|asm
specifier|volatile
asm|("USE(%0)" :: "z"(0LL));
asm|asm
specifier|volatile
asm|("USE(%x0)" :: "z"(0LL));
asm|asm
specifier|volatile
asm|("USE(%w0)" :: "z"(0));
block|}
end_function

end_unit

