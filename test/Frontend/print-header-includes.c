begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -I%S -include Inputs/test3.h -E -H -o /dev/null %s 2> %t.stderr
end_comment

begin_comment
comment|// RUN: FileCheck< %t.stderr %s
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
comment|// RUN: %clang_cc1 -I%S -include Inputs/test3.h -E --show-includes -o /dev/null %s | \
end_comment

begin_comment
comment|// RUN:     FileCheck --strict-whitespace --check-prefix=MS %s
end_comment

begin_comment
comment|// MS-NOT:<command line>
end_comment

begin_comment
comment|// MS: Note: including file: {{[^ ]*test3.h}}
end_comment

begin_comment
comment|// MS: Note: including file: {{[^ ]*test.h}}
end_comment

begin_comment
comment|// MS: Note: including file:  {{[^ ]*test2.h}}
end_comment

begin_comment
comment|// MS-NOT: Note
end_comment

begin_comment
comment|// RUN: echo "fun:foo"> %t.blacklist
end_comment

begin_comment
comment|// RUN: %clang_cc1 -I%S -fsanitize=address -fdepfile-entry=%t.blacklist -E --show-includes -o /dev/null %s | \
end_comment

begin_comment
comment|// RUN:     FileCheck --strict-whitespace --check-prefix=MS-BLACKLIST %s
end_comment

begin_comment
comment|// MS-BLACKLIST: Note: including file: {{[^ ]*\.blacklist}}
end_comment

begin_comment
comment|// MS-BLACKLIST: Note: including file: {{[^ ]*test.h}}
end_comment

begin_comment
comment|// MS-BLACKLIST: Note: including file:  {{[^ ]*test2.h}}
end_comment

begin_comment
comment|// MS-BLACKLIST-NOT: Note
end_comment

begin_include
include|#
directive|include
file|"Inputs/test.h"
end_include

end_unit

