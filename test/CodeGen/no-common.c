begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | FileCheck %s -check-prefix=CHECK-DEFAULT
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -fno-common -emit-llvm -o - | FileCheck %s -check-prefix=CHECK-NOCOMMON
end_comment

begin_comment
comment|// CHECK-DEFAULT: @x = common global
end_comment

begin_comment
comment|// CHECK-NOCOMMON: @x = global
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DEFAULT: @ABC = global
end_comment

begin_comment
comment|// CHECK-NOCOMMON: @ABC = global
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|fn_t
function_decl|)
parameter_list|(
name|long
name|a
parameter_list|,
name|long
name|b
parameter_list|,
name|char
modifier|*
name|f
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|fn_t
name|ABC
name|__attribute__
argument_list|(
operator|(
name|nocommon
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DEFAULT: @y = common global
end_comment

begin_comment
comment|// CHECK-NOCOMMON: @y = common global
end_comment

begin_decl_stmt
name|int
name|y
name|__attribute__
argument_list|(
operator|(
name|common
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

