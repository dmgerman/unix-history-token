begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|void
name|f1
parameter_list|()
block|{
comment|// Scalars in braces.
name|int
name|a
init|=
block|{
literal|1
block|}
decl_stmt|;
block|}
end_function

begin_function
name|void
name|f2
parameter_list|()
block|{
name|int
name|a
index|[
literal|2
index|]
index|[
literal|2
index|]
init|=
block|{
block|{
literal|1
block|,
literal|2
block|}
block|,
block|{
literal|3
block|,
literal|4
block|}
block|}
decl_stmt|;
name|int
name|b
index|[
literal|3
index|]
index|[
literal|3
index|]
init|=
block|{
block|{
literal|1
block|,
literal|2
block|}
block|,
block|{
literal|3
block|,
literal|4
block|}
block|}
decl_stmt|;
name|int
modifier|*
name|c
index|[
literal|2
index|]
init|=
block|{
operator|&
name|a
index|[
literal|1
index|]
index|[
literal|1
index|]
block|,
operator|&
name|b
index|[
literal|2
index|]
index|[
literal|2
index|]
block|}
decl_stmt|;
name|int
modifier|*
name|d
index|[
literal|2
index|]
index|[
literal|2
index|]
init|=
block|{
block|{
operator|&
name|a
index|[
literal|1
index|]
index|[
literal|1
index|]
block|,
operator|&
name|b
index|[
literal|2
index|]
index|[
literal|2
index|]
block|}
block|,
block|{
operator|&
name|a
index|[
literal|0
index|]
index|[
literal|0
index|]
block|,
operator|&
name|b
index|[
literal|1
index|]
index|[
literal|1
index|]
block|}
block|}
decl_stmt|;
name|int
modifier|*
name|e
index|[
literal|3
index|]
index|[
literal|3
index|]
init|=
block|{
block|{
operator|&
name|a
index|[
literal|1
index|]
index|[
literal|1
index|]
block|,
operator|&
name|b
index|[
literal|2
index|]
index|[
literal|2
index|]
block|}
block|,
block|{
operator|&
name|a
index|[
literal|0
index|]
index|[
literal|0
index|]
block|,
operator|&
name|b
index|[
literal|1
index|]
index|[
literal|1
index|]
block|}
block|}
decl_stmt|;
name|char
name|ext
index|[
literal|3
index|]
index|[
literal|3
index|]
init|=
block|{
literal|".Y"
block|,
literal|".U"
block|,
literal|".V"
block|}
decl_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|F
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|S
block|{
name|F
name|f
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f3
parameter_list|()
block|{
name|struct
name|S
name|a
index|[
literal|1
index|]
init|=
block|{
block|{
name|foo
block|}
block|}
decl_stmt|;
block|}
end_function

begin_comment
comment|// Constants
end_comment

begin_comment
comment|// CHECK: @g3 = constant i32 10
end_comment

begin_comment
comment|// CHECK: @f4.g4 = internal constant i32 12
end_comment

begin_decl_stmt
specifier|const
name|int
name|g3
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f4
parameter_list|()
block|{
specifier|static
specifier|const
name|int
name|g4
init|=
literal|12
decl_stmt|;
return|return
name|g4
return|;
block|}
end_function

begin_comment
comment|// PR6537
end_comment

begin_typedef
typedef|typedef
union|union
name|vec3
block|{
struct|struct
block|{
name|double
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
block|}
struct|;
name|double
name|component
index|[
literal|3
index|]
decl_stmt|;
block|}
name|vec3
typedef|;
end_typedef

begin_function
name|vec3
name|f5
parameter_list|(
name|vec3
name|value
parameter_list|)
block|{
return|return
operator|(
name|vec3
operator|)
block|{
block|{
operator|.
name|x
operator|=
name|value
operator|.
name|x
block|}
block|}
return|;
block|}
end_function

begin_comment
comment|// rdar://problem/8154689
end_comment

begin_function
name|void
name|f6
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|long
name|ids
index|[]
init|=
block|{
operator|(
name|long
operator|)
operator|&
name|x
block|}
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test7 = global{{.*}}{ i32 0, [4 x i8] c"bar\00" }
end_comment

begin_comment
comment|// PR8217
end_comment

begin_struct
struct|struct
name|a7
block|{
name|int
name|b
decl_stmt|;
name|char
name|v
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|a7
name|test7
init|=
block|{
operator|.
name|b
operator|=
literal|0
block|,
operator|.
name|v
operator|=
literal|"bar"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR279 comment #3
end_comment

begin_function
name|char
name|test8
parameter_list|(
name|int
name|X
parameter_list|)
block|{
name|char
name|str
index|[
literal|100000
index|]
init|=
literal|"abc"
decl_stmt|;
comment|// tail should be memset.
return|return
name|str
index|[
name|X
index|]
return|;
comment|// CHECK: @test8(
comment|// CHECK: call void @llvm.memset
comment|// CHECK: store i8 97
comment|// CHECK: store i8 98
comment|// CHECK: store i8 99
comment|// CHECK-NOT: getelementptr
comment|// CHECK: load
block|}
end_function

begin_function_decl
name|void
name|bar
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// PR279
end_comment

begin_function
name|int
name|test9
parameter_list|(
name|int
name|X
parameter_list|)
block|{
name|int
name|Arr
index|[
literal|100
index|]
init|=
block|{
name|X
block|}
decl_stmt|;
comment|// Should use memset
name|bar
argument_list|(
name|Arr
argument_list|)
expr_stmt|;
comment|// CHECK: @test9
comment|// CHECK: call void @llvm.memset
comment|// CHECK-NOT: store i32 0
comment|// CHECK: call void @bar
block|}
end_function

begin_struct
struct|struct
name|a
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|,
name|e
decl_stmt|,
name|f
decl_stmt|,
name|g
decl_stmt|,
name|h
decl_stmt|,
name|i
decl_stmt|,
name|j
decl_stmt|,
name|k
decl_stmt|,
modifier|*
name|p
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|b
block|{
name|struct
name|a
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|,
name|e
decl_stmt|,
name|f
decl_stmt|,
name|g
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|test10
parameter_list|(
name|int
name|X
parameter_list|)
block|{
name|struct
name|b
name|S
init|=
block|{
operator|.
name|a
operator|.
name|a
operator|=
name|X
block|,
operator|.
name|d
operator|.
name|e
operator|=
name|X
block|,
operator|.
name|f
operator|.
name|e
operator|=
literal|0
block|,
operator|.
name|f
operator|.
name|f
operator|=
literal|0
block|,
operator|.
name|f
operator|.
name|p
operator|=
literal|0
block|}
decl_stmt|;
name|bar
argument_list|(
operator|&
name|S
argument_list|)
expr_stmt|;
comment|// CHECK: @test10
comment|// CHECK: call void @llvm.memset
comment|// CHECK-NOT: store i32 0
comment|// CHECK: call void @bar
block|}
end_function

begin_comment
comment|// PR9257
end_comment

begin_struct
struct|struct
name|test11S
block|{
name|int
name|A
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|test11
parameter_list|(
name|struct
name|test11S
modifier|*
name|P
parameter_list|)
block|{
operator|*
name|P
operator|=
operator|(
expr|struct
name|test11S
operator|)
block|{
operator|.
name|A
operator|=
block|{
index|[
literal|0
operator|...
literal|3
index|]
operator|=
literal|4
block|}
block|}
expr_stmt|;
comment|// CHECK: @test11
comment|// CHECK: store i32 4
comment|// CHECK: store i32 4
comment|// CHECK: store i32 4
comment|// CHECK: store i32 4
comment|// CHECK: ret void
block|}
end_function

begin_comment
comment|// Verify that we can convert a recursive struct with a memory that returns
end_comment

begin_comment
comment|// an instance of the struct we're converting.
end_comment

begin_struct
struct|struct
name|test12
block|{
name|struct
name|test12
function_decl|(
modifier|*
name|p
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
name|test12g
struct|;
end_struct

begin_function
name|void
name|test13
parameter_list|(
name|int
name|x
parameter_list|)
block|{
struct|struct
name|X
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
range|:
literal|10
decl_stmt|;
name|int
name|c
decl_stmt|;
block|}
struct|;
name|struct
name|X
name|y
init|=
block|{
operator|.
name|c
operator|=
name|x
block|}
decl_stmt|;
comment|// CHECK: @test13
comment|// CHECK: and i16 {{.*}}, -1024
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @PR20473
end_comment

begin_function
name|void
name|PR20473
parameter_list|()
block|{
comment|// CHECK: memcpy{{.*}}([2 x i8]* @
name|bar
argument_list|(
operator|(
name|char
index|[
literal|2
index|]
operator|)
block|{
literal|""
block|}
argument_list|)
expr_stmt|;
comment|// CHECK: memcpy{{.*}}([3 x i8]* @
name|bar
argument_list|(
operator|(
name|char
index|[
literal|3
index|]
operator|)
block|{
literal|""
block|}
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

