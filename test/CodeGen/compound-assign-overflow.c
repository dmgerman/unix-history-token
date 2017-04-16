begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Verify proper type emitted for compound assignments
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -triple x86_64-apple-darwin10 -emit-llvm -o - %s  -fsanitize=signed-integer-overflow,unsigned-integer-overflow -fsanitize-recover=signed-integer-overflow,unsigned-integer-overflow | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// CHECK: @[[INT:.*]] = private unnamed_addr constant { i16, i16, [6 x i8] } { i16 0, i16 11, [6 x i8] c"'int'\00" }
end_comment

begin_comment
comment|// CHECK: @[[LINE_100:.*]] = private unnamed_addr global {{.*}}, i32 100, i32 5 {{.*}} @[[INT]]
end_comment

begin_comment
comment|// CHECK: @[[UINT:.*]] = private unnamed_addr constant { i16, i16, [15 x i8] } { i16 0, i16 10, [15 x i8] c"'unsigned int'\00" }
end_comment

begin_comment
comment|// CHECK: @[[LINE_200:.*]] = private unnamed_addr global {{.*}}, i32 200, i32 5 {{.*}} @[[UINT]]
end_comment

begin_comment
comment|// CHECK: @[[LINE_300:.*]] = private unnamed_addr global {{.*}}, i32 300, i32 5 {{.*}} @[[INT]]
end_comment

begin_decl_stmt
name|int32_t
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @compaddsigned
end_comment

begin_function
name|void
name|compaddsigned
parameter_list|()
block|{
line|#
directive|line
number|100
name|x
operator|+=
operator|(
operator|(
name|int32_t
operator|)
literal|1
operator|)
expr_stmt|;
comment|// CHECK: @__ubsan_handle_add_overflow(i8* bitcast ({{.*}} @[[LINE_100]] to i8*), {{.*}})
block|}
end_function

begin_comment
comment|// CHECK: @compaddunsigned
end_comment

begin_function
name|void
name|compaddunsigned
parameter_list|()
block|{
line|#
directive|line
number|200
name|x
operator|+=
operator|(
operator|(
name|uint32_t
operator|)
literal|1U
operator|)
expr_stmt|;
comment|// CHECK: @__ubsan_handle_add_overflow(i8* bitcast ({{.*}} @[[LINE_200]] to i8*), {{.*}})
block|}
end_function

begin_comment
comment|// CHECK: @compdiv
end_comment

begin_function
name|void
name|compdiv
parameter_list|()
block|{
line|#
directive|line
number|300
name|x
operator|/=
name|x
expr_stmt|;
comment|// CHECK: @__ubsan_handle_divrem_overflow(i8* bitcast ({{.*}} @[[LINE_300]] to i8*), {{.*}})
block|}
end_function

end_unit

