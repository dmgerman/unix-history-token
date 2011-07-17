begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: shell
end_comment

begin_comment
comment|// Basic test
end_comment

begin_comment
comment|// RUN: rm -rf %t.dir
end_comment

begin_comment
comment|// RUN: mkdir -p %t.dir/a/b
end_comment

begin_comment
comment|// RUN: echo> %t.dir/a/b/x.h
end_comment

begin_comment
comment|// RUN: cd %t.dir
end_comment

begin_comment
comment|// RUN: %clang -MD -MF - %s -fsyntax-only -I a/b | FileCheck -check-prefix=CHECK-ONE %s
end_comment

begin_comment
comment|// CHECK-ONE: {{ }}a/b/x.h
end_comment

begin_comment
comment|// PR8974 (-include flag)
end_comment

begin_comment
comment|// RUN: %clang -MD -MF - %s -fsyntax-only -include a/b/x.h -DINCLUDE_FLAG_TEST | FileCheck -check-prefix=CHECK-TWO %s
end_comment

begin_comment
comment|// CHECK-TWO: {{ }}a/b/x.h
end_comment

begin_comment
comment|// rdar://problem/9734352 (paths involving ".")
end_comment

begin_comment
comment|// RUN: %clang -MD -MF - %s -fsyntax-only -I ./a/b | FileCheck -check-prefix=CHECK-THREE %s
end_comment

begin_comment
comment|// CHECK-THREE: {{ }}a/b/x.h
end_comment

begin_comment
comment|// RUN: %clang -MD -MF - %s -fsyntax-only -I .//./a/b/ | FileCheck -check-prefix=CHECK-FOUR %s
end_comment

begin_comment
comment|// CHECK-FOUR: {{ }}a/b/x.h
end_comment

begin_comment
comment|// RUN: %clang -MD -MF - %s -fsyntax-only -I a/b/. | FileCheck -check-prefix=CHECK-FIVE %s
end_comment

begin_comment
comment|// CHECK-FIVE: {{ }}a/b/./x.h
end_comment

begin_comment
comment|// RUN: cd a/b
end_comment

begin_comment
comment|// RUN: %clang -MD -MF - %s -fsyntax-only -I ./ | FileCheck -check-prefix=CHECK-SIX %s
end_comment

begin_comment
comment|// CHECK-SIX: {{ }}x.h
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INCLUDE_FLAG_TEST
end_ifndef

begin_include
include|#
directive|include
file|<x.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

