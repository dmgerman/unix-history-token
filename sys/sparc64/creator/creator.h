begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_FB_CREATOR_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_FB_CREATOR_H_
end_define

begin_define
define|#
directive|define
name|FFB_NREG
value|24
end_define

begin_define
define|#
directive|define
name|FFB_DAC
value|1
end_define

begin_define
define|#
directive|define
name|FFB_DAC_TYPE
value|0x0
end_define

begin_define
define|#
directive|define
name|FFB_DAC_VALUE
value|0x4
end_define

begin_define
define|#
directive|define
name|FFB_DAC_TYPE2
value|0x8
end_define

begin_define
define|#
directive|define
name|FFB_DAC_VALUE2
value|0xc
end_define

begin_define
define|#
directive|define
name|FFB_FBC
value|2
end_define

begin_define
define|#
directive|define
name|FFB_FBC_BY
value|0x60
end_define

begin_define
define|#
directive|define
name|FFB_FBC_BX
value|0x64
end_define

begin_define
define|#
directive|define
name|FFB_FBC_DY
value|0x68
end_define

begin_define
define|#
directive|define
name|FFB_FBC_DX
value|0x6c
end_define

begin_define
define|#
directive|define
name|FFB_FBC_BH
value|0x70
end_define

begin_define
define|#
directive|define
name|FFB_FBC_BW
value|0x74
end_define

begin_define
define|#
directive|define
name|FFB_FBC_PPC
value|0x200
end_define

begin_comment
comment|/* Pixel Processor Control */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_FG
value|0x208
end_define

begin_comment
comment|/* Foreground */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_BG
value|0x20c
end_define

begin_comment
comment|/* Background */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_FBC
value|0x254
end_define

begin_comment
comment|/* Frame Buffer Control */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_ROP
value|0x258
end_define

begin_comment
comment|/* Raster Operation */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_PMASK
value|0x290
end_define

begin_comment
comment|/* Pixel Mask */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_DRAWOP
value|0x300
end_define

begin_comment
comment|/* Draw Operation */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_FONTXY
value|0x314
end_define

begin_comment
comment|/* Font X/Y */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_FONTW
value|0x318
end_define

begin_comment
comment|/* Font Width */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_FONTINC
value|0x31c
end_define

begin_comment
comment|/* Font Increment */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_FONT
value|0x320
end_define

begin_comment
comment|/* Font Data */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_UCSR
value|0x900
end_define

begin_comment
comment|/* User Control& Status */
end_comment

begin_define
define|#
directive|define
name|FBC_PPC_VCE_DIS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|FBC_PPC_APE_DIS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|FBC_PPC_TBE_OPAQUE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|FBC_PPC_CS_CONST
value|0x00000003
end_define

begin_define
define|#
directive|define
name|FFB_FBC_WB_A
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FFB_FBC_RB_A
value|0x00004000
end_define

begin_define
define|#
directive|define
name|FFB_FBC_SB_BOTH
value|0x00003000
end_define

begin_define
define|#
directive|define
name|FFB_FBC_XE_OFF
value|0x00000040
end_define

begin_define
define|#
directive|define
name|FFB_FBC_RGBE_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|FBC_ROP_NEW
value|0x83
end_define

begin_define
define|#
directive|define
name|FBC_DRAWOP_RECTANGLE
value|0x08
end_define

begin_define
define|#
directive|define
name|FBC_UCSR_FIFO_OVFL
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FBC_UCSR_READ_ERR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FBC_UCSR_RP_BUSY
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FBC_UCSR_FB_BUSY
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FBC_UCSR_FIFO_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB8R
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB8G
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB8B
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB8X
value|0x00c00000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB32
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB64
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_FBC
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_FBC_BM
value|0x04002000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB8R
value|0x04004000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB8G
value|0x04404000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB8B
value|0x04804000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB8X
value|0x04c04000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB24
value|0x05004000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB32
value|0x06004000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB422A
value|0x07004000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB422AD
value|0x07804000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB24B
value|0x08004000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB422B
value|0x09004000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB422BD
value|0x09804000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB16Z
value|0x0a004000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB8Z
value|0x0a404000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB422
value|0x0ac04000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB422D
value|0x0b404000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_FBC_KREG
value|0x0bc04000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DAC
value|0x0bc06000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_PROM
value|0x0bc08000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_EXP
value|0x0bc18000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB8R
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB8G
value|0x04400000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB8B
value|0x04800000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB8X
value|0x04c00000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB32
value|0x05000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB64
value|0x06000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_FBC
value|0x00600000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_FBC_BM
value|0x00600000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB8R
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB8G
value|0x01400000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB8B
value|0x01800000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB8X
value|0x01c00000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB24
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB32
value|0x03000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB422A
value|0x09000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB422AD
value|0x09800000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB24B
value|0x0a000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB422B
value|0x0b000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB422BD
value|0x0b800000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB16Z
value|0x0c800000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB8Z
value|0x0c000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB422
value|0x0d000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB422D
value|0x0d800000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_FBC_KREG
value|0x00610000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DAC
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_PROM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_EXP
value|0x00200000
end_define

begin_define
define|#
directive|define
name|FFB_READ
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|)
define|\
value|bus_space_read_4((sc)->sc_bt[(reg)], (sc)->sc_bh[(reg)], (off))
end_define

begin_define
define|#
directive|define
name|FFB_WRITE
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_bt[(reg)], (sc)->sc_bh[(reg)], (off), (val))
end_define

begin_struct
struct|struct
name|creator_softc
block|{
name|video_adapter_t
name|sc_va
decl_stmt|;
comment|/* XXX must be first */
name|dev_t
name|sc_si
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_reg
index|[
name|FFB_NREG
index|]
decl_stmt|;
name|bus_space_tag_t
name|sc_bt
index|[
name|FFB_NREG
index|]
decl_stmt|;
name|bus_space_handle_t
name|sc_bh
index|[
name|FFB_NREG
index|]
decl_stmt|;
name|char
name|sc_model
index|[
literal|32
index|]
decl_stmt|;
name|int
name|sc_console
decl_stmt|;
name|int
name|sc_dac
decl_stmt|;
name|int
name|sc_height
decl_stmt|;
name|int
name|sc_width
decl_stmt|;
name|int
name|sc_ncol
decl_stmt|;
name|int
name|sc_nrow
decl_stmt|;
name|int
name|sc_xmargin
decl_stmt|;
name|int
name|sc_ymargin
decl_stmt|;
name|u_char
modifier|*
name|sc_font
decl_stmt|;
name|int
modifier|*
name|sc_rowp
decl_stmt|;
name|int
modifier|*
name|sc_colp
decl_stmt|;
name|int
name|sc_bg_cache
decl_stmt|;
name|int
name|sc_fg_cache
decl_stmt|;
name|int
name|sc_fifo_cache
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

