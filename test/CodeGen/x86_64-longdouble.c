begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux-android -emit-llvm -O -o - %s \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s --check-prefix=ANDROID --check-prefix=CHECK
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux-gnu -emit-llvm -O -o - %s \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s --check-prefix=GNU --check-prefix=CHECK
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64 -emit-llvm -O -o - %s \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s --check-prefix=GNU --check-prefix=CHECK
end_comment

begin_comment
comment|// NaCl is an example of a target for which long double is the same as double.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-nacl -emit-llvm -O -o - %s \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s --check-prefix=NACL --check-prefix=CHECK
end_comment

begin_comment
comment|// Android uses fp128 for long double but other x86_64 targets use x86_fp80.
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
comment|// ANDROID: @dataLD = local_unnamed_addr global fp128 0xL00000000000000003FFF000000000000, align 16
end_comment

begin_comment
comment|// GNU: @dataLD = local_unnamed_addr global x86_fp80 0xK3FFF8000000000000000, align 16
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
comment|// ANDROID: @dataLDC = local_unnamed_addr global { fp128, fp128 } { fp128 0xL00000000000000003FFF000000000000, fp128 0xL00000000000000003FFF000000000000 }, align 16
end_comment

begin_comment
comment|// GNU: @dataLDC = local_unnamed_addr global { x86_fp80, x86_fp80 } { x86_fp80 0xK3FFF8000000000000000, x86_fp80 0xK3FFF8000000000000000 }, align 16
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
comment|// ANDROID: define fp128 @TestLD(fp128 %x)
comment|// GNU: define x86_fp80 @TestLD(x86_fp80 %x)
comment|// NACL: define double @TestLD(double %x)
block|}
end_function

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
comment|// ANDROID: define void @TestLDC({ fp128, fp128 }* {{.*}}, { fp128, fp128 }* {{.*}} %x)
comment|// GNU: define { x86_fp80, x86_fp80 } @TestLDC({ x86_fp80, x86_fp80 }* {{.*}} %x)
comment|// NACL: define { double, double } @TestLDC(double %x{{.*}}, double %x{{.*}})
block|}
end_function

begin_typedef
typedef|typedef
name|__builtin_va_list
name|va_list
typedef|;
end_typedef

begin_function
name|int
name|TestGetVarInt
parameter_list|(
name|va_list
name|ap
parameter_list|)
block|{
return|return
name|__builtin_va_arg
argument_list|(
name|ap
argument_list|,
name|int
argument_list|)
return|;
comment|// Since int can be passed in memory or register there are two branches.
comment|// CHECK:   define i32 @TestGetVarInt(
comment|// CHECK:   br label
comment|// CHECK:   br label
comment|// CHECK:   = phi
comment|// CHECK:   ret i32
block|}
end_function

begin_function
name|double
name|TestGetVarDouble
parameter_list|(
name|va_list
name|ap
parameter_list|)
block|{
return|return
name|__builtin_va_arg
argument_list|(
name|ap
argument_list|,
name|double
argument_list|)
return|;
comment|// Since double can be passed in memory or register there are two branches.
comment|// CHECK:   define double @TestGetVarDouble(
comment|// CHECK:   br label
comment|// CHECK:   br label
comment|// CHECK:   = phi
comment|// CHECK:   ret double
block|}
end_function

begin_function
name|long
name|double
name|TestGetVarLD
parameter_list|(
name|va_list
name|ap
parameter_list|)
block|{
return|return
name|__builtin_va_arg
argument_list|(
argument|ap
argument_list|,
argument|long double
argument_list|)
return|;
comment|// fp128 and double can be passed in memory or in register, but x86_fp80 is in
comment|// memory.
comment|// ANDROID: define fp128 @TestGetVarLD(
comment|// GNU:     define x86_fp80 @TestGetVarLD(
comment|// NACL:     define double @TestGetVarLD(
comment|// ANDROID: br label
comment|// ANDROID: br label
comment|// NACL: br
comment|// ANDROID: = phi
comment|// GNU-NOT: br
comment|// GNU-NOT: = phi
comment|// NACL: = phi
comment|// ANDROID: ret fp128
comment|// GNU:     ret x86_fp80
block|}
end_function

begin_function
name|long
name|double
specifier|_Complex
name|TestGetVarLDC
parameter_list|(
name|va_list
name|ap
parameter_list|)
block|{
return|return
name|__builtin_va_arg
argument_list|(
argument|ap
argument_list|,
argument|long double _Complex
argument_list|)
return|;
comment|// Pair of fp128 or x86_fp80 are passed as struct in memory.
comment|// ANDROID:   define void @TestGetVarLDC({ fp128, fp128 }* {{.*}}, %struct.__va_list_tag*
comment|// GNU:       define { x86_fp80, x86_fp80 } @TestGetVarLDC(
comment|// Pair of double can go in SSE registers or memory
comment|// NACL:       define { double, double } @TestGetVarLDC(
comment|// ANDROID-NOT: br
comment|// GNU-NOT: br
comment|// NACL: br
comment|// ANDROID-NOT: phi
comment|// GNU-NOT: phi
comment|// NACL: phi
comment|// ANDROID:   ret void
comment|// GNU:       ret { x86_fp80, x86_fp80 }
comment|// NACL:       ret { double, double }
block|}
end_function

begin_function_decl
name|void
name|TestVarArg
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|TestPassVarInt
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|TestVarArg
argument_list|(
literal|"A"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: define void @TestPassVarInt(i32 %x)
comment|// CHECK: call {{.*}} @TestVarArg(i8* {{.*}}, i32 %x)
block|}
end_function

begin_function
name|void
name|TestPassVarFloat
parameter_list|(
name|float
name|x
parameter_list|)
block|{
name|TestVarArg
argument_list|(
literal|"A"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: define void @TestPassVarFloat(float %x)
comment|// CHECK: call {{.*}} @TestVarArg(i8* {{.*}}, double %
block|}
end_function

begin_function
name|void
name|TestPassVarDouble
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|TestVarArg
argument_list|(
literal|"A"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: define void @TestPassVarDouble(double %x)
comment|// CHECK: call {{.*}} @TestVarArg(i8* {{.*}}, double %x
block|}
end_function

begin_function
name|void
name|TestPassVarLD
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
name|TestVarArg
argument_list|(
literal|"A"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// ANDROID: define void @TestPassVarLD(fp128 %x)
comment|// ANDROID: call {{.*}} @TestVarArg(i8* {{.*}}, fp128 %x
comment|// GNU: define void @TestPassVarLD(x86_fp80 %x)
comment|// GNU: call {{.*}} @TestVarArg(i8* {{.*}}, x86_fp80 %x
comment|// NACL: define void @TestPassVarLD(double %x)
comment|// NACL: call {{.*}} @TestVarArg(i8* {{.*}}, double %x
block|}
end_function

begin_function
name|void
name|TestPassVarLDC
parameter_list|(
name|long
name|double
specifier|_Complex
name|x
parameter_list|)
block|{
name|TestVarArg
argument_list|(
literal|"A"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// ANDROID:      define void @TestPassVarLDC({ fp128, fp128 }* {{.*}} %x)
comment|// ANDROID:      store fp128 %{{.*}}, fp128* %
comment|// ANDROID-NEXT: store fp128 %{{.*}}, fp128* %
comment|// ANDROID-NEXT: call {{.*}} @TestVarArg(i8* {{.*}}, { fp128, fp128 }* {{.*}} %
comment|// GNU:          define void @TestPassVarLDC({ x86_fp80, x86_fp80 }* {{.*}} %x)
comment|// GNU:          store x86_fp80 %{{.*}}, x86_fp80* %
comment|// GNU-NEXT:     store x86_fp80 %{{.*}}, x86_fp80* %
comment|// GNU-NEXT:   call {{.*}} @TestVarArg(i8* {{.*}}, { x86_fp80, x86_fp80 }* {{.*}} %
comment|// NACL:      define void @TestPassVarLDC(double %x{{.*}}, double %x{{.*}})
comment|// NACL: call {{.*}} @TestVarArg(i8* {{.*}}, double %x{{.*}}, double %x{{.*}})
block|}
end_function

end_unit

