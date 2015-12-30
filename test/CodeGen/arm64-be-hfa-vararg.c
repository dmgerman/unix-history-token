begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN:  %clang_cc1 -triple aarch64_be-linux-gnu -ffreestanding -emit-llvm -O0 -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|// A single member HFA must be aligned just like a non-HFA register argument.
end_comment

begin_function
name|double
name|callee
parameter_list|(
name|int
name|a
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK: [[REGPP:%.*]] = getelementptr inbounds %struct.__va_list, %struct.__va_list* [[VA:%.*]], i32 0, i32 2
comment|// CHECK: [[REGP:%.*]] = load i8*, i8** [[REGPP]], align 8
comment|// CHECK: [[OFFSET0:%.*]] = getelementptr inbounds i8, i8* [[REGP]], i32 {{.*}}
comment|// CHECK: [[OFFSET1:%.*]] = getelementptr inbounds i8, i8* [[OFFSET0]], i64 8
comment|// CHECK: [[MEMPP:%.*]] = getelementptr inbounds %struct.__va_list, %struct.__va_list* [[VA:%.*]], i32 0, i32 0
comment|// CHECK: [[MEMP:%.*]] = load i8*, i8** [[MEMPP]], align 8
comment|// CHECK: [[NEXTP:%.*]] = getelementptr inbounds i8, i8* [[MEMP]], i64 8
comment|// CHECK: store i8* [[NEXTP]], i8** [[MEMPP]], align 8
name|va_list
name|vl
decl_stmt|;
name|va_start
argument_list|(
name|vl
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|double
name|result
init|=
name|va_arg
argument_list|(
argument|vl
argument_list|,
argument|struct { double a; }
argument_list|)
operator|.
name|a
decl_stmt|;
name|va_end
argument_list|(
name|vl
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

end_unit

