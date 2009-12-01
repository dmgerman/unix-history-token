begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -emit-llvm -O0 -o - | FileCheck %s
end_comment

begin_comment
comment|// PR 4349
end_comment

begin_union
union|union
name|reg
block|{
name|unsigned
name|char
name|b
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|short
name|w
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|int
name|d
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|cpu
block|{
name|union
name|reg
name|pc
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|cpu
name|cpu
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|svar
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: @svars1 = global [1 x %struct.svar] [%struct.svar { i8* bitcast (%struct.cpu* @cpu to i8*) }]
end_comment

begin_decl_stmt
name|struct
name|svar
name|svars1
index|[]
init|=
block|{
block|{
operator|&
operator|(
operator|(
name|cpu
operator|.
name|pc
operator|)
operator|.
name|w
index|[
literal|0
index|]
operator|)
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @svars2 = global [1 x %struct.svar] [%struct.svar { i8* getelementptr ([2 x i8]* bitcast (%struct.cpu* @cpu to [2 x i8]*), i{{[0-9]+}} 0, i{{[0-9]+}} 1) }]
end_comment

begin_decl_stmt
name|struct
name|svar
name|svars2
index|[]
init|=
block|{
block|{
operator|&
operator|(
operator|(
name|cpu
operator|.
name|pc
operator|)
operator|.
name|b
index|[
literal|0
index|]
index|[
literal|1
index|]
operator|)
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @svars3 = global [1 x %struct.svar] [%struct.svar { i8* bitcast (i16* getelementptr ([2 x i16]* bitcast (%struct.cpu* @cpu to [2 x i16]*), i{{[0-9]+}} 0, i{{[0-9]+}} 1) to i8*) }]
end_comment

begin_decl_stmt
name|struct
name|svar
name|svars3
index|[]
init|=
block|{
block|{
operator|&
operator|(
operator|(
name|cpu
operator|.
name|pc
operator|)
operator|.
name|w
index|[
literal|1
index|]
operator|)
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @svars4 = global [1 x %struct.svar] [%struct.svar { i8* getelementptr ([2 x [2 x i8]]* bitcast (%struct.cpu* @cpu to [2 x [2 x i8]]*), i{{[0-9]+}} 0, i{{[0-9]+}} 1, i{{[0-9]+}} 1) }]
end_comment

begin_decl_stmt
name|struct
name|svar
name|svars4
index|[]
init|=
block|{
block|{
operator|&
operator|(
operator|(
name|cpu
operator|.
name|pc
operator|)
operator|.
name|b
index|[
literal|1
index|]
index|[
literal|1
index|]
operator|)
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

