begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2001 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_ipac.h - definitions for the Siemens IPAC PSB2115 chip  *	==========================================================  *  * $FreeBSD$  *  *      last edit-date: [Wed Jan 24 09:10:09 2001]  *  *---------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_IPAC_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_IPAC_H_
end_define

begin_define
define|#
directive|define
name|IPAC_BFIFO_LEN
value|64
end_define

begin_comment
comment|/* 64 bytes B-channel FIFO on chip	*/
end_comment

begin_define
define|#
directive|define
name|IPAC_HSCXA_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|IPAC_HSCXB_OFF
value|0x40
end_define

begin_define
define|#
directive|define
name|IPAC_ISAC_OFF
value|0x80
end_define

begin_define
define|#
directive|define
name|IPAC_IPAC_OFF
value|0xc0
end_define

begin_comment
comment|/* chip version */
end_comment

begin_define
define|#
directive|define
name|IPAC_V11
value|0x01
end_define

begin_comment
comment|/* IPAC Version 1.1 */
end_comment

begin_define
define|#
directive|define
name|IPAC_V12
value|0x02
end_define

begin_comment
comment|/* IPAC Version 1.2 */
end_comment

begin_comment
comment|/*  * definitions of registers and bits for the IPAC ISDN chip.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ipac_reg
block|{
comment|/* most registers can be read/written, but have different names */
comment|/* so define a union with read/write names to make that clear */
union|union
block|{
struct|struct
block|{
name|unsigned
name|char
name|ipac_conf
decl_stmt|;
name|unsigned
name|char
name|ipac_ista
decl_stmt|;
name|unsigned
name|char
name|ipac_id
decl_stmt|;
name|unsigned
name|char
name|ipac_acfg
decl_stmt|;
name|unsigned
name|char
name|ipac_aoe
decl_stmt|;
name|unsigned
name|char
name|ipac_arx
decl_stmt|;
name|unsigned
name|char
name|ipac_pita1
decl_stmt|;
name|unsigned
name|char
name|ipac_pita2
decl_stmt|;
name|unsigned
name|char
name|ipac_pota1
decl_stmt|;
name|unsigned
name|char
name|ipac_pota2
decl_stmt|;
name|unsigned
name|char
name|ipac_pcfg
decl_stmt|;
name|unsigned
name|char
name|ipac_scfg
decl_stmt|;
name|unsigned
name|char
name|ipac_timr2
decl_stmt|;
block|}
name|ipac_r
struct|;
struct|struct
block|{
name|unsigned
name|char
name|ipac_conf
decl_stmt|;
name|unsigned
name|char
name|ipac_mask
decl_stmt|;
name|unsigned
name|char
name|ipac_dummy
decl_stmt|;
name|unsigned
name|char
name|ipac_acfg
decl_stmt|;
name|unsigned
name|char
name|ipac_aoe
decl_stmt|;
name|unsigned
name|char
name|ipac_atx
decl_stmt|;
name|unsigned
name|char
name|ipac_pita1
decl_stmt|;
name|unsigned
name|char
name|ipac_pita2
decl_stmt|;
name|unsigned
name|char
name|ipac_pota1
decl_stmt|;
name|unsigned
name|char
name|ipac_pota2
decl_stmt|;
name|unsigned
name|char
name|ipac_pcfg
decl_stmt|;
name|unsigned
name|char
name|ipac_scfg
decl_stmt|;
name|unsigned
name|char
name|ipac_timr2
decl_stmt|;
block|}
name|ipac_w
struct|;
block|}
name|ipac_rw
union|;
block|}
name|ipac_reg_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|REG_OFFSET
parameter_list|(
name|type
parameter_list|,
name|field
parameter_list|)
value|(int)(&(((type *)0)->field))
end_define

begin_comment
comment|/* IPAC read registers */
end_comment

begin_define
define|#
directive|define
name|IPAC_CONF
value|REG_OFFSET(ipac_reg_t, ipac_rw.ipac_r.ipac_conf)
end_define

begin_define
define|#
directive|define
name|IPAC_ISTA
value|REG_OFFSET(ipac_reg_t, ipac_rw.ipac_r.ipac_ista)
end_define

begin_define
define|#
directive|define
name|IPAC_ID
value|REG_OFFSET(ipac_reg_t, ipac_rw.ipac_r.ipac_id)
end_define

begin_define
define|#
directive|define
name|IPAC_ACFG
value|REG_OFFSET(ipac_reg_t, ipac_rw.ipac_r.ipac_acfg)
end_define

begin_define
define|#
directive|define
name|IPAC_AOE
value|REG_OFFSET(ipac_reg_t, ipac_rw.ipac_r.ipac_aoe)
end_define

begin_define
define|#
directive|define
name|IPAC_ARX
value|REG_OFFSET(ipac_reg_t, ipac_rw.ipac_r.ipac_arx)
end_define

begin_define
define|#
directive|define
name|IPAC_PITA1
value|REG_OFFSET(ipac_reg_t, ipac_rw.ipac_r.ipac_pita1)
end_define

begin_define
define|#
directive|define
name|IPAC_PITA2
value|REG_OFFSET(ipac_reg_t, ipac_rw.ipac_r.ipac_pita2)
end_define

begin_define
define|#
directive|define
name|IPAC_POTA1
value|REG_OFFSET(ipac_reg_t, ipac_rw.ipac_r.ipac_pota1)
end_define

begin_define
define|#
directive|define
name|IPAC_POTA2
value|REG_OFFSET(ipac_reg_t, ipac_rw.ipac_r.ipac_pota2)
end_define

begin_define
define|#
directive|define
name|IPAC_PCFG
value|REG_OFFSET(ipac_reg_t, ipac_rw.ipac_r.ipac_pcfg)
end_define

begin_define
define|#
directive|define
name|IPAC_SCFG
value|REG_OFFSET(ipac_reg_t, ipac_rw.ipac_r.ipac_scfg)
end_define

begin_define
define|#
directive|define
name|IPAC_TIMR2
value|REG_OFFSET(ipac_reg_t, ipac_rw.ipac_r.ipac_timr2)
end_define

begin_comment
comment|/* IPAC write registers */
end_comment

begin_define
define|#
directive|define
name|IPAC_MASK
value|REG_OFFSET(ipac_reg_t, ipac_rw.ipac_w.ipac_mask)
end_define

begin_define
define|#
directive|define
name|IPAC_ATX
value|REG_OFFSET(ipac_reg_t, ipac_rw.ipac_w.ipac_atx)
end_define

begin_comment
comment|/* register bits */
end_comment

begin_define
define|#
directive|define
name|IPAC_CONF_AMP
value|0x80
end_define

begin_define
define|#
directive|define
name|IPAC_CONF_CFS
value|0x40
end_define

begin_define
define|#
directive|define
name|IPAC_CONF_TEM
value|0x20
end_define

begin_define
define|#
directive|define
name|IPAC_CONF_PDS
value|0x10
end_define

begin_define
define|#
directive|define
name|IPAC_CONF_IDH
value|0x08
end_define

begin_define
define|#
directive|define
name|IPAC_CONF_SGO
value|0x04
end_define

begin_define
define|#
directive|define
name|IPAC_CONF_ODS
value|0x02
end_define

begin_define
define|#
directive|define
name|IPAC_CONF_IOF
value|0x01
end_define

begin_define
define|#
directive|define
name|IPAC_ISTA_INT1
value|0x80
end_define

begin_define
define|#
directive|define
name|IPAC_ISTA_INT0
value|0x40
end_define

begin_define
define|#
directive|define
name|IPAC_ISTA_ICD
value|0x20
end_define

begin_define
define|#
directive|define
name|IPAC_ISTA_EXD
value|0x10
end_define

begin_define
define|#
directive|define
name|IPAC_ISTA_ICA
value|0x08
end_define

begin_define
define|#
directive|define
name|IPAC_ISTA_EXA
value|0x04
end_define

begin_define
define|#
directive|define
name|IPAC_ISTA_ICB
value|0x02
end_define

begin_define
define|#
directive|define
name|IPAC_ISTA_EXB
value|0x01
end_define

begin_define
define|#
directive|define
name|IPAC_MASK_INT1
value|0x80
end_define

begin_define
define|#
directive|define
name|IPAC_MASK_INT0
value|0x40
end_define

begin_define
define|#
directive|define
name|IPAC_MASK_ICD
value|0x20
end_define

begin_define
define|#
directive|define
name|IPAC_MASK_EXD
value|0x10
end_define

begin_define
define|#
directive|define
name|IPAC_MASK_ICA
value|0x08
end_define

begin_define
define|#
directive|define
name|IPAC_MASK_EXA
value|0x04
end_define

begin_define
define|#
directive|define
name|IPAC_MASK_ICB
value|0x02
end_define

begin_define
define|#
directive|define
name|IPAC_MASK_EXB
value|0x01
end_define

begin_define
define|#
directive|define
name|IPAC_ACFG_OD7
value|0x80
end_define

begin_define
define|#
directive|define
name|IPAC_ACFG_OD6
value|0x40
end_define

begin_define
define|#
directive|define
name|IPAC_ACFG_OD5
value|0x20
end_define

begin_define
define|#
directive|define
name|IPAC_ACFG_OD4
value|0x10
end_define

begin_define
define|#
directive|define
name|IPAC_ACFG_OD3
value|0x08
end_define

begin_define
define|#
directive|define
name|IPAC_ACFG_OD2
value|0x04
end_define

begin_define
define|#
directive|define
name|IPAC_ACFG_EL1
value|0x02
end_define

begin_define
define|#
directive|define
name|IPAC_ACFG_EL2
value|0x01
end_define

begin_define
define|#
directive|define
name|IPAC_AOE_OE7
value|0x80
end_define

begin_define
define|#
directive|define
name|IPAC_AOE_OE6
value|0x40
end_define

begin_define
define|#
directive|define
name|IPAC_AOE_OE5
value|0x20
end_define

begin_define
define|#
directive|define
name|IPAC_AOE_OE4
value|0x10
end_define

begin_define
define|#
directive|define
name|IPAC_AOE_OE3
value|0x08
end_define

begin_define
define|#
directive|define
name|IPAC_AOE_OE2
value|0x04
end_define

begin_define
define|#
directive|define
name|IPAC_ARX_AR7
value|0x80
end_define

begin_define
define|#
directive|define
name|IPAC_ARX_AR6
value|0x40
end_define

begin_define
define|#
directive|define
name|IPAC_ARX_AR5
value|0x20
end_define

begin_define
define|#
directive|define
name|IPAC_ARX_AR4
value|0x10
end_define

begin_define
define|#
directive|define
name|IPAC_ARX_AR3
value|0x08
end_define

begin_define
define|#
directive|define
name|IPAC_ARX_AR2
value|0x04
end_define

begin_define
define|#
directive|define
name|IPAC_ATX_AT7
value|0x80
end_define

begin_define
define|#
directive|define
name|IPAC_ATX_AT6
value|0x40
end_define

begin_define
define|#
directive|define
name|IPAC_ATX_AT5
value|0x20
end_define

begin_define
define|#
directive|define
name|IPAC_ATX_AT4
value|0x10
end_define

begin_define
define|#
directive|define
name|IPAC_ATX_AT3
value|0x08
end_define

begin_define
define|#
directive|define
name|IPAC_ATX_AT2
value|0x04
end_define

begin_define
define|#
directive|define
name|IPAC_PITA1_ENA
value|0x80
end_define

begin_define
define|#
directive|define
name|IPAC_PITA1_DUDD
value|0x40
end_define

begin_define
define|#
directive|define
name|IPAC_PITA2_ENA
value|0x80
end_define

begin_define
define|#
directive|define
name|IPAC_PITA2_DUDD
value|0x40
end_define

begin_define
define|#
directive|define
name|IPAC_POTA1_ENA
value|0x80
end_define

begin_define
define|#
directive|define
name|IPAC_POTA1_DUDD
value|0x40
end_define

begin_define
define|#
directive|define
name|IPAC_POTA2_ENA
value|0x80
end_define

begin_define
define|#
directive|define
name|IPAC_POTA2_DUDD
value|0x40
end_define

begin_define
define|#
directive|define
name|IPAC_PCFG_DPS
value|0x80
end_define

begin_define
define|#
directive|define
name|IPAC_PCFG_ACL
value|0x40
end_define

begin_define
define|#
directive|define
name|IPAC_PCFG_LED
value|0x20
end_define

begin_define
define|#
directive|define
name|IPAC_PCFG_PLD
value|0x10
end_define

begin_define
define|#
directive|define
name|IPAC_PCFG_FBS
value|0x08
end_define

begin_define
define|#
directive|define
name|IPAC_PCFG_CSL2
value|0x04
end_define

begin_define
define|#
directive|define
name|IPAC_PCFG_CSL1
value|0x02
end_define

begin_define
define|#
directive|define
name|IPAC_PCFG_CSL0
value|0x01
end_define

begin_define
define|#
directive|define
name|IPAC_SCFG_PRI
value|0x80
end_define

begin_define
define|#
directive|define
name|IPAC_SCFG_TXD
value|0x40
end_define

begin_define
define|#
directive|define
name|IPAC_SCFG_TLEN
value|0x20
end_define

begin_define
define|#
directive|define
name|IPAC_TIMR2_TMD
value|0x80
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_IPAC_H_ */
end_comment

end_unit

