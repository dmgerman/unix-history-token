begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pcmciavar.h,v 1.9 1998/12/29 09:00:28 marc Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997 Marc Horowitz.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Marc Horowitz.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|pccard_verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Contains information about mapped/allocated i/o spaces.  */
end_comment

begin_struct
struct|struct
name|pccard_io_handle
block|{
name|bus_space_tag_t
name|iot
decl_stmt|;
comment|/* bus space tag (from chipset) */
name|bus_space_handle_t
name|ioh
decl_stmt|;
comment|/* mapped space handle */
name|bus_addr_t
name|addr
decl_stmt|;
comment|/* resulting address in bus space */
name|bus_size_t
name|size
decl_stmt|;
comment|/* size of i/o space */
name|int
name|flags
decl_stmt|;
comment|/* misc. information */
name|int
name|width
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PCCARD_IO_ALLOCATED
value|0x01
end_define

begin_comment
comment|/* i/o space was allocated */
end_comment

begin_comment
comment|/*  * Contains information about allocated memory space.  */
end_comment

begin_struct
struct|struct
name|pccard_mem_handle
block|{
name|bus_space_tag_t
name|memt
decl_stmt|;
comment|/* bus space tag (from chipset) */
name|bus_space_handle_t
name|memh
decl_stmt|;
comment|/* mapped space handle */
name|bus_addr_t
name|addr
decl_stmt|;
comment|/* resulting address in bus space */
name|bus_size_t
name|size
decl_stmt|;
comment|/* size of mem space */
name|bus_size_t
name|realsize
decl_stmt|;
comment|/* how much we really allocated */
name|long
name|offset
decl_stmt|;
name|int
name|kind
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* pccard itself */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CFE_MWAIT_REQUIRED
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCCARD_CFE_RDYBSY_ACTIVE
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCCARD_CFE_WP_ACTIVE
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCCARD_CFE_BVD_ACTIVE
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCCARD_CFE_IO8
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCCARD_CFE_IO16
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCCARD_CFE_IRQSHARE
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCCARD_CFE_IRQPULSE
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCCARD_CFE_IRQLEVEL
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCCARD_CFE_POWERDOWN
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCCARD_CFE_READONLY
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCCARD_CFE_AUDIO
value|0x0800
end_define

begin_struct
struct|struct
name|pccard_config_entry
block|{
name|int
name|number
decl_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
name|int
name|iftype
decl_stmt|;
name|int
name|num_iospace
decl_stmt|;
comment|/* 	 * The card will only decode this mask in any case, so we can 	 * do dynamic allocation with this in mind, in case the suggestions 	 * below are no good. 	 */
name|u_long
name|iomask
decl_stmt|;
struct|struct
block|{
name|u_long
name|length
decl_stmt|;
name|u_long
name|start
decl_stmt|;
block|}
name|iospace
index|[
literal|4
index|]
struct|;
comment|/* XXX this could be as high as 16 */
name|u_int16_t
name|irqmask
decl_stmt|;
name|int
name|num_memspace
decl_stmt|;
struct|struct
block|{
name|u_long
name|length
decl_stmt|;
name|u_long
name|cardaddr
decl_stmt|;
name|u_long
name|hostaddr
decl_stmt|;
block|}
name|memspace
index|[
literal|2
index|]
struct|;
comment|/* XXX this could be as high as 8 */
name|int
name|maxtwins
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|pccard_config_entry
argument_list|)
name|cfe_list
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pccard_function
block|{
comment|/* read off the card */
name|int
name|number
decl_stmt|;
name|int
name|function
decl_stmt|;
name|int
name|last_config_index
decl_stmt|;
name|u_long
name|ccr_base
decl_stmt|;
name|u_long
name|ccr_mask
decl_stmt|;
name|struct
name|resource
modifier|*
name|ccr_res
decl_stmt|;
name|int
name|ccr_rid
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|pccard_config_entry
argument_list|)
name|cfe_head
expr_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|pccard_function
argument_list|)
name|pf_list
expr_stmt|;
comment|/* run-time state */
name|struct
name|pccard_softc
modifier|*
name|sc
decl_stmt|;
name|struct
name|pccard_config_entry
modifier|*
name|cfe
decl_stmt|;
name|struct
name|pccard_mem_handle
name|pf_pcmh
decl_stmt|;
define|#
directive|define
name|pf_ccrt
value|pf_pcmh.memt
define|#
directive|define
name|pf_ccrh
value|pf_pcmh.memh
define|#
directive|define
name|pf_ccr_realsize
value|pf_pcmh.realsize
name|bus_addr_t
name|pf_ccr_offset
decl_stmt|;
name|int
name|pf_ccr_window
decl_stmt|;
name|long
name|pf_mfc_iobase
decl_stmt|;
name|long
name|pf_mfc_iomax
decl_stmt|;
name|int
function_decl|(
modifier|*
name|ih_fct
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|ih_arg
decl_stmt|;
name|int
name|ih_ipl
decl_stmt|;
name|int
name|pf_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* pf_flags */
end_comment

begin_define
define|#
directive|define
name|PFF_ENABLED
value|0x0001
end_define

begin_comment
comment|/* function is enabled */
end_comment

begin_struct
struct|struct
name|pccard_card
block|{
name|int
name|cis1_major
decl_stmt|;
name|int
name|cis1_minor
decl_stmt|;
comment|/* XXX waste of space? */
name|char
name|cis1_info_buf
index|[
literal|256
index|]
decl_stmt|;
name|char
modifier|*
name|cis1_info
index|[
literal|4
index|]
decl_stmt|;
comment|/* 	 * Use int32_t for manufacturer and product so that they can 	 * hold the id value found in card CIS and special value that 	 * indicates no id was found. 	 */
name|int32_t
name|manufacturer
decl_stmt|;
define|#
directive|define
name|PCCARD_VENDOR_INVALID
value|-1
name|int32_t
name|product
decl_stmt|;
define|#
directive|define
name|PCCARD_PRODUCT_INVALID
value|-1
name|u_int16_t
name|error
decl_stmt|;
define|#
directive|define
name|PCCARD_CIS_INVALID
value|{ NULL, NULL, NULL, NULL }
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|pccard_function
argument_list|)
name|pf_head
expr_stmt|;
block|}
struct|;
end_struct

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

begin_comment
comment|/* More later? */
end_comment

begin_struct
struct|struct
name|pccard_ivar
block|{
name|struct
name|resource_list
name|resources
decl_stmt|;
name|int
name|slotnum
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pccard_softc
block|{
name|device_t
name|dev
decl_stmt|;
comment|/* this stuff is for the socket */
comment|/* this stuff is for the card */
name|struct
name|pccard_card
name|card
decl_stmt|;
name|void
modifier|*
name|ih
decl_stmt|;
name|int
name|sc_enabled_count
decl_stmt|;
comment|/* num functions enabled */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|pccardbus_if_setup
parameter_list|(
name|struct
name|pccard_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|pccard_cis_quirk
block|{
name|int32_t
name|manufacturer
decl_stmt|;
name|int32_t
name|product
decl_stmt|;
name|char
modifier|*
name|cis1_info
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|pccard_function
modifier|*
name|pf
decl_stmt|;
name|struct
name|pccard_config_entry
modifier|*
name|cfe
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pccard_tuple
block|{
name|unsigned
name|int
name|code
decl_stmt|;
name|unsigned
name|int
name|length
decl_stmt|;
name|u_long
name|mult
decl_stmt|;
name|bus_addr_t
name|ptr
decl_stmt|;
name|bus_space_tag_t
name|memt
decl_stmt|;
name|bus_space_handle_t
name|memh
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|pccard_read_cis
parameter_list|(
name|struct
name|pccard_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pccard_check_cis_quirks
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pccard_print_cis
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pccard_scan_cis
parameter_list|(
name|device_t
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|pccard_tuple
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|pccard_cis_read_1
parameter_list|(
name|tuple
parameter_list|,
name|idx0
parameter_list|)
define|\
value|(bus_space_read_1((tuple)->memt, (tuple)->memh, (tuple)->mult*(idx0)))
end_define

begin_define
define|#
directive|define
name|pccard_tuple_read_1
parameter_list|(
name|tuple
parameter_list|,
name|idx1
parameter_list|)
define|\
value|(pccard_cis_read_1((tuple), ((tuple)->ptr+(2+(idx1)))))
end_define

begin_define
define|#
directive|define
name|pccard_tuple_read_2
parameter_list|(
name|tuple
parameter_list|,
name|idx2
parameter_list|)
define|\
value|(pccard_tuple_read_1((tuple), (idx2)) | 			\ 	 (pccard_tuple_read_1((tuple), (idx2)+1)<<8))
end_define

begin_define
define|#
directive|define
name|pccard_tuple_read_3
parameter_list|(
name|tuple
parameter_list|,
name|idx3
parameter_list|)
define|\
value|(pccard_tuple_read_1((tuple), (idx3)) |				\ 	 (pccard_tuple_read_1((tuple), (idx3)+1)<<8) |			\ 	 (pccard_tuple_read_1((tuple), (idx3)+2)<<16))
end_define

begin_define
define|#
directive|define
name|pccard_tuple_read_4
parameter_list|(
name|tuple
parameter_list|,
name|idx4
parameter_list|)
define|\
value|(pccard_tuple_read_1((tuple), (idx4)) |				\ 	 (pccard_tuple_read_1((tuple), (idx4)+1)<<8) |			\ 	 (pccard_tuple_read_1((tuple), (idx4)+2)<<16) |			\ 	 (pccard_tuple_read_1((tuple), (idx4)+3)<<24))
end_define

begin_define
define|#
directive|define
name|pccard_tuple_read_n
parameter_list|(
name|tuple
parameter_list|,
name|n
parameter_list|,
name|idxn
parameter_list|)
define|\
value|(((n)==1)?pccard_tuple_read_1((tuple), (idxn)) :		\ 	 (((n)==2)?pccard_tuple_read_2((tuple), (idxn)) :		\ 	  (((n)==3)?pccard_tuple_read_3((tuple), (idxn)) :		\
comment|/* n == 4 */
value|pccard_tuple_read_4((tuple), (idxn)))))
end_define

begin_define
define|#
directive|define
name|PCCARD_SPACE_MEMORY
value|1
end_define

begin_define
define|#
directive|define
name|PCCARD_SPACE_IO
value|2
end_define

begin_function_decl
name|int
name|pccard_ccr_read
parameter_list|(
name|struct
name|pccard_function
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pccard_ccr_write
parameter_list|(
name|struct
name|pccard_function
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|pccard_mfc
parameter_list|(
name|sc
parameter_list|)
value|(STAILQ_FIRST(&(sc)->card.pf_head)&&		\ 		 STAILQ_NEXT(STAILQ_FIRST(&(sc)->card.pf_head),pf_list))
end_define

begin_function_decl
name|void
name|pccard_function_init
parameter_list|(
name|struct
name|pccard_function
modifier|*
parameter_list|,
name|struct
name|pccard_config_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pccard_function_enable
parameter_list|(
name|struct
name|pccard_function
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pccard_function_disable
parameter_list|(
name|struct
name|pccard_function
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|pccard_io_alloc
parameter_list|(
name|pf
parameter_list|,
name|start
parameter_list|,
name|size
parameter_list|,
name|align
parameter_list|,
name|pciop
parameter_list|)
define|\
value|(pccard_chip_io_alloc((pf)->sc->pct, pf->sc->pch, (start),	\ 	 (size), (align), (pciop)))
end_define

begin_define
define|#
directive|define
name|pccard_io_free
parameter_list|(
name|pf
parameter_list|,
name|pciohp
parameter_list|)
define|\
value|(pccard_chip_io_free((pf)->sc->pct, (pf)->sc->pch, (pciohp)))
end_define

begin_function_decl
name|int
name|pccard_io_map
parameter_list|(
name|struct
name|pccard_function
modifier|*
parameter_list|,
name|int
parameter_list|,
name|bus_addr_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|struct
name|pccard_io_handle
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pccard_io_unmap
parameter_list|(
name|struct
name|pccard_function
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|pccard_mem_alloc
parameter_list|(
name|pf
parameter_list|,
name|size
parameter_list|,
name|pcmhp
parameter_list|)
define|\
value|(pccard_chip_mem_alloc((pf)->sc->pct, (pf)->sc->pch, (size), (pcmhp)))
end_define

begin_define
define|#
directive|define
name|pccard_mem_free
parameter_list|(
name|pf
parameter_list|,
name|pcmhp
parameter_list|)
define|\
value|(pccard_chip_mem_free((pf)->sc->pct, (pf)->sc->pch, (pcmhp)))
end_define

begin_define
define|#
directive|define
name|pccard_mem_map
parameter_list|(
name|pf
parameter_list|,
name|kind
parameter_list|,
name|card_addr
parameter_list|,
name|size
parameter_list|,
name|pcmhp
parameter_list|,
name|offsetp
parameter_list|,
name|windowp
parameter_list|)
define|\
value|(pccard_chip_mem_map((pf)->sc->pct, (pf)->sc->pch, (kind),	\ 	 (card_addr), (size), (pcmhp), (offsetp), (windowp)))
end_define

begin_define
define|#
directive|define
name|pccard_mem_unmap
parameter_list|(
name|pf
parameter_list|,
name|window
parameter_list|)
define|\
value|(pccard_chip_mem_unmap((pf)->sc->pct, (pf)->sc->pch, (window)))
end_define

begin_comment
comment|/* ivar interface */
end_comment

begin_enum
enum|enum
block|{
name|PCCARD_IVAR_ETHADDR
block|,
comment|/* read ethernet address from CIS tupple */
block|}
enum|;
end_enum

begin_comment
comment|/* read ethernet address from CIS tupple */
end_comment

begin_function
name|__inline
specifier|static
name|int
name|pccard_get_ether
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_char
modifier|*
name|enaddr
parameter_list|)
block|{
return|return
name|BUS_READ_IVAR
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|PCCARD_IVAR_ETHADDR
argument_list|,
operator|(
name|uintptr_t
operator|*
operator|)
name|enaddr
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* shared memory flags */
end_comment

begin_enum
enum|enum
block|{
name|PCCARD_A_MEM_ATTR
init|=
literal|1
block|,
comment|/* attribute */
name|PCCARD_A_MEM_COM
block|,
comment|/* common */
name|PCCARD_A_MEM_8BIT
block|,
comment|/* 8 bit */
name|PCCARD_A_MEM_16BIT
comment|/* 16 bit */
block|}
enum|;
end_enum

end_unit

