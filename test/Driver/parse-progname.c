begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: shell, arm-registered-target
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/clang++
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/clang++3.5.0
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/clang++-3.5
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/clang++-tot
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/clang-c++
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/clang-g++
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/c++
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/foo-clang++
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/foo-clang++-3.5
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/foo-clang++3.5
end_comment

begin_comment
comment|// RUN: %T/clang++          -### %s 2>&1 | FileCheck -check-prefix=CXXMODE %s
end_comment

begin_comment
comment|// RUN: %T/clang++3.5.0     -### %s 2>&1 | FileCheck -check-prefix=CXXMODE %s
end_comment

begin_comment
comment|// RUN: %T/clang++-3.5      -### %s 2>&1 | FileCheck -check-prefix=CXXMODE %s
end_comment

begin_comment
comment|// RUN: %T/clang++-tot      -### %s 2>&1 | FileCheck -check-prefix=CXXMODE %s
end_comment

begin_comment
comment|// RUN: %T/clang-c++        -### %s 2>&1 | FileCheck -check-prefix=CXXMODE %s
end_comment

begin_comment
comment|// RUN: %T/clang-g++        -### %s 2>&1 | FileCheck -check-prefix=CXXMODE %s
end_comment

begin_comment
comment|// RUN: %T/c++              -### %s 2>&1 | FileCheck -check-prefix=CXXMODE %s
end_comment

begin_comment
comment|// RUN: %T/foo-clang++      -### %s 2>&1 | FileCheck -check-prefix=CXXMODE %s
end_comment

begin_comment
comment|// RUN: %T/foo-clang++-3.5  -### %s 2>&1 | FileCheck -check-prefix=CXXMODE %s
end_comment

begin_comment
comment|// RUN: %T/foo-clang++3.5   -### %s 2>&1 | FileCheck -check-prefix=CXXMODE %s
end_comment

begin_comment
comment|// CXXMODE: "-x" "c++"
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/clang-cl
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/cl
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/cl.exe
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/clang-cl3.5
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/clang-cl-3.5
end_comment

begin_comment
comment|// Note: use -- in front of the filename so it's not mistaken for an option on
end_comment

begin_comment
comment|// filesystems that use slashes for dir separators.
end_comment

begin_comment
comment|// RUN: %T/clang-cl         -### -- %s 2>&1 | FileCheck -check-prefix=CLMODE %s
end_comment

begin_comment
comment|// RUN: %T/cl               -### -- %s 2>&1 | FileCheck -check-prefix=CLMODE %s
end_comment

begin_comment
comment|// RUN: %T/cl.exe           -### -- %s 2>&1 | FileCheck -check-prefix=CLMODE %s
end_comment

begin_comment
comment|// RUN: %T/clang-cl3.5      -### -- %s 2>&1 | FileCheck -check-prefix=CLMODE %s
end_comment

begin_comment
comment|// RUN: %T/clang-cl-3.5     -### -- %s 2>&1 | FileCheck -check-prefix=CLMODE %s
end_comment

begin_comment
comment|// CLMODE: "-fdiagnostics-format" "msvc"
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/clang-cpp
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/cpp
end_comment

begin_comment
comment|// RUN: %T/clang-cpp        -### %s 2>&1 | FileCheck -check-prefix=CPPMODE %s
end_comment

begin_comment
comment|// RUN: %T/cpp              -### %s 2>&1 | FileCheck -check-prefix=CPPMODE %s
end_comment

begin_comment
comment|// CPPMODE: "-E"
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/cl-clang
end_comment

begin_comment
comment|// RUN: %T/cl-clang        -### %s 2>&1 | FileCheck -check-prefix=CMODE %s
end_comment

begin_comment
comment|// CMODE: "-x" "c"
end_comment

begin_comment
comment|// CMODE-NOT: "-fdiagnostics-format" "msvc"
end_comment

begin_comment
comment|// RUN: ln -fs %clang %T/arm-linux-gnueabi-clang
end_comment

begin_comment
comment|// RUN: %T/arm-linux-gnueabi-clang -### %s 2>&1 | FileCheck -check-prefix=TARGET %s
end_comment

begin_comment
comment|// TARGET: Target: arm--linux-gnueabi
end_comment

end_unit

