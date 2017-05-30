begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64le-linux-gnu -S -O0 -o - %s -target-feature +altivec -target-feature +vsx | FileCheck %s -check-prefix=CHECK -check-prefix=VSX
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc-linux-gnu -S -O0 -o - %s -target-feature +altivec -target-feature -vsx | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_include
include|#
directive|include
file|<altivec.h>
end_include

begin_comment
comment|// CHECK-LABEL: test1
end_comment

begin_comment
comment|// CHECK: vcfsx
end_comment

begin_function
name|vector
name|float
name|test1
parameter_list|(
name|vector
name|int
name|x
parameter_list|)
block|{
return|return
name|vec_ctf
argument_list|(
name|x
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test2
end_comment

begin_comment
comment|// CHECK: vcfux
end_comment

begin_function
name|vector
name|float
name|test2
parameter_list|(
name|vector
name|unsigned
name|int
name|x
parameter_list|)
block|{
return|return
name|vec_ctf
argument_list|(
name|x
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__VSX__
end_ifdef

begin_comment
comment|// VSX-LABEL: test3
end_comment

begin_function
name|vector
name|double
name|test3
parameter_list|(
name|vector
name|signed
name|long
name|long
name|x
parameter_list|)
block|{
return|return
name|vec_ctf
argument_list|(
name|x
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// VSX-LABEL: test4
end_comment

begin_function
name|vector
name|double
name|test4
parameter_list|(
name|vector
name|unsigned
name|long
name|long
name|x
parameter_list|)
block|{
return|return
name|vec_ctf
argument_list|(
name|x
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-LABEL: test5
end_comment

begin_comment
comment|// CHECK: vcfsx
end_comment

begin_function
name|vector
name|float
name|test5
parameter_list|(
name|vector
name|int
name|x
parameter_list|)
block|{
return|return
name|vec_vcfsx
argument_list|(
name|x
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test6
end_comment

begin_comment
comment|// CHECK: vcfux
end_comment

begin_function
name|vector
name|float
name|test6
parameter_list|(
name|vector
name|unsigned
name|int
name|x
parameter_list|)
block|{
return|return
name|vec_vcfux
argument_list|(
name|x
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test7
end_comment

begin_comment
comment|// CHECK: vctsxs
end_comment

begin_function
name|vector
name|int
name|test7
parameter_list|(
name|vector
name|float
name|x
parameter_list|)
block|{
return|return
name|vec_cts
argument_list|(
name|x
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__VSX__
end_ifdef

begin_comment
comment|// VSX-LABEL: test8
end_comment

begin_function
name|vector
name|signed
name|long
name|long
name|test8
parameter_list|(
name|vector
name|double
name|x
parameter_list|)
block|{
return|return
name|vec_cts
argument_list|(
name|x
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-LABEL: test9
end_comment

begin_comment
comment|// CHECK: vctsxs
end_comment

begin_function
name|vector
name|int
name|test9
parameter_list|(
name|vector
name|float
name|x
parameter_list|)
block|{
return|return
name|vec_vctsxs
argument_list|(
name|x
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test10
end_comment

begin_comment
comment|// CHECK: vctuxs
end_comment

begin_function
name|vector
name|unsigned
name|test10
parameter_list|(
name|vector
name|float
name|x
parameter_list|)
block|{
return|return
name|vec_ctu
argument_list|(
name|x
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__VSX__
end_ifdef

begin_comment
comment|// VSX-LABEL: test11
end_comment

begin_function
name|vector
name|unsigned
name|long
name|long
name|test11
parameter_list|(
name|vector
name|double
name|x
parameter_list|)
block|{
return|return
name|vec_ctu
argument_list|(
name|x
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-LABEL: test12
end_comment

begin_comment
comment|// CHECK: vctuxs
end_comment

begin_function
name|vector
name|unsigned
name|test12
parameter_list|(
name|vector
name|float
name|x
parameter_list|)
block|{
return|return
name|vec_vctuxs
argument_list|(
name|x
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

end_unit

