begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1989 Carnegie-Mellon University  * All rights reserved.  The CMU software License Agreement specifies  * the terms and conditions for use and redistribution.  *	@(#)wtreg.h	1.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   * HISTORY  * $Log:	wtreg.h,v $  * Revision 2.2.1.1  90/01/08  13:29:25  rvb  * 	Add Intel copyright.  * 	[90/01/08            rvb]  *   * Revision 2.2  89/09/25  12:33:09  rvb  * 	Driver was provided by Intel 9/18/89.  * 	[89/09/23            rvb]  *   */
end_comment

begin_comment
comment|/*  *  *  Copyright 1988, 1989 by Intel Corporation  *  */
end_comment

begin_comment
comment|/*  *  wtioctl.h  *   defines ioctl parameters for direct QIC commands  */
end_comment

begin_define
define|#
directive|define
name|WTIOC
value|('W'<<8)
end_define

begin_define
define|#
directive|define
name|WTQICMD
value|(WTIOC|0)
end_define

begin_comment
comment|/* QIC commands allowed */
end_comment

begin_define
define|#
directive|define
name|SELECT
value|0x01
end_define

begin_define
define|#
directive|define
name|REWIND
value|0x21
end_define

begin_define
define|#
directive|define
name|ERASE
value|0x22
end_define

begin_define
define|#
directive|define
name|RETENS
value|0x24
end_define

end_unit

