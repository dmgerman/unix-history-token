begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -fms-extensions -emit-llvm< %s | FileCheck %s
end_comment

begin_comment
comment|// -------------
end_comment

begin_comment
comment|// Scalar integer
end_comment

begin_comment
comment|// -------------
end_comment

begin_decl_stmt
name|__unaligned
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test1
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: {{%.*}} = load i32, i32* @x, align 1
comment|// CHECK: store i32 {{%.*}}, i32* @x, align 1
name|x
operator|++
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test2
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: %y = alloca i32, align 1
comment|// CHECK: {{%.*}} = load i32, i32* %y, align 1
comment|// CHECK: store i32 {{%.*}}, i32* %y, align 1
name|__unaligned
name|int
name|y
decl_stmt|;
name|y
operator|++
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test2_1
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: %y = alloca i32, align 1
comment|// CHECK: store i32 1, i32* %y, align 1
name|__unaligned
name|int
name|y
init|=
literal|1
decl_stmt|;
block|}
end_function

begin_comment
comment|// -------------
end_comment

begin_comment
comment|// Global pointer
end_comment

begin_comment
comment|// -------------
end_comment

begin_decl_stmt
name|int
modifier|*
name|__unaligned
name|p1
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test3
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: {{%.*}} = load i32*, i32** @p1, align 1
comment|// CHECK: {{%.*}} = load i32, i32* {{%.*}}, align 4
comment|// CHECK: store i32 {{%.*}}, i32* {{%.*}}, align 4
operator|(
operator|*
name|p1
operator|)
operator|++
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|int
name|__unaligned
modifier|*
name|p2
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test4
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: {{%.*}} = load i32*, i32** @p2, align 8
comment|// CHECK: {{%.*}} = load i32, i32* {{%.*}}, align 1
comment|// CHECK: store i32 {{%.*}}, i32* {{%.*}}, align 1
operator|(
operator|*
name|p2
operator|)
operator|++
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|int
name|__unaligned
modifier|*
name|__unaligned
name|p3
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test5
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: {{%.*}} = load i32*, i32** @p3, align 1
comment|// CHECK: {{%.*}} = load i32, i32* {{%.*}}, align 1
comment|// CHECK: store i32 {{%.*}}, i32* {{%.*}}, align 1
operator|(
operator|*
name|p3
operator|)
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|// -------------
end_comment

begin_comment
comment|// Local pointer
end_comment

begin_comment
comment|// -------------
end_comment

begin_function
name|void
name|test6
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: %lp1 = alloca i32*, align 1
comment|// CHECK: {{%.*}} = load i32*, i32** %lp1, align 1
comment|// CHECK: {{%.*}} = load i32, i32* {{%.*}}, align 4
comment|// CHECK: store i32 {{%.*}}, i32* {{%.*}}, align 4
name|int
modifier|*
name|__unaligned
name|lp1
decl_stmt|;
operator|(
operator|*
name|lp1
operator|)
operator|++
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test7
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: %lp2 = alloca i32*, align 8
comment|// CHECK: {{%.*}} = load i32*, i32** %lp2, align 8
comment|// CHECK: {{%.*}} = load i32, i32* {{%.*}}, align 1
comment|// CHECK: store i32 {{%.*}}, i32* {{%.*}}, align 1
name|int
name|__unaligned
modifier|*
name|lp2
decl_stmt|;
operator|(
operator|*
name|lp2
operator|)
operator|++
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test8
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: %lp3 = alloca i32*, align 1
comment|// CHECK: {{%.*}} = load i32*, i32** %lp3, align 1
comment|// CHECK: {{%.*}} = load i32, i32* {{%.*}}, align 1
comment|// CHECK: store i32 {{%.*}}, i32* {{%.*}}, align 1
name|int
name|__unaligned
modifier|*
name|__unaligned
name|lp3
decl_stmt|;
operator|(
operator|*
name|lp3
operator|)
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|// -------------
end_comment

begin_comment
comment|// Global array
end_comment

begin_comment
comment|// -------------
end_comment

begin_decl_stmt
name|__unaligned
name|int
name|a
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test9
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: {{%.*}} = load i32, i32* getelementptr inbounds ([10 x i32], [10 x i32]* @a, i64 0, i64 3), align 1
comment|// CHECK: store i32 {{%.*}}, i32* getelementptr inbounds ([10 x i32], [10 x i32]* @a, i64 0, i64 3), align 1
operator|(
name|a
index|[
literal|3
index|]
operator|)
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|// -------------
end_comment

begin_comment
comment|// Local array
end_comment

begin_comment
comment|// -------------
end_comment

begin_function
name|void
name|test10
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: %la = alloca [10 x i32], align 1
comment|// CHECK: {{%.*}} = getelementptr inbounds [10 x i32], [10 x i32]* %la, i64 0, i64 3
comment|// CHECK: {{%.*}} = load i32, i32* {{%.*}}, align 1
comment|// CHECK: store i32 {{%.*}}, i32* {{%.*}}, align 1
name|__unaligned
name|int
name|la
index|[
literal|10
index|]
decl_stmt|;
operator|(
name|la
index|[
literal|3
index|]
operator|)
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|// --------
end_comment

begin_comment
comment|// Typedefs
end_comment

begin_comment
comment|// --------
end_comment

begin_typedef
typedef|typedef
name|__unaligned
name|int
name|UnalignedInt
typedef|;
end_typedef

begin_function
name|void
name|test13
parameter_list|()
block|{
comment|// CHECK: %i = alloca i32, align 1
comment|// CHECK: {{%.*}} = load i32, i32* %i, align 1
comment|// CHECK: store i32 {{%.*}}, i32* %i, align 1
name|UnalignedInt
name|i
decl_stmt|;
name|i
operator|++
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|int
name|Aligned
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__unaligned
name|Aligned
name|UnalignedInt2
typedef|;
end_typedef

begin_function
name|void
name|test14
parameter_list|()
block|{
comment|// CHECK: %i = alloca i32, align 1
comment|// CHECK: {{%.*}} = load i32, i32* %i, align 1
comment|// CHECK: store i32 {{%.*}}, i32* %i, align 1
name|UnalignedInt2
name|i
decl_stmt|;
name|i
operator|++
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|UnalignedInt
name|UnalignedInt3
typedef|;
end_typedef

begin_function
name|void
name|test15
parameter_list|()
block|{
comment|// CHECK: %i = alloca i32, align 1
comment|// CHECK: {{%.*}} = load i32, i32* %i, align 1
comment|// CHECK: store i32 {{%.*}}, i32* %i, align 1
name|UnalignedInt3
name|i
decl_stmt|;
name|i
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|// -------------
end_comment

begin_comment
comment|// Decayed types
end_comment

begin_comment
comment|// -------------
end_comment

begin_function
name|void
name|test16
parameter_list|(
name|__unaligned
name|int
name|c
index|[
literal|10
index|]
parameter_list|)
block|{
comment|// CHECK: {{%.*}} = alloca i32*, align 8
comment|// CHECK: store i32* %c, i32** {{%.*}}, align 8
comment|// CHECK: {{%.*}} = load i32*, i32** {{%.*}}, align 8
comment|// CHECK: {{%.*}} = getelementptr inbounds i32, i32* {{%.*}}, i64 3
comment|// CHECK: {{%.*}} = load i32, i32* {{%.*}}, align 1
comment|// CHECK: store i32 {{%.*}}, i32* {{%.*}}, align 1
name|c
index|[
literal|3
index|]
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|// -----------
end_comment

begin_comment
comment|// __alignof__
end_comment

begin_comment
comment|// -----------
end_comment

begin_function
name|int
name|test17
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: ret i32 1
return|return
name|__alignof__
argument_list|(
argument|__unaligned int
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test18
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: ret i32 1
name|__unaligned
name|int
name|a
decl_stmt|;
return|return
name|__alignof__
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test19
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: ret i32 1
name|__unaligned
name|int
name|a
index|[
literal|10
index|]
decl_stmt|;
return|return
name|__alignof__
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// -----------
end_comment

begin_comment
comment|// structs
end_comment

begin_comment
comment|// -----------
end_comment

begin_typedef
typedef|typedef
struct|struct
name|S1
block|{
name|char
name|c
decl_stmt|;
name|int
name|x
decl_stmt|;
block|}
name|S1
typedef|;
end_typedef

begin_decl_stmt
name|__unaligned
name|S1
name|s1
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test20
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: {{%.*}} = load i32, i32* getelementptr inbounds (%struct.S1, %struct.S1* @s1, i32 0, i32 1), align 1
comment|// CHECK: store i32 {{%.*}}, i32* getelementptr inbounds (%struct.S1, %struct.S1* @s1, i32 0, i32 1), align 1
name|s1
operator|.
name|x
operator|++
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test21
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: {{%.*}} = alloca %struct.S1, align 1
comment|// CHECK: {{%.*}} = getelementptr inbounds %struct.S1, %struct.S1* {{%.*}}, i32 0, i32 1
comment|// CHECK: {{%.*}} = load i32, i32* {{%.*}}, align 1
comment|// CHECK: store i32 {{%.*}}, i32* {{%.*}}, align 1
name|__unaligned
name|S1
name|s1_2
decl_stmt|;
name|s1_2
operator|.
name|x
operator|++
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
struct|struct
name|__attribute__
argument_list|(
argument|(packed)
argument_list|)
name|S2
block|{
name|char
name|c
decl_stmt|;
name|int
name|x
decl_stmt|;
block|}
name|S2
typedef|;
end_typedef

begin_decl_stmt
name|__unaligned
name|S2
name|s2
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test22
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: {{%.*}} = load i32, i32* getelementptr inbounds (%struct.S2, %struct.S2* @s2, i32 0, i32 1), align 1
comment|// CHECK: store i32 {{%.*}}, i32* getelementptr inbounds (%struct.S2, %struct.S2* @s2, i32 0, i32 1), align 1
name|s2
operator|.
name|x
operator|++
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test23
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: {{%.*}} = alloca %struct.S2, align 1
comment|// CHECK: {{%.*}} = getelementptr inbounds %struct.S2, %struct.S2* {{%.*}}, i32 0, i32 1
comment|// CHECK: {{%.*}} = load i32, i32* {{%.*}}, align 1
comment|// CHECK: store i32 {{%.*}}, i32* {{%.*}}, align 1
name|__unaligned
name|S2
name|s2_2
decl_stmt|;
name|s2_2
operator|.
name|x
operator|++
expr_stmt|;
block|}
end_function

end_unit

