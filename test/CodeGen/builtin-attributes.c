begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm-unknown-linux-gnueabi -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: declare i32 @printf(i8*, ...)
end_comment

begin_function
name|void
name|f0
parameter_list|()
block|{
name|printf
argument_list|(
literal|"a\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: call void @exit
end_comment

begin_comment
comment|// CHECK: unreachable
end_comment

begin_function
name|void
name|f1
parameter_list|()
block|{
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: call i8* @strstr{{.*}} nounwind
end_comment

begin_function
name|char
modifier|*
name|f2
parameter_list|(
name|char
modifier|*
name|a
parameter_list|,
name|char
modifier|*
name|b
parameter_list|)
block|{
return|return
name|__builtin_strstr
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// frexp is NOT readnone. It writes to its pointer argument.
end_comment

begin_comment
comment|//<rdar://problem/10070234>
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: f3
end_comment

begin_comment
comment|// CHECK: call double @frexp(double %
end_comment

begin_comment
comment|// CHECK-NOT: readnone
end_comment

begin_comment
comment|// CHECK: call float @frexpf(float %
end_comment

begin_comment
comment|// CHECK-NOT: readnone
end_comment

begin_comment
comment|// CHECK: call double @frexpl(double %
end_comment

begin_comment
comment|// CHECK-NOT: readnone
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Same thing for modf and friends.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: call double @modf(double %
end_comment

begin_comment
comment|// CHECK-NOT: readnone
end_comment

begin_comment
comment|// CHECK: call float @modff(float %
end_comment

begin_comment
comment|// CHECK-NOT: readnone
end_comment

begin_comment
comment|// CHECK: call double @modfl(double %
end_comment

begin_comment
comment|// CHECK-NOT: readnone
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: call double @remquo(double %
end_comment

begin_comment
comment|// CHECK-NOT: readnone
end_comment

begin_comment
comment|// CHECK: call float @remquof(float %
end_comment

begin_comment
comment|// CHECK-NOT: readnone
end_comment

begin_comment
comment|// CHECK: call double @remquol(double %
end_comment

begin_comment
comment|// CHECK-NOT: readnone
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|int
name|f3
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|int
name|e
decl_stmt|;
name|__builtin_frexp
argument_list|(
name|x
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
name|__builtin_frexpf
argument_list|(
name|x
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
name|__builtin_frexpl
argument_list|(
name|x
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
name|__builtin_modf
argument_list|(
name|x
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
name|__builtin_modff
argument_list|(
name|x
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
name|__builtin_modfl
argument_list|(
name|x
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
name|__builtin_remquo
argument_list|(
name|x
argument_list|,
name|x
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
name|__builtin_remquof
argument_list|(
name|x
argument_list|,
name|x
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
name|__builtin_remquol
argument_list|(
name|x
argument_list|,
name|x
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
return|return
name|e
return|;
block|}
end_function

end_unit

