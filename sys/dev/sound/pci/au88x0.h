begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Dag-Erling Coïdan Smørgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AU88X0_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_AU88X0_H_INCLUDED
end_define

begin_comment
comment|/*  * Chipset parameters  */
end_comment

begin_struct
struct|struct
name|au88x0_chipset
block|{
specifier|const
name|char
modifier|*
name|auc_name
decl_stmt|;
name|uint32_t
name|auc_pci_id
decl_stmt|;
comment|/* General control register */
name|uint32_t
name|auc_control
decl_stmt|;
define|#
directive|define
name|AU88X0_CTL_MIDI_ENABLE
value|0x0001
define|#
directive|define
name|AU88X0_CTL_GAME_ENABLE
value|0x0008
define|#
directive|define
name|AU88X0_CTL_IRQ_ENABLE
value|0x4000
comment|/* IRQ control register */
name|uint32_t
name|auc_irq_source
decl_stmt|;
define|#
directive|define
name|AU88X0_IRQ_FATAL_ERR
value|0x0001
define|#
directive|define
name|AU88X0_IRQ_PARITY_ERR
value|0x0002
define|#
directive|define
name|AU88X0_IRQ_REG_ERR
value|0x0004
define|#
directive|define
name|AU88X0_IRQ_FIFO_ERR
value|0x0008
define|#
directive|define
name|AU88X0_IRQ_DMA_ERR
value|0x0010
define|#
directive|define
name|AU88X0_IRQ_PCMOUT
value|0x0020
define|#
directive|define
name|AU88X0_IRQ_TIMER
value|0x1000
define|#
directive|define
name|AU88X0_IRQ_MIDI
value|0x2000
define|#
directive|define
name|AU88X0_IRQ_MODEM
value|0x4000
name|uint32_t
name|auc_irq_mask
decl_stmt|;
name|uint32_t
name|auc_irq_control
decl_stmt|;
define|#
directive|define
name|AU88X0_IRQ_PENDING_BIT
value|0x0001
name|uint32_t
name|auc_irq_status
decl_stmt|;
comment|/* DMA control registers */
name|uint32_t
name|auc_dma_control
decl_stmt|;
comment|/* FIFOs */
name|int
name|auc_fifo_size
decl_stmt|;
name|int
name|auc_wt_fifos
decl_stmt|;
name|uint32_t
name|auc_wt_fifo_base
decl_stmt|;
name|uint32_t
name|auc_wt_fifo_ctl
decl_stmt|;
name|uint32_t
name|auc_wt_dma_ctl
decl_stmt|;
name|int
name|auc_adb_fifos
decl_stmt|;
name|uint32_t
name|auc_adb_fifo_base
decl_stmt|;
name|uint32_t
name|auc_adb_fifo_ctl
decl_stmt|;
name|uint32_t
name|auc_adb_dma_ctl
decl_stmt|;
comment|/* Routing */
name|uint32_t
name|auc_adb_route_base
decl_stmt|;
name|int
name|auc_adb_route_bits
decl_stmt|;
name|int
name|auc_adb_codec_in
decl_stmt|;
name|int
name|auc_adb_codec_out
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Channel information  */
end_comment

begin_struct
struct|struct
name|au88x0_chan_info
block|{
name|struct
name|au88x0_info
modifier|*
name|auci_aui
decl_stmt|;
name|struct
name|pcm_channel
modifier|*
name|auci_pcmchan
decl_stmt|;
name|struct
name|snd_dbuf
modifier|*
name|auci_buf
decl_stmt|;
name|int
name|auci_dir
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Device information  */
end_comment

begin_struct
struct|struct
name|au88x0_info
block|{
comment|/* the device we're associated with */
name|device_t
name|aui_dev
decl_stmt|;
name|uint32_t
name|aui_model
decl_stmt|;
name|struct
name|au88x0_chipset
modifier|*
name|aui_chipset
decl_stmt|;
comment|/* parameters */
name|bus_size_t
name|aui_bufsize
decl_stmt|;
name|int
name|aui_wt_fifos
decl_stmt|;
name|int
name|aui_wt_fifo_ctl
decl_stmt|;
name|int
name|aui_adb_fifos
decl_stmt|;
name|int
name|aui_adb_fifo_ctl
decl_stmt|;
name|int
name|aui_fifo_size
decl_stmt|;
name|uint32_t
name|aui_chanbase
decl_stmt|;
comment|/* bus_space tag and handle */
name|bus_space_tag_t
name|aui_spct
decl_stmt|;
name|bus_space_handle_t
name|aui_spch
decl_stmt|;
comment|/* register space */
name|int
name|aui_regtype
decl_stmt|;
name|int
name|aui_regid
decl_stmt|;
name|struct
name|resource
modifier|*
name|aui_reg
decl_stmt|;
comment|/* irq */
name|int
name|aui_irqtype
decl_stmt|;
name|int
name|aui_irqid
decl_stmt|;
name|struct
name|resource
modifier|*
name|aui_irq
decl_stmt|;
name|void
modifier|*
name|aui_irqh
decl_stmt|;
comment|/* dma */
name|bus_dma_tag_t
name|aui_dmat
decl_stmt|;
comment|/* codec */
name|struct
name|ac97_info
modifier|*
name|aui_ac97i
decl_stmt|;
comment|/* channels */
name|struct
name|au88x0_chan_info
name|aui_chan
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Common parameters  */
end_comment

begin_define
define|#
directive|define
name|AU88X0_SETTLE_DELAY
value|1000
end_define

begin_define
define|#
directive|define
name|AU88X0_RETRY_COUNT
value|10
end_define

begin_define
define|#
directive|define
name|AU88X0_BUFSIZE_MIN
value|0x1000
end_define

begin_define
define|#
directive|define
name|AU88X0_BUFSIZE_DFLT
value|0x4000
end_define

begin_define
define|#
directive|define
name|AU88X0_BUFSIZE_MAX
value|0x4000
end_define

begin_comment
comment|/*  * Codec control registers  *  * AU88X0_CODEC_CHANNEL	array of 32 32-bit words  *  * AU88X0_CODEC_CONTROL	control register  *  *    bit     16	ready  *  * AU88X0_CODEC_IO	I/O register  *  *    bits  0-15	contents of codec register  *    bits 16-22	address of codec register  *    bit     23	0 for read, 1 for write  */
end_comment

begin_define
define|#
directive|define
name|AU88X0_CODEC_CHANNEL
value|0x29080
end_define

begin_define
define|#
directive|define
name|AU88X0_CODEC_CONTROL
value|0x29184
end_define

begin_define
define|#
directive|define
name|AU88X0_CDCTL_WROK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AU88X0_CODEC_IO
value|0x29188
end_define

begin_define
define|#
directive|define
name|AU88X0_CDIO_DATA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AU88X0_CDIO_DATA_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|AU88X0_CDIO_ADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AU88X0_CDIO_ADDR_MASK
value|0x007f0000
end_define

begin_define
define|#
directive|define
name|AU88X0_CDIO_RDBIT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|AU88X0_CDIO_WRBIT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AU88X0_CDIO_READ
parameter_list|(
name|a
parameter_list|)
value|(AU88X0_CDIO_RDBIT | \ 	 (((a)<< AU88X0_CDIO_ADDR_SHIFT)& AU88X0_CDIO_ADDR_MASK))
end_define

begin_define
define|#
directive|define
name|AU88X0_CDIO_WRITE
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|(AU88X0_CDIO_WRBIT | \ 	 (((a)<< AU88X0_CDIO_ADDR_SHIFT)& AU88X0_CDIO_ADDR_MASK) | \ 	 (((d)<< AU88X0_CDIO_DATA_SHIFT)& AU88X0_CDIO_DATA_MASK))
end_define

begin_define
define|#
directive|define
name|AU88X0_CODEC_ENABLE
value|0x29190
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

