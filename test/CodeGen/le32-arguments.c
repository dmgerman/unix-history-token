begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple le32-unknown-nacl %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Basic argument/attribute tests for le32/PNaCl
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f0(i32 %i, i32 %j, double %k)
end_comment

begin_function
name|void
name|f0
parameter_list|(
name|int
name|i
parameter_list|,
name|long
name|j
parameter_list|,
name|double
name|k
parameter_list|)
block|{}
end_function

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|aa
decl_stmt|;
name|int
name|bb
decl_stmt|;
block|}
name|s1
typedef|;
end_typedef

begin_comment
comment|// Structs should be passed byval and not split up
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f1(%struct.s1* byval %i)
end_comment

begin_function
name|void
name|f1
parameter_list|(
name|s1
name|i
parameter_list|)
block|{}
end_function

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|cc
decl_stmt|;
block|}
name|s2
typedef|;
end_typedef

begin_comment
comment|// Structs should be returned sret and not simplified by the frontend
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f2(%struct.s2* noalias sret %agg.result)
end_comment

begin_function
name|s2
name|f2
parameter_list|()
block|{
name|s2
name|foo
decl_stmt|;
return|return
name|foo
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f3(i64 %i)
end_comment

begin_function
name|void
name|f3
parameter_list|(
name|long
name|long
name|i
parameter_list|)
block|{}
end_function

begin_comment
comment|// i8/i16 should be signext, i32 and higher should not
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f4(i8 signext %a, i16 signext %b)
end_comment

begin_function
name|void
name|f4
parameter_list|(
name|char
name|a
parameter_list|,
name|short
name|b
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f5(i8 zeroext %a, i16 zeroext %b)
end_comment

begin_function
name|void
name|f5
parameter_list|(
name|unsigned
name|char
name|a
parameter_list|,
name|unsigned
name|short
name|b
parameter_list|)
block|{}
end_function

begin_enum
enum|enum
name|my_enum
block|{
name|ENUM1
block|,
name|ENUM2
block|,
name|ENUM3
block|, }
enum|;
end_enum

begin_comment
comment|// Enums should be treated as the underlying i32
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f6(i32 %a)
end_comment

begin_function
name|void
name|f6
parameter_list|(
name|enum
name|my_enum
name|a
parameter_list|)
block|{}
end_function

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
comment|// CHECK-LABEL: define void @f7(%union.simple_union* byval %s)
end_comment

begin_function
name|void
name|f7
parameter_list|(
name|union
name|simple_union
name|s
parameter_list|)
block|{}
end_function

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
comment|// CHECK-LABEL: define void @f8(%struct.bitfield1* byval %bf1)
end_comment

begin_function
name|void
name|f8
parameter_list|(
name|bitfield1
name|bf1
parameter_list|)
block|{}
end_function

end_unit

