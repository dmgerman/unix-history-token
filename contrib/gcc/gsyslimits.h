begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* syslimits.h stands for the system's own limits.h file.    If we can use it ok unmodified, then we install this text.    If fixincludes fixes it, then the fixed version is installed    instead of this text.  */
end_comment

begin_define
define|#
directive|define
name|_GCC_NEXT_LIMITS_H
end_define

begin_comment
comment|/* tell gcc's limits.h to recurse */
end_comment

begin_empty
empty|#include_next<limits.h>
end_empty

begin_undef
undef|#
directive|undef
name|_GCC_NEXT_LIMITS_H
end_undef

end_unit

