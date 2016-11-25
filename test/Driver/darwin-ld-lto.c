begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: system-darwin
end_comment

begin_comment
comment|// Check that ld gets "-lto_library".
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %s \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %T/bin -mlinker-version=133 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_LTOLIB_PATH %s -input-file %t.log
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
comment|// Also pass -lto_library even if the file doesn't exist; if it's needed at
end_comment

begin_comment
comment|// link time, ld will complain instead.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %s \
end_comment

begin_comment
comment|// RUN:   -ccc-install-dir %S/dummytestdir -mlinker-version=133 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINK_LTOLIB_PATH %s -input-file %t.log
end_comment

end_unit

