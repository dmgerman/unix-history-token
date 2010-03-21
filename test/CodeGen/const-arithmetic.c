begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @g1 = global [2 x i8*] [i8* getelementptr (i8* getelementptr inbounds ([0 x %struct.anon]* @g0, i32 0, i32 0, i32 0), i64 -2), i8* getelementptr (i8* getelementptr inbounds ([0 x %struct.anon]* @g0, i32 0, i32 0, i32 0), i64 -46)], align 8 ;<[2 x i8*]*> [#uses=0]
end_comment

begin_comment
comment|// CHECK: @g2 = global [2 x i8*] [i8* getelementptr (i8* getelementptr inbounds ([0 x %struct.anon]* @g0, i32 0, i32 0, i32 0), i64 -2), i8* getelementptr (i8* getelementptr inbounds ([0 x %struct.anon]* @g0, i32 0, i32 0, i32 0), i64 -46)], align 8 ;<[2 x i8*]*> [#uses=0]
end_comment

begin_struct
specifier|extern
struct|struct
block|{
name|unsigned
name|char
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
name|g0
index|[]
struct|;
end_struct

begin_decl_stmt
name|void
modifier|*
name|g1
index|[]
init|=
block|{
name|g0
operator|+
operator|-
literal|1
block|,
name|g0
operator|+
operator|-
literal|23
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|g2
index|[]
init|=
block|{
name|g0
operator|-
literal|1
block|,
name|g0
operator|-
literal|23
block|}
decl_stmt|;
end_decl_stmt

end_unit

