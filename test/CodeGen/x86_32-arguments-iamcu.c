begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -w -triple i386-pc-elfiamcu -mfloat-abi soft -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK-LABEL: define void @ints(i32 %a, i32 %b, i32 %c, i32 %d)
end_comment

begin_function
name|void
name|ints
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
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @floats(float %a, float %b, float %c, float %d)
end_comment

begin_function
name|void
name|floats
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|,
name|float
name|c
parameter_list|,
name|float
name|d
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @mixed(i32 %a, float %b, i32 %c, float %d)
end_comment

begin_function
name|void
name|mixed
parameter_list|(
name|int
name|a
parameter_list|,
name|float
name|b
parameter_list|,
name|int
name|c
parameter_list|,
name|float
name|d
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @doubles(double %d1, double %d2)
end_comment

begin_function
name|void
name|doubles
parameter_list|(
name|double
name|d1
parameter_list|,
name|double
name|d2
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @mixedDoubles(i32 %a, double %d1)
end_comment

begin_function
name|void
name|mixedDoubles
parameter_list|(
name|int
name|a
parameter_list|,
name|double
name|d1
parameter_list|)
block|{}
end_function

begin_typedef
typedef|typedef
struct|struct
name|st3_t
block|{
name|char
name|a
index|[
literal|3
index|]
decl_stmt|;
block|}
name|st3_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|st4_t
block|{
name|int
name|a
decl_stmt|;
block|}
name|st4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|st5_t
block|{
name|int
name|a
decl_stmt|;
name|char
name|b
decl_stmt|;
block|}
name|st5_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|st12_t
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
name|int
name|c
decl_stmt|;
block|}
name|st12_t
typedef|;
end_typedef

begin_comment
comment|// CHECK-LABEL: define void @smallStructs(i32 %st1.coerce, i32 %st2.coerce, i32 %st3.coerce)
end_comment

begin_function
name|void
name|smallStructs
parameter_list|(
name|st4_t
name|st1
parameter_list|,
name|st4_t
name|st2
parameter_list|,
name|st4_t
name|st3
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @paddedStruct(i32 %i1, i32 %st.coerce0, i32 %st.coerce1, i32 %st4.0)
end_comment

begin_function
name|void
name|paddedStruct
parameter_list|(
name|int
name|i1
parameter_list|,
name|st5_t
name|st
parameter_list|,
name|st4_t
name|st4
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @largeStructBegin(%struct.st12_t* byval align 4 %st)
end_comment

begin_function
name|void
name|largeStructBegin
parameter_list|(
name|st12_t
name|st
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @largeStructMiddle(i32 %i1, %struct.st12_t* byval align 4 %st, i32 %i2, i32 %i3)
end_comment

begin_function
name|void
name|largeStructMiddle
parameter_list|(
name|int
name|i1
parameter_list|,
name|st12_t
name|st
parameter_list|,
name|int
name|i2
parameter_list|,
name|int
name|i3
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @largeStructEnd(i32 %i1, i32 %i2, i32 %i3, i32 %st.0, i32 %st.1, i32 %st.2)
end_comment

begin_function
name|void
name|largeStructEnd
parameter_list|(
name|int
name|i1
parameter_list|,
name|int
name|i2
parameter_list|,
name|int
name|i3
parameter_list|,
name|st12_t
name|st
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define i24 @retNonPow2Struct(i32 %r.coerce)
end_comment

begin_function
name|st3_t
name|retNonPow2Struct
parameter_list|(
name|st3_t
name|r
parameter_list|)
block|{
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @retSmallStruct(i32 %r.coerce)
end_comment

begin_function
name|st4_t
name|retSmallStruct
parameter_list|(
name|st4_t
name|r
parameter_list|)
block|{
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @retPaddedStruct(i32 %r.coerce0, i32 %r.coerce1)
end_comment

begin_function
name|st5_t
name|retPaddedStruct
parameter_list|(
name|st5_t
name|r
parameter_list|)
block|{
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @retLargeStruct(%struct.st12_t* noalias sret %agg.result, i32 %i1, %struct.st12_t* byval align 4 %r)
end_comment

begin_function
name|st12_t
name|retLargeStruct
parameter_list|(
name|int
name|i1
parameter_list|,
name|st12_t
name|r
parameter_list|)
block|{
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @varArgs(i32 %i1, ...)
end_comment

begin_function
name|int
name|varArgs
parameter_list|(
name|int
name|i1
parameter_list|,
modifier|...
parameter_list|)
block|{
return|return
name|i1
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define double @longDoubleArg(double %ld1)
end_comment

begin_function
name|long
name|double
name|longDoubleArg
parameter_list|(
name|long
name|double
name|ld1
parameter_list|)
block|{
return|return
name|ld1
return|;
block|}
end_function

end_unit

