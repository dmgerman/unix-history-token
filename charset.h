begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1984-2017  Mark Nudelman  *  * You may distribute under the terms of either the GNU General Public  * License or the Less License, as specified in the README file.  *  * For more information, see the README file.  */
end_comment

begin_define
define|#
directive|define
name|IS_ASCII_OCTET
parameter_list|(
name|c
parameter_list|)
value|(((c)& 0x80) == 0)
end_define

begin_define
define|#
directive|define
name|IS_UTF8_TRAIL
parameter_list|(
name|c
parameter_list|)
value|(((c)& 0xC0) == 0x80)
end_define

begin_define
define|#
directive|define
name|IS_UTF8_LEAD2
parameter_list|(
name|c
parameter_list|)
value|(((c)& 0xE0) == 0xC0)
end_define

begin_define
define|#
directive|define
name|IS_UTF8_LEAD3
parameter_list|(
name|c
parameter_list|)
value|(((c)& 0xF0) == 0xE0)
end_define

begin_define
define|#
directive|define
name|IS_UTF8_LEAD4
parameter_list|(
name|c
parameter_list|)
value|(((c)& 0xF8) == 0xF0)
end_define

begin_define
define|#
directive|define
name|IS_UTF8_LEAD5
parameter_list|(
name|c
parameter_list|)
value|(((c)& 0xFC) == 0xF8)
end_define

begin_define
define|#
directive|define
name|IS_UTF8_LEAD6
parameter_list|(
name|c
parameter_list|)
value|(((c)& 0xFE) == 0xFC)
end_define

begin_define
define|#
directive|define
name|IS_UTF8_INVALID
parameter_list|(
name|c
parameter_list|)
value|(((c)& 0xFE) == 0xFE)
end_define

begin_define
define|#
directive|define
name|IS_UTF8_LEAD
parameter_list|(
name|c
parameter_list|)
value|(((c)& 0xC0) == 0xC0&& !IS_UTF8_INVALID(c))
end_define

end_unit

