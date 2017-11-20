begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2007 The DragonFly Project.  All rights reserved.  *   * This code is derived from software contributed to The DragonFly Project  * by Sepherosa Ziehau<sepherosa@gmail.com>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  * 3. Neither the name of The DragonFly Project nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific, prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * $DragonFly: src/sys/dev/netif/bwi/bwirf.h,v 1.3 2007/10/03 04:53:19 sephe Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BWI_RF_H
end_ifndef

begin_define
define|#
directive|define
name|_BWI_RF_H
end_define

begin_function_decl
name|int
name|bwi_rf_attach
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_rf_clear_state
parameter_list|(
name|struct
name|bwi_rf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bwi_rf_map_txpower
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_rf_lo_adjust
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
specifier|const
name|struct
name|bwi_tpctl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_rf_set_chan
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_rf_get_gains
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_rf_init
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_rf_init_bcm2050
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_rf_init_hw_nrssi_table
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_rf_set_ant_mode
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_rf_clear_tssi
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bwi_rf_get_latest_tssi
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
name|int8_t
index|[]
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bwi_rf_tssi2dbm
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
name|int8_t
parameter_list|,
name|int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_rf_write
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
name|uint16_t
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|bwi_rf_read
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|bwi_rf_off
parameter_list|(
name|struct
name|bwi_mac
modifier|*
name|_mac
parameter_list|)
block|{
name|_mac
operator|->
name|mac_rf
operator|.
name|rf_off
argument_list|(
name|_mac
argument_list|)
expr_stmt|;
comment|/* TODO:LED */
name|_mac
operator|->
name|mac_rf
operator|.
name|rf_flags
operator|&=
operator|~
name|BWI_RF_F_ON
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bwi_rf_on
parameter_list|(
name|struct
name|bwi_mac
modifier|*
name|_mac
parameter_list|)
block|{
if|if
condition|(
name|_mac
operator|->
name|mac_rf
operator|.
name|rf_flags
operator|&
name|BWI_RF_F_ON
condition|)
return|return;
name|_mac
operator|->
name|mac_rf
operator|.
name|rf_on
argument_list|(
name|_mac
argument_list|)
expr_stmt|;
comment|/* TODO: LED */
name|_mac
operator|->
name|mac_rf
operator|.
name|rf_flags
operator||=
name|BWI_RF_F_ON
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bwi_rf_calc_nrssi_slope
parameter_list|(
name|struct
name|bwi_mac
modifier|*
name|_mac
parameter_list|)
block|{
name|_mac
operator|->
name|mac_rf
operator|.
name|rf_calc_nrssi_slope
argument_list|(
name|_mac
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bwi_rf_set_nrssi_thr
parameter_list|(
name|struct
name|bwi_mac
modifier|*
name|_mac
parameter_list|)
block|{
name|_mac
operator|->
name|mac_rf
operator|.
name|rf_set_nrssi_thr
argument_list|(
name|_mac
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|bwi_rf_calc_rssi
parameter_list|(
name|struct
name|bwi_mac
modifier|*
name|_mac
parameter_list|,
specifier|const
name|struct
name|bwi_rxbuf_hdr
modifier|*
name|_hdr
parameter_list|)
block|{
return|return
name|_mac
operator|->
name|mac_rf
operator|.
name|rf_calc_rssi
argument_list|(
name|_mac
argument_list|,
name|_hdr
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|bwi_rf_calc_noise
parameter_list|(
name|struct
name|bwi_mac
modifier|*
name|_mac
parameter_list|)
block|{
return|return
name|_mac
operator|->
name|mac_rf
operator|.
name|rf_calc_noise
argument_list|(
name|_mac
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bwi_rf_lo_update
parameter_list|(
name|struct
name|bwi_mac
modifier|*
name|_mac
parameter_list|)
block|{
return|return
name|_mac
operator|->
name|mac_rf
operator|.
name|rf_lo_update
argument_list|(
name|_mac
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|RF_WRITE
parameter_list|(
name|mac
parameter_list|,
name|ofs
parameter_list|,
name|val
parameter_list|)
value|bwi_rf_write((mac), (ofs), (val))
end_define

begin_define
define|#
directive|define
name|RF_READ
parameter_list|(
name|mac
parameter_list|,
name|ofs
parameter_list|)
value|bwi_rf_read((mac), (ofs))
end_define

begin_define
define|#
directive|define
name|RF_SETBITS
parameter_list|(
name|mac
parameter_list|,
name|ofs
parameter_list|,
name|bits
parameter_list|)
define|\
value|RF_WRITE((mac), (ofs), RF_READ((mac), (ofs)) | (bits))
end_define

begin_define
define|#
directive|define
name|RF_CLRBITS
parameter_list|(
name|mac
parameter_list|,
name|ofs
parameter_list|,
name|bits
parameter_list|)
define|\
value|RF_WRITE((mac), (ofs), RF_READ((mac), (ofs))& ~(bits))
end_define

begin_define
define|#
directive|define
name|RF_FILT_SETBITS
parameter_list|(
name|mac
parameter_list|,
name|ofs
parameter_list|,
name|filt
parameter_list|,
name|bits
parameter_list|)
define|\
value|RF_WRITE((mac), (ofs), (RF_READ((mac), (ofs))& (filt)) | (bits))
end_define

begin_define
define|#
directive|define
name|BWI_RFR_ATTEN
value|0x43
end_define

begin_define
define|#
directive|define
name|BWI_RFR_TXPWR
value|0x52
end_define

begin_define
define|#
directive|define
name|BWI_RFR_TXPWR1_MASK
value|__BITS(6, 4)
end_define

begin_define
define|#
directive|define
name|BWI_RFR_BBP_ATTEN
value|0x60
end_define

begin_define
define|#
directive|define
name|BWI_RFR_BBP_ATTEN_CALIB_BIT
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|BWI_RFR_BBP_ATTEN_CALIB_IDX
value|__BITS(4, 1)
end_define

begin_comment
comment|/*  * TSSI -- TX power maps  */
end_comment

begin_comment
comment|/*  * http://bcm-specs.sipsolutions.net/TSSI_to_DBM_Table  * B PHY  */
end_comment

begin_define
define|#
directive|define
name|BWI_TXPOWER_MAP_11B
define|\
value|0x4d,	0x4c,	0x4b,	0x4a,	0x4a,	0x49,	0x48,	0x47,	\ 	0x47,	0x46,	0x45,	0x45,	0x44,	0x43,	0x42,	0x42,	\ 	0x41,	0x40,	0x3f,	0x3e,	0x3d,	0x3c,	0x3b,	0x3a,	\ 	0x39,	0x38,	0x37,	0x36,	0x35,	0x34,	0x32,	0x31,	\ 	0x30,	0x2f,	0x2d,	0x2c,	0x2b,	0x29,	0x28,	0x26,	\ 	0x25,	0x23,	0x21,	0x1f,	0x1d,	0x1a,	0x17,	0x14,	\ 	0x10,	0x0c,	0x06,	0x00,	-7,	-7,	-7,	-7, 	\ 	-7,	-7,	-7,	-7,	-7,	-7,	-7,	-7
end_define

begin_comment
comment|/*  * http://bcm-specs.sipsolutions.net/TSSI_to_DBM_Table  * G PHY  */
end_comment

begin_define
define|#
directive|define
name|BWI_TXPOWER_MAP_11G
define|\
value|77,	77,	77,	76,	76,	76,	75,	75,	\ 	74,	74,	73,	73,	73,	72,	72,	71,	\ 	71,	70,	70,	69,	68,	68,	67,	67,	\ 	66,	65,	65,	64,	63,	63,	62,	61,	\ 	60,	59,	58,	57,	56,	55,	54,	53,	\ 	52,	50,	49,	47,	45,	43,	40,	37,	\ 	33,	28,	22,	14,	5,	-7,	-20,	-20,	\ 	-20,	-20,	-20,	-20,	-20,	-20,	-20,	-20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BWI_RF_H */
end_comment

end_unit

