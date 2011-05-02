begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that we run dsymutil properly with multiple -arch options.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-apple-darwin10 -ccc-print-phases \
end_comment

begin_comment
comment|// RUN:   -arch i386 -arch x86_64 %s -g 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-MULTIARCH-ACTIONS< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-MULTIARCH-ACTIONS: 0: input, "{{.*}}darwin-dsymutil.c", c
end_comment

begin_comment
comment|// CHECK-MULTIARCH-ACTIONS: 1: preprocessor, {0}, cpp-output
end_comment

begin_comment
comment|// CHECK-MULTIARCH-ACTIONS: 2: compiler, {1}, assembler
end_comment

begin_comment
comment|// CHECK-MULTIARCH-ACTIONS: 3: assembler, {2}, object
end_comment

begin_comment
comment|// CHECK-MULTIARCH-ACTIONS: 4: linker, {3}, image
end_comment

begin_comment
comment|// CHECK-MULTIARCH-ACTIONS: 5: bind-arch, "i386", {4}, image
end_comment

begin_comment
comment|// CHECK-MULTIARCH-ACTIONS: 6: bind-arch, "x86_64", {4}, image
end_comment

begin_comment
comment|// CHECK-MULTIARCH-ACTIONS: 7: lipo, {5, 6}, image
end_comment

begin_comment
comment|// CHECK-MULTIARCH-ACTIONS: 8: dsymutil, {7}, dSYM
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-apple-darwin10 -ccc-print-bindings \
end_comment

begin_comment
comment|// RUN:   -arch i386 -arch x86_64 %s -g 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-MULTIARCH-BINDINGS< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-MULTIARCH-BINDINGS: "x86_64-apple-darwin10" - "darwin::Lipo", inputs: [{{.*}}, {{.*}}], output: "a.out"
end_comment

begin_comment
comment|// CHECK-MULTIARCH-BINDINGS: # "x86_64-apple-darwin10" - "darwin::Dsymutil", inputs: ["a.out"], output: "a.out.dSYM"
end_comment

begin_comment
comment|// Check output name derivation.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-apple-darwin10 -ccc-print-bindings \
end_comment

begin_comment
comment|// RUN:   -o foo %s -g 2> %t
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
comment|// Check that we only use dsymutil when needed.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: touch %t.o
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-apple-darwin10 -ccc-print-bindings \
end_comment

begin_comment
comment|// RUN:   -o foo %t.o -g 2> %t
end_comment

begin_comment
comment|// RUN: grep "Dsymutil" %t | count 0
end_comment

begin_comment
comment|// Check that we put the .dSYM in the right place.
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-apple-darwin10 -ccc-print-bindings \
end_comment

begin_comment
comment|// RUN:   -o bar/foo %s -g 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-LOCATION< %t %s
end_comment

begin_comment
comment|// CHECK-LOCATION: "x86_64-apple-darwin10" - "darwin::Dsymutil", inputs: ["bar/foo"], output: "bar/foo.dSYM"
end_comment

end_unit

