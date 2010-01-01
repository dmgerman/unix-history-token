begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only %s
end_comment

begin_comment
comment|// PR1900
end_comment

begin_comment
comment|// This test should get a redefinition error from m_iopt.h: the MI opt
end_comment

begin_comment
comment|// shouldn't apply.
end_comment

begin_define
define|#
directive|define
name|MACRO
end_define

begin_include
include|#
directive|include
file|"mi_opt.h"
end_include

begin_undef
undef|#
directive|undef
name|MACRO
end_undef

begin_define
define|#
directive|define
name|MACRO
value||| 1
end_define

begin_include
include|#
directive|include
file|"mi_opt.h"
end_include

end_unit

