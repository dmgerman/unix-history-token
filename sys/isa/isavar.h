begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISA_ISAVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_ISA_ISAVAR_H_
end_define

begin_struct_decl
struct_decl|struct
name|isa_config
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|isa_pnp_id
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
name|isa_config_cb
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|struct
name|isa_config
modifier|*
name|config
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
end_typedef

begin_include
include|#
directive|include
file|"isa_if.h"
end_include

begin_include
include|#
directive|include
file|<isa/pnpvar.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * ISA devices are partially ordered.  This is to ensure that hardwired  * devices the BIOS tells us are there appear first, then speculative  * devices that are sensitive to the probe order, then devices that  * are hinted to be there, then the most flexible devices which support  * the ISA bus PNP standard.  */
end_comment

begin_define
define|#
directive|define
name|ISA_ORDER_PNPBIOS
value|10
end_define

begin_comment
comment|/* plug-and-play BIOS inflexible hardware */
end_comment

begin_define
define|#
directive|define
name|ISA_ORDER_SENSITIVE
value|20
end_define

begin_comment
comment|/* legacy sensitive hardware */
end_comment

begin_define
define|#
directive|define
name|ISA_ORDER_SPECULATIVE
value|30
end_define

begin_comment
comment|/* legacy non-sensitive hardware */
end_comment

begin_define
define|#
directive|define
name|ISA_ORDER_PNP
value|40
end_define

begin_comment
comment|/* plug-and-play hardware */
end_comment

begin_comment
comment|/*  * Limits on resources that we can manage  */
end_comment

begin_define
define|#
directive|define
name|ISA_NPORT
value|50
end_define

begin_define
define|#
directive|define
name|ISA_NMEM
value|50
end_define

begin_define
define|#
directive|define
name|ISA_NIRQ
value|50
end_define

begin_define
define|#
directive|define
name|ISA_NDRQ
value|50
end_define

begin_comment
comment|/*  * Limits on resources the hardware can actually handle  */
end_comment

begin_define
define|#
directive|define
name|ISA_PNP_NPORT
value|8
end_define

begin_define
define|#
directive|define
name|ISA_PNP_NMEM
value|4
end_define

begin_define
define|#
directive|define
name|ISA_PNP_NIRQ
value|2
end_define

begin_define
define|#
directive|define
name|ISA_PNP_NDRQ
value|2
end_define

begin_define
define|#
directive|define
name|ISADMA_READ
value|0x00100000
end_define

begin_define
define|#
directive|define
name|ISADMA_WRITE
value|0
end_define

begin_define
define|#
directive|define
name|ISADMA_RAW
value|0x00080000
end_define

begin_comment
comment|/*  * Plug and play cards can support a range of resource  * configurations. This structure is used by the isapnp parser to  * inform the isa bus about the resource possibilities of the  * device. Each different alternative should be supplied by calling  * ISA_ADD_CONFIG().  */
end_comment

begin_struct
struct|struct
name|isa_range
block|{
name|u_int32_t
name|ir_start
decl_stmt|;
name|u_int32_t
name|ir_end
decl_stmt|;
name|u_int32_t
name|ir_size
decl_stmt|;
name|u_int32_t
name|ir_align
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|isa_config
block|{
name|struct
name|isa_range
name|ic_mem
index|[
name|ISA_NMEM
index|]
decl_stmt|;
name|struct
name|isa_range
name|ic_port
index|[
name|ISA_NPORT
index|]
decl_stmt|;
name|u_int32_t
name|ic_irqmask
index|[
name|ISA_NIRQ
index|]
decl_stmt|;
name|u_int32_t
name|ic_drqmask
index|[
name|ISA_NDRQ
index|]
decl_stmt|;
name|int
name|ic_nmem
decl_stmt|;
name|int
name|ic_nport
decl_stmt|;
name|int
name|ic_nirq
decl_stmt|;
name|int
name|ic_ndrq
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Used to build lists of IDs and description strings for PnP drivers.  */
end_comment

begin_struct
struct|struct
name|isa_pnp_id
block|{
name|u_int32_t
name|ip_id
decl_stmt|;
specifier|const
name|char
modifier|*
name|ip_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|isa_device_ivars
block|{
name|ISA_IVAR_PORT
block|,
name|ISA_IVAR_PORT_0
init|=
name|ISA_IVAR_PORT
block|,
name|ISA_IVAR_PORT_1
block|,
name|ISA_IVAR_PORTSIZE
block|,
name|ISA_IVAR_PORTSIZE_0
init|=
name|ISA_IVAR_PORTSIZE
block|,
name|ISA_IVAR_PORTSIZE_1
block|,
name|ISA_IVAR_MADDR
block|,
name|ISA_IVAR_MADDR_0
init|=
name|ISA_IVAR_MADDR
block|,
name|ISA_IVAR_MADDR_1
block|,
name|ISA_IVAR_MEMSIZE
block|,
name|ISA_IVAR_MEMSIZE_0
init|=
name|ISA_IVAR_MEMSIZE
block|,
name|ISA_IVAR_MEMSIZE_1
block|,
name|ISA_IVAR_IRQ
block|,
name|ISA_IVAR_IRQ_0
init|=
name|ISA_IVAR_IRQ
block|,
name|ISA_IVAR_IRQ_1
block|,
name|ISA_IVAR_DRQ
block|,
name|ISA_IVAR_DRQ_0
init|=
name|ISA_IVAR_DRQ
block|,
name|ISA_IVAR_DRQ_1
block|,
name|ISA_IVAR_VENDORID
block|,
name|ISA_IVAR_SERIAL
block|,
name|ISA_IVAR_LOGICALID
block|,
name|ISA_IVAR_COMPATID
block|,
name|ISA_IVAR_CONFIGATTR
block|}
enum|;
end_enum

begin_comment
comment|/*  * ISA_IVAR_CONFIGATTR bits  */
end_comment

begin_define
define|#
directive|define
name|ISACFGATTR_CANDISABLE
value|(1<< 0)
end_define

begin_comment
comment|/* can be disabled */
end_comment

begin_define
define|#
directive|define
name|ISACFGATTR_DYNAMIC
value|(1<< 1)
end_define

begin_comment
comment|/* dynamic configuration */
end_comment

begin_define
define|#
directive|define
name|ISACFGATTR_MULTI
value|(1<< 2)
end_define

begin_comment
comment|/* multiple configurations */
end_comment

begin_comment
comment|/*  * Simplified accessors for isa devices  */
end_comment

begin_define
define|#
directive|define
name|ISA_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(isa, var, ISA, ivar, type)
end_define

begin_macro
name|ISA_ACCESSOR
argument_list|(
argument|port
argument_list|,
argument|PORT
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|ISA_ACCESSOR
argument_list|(
argument|portsize
argument_list|,
argument|PORTSIZE
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|ISA_ACCESSOR
argument_list|(
argument|irq
argument_list|,
argument|IRQ
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|ISA_ACCESSOR
argument_list|(
argument|drq
argument_list|,
argument|DRQ
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|ISA_ACCESSOR
argument_list|(
argument|maddr
argument_list|,
argument|MADDR
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|ISA_ACCESSOR
argument_list|(
argument|msize
argument_list|,
argument|MEMSIZE
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|ISA_ACCESSOR
argument_list|(
argument|vendorid
argument_list|,
argument|VENDORID
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|ISA_ACCESSOR
argument_list|(
argument|serial
argument_list|,
argument|SERIAL
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|ISA_ACCESSOR
argument_list|(
argument|logicalid
argument_list|,
argument|LOGICALID
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|ISA_ACCESSOR
argument_list|(
argument|compatid
argument_list|,
argument|COMPATID
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|ISA_ACCESSOR
argument_list|(
argument|configattr
argument_list|,
argument|CONFIGATTR
argument_list|,
argument|int
argument_list|)
end_macro

begin_comment
comment|/* Device class for ISA bridges. */
end_comment

begin_decl_stmt
specifier|extern
name|devclass_t
name|isab_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|intrmask_t
name|isa_irq_pending
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isa_probe_children
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isa_dmacascade
parameter_list|(
name|int
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isa_dmadone
parameter_list|(
name|int
name|flags
parameter_list|,
name|caddr_t
name|addr
parameter_list|,
name|int
name|nbytes
parameter_list|,
name|int
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isa_dma_init
parameter_list|(
name|int
name|chan
parameter_list|,
name|u_int
name|bouncebufsize
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isa_dmastart
parameter_list|(
name|int
name|flags
parameter_list|,
name|caddr_t
name|addr
parameter_list|,
name|u_int
name|nbytes
parameter_list|,
name|int
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isa_dma_acquire
parameter_list|(
name|int
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isa_dma_release
parameter_list|(
name|int
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isa_dmastatus
parameter_list|(
name|int
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isa_dmastop
parameter_list|(
name|int
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isa_dmatc
parameter_list|(
name|int
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|isa_dmainit
parameter_list|(
name|chan
parameter_list|,
name|size
parameter_list|)
value|do { \ 	if (isa_dma_init(chan, size, M_NOWAIT)) \ 		printf("WARNING: isa_dma_init(%d, %ju) failed\n", \ 		    (int)(chan), (uintmax_t)(size)); \ 	} while (0)
end_define

begin_function_decl
name|int
name|isab_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_comment
comment|/*  * Allocate discontinuous resources for ISA bus.  */
end_comment

begin_function_decl
name|struct
name|resource
modifier|*
name|isa_alloc_resourcev
parameter_list|(
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
modifier|*
name|rid
parameter_list|,
name|bus_addr_t
modifier|*
name|res
parameter_list|,
name|bus_size_t
name|count
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isa_load_resourcev
parameter_list|(
name|struct
name|resource
modifier|*
name|re
parameter_list|,
name|bus_addr_t
modifier|*
name|res
parameter_list|,
name|bus_size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ISA_ISAVAR_H_ */
end_comment

end_unit

