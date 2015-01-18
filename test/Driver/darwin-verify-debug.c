begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that we verify debug output properly with multiple -arch options.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -ccc-print-phases \
end_comment

begin_comment
comment|// RUN:   --verify-debug-info -arch i386 -arch x86_64 %s -g 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-MULTIARCH-ACTIONS< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-MULTIARCH-ACTIONS: 0: input, "{{.*}}darwin-verify-debug.c", c
end_comment

begin_comment
comment|// CHECK-MULTIARCH-ACTIONS: 9: dsymutil, {8}, dSYM
end_comment

begin_comment
comment|// CHECK-MULTIARCH-ACTIONS: 10: verify-debug-info, {9}, none
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -ccc-print-bindings \
end_comment

begin_comment
comment|// RUN:   --verify-debug-info -arch i386 -arch x86_64 %s -g 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-MULTIARCH-BINDINGS< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-MULTIARCH-BINDINGS: # "x86_64-apple-darwin10" - "darwin::Dsymutil", inputs: ["a.out"], output: "a.out.dSYM"
end_comment

begin_comment
comment|// CHECK-MULTIARCH-BINDINGS: # "x86_64-apple-darwin10" - "darwin::VerifyDebug", inputs: ["a.out.dSYM"], output: (nothing)
end_comment

begin_comment
comment|// Check output name derivation.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -ccc-print-bindings \
end_comment

begin_comment
comment|// RUN:   --verify-debug-info -o foo %s -g 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-OUTPUT-NAME< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-OUTPUT-NAME: "x86_64-apple-darwin10" - "darwin::Link", inputs: [{{.*}}], output: "foo"
end_comment

begin_comment
comment|// CHECK-OUTPUT-NAME: "x86_64-apple-darwin10" - "darwin::Dsymutil", inputs: ["foo"], output: "foo.dSYM"
end_comment

begin_comment
comment|// CHECK-OUTPUT-NAME: "x86_64-apple-darwin10" - "darwin::VerifyDebug", inputs: ["foo.dSYM"], output: (nothing)
end_comment

begin_comment
comment|// Check that we only verify when needed.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: touch %t.o
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -ccc-print-bindings \
end_comment

begin_comment
comment|// RUN:   --verify-debug-info -o foo %t.o -g 2> %t
end_comment

begin_comment
comment|// RUN: not grep "Verify" %t
end_comment

end_unit

