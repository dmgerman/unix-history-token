begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that the montavista gcc-toolchain is correctly detected
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -print-libgcc-file-name 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i686-montavista-linux \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/montavista_i686_tree/usr \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s
end_comment

begin_comment
comment|// Test for header search toolchain detection.
end_comment

begin_comment
comment|// CHECK: montavista_i686_tree/usr/lib/gcc/i686-montavista-linux/4.2.0{{/|\\}}libgcc.a
end_comment

end_unit

