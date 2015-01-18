begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instr-generate -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name casts.c %s | FileCheck %s
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK: File 0, [[@LINE]]:12 -> [[@LINE+4]]:2 = #0 (HasCodeBefore = 0)
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:41 -> [[@LINE+1]]:54 = #1 (HasCodeBefore = 0)
name|int
name|window_size
init|=
operator|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|<=
literal|2
condition|?
operator|(
name|unsigned
operator|)
literal|512
else|:
literal|1024
operator|)
decl_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:57 -> [[@LINE]]:61 = (#0 - #1) (HasCodeBefore = 0)
return|return
literal|0
return|;
block|}
end_function

end_unit

