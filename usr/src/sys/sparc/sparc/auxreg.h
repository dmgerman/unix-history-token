begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)auxreg.h	7.3 (Berkeley) %G%  *  * from: $Header: auxreg.h,v 1.8 92/11/26 03:04:45 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Sun-4c Auxiliary I/O register.  This register talks to the floppy  * (if it exists) and the front-panel LED.  */
end_comment

begin_define
define|#
directive|define
name|AUXIO_MB1
value|0xf0
end_define

begin_comment
comment|/* must be set on write */
end_comment

begin_define
define|#
directive|define
name|AUXIO_FHD
value|0x20
end_define

begin_comment
comment|/* floppy: high density (unreliable?)*/
end_comment

begin_define
define|#
directive|define
name|AUXIO_FDC
value|0x10
end_define

begin_comment
comment|/* floppy: diskette was changed */
end_comment

begin_define
define|#
directive|define
name|AUXIO_FDS
value|0x08
end_define

begin_comment
comment|/* floppy: drive select */
end_comment

begin_define
define|#
directive|define
name|AUXIO_FTC
value|0x04
end_define

begin_comment
comment|/* floppy: drives Terminal Count pin */
end_comment

begin_define
define|#
directive|define
name|AUXIO_FEJ
value|0x02
end_define

begin_comment
comment|/* floppy: eject disk */
end_comment

begin_define
define|#
directive|define
name|AUXIO_LED
value|0x01
end_define

begin_comment
comment|/* front panel LED */
end_comment

begin_comment
comment|/*  * We use a fixed virtual address for the register because we use it for  * timing short sections of code (via external hardware attached to the LED).  */
end_comment

begin_define
define|#
directive|define
name|AUXIO_REG
value|((volatile u_char *)(AUXREG_VA + 3))
end_define

begin_define
define|#
directive|define
name|LED_ON
value|*AUXIO_REG = AUXIO_MB1|AUXIO_FEJ|AUXIO_LED
end_define

begin_define
define|#
directive|define
name|LED_OFF
value|*AUXIO_REG = AUXIO_MB1|AUXIO_FEJ
end_define

begin_define
define|#
directive|define
name|LED_FLIP
value|*AUXIO_REG = (*AUXIO_REG | AUXIO_MB1) ^ AUXIO_LED
end_define

begin_define
define|#
directive|define
name|AUXIO_BITS
value|"\20\6FHD\5FDC\4FDS\3FTC\2FEJ\1LED"
end_define

end_unit

