begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-nacl -emit-llvm -o - %s| FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|// Test for x86-64 structure representation (instead of pnacl representation),
end_comment

begin_comment
comment|// in particular for unions. Also crib a few tests from x86 Linux.
end_comment

begin_union
union|union
name|PP_VarValue
block|{
name|int
name|as_int
decl_stmt|;
name|double
name|as_double
decl_stmt|;
name|long
name|long
name|as_i64
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|PP_Var
block|{
name|int
name|type
decl_stmt|;
name|int
name|padding
decl_stmt|;
name|union
name|PP_VarValue
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: define { i64, i64 } @f0()
end_comment

begin_function
name|struct
name|PP_Var
name|f0
parameter_list|()
block|{
name|struct
name|PP_Var
name|result
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
return|return
name|result
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f1(i64 %p1.coerce0, i64 %p1.coerce1)
end_comment

begin_function
name|void
name|f1
parameter_list|(
name|struct
name|PP_Var
name|p1
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_comment
comment|// long doubles are 64 bits on NaCl
end_comment

begin_comment
comment|// CHECK-LABEL: define double @f5()
end_comment

begin_function
name|long
name|double
name|f5
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f6(i8 signext %a0, i16 signext %a1, i32 %a2, i64 %a3, i8* %a4)
end_comment

begin_function
name|void
name|f6
parameter_list|(
name|char
name|a0
parameter_list|,
name|short
name|a1
parameter_list|,
name|int
name|a2
parameter_list|,
name|long
name|long
name|a3
parameter_list|,
name|void
modifier|*
name|a4
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @f8_1()
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f8_2(i64 %a0.coerce)
end_comment

begin_union
union|union
name|u8
block|{
name|long
name|double
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
union|;
end_union

begin_function
name|union
name|u8
name|f8_1
parameter_list|()
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_function
name|void
name|f8_2
parameter_list|(
name|union
name|u8
name|a0
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @f9()
end_comment

begin_struct
struct|struct
name|s9
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
block|}
name|f9
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// CHECK-LABEL: define void @f10(i64 %a0.coerce)
decl|struct
name|s10
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f10
parameter_list|(
name|struct
name|s10
name|a0
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define double @f11()
end_comment

begin_union
union|union
block|{
name|long
name|double
name|a
decl_stmt|;
name|float
name|b
decl_stmt|;
block|}
name|f11
argument_list|()
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// CHECK-LABEL: define i32 @f12_0()
comment|// CHECK-LABEL: define void @f12_1(i32 %a0.coerce)
decl|struct
name|s12
block|{
name|int
name|a
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
decl_stmt|;
block|}
union|;
end_union

begin_function
name|struct
name|s12
name|f12_0
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_function
name|void
name|f12_1
parameter_list|(
name|struct
name|s12
name|a0
parameter_list|)
block|{}
end_function

begin_comment
comment|// Check that sret parameter is accounted for when checking available integer
end_comment

begin_comment
comment|// registers.
end_comment

begin_comment
comment|// CHECK: define void @f13(%struct.s13_0* noalias sret %agg.result, i32 %a, i32 %b, i32 %c, i32 %d, {{.*}}* byval align 8 %e, i32 %f)
end_comment

begin_struct
struct|struct
name|s13_0
block|{
name|long
name|long
name|f0
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s13_1
block|{
name|long
name|long
name|f0
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s13_0
name|f13
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|d
parameter_list|,
name|struct
name|s13_1
name|e
parameter_list|,
name|int
name|f
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f20(%struct.s20* byval align 32 %x)
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(aligned(
literal|32
argument|))
argument_list|)
name|s20
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f20
parameter_list|(
name|struct
name|s20
name|x
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: declare void @func(i64)
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_str
block|{
union|union
block|{
name|long
name|double
name|a
decl_stmt|;
name|long
name|c
decl_stmt|;
block|}
union|;
block|}
name|str
typedef|;
end_typedef

begin_function_decl
name|void
name|func
parameter_list|(
name|str
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|str
name|ss
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f9122143
parameter_list|()
block|{
name|func
argument_list|(
name|ss
argument_list|)
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
name|s1
typedef|;
end_typedef

begin_comment
comment|// CHECK-LABEL: define i32 @f48(%struct.s1* byval %s)
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|pnaclcall
operator|)
argument_list|)
name|f48
argument_list|(
name|s1
name|s
argument_list|)
block|{
return|return
name|s
operator|.
name|a
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @f49(%struct.s1* noalias sret %agg.result)
end_comment

begin_decl_stmt
name|s1
name|__attribute__
argument_list|(
operator|(
name|pnaclcall
operator|)
argument_list|)
name|f49
argument_list|()
block|{
name|s1
name|s
decl_stmt|;
name|s
operator|.
name|a
operator|=
name|s
operator|.
name|b
operator|=
literal|1
expr_stmt|;
return|return
name|s
return|;
block|}
end_decl_stmt

begin_union
union|union
name|simple_union
block|{
name|int
name|a
decl_stmt|;
name|char
name|b
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|// Unions should be passed as byval structs
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f50(%union.simple_union* byval %s)
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|pnaclcall
operator|)
argument_list|)
name|f50
argument_list|(
expr|union
name|simple_union
name|s
argument_list|)
block|{}
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|b4
range|:
literal|4
decl_stmt|;
name|int
name|b3
range|:
literal|3
decl_stmt|;
name|int
name|b8
range|:
literal|8
decl_stmt|;
block|}
name|bitfield1
typedef|;
end_typedef

begin_comment
comment|// Bitfields should be passed as byval structs
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f51(%struct.bitfield1* byval %bf1)
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|pnaclcall
operator|)
argument_list|)
name|f51
argument_list|(
name|bitfield1
name|bf1
argument_list|)
block|{}
end_decl_stmt

end_unit

