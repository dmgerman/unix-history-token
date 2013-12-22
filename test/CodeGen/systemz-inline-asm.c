begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple s390x-linux-gnu -O2 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_decl_stmt
name|unsigned
name|int
name|gi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|gl
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_store_m
parameter_list|(
name|unsigned
name|int
name|i
parameter_list|)
block|{
asm|asm("st %1, %0" : "=m" (gi) : "r" (i));
comment|// CHECK-LABEL: define void @test_store_m(i32 zeroext %i)
comment|// CHECK: call void asm "st $1, $0", "=*m,r"(i32* @gi, i32 %i)
block|}
end_function

begin_function
name|void
name|test_store_Q
parameter_list|(
name|unsigned
name|int
name|i
parameter_list|)
block|{
asm|asm("st %1, %0" : "=Q" (gi) : "r" (i));
comment|// CHECK-LABEL: define void @test_store_Q(i32 zeroext %i)
comment|// CHECK: call void asm "st $1, $0", "=*Q,r"(i32* @gi, i32 %i)
block|}
end_function

begin_function
name|void
name|test_store_R
parameter_list|(
name|unsigned
name|int
name|i
parameter_list|)
block|{
asm|asm("st %1, %0" : "=R" (gi) : "r" (i));
comment|// CHECK-LABEL: define void @test_store_R(i32 zeroext %i)
comment|// CHECK: call void asm "st $1, $0", "=*R,r"(i32* @gi, i32 %i)
block|}
end_function

begin_function
name|void
name|test_store_S
parameter_list|(
name|unsigned
name|int
name|i
parameter_list|)
block|{
asm|asm("st %1, %0" : "=S" (gi) : "r" (i));
comment|// CHECK-LABEL: define void @test_store_S(i32 zeroext %i)
comment|// CHECK: call void asm "st $1, $0", "=*S,r"(i32* @gi, i32 %i)
block|}
end_function

begin_function
name|void
name|test_store_T
parameter_list|(
name|unsigned
name|int
name|i
parameter_list|)
block|{
asm|asm("st %1, %0" : "=T" (gi) : "r" (i));
comment|// CHECK-LABEL: define void @test_store_T(i32 zeroext %i)
comment|// CHECK: call void asm "st $1, $0", "=*T,r"(i32* @gi, i32 %i)
block|}
end_function

begin_function
name|int
name|test_load_m
parameter_list|()
block|{
name|unsigned
name|int
name|i
decl_stmt|;
asm|asm("l %0, %1" : "=r" (i) : "m" (gi));
return|return
name|i
return|;
comment|// CHECK-LABEL: define signext i32 @test_load_m()
comment|// CHECK: call i32 asm "l $0, $1", "=r,*m"(i32* @gi)
block|}
end_function

begin_function
name|int
name|test_load_Q
parameter_list|()
block|{
name|unsigned
name|int
name|i
decl_stmt|;
asm|asm("l %0, %1" : "=r" (i) : "Q" (gi));
return|return
name|i
return|;
comment|// CHECK-LABEL: define signext i32 @test_load_Q()
comment|// CHECK: call i32 asm "l $0, $1", "=r,*Q"(i32* @gi)
block|}
end_function

begin_function
name|int
name|test_load_R
parameter_list|()
block|{
name|unsigned
name|int
name|i
decl_stmt|;
asm|asm("l %0, %1" : "=r" (i) : "R" (gi));
return|return
name|i
return|;
comment|// CHECK-LABEL: define signext i32 @test_load_R()
comment|// CHECK: call i32 asm "l $0, $1", "=r,*R"(i32* @gi)
block|}
end_function

begin_function
name|int
name|test_load_S
parameter_list|()
block|{
name|unsigned
name|int
name|i
decl_stmt|;
asm|asm("l %0, %1" : "=r" (i) : "S" (gi));
return|return
name|i
return|;
comment|// CHECK-LABEL: define signext i32 @test_load_S()
comment|// CHECK: call i32 asm "l $0, $1", "=r,*S"(i32* @gi)
block|}
end_function

begin_function
name|int
name|test_load_T
parameter_list|()
block|{
name|unsigned
name|int
name|i
decl_stmt|;
asm|asm("l %0, %1" : "=r" (i) : "T" (gi));
return|return
name|i
return|;
comment|// CHECK-LABEL: define signext i32 @test_load_T()
comment|// CHECK: call i32 asm "l $0, $1", "=r,*T"(i32* @gi)
block|}
end_function

begin_function
name|void
name|test_mI
parameter_list|(
name|unsigned
name|char
modifier|*
name|c
parameter_list|)
block|{
asm|asm
specifier|volatile
asm|("cli %0, %1" :: "Q" (*c), "I" (100));
comment|// CHECK-LABEL: define void @test_mI(i8* %c)
comment|// CHECK: call void asm sideeffect "cli $0, $1", "*Q,I"(i8* %c, i32 100)
block|}
end_function

begin_function
name|unsigned
name|int
name|test_dJa
parameter_list|(
name|unsigned
name|int
name|i
parameter_list|,
name|unsigned
name|int
name|j
parameter_list|)
block|{
asm|asm("sll %0, %2(%3)" : "=d" (i) : "0" (i), "J" (1000), "a" (j));
return|return
name|i
return|;
comment|// CHECK-LABEL: define zeroext i32 @test_dJa(i32 zeroext %i, i32 zeroext %j)
comment|// CHECK: call i32 asm "sll $0, $2($3)", "=d,0,J,a"(i32 %i, i32 1000, i32 %j)
block|}
end_function

begin_function
name|unsigned
name|long
name|test_rK
parameter_list|(
name|unsigned
name|long
name|i
parameter_list|)
block|{
asm|asm("aghi %0, %2" : "=r" (i) : "0" (i), "K" (-30000));
return|return
name|i
return|;
comment|// CHECK-LABEL: define i64 @test_rK(i64 %i)
comment|// CHECK: call i64 asm "aghi $0, $2", "=r,0,K"(i64 %i, i32 -30000)
block|}
end_function

begin_function
name|unsigned
name|long
name|test_rL
parameter_list|(
name|unsigned
name|long
name|i
parameter_list|)
block|{
asm|asm("sllg %0, %1, %2" : "=r" (i) : "r" (i), "L" (500000));
return|return
name|i
return|;
comment|// CHECK-LABEL: define i64 @test_rL(i64 %i)
comment|// CHECK: call i64 asm "sllg $0, $1, $2", "=r,r,L"(i64 %i, i32 500000)
block|}
end_function

begin_function
name|void
name|test_M
parameter_list|()
block|{
asm|asm
specifier|volatile
asm|("#FOO %0" :: "M"(0x7fffffff));
comment|// CHECK-LABEL: define void @test_M()
comment|// CHECK: call void asm sideeffect "#FOO $0", "M"(i32 2147483647)
block|}
end_function

begin_function
name|float
name|test_f32
parameter_list|(
name|float
name|f
parameter_list|,
name|float
name|g
parameter_list|)
block|{
asm|asm("aebr %0, %2" : "=f" (f) : "0" (f), "f" (g));
return|return
name|f
return|;
comment|// CHECK-LABEL: define float @test_f32(float %f, float %g)
comment|// CHECK: call float asm "aebr $0, $2", "=f,0,f"(float %f, float %g)
block|}
end_function

begin_function
name|double
name|test_f64
parameter_list|(
name|double
name|f
parameter_list|,
name|double
name|g
parameter_list|)
block|{
asm|asm("adbr %0, %2" : "=f" (f) : "0" (f), "f" (g));
return|return
name|f
return|;
comment|// CHECK-LABEL: define double @test_f64(double %f, double %g)
comment|// CHECK: call double asm "adbr $0, $2", "=f,0,f"(double %f, double %g)
block|}
end_function

begin_function
name|long
name|double
name|test_f128
parameter_list|(
name|long
name|double
name|f
parameter_list|,
name|long
name|double
name|g
parameter_list|)
block|{
asm|asm("axbr %0, %2" : "=f" (f) : "0" (f), "f" (g));
return|return
name|f
return|;
comment|// CHECK: define void @test_f128(fp128* noalias nocapture sret [[DEST:%.*]], fp128* nocapture readonly, fp128* nocapture readonly)
comment|// CHECK: %f = load fp128* %0
comment|// CHECK: %g = load fp128* %1
comment|// CHECK: [[RESULT:%.*]] = tail call fp128 asm "axbr $0, $2", "=f,0,f"(fp128 %f, fp128 %g)
comment|// CHECK: store fp128 [[RESULT]], fp128* [[DEST]]
block|}
end_function

end_unit

