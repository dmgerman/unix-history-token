begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_struct
struct|struct
name|x
block|{
name|long
name|a
decl_stmt|;
name|double
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|testva
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|struct
name|x
name|t
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|x
argument_list|)
decl_stmt|;
comment|// CHECK: bitcast i8* %{{[a-z.0-9]*}} to %struct.x*
comment|// CHECK: bitcast %struct.x* %t to i8*
comment|// CHECK: bitcast %struct.x* %{{[0-9]+}} to i8*
comment|// CHECK: call void @llvm.memcpy
name|int
name|v
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|int
argument_list|)
decl_stmt|;
comment|// CHECK: ptrtoint i8* %{{[a-z.0-9]*}} to i64
comment|// CHECK: add i64 %{{[0-9]+}}, 4
comment|// CHECK: inttoptr i64 %{{[0-9]+}} to i8*
comment|// CHECK: bitcast i8* %{{[0-9]+}} to i32*
name|__int128_t
name|u
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__int128_t
argument_list|)
decl_stmt|;
comment|// CHECK: bitcast i8* %{{[a-z.0-9]+}} to i128*
comment|// CHECK-NEXT: load i128* %{{[0-9]+}}
block|}
end_function

end_unit

