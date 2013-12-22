begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fno-stack-protector -### %s 2>&1 | FileCheck %s -check-prefix=NOSSP
end_comment

begin_comment
comment|// NOSSP-NOT: "-stack-protector" "1"
end_comment

begin_comment
comment|// NOSSP-NOT: "-stack-protector-buffer-size"
end_comment

begin_comment
comment|// RUN: %clang -fstack-protector -### %s 2>&1 | FileCheck %s -check-prefix=SSP
end_comment

begin_comment
comment|// SSP: "-stack-protector" "1"
end_comment

begin_comment
comment|// SSP-NOT: "-stack-protector-buffer-size"
end_comment

begin_comment
comment|// RUN: %clang -fstack-protector --param ssp-buffer-size=16 -### %s 2>&1 | FileCheck %s -check-prefix=SSP-BUF
end_comment

begin_comment
comment|// SSP-BUF: "-stack-protector" "1"
end_comment

begin_comment
comment|// SSP-BUF: "-stack-protector-buffer-size" "16"
end_comment

begin_comment
comment|// RUN: %clang -target i386-pc-openbsd -### %s 2>&1 | FileCheck %s -check-prefix=OPENBSD
end_comment

begin_comment
comment|// OPENBSD: "-stack-protector" "1"
end_comment

begin_comment
comment|// RUN: %clang -target i386-pc-openbsd -fno-stack-protector -### %s 2>&1 | FileCheck %s -check-prefix=OPENBSD_OFF
end_comment

begin_comment
comment|// OPENBSD_OFF-NOT: "-stack-protector"
end_comment

end_unit

