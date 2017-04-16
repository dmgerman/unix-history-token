begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux -### %s -flto=full 2>&1 | FileCheck --check-prefix=UNIT %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux -### %s -flto=thin 2>&1 | FileCheck --check-prefix=UNIT %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin13.3.0 -### %s -flto=full 2>&1 | FileCheck --check-prefix=UNIT %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin13.3.0 -### %s -flto=thin 2>&1 | FileCheck --check-prefix=NOUNIT %s
end_comment

begin_comment
comment|// UNIT: "-flto-unit"
end_comment

begin_comment
comment|// NOUNIT-NOT: "-flto-unit"
end_comment

end_unit

