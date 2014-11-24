begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple le32-unknown-nacl -emit-llvm -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

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

begin_comment
comment|// CHECK: define i32 @get_int
end_comment

begin_comment
comment|// CHECK: [[RESULT:%[a-z_0-9]+]] = va_arg {{.*}}, i32{{$}}
end_comment

begin_comment
comment|// CHECK: ret i32 [[RESULT]]
end_comment

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

begin_comment
comment|// CHECK: define void @get_struct
end_comment

begin_comment
comment|// CHECK: [[RESULT:%[a-z_0-9]+]] = va_arg {{.*}}, %struct.Foo{{$}}
end_comment

begin_comment
comment|// CHECK: store %struct.Foo [[RESULT]], %struct.Foo* @dest
end_comment

begin_function
name|void
name|skip_struct
parameter_list|(
name|va_list
modifier|*
name|args
parameter_list|)
block|{
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

begin_comment
comment|// CHECK: define void @skip_struct
end_comment

begin_comment
comment|// CHECK: va_arg {{.*}}, %struct.Foo{{$}}
end_comment

end_unit

