begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_define
define|#
directive|define
name|atof
value|sun_atof
end_define

begin_define
define|#
directive|define
name|strtod
value|sun_strtod
end_define

begin_empty
empty|#include_next "floatingpoint.h"
end_empty

begin_undef
undef|#
directive|undef
name|atof
end_undef

begin_undef
undef|#
directive|undef
name|strtod
end_undef

end_unit

