begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i686-pc-windows-msvc -### %s 2>&1 | FileCheck --check-prefix=BASIC %s
end_comment

begin_comment
comment|// BASIC: link.exe"
end_comment

begin_comment
comment|// BASIC: "-out:a.exe"
end_comment

begin_comment
comment|// BASIC: "-defaultlib:libcmt"
end_comment

begin_comment
comment|// BASIC: "-nologo"
end_comment

begin_comment
comment|// RUN: %clang -target i686-pc-windows-msvc -shared -o a.dll -### %s 2>&1 | FileCheck --check-prefix=DLL %s
end_comment

begin_comment
comment|// DLL: link.exe"
end_comment

begin_comment
comment|// DLL: "-out:a.dll"
end_comment

begin_comment
comment|// DLL: "-defaultlib:libcmt"
end_comment

begin_comment
comment|// DLL: "-nologo"
end_comment

begin_comment
comment|// DLL: "-dll"
end_comment

begin_comment
comment|// RUN: %clang -target i686-pc-windows-msvc -L/var/empty -L/usr/lib -### %s 2>&1 | FileCheck --check-prefix LIBPATH %s
end_comment

begin_comment
comment|// LIBPATH: "-libpath:/var/empty"
end_comment

begin_comment
comment|// LIBPATH: "-libpath:/usr/lib"
end_comment

begin_comment
comment|// LIBPATH: "-nologo"
end_comment

end_unit

