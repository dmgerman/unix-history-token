begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_XILINX
value|0x10ee
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_XILINX_HDSPE
value|0x3fc6
end_define

begin_comment
comment|/* AIO, MADI, AES, RayDAT */
end_comment

begin_define
define|#
directive|define
name|PCI_CLASS_REVISION
value|0x08
end_define

begin_define
define|#
directive|define
name|PCI_REVISION_AIO
value|212
end_define

begin_define
define|#
directive|define
name|PCI_REVISION_RAYDAT
value|211
end_define

begin_define
define|#
directive|define
name|AIO
value|0
end_define

begin_define
define|#
directive|define
name|RAYDAT
value|1
end_define

begin_comment
comment|/* Hardware mixer */
end_comment

begin_define
define|#
directive|define
name|HDSPE_OUT_ENABLE_BASE
value|512
end_define

begin_define
define|#
directive|define
name|HDSPE_IN_ENABLE_BASE
value|768
end_define

begin_define
define|#
directive|define
name|HDSPE_MIXER_BASE
value|32768
end_define

begin_define
define|#
directive|define
name|HDSPE_MAX_GAIN
value|32768
end_define

begin_comment
comment|/* Buffer */
end_comment

begin_define
define|#
directive|define
name|HDSPE_PAGE_ADDR_BUF_OUT
value|8192
end_define

begin_define
define|#
directive|define
name|HDSPE_PAGE_ADDR_BUF_IN
value|(HDSPE_PAGE_ADDR_BUF_OUT + 64 * 16 * 4)
end_define

begin_define
define|#
directive|define
name|HDSPE_BUF_POSITION_MASK
value|0x000FFC0
end_define

begin_comment
comment|/* Frequency */
end_comment

begin_define
define|#
directive|define
name|HDSPE_FREQ_0
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|HDSPE_FREQ_1
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|HDSPE_FREQ_DOUBLE
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|HDSPE_FREQ_QUAD
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|HDSPE_FREQ_32000
value|HDSPE_FREQ_0
end_define

begin_define
define|#
directive|define
name|HDSPE_FREQ_44100
value|HDSPE_FREQ_1
end_define

begin_define
define|#
directive|define
name|HDSPE_FREQ_48000
value|(HDSPE_FREQ_0 | HDSPE_FREQ_1)
end_define

begin_define
define|#
directive|define
name|HDSPE_FREQ_MASK
value|(HDSPE_FREQ_0 | HDSPE_FREQ_1 |	\ 					HDSPE_FREQ_DOUBLE | HDSPE_FREQ_QUAD)
end_define

begin_define
define|#
directive|define
name|HDSPE_FREQ_MASK_DEFAULT
value|HDSPE_FREQ_48000
end_define

begin_define
define|#
directive|define
name|HDSPE_FREQ_REG
value|256
end_define

begin_define
define|#
directive|define
name|HDSPE_FREQ_AIO
value|104857600000000ULL
end_define

begin_define
define|#
directive|define
name|HDSPE_SPEED_DEFAULT
value|48000
end_define

begin_comment
comment|/* Latency */
end_comment

begin_define
define|#
directive|define
name|HDSPE_LAT_0
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|HDSPE_LAT_1
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|HDSPE_LAT_2
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|HDSPE_LAT_MASK
value|(HDSPE_LAT_0 | HDSPE_LAT_1 | HDSPE_LAT_2)
end_define

begin_define
define|#
directive|define
name|HDSPE_LAT_BYTES_MAX
value|(4096 * 4)
end_define

begin_define
define|#
directive|define
name|HDSPE_LAT_BYTES_MIN
value|(32 * 4)
end_define

begin_define
define|#
directive|define
name|hdspe_encode_latency
parameter_list|(
name|x
parameter_list|)
value|(((x)<<1)& HDSPE_LAT_MASK)
end_define

begin_comment
comment|/* Settings */
end_comment

begin_define
define|#
directive|define
name|HDSPE_SETTINGS_REG
value|0
end_define

begin_define
define|#
directive|define
name|HDSPE_CONTROL_REG
value|64
end_define

begin_define
define|#
directive|define
name|HDSPE_STATUS_REG
value|0
end_define

begin_define
define|#
directive|define
name|HDSPE_ENABLE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|HDSPM_CLOCK_MODE_MASTER
value|(1<<4)
end_define

begin_comment
comment|/* Interrupts */
end_comment

begin_define
define|#
directive|define
name|HDSPE_AUDIO_IRQ_PENDING
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|HDSPE_AUDIO_INT_ENABLE
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|HDSPE_INTERRUPT_ACK
value|96
end_define

begin_comment
comment|/* Channels */
end_comment

begin_define
define|#
directive|define
name|HDSPE_MAX_SLOTS
value|64
end_define

begin_comment
comment|/* Mono channels */
end_comment

begin_define
define|#
directive|define
name|HDSPE_MAX_CHANS
value|(HDSPE_MAX_SLOTS / 2)
end_define

begin_comment
comment|/* Stereo pairs */
end_comment

begin_define
define|#
directive|define
name|HDSPE_CHANBUF_SAMPLES
value|(16 * 1024)
end_define

begin_define
define|#
directive|define
name|HDSPE_CHANBUF_SIZE
value|(4 * HDSPE_CHANBUF_SAMPLES)
end_define

begin_define
define|#
directive|define
name|HDSPE_DMASEGSIZE
value|(HDSPE_CHANBUF_SIZE * HDSPE_MAX_SLOTS)
end_define

begin_struct
struct|struct
name|hdspe_channel
block|{
name|uint32_t
name|left
decl_stmt|;
name|uint32_t
name|right
decl_stmt|;
name|char
modifier|*
name|descr
decl_stmt|;
name|uint32_t
name|play
decl_stmt|;
name|uint32_t
name|rec
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
specifier|static
name|MALLOC_DEFINE
argument_list|(
name|M_HDSPE
argument_list|,
literal|"hdspe"
argument_list|,
literal|"hdspe audio"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Channel registers */
end_comment

begin_struct
struct|struct
name|sc_chinfo
block|{
name|struct
name|snd_dbuf
modifier|*
name|buffer
decl_stmt|;
name|struct
name|pcm_channel
modifier|*
name|channel
decl_stmt|;
name|struct
name|sc_pcminfo
modifier|*
name|parent
decl_stmt|;
comment|/* Channel information */
name|uint32_t
name|dir
decl_stmt|;
name|uint32_t
name|format
decl_stmt|;
name|uint32_t
name|lslot
decl_stmt|;
name|uint32_t
name|rslot
decl_stmt|;
name|uint32_t
name|lvol
decl_stmt|;
name|uint32_t
name|rvol
decl_stmt|;
comment|/* Buffer */
name|uint32_t
modifier|*
name|data
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
comment|/* Flags */
name|uint32_t
name|run
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* PCM device private data */
end_comment

begin_struct
struct|struct
name|sc_pcminfo
block|{
name|device_t
name|dev
decl_stmt|;
name|uint32_t
function_decl|(
modifier|*
name|ih
function_decl|)
parameter_list|(
name|struct
name|sc_pcminfo
modifier|*
name|scp
parameter_list|)
function_decl|;
name|uint32_t
name|chnum
decl_stmt|;
name|struct
name|sc_chinfo
name|chan
index|[
name|HDSPE_MAX_CHANS
index|]
decl_stmt|;
name|struct
name|sc_info
modifier|*
name|sc
decl_stmt|;
name|struct
name|hdspe_channel
modifier|*
name|hc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* HDSPe device private data */
end_comment

begin_struct
struct|struct
name|sc_info
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|mtx
modifier|*
name|lock
decl_stmt|;
name|uint32_t
name|ctrl_register
decl_stmt|;
name|uint32_t
name|settings_register
decl_stmt|;
name|uint32_t
name|type
decl_stmt|;
comment|/* Control/Status register */
name|struct
name|resource
modifier|*
name|cs
decl_stmt|;
name|int
name|csid
decl_stmt|;
name|bus_space_tag_t
name|cst
decl_stmt|;
name|bus_space_handle_t
name|csh
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|int
name|irqid
decl_stmt|;
name|void
modifier|*
name|ih
decl_stmt|;
name|bus_dma_tag_t
name|dmat
decl_stmt|;
comment|/* Play/Record DMA buffers */
name|uint32_t
modifier|*
name|pbuf
decl_stmt|;
name|uint32_t
modifier|*
name|rbuf
decl_stmt|;
name|uint32_t
name|bufsize
decl_stmt|;
name|bus_dmamap_t
name|pmap
decl_stmt|;
name|bus_dmamap_t
name|rmap
decl_stmt|;
name|uint32_t
name|period
decl_stmt|;
name|uint32_t
name|speed
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|hdspe_read_1
parameter_list|(
name|sc
parameter_list|,
name|regno
parameter_list|)
define|\
value|bus_space_read_1((sc)->cst, (sc)->csh, (regno))
end_define

begin_define
define|#
directive|define
name|hdspe_read_2
parameter_list|(
name|sc
parameter_list|,
name|regno
parameter_list|)
define|\
value|bus_space_read_2((sc)->cst, (sc)->csh, (regno))
end_define

begin_define
define|#
directive|define
name|hdspe_read_4
parameter_list|(
name|sc
parameter_list|,
name|regno
parameter_list|)
define|\
value|bus_space_read_4((sc)->cst, (sc)->csh, (regno))
end_define

begin_define
define|#
directive|define
name|hdspe_write_1
parameter_list|(
name|sc
parameter_list|,
name|regno
parameter_list|,
name|data
parameter_list|)
define|\
value|bus_space_write_1((sc)->cst, (sc)->csh, (regno), (data))
end_define

begin_define
define|#
directive|define
name|hdspe_write_2
parameter_list|(
name|sc
parameter_list|,
name|regno
parameter_list|,
name|data
parameter_list|)
define|\
value|bus_space_write_2((sc)->cst, (sc)->csh, (regno), (data))
end_define

begin_define
define|#
directive|define
name|hdspe_write_4
parameter_list|(
name|sc
parameter_list|,
name|regno
parameter_list|,
name|data
parameter_list|)
define|\
value|bus_space_write_4((sc)->cst, (sc)->csh, (regno), (data))
end_define

end_unit

