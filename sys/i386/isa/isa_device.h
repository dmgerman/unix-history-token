begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)isa_device.h	7.1 (Berkeley) 5/9/91  *	$Id: isa_device.h,v 1.33 1996/09/10 23:30:51 bde Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ISA_ISA_DEVICE_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_ISA_ISA_DEVICE_H_
end_define

begin_comment
comment|/*  * ISA Bus Autoconfiguration  */
end_comment

begin_define
define|#
directive|define
name|IDTVEC
parameter_list|(
name|name
parameter_list|)
value|__CONCAT(X,name)
end_define

begin_comment
comment|/*  * Type of the first (asm) part of an interrupt handler.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|inthand_t
name|__P
typedef|((
name|u_int
name|cs
typedef|,
name|u_int
name|ef
typedef|,
name|u_int
name|esp
typedef|,
name|u_int
name|ss
typedef|));
end_typedef

begin_comment
comment|/*  * Usual type of the second (C) part of an interrupt handler.  Some bogus  * ones need the arg to be the interrupt frame (and not a copy of it, which  * is all that is possible in C).  */
end_comment

begin_typedef
typedef|typedef
name|void
name|inthand2_t
name|__P
typedef|((
name|int
name|unit
typedef|));
end_typedef

begin_comment
comment|/*  * Per device structure.  *  * XXX Note:  id_conflicts should either become an array of things we're  * specifically allowed to conflict with or be subsumed into some  * more powerful mechanism for detecting and dealing with multiple types  * of non-fatal conflict.  -jkh XXX  */
end_comment

begin_struct
struct|struct
name|isa_device
block|{
name|int
name|id_id
decl_stmt|;
comment|/* device id */
name|struct
name|isa_driver
modifier|*
name|id_driver
decl_stmt|;
name|int
name|id_iobase
decl_stmt|;
comment|/* base i/o address */
name|u_short
name|id_irq
decl_stmt|;
comment|/* interrupt request */
name|short
name|id_drq
decl_stmt|;
comment|/* DMA request */
name|caddr_t
name|id_maddr
decl_stmt|;
comment|/* physical i/o memory address on bus (if any)*/
name|int
name|id_msize
decl_stmt|;
comment|/* size of i/o memory */
name|inthand2_t
modifier|*
name|id_intr
decl_stmt|;
comment|/* interrupt interface routine */
name|int
name|id_unit
decl_stmt|;
comment|/* unit number */
name|int
name|id_flags
decl_stmt|;
comment|/* flags */
name|int
name|id_scsiid
decl_stmt|;
comment|/* scsi id if needed */
name|int
name|id_alive
decl_stmt|;
comment|/* device is present */
define|#
directive|define
name|RI_FAST
value|1
comment|/* fast interrupt handler */
name|u_int
name|id_ri_flags
decl_stmt|;
comment|/* flags for register_intr() */
name|int
name|id_reconfig
decl_stmt|;
comment|/* hot eject device support (such as PCMCIA) */
name|int
name|id_enabled
decl_stmt|;
comment|/* is device enabled */
name|int
name|id_conflicts
decl_stmt|;
comment|/* we're allowed to conflict with things */
name|struct
name|isa_device
modifier|*
name|id_next
decl_stmt|;
comment|/* used in isa_devlist in userconfig() */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bits to specify the type and amount of conflict checking.  */
end_comment

begin_define
define|#
directive|define
name|CC_ATTACH
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|CC_DRQ
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|CC_IOADDR
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|CC_IRQ
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|CC_MEMADDR
value|(1<< 4)
end_define

begin_comment
comment|/*  * Per-driver structure.  *  * Each device driver defines entries for a set of routines  * as well as an array of types which are acceptable to it.  * These are used at boot time by the configuration program.  */
end_comment

begin_struct
struct|struct
name|isa_driver
block|{
name|int
argument_list|(
argument|*probe
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|isa_device
operator|*
name|idp
operator|)
argument_list|)
expr_stmt|;
comment|/* test whether device is present */
name|int
argument_list|(
argument|*attach
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|isa_device
operator|*
name|idp
operator|)
argument_list|)
expr_stmt|;
comment|/* setup driver for a device */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* device name */
name|int
name|sensitive_hw
decl_stmt|;
comment|/* true if other probes confuse us */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISA_EXTERNALLEN
value|(sizeof(struct isa_device))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|char
name|eintrnames
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of intrnames[] */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|intrcnt
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* counts for for each device and stray */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|intrnames
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string table containing device names */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
modifier|*
name|intr_countp
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointers into intrcnt[] */
end_comment

begin_decl_stmt
specifier|extern
name|inthand2_t
modifier|*
name|intr_handler
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C entry points of intr handlers */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|intr_mask
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sets of intrs masked during handling of 1 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|intr_unit
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cookies to pass to intr handlers */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|isa_device
name|isa_biotab_fdc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|isa_device
name|isa_biotab_wdc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|isa_device
name|isa_devtab_bio
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|isa_device
name|isa_devtab_net
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|isa_device
name|isa_devtab_null
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|isa_device
name|isa_devtab_tty
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|inthand_t
name|IDTVEC
argument_list|(
name|fastintr0
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr1
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr2
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr3
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr4
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr5
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr6
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr7
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr8
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr9
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr10
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr11
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr12
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr13
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr14
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr15
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|inthand_t
name|IDTVEC
argument_list|(
name|intr0
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr1
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr2
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr3
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr4
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr5
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr6
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr7
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr8
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr9
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr10
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr11
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr12
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr13
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr14
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr15
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|isa_device
modifier|*
name|find_display
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|isa_device
modifier|*
name|find_isadev
name|__P
argument_list|(
operator|(
expr|struct
name|isa_device
operator|*
name|table
operator|,
expr|struct
name|isa_driver
operator|*
name|driverp
operator|,
name|int
name|unit
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|haveseen_isadev
name|__P
argument_list|(
operator|(
expr|struct
name|isa_device
operator|*
name|dvp
operator|,
name|u_int
name|checkbits
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|isa_configure
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|isa_defaultirq
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|isa_dmacascade
name|__P
argument_list|(
operator|(
name|int
name|chan
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|isa_dmadone
name|__P
argument_list|(
operator|(
name|int
name|flags
operator|,
name|caddr_t
name|addr
operator|,
name|int
name|nbytes
operator|,
name|int
name|chan
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|isa_dmainit
name|__P
argument_list|(
operator|(
name|int
name|chan
operator|,
name|u_int
name|bouncebufsize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|isa_dmastart
name|__P
argument_list|(
operator|(
name|int
name|flags
operator|,
name|caddr_t
name|addr
operator|,
name|u_int
name|nbytes
operator|,
name|int
name|chan
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isa_dma_acquire
name|__P
argument_list|(
operator|(
name|int
name|chan
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|isa_dma_release
name|__P
argument_list|(
operator|(
name|int
name|chan
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isa_dmastatus
name|__P
argument_list|(
operator|(
name|int
name|chan
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isa_dmastop
name|__P
argument_list|(
operator|(
name|int
name|chan
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isa_irq_pending
name|__P
argument_list|(
operator|(
expr|struct
name|isa_device
operator|*
name|dvp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isa_nmi
name|__P
argument_list|(
operator|(
name|int
name|cd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|reconfig_isadev
name|__P
argument_list|(
operator|(
expr|struct
name|isa_device
operator|*
name|isdp
operator|,
name|u_int
operator|*
name|mp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|register_intr
name|__P
argument_list|(
operator|(
name|int
name|intr
operator|,
name|int
name|device_id
operator|,
name|u_int
name|flags
operator|,
name|inthand2_t
operator|*
name|handler
operator|,
name|u_int
operator|*
name|maskptr
operator|,
name|int
name|unit
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unregister_intr
name|__P
argument_list|(
operator|(
name|int
name|intr
operator|,
name|inthand2_t
operator|*
name|handler
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|update_intr_masks
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_I386_ISA_ISA_DEVICE_H_ */
end_comment

end_unit

