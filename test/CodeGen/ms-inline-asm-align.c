begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-apple-darwin10 -fasm-blocks -emit-llvm -o - | FileCheck %s --check-prefix=DARWIN
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i686-pc-win32 -fasm-blocks -emit-llvm -o - | FileCheck %s --check-prefix=WINDOWS
end_comment

begin_comment
comment|// On Windows, .align is in bytes, and on Darwin, .align is in log2 form. The
end_comment

begin_comment
comment|// Intel inline assembly parser should rewrite to the appropriate form depending
end_comment

begin_comment
comment|// on the platform.
end_comment

begin_function
name|void
name|align_test
parameter_list|()
block|{
asm|__asm align 8
asm|__asm align 16;
asm|__asm align 128;
asm|__asm ALIGN 256;
block|}
end_function

begin_comment
comment|// DARWIN-LABEL: define void @align_test()
end_comment

begin_comment
comment|// DARWIN: call void asm sideeffect inteldialect
end_comment

begin_comment
comment|// DARWIN-SAME: .align 3
end_comment

begin_comment
comment|// DARWIN-SAME: .align 4
end_comment

begin_comment
comment|// DARWIN-SAME: .align 7
end_comment

begin_comment
comment|// DARWIN-SAME: .align 8
end_comment

begin_comment
comment|// DARWIN-SAME: "~{dirflag},~{fpsr},~{flags}"()
end_comment

begin_comment
comment|// WINDOWS-LABEL: define void @align_test()
end_comment

begin_comment
comment|// WINDOWS: call void asm sideeffect inteldialect
end_comment

begin_comment
comment|// WINDOWS-SAME: .align 8
end_comment

begin_comment
comment|// WINDOWS-SAME: .align 16
end_comment

begin_comment
comment|// WINDOWS-SAME: .align 128
end_comment

begin_comment
comment|// WINDOWS-SAME: .align 256
end_comment

begin_comment
comment|// WINDOWS-SAME: "~{dirflag},~{fpsr},~{flags}"()
end_comment

end_unit

