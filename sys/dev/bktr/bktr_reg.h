begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Mark Tinguely and Jim Lowe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Mark Tinguely and Jim Lowe  * 4. The name of the author may not be used to endorse or promote products   *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $Id$  */
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
name|BROOKTREE_848_ID
value|0x0350109E
end_define

begin_typedef
typedef|typedef
specifier|volatile
name|u_int
name|breg_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BKTR_DSTATUS
value|0x000
end_define

begin_define
define|#
directive|define
name|BKTR_IFORM
value|0x004
end_define

begin_define
define|#
directive|define
name|BKTR_TDEC
value|0x008
end_define

begin_define
define|#
directive|define
name|BKTR_EVEN_CROP
value|0x00C
end_define

begin_define
define|#
directive|define
name|BKTR_ODD_CROP
value|0x08C
end_define

begin_define
define|#
directive|define
name|BKTR_E_VDELAY_LO
value|0x010
end_define

begin_define
define|#
directive|define
name|BKTR_O_VDELAY_LO
value|0x090
end_define

begin_define
define|#
directive|define
name|BKTR_E_VACTIVE_LO
value|0x014
end_define

begin_define
define|#
directive|define
name|BKTR_O_VACTIVE_LO
value|0x094
end_define

begin_define
define|#
directive|define
name|BKTR_E_DELAY_LO
value|0x018
end_define

begin_define
define|#
directive|define
name|BKTR_O_DELAY_LO
value|0x098
end_define

begin_define
define|#
directive|define
name|BKTR_E_HACTIVE_LO
value|0x01C
end_define

begin_define
define|#
directive|define
name|BKTR_O_HACTIVE_LO
value|0x09C
end_define

begin_define
define|#
directive|define
name|BKTR_E_HSCALE_HI
value|0x020
end_define

begin_define
define|#
directive|define
name|BKTR_O_HSCALE_HI
value|0x0A0
end_define

begin_define
define|#
directive|define
name|BKTR_E_HSCALE_LO
value|0x024
end_define

begin_define
define|#
directive|define
name|BKTR_O_HSCALE_LO
value|0x0A4
end_define

begin_define
define|#
directive|define
name|BKTR_BRIGHT
value|0x028
end_define

begin_define
define|#
directive|define
name|BKTR_E_CONTROL
value|0x02C
end_define

begin_define
define|#
directive|define
name|BKTR_O_CONTROL
value|0x0AC
end_define

begin_define
define|#
directive|define
name|BKTR_CONTRAST_LO
value|0x030
end_define

begin_define
define|#
directive|define
name|BKTR_SAT_U_LO
value|0x034
end_define

begin_define
define|#
directive|define
name|BKTR_SAT_V_LO
value|0x038
end_define

begin_define
define|#
directive|define
name|BKTR_HUE
value|0x03C
end_define

begin_define
define|#
directive|define
name|BKTR_E_SCLOOP
value|0x040
end_define

begin_define
define|#
directive|define
name|BKTR_O_SCLOOP
value|0x0C0
end_define

begin_define
define|#
directive|define
name|BKTR_OFORM
value|0x048
end_define

begin_define
define|#
directive|define
name|BKTR_E_VSCALE_HI
value|0x04C
end_define

begin_define
define|#
directive|define
name|BKTR_O_VSCALE_HI
value|0x0CC
end_define

begin_define
define|#
directive|define
name|BKTR_E_VSCALE_LO
value|0x050
end_define

begin_define
define|#
directive|define
name|BKTR_O_VSCALE_LO
value|0x0D0
end_define

begin_define
define|#
directive|define
name|BKTR_TEST
value|0x054
end_define

begin_define
define|#
directive|define
name|BKTR_ADELAY
value|0x060
end_define

begin_define
define|#
directive|define
name|BKTR_BDELAY
value|0x064
end_define

begin_define
define|#
directive|define
name|BKTR_ADC
value|0x068
end_define

begin_define
define|#
directive|define
name|BKTR_E_VTC
value|0x06C
end_define

begin_define
define|#
directive|define
name|BKTR_O_VTC
value|0x0EC
end_define

begin_define
define|#
directive|define
name|BKTR_SRESET
value|0x07C
end_define

begin_define
define|#
directive|define
name|BKTR_COLOR_FMT
value|0x0D4
end_define

begin_define
define|#
directive|define
name|BKTR_COLOR_CTL
value|0x0D8
end_define

begin_define
define|#
directive|define
name|BKTR_CAP_CTL
value|0x0DC
end_define

begin_define
define|#
directive|define
name|BKTR_VBI_PACK_SIZE
value|0x0E0
end_define

begin_define
define|#
directive|define
name|BKTR_VBI_PACK_DEL
value|0x0E4
end_define

begin_define
define|#
directive|define
name|BKTR_INT_STAT
value|0x100
end_define

begin_define
define|#
directive|define
name|BKTR_INT_MASK
value|0x104
end_define

begin_define
define|#
directive|define
name|BKTR_RISC_COUNT
value|0x120
end_define

begin_define
define|#
directive|define
name|BKTR_RISC_STRT_ADD
value|0x114
end_define

begin_define
define|#
directive|define
name|BKTR_GPIO_DMA_CTL
value|0x10C
end_define

begin_define
define|#
directive|define
name|BKTR_GPIO_OUT_EN
value|0x118
end_define

begin_define
define|#
directive|define
name|BKTR_GPIO_REG_INP
value|0x11C
end_define

begin_define
define|#
directive|define
name|BKTR_GPIO_DATA
value|0x200
end_define

begin_define
define|#
directive|define
name|BKTR_I2C_CONTROL
value|0x110
end_define

begin_comment
comment|/*  * device support for onboard tv tuners  */
end_comment

begin_struct
struct|struct
name|tvtuner
block|{
name|int
name|frequency
decl_stmt|;
name|u_char
name|tunertype
decl_stmt|;
name|u_char
name|channel
decl_stmt|;
name|u_char
name|band
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * BrookTree 848  info structure, one per bt848 card installed.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bktr_softc
block|{
name|char
modifier|*
name|base
decl_stmt|;
comment|/* saa7116 register physical address */
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
name|vm_offset_t
name|dma_prog
decl_stmt|;
name|vm_offset_t
name|odd_dma_prog
decl_stmt|;
name|char
name|dma_prog_loaded
decl_stmt|;
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
name|u_long
name|format
decl_stmt|;
comment|/* frame format rgb, yuv, etc.. */
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
name|u_short
name|capcontrol
decl_stmt|;
comment|/* reg 0xdc capture control */
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
name|u_short
name|fps
decl_stmt|;
comment|/* frames per second */
ifdef|#
directive|ifdef
name|DEVFS
name|void
modifier|*
name|devfs_token
decl_stmt|;
endif|#
directive|endif
name|struct
name|meteor_video
name|video
decl_stmt|;
name|struct
name|tvtuner
name|tuner
decl_stmt|;
block|}
name|bktr_reg_t
typedef|;
end_typedef

end_unit

