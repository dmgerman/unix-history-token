begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   Copyright (c) 1996, 2000 Gary Jennejohn. All rights reserved.   *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *      documentation and/or other materials provided with the distribution.  *   3. Neither the name of the author nor the names of any co-contributors  *      may be used to endorse or promote products derived from this software  *      without specific prior written permission.  *   4. Altered versions must be plainly marked as such, and must not be  *      misrepresented as being the original software and/or documentation.  *     *   THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  *   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *   ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  *   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *   OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *   OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  *   SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  * $FreeBSD$  *  *      last edit-date: [Wed Jan 24 09:09:51 2001]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|I4B_HSCX_H_
end_ifndef

begin_define
define|#
directive|define
name|I4B_HSCX_H_
end_define

begin_enum
enum|enum
name|HSCX_VERSIONS
block|{
name|HSCX_VA1
block|,
comment|/* 82525 A1  */
name|HSCX_UNKN1
block|,
comment|/* unknown 1 */
name|HSCX_VA2
block|,
comment|/* 82525 A2  */
name|HSCX_UNKN3
block|,
comment|/* unknown 3 */
name|HSCX_VA3
block|,
comment|/* 82525 A3  */
name|HSCX_V21
block|,
comment|/* 82525 2.1 */
name|HSCX_UNKN
comment|/* unknown version */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|HSCX_CH_A
value|0
end_define

begin_comment
comment|/* channel A */
end_comment

begin_define
define|#
directive|define
name|HSCX_CH_B
value|1
end_define

begin_comment
comment|/* channel B */
end_comment

begin_define
define|#
directive|define
name|HSCX_FIFO_LEN
value|32
end_define

begin_comment
comment|/* 32 bytes FIFO on chip */
end_comment

begin_comment
comment|/*  * definitions of registers and bits for the HSCX ISDN chip.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hscx_reg
block|{
comment|/* 32 byte deep FIFO always first */
name|unsigned
name|char
name|hscx_fifo
index|[
name|HSCX_FIFO_LEN
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
name|hscx_ista
decl_stmt|;
name|unsigned
name|char
name|hscx_star
decl_stmt|;
name|unsigned
name|char
name|hscx_mode
decl_stmt|;
name|unsigned
name|char
name|hscx_timr
decl_stmt|;
name|unsigned
name|char
name|hscx_exir
decl_stmt|;
name|unsigned
name|char
name|hscx_rbcl
decl_stmt|;
name|unsigned
name|char
name|dummy_26
decl_stmt|;
name|unsigned
name|char
name|hscx_rsta
decl_stmt|;
name|unsigned
name|char
name|hscx_ral1
decl_stmt|;
name|unsigned
name|char
name|hscx_rhcr
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
name|hscx_ccr2
decl_stmt|;
name|unsigned
name|char
name|hscx_rbch
decl_stmt|;
name|unsigned
name|char
name|hscx_vstr
decl_stmt|;
name|unsigned
name|char
name|hscx_ccr
decl_stmt|;
name|unsigned
name|char
name|dummy_30
decl_stmt|;
name|unsigned
name|char
name|dummy_31
decl_stmt|;
name|unsigned
name|char
name|dummy_32
decl_stmt|;
name|unsigned
name|char
name|dummy_33
decl_stmt|;
block|}
name|hscx_r
struct|;
struct|struct
block|{
name|unsigned
name|char
name|hscx_mask
decl_stmt|;
name|unsigned
name|char
name|hscx_cmdr
decl_stmt|;
name|unsigned
name|char
name|hscx_mode
decl_stmt|;
name|unsigned
name|char
name|hscx_timr
decl_stmt|;
name|unsigned
name|char
name|hscx_xad1
decl_stmt|;
name|unsigned
name|char
name|hscx_xad2
decl_stmt|;
name|unsigned
name|char
name|hscx_rah1
decl_stmt|;
name|unsigned
name|char
name|hscx_rah2
decl_stmt|;
name|unsigned
name|char
name|hscx_ral1
decl_stmt|;
name|unsigned
name|char
name|hscx_ral2
decl_stmt|;
name|unsigned
name|char
name|hscx_xbcl
decl_stmt|;
name|unsigned
name|char
name|hscx_bgr
decl_stmt|;
name|unsigned
name|char
name|hscx_ccr2
decl_stmt|;
name|unsigned
name|char
name|hscx_xbch
decl_stmt|;
name|unsigned
name|char
name|hscx_rlcr
decl_stmt|;
name|unsigned
name|char
name|hscx_ccr1
decl_stmt|;
name|unsigned
name|char
name|hscx_tsax
decl_stmt|;
name|unsigned
name|char
name|hscx_tsar
decl_stmt|;
name|unsigned
name|char
name|hscx_xccr
decl_stmt|;
name|unsigned
name|char
name|hscx_rccr
decl_stmt|;
block|}
name|hscx_w
struct|;
block|}
name|hscx_rw
union|;
block|}
name|hscx_reg_t
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
comment|/* HSCX read registers */
end_comment

begin_define
define|#
directive|define
name|h_ista
value|hscx_rw.hscx_r.hscx_ista
end_define

begin_define
define|#
directive|define
name|H_ISTA
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_r.hscx_ista)
end_define

begin_define
define|#
directive|define
name|h_star
value|hscx_rw.hscx_r.hscx_star
end_define

begin_define
define|#
directive|define
name|H_STAR
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_r.hscx_star)
end_define

begin_define
define|#
directive|define
name|h_mode
value|hscx_rw.hscx_r.hscx_mode
end_define

begin_define
define|#
directive|define
name|H_MODE
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_r.hscx_mode)
end_define

begin_define
define|#
directive|define
name|h_timr
value|hscx_rw.hscx_r.hscx_timr
end_define

begin_define
define|#
directive|define
name|H_TIMR
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_r.hscx_timr)
end_define

begin_define
define|#
directive|define
name|h_exir
value|hscx_rw.hscx_r.hscx_exir
end_define

begin_define
define|#
directive|define
name|H_EXIR
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_r.hscx_exir)
end_define

begin_define
define|#
directive|define
name|h_rbcl
value|hscx_rw.hscx_r.hscx_rbcl
end_define

begin_define
define|#
directive|define
name|H_RBCL
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_r.hscx_rbcl)
end_define

begin_define
define|#
directive|define
name|h_rsta
value|hscx_rw.hscx_r.hscx_rsta
end_define

begin_define
define|#
directive|define
name|H_RSTA
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_r.hscx_rsta)
end_define

begin_define
define|#
directive|define
name|h_ral1
value|hscx_rw.hscx_r.hscx_ral1
end_define

begin_define
define|#
directive|define
name|H_RAL1
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_r.hscx_ral1)
end_define

begin_define
define|#
directive|define
name|h_rhcr
value|hscx_rw.hscx_r.hscx_rhcr
end_define

begin_define
define|#
directive|define
name|H_RHCR
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_r.hscx_rhcr)
end_define

begin_define
define|#
directive|define
name|h_ccr2
value|hscx_rw.hscx_r.hscx_ccr2
end_define

begin_define
define|#
directive|define
name|H_CCR2
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_r.hscx_ccr2)
end_define

begin_define
define|#
directive|define
name|h_rbch
value|hscx_rw.hscx_r.hscx_rbch
end_define

begin_define
define|#
directive|define
name|H_RBCH
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_r.hscx_rbch)
end_define

begin_define
define|#
directive|define
name|h_vstr
value|hscx_rw.hscx_r.hscx_vstr
end_define

begin_define
define|#
directive|define
name|H_VSTR
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_r.hscx_vstr)
end_define

begin_define
define|#
directive|define
name|h_ccr
value|hscx_rw.hscx_r.hscx_ccr
end_define

begin_define
define|#
directive|define
name|H_CCR
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_r.hscx_ccr)
end_define

begin_comment
comment|/* HSCX write registers - for hscx_mode, hscx_timr, hscx_ral1, hscx_ccr2 */
end_comment

begin_comment
comment|/* see read registers */
end_comment

begin_define
define|#
directive|define
name|h_mask
value|hscx_rw.hscx_w.hscx_mask
end_define

begin_define
define|#
directive|define
name|H_MASK
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_w.hscx_mask)
end_define

begin_define
define|#
directive|define
name|h_cmdr
value|hscx_rw.hscx_w.hscx_cmdr
end_define

begin_define
define|#
directive|define
name|H_CMDR
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_w.hscx_cmdr)
end_define

begin_define
define|#
directive|define
name|h_xad1
value|hscx_rw.hscx_w.hscx_xad1
end_define

begin_define
define|#
directive|define
name|H_XAD1
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_w.hscx_xad1)
end_define

begin_define
define|#
directive|define
name|h_xad2
value|hscx_rw.hscx_w.hscx_xad2
end_define

begin_define
define|#
directive|define
name|H_XAD2
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_w.hscx_xad2)
end_define

begin_define
define|#
directive|define
name|h_rah1
value|hscx_rw.hscx_w.hscx_rah1
end_define

begin_define
define|#
directive|define
name|H_RAH1
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_w.hscx_rah1)
end_define

begin_define
define|#
directive|define
name|h_rah2
value|hscx_rw.hscx_w.hscx_rah2
end_define

begin_define
define|#
directive|define
name|H_RAH2
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_w.hscx_rah2)
end_define

begin_define
define|#
directive|define
name|h_ral2
value|hscx_rw.hscx_w.hscx_ral2
end_define

begin_define
define|#
directive|define
name|H_RAL2
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_w.hscx_ral2)
end_define

begin_define
define|#
directive|define
name|h_xbcl
value|hscx_rw.hscx_w.hscx_xbcl
end_define

begin_define
define|#
directive|define
name|H_XBCL
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_w.hscx_xbcl)
end_define

begin_define
define|#
directive|define
name|h_bgr
value|hscx_rw.hscx_w.hscx_bgr
end_define

begin_define
define|#
directive|define
name|H_BGR
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_w.hscx_bgr)
end_define

begin_define
define|#
directive|define
name|h_xbch
value|hscx_rw.hscx_w.hscx_xbch
end_define

begin_define
define|#
directive|define
name|H_XBCH
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_w.hscx_xbch)
end_define

begin_define
define|#
directive|define
name|h_rlcr
value|hscx_rw.hscx_w.hscx_rlcr
end_define

begin_define
define|#
directive|define
name|H_RLCR
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_w.hscx_rlcr)
end_define

begin_define
define|#
directive|define
name|h_ccr1
value|hscx_rw.hscx_w.hscx_ccr1
end_define

begin_define
define|#
directive|define
name|H_CCR1
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_w.hscx_ccr1)
end_define

begin_define
define|#
directive|define
name|h_tsax
value|hscx_rw.hscx_w.hscx_tsax
end_define

begin_define
define|#
directive|define
name|H_TSAX
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_w.hscx_tsax)
end_define

begin_define
define|#
directive|define
name|h_tsar
value|hscx_rw.hscx_w.hscx_tsar
end_define

begin_define
define|#
directive|define
name|H_TSAR
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_w.hscx_tsar)
end_define

begin_define
define|#
directive|define
name|h_xccr
value|hscx_rw.hscx_w.hscx_xccr
end_define

begin_define
define|#
directive|define
name|H_XCCR
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_w.hscx_xccr)
end_define

begin_define
define|#
directive|define
name|h_rccr
value|hscx_rw.hscx_w.hscx_rccr
end_define

begin_define
define|#
directive|define
name|H_RCCR
value|REG_OFFSET(hscx_reg_t, hscx_rw.hscx_w.hscx_rccr)
end_define

begin_define
define|#
directive|define
name|HSCX_ISTA_RME
value|0x80
end_define

begin_define
define|#
directive|define
name|HSCX_ISTA_RPF
value|0x40
end_define

begin_define
define|#
directive|define
name|HSCX_ISTA_RSC
value|0x20
end_define

begin_define
define|#
directive|define
name|HSCX_ISTA_XPR
value|0x10
end_define

begin_define
define|#
directive|define
name|HSCX_ISTA_TIN
value|0x08
end_define

begin_define
define|#
directive|define
name|HSCX_ISTA_ICA
value|0x04
end_define

begin_define
define|#
directive|define
name|HSCX_ISTA_EXA
value|0x02
end_define

begin_define
define|#
directive|define
name|HSCX_ISTA_EXB
value|0x01
end_define

begin_define
define|#
directive|define
name|HSCX_MASK_RME
value|0x80
end_define

begin_define
define|#
directive|define
name|HSCX_MASK_RPF
value|0x40
end_define

begin_define
define|#
directive|define
name|HSCX_MASK_RSC
value|0x20
end_define

begin_define
define|#
directive|define
name|HSCX_MASK_XPR
value|0x10
end_define

begin_define
define|#
directive|define
name|HSCX_MASK_TIN
value|0x08
end_define

begin_define
define|#
directive|define
name|HSCX_MASK_ICA
value|0x04
end_define

begin_define
define|#
directive|define
name|HSCX_MASK_EXA
value|0x02
end_define

begin_define
define|#
directive|define
name|HSCX_MASK_EXB
value|0x01
end_define

begin_define
define|#
directive|define
name|HSCX_EXIR_XMR
value|0x80
end_define

begin_define
define|#
directive|define
name|HSCX_EXIR_XDU
value|0x40
end_define

begin_define
define|#
directive|define
name|HSCX_EXIR_PCE
value|0x20
end_define

begin_define
define|#
directive|define
name|HSCX_EXIR_RFO
value|0x10
end_define

begin_define
define|#
directive|define
name|HSCX_EXIR_CSC
value|0x08
end_define

begin_define
define|#
directive|define
name|HSCX_EXIR_RFS
value|0x04
end_define

begin_comment
comment|/* the other bits are always 0 */
end_comment

begin_define
define|#
directive|define
name|HSCX_STAR_XDOV
value|0x80
end_define

begin_define
define|#
directive|define
name|HSCX_STAR_XFW
value|0x40
end_define

begin_define
define|#
directive|define
name|HSCX_STAR_XRNR
value|0x20
end_define

begin_define
define|#
directive|define
name|HSCX_STAR_RRNR
value|0x10
end_define

begin_define
define|#
directive|define
name|HSCX_STAR_RLI
value|0x08
end_define

begin_define
define|#
directive|define
name|HSCX_STAR_CEC
value|0x04
end_define

begin_define
define|#
directive|define
name|HSCX_STAR_CTS
value|0x02
end_define

begin_define
define|#
directive|define
name|HSCX_STAR_WFA
value|0x01
end_define

begin_define
define|#
directive|define
name|HSCX_CMDR_RMC
value|0x80
end_define

begin_define
define|#
directive|define
name|HSCX_CMDR_RHR
value|0x40
end_define

begin_comment
comment|/* also known as XREP in transparent mode */
end_comment

begin_define
define|#
directive|define
name|HSCX_CMDR_RNR
value|0x20
end_define

begin_define
define|#
directive|define
name|HSCX_CMDR_STI
value|0x10
end_define

begin_define
define|#
directive|define
name|HSCX_CMDR_XTF
value|0x08
end_define

begin_define
define|#
directive|define
name|HSCX_CMDR_XIF
value|0x04
end_define

begin_define
define|#
directive|define
name|HSCX_CMDR_XME
value|0x02
end_define

begin_define
define|#
directive|define
name|HSCX_CMDR_XRES
value|0x01
end_define

begin_define
define|#
directive|define
name|HSCX_MODE_MDS1
value|0x80
end_define

begin_define
define|#
directive|define
name|HSCX_MODE_MDS0
value|0x40
end_define

begin_define
define|#
directive|define
name|HSCX_MODE_ADM
value|0x20
end_define

begin_define
define|#
directive|define
name|HSCX_MODE_TMD
value|0x10
end_define

begin_define
define|#
directive|define
name|HSCX_MODE_RAC
value|0x08
end_define

begin_define
define|#
directive|define
name|HSCX_MODE_RTS
value|0x04
end_define

begin_define
define|#
directive|define
name|HSCX_MODE_TRS
value|0x02
end_define

begin_define
define|#
directive|define
name|HSCX_MODE_TLP
value|0x01
end_define

begin_define
define|#
directive|define
name|HSCX_RSTA_VFR
value|0x80
end_define

begin_define
define|#
directive|define
name|HSCX_RSTA_RDO
value|0x40
end_define

begin_define
define|#
directive|define
name|HSCX_RSTA_CRC
value|0x20
end_define

begin_define
define|#
directive|define
name|HSCX_RSTA_RAB
value|0x10
end_define

begin_define
define|#
directive|define
name|HSCX_RSTA_HA1
value|0x08
end_define

begin_define
define|#
directive|define
name|HSCX_RSTA_HA0
value|0x04
end_define

begin_define
define|#
directive|define
name|HSCX_RSTA_CR
value|0x02
end_define

begin_define
define|#
directive|define
name|HSCX_RSTA_LA
value|0x01
end_define

begin_define
define|#
directive|define
name|HSCX_RSTA_MASK
value|0xf0
end_define

begin_comment
comment|/* the interesting ones */
end_comment

begin_comment
comment|/* only used in DMA mode */
end_comment

begin_define
define|#
directive|define
name|HSCX_XBCH_DMA
value|0x80
end_define

begin_define
define|#
directive|define
name|HSCX_XBCH_NRM
value|0x40
end_define

begin_define
define|#
directive|define
name|HSCX_XBCH_CAS
value|0x20
end_define

begin_define
define|#
directive|define
name|HSCX_XBCH_XC
value|0x10
end_define

begin_comment
comment|/* the rest are bits 11 thru 8 of the byte count */
end_comment

begin_define
define|#
directive|define
name|HSCX_RBCH_DMA
value|0x80
end_define

begin_define
define|#
directive|define
name|HSCX_RBCH_NRM
value|0x40
end_define

begin_define
define|#
directive|define
name|HSCX_RBCH_CAS
value|0x20
end_define

begin_define
define|#
directive|define
name|HSCX_RBCH_OV
value|0x10
end_define

begin_comment
comment|/* the rest are bits 11 thru 8 of the byte count */
end_comment

begin_define
define|#
directive|define
name|HSCX_VSTR_CD
value|0x80
end_define

begin_comment
comment|/* bits 6 thru 4 are 0 */
end_comment

begin_comment
comment|/* bits 3 thru 0 are the version number */
end_comment

begin_define
define|#
directive|define
name|HSCX_RLCR_RC
value|0x80
end_define

begin_comment
comment|/* the rest of the bits are used to set the received length */
end_comment

begin_define
define|#
directive|define
name|HSCX_CCR1_PU
value|0x80
end_define

begin_comment
comment|/* bits 6 and 5 are SC1 SC0 */
end_comment

begin_define
define|#
directive|define
name|HSCX_CCR1_ODS
value|0x10
end_define

begin_define
define|#
directive|define
name|HSCX_CCR1_ITF
value|0x08
end_define

begin_define
define|#
directive|define
name|HSCX_CCR1_CM2
value|0x04
end_define

begin_define
define|#
directive|define
name|HSCX_CCR1_CM1
value|0x02
end_define

begin_define
define|#
directive|define
name|HSCX_CCR1_CM0
value|0x01
end_define

begin_comment
comment|/* for clock mode 5 */
end_comment

begin_define
define|#
directive|define
name|HSCX_CCR2_SOC2
value|0x80
end_define

begin_define
define|#
directive|define
name|HSCX_CCR2_SOC1
value|0x40
end_define

begin_define
define|#
directive|define
name|HSCX_CCR2_XCS0
value|0x20
end_define

begin_define
define|#
directive|define
name|HSCX_CCR2_RCS0
value|0x10
end_define

begin_define
define|#
directive|define
name|HSCX_CCR2_TIO
value|0x08
end_define

begin_define
define|#
directive|define
name|HSCX_CCR2_CIE
value|0x04
end_define

begin_define
define|#
directive|define
name|HSCX_CCR2_RIE
value|0x02
end_define

begin_define
define|#
directive|define
name|HSCX_CCR2_DIV
value|0x01
end_define

begin_comment
comment|/* bits 7 thru 2 are TSNX */
end_comment

begin_define
define|#
directive|define
name|HSCX_TSAX_XCS2
value|0x02
end_define

begin_define
define|#
directive|define
name|HSCX_TSAX_XCS1
value|0x01
end_define

begin_comment
comment|/* bits 7 thru 2 are TSNR */
end_comment

begin_define
define|#
directive|define
name|HSCX_TSAR_RCS2
value|0x02
end_define

begin_define
define|#
directive|define
name|HSCX_TSAR_RCS1
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I4B_HSCX_H_ */
end_comment

end_unit

