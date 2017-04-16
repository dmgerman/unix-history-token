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
comment|// RUN: not %clang %s -std=foobar -c 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck --match-full-lines %s
end_comment

begin_comment
comment|// CHECK: error: invalid value 'foobar' in '-std=foobar'
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'c89' for 'ISO C 1990' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'c90' for 'ISO C 1990' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'iso9899:1990' for 'ISO C 1990' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'iso9899:199409' for 'ISO C 1990 with amendment 1' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'gnu89' for 'ISO C 1990 with GNU extensions' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'gnu90' for 'ISO C 1990 with GNU extensions' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'c99' for 'ISO C 1999' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'c9x' for 'ISO C 1999' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'iso9899:1999' for 'ISO C 1999' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'iso9899:199x' for 'ISO C 1999' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'gnu99' for 'ISO C 1999 with GNU extensions' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'gnu9x' for 'ISO C 1999 with GNU extensions' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'c11' for 'ISO C 2011' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'c1x' for 'ISO C 2011' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'iso9899:2011' for 'ISO C 2011' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'iso9899:201x' for 'ISO C 2011' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'gnu11' for 'ISO C 2011 with GNU extensions' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'gnu1x' for 'ISO C 2011 with GNU extensions' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'cl' for 'OpenCL 1.0' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'cl1.1' for 'OpenCL 1.1' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'cl1.2' for 'OpenCL 1.2' standard
end_comment

begin_comment
comment|// CHECK-NEXT: note: use 'cl2.0' for 'OpenCL 2.0' standard
end_comment

begin_comment
comment|// Make sure that no other output is present.
end_comment

begin_comment
comment|// CHECK-NOT: {{^.+$}}
end_comment

end_unit

