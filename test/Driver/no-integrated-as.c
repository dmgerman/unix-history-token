begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i386 -### -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s -check-prefix NOIAS
end_comment

begin_comment
comment|// NOIAS: -no-integrated-as
end_comment

begin_comment
comment|// RUN: %clang -target i386 -### -integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s -check-prefix IAS
end_comment

begin_comment
comment|// IAS-NOT: -no-integrated-as
end_comment

begin_comment
comment|// RUN: %clang -target i386 -### -c %s 2>&1 | FileCheck %s -check-prefix DEFAULT
end_comment

begin_comment
comment|// DEFAULT-NOT: -no-integrated-as
end_comment

begin_comment
comment|// RUN: %clang -target msp430 -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s -check-prefix NO-IAS-DEFAULT
end_comment

begin_comment
comment|// NO-IAS-DEFAULT: -no-integrated-as
end_comment

end_unit

