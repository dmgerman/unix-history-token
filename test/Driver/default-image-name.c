begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i386-unknown-linux-gnu %s -### 2>&1 | FileCheck -check-prefix=LINUX %s
end_comment

begin_comment
comment|// LINUX: a.out
end_comment

begin_comment
comment|// RUN: %clang -target i686-pc-windows-msvc %s -### 2>&1 | FileCheck -check-prefix=WIN %s
end_comment

begin_comment
comment|// RUN: %clang -target i686-pc-windows-gnu %s -### 2>&1 | FileCheck -check-prefix=WIN %s
end_comment

begin_comment
comment|// RUN: %clang -target i686-windows-gnu %s -### 2>&1 | FileCheck -check-prefix=WIN %s
end_comment

begin_comment
comment|// WIN: a.exe
end_comment

end_unit

