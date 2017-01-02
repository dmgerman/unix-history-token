begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -gdwarf-2 -S -emit-llvm -o - %s | FileCheck %s --check-prefix=VER2
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -gdwarf-3 -S -emit-llvm -o - %s | FileCheck %s --check-prefix=VER3
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -gdwarf-4 -S -emit-llvm -o - %s | FileCheck %s --check-prefix=VER4
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -gdwarf-5 -S -emit-llvm -o - %s | FileCheck %s --check-prefix=VER5
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -g -S -emit-llvm -o - %s | FileCheck %s --check-prefix=VER4
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -gdwarf -S -emit-llvm -o - %s | FileCheck %s --check-prefix=VER4
end_comment

begin_comment
comment|// The -isysroot is used as a hack to avoid LIT messing with the SDKROOT
end_comment

begin_comment
comment|// environment variable which indirecty overrides the version in the target
end_comment

begin_comment
comment|// triple used here.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-macosx10.11 -g -S -emit-llvm -o - %s -isysroot %t | FileCheck %s --check-prefix=VER4
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin14 -g -S -emit-llvm -o - %s -isysroot %t | FileCheck %s --check-prefix=VER2
end_comment

begin_comment
comment|// RUN: %clang -target powerpc-unknown-openbsd -g -S -emit-llvm -o - %s | FileCheck %s --check-prefix=VER2
end_comment

begin_comment
comment|// RUN: %clang -target powerpc-unknown-freebsd -g -S -emit-llvm -o - %s | FileCheck %s --check-prefix=VER2
end_comment

begin_comment
comment|// RUN: %clang -target i386-pc-solaris -g -S -emit-llvm -o - %s | FileCheck %s --check-prefix=VER2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Test what -gcodeview and -gdwarf do on Windows.
end_comment

begin_comment
comment|// RUN: %clang -target i686-pc-windows-msvc -gcodeview -S -emit-llvm -o - %s | FileCheck %s --check-prefix=NODWARF --check-prefix=CODEVIEW
end_comment

begin_comment
comment|// RUN: %clang -target i686-pc-windows-msvc -gdwarf -gcodeview -S -emit-llvm -o - %s | FileCheck %s --check-prefix=VER4 --check-prefix=CODEVIEW
end_comment

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// VER2: !{i32 2, !"Dwarf Version", i32 2}
end_comment

begin_comment
comment|// VER3: !{i32 2, !"Dwarf Version", i32 3}
end_comment

begin_comment
comment|// VER4: !{i32 2, !"Dwarf Version", i32 4}
end_comment

begin_comment
comment|// VER5: !{i32 2, !"Dwarf Version", i32 5}
end_comment

begin_comment
comment|// NODWARF-NOT: !"Dwarf Version"
end_comment

begin_comment
comment|// CODEVIEW: !{i32 2, !"CodeView", i32 1}
end_comment

begin_comment
comment|// NODWARF-NOT: !"Dwarf Version"
end_comment

end_unit

