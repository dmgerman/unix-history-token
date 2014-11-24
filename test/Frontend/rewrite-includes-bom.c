begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: grep -q $'^\xEF\xBB\xBF' %S/Inputs/rewrite-includes-bom.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -frewrite-includes -I %S/Inputs %s -o %t.c
end_comment

begin_comment
comment|// RUN: ! grep -q $'\xEF\xBB\xBF' %t.c
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %t.c
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

begin_include
include|#
directive|include
file|"rewrite-includes-bom.h"
end_include

end_unit

