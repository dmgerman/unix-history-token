begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-darwin -fsyntax-only -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_t
typedef|;
end_typedef

begin_function
name|uint8_t
name|constraint_r
parameter_list|(
name|uint8_t
modifier|*
name|addr
parameter_list|)
block|{
name|uint8_t
name|byte
decl_stmt|;
asm|__asm__
specifier|volatile
asm|("ldrb %0, [%1]" : "=r" (byte) : "r" (addr) : "memory");
comment|// CHECK: warning: value size does not match register size specified by the constraint and modifier
comment|// CHECK: note: use constraint modifier "w"
comment|// CHECK: fix-it:{{.*}}:{8:26-8:28}:"%w0"
return|return
name|byte
return|;
block|}
end_function

begin_function
name|uint8_t
name|constraint_r_symbolic
parameter_list|(
name|uint8_t
modifier|*
name|addr
parameter_list|)
block|{
name|uint8_t
name|byte
decl_stmt|;
asm|__asm__
specifier|volatile
asm|("ldrb %[s0], [%[s1]]" : [s0] "=r" (byte) : [s1] "r" (addr) : "memory");
comment|// CHECK: warning: value size does not match register size specified by the constraint and modifier
comment|// CHECK: note: use constraint modifier "w"
comment|// CHECK: fix-it:{{.*}}:{19:26-19:31}:"%w[s0]"
return|return
name|byte
return|;
block|}
end_function

begin_define
define|#
directive|define
name|PERCENT
value|"%"
end_define

begin_function
name|uint8_t
name|constraint_r_symbolic_macro
parameter_list|(
name|uint8_t
modifier|*
name|addr
parameter_list|)
block|{
name|uint8_t
name|byte
decl_stmt|;
asm|__asm__
specifier|volatile
asm|("ldrb "PERCENT"[s0], [%[s1]]" : [s0] "=r" (byte) : [s1] "r" (addr) : "memory");
comment|// CHECK: warning: value size does not match register size specified by the constraint and modifier
comment|// CHECK: note: use constraint modifier "w"
comment|// CHECK-NOT: fix-it
return|return
name|byte
return|;
block|}
end_function

end_unit

