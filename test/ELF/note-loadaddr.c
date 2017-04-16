begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86
end_comment

begin_comment
comment|// RUN: llvm-mc -filetype=obj -triple=x86_64-pc-linux %s -o %t.o
end_comment

begin_comment
comment|// RUN: echo "SECTIONS { \
end_comment

begin_comment
comment|// RUN:  .note.a : AT(0x1000) { *(.note.a) } \
end_comment

begin_comment
comment|// RUN:  .note.b : AT(0x2000) { *(.note.b) } \
end_comment

begin_comment
comment|// RUN: }"> %t.script
end_comment

begin_comment
comment|// RUN: ld.lld %t.o --script %t.script -o %t
end_comment

begin_comment
comment|// RUN: llvm-readobj -program-headers %t | FileCheck %s
end_comment

begin_comment
comment|// CHECK:      Type: PT_NOTE
end_comment

begin_comment
comment|// CHECK-NEXT: Offset: 0x1000
end_comment

begin_comment
comment|// CHECK-NEXT: VirtualAddress: 0x0
end_comment

begin_comment
comment|// CHECK-NEXT: PhysicalAddress: 0x1000
end_comment

begin_comment
comment|// CHECK-NEXT: FileSize: 8
end_comment

begin_comment
comment|// CHECK-NEXT: MemSize: 8
end_comment

begin_comment
comment|// CHECK-NEXT:   Flags [
end_comment

begin_comment
comment|// CHECK-NEXT:   PF_R
end_comment

begin_comment
comment|// CHECK-NEXT: ]
end_comment

begin_comment
comment|// CHECK-NEXT: Alignment: 1
end_comment

begin_comment
comment|// CHECK:      Type: PT_NOTE
end_comment

begin_comment
comment|// CHECK-NEXT: Offset: 0x1008
end_comment

begin_comment
comment|// CHECK-NEXT: VirtualAddress: 0x8
end_comment

begin_comment
comment|// CHECK-NEXT: PhysicalAddress: 0x2000
end_comment

begin_comment
comment|// CHECK-NEXT: FileSize: 8
end_comment

begin_comment
comment|// CHECK-NEXT: MemSize: 8
end_comment

begin_comment
comment|// CHECK-NEXT:   Flags [
end_comment

begin_comment
comment|// CHECK-NEXT:   PF_R
end_comment

begin_comment
comment|// CHECK-NEXT: ]
end_comment

begin_comment
comment|// CHECK-NEXT: Alignment: 1
end_comment

begin_expr_stmt
operator|.
name|section
operator|.
name|note
operator|.
name|a
operator|,
literal|"a"
operator|,
expr_stmt|@
name|note
operator|.
name|quad
literal|0
operator|.
name|section
operator|.
name|note
operator|.
name|b
operator|,
literal|"a"
operator|,
expr_stmt|@
name|note
operator|.
name|quad
literal|0
end_expr_stmt

end_unit

