begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Don't attempt slash switches on msys bash.
end_comment

begin_comment
comment|// REQUIRES: shell-preserves-root
end_comment

begin_comment
comment|// Note: we have to quote the /? option, otherwise some shells will try to
end_comment

begin_comment
comment|// expand the ? into a one-letter filename in the root directory, and make
end_comment

begin_comment
comment|// the test fail is such a file or directory exists.
end_comment

begin_comment
comment|// Note: %s must be preceded by --, otherwise it may be interpreted as a
end_comment

begin_comment
comment|// command-line option, e.g. on Mac where %s is commonly under /Users.
end_comment

begin_comment
comment|// Check that clang-cl options are not available by default.
end_comment

begin_comment
comment|// RUN: %clang -help | FileCheck %s -check-prefix=DEFAULT
end_comment

begin_comment
comment|// DEFAULT-NOT: CL.EXE COMPATIBILITY OPTIONS
end_comment

begin_comment
comment|// DEFAULT-NOT: {{/[?]}}
end_comment

begin_comment
comment|// DEFAULT-NOT: /help
end_comment

begin_comment
comment|// RUN: not %clang "/?"
end_comment

begin_comment
comment|// RUN: not %clang -?
end_comment

begin_comment
comment|// RUN: not %clang /help
end_comment

begin_comment
comment|// Check that /? and /help are available as clang-cl options.
end_comment

begin_comment
comment|// RUN: %clang_cl "/?" | FileCheck %s -check-prefix=CL
end_comment

begin_comment
comment|// RUN: %clang_cl /help | FileCheck %s -check-prefix=CL
end_comment

begin_comment
comment|// RUN: %clang_cl -help | FileCheck %s -check-prefix=CL
end_comment

begin_comment
comment|// CL: CL.EXE COMPATIBILITY OPTIONS
end_comment

begin_comment
comment|// CL: {{/[?]}}
end_comment

begin_comment
comment|// CL: /help
end_comment

begin_comment
comment|// Options which are not "core" clang options nor cl.exe compatible options
end_comment

begin_comment
comment|// are not available in clang-cl.
end_comment

begin_comment
comment|// DEFAULT: -fapple-kext
end_comment

begin_comment
comment|// CL-NOT: -fapple-kext
end_comment

begin_comment
comment|// RUN: %clang_cl /c -### -- %s 2>&1 | FileCheck -check-prefix=COMPILE %s
end_comment

begin_comment
comment|// COMPILE: "-fdiagnostics-format" "msvc"
end_comment

end_unit

