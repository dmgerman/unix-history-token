begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   Copyright (c) 1996, 2000 Gary Jennejohn. All rights reserved.   *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *      documentation and/or other materials provided with the distribution.  *   3. Neither the name of the author nor the names of any co-contributors  *      may be used to endorse or promote products derived from this software  *      without specific prior written permission.  *   4. Altered versions must be plainly marked as such, and must not be  *      misrepresented as being the original software and/or documentation.  *     *   THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  *   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *   ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  *   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *   OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *   OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  *   SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  * $FreeBSD$  *  *      last edit-date: [Wed Jan 24 09:10:42 2001]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|I4B_ISAC_H_
end_ifndef

begin_define
define|#
directive|define
name|I4B_ISAC_H_
end_define

begin_comment
comment|/*  * The ISAC databook specifies a delay of 2.5 DCL clock cycles between  * writes to the ISAC command register CMDR. This is the delay used to  * satisfy this requirement.  */
end_comment

begin_define
define|#
directive|define
name|I4B_ISAC_CMDRWRDELAY
value|30
end_define

begin_if
if|#
directive|if
operator|(
name|I4B_ISAC_CMDRWRDELAY
operator|>
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|ISACCMDRWRDELAY
parameter_list|()
value|DELAY(I4B_ISAC_CMDRWRDELAY)
end_define

begin_else
else|#
directive|else
end_else

begin_warning
warning|#
directive|warning
literal|"I4B_ISAC_CMDRWRDELAY set to 0!"
end_warning

begin_define
define|#
directive|define
name|ISACCMDRWRDELAY
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|ISAC_VERSIONS
block|{
name|ISAC_VA
block|,
comment|/* 2085 A1 or A2, 2086/2186 V1.1	*/
name|ISAC_VB1
block|,
comment|/* 2085 B1				*/
name|ISAC_VB2
block|,
comment|/* 2085 B2				*/
name|ISAC_VB3
block|,
comment|/* 2085 B3/V2.3				*/
name|ISAC_UNKN
comment|/* unknown version			*/
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|ISAC_FIFO_LEN
value|32
end_define

begin_comment
comment|/* 32 bytes FIFO on chip */
end_comment

begin_comment
comment|/*  * definitions of registers and bits for the ISAC ISDN chip.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|isac_reg
block|{
comment|/* 32 byte deep FIFO always first */
name|unsigned
name|char
name|isac_fifo
index|[
name|ISAC_FIFO_LEN
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
name|isac_ista
decl_stmt|;
name|unsigned
name|char
name|isac_star
decl_stmt|;
name|unsigned
name|char
name|isac_mode
decl_stmt|;
name|unsigned
name|char
name|isac_timr
decl_stmt|;
name|unsigned
name|char
name|isac_exir
decl_stmt|;
name|unsigned
name|char
name|isac_rbcl
decl_stmt|;
name|unsigned
name|char
name|isac_sapr
decl_stmt|;
name|unsigned
name|char
name|isac_rsta
decl_stmt|;
name|unsigned
name|char
name|dummy_28
decl_stmt|;
name|unsigned
name|char
name|isac_rhcr
decl_stmt|;
name|unsigned
name|char
name|isac_rbch
decl_stmt|;
name|unsigned
name|char
name|isac_star2
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
name|dummy_2e
decl_stmt|;
name|unsigned
name|char
name|dummt_2f
decl_stmt|;
name|unsigned
name|char
name|isac_spcr
decl_stmt|;
name|unsigned
name|char
name|isac_cirr
decl_stmt|;
name|unsigned
name|char
name|isac_mor
decl_stmt|;
name|unsigned
name|char
name|isac_sscr
decl_stmt|;
name|unsigned
name|char
name|isac_sfcr
decl_stmt|;
name|unsigned
name|char
name|isac_c1r
decl_stmt|;
name|unsigned
name|char
name|isac_c2r
decl_stmt|;
name|unsigned
name|char
name|isac_b1cr
decl_stmt|;
name|unsigned
name|char
name|isac_b2cr
decl_stmt|;
name|unsigned
name|char
name|isac_adf2
decl_stmt|;
name|unsigned
name|char
name|isac_mosr
decl_stmt|;
name|unsigned
name|char
name|isac_sqrr
decl_stmt|;
block|}
name|isac_r
struct|;
struct|struct
block|{
name|unsigned
name|char
name|isac_mask
decl_stmt|;
name|unsigned
name|char
name|isac_cmdr
decl_stmt|;
name|unsigned
name|char
name|isac_mode
decl_stmt|;
name|unsigned
name|char
name|isac_timr
decl_stmt|;
name|unsigned
name|char
name|isac_xad1
decl_stmt|;
name|unsigned
name|char
name|isac_xad2
decl_stmt|;
name|unsigned
name|char
name|isac_sap1
decl_stmt|;
name|unsigned
name|char
name|isac_sap2
decl_stmt|;
name|unsigned
name|char
name|isac_tei1
decl_stmt|;
name|unsigned
name|char
name|isac_tei2
decl_stmt|;
name|unsigned
name|char
name|dummy_2a
decl_stmt|;
name|unsigned
name|char
name|isac_star2
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
name|dummy_2e
decl_stmt|;
name|unsigned
name|char
name|dummt_2f
decl_stmt|;
name|unsigned
name|char
name|isac_spcr
decl_stmt|;
name|unsigned
name|char
name|isac_cixr
decl_stmt|;
name|unsigned
name|char
name|isac_mox
decl_stmt|;
name|unsigned
name|char
name|isac_sscx
decl_stmt|;
name|unsigned
name|char
name|isac_sfcw
decl_stmt|;
name|unsigned
name|char
name|isac_c1r
decl_stmt|;
name|unsigned
name|char
name|isac_c2r
decl_stmt|;
name|unsigned
name|char
name|isac_stcr
decl_stmt|;
name|unsigned
name|char
name|isac_adf1
decl_stmt|;
name|unsigned
name|char
name|isac_adf2
decl_stmt|;
name|unsigned
name|char
name|isac_mocr
decl_stmt|;
name|unsigned
name|char
name|isac_sqxr
decl_stmt|;
block|}
name|isac_w
struct|;
block|}
name|isac_rw
union|;
block|}
name|isac_reg_t
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
comment|/* ISAC read registers */
end_comment

begin_define
define|#
directive|define
name|i_ista
value|isac_rw.isac_r.isac_ista
end_define

begin_define
define|#
directive|define
name|I_ISTA
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_ista)
end_define

begin_define
define|#
directive|define
name|i_star
value|isac_rw.isac_r.isac_star
end_define

begin_define
define|#
directive|define
name|I_STAR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_star)
end_define

begin_define
define|#
directive|define
name|i_mode
value|isac_rw.isac_r.isac_mode
end_define

begin_define
define|#
directive|define
name|I_MODE
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_mode)
end_define

begin_define
define|#
directive|define
name|i_timr
value|isac_rw.isac_r.isac_timr
end_define

begin_define
define|#
directive|define
name|I_TIMR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_timr)
end_define

begin_define
define|#
directive|define
name|i_exir
value|isac_rw.isac_r.isac_exir
end_define

begin_define
define|#
directive|define
name|I_EXIR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_exir)
end_define

begin_define
define|#
directive|define
name|i_rbcl
value|isac_rw.isac_r.isac_rbcl
end_define

begin_define
define|#
directive|define
name|I_RBCL
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_rbcl)
end_define

begin_define
define|#
directive|define
name|i_sapr
value|isac_rw.isac_r.isac_sapr
end_define

begin_define
define|#
directive|define
name|I_SAPR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_sapr)
end_define

begin_define
define|#
directive|define
name|i_rsta
value|isac_rw.isac_r.isac_rsta
end_define

begin_define
define|#
directive|define
name|I_RSTA
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_rsta)
end_define

begin_define
define|#
directive|define
name|i_rhcr
value|isac_rw.isac_r.isac_rhcr
end_define

begin_define
define|#
directive|define
name|I_RHCR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_rhcr)
end_define

begin_define
define|#
directive|define
name|i_rbch
value|isac_rw.isac_r.isac_rbch
end_define

begin_define
define|#
directive|define
name|I_RBCH
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_rbch)
end_define

begin_define
define|#
directive|define
name|i_star2
value|isac_rw.isac_r.isac_star2
end_define

begin_define
define|#
directive|define
name|I_STAR2
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_star2)
end_define

begin_define
define|#
directive|define
name|i_spcr
value|isac_rw.isac_r.isac_spcr
end_define

begin_define
define|#
directive|define
name|I_SPCR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_spcr)
end_define

begin_define
define|#
directive|define
name|i_cirr
value|isac_rw.isac_r.isac_cirr
end_define

begin_define
define|#
directive|define
name|I_CIRR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_cirr)
end_define

begin_define
define|#
directive|define
name|i_mor
value|isac_rw.isac_r.isac_mor
end_define

begin_define
define|#
directive|define
name|I_MOR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_mor)
end_define

begin_define
define|#
directive|define
name|i_sscr
value|isac_rw.isac_r.isac_sscr
end_define

begin_define
define|#
directive|define
name|I_SSCR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_sscr)
end_define

begin_define
define|#
directive|define
name|i_sfcr
value|isac_rw.isac_r.isac_sfcr
end_define

begin_define
define|#
directive|define
name|I_SFCR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_sfcr)
end_define

begin_define
define|#
directive|define
name|i_c1r
value|isac_rw.isac_r.isac_c1r
end_define

begin_define
define|#
directive|define
name|I_C1R
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_c1r)
end_define

begin_define
define|#
directive|define
name|i_c2r
value|isac_rw.isac_r.isac_c2r
end_define

begin_define
define|#
directive|define
name|I_C2R
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_c2r)
end_define

begin_define
define|#
directive|define
name|i_b1cr
value|isac_rw.isac_r.isac_b1cr
end_define

begin_define
define|#
directive|define
name|I_B1CR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_b1cr)
end_define

begin_define
define|#
directive|define
name|i_b2cr
value|isac_rw.isac_r.isac_b2cr
end_define

begin_define
define|#
directive|define
name|I_B2CR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_b2cr)
end_define

begin_define
define|#
directive|define
name|i_adf2
value|isac_rw.isac_r.isac_adf2
end_define

begin_define
define|#
directive|define
name|I_ADF2
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_adf2)
end_define

begin_define
define|#
directive|define
name|i_mosr
value|isac_rw.isac_r.isac_mosr
end_define

begin_define
define|#
directive|define
name|I_MOSR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_mosr)
end_define

begin_define
define|#
directive|define
name|i_sqrr
value|isac_rw.isac_r.isac_sqrr
end_define

begin_define
define|#
directive|define
name|I_SQRR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_r.isac_sqrr)
end_define

begin_comment
comment|/* ISAC write registers - isac_mode, isac_timr, isac_star2, isac_spcr, */
end_comment

begin_comment
comment|/* isac_c1r, isac_c2r, isac_adf2 see read registers */
end_comment

begin_define
define|#
directive|define
name|i_mask
value|isac_rw.isac_w.isac_mask
end_define

begin_define
define|#
directive|define
name|I_MASK
value|REG_OFFSET(isac_reg_t, isac_rw.isac_w.isac_mask)
end_define

begin_define
define|#
directive|define
name|i_cmdr
value|isac_rw.isac_w.isac_cmdr
end_define

begin_define
define|#
directive|define
name|I_CMDR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_w.isac_cmdr)
end_define

begin_define
define|#
directive|define
name|i_xad1
value|isac_rw.isac_w.isac_xad1
end_define

begin_define
define|#
directive|define
name|I_XAD1
value|REG_OFFSET(isac_reg_t, isac_rw.isac_w.isac_xad1)
end_define

begin_define
define|#
directive|define
name|i_xad2
value|isac_rw.isac_w.isac_xad2
end_define

begin_define
define|#
directive|define
name|I_XAD2
value|REG_OFFSET(isac_reg_t, isac_rw.isac_w.isac_xad2)
end_define

begin_define
define|#
directive|define
name|i_sap1
value|isac_rw.isac_w.isac_sap1
end_define

begin_define
define|#
directive|define
name|I_SAP1
value|REG_OFFSET(isac_reg_t, isac_rw.isac_w.isac_sap1)
end_define

begin_define
define|#
directive|define
name|i_sap2
value|isac_rw.isac_w.isac_sap2
end_define

begin_define
define|#
directive|define
name|I_SAP2
value|REG_OFFSET(isac_reg_t, isac_rw.isac_w.isac_sap2)
end_define

begin_define
define|#
directive|define
name|i_tei1
value|isac_rw.isac_w.isac_tei1
end_define

begin_define
define|#
directive|define
name|i_tei2
value|isac_rw.isac_w.isac_tei2
end_define

begin_define
define|#
directive|define
name|i_cixr
value|isac_rw.isac_w.isac_cixr
end_define

begin_define
define|#
directive|define
name|I_CIXR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_w.isac_cixr)
end_define

begin_define
define|#
directive|define
name|I_CIX0
value|I_CIXR
end_define

begin_define
define|#
directive|define
name|i_mox
value|isac_rw.isac_w.isac_mox
end_define

begin_define
define|#
directive|define
name|I_MOX
value|REG_OFFSET(isac_reg_t, isac_rw.isac_w.isac_mox)
end_define

begin_define
define|#
directive|define
name|i_sscx
value|isac_rw.isac_w.isac_sscx
end_define

begin_define
define|#
directive|define
name|I_SSCX
value|REG_OFFSET(isac_reg_t, isac_rw.isac_w.isac_sscx)
end_define

begin_define
define|#
directive|define
name|i_sfcw
value|isac_rw.isac_w.isac_sfcw
end_define

begin_define
define|#
directive|define
name|I_SFCW
value|REG_OFFSET(isac_reg_t, isac_rw.isac_w.isac_sfcw)
end_define

begin_define
define|#
directive|define
name|i_stcr
value|isac_rw.isac_w.isac_stcr
end_define

begin_define
define|#
directive|define
name|I_STCR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_w.isac_stcr)
end_define

begin_define
define|#
directive|define
name|i_adf1
value|isac_rw.isac_w.isac_adf1
end_define

begin_define
define|#
directive|define
name|I_ADF1
value|REG_OFFSET(isac_reg_t, isac_rw.isac_w.isac_adf1)
end_define

begin_define
define|#
directive|define
name|i_mocr
value|isac_rw.isac_w.isac_mocr
end_define

begin_define
define|#
directive|define
name|I_MOCR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_w.isac_mocr)
end_define

begin_define
define|#
directive|define
name|i_sqxr
value|isac_rw.isac_w.isac_sqxr
end_define

begin_define
define|#
directive|define
name|I_SQXR
value|REG_OFFSET(isac_reg_t, isac_rw.isac_w.isac_sqxr)
end_define

begin_define
define|#
directive|define
name|ISAC_ISTA_RME
value|0x80
end_define

begin_define
define|#
directive|define
name|ISAC_ISTA_RPF
value|0x40
end_define

begin_define
define|#
directive|define
name|ISAC_ISTA_RSC
value|0x20
end_define

begin_define
define|#
directive|define
name|ISAC_ISTA_XPR
value|0x10
end_define

begin_define
define|#
directive|define
name|ISAC_ISTA_TIN
value|0x08
end_define

begin_define
define|#
directive|define
name|ISAC_ISTA_CISQ
value|0x04
end_define

begin_define
define|#
directive|define
name|ISAC_ISTA_SIN
value|0x02
end_define

begin_define
define|#
directive|define
name|ISAC_ISTA_EXI
value|0x01
end_define

begin_define
define|#
directive|define
name|ISAC_MASK_RME
value|0x80
end_define

begin_define
define|#
directive|define
name|ISAC_MASL_RPF
value|0x40
end_define

begin_define
define|#
directive|define
name|ISAC_MASK_RSC
value|0x20
end_define

begin_define
define|#
directive|define
name|ISAC_MASK_XPR
value|0x10
end_define

begin_define
define|#
directive|define
name|ISAC_MASK_TIN
value|0x08
end_define

begin_define
define|#
directive|define
name|ISAC_MASK_CISQ
value|0x04
end_define

begin_define
define|#
directive|define
name|ISAC_MASK_SIN
value|0x02
end_define

begin_define
define|#
directive|define
name|ISAC_MASK_EXI
value|0x01
end_define

begin_define
define|#
directive|define
name|ISAC_MASK_ALL
value|0xff
end_define

begin_define
define|#
directive|define
name|ISAC_STAR_XDOV
value|0x80
end_define

begin_define
define|#
directive|define
name|ISAC_STAR_XFW
value|0x40
end_define

begin_define
define|#
directive|define
name|ISAC_STAR_XRNR
value|0x20
end_define

begin_define
define|#
directive|define
name|ISAC_STAR_RRNR
value|0x10
end_define

begin_define
define|#
directive|define
name|ISAC_STAR_MBR
value|0x08
end_define

begin_define
define|#
directive|define
name|ISAC_STAR_MAC1
value|0x04
end_define

begin_define
define|#
directive|define
name|ISAC_STAR_BVS
value|0x02
end_define

begin_define
define|#
directive|define
name|ISAC_STAR_MAC0
value|0x01
end_define

begin_define
define|#
directive|define
name|ISAC_CMDR_RMC
value|0x80
end_define

begin_define
define|#
directive|define
name|ISAC_CMDR_RRES
value|0x40
end_define

begin_define
define|#
directive|define
name|ISAC_CMDR_RNR
value|0x20
end_define

begin_define
define|#
directive|define
name|ISAC_CMDR_STI
value|0x10
end_define

begin_define
define|#
directive|define
name|ISAC_CMDR_XTF
value|0x08
end_define

begin_define
define|#
directive|define
name|ISAC_CMDR_XIF
value|0x04
end_define

begin_define
define|#
directive|define
name|ISAC_CMDR_XME
value|0x02
end_define

begin_define
define|#
directive|define
name|ISAC_CMDR_XRES
value|0x01
end_define

begin_define
define|#
directive|define
name|ISAC_MODE_MDS2
value|0x80
end_define

begin_define
define|#
directive|define
name|ISAC_MODE_MDS1
value|0x40
end_define

begin_define
define|#
directive|define
name|ISAC_MODE_MDS0
value|0x20
end_define

begin_define
define|#
directive|define
name|ISAC_MODE_TMD
value|0x10
end_define

begin_define
define|#
directive|define
name|ISAC_MODE_RAC
value|0x08
end_define

begin_define
define|#
directive|define
name|ISAC_MODE_DIM2
value|0x04
end_define

begin_define
define|#
directive|define
name|ISAC_MODE_DIM1
value|0x02
end_define

begin_define
define|#
directive|define
name|ISAC_MODE_DIM0
value|0x01
end_define

begin_define
define|#
directive|define
name|ISAC_EXIR_XMR
value|0x80
end_define

begin_define
define|#
directive|define
name|ISAC_EXIR_XDU
value|0x40
end_define

begin_define
define|#
directive|define
name|ISAC_EXIR_PCE
value|0x20
end_define

begin_define
define|#
directive|define
name|ISAC_EXIR_RFO
value|0x10
end_define

begin_define
define|#
directive|define
name|ISAC_EXIR_SOV
value|0x08
end_define

begin_define
define|#
directive|define
name|ISAC_EXIR_MOS
value|0x04
end_define

begin_define
define|#
directive|define
name|ISAC_EXIR_SAW
value|0x02
end_define

begin_define
define|#
directive|define
name|ISAC_EXIR_WOV
value|0x01
end_define

begin_define
define|#
directive|define
name|ISAC_RSTA_RDA
value|0x80
end_define

begin_define
define|#
directive|define
name|ISAC_RSTA_RDO
value|0x40
end_define

begin_define
define|#
directive|define
name|ISAC_RSTA_CRC
value|0x20
end_define

begin_define
define|#
directive|define
name|ISAC_RSTA_RAB
value|0x10
end_define

begin_define
define|#
directive|define
name|ISAC_RSTA_SA1
value|0x08
end_define

begin_define
define|#
directive|define
name|ISAC_RSTA_SA0
value|0x04
end_define

begin_define
define|#
directive|define
name|ISAC_RSTA_CR
value|0x02
end_define

begin_define
define|#
directive|define
name|ISAC_RSTA_TA
value|0x01
end_define

begin_define
define|#
directive|define
name|ISAC_RSTA_MASK
value|0x70
end_define

begin_comment
comment|/* the interesting bits */
end_comment

begin_define
define|#
directive|define
name|ISAC_RBCH_XAC
value|0x80
end_define

begin_define
define|#
directive|define
name|ISAC_RBCH_VN1
value|0x40
end_define

begin_define
define|#
directive|define
name|ISAC_RBCH_VN0
value|0x20
end_define

begin_define
define|#
directive|define
name|ISAC_RBCH_OV
value|0x10
end_define

begin_comment
comment|/* the other 4 bits are the high bits of the receive byte count */
end_comment

begin_define
define|#
directive|define
name|ISAC_SPCR_SPU
value|0x80
end_define

begin_define
define|#
directive|define
name|ISAC_SPCR_SAC
value|0x40
end_define

begin_define
define|#
directive|define
name|ISAC_SPCR_SPM
value|0x20
end_define

begin_define
define|#
directive|define
name|ISAC_SPCR_TLP
value|0x10
end_define

begin_define
define|#
directive|define
name|ISAC_SPCR_C1C1
value|0x08
end_define

begin_define
define|#
directive|define
name|ISAC_SPCR_C1C0
value|0x04
end_define

begin_define
define|#
directive|define
name|ISAC_SPCR_C2C1
value|0x02
end_define

begin_define
define|#
directive|define
name|ISAC_SPCR_C2C0
value|0x01
end_define

begin_define
define|#
directive|define
name|ISAC_CIRR_SQC
value|0x80
end_define

begin_define
define|#
directive|define
name|ISAC_CIRR_BAS
value|0x40
end_define

begin_comment
comment|/* bits 5-2 CODR */
end_comment

begin_define
define|#
directive|define
name|ISAC_CIRR_CIC0
value|0x02
end_define

begin_comment
comment|/* bit 0 is always 0 */
end_comment

begin_comment
comment|/* C/I codes from bits 5-2 (>> 2& 0xf) */
end_comment

begin_comment
comment|/* the indications */
end_comment

begin_define
define|#
directive|define
name|ISAC_CIRR_IPU
value|0x07
end_define

begin_define
define|#
directive|define
name|ISAC_CIRR_IDR
value|0x00
end_define

begin_define
define|#
directive|define
name|ISAC_CIRR_ISD
value|0x02
end_define

begin_define
define|#
directive|define
name|ISAC_CIRR_IDIS
value|0x03
end_define

begin_define
define|#
directive|define
name|ISAC_CIRR_IEI
value|0x06
end_define

begin_define
define|#
directive|define
name|ISAC_CIRR_IRSY
value|0x04
end_define

begin_define
define|#
directive|define
name|ISAC_CIRR_IARD
value|0x08
end_define

begin_define
define|#
directive|define
name|ISAC_CIRR_ITI
value|0x0a
end_define

begin_define
define|#
directive|define
name|ISAC_CIRR_IATI
value|0x0b
end_define

begin_define
define|#
directive|define
name|ISAC_CIRR_IAI8
value|0x0c
end_define

begin_define
define|#
directive|define
name|ISAC_CIRR_IAI10
value|0x0d
end_define

begin_define
define|#
directive|define
name|ISAC_CIRR_IDID
value|0x0f
end_define

begin_define
define|#
directive|define
name|ISAC_CI_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|ISAC_CIXR_RSS
value|0x80
end_define

begin_define
define|#
directive|define
name|ISAC_CIXR_BAC
value|0x40
end_define

begin_comment
comment|/* bits 5-2 CODX */
end_comment

begin_define
define|#
directive|define
name|ISAC_CIXR_TCX
value|0x02
end_define

begin_define
define|#
directive|define
name|ISAC_CIXR_ECX
value|0x01
end_define

begin_comment
comment|/* in IOM-2 mode the low bits are always 1 */
end_comment

begin_define
define|#
directive|define
name|ISAC_CIX0_LOW
value|0x03
end_define

begin_comment
comment|/* C/I codes from bits 5-2 (>> 2& 0xf) */
end_comment

begin_comment
comment|/* the commands */
end_comment

begin_define
define|#
directive|define
name|ISAC_CIXR_CTIM
value|0
end_define

begin_define
define|#
directive|define
name|ISAC_CIXR_CRS
value|0x01
end_define

begin_define
define|#
directive|define
name|ISAC_CIXR_CSCZ
value|0x04
end_define

begin_define
define|#
directive|define
name|ISAC_CIXR_CSSZ
value|0x02
end_define

begin_define
define|#
directive|define
name|ISAC_CIXR_CAR8
value|0x08
end_define

begin_define
define|#
directive|define
name|ISAC_CIXR_CAR10
value|0x09
end_define

begin_define
define|#
directive|define
name|ISAC_CIXR_CARL
value|0x0a
end_define

begin_define
define|#
directive|define
name|ISAC_CIXR_CDIU
value|0x0f
end_define

begin_define
define|#
directive|define
name|ISAC_STCR_TSF
value|0x80
end_define

begin_define
define|#
directive|define
name|ISAC_STCR_TBA2
value|0x40
end_define

begin_define
define|#
directive|define
name|ISAC_STCR_TBA1
value|0x20
end_define

begin_define
define|#
directive|define
name|ISAC_STCR_TBA0
value|0x10
end_define

begin_define
define|#
directive|define
name|ISAC_STCR_ST1
value|0x08
end_define

begin_define
define|#
directive|define
name|ISAC_STCR_ST0
value|0x04
end_define

begin_define
define|#
directive|define
name|ISAC_STCR_SC1
value|0x02
end_define

begin_define
define|#
directive|define
name|ISAC_STCR_SC0
value|0x01
end_define

begin_define
define|#
directive|define
name|ISAC_ADF1_WTC1
value|0x80
end_define

begin_define
define|#
directive|define
name|ISAC_ADF1_WTC2
value|0x40
end_define

begin_define
define|#
directive|define
name|ISAC_ADF1_TEM
value|0x20
end_define

begin_define
define|#
directive|define
name|ISAC_ADF1_PFS
value|0x10
end_define

begin_define
define|#
directive|define
name|ISAC_ADF1_CFS
value|0x08
end_define

begin_define
define|#
directive|define
name|ISAC_ADF1_FC2
value|0x04
end_define

begin_define
define|#
directive|define
name|ISAC_ADF1_FC1
value|0x02
end_define

begin_define
define|#
directive|define
name|ISAC_ADF1_ITF
value|0x01
end_define

begin_define
define|#
directive|define
name|ISAC_ADF2_IMS
value|0x80
end_define

begin_comment
comment|/* all other bits are 0 */
end_comment

begin_comment
comment|/* bits 7-5 are always 0 */
end_comment

begin_define
define|#
directive|define
name|ISAC_SQRR_SYN
value|0x10
end_define

begin_define
define|#
directive|define
name|ISAC_SQRR_SQR1
value|0x08
end_define

begin_define
define|#
directive|define
name|ISAC_SQRR_SQR2
value|0x04
end_define

begin_define
define|#
directive|define
name|ISAC_SQRR_SQR3
value|0x02
end_define

begin_define
define|#
directive|define
name|ISAC_SQRR_SQR4
value|0x01
end_define

begin_define
define|#
directive|define
name|ISAC_SQXR_IDC
value|0x80
end_define

begin_define
define|#
directive|define
name|ISAC_SQXR_CFS
value|0x40
end_define

begin_define
define|#
directive|define
name|ISAC_SQXR_CI1E
value|0x20
end_define

begin_define
define|#
directive|define
name|ISAC_SQXR_SQIE
value|0x10
end_define

begin_define
define|#
directive|define
name|ISAC_SQXR_SQX1
value|0x08
end_define

begin_define
define|#
directive|define
name|ISAC_SQXR_SQX2
value|0x04
end_define

begin_define
define|#
directive|define
name|ISAC_SQXR_SQX3
value|0x02
end_define

begin_define
define|#
directive|define
name|ISAC_SQXR_SQX4
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I4B_ISAC_H_ */
end_comment

end_unit

