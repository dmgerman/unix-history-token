begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=%itanium_abi_triple -emit-llvm< %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-IT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple=%ms_abi_triple -emit-llvm< %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-MS
end_comment

begin_decl_stmt
name|int
name|S
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|int
name|vS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|pS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|int
modifier|*
name|pvS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|A
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|int
name|vA
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
block|{
name|int
name|x
decl_stmt|;
block|}
name|F
struct|;
end_struct

begin_struct
struct|struct
block|{
specifier|volatile
name|int
name|x
decl_stmt|;
block|}
name|vF
struct|;
end_struct

begin_struct
struct|struct
block|{
name|int
name|x
decl_stmt|;
block|}
name|F2
struct|;
end_struct

begin_struct
specifier|volatile
struct|struct
block|{
name|int
name|x
decl_stmt|;
block|}
name|vF2
struct|;
end_struct

begin_struct
specifier|volatile
struct|struct
block|{
name|int
name|x
decl_stmt|;
block|}
modifier|*
name|vpF2
struct|;
end_struct

begin_struct
struct|struct
block|{
struct|struct
block|{
name|int
name|y
decl_stmt|;
block|}
name|x
struct|;
block|}
name|F3
struct|;
end_struct

begin_struct
specifier|volatile
struct|struct
block|{
struct|struct
block|{
name|int
name|y
decl_stmt|;
block|}
name|x
struct|;
block|}
name|vF3
struct|;
end_struct

begin_struct
struct|struct
block|{
name|int
name|x
range|:
literal|3
decl_stmt|;
block|}
name|BF
struct|;
end_struct

begin_struct
struct|struct
block|{
specifier|volatile
name|int
name|x
range|:
literal|3
decl_stmt|;
block|}
name|vBF
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
name|v4si
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_decl_stmt
name|v4si
name|V
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|v4si
name|vV
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|4
argument|) )
argument_list|)
name|int
name|extv4
typedef|;
end_typedef

begin_decl_stmt
name|extv4
name|VE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|extv4
name|vVE
decl_stmt|;
end_decl_stmt

begin_struct
specifier|volatile
struct|struct
block|{
name|int
name|x
decl_stmt|;
block|}
name|aggFct
argument_list|(
name|void
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
specifier|volatile
name|int
name|volatile_int
typedef|;
end_typedef

begin_decl_stmt
name|volatile_int
name|vtS
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
comment|// CHECK: [[I:%[a-zA-Z0-9_.]+]] = alloca i32
comment|// load
name|i
operator|=
name|S
expr_stmt|;
comment|// CHECK: load i32* @S
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|vS
expr_stmt|;
comment|// CHECK: load volatile i32* @vS
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
operator|*
name|pS
expr_stmt|;
comment|// CHECK: [[PS_VAL:%[a-zA-Z0-9_.]+]] = load i32** @pS
comment|// CHECK: load i32* [[PS_VAL]]
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
operator|*
name|pvS
expr_stmt|;
comment|// CHECK: [[PVS_VAL:%[a-zA-Z0-9_.]+]] = load i32** @pvS
comment|// CHECK: load volatile i32* [[PVS_VAL]]
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|A
index|[
literal|2
index|]
expr_stmt|;
comment|// CHECK: load i32* getelementptr {{.*}} @A
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|vA
index|[
literal|2
index|]
expr_stmt|;
comment|// CHECK: load volatile i32* getelementptr {{.*}} @vA
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|F
operator|.
name|x
expr_stmt|;
comment|// CHECK: load i32* getelementptr {{.*}} @F
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|vF
operator|.
name|x
expr_stmt|;
comment|// CHECK: load volatile i32* getelementptr {{.*}} @vF
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|F2
operator|.
name|x
expr_stmt|;
comment|// CHECK: load i32* getelementptr {{.*}} @F2
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|vF2
operator|.
name|x
expr_stmt|;
comment|// CHECK: load volatile i32* getelementptr {{.*}} @vF2
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|vpF2
operator|->
name|x
expr_stmt|;
comment|// CHECK: [[VPF2_VAL:%[a-zA-Z0-9_.]+]] = load {{%[a-zA-Z0-9_.]+}}** @vpF2
comment|// CHECK: [[ELT:%[a-zA-Z0-9_.]+]] = getelementptr {{.*}} [[VPF2_VAL]]
comment|// CHECK: load volatile i32* [[ELT]]
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|F3
operator|.
name|x
operator|.
name|y
expr_stmt|;
comment|// CHECK: load i32* getelementptr {{.*}} @F3
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|vF3
operator|.
name|x
operator|.
name|y
expr_stmt|;
comment|// CHECK: load volatile i32* getelementptr {{.*}} @vF3
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|BF
operator|.
name|x
expr_stmt|;
comment|// CHECK-IT: load i8* getelementptr {{.*}} @BF
comment|// CHECK-MS: load i32* getelementptr {{.*}} @BF
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|vBF
operator|.
name|x
expr_stmt|;
comment|// CHECK-IT: load volatile i8* getelementptr {{.*}} @vBF
comment|// CHECK-MS: load volatile i32* getelementptr {{.*}} @vBF
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|V
index|[
literal|3
index|]
expr_stmt|;
comment|// CHECK: load<4 x i32>* @V
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|vV
index|[
literal|3
index|]
expr_stmt|;
comment|// CHECK: load volatile<4 x i32>* @vV
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|VE
operator|.
name|yx
index|[
literal|1
index|]
expr_stmt|;
comment|// CHECK: load<4 x i32>* @VE
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|vVE
operator|.
name|zy
index|[
literal|1
index|]
expr_stmt|;
comment|// CHECK: load volatile<4 x i32>* @vVE
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|aggFct
argument_list|()
operator|.
name|x
expr_stmt|;
comment|// Note: not volatile
comment|// N.b. Aggregate return is extremely target specific, all we can
comment|// really say here is that there probably shouldn't be a volatile
comment|// load.
comment|// CHECK-NOT: load volatile
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|=
name|vtS
expr_stmt|;
comment|// CHECK: load volatile i32* @vtS
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
comment|// store
name|S
operator|=
name|i
expr_stmt|;
comment|// CHECK: load i32* [[I]]
comment|// CHECK: store i32 {{.*}}, i32* @S
name|vS
operator|=
name|i
expr_stmt|;
comment|// CHECK: load i32* [[I]]
comment|// CHECK: store volatile i32 {{.*}}, i32* @vS
operator|*
name|pS
operator|=
name|i
expr_stmt|;
comment|// CHECK: load i32* [[I]]
comment|// CHECK: [[PS_VAL:%[a-zA-Z0-9_.]+]] = load i32** @pS
comment|// CHECK: store i32 {{.*}}, i32* [[PS_VAL]]
operator|*
name|pvS
operator|=
name|i
expr_stmt|;
comment|// CHECK: load i32* [[I]]
comment|// CHECK: [[PVS_VAL:%[a-zA-Z0-9_.]+]] = load i32** @pvS
comment|// CHECK: store volatile i32 {{.*}}, i32* [[PVS_VAL]]
name|A
index|[
literal|2
index|]
operator|=
name|i
expr_stmt|;
comment|// CHECK: load i32* [[I]]
comment|// CHECK: store i32 {{.*}}, i32* getelementptr {{.*}} @A
name|vA
index|[
literal|2
index|]
operator|=
name|i
expr_stmt|;
comment|// CHECK: load i32* [[I]]
comment|// CHECK: store volatile i32 {{.*}}, i32* getelementptr {{.*}} @vA
name|F
operator|.
name|x
operator|=
name|i
expr_stmt|;
comment|// CHECK: load i32* [[I]]
comment|// CHECK: store i32 {{.*}}, i32* getelementptr {{.*}} @F
name|vF
operator|.
name|x
operator|=
name|i
expr_stmt|;
comment|// CHECK: load i32* [[I]]
comment|// CHECK: store volatile i32 {{.*}}, i32* getelementptr {{.*}} @vF
name|F2
operator|.
name|x
operator|=
name|i
expr_stmt|;
comment|// CHECK: load i32* [[I]]
comment|// CHECK: store i32 {{.*}}, i32* getelementptr {{.*}} @F2
name|vF2
operator|.
name|x
operator|=
name|i
expr_stmt|;
comment|// CHECK: load i32* [[I]]
comment|// CHECK: store volatile i32 {{.*}}, i32* getelementptr {{.*}} @vF2
name|vpF2
operator|->
name|x
operator|=
name|i
expr_stmt|;
comment|// CHECK: load i32* [[I]]
comment|// CHECK: [[VPF2_VAL:%[a-zA-Z0-9_.]+]] = load {{%[a-zA-Z0-9._]+}}** @vpF2
comment|// CHECK: [[ELT:%[a-zA-Z0-9_.]+]] = getelementptr {{.*}} [[VPF2_VAL]]
comment|// CHECK: store volatile i32 {{.*}}, i32* [[ELT]]
name|vF3
operator|.
name|x
operator|.
name|y
operator|=
name|i
expr_stmt|;
comment|// CHECK: load i32* [[I]]
comment|// CHECK: store volatile i32 {{.*}}, i32* getelementptr {{.*}} @vF3
name|BF
operator|.
name|x
operator|=
name|i
expr_stmt|;
comment|// CHECK: load i32* [[I]]
comment|// CHECK-IT: load i8* getelementptr {{.*}} @BF
comment|// CHECK-MS: load i32* getelementptr {{.*}} @BF
comment|// CHECK-IT: store i8 {{.*}}, i8* getelementptr {{.*}} @BF
comment|// CHECK-MS: store i32 {{.*}}, i32* getelementptr {{.*}} @BF
name|vBF
operator|.
name|x
operator|=
name|i
expr_stmt|;
comment|// CHECK: load i32* [[I]]
comment|// CHECK-IT: load volatile i8* getelementptr {{.*}} @vBF
comment|// CHECK-MS: load volatile i32* getelementptr {{.*}} @vBF
comment|// CHECK-IT: store volatile i8 {{.*}}, i8* getelementptr {{.*}} @vBF
comment|// CHECK-MS: store volatile i32 {{.*}}, i32* getelementptr {{.*}} @vBF
name|V
index|[
literal|3
index|]
operator|=
name|i
expr_stmt|;
comment|// CHECK: load i32* [[I]]
comment|// CHECK: load<4 x i32>* @V
comment|// CHECK: store<4 x i32> {{.*}},<4 x i32>* @V
name|vV
index|[
literal|3
index|]
operator|=
name|i
expr_stmt|;
comment|// CHECK: load i32* [[I]]
comment|// CHECK: load volatile<4 x i32>* @vV
comment|// CHECK: store volatile<4 x i32> {{.*}},<4 x i32>* @vV
name|vtS
operator|=
name|i
expr_stmt|;
comment|// CHECK: load i32* [[I]]
comment|// CHECK: store volatile i32 {{.*}}, i32* @vtS
comment|// other ops:
operator|++
name|S
expr_stmt|;
comment|// CHECK: load i32* @S
comment|// CHECK: store i32 {{.*}}, i32* @S
operator|++
name|vS
expr_stmt|;
comment|// CHECK: load volatile i32* @vS
comment|// CHECK: store volatile i32 {{.*}}, i32* @vS
name|i
operator|+=
name|S
expr_stmt|;
comment|// CHECK: load i32* @S
comment|// CHECK: load i32* [[I]]
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
name|i
operator|+=
name|vS
expr_stmt|;
comment|// CHECK: load volatile i32* @vS
comment|// CHECK: load i32* [[I]]
comment|// CHECK: store i32 {{.*}}, i32* [[I]]
operator|++
name|vtS
expr_stmt|;
comment|// CHECK: load volatile i32* @vtS
comment|// CHECK: store volatile i32 {{.*}}, i32* @vtS
operator|(
name|void
operator|)
name|vF2
expr_stmt|;
comment|// From vF2 to a temporary
comment|// CHECK: call void @llvm.memcpy.{{.*}}(i8* %{{.*}}, i8* {{.*}} @vF2 {{.*}}, i1 true)
name|vF2
operator|=
name|vF2
expr_stmt|;
comment|// vF2 to itself
comment|// CHECK: call void @llvm.memcpy.{{.*}}(i8* {{.*@vF2.*}}, i8* {{.*@vF2.*}}, i1 true)
name|vF2
operator|=
name|vF2
operator|=
name|vF2
expr_stmt|;
comment|// vF2 to itself twice
comment|// CHECK: call void @llvm.memcpy.{{.*}}(i8* {{.*@vF2.*}}, i8* {{.*@vF2.*}}, i1 true)
comment|// CHECK: call void @llvm.memcpy.{{.*}}(i8* {{.*@vF2.*}}, i8* {{.*@vF2.*}}, i1 true)
name|vF2
operator|=
operator|(
name|vF2
operator|,
name|vF2
operator|)
expr_stmt|;
comment|// vF2 to a temporary, then vF2 to itself
comment|// CHECK: call void @llvm.memcpy.{{.*}}(i8* %{{.*}}, i8* {{.*@vF2.*}}, i1 true)
comment|// CHECK: call void @llvm.memcpy.{{.*}}(i8* {{.*@vF2.*}}, i8* {{.*@vF2.*}}, i1 true)
block|}
end_function

end_unit

