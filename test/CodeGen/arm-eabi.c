begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-eabi -S -o - %s | FileCheck -check-prefix=CHECK-EABI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-eabi -S -meabi gnu -o - %s | FileCheck -check-prefix=CHECK-GNUEABI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-eabihf -S -o - %s | FileCheck -check-prefix=CHECK-EABI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-eabihf -S -meabi gnu -o - %s | FileCheck -check-prefix=CHECK-GNUEABI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -S -o - %s | FileCheck -check-prefix=CHECK-GNUEABI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -S -meabi 5 -o - %s | FileCheck -check-prefix=CHECK-EABI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabihf -S -o - %s | FileCheck -check-prefix=CHECK-GNUEABI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabihf -S -meabi 5 -o - %s | FileCheck -check-prefix=CHECK-EABI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-musleabi -S -o - %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-GNUEABI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-musleabi -S -o - %s -meabi 5 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-EABI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-musleabihf -S -o - %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-GNUEABI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-musleabihf -S -o - %s -meabi 5 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-EABI %s
end_comment

begin_struct
struct|struct
name|my_s
block|{
name|unsigned
name|long
name|a
index|[
literal|18
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: foo
end_comment

begin_comment
comment|// CHECK-EABI: bl __aeabi_memcpy4
end_comment

begin_comment
comment|// CHECK-GNUEABI: bl memcpy
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|unsigned
name|long
modifier|*
name|t
parameter_list|)
block|{
operator|*
operator|(
expr|struct
name|my_s
operator|*
operator|)
name|t
operator|=
operator|*
operator|(
operator|(
expr|struct
name|my_s
operator|*
operator|)
operator|(
literal|1UL
operator|)
operator|)
expr_stmt|;
block|}
end_function

end_unit

