begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: mkdir -p %t.dir
end_comment

begin_comment
comment|// RUN: echo '#include "header2.h"'> %t.dir/header1.h
end_comment

begin_comment
comment|// RUN: echo> %t.dir/header2.h
end_comment

begin_comment
comment|// RUN: cp %s %t.dir/t.c
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c-header %t.dir/header1.h -emit-pch -o %t.pch
end_comment

begin_comment
comment|// RUN: echo>> %t.dir/header2.h
end_comment

begin_comment
comment|// RUN: not %clang_cc1 %t.dir/t.c -include-pch %t.pch -fsyntax-only 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"header2.h"
end_include

begin_comment
comment|// CHECK: fatal error: file {{.*}} has been modified since the precompiled header {{.*}} was built
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

end_unit

