begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Werror -triple i386-unknown-unknown -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: Note that we don't currently get the ABI right here. f0() should be
end_comment

begin_comment
comment|// f0(i8*).
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|void
modifier|*
name|f0
decl_stmt|;
block|}
name|transp_t0
name|__attribute__
typedef|((
name|transparent_union
typedef|));
end_typedef

begin_function_decl
name|void
name|f0
parameter_list|(
name|transp_t0
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: define void @f1_0(i32* %a0)
end_comment

begin_comment
comment|// CHECK:  call void @f0(%union.transp_t0* byval align 4 %{{.*}})
end_comment

begin_comment
comment|// CHECK:  call void %{{.*}}(i8* %{{[a-z0-9]*}})
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|void
name|f1_0
parameter_list|(
name|int
modifier|*
name|a0
parameter_list|)
block|{
name|void
function_decl|(
modifier|*
name|f0p
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
init|=
name|f0
function_decl|;
name|f0
argument_list|(
name|a0
argument_list|)
expr_stmt|;
name|f0p
argument_list|(
name|a0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f1_1
parameter_list|(
name|int
modifier|*
name|a0
parameter_list|)
block|{
name|f0
argument_list|(
operator|(
name|transp_t0
operator|)
block|{
name|a0
block|}
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

