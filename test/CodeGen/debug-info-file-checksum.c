begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -emit-llvm -S -g -gcodeview -x c %S/Inputs/debug-info-file-checksum.c -o - | FileCheck %s
end_comment

begin_comment
comment|// Check that "checksum" is created correctly for the compiled file.
end_comment

begin_comment
comment|// CHECK: !DIFile(filename:{{.*}}, directory:{{.*}}, checksumkind: CSK_MD5, checksum: "a3b7d27af071accdeccaa933fc603608")
end_comment

end_unit

