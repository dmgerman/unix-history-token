begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -ccc-host-triple i386-apple-darwin9 -arch arm -print-search-dirs | FileCheck %s
end_comment

begin_comment
comment|// Check that we look in the relative libexec directory.
end_comment

begin_comment
comment|// CHECK: {{programs: =.*/../libexec:}}
end_comment

end_unit

