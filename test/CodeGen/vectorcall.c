begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -triple=i386-pc-win32 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -triple=x86_64-pc-win32 | FileCheck %s --check-prefix=X64
end_comment

begin_function
name|void
name|__vectorcall
name|v1
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01v1@@8"(i32 inreg %a, i32 inreg %b)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01v1@@16"(i32 %a, i32 %b)
end_comment

begin_function
name|void
name|__vectorcall
name|v2
parameter_list|(
name|char
name|a
parameter_list|,
name|char
name|b
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01v2@@8"(i8 inreg signext %a, i8 inreg signext %b)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01v2@@16"(i8 %a, i8 %b)
end_comment

begin_struct
struct|struct
name|Small
block|{
name|int
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|__vectorcall
name|v3
parameter_list|(
name|int
name|a
parameter_list|,
name|struct
name|Small
name|b
parameter_list|,
name|int
name|c
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01v3@@12"(i32 inreg %a, %struct.Small* byval align 4 %b, i32 inreg %c)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01v3@@24"(i32 %a, i32 %b.coerce, i32 %c)
end_comment

begin_struct
struct|struct
name|Large
block|{
name|int
name|a
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|__vectorcall
name|v4
parameter_list|(
name|int
name|a
parameter_list|,
name|struct
name|Large
name|b
parameter_list|,
name|int
name|c
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01v4@@28"(i32 inreg %a, %struct.Large* byval align 4 %b, i32 inreg %c)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01v4@@40"(i32 %a, %struct.Large* %b, i32 %c)
end_comment

begin_struct
struct|struct
name|HFA2
block|{
name|double
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|HFA4
block|{
name|double
name|w
decl_stmt|,
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|HFA5
block|{
name|double
name|v
decl_stmt|,
name|w
decl_stmt|,
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|__vectorcall
name|hfa1
parameter_list|(
name|int
name|a
parameter_list|,
name|struct
name|HFA4
name|b
parameter_list|,
name|int
name|c
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01hfa1@@40"(i32 inreg %a, double %b.0, double %b.1, double %b.2, double %b.3, i32 inreg %c)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01hfa1@@48"(i32 %a, double %b.0, double %b.1, double %b.2, double %b.3, i32 %c)
end_comment

begin_comment
comment|// HFAs that would require more than six total SSE registers are passed
end_comment

begin_comment
comment|// indirectly. Additional vector arguments can consume the rest of the SSE
end_comment

begin_comment
comment|// registers.
end_comment

begin_function
name|void
name|__vectorcall
name|hfa2
parameter_list|(
name|struct
name|HFA4
name|a
parameter_list|,
name|struct
name|HFA4
name|b
parameter_list|,
name|double
name|c
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01hfa2@@72"(double %a.0, double %a.1, double %a.2, double %a.3, %struct.HFA4* inreg %b, double %c)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01hfa2@@72"(double %a.0, double %a.1, double %a.2, double %a.3, %struct.HFA4* align 8 %b, double %c)
end_comment

begin_comment
comment|// Ensure that we pass builtin types directly while counting them against the
end_comment

begin_comment
comment|// SSE register usage.
end_comment

begin_function
name|void
name|__vectorcall
name|hfa3
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|,
name|double
name|c
parameter_list|,
name|double
name|d
parameter_list|,
name|double
name|e
parameter_list|,
name|struct
name|HFA2
name|f
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01hfa3@@56"(double %a, double %b, double %c, double %d, double %e, %struct.HFA2* inreg %f)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01hfa3@@56"(double %a, double %b, double %c, double %d, double %e, %struct.HFA2* align 8 %f)
end_comment

begin_comment
comment|// Aggregates with more than four elements are not HFAs and are passed byval.
end_comment

begin_comment
comment|// Because they are not classified as homogeneous, they don't get special
end_comment

begin_comment
comment|// handling to ensure alignment.
end_comment

begin_function
name|void
name|__vectorcall
name|hfa4
parameter_list|(
name|struct
name|HFA5
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01hfa4@@40"(%struct.HFA5* byval align 4)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01hfa4@@40"(%struct.HFA5* %a)
end_comment

begin_comment
comment|// Return HFAs of 4 or fewer elements in registers.
end_comment

begin_decl_stmt
specifier|static
name|struct
name|HFA2
name|g_hfa2
decl_stmt|;
end_decl_stmt

begin_function
name|struct
name|HFA2
name|__vectorcall
name|hfa5
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|g_hfa2
return|;
block|}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc %struct.HFA2 @"\01hfa5@@0"()
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc %struct.HFA2 @"\01hfa5@@0"()
end_comment

begin_typedef
typedef|typedef
name|float
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|v4f32
typedef|;
end_typedef

begin_struct
struct|struct
name|HVA2
block|{
name|v4f32
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|HVA4
block|{
name|v4f32
name|w
decl_stmt|,
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|__vectorcall
name|hva1
parameter_list|(
name|int
name|a
parameter_list|,
name|struct
name|HVA4
name|b
parameter_list|,
name|int
name|c
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01hva1@@72"(i32 inreg %a,<4 x float> %b.0,<4 x float> %b.1,<4 x float> %b.2,<4 x float> %b.3, i32 inreg %c)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01hva1@@80"(i32 %a,<4 x float> %b.0,<4 x float> %b.1,<4 x float> %b.2,<4 x float> %b.3, i32 %c)
end_comment

begin_function
name|void
name|__vectorcall
name|hva2
parameter_list|(
name|struct
name|HVA4
name|a
parameter_list|,
name|struct
name|HVA4
name|b
parameter_list|,
name|v4f32
name|c
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01hva2@@144"(<4 x float> %a.0,<4 x float> %a.1,<4 x float> %a.2,<4 x float> %a.3, %struct.HVA4* inreg %b,<4 x float> %c)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01hva2@@144"(<4 x float> %a.0,<4 x float> %a.1,<4 x float> %a.2,<4 x float> %a.3, %struct.HVA4* align 16 %b,<4 x float> %c)
end_comment

begin_function
name|void
name|__vectorcall
name|hva3
parameter_list|(
name|v4f32
name|a
parameter_list|,
name|v4f32
name|b
parameter_list|,
name|v4f32
name|c
parameter_list|,
name|v4f32
name|d
parameter_list|,
name|v4f32
name|e
parameter_list|,
name|struct
name|HVA2
name|f
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01hva3@@112"(<4 x float> %a,<4 x float> %b,<4 x float> %c,<4 x float> %d,<4 x float> %e, %struct.HVA2* inreg %f)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01hva3@@112"(<4 x float> %a,<4 x float> %b,<4 x float> %c,<4 x float> %d,<4 x float> %e, %struct.HVA2* align 16 %f)
end_comment

begin_typedef
typedef|typedef
name|float
name|__attribute__
argument_list|(
operator|(
name|ext_vector_type
argument_list|(
literal|3
argument_list|)
operator|)
argument_list|)
name|v3f32
typedef|;
end_typedef

begin_struct
struct|struct
name|OddSizeHVA
block|{
name|v3f32
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|__vectorcall
name|odd_size_hva
parameter_list|(
name|struct
name|OddSizeHVA
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01odd_size_hva@@32"(<3 x float> %a.0,<3 x float> %a.1)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01odd_size_hva@@32"(<3 x float> %a.0,<3 x float> %a.1)
end_comment

end_unit

