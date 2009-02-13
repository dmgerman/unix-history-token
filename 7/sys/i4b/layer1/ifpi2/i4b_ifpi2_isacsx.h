begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *   Copyright (c) 2001 Gary Jennejohn. All rights reserved.   *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *      documentation and/or other materials provided with the distribution.  *   3. Neither the name of the author nor the names of any co-contributors  *      may be used to endorse or promote products derived from this software  *      without specific prior written permission.  *   4. Altered versions must be plainly marked as such, and must not be  *      misrepresented as being the original software and/or documentation.  *     *   THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  *   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *   ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  *   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *   OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *   OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  *   SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------  *  * $FreeBSD$  *  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|I4B_ISACSX_H_
end_ifndef

begin_define
define|#
directive|define
name|I4B_ISACSX_H_
end_define

begin_define
define|#
directive|define
name|ISACSX_FIFO_LEN
value|32
end_define

begin_comment
comment|/* 32 bytes FIFO on chip */
end_comment

begin_define
define|#
directive|define
name|ISACSX_V13
value|0x01
end_define

begin_comment
comment|/*  * definitions of registers and bits for the ISAC-SX ISDN chip.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|isacsx_reg
block|{
comment|/* 32 byte deep FIFO always first */
name|unsigned
name|char
name|isacsx_fifo
index|[
name|ISACSX_FIFO_LEN
index|]
decl_stmt|;
comment|/* most registers can be read/written, but have different names */
comment|/* so define a union with read/write names to make that clear */
union|union
block|{
struct|struct
block|{
name|unsigned
name|char
name|isacsx_istad
decl_stmt|;
name|unsigned
name|char
name|isacsx_stard
decl_stmt|;
name|unsigned
name|char
name|isacsx_moded
decl_stmt|;
name|unsigned
name|char
name|isacsx_exmd1
decl_stmt|;
name|unsigned
name|char
name|isacsx_timr1
decl_stmt|;
name|unsigned
name|char
name|dummy_25
decl_stmt|;
name|unsigned
name|char
name|isacsx_rbcld
decl_stmt|;
name|unsigned
name|char
name|isacsx_rbchd
decl_stmt|;
name|unsigned
name|char
name|isacsx_rstad
decl_stmt|;
name|unsigned
name|char
name|isacsx_tmd
decl_stmt|;
name|unsigned
name|char
name|dummy_2a
decl_stmt|;
name|unsigned
name|char
name|dummy_2b
decl_stmt|;
name|unsigned
name|char
name|dummy_2c
decl_stmt|;
name|unsigned
name|char
name|dummy_2d
decl_stmt|;
name|unsigned
name|char
name|isacsx_cir0
decl_stmt|;
name|unsigned
name|char
name|isacsx_codr1
decl_stmt|;
name|unsigned
name|char
name|isacsx_tr_conf0
decl_stmt|;
name|unsigned
name|char
name|isacsx_tr_conf1
decl_stmt|;
name|unsigned
name|char
name|isacsx_tr_conf2
decl_stmt|;
name|unsigned
name|char
name|isacsx_tr_sta
decl_stmt|;
name|unsigned
name|char
name|dummy_34
decl_stmt|;
name|unsigned
name|char
name|isacsx_sqrr1
decl_stmt|;
name|unsigned
name|char
name|isacsx_sqrr2
decl_stmt|;
name|unsigned
name|char
name|isacsx_sqrr3
decl_stmt|;
name|unsigned
name|char
name|isacsx_istatr
decl_stmt|;
name|unsigned
name|char
name|isacsx_masktr
decl_stmt|;
name|unsigned
name|char
name|dummy_3a
decl_stmt|;
name|unsigned
name|char
name|dummy_3b
decl_stmt|;
name|unsigned
name|char
name|isacsx_acgf2
decl_stmt|;
name|unsigned
name|char
name|dummy_3d
decl_stmt|;
name|unsigned
name|char
name|dummy_3e
decl_stmt|;
name|unsigned
name|char
name|dummy_3f
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda10
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda11
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda20
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda21
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda_tsdp10
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda_tsdp11
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda_tsdp20
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda_tsdp21
decl_stmt|;
name|unsigned
name|char
name|dummy_48
decl_stmt|;
name|unsigned
name|char
name|dummy_49
decl_stmt|;
name|unsigned
name|char
name|dummy_4a
decl_stmt|;
name|unsigned
name|char
name|dummy_4b
decl_stmt|;
name|unsigned
name|char
name|isacsx_tr_tsdp_bc1
decl_stmt|;
name|unsigned
name|char
name|isacsx_tr_tsdp_bc2
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda1_cr
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda2_cr
decl_stmt|;
name|unsigned
name|char
name|isacsx_tr_cr
decl_stmt|;
name|unsigned
name|char
name|dummy_51
decl_stmt|;
name|unsigned
name|char
name|dummy_52
decl_stmt|;
name|unsigned
name|char
name|isacsx_dci_cr
decl_stmt|;
name|unsigned
name|char
name|isacsx_mon_cr
decl_stmt|;
name|unsigned
name|char
name|isacsx_sds_cr
decl_stmt|;
name|unsigned
name|char
name|dummy_56
decl_stmt|;
name|unsigned
name|char
name|isacsx_iom_cr
decl_stmt|;
name|unsigned
name|char
name|isacsx_sti
decl_stmt|;
name|unsigned
name|char
name|isacsx_msti
decl_stmt|;
name|unsigned
name|char
name|isacsx_sds_conf
decl_stmt|;
name|unsigned
name|char
name|isacsx_mcda
decl_stmt|;
name|unsigned
name|char
name|isacsx_mor
decl_stmt|;
name|unsigned
name|char
name|isacsx_mosr
decl_stmt|;
name|unsigned
name|char
name|isacsx_mocr
decl_stmt|;
name|unsigned
name|char
name|isacsx_msta
decl_stmt|;
name|unsigned
name|char
name|isacsx_ista
decl_stmt|;
name|unsigned
name|char
name|isacsx_auxi
decl_stmt|;
name|unsigned
name|char
name|isacsx_mode1
decl_stmt|;
name|unsigned
name|char
name|isacsx_mode2
decl_stmt|;
name|unsigned
name|char
name|isacsx_id
decl_stmt|;
name|unsigned
name|char
name|isacsx_timr2
decl_stmt|;
name|unsigned
name|char
name|dummy_66
decl_stmt|;
name|unsigned
name|char
name|dummy_67
decl_stmt|;
name|unsigned
name|char
name|dummy_68
decl_stmt|;
name|unsigned
name|char
name|dummy_69
decl_stmt|;
name|unsigned
name|char
name|dummy_6a
decl_stmt|;
name|unsigned
name|char
name|dummy_6b
decl_stmt|;
name|unsigned
name|char
name|dummy_6c
decl_stmt|;
name|unsigned
name|char
name|dummy_6d
decl_stmt|;
name|unsigned
name|char
name|dummy_6e
decl_stmt|;
name|unsigned
name|char
name|dummy_6f
decl_stmt|;
block|}
name|isacsx_r
struct|;
struct|struct
block|{
name|unsigned
name|char
name|isacsx_maskd
decl_stmt|;
name|unsigned
name|char
name|isacsx_cmdrd
decl_stmt|;
name|unsigned
name|char
name|isacsx_moded
decl_stmt|;
name|unsigned
name|char
name|isacsx_exmd1
decl_stmt|;
name|unsigned
name|char
name|isacsx_timr1
decl_stmt|;
name|unsigned
name|char
name|isacsx_sap1
decl_stmt|;
name|unsigned
name|char
name|isacsx_sap2
decl_stmt|;
name|unsigned
name|char
name|isacsx_tei1
decl_stmt|;
name|unsigned
name|char
name|isacsx_tei2
decl_stmt|;
name|unsigned
name|char
name|isacsx_tmd
decl_stmt|;
name|unsigned
name|char
name|dummy_2a
decl_stmt|;
name|unsigned
name|char
name|dummy_2b
decl_stmt|;
name|unsigned
name|char
name|dummy_2c
decl_stmt|;
name|unsigned
name|char
name|dummy_2d
decl_stmt|;
name|unsigned
name|char
name|isacsx_cix0
decl_stmt|;
name|unsigned
name|char
name|isacsx_codx1
decl_stmt|;
name|unsigned
name|char
name|isacsx_tr_conf0
decl_stmt|;
name|unsigned
name|char
name|isacsx_tr_conf1
decl_stmt|;
name|unsigned
name|char
name|isacsx_tr_conf2
decl_stmt|;
name|unsigned
name|char
name|dummy_33
decl_stmt|;
name|unsigned
name|char
name|dummy_34
decl_stmt|;
name|unsigned
name|char
name|isacsx_sqrx1
decl_stmt|;
name|unsigned
name|char
name|dummy_36
decl_stmt|;
name|unsigned
name|char
name|dummy_37
decl_stmt|;
name|unsigned
name|char
name|dummy_38
decl_stmt|;
name|unsigned
name|char
name|isacsx_masktr
decl_stmt|;
name|unsigned
name|char
name|dummy_3a
decl_stmt|;
name|unsigned
name|char
name|dummy_3b
decl_stmt|;
name|unsigned
name|char
name|isacsx_acgf2
decl_stmt|;
name|unsigned
name|char
name|dummy_3d
decl_stmt|;
name|unsigned
name|char
name|dummy_3e
decl_stmt|;
name|unsigned
name|char
name|dummy_3f
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda10
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda11
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda20
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda21
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda_tsdp10
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda_tsdp11
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda_tsdp20
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda_tsdp21
decl_stmt|;
name|unsigned
name|char
name|dummy_48
decl_stmt|;
name|unsigned
name|char
name|dummy_49
decl_stmt|;
name|unsigned
name|char
name|dummy_4a
decl_stmt|;
name|unsigned
name|char
name|dummy_4b
decl_stmt|;
name|unsigned
name|char
name|isacsx_tr_tsdp_bc1
decl_stmt|;
name|unsigned
name|char
name|isacsx_tr_tsdp_bc2
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda1_cr
decl_stmt|;
name|unsigned
name|char
name|isacsx_cda2_cr
decl_stmt|;
name|unsigned
name|char
name|isacsx_tr_cr
decl_stmt|;
name|unsigned
name|char
name|dummy_51
decl_stmt|;
name|unsigned
name|char
name|dummy_52
decl_stmt|;
name|unsigned
name|char
name|isacsx_dci_cr
decl_stmt|;
name|unsigned
name|char
name|isacsx_mon_cr
decl_stmt|;
name|unsigned
name|char
name|isacsx_sds_cr
decl_stmt|;
name|unsigned
name|char
name|dummy_56
decl_stmt|;
name|unsigned
name|char
name|isacsx_iom_cr
decl_stmt|;
name|unsigned
name|char
name|isacsx_asti
decl_stmt|;
name|unsigned
name|char
name|isacsx_msti
decl_stmt|;
name|unsigned
name|char
name|isacsx_sds_conf
decl_stmt|;
name|unsigned
name|char
name|dummy_5b
decl_stmt|;
name|unsigned
name|char
name|isacsx_mox
decl_stmt|;
name|unsigned
name|char
name|dummy_5d
decl_stmt|;
name|unsigned
name|char
name|isacsx_mocr
decl_stmt|;
name|unsigned
name|char
name|isacsx_mconf
decl_stmt|;
name|unsigned
name|char
name|isacsx_mask
decl_stmt|;
name|unsigned
name|char
name|isacsx_auxm
decl_stmt|;
name|unsigned
name|char
name|isacsx_mode1
decl_stmt|;
name|unsigned
name|char
name|isacsx_mode2
decl_stmt|;
name|unsigned
name|char
name|isacsx_sres
decl_stmt|;
name|unsigned
name|char
name|isacsx_timr2
decl_stmt|;
name|unsigned
name|char
name|dummy_66
decl_stmt|;
name|unsigned
name|char
name|dummy_67
decl_stmt|;
name|unsigned
name|char
name|dummy_68
decl_stmt|;
name|unsigned
name|char
name|dummy_69
decl_stmt|;
name|unsigned
name|char
name|dummy_6a
decl_stmt|;
name|unsigned
name|char
name|dummy_6b
decl_stmt|;
name|unsigned
name|char
name|dummy_6c
decl_stmt|;
name|unsigned
name|char
name|dummy_6d
decl_stmt|;
name|unsigned
name|char
name|dummy_6e
decl_stmt|;
name|unsigned
name|char
name|dummy_6f
decl_stmt|;
block|}
name|isacsx_w
struct|;
block|}
name|isacsx_rw
union|;
block|}
name|isacsx_reg_t
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
comment|/* ISACSX read registers */
end_comment

begin_define
define|#
directive|define
name|i_istad
value|isacsx_rw.isacsx_r.isacsx_istad
end_define

begin_define
define|#
directive|define
name|I_ISTAD
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_istad)
end_define

begin_define
define|#
directive|define
name|i_stard
value|isacsx_rw.isacsx_r.isacsx_stard
end_define

begin_define
define|#
directive|define
name|I_STARD
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_stard)
end_define

begin_define
define|#
directive|define
name|i_rmoded
value|isacsx_rw.isacsx_r.isacsx_moded
end_define

begin_define
define|#
directive|define
name|I_RMODED
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_moded)
end_define

begin_define
define|#
directive|define
name|i_rexmd1
value|isacsx_rw.isacsx_r.isacsx_exmd1
end_define

begin_define
define|#
directive|define
name|I_REXMD1
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_exmd1)
end_define

begin_define
define|#
directive|define
name|i_rtimr1
value|isacsx_rw.isacsx_r.isacsx_timr1
end_define

begin_define
define|#
directive|define
name|I_RTIMR1
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_timr1)
end_define

begin_define
define|#
directive|define
name|i_rbcld
value|isacsx_rw.isacsx_r.isacsx_rbcld
end_define

begin_define
define|#
directive|define
name|I_RBCLD
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_rbcld)
end_define

begin_define
define|#
directive|define
name|i_rbchd
value|isacsx_rw.isacsx_r.isacsx_rbchd
end_define

begin_define
define|#
directive|define
name|I_RBCHD
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_rbchd)
end_define

begin_define
define|#
directive|define
name|i_rstad
value|isacsx_rw.isacsx_r.isacsx_rstad
end_define

begin_define
define|#
directive|define
name|I_RSTAD
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_rstad)
end_define

begin_define
define|#
directive|define
name|i_rtmd
value|isacsx_rw.isacsx_r.isacsx_tmd
end_define

begin_define
define|#
directive|define
name|I_RTMD
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_tmd)
end_define

begin_define
define|#
directive|define
name|i_cir0
value|isacsx_rw.isacsx_r.isacsx_cir0
end_define

begin_define
define|#
directive|define
name|I_CIR0
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cir0)
end_define

begin_define
define|#
directive|define
name|i_codr1
value|isacsx_rw.isacsx_r.isacsx_codr1
end_define

begin_define
define|#
directive|define
name|I_CODR1
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_codr1)
end_define

begin_define
define|#
directive|define
name|i_rtr_conf0
value|isacsx_rw.isacsx_r.isacsx_tr_conf0
end_define

begin_define
define|#
directive|define
name|I_RTR_CONF0
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_tr_conf0)
end_define

begin_define
define|#
directive|define
name|i_rtr_conf1
value|isacsx_rw.isacsx_r.isacsx_tr_conf1
end_define

begin_define
define|#
directive|define
name|I_RTR_CONF1
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_tr_conf1)
end_define

begin_define
define|#
directive|define
name|i_rtr_conf2
value|isacsx_rw.isacsx_r.isacsx_tr_conf2
end_define

begin_define
define|#
directive|define
name|I_RTR_CONF2
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_tr_conf2)
end_define

begin_define
define|#
directive|define
name|i_sta
value|isacsx_rw.isacsx_r.isacsx_sta
end_define

begin_define
define|#
directive|define
name|I_STA
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_sta)
end_define

begin_define
define|#
directive|define
name|i_sqrr1
value|isacsx_rw.isacsx_r.isacsx_sqrr1
end_define

begin_define
define|#
directive|define
name|I_SQRR1
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_sqrr1)
end_define

begin_define
define|#
directive|define
name|i_sqrr2
value|isacsx_rw.isacsx_r.isacsx_sqrr2
end_define

begin_define
define|#
directive|define
name|I_SQRR2
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_sqrr2)
end_define

begin_define
define|#
directive|define
name|i_sqrr3
value|isacsx_rw.isacsx_r.isacsx_sqrr3
end_define

begin_define
define|#
directive|define
name|I_SQRR3
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_sqrr3)
end_define

begin_define
define|#
directive|define
name|i_istatr
value|isacsx_rw.isacsx_r.isacsx_istatr
end_define

begin_define
define|#
directive|define
name|I_ISTATR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_istatr)
end_define

begin_define
define|#
directive|define
name|i_rmasktr
value|isacsx_rw.isacsx_r.isacsx_masktr
end_define

begin_define
define|#
directive|define
name|I_RMASKTR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_masktr)
end_define

begin_define
define|#
directive|define
name|i_racgf2
value|isacsx_rw.isacsx_r.isacsx_acgf2
end_define

begin_define
define|#
directive|define
name|I_RACGF2
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_acgf2)
end_define

begin_define
define|#
directive|define
name|i_rcda10
value|isacsx_rw.isacsx_r.isacsx_cda10
end_define

begin_define
define|#
directive|define
name|I_RCDA10
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda10)
end_define

begin_define
define|#
directive|define
name|i_rcda11
value|isacsx_rw.isacsx_r.isacsx_cda11
end_define

begin_define
define|#
directive|define
name|I_RCDA11
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda11)
end_define

begin_define
define|#
directive|define
name|i_rcda20
value|isacsx_rw.isacsx_r.isacsx_cda20
end_define

begin_define
define|#
directive|define
name|I_RCDA20
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda20)
end_define

begin_define
define|#
directive|define
name|i_rcda21
value|isacsx_rw.isacsx_r.isacsx_cda21
end_define

begin_define
define|#
directive|define
name|I_RCDA21
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda21)
end_define

begin_define
define|#
directive|define
name|i_cda_tsdp10
value|isacsx_rw.isacsx_r.isacsx_cda_tsdp10
end_define

begin_define
define|#
directive|define
name|I_CDA_TSDP10
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda_tsdp10)
end_define

begin_define
define|#
directive|define
name|i_cda_tsdp11
value|isacsx_rw.isacsx_r.isacsx_cda_tsdp11
end_define

begin_define
define|#
directive|define
name|I_CDA_TSDP11
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda_tsdp11)
end_define

begin_define
define|#
directive|define
name|i_cda_tsdp20
value|isacsx_rw.isacsx_r.isacsx_cda_tsdp20
end_define

begin_define
define|#
directive|define
name|I_CDA_TSDP20
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda_tsdp20)
end_define

begin_define
define|#
directive|define
name|i_cda_tsdp21
value|isacsx_rw.isacsx_r.isacsx_cda_tsdp21
end_define

begin_define
define|#
directive|define
name|I_CDA_TSDP21
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda_tsdp21)
end_define

begin_define
define|#
directive|define
name|i_tr_tsdp_bc1
value|isacsx_rw.isacsx_r.isacsx_tr_tsdp_bc1
end_define

begin_define
define|#
directive|define
name|I_TR_TSDP_BC1
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_tr_tsdp_bc1)
end_define

begin_define
define|#
directive|define
name|i_tr_tsdp_bc2
value|isacsx_rw.isacsx_r.isacsx_tr_tsdp_bc2
end_define

begin_define
define|#
directive|define
name|I_TR_TSDP_BC2
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_tr_tsdp_bc2)
end_define

begin_define
define|#
directive|define
name|i_cda1_cr
value|isacsx_rw.isacsx_r.isacsx_cda1_cr
end_define

begin_define
define|#
directive|define
name|I_CDA1_CR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda1_cr)
end_define

begin_define
define|#
directive|define
name|i_cda2_cr
value|isacsx_rw.isacsx_r.isacsx_cda2_cr
end_define

begin_define
define|#
directive|define
name|I_CDA2_CR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda2_cr)
end_define

begin_define
define|#
directive|define
name|i_tr_cr
value|isacsx_rw.isacsx_r.isacsx_tr_cr
end_define

begin_define
define|#
directive|define
name|I_TR_CR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_tr_cr)
end_define

begin_define
define|#
directive|define
name|i_dci_cr
value|isacsx_rw.isacsx_r.isacsx_dci_cr
end_define

begin_define
define|#
directive|define
name|I_DCI_CR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_dci_cr)
end_define

begin_define
define|#
directive|define
name|i_mon_cr
value|isacsx_rw.isacsx_r.isacsx_mon_cr
end_define

begin_define
define|#
directive|define
name|I_MON_CR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_mon_cr)
end_define

begin_define
define|#
directive|define
name|i_sds_cr
value|isacsx_rw.isacsx_r.isacsx_sds_cr
end_define

begin_define
define|#
directive|define
name|I_SDS_CR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_sds_cr)
end_define

begin_define
define|#
directive|define
name|i_iom_cr
value|isacsx_rw.isacsx_r.isacsx_iom_cr
end_define

begin_define
define|#
directive|define
name|I_IOM_CR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_iom_cr)
end_define

begin_define
define|#
directive|define
name|i_sti
value|isacsx_rw.isacsx_r.isacsx_sti
end_define

begin_define
define|#
directive|define
name|I_STI
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_sti)
end_define

begin_define
define|#
directive|define
name|i_msti
value|isacsx_rw.isacsx_r.isacsx_msti
end_define

begin_define
define|#
directive|define
name|I_MSTI
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_msti)
end_define

begin_define
define|#
directive|define
name|i_sds_conf
value|isacsx_rw.isacsx_r.isacsx_sds_conf
end_define

begin_define
define|#
directive|define
name|I_SDS_CONF
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_sds_conf)
end_define

begin_define
define|#
directive|define
name|i_mcda
value|isacsx_rw.isacsx_r.isacsx_mcda
end_define

begin_define
define|#
directive|define
name|I_MCDA
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_mcda)
end_define

begin_define
define|#
directive|define
name|i_mor
value|isacsx_rw.isacsx_r.isacsx_mor
end_define

begin_define
define|#
directive|define
name|I_MOR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_mor)
end_define

begin_define
define|#
directive|define
name|i_mosr
value|isacsx_rw.isacsx_r.isacsx_mosr
end_define

begin_define
define|#
directive|define
name|I_MOSR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_mosr)
end_define

begin_define
define|#
directive|define
name|i_rmocr
value|isacsx_rw.isacsx_r.isacsx_mocr
end_define

begin_define
define|#
directive|define
name|I_RMOCR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_mocr)
end_define

begin_define
define|#
directive|define
name|i_msta
value|isacsx_rw.isacsx_r.isacsx_msta
end_define

begin_define
define|#
directive|define
name|I_MSTA
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_msta)
end_define

begin_define
define|#
directive|define
name|i_ista
value|isacsx_rw.isacsx_r.isacsx_ista
end_define

begin_define
define|#
directive|define
name|I_ISTA
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_ista)
end_define

begin_define
define|#
directive|define
name|i_auxi
value|isacsx_rw.isacsx_r.isacsx_auxi
end_define

begin_define
define|#
directive|define
name|I_AUXI
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_auxi)
end_define

begin_define
define|#
directive|define
name|i_rmode1
value|isacsx_rw.isacsx_r.isacsx_mode1
end_define

begin_define
define|#
directive|define
name|I_RMODE1
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_mode1)
end_define

begin_define
define|#
directive|define
name|i_rmode2
value|isacsx_rw.isacsx_r.isacsx_mode2
end_define

begin_define
define|#
directive|define
name|I_RMODE2
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_mode2)
end_define

begin_define
define|#
directive|define
name|i_id
value|isacsx_rw.isacsx_r.isacsx_id
end_define

begin_define
define|#
directive|define
name|I_ID
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_id)
end_define

begin_define
define|#
directive|define
name|i_rtimr2
value|isacsx_rw.isacsx_r.isacsx_timr2
end_define

begin_define
define|#
directive|define
name|I_RTIMR2
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_timr2)
end_define

begin_comment
comment|/* ISAC write registers - isacsx_mode, isacsx_timr, isacsx_star2, isacsx_spcr, */
end_comment

begin_comment
comment|/* isacsx_c1r, isacsx_c2r, isacsx_adf2 see read registers */
end_comment

begin_define
define|#
directive|define
name|i_maskd
value|isacsx_rw.isacsx_w.isacsx_maskd
end_define

begin_define
define|#
directive|define
name|I_MASKD
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_maskd)
end_define

begin_define
define|#
directive|define
name|i_cmdrd
value|isacsx_rw.isacsx_w.isacsx_cmdrd
end_define

begin_define
define|#
directive|define
name|I_CMDRD
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_cmdrd)
end_define

begin_define
define|#
directive|define
name|i_wmoded
value|isacsx_rw.isacsx_w.isacsx_moded
end_define

begin_define
define|#
directive|define
name|I_WMODED
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_moded)
end_define

begin_define
define|#
directive|define
name|i_wexmd1
value|isacsx_rw.isacsx_w.isacsx_exmd1
end_define

begin_define
define|#
directive|define
name|I_WEXMD1
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_exmd1)
end_define

begin_define
define|#
directive|define
name|i_wtimr1
value|isacsx_rw.isacsx_w.isacsx_timr1
end_define

begin_define
define|#
directive|define
name|I_WTIMR1
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_timr1)
end_define

begin_define
define|#
directive|define
name|i_sap1
value|isacsx_rw.isacsx_w.isacsx_sap1
end_define

begin_define
define|#
directive|define
name|I_SAP1
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_sap1)
end_define

begin_define
define|#
directive|define
name|i_sap2
value|isacsx_rw.isacsx_w.isacsx_sap2
end_define

begin_define
define|#
directive|define
name|I_SAP2
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_sap2)
end_define

begin_define
define|#
directive|define
name|i_tei1
value|isacsx_rw.isacsx_w.isacsx_tei1
end_define

begin_define
define|#
directive|define
name|i_tei2
value|isacsx_rw.isacsx_w.isacsx_tei2
end_define

begin_define
define|#
directive|define
name|i_wtmd
value|isacsx_rw.isacsx_w.isacsx_tmd
end_define

begin_define
define|#
directive|define
name|I_WTMD
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_tmd)
end_define

begin_define
define|#
directive|define
name|i_cix0
value|isacsx_rw.isacsx_w.isacsx_cix0
end_define

begin_define
define|#
directive|define
name|I_CIX0
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_cix0)
end_define

begin_define
define|#
directive|define
name|i_codx1
value|isacsx_rw.isacsx_w.isacsx_codx1
end_define

begin_define
define|#
directive|define
name|I_CODX1
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_codx1)
end_define

begin_define
define|#
directive|define
name|i_wtr_conf0
value|isacsx_rw.isacsx_w.isacsx_tr_conf0
end_define

begin_define
define|#
directive|define
name|I_WTR_CONF0
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_tr_conf0)
end_define

begin_define
define|#
directive|define
name|i_wtr_conf1
value|isacsx_rw.isacsx_w.isacsx_tr_conf1
end_define

begin_define
define|#
directive|define
name|I_WTR_CONF1
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_tr_conf1)
end_define

begin_define
define|#
directive|define
name|i_wtr_conf2
value|isacsx_rw.isacsx_w.isacsx_tr_conf2
end_define

begin_define
define|#
directive|define
name|I_WTR_CONF2
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_tr_conf2)
end_define

begin_define
define|#
directive|define
name|i_sqrx1
value|isacsx_rw.isacsx_w.isacsx_sqrx1
end_define

begin_define
define|#
directive|define
name|I_SQRX1
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_sqrx1)
end_define

begin_define
define|#
directive|define
name|i_wmasktr
value|isacsx_rw.isacsx_w.isacsx_masktr
end_define

begin_define
define|#
directive|define
name|I_WMASKTR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_masktr)
end_define

begin_define
define|#
directive|define
name|i_wacgf2
value|isacsx_rw.isacsx_w.isacsx_acgf2
end_define

begin_define
define|#
directive|define
name|I_WACGF2
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_acgf2)
end_define

begin_define
define|#
directive|define
name|i_wcda10
value|isacsx_rw.isacsx_w.isacsx_cda10
end_define

begin_define
define|#
directive|define
name|I_WCDA10
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_cda10)
end_define

begin_define
define|#
directive|define
name|i_wcda11
value|isacsx_rw.isacsx_r.isacsx_cda11
end_define

begin_define
define|#
directive|define
name|I_WCDA11
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda11)
end_define

begin_define
define|#
directive|define
name|i_wcda20
value|isacsx_rw.isacsx_r.isacsx_cda20
end_define

begin_define
define|#
directive|define
name|I_WCDA20
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda20)
end_define

begin_define
define|#
directive|define
name|i_wcda21
value|isacsx_rw.isacsx_r.isacsx_cda21
end_define

begin_define
define|#
directive|define
name|I_WCDA21
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda21)
end_define

begin_define
define|#
directive|define
name|i_cda_tsdp10
value|isacsx_rw.isacsx_r.isacsx_cda_tsdp10
end_define

begin_define
define|#
directive|define
name|I_CDA_TSDP10
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda_tsdp10)
end_define

begin_define
define|#
directive|define
name|i_cda_tsdp11
value|isacsx_rw.isacsx_r.isacsx_cda_tsdp11
end_define

begin_define
define|#
directive|define
name|I_CDA_TSDP11
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda_tsdp11)
end_define

begin_define
define|#
directive|define
name|i_cda_tsdp20
value|isacsx_rw.isacsx_r.isacsx_cda_tsdp20
end_define

begin_define
define|#
directive|define
name|I_CDA_TSDP20
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda_tsdp20)
end_define

begin_define
define|#
directive|define
name|i_cda_tsdp21
value|isacsx_rw.isacsx_r.isacsx_cda_tsdp21
end_define

begin_define
define|#
directive|define
name|I_CDA_TSDP21
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda_tsdp21)
end_define

begin_define
define|#
directive|define
name|i_tr_tsdp_bc1
value|isacsx_rw.isacsx_r.isacsx_tr_tsdp_bc1
end_define

begin_define
define|#
directive|define
name|I_TR_TSDP_BC1
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_tr_tsdp_bc1)
end_define

begin_define
define|#
directive|define
name|i_tr_tsdp_bc2
value|isacsx_rw.isacsx_r.isacsx_tr_tsdp_bc2
end_define

begin_define
define|#
directive|define
name|I_TR_TSDP_BC2
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_tr_tsdp_bc2)
end_define

begin_define
define|#
directive|define
name|i_cda1_cr
value|isacsx_rw.isacsx_r.isacsx_cda1_cr
end_define

begin_define
define|#
directive|define
name|I_CDA1_CR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda1_cr)
end_define

begin_define
define|#
directive|define
name|i_cda2_cr
value|isacsx_rw.isacsx_r.isacsx_cda2_cr
end_define

begin_define
define|#
directive|define
name|I_CDA2_CR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_cda2_cr)
end_define

begin_define
define|#
directive|define
name|i_tr_cr
value|isacsx_rw.isacsx_r.isacsx_tr_cr
end_define

begin_define
define|#
directive|define
name|I_TR_CR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_tr_cr)
end_define

begin_define
define|#
directive|define
name|i_dci_cr
value|isacsx_rw.isacsx_r.isacsx_dci_cr
end_define

begin_define
define|#
directive|define
name|I_DCI_CR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_dci_cr)
end_define

begin_define
define|#
directive|define
name|i_mon_cr
value|isacsx_rw.isacsx_r.isacsx_mon_cr
end_define

begin_define
define|#
directive|define
name|I_MON_CR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_mon_cr)
end_define

begin_define
define|#
directive|define
name|i_sds_cr
value|isacsx_rw.isacsx_r.isacsx_sds_cr
end_define

begin_define
define|#
directive|define
name|I_SDS_CR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_sds_cr)
end_define

begin_define
define|#
directive|define
name|i_iom_cr
value|isacsx_rw.isacsx_r.isacsx_iom_cr
end_define

begin_define
define|#
directive|define
name|I_IOM_CR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_iom_cr)
end_define

begin_define
define|#
directive|define
name|i_asti
value|isacsx_rw.isacsx_r.isacsx_asti
end_define

begin_define
define|#
directive|define
name|I_ASTI
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_asti)
end_define

begin_define
define|#
directive|define
name|i_msti
value|isacsx_rw.isacsx_r.isacsx_msti
end_define

begin_define
define|#
directive|define
name|I_MSTI
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_msti)
end_define

begin_define
define|#
directive|define
name|i_sds_conf
value|isacsx_rw.isacsx_r.isacsx_sds_conf
end_define

begin_define
define|#
directive|define
name|I_SDS_CONF
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_r.isacsx_sds_conf)
end_define

begin_define
define|#
directive|define
name|i_mox
value|isacsx_rw.isacsx_w.isacsx_mox
end_define

begin_define
define|#
directive|define
name|I_MOX
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_mox)
end_define

begin_define
define|#
directive|define
name|i_wmocr
value|isacsx_rw.isacsx_w.isacsx_mocr
end_define

begin_define
define|#
directive|define
name|I_WMOCR
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_mocr)
end_define

begin_define
define|#
directive|define
name|i_mconf
value|isacsx_rw.isacsx_w.isacsx_mconf
end_define

begin_define
define|#
directive|define
name|I_MCONF
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_mconf)
end_define

begin_define
define|#
directive|define
name|i_mask
value|isacsx_rw.isacsx_w.isacsx_mask
end_define

begin_define
define|#
directive|define
name|I_MASK
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_mask)
end_define

begin_define
define|#
directive|define
name|i_auxm
value|isacsx_rw.isacsx_w.isacsx_auxm
end_define

begin_define
define|#
directive|define
name|I_AUXM
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_auxm)
end_define

begin_define
define|#
directive|define
name|i_wmode1
value|isacsx_rw.isacsx_w.isacsx_mode1
end_define

begin_define
define|#
directive|define
name|I_WMODE1
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_mode1)
end_define

begin_define
define|#
directive|define
name|i_wmode2
value|isacsx_rw.isacsx_w.isacsx_mode2
end_define

begin_define
define|#
directive|define
name|I_WMODE2
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_mode2)
end_define

begin_define
define|#
directive|define
name|i_sres
value|isacsx_rw.isacsx_w.isacsx_sres
end_define

begin_define
define|#
directive|define
name|I_SRES
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_sres)
end_define

begin_define
define|#
directive|define
name|i_wtimr2
value|isacsx_rw.isacsx_w.isacsx_timr2
end_define

begin_define
define|#
directive|define
name|I_WTIMR2
value|REG_OFFSET(isacsx_reg_t, isacsx_rw.isacsx_w.isacsx_timr2)
end_define

begin_define
define|#
directive|define
name|ISACSX_ISTAD_RME
value|0x80
end_define

begin_define
define|#
directive|define
name|ISACSX_ISTAD_RPF
value|0x40
end_define

begin_define
define|#
directive|define
name|ISACSX_ISTAD_RFO
value|0x20
end_define

begin_define
define|#
directive|define
name|ISACSX_ISTAD_XPR
value|0x10
end_define

begin_define
define|#
directive|define
name|ISACSX_ISTAD_XMR
value|0x08
end_define

begin_define
define|#
directive|define
name|ISACSX_ISTAD_XDU
value|0x04
end_define

begin_define
define|#
directive|define
name|ISACSX_MASKD_RME
value|0x80
end_define

begin_define
define|#
directive|define
name|ISACSX_MASKD_RPF
value|0x40
end_define

begin_define
define|#
directive|define
name|ISACSX_MASKD_RFO
value|0x20
end_define

begin_define
define|#
directive|define
name|ISACSX_MASKD_XPR
value|0x10
end_define

begin_define
define|#
directive|define
name|ISACSX_MASKD_XMR
value|0x08
end_define

begin_define
define|#
directive|define
name|ISACSX_MASKD_XDU
value|0x04
end_define

begin_comment
comment|/* these must always be set */
end_comment

begin_define
define|#
directive|define
name|ISACSX_MASKD_LOW
value|0x03
end_define

begin_define
define|#
directive|define
name|ISACSX_MASKD_ALL
value|0xff
end_define

begin_define
define|#
directive|define
name|ISACSX_STARD_XDOV
value|0x80
end_define

begin_define
define|#
directive|define
name|ISACSX_STARD_XFW
value|0x40
end_define

begin_define
define|#
directive|define
name|ISACSX_STARD_RAC1
value|0x08
end_define

begin_define
define|#
directive|define
name|ISACSX_STARD_XAC1
value|0x02
end_define

begin_define
define|#
directive|define
name|ISACSX_CMDRD_RMC
value|0x80
end_define

begin_define
define|#
directive|define
name|ISACSX_CMDRD_RRES
value|0x40
end_define

begin_define
define|#
directive|define
name|ISACSX_CMDRD_STI
value|0x10
end_define

begin_define
define|#
directive|define
name|ISACSX_CMDRD_XTF
value|0x08
end_define

begin_define
define|#
directive|define
name|ISACSX_CMDRD_XME
value|0x02
end_define

begin_define
define|#
directive|define
name|ISACSX_CMDRD_XRES
value|0x01
end_define

begin_define
define|#
directive|define
name|ISACSX_MODED_MDS2
value|0x80
end_define

begin_define
define|#
directive|define
name|ISACSX_MODED_MDS1
value|0x40
end_define

begin_define
define|#
directive|define
name|ISACSX_MODED_MDS0
value|0x20
end_define

begin_define
define|#
directive|define
name|ISACSX_MODED_RAC
value|0x08
end_define

begin_define
define|#
directive|define
name|ISACSX_MODED_DIM2
value|0x04
end_define

begin_define
define|#
directive|define
name|ISACSX_MODED_DIM1
value|0x02
end_define

begin_define
define|#
directive|define
name|ISACSX_MODED_DIM0
value|0x01
end_define

begin_comment
comment|/* default */
end_comment

begin_define
define|#
directive|define
name|ISACSX_EXMD1_XFBS_32
value|0x00
end_define

begin_comment
comment|/* XFIFO is 32 bytes */
end_comment

begin_define
define|#
directive|define
name|ISACSX_EXMD1_XFBS_16
value|0x80
end_define

begin_comment
comment|/* XFIFO is 16 bytes */
end_comment

begin_comment
comment|/* default */
end_comment

begin_define
define|#
directive|define
name|ISACSX_EXMD1_RFBS_32
value|0x00
end_define

begin_comment
comment|/* XFIFO is 32 bytes */
end_comment

begin_define
define|#
directive|define
name|ISACSX_EXMD1_RFBS_16
value|0x20
end_define

begin_comment
comment|/* XFIFO is 16 bytes */
end_comment

begin_define
define|#
directive|define
name|ISACSX_EXMD1_RFBS_08
value|0x40
end_define

begin_comment
comment|/* XFIFO is 8 bytes */
end_comment

begin_define
define|#
directive|define
name|ISACSX_EXMD1_RFBS_04
value|0x60
end_define

begin_comment
comment|/* XFIFO is 4 bytes */
end_comment

begin_define
define|#
directive|define
name|ISACSX_EXMD1_SRA
value|0x10
end_define

begin_define
define|#
directive|define
name|ISACSX_EXMD1_XCRC
value|0x08
end_define

begin_define
define|#
directive|define
name|ISACSX_EXMD1_RCRC
value|0x04
end_define

begin_define
define|#
directive|define
name|ISACSX_EXMD1_ITF
value|0x01
end_define

begin_define
define|#
directive|define
name|ISACSX_RSTAD_VFR
value|0x80
end_define

begin_define
define|#
directive|define
name|ISACSX_RSTAD_RDO
value|0x40
end_define

begin_define
define|#
directive|define
name|ISACSX_RSTAD_CRC
value|0x20
end_define

begin_define
define|#
directive|define
name|ISACSX_RSTAD_RAB
value|0x10
end_define

begin_define
define|#
directive|define
name|ISACSX_RSTAD_SA1
value|0x08
end_define

begin_define
define|#
directive|define
name|ISACSX_RSTAD_SA0
value|0x04
end_define

begin_define
define|#
directive|define
name|ISACSX_RSTAD_CR
value|0x02
end_define

begin_define
define|#
directive|define
name|ISACSX_RSTAD_TA
value|0x01
end_define

begin_define
define|#
directive|define
name|ISACSX_RSTAD_MASK
value|0xf0
end_define

begin_comment
comment|/* the interesting bits */
end_comment

begin_define
define|#
directive|define
name|ISACSX_RBCHD_OV
value|0x10
end_define

begin_comment
comment|/* the other 4 bits are the high bits of the receive byte count */
end_comment

begin_define
define|#
directive|define
name|ISACSX_CIR0_CIC0
value|0x08
end_define

begin_comment
comment|/* CODR0>> 4 */
end_comment

begin_define
define|#
directive|define
name|ISACSX_CIR0_IPU
value|0x07
end_define

begin_define
define|#
directive|define
name|ISACSX_CIR0_IDR
value|0x00
end_define

begin_define
define|#
directive|define
name|ISACSX_CIR0_ISD
value|0x02
end_define

begin_define
define|#
directive|define
name|ISACSX_CIR0_IDIS
value|0x03
end_define

begin_define
define|#
directive|define
name|ISACSX_CIR0_IEI
value|0x06
end_define

begin_define
define|#
directive|define
name|ISACSX_CIR0_IRSY
value|0x04
end_define

begin_define
define|#
directive|define
name|ISACSX_CIR0_IARD
value|0x08
end_define

begin_define
define|#
directive|define
name|ISACSX_CIR0_ITI
value|0x0a
end_define

begin_define
define|#
directive|define
name|ISACSX_CIR0_IATI
value|0x0b
end_define

begin_define
define|#
directive|define
name|ISACSX_CIR0_IAI8
value|0x0c
end_define

begin_define
define|#
directive|define
name|ISACSX_CIR0_IAI10
value|0x0d
end_define

begin_define
define|#
directive|define
name|ISACSX_CIR0_IDID
value|0x0f
end_define

begin_define
define|#
directive|define
name|ISACSX_IOM_CR_SPU
value|0x80
end_define

begin_define
define|#
directive|define
name|ISACSX_IOM_CR_CI_CS
value|0x20
end_define

begin_define
define|#
directive|define
name|ISACSX_IOM_CR_TIC_DIS
value|0x10
end_define

begin_define
define|#
directive|define
name|ISACSX_IOM_CR_EN_BCL
value|0x08
end_define

begin_define
define|#
directive|define
name|ISACSX_IOM_CR_CLKM
value|0x04
end_define

begin_define
define|#
directive|define
name|ISACSX_IOM_CR_DIS_OD
value|0x02
end_define

begin_define
define|#
directive|define
name|ISACSX_IOM_CR_DIS_IOM
value|0x01
end_define

begin_define
define|#
directive|define
name|ISACSX_CI_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|ISACSX_CIX0_BAC
value|0x01
end_define

begin_comment
comment|/* in IOM-2 mode the low bits are always 1 */
end_comment

begin_define
define|#
directive|define
name|ISACSX_CIX0_LOW
value|0x0e
end_define

begin_comment
comment|/* C/I codes from bits 7-4 (>> 4& 0xf) */
end_comment

begin_comment
comment|/* the commands */
end_comment

begin_define
define|#
directive|define
name|ISACSX_CIX0_CTIM
value|0
end_define

begin_define
define|#
directive|define
name|ISACSX_CIX0_CRS
value|0x01
end_define

begin_comment
comment|/* test mode only */
end_comment

begin_define
define|#
directive|define
name|ISACSX_CIX0_CSSSP
value|0x02
end_define

begin_comment
comment|/* test mode only */
end_comment

begin_define
define|#
directive|define
name|ISACSX_CIX0_CSSCP
value|0x03
end_define

begin_define
define|#
directive|define
name|ISACSX_CIX0_CAR8
value|0x08
end_define

begin_define
define|#
directive|define
name|ISACSX_CIX0_CAR10
value|0x09
end_define

begin_define
define|#
directive|define
name|ISACSX_CIX0_CARL
value|0x0a
end_define

begin_define
define|#
directive|define
name|ISACSX_CIX0_CDIU
value|0x0f
end_define

begin_comment
comment|/* Interrupt, General Configuration Registers */
end_comment

begin_define
define|#
directive|define
name|ISACSX_ISTA_ST
value|0x20
end_define

begin_define
define|#
directive|define
name|ISACSX_ISTA_CIC
value|0x10
end_define

begin_define
define|#
directive|define
name|ISACSX_ISTA_AUX
value|0x08
end_define

begin_define
define|#
directive|define
name|ISACSX_ISTA_TRAN
value|0x04
end_define

begin_define
define|#
directive|define
name|ISACSX_ISTA_MOS
value|0x02
end_define

begin_define
define|#
directive|define
name|ISACSX_ISTA_ICD
value|0x01
end_define

begin_define
define|#
directive|define
name|ISACSX_MASK_ST
value|0x20
end_define

begin_define
define|#
directive|define
name|ISACSX_MASK_CIC
value|0x10
end_define

begin_define
define|#
directive|define
name|ISACSX_MASK_AUX
value|0x08
end_define

begin_define
define|#
directive|define
name|ISACSX_MASK_TRAN
value|0x04
end_define

begin_define
define|#
directive|define
name|ISACSX_MASK_MOS
value|0x02
end_define

begin_define
define|#
directive|define
name|ISACSX_MASK_ICD
value|0x01
end_define

begin_define
define|#
directive|define
name|ISACSX_AUXI_EAW
value|0x20
end_define

begin_define
define|#
directive|define
name|ISACSX_AUXI_WOV
value|0x10
end_define

begin_define
define|#
directive|define
name|ISACSX_AUXI_TIN2
value|0x08
end_define

begin_define
define|#
directive|define
name|ISACSX_AUXI_TIN1
value|0x04
end_define

begin_define
define|#
directive|define
name|ISACSX_AUXM_EAW
value|0x20
end_define

begin_define
define|#
directive|define
name|ISACSX_AUXM_WOV
value|0x10
end_define

begin_define
define|#
directive|define
name|ISACSX_AUXM_TIN2
value|0x08
end_define

begin_define
define|#
directive|define
name|ISACSX_AUXM_TIN1
value|0x04
end_define

begin_define
define|#
directive|define
name|ISACSX_MODE1_WTC1
value|0x10
end_define

begin_define
define|#
directive|define
name|ISACSX_MODE1_WTC2
value|0x08
end_define

begin_define
define|#
directive|define
name|ISACSX_MODE1_CFS
value|0x04
end_define

begin_define
define|#
directive|define
name|ISACSX_MODE1_RSS2
value|0x02
end_define

begin_define
define|#
directive|define
name|ISACSX_MODE1_RSS1
value|0x01
end_define

begin_define
define|#
directive|define
name|ISACSX_MODE2_INT_POL
value|0x08
end_define

begin_define
define|#
directive|define
name|ISACSX_MODE2_PPSDX
value|0x01
end_define

begin_define
define|#
directive|define
name|ISACSX_ID_MASK
value|0x2F
end_define

begin_comment
comment|/* 0x01 = Version 1.3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I4B_ISACSX_H_ */
end_comment

end_unit

