begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Note: %s must be preceded by --, otherwise it may be interpreted as a
end_comment

begin_comment
comment|// command-line option, e.g. on Mac where %s is commonly under /Users.
end_comment

begin_comment
comment|// RUN: %clang_cl --target=i686-windows-msvc /Gd -### -- %s 2>&1 | FileCheck --check-prefix=CDECL %s
end_comment

begin_comment
comment|// CDECL: -fdefault-calling-conv=cdecl
end_comment

begin_comment
comment|// RUN: %clang_cl --target=i686-windows-msvc /Gr -### -- %s 2>&1 | FileCheck --check-prefix=FASTCALL %s
end_comment

begin_comment
comment|// FASTCALL: -fdefault-calling-conv=fastcall
end_comment

begin_comment
comment|// RUN: %clang_cl --target=i686-windows-msvc /Gz -### -- %s 2>&1 | FileCheck --check-prefix=STDCALL %s
end_comment

begin_comment
comment|// STDCALL: -fdefault-calling-conv=stdcall
end_comment

begin_comment
comment|// RUN: %clang_cl --target=i686-windows-msvc /Gv -### -- %s 2>&1 | FileCheck --check-prefix=VECTORCALL %s
end_comment

begin_comment
comment|// VECTORCALL: -fdefault-calling-conv=vectorcall
end_comment

begin_comment
comment|// Last one should win:
end_comment

begin_comment
comment|// RUN: %clang_cl --target=i686-windows-msvc /Gd /Gv -### -- %s 2>&1 | FileCheck --check-prefix=LASTWINS_VECTOR %s
end_comment

begin_comment
comment|// LASTWINS_VECTOR: -fdefault-calling-conv=vectorcall
end_comment

begin_comment
comment|// RUN: %clang_cl --target=i686-windows-msvc /Gv /Gd -### -- %s 2>&1 | FileCheck --check-prefix=LASTWINS_CDECL %s
end_comment

begin_comment
comment|// LASTWINS_CDECL: -fdefault-calling-conv=cdecl
end_comment

begin_comment
comment|// No fastcall or stdcall on x86_64:
end_comment

begin_comment
comment|// RUN: %clang_cl -Wno-msvc-not-found --target=x86_64-windows-msvc /Gr -### -- %s 2>&1 | FileCheck --check-prefix=UNSUPPORTED %s
end_comment

begin_comment
comment|// RUN: %clang_cl -Wno-msvc-not-found --target=x86_64-windows-msvc /Gz -### -- %s 2>&1 | FileCheck --check-prefix=UNSUPPORTED %s
end_comment

begin_comment
comment|// RUN: %clang_cl -Wno-msvc-not-found --target=thumbv7-windows-msvc /Gv -### -- %s 2>&1 | FileCheck --check-prefix=UNSUPPORTED %s
end_comment

begin_comment
comment|// UNSUPPORTED-NOT: error:
end_comment

begin_comment
comment|// UNSUPPORTED-NOT: warning:
end_comment

begin_comment
comment|// UNSUPPORTED-NOT: -fdefault-calling-conv=
end_comment

end_unit

