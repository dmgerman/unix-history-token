begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -triple armv8-eabi -target-cpu cortex-a57 -O -S -emit-llvm -o - %s | FileCheck %s -check-prefix=ARM -check-prefix=AArch32
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -triple aarch64-eabi -target-cpu cortex-a57 -target-feature +neon -target-feature +crc -target-feature +crypto -O -S -emit-llvm -o - %s | FileCheck %s -check-prefix=ARM -check-prefix=AArch64
end_comment

begin_include
include|#
directive|include
file|<arm_acle.h>
end_include

begin_comment
comment|/* 8 SYNCHRONIZATION, BARRIER AND HINT INTRINSICS */
end_comment

begin_comment
comment|/* 8.3 Memory Barriers */
end_comment

begin_comment
comment|// ARM-LABEL: test_dmb
end_comment

begin_comment
comment|// AArch32: call void @llvm.arm.dmb(i32 1)
end_comment

begin_comment
comment|// AArch64: call void @llvm.aarch64.dmb(i32 1)
end_comment

begin_function
name|void
name|test_dmb
parameter_list|(
name|void
parameter_list|)
block|{
name|__dmb
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_dsb
end_comment

begin_comment
comment|// AArch32: call void @llvm.arm.dsb(i32 2)
end_comment

begin_comment
comment|// AArch64: call void @llvm.aarch64.dsb(i32 2)
end_comment

begin_function
name|void
name|test_dsb
parameter_list|(
name|void
parameter_list|)
block|{
name|__dsb
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_isb
end_comment

begin_comment
comment|// AArch32: call void @llvm.arm.isb(i32 3)
end_comment

begin_comment
comment|// AArch64: call void @llvm.aarch64.isb(i32 3)
end_comment

begin_function
name|void
name|test_isb
parameter_list|(
name|void
parameter_list|)
block|{
name|__isb
argument_list|(
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* 8.4 Hints */
end_comment

begin_comment
comment|// ARM-LABEL: test_yield
end_comment

begin_comment
comment|// AArch32: call void @llvm.arm.hint(i32 1)
end_comment

begin_comment
comment|// AArch64: call void @llvm.aarch64.hint(i32 1)
end_comment

begin_function
name|void
name|test_yield
parameter_list|(
name|void
parameter_list|)
block|{
name|__yield
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_wfe
end_comment

begin_comment
comment|// AArch32: call void @llvm.arm.hint(i32 2)
end_comment

begin_comment
comment|// AArch64: call void @llvm.aarch64.hint(i32 2)
end_comment

begin_function
name|void
name|test_wfe
parameter_list|(
name|void
parameter_list|)
block|{
name|__wfe
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_wfi
end_comment

begin_comment
comment|// AArch32: call void @llvm.arm.hint(i32 3)
end_comment

begin_comment
comment|// AArch64: call void @llvm.aarch64.hint(i32 3)
end_comment

begin_function
name|void
name|test_wfi
parameter_list|(
name|void
parameter_list|)
block|{
name|__wfi
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_sev
end_comment

begin_comment
comment|// AArch32: call void @llvm.arm.hint(i32 4)
end_comment

begin_comment
comment|// AArch64: call void @llvm.aarch64.hint(i32 4)
end_comment

begin_function
name|void
name|test_sev
parameter_list|(
name|void
parameter_list|)
block|{
name|__sev
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_sevl
end_comment

begin_comment
comment|// AArch32: call void @llvm.arm.hint(i32 5)
end_comment

begin_comment
comment|// AArch64: call void @llvm.aarch64.hint(i32 5)
end_comment

begin_function
name|void
name|test_sevl
parameter_list|(
name|void
parameter_list|)
block|{
name|__sevl
argument_list|()
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|__ARM_32BIT_STATE
end_if

begin_comment
comment|// AArch32-LABEL: test_dbg
end_comment

begin_comment
comment|// AArch32: call void @llvm.arm.dbg(i32 0)
end_comment

begin_function
name|void
name|test_dbg
parameter_list|(
name|void
parameter_list|)
block|{
name|__dbg
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 8.5 Swap */
end_comment

begin_comment
comment|// ARM-LABEL: test_swp
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.ldrex
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.strex
end_comment

begin_comment
comment|// AArch64: call i64 @llvm.aarch64.ldxr
end_comment

begin_comment
comment|// AArch64: call i32 @llvm.aarch64.stxr
end_comment

begin_function
name|uint32_t
name|test_swp
parameter_list|(
name|uint32_t
name|x
parameter_list|,
specifier|volatile
name|void
modifier|*
name|p
parameter_list|)
block|{
name|__swp
argument_list|(
name|x
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* 8.6 Memory prefetch intrinsics */
end_comment

begin_comment
comment|/* 8.6.1 Data prefetch */
end_comment

begin_comment
comment|// ARM-LABEL: test_pld
end_comment

begin_comment
comment|// ARM: call void @llvm.prefetch(i8* null, i32 0, i32 3, i32 1)
end_comment

begin_function
name|void
name|test_pld
parameter_list|()
block|{
name|__pld
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_pldx
end_comment

begin_comment
comment|// AArch32: call void @llvm.prefetch(i8* null, i32 1, i32 3, i32 1)
end_comment

begin_comment
comment|// AArch64: call void @llvm.prefetch(i8* null, i32 1, i32 1, i32 1)
end_comment

begin_function
name|void
name|test_pldx
parameter_list|()
block|{
name|__pldx
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* 8.6.2 Instruction prefetch */
end_comment

begin_comment
comment|// ARM-LABEL: test_pli
end_comment

begin_comment
comment|// ARM: call void @llvm.prefetch(i8* null, i32 0, i32 3, i32 0)
end_comment

begin_function
name|void
name|test_pli
parameter_list|()
block|{
name|__pli
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_plix
end_comment

begin_comment
comment|// AArch32: call void @llvm.prefetch(i8* null, i32 0, i32 3, i32 0)
end_comment

begin_comment
comment|// AArch64: call void @llvm.prefetch(i8* null, i32 0, i32 1, i32 0)
end_comment

begin_function
name|void
name|test_plix
parameter_list|()
block|{
name|__plix
argument_list|(
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* 8.7 NOP */
end_comment

begin_comment
comment|// ARM-LABEL: test_nop
end_comment

begin_comment
comment|// AArch32: call void @llvm.arm.hint(i32 0)
end_comment

begin_comment
comment|// AArch64: call void @llvm.aarch64.hint(i32 0)
end_comment

begin_function
name|void
name|test_nop
parameter_list|(
name|void
parameter_list|)
block|{
name|__nop
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* 9 DATA-PROCESSING INTRINSICS */
end_comment

begin_comment
comment|/* 9.2 Miscellaneous data-processing intrinsics */
end_comment

begin_comment
comment|// ARM-LABEL: test_ror
end_comment

begin_comment
comment|// ARM: lshr
end_comment

begin_comment
comment|// ARM: sub
end_comment

begin_comment
comment|// ARM: shl
end_comment

begin_comment
comment|// ARM: or
end_comment

begin_function
name|uint32_t
name|test_ror
parameter_list|(
name|uint32_t
name|x
parameter_list|,
name|uint32_t
name|y
parameter_list|)
block|{
return|return
name|__ror
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_rorl
end_comment

begin_comment
comment|// ARM: lshr
end_comment

begin_comment
comment|// ARM: sub
end_comment

begin_comment
comment|// ARM: shl
end_comment

begin_comment
comment|// ARM: or
end_comment

begin_function
name|unsigned
name|long
name|test_rorl
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|,
name|uint32_t
name|y
parameter_list|)
block|{
return|return
name|__rorl
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_rorll
end_comment

begin_comment
comment|// ARM: lshr
end_comment

begin_comment
comment|// ARM: sub
end_comment

begin_comment
comment|// ARM: shl
end_comment

begin_comment
comment|// ARM: or
end_comment

begin_function
name|uint64_t
name|test_rorll
parameter_list|(
name|uint64_t
name|x
parameter_list|,
name|uint32_t
name|y
parameter_list|)
block|{
return|return
name|__rorll
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_clz
end_comment

begin_comment
comment|// ARM: call i32 @llvm.ctlz.i32(i32 %t, i1 false)
end_comment

begin_function
name|uint32_t
name|test_clz
parameter_list|(
name|uint32_t
name|t
parameter_list|)
block|{
return|return
name|__clz
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_clzl
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.ctlz.i32(i32 %t, i1 false)
end_comment

begin_comment
comment|// AArch64: call i64 @llvm.ctlz.i64(i64 %t, i1 false)
end_comment

begin_function
name|long
name|test_clzl
parameter_list|(
name|long
name|t
parameter_list|)
block|{
return|return
name|__clzl
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_clzll
end_comment

begin_comment
comment|// ARM: call i64 @llvm.ctlz.i64(i64 %t, i1 false)
end_comment

begin_function
name|uint64_t
name|test_clzll
parameter_list|(
name|uint64_t
name|t
parameter_list|)
block|{
return|return
name|__clzll
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_rev
end_comment

begin_comment
comment|// ARM: call i32 @llvm.bswap.i32(i32 %t)
end_comment

begin_function
name|uint32_t
name|test_rev
parameter_list|(
name|uint32_t
name|t
parameter_list|)
block|{
return|return
name|__rev
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_revl
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.bswap.i32(i32 %t)
end_comment

begin_comment
comment|// AArch64: call i64 @llvm.bswap.i64(i64 %t)
end_comment

begin_function
name|long
name|test_revl
parameter_list|(
name|long
name|t
parameter_list|)
block|{
return|return
name|__revl
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_revll
end_comment

begin_comment
comment|// ARM: call i64 @llvm.bswap.i64(i64 %t)
end_comment

begin_function
name|uint64_t
name|test_revll
parameter_list|(
name|uint64_t
name|t
parameter_list|)
block|{
return|return
name|__revll
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_rev16
end_comment

begin_comment
comment|// ARM: llvm.bswap
end_comment

begin_comment
comment|// ARM: lshr
end_comment

begin_comment
comment|// ARM: shl
end_comment

begin_comment
comment|// ARM: or
end_comment

begin_function
name|uint32_t
name|test_rev16
parameter_list|(
name|uint32_t
name|t
parameter_list|)
block|{
return|return
name|__rev16
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_rev16l
end_comment

begin_comment
comment|// ARM: llvm.bswap
end_comment

begin_comment
comment|// ARM: lshr
end_comment

begin_comment
comment|// ARM: shl
end_comment

begin_comment
comment|// ARM: or
end_comment

begin_function
name|long
name|test_rev16l
parameter_list|(
name|long
name|t
parameter_list|)
block|{
return|return
name|__rev16l
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_rev16ll
end_comment

begin_comment
comment|// ARM: llvm.bswap
end_comment

begin_comment
comment|// ARM: lshr
end_comment

begin_comment
comment|// ARM: shl
end_comment

begin_comment
comment|// ARM: or
end_comment

begin_function
name|uint64_t
name|test_rev16ll
parameter_list|(
name|uint64_t
name|t
parameter_list|)
block|{
return|return
name|__rev16ll
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_revsh
end_comment

begin_comment
comment|// ARM: call i16 @llvm.bswap.i16(i16 %t)
end_comment

begin_function
name|int16_t
name|test_revsh
parameter_list|(
name|int16_t
name|t
parameter_list|)
block|{
return|return
name|__revsh
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_rbit
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.rbit
end_comment

begin_comment
comment|// AArch64: call i32 @llvm.aarch64.rbit.i32
end_comment

begin_function
name|uint32_t
name|test_rbit
parameter_list|(
name|uint32_t
name|t
parameter_list|)
block|{
return|return
name|__rbit
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_rbitl
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.rbit
end_comment

begin_comment
comment|// AArch64: call i64 @llvm.aarch64.rbit.i64
end_comment

begin_function
name|long
name|test_rbitl
parameter_list|(
name|long
name|t
parameter_list|)
block|{
return|return
name|__rbitl
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_rbitll
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.rbit
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.rbit
end_comment

begin_comment
comment|// AArch64: call i64 @llvm.aarch64.rbit.i64
end_comment

begin_function
name|uint64_t
name|test_rbitll
parameter_list|(
name|uint64_t
name|t
parameter_list|)
block|{
return|return
name|__rbitll
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* 9.4 Saturating intrinsics */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_32BIT_STATE
end_ifdef

begin_comment
comment|/* 9.4.1 Width-specified saturation intrinsics */
end_comment

begin_comment
comment|// AArch32-LABEL: test_ssat
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.ssat(i32 %t, i32 1)
end_comment

begin_function
name|int32_t
name|test_ssat
parameter_list|(
name|int32_t
name|t
parameter_list|)
block|{
return|return
name|__ssat
argument_list|(
name|t
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// AArch32-LABEL: test_usat
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.usat(i32 %t, i32 2)
end_comment

begin_function
name|int32_t
name|test_usat
parameter_list|(
name|int32_t
name|t
parameter_list|)
block|{
return|return
name|__usat
argument_list|(
name|t
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* 9.4.2 Saturating addition and subtraction intrinsics */
end_comment

begin_comment
comment|// AArch32-LABEL: test_qadd
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.qadd(i32 %a, i32 %b)
end_comment

begin_function
name|int32_t
name|test_qadd
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|__qadd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// AArch32-LABEL: test_qsub
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.qsub(i32 %a, i32 %b)
end_comment

begin_function
name|int32_t
name|test_qsub
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|__qsub
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function_decl
specifier|extern
name|int32_t
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// AArch32-LABEL: test_qdbl
end_comment

begin_comment
comment|// AArch32: [[VAR:%[a-z0-9]+]] = {{.*}} call {{.*}} @f
end_comment

begin_comment
comment|// AArch32-NOT: call {{.*}} @f
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.qadd(i32 [[VAR]], i32 [[VAR]])
end_comment

begin_function
name|int32_t
name|test_qdbl
parameter_list|()
block|{
return|return
name|__qdbl
argument_list|(
name|f
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 9.7 CRC32 intrinsics */
end_comment

begin_comment
comment|// ARM-LABEL: test_crc32b
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.crc32b
end_comment

begin_comment
comment|// AArch64: call i32 @llvm.aarch64.crc32b
end_comment

begin_function
name|uint32_t
name|test_crc32b
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint8_t
name|b
parameter_list|)
block|{
return|return
name|__crc32b
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_crc32h
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.crc32h
end_comment

begin_comment
comment|// AArch64: call i32 @llvm.aarch64.crc32h
end_comment

begin_function
name|uint32_t
name|test_crc32h
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
return|return
name|__crc32h
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_crc32w
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.crc32w
end_comment

begin_comment
comment|// AArch64: call i32 @llvm.aarch64.crc32w
end_comment

begin_function
name|uint32_t
name|test_crc32w
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
return|return
name|__crc32w
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_crc32d
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.crc32w
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.crc32w
end_comment

begin_comment
comment|// AArch64: call i32 @llvm.aarch64.crc32x
end_comment

begin_function
name|uint32_t
name|test_crc32d
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
return|return
name|__crc32d
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_crc32cb
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.crc32cb
end_comment

begin_comment
comment|// AArch64: call i32 @llvm.aarch64.crc32cb
end_comment

begin_function
name|uint32_t
name|test_crc32cb
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint8_t
name|b
parameter_list|)
block|{
return|return
name|__crc32cb
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_crc32ch
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.crc32ch
end_comment

begin_comment
comment|// AArch64: call i32 @llvm.aarch64.crc32ch
end_comment

begin_function
name|uint32_t
name|test_crc32ch
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
return|return
name|__crc32ch
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_crc32cw
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.crc32cw
end_comment

begin_comment
comment|// AArch64: call i32 @llvm.aarch64.crc32cw
end_comment

begin_function
name|uint32_t
name|test_crc32cw
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
return|return
name|__crc32cw
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ARM-LABEL: test_crc32cd
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.crc32cw
end_comment

begin_comment
comment|// AArch32: call i32 @llvm.arm.crc32cw
end_comment

begin_comment
comment|// AArch64: call i32 @llvm.aarch64.crc32cx
end_comment

begin_function
name|uint32_t
name|test_crc32cd
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
return|return
name|__crc32cd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

end_unit

