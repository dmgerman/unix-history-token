begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin9 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-REG
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin9 -fpcc-struct-return -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-PCC
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin9 -freg-struct-return -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-REG
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-linux-gnu -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-PCC
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-linux-gnu -fpcc-struct-return -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-PCC
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-linux-gnu -freg-struct-return -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-REG
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-win32 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-REG
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-win32 -fpcc-struct-return -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-PCC
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-win32 -freg-struct-return -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-REG
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|;
block|}
name|Big
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|i
decl_stmt|;
block|}
name|Small
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|s
decl_stmt|;
block|}
name|Short
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{ }
name|ZeroSized
typedef|;
end_typedef

begin_comment
comment|// CHECK-LABEL: define void @returnBig
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|Big
name|returnBig
parameter_list|(
name|Big
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-PCC-LABEL: define void @returnSmall
end_comment

begin_comment
comment|// CHECK-PCC: ret void
end_comment

begin_comment
comment|// CHECK-REG-LABEL: define i32 @returnSmall
end_comment

begin_comment
comment|// CHECK-REG: ret i32
end_comment

begin_function
name|Small
name|returnSmall
parameter_list|(
name|Small
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-PCC-LABEL: define void @returnShort
end_comment

begin_comment
comment|// CHECK-PCC: ret void
end_comment

begin_comment
comment|// CHECK-REG-LABEL: define i16 @returnShort
end_comment

begin_comment
comment|// CHECK-REG: ret i16
end_comment

begin_function
name|Short
name|returnShort
parameter_list|(
name|Short
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @returnZero()
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|ZeroSized
name|returnZero
parameter_list|(
name|ZeroSized
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

end_unit

