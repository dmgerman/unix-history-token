begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple sparcv9-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|// CHECK-LABEL: define void @f_void()
end_comment

begin_function
name|void
name|f_void
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// Arguments and return values smaller than the word size are extended.
end_comment

begin_comment
comment|// CHECK-LABEL: define signext i32 @f_int_1(i32 signext %x)
end_comment

begin_function
name|int
name|f_int_1
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define zeroext i32 @f_int_2(i32 zeroext %x)
end_comment

begin_function
name|unsigned
name|f_int_2
parameter_list|(
name|unsigned
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @f_int_3(i64 %x)
end_comment

begin_function
name|long
name|long
name|f_int_3
parameter_list|(
name|long
name|long
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define signext i8 @f_int_4(i8 signext %x)
end_comment

begin_function
name|char
name|f_int_4
parameter_list|(
name|char
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define fp128 @f_ld(fp128 %x)
end_comment

begin_function
name|long
name|double
name|f_ld
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// Small structs are passed in registers.
end_comment

begin_struct
struct|struct
name|small
block|{
name|int
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: define %struct.small @f_small(i32* %x.coerce0, i32* %x.coerce1)
end_comment

begin_function
name|struct
name|small
name|f_small
parameter_list|(
name|struct
name|small
name|x
parameter_list|)
block|{
name|x
operator|.
name|a
operator|+=
operator|*
name|x
operator|.
name|b
expr_stmt|;
name|x
operator|.
name|b
operator|=
literal|0
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// Medium-sized structs are passed indirectly, but can be returned in registers.
end_comment

begin_struct
struct|struct
name|medium
block|{
name|int
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
name|int
modifier|*
name|c
decl_stmt|,
modifier|*
name|d
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: define %struct.medium @f_medium(%struct.medium* %x)
end_comment

begin_function
name|struct
name|medium
name|f_medium
parameter_list|(
name|struct
name|medium
name|x
parameter_list|)
block|{
name|x
operator|.
name|a
operator|+=
operator|*
name|x
operator|.
name|b
expr_stmt|;
name|x
operator|.
name|b
operator|=
literal|0
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// Large structs are also returned indirectly.
end_comment

begin_struct
struct|struct
name|large
block|{
name|int
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
name|int
modifier|*
name|c
decl_stmt|,
modifier|*
name|d
decl_stmt|;
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: define void @f_large(%struct.large* noalias sret %agg.result, %struct.large* %x)
end_comment

begin_function
name|struct
name|large
name|f_large
parameter_list|(
name|struct
name|large
name|x
parameter_list|)
block|{
name|x
operator|.
name|a
operator|+=
operator|*
name|x
operator|.
name|b
expr_stmt|;
name|x
operator|.
name|b
operator|=
literal|0
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// A 64-bit struct fits in a register.
end_comment

begin_struct
struct|struct
name|reg
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: define i64 @f_reg(i64 %x.coerce)
end_comment

begin_function
name|struct
name|reg
name|f_reg
parameter_list|(
name|struct
name|reg
name|x
parameter_list|)
block|{
name|x
operator|.
name|a
operator|+=
name|x
operator|.
name|b
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// Structs with mixed int and float parts require the inreg attribute.
end_comment

begin_struct
struct|struct
name|mixed
block|{
name|int
name|a
decl_stmt|;
name|float
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: define inreg %struct.mixed @f_mixed(i32 inreg %x.coerce0, float inreg %x.coerce1)
end_comment

begin_function
name|struct
name|mixed
name|f_mixed
parameter_list|(
name|struct
name|mixed
name|x
parameter_list|)
block|{
name|x
operator|.
name|a
operator|+=
literal|1
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// Struct with padding.
end_comment

begin_struct
struct|struct
name|mixed2
block|{
name|int
name|a
decl_stmt|;
name|double
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: define { i64, double } @f_mixed2(i64 %x.coerce0, double %x.coerce1)
end_comment

begin_comment
comment|// CHECK: store i64 %x.coerce0
end_comment

begin_comment
comment|// CHECK: store double %x.coerce1
end_comment

begin_function
name|struct
name|mixed2
name|f_mixed2
parameter_list|(
name|struct
name|mixed2
name|x
parameter_list|)
block|{
name|x
operator|.
name|a
operator|+=
literal|1
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// Struct with single element and padding in passed in the high bits of a
end_comment

begin_comment
comment|// register.
end_comment

begin_struct
struct|struct
name|tiny
block|{
name|char
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: define i64 @f_tiny(i64 %x.coerce)
end_comment

begin_comment
comment|// CHECK: %[[HB:[^ ]+]] = lshr i64 %x.coerce, 56
end_comment

begin_comment
comment|// CHECK: = trunc i64 %[[HB]] to i8
end_comment

begin_function
name|struct
name|tiny
name|f_tiny
parameter_list|(
name|struct
name|tiny
name|x
parameter_list|)
block|{
name|x
operator|.
name|a
operator|+=
literal|1
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @call_tiny()
end_comment

begin_comment
comment|// CHECK: %[[XV:[^ ]+]] = zext i8 %{{[^ ]+}} to i64
end_comment

begin_comment
comment|// CHECK: %[[HB:[^ ]+]] = shl i64 %[[XV]], 56
end_comment

begin_comment
comment|// CHECK: = call i64 @f_tiny(i64 %[[HB]])
end_comment

begin_function
name|void
name|call_tiny
parameter_list|()
block|{
name|struct
name|tiny
name|x
init|=
block|{
literal|1
block|}
decl_stmt|;
name|f_tiny
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define signext i32 @f_variable(i8* %f, ...)
end_comment

begin_comment
comment|// CHECK: %ap = alloca i8*
end_comment

begin_comment
comment|// CHECK: call void @llvm.va_start
end_comment

begin_comment
comment|//
end_comment

begin_function
name|int
name|f_variable
parameter_list|(
name|char
modifier|*
name|f
parameter_list|,
modifier|...
parameter_list|)
block|{
name|int
name|s
init|=
literal|0
decl_stmt|;
name|char
name|c
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|f
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|f
operator|++
operator|)
condition|)
switch|switch
condition|(
name|c
condition|)
block|{
comment|// CHECK: %[[CUR:[^ ]+]] = load i8** %ap
comment|// CHECK-DAG: %[[NXT:[^ ]+]] = getelementptr i8* %[[CUR]], i32 8
comment|// CHECK-DAG: store i8* %[[NXT]], i8** %ap
comment|// CHECK-DAG: %[[EXT:[^ ]+]] = getelementptr i8* %[[CUR]], i32 4
comment|// CHECK-DAG: %[[ADR:[^ ]+]] = bitcast i8* %[[EXT]] to i32*
comment|// CHECK-DAG: load i32* %[[ADR]]
comment|// CHECK: br
case|case
literal|'i'
case|:
name|s
operator|+=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|int
argument_list|)
expr_stmt|;
break|break;
comment|// CHECK: %[[CUR:[^ ]+]] = load i8** %ap
comment|// CHECK-DAG: %[[NXT:[^ ]+]] = getelementptr i8* %[[CUR]], i32 8
comment|// CHECK-DAG: store i8* %[[NXT]], i8** %ap
comment|// CHECK-DAG: %[[ADR:[^ ]+]] = bitcast i8* %[[CUR]] to i64*
comment|// CHECK-DAG: load i64* %[[ADR]]
comment|// CHECK: br
case|case
literal|'l'
case|:
name|s
operator|+=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|long
argument_list|)
expr_stmt|;
break|break;
comment|// CHECK: %[[CUR:[^ ]+]] = load i8** %ap
comment|// CHECK-DAG: %[[NXT:[^ ]+]] = getelementptr i8* %[[CUR]], i32 8
comment|// CHECK-DAG: store i8* %[[NXT]], i8** %ap
comment|// CHECK-DAG: %[[ADR:[^ ]+]] = bitcast i8* %[[CUR]] to %struct.tiny*
comment|// CHECK: br
case|case
literal|'t'
case|:
name|s
operator|+=
name|va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|tiny
argument_list|)
operator|.
name|a
expr_stmt|;
break|break;
comment|// CHECK: %[[CUR:[^ ]+]] = load i8** %ap
comment|// CHECK-DAG: %[[NXT:[^ ]+]] = getelementptr i8* %[[CUR]], i32 16
comment|// CHECK-DAG: store i8* %[[NXT]], i8** %ap
comment|// CHECK-DAG: %[[ADR:[^ ]+]] = bitcast i8* %[[CUR]] to %struct.small*
comment|// CHECK: br
case|case
literal|'s'
case|:
name|s
operator|+=
operator|*
name|va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|small
argument_list|)
operator|.
name|a
expr_stmt|;
break|break;
comment|// CHECK: %[[CUR:[^ ]+]] = load i8** %ap
comment|// CHECK-DAG: %[[NXT:[^ ]+]] = getelementptr i8* %[[CUR]], i32 8
comment|// CHECK-DAG: store i8* %[[NXT]], i8** %ap
comment|// CHECK-DAG: %[[IND:[^ ]+]] = bitcast i8* %[[CUR]] to %struct.medium**
comment|// CHECK-DAG: %[[ADR:[^ ]+]] = load %struct.medium** %[[IND]]
comment|// CHECK: br
case|case
literal|'m'
case|:
name|s
operator|+=
operator|*
name|va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|medium
argument_list|)
operator|.
name|a
expr_stmt|;
break|break;
block|}
return|return
name|s
return|;
block|}
end_function

end_unit

