begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_typedef
typedef|typedef
struct|struct
name|s1
block|{
name|float
name|f
decl_stmt|;
block|}
name|Sf
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s2
block|{
name|double
name|d
decl_stmt|;
block|}
name|Sd
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s4
block|{
name|Sf
name|fs
decl_stmt|;
block|}
name|SSf
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s5
block|{
name|Sd
name|ds
decl_stmt|;
block|}
name|SSd
typedef|;
end_typedef

begin_function
name|void
name|bar
parameter_list|(
name|Sf
name|a
parameter_list|,
name|Sd
name|b
parameter_list|,
name|SSf
name|d
parameter_list|,
name|SSd
name|e
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @bar
end_comment

begin_comment
comment|// CHECK:  %a = alloca %struct.s1, align 4
end_comment

begin_comment
comment|// CHECK:  %b = alloca %struct.s2, align 8
end_comment

begin_comment
comment|// CHECK:  %d = alloca %struct.s4, align 4
end_comment

begin_comment
comment|// CHECK:  %e = alloca %struct.s5, align 8
end_comment

begin_comment
comment|// CHECK:  %{{[a-zA-Z0-9.]+}} = getelementptr %struct.s1* %a, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:  store float %a.coerce, float* %{{[a-zA-Z0-9.]+}}, align 1
end_comment

begin_comment
comment|// CHECK:  %{{[a-zA-Z0-9.]+}} = getelementptr %struct.s2* %b, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:  store double %b.coerce, double* %{{[a-zA-Z0-9.]+}}, align 1
end_comment

begin_comment
comment|// CHECK:  %{{[a-zA-Z0-9.]+}} = getelementptr %struct.s4* %d, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:  %{{[a-zA-Z0-9.]+}} = getelementptr %struct.s1* %{{[a-zA-Z0-9.]+}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:  store float %d.coerce, float* %{{[a-zA-Z0-9.]+}}, align 1
end_comment

begin_comment
comment|// CHECK:  %{{[a-zA-Z0-9.]+}} = getelementptr %struct.s5* %e, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:  %{{[a-zA-Z0-9.]+}} = getelementptr %struct.s2* %{{[a-zA-Z0-9.]+}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:  store double %e.coerce, double* %{{[a-zA-Z0-9.]+}}, align 1
end_comment

begin_comment
comment|// CHECK:  ret void
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
name|Sf
name|p1
init|=
block|{
literal|22.63f
block|}
decl_stmt|;
name|Sd
name|p2
init|=
block|{
literal|19.47
block|}
decl_stmt|;
name|SSf
name|p4
init|=
block|{
block|{
literal|22.63f
block|}
block|}
decl_stmt|;
name|SSd
name|p5
init|=
block|{
block|{
literal|19.47
block|}
block|}
decl_stmt|;
name|bar
argument_list|(
name|p1
argument_list|,
name|p2
argument_list|,
name|p4
argument_list|,
name|p5
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @foo
end_comment

begin_comment
comment|// CHECK:  %{{[a-zA-Z0-9.]+}} = getelementptr %struct.s1* %p1, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:  %{{[0-9]+}} = load float* %{{[a-zA-Z0-9.]+}}, align 1
end_comment

begin_comment
comment|// CHECK:  %{{[a-zA-Z0-9.]+}} = getelementptr %struct.s2* %p2, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:  %{{[0-9]+}} = load double* %{{[a-zA-Z0-9.]+}}, align 1
end_comment

begin_comment
comment|// CHECK:  %{{[a-zA-Z0-9.]+}} = getelementptr %struct.s4* %p4, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:  %{{[a-zA-Z0-9.]+}} = getelementptr %struct.s1* %{{[a-zA-Z0-9.]+}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:  %{{[0-9]+}} = load float* %{{[a-zA-Z0-9.]+}}, align 1
end_comment

begin_comment
comment|// CHECK:  %{{[a-zA-Z0-9.]+}} = getelementptr %struct.s5* %p5, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:  %{{[a-zA-Z0-9.]+}} = getelementptr %struct.s2* %{{[a-zA-Z0-9.]+}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:  %{{[0-9]+}} = load double* %{{[a-zA-Z0-9.]+}}, align 1
end_comment

begin_comment
comment|// CHECK:  call void @bar(float inreg %{{[0-9]+}}, double inreg %{{[0-9]+}}, float inreg %{{[0-9]+}}, double inreg %{{[0-9]+}})
end_comment

begin_comment
comment|// CHECK:  ret void
end_comment

end_unit

