begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple armv7-apple-darwin9 -target-abi apcs-gnu -emit-llvm -w -o - %s | FileCheck -check-prefix=APCS-GNU %s
end_comment

begin_comment
comment|// RUN: clang-cc -triple armv7-apple-darwin9 -target-abi aapcs -emit-llvm -w -o - %s | FileCheck -check-prefix=AAPCS %s
end_comment

begin_comment
comment|// APCS-GNU: define arm_apcscc signext i8 @f0()
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc signext i8 @f0()
end_comment

begin_function
name|char
name|f0
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
comment|// APCS-GNU: define arm_apcscc i8 @f1()
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc i8 @f1()
end_comment

begin_struct
struct|struct
name|s1
block|{
name|char
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s1
name|f1
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// APCS-GNU: define arm_apcscc i16 @f2()
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc i16 @f2()
end_comment

begin_struct
struct|struct
name|s2
block|{
name|short
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s2
name|f2
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// APCS-GNU: define arm_apcscc i32 @f3()
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc i32 @f3()
end_comment

begin_struct
struct|struct
name|s3
block|{
name|int
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s3
name|f3
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// APCS-GNU: define arm_apcscc i32 @f4()
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc i32 @f4()
end_comment

begin_struct
struct|struct
name|s4
block|{
struct|struct
name|s4_0
block|{
name|int
name|f0
decl_stmt|;
block|}
name|f0
struct|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s4
name|f4
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// APCS-GNU: define arm_apcscc void @f5(
end_comment

begin_comment
comment|// APCS-GNU: struct.s5* noalias sret
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc i32 @f5()
end_comment

begin_struct
struct|struct
name|s5
block|{
struct|struct
block|{ }
name|f0
struct|;
name|int
name|f1
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s5
name|f5
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// APCS-GNU: define arm_apcscc void @f6(
end_comment

begin_comment
comment|// APCS-GNU: struct.s6* noalias sret
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc i32 @f6()
end_comment

begin_struct
struct|struct
name|s6
block|{
name|int
name|f0
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s6
name|f6
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// APCS-GNU: define arm_apcscc void @f7()
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc void @f7()
end_comment

begin_struct
struct|struct
name|s7
block|{
struct|struct
block|{
name|int
label|:
literal|0
expr_stmt|;
block|}
name|f0
struct|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s7
name|f7
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// APCS-GNU: define arm_apcscc void @f8(
end_comment

begin_comment
comment|// APCS-GNU: struct.s8* noalias sret
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc void @f8()
end_comment

begin_struct
struct|struct
name|s8
block|{
struct|struct
block|{
name|int
label|:
literal|0
expr_stmt|;
block|}
name|f0
index|[
literal|1
index|]
struct|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s8
name|f8
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// APCS-GNU: define arm_apcscc i32 @f9()
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc i32 @f9()
end_comment

begin_struct
struct|struct
name|s9
block|{
name|int
name|f0
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s9
name|f9
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// APCS-GNU: define arm_apcscc i32 @f10()
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc i32 @f10()
end_comment

begin_struct
struct|struct
name|s10
block|{
name|int
name|f0
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|int
label|:
literal|0
expr_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s10
name|f10
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// APCS-GNU: define arm_apcscc void @f11(
end_comment

begin_comment
comment|// APCS-GNU: struct.s10* noalias sret
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc i32 @f11()
end_comment

begin_struct
struct|struct
name|s11
block|{
name|int
label|:
literal|0
expr_stmt|;
name|int
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s11
name|f11
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// APCS-GNU: define arm_apcscc i32 @f12()
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc i32 @f12()
end_comment

begin_union
union|union
name|u12
block|{
name|char
name|f0
decl_stmt|;
name|short
name|f1
decl_stmt|;
name|int
name|f2
decl_stmt|;
block|}
union|;
end_union

begin_function
name|union
name|u12
name|f12
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// APCS-GNU: define arm_apcscc void @f13(
end_comment

begin_comment
comment|// APCS-GNU: struct.s13* noalias sret
end_comment

begin_comment
comment|// FIXME: This should return a float.
end_comment

begin_comment
comment|// AAPCS-FIXME: define arm_aapcscc float @f13()
end_comment

begin_struct
struct|struct
name|s13
block|{
name|float
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s13
name|f13
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// APCS-GNU: define arm_apcscc void @f14(
end_comment

begin_comment
comment|// APCS-GNU: struct.s13* noalias sret
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc i32 @f14()
end_comment

begin_union
union|union
name|u14
block|{
name|float
name|f0
decl_stmt|;
block|}
union|;
end_union

begin_function
name|union
name|u14
name|f14
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// APCS-GNU: define arm_apcscc void @f15()
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc void @f15()
end_comment

begin_function
name|void
name|f15
parameter_list|(
name|struct
name|s7
name|a0
parameter_list|)
block|{}
end_function

begin_comment
comment|// APCS-GNU: define arm_apcscc void @f16()
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc void @f16()
end_comment

begin_function
name|void
name|f16
parameter_list|(
name|struct
name|s8
name|a0
parameter_list|)
block|{}
end_function

end_unit

