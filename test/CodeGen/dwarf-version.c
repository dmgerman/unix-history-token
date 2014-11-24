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
comment|// RUN: %clang -target x86_64-linux-gnu -g -S -emit-llvm -o - %s | FileCheck %s --check-prefix=VER4
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -g -S -emit-llvm -o - %s | FileCheck %s --check-prefix=VER2
end_comment

begin_comment
comment|// RUN: %clang -target powerpc-unknown-openbsd -g -S -emit-llvm -o - %s | FileCheck %s --check-prefix=VER2
end_comment

begin_comment
comment|// RUN: %clang -target powerpc-unknown-freebsd -g -S -emit-llvm -o - %s | FileCheck %s --check-prefix=VER2
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
comment|// VER2: metadata !{i32 2, metadata !"Dwarf Version", i32 2}
end_comment

begin_comment
comment|// VER3: metadata !{i32 2, metadata !"Dwarf Version", i32 3}
end_comment

begin_comment
comment|// VER4: metadata !{i32 2, metadata !"Dwarf Version", i32 4}
end_comment

end_unit

