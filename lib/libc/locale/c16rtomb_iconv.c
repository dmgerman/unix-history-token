begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_define
define|#
directive|define
name|charXX_t
value|char16_t
end_define

begin_define
define|#
directive|define
name|cXXrtomb
value|c16rtomb
end_define

begin_define
define|#
directive|define
name|cXXrtomb_l
value|c16rtomb_l
end_define

begin_define
define|#
directive|define
name|SRCBUF_LEN
value|2
end_define

begin_define
define|#
directive|define
name|UTF_XX_INTERNAL
value|"UTF-16-INTERNAL"
end_define

begin_include
include|#
directive|include
file|"cXXrtomb_iconv.h"
end_include

end_unit

