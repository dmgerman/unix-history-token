begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instr-generate -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name preprocessor.c %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: func
end_comment

begin_function
name|void
name|func
parameter_list|()
block|{
comment|// CHECK: File 0, [[@LINE]]:13 -> [[@LINE+5]]:2 = #0 (HasCodeBefore = 0)
name|int
name|i
init|=
literal|0
decl_stmt|;
ifdef|#
directive|ifdef
name|MACRO
comment|// CHECK-NEXT: Skipped,File 0, [[@LINE]]:2 -> [[@LINE+2]]:2 = 0 (HasCodeBefore = 0)
name|int
name|x
init|=
name|i
decl_stmt|;
endif|#
directive|endif
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|int g = 0;    void bar() { }
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK: main
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:12 -> [[@LINE+19]]:2 = #0 (HasCodeBefore = 0)
name|int
name|i
init|=
literal|0
decl_stmt|;
if|#
directive|if
literal|0
comment|// CHECK-NEXT: Skipped,File 0, [[@LINE]]:2 -> [[@LINE+4]]:2 = 0 (HasCodeBefore = 0)
block|if(i == 0) {     i = 1;   }
endif|#
directive|endif
if|#
directive|if
literal|1
if|if
condition|(
name|i
operator|==
literal|0
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:14 -> [[@LINE+2]]:4 = #1 (HasCodeBefore = 0)
name|i
operator|=
literal|1
expr_stmt|;
block|}
else|#
directive|else
comment|// CHECK-NEXT: Skipped,File 0, [[@LINE]]:2 -> [[@LINE+5]]:2 = 0 (HasCodeBefore = 0)
if|if
condition|(
name|i
operator|==
literal|1
condition|)
block|{
name|i
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_return
return|return
literal|0
return|;
end_return

unit|}
end_unit

