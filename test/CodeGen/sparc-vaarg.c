begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple sparc -emit-llvm -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|// CHECK-LABEL: define i32 @get_int
end_comment

begin_comment
comment|// CHECK: [[RESULT:%[a-z_0-9]+]] = va_arg {{.*}}, i32{{$}}
end_comment

begin_comment
comment|// CHECK: store i32 [[RESULT]], i32* [[LOC:%[a-z_0-9]+]]
end_comment

begin_comment
comment|// CHECK: [[RESULT2:%[a-z_0-9]+]] = load i32, i32* [[LOC]]
end_comment

begin_comment
comment|// CHECK: ret i32 [[RESULT2]]
end_comment

begin_function
name|int
name|get_int
parameter_list|(
name|va_list
modifier|*
name|args
parameter_list|)
block|{
return|return
name|va_arg
argument_list|(
operator|*
name|args
argument_list|,
name|int
argument_list|)
return|;
block|}
end_function

begin_struct
struct|struct
name|Foo
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|Foo
name|dest
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @get_struct
end_comment

begin_comment
comment|// CHECK: [[RESULT:%[a-z_0-9]+]] = va_arg {{.*}}, %struct.Foo*{{$}}
end_comment

begin_comment
comment|// CHECK: [[RESULT2:%[a-z_0-9]+]] = bitcast {{.*}} [[RESULT]] to i8*
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy{{.*}}@dest{{.*}}, i8* [[RESULT2]]
end_comment

begin_function
name|void
name|get_struct
parameter_list|(
name|va_list
modifier|*
name|args
parameter_list|)
block|{
name|dest
operator|=
name|va_arg
argument_list|(
operator|*
name|args
argument_list|,
expr|struct
name|Foo
argument_list|)
expr_stmt|;
block|}
end_function

begin_enum
enum|enum
name|E
block|{
name|Foo_one
init|=
literal|1
block|}
enum|;
end_enum

begin_decl_stmt
name|enum
name|E
name|enum_dest
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @get_enum
end_comment

begin_comment
comment|// CHECK: va_arg i8** {{.*}}, i32
end_comment

begin_function
name|void
name|get_enum
parameter_list|(
name|va_list
modifier|*
name|args
parameter_list|)
block|{
name|enum_dest
operator|=
name|va_arg
argument_list|(
operator|*
name|args
argument_list|,
expr|enum
name|E
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

