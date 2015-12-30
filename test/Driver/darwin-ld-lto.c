begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: system-darwin
end_comment

begin_comment
comment|// Check that ld gets "-lto_library" and warnings about libLTO.dylib path.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %s \
end_comment

begin_comment
comment|// RUN:   -mlinker-version=133 -flto 2> %t.log
end_comment

begin_comment
comment|// RUN: cat %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_LTOLIB_PATH %s< %t.log
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// LINK_LTOLIB_PATH: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_LTOLIB_PATH: "-lto_library"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %s \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/dummytestdir -mlinker-version=133 -flto 2> %t.log
end_comment

begin_comment
comment|// RUN: cat %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_LTOLIB_PATH_WRN %s< %t.log
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// LINK_LTOLIB_PATH_WRN: warning: libLTO.dylib relative to clang installed dir not found; using 'ld' default search path instead
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %s \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/dummytestdir -mlinker-version=133 -Wno-liblto -flto 2> %t.log
end_comment

begin_comment
comment|// RUN: cat %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_LTOLIB_PATH_NOWRN %s< %t.log
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// LINK_LTOLIB_PATH_NOWRN-NOT: warning: libLTO.dylib relative to clang installed dir not found; using 'ld' default search path instead
end_comment

end_unit

