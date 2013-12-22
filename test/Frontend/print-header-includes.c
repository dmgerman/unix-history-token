begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -include Inputs/test3.h -E -H -o %t.out %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck< %t.err %s
end_comment

begin_comment
comment|// CHECK-NOT: test3.h
end_comment

begin_comment
comment|// CHECK: . {{.*test.h}}
end_comment

begin_comment
comment|// CHECK: .. {{.*test2.h}}
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include Inputs/test3.h -E --show-includes -o %t.out %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=MS< %t.err %s
end_comment

begin_comment
comment|// MS-NOT: test3.h
end_comment

begin_comment
comment|// MS: Note: including file: {{.*test.h}}
end_comment

begin_comment
comment|// MS: Note: including file:  {{.*test2.h}}
end_comment

begin_comment
comment|// MS-NOT: Note
end_comment

begin_include
include|#
directive|include
file|"Inputs/test.h"
end_include

end_unit

