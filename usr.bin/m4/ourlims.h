begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  File   : ourlims.h     Author : Richard A. O'Keefe     Defines: UCHAR_MAX, CHAR_BIT, LONG_BIT */
end_comment

begin_comment
comment|/*  If<limits.h> is available, use that.     Otherwise, use 8-bit byte as the default.     If the number of characters is a power of 2, you might be able     to use (unsigned char)(~0), but why get fancy? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UCHAR_MAX
value|255
end_define

begin_define
define|#
directive|define
name|CHAR_BIT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LONG_BIT
value|32
end_define

end_unit

