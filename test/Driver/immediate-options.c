begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang --help | FileCheck %s -check-prefix=HELP
end_comment

begin_comment
comment|// HELP: isystem
end_comment

begin_comment
comment|// HELP-NOT: ast-dump
end_comment

begin_comment
comment|// HELP-NOT: driver-mode
end_comment

begin_comment
comment|// RUN: %clang --help-hidden | FileCheck %s -check-prefix=HELP-HIDDEN
end_comment

begin_comment
comment|// HELP-HIDDEN: driver-mode
end_comment

begin_comment
comment|// RUN: %clang -dumpversion | FileCheck %s -check-prefix=DUMPVERSION
end_comment

begin_comment
comment|// DUMPVERSION: 4.2.1
end_comment

begin_comment
comment|// RUN: %clang -print-search-dirs | FileCheck %s -check-prefix=PRINT-SEARCH-DIRS
end_comment

begin_comment
comment|// PRINT-SEARCH-DIRS: programs: ={{.*}}
end_comment

begin_comment
comment|// PRINT-SEARCH-DIRS: libraries: ={{.*}}
end_comment

begin_comment
comment|// Test if the -print-resource-dir option is accepted without error.
end_comment

begin_comment
comment|// Allow unspecified output because the value of CLANG_RESOURCE_DIR is unknown.
end_comment

begin_comment
comment|// RUN: %clang -print-resource-dir | FileCheck %s -check-prefix=PRINT-RESOURCE-DIR
end_comment

begin_comment
comment|// PRINT-RESOURCE-DIR: {{.+}}
end_comment

end_unit

