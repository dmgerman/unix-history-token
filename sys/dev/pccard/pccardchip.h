begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pcmciachip.h,v 1.4 1999/10/15 06:07:32 haya Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997 Marc Horowitz.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Marc Horowitz.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCCARD_PCCARDCHIP_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCCARD_PCCARDCHIP_H_
end_define

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_struct_decl
struct_decl|struct
name|pccard_function
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pccard_mem_handle
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pccard_io_handle
struct_decl|;
end_struct_decl

begin_comment
comment|/* interfaces for pccard to call the chipset */
end_comment

begin_typedef
typedef|typedef
name|struct
name|pccard_chip_functions
modifier|*
name|pccard_chipset_tag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|pccard_chipset_handle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|pccard_mem_handle_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PCCARD_MEM_ATTR
value|1
end_define

begin_define
define|#
directive|define
name|PCCARD_MEM_COMMON
value|2
end_define

begin_define
define|#
directive|define
name|PCCARD_WIDTH_AUTO
value|0
end_define

begin_define
define|#
directive|define
name|PCCARD_WIDTH_IO8
value|1
end_define

begin_define
define|#
directive|define
name|PCCARD_WIDTH_IO16
value|2
end_define

begin_struct
struct|struct
name|pccard_chip_functions
block|{
comment|/* memory space allocation */
name|int
argument_list|(
argument|*mem_alloc
argument_list|)
name|__P
argument_list|(
operator|(
name|pccard_chipset_handle_t
operator|,
name|bus_size_t
operator|,
expr|struct
name|pccard_mem_handle
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*mem_free
argument_list|)
name|__P
argument_list|(
operator|(
name|pccard_chipset_handle_t
operator|,
expr|struct
name|pccard_mem_handle
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* memory space window mapping */
name|int
argument_list|(
argument|*mem_map
argument_list|)
name|__P
argument_list|(
operator|(
name|pccard_chipset_handle_t
operator|,
name|int
operator|,
name|bus_addr_t
operator|,
name|bus_size_t
operator|,
expr|struct
name|pccard_mem_handle
operator|*
operator|,
name|bus_addr_t
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*mem_unmap
argument_list|)
name|__P
argument_list|(
operator|(
name|pccard_chipset_handle_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* I/O space allocation */
name|int
argument_list|(
argument|*io_alloc
argument_list|)
name|__P
argument_list|(
operator|(
name|pccard_chipset_handle_t
operator|,
name|bus_addr_t
operator|,
name|bus_size_t
operator|,
name|bus_size_t
operator|,
expr|struct
name|pccard_io_handle
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*io_free
argument_list|)
name|__P
argument_list|(
operator|(
name|pccard_chipset_handle_t
operator|,
expr|struct
name|pccard_io_handle
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* I/O space window mapping */
name|int
argument_list|(
argument|*io_map
argument_list|)
name|__P
argument_list|(
operator|(
name|pccard_chipset_handle_t
operator|,
name|int
operator|,
name|bus_addr_t
operator|,
name|bus_size_t
operator|,
expr|struct
name|pccard_io_handle
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*io_unmap
argument_list|)
name|__P
argument_list|(
operator|(
name|pccard_chipset_handle_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* interrupt glue */
name|void
operator|*
operator|(
operator|*
name|intr_establish
operator|)
name|__P
argument_list|(
operator|(
name|pccard_chipset_handle_t
operator|,
expr|struct
name|pccard_function
operator|*
operator|,
name|int
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*intr_disestablish
argument_list|)
name|__P
argument_list|(
operator|(
name|pccard_chipset_handle_t
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* card enable/disable */
name|void
argument_list|(
argument|*socket_enable
argument_list|)
name|__P
argument_list|(
operator|(
name|pccard_chipset_handle_t
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*socket_disable
argument_list|)
name|__P
argument_list|(
operator|(
name|pccard_chipset_handle_t
operator|)
argument_list|)
expr_stmt|;
comment|/* card detection */
name|int
argument_list|(
argument|*card_detect
argument_list|)
name|__P
argument_list|(
operator|(
name|pccard_chipset_handle_t
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Memory space functions. */
end_comment

begin_define
define|#
directive|define
name|pccard_chip_mem_alloc
parameter_list|(
name|tag
parameter_list|,
name|handle
parameter_list|,
name|size
parameter_list|,
name|pcmhp
parameter_list|)
define|\
value|((*(tag)->mem_alloc)((handle), (size), (pcmhp)))
end_define

begin_define
define|#
directive|define
name|pccard_chip_mem_free
parameter_list|(
name|tag
parameter_list|,
name|handle
parameter_list|,
name|pcmhp
parameter_list|)
define|\
value|((*(tag)->mem_free)((handle), (pcmhp)))
end_define

begin_define
define|#
directive|define
name|pccard_chip_mem_map
parameter_list|(
name|tag
parameter_list|,
name|handle
parameter_list|,
name|kind
parameter_list|,
name|card_addr
parameter_list|,
name|size
parameter_list|,
name|pcmhp
parameter_list|,	\
name|offsetp
parameter_list|,
name|windowp
parameter_list|)
define|\
value|((*(tag)->mem_map)((handle), (kind), (card_addr), (size), (pcmhp), \ 	    (offsetp), (windowp)))
end_define

begin_define
define|#
directive|define
name|pccard_chip_mem_unmap
parameter_list|(
name|tag
parameter_list|,
name|handle
parameter_list|,
name|window
parameter_list|)
define|\
value|((*(tag)->mem_unmap)((handle), (window)))
end_define

begin_comment
comment|/* I/O space functions. */
end_comment

begin_define
define|#
directive|define
name|pccard_chip_io_alloc
parameter_list|(
name|tag
parameter_list|,
name|handle
parameter_list|,
name|start
parameter_list|,
name|size
parameter_list|,
name|align
parameter_list|,
name|pcihp
parameter_list|)
define|\
value|((*(tag)->io_alloc)((handle), (start), (size), (align), (pcihp)))
end_define

begin_define
define|#
directive|define
name|pccard_chip_io_free
parameter_list|(
name|tag
parameter_list|,
name|handle
parameter_list|,
name|pcihp
parameter_list|)
define|\
value|((*(tag)->io_free)((handle), (pcihp)))
end_define

begin_define
define|#
directive|define
name|pccard_chip_io_map
parameter_list|(
name|tag
parameter_list|,
name|handle
parameter_list|,
name|width
parameter_list|,
name|card_addr
parameter_list|,
name|size
parameter_list|,
name|pcihp
parameter_list|,	\
name|windowp
parameter_list|)
define|\
value|((*(tag)->io_map)((handle), (width), (card_addr), (size), (pcihp), \ 	    (windowp)))
end_define

begin_define
define|#
directive|define
name|pccard_chip_io_unmap
parameter_list|(
name|tag
parameter_list|,
name|handle
parameter_list|,
name|window
parameter_list|)
define|\
value|((*(tag)->io_unmap)((handle), (window)))
end_define

begin_comment
comment|/* Interrupt functions. */
end_comment

begin_define
define|#
directive|define
name|pccard_chip_intr_establish
parameter_list|(
name|tag
parameter_list|,
name|handle
parameter_list|,
name|pf
parameter_list|,
name|ipl
parameter_list|,
name|fct
parameter_list|,
name|arg
parameter_list|)
define|\
value|((*(tag)->intr_establish)((handle), (pf), (ipl), (fct), (arg)))
end_define

begin_define
define|#
directive|define
name|pccard_chip_intr_disestablish
parameter_list|(
name|tag
parameter_list|,
name|handle
parameter_list|,
name|ih
parameter_list|)
define|\
value|((*(tag)->intr_disestablish)((handle), (ih)))
end_define

begin_comment
comment|/* Socket functions. */
end_comment

begin_define
define|#
directive|define
name|pccard_chip_socket_enable
parameter_list|(
name|tag
parameter_list|,
name|handle
parameter_list|)
define|\
value|((*(tag)->socket_enable)((handle)))
end_define

begin_define
define|#
directive|define
name|pccard_chip_socket_disable
parameter_list|(
name|tag
parameter_list|,
name|handle
parameter_list|)
define|\
value|((*(tag)->socket_disable)((handle)))
end_define

begin_struct
struct|struct
name|pccardbus_attach_args
block|{
name|char
modifier|*
name|paa_busname
decl_stmt|;
comment|/* Bus name */
name|pccard_chipset_tag_t
name|pct
decl_stmt|;
name|pccard_chipset_handle_t
name|pch
decl_stmt|;
name|bus_addr_t
name|iobase
decl_stmt|;
comment|/* start i/o space allocation here */
name|bus_size_t
name|iosize
decl_stmt|;
comment|/* size of the i/o space range */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PCCARD_PCCARDCHIP_H_ */
end_comment

end_unit

