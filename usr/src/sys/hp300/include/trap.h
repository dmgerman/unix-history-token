begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1986, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: trap.h 1.7 91/03/25$  *  *	@(#)trap.h	7.6 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Trap codes  */
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

begin_define
define|#
directive|define
name|T_FPEMULI
value|16
end_define

begin_define
define|#
directive|define
name|T_FPEMULD
value|17
end_define

begin_define
define|#
directive|define
name|T_USER
value|0x80
end_define

begin_comment
comment|/* user-mode flag or'ed with type */
end_comment

end_unit

