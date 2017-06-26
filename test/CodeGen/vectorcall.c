begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -ffreestanding -triple=i386-pc-win32       | FileCheck %s --check-prefix=X32
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -ffreestanding -triple=x86_64-pc-win32     | FileCheck %s --check-prefix=X64
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
comment|// X32: define x86_vectorcallcc void @"\01v1@@8"(i32 inreg %a, i32 inreg %b)
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
comment|// X32: define x86_vectorcallcc void @"\01v2@@8"(i8 inreg signext %a, i8 inreg signext %b)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01v2@@16"(i8 %a, i8 %b)
end_comment

begin_struct
struct|struct
name|Small
block|{
name|int
name|x
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
comment|// X32: define x86_vectorcallcc void @"\01v3@@12"(i32 inreg %a, i32 %b.0, i32 inreg %c)
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
comment|// X32: define x86_vectorcallcc void @"\01v4@@28"(i32 inreg %a, %struct.Large* byval align 4 %b, i32 inreg %c)
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
comment|// X32: define x86_vectorcallcc void @"\01hfa1@@40"(i32 inreg %a, %struct.HFA4 inreg %b.coerce, i32 inreg %c)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01hfa1@@48"(i32 %a, %struct.HFA4 inreg %b.coerce, i32 %c)
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
comment|// X32: define x86_vectorcallcc void @"\01hfa2@@72"(%struct.HFA4 inreg %a.coerce, %struct.HFA4* inreg %b, double %c)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01hfa2@@72"(%struct.HFA4 inreg %a.coerce, %struct.HFA4* %b, double %c)
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
comment|// X32: define x86_vectorcallcc void @"\01hfa3@@56"(double %a, double %b, double %c, double %d, double %e, %struct.HFA2* inreg %f)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01hfa3@@56"(double %a, double %b, double %c, double %d, double %e, %struct.HFA2* %f)
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
comment|// X32: define x86_vectorcallcc void @"\01hfa4@@40"(%struct.HFA5* byval align 4)
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
comment|// X32: define x86_vectorcallcc %struct.HFA2 @"\01hfa5@@0"()
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
name|HVA3
block|{
name|v4f32
name|w
decl_stmt|,
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

begin_struct
struct|struct
name|HVA5
block|{
name|v4f32
name|w
decl_stmt|,
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|,
name|p
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|v4f32
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
block|{
return|return
name|b
operator|.
name|w
return|;
block|}
end_function

begin_comment
comment|// X32: define x86_vectorcallcc<4 x float> @"\01hva1@@72"(i32 inreg %a, %struct.HVA4 inreg %b.coerce, i32 inreg %c)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc<4 x float> @"\01hva1@@80"(i32 %a, %struct.HVA4 inreg %b.coerce, i32 %c)
end_comment

begin_function
name|v4f32
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
block|{
return|return
name|c
return|;
block|}
end_function

begin_comment
comment|// X32: define x86_vectorcallcc<4 x float> @"\01hva2@@144"(%struct.HVA4 inreg %a.coerce, %struct.HVA4* inreg %b,<4 x float> %c)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc<4 x float> @"\01hva2@@144"(%struct.HVA4 inreg %a.coerce, %struct.HVA4* %b,<4 x float> %c)
end_comment

begin_function
name|v4f32
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
block|{
return|return
name|f
operator|.
name|x
return|;
block|}
end_function

begin_comment
comment|// X32: define x86_vectorcallcc<4 x float> @"\01hva3@@112"(<4 x float> %a,<4 x float> %b,<4 x float> %c,<4 x float> %d,<4 x float> %e, %struct.HVA2* inreg %f)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc<4 x float> @"\01hva3@@112"(<4 x float> %a,<4 x float> %b,<4 x float> %c,<4 x float> %d,<4 x float> %e, %struct.HVA2* %f)
end_comment

begin_comment
comment|// vector types have higher priority then HVA structures, So vector types are allocated first
end_comment

begin_comment
comment|// and HVAs are allocated if enough registers are available
end_comment

begin_function
name|v4f32
name|__vectorcall
name|hva4
parameter_list|(
name|struct
name|HVA4
name|a
parameter_list|,
name|struct
name|HVA2
name|b
parameter_list|,
name|v4f32
name|c
parameter_list|)
block|{
return|return
name|b
operator|.
name|y
return|;
block|}
end_function

begin_comment
comment|// X32: define x86_vectorcallcc<4 x float> @"\01hva4@@112"(%struct.HVA4 inreg %a.coerce, %struct.HVA2* inreg %b,<4 x float> %c)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc<4 x float> @"\01hva4@@112"(%struct.HVA4 inreg %a.coerce, %struct.HVA2* %b,<4 x float> %c)
end_comment

begin_function
name|v4f32
name|__vectorcall
name|hva5
parameter_list|(
name|struct
name|HVA3
name|a
parameter_list|,
name|struct
name|HVA3
name|b
parameter_list|,
name|v4f32
name|c
parameter_list|,
name|struct
name|HVA2
name|d
parameter_list|)
block|{
return|return
name|d
operator|.
name|y
return|;
block|}
end_function

begin_comment
comment|// X32: define x86_vectorcallcc<4 x float> @"\01hva5@@144"(%struct.HVA3 inreg %a.coerce, %struct.HVA3* inreg %b,<4 x float> %c, %struct.HVA2 inreg %d.coerce)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc<4 x float> @"\01hva5@@144"(%struct.HVA3 inreg %a.coerce, %struct.HVA3* %b,<4 x float> %c, %struct.HVA2 inreg %d.coerce)
end_comment

begin_function
name|struct
name|HVA4
name|__vectorcall
name|hva6
parameter_list|(
name|struct
name|HVA4
name|a
parameter_list|,
name|struct
name|HVA4
name|b
parameter_list|)
block|{
return|return
name|b
return|;
block|}
end_function

begin_comment
comment|// X32: define x86_vectorcallcc %struct.HVA4 @"\01hva6@@128"(%struct.HVA4 inreg %a.coerce, %struct.HVA4* inreg %b)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc %struct.HVA4 @"\01hva6@@128"(%struct.HVA4 inreg %a.coerce, %struct.HVA4* %b)
end_comment

begin_function
name|struct
name|HVA5
name|__vectorcall
name|hva7
parameter_list|()
block|{
name|struct
name|HVA5
name|a
init|=
block|{}
decl_stmt|;
return|return
name|a
return|;
block|}
end_function

begin_comment
comment|// X32: define x86_vectorcallcc void @"\01hva7@@0"(%struct.HVA5* inreg noalias sret %agg.result)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01hva7@@0"(%struct.HVA5* noalias sret %agg.result)
end_comment

begin_function
name|v4f32
name|__vectorcall
name|hva8
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
name|int
name|e
parameter_list|,
name|v4f32
name|f
parameter_list|)
block|{
return|return
name|f
return|;
block|}
end_function

begin_comment
comment|// X32: define x86_vectorcallcc<4 x float> @"\01hva8@@84"(<4 x float> %a,<4 x float> %b,<4 x float> %c,<4 x float> %d, i32 inreg %e,<4 x float> %f)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc<4 x float> @"\01hva8@@88"(<4 x float> %a,<4 x float> %b,<4 x float> %c,<4 x float> %d, i32 %e,<4 x float> %f)
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
comment|// X32: define x86_vectorcallcc void @"\01odd_size_hva@@32"(%struct.OddSizeHVA inreg %a.coerce)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01odd_size_hva@@32"(%struct.OddSizeHVA inreg %a.coerce)
end_comment

begin_comment
comment|// The Vectorcall ABI only allows passing the first 6 items in registers in x64, so this shouldn't
end_comment

begin_comment
comment|// consider 'p7' as a register.  Instead p5 gets put into the register on the second pass.
end_comment

begin_comment
comment|// x86 should pass p2, p6 and p7 in registers, then p1 in the second pass.
end_comment

begin_function
name|struct
name|HFA2
name|__vectorcall
name|AddParticles
parameter_list|(
name|struct
name|HFA2
name|p1
parameter_list|,
name|float
name|p2
parameter_list|,
name|struct
name|HFA4
name|p3
parameter_list|,
name|int
name|p4
parameter_list|,
name|struct
name|HFA2
name|p5
parameter_list|,
name|float
name|p6
parameter_list|,
name|float
name|p7
parameter_list|,
name|int
name|p8
parameter_list|)
block|{
return|return
name|p1
return|;
block|}
end_function

begin_comment
comment|// X32: define x86_vectorcallcc %struct.HFA2 @"\01AddParticles@@84"(%struct.HFA2 inreg %p1.coerce, float %p2, %struct.HFA4* inreg %p3, i32 inreg %p4, %struct.HFA2* %p5, float %p6, float %p7, i32 %p8)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc %struct.HFA2 @"\01AddParticles@@104"(%struct.HFA2 inreg %p1.coerce, float %p2, %struct.HFA4* %p3, i32 %p4, %struct.HFA2 inreg %p5.coerce, float %p6, float %p7, i32 %p8)
end_comment

begin_comment
comment|// Vectorcall in both architectures allows passing of an HVA as long as there is room,
end_comment

begin_comment
comment|// even if it is not one of the first 6 arguments.  First pass puts p4 into a
end_comment

begin_comment
comment|// register on both.  p9 ends up in a register in x86 only.  Second pass puts p1
end_comment

begin_comment
comment|// in a register, does NOT put p7 in a register (since theres no room), then puts
end_comment

begin_comment
comment|// p8 in a register.
end_comment

begin_function
name|void
name|__vectorcall
name|HVAAnywhere
parameter_list|(
name|struct
name|HFA2
name|p1
parameter_list|,
name|int
name|p2
parameter_list|,
name|int
name|p3
parameter_list|,
name|float
name|p4
parameter_list|,
name|int
name|p5
parameter_list|,
name|int
name|p6
parameter_list|,
name|struct
name|HFA4
name|p7
parameter_list|,
name|struct
name|HFA2
name|p8
parameter_list|,
name|float
name|p9
parameter_list|)
block|{}
end_function

begin_comment
comment|// X32: define x86_vectorcallcc void @"\01HVAAnywhere@@88"(%struct.HFA2 inreg %p1.coerce, i32 inreg %p2, i32 inreg %p3, float %p4, i32 %p5, i32 %p6, %struct.HFA4* %p7, %struct.HFA2 inreg %p8.coerce, float %p9)
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01HVAAnywhere@@112"(%struct.HFA2 inreg %p1.coerce, i32 %p2, i32 %p3, float %p4, i32 %p5, i32 %p6, %struct.HFA4* %p7, %struct.HFA2 inreg %p8.coerce, float %p9)
end_comment

end_unit

