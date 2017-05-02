begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that we split debug output properly
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gsplit-dwarf -c -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-ACTIONS< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ACTIONS: objcopy{{.*}}--extract-dwo{{.*}}"split-debug.dwo"
end_comment

begin_comment
comment|// CHECK-ACTIONS: objcopy{{.*}}--strip-dwo{{.*}}"split-debug.o"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-macosx -gsplit-dwarf -c -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-NO-ACTIONS< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NO-ACTIONS-NOT: -split-dwarf
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gsplit-dwarf -o Bad.x -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-BAD< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-BAD-NOT: "Bad.dwo"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gsplit-dwarf -c -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-OPTION< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-OPTION: "-split-dwarf-file" "split-debug.dwo"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gsplit-dwarf -S -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-ASM< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ASM-NOT: objcopy
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -no-integrated-as -gsplit-dwarf -c -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-IAS< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-IAS: objcopy
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gsplit-dwarf -gmlt -fno-split-dwarf-inlining -S -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-GMLT-WITH-SPLIT< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-GMLT-WITH-SPLIT: "-enable-split-dwarf"
end_comment

begin_comment
comment|// CHECK-GMLT-WITH-SPLIT: "-debug-info-kind=line-tables-only"
end_comment

begin_comment
comment|// CHECK-GMLT-WITH-SPLIT: "-split-dwarf-file"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -g -fno-split-dwarf-inlining -S -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-NOINLINE-WITHOUT-SPLIT< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NOINLINE-WITHOUT-SPLIT-NOT: "-enable-split-dwarf"
end_comment

begin_comment
comment|// CHECK-NOINLINE-WITHOUT-SPLIT: "-fno-split-dwarf-inlining"
end_comment

begin_comment
comment|// CHECK-NOINLINE-WITHOUT-SPLIT: "-debug-info-kind=limited"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gmlt -gsplit-dwarf -fno-split-dwarf-inlining -S -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-SPLIT-WITH-GMLT< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-SPLIT-WITH-GMLT: "-enable-split-dwarf"
end_comment

begin_comment
comment|// CHECK-SPLIT-WITH-GMLT: "-debug-info-kind=line-tables-only"
end_comment

begin_comment
comment|// CHECK-SPLIT-WITH-GMLT: "-split-dwarf-file"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gsplit-dwarf -fno-split-dwarf-inlining -S -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-SPLIT-WITH-NOINL< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-SPLIT-WITH-NOINL: "-enable-split-dwarf"
end_comment

begin_comment
comment|// CHECK-SPLIT-WITH-NOINL: "-debug-info-kind=limited"
end_comment

begin_comment
comment|// CHECK-SPLIT-WITH-NOINL: "-split-dwarf-file"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gsplit-dwarf -gmlt -S -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-GMLT-OVER-SPLIT< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-GMLT-OVER-SPLIT-NOT: "-enable-split-dwarf"
end_comment

begin_comment
comment|// CHECK-GMLT-OVER-SPLIT: "-debug-info-kind=line-tables-only"
end_comment

begin_comment
comment|// CHECK-GMLT-OVER-SPLIT-NOT: "-split-dwarf-file"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gmlt -gsplit-dwarf -S -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-SPLIT-OVER-GMLT< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-SPLIT-OVER-GMLT: "-enable-split-dwarf" "-debug-info-kind=limited"
end_comment

begin_comment
comment|// CHECK-SPLIT-OVER-GMLT: "-split-dwarf-file"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gsplit-dwarf -g0 -fno-split-dwarf-inlining -S -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-G0-OVER-SPLIT< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-G0-OVER-SPLIT-NOT: "-enable-split-dwarf"
end_comment

begin_comment
comment|// CHECK-G0-OVER-SPLIT-NOT: "-debug-info-kind
end_comment

begin_comment
comment|// CHECK-G0-OVER-SPLIT-NOT: "-split-dwarf-file"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gsplit-dwarf -g0 -S -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-G0-OVER-SPLIT< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-G0-OVER-SPLIT-NOT: "-enable-split-dwarf"
end_comment

begin_comment
comment|// CHECK-G0-OVER-SPLIT-NOT: "-debug-info-kind
end_comment

begin_comment
comment|// CHECK-G0-OVER-SPLIT-NOT: "-split-dwarf-file"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -g0 -gsplit-dwarf -S -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-SPLIT-OVER-G0< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-SPLIT-OVER-G0: "-enable-split-dwarf" "-debug-info-kind=limited"
end_comment

begin_comment
comment|// CHECK-SPLIT-OVER-G0: "-split-dwarf-file"
end_comment

end_unit

