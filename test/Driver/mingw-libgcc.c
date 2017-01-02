begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test if mingw toolchain driver emits static linking (-lgcc -lgcc_eh) or dynamic linking (-lgcc_s -lgcc).
end_comment

begin_comment
comment|// Verified with gcc version 5.1.0 (i686-posix-dwarf-rev0, Built by MinGW-W64 project).
end_comment

begin_comment
comment|// gcc, static
end_comment

begin_comment
comment|// RUN: %clang -v -target i686-pc-windows-gnu -rtlib=platform -### %s 2>&1 | FileCheck -check-prefix=CHECK_STATIC %s
end_comment

begin_comment
comment|// RUN: %clang -static -v -target i686-pc-windows-gnu -rtlib=platform -### %s 2>&1 | FileCheck -check-prefix=CHECK_STATIC %s
end_comment

begin_comment
comment|// RUN: %clang -static-libgcc -v -target i686-pc-windows-gnu -rtlib=platform -### %s 2>&1 | FileCheck -check-prefix=CHECK_STATIC %s
end_comment

begin_comment
comment|// RUN: %clang -static -shared -v -target i686-pc-windows-gnu -rtlib=platform -### %s 2>&1 | FileCheck -check-prefix=CHECK_STATIC %s
end_comment

begin_comment
comment|// RUN: %clang -static-libgcc -shared -v -target i686-pc-windows-gnu -rtlib=platform -### %s 2>&1 | FileCheck -check-prefix=CHECK_STATIC %s
end_comment

begin_comment
comment|// gcc, dynamic
end_comment

begin_comment
comment|// RUN: %clang -shared -v -target i686-pc-windows-gnu -rtlib=platform -### %s 2>&1 | FileCheck -check-prefix=CHECK_DYNAMIC %s
end_comment

begin_comment
comment|// g++, static
end_comment

begin_comment
comment|// RUN: %clang -static --driver-mode=g++ -v -target i686-pc-windows-gnu -rtlib=platform -### %s 2>&1 | FileCheck -check-prefix=CHECK_STATIC %s
end_comment

begin_comment
comment|// RUN: %clang -static-libgcc --driver-mode=g++ -v -target i686-pc-windows-gnu -rtlib=platform -### %s 2>&1 | FileCheck -check-prefix=CHECK_STATIC %s
end_comment

begin_comment
comment|// RUN: %clang -static -shared --driver-mode=g++ -v -target i686-pc-windows-gnu -rtlib=platform -### %s 2>&1 | FileCheck -check-prefix=CHECK_STATIC %s
end_comment

begin_comment
comment|// RUN: %clang -static-libgcc -shared --driver-mode=g++ -v -target i686-pc-windows-gnu -rtlib=platform -### %s 2>&1 | FileCheck -check-prefix=CHECK_STATIC %s
end_comment

begin_comment
comment|// g++, dynamic
end_comment

begin_comment
comment|// RUN: %clang --driver-mode=g++ -v -target i686-pc-windows-gnu -rtlib=platform -### %s 2>&1 | FileCheck -check-prefix=CHECK_DYNAMIC %s
end_comment

begin_comment
comment|// RUN: %clang -shared --driver-mode=g++ -v -target i686-pc-windows-gnu -rtlib=platform -### %s 2>&1 | FileCheck -check-prefix=CHECK_DYNAMIC %s
end_comment

begin_comment
comment|// CHECK_STATIC: "-lgcc" "-lgcc_eh"
end_comment

begin_comment
comment|// CHECK_DYNAMIC: "-lgcc_s" "-lgcc"
end_comment

end_unit

