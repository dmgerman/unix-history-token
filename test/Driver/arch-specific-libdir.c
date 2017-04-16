begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that the driver adds an arch-specific subdirectory in
end_comment

begin_comment
comment|// {RESOURCE_DIR}/lib/linux to the search path.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir_with_arch_subdir \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=FILEPATH,ARCHDIR-i386 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=FILEPATH,NO-ARCHDIR %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target i686-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir_with_arch_subdir \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=FILEPATH,ARCHDIR-i386 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target i686-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=FILEPATH,NO-ARCHDIR %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target x86_64-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir_with_arch_subdir \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=FILEPATH,ARCHDIR-x86_64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target x86_64-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=FILEPATH,NO-ARCHDIR %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target arm-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir_with_arch_subdir \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=FILEPATH,ARCHDIR-arm %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target arm-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=FILEPATH,NO-ARCHDIR %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target aarch64-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir_with_arch_subdir \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=FILEPATH,ARCHDIR-aarch64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target aarch64-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=FILEPATH,NO-ARCHDIR %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FILEPATH: "-x" "c" "[[FILE_PATH:.*]]{{(/|\\\\).*}}.c"
end_comment

begin_comment
comment|// ARCHDIR-i386:    -L[[FILE_PATH]]{{(/|\\\\)Inputs(/|\\\\)resource_dir_with_arch_subdir(/|\\\\)lib(/|\\\\)linux(/|\\\\)i386}}
end_comment

begin_comment
comment|// ARCHDIR-x86_64:  -L[[FILE_PATH]]{{(/|\\\\)Inputs(/|\\\\)resource_dir_with_arch_subdir(/|\\\\)lib(/|\\\\)linux(/|\\\\)x86_64}}
end_comment

begin_comment
comment|// ARCHDIR-arm:     -L[[FILE_PATH]]{{(/|\\\\)Inputs(/|\\\\)resource_dir_with_arch_subdir(/|\\\\)lib(/|\\\\)linux(/|\\\\)arm}}
end_comment

begin_comment
comment|// ARCHDIR-aarch64: -L[[FILE_PATH]]{{(/|\\\\)Inputs(/|\\\\)resource_dir_with_arch_subdir(/|\\\\)lib(/|\\\\)linux(/|\\\\)aarch64}}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Have a stricter check for no-archdir - that the driver doesn't add any
end_comment

begin_comment
comment|// subdirectory from the provided resource directory.
end_comment

begin_comment
comment|// NO-ARCHDIR-NOT: -L[[FILE_PATH]]/Inputs/resource_dir
end_comment

end_unit

