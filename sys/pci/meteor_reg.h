begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Mark Tinguely and Jim Lowe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Mark Tinguely and Jim Lowe  * 4. The name of the author may not be used to endorse or promote products   *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_LATENCY_TIMER
end_ifndef

begin_define
define|#
directive|define
name|PCI_LATENCY_TIMER
value|0x0c
end_define

begin_comment
comment|/* pci timer register */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Definitions for the Philips SAA7116 digital video to pci interface.  */
end_comment

begin_define
define|#
directive|define
name|SAA7116_PHILIPS_ID
value|0x12238086ul
end_define

begin_define
define|#
directive|define
name|SAA7116_I2C_WRITE
value|0x00
end_define

begin_define
define|#
directive|define
name|SAA7116_I2C_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|SAA7116_IIC_NEW_CYCLE
value|0x1000000L
end_define

begin_define
define|#
directive|define
name|SAA7116_IIC_DIRECT_TRANSFER_ABORTED
value|0x0000200L
end_define

begin_typedef
typedef|typedef
specifier|volatile
name|u_int
name|mreg_t
typedef|;
end_typedef

begin_struct
struct|struct
name|saa7116_regs
block|{
name|mreg_t
name|dma1e
decl_stmt|;
comment|/* Base address for even field dma chn 1 */
name|mreg_t
name|dma2e
decl_stmt|;
comment|/* Base address for even field dma chn 2 */
name|mreg_t
name|dma3e
decl_stmt|;
comment|/* Base address for even field dma chn 3 */
name|mreg_t
name|dma1o
decl_stmt|;
comment|/* Base address for odd field dma chn 1 */
name|mreg_t
name|dma2o
decl_stmt|;
comment|/* Base address for odd field dma chn 2 */
name|mreg_t
name|dma3o
decl_stmt|;
comment|/* Base address for odd field dma chn 3 */
name|mreg_t
name|stride1e
decl_stmt|;
comment|/* Address stride for even field dma chn 1 */
name|mreg_t
name|stride2e
decl_stmt|;
comment|/* Address stride for even field dma chn 2 */
name|mreg_t
name|stride3e
decl_stmt|;
comment|/* Address stride for even field dma chn 3 */
name|mreg_t
name|stride1o
decl_stmt|;
comment|/* Address stride for odd field dma chn 1 */
name|mreg_t
name|stride2o
decl_stmt|;
comment|/* Address stride for odd field dma chn 2 */
name|mreg_t
name|stride3o
decl_stmt|;
comment|/* Address stride for odd field dma chn 3 */
name|mreg_t
name|routee
decl_stmt|;
comment|/* Route/mode even */
name|mreg_t
name|routeo
decl_stmt|;
comment|/* Route/mode odd */
name|mreg_t
name|fifo_t
decl_stmt|;
comment|/* FIFO trigger for PCI int */
name|mreg_t
name|field_t
decl_stmt|;
comment|/* Field toggle */
name|mreg_t
name|cap_cntl
decl_stmt|;
comment|/* Capture control */
name|mreg_t
name|retry_wait_cnt
decl_stmt|;
comment|/* Clks for master to wait after disconnect */
name|mreg_t
name|irq_stat
decl_stmt|;
comment|/* IRQ mask and status reg */
name|mreg_t
name|fme
decl_stmt|;
comment|/* Field Mask even */
name|mreg_t
name|fmo
decl_stmt|;
comment|/* Field mask odd */
name|mreg_t
name|fml
decl_stmt|;
comment|/* Field mask length */
name|mreg_t
name|fifo_t_err
decl_stmt|;
comment|/* FIFO almost empty/almost full ptrs */
name|mreg_t
name|i2c_phase
decl_stmt|;
comment|/* i2c phase register */
name|mreg_t
name|i2c_read
decl_stmt|;
comment|/* i2c read register */
name|mreg_t
name|i2c_write
decl_stmt|;
comment|/* i2c write register */
name|mreg_t
name|i2c_auto_a_e
decl_stmt|;
comment|/* i2c auto register a, even */
name|mreg_t
name|i2c_auto_b_e
decl_stmt|;
comment|/* i2c auto register b, even */
name|mreg_t
name|i2c_auto_c_e
decl_stmt|;
comment|/* i2c auto register c, even */
name|mreg_t
name|i2c_auto_d_e
decl_stmt|;
comment|/* i2c auto register d, even */
name|mreg_t
name|i2c_auto_a_o
decl_stmt|;
comment|/* i2c auto register a, odd */
name|mreg_t
name|i2c_auto_b_o
decl_stmt|;
comment|/* i2c auto register b, odd */
name|mreg_t
name|i2c_auto_c_o
decl_stmt|;
comment|/* i2c auto register c, odd */
name|mreg_t
name|i2c_auto_d_o
decl_stmt|;
comment|/* i2c auto register d, odd */
name|mreg_t
name|i2c_auto_enable
decl_stmt|;
comment|/* enable above auto registers */
name|mreg_t
name|dma_end_e
decl_stmt|;
comment|/* DMA end even (range) */
name|mreg_t
name|dma_end_o
decl_stmt|;
comment|/* DMA end odd (range) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Definitions for the Philips SAA7196 digital video decoder,  * scalar, and clock generator circuit (DESCpro).  */
end_comment

begin_define
define|#
directive|define
name|NUM_SAA7196_I2C_REGS
value|49
end_define

begin_define
define|#
directive|define
name|SAA7196_I2C_ADDR
value|0x40
end_define

begin_define
define|#
directive|define
name|SAA7196_WRITE
parameter_list|(
name|mtr
parameter_list|,
name|reg
parameter_list|,
name|data
parameter_list|)
define|\
value|i2c_write(mtr, SAA7196_I2C_ADDR, SAA7116_I2C_WRITE, reg, data), \ 	mtr->saa7196_i2c[reg] = data
end_define

begin_define
define|#
directive|define
name|SAA7196_REG
parameter_list|(
name|mtr
parameter_list|,
name|reg
parameter_list|)
value|mtr->saa7196_i2c[reg]
end_define

begin_define
define|#
directive|define
name|SAA7196_READ
parameter_list|(
name|mtr
parameter_list|)
define|\
value|i2c_write(mtr, SAA7196_I2C_ADDR, SAA7116_I2C_READ, 0x0, 0x0)
end_define

begin_define
define|#
directive|define
name|SAA7196_IDEL
value|0x00
end_define

begin_comment
comment|/* Increment delay */
end_comment

begin_define
define|#
directive|define
name|SAA7196_HSB5
value|0x01
end_define

begin_comment
comment|/* H-sync begin; 50 hz */
end_comment

begin_define
define|#
directive|define
name|SAA7196_HSS5
value|0x02
end_define

begin_comment
comment|/* H-sync stop; 50 hz */
end_comment

begin_define
define|#
directive|define
name|SAA7196_HCB5
value|0x03
end_define

begin_comment
comment|/* H-clamp begin; 50 hz */
end_comment

begin_define
define|#
directive|define
name|SAA7196_HCS5
value|0x04
end_define

begin_comment
comment|/* H-clamp stop; 50 hz */
end_comment

begin_define
define|#
directive|define
name|SAA7196_HSP5
value|0x05
end_define

begin_comment
comment|/* H-sync after PHI1; 50 hz */
end_comment

begin_define
define|#
directive|define
name|SAA7196_LUMC
value|0x06
end_define

begin_comment
comment|/* Luminance control */
end_comment

begin_define
define|#
directive|define
name|SAA7196_HUEC
value|0x07
end_define

begin_comment
comment|/* Hue control */
end_comment

begin_define
define|#
directive|define
name|SAA7196_CKTQ
value|0x08
end_define

begin_comment
comment|/* Colour Killer Threshold QAM (PAL, NTSC) */
end_comment

begin_define
define|#
directive|define
name|SAA7196_CKTS
value|0x09
end_define

begin_comment
comment|/* Colour Killer Threshold SECAM */
end_comment

begin_define
define|#
directive|define
name|SAA7196_PALS
value|0x0a
end_define

begin_comment
comment|/* PAL switch sensitivity */
end_comment

begin_define
define|#
directive|define
name|SAA7196_SECAMS
value|0x0b
end_define

begin_comment
comment|/* SECAM switch sensitivity */
end_comment

begin_define
define|#
directive|define
name|SAA7196_CGAINC
value|0x0c
end_define

begin_comment
comment|/* Chroma gain control */
end_comment

begin_define
define|#
directive|define
name|SAA7196_STDC
value|0x0d
end_define

begin_comment
comment|/* Standard/Mode control */
end_comment

begin_define
define|#
directive|define
name|SAA7196_IOCC
value|0x0e
end_define

begin_comment
comment|/* I/O and Clock Control */
end_comment

begin_define
define|#
directive|define
name|SAA7196_CTRL1
value|0x0f
end_define

begin_comment
comment|/* Control #1 */
end_comment

begin_define
define|#
directive|define
name|SAA7196_CTRL2
value|0x10
end_define

begin_comment
comment|/* Control #2 */
end_comment

begin_define
define|#
directive|define
name|SAA7196_CGAINR
value|0x11
end_define

begin_comment
comment|/* Chroma Gain Reference */
end_comment

begin_define
define|#
directive|define
name|SAA7196_CSAT
value|0x12
end_define

begin_comment
comment|/* Chroma Saturation */
end_comment

begin_define
define|#
directive|define
name|SAA7196_CONT
value|0x13
end_define

begin_comment
comment|/* Luminance Contrast */
end_comment

begin_define
define|#
directive|define
name|SAA7196_HSB6
value|0x14
end_define

begin_comment
comment|/* H-sync begin; 60 hz */
end_comment

begin_define
define|#
directive|define
name|SAA7196_HSS6
value|0x15
end_define

begin_comment
comment|/* H-sync stop; 60 hz */
end_comment

begin_define
define|#
directive|define
name|SAA7196_HCB6
value|0x16
end_define

begin_comment
comment|/* H-clamp begin; 60 hz */
end_comment

begin_define
define|#
directive|define
name|SAA7196_HCS6
value|0x17
end_define

begin_comment
comment|/* H-clamp stop; 60 hz */
end_comment

begin_define
define|#
directive|define
name|SAA7196_HSP6
value|0x18
end_define

begin_comment
comment|/* H-sync after PHI1; 60 hz */
end_comment

begin_define
define|#
directive|define
name|SAA7196_BRIG
value|0x19
end_define

begin_comment
comment|/* Luminance Brightness */
end_comment

begin_define
define|#
directive|define
name|SAA7196_FMTS
value|0x20
end_define

begin_comment
comment|/* Formats and sequence */
end_comment

begin_define
define|#
directive|define
name|SAA7196_OUTPIX
value|0x21
end_define

begin_comment
comment|/* Output data pixel/line */
end_comment

begin_define
define|#
directive|define
name|SAA7196_INPIX
value|0x22
end_define

begin_comment
comment|/* Input data pixel/line */
end_comment

begin_define
define|#
directive|define
name|SAA7196_HWS
value|0x23
end_define

begin_comment
comment|/* Horiz. window start */
end_comment

begin_define
define|#
directive|define
name|SAA7196_HFILT
value|0x24
end_define

begin_comment
comment|/* Horiz. filter */
end_comment

begin_define
define|#
directive|define
name|SAA7196_OUTLINE
value|0x25
end_define

begin_comment
comment|/* Output data lines/field */
end_comment

begin_define
define|#
directive|define
name|SAA7196_INLINE
value|0x26
end_define

begin_comment
comment|/* Input data lines/field */
end_comment

begin_define
define|#
directive|define
name|SAA7196_VWS
value|0x27
end_define

begin_comment
comment|/* Vertical window start */
end_comment

begin_define
define|#
directive|define
name|SAA7196_VYP
value|0x28
end_define

begin_comment
comment|/* AFS/vertical Y processing */
end_comment

begin_define
define|#
directive|define
name|SAA7196_VBS
value|0x29
end_define

begin_comment
comment|/* Vertical Bypass start */
end_comment

begin_define
define|#
directive|define
name|SAA7196_VBCNT
value|0x2a
end_define

begin_comment
comment|/* Vertical Bypass count */
end_comment

begin_define
define|#
directive|define
name|SAA7196_VBP
value|0x2b
end_define

begin_comment
comment|/* veritcal Bypass Polarity */
end_comment

begin_define
define|#
directive|define
name|SAA7196_VLOW
value|0x2c
end_define

begin_comment
comment|/* Colour-keying lower V limit */
end_comment

begin_define
define|#
directive|define
name|SAA7196_VHIGH
value|0x2d
end_define

begin_comment
comment|/* Colour-keying upper V limit */
end_comment

begin_define
define|#
directive|define
name|SAA7196_ULOW
value|0x2e
end_define

begin_comment
comment|/* Colour-keying lower U limit */
end_comment

begin_define
define|#
directive|define
name|SAA7196_UHIGH
value|0x2f
end_define

begin_comment
comment|/* Colour-keying upper U limit */
end_comment

begin_define
define|#
directive|define
name|SAA7196_DPATH
value|0x30
end_define

begin_comment
comment|/* Data path setting  */
end_comment

begin_comment
comment|/*  * Defines for the PCF8574.  */
end_comment

begin_define
define|#
directive|define
name|NUM_PCF8574_I2C_REGS
value|2
end_define

begin_define
define|#
directive|define
name|PCF8574_CTRL_I2C_ADDR
value|0x70
end_define

begin_define
define|#
directive|define
name|PCF8574_DATA_I2C_ADDR
value|0x72
end_define

begin_define
define|#
directive|define
name|PCF8574_CTRL_WRITE
parameter_list|(
name|mtr
parameter_list|,
name|data
parameter_list|)
define|\
value|i2c_write(mtr,  PCF8574_CTRL_I2C_ADDR, SAA7116_I2C_WRITE, data, data), \ 	mtr->pcf_i2c[0] = data
end_define

begin_define
define|#
directive|define
name|PCF8574_DATA_WRITE
parameter_list|(
name|mtr
parameter_list|,
name|data
parameter_list|)
define|\
value|i2c_write(mtr,  PCF8574_DATA_I2C_ADDR, SAA7116_I2C_WRITE, data, data), \ 	mtr->pcf_i2c[1] = data
end_define

begin_define
define|#
directive|define
name|PCF8574_CTRL_REG
parameter_list|(
name|mtr
parameter_list|)
value|mtr->pcf_i2c[0]
end_define

begin_define
define|#
directive|define
name|PCF8574_DATA_REG
parameter_list|(
name|mtr
parameter_list|)
value|mtr->pcf_i2c[1]
end_define

begin_comment
comment|/*  * Defines for the BT254.  */
end_comment

begin_define
define|#
directive|define
name|NUM_BT254_REGS
value|7
end_define

begin_define
define|#
directive|define
name|BT254_COMMAND
value|0
end_define

begin_define
define|#
directive|define
name|BT254_IOUT1
value|1
end_define

begin_define
define|#
directive|define
name|BT254_IOUT2
value|2
end_define

begin_define
define|#
directive|define
name|BT254_IOUT3
value|3
end_define

begin_define
define|#
directive|define
name|BT254_IOUT4
value|4
end_define

begin_define
define|#
directive|define
name|BT254_IOUT5
value|5
end_define

begin_define
define|#
directive|define
name|BT254_IOUT6
value|6
end_define

begin_comment
comment|/*  * Meteor info structure, one per meteor card installed.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|meteor_softc
block|{
name|struct
name|saa7116_regs
modifier|*
name|base
decl_stmt|;
comment|/* saa7116 register virtual address */
name|vm_offset_t
name|phys_base
decl_stmt|;
comment|/* saa7116 register physical address */
name|pcici_t
name|tag
decl_stmt|;
comment|/* PCI tag, for doing PCI commands */
name|vm_offset_t
name|bigbuf
decl_stmt|;
comment|/* buffer that holds the captured image */
name|int
name|alloc_pages
decl_stmt|;
comment|/* number of pages in bigbuf */
name|struct
name|proc
modifier|*
name|proc
decl_stmt|;
comment|/* process to receive raised signal */
name|int
name|signal
decl_stmt|;
comment|/* signal to send to process */
define|#
directive|define
name|METEOR_SIG_MODE_MASK
value|0xffff0000
define|#
directive|define
name|METEOR_SIG_FIELD_MODE
value|0x00010000
define|#
directive|define
name|METEOR_SIG_FRAME_MODE
value|0x00000000
name|struct
name|meteor_mem
modifier|*
name|mem
decl_stmt|;
comment|/* used to control sync. multi-frame output */
name|u_long
name|synch_wait
decl_stmt|;
comment|/* wait for free buffer before continuing */
name|short
name|current
decl_stmt|;
comment|/* frame number in buffer (1-frames) */
name|short
name|rows
decl_stmt|;
comment|/* number of rows in a frame */
name|short
name|cols
decl_stmt|;
comment|/* number of columns in a frame */
name|short
name|depth
decl_stmt|;
comment|/* number of byte per pixel */
name|short
name|frames
decl_stmt|;
comment|/* number of frames allocated */
name|int
name|frame_size
decl_stmt|;
comment|/* number of bytes in a frame */
name|u_long
name|fifo_errors
decl_stmt|;
comment|/* number of fifo capture errors since open */
name|u_long
name|dma_errors
decl_stmt|;
comment|/* number of DMA capture errors since open */
name|u_long
name|frames_captured
decl_stmt|;
comment|/* number of frames captured since open */
name|u_long
name|even_fields_captured
decl_stmt|;
comment|/* number of even fields captured */
name|u_long
name|odd_fields_captured
decl_stmt|;
comment|/* number of odd fields captured */
name|u_long
name|range_enable
decl_stmt|;
comment|/* enable range checking ?? */
name|unsigned
name|flags
decl_stmt|;
define|#
directive|define
name|METEOR_INITALIZED
value|0x00000001
define|#
directive|define
name|METEOR_OPEN
value|0x00000002
define|#
directive|define
name|METEOR_MMAP
value|0x00000004
define|#
directive|define
name|METEOR_INTR
value|0x00000008
define|#
directive|define
name|METEOR_READ
value|0x00000010
comment|/* XXX never gets referenced */
define|#
directive|define
name|METEOR_SINGLE
value|0x00000020
comment|/* get single frame */
define|#
directive|define
name|METEOR_CONTIN
value|0x00000040
comment|/* continuously get frames */
define|#
directive|define
name|METEOR_SYNCAP
value|0x00000080
comment|/* synchronously get frames */
define|#
directive|define
name|METEOR_CAP_MASK
value|0x000000f0
define|#
directive|define
name|METEOR_NTSC
value|0x00000100
define|#
directive|define
name|METEOR_PAL
value|0x00000200
define|#
directive|define
name|METEOR_SECAM
value|0x00000400
define|#
directive|define
name|METEOR_AUTOMODE
value|0x00000800
define|#
directive|define
name|METEOR_FORM_MASK
value|0x00000f00
define|#
directive|define
name|METEOR_DEV0
value|0x00001000
define|#
directive|define
name|METEOR_DEV1
value|0x00002000
define|#
directive|define
name|METEOR_DEV2
value|0x00004000
define|#
directive|define
name|METEOR_DEV3
value|0x00008000
define|#
directive|define
name|METEOR_DEV_SVIDEO
value|0x00006000
define|#
directive|define
name|METEOR_DEV_RGB
value|0x0000a000
define|#
directive|define
name|METEOR_DEV_MASK
value|0x0000f000
define|#
directive|define
name|METEOR_RGB16
value|0x00010000
define|#
directive|define
name|METEOR_RGB24
value|0x00020000
define|#
directive|define
name|METEOR_YUV_PACKED
value|0x00040000
define|#
directive|define
name|METEOR_YUV_PLANAR
value|0x00080000
define|#
directive|define
name|METEOR_WANT_EVEN
value|0x00100000
comment|/* want even frame */
define|#
directive|define
name|METEOR_WANT_ODD
value|0x00200000
comment|/* want odd frame */
define|#
directive|define
name|METEOR_WANT_MASK
value|0x00300000
define|#
directive|define
name|METEOR_ONLY_EVEN_FIELDS
value|0x01000000
define|#
directive|define
name|METEOR_ONLY_ODD_FIELDS
value|0x02000000
define|#
directive|define
name|METEOR_ONLY_FIELDS_MASK
value|0x03000000
define|#
directive|define
name|METEOR_YUV_422
value|0x04000000
define|#
directive|define
name|METEOR_OUTPUT_FMT_MASK
value|0x040f0000
define|#
directive|define
name|METEOR_WANT_TS
value|0x08000000
comment|/* time-stamp a frame */
define|#
directive|define
name|METEOR_RGB
value|0x20000000
comment|/* meteor rgb unit */
define|#
directive|define
name|METEOR_FIELD_MODE
value|0x80000000
name|u_char
name|saa7196_i2c
index|[
name|NUM_SAA7196_I2C_REGS
index|]
decl_stmt|;
comment|/* saa7196 register values */
name|u_char
name|pcf_i2c
index|[
name|NUM_PCF8574_I2C_REGS
index|]
decl_stmt|;
comment|/* PCF8574 register values */
name|u_char
name|bt254_reg
index|[
name|NUM_BT254_REGS
index|]
decl_stmt|;
comment|/* BT254 register values */
name|u_short
name|fps
decl_stmt|;
comment|/* frames per second */
ifdef|#
directive|ifdef
name|METEOR_TEST_VIDEO
name|struct
name|meteor_video
name|video
decl_stmt|;
endif|#
directive|endif
block|}
name|meteor_reg_t
typedef|;
end_typedef

end_unit

