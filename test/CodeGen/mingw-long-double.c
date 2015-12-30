begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows-gnu -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s --check-prefix=GNU32
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows-gnu -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s --check-prefix=GNU64
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows-msvc -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s --check-prefix=MSC64
end_comment

begin_struct
struct|struct
block|{
name|char
name|c
decl_stmt|;
name|long
name|double
name|ldb
decl_stmt|;
block|}
name|agggregate_LD
init|=
block|{}
struct|;
end_struct

begin_comment
comment|// GNU32: %struct.anon = type { i8, x86_fp80 }
end_comment

begin_comment
comment|// GNU32: @agggregate_LD = global %struct.anon zeroinitializer, align 4
end_comment

begin_comment
comment|// GNU64: %struct.anon = type { i8, x86_fp80 }
end_comment

begin_comment
comment|// GNU64: @agggregate_LD = global %struct.anon zeroinitializer, align 16
end_comment

begin_comment
comment|// MSC64: %struct.anon = type { i8, double }
end_comment

begin_comment
comment|// MSC64: @agggregate_LD = global %struct.anon zeroinitializer, align 8
end_comment

begin_decl_stmt
name|long
name|double
name|dataLD
init|=
literal|1.0L
decl_stmt|;
end_decl_stmt

begin_comment
comment|// GNU32: @dataLD = global x86_fp80 0xK3FFF8000000000000000, align 4
end_comment

begin_comment
comment|// GNU64: @dataLD = global x86_fp80 0xK3FFF8000000000000000, align 16
end_comment

begin_comment
comment|// MSC64: @dataLD = global double 1.000000e+00, align 8
end_comment

begin_decl_stmt
name|long
name|double
specifier|_Complex
name|dataLDC
init|=
block|{
literal|1.0L
block|,
literal|1.0L
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// GNU32: @dataLDC = global { x86_fp80, x86_fp80 } { x86_fp80 0xK3FFF8000000000000000, x86_fp80 0xK3FFF8000000000000000 }, align 4
end_comment

begin_comment
comment|// GNU64: @dataLDC = global { x86_fp80, x86_fp80 } { x86_fp80 0xK3FFF8000000000000000, x86_fp80 0xK3FFF8000000000000000 }, align 16
end_comment

begin_comment
comment|// MSC64: @dataLDC = global { double, double } { double 1.000000e+00, double 1.000000e+00 }, align 8
end_comment

begin_function
name|long
name|double
name|TestLD
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
return|return
name|x
operator|*
name|x
return|;
block|}
end_function

begin_comment
comment|// GNU32: define x86_fp80 @TestLD(x86_fp80 %x)
end_comment

begin_comment
comment|// GNU64: define void @TestLD(x86_fp80* noalias sret %agg.result, x86_fp80*)
end_comment

begin_comment
comment|// MSC64: define double @TestLD(double %x)
end_comment

begin_function
name|long
name|double
specifier|_Complex
name|TestLDC
parameter_list|(
name|long
name|double
specifier|_Complex
name|x
parameter_list|)
block|{
return|return
name|x
operator|*
name|x
return|;
block|}
end_function

begin_comment
comment|// GNU32: define void @TestLDC({ x86_fp80, x86_fp80 }* noalias sret %agg.result, { x86_fp80, x86_fp80 }* byval align 4 %x)
end_comment

begin_comment
comment|// GNU64: define void @TestLDC({ x86_fp80, x86_fp80 }* noalias sret %agg.result, { x86_fp80, x86_fp80 }* %x)
end_comment

begin_comment
comment|// MSC64: define void @TestLDC({ double, double }* noalias sret %agg.result, { double, double }* %x)
end_comment

end_unit

