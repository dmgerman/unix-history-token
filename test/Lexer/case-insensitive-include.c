begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: case-insensitive-filesystem
end_comment

begin_comment
comment|// RUN: mkdir -p %T/apath
end_comment

begin_comment
comment|// RUN: mkdir -p %T/asystempath
end_comment

begin_comment
comment|// RUN: cp %S/Inputs/case-insensitive-include.h %T
end_comment

begin_comment
comment|// RUN: cp %S/Inputs/case-insensitive-include.h %T/asystempath/case-insensitive-include2.h
end_comment

begin_comment
comment|// RUN: cd %T
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -include %s -I %T -isystem %T/asystempath -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fdiagnostics-parseable-fixits %s -include %s -I %T -isystem %T/asystempath 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// Known standard header, so warn:
end_comment

begin_include
include|#
directive|include
file|<StdDef.h>
end_include

begin_comment
comment|// expected-warning {{non-portable path}}
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:10-[[@LINE-1]]:20}:"<stddef.h>"
end_comment

begin_include
include|#
directive|include
file|"case-insensitive-include.h"
end_include

begin_include
include|#
directive|include
file|"Case-Insensitive-Include.h"
end_include

begin_comment
comment|// expected-warning {{non-portable path}}
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:10-[[@LINE-1]]:38}:"\"case-insensitive-include.h\""
end_comment

begin_include
include|#
directive|include
file|"../Output/./case-insensitive-include.h"
end_include

begin_include
include|#
directive|include
file|"../Output/./Case-Insensitive-Include.h"
end_include

begin_comment
comment|// expected-warning {{non-portable path}}
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:10-[[@LINE-1]]:50}:"\"../Output/./case-insensitive-include.h\""
end_comment

begin_include
include|#
directive|include
file|"../output/./case-insensitive-include.h"
end_include

begin_comment
comment|// expected-warning {{non-portable path}}
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:10-[[@LINE-1]]:50}:"\"../Output/./case-insensitive-include.h\""
end_comment

begin_include
include|#
directive|include
file|"apath/.././case-insensitive-include.h"
end_include

begin_include
include|#
directive|include
file|"apath/.././Case-Insensitive-Include.h"
end_include

begin_comment
comment|// expected-warning {{non-portable path}}
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:10-[[@LINE-1]]:49}:"\"apath/.././case-insensitive-include.h\""
end_comment

begin_include
include|#
directive|include
file|"APath/.././case-insensitive-include.h"
end_include

begin_comment
comment|// For the sake of efficiency, this case is not diagnosed. :-(
end_comment

begin_include
include|#
directive|include
file|"../Output/./apath/.././case-insensitive-include.h"
end_include

begin_include
include|#
directive|include
file|"../Output/./APath/.././case-insensitive-include.h"
end_include

begin_comment
comment|// For the sake of efficiency, this case is not diagnosed. :-(
end_comment

begin_include
include|#
directive|include
file|"../output/./apath/.././case-insensitive-include.h"
end_include

begin_comment
comment|// expected-warning {{non-portable path}}
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:10-[[@LINE-1]]:61}:"\"../Output/./apath/.././case-insensitive-include.h\""
end_comment

begin_include
include|#
directive|include
file|"CASE-INSENSITIVE-INCLUDE2.H"
end_include

begin_comment
comment|// Found in an -isystem directory. No warning.
end_comment

end_unit

