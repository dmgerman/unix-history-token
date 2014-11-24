begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -ivfsoverlay foo.h -### %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-ivfsoverlay" "foo.h"
end_comment

begin_comment
comment|// RUN: not %clang -ivfsoverlay foo.h %s 2>&1 | FileCheck -check-prefix=CHECK-MISSING %s
end_comment

begin_comment
comment|// CHECK-MISSING: virtual filesystem overlay file 'foo.h' not found
end_comment

end_unit

