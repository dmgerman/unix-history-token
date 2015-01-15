begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Don't attempt slash switches on msys bash.
end_comment

begin_comment
comment|// REQUIRES: shell-preserves-root
end_comment

begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// We support -m32 and -m64.  We support all x86 CPU feature flags in gcc's -m
end_comment

begin_comment
comment|// flag space.
end_comment

begin_comment
comment|// RUN: %clang_cl /Zs /WX -m32 -m64 -msse3 -msse4.1 -mavx -mno-avx \
end_comment

begin_comment
comment|// RUN:     --target=i386-pc-win32 -### -- 2>&1 %s | FileCheck -check-prefix=MFLAGS %s
end_comment

begin_comment
comment|// MFLAGS-NOT: argument unused during compilation
end_comment

begin_comment
comment|// -arch:IA32 is no-op.
end_comment

begin_comment
comment|// RUN: %clang_cl -m32 -arch:IA32 --target=i386 -### -- 2>&1 %s | FileCheck -check-prefix=IA32 %s
end_comment

begin_comment
comment|// IA32-NOT: argument unused during compilation
end_comment

begin_comment
comment|// IA32-NOT: -target-feature
end_comment

begin_comment
comment|// RUN: %clang_cl -m32 -arch:ia32 --target=i386 -### -- 2>&1 %s | FileCheck -check-prefix=ia32 %s
end_comment

begin_comment
comment|// ia32: argument unused during compilation
end_comment

begin_comment
comment|// ia32-NOT: -target-feature
end_comment

begin_comment
comment|// RUN: %clang_cl -m64 -arch:IA32 --target=x86_64 -### -- 2>&1 %s | FileCheck -check-prefix=IA3264 %s
end_comment

begin_comment
comment|// IA3264: argument unused during compilation
end_comment

begin_comment
comment|// IA3264-NOT: -target-feature
end_comment

begin_comment
comment|// RUN: %clang_cl -m32 -arch:SSE --target=i386 -### -- 2>&1 %s | FileCheck -check-prefix=SSE %s
end_comment

begin_comment
comment|// SSE: -target-feature
end_comment

begin_comment
comment|// SSE: +sse
end_comment

begin_comment
comment|// SSE-NOT: argument unused during compilation
end_comment

begin_comment
comment|// RUN: %clang_cl -m32 -arch:sse --target=i386 -### -- 2>&1 %s | FileCheck -check-prefix=sse %s
end_comment

begin_comment
comment|// sse: argument unused during compilation
end_comment

begin_comment
comment|// sse-NOT: -target-feature
end_comment

begin_comment
comment|// RUN: %clang_cl -m32 -arch:SSE2 --target=i386 -### -- 2>&1 %s | FileCheck -check-prefix=SSE2 %s
end_comment

begin_comment
comment|// SSE2: -target-feature
end_comment

begin_comment
comment|// SSE2: +sse2
end_comment

begin_comment
comment|// SSE2-NOT: argument unused during compilation
end_comment

begin_comment
comment|// RUN: %clang_cl -m32 -arch:sse2 --target=i386 -### -- 2>&1 %s | FileCheck -check-prefix=sse %s
end_comment

begin_comment
comment|// sse2: argument unused during compilation
end_comment

begin_comment
comment|// sse2-NOT: -target-feature
end_comment

begin_comment
comment|// RUN: %clang_cl -m64 -arch:SSE --target=x86_64 -### -- 2>&1 %s | FileCheck -check-prefix=SSE64 %s
end_comment

begin_comment
comment|// SSE64: argument unused during compilation
end_comment

begin_comment
comment|// SSE64-NOT: -target-feature
end_comment

begin_comment
comment|// RUN: %clang_cl -m64 -arch:SSE2 --target=x86_64 -### -- 2>&1 %s | FileCheck -check-prefix=SSE264 %s
end_comment

begin_comment
comment|// SSE264: argument unused during compilation
end_comment

begin_comment
comment|// SSE264-NOT: -target-feature
end_comment

begin_comment
comment|// RUN: %clang_cl -m32 -arch:AVX --target=i386 -### -- 2>&1 %s | FileCheck -check-prefix=AVX %s
end_comment

begin_comment
comment|// AVX: -target-feature
end_comment

begin_comment
comment|// AVX: +avx
end_comment

begin_comment
comment|// RUN: %clang_cl -m32 -arch:avx --target=i386 -### -- 2>&1 %s | FileCheck -check-prefix=avx %s
end_comment

begin_comment
comment|// avx: argument unused during compilation
end_comment

begin_comment
comment|// avx-NOT: -target-feature
end_comment

begin_comment
comment|// RUN: %clang_cl -m32 -arch:AVX2 --target=i386 -### -- 2>&1 %s | FileCheck -check-prefix=AVX2 %s
end_comment

begin_comment
comment|// AVX2: -target-feature
end_comment

begin_comment
comment|// AVX2: +avx2
end_comment

begin_comment
comment|// RUN: %clang_cl -m32 -arch:avx2 --target=i386 -### -- 2>&1 %s | FileCheck -check-prefix=avx2 %s
end_comment

begin_comment
comment|// avx2: argument unused during compilation
end_comment

begin_comment
comment|// avx2-NOT: -target-feature
end_comment

begin_comment
comment|// RUN: %clang_cl -m64 -arch:AVX --target=x86_64 -### -- 2>&1 %s | FileCheck -check-prefix=AVX64 %s
end_comment

begin_comment
comment|// AVX64: -target-feature
end_comment

begin_comment
comment|// AVX64: +avx
end_comment

begin_comment
comment|// RUN: %clang_cl -m64 -arch:avx --target=x86_64 -### -- 2>&1 %s | FileCheck -check-prefix=avx64 %s
end_comment

begin_comment
comment|// avx64: argument unused during compilation
end_comment

begin_comment
comment|// avx64-NOT: -target-feature
end_comment

begin_comment
comment|// RUN: %clang_cl -m64 -arch:AVX2 --target=x86_64 -### -- 2>&1 %s | FileCheck -check-prefix=AVX264 %s
end_comment

begin_comment
comment|// AVX264: -target-feature
end_comment

begin_comment
comment|// AVX264: +avx2
end_comment

begin_comment
comment|// RUN: %clang_cl -m64 -arch:avx2 --target=x86_64 -### -- 2>&1 %s | FileCheck -check-prefix=avx264 %s
end_comment

begin_comment
comment|// avx264: argument unused during compilation
end_comment

begin_comment
comment|// avx264-NOT: -target-feature
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{ }
end_function

end_unit

