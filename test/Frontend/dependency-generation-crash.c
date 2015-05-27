begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -E -dependency-file bla -MT %t/doesnotexist/bla.o -MP -o %t/doesnotexist/bla.o -x c /dev/null 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: error: unable to open output file
end_comment

begin_comment
comment|// rdar://9286457
end_comment

end_unit

