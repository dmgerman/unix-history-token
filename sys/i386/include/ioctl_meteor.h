begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Mark Tinguely and Jim Lowe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Mark Tinguely and Jim Lowe  * 4. The name of the author may not be used to endorse or promote products   *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *	ioctl constants for Matrox Meteor Capture card.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IOCTL_METEOR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IOCTL_METEOR_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_struct
struct|struct
name|meteor_capframe
block|{
name|short
name|command
decl_stmt|;
comment|/* see below for valid METEORCAPFRM commands */
name|short
name|lowat
decl_stmt|;
comment|/* start transfer if< this number */
name|short
name|hiwat
decl_stmt|;
comment|/* stop transfer if> this number */
block|}
struct|;
end_struct

begin_comment
comment|/* structure for METEOR[GS]ETGEO - get/set geometry  */
end_comment

begin_struct
struct|struct
name|meteor_geomet
block|{
name|u_short
name|rows
decl_stmt|;
name|u_short
name|columns
decl_stmt|;
name|u_short
name|frames
decl_stmt|;
name|u_long
name|oformat
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* structure for METEORGCOUNT-get count of frames, fifo errors and dma errors */
end_comment

begin_struct
struct|struct
name|meteor_counts
block|{
name|u_long
name|fifo_errors
decl_stmt|;
comment|/* count of fifo errors since open */
name|u_long
name|dma_errors
decl_stmt|;
comment|/* count of dma errors since open */
name|u_long
name|frames_captured
decl_stmt|;
comment|/* count of frames captured since open */
name|u_long
name|even_fields_captured
decl_stmt|;
comment|/* count of even fields captured */
name|u_long
name|odd_fields_captured
decl_stmt|;
comment|/* count of odd fields captured */
block|}
struct|;
end_struct

begin_comment
comment|/* structure for getting and setting direct transfers to vram */
end_comment

begin_struct
struct|struct
name|meteor_video
block|{
name|u_long
name|addr
decl_stmt|;
comment|/* Address of location to dma to */
name|u_long
name|width
decl_stmt|;
comment|/* Width of memory area */
name|u_long
name|banksize
decl_stmt|;
comment|/* Size of Vram bank */
name|u_long
name|ramsize
decl_stmt|;
comment|/* Size of Vram */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|METEORCAPTUR
value|_IOW('x', 1, int)
end_define

begin_comment
comment|/* capture a frame */
end_comment

begin_define
define|#
directive|define
name|METEORCAPFRM
value|_IOW('x', 2, struct meteor_capframe)
end_define

begin_comment
comment|/* sync capture */
end_comment

begin_define
define|#
directive|define
name|METEORSETGEO
value|_IOW('x', 3, struct meteor_geomet)
end_define

begin_comment
comment|/* set geometry */
end_comment

begin_define
define|#
directive|define
name|METEORGETGEO
value|_IOR('x', 4, struct meteor_geomet)
end_define

begin_comment
comment|/* get geometry */
end_comment

begin_define
define|#
directive|define
name|METEORSTATUS
value|_IOR('x', 5, unsigned short)
end_define

begin_comment
comment|/* get status */
end_comment

begin_define
define|#
directive|define
name|METEORSHUE
value|_IOW('x', 6, signed char)
end_define

begin_comment
comment|/* set hue */
end_comment

begin_define
define|#
directive|define
name|METEORGHUE
value|_IOR('x', 6, signed char)
end_define

begin_comment
comment|/* get hue */
end_comment

begin_define
define|#
directive|define
name|METEORSFMT
value|_IOW('x', 7, unsigned long)
end_define

begin_comment
comment|/* set format */
end_comment

begin_define
define|#
directive|define
name|METEORGFMT
value|_IOR('x', 7, unsigned long)
end_define

begin_comment
comment|/* get format */
end_comment

begin_define
define|#
directive|define
name|METEORSINPUT
value|_IOW('x', 8, unsigned long)
end_define

begin_comment
comment|/* set input dev */
end_comment

begin_define
define|#
directive|define
name|METEORGINPUT
value|_IOR('x', 8, unsigned long)
end_define

begin_comment
comment|/* get input dev */
end_comment

begin_define
define|#
directive|define
name|METEORSCHCV
value|_IOW('x', 9, unsigned char)
end_define

begin_comment
comment|/* set uv gain */
end_comment

begin_define
define|#
directive|define
name|METEORGCHCV
value|_IOR('x', 9, unsigned char)
end_define

begin_comment
comment|/* get uv gain */
end_comment

begin_define
define|#
directive|define
name|METEORSCOUNT
value|_IOW('x',10, struct meteor_counts)
end_define

begin_define
define|#
directive|define
name|METEORGCOUNT
value|_IOR('x',10, struct meteor_counts)
end_define

begin_define
define|#
directive|define
name|METEORSFPS
value|_IOW('x',11, unsigned short)
end_define

begin_comment
comment|/* set fps */
end_comment

begin_define
define|#
directive|define
name|METEORGFPS
value|_IOR('x',11, unsigned short)
end_define

begin_comment
comment|/* get fps */
end_comment

begin_define
define|#
directive|define
name|METEORSSIGNAL
value|_IOW('x', 12, unsigned int)
end_define

begin_comment
comment|/* set signal */
end_comment

begin_define
define|#
directive|define
name|METEORGSIGNAL
value|_IOR('x', 12, unsigned int)
end_define

begin_comment
comment|/* get signal */
end_comment

begin_define
define|#
directive|define
name|METEORSVIDEO
value|_IOW('x', 13, struct meteor_video)
end_define

begin_comment
comment|/* set video */
end_comment

begin_define
define|#
directive|define
name|METEORGVIDEO
value|_IOR('x', 13, struct meteor_video)
end_define

begin_comment
comment|/* get video */
end_comment

begin_define
define|#
directive|define
name|METEORSBRIG
value|_IOW('x', 14, unsigned char)
end_define

begin_comment
comment|/* set brightness */
end_comment

begin_define
define|#
directive|define
name|METEORGBRIG
value|_IOR('x', 14, unsigned char)
end_define

begin_comment
comment|/* get brightness */
end_comment

begin_define
define|#
directive|define
name|METEORSCSAT
value|_IOW('x', 15, unsigned char)
end_define

begin_comment
comment|/* set chroma sat */
end_comment

begin_define
define|#
directive|define
name|METEORGCSAT
value|_IOR('x', 15, unsigned char)
end_define

begin_comment
comment|/* get uv saturation */
end_comment

begin_define
define|#
directive|define
name|METEORSCONT
value|_IOW('x', 16, unsigned char)
end_define

begin_comment
comment|/* set contrast */
end_comment

begin_define
define|#
directive|define
name|METEORGCONT
value|_IOR('x', 16, unsigned char)
end_define

begin_comment
comment|/* get contrast */
end_comment

begin_define
define|#
directive|define
name|METEORSBT254
value|_IOW('x', 17, unsigned short)
end_define

begin_comment
comment|/* set Bt254 reg */
end_comment

begin_define
define|#
directive|define
name|METEORGBT254
value|_IOR('x', 17, unsigned short)
end_define

begin_comment
comment|/* get Bt254 reg */
end_comment

begin_define
define|#
directive|define
name|METEORSHWS
value|_IOW('x', 18, unsigned char)
end_define

begin_comment
comment|/* set hor start reg */
end_comment

begin_define
define|#
directive|define
name|METEORGHWS
value|_IOR('x', 18, unsigned char)
end_define

begin_comment
comment|/* get hor start reg */
end_comment

begin_define
define|#
directive|define
name|METEORSVWS
value|_IOW('x', 19, unsigned char)
end_define

begin_comment
comment|/* set vert start reg */
end_comment

begin_define
define|#
directive|define
name|METEORGVWS
value|_IOR('x', 19, unsigned char)
end_define

begin_comment
comment|/* get vert start reg */
end_comment

begin_define
define|#
directive|define
name|METEORSTS
value|_IOW('x', 20, unsigned char)
end_define

begin_comment
comment|/* set time stamp */
end_comment

begin_define
define|#
directive|define
name|METEORGTS
value|_IOR('x', 20, unsigned char)
end_define

begin_comment
comment|/* get time stamp */
end_comment

begin_define
define|#
directive|define
name|METEOR_STATUS_ID_MASK
value|0xf000
end_define

begin_comment
comment|/* ID of 7196 */
end_comment

begin_define
define|#
directive|define
name|METEOR_STATUS_DIR
value|0x0800
end_define

begin_comment
comment|/* Direction of Expansion port YUV */
end_comment

begin_define
define|#
directive|define
name|METEOR_STATUS_OEF
value|0x0200
end_define

begin_comment
comment|/* Field detected: Even/Odd */
end_comment

begin_define
define|#
directive|define
name|METEOR_STATUS_SVP
value|0x0100
end_define

begin_comment
comment|/* State of VRAM Port:inactive/active */
end_comment

begin_define
define|#
directive|define
name|METEOR_STATUS_STTC
value|0x0080
end_define

begin_comment
comment|/* Time Constant: TV/VCR */
end_comment

begin_define
define|#
directive|define
name|METEOR_STATUS_HCLK
value|0x0040
end_define

begin_comment
comment|/* Horiz PLL: locked/unlocked */
end_comment

begin_define
define|#
directive|define
name|METEOR_STATUS_FIDT
value|0x0020
end_define

begin_comment
comment|/* Field detect: 50/60hz */
end_comment

begin_define
define|#
directive|define
name|METEOR_STATUS_ALTD
value|0x0002
end_define

begin_comment
comment|/* Line alt: no line alt/line alt */
end_comment

begin_define
define|#
directive|define
name|METEOR_STATUS_CODE
value|0x0001
end_define

begin_comment
comment|/* Colour info: no colour/colour */
end_comment

begin_comment
comment|/* METEORCAPTUR capture options */
end_comment

begin_define
define|#
directive|define
name|METEOR_CAP_SINGLE
value|0x0001
end_define

begin_comment
comment|/* capture one frame */
end_comment

begin_define
define|#
directive|define
name|METEOR_CAP_CONTINOUS
value|0x0002
end_define

begin_comment
comment|/* continuously capture */
end_comment

begin_define
define|#
directive|define
name|METEOR_CAP_STOP_CONT
value|0x0004
end_define

begin_comment
comment|/* stop the continuous capture */
end_comment

begin_comment
comment|/* METEORCAPFRM capture commands */
end_comment

begin_define
define|#
directive|define
name|METEOR_CAP_N_FRAMES
value|0x0001
end_define

begin_comment
comment|/* capture N frames */
end_comment

begin_define
define|#
directive|define
name|METEOR_CAP_STOP_FRAMES
value|0x0002
end_define

begin_comment
comment|/* stop capture N frames */
end_comment

begin_define
define|#
directive|define
name|METEOR_HALT_N_FRAMES
value|0x0003
end_define

begin_comment
comment|/* halt of capture N frames */
end_comment

begin_define
define|#
directive|define
name|METEOR_CONT_N_FRAMES
value|0x0004
end_define

begin_comment
comment|/* continue after above halt */
end_comment

begin_comment
comment|/* valid video input formats:  */
end_comment

begin_define
define|#
directive|define
name|METEOR_FMT_NTSC
value|0x00100
end_define

begin_comment
comment|/* NTSC --  initialized default */
end_comment

begin_define
define|#
directive|define
name|METEOR_FMT_PAL
value|0x00200
end_define

begin_comment
comment|/* PAL */
end_comment

begin_define
define|#
directive|define
name|METEOR_FMT_SECAM
value|0x00400
end_define

begin_comment
comment|/* SECAM */
end_comment

begin_define
define|#
directive|define
name|METEOR_FMT_AUTOMODE
value|0x00800
end_define

begin_comment
comment|/* auto-mode */
end_comment

begin_define
define|#
directive|define
name|METEOR_INPUT_DEV0
value|0x01000
end_define

begin_comment
comment|/* camera input 0 -- default */
end_comment

begin_define
define|#
directive|define
name|METEOR_INPUT_DEV_RCA
value|METEOR_INPUT_DEV0
end_define

begin_define
define|#
directive|define
name|METEOR_INPUT_DEV1
value|0x02000
end_define

begin_comment
comment|/* camera input 1 */
end_comment

begin_define
define|#
directive|define
name|METEOR_INPUT_DEV2
value|0x04000
end_define

begin_comment
comment|/* camera input 2 */
end_comment

begin_define
define|#
directive|define
name|METEOR_INPUT_DEV3
value|0x08000
end_define

begin_comment
comment|/* camera input 3 */
end_comment

begin_define
define|#
directive|define
name|METEOR_INPUT_DEV_RGB
value|0x0a000
end_define

begin_comment
comment|/* for rgb version of meteor */
end_comment

begin_define
define|#
directive|define
name|METEOR_INPUT_DEV_SVIDEO
value|0x06000
end_define

begin_comment
comment|/* S-video input port */
end_comment

begin_comment
comment|/* valid video output formats:  */
end_comment

begin_define
define|#
directive|define
name|METEOR_GEO_RGB16
value|0x0010000
end_define

begin_comment
comment|/* packed -- initialized default */
end_comment

begin_define
define|#
directive|define
name|METEOR_GEO_RGB24
value|0x0020000
end_define

begin_comment
comment|/* RBG 24 bits packed */
end_comment

begin_comment
comment|/* internally stored in 32 bits */
end_comment

begin_define
define|#
directive|define
name|METEOR_GEO_YUV_PACKED
value|0x0040000
end_define

begin_comment
comment|/* 4-2-2 YUV 16 bits packed */
end_comment

begin_define
define|#
directive|define
name|METEOR_GEO_YUV_PLANAR
value|0x0080000
end_define

begin_comment
comment|/* 4-2-2 YUV 16 bits planer */
end_comment

begin_define
define|#
directive|define
name|METEOR_GEO_YUV_PLANER
value|METEOR_GEO_YUV_PLANAR
end_define

begin_define
define|#
directive|define
name|METEOR_GEO_UNSIGNED
value|0x0400000
end_define

begin_comment
comment|/* unsigned uv outputs */
end_comment

begin_define
define|#
directive|define
name|METEOR_GEO_EVEN_ONLY
value|0x1000000
end_define

begin_comment
comment|/* set for even only field capture */
end_comment

begin_define
define|#
directive|define
name|METEOR_GEO_ODD_ONLY
value|0x2000000
end_define

begin_comment
comment|/* set for odd only field capture */
end_comment

begin_define
define|#
directive|define
name|METEOR_GEO_FIELD_MASK
value|0x3000000
end_define

begin_define
define|#
directive|define
name|METEOR_GEO_YUV_422
value|0x4000000
end_define

begin_comment
comment|/* 4-2-2 YUV in Y-U-V combined */
end_comment

begin_define
define|#
directive|define
name|METEOR_GEO_OUTPUT_MASK
value|0x40f0000
end_define

begin_define
define|#
directive|define
name|METEOR_GEO_YUV_12
value|0x10000000
end_define

begin_comment
comment|/* YUV 12 format */
end_comment

begin_define
define|#
directive|define
name|METEOR_GEO_YUV_9
value|0x40000000
end_define

begin_comment
comment|/* YUV 9 format */
end_comment

begin_define
define|#
directive|define
name|METEOR_FIELD_MODE
value|0x80000000
end_define

begin_comment
comment|/* Field cap or Frame cap */
end_comment

begin_define
define|#
directive|define
name|METEOR_SIG_MODE_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|METEOR_SIG_FRAME
value|0x00000000
end_define

begin_comment
comment|/* signal every frame */
end_comment

begin_define
define|#
directive|define
name|METEOR_SIG_FIELD
value|0x00010000
end_define

begin_comment
comment|/* signal every field */
end_comment

begin_comment
comment|/* following structure is used to coordinate the synchronous */
end_comment

begin_struct
struct|struct
name|meteor_mem
block|{
comment|/* kernel write only  */
name|int
name|frame_size
decl_stmt|;
comment|/* row*columns*depth */
name|unsigned
name|num_bufs
decl_stmt|;
comment|/* number of frames in buffer (1-32) */
comment|/* user and kernel change these */
name|int
name|lowat
decl_stmt|;
comment|/* kernel starts capture if< this number */
name|int
name|hiwat
decl_stmt|;
comment|/* kernel stops capture if> this number. 				    hiwat<= numbufs */
name|unsigned
name|active
decl_stmt|;
comment|/* bit mask of active frame buffers 				    kernel sets, user clears */
name|int
name|num_active_bufs
decl_stmt|;
comment|/* count of active frame buffer 				    kernel increments, user decrements */
comment|/* reference to mmapped data */
name|caddr_t
name|buf
decl_stmt|;
comment|/* The real space (virtual addr) */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_IOCTL_METEOR_H_ */
end_comment

end_unit

