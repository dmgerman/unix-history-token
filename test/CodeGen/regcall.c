begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -ffreestanding -triple=i386-pc-win32       | FileCheck %s --check-prefix=Win32
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -ffreestanding -triple=x86_64-pc-win32     | FileCheck %s --check-prefix=Win64
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -ffreestanding -triple=i386-pc-linux-gnu   | FileCheck %s --check-prefix=Lin32
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -ffreestanding -triple=x86_64-pc-linux-gnu | FileCheck %s --check-prefix=Lin64
end_comment

begin_include
include|#
directive|include
file|<xmmintrin.h>
end_include

begin_function
name|void
name|__regcall
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
comment|// Win32: define x86_regcallcc void @__regcall3__v1(i32 inreg %a, i32 inreg %b)
end_comment

begin_comment
comment|// Win64: define x86_regcallcc void @__regcall3__v1(i32 %a, i32 %b)
end_comment

begin_comment
comment|// Lin32: define x86_regcallcc void @__regcall3__v1(i32 inreg %a, i32 inreg %b)
end_comment

begin_comment
comment|// Lin64: define x86_regcallcc void @__regcall3__v1(i32 %a, i32 %b)
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|regcall
operator|)
argument_list|)
name|v1b
argument_list|(
name|int
name|a
argument_list|,
name|int
name|b
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|// Win32: define x86_regcallcc void @__regcall3__v1b(i32 inreg %a, i32 inreg %b)
end_comment

begin_comment
comment|// Win64: define x86_regcallcc void @__regcall3__v1b(i32 %a, i32 %b)
end_comment

begin_comment
comment|// Lin32: define x86_regcallcc void @__regcall3__v1b(i32 inreg %a, i32 inreg %b)
end_comment

begin_comment
comment|// Lin64: define x86_regcallcc void @__regcall3__v1b(i32 %a, i32 %b)
end_comment

begin_function
name|void
name|__regcall
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
comment|// Win32: define x86_regcallcc void @__regcall3__v2(i8 inreg signext %a, i8 inreg signext %b)
end_comment

begin_comment
comment|// Win64: define x86_regcallcc void @__regcall3__v2(i8 %a, i8 %b)
end_comment

begin_comment
comment|// Lin32: define x86_regcallcc void @__regcall3__v2(i8 inreg signext %a, i8 inreg signext %b)
end_comment

begin_comment
comment|// Lin64: define x86_regcallcc void @__regcall3__v2(i8 signext %a, i8 signext %b)
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
name|__regcall
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
comment|// Win32: define x86_regcallcc void @__regcall3__v3(i32 inreg %a, i32 %b.0, i32 inreg %c)
end_comment

begin_comment
comment|// Win64: define x86_regcallcc void @__regcall3__v3(i32 %a, i32 %b.coerce, i32 %c)
end_comment

begin_comment
comment|// Lin32: define x86_regcallcc void @__regcall3__v3(i32 inreg %a, i32 inreg, i32 %b.0, i32 inreg %c)
end_comment

begin_comment
comment|// Lin64: define x86_regcallcc void @__regcall3__v3(i32 %a, i32 %b.coerce, i32 %c)
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
name|__regcall
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
comment|// Win32: define x86_regcallcc void @__regcall3__v4(i32 inreg %a, %struct.Large* byval align 4 %b, i32 inreg %c)
end_comment

begin_comment
comment|// Win64: define x86_regcallcc void @__regcall3__v4(i32 %a, %struct.Large* %b, i32 %c)
end_comment

begin_comment
comment|// Lin32: define x86_regcallcc void @__regcall3__v4(i32 inreg %a, %struct.Large* byval align 4 %b, i32 %c)
end_comment

begin_comment
comment|// Lin64: define x86_regcallcc void @__regcall3__v4(i32 %a, [5 x i32] %b.coerce, i32 %c)
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
name|__regcall
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
comment|// Win32: define x86_regcallcc void @__regcall3__hfa1(i32 inreg %a, double %b.0, double %b.1, double %b.2, double %b.3, i32 inreg %c)
end_comment

begin_comment
comment|// Win64: define x86_regcallcc void @__regcall3__hfa1(i32 %a, double %b.0, double %b.1, double %b.2, double %b.3, i32 %c)
end_comment

begin_comment
comment|// Lin32: define x86_regcallcc void @__regcall3__hfa1(i32 inreg %a, double %b.0, double %b.1, double %b.2, double %b.3, i32 inreg %c)
end_comment

begin_comment
comment|// Lin64: define x86_regcallcc void @__regcall3__hfa1(i32 %a, double %b.coerce0, double %b.coerce1, double %b.coerce2, double %b.coerce3, i32 %c)
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
name|__regcall
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
comment|// Win32: define x86_regcallcc void @__regcall3__hfa2(double %a.0, double %a.1, double %a.2, double %a.3, double %b.0, double %b.1, double %b.2, double %b.3, double* inreg)
end_comment

begin_comment
comment|// Win64: define x86_regcallcc void @__regcall3__hfa2(double %a.0, double %a.1, double %a.2, double %a.3, double %b.0, double %b.1, double %b.2, double %b.3, double %c)
end_comment

begin_comment
comment|// Lin32: define x86_regcallcc void @__regcall3__hfa2(double %a.0, double %a.1, double %a.2, double %a.3, double %b.0, double %b.1, double %b.2, double %b.3, double* inreg)
end_comment

begin_comment
comment|// Lin64: define x86_regcallcc void @__regcall3__hfa2(double %a.coerce0, double %a.coerce1, double %a.coerce2, double %a.coerce3, double %b.coerce0, double %b.coerce1, double %b.coerce2, double %b.coerce3, double %c)
end_comment

begin_comment
comment|// Ensure that we pass builtin types directly while counting them against the
end_comment

begin_comment
comment|// SSE register usage.
end_comment

begin_function
name|void
name|__regcall
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
comment|// Win32: define x86_regcallcc void @__regcall3__hfa3(double %a, double %b, double %c, double %d, double %e, double %f.0, double %f.1)
end_comment

begin_comment
comment|// Win64: define x86_regcallcc void @__regcall3__hfa3(double %a, double %b, double %c, double %d, double %e, double %f.0, double %f.1)
end_comment

begin_comment
comment|// Lin32: define x86_regcallcc void @__regcall3__hfa3(double %a, double %b, double %c, double %d, double %e, double %f.0, double %f.1)
end_comment

begin_comment
comment|// Lin64: define x86_regcallcc void @__regcall3__hfa3(double %a, double %b, double %c, double %d, double %e, double %f.coerce0, double %f.coerce1)
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
name|__regcall
name|hfa4
parameter_list|(
name|struct
name|HFA5
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// Win32: define x86_regcallcc void @__regcall3__hfa4(%struct.HFA5* byval align 4)
end_comment

begin_comment
comment|// Win64: define x86_regcallcc void @__regcall3__hfa4(%struct.HFA5* %a)
end_comment

begin_comment
comment|// Lin32: define x86_regcallcc void @__regcall3__hfa4(%struct.HFA5* byval align 4 %a)
end_comment

begin_comment
comment|// Lin64: define x86_regcallcc void @__regcall3__hfa4(double %a.coerce0, double %a.coerce1, double %a.coerce2, double %a.coerce3, double %a.coerce4)
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
name|__regcall
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
comment|// Win32: define x86_regcallcc %struct.HFA2 @__regcall3__hfa5()
end_comment

begin_comment
comment|// Win64: define x86_regcallcc %struct.HFA2 @__regcall3__hfa5()
end_comment

begin_comment
comment|// Lin32: define x86_regcallcc %struct.HFA2 @__regcall3__hfa5()
end_comment

begin_comment
comment|// Lin64: define x86_regcallcc %struct.HFA2 @__regcall3__hfa5()
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
name|__regcall
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
comment|// Win32: define x86_regcallcc void @__regcall3__hva1(i32 inreg %a,<4 x float> %b.0,<4 x float> %b.1,<4 x float> %b.2,<4 x float> %b.3, i32 inreg %c)
end_comment

begin_comment
comment|// Win64: define x86_regcallcc void @__regcall3__hva1(i32 %a,<4 x float> %b.0,<4 x float> %b.1,<4 x float> %b.2,<4 x float> %b.3, i32 %c)
end_comment

begin_comment
comment|// Lin32: define x86_regcallcc void @__regcall3__hva1(i32 inreg %a,<4 x float> %b.0,<4 x float> %b.1,<4 x float> %b.2,<4 x float> %b.3, i32 inreg %c)
end_comment

begin_comment
comment|// Lin64: define x86_regcallcc void @__regcall3__hva1(i32 %a,<4 x float> %b.coerce0,<4 x float> %b.coerce1,<4 x float> %b.coerce2,<4 x float> %b.coerce3, i32 %c)
end_comment

begin_function
name|void
name|__regcall
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
comment|// Win32: define x86_regcallcc void @__regcall3__hva2(<4 x float> %a.0,<4 x float> %a.1,<4 x float> %a.2,<4 x float> %a.3,<4 x float> %b.0,<4 x float> %b.1,<4 x float> %b.2,<4 x float> %b.3,<4 x float>* inreg)
end_comment

begin_comment
comment|// Win64: define x86_regcallcc void @__regcall3__hva2(<4 x float> %a.0,<4 x float> %a.1,<4 x float> %a.2,<4 x float> %a.3,<4 x float> %b.0,<4 x float> %b.1,<4 x float> %b.2,<4 x float> %b.3,<4 x float> %c)
end_comment

begin_comment
comment|// Lin32: define x86_regcallcc void @__regcall3__hva2(<4 x float> %a.0,<4 x float> %a.1,<4 x float> %a.2,<4 x float> %a.3,<4 x float> %b.0,<4 x float> %b.1,<4 x float> %b.2,<4 x float> %b.3,<4 x float>* inreg)
end_comment

begin_comment
comment|// Lin64: define x86_regcallcc void @__regcall3__hva2(<4 x float> %a.coerce0,<4 x float> %a.coerce1,<4 x float> %a.coerce2,<4 x float> %a.coerce3,<4 x float> %b.coerce0,<4 x float> %b.coerce1,<4 x float> %b.coerce2,<4 x float> %b.coerce3,<4 x float> %c)
end_comment

begin_function
name|void
name|__regcall
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
comment|// Win32: define x86_regcallcc void @__regcall3__hva3(<4 x float> %a,<4 x float> %b,<4 x float> %c,<4 x float> %d,<4 x float> %e,<4 x float> %f.0,<4 x float> %f.1)
end_comment

begin_comment
comment|// Win64: define x86_regcallcc void @__regcall3__hva3(<4 x float> %a,<4 x float> %b,<4 x float> %c,<4 x float> %d,<4 x float> %e,<4 x float> %f.0,<4 x float> %f.1)
end_comment

begin_comment
comment|// Lin32: define x86_regcallcc void @__regcall3__hva3(<4 x float> %a,<4 x float> %b,<4 x float> %c,<4 x float> %d,<4 x float> %e,<4 x float> %f.0,<4 x float> %f.1)
end_comment

begin_comment
comment|// Lin64: define x86_regcallcc void @__regcall3__hva3(<4 x float> %a,<4 x float> %b,<4 x float> %c,<4 x float> %d,<4 x float> %e,<4 x float> %f.coerce0,<4 x float> %f.coerce1)
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
name|__regcall
name|odd_size_hva
parameter_list|(
name|struct
name|OddSizeHVA
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// Win32: define x86_regcallcc void @__regcall3__odd_size_hva(<3 x float> %a.0,<3 x float> %a.1)
end_comment

begin_comment
comment|// Win64: define x86_regcallcc void @__regcall3__odd_size_hva(<3 x float> %a.0,<3 x float> %a.1)
end_comment

begin_comment
comment|// Lin32: define x86_regcallcc void @__regcall3__odd_size_hva(<3 x float> %a.0,<3 x float> %a.1)
end_comment

begin_comment
comment|// Lin64: define x86_regcallcc void @__regcall3__odd_size_hva(<3 x float> %a.coerce0,<3 x float> %a.coerce1)
end_comment

begin_struct
struct|struct
name|HFA6
block|{
name|__m128
name|f
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|HFA6
name|__regcall
name|ret_reg_reused
parameter_list|(
name|struct
name|HFA6
name|a
parameter_list|,
name|struct
name|HFA6
name|b
parameter_list|,
name|struct
name|HFA6
name|c
parameter_list|,
name|struct
name|HFA6
name|d
parameter_list|)
block|{
name|struct
name|HFA6
name|h
decl_stmt|;
return|return
name|h
return|;
block|}
end_function

begin_comment
comment|// Win32: define x86_regcallcc %struct.HFA6 @__regcall3__ret_reg_reused(<4 x float> %a.0,<4 x float> %a.1,<4 x float> %a.2,<4 x float> %a.3,<4 x float> %b.0,<4 x float> %b.1,<4 x float> %b.2,<4 x float> %b.3, %struct.HFA6* inreg %c, %struct.HFA6* inreg %d)
end_comment

begin_comment
comment|// Win64: define x86_regcallcc %struct.HFA6 @__regcall3__ret_reg_reused(<4 x float> %a.0,<4 x float> %a.1,<4 x float> %a.2,<4 x float> %a.3,<4 x float> %b.0,<4 x float> %b.1,<4 x float> %b.2,<4 x float> %b.3,<4 x float> %c.0,<4 x float> %c.1,<4 x float> %c.2,<4 x float> %c.3,<4 x float> %d.0,<4 x float> %d.1,<4 x float> %d.2,<4 x float> %d.3)
end_comment

begin_comment
comment|// Lin32: define x86_regcallcc %struct.HFA6 @__regcall3__ret_reg_reused(<4 x float> %a.0,<4 x float> %a.1,<4 x float> %a.2,<4 x float> %a.3,<4 x float> %b.0,<4 x float> %b.1,<4 x float> %b.2,<4 x float> %b.3, %struct.HFA6* inreg %c, %struct.HFA6* inreg %d)
end_comment

begin_comment
comment|// Lin64: define x86_regcallcc %struct.HFA6 @__regcall3__ret_reg_reused([4 x<4 x float>] %a.coerce, [4 x<4 x float>] %b.coerce, [4 x<4 x float>] %c.coerce, [4 x<4 x float>] %d.coerce)
end_comment

end_unit

