begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: case-insensitive-filesystem
end_comment

begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: cp %S/Inputs/case-insensitive-include.h %T
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -include %s -I %T -verify
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t.pch %s -I %T
end_comment

begin_comment
comment|// Modify inode of the header.
end_comment

begin_comment
comment|// RUN: cp %T/case-insensitive-include.h %t.copy
end_comment

begin_comment
comment|// RUN: touch -r %T/case-insensitive-include.h %t.copy
end_comment

begin_comment
comment|// RUN: mv %t.copy %T/case-insensitive-include.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -include-pch %t.pch -I %T -verify
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER
end_ifndef

begin_define
define|#
directive|define
name|HEADER
end_define

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

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"Case-Insensitive-Include.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

