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

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_comment
unit|struct pccard_function; struct pccard_mem_handle; struct pccard_io_handle;
comment|/* interfaces for pccard to call the chipset */
end_comment

begin_endif
unit|typedef struct pccard_chip_functions *pccard_chipset_tag_t; typedef void *pccard_chipset_handle_t;
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|struct pccard_chip_functions {
comment|/* memory space allocation */
end_comment

begin_comment
unit|int	(*mem_alloc)(pccard_chipset_handle_t, bus_size_t, 		    struct pccard_mem_handle *); 	void	(*mem_free)(pccard_chipset_handle_t, 		    struct pccard_mem_handle *);
comment|/* memory space window mapping */
end_comment

begin_comment
unit|int	(*mem_map)(pccard_chipset_handle_t, int, bus_addr_t, 		    bus_size_t, struct pccard_mem_handle *, 		    bus_addr_t *, int *); 	void	(*mem_unmap)(pccard_chipset_handle_t, int);
comment|/* I/O space allocation */
end_comment

begin_comment
unit|int	(*io_alloc) (pccard_chipset_handle_t, bus_addr_t, 		    bus_size_t, bus_size_t, struct pccard_io_handle *); 	void	(*io_free) (pccard_chipset_handle_t, 		    struct pccard_io_handle *);
comment|/* I/O space window mapping */
end_comment

begin_comment
unit|int	(*io_map) (pccard_chipset_handle_t, int, bus_addr_t, 		    bus_size_t, struct pccard_io_handle *, int *); 	void	(*io_unmap) (pccard_chipset_handle_t, int);
comment|/* interrupt glue */
end_comment

begin_comment
unit|void	*(*intr_establish) (pccard_chipset_handle_t, 		    struct pccard_function *, int, int (*)(void *), void *); 	void	(*intr_disestablish) (pccard_chipset_handle_t, void *);
comment|/* card enable/disable */
end_comment

begin_comment
unit|void	(*socket_enable) (pccard_chipset_handle_t); 	void	(*socket_disable) (pccard_chipset_handle_t);
comment|/* card detection */
end_comment

begin_comment
unit|int (*card_detect)(pccard_chipset_handle_t);   };
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

begin_comment
unit|struct pccardbus_attach_args { 	char *paa_busname;
comment|/* Bus name */
end_comment

begin_comment
unit|pccard_chipset_tag_t pct; 	pccard_chipset_handle_t pch; 	bus_addr_t iobase;
comment|/* start i/o space allocation here */
end_comment

begin_comment
unit|bus_size_t iosize;
comment|/* size of the i/o space range */
end_comment

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PCCARD_PCCARDCHIP_H_ */
end_comment

end_unit

