begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple powerpc64-unknown-linux-gnu -fasm-blocks -verify -fsyntax-only
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
asm|__asm nop
comment|//
asm|expected-error {{Unsupported architecture 'powerpc64' for MS-style inline assembly}}
block|}
end_function

end_unit

