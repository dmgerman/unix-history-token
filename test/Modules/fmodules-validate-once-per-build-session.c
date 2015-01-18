begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"foo.h"
end_include

begin_comment
comment|// Clear the module cache.
end_comment

begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir -p %t/Inputs
end_comment

begin_comment
comment|// RUN: mkdir -p %t/modules-to-compare
end_comment

begin_comment
comment|// ===
end_comment

begin_comment
comment|// Create a module.  We will use -I or -isystem to determine whether to treat
end_comment

begin_comment
comment|// foo.h as a system header.
end_comment

begin_comment
comment|// RUN: echo 'void meow(void);'> %t/Inputs/foo.h
end_comment

begin_comment
comment|// RUN: echo 'module Foo { header "foo.h" }'> %t/Inputs/module.map
end_comment

begin_comment
comment|// ===
end_comment

begin_comment
comment|// Compile the module.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -cc1 -fmodules -fdisable-module-hash -fmodules-cache-path=%t/modules-cache -fsyntax-only -isystem %t/Inputs -fbuild-session-timestamp=1390000000 -fmodules-validate-once-per-build-session %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -cc1 -fmodules -fdisable-module-hash -fmodules-cache-path=%t/modules-cache-user -fsyntax-only -I %t/Inputs -fbuild-session-timestamp=1390000000 -fmodules-validate-once-per-build-session %s
end_comment

begin_comment
comment|// RUN: ls -R %t/modules-cache | grep Foo.pcm.timestamp
end_comment

begin_comment
comment|// RUN: ls -R %t/modules-cache-user | grep Foo.pcm.timestamp
end_comment

begin_comment
comment|// RUN: cp %t/modules-cache/Foo.pcm %t/modules-to-compare/Foo-before.pcm
end_comment

begin_comment
comment|// RUN: cp %t/modules-cache-user/Foo.pcm %t/modules-to-compare/Foo-before-user.pcm
end_comment

begin_comment
comment|// ===
end_comment

begin_comment
comment|// Use it, and make sure that we did not recompile it.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -cc1 -fmodules -fdisable-module-hash -fmodules-cache-path=%t/modules-cache -fsyntax-only -isystem %t/Inputs -fbuild-session-timestamp=1390000000 -fmodules-validate-once-per-build-session %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -cc1 -fmodules -fdisable-module-hash -fmodules-cache-path=%t/modules-cache-user -fsyntax-only -I %t/Inputs -fbuild-session-timestamp=1390000000 -fmodules-validate-once-per-build-session %s
end_comment

begin_comment
comment|// RUN: ls -R %t/modules-cache | grep Foo.pcm.timestamp
end_comment

begin_comment
comment|// RUN: ls -R %t/modules-cache-user | grep Foo.pcm.timestamp
end_comment

begin_comment
comment|// RUN: cp %t/modules-cache/Foo.pcm %t/modules-to-compare/Foo-after.pcm
end_comment

begin_comment
comment|// RUN: cp %t/modules-cache-user/Foo.pcm %t/modules-to-compare/Foo-after-user.pcm
end_comment

begin_comment
comment|// RUN: diff %t/modules-to-compare/Foo-before.pcm %t/modules-to-compare/Foo-after.pcm
end_comment

begin_comment
comment|// RUN: diff %t/modules-to-compare/Foo-before-user.pcm %t/modules-to-compare/Foo-after-user.pcm
end_comment

begin_comment
comment|// ===
end_comment

begin_comment
comment|// Change the sources.
end_comment

begin_comment
comment|// RUN: echo 'void meow2(void);'> %t/Inputs/foo.h
end_comment

begin_comment
comment|// ===
end_comment

begin_comment
comment|// Use the module, and make sure that we did not recompile it if foo.h is a
end_comment

begin_comment
comment|// system header, even though the sources changed.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -cc1 -fmodules -fdisable-module-hash -fmodules-cache-path=%t/modules-cache -fsyntax-only -isystem %t/Inputs -fbuild-session-timestamp=1390000000 -fmodules-validate-once-per-build-session %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -cc1 -fmodules -fdisable-module-hash -fmodules-cache-path=%t/modules-cache-user -fsyntax-only -I %t/Inputs -fbuild-session-timestamp=1390000000 -fmodules-validate-once-per-build-session %s
end_comment

begin_comment
comment|// RUN: ls -R %t/modules-cache | grep Foo.pcm.timestamp
end_comment

begin_comment
comment|// RUN: ls -R %t/modules-cache-user | grep Foo.pcm.timestamp
end_comment

begin_comment
comment|// RUN: cp %t/modules-cache/Foo.pcm %t/modules-to-compare/Foo-after.pcm
end_comment

begin_comment
comment|// RUN: cp %t/modules-cache-user/Foo.pcm %t/modules-to-compare/Foo-after-user.pcm
end_comment

begin_comment
comment|// RUN: diff %t/modules-to-compare/Foo-before.pcm %t/modules-to-compare/Foo-after.pcm
end_comment

begin_comment
comment|// When foo.h is a user header, we will always validate it.
end_comment

begin_comment
comment|// RUN: not diff %t/modules-to-compare/Foo-before-user.pcm %t/modules-to-compare/Foo-after-user.pcm
end_comment

begin_comment
comment|// ===
end_comment

begin_comment
comment|// Recompile the module if the today's date is before 01 January 2030.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -cc1 -fmodules -fdisable-module-hash -fmodules-cache-path=%t/modules-cache -fsyntax-only -isystem %t/Inputs -fbuild-session-timestamp=1893456000 -fmodules-validate-once-per-build-session %s
end_comment

begin_comment
comment|// RUN: ls -R %t/modules-cache | grep Foo.pcm.timestamp
end_comment

begin_comment
comment|// RUN: cp %t/modules-cache/Foo.pcm %t/modules-to-compare/Foo-after.pcm
end_comment

begin_comment
comment|// RUN: not diff %t/modules-to-compare/Foo-before.pcm %t/modules-to-compare/Foo-after.pcm
end_comment

end_unit

