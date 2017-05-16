begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple sparc-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: define float @fabsf(float %a)
end_comment

begin_comment
comment|// CHECK: %{{.*}} = call float asm sideeffect "fabss $1, $0;", "=e,f"(float %{{.*}}) #1
end_comment

begin_function
name|float
name|fabsf
parameter_list|(
name|float
name|a
parameter_list|)
block|{
name|float
name|res
decl_stmt|;
asm|__asm __volatile__("fabss  %1, %0;"
block|:
comment|/* reg out*/
literal|"=e"
operator|(
name|res
operator|)
operator|:
comment|/* reg in */
literal|"f"
operator|(
name|a
operator|)
block|)
function|;
end_function

begin_return
return|return
name|res
return|;
end_return

unit|}
end_unit

