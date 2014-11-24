begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fblocks -emit-llvm %s -o %t
end_comment

begin_comment
comment|// RUN: FileCheck %s -input-file=%t -check-prefix=CHECK1
end_comment

begin_comment
comment|// RUN: FileCheck %s -input-file=%t -check-prefix=CHECK2
end_comment

begin_struct
struct|struct
name|A
block|{
name|int
name|a
decl_stmt|;
name|float
name|b
decl_stmt|;
name|char
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|test_nest_captured_stmt
parameter_list|(
name|int
name|param
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|param_arr
index|[
name|size
index|]
parameter_list|)
block|{
name|int
name|w
decl_stmt|;
name|int
name|arr
index|[
name|param
index|]
index|[
name|size
index|]
decl_stmt|;
comment|// CHECK1: %struct.anon{{.*}} = type { i32*, i32*, i{{.+}}*, i32**, i32* }
comment|// CHECK1: %struct.anon{{.*}} = type { i32*, i32*, i32**, i32*, i{{.+}}*, i32**, i32* }
comment|// CHECK1: [[T:%struct.anon.*]] = type { i32*, i32*, %struct.A*, i32**, i32*, i{{.+}}*, i32**, i32* }
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
name|int
name|x
decl_stmt|;
name|int
modifier|*
name|y
init|=
operator|&
name|w
decl_stmt|;
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
name|struct
name|A
name|z
decl_stmt|;
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
name|w
operator|=
name|x
operator|=
name|z
operator|.
name|a
operator|=
literal|1
expr_stmt|;
operator|*
name|y
operator|=
name|param
expr_stmt|;
name|z
operator|.
name|b
operator|=
literal|0.1f
expr_stmt|;
name|z
operator|.
name|c
operator|=
literal|'c'
expr_stmt|;
name|param_arr
index|[
name|size
operator|-
literal|1
index|]
operator|=
literal|2
expr_stmt|;
name|arr
index|[
literal|10
index|]
index|[
name|z
operator|.
name|a
index|]
operator|=
literal|12
expr_stmt|;
comment|// CHECK1: define internal void @__captured_stmt{{.*}}([[T]]
comment|//
comment|// CHECK1: getelementptr inbounds [[T]]* {{.*}}, i32 0, i32 2
comment|// CHECK1-NEXT: load %struct.A**
comment|// CHECK1-NEXT: getelementptr inbounds %struct.A*
comment|// CHECK1-NEXT: store i{{.+}} 1
comment|//
comment|// CHECK1: getelementptr inbounds [[T]]* {{.*}}, i32 0, i32 1
comment|// CHECK1-NEXT: load i32**
comment|// CHECK1-NEXT: store i32 1
comment|//
comment|// CHECK1: getelementptr inbounds [[T]]* {{.*}}, i32 0, i32 0
comment|// CHECK1-NEXT: load i32**
comment|// CHECK1-NEXT: store i32 1
comment|//
comment|// CHECK1: getelementptr inbounds [[T]]* {{.*}}, i32 0, i32 4
comment|// CHECK1-NEXT: load i32**
comment|// CHECK1-NEXT: load i32*
comment|// CHECK1-NEXT: getelementptr inbounds [[T]]* {{.*}}, i32 0, i32 3
comment|// CHECK1-NEXT: load i32***
comment|// CHECK1-NEXT: load i32**
comment|// CHECK1-NEXT: store i32
comment|//
comment|// CHECK1: getelementptr inbounds [[T]]* {{.*}}, i32 0, i32 2
comment|// CHECK1-NEXT: load %struct.A**
comment|// CHECK1-NEXT: getelementptr inbounds %struct.A*
comment|// CHECK1-NEXT: store float
comment|//
comment|// CHECK1: getelementptr inbounds [[T]]* {{.*}}, i32 0, i32 2
comment|// CHECK1-NEXT: load %struct.A**
comment|// CHECK1-NEXT: getelementptr inbounds %struct.A*
comment|// CHECK1-NEXT: store i8 99
comment|//
comment|// CHECK1: [[SIZE_ADDR_REF:%.*]] = getelementptr inbounds [[T]]* {{.*}}, i{{.+}} 0, i{{.+}} 5
comment|// CHECK1-DAG: [[SIZE_ADDR:%.*]] = load i{{.+}}** [[SIZE_ADDR_REF]]
comment|// CHECK1-DAG: [[SIZE:%.*]] = load i{{.+}}* [[SIZE_ADDR]]
comment|// CHECK1-DAG: [[PARAM_ARR_IDX:%.*]] = sub nsw i{{.+}} [[SIZE]], 1
comment|// CHECK1-DAG: [[PARAM_ARR_ADDR_REF:%.*]] = getelementptr inbounds [[T]]* {{.*}}, i{{.+}} 0, i{{.+}} 6
comment|// CHECK1-DAG: [[PARAM_ARR_ADDR:%.*]] = load i{{.+}}*** [[PARAM_ARR_ADDR_REF]]
comment|// CHECK1-DAG: [[PARAM_ARR:%.*]] = load i{{.+}}** [[PARAM_ARR_ADDR]]
comment|// CHECK1-DAG: [[PARAM_ARR_SIZE_MINUS_1_ADDR:%.*]] = getelementptr inbounds i{{.+}}* [[PARAM_ARR]], i{{.*}}
comment|// CHECK1: store i{{.+}} 2, i{{.+}}* [[PARAM_ARR_SIZE_MINUS_1_ADDR]]
comment|//
comment|// CHECK1: [[Z_ADDR_REF:%.*]] = getelementptr inbounds [[T]]* {{.*}}, i{{.+}} 0, i{{.+}} 2
comment|// CHECK1-DAG: [[Z_ADDR:%.*]] = load %struct.A** [[Z_ADDR_REF]]
comment|// CHECK1-DAG: [[Z_A_ADDR:%.*]] = getelementptr inbounds %struct.A* [[Z_ADDR]], i{{.+}} 0, i{{.+}} 0
comment|// CHECK1-DAG: [[ARR_IDX_2:%.*]] = load i{{.+}}* [[Z_A_ADDR]]
comment|// CHECK1-DAG: [[ARR_ADDR_REF:%.*]] = getelementptr inbounds [[T]]* {{.*}}, i{{.+}} 0, i{{.+}} 7
comment|// CHECK1-DAG: [[ARR_ADDR:%.*]] = load i{{.+}}** [[ARR_ADDR_REF]]
comment|// CHECK1-DAG: [[ARR_IDX_1:%.*]] = mul {{.*}} 10
comment|// CHECK1-DAG: [[ARR_10_ADDR:%.*]] = getelementptr inbounds i{{.+}}* [[ARR_ADDR]], i{{.*}} [[ARR_IDX_1]]
comment|// CHECK1-DAG: [[ARR_10_Z_A_ADDR:%.*]] = getelementptr inbounds i{{.+}}* [[ARR_10_ADDR]], i{{.*}}
comment|// CHECK1: store i{{.+}} 12, i{{.+}}* [[ARR_10_Z_A_ADDR]]
block|}
block|}
block|}
block|}
end_function

begin_function
name|void
name|test_nest_block
parameter_list|()
block|{
specifier|__block
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
lambda|^
block|{
name|int
name|z
decl_stmt|;
name|x
operator|=
name|z
expr_stmt|;
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
name|z
operator|=
name|y
expr_stmt|;
comment|// OK
block|}
block|}
argument_list|()
expr_stmt|;
comment|// CHECK2: define internal void @{{.*}}test_nest_block_block_invoke
comment|//
comment|// CHECK2: [[Z:%[0-9a-z_]*]] = alloca i32
comment|// CHECK2: alloca %struct.anon{{.*}}
comment|//
comment|// CHECK2: store i32
comment|// CHECK2: store i32* [[Z]]
comment|//
comment|// CHECK2: getelementptr inbounds %struct.anon
comment|// CHECK2-NEXT: getelementptr inbounds
comment|// CHECK2-NEXT: store i32*
comment|//
comment|// CHECK2: call void @__captured_stmt
name|int
name|a
decl_stmt|;
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
specifier|__block
name|int
name|b
decl_stmt|;
name|int
name|c
decl_stmt|;
specifier|__block
name|int
name|d
decl_stmt|;
lambda|^
block|{
name|b
operator|=
name|a
expr_stmt|;
name|b
operator|=
name|c
expr_stmt|;
name|b
operator|=
name|d
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
block|}
comment|// CHECK2: alloca %struct.__block_byref_b
comment|// CHECK2-NEXT: [[C:%[0-9a-z_]*]] = alloca i32
comment|// CHECK2-NEXT: alloca %struct.__block_byref_d
comment|//
comment|// CHECK2: bitcast %struct.__block_byref_b*
comment|// CHECK2-NEXT: store i8*
comment|//
comment|// CHECK2: [[CapA:%[0-9a-z_.]*]] = getelementptr inbounds {{.*}}, i32 0, i32 7
comment|//
comment|// CHECK2: getelementptr inbounds %struct.anon{{.*}}, i32 0, i32 0
comment|// CHECK2: load i32**
comment|// CHECK2: load i32*
comment|// CHECK2: store i32 {{.*}}, i32* [[CapA]]
comment|//
comment|// CHECK2: [[CapC:%[0-9a-z_.]*]] = getelementptr inbounds {{.*}}, i32 0, i32 8
comment|// CHECK2-NEXT: [[Val:%[0-9a-z_]*]] = load i32* [[C]]
comment|// CHECK2-NEXT: store i32 [[Val]], i32* [[CapC]]
comment|//
comment|// CHECK2: bitcast %struct.__block_byref_d*
comment|// CHECK2-NEXT: store i8*
block|}
end_function

end_unit

