begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)kdbparam.h	7.7 (Berkeley) 5/21/88  */
end_comment

begin_define
define|#
directive|define
name|DBNAME
value|"kdb\n"
end_define

begin_define
define|#
directive|define
name|LPRMODE
value|"%R"
end_define

begin_define
define|#
directive|define
name|OFFMODE
value|"+%R"
end_define

begin_define
define|#
directive|define
name|MAXINT
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|MAXSTOR
value|(KERNBASE - ctob(UPAGES))
end_define

begin_define
define|#
directive|define
name|ENTRYMASK
value|1
end_define

begin_comment
comment|/* check for entry masks */
end_comment

begin_define
define|#
directive|define
name|ishiddenreg
parameter_list|(
name|p
parameter_list|)
value|((p)<=&reglist[8])
end_define

begin_define
define|#
directive|define
name|BPT
value|0x30
end_define

begin_define
define|#
directive|define
name|KCALL
value|0xcf
end_define

begin_define
define|#
directive|define
name|CASEL
value|0xfc
end_define

begin_define
define|#
directive|define
name|TBIT
value|0x10
end_define

begin_define
define|#
directive|define
name|KDB_IPL
value|0xf
end_define

begin_comment
comment|/* highest priority software interrupt */
end_comment

begin_define
define|#
directive|define
name|setsoftkdb
parameter_list|()
value|mtpr(SIRR, KDB_IPL)
end_define

begin_define
define|#
directive|define
name|clrsstep
parameter_list|()
value|(pcb.pcb_psl&= ~TBIT)
end_define

begin_define
define|#
directive|define
name|setsstep
parameter_list|()
value|(pcb.pcb_psl |= TBIT)
end_define

begin_define
define|#
directive|define
name|SETBP
parameter_list|(
name|ins
parameter_list|)
value|((BPT<<24) | ((ins)& 0xffffff))
end_define

begin_define
define|#
directive|define
name|getprevpc
parameter_list|(
name|fp
parameter_list|)
value|get((off_t)(fp)-8, DSP)
end_define

begin_comment
comment|/* pc of caller */
end_comment

begin_define
define|#
directive|define
name|getprevframe
parameter_list|(
name|fp
parameter_list|)
value|(get((off_t)(fp), DSP)&~3)
end_define

begin_comment
comment|/* fp of caller */
end_comment

begin_define
define|#
directive|define
name|getnargs
parameter_list|(
name|fp
parameter_list|)
value|(((get((off_t)(fp)-4, DSP)&0xffff)-4)/4)
end_define

begin_define
define|#
directive|define
name|nextarg
parameter_list|(
name|ap
parameter_list|)
value|((ap) + 4)
end_define

begin_comment
comment|/* next argument in list */
end_comment

begin_define
define|#
directive|define
name|NOFRAME
value|0
end_define

begin_comment
comment|/* fp at top of call stack */
end_comment

begin_define
define|#
directive|define
name|issignalpc
parameter_list|(
name|pc
parameter_list|)
value|((unsigned)MAXSTOR< (pc)&& (pc)< (unsigned)KERNBASE)
end_define

begin_define
define|#
directive|define
name|getsignalpc
parameter_list|(
name|fp
parameter_list|)
value|get((off_t)(fp)+44, DSP)
end_define

begin_comment
comment|/* pc of caller before signal */
end_comment

begin_define
define|#
directive|define
name|leng
parameter_list|(
name|a
parameter_list|)
value|((long)((unsigned)(a)))
end_define

begin_define
define|#
directive|define
name|shorten
parameter_list|(
name|a
parameter_list|)
value|(((a)>> 16)& 0xffff)
end_define

begin_define
define|#
directive|define
name|itol
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((long)(((a)<< 16) | ((b)& 0xffff)))
end_define

begin_define
define|#
directive|define
name|byte
parameter_list|(
name|a
parameter_list|)
value|(((a)>> 24)& 0xff)
end_define

begin_define
define|#
directive|define
name|btol
parameter_list|(
name|a
parameter_list|)
value|((long)((a)<< 24))
end_define

begin_comment
comment|/* check for address wrap around */
end_comment

begin_define
define|#
directive|define
name|addrwrap
parameter_list|(
name|oaddr
parameter_list|,
name|newaddr
parameter_list|)
define|\
value|(((oaddr)^(newaddr))>> 24)
end_define

begin_comment
comment|/*  * INSTACK tells whether its argument is a stack address.  * INUDOT tells whether its argument is in the (extended) u. area.  * These are used for consistency checking and dont have to be exact.  *  * INKERNEL tells whether its argument is a kernel space address.  * KVTOPH trims a kernel virtal address back to its offset  * in the kernel address space.  */
end_comment

begin_define
define|#
directive|define
name|INSTACK
parameter_list|(
name|x
parameter_list|)
value|(((int)(x)&0xf0000000) == 0xb0000000)
end_define

begin_define
define|#
directive|define
name|INUDOT
parameter_list|(
name|x
parameter_list|)
value|(((int)(x)&0xf0000000) == 0xb0000000)
end_define

begin_define
define|#
directive|define
name|INKERNEL
parameter_list|(
name|x
parameter_list|)
value|(((int)(x)&0xf0000000) == 0xc0000000)
end_define

begin_define
define|#
directive|define
name|KERNOFF
value|(KERNBASE + 0x800)
end_define

begin_comment
comment|/* start of kernel's text */
end_comment

begin_comment
comment|/* #define	KVTOPH(x)	((x)&~ 0xc0000000) sometimes */
end_comment

end_unit

