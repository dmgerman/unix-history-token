begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Whether strstr must be declared even if<string.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_STRSTR
end_undef

begin_comment
comment|/* Whether fprintf must be declared even if<stdio.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_FPRINTF
end_undef

begin_comment
comment|/* Whether sbrk must be declared even if<unistd.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_SBRK
end_undef

begin_comment
comment|/* Whether getenv must be declared even if<stdlib.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_GETENV
end_undef

begin_expr_stmt
unit|@
name|TOP
expr|@
end_expr_stmt

begin_comment
comment|/* Is the type time_t defined in<time.h>?  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_TIME_T_IN_TIME_H
end_undef

begin_comment
comment|/* Is the type time_t defined in<sys/types.h>?  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_TIME_T_IN_TYPES_H
end_undef

begin_comment
comment|/* Does<utime.h> define struct utimbuf?  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GOOD_UTIME_H
end_undef

begin_comment
comment|/* Do we need to use the b modifier when opening binary files?  */
end_comment

begin_undef
undef|#
directive|undef
name|USE_BINARY_FOPEN
end_undef

end_unit

