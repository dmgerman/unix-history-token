begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Mark Tinguely and Jim Lowe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Mark Tinguely and Jim Lowe  * 4. The name of the author may not be used to endorse or promote products   *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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
name|bregister_t
typedef|;
end_typedef

begin_comment
comment|/*  * if other persuasion endian, then compiler will probably require that  * these next  * macros be reversed  */
end_comment

begin_define
define|#
directive|define
name|BTBYTE
parameter_list|(
name|what
parameter_list|)
value|bregister_t  what:8; int :24
end_define

begin_define
define|#
directive|define
name|BTWORD
parameter_list|(
name|what
parameter_list|)
value|bregister_t  what:16; int: 16
end_define

begin_define
define|#
directive|define
name|BTLONG
parameter_list|(
name|what
parameter_list|)
value|bregister_t  what:32
end_define

begin_struct
struct|struct
name|bt848_registers
block|{
name|BTBYTE
argument_list|(
name|dstatus
argument_list|)
expr_stmt|;
comment|/* 0, 1,2,3 */
define|#
directive|define
name|BT848_DSTATUS_PRES
value|(1<<7)
define|#
directive|define
name|BT848_DSTATUS_HLOC
value|(1<<6)
define|#
directive|define
name|BT848_DSTATUS_FIELD
value|(1<<5)
define|#
directive|define
name|BT848_DSTATUS_NUML
value|(1<<4)
define|#
directive|define
name|BT848_DSTATUS_CSEL
value|(1<<3)
define|#
directive|define
name|BT848_DSTATUS_LOF
value|(1<<1)
define|#
directive|define
name|BT848_DSTATUS_COF
value|(1<<0)
name|BTBYTE
argument_list|(
name|iform
argument_list|)
expr_stmt|;
comment|/* 4, 5,6,7 */
define|#
directive|define
name|BT848_IFORM_MUXSEL
value|(0x3<<5)
define|#
directive|define
name|BT848_IFORM_M_MUX1
value|(0x03<<5)
define|#
directive|define
name|BT848_IFORM_M_MUX0
value|(0x02<<5)
define|#
directive|define
name|BT848_IFORM_M_MUX2
value|(0x01<<5)
define|#
directive|define
name|BT848_IFORM_M_RSVD
value|(0x00<<5)
define|#
directive|define
name|BT848_IFORM_XTSEL
value|(0x3<<3)
define|#
directive|define
name|BT848_IFORM_X_AUTO
value|(0x03<<3)
define|#
directive|define
name|BT848_IFORM_X_XT1
value|(0x02<<3)
define|#
directive|define
name|BT848_IFORM_X_XT0
value|(0x01<<3)
define|#
directive|define
name|BT848_IFORM_X_RSVD
value|(0x00<<3)
name|BTBYTE
argument_list|(
name|tdec
argument_list|)
expr_stmt|;
comment|/* 8, 9,a,b */
name|BTBYTE
argument_list|(
name|e_crop
argument_list|)
expr_stmt|;
comment|/* c, d,e,f */
name|BTBYTE
argument_list|(
name|e_vdelay_lo
argument_list|)
expr_stmt|;
comment|/* 10, 11,12,13 */
name|BTBYTE
argument_list|(
name|e_vactive_lo
argument_list|)
expr_stmt|;
comment|/* 14, 15,16,17 */
name|BTBYTE
argument_list|(
name|e_delay_lo
argument_list|)
expr_stmt|;
comment|/* 18, 19,1a,1b */
name|BTBYTE
argument_list|(
name|e_hactive_lo
argument_list|)
expr_stmt|;
comment|/* 1c, 1d,1e,1f */
name|BTBYTE
argument_list|(
name|e_hscale_hi
argument_list|)
expr_stmt|;
comment|/* 20, 21,22,23 */
name|BTBYTE
argument_list|(
name|e_hscale_lo
argument_list|)
expr_stmt|;
comment|/* 24, 25,26,27 */
name|BTBYTE
argument_list|(
name|bright
argument_list|)
expr_stmt|;
comment|/* 28, 29,2a,2b */
name|BTBYTE
argument_list|(
name|e_control
argument_list|)
expr_stmt|;
comment|/* 2c, 2d,2e,2f */
define|#
directive|define
name|BT848_E_CONTROL_LNOTCH
value|(1<<7)
define|#
directive|define
name|BT848_E_CONTROL_COMP
value|(1<<6)
define|#
directive|define
name|BT848_E_CONTROL_LDEC
value|(1<<5)
define|#
directive|define
name|BT848_E_CONTROL_CBSENSE
value|(1<<4)
define|#
directive|define
name|BT848_E_CONTROL_RSVD
value|(1<<3)
define|#
directive|define
name|BT848_E_CONTROL_CON_MSB
value|(1<<2)
define|#
directive|define
name|BT848_E_CONTROL_SAT_U_MSB
value|(1<<1)
define|#
directive|define
name|BT848_E_CONTROL_SAT_V_MSB
value|(1<<0)
name|BTBYTE
argument_list|(
name|contrast_lo
argument_list|)
expr_stmt|;
comment|/* 30, 31,32,33 */
name|BTBYTE
argument_list|(
name|sat_u_lo
argument_list|)
expr_stmt|;
comment|/* 34, 35,36,37 */
name|BTBYTE
argument_list|(
name|sat_v_lo
argument_list|)
expr_stmt|;
comment|/* 38, 39,3a,3b */
name|BTBYTE
argument_list|(
name|hue
argument_list|)
expr_stmt|;
comment|/* 3c, 3d,3e,3f */
name|BTBYTE
argument_list|(
name|e_scloop
argument_list|)
expr_stmt|;
comment|/* 40, 41,42,43 */
define|#
directive|define
name|BT848_E_SCLOOP_RSVD1
value|(1<<7)
define|#
directive|define
name|BT848_E_SCLOOP_CAGC
value|(1<<6)
define|#
directive|define
name|BT848_E_SCLOOP_CKILL
value|(1<<5)
define|#
directive|define
name|BT848_E_SCLOOP_HFILT
value|(0x3<<3)
define|#
directive|define
name|BT848_E_SCLOOP_HFILT_ICON
value|(0x3<<3)
define|#
directive|define
name|BT848_E_SCLOOP_HFILT_QCIF
value|(0x2<<3)
define|#
directive|define
name|BT848_E_SCLOOP_HFILT_CIF
value|(0x1<<3)
define|#
directive|define
name|BT848_E_SCLOOP_HFILT_AUTO
value|(0x0<<3)
define|#
directive|define
name|BT848_E_SCLOOP_RSVD0
value|(0x7<<0)
name|int
label|:
literal|32
expr_stmt|;
comment|/* 44, 45,46,47 */
name|BTBYTE
argument_list|(
name|oform
argument_list|)
expr_stmt|;
comment|/* 48, 49,4a,4b */
name|BTBYTE
argument_list|(
name|e_vscale_hi
argument_list|)
expr_stmt|;
comment|/* 4c, 4d,4e,4f */
name|BTBYTE
argument_list|(
name|e_vscale_lo
argument_list|)
expr_stmt|;
comment|/* 50, 51,52,53 */
name|BTBYTE
argument_list|(
name|test
argument_list|)
expr_stmt|;
comment|/* 54, 55,56,57 */
name|int
label|:
literal|32
expr_stmt|;
comment|/* 58, 59,5a,5b */
name|int
label|:
literal|32
expr_stmt|;
comment|/* 5c, 5d,5e,5f */
name|BTLONG
argument_list|(
name|adelay
argument_list|)
expr_stmt|;
comment|/* 60, 61,62,63 */
name|BTBYTE
argument_list|(
name|bdelay
argument_list|)
expr_stmt|;
comment|/* 64, 65,66,67 */
name|BTBYTE
argument_list|(
name|adc
argument_list|)
expr_stmt|;
comment|/* 68, 69,6a,6b */
define|#
directive|define
name|BT848_ADC_RESERVED
value|(0x80)
comment|/* required pattern */
define|#
directive|define
name|BT848_ADC_SYNC_T
value|(1<<5)
define|#
directive|define
name|BT848_ADC_AGC_EN
value|(1<<4)
define|#
directive|define
name|BT848_ADC_CLK_SLEEP
value|(1<<3)
define|#
directive|define
name|BT848_ADC_Y_SLEEP
value|(1<<2)
define|#
directive|define
name|BT848_ADC_C_SLEEP
value|(1<<1)
define|#
directive|define
name|BT848_ADC_CRUSH
value|(1<<0)
name|BTBYTE
argument_list|(
name|e_vtc
argument_list|)
expr_stmt|;
comment|/* 6c, 6d,6e,6f */
name|int
label|:
literal|32
expr_stmt|;
comment|/* 70, 71,72,73 */
name|int
label|:
literal|32
expr_stmt|;
comment|/* 74, 75,76,77 */
name|int
label|:
literal|32
expr_stmt|;
comment|/* 78, 79,7a,7b */
name|BTLONG
argument_list|(
name|sreset
argument_list|)
expr_stmt|;
comment|/* 7c, 7d,7e,7f */
name|u_char
name|filler
index|[
literal|0x8c
operator|-
literal|0x80
index|]
decl_stmt|;
name|BTBYTE
argument_list|(
name|o_crop
argument_list|)
expr_stmt|;
comment|/* 8c, 8d,8e,8f */
name|BTBYTE
argument_list|(
name|o_vdelay_lo
argument_list|)
expr_stmt|;
comment|/* 90, 91,92,93 */
name|BTBYTE
argument_list|(
name|o_vactive_lo
argument_list|)
expr_stmt|;
comment|/* 94, 95,96,97 */
name|BTBYTE
argument_list|(
name|o_delay_lo
argument_list|)
expr_stmt|;
comment|/* 98, 99,9a,9b */
name|BTBYTE
argument_list|(
name|o_hactive_lo
argument_list|)
expr_stmt|;
comment|/* 9c, 9d,9e,9f */
name|BTBYTE
argument_list|(
name|o_hscale_hi
argument_list|)
expr_stmt|;
comment|/* a0, a1,a2,a3 */
name|BTBYTE
argument_list|(
name|o_hscale_lo
argument_list|)
expr_stmt|;
comment|/* a4, a5,a6,a7 */
name|int
label|:
literal|32
expr_stmt|;
comment|/* a8, a9,aa,ab */
name|BTBYTE
argument_list|(
name|o_control
argument_list|)
expr_stmt|;
comment|/* ac, ad,ae,af */
define|#
directive|define
name|BT848_O_CONTROL_LNOTCH
value|(1<<7)
define|#
directive|define
name|BT848_O_CONTROL_COMP
value|(1<<6)
define|#
directive|define
name|BT848_O_CONTROL_LDEC
value|(1<<5)
define|#
directive|define
name|BT848_O_CONTROL_CBSENSE
value|(1<<4)
define|#
directive|define
name|BT848_O_CONTROL_RSVD
value|(1<<3)
define|#
directive|define
name|BT848_O_CONTROL_CON_MSB
value|(1<<2)
define|#
directive|define
name|BT848_O_CONTROL_SAT_U_MSB
value|(1<<1)
define|#
directive|define
name|BT848_O_CONTROL_SAT_V_MSB
value|(1<<0)
name|u_char
name|fillter1
index|[
literal|16
index|]
decl_stmt|;
name|BTBYTE
argument_list|(
name|o_scloop
argument_list|)
expr_stmt|;
comment|/* c0, c1,c2,c3 */
define|#
directive|define
name|BT848_O_SCLOOP_RSVD1
value|(1<<7)
define|#
directive|define
name|BT848_O_SCLOOP_CAGC
value|(1<<6)
define|#
directive|define
name|BT848_O_SCLOOP_CKILL
value|(1<<5)
define|#
directive|define
name|BT848_O_SCLOOP_HFILT
value|(0x3<<3)
define|#
directive|define
name|BT848_O_SCLOOP_HFILT_ICON
value|(0x3<<3)
define|#
directive|define
name|BT848_O_SCLOOP_HFILT_QCIF
value|(0x2<<3)
define|#
directive|define
name|BT848_O_SCLOOP_HFILT_CIF
value|(0x1<<3)
define|#
directive|define
name|BT848_O_SCLOOP_HFILT_AUTO
value|(0x0<<3)
define|#
directive|define
name|BT848_O_SCLOOP_RSVD0
value|(0x7<<0)
name|int
label|:
literal|32
expr_stmt|;
comment|/* c4, c5,c6,c7 */
name|int
label|:
literal|32
expr_stmt|;
comment|/* c8, c9,ca,cb */
name|BTBYTE
argument_list|(
name|o_vscale_hi
argument_list|)
expr_stmt|;
comment|/* cc, cd,ce,cf */
name|BTBYTE
argument_list|(
name|o_vscale_lo
argument_list|)
expr_stmt|;
comment|/* d0, d1,d2,d3 */
name|BTBYTE
argument_list|(
name|color_fmt
argument_list|)
expr_stmt|;
comment|/* d4, d5,d6,d7 */
name|bregister_t
name|color_ctl_swap
range|:
literal|4
decl_stmt|;
comment|/* d8 */
define|#
directive|define
name|BT848_COLOR_CTL_WSWAP_ODD
value|(1<<3)
define|#
directive|define
name|BT848_COLOR_CTL_WSWAP_EVEN
value|(1<<2)
define|#
directive|define
name|BT848_COLOR_CTL_BSWAP_ODD
value|(1<<1)
define|#
directive|define
name|BT848_COLOR_CTL_BSWAP_EVEN
value|(1<<0)
name|bregister_t
name|color_ctl_gamma
range|:
literal|1
decl_stmt|;
name|bregister_t
name|color_ctl_rgb_ded
range|:
literal|1
decl_stmt|;
name|bregister_t
name|color_ctl_color_bars
range|:
literal|1
decl_stmt|;
name|bregister_t
name|color_ctl_ext_frmrate
range|:
literal|1
decl_stmt|;
name|int
label|:
literal|24
expr_stmt|;
comment|/* d9,da,db */
name|BTBYTE
argument_list|(
name|cap_ctl
argument_list|)
expr_stmt|;
comment|/* dc, dd,de,df */
define|#
directive|define
name|BT848_CAP_CTL_DITH_FRAME
value|(1<<4)
define|#
directive|define
name|BT848_CAP_CTL_VBI_ODD
value|(1<<3)
define|#
directive|define
name|BT848_CAP_CTL_VBI_EVEN
value|(1<<2)
define|#
directive|define
name|BT848_CAP_CTL_ODD
value|(1<<1)
define|#
directive|define
name|BT848_CAP_CTL_EVEN
value|(1<<0)
name|BTBYTE
argument_list|(
name|vbi_pack_size
argument_list|)
expr_stmt|;
comment|/* e0, e1,e2,e3 */
name|BTBYTE
argument_list|(
name|vbi_pack_del
argument_list|)
expr_stmt|;
comment|/* e4, e5,e6,e7 */
name|int
label|:
literal|32
expr_stmt|;
comment|/* e8, e9,ea,eb */
name|BTBYTE
argument_list|(
name|o_vtc
argument_list|)
expr_stmt|;
comment|/* ec, ed,ee,ef */
name|u_char
name|filler2
index|[
literal|0x100
operator|-
literal|0xf0
index|]
decl_stmt|;
name|BTLONG
argument_list|(
name|int_stat
argument_list|)
expr_stmt|;
comment|/* 100, 101,102,103 */
name|BTLONG
argument_list|(
name|int_mask
argument_list|)
expr_stmt|;
comment|/* 104, 105,106,107 */
define|#
directive|define
name|BT848_INT_RISCS
value|(0xf<<28)
define|#
directive|define
name|BT848_INT_RISC_EN
value|(1<<27)
define|#
directive|define
name|BT848_INT_RACK
value|(1<<25)
define|#
directive|define
name|BT848_INT_FIELD
value|(1<<24)
define|#
directive|define
name|BT848_INT_MYSTERYBIT
value|(1<<23)
define|#
directive|define
name|BT848_INT_SCERR
value|(1<<19)
define|#
directive|define
name|BT848_INT_OCERR
value|(1<<18)
define|#
directive|define
name|BT848_INT_PABORT
value|(1<<17)
define|#
directive|define
name|BT848_INT_RIPERR
value|(1<<16)
define|#
directive|define
name|BT848_INT_PPERR
value|(1<<15)
define|#
directive|define
name|BT848_INT_FDSR
value|(1<<14)
define|#
directive|define
name|BT848_INT_FTRGT
value|(1<<13)
define|#
directive|define
name|BT848_INT_FBUS
value|(1<<12)
define|#
directive|define
name|BT848_INT_RISCI
value|(1<<11)
define|#
directive|define
name|BT848_INT_GPINT
value|(1<<9)
define|#
directive|define
name|BT848_INT_I2CDONE
value|(1<<8)
define|#
directive|define
name|BT848_INT_RSV1
value|(1<<7)
define|#
directive|define
name|BT848_INT_RSV0
value|(1<<6)
define|#
directive|define
name|BT848_INT_VPRES
value|(1<<5)
define|#
directive|define
name|BT848_INT_HLOCK
value|(1<<4)
define|#
directive|define
name|BT848_INT_OFLOW
value|(1<<3)
define|#
directive|define
name|BT848_INT_HSYNC
value|(1<<2)
define|#
directive|define
name|BT848_INT_VSYNC
value|(1<<1)
define|#
directive|define
name|BT848_INT_FMTCHG
value|(1<<0)
name|int
label|:
literal|32
expr_stmt|;
comment|/* 108, 109,10a,10b */
name|BTWORD
argument_list|(
name|gpio_dma_ctl
argument_list|)
expr_stmt|;
comment|/* 10c, 10d,10e,10f */
define|#
directive|define
name|BT848_DMA_CTL_PL23TP4
value|(0<<6)
comment|/* planar1 trigger 4 */
define|#
directive|define
name|BT848_DMA_CTL_PL23TP8
value|(1<<6)
comment|/* planar1 trigger 8 */
define|#
directive|define
name|BT848_DMA_CTL_PL23TP16
value|(2<<6)
comment|/* planar1 trigger 16 */
define|#
directive|define
name|BT848_DMA_CTL_PL23TP32
value|(3<<6)
comment|/* planar1 trigger 32 */
define|#
directive|define
name|BT848_DMA_CTL_PL1TP4
value|(0<<4)
comment|/* planar1 trigger 4 */
define|#
directive|define
name|BT848_DMA_CTL_PL1TP8
value|(1<<4)
comment|/* planar1 trigger 8 */
define|#
directive|define
name|BT848_DMA_CTL_PL1TP16
value|(2<<4)
comment|/* planar1 trigger 16 */
define|#
directive|define
name|BT848_DMA_CTL_PL1TP32
value|(3<<4)
comment|/* planar1 trigger 32 */
define|#
directive|define
name|BT848_DMA_CTL_PKTP4
value|(0<<2)
comment|/* packed trigger 4 */
define|#
directive|define
name|BT848_DMA_CTL_PKTP8
value|(1<<2)
comment|/* packed trigger 8 */
define|#
directive|define
name|BT848_DMA_CTL_PKTP16
value|(2<<2)
comment|/* packed trigger 16 */
define|#
directive|define
name|BT848_DMA_CTL_PKTP32
value|(3<<2)
comment|/* packed trigger 32 */
define|#
directive|define
name|BT848_DMA_CTL_RISC_EN
value|(1<<1)
define|#
directive|define
name|BT848_DMA_CTL_FIFO_EN
value|(1<<0)
name|BTLONG
argument_list|(
name|i2c_data_ctl
argument_list|)
expr_stmt|;
comment|/* 110, 111,112,113 */
define|#
directive|define
name|BT848_DATA_CTL_I2CDIV
value|(0xf<<4)
define|#
directive|define
name|BT848_DATA_CTL_I2CSYNC
value|(1<<3)
define|#
directive|define
name|BT848_DATA_CTL_I2CW3B
value|(1<<2)
define|#
directive|define
name|BT848_DATA_CTL_I2CSCL
value|(1<<1)
define|#
directive|define
name|BT848_DATA_CTL_I2CSDA
value|(1<<0)
name|BTLONG
argument_list|(
name|risc_strt_add
argument_list|)
expr_stmt|;
comment|/* 114, 115,116,117 */
name|BTLONG
argument_list|(
name|gpio_out_en
argument_list|)
expr_stmt|;
comment|/* 118, 119,11a,11b */
comment|/* really 24 bits */
name|BTLONG
argument_list|(
name|gpio_reg_inp
argument_list|)
expr_stmt|;
comment|/* 11c, 11d,11e,11f */
comment|/* really 24 bits */
name|BTLONG
argument_list|(
name|risc_count
argument_list|)
expr_stmt|;
comment|/* 120, 121,122,123 */
name|u_char
name|filler3
index|[
literal|0x200
operator|-
literal|0x124
index|]
decl_stmt|;
name|BTLONG
argument_list|(
name|gpio_data
argument_list|)
expr_stmt|;
comment|/* 200, 201,202,203 */
comment|/* really 24 bits */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
specifier|volatile
name|struct
name|bt848_registers
modifier|*
name|bt848_ptr_t
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* force people to be aware of the new struct */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/*  * device support for onboard tv tuners  */
end_comment

begin_comment
comment|/* description of the LOGICAL tuner */
end_comment

begin_struct
struct|struct
name|TVTUNER
block|{
name|int
name|frequency
decl_stmt|;
name|u_char
name|chnlset
decl_stmt|;
name|u_char
name|channel
decl_stmt|;
name|u_char
name|band
decl_stmt|;
name|u_char
name|afc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* description of the PHYSICAL tuner */
end_comment

begin_struct
struct|struct
name|TUNER
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|u_char
name|type
decl_stmt|;
name|u_char
name|pllAddr
decl_stmt|;
name|u_char
name|pllControl
decl_stmt|;
name|u_char
name|bandLimits
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|bandAddrs
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* description of the card */
end_comment

begin_define
define|#
directive|define
name|EEPROMBLOCKSIZE
value|32
end_define

begin_struct
struct|struct
name|CARDTYPE
block|{
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|struct
name|TUNER
modifier|*
name|tuner
decl_stmt|;
name|u_char
name|dbx
decl_stmt|;
comment|/* Has DBX chip? */
name|u_char
name|msp3400c
decl_stmt|;
comment|/* Has msp3400c chip? */
name|u_char
name|eepromAddr
decl_stmt|;
name|u_char
name|eepromSize
decl_stmt|;
comment|/* bytes / EEPROMBLOCKSIZE */
name|u_char
name|audiomuxs
index|[
literal|5
index|]
decl_stmt|;
comment|/* tuner, ext, int/unused, 						    mute, present */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|format_params
block|{
comment|/* Total lines, lines before image, image lines */
name|int
name|vtotal
decl_stmt|,
name|vdelay
decl_stmt|,
name|vactive
decl_stmt|;
comment|/* Total unscaled horizontal pixels, pixels before image, image pixels */
name|int
name|htotal
decl_stmt|,
name|hdelay
decl_stmt|,
name|hactive
decl_stmt|;
comment|/* visible active horizontal and vertical : 480 640 for NTSC */
name|int
name|horizontal
decl_stmt|,
name|vertical
decl_stmt|;
comment|/* frame rate . for ntsc is 30 frames per second */
name|int
name|frame_rate
decl_stmt|;
comment|/* A-delay and B-delay */
name|u_char
name|adelay
decl_stmt|,
name|bdelay
decl_stmt|;
comment|/* Iform XTSEL value */
name|int
name|iform_xtsel
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bktr_clip
name|bktr_clip_t
typedef|;
end_typedef

begin_comment
comment|/*  * BrookTree 848  info structure, one per bt848 card installed.  */
end_comment

begin_struct
struct|struct
name|bktr_softc
block|{
ifdef|#
directive|ifdef
name|__bsdi__
name|struct
name|device
name|bktr_dev
decl_stmt|;
comment|/* base device */
name|struct
name|isadev
name|bktr_id
decl_stmt|;
comment|/* ISA device */
name|struct
name|intrhand
name|bktr_ih
decl_stmt|;
comment|/* interrupt vectoring */
define|#
directive|define
name|pcici_t
value|pci_devaddr_t
endif|#
directive|endif
name|bt848_ptr_t
name|base
decl_stmt|;
comment|/* Bt848 register physical address */
name|vm_offset_t
name|phys_base
decl_stmt|;
comment|/* Bt848 register physical address */
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
name|int
name|pixfmt
decl_stmt|;
comment|/* active pixel format (idx into fmt tbl) */
name|int
name|pixfmt_compat
decl_stmt|;
comment|/* Y/N - in meteor pix fmt compat mode */
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
name|u_short
name|bktr_cap_ctl
decl_stmt|;
specifier|volatile
name|u_int
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
name|tflags
decl_stmt|;
define|#
directive|define
name|TUNER_INITALIZED
value|0x00000001
define|#
directive|define
name|TUNER_OPEN
value|0x00000002
name|u_short
name|fps
decl_stmt|;
comment|/* frames per second */
ifdef|#
directive|ifdef
name|DEVFS
name|void
modifier|*
name|devfs_bktr_token
decl_stmt|;
name|void
modifier|*
name|devfs_tuner_token
decl_stmt|;
endif|#
directive|endif
name|struct
name|meteor_video
name|video
decl_stmt|;
name|struct
name|TVTUNER
name|tuner
decl_stmt|;
name|struct
name|CARDTYPE
name|card
decl_stmt|;
name|u_char
name|audio_mux_select
decl_stmt|;
comment|/* current mode of the audio */
name|u_char
name|audio_mute_state
decl_stmt|;
comment|/* mute state of the audio */
name|u_char
name|format_params
decl_stmt|;
name|u_long
name|current_sol
decl_stmt|;
name|u_long
name|current_col
decl_stmt|;
name|int
name|clip_start
decl_stmt|;
name|int
name|line_length
decl_stmt|;
name|int
name|last_y
decl_stmt|;
name|int
name|y
decl_stmt|;
name|int
name|y2
decl_stmt|;
name|int
name|yclip
decl_stmt|;
name|int
name|yclip2
decl_stmt|;
name|int
name|max_clip_node
decl_stmt|;
name|bktr_clip_t
name|clip_list
index|[
literal|100
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bktr_softc
name|bktr_reg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bktr_softc
modifier|*
name|bktr_ptr_t
typedef|;
end_typedef

end_unit

