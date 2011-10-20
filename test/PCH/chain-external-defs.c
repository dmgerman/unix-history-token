begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin9 -emit-pch -o %t1.pch %S/Inputs/chain-external-defs1.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin9 -emit-pch -o %t2.pch %S/Inputs/chain-external-defs2.h -include-pch %t1.pch
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin9 -include-pch %t2.pch -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: echo FINI>> %t
end_comment

begin_comment
comment|// RUN: FileCheck -input-file=%t -check-prefix=Z %s
end_comment

begin_comment
comment|// RUN: FileCheck -input-file=%t -check-prefix=XA %s
end_comment

begin_comment
comment|// RUN: FileCheck -input-file=%t -check-prefix=YA %s
end_comment

begin_comment
comment|// RUN: FileCheck -input-file=%t -check-prefix=XB %s
end_comment

begin_comment
comment|// RUN: FileCheck -input-file=%t -check-prefix=YB %s
end_comment

begin_comment
comment|// RUN: FileCheck -input-file=%t -check-prefix=AA %s
end_comment

begin_comment
comment|// RUN: FileCheck -input-file=%t -check-prefix=AB %s
end_comment

begin_comment
comment|// RUN: FileCheck -input-file=%t -check-prefix=AC %s
end_comment

begin_comment
comment|// RUN: FileCheck -input-file=%t -check-prefix=S %s
end_comment

begin_comment
comment|// Z-NOT: @z
end_comment

begin_comment
comment|// XA: @x = common global i32 0
end_comment

begin_comment
comment|// XA-NOT: @x = common global i32 0
end_comment

begin_comment
comment|// YA: @y = common global i32 0
end_comment

begin_comment
comment|// YA-NOT: @y = common global i32 0
end_comment

begin_comment
comment|// XB: @x2 = global i32 19
end_comment

begin_comment
comment|// XB-NOT: @x2 = global i32 19
end_comment

begin_decl_stmt
name|int
name|x2
init|=
literal|19
decl_stmt|;
end_decl_stmt

begin_comment
comment|// YB: @y2 = global i32 18
end_comment

begin_comment
comment|// YB-NOT: @y2 = global i32 18
end_comment

begin_decl_stmt
name|int
name|y2
init|=
literal|18
decl_stmt|;
end_decl_stmt

begin_comment
comment|// AA: @incomplete_array = common global [1 x i32]
end_comment

begin_comment
comment|// AA-NOT: @incomplete_array = common global [1 x i32]
end_comment

begin_comment
comment|// AB: @incomplete_array2 = common global [17 x i32]
end_comment

begin_comment
comment|// AB-NOT: @incomplete_array2 = common global [17 x i32]
end_comment

begin_decl_stmt
name|int
name|incomplete_array2
index|[
literal|17
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// AC: @incomplete_array3 = common global [1 x i32]
end_comment

begin_comment
comment|// AC-NOT: @incomplete_array3 = common global [1 x i32]
end_comment

begin_decl_stmt
name|int
name|incomplete_array3
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// S: @s = common global %struct.S
end_comment

begin_comment
comment|// S-NOT: @s = common global %struct.S
end_comment

begin_struct
struct|struct
name|S
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// Z: FINI
end_comment

begin_comment
comment|// XA: FINI
end_comment

begin_comment
comment|// YA: FINI
end_comment

begin_comment
comment|// XB: FINI
end_comment

begin_comment
comment|// YB: FINI
end_comment

begin_comment
comment|// AA: FINI
end_comment

begin_comment
comment|// AB: FINI
end_comment

begin_comment
comment|// AC: FINI
end_comment

begin_comment
comment|// S: FINI
end_comment

end_unit

