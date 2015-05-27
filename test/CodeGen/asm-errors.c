begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: true
end_comment

begin_comment
comment|// UN: not %clang_cc1 -triple i386-apple-darwin10 -emit-obj %s -o /dev/null> %t 2>&1
end_comment

begin_comment
comment|// UN: FileCheck %s< %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin10 -emit-llvm-bc %s -o %t.bc
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin10 -emit-obj %t.bc -o /dev/null 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CRASH-REPORT %s
end_comment

begin_comment
comment|// CRASH-REPORT:<inline asm>:
end_comment

begin_comment
comment|// CRASH-REPORT: error: invalid instruction mnemonic 'abc'
end_comment

begin_comment
comment|// CRASH-REPORT-NOT: note: diagnostic msg:
end_comment

begin_function
name|int
name|test1
parameter_list|(
name|int
name|X
parameter_list|)
block|{
comment|// CHECK: error: invalid instruction mnemonic 'abc'
asm|__asm__ ("abc incl    %0" : "+r" (X));
return|return
name|X
return|;
block|}
end_function

end_unit

