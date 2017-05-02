begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This file checks output given when processing C/ObjC files.
end_comment

begin_comment
comment|// When user selects invalid language standard
end_comment

begin_comment
comment|// print out supported values with short description.
end_comment

begin_comment
comment|// RUN: not %clang %s -std=foobar -c 2>&1 | FileCheck --match-full-lines %s
end_comment

begin_comment
comment|// RUN: not %clang -x objective-c %s -std=foobar -c 2>&1 | FileCheck --match-full-lines %s
end_comment

begin_comment
comment|// RUN: not %clang -x renderscript %s -std=foobar -c 2>&1 | FileCheck --match-full-lines %s
end_comment

begin_comment
comment|// CHECK: error: invalid value 'foobar' in '-std=foobar'
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'c89', 'c90', or 'iso9899:1990' for 'ISO C 1990' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'iso9899:199409' for 'ISO C 1990 with amendment 1' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'gnu89' or 'gnu90' for 'ISO C 1990 with GNU extensions' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'c99' or 'iso9899:1999' for 'ISO C 1999' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'gnu99' for 'ISO C 1999 with GNU extensions' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'c11' or 'iso9899:2011' for 'ISO C 2011' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'gnu11' for 'ISO C 2011 with GNU extensions' standard
end_comment

begin_comment
comment|// Make sure that no other output is present.
end_comment

begin_comment
comment|// CHECK-NOT: {{^.+$}}
end_comment

end_unit

