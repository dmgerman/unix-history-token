begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)vaddrs.h	7.3 (Berkeley) %G%  *  * from: $Header: vaddrs.h,v 1.3 92/11/26 03:05:11 torek Exp $  */
end_comment

begin_comment
comment|/*  * Special (fixed) virtual addresses on the SPARC.  *  * IO virtual space begins at 0xfe000000 (a segment boundary) and  * continues up to the DMVA edge at 0xff000000.  (The upper all-1s  * byte is special since some of the hardware supplies this to pad  * a 24-bit address space out to 32 bits.  This is a legacy of the  * IBM PC AT bus, actually, just so you know who to blame.)  *  * We reserve several pages at the base of our IO virtual space  * for `oft-used' devices which must be present anyway in order to  * configure.  In particular, we want the counter-timer register and  * the Zilog ZSCC serial port chips to be mapped at fixed VAs to make  * microtime() and the zs hardware interrupt handlers faster.  *  * Ideally, we should map the interrupt enable register here as well,  * but that would require allocating pmegs in locore.s, so instead we  * use one of the two `wasted' pages at KERNBASE+2*NBPG (see locore.s).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IODEV_0
end_ifndef

begin_define
define|#
directive|define
name|IODEV_0
value|0xfe000000
end_define

begin_comment
comment|/* must match VM_MAX_KERNEL_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|TIMERREG_VA
value|(IODEV_0 + 0*NBPG)
end_define

begin_define
define|#
directive|define
name|ZS0_VA
value|(IODEV_0 + 1*NBPG)
end_define

begin_define
define|#
directive|define
name|ZS1_VA
value|(IODEV_0 + 2*NBPG)
end_define

begin_define
define|#
directive|define
name|AUXREG_VA
value|(IODEV_0 + 3*NBPG)
end_define

begin_define
define|#
directive|define
name|IODEV_BASE
value|(IODEV_0 + 4*NBPG)
end_define

begin_define
define|#
directive|define
name|IODEV_END
value|0xff000000
end_define

begin_comment
comment|/* 16 MB of iospace */
end_comment

begin_define
define|#
directive|define
name|DVMA_BASE
value|0xfff00000
end_define

begin_define
define|#
directive|define
name|DVMA_END
value|0xfffc0000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IODEV_0 */
end_comment

end_unit

