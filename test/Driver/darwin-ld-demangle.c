begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: system-darwin
end_comment

begin_comment
comment|// On Darwin, -demangle is passed to the linker of HOST_LINK_VERSION
end_comment

begin_comment
comment|// is high enough. It is assumed to be high enough on systems where
end_comment

begin_comment
comment|// this test gets run.
end_comment

begin_comment
comment|// RUN: %clang -### %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: -demangle
end_comment

end_unit

