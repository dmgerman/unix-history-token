begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang -O3 -target aarch64-linux-eabi %s -S -o- \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO --check-prefix=CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -O3 -target aarch64-linux-eabi -mfix-cortex-a53-835769 %s -S -o- 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-YES --check-prefix=CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -O3 -target aarch64-linux-eabi -mno-fix-cortex-a53-835769 %s -S -o- 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO --check-prefix=CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -O3 -target aarch64-android-eabi %s -S -o- \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-YES --check-prefix=CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -O3 -target aarch64-android-eabi -mfix-cortex-a53-835769 %s -S -o- \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-YES --check-prefix=CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -O3 -target aarch64-android-eabi -mno-fix-cortex-a53-835769 %s -S -o- \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO --check-prefix=CHECK %s
end_comment

begin_typedef
typedef|typedef
name|long
name|int64_t
typedef|;
end_typedef

begin_function
name|int64_t
name|f_load_madd_64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|,
name|int64_t
modifier|*
name|c
parameter_list|)
block|{
name|int64_t
name|result
init|=
name|a
operator|+
name|b
operator|*
operator|(
operator|*
name|c
operator|)
decl_stmt|;
return|return
name|result
return|;
block|}
end_function

begin_comment
comment|// CHECK: ldr
end_comment

begin_comment
comment|// CHECK-YES-NEXT: nop
end_comment

begin_comment
comment|// CHECK-NO-NEXT-NOT: nop
end_comment

begin_comment
comment|// CHECK-NEXT: madd
end_comment

end_unit

