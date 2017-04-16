begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Tests that clang does not crash with invalid architectures in target triples.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: not %clang -target powerpc64le-linux-gnu -faltivec -o %t.o %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t.err --check-prefix=CHECK-NOFALTIVEC %s
end_comment

begin_comment
comment|// CHECK-NOFALTIVEC: error: the clang compiler does not support 'faltivec', please use -maltivec and include altivec.h explicitly
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: not %clang -target powerpc64le-linux-gnu -fno-altivec -o %t.o %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t.err --check-prefix=CHECK-NOFNOALTIVEC %s
end_comment

begin_comment
comment|// CHECK-NOFNOALTIVEC: error: the clang compiler does not support 'fno-altivec', please use -mno-altivec
end_comment

end_unit

