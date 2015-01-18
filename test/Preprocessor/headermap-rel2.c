begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This uses a headermap with this entry:
end_comment

begin_comment
comment|//   someheader.h -> Product/someheader.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -v -fsyntax-only %s -iquote %S/Inputs/headermap-rel2/project-headers.hmap -isystem %S/Inputs/headermap-rel2/system/usr/include -I %S/Inputs/headermap-rel2 -H
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -iquote %S/Inputs/headermap-rel2/project-headers.hmap -isystem %S/Inputs/headermap-rel2/system/usr/include -I %S/Inputs/headermap-rel2 -H 2> %t.out
end_comment

begin_comment
comment|// RUN: FileCheck %s -input-file %t.out
end_comment

begin_comment
comment|// CHECK: Product/someheader.h
end_comment

begin_comment
comment|// CHECK: system/usr/include{{[/\\]+}}someheader.h
end_comment

begin_comment
comment|// CHECK: system/usr/include{{[/\\]+}}someheader.h
end_comment

begin_include
include|#
directive|include
file|"someheader.h"
end_include

begin_include
include|#
directive|include
file|<someheader.h>
end_include

begin_include
include|#
directive|include
file|<someheader.h>
end_include

end_unit

