begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1985 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * %sccs.include.redist.c%  *  *	@(#)fp.h	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|EXPMASK
value|0x7f800000
end_define

begin_define
define|#
directive|define
name|SIGNBIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ONE_EXP
value|0x40800000
end_define

begin_define
define|#
directive|define
name|TWO_EXP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|EXPSHIFT
value|23
end_define

begin_define
define|#
directive|define
name|HID_POS
value|24
end_define

begin_define
define|#
directive|define
name|HID_R0R1
value|24+32
end_define

begin_define
define|#
directive|define
name|CLEARHID
value|0xff7fffff
end_define

begin_define
define|#
directive|define
name|EXPSIGN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|MAX_EXP_DIF
value|55
end_define

begin_define
define|#
directive|define
name|SMAX_EXP_DIF
value|23
end_define

begin_define
define|#
directive|define
name|BIAS
value|0x80
end_define

begin_define
define|#
directive|define
name|BIASP1
value|0x81
end_define

begin_define
define|#
directive|define
name|BIASM1
value|0x7f
end_define

begin_define
define|#
directive|define
name|HUGE0
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|HUGE1
value|0xffffffff
end_define

end_unit

