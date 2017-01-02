begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -frewrite-map-file %t.map -c %s -o /dev/null 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: error: no such file or directory:
end_comment

end_unit

