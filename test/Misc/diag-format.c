begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fsyntax-only  %s 2>&1 | FileCheck %s -check-prefix=DEFAULT
end_comment

begin_comment
comment|// RUN: %clang -fsyntax-only -fdiagnostics-format=clang %s 2>&1 | FileCheck %s -check-prefix=DEFAULT
end_comment

begin_comment
comment|// RUN: %clang -fsyntax-only -fdiagnostics-format=clang -target x86_64-pc-win32 %s 2>&1 | FileCheck %s -check-prefix=DEFAULT
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -fsyntax-only -fdiagnostics-format=msvc  %s 2>&1 | FileCheck %s -check-prefix=MSVC
end_comment

begin_comment
comment|// RUN: %clang -fsyntax-only -fdiagnostics-format=msvc -target x86_64-pc-win32 %s 2>&1 | FileCheck %s -check-prefix=MSVC
end_comment

begin_comment
comment|// RUN: %clang -fsyntax-only -fdiagnostics-format=msvc -target x86_64-pc-win32 -fshow-column %s 2>&1 | FileCheck %s -check-prefix=MSVC
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -fsyntax-only -fdiagnostics-format=vi    %s 2>&1 | FileCheck %s -check-prefix=VI
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -fsyntax-only -fdiagnostics-format=msvc -fno-show-column %s 2>&1 | FileCheck %s -check-prefix=MSVC_ORIG
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -fsyntax-only -fno-show-column %s 2>&1 | FileCheck %s -check-prefix=NO_COLUMN
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: not %clang -fsyntax-only -Werror -fdiagnostics-format=msvc-fallback %s 2>&1 | FileCheck %s -check-prefix=MSVC-FALLBACK
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|foo
end_ifdef

begin_endif
endif|#
directive|endif
endif|bad
end_endif

begin_comment
comment|// extension!
end_comment

begin_comment
comment|// DEFAULT: {{.*}}:28:8: warning: extra tokens at end of #endif directive [-Wextra-tokens]
end_comment

begin_comment
comment|// MSVC: {{.*}}(28,7) : warning: extra tokens at end of #endif directive [-Wextra-tokens]
end_comment

begin_comment
comment|// VI: {{.*}} +28:8: warning: extra tokens at end of #endif directive [-Wextra-tokens]
end_comment

begin_comment
comment|// MSVC_ORIG: {{.*}}(28) : warning: extra tokens at end of #endif directive [-Wextra-tokens]
end_comment

begin_comment
comment|// NO_COLUMN: {{.*}}:28: warning: extra tokens at end of #endif directive [-Wextra-tokens]
end_comment

begin_comment
comment|// MSVC-FALLBACK: {{.*}}(28,7) : error(clang): extra tokens at end of #endif directive
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

end_unit

