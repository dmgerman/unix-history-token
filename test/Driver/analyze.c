begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Verify that the analyzer gets the same flags as normal compilation
end_comment

begin_comment
comment|// (at least for a few key ones).
end_comment

begin_comment
comment|// RUN: env MACOSX_DEPLOYMENT_TARGET=10.5 clang -ccc-host-triple i386-apple-darwin9  -### --analyze -o /dev/null %s -msse 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t.log %s
end_comment

begin_comment
comment|// CHECK: "-analyze"
end_comment

begin_comment
comment|// CHECK: "-target-feature" "+sse"
end_comment

begin_comment
comment|// CHECK: "-fno-math-errno"
end_comment

end_unit

