begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-module -triple x86_64-apple-darwin10 -o %t/module.pcm -DBUILD_MODULE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodule-cache-path %t -triple x86_64-apple-darwin10 -fdisable-module-hash -emit-llvm -o - %s | FileCheck %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BUILD_MODULE
end_ifdef

begin_function
specifier|static
specifier|inline
name|int
name|triple
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
operator|*
literal|3
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|__import_module__
name|module
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: define void @triple_value
end_comment

begin_function
name|void
name|triple_value
parameter_list|(
name|int
modifier|*
name|px
parameter_list|)
block|{
operator|*
name|px
operator|=
name|triple
argument_list|(
operator|*
name|px
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: define internal i32 @triple(i32
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

