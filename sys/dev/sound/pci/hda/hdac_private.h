begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Stephane E. Potvin<sepotvin@videotron.ca>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HDAC_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_HDAC_PRIVATE_H_
end_define

begin_comment
comment|/****************************************************************************  * Miscellaneous defines  ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HDAC_DMA_ALIGNMENT
value|128
end_define

begin_define
define|#
directive|define
name|HDAC_CODEC_MAX
value|16
end_define

begin_define
define|#
directive|define
name|HDAC_MTX_NAME
value|"hdac driver mutex"
end_define

begin_comment
comment|/****************************************************************************  * Helper Macros  ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HDAC_READ_1
parameter_list|(
name|mem
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_read_1((mem)->mem_tag, (mem)->mem_handle, (offset))
end_define

begin_define
define|#
directive|define
name|HDAC_READ_2
parameter_list|(
name|mem
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_read_2((mem)->mem_tag, (mem)->mem_handle, (offset))
end_define

begin_define
define|#
directive|define
name|HDAC_READ_4
parameter_list|(
name|mem
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_read_4((mem)->mem_tag, (mem)->mem_handle, (offset))
end_define

begin_define
define|#
directive|define
name|HDAC_WRITE_1
parameter_list|(
name|mem
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_1((mem)->mem_tag, (mem)->mem_handle, (offset), (value))
end_define

begin_define
define|#
directive|define
name|HDAC_WRITE_2
parameter_list|(
name|mem
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_2((mem)->mem_tag, (mem)->mem_handle, (offset), (value))
end_define

begin_define
define|#
directive|define
name|HDAC_WRITE_4
parameter_list|(
name|mem
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_4((mem)->mem_tag, (mem)->mem_handle, (offset), (value))
end_define

begin_define
define|#
directive|define
name|HDAC_ISDCTL
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_ISDCTL((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_ISDSTS
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_ISDSTS((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_ISDPICB
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_ISDPICB((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_ISDCBL
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_ISDCBL((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_ISDLVI
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_ISDLVI((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_ISDFIFOD
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_ISDFIFOD((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_ISDFMT
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_ISDFMT((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_ISDBDPL
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_ISDBDPL((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_ISDBDPU
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_ISDBDPU((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_OSDCTL
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_OSDCTL((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_OSDSTS
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_OSDSTS((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_OSDPICB
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_OSDPICB((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_OSDCBL
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_OSDCBL((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_OSDLVI
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_OSDLVI((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_OSDFIFOD
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_OSDFIFOD((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_OSDBDPL
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_OSDBDPL((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_OSDBDPU
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_OSDBDPU((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_BSDCTL
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_BSDCTL((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_BSDSTS
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_BSDSTS((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_BSDPICB
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_BSDPICB((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_BSDCBL
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_BSDCBL((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_BSDLVI
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_BSDLVI((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_BSDFIFOD
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_BSDFIFOD((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_BSDBDPL
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_BSDBDPL((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_define
define|#
directive|define
name|HDAC_BSDBDPU
parameter_list|(
name|sc
parameter_list|,
name|n
parameter_list|)
value|(_HDAC_BSDBDPU((n), (sc)->num_iss, (sc)->num_oss))
end_define

begin_comment
comment|/****************************************************************************  * Custom hdac malloc type  ****************************************************************************/
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_HDAC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/****************************************************************************  * struct hdac_mem  *  * Holds the resources necessary to describe the physical memory associated  * with the device.  ****************************************************************************/
end_comment

begin_struct
struct|struct
name|hdac_mem
block|{
name|struct
name|resource
modifier|*
name|mem_res
decl_stmt|;
name|int
name|mem_rid
decl_stmt|;
name|bus_space_tag_t
name|mem_tag
decl_stmt|;
name|bus_space_handle_t
name|mem_handle
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/****************************************************************************  * struct hdac_irq  *  * Holds the resources necessary to describe the irq associated with the  * device.  ****************************************************************************/
end_comment

begin_struct
struct|struct
name|hdac_irq
block|{
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
name|void
modifier|*
name|irq_handle
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/****************************************************************************  * struct hdac_dma  *  * This structure is used to hold all the information to manage the dma  * states.  ****************************************************************************/
end_comment

begin_struct
struct|struct
name|hdac_dma
block|{
name|bus_dma_tag_t
name|dma_tag
decl_stmt|;
name|bus_dmamap_t
name|dma_map
decl_stmt|;
name|bus_addr_t
name|dma_paddr
decl_stmt|;
name|caddr_t
name|dma_vaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/****************************************************************************  * struct hdac_rirb  *  * Hold a response from a verb sent to a codec received via the rirb.  ****************************************************************************/
end_comment

begin_struct
struct|struct
name|hdac_rirb
block|{
name|uint32_t
name|response
decl_stmt|;
name|uint32_t
name|response_ex
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HDAC_RIRB_RESPONSE_EX_SDATA_IN_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|HDAC_RIRB_RESPONSE_EX_SDATA_IN_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|HDAC_RIRB_RESPONSE_EX_UNSOLICITED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HDAC_RIRB_RESPONSE_EX_SDATA_IN
parameter_list|(
name|response_ex
parameter_list|)
define|\
value|(((response_ex)& HDAC_RIRB_RESPONSE_EX_SDATA_IN_MASK)>>		\     HDAC_RIRB_RESPONSE_EX_SDATA_IN_OFFSET)
end_define

begin_comment
comment|/****************************************************************************  * struct hdac_command_list  *  * This structure holds the list of verbs that are to be sent to the codec  * via the corb and the responses received via the rirb. It's allocated by  * the codec driver and is owned by it.  ****************************************************************************/
end_comment

begin_struct
struct|struct
name|hdac_command_list
block|{
name|int
name|num_commands
decl_stmt|;
name|uint32_t
modifier|*
name|verbs
decl_stmt|;
name|uint32_t
modifier|*
name|responses
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
name|nid_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|hdac_softc
struct_decl|;
end_struct_decl

begin_comment
comment|/****************************************************************************  * struct hdac_codec  *  ****************************************************************************/
end_comment

begin_struct
struct|struct
name|hdac_codec
block|{
name|int
name|verbs_sent
decl_stmt|;
name|int
name|responses_received
decl_stmt|;
name|nid_t
name|cad
decl_stmt|;
name|struct
name|hdac_command_list
modifier|*
name|commands
decl_stmt|;
name|struct
name|hdac_softc
modifier|*
name|sc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hdac_bdle
block|{
specifier|volatile
name|uint32_t
name|addrl
decl_stmt|;
specifier|volatile
name|uint32_t
name|addrh
decl_stmt|;
specifier|volatile
name|uint32_t
name|len
decl_stmt|;
specifier|volatile
name|uint32_t
name|ioc
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|HDA_MAX_CONNS
value|32
end_define

begin_define
define|#
directive|define
name|HDA_MAX_NAMELEN
value|32
end_define

begin_struct_decl
struct_decl|struct
name|hdac_devinfo
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|hdac_widget
block|{
name|nid_t
name|nid
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|enable
decl_stmt|;
name|int
name|nconns
decl_stmt|,
name|selconn
decl_stmt|;
name|uint32_t
name|pflags
decl_stmt|,
name|ctlflags
decl_stmt|;
name|nid_t
name|conns
index|[
name|HDA_MAX_CONNS
index|]
decl_stmt|;
name|char
name|name
index|[
name|HDA_MAX_NAMELEN
index|]
decl_stmt|;
name|struct
name|hdac_devinfo
modifier|*
name|devinfo
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|widget_cap
decl_stmt|;
name|uint32_t
name|outamp_cap
decl_stmt|;
name|uint32_t
name|inamp_cap
decl_stmt|;
name|uint32_t
name|supp_stream_formats
decl_stmt|;
name|uint32_t
name|supp_pcm_size_rate
decl_stmt|;
name|uint32_t
name|eapdbtl
decl_stmt|;
name|int
name|outpath
decl_stmt|;
block|}
name|param
struct|;
union|union
block|{
struct|struct
block|{
name|uint32_t
name|config
decl_stmt|;
name|uint32_t
name|cap
decl_stmt|;
name|uint32_t
name|ctrl
decl_stmt|;
block|}
name|pin
struct|;
block|}
name|wclass
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hdac_audio_ctl
block|{
name|struct
name|hdac_widget
modifier|*
name|widget
decl_stmt|,
modifier|*
name|childwidget
decl_stmt|;
name|int
name|enable
decl_stmt|;
name|int
name|index
decl_stmt|;
name|int
name|mute
decl_stmt|,
name|step
decl_stmt|,
name|size
decl_stmt|,
name|offset
decl_stmt|;
name|int
name|left
decl_stmt|,
name|right
decl_stmt|;
name|uint32_t
name|muted
decl_stmt|;
name|int
name|ossdev
decl_stmt|;
name|uint32_t
name|dir
decl_stmt|,
name|ossmask
decl_stmt|,
name|ossval
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/****************************************************************************  * struct hdac_devinfo  *  * Holds all the parameters of a given codec function group. This is stored  * in the ivar of each child of the hdac bus  ****************************************************************************/
end_comment

begin_struct
struct|struct
name|hdac_devinfo
block|{
name|device_t
name|dev
decl_stmt|;
name|uint16_t
name|vendor_id
decl_stmt|;
name|uint16_t
name|device_id
decl_stmt|;
name|uint8_t
name|revision_id
decl_stmt|;
name|uint8_t
name|stepping_id
decl_stmt|;
name|uint8_t
name|node_type
decl_stmt|;
name|nid_t
name|nid
decl_stmt|;
name|nid_t
name|startnode
decl_stmt|,
name|endnode
decl_stmt|;
name|int
name|nodecnt
decl_stmt|;
name|struct
name|hdac_codec
modifier|*
name|codec
decl_stmt|;
name|struct
name|hdac_widget
modifier|*
name|widget
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint32_t
name|outamp_cap
decl_stmt|;
name|uint32_t
name|inamp_cap
decl_stmt|;
name|uint32_t
name|supp_stream_formats
decl_stmt|;
name|uint32_t
name|supp_pcm_size_rate
decl_stmt|;
name|int
name|ctlcnt
decl_stmt|,
name|pcnt
decl_stmt|,
name|rcnt
decl_stmt|;
name|struct
name|hdac_audio_ctl
modifier|*
name|ctl
decl_stmt|;
name|uint32_t
name|mvol
decl_stmt|;
name|uint32_t
name|quirks
decl_stmt|;
name|int
name|ossidx
decl_stmt|;
name|int
name|playcnt
decl_stmt|,
name|reccnt
decl_stmt|;
name|int
name|parsing_strategy
decl_stmt|;
block|}
name|audio
struct|;
comment|/* XXX undefined: modem, hdmi. */
block|}
name|function
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hdac_chan
block|{
name|struct
name|snd_dbuf
modifier|*
name|b
decl_stmt|;
name|struct
name|pcm_channel
modifier|*
name|c
decl_stmt|;
name|struct
name|pcmchan_caps
name|caps
decl_stmt|;
name|struct
name|hdac_devinfo
modifier|*
name|devinfo
decl_stmt|;
name|struct
name|hdac_dma
name|bdl_dma
decl_stmt|;
name|uint32_t
name|spd
decl_stmt|,
name|fmt
decl_stmt|,
name|fmtlist
index|[
literal|8
index|]
decl_stmt|,
name|pcmrates
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|supp_stream_formats
decl_stmt|,
name|supp_pcm_size_rate
decl_stmt|;
name|uint32_t
name|ptr
decl_stmt|,
name|prevptr
decl_stmt|,
name|blkcnt
decl_stmt|,
name|blksz
decl_stmt|;
name|int
name|active
decl_stmt|;
name|int
name|dir
decl_stmt|;
name|int
name|off
decl_stmt|;
name|int
name|sid
decl_stmt|;
name|int
name|bit16
decl_stmt|,
name|bit32
decl_stmt|;
name|nid_t
name|io
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/****************************************************************************  * struct hdac_softc  *  * This structure holds the current state of the hdac driver.  ****************************************************************************/
end_comment

begin_struct
struct|struct
name|hdac_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|device_t
name|hdabus
decl_stmt|;
name|struct
name|mtx
modifier|*
name|lock
decl_stmt|;
name|struct
name|intr_config_hook
name|intrhook
decl_stmt|;
name|struct
name|hdac_mem
name|mem
decl_stmt|;
name|struct
name|hdac_irq
name|irq
decl_stmt|;
name|uint32_t
name|pci_subvendor
decl_stmt|;
name|int
name|num_iss
decl_stmt|;
name|int
name|num_oss
decl_stmt|;
name|int
name|num_bss
decl_stmt|;
name|int
name|support_64bit
decl_stmt|;
name|int
name|streamcnt
decl_stmt|;
name|int
name|corb_size
decl_stmt|;
name|struct
name|hdac_dma
name|corb_dma
decl_stmt|;
name|int
name|corb_wp
decl_stmt|;
name|int
name|rirb_size
decl_stmt|;
name|struct
name|hdac_dma
name|rirb_dma
decl_stmt|;
name|int
name|rirb_rp
decl_stmt|;
name|struct
name|hdac_chan
name|play
decl_stmt|,
name|rec
decl_stmt|;
name|bus_dma_tag_t
name|chan_dmat
decl_stmt|;
name|int
name|chan_size
decl_stmt|;
name|int
name|chan_blkcnt
decl_stmt|;
comment|/* 	 * Polling 	 */
name|int
name|polling
decl_stmt|;
name|int
name|poll_ticks
decl_stmt|;
name|struct
name|callout
name|poll_hda
decl_stmt|;
name|struct
name|callout
name|poll_hdac
decl_stmt|;
define|#
directive|define
name|HDAC_UNSOLQ_MAX
value|64
define|#
directive|define
name|HDAC_UNSOLQ_READY
value|0
define|#
directive|define
name|HDAC_UNSOLQ_BUSY
value|1
name|int
name|unsolq_rp
decl_stmt|;
name|int
name|unsolq_wp
decl_stmt|;
name|int
name|unsolq_st
decl_stmt|;
name|uint32_t
name|unsolq
index|[
name|HDAC_UNSOLQ_MAX
index|]
decl_stmt|;
name|struct
name|hdac_codec
modifier|*
name|codecs
index|[
name|HDAC_CODEC_MAX
index|]
decl_stmt|;
name|int
name|registered
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/****************************************************************************  * struct hdac_command flags  ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HDAC_COMMAND_FLAG_WAITOK
value|0x0000
end_define

begin_define
define|#
directive|define
name|HDAC_COMMAND_FLAG_NOWAIT
value|0x0001
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

