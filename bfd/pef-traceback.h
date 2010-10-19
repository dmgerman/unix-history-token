begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* PowerPC traceback table support for BFD.    Copyright 1993, 1998, 1999, 2000, 2001, 2002, 2005    Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software     Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Originally written by Ira Ruben, 06/28/93 */
end_comment

begin_comment
comment|/*  This is a compiler independent representation of the AIX Version 3 traceback table (in     sys/debug.h), which occurs, usually, one per procedure (routine). The table is marked by     a multiple of 4 32-bit word of zeroes in the instruction space. The traceback table is     also referred to as "procedure-end table".       The AIX traceback table representation on which this header is based is defined as a     series of bit field struct specifications. Bit fields are compiler dependent! Thus,     the definitions presented here follow the original header and the existing documentation     (such as it is), but define the fields as BIT MASKS and other macros. The mask names,     however, where chosen as the original field names to give some compatibility with the      original header and to agree with the documentation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TRACEBACK__
end_ifndef

begin_define
define|#
directive|define
name|__TRACEBACK__
end_define

begin_define
define|#
directive|define
name|TB_C
value|0U
end_define

begin_comment
comment|/* C */
end_comment

begin_define
define|#
directive|define
name|TB_FORTRAN
value|1U
end_define

begin_comment
comment|/* FORTRAN */
end_comment

begin_define
define|#
directive|define
name|TB_PASCAL
value|2U
end_define

begin_comment
comment|/* Pascal */
end_comment

begin_define
define|#
directive|define
name|TB_ADA
value|3U
end_define

begin_comment
comment|/* ADA */
end_comment

begin_define
define|#
directive|define
name|TB_PL1
value|4U
end_define

begin_comment
comment|/* PL1 */
end_comment

begin_define
define|#
directive|define
name|TB_BASIC
value|5U
end_define

begin_comment
comment|/* Basic */
end_comment

begin_define
define|#
directive|define
name|TB_LISP
value|6U
end_define

begin_comment
comment|/* Lisp */
end_comment

begin_define
define|#
directive|define
name|TB_COBOL
value|7U
end_define

begin_comment
comment|/* eCobol */
end_comment

begin_define
define|#
directive|define
name|TB_MODULA2
value|8U
end_define

begin_comment
comment|/* Modula2 */
end_comment

begin_define
define|#
directive|define
name|TB_CPLUSPLUS
value|9U
end_define

begin_comment
comment|/* C++ */
end_comment

begin_define
define|#
directive|define
name|TB_RPG
value|10U
end_define

begin_comment
comment|/* RPG */
end_comment

begin_define
define|#
directive|define
name|TB_PL8
value|11U
end_define

begin_comment
comment|/* PL8 */
end_comment

begin_define
define|#
directive|define
name|TB_ASM
value|12U
end_define

begin_comment
comment|/* Asm */
end_comment

begin_comment
comment|/* Flags 1.  */
end_comment

begin_define
define|#
directive|define
name|TB_GLOBALLINK
value|0x80U
end_define

begin_comment
comment|/* Routine is Global Linkage.  */
end_comment

begin_define
define|#
directive|define
name|TB_is_eprol
value|0x40U
end_define

begin_comment
comment|/* Out-of-line prolog or epilog routine.  */
end_comment

begin_define
define|#
directive|define
name|TB_HAS_TBOFF
value|0x20U
end_define

begin_comment
comment|/* tb_offset set (extension field).  */
end_comment

begin_define
define|#
directive|define
name|TB_INT_PROC
value|0x10U
end_define

begin_comment
comment|/* Internal leaf routine.  */
end_comment

begin_define
define|#
directive|define
name|TB_HAS_CTL
value|0x08U
end_define

begin_comment
comment|/* Has controlled automatic storage.  */
end_comment

begin_define
define|#
directive|define
name|TB_TOCLESS
value|0X04U
end_define

begin_comment
comment|/* Routine has no TOC.  */
end_comment

begin_define
define|#
directive|define
name|TB_FP_PRESENT
value|0x02U
end_define

begin_comment
comment|/* Routine has floating point ops.  */
end_comment

begin_define
define|#
directive|define
name|TB_LOG_ABORT
value|0x01U
end_define

begin_comment
comment|/* fp_present&& log/abort compiler opt.  */
end_comment

begin_comment
comment|/* Flags 2.  */
end_comment

begin_define
define|#
directive|define
name|TB_INT_HNDL
value|0x80U
end_define

begin_comment
comment|/* Routine is an interrupt handler.  */
end_comment

begin_define
define|#
directive|define
name|TB_NAME_PRESENT
value|0x40U
end_define

begin_comment
comment|/* Name_len/name set (extension field).  */
end_comment

begin_define
define|#
directive|define
name|TB_USES_ALLOCA
value|0x20U
end_define

begin_comment
comment|/* Uses alloca() to allocate storage.  */
end_comment

begin_define
define|#
directive|define
name|TB_CL_DIS_inv
value|0x1CU
end_define

begin_comment
comment|/* On-condition directives (see below).  */
end_comment

begin_define
define|#
directive|define
name|TB_SAVES_CR
value|0x02U
end_define

begin_comment
comment|/* Routine saves the CR.  */
end_comment

begin_define
define|#
directive|define
name|TB_SAVES_LR
value|0x01U
end_define

begin_comment
comment|/* Routine saves the LR.  */
end_comment

begin_comment
comment|/* cl_dis_inv "on condition" settings:  */
end_comment

begin_define
define|#
directive|define
name|TB_CL_DIS_INV
parameter_list|(
name|x
parameter_list|)
value|(((x)& cl_dis_inv)>> 2U)
end_define

begin_define
define|#
directive|define
name|TB_WALK_ONCOND
value|0U
end_define

begin_comment
comment|/* Walk stack without restoring state.  */
end_comment

begin_define
define|#
directive|define
name|TB_DISCARD_ONCOND
value|1U
end_define

begin_comment
comment|/* Walk stack and discard.  */
end_comment

begin_define
define|#
directive|define
name|TB_INVOKE_ONCOND
value|2U
end_define

begin_comment
comment|/* Invoke a specific system routine.  */
end_comment

begin_comment
comment|/* Flags 3.  */
end_comment

begin_define
define|#
directive|define
name|TB_STORES_BC
value|0x80U
end_define

begin_comment
comment|/* Routine saves frame ptr of caller.  */
end_comment

begin_define
define|#
directive|define
name|TB_SPARE2
value|0X40U
end_define

begin_comment
comment|/* Spare bit.  */
end_comment

begin_define
define|#
directive|define
name|TB_FPR_SAVED
value|0x3fU
end_define

begin_comment
comment|/* Number of FPRs saved (max of 32).  */
end_comment

begin_comment
comment|/* (Last reg saved is ALWAYS fpr31).  */
end_comment

begin_define
define|#
directive|define
name|TB_NUM_FPR_SAVED
parameter_list|(
name|x
parameter_list|)
value|((x)& fpr_saved)
end_define

begin_comment
comment|/* Flags 4.  */
end_comment

begin_define
define|#
directive|define
name|TB_HAS_VEC_INFO
value|0x80U
end_define

begin_comment
comment|/* Routine uses vectors.  */
end_comment

begin_define
define|#
directive|define
name|TB_SPARE3
value|0X40U
end_define

begin_comment
comment|/* Spare bit.  */
end_comment

begin_define
define|#
directive|define
name|TB_GPR_SAVED
value|0x3fU
end_define

begin_comment
comment|/* Number of GPRs saved (max of 32).  */
end_comment

begin_comment
comment|/* (Last reg saved is ALWAYS gpr31).  */
end_comment

begin_define
define|#
directive|define
name|TB_NUM_GPR_SAVED
parameter_list|(
name|x
parameter_list|)
value|((x)& gpr_saved)
end_define

begin_comment
comment|/* Flags 5.  */
end_comment

begin_define
define|#
directive|define
name|TB_FLOATPARAMS
value|0xfeU
end_define

begin_comment
comment|/* Number of floating point parameters.  */
end_comment

begin_define
define|#
directive|define
name|TB_PARAMSONSTK
value|0X01U
end_define

begin_comment
comment|/* All parameters are on the stack.  */
end_comment

begin_define
define|#
directive|define
name|TB_NUM_FLOATPARAMS
parameter_list|(
name|X
parameter_list|)
value|(((x)& floatparams)>> 1U)
end_define

begin_comment
comment|/* Traceback_table (fixed portion).  */
end_comment

begin_struct
struct|struct
name|traceback_table
block|{
comment|/* Traceback table layout (fixed portion):  */
name|unsigned
name|char
name|version
decl_stmt|;
comment|/* Traceback format version.  */
name|unsigned
name|char
name|lang
decl_stmt|;
comment|/* Language indicators:  */
name|unsigned
name|char
name|flags1
decl_stmt|;
comment|/* Flag bits #1:  */
name|unsigned
name|char
name|flags2
decl_stmt|;
comment|/* Flag bits #2:  */
name|unsigned
name|char
name|flags3
decl_stmt|;
comment|/* Flag bits #3:  */
name|unsigned
name|char
name|flags4
decl_stmt|;
comment|/* Flag bits #4:  */
name|unsigned
name|char
name|fixedparams
decl_stmt|;
comment|/* Number of fixed point parameters.  */
name|unsigned
name|char
name|flags5
decl_stmt|;
comment|/* Flag bits #5:  */
block|}
struct|;
end_struct

begin_comment
comment|/* traceback_table (optional) extensions.  */
end_comment

begin_comment
comment|/* Optional portions exist independently in the order presented below,    not as a structure or a union. Whether or not portions exist is    determinable from bit-fields within the fixed portion above.  */
end_comment

begin_comment
comment|/* The following is present only if fixedparams or floatparams are non    zero and it immediately follows the fixed portion of the traceback    table...  */
end_comment

begin_comment
comment|/* Order and type encoding of parameters:  */
end_comment

begin_struct
struct|struct
name|traceback_table_fixedparams
block|{
name|unsigned
name|long
name|paraminfo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Left-justified bit-encoding as follows:  */
end_comment

begin_define
define|#
directive|define
name|FIXED_PARAM
value|0
end_define

begin_comment
comment|/* '0'  ==> fixed param (1 gpr or word).  */
end_comment

begin_define
define|#
directive|define
name|SPFP_PARAM
value|2
end_define

begin_comment
comment|/* '10' ==> single-precision float param.  */
end_comment

begin_define
define|#
directive|define
name|DPFP_PARAM
value|3
end_define

begin_comment
comment|/* '11' ==> double-precision float param.  */
end_comment

begin_define
define|#
directive|define
name|PARAM_ENCODING
parameter_list|(
name|x
parameter_list|,
name|bit
parameter_list|)
comment|/* Yields xxx_PARAM as a function of "bit".  */
define|\
value|((((x)&(1UL<<(31UL-(bit++))))==0UL)
comment|/* Values 0:31 (left-to-right). "bit" is */
value|\  ? FIXED_PARAM
comment|/* an L-value that's left incremented to */
value|\  : ((((x)&(1UL<<(31UL-(bit++))))==0)
comment|/* the next bit position for the next */
value|\  ? SPFP_PARAM
comment|/* parameter.  This will be 1 or 2 bit */
value|\  : DPFP_PARAM))
end_define

begin_comment
comment|/* positions later.  */
end_comment

begin_comment
comment|/* The following is present only if has_tboff (in flags1) in fixed part is present...  */
end_comment

begin_comment
comment|/* Offset from start of code to TracebackTbl.  */
end_comment

begin_struct
struct|struct
name|traceback_table_tboff
block|{
name|unsigned
name|long
name|tb_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The following is present only if int_hndl (in flags2) in fixed part is present ...  */
end_comment

begin_comment
comment|/* What interrupts are handled by the routine.  */
end_comment

begin_struct
struct|struct
name|traceback_table_interrupts
block|{
name|long
name|hand_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The following are present only if has_ctl (in flags1) in fixed part is present...  */
end_comment

begin_comment
comment|/* Controlled automatic storage info:  */
end_comment

begin_struct
struct|struct
name|traceback_table_anchors
block|{
name|unsigned
name|long
name|ctl_info
decl_stmt|;
comment|/* Number of controlled automatic anchors.  */
name|long
name|ctl_info_disp
index|[
literal|1
index|]
decl_stmt|;
comment|/* Array of stack displacements where each.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Anchor is located (array STARTS here).  */
end_comment

begin_comment
comment|/* The following are present only if name_present (in flags2) in fixed    part is present...  */
end_comment

begin_comment
comment|/* Routine name:  */
end_comment

begin_struct
struct|struct
name|traceback_table_routine
block|{
name|unsigned
name|short
name|name_len
decl_stmt|;
comment|/* Length of name that follows.  */
name|char
name|name
index|[
literal|1
index|]
decl_stmt|;
comment|/* Name starts here (NOT null terminated).  */
block|}
struct|;
end_struct

begin_comment
comment|/* The following are present only if uses_alloca (in flags2) in fixed    part is present...  */
end_comment

begin_comment
comment|/* Register auto storage when alloca() is used.  */
end_comment

begin_struct
struct|struct
name|traceback_table_alloca
block|{
name|char
name|alloca_reg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The following are present only if has_vec_info (in flags4) in fixed    part is present...  */
end_comment

begin_comment
comment|/* Vector info:  */
end_comment

begin_struct
struct|struct
name|traceback_table_vector
block|{
name|unsigned
name|char
name|vec_flags1
decl_stmt|;
comment|/* Vec info bits #1:  */
define|#
directive|define
name|TB_VR_SAVED
value|0xFCU
comment|/* Number of saved vector registers.  */
define|#
directive|define
name|TB_SAVES_VRSAVE
value|0x02U
comment|/* Saves VRsave.  */
define|#
directive|define
name|TB_HAS_VARARGS
value|0x01U
comment|/* Routine has a variable argument list.  */
define|#
directive|define
name|TB_NUM_VR_SAVED
parameter_list|(
name|x
parameter_list|)
value|(((x)& TB_VR_SAVED)>> 2U)
name|unsigned
name|char
name|vec_flags2
decl_stmt|;
comment|/* Vec info bits #2:  */
define|#
directive|define
name|TB_VECTORPARAMS
value|0xfeU
comment|/* Number of vector parameters.  */
define|#
directive|define
name|TB_VEC_PRESENT
value|0x01U
comment|/* Routine uses at least one vec instr.  */
define|#
directive|define
name|VECPARAMS
parameter_list|(
name|x
parameter_list|)
value|(((x)& TB_VECTORPARAMS)>> 1U)
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

