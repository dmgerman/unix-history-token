begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7---eabi -target-abi aapcs -mfloat-abi hard -emit-llvm %s -o - | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|long
name|long
name|int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32_t
typedef|;
end_typedef

begin_comment
comment|/* This is not a homogenous aggregate - fundamental types are different */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|float
name|f
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|i
index|[
literal|4
index|]
decl_stmt|;
block|}
name|union_with_first_floats
typedef|;
end_typedef

begin_decl_stmt
name|union_with_first_floats
name|g_u_f
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|takes_union_with_first_floats
parameter_list|(
name|union_with_first_floats
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|union_with_first_floats
name|returns_union_with_first_floats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_union_with_first_floats
parameter_list|(
name|void
parameter_list|)
block|{
name|takes_union_with_first_floats
argument_list|(
name|g_u_f
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare arm_aapcs_vfpcc void @takes_union_with_first_floats([4 x i32])
end_comment

begin_function
name|void
name|test_return_union_with_first_floats
parameter_list|(
name|void
parameter_list|)
block|{
name|g_u_f
operator|=
name|returns_union_with_first_floats
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare arm_aapcs_vfpcc void @returns_union_with_first_floats(%union.union_with_first_floats* sret)
end_comment

begin_comment
comment|/* This is not a homogenous aggregate - fundamental types are different */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint32_t
name|i
index|[
literal|4
index|]
decl_stmt|;
name|float
name|f
index|[
literal|4
index|]
decl_stmt|;
block|}
name|union_with_non_first_floats
typedef|;
end_typedef

begin_decl_stmt
name|union_with_non_first_floats
name|g_u_nf_f
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|takes_union_with_non_first_floats
parameter_list|(
name|union_with_non_first_floats
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|union_with_non_first_floats
name|returns_union_with_non_first_floats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_union_with_non_first_floats
parameter_list|(
name|void
parameter_list|)
block|{
name|takes_union_with_non_first_floats
argument_list|(
name|g_u_nf_f
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare arm_aapcs_vfpcc void @takes_union_with_non_first_floats([4 x i32])
end_comment

begin_function
name|void
name|test_return_union_with_non_first_floats
parameter_list|(
name|void
parameter_list|)
block|{
name|g_u_nf_f
operator|=
name|returns_union_with_non_first_floats
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare arm_aapcs_vfpcc void @returns_union_with_non_first_floats(%union.union_with_non_first_floats* sret)
end_comment

begin_comment
comment|/* This is not a homogenous aggregate - fundamental types are different */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|a
decl_stmt|;
name|union_with_first_floats
name|b
decl_stmt|;
block|}
name|struct_with_union_with_first_floats
typedef|;
end_typedef

begin_decl_stmt
name|struct_with_union_with_first_floats
name|g_s_f
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|takes_struct_with_union_with_first_floats
parameter_list|(
name|struct_with_union_with_first_floats
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct_with_union_with_first_floats
name|returns_struct_with_union_with_first_floats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_struct_with_union_with_first_floats
parameter_list|(
name|void
parameter_list|)
block|{
name|takes_struct_with_union_with_first_floats
argument_list|(
name|g_s_f
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare arm_aapcs_vfpcc void @takes_struct_with_union_with_first_floats([5 x i32])
end_comment

begin_function
name|void
name|test_return_struct_with_union_with_first_floats
parameter_list|(
name|void
parameter_list|)
block|{
name|g_s_f
operator|=
name|returns_struct_with_union_with_first_floats
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare arm_aapcs_vfpcc void @returns_struct_with_union_with_first_floats(%struct.struct_with_union_with_first_floats* sret)
end_comment

begin_comment
comment|/* This is not a homogenous aggregate - fundamental types are different */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|a
decl_stmt|;
name|union_with_non_first_floats
name|b
decl_stmt|;
block|}
name|struct_with_union_with_non_first_floats
typedef|;
end_typedef

begin_decl_stmt
name|struct_with_union_with_non_first_floats
name|g_s_nf_f
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|takes_struct_with_union_with_non_first_floats
parameter_list|(
name|struct_with_union_with_non_first_floats
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct_with_union_with_non_first_floats
name|returns_struct_with_union_with_non_first_floats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_struct_with_union_with_non_first_floats
parameter_list|(
name|void
parameter_list|)
block|{
name|takes_struct_with_union_with_non_first_floats
argument_list|(
name|g_s_nf_f
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare arm_aapcs_vfpcc void @takes_struct_with_union_with_non_first_floats([5 x i32])
end_comment

begin_function
name|void
name|test_return_struct_with_union_with_non_first_floats
parameter_list|(
name|void
parameter_list|)
block|{
name|g_s_nf_f
operator|=
name|returns_struct_with_union_with_non_first_floats
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare arm_aapcs_vfpcc void @returns_struct_with_union_with_non_first_floats(%struct.struct_with_union_with_non_first_floats* sret)
end_comment

begin_comment
comment|/* Plain array is not a homogenous aggregate */
end_comment

begin_function_decl
specifier|extern
name|void
name|takes_array_of_floats
parameter_list|(
name|float
name|a
index|[
literal|4
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_array_of_floats
parameter_list|(
name|void
parameter_list|)
block|{
name|float
name|a
index|[
literal|4
index|]
init|=
block|{
literal|1.0
block|,
literal|2.0
block|,
literal|3.0
block|,
literal|4.0
block|}
decl_stmt|;
name|takes_array_of_floats
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare arm_aapcs_vfpcc void @takes_array_of_floats(float*)
end_comment

begin_comment
comment|/* Struct-type homogenous aggregate */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|,
name|w
decl_stmt|;
block|}
name|struct_with_fundamental_elems
typedef|;
end_typedef

begin_decl_stmt
name|struct_with_fundamental_elems
name|g_s
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|takes_struct_with_fundamental_elems
parameter_list|(
name|struct_with_fundamental_elems
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct_with_fundamental_elems
name|returns_struct_with_fundamental_elems
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_struct_with_fundamental_elems
parameter_list|(
name|void
parameter_list|)
block|{
name|takes_struct_with_fundamental_elems
argument_list|(
name|g_s
argument_list|)
expr_stmt|;
comment|// CHECK:  call arm_aapcs_vfpcc  void @takes_struct_with_fundamental_elems(float {{.*}}, float {{.*}}, float{{.*}}, float {{.*}})
block|}
end_function

begin_comment
comment|// CHECK: declare arm_aapcs_vfpcc void @takes_struct_with_fundamental_elems(float, float, float, float)
end_comment

begin_function
name|void
name|test_return_struct_with_fundamental_elems
parameter_list|(
name|void
parameter_list|)
block|{
name|g_s
operator|=
name|returns_struct_with_fundamental_elems
argument_list|()
expr_stmt|;
comment|// CHECK: call arm_aapcs_vfpcc  %struct.struct_with_fundamental_elems @returns_struct_with_fundamental_elems()
block|}
end_function

begin_comment
comment|// CHECK: declare arm_aapcs_vfpcc %struct.struct_with_fundamental_elems @returns_struct_with_fundamental_elems()
end_comment

begin_comment
comment|/* Array-type homogenous aggregate */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|xyzw
index|[
literal|4
index|]
decl_stmt|;
block|}
name|struct_with_array
typedef|;
end_typedef

begin_decl_stmt
name|struct_with_array
name|g_s_a
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|takes_struct_with_array
parameter_list|(
name|struct_with_array
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct_with_array
name|returns_struct_with_array
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_struct_with_array
parameter_list|(
name|void
parameter_list|)
block|{
name|takes_struct_with_array
argument_list|(
name|g_s_a
argument_list|)
expr_stmt|;
comment|// CHECK:   call arm_aapcs_vfpcc  void @takes_struct_with_array(float {{.*}}, float {{.*}}, float {{.*}}, float {{.*}})
block|}
end_function

begin_comment
comment|// CHECK: declare arm_aapcs_vfpcc void @takes_struct_with_array(float, float, float, float)
end_comment

begin_function
name|void
name|test_return_struct_with_array
parameter_list|(
name|void
parameter_list|)
block|{
name|g_s_a
operator|=
name|returns_struct_with_array
argument_list|()
expr_stmt|;
comment|// CHECK:   call arm_aapcs_vfpcc  %struct.struct_with_array @returns_struct_with_array()
block|}
end_function

begin_comment
comment|// CHECK: declare arm_aapcs_vfpcc %struct.struct_with_array @returns_struct_with_array()
end_comment

begin_comment
comment|/* This union is a homogenous aggregate. Check that it's passed properly */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|struct_with_fundamental_elems
name|xyzw
decl_stmt|;
name|float
name|a
index|[
literal|3
index|]
decl_stmt|;
block|}
name|union_with_struct_with_fundamental_elems
typedef|;
end_typedef

begin_decl_stmt
name|union_with_struct_with_fundamental_elems
name|g_u_s_fe
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|takes_union_with_struct_with_fundamental_elems
parameter_list|(
name|union_with_struct_with_fundamental_elems
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|union_with_struct_with_fundamental_elems
name|returns_union_with_struct_with_fundamental_elems
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_union_with_struct_with_fundamental_elems
parameter_list|(
name|void
parameter_list|)
block|{
name|takes_union_with_struct_with_fundamental_elems
argument_list|(
name|g_u_s_fe
argument_list|)
expr_stmt|;
comment|// CHECK: call arm_aapcs_vfpcc  void @takes_union_with_struct_with_fundamental_elems(float {{.*}}, float {{.*}}, float {{.*}}, float {{.*}})
block|}
end_function

begin_comment
comment|// CHECK: declare arm_aapcs_vfpcc void @takes_union_with_struct_with_fundamental_elems(float, float, float, float)
end_comment

begin_function
name|void
name|test_return_union_with_struct_with_fundamental_elems
parameter_list|(
name|void
parameter_list|)
block|{
name|g_u_s_fe
operator|=
name|returns_union_with_struct_with_fundamental_elems
argument_list|()
expr_stmt|;
comment|// CHECK: call arm_aapcs_vfpcc  %union.union_with_struct_with_fundamental_elems @returns_union_with_struct_with_fundamental_elems()
block|}
end_function

begin_comment
comment|// CHECK: declare arm_aapcs_vfpcc %union.union_with_struct_with_fundamental_elems @returns_union_with_struct_with_fundamental_elems()
end_comment

begin_comment
comment|// FIXME: Tests necessary:
end_comment

begin_comment
comment|//         - Vectors
end_comment

begin_comment
comment|//         - C++ stuff
end_comment

end_unit

