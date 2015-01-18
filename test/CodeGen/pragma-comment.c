begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple i686-pc-win32 -fms-extensions -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-pc-win32 -fms-extensions -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i686-pc-linux -fms-extensions -emit-llvm -o - | FileCheck -check-prefix LINUX %s
end_comment

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|lib
name|,
literal|"msvcrt.lib"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|lib
name|,
literal|"kernel32"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|lib
name|,
literal|"USER32.LIB"
name|)
end_pragma

begin_define
define|#
directive|define
name|BAR
value|"2"
end_define

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|linker
name|,
literal|" /bar="
name|BAR
name|)
end_pragma

begin_comment
comment|// CHECK: !llvm.module.flags = !{{{.*}}}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{i32 6, !"Linker Options", ![[link_opts:[0-9]+]]}
end_comment

begin_comment
comment|// CHECK: ![[link_opts]] = !{![[msvcrt:[0-9]+]], ![[kernel32:[0-9]+]], ![[USER32:[0-9]+]], ![[bar:[0-9]+]]}
end_comment

begin_comment
comment|// CHECK: ![[msvcrt]] = !{!"/DEFAULTLIB:msvcrt.lib"}
end_comment

begin_comment
comment|// CHECK: ![[kernel32]] = !{!"/DEFAULTLIB:kernel32.lib"}
end_comment

begin_comment
comment|// CHECK: ![[USER32]] = !{!"/DEFAULTLIB:USER32.LIB"}
end_comment

begin_comment
comment|// CHECK: ![[bar]] = !{!" /bar=2"}
end_comment

begin_comment
comment|// LINUX: !{!"-lmsvcrt.lib"}
end_comment

begin_comment
comment|// LINUX: !{!"-lkernel32"}
end_comment

begin_comment
comment|// LINUX: !{!"-lUSER32.LIB"}
end_comment

begin_comment
comment|// LINUX: !{!" /bar=2"}
end_comment

end_unit

