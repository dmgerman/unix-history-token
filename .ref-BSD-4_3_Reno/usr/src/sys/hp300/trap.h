begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1986, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * from: Utah $Hdr: trap.h 1.6 88/11/25$  *  *	@(#)trap.h	7.2 (Berkeley) 6/22/90  */
end_comment

begin_comment
comment|/*  * Trap type values  */
end_comment

begin_define
define|#
directive|define
name|T_BUSERR
value|0
end_define

begin_define
define|#
directive|define
name|T_ADDRERR
value|1
end_define

begin_define
define|#
directive|define
name|T_ILLINST
value|2
end_define

begin_define
define|#
directive|define
name|T_ZERODIV
value|3
end_define

begin_define
define|#
directive|define
name|T_CHKINST
value|4
end_define

begin_define
define|#
directive|define
name|T_TRAPVINST
value|5
end_define

begin_define
define|#
directive|define
name|T_PRIVINST
value|6
end_define

begin_define
define|#
directive|define
name|T_TRACE
value|7
end_define

begin_define
define|#
directive|define
name|T_MMUFLT
value|8
end_define

begin_define
define|#
directive|define
name|T_SSIR
value|9
end_define

begin_define
define|#
directive|define
name|T_FMTERR
value|10
end_define

begin_define
define|#
directive|define
name|T_FPERR
value|11
end_define

begin_define
define|#
directive|define
name|T_COPERR
value|12
end_define

begin_define
define|#
directive|define
name|T_ASTFLT
value|13
end_define

begin_define
define|#
directive|define
name|T_TRAP15
value|15
end_define

end_unit

