begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)isa_device.h	7.1 (Berkeley) 5/9/91  * $FreeBSD$  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_ISA_ISAVAR_H_
end_ifndef

begin_include
include|#
directive|include
file|<i386/isa/isa_dma.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ISA Bus Autoconfiguration  */
end_comment

begin_comment
comment|/*  * Per device structure.  */
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
name|int
name|id_iosize
decl_stmt|;
comment|/* base i/o length */
name|u_int
name|id_irq
decl_stmt|;
comment|/* interrupt request */
name|int
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
union|union
block|{
name|inthand2_t
modifier|*
name|id_i
decl_stmt|;
name|ointhand2_t
modifier|*
name|id_oi
decl_stmt|;
block|}
name|id_iu
union|;
comment|/* interrupt interface routine */
define|#
directive|define
name|id_intr
value|id_iu.id_i
define|#
directive|define
name|id_ointr
value|id_iu.id_oi
name|int
name|id_unit
decl_stmt|;
comment|/* unit number */
name|int
name|id_flags
decl_stmt|;
comment|/* flags */
name|int
name|id_enabled
decl_stmt|;
comment|/* is device enabled */
name|struct
name|isa_device
modifier|*
name|id_next
decl_stmt|;
comment|/* used in isa_devlist in userconfig() */
name|struct
name|device
modifier|*
name|id_device
decl_stmt|;
comment|/* new-bus wrapper device */
block|}
struct|;
end_struct

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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
name|int
name|haveseen_iobase
name|__P
argument_list|(
operator|(
expr|struct
name|isa_device
operator|*
name|dvp
operator|,
name|int
name|iosize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isa_compat_nextid
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_I386_ISA_ISA_DEVICE_H_ */
end_comment

end_unit

