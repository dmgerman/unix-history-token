begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Device driver optimized for the Symbios/LSI 53C896/53C895A/53C1010   *  PCI-SCSI controllers.  *  *  Copyright (C) 1999-2000  Gerard Roudier<groudier@club-internet.fr>  *  *  This driver also supports the following Symbios/LSI PCI-SCSI chips:  *	53C810A, 53C825A, 53C860, 53C875, 53C876, 53C885, 53C895,  *	53C810,  53C815,  53C825 and the 53C1510D is 53C8XX mode.  *  *    *  This driver for FreeBSD-CAM is derived from the Linux sym53c8xx driver.  *  Copyright (C) 1998-1999  Gerard Roudier  *  *  The sym53c8xx driver is derived from the ncr53c8xx driver that had been   *  a port of the FreeBSD ncr driver to Linux-1.2.13.  *  *  The original ncr driver has been written for 386bsd and FreeBSD by  *          Wolfgang Stanglmeier<wolf@cologne.de>  *          Stefan Esser<se@mi.Uni-Koeln.de>  *  Copyright (C) 1994  Wolfgang Stanglmeier  *  *  The initialisation code, and part of the code that addresses   *  FreeBSD-CAM services is based on the aic7xxx driver for FreeBSD-CAM   *  written by Justin T. Gibbs.  *  *  Other major contributions:  *  *  NVRAM detection and reading.  *  Copyright (C) 1997 Richard Waltham<dormouse@farsrobt.demon.co.uk>  *  *-----------------------------------------------------------------------------  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYM_FW_H
end_ifndef

begin_define
define|#
directive|define
name|SYM_FW_H
end_define

begin_comment
comment|/*  *  Macro used to generate interfaces for script A.  */
end_comment

begin_define
define|#
directive|define
name|SYM_GEN_FW_A
parameter_list|(
name|s
parameter_list|)
define|\
value|SYM_GEN_A(s, start)		SYM_GEN_A(s, getjob_begin)	\ 	SYM_GEN_A(s, getjob_end)					\ 	SYM_GEN_A(s, select)		SYM_GEN_A(s, wf_sel_done)	\ 	SYM_GEN_A(s, send_ident)					\ 	SYM_GEN_A(s, dispatch)		SYM_GEN_A(s, init)		\ 	SYM_GEN_A(s, clrack)		SYM_GEN_A(s, complete_error)	\ 	SYM_GEN_A(s, done)		SYM_GEN_A(s, done_end)		\ 	SYM_GEN_A(s, idle)		SYM_GEN_A(s, ungetjob)		\ 	SYM_GEN_A(s, reselect)						\ 	SYM_GEN_A(s, resel_tag)		SYM_GEN_A(s, resel_dsa)		\ 	SYM_GEN_A(s, resel_no_tag)					\ 	SYM_GEN_A(s, data_in)		SYM_GEN_A(s, data_in2)		\ 	SYM_GEN_A(s, data_out)		SYM_GEN_A(s, data_out2)		\ 	SYM_GEN_A(s, pm0_data)		SYM_GEN_A(s, pm1_data)
end_define

begin_comment
comment|/*  *  Macro used to generate interfaces for script B.  */
end_comment

begin_define
define|#
directive|define
name|SYM_GEN_FW_B
parameter_list|(
name|s
parameter_list|)
define|\
value|SYM_GEN_B(s, no_data)						\ 	SYM_GEN_B(s, sel_for_abort)	SYM_GEN_B(s, sel_for_abort_1)	\ 	SYM_GEN_B(s, msg_bad)		SYM_GEN_B(s, msg_weird)		\ 	SYM_GEN_B(s, wdtr_resp)		SYM_GEN_B(s, send_wdtr)		\ 	SYM_GEN_B(s, sdtr_resp)		SYM_GEN_B(s, send_sdtr)		\ 	SYM_GEN_B(s, ppr_resp)		SYM_GEN_B(s, send_ppr)		\ 	SYM_GEN_B(s, nego_bad_phase)					\ 	SYM_GEN_B(s, ident_break) 	SYM_GEN_B(s, ident_break_atn)	\ 	SYM_GEN_B(s, sdata_in)		SYM_GEN_B(s, resel_bad_lun)	\ 	SYM_GEN_B(s, bad_i_t_l)		SYM_GEN_B(s, bad_i_t_l_q)	\ 	SYM_GEN_B(s, wsr_ma_helper)					\ 	SYM_GEN_B(s, snooptest)		SYM_GEN_B(s, snoopend)
end_define

begin_comment
comment|/*  *  Generates structure interface that contains   *  offsets within script A and script B.  */
end_comment

begin_define
define|#
directive|define
name|SYM_GEN_A
parameter_list|(
name|s
parameter_list|,
name|label
parameter_list|)
value|s label;
end_define

begin_define
define|#
directive|define
name|SYM_GEN_B
parameter_list|(
name|s
parameter_list|,
name|label
parameter_list|)
value|s label;
end_define

begin_struct
struct|struct
name|sym_fwa_ofs
block|{
name|SYM_GEN_FW_A
argument_list|(
argument|u_short
argument_list|)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sym_fwb_ofs
block|{
name|SYM_GEN_FW_B
argument_list|(
argument|u_short
argument_list|)
name|SYM_GEN_B
argument_list|(
name|u_short
argument_list|,
name|start64
argument_list|)
expr_stmt|;
name|SYM_GEN_B
argument_list|(
name|u_short
argument_list|,
name|pm_handle
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  Generates structure interface that contains   *  bus addresses within script A and script B.  */
end_comment

begin_struct
struct|struct
name|sym_fwa_ba
block|{
name|SYM_GEN_FW_A
argument_list|(
argument|u32
argument_list|)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sym_fwb_ba
block|{
name|SYM_GEN_FW_B
argument_list|(
argument|u32
argument_list|)
name|SYM_GEN_B
argument_list|(
name|u32
argument_list|,
name|start64
argument_list|)
expr_stmt|;
name|SYM_GEN_B
argument_list|(
name|u32
argument_list|,
name|pm_handle
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_undef
undef|#
directive|undef
name|SYM_GEN_A
end_undef

begin_undef
undef|#
directive|undef
name|SYM_GEN_B
end_undef

begin_comment
comment|/*  *  Let cc know about the name of the controller data structure.  *  We need this for function prototype declarations just below.  */
end_comment

begin_struct_decl
struct_decl|struct
name|sym_hcb
struct_decl|;
end_struct_decl

begin_comment
comment|/*  *  Generic structure that defines a firmware.  */
end_comment

begin_struct
struct|struct
name|sym_fw
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name we want to print out	*/
name|u32
modifier|*
name|a_base
decl_stmt|;
comment|/* Pointer to script A template	*/
name|int
name|a_size
decl_stmt|;
comment|/* Size of script A		*/
name|struct
name|sym_fwa_ofs
modifier|*
name|a_ofs
decl_stmt|;
comment|/* Useful offsets in script A	*/
name|u32
modifier|*
name|b_base
decl_stmt|;
comment|/* Pointer to script B template	*/
name|int
name|b_size
decl_stmt|;
comment|/* Size of script B		*/
name|struct
name|sym_fwb_ofs
modifier|*
name|b_ofs
decl_stmt|;
comment|/* Useful offsets in script B	*/
comment|/* Setup and patch methods for this firmware */
name|void
function_decl|(
modifier|*
name|setup
function_decl|)
parameter_list|(
name|struct
name|sym_hcb
modifier|*
parameter_list|,
name|struct
name|sym_fw
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|patch
function_decl|)
parameter_list|(
name|struct
name|sym_hcb
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  Macro used to declare a firmware.  */
end_comment

begin_define
define|#
directive|define
name|SYM_FW_ENTRY
parameter_list|(
name|fw
parameter_list|,
name|name
parameter_list|)
define|\
value|{								\ 	name,							\ 	(u32 *)&fw##a_scr, sizeof(fw##a_scr),&fw##a_ofs,	\ 	(u32 *)&fw##b_scr, sizeof(fw##b_scr),&fw##b_ofs,	\ 	fw##_setup, fw##_patch					\ }
end_define

begin_comment
comment|/*  *  Macros used from the C code to get useful  *  SCRIPTS bus addresses.  */
end_comment

begin_define
define|#
directive|define
name|SCRIPTA_BA
parameter_list|(
name|np
parameter_list|,
name|label
parameter_list|)
value|(np->fwa_bas.label)
end_define

begin_define
define|#
directive|define
name|SCRIPTB_BA
parameter_list|(
name|np
parameter_list|,
name|label
parameter_list|)
value|(np->fwb_bas.label)
end_define

begin_define
define|#
directive|define
name|SCRIPTB0_BA
parameter_list|(
name|np
parameter_list|,
name|label
parameter_list|)
define|\
value|(np->scriptb0_ba + (np->fwb_bas.label - np->scriptb_ba))
end_define

begin_comment
comment|/*  *  Macros used by scripts definitions.  *  *  HADDR_1 generates a reference to a field of the controller data.  *  HADDR_2 generates a reference to a field of the controller data  *          with offset.  *  RADDR_1 generates a reference to a script processor register.  *  RADDR_2 generates a reference to a script processor register  *          with offset.  *  PADDR_A generates a reference to another part of script A.  *  PADDR_B generates a reference to another part of script B.  *  *  SYM_GEN_PADDR_A and SYM_GEN_PADDR_B are used to define respectively   *  the PADDR_A and PADDR_B macros for each firmware by setting argument   *  `s' to the name of the corresponding structure.  *  *  SCR_DATA_ZERO is used to allocate a DWORD of data in scripts areas.  */
end_comment

begin_define
define|#
directive|define
name|RELOC_SOFTC
value|0x40000000
end_define

begin_define
define|#
directive|define
name|RELOC_LABEL_A
value|0x50000000
end_define

begin_define
define|#
directive|define
name|RELOC_REGISTER
value|0x60000000
end_define

begin_define
define|#
directive|define
name|RELOC_LABEL_B
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RELOC_MASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|HADDR_1
parameter_list|(
name|label
parameter_list|)
value|(RELOC_SOFTC    | offsetof(struct sym_hcb, label))
end_define

begin_define
define|#
directive|define
name|HADDR_2
parameter_list|(
name|label
parameter_list|,
name|ofs
parameter_list|)
value|(RELOC_SOFTC    | \ 				(offsetof(struct sym_hcb, label)+(ofs)))
end_define

begin_define
define|#
directive|define
name|RADDR_1
parameter_list|(
name|label
parameter_list|)
value|(RELOC_REGISTER | REG(label))
end_define

begin_define
define|#
directive|define
name|RADDR_2
parameter_list|(
name|label
parameter_list|,
name|ofs
parameter_list|)
value|(RELOC_REGISTER | ((REG(label))+(ofs)))
end_define

begin_define
define|#
directive|define
name|SYM_GEN_PADDR_A
parameter_list|(
name|s
parameter_list|,
name|label
parameter_list|)
value|(RELOC_LABEL_A  | offsetof(s, label))
end_define

begin_define
define|#
directive|define
name|SYM_GEN_PADDR_B
parameter_list|(
name|s
parameter_list|,
name|label
parameter_list|)
value|(RELOC_LABEL_B  | offsetof(s, label))
end_define

begin_define
define|#
directive|define
name|SCR_DATA_ZERO
value|0xf00ff00f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYM_FW_H */
end_comment

end_unit

