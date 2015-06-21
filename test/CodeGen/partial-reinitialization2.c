begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-unknown-unknown -emit-llvm -o - | FileCheck %s
end_comment

begin_struct
struct|struct
name|P1
block|{
name|char
name|x
index|[
literal|6
index|]
decl_stmt|;
block|}
name|g1
init|=
block|{
literal|"foo"
block|}
struct|;
end_struct

begin_struct
struct|struct
name|LP1
block|{
name|struct
name|P1
name|p1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|P2
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
block|}
name|g2
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
struct|;
end_struct

begin_struct
struct|struct
name|LP2
block|{
name|struct
name|P2
name|p2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|LP2P2
block|{
name|struct
name|P2
name|p1
decl_stmt|,
name|p2
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|UP2
block|{
name|struct
name|P2
name|p2
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|LP3
block|{
name|struct
name|P1
name|p1
index|[
literal|2
index|]
decl_stmt|;
block|}
name|g3
init|=
block|{
block|{
literal|"dog"
block|}
block|,
block|{
literal|"cat"
block|}
block|}
struct|;
end_struct

begin_struct
struct|struct
name|LLP3
block|{
name|struct
name|LP3
name|l3
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|ULP3
block|{
name|struct
name|LP3
name|l3
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|// CHECK-LABEL: test1
end_comment

begin_function
name|void
name|test1
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: call void @llvm.memcpy{{.*}}%struct.P1, %struct.P1* @g1{{.*}}i64 6, i32 {{[0-9]}}, i1 false)
comment|// CHECK: store i8 120, i8* %
name|struct
name|LP1
name|l
init|=
block|{
operator|.
name|p1
operator|=
name|g1
block|,
operator|.
name|p1
operator|.
name|x
index|[
literal|2
index|]
operator|=
literal|'x'
block|}
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test2
end_comment

begin_function
name|void
name|test2
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: call void @llvm.memcpy{{.*}}%struct.P1, %struct.P1* @g1{{.*}}i64 6, i32 {{[0-9]}}, i1 false)
comment|// CHECK: store i8 114, i8* %
name|struct
name|LP1
name|l
init|=
block|{
operator|.
name|p1
operator|=
name|g1
block|,
operator|.
name|p1
operator|.
name|x
index|[
literal|1
index|]
operator|=
literal|'r'
block|}
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test3
end_comment

begin_function
name|void
name|test3
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: call void @llvm.memcpy{{.*}}%struct.P2* @g2{{.*}}i64 12, i32 {{[0-9]}}, i1 false)
comment|// CHECK: store i32 10, i32* %
name|struct
name|LP2
name|l
init|=
block|{
operator|.
name|p2
operator|=
name|g2
block|,
operator|.
name|p2
operator|.
name|b
operator|=
literal|10
block|}
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: get235
end_comment

begin_function
name|struct
name|P2
name|get235
parameter_list|()
block|{
name|struct
name|P2
name|p
init|=
block|{
literal|2
block|,
literal|3
block|,
literal|5
block|}
decl_stmt|;
return|return
name|p
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: get456789
end_comment

begin_function
name|struct
name|LP2P2
name|get456789
parameter_list|()
block|{
name|struct
name|LP2P2
name|l
init|=
block|{
block|{
literal|4
block|,
literal|5
block|,
literal|6
block|}
block|,
block|{
literal|7
block|,
literal|8
block|,
literal|9
block|}
block|}
decl_stmt|;
return|return
name|l
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: get123
end_comment

begin_function
name|union
name|UP2
name|get123
parameter_list|()
block|{
name|union
name|UP2
name|u
init|=
block|{
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
block|}
decl_stmt|;
return|return
name|u
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test4
end_comment

begin_function
name|void
name|test4
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: [[CALL:%[a-z0-9]+]] = call {{.*}}@get123()
comment|// CHECK: store{{.*}}[[CALL]], {{.*}}[[TMP0:%[a-z0-9]+]]
comment|// CHECK: [[TMP1:%[a-z0-9]+]] = bitcast {{.*}}[[TMP0]]
comment|// CHECK: call void @llvm.memcpy{{.*}}[[TMP1]], i64 12, i32 {{[0-9]}}, i1 false)
comment|// CHECK: store i32 100, i32* %
struct|struct
name|LUP2
block|{
name|union
name|UP2
name|up
decl_stmt|;
block|}
name|var
init|=
block|{
name|get123
argument_list|()
block|,
operator|.
name|up
operator|.
name|p2
operator|.
name|a
operator|=
literal|100
block|}
struct|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test5
end_comment

begin_function
name|void
name|test5
parameter_list|(
name|void
parameter_list|)
block|{
comment|// .l3 = g3
comment|// CHECK: call void @llvm.memcpy{{.*}}%struct.LP3, %struct.LP3* @g3{{.*}}i64 12, i32 {{[0-9]}}, i1 false)
comment|// .l3.p1 = { [0] = g1 } implicitly sets [1] to zero
comment|// CHECK: call void @llvm.memcpy{{.*}}%struct.P1, %struct.P1* @g1{{.*}}i64 6, i32 {{[0-9]}}, i1 false)
comment|// CHECK: getelementptr{{.*}}%struct.P1, %struct.P1*{{.*}}i64 1
comment|// CHECK: call void @llvm.memset{{.*}}i8 0, i64 6, i32 {{[0-9]}}, i1 false)
comment|// .l3.p1[1].x[1] = 'x'
comment|// CHECK: store i8 120, i8* %
name|struct
name|LLP3
name|var
init|=
block|{
operator|.
name|l3
operator|=
name|g3
block|,
operator|.
name|l3
operator|.
name|p1
operator|=
block|{
index|[
literal|0
index|]
operator|=
name|g1
block|}
block|,
operator|.
name|l3
operator|.
name|p1
index|[
literal|1
index|]
operator|.
name|x
index|[
literal|1
index|]
operator|=
literal|'x'
block|}
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test6
end_comment

begin_function
name|void
name|test6
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: [[LP:%[a-z0-9]+]] = getelementptr{{.*}}%struct.LLP2P2, %struct.LLP2P2*{{.*}}, i32 0, i32 0
comment|// CHECK: call {{.*}}get456789(%struct.LP2P2* {{.*}}[[LP]])
comment|// CHECK: [[CALL:%[a-z0-9]+]] = call {{.*}}@get235()
comment|// CHECK: store{{.*}}[[CALL]], {{.*}}[[TMP0:%[a-z0-9]+]]
comment|// CHECK: [[TMP1:%[a-z0-9]+]] = bitcast {{.*}}[[TMP0]]
comment|// CHECK: call void @llvm.memcpy{{.*}}[[TMP1]], i64 12, i32 {{[0-9]}}, i1 false)
comment|// CHECK: store i32 10, i32* %
struct|struct
name|LLP2P2
block|{
name|struct
name|LP2P2
name|lp
decl_stmt|;
block|}
name|var
init|=
block|{
name|get456789
argument_list|()
block|,
operator|.
name|lp
operator|.
name|p1
operator|=
name|get235
argument_list|()
block|,
operator|.
name|lp
operator|.
name|p1
operator|.
name|b
operator|=
literal|10
block|}
struct|;
block|}
end_function

end_unit

