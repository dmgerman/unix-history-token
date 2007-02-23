begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005, M. Warner Losh  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCCARD_PCCARDVARP_H
end_ifndef

begin_define
define|#
directive|define
name|_PCCARD_PCCARDVARP_H
end_define

begin_comment
comment|/* pccard itself */
end_comment

begin_define
define|#
directive|define
name|PCCARD_MEM_PAGE_SIZE
value|1024
end_define

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
name|uint32_t
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
name|uint16_t
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
name|pccard_funce_disk
block|{
name|int
name|pfd_interface
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pccard_funce_lan
block|{
name|int
name|pfl_nidlen
decl_stmt|;
name|uint8_t
name|pfl_nid
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|pccard_funce
block|{
name|struct
name|pccard_funce_disk
name|pfv_disk
decl_stmt|;
name|struct
name|pccard_funce_lan
name|pfv_lan
decl_stmt|;
block|}
union|;
end_union

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
name|uint32_t
name|ccr_base
decl_stmt|;
comment|/* Offset with card's memory */
name|uint32_t
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
name|device_t
name|dev
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
name|uint32_t
name|pf_ccr_offset
decl_stmt|;
comment|/* Offset from ccr_base of CIS */
name|int
name|pf_ccr_window
decl_stmt|;
name|bus_addr_t
name|pf_mfc_iobase
decl_stmt|;
name|bus_addr_t
name|pf_mfc_iomax
decl_stmt|;
name|int
name|pf_flags
decl_stmt|;
name|driver_filter_t
modifier|*
name|filt_handler
decl_stmt|;
name|driver_intr_t
modifier|*
name|intr_handler
decl_stmt|;
name|void
modifier|*
name|intr_handler_arg
decl_stmt|;
name|void
modifier|*
name|intr_handler_cookie
decl_stmt|;
name|union
name|pccard_funce
name|pf_funce
decl_stmt|;
comment|/* CISTPL_FUNCE */
define|#
directive|define
name|pf_funce_disk_interface
value|pf_funce.pfv_disk.pfd_interface
define|#
directive|define
name|pf_funce_lan_nid
value|pf_funce.pfv_lan.pfl_nid
define|#
directive|define
name|pf_funce_lan_nidlen
value|pf_funce.pfv_lan.pfl_nidlen
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
name|PCMCIA_VENDOR_INVALID
value|-1
name|int32_t
name|product
decl_stmt|;
define|#
directive|define
name|PCMCIA_PRODUCT_INVALID
value|-1
name|int16_t
name|prodext
decl_stmt|;
name|uint16_t
name|error
decl_stmt|;
define|#
directive|define
name|PCMCIA_CIS_INVALID
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
name|struct
name|pccard_function
modifier|*
name|pf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cis_buffer
block|{
name|size_t
name|len
decl_stmt|;
comment|/* Actual length of the CIS */
name|uint8_t
name|buffer
index|[
literal|2040
index|]
decl_stmt|;
comment|/* small enough to be 2k */
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
name|int
name|sc_enabled_count
decl_stmt|;
comment|/* num functions enabled */
name|struct
name|cdev
modifier|*
name|cisdev
decl_stmt|;
name|int
name|cis_open
decl_stmt|;
name|struct
name|cis_buffer
modifier|*
name|cis
decl_stmt|;
block|}
struct|;
end_struct

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
name|device_t
parameter_list|,
name|pccard_scan_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pccard_device_create
parameter_list|(
name|struct
name|pccard_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pccard_device_destroy
parameter_list|(
name|struct
name|pccard_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PCCARD_SOFTC
parameter_list|(
name|d
parameter_list|)
value|(struct pccard_softc *) device_get_softc(d)
end_define

begin_define
define|#
directive|define
name|PCCARD_IVAR
parameter_list|(
name|d
parameter_list|)
value|(struct pccard_ivar *) device_get_ivars(d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PCCARD_PCCARDVARP_H */
end_comment

end_unit

