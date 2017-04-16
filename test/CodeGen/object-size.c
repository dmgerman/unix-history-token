begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin -emit-llvm %s -o - 2>&1 | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|strcpy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
define|\
value|((__builtin_object_size(dest, 0) != -1ULL) \    ? __builtin___strcpy_chk (dest, src, __builtin_object_size(dest, 1)) \    : __inline_strcpy_chk(dest, src))
end_define

begin_function
specifier|static
name|char
modifier|*
name|__inline_strcpy_chk
parameter_list|(
name|char
modifier|*
name|dest
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|)
block|{
return|return
name|__builtin___strcpy_chk
argument_list|(
name|dest
argument_list|,
name|src
argument_list|,
name|__builtin_object_size
argument_list|(
name|dest
argument_list|,
literal|1
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|char
name|gbuf
index|[
literal|63
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|gp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gi
decl_stmt|,
name|gj
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @test1
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
comment|// CHECK:     = call i8* @__strcpy_chk(i8* getelementptr inbounds ([63 x i8], [63 x i8]* @gbuf, i64 0, i64 4), i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i32 0, i32 0), i64 59)
name|strcpy
argument_list|(
operator|&
name|gbuf
index|[
literal|4
index|]
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test2
end_comment

begin_function
name|void
name|test2
parameter_list|()
block|{
comment|// CHECK:     = call i8* @__strcpy_chk(i8* getelementptr inbounds ([63 x i8], [63 x i8]* @gbuf, i32 0, i32 0), i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i32 0, i32 0), i64 63)
name|strcpy
argument_list|(
name|gbuf
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test3
end_comment

begin_function
name|void
name|test3
parameter_list|()
block|{
comment|// CHECK:     = call i8* @__strcpy_chk(i8* getelementptr inbounds ([63 x i8], [63 x i8]* @gbuf, i64 1, i64 37), i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i32 0, i32 0), i64 0)
name|strcpy
argument_list|(
operator|&
name|gbuf
index|[
literal|100
index|]
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test4
end_comment

begin_function
name|void
name|test4
parameter_list|()
block|{
comment|// CHECK:     = call i8* @__strcpy_chk(i8* getelementptr inbounds ([63 x i8], [63 x i8]* @gbuf, i64 0, i64 -1), i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i32 0, i32 0), i64 0)
name|strcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|(
name|void
operator|*
operator|)
operator|&
name|gbuf
index|[
operator|-
literal|1
index|]
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test5
end_comment

begin_function
name|void
name|test5
parameter_list|()
block|{
comment|// CHECK:     = load i8*, i8** @gp
comment|// CHECK-NEXT:= call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|strcpy
argument_list|(
name|gp
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test6
end_comment

begin_function
name|void
name|test6
parameter_list|()
block|{
name|char
name|buf
index|[
literal|57
index|]
decl_stmt|;
comment|// CHECK:       = call i8* @__strcpy_chk(i8* %{{.*}}, i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i32 0, i32 0), i64 53)
name|strcpy
argument_list|(
operator|&
name|buf
index|[
literal|4
index|]
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test7
end_comment

begin_function
name|void
name|test7
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
comment|// Ensure we only evaluate the side-effect once.
comment|// CHECK:     = add
comment|// CHECK-NOT: = add
comment|// CHECK:     = call i8* @__strcpy_chk(i8* getelementptr inbounds ([63 x i8], [63 x i8]* @gbuf, i32 0, i32 0), i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i32 0, i32 0), i64 63)
name|strcpy
argument_list|(
operator|(
operator|++
name|i
operator|,
name|gbuf
operator|)
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test8
end_comment

begin_function
name|void
name|test8
parameter_list|()
block|{
name|char
modifier|*
name|buf
index|[
literal|50
index|]
decl_stmt|;
comment|// CHECK-NOT:   __strcpy_chk
comment|// CHECK:       = call i8* @__inline_strcpy_chk(i8* %{{.*}}, i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i32 0, i32 0))
name|strcpy
argument_list|(
name|buf
index|[
operator|++
name|gi
index|]
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test9
end_comment

begin_function
name|void
name|test9
parameter_list|()
block|{
comment|// CHECK-NOT:   __strcpy_chk
comment|// CHECK:       = call i8* @__inline_strcpy_chk(i8* %{{.*}}, i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i32 0, i32 0))
name|strcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|(
operator|(
operator|++
name|gi
operator|)
operator|+
name|gj
operator|)
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test10
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test10
parameter_list|()
block|{
comment|// CHECK-NOT:   __strcpy_chk
comment|// CHECK:       = call i8* @__inline_strcpy_chk(i8* %{{.*}}, i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i32 0, i32 0))
name|strcpy
argument_list|(
operator|*
operator|(
operator|++
name|p
operator|)
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test11
end_comment

begin_function
name|void
name|test11
parameter_list|()
block|{
comment|// CHECK-NOT:   __strcpy_chk
comment|// CHECK:       = call i8* @__inline_strcpy_chk(i8* getelementptr inbounds ([63 x i8], [63 x i8]* @gbuf, i32 0, i32 0), i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i32 0, i32 0))
name|strcpy
argument_list|(
name|gp
operator|=
name|gbuf
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test12
end_comment

begin_function
name|void
name|test12
parameter_list|()
block|{
comment|// CHECK-NOT:   __strcpy_chk
comment|// CHECK:       = call i8* @__inline_strcpy_chk(i8* %{{.*}}, i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i32 0, i32 0))
name|strcpy
argument_list|(
operator|++
name|gp
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test13
end_comment

begin_function
name|void
name|test13
parameter_list|()
block|{
comment|// CHECK-NOT:   __strcpy_chk
comment|// CHECK:       = call i8* @__inline_strcpy_chk(i8* %{{.*}}, i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i32 0, i32 0))
name|strcpy
argument_list|(
name|gp
operator|++
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test14
end_comment

begin_function
name|void
name|test14
parameter_list|()
block|{
comment|// CHECK-NOT:   __strcpy_chk
comment|// CHECK:       = call i8* @__inline_strcpy_chk(i8* %{{.*}}, i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i32 0, i32 0))
name|strcpy
argument_list|(
operator|--
name|gp
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test15
end_comment

begin_function
name|void
name|test15
parameter_list|()
block|{
comment|// CHECK-NOT:   __strcpy_chk
comment|// CHECK:       = call i8* @__inline_strcpy_chk(i8* %{{..*}}, i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i32 0, i32 0))
name|strcpy
argument_list|(
name|gp
operator|--
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test16
end_comment

begin_function
name|void
name|test16
parameter_list|()
block|{
comment|// CHECK-NOT:   __strcpy_chk
comment|// CHECK:       = call i8* @__inline_strcpy_chk(i8* %{{.*}}, i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i32 0, i32 0))
name|strcpy
argument_list|(
name|gp
operator|+=
literal|1
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test17
end_comment

begin_function
name|void
name|test17
parameter_list|()
block|{
comment|// CHECK: store i32 -1
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|gp
operator|++
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 -1
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|gp
operator|++
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|gp
operator|++
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|gp
operator|++
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test18
end_comment

begin_function
name|unsigned
name|test18
parameter_list|(
name|int
name|cond
parameter_list|)
block|{
name|int
name|a
index|[
literal|4
index|]
decl_stmt|,
name|b
index|[
literal|4
index|]
decl_stmt|;
comment|// CHECK: phi i32*
comment|// CHECK: call i64 @llvm.objectsize.i64
return|return
name|__builtin_object_size
argument_list|(
name|cond
condition|?
name|a
else|:
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test19
end_comment

begin_function
name|void
name|test19
parameter_list|()
block|{
struct|struct
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
name|foo
struct|;
comment|// CHECK: store i32 8
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|foo
operator|.
name|a
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 4
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|foo
operator|.
name|a
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 8
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|foo
operator|.
name|a
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 4
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|foo
operator|.
name|a
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 4
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|foo
operator|.
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 4
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|foo
operator|.
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 4
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|foo
operator|.
name|b
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 4
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|foo
operator|.
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test20
end_comment

begin_function
name|void
name|test20
parameter_list|()
block|{
struct|struct
block|{
name|int
name|t
index|[
literal|10
index|]
decl_stmt|;
block|}
name|t
index|[
literal|10
index|]
struct|;
comment|// CHECK: store i32 380
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
index|[
literal|0
index|]
operator|.
name|t
index|[
literal|5
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 20
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
index|[
literal|0
index|]
operator|.
name|t
index|[
literal|5
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 380
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
index|[
literal|0
index|]
operator|.
name|t
index|[
literal|5
index|]
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 20
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
index|[
literal|0
index|]
operator|.
name|t
index|[
literal|5
index|]
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test21
end_comment

begin_function
name|void
name|test21
parameter_list|()
block|{
struct|struct
block|{
name|int
name|t
decl_stmt|;
block|}
name|t
struct|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
operator|+
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
operator|+
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
operator|+
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
operator|+
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
operator|.
name|t
operator|+
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
operator|.
name|t
operator|+
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
operator|.
name|t
operator|+
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
operator|.
name|t
operator|+
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test22
end_comment

begin_function
name|void
name|test22
parameter_list|()
block|{
struct|struct
block|{
name|int
name|t
index|[
literal|10
index|]
decl_stmt|;
block|}
name|t
index|[
literal|10
index|]
struct|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
index|[
literal|10
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
index|[
literal|10
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
index|[
literal|10
index|]
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
index|[
literal|10
index|]
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
index|[
literal|9
index|]
operator|.
name|t
index|[
literal|10
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
index|[
literal|9
index|]
operator|.
name|t
index|[
literal|10
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
index|[
literal|9
index|]
operator|.
name|t
index|[
literal|10
index|]
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
index|[
literal|9
index|]
operator|.
name|t
index|[
literal|10
index|]
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|t
index|[
literal|0
index|]
operator|+
sizeof|sizeof
argument_list|(
name|t
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|t
index|[
literal|0
index|]
operator|+
sizeof|sizeof
argument_list|(
name|t
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|t
index|[
literal|0
index|]
operator|+
sizeof|sizeof
argument_list|(
name|t
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|t
index|[
literal|0
index|]
operator|+
sizeof|sizeof
argument_list|(
name|t
argument_list|)
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|t
index|[
literal|9
index|]
operator|.
name|t
index|[
literal|0
index|]
operator|+
literal|10
operator|*
sizeof|sizeof
argument_list|(
name|t
index|[
literal|0
index|]
operator|.
name|t
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|t
index|[
literal|9
index|]
operator|.
name|t
index|[
literal|0
index|]
operator|+
literal|10
operator|*
sizeof|sizeof
argument_list|(
name|t
index|[
literal|0
index|]
operator|.
name|t
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|t
index|[
literal|9
index|]
operator|.
name|t
index|[
literal|0
index|]
operator|+
literal|10
operator|*
sizeof|sizeof
argument_list|(
name|t
index|[
literal|0
index|]
operator|.
name|t
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|t
index|[
literal|9
index|]
operator|.
name|t
index|[
literal|0
index|]
operator|+
literal|10
operator|*
sizeof|sizeof
argument_list|(
name|t
index|[
literal|0
index|]
operator|.
name|t
argument_list|)
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|Test23Ty
block|{
name|int
name|a
decl_stmt|;
name|int
name|t
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: @test23
end_comment

begin_function
name|void
name|test23
parameter_list|(
name|struct
name|Test23Ty
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|p
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|p
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 true, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|p
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// Note: this is currently fixed at 0 because LLVM doesn't have sufficient
comment|// data to correctly handle type=3
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|p
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|p
operator|->
name|a
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 4
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|p
operator|->
name|a
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 true, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|p
operator|->
name|a
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 4
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|p
operator|->
name|a
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|p
operator|->
name|t
index|[
literal|5
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|p
operator|->
name|t
index|[
literal|5
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 true, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|p
operator|->
name|t
index|[
literal|5
index|]
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 20
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|p
operator|->
name|t
index|[
literal|5
index|]
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// PR24493 -- ICE if __builtin_object_size called with NULL and (Type& 1) != 0
end_comment

begin_comment
comment|// CHECK-LABEL: @test24
end_comment

begin_function
name|void
name|test24
parameter_list|()
block|{
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* {{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* {{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* {{.*}}, i1 true, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// Note: Currently fixed at zero because LLVM can't handle type=3 correctly.
comment|// Hopefully will be lowered properly in the future.
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test25
end_comment

begin_function
name|void
name|test25
parameter_list|()
block|{
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* {{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0x1000
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* {{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0x1000
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* {{.*}}, i1 true, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0x1000
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// Note: Currently fixed at zero because LLVM can't handle type=3 correctly.
comment|// Hopefully will be lowered properly in the future.
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0x1000
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* {{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
operator|+
literal|0x1000
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* {{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
operator|+
literal|0x1000
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* {{.*}}, i1 true, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
operator|+
literal|0x1000
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// Note: Currently fixed at zero because LLVM can't handle type=3 correctly.
comment|// Hopefully will be lowered properly in the future.
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
operator|+
literal|0x1000
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test26
end_comment

begin_function
name|void
name|test26
parameter_list|()
block|{
struct|struct
block|{
name|int
name|v
index|[
literal|10
index|]
decl_stmt|;
block|}
name|t
index|[
literal|10
index|]
struct|;
comment|// CHECK: store i32 316
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|v
index|[
literal|11
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 312
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|v
index|[
literal|12
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 308
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|v
index|[
literal|13
index|]
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|v
index|[
literal|14
index|]
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_struct_decl
struct_decl|struct
name|Test27IncompleteTy
struct_decl|;
end_struct_decl

begin_comment
comment|// CHECK-LABEL: @test27
end_comment

begin_function
name|void
name|test27
parameter_list|(
name|struct
name|Test27IncompleteTy
modifier|*
name|t
parameter_list|)
block|{
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|t
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|t
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 true, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|t
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// Note: this is currently fixed at 0 because LLVM doesn't have sufficient
comment|// data to correctly handle type=3
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|t
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* {{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|test27
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* {{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|test27
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* {{.*}}, i1 true, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|test27
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// Note: this is currently fixed at 0 because LLVM doesn't have sufficient
comment|// data to correctly handle type=3
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|test27
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// The intent of this test is to ensure that __builtin_object_size treats `&foo`
end_comment

begin_comment
comment|// and `(T*)&foo` identically, when used as the pointer argument.
end_comment

begin_comment
comment|// CHECK-LABEL: @test28
end_comment

begin_function
name|void
name|test28
parameter_list|()
block|{
struct|struct
block|{
name|int
name|v
index|[
literal|10
index|]
decl_stmt|;
block|}
name|t
index|[
literal|10
index|]
struct|;
define|#
directive|define
name|addCasts
parameter_list|(
name|s
parameter_list|)
value|((char*)((short*)(s)))
comment|// CHECK: store i32 360
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|addCasts
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 360
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|addCasts
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 360
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|addCasts
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 360
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|addCasts
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 356
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|addCasts
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|v
index|[
literal|1
index|]
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 36
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|addCasts
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|v
index|[
literal|1
index|]
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 356
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|addCasts
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|v
index|[
literal|1
index|]
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 36
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|addCasts
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|v
index|[
literal|1
index|]
argument_list|)
argument_list|,
literal|3
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|addCasts
block|}
end_function

begin_struct
struct|struct
name|DynStructVar
block|{
name|char
name|fst
index|[
literal|16
index|]
decl_stmt|;
name|char
name|snd
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DynStruct0
block|{
name|char
name|fst
index|[
literal|16
index|]
decl_stmt|;
name|char
name|snd
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DynStruct1
block|{
name|char
name|fst
index|[
literal|16
index|]
decl_stmt|;
name|char
name|snd
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|StaticStruct
block|{
name|char
name|fst
index|[
literal|16
index|]
decl_stmt|;
name|char
name|snd
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: @test29
end_comment

begin_function
name|void
name|test29
parameter_list|(
name|struct
name|DynStructVar
modifier|*
name|dv
parameter_list|,
name|struct
name|DynStruct0
modifier|*
name|d0
parameter_list|,
name|struct
name|DynStruct1
modifier|*
name|d1
parameter_list|,
name|struct
name|StaticStruct
modifier|*
name|ss
parameter_list|)
block|{
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|dv
operator|->
name|snd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|dv
operator|->
name|snd
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 true, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|dv
operator|->
name|snd
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|dv
operator|->
name|snd
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|d0
operator|->
name|snd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|d0
operator|->
name|snd
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 true, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|d0
operator|->
name|snd
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|d0
operator|->
name|snd
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|d1
operator|->
name|snd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|d1
operator|->
name|snd
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 true, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|d1
operator|->
name|snd
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 1
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|d1
operator|->
name|snd
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|ss
operator|->
name|snd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|ss
operator|->
name|snd
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 true, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|ss
operator|->
name|snd
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 2
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|ss
operator|->
name|snd
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test30
end_comment

begin_function
name|void
name|test30
parameter_list|()
block|{
struct|struct
block|{
name|struct
name|DynStruct1
name|fst
decl_stmt|,
name|snd
decl_stmt|;
block|}
modifier|*
name|nested
struct|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|nested
operator|->
name|fst
operator|.
name|snd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 1
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|nested
operator|->
name|fst
operator|.
name|snd
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 true, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|nested
operator|->
name|fst
operator|.
name|snd
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 1
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|nested
operator|->
name|fst
operator|.
name|snd
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|nested
operator|->
name|snd
operator|.
name|snd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|nested
operator|->
name|snd
operator|.
name|snd
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 true, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|nested
operator|->
name|snd
operator|.
name|snd
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 1
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|nested
operator|->
name|snd
operator|.
name|snd
argument_list|,
literal|3
argument_list|)
expr_stmt|;
union|union
block|{
name|struct
name|DynStruct1
name|d1
decl_stmt|;
name|char
name|c
index|[
literal|1
index|]
decl_stmt|;
block|}
modifier|*
name|u
union|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|u
operator|->
name|c
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|u
operator|->
name|c
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 true, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|u
operator|->
name|c
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 1
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|u
operator|->
name|c
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|u
operator|->
name|d1
operator|.
name|snd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|u
operator|->
name|d1
operator|.
name|snd
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 true, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|u
operator|->
name|d1
operator|.
name|snd
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 1
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|u
operator|->
name|d1
operator|.
name|snd
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test31
end_comment

begin_function
name|void
name|test31
parameter_list|()
block|{
comment|// Miscellaneous 'writing off the end' detection tests
name|struct
name|DynStructVar
modifier|*
name|dsv
decl_stmt|;
name|struct
name|DynStruct0
modifier|*
name|ds0
decl_stmt|;
name|struct
name|DynStruct1
modifier|*
name|ds1
decl_stmt|;
name|struct
name|StaticStruct
modifier|*
name|ss
decl_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|ds1
index|[
literal|9
index|]
operator|.
name|snd
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|ss
index|[
literal|9
index|]
operator|.
name|snd
index|[
literal|0
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|ds1
index|[
literal|9
index|]
operator|.
name|snd
index|[
literal|0
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|ds0
index|[
literal|9
index|]
operator|.
name|snd
index|[
literal|0
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|dsv
index|[
literal|9
index|]
operator|.
name|snd
index|[
literal|0
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @PR30346
end_comment

begin_function
name|void
name|PR30346
parameter_list|()
block|{
struct|struct
name|sa_family_t
block|{}
struct|;
struct|struct
name|sockaddr
block|{
name|struct
name|sa_family_t
name|sa_family
decl_stmt|;
name|char
name|sa_data
index|[
literal|14
index|]
decl_stmt|;
block|}
struct|;
name|struct
name|sockaddr
modifier|*
name|sa
decl_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|sa
operator|->
name|sa_data
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 false, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|sa
operator|->
name|sa_data
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8(i8* %{{.*}}, i1 true, i1 true)
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|sa
operator|->
name|sa_data
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 14
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|sa
operator|->
name|sa_data
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|char
name|incomplete_char_array
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: @incomplete_and_function_types
end_comment

begin_function
name|int
name|incomplete_and_function_types
parameter_list|()
block|{
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|incomplete_char_array
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|incomplete_char_array
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p0i8
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|incomplete_char_array
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 0
name|gi
operator|=
name|__builtin_object_size
argument_list|(
name|incomplete_char_array
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Flips between the pointer and lvalue evaluator a lot.
end_comment

begin_function
name|void
name|deeply_nested
parameter_list|()
block|{
struct|struct
block|{
struct|struct
block|{
struct|struct
block|{
struct|struct
block|{
name|int
name|e
index|[
literal|2
index|]
decl_stmt|;
name|char
name|f
decl_stmt|;
comment|// Inhibit our writing-off-the-end check
block|}
name|d
index|[
literal|2
index|]
struct|;
block|}
name|c
index|[
literal|2
index|]
struct|;
block|}
name|b
index|[
literal|2
index|]
struct|;
block|}
modifier|*
name|a
struct|;
comment|// CHECK: store i32 4
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|a
operator|->
name|b
index|[
literal|1
index|]
operator|.
name|c
index|[
literal|1
index|]
operator|.
name|d
index|[
literal|1
index|]
operator|.
name|e
index|[
literal|1
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: store i32 4
name|gi
operator|=
name|__builtin_object_size
argument_list|(
operator|&
name|a
operator|->
name|b
index|[
literal|1
index|]
operator|.
name|c
index|[
literal|1
index|]
operator|.
name|d
index|[
literal|1
index|]
operator|.
name|e
index|[
literal|1
index|]
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

