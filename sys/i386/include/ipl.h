begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IPL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IPL_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|APIC_IO
end_ifdef

begin_include
include|#
directive|include
file|<i386/isa/apic_ipl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<i386/isa/icu_ipl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Software interrupt bit numbers in priority order.  The priority only  * determines which swi will be dispatched next; a higher priority swi  * may be dispatched when a nested h/w interrupt handler returns.  */
end_comment

begin_define
define|#
directive|define
name|SWI_TTY
value|(NHWI + 0)
end_define

begin_define
define|#
directive|define
name|SWI_NET
value|(NHWI + 1)
end_define

begin_define
define|#
directive|define
name|SWI_CAMNET
value|(NHWI + 2)
end_define

begin_define
define|#
directive|define
name|SWI_CAMBIO
value|(NHWI + 3)
end_define

begin_define
define|#
directive|define
name|SWI_VM
value|(NHWI + 4)
end_define

begin_define
define|#
directive|define
name|SWI_TQ
value|(NHWI + 5)
end_define

begin_define
define|#
directive|define
name|SWI_CLOCK
value|(NHWI + 6)
end_define

begin_define
define|#
directive|define
name|NSWI
value|7
end_define

begin_comment
comment|/*  * Corresponding interrupt-pending bits for ipending.  */
end_comment

begin_define
define|#
directive|define
name|SWI_TTY_PENDING
value|(1<< SWI_TTY)
end_define

begin_define
define|#
directive|define
name|SWI_NET_PENDING
value|(1<< SWI_NET)
end_define

begin_define
define|#
directive|define
name|SWI_CAMNET_PENDING
value|(1<< SWI_CAMNET)
end_define

begin_define
define|#
directive|define
name|SWI_CAMBIO_PENDING
value|(1<< SWI_CAMBIO)
end_define

begin_define
define|#
directive|define
name|SWI_VM_PENDING
value|(1<< SWI_VM)
end_define

begin_define
define|#
directive|define
name|SWI_TQ_PENDING
value|(1<< SWI_TQ)
end_define

begin_define
define|#
directive|define
name|SWI_CLOCK_PENDING
value|(1<< SWI_CLOCK)
end_define

begin_comment
comment|/*  * Corresponding interrupt-disable masks for cpl.  The ordering is now by  * inclusion (where each mask is considered as a set of bits).  Everything  * except SWI_CLOCK_MASK includes SWI_LOW_MASK so that softclock() and low  * priority swi's don't run while other swi handlers are running and timeout  * routines can call swi handlers.  SWI_TTY_MASK includes SWI_NET_MASK in  * case tty interrupts are processed at splsofttty() for a tty that is in  * SLIP or PPP line discipline (this is weaker than merging net_imask with  * tty_imask in isa.c - splimp() must mask hard and soft tty interrupts, but  * spltty() apparently only needs to mask soft net interrupts).  */
end_comment

begin_define
define|#
directive|define
name|SWI_TTY_MASK
value|(SWI_TTY_PENDING | SWI_LOW_MASK | SWI_NET_MASK)
end_define

begin_define
define|#
directive|define
name|SWI_CAMNET_MASK
value|(SWI_CAMNET_PENDING | SWI_LOW_MASK)
end_define

begin_define
define|#
directive|define
name|SWI_CAMBIO_MASK
value|(SWI_CAMBIO_PENDING | SWI_LOW_MASK)
end_define

begin_define
define|#
directive|define
name|SWI_NET_MASK
value|(SWI_NET_PENDING | SWI_LOW_MASK)
end_define

begin_define
define|#
directive|define
name|SWI_VM_MASK
value|(SWI_VM_PENDING | SWI_LOW_MASK)
end_define

begin_define
define|#
directive|define
name|SWI_TQ_MASK
value|(SWI_TQ_PENDING | SWI_LOW_MASK)
end_define

begin_define
define|#
directive|define
name|SWI_CLOCK_MASK
value|SWI_CLOCK_PENDING
end_define

begin_define
define|#
directive|define
name|SWI_LOW_MASK
value|(SWI_TQ_PENDING | SWI_CLOCK_MASK)
end_define

begin_define
define|#
directive|define
name|SWI_MASK
value|(~HWI_MASK)
end_define

begin_comment
comment|/*  * astpending bits  */
end_comment

begin_define
define|#
directive|define
name|AST_PENDING
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AST_RESCHED
value|0x00000002
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * cpl is preserved by interrupt handlers so it is effectively nonvolatile.  * ipending and idelayed are changed by interrupt handlers so they are  * volatile.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_comment
comment|/* in<sys/interrupt.h> until pci drivers stop hacking on them */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|bio_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* group of interrupts masked with splbio() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|unsigned
name|cpl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current priority level mask */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_decl_stmt
specifier|extern
name|unsigned
name|cil
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current INTerrupt level mask */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|volatile
name|unsigned
name|idelayed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interrupts to become pending */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|unsigned
name|ipending
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* active interrupts masked by cpl */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_comment
comment|/* in<sys/systm.h> until pci drivers stop hacking on them */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|net_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* group of interrupts masked with splimp() */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|stat_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interrupts masked with splstatclock() */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|tty_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* group of interrupts masked with spltty() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_IPL_H_ */
end_comment

end_unit

