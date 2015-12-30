begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### %s 2>&1 | FileCheck %s -check-prefix=NO-MSBITFIELDS
end_comment

begin_comment
comment|// RUN: %clang -### -mno-ms-bitfields -mms-bitfields %s 2>&1 | FileCheck %s -check-prefix=MSBITFIELDS
end_comment

begin_comment
comment|// RUN: %clang -### -mms-bitfields -mno-ms-bitfields %s 2>&1 | FileCheck %s -check-prefix=NO-MSBITFIELDS
end_comment

begin_comment
comment|// MSBITFIELDS: -mms-bitfields
end_comment

begin_comment
comment|// NO-MSBITFIELDS-NOT: -mms-bitfields
end_comment

begin_comment
comment|// REQUIRES: clang-driver
end_comment

end_unit

