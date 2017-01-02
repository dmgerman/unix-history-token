begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -S -fdenormal-fp-math=ieee %s -emit-llvm -o - | FileCheck %s --check-prefix=CHECK-IEEE
end_comment

begin_comment
comment|// RUN: %clang_cc1 -S -fdenormal-fp-math=preserve-sign %s -emit-llvm -o - | FileCheck %s --check-prefix=CHECK-PS
end_comment

begin_comment
comment|// RUN: %clang_cc1 -S -fdenormal-fp-math=positive-zero %s -emit-llvm -o - | FileCheck %s --check-prefix=CHECK-PZ
end_comment

begin_comment
comment|// CHECK-LABEL: main
end_comment

begin_comment
comment|// CHECK-IEEE: attributes #0 = {{.*}}"denormal-fp-math"="ieee"{{.*}}
end_comment

begin_comment
comment|// CHECK-PS: attributes #0 = {{.*}}"denormal-fp-math"="preserve-sign"{{.*}}
end_comment

begin_comment
comment|// CHECK-PZ: attributes #0 = {{.*}}"denormal-fp-math"="positive-zero"{{.*}}
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

