begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)preset.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * preset.h -- preset infomation  *   by A.Fujita, Dec-12-1992  */
end_comment

begin_comment
comment|/*  * DIP SW-1  */
end_comment

begin_define
define|#
directive|define
name|PS_AUTOBOOT
value|0x01
end_define

begin_comment
comment|/* 1: PROM auto-boot */
end_comment

begin_define
define|#
directive|define
name|PS_BMC_CONS
value|0x02
end_define

begin_comment
comment|/* 2: use bitmap display as console */
end_comment

begin_define
define|#
directive|define
name|PS_BW_DISP
value|0x04
end_define

begin_comment
comment|/* 3: use B&W display (unused) */
end_comment

begin_comment
comment|/* 4: HD write verify (???) */
end_comment

begin_define
define|#
directive|define
name|PS_COFF
value|0x10
end_define

begin_comment
comment|/* 5: boot COFF format kernel */
end_comment

begin_define
define|#
directive|define
name|PS_PLAIN
value|0x20
end_define

begin_comment
comment|/* 6: number of bitmap plain (unused) */
end_comment

begin_comment
comment|/* NOTE: it has 4 plain, if turn it on, else 1 */
end_comment

begin_comment
comment|/* 7: boot device (unused) */
end_comment

begin_comment
comment|/* NOTE: it should be net-booting, if turn it on */
end_comment

begin_comment
comment|/* 8: load diagnostic program (unused) */
end_comment

end_unit

