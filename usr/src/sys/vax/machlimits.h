begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)machlimits.h	7.2 (Berkeley) 6/28/90  */
end_comment

begin_define
define|#
directive|define
name|CHAR_BIT
value|8
end_define

begin_comment
comment|/* number of bits in a char */
end_comment

begin_define
define|#
directive|define
name|CLK_TCK
value|60
end_define

begin_comment
comment|/* ticks per second */
end_comment

begin_define
define|#
directive|define
name|MB_LEN_MAX
value|1
end_define

begin_comment
comment|/* no multibyte characters */
end_comment

begin_define
define|#
directive|define
name|SCHAR_MIN
value|0x80
end_define

begin_comment
comment|/* max value for a signed char */
end_comment

begin_define
define|#
directive|define
name|SCHAR_MAX
value|0x7f
end_define

begin_comment
comment|/* min value for a signed char */
end_comment

begin_define
define|#
directive|define
name|UCHAR_MAX
value|0xff
end_define

begin_comment
comment|/* max value for an unsigned char */
end_comment

begin_define
define|#
directive|define
name|CHAR_MAX
value|0x7f
end_define

begin_comment
comment|/* max value for a char */
end_comment

begin_define
define|#
directive|define
name|CHAR_MIN
value|0x80
end_define

begin_comment
comment|/* min value for a char */
end_comment

begin_define
define|#
directive|define
name|USHRT_MAX
value|0xffff
end_define

begin_comment
comment|/* max value for an unsigned short */
end_comment

begin_define
define|#
directive|define
name|SHRT_MAX
value|0x7fff
end_define

begin_comment
comment|/* max value for a short */
end_comment

begin_define
define|#
directive|define
name|SHRT_MIN
value|0x8000
end_define

begin_comment
comment|/* min value for a short */
end_comment

begin_define
define|#
directive|define
name|UINT_MAX
value|0xffffffff
end_define

begin_comment
comment|/* max value for an unsigned int */
end_comment

begin_define
define|#
directive|define
name|INT_MAX
value|0x7fffffff
end_define

begin_comment
comment|/* max value for an int */
end_comment

begin_define
define|#
directive|define
name|INT_MIN
value|0x80000000
end_define

begin_comment
comment|/* min value for an int */
end_comment

begin_define
define|#
directive|define
name|ULONG_MAX
value|0xffffffff
end_define

begin_comment
comment|/* max value for an unsigned long */
end_comment

begin_define
define|#
directive|define
name|LONG_MAX
value|0x7fffffff
end_define

begin_comment
comment|/* max value for a long */
end_comment

begin_define
define|#
directive|define
name|LONG_MIN
value|0x80000000
end_define

begin_comment
comment|/* min value for a long */
end_comment

end_unit

