begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7-unknown-nacl-gnueabi \
end_comment

begin_comment
comment|// RUN:   -ffreestanding -mfloat-abi hard -target-cpu cortex-a8 \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -w -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Test that functions with pnaclcall attribute generate portable bitcode
end_comment

begin_comment
comment|// like the le32 arch target
end_comment

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

