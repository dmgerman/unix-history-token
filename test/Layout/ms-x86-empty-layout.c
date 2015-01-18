begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fno-rtti -emit-llvm-only -triple i686-pc-win32 -fdump-record-layouts -fsyntax-only %s 2>/dev/null \
end_comment

begin_comment
comment|// RUN:            | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fno-rtti -emit-llvm-only -triple x86_64-pc-win32 -fdump-record-layouts -fsyntax-only %s 2>/dev/null \
end_comment

begin_comment
comment|// RUN:            | FileCheck %s
end_comment

begin_struct
struct|struct
name|EmptyIntMemb
block|{
name|int
name|FlexArrayMemb
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: *** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK: Type: struct EmptyIntMemb
end_comment

begin_comment
comment|// CHECK: Record:
end_comment

begin_comment
comment|// CHECK: Layout:<ASTRecordLayout
end_comment

begin_comment
comment|// CHECK:     Size:32
end_comment

begin_comment
comment|// CHECK:     Alignment:32
end_comment

begin_comment
comment|// CHECK:     FieldOffsets: [0]>
end_comment

begin_struct
struct|struct
name|EmptyLongLongMemb
block|{
name|long
name|long
name|FlexArrayMemb
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: *** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK: Type: struct EmptyLongLongMemb
end_comment

begin_comment
comment|// CHECK: Record:
end_comment

begin_comment
comment|// CHECK: Layout:<ASTRecordLayout
end_comment

begin_comment
comment|// CHECK:     Size:32
end_comment

begin_comment
comment|// CHECK:     Alignment:64
end_comment

begin_comment
comment|// CHECK:     FieldOffsets: [0]>
end_comment

begin_struct
struct|struct
name|EmptyAligned2LongLongMemb
block|{
name|long
name|long
name|__declspec
argument_list|(
name|align
argument_list|(
literal|2
argument_list|)
argument_list|)
name|FlexArrayMemb
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: *** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK: Type: struct EmptyAligned2LongLongMemb
end_comment

begin_comment
comment|// CHECK: Record:
end_comment

begin_comment
comment|// CHECK: Layout:<ASTRecordLayout
end_comment

begin_comment
comment|// CHECK:     Size:32
end_comment

begin_comment
comment|// CHECK:     Alignment:64
end_comment

begin_comment
comment|// CHECK:     FieldOffsets: [0]>
end_comment

begin_struct
struct|struct
name|EmptyAligned8LongLongMemb
block|{
name|long
name|long
name|__declspec
argument_list|(
name|align
argument_list|(
literal|8
argument_list|)
argument_list|)
name|FlexArrayMemb
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: *** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK: Type: struct EmptyAligned8LongLongMemb
end_comment

begin_comment
comment|// CHECK: Record:
end_comment

begin_comment
comment|// CHECK: Layout:<ASTRecordLayout
end_comment

begin_comment
comment|// CHECK:     Size:64
end_comment

begin_comment
comment|// CHECK:     Alignment:64
end_comment

begin_comment
comment|// CHECK:     FieldOffsets: [0]>
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_struct
struct|struct
name|__declspec
argument_list|(
argument|align(
literal|4
argument|)
argument_list|)
name|EmptyPackedAligned4LongLongMemb
block|{
name|long
name|long
name|FlexArrayMemb
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|// CHECK: *** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK: Type: struct EmptyPackedAligned4LongLongMemb
end_comment

begin_comment
comment|// CHECK: Record:
end_comment

begin_comment
comment|// CHECK: Layout:<ASTRecordLayout
end_comment

begin_comment
comment|// CHECK:     Size:32
end_comment

begin_comment
comment|// CHECK:     Alignment:32
end_comment

begin_comment
comment|// CHECK:     FieldOffsets: [0]>
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_struct
struct|struct
name|EmptyPackedAligned8LongLongMemb
block|{
name|long
name|long
name|__declspec
argument_list|(
name|align
argument_list|(
literal|8
argument_list|)
argument_list|)
name|FlexArrayMemb
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|// CHECK: *** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK: Type: struct EmptyPackedAligned8LongLongMemb
end_comment

begin_comment
comment|// CHECK: Record:
end_comment

begin_comment
comment|// CHECK: Layout:<ASTRecordLayout
end_comment

begin_comment
comment|// CHECK:     Size:64
end_comment

begin_comment
comment|// CHECK:     Alignment:64
end_comment

begin_comment
comment|// CHECK:     FieldOffsets: [0]>
end_comment

begin_decl_stmt
name|int
name|a
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|EmptyIntMemb
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|EmptyLongLongMemb
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|EmptyAligned2LongLongMemb
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|EmptyAligned8LongLongMemb
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|EmptyPackedAligned4LongLongMemb
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|EmptyPackedAligned8LongLongMemb
argument_list|)
operator|+
literal|0
index|]
decl_stmt|;
end_decl_stmt

end_unit

