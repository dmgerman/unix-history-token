begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)ctlreg.h	7.4 (Berkeley) %G%  *  * from: $Header: ctlreg.h,v 1.6 93/04/27 14:29:07 torek Exp $  */
end_comment

begin_comment
comment|/*  * Sun-4 (sort of) and 4c (Campus, i.e., SparcStation) control registers  * (includes address space definitions and registers in control space).  *  * Address space identifiers are 8 bits (0 through 255), but we  * only use four of them.  */
end_comment

begin_comment
comment|/*			0	   unused */
end_comment

begin_comment
comment|/*			1	   unused */
end_comment

begin_define
define|#
directive|define
name|ASI_CONTROL
value|2
end_define

begin_comment
comment|/* cache enable, context reg, etc */
end_comment

begin_define
define|#
directive|define
name|ASI_SEGMAP
value|3
end_define

begin_comment
comment|/* segment maps (so we can reach each pmeg) */
end_comment

begin_define
define|#
directive|define
name|ASI_PTE
value|4
end_define

begin_comment
comment|/* PTE space (pmegs) */
end_comment

begin_define
define|#
directive|define
name|ASI_HWFLUSHSEG
value|5
end_define

begin_comment
comment|/* hardware assisted version of FLUSHSEG */
end_comment

begin_define
define|#
directive|define
name|ASI_HWFLUSHPG
value|6
end_define

begin_comment
comment|/* hardware assisted version of FLUSHPG */
end_comment

begin_define
define|#
directive|define
name|ASI_HWFLUSHCTX
value|7
end_define

begin_comment
comment|/* hardware assisted version of FLUSHCTX */
end_comment

begin_define
define|#
directive|define
name|ASI_USERI
value|8
end_define

begin_comment
comment|/* I-space (user) */
end_comment

begin_define
define|#
directive|define
name|ASI_KERNELI
value|9
end_define

begin_comment
comment|/* I-space (kernel) */
end_comment

begin_define
define|#
directive|define
name|ASI_USERD
value|10
end_define

begin_comment
comment|/* D-space (user) */
end_comment

begin_define
define|#
directive|define
name|ASI_KERNELD
value|11
end_define

begin_comment
comment|/* D-space (kernel) */
end_comment

begin_define
define|#
directive|define
name|ASI_FLUSHSEG
value|12
end_define

begin_comment
comment|/* causes hardware to flush cache segment */
end_comment

begin_define
define|#
directive|define
name|ASI_FLUSHPG
value|13
end_define

begin_comment
comment|/* causes hardware to flush cache page */
end_comment

begin_define
define|#
directive|define
name|ASI_FLUSHCTX
value|14
end_define

begin_comment
comment|/* causes hardware to flush cache context */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUN4
end_ifdef

begin_define
define|#
directive|define
name|ASI_DCACHE
value|15
end_define

begin_comment
comment|/* flush data cache; not used on 4c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 16 through 255 unused (and probably wrap, but who cares?) */
end_comment

begin_comment
comment|/* registers in the control space */
end_comment

begin_define
define|#
directive|define
name|AC_CONTEXT
value|0x30000000
end_define

begin_comment
comment|/* context register (byte) */
end_comment

begin_define
define|#
directive|define
name|AC_SYSENABLE
value|0x40000000
end_define

begin_comment
comment|/* system enable register (byte) */
end_comment

begin_define
define|#
directive|define
name|AC_CACHETAGS
value|0x80000000
end_define

begin_comment
comment|/* cache tag base address */
end_comment

begin_define
define|#
directive|define
name|AC_SERIAL
value|0xf0000000
end_define

begin_comment
comment|/* special serial port sneakiness */
end_comment

begin_comment
comment|/* AC_SERIAL is not used in the kernel (it is for the PROM) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUN4
end_ifdef

begin_define
define|#
directive|define
name|AC_DVMA_ENABLE
value|0x50000000
end_define

begin_comment
comment|/* enable user dvma */
end_comment

begin_define
define|#
directive|define
name|AC_BUS_ERR
value|0x60000000
end_define

begin_comment
comment|/* bus error register */
end_comment

begin_define
define|#
directive|define
name|AC_DIAG_REG
value|0x70000000
end_define

begin_comment
comment|/* diagnostic reg */
end_comment

begin_define
define|#
directive|define
name|AC_DVMA_MAP
value|0xd0000000
end_define

begin_comment
comment|/* user dvma map entries */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SUN4C
end_ifdef

begin_define
define|#
directive|define
name|AC_SYNC_ERR
value|0x60000000
end_define

begin_comment
comment|/* sync (memory) error reg */
end_comment

begin_define
define|#
directive|define
name|AC_SYNC_VA
value|0x60000004
end_define

begin_comment
comment|/* sync error virtual addr */
end_comment

begin_define
define|#
directive|define
name|AC_ASYNC_ERR
value|0x60000008
end_define

begin_comment
comment|/* async error reg */
end_comment

begin_define
define|#
directive|define
name|AC_ASYNC_VA
value|0x6000000c
end_define

begin_comment
comment|/* async error virtual addr */
end_comment

begin_define
define|#
directive|define
name|AC_CACHEDATA
value|0x90000000
end_define

begin_comment
comment|/* cached data */
end_comment

begin_comment
comment|/*  * Bits in sync error register.  Reading the register clears these;  * otherwise they accumulate.  The error(s) occurred at the virtual  * address stored in the sync error address register, and may have  * been due to, e.g., what would usually be called a page fault.  * Worse, the bits accumulate during instruction prefetch, so  * various bits can be on that should be off.  */
end_comment

begin_define
define|#
directive|define
name|SER_WRITE
value|0x8000
end_define

begin_comment
comment|/* error occurred during write */
end_comment

begin_define
define|#
directive|define
name|SER_INVAL
value|0x80
end_define

begin_comment
comment|/* PTE had PG_V off */
end_comment

begin_define
define|#
directive|define
name|SER_PROT
value|0x40
end_define

begin_comment
comment|/* operation violated PTE prot */
end_comment

begin_define
define|#
directive|define
name|SER_TIMEOUT
value|0x20
end_define

begin_comment
comment|/* bus timeout (non-existent mem) */
end_comment

begin_define
define|#
directive|define
name|SER_SBUSERR
value|0x10
end_define

begin_comment
comment|/* S-Bus bus error */
end_comment

begin_define
define|#
directive|define
name|SER_MEMERR
value|0x08
end_define

begin_comment
comment|/* memory ecc/parity error */
end_comment

begin_define
define|#
directive|define
name|SER_SZERR
value|0x02
end_define

begin_comment
comment|/* size error, whatever that is */
end_comment

begin_define
define|#
directive|define
name|SER_WATCHDOG
value|0x01
end_define

begin_comment
comment|/* watchdog reset (never see this) */
end_comment

begin_define
define|#
directive|define
name|SER_BITS
define|\
value|"\20\20WRITE\10INVAL\7PROT\6TIMEOUT\5SBUSERR\4MEMERR\2SZERR\1WATCHDOG"
end_define

begin_comment
comment|/*  * Bits in async error register (errors from DVMA or Sun-4 cache  * writeback).  The corresponding bit is also set in the sync error reg.  *  * A writeback invalid error means there is a bug in the PTE manager.  *  * The word is that the async error register does not work right.  */
end_comment

begin_define
define|#
directive|define
name|AER_WBINVAL
value|0x80
end_define

begin_comment
comment|/* writeback found PTE without PG_V */
end_comment

begin_define
define|#
directive|define
name|AER_TIMEOUT
value|0x20
end_define

begin_comment
comment|/* bus timeout */
end_comment

begin_define
define|#
directive|define
name|AER_DVMAERR
value|0x10
end_define

begin_comment
comment|/* bus error during DVMA */
end_comment

begin_define
define|#
directive|define
name|AER_BITS
value|"\20\10WBINVAL\6TIMEOUT\5DVMAERR"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUN4C */
end_comment

begin_comment
comment|/*  * Bits in system enable register.  */
end_comment

begin_define
define|#
directive|define
name|SYSEN_DVMA
value|0x20
end_define

begin_comment
comment|/* enable dvma */
end_comment

begin_define
define|#
directive|define
name|SYSEN_CACHE
value|0x10
end_define

begin_comment
comment|/* enable cache */
end_comment

begin_define
define|#
directive|define
name|SYSEN_RESET
value|0x04
end_define

begin_comment
comment|/* reset the hardware */
end_comment

end_unit

