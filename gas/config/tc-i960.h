begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-i960.h - Basic 80960 instruction formats.    Copyright 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1997, 1998, 1999,    2000, 2002, 2003    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2,    or (at your option) any later version.     GAS is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See    the GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_I960
end_ifndef

begin_define
define|#
directive|define
name|TC_I960
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-i960"
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_i960
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_comment
comment|/*  * The 'COJ' instructions are actually COBR instructions with the 'b' in  * the mnemonic replaced by a 'j';  they are ALWAYS "de-optimized" if necessary:  * if the displacement will not fit in 13 bits, the assembler will replace them  * with the corresponding compare and branch instructions.  *  * All of the 'MEMn' instructions are the same format; the 'n' in the name  * indicates the default index scale factor (the size of the datum operated on).  *  * The FBRA formats are not actually an instruction format.  They are the  * "convenience directives" for branching on floating-point comparisons,  * each of which generates 2 instructions (a 'bno' and one other branch).  *  * The CALLJ format is not actually an instruction format.  It indicates that  * the instruction generated (a CTRL-format 'call') should have its relocation  * specially flagged for link-time replacement with a 'bal' or 'calls' if  * appropriate.  */
end_comment

begin_comment
comment|/* tailor gas */
end_comment

begin_define
define|#
directive|define
name|SYMBOLS_NEED_BACKPOINTERS
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_define
define|#
directive|define
name|BITFIELD_CONS_EXPRESSIONS
end_define

begin_comment
comment|/* tailor the coff format */
end_comment

begin_define
define|#
directive|define
name|BFD_ARCH
value|bfd_arch_i960
end_define

begin_define
define|#
directive|define
name|COFF_FLAGS
value|F_AR32WR
end_define

begin_define
define|#
directive|define
name|COFF_MAGIC
value|I960ROMAGIC
end_define

begin_define
define|#
directive|define
name|OBJ_COFF_SECTION_HEADER_HAS_ALIGNMENT
end_define

begin_define
define|#
directive|define
name|OBJ_COFF_MAX_AUXENTRIES
value|(2)
end_define

begin_define
define|#
directive|define
name|TC_COUNT_RELOC
parameter_list|(
name|FIX
parameter_list|)
value|(!(FIX)->fx_done)
end_define

begin_define
define|#
directive|define
name|TC_COFF_FIX2RTYPE
parameter_list|(
name|FIX
parameter_list|)
value|tc_coff_fix2rtype (FIX)
end_define

begin_define
define|#
directive|define
name|TC_COFF_SIZEMACHDEP
parameter_list|(
name|FRAGP
parameter_list|)
value|tc_coff_sizemachdep (FRAGP)
end_define

begin_define
define|#
directive|define
name|TC_COFF_SET_MACHINE
parameter_list|(
name|HDRS
parameter_list|)
value|tc_headers_hook (HDRS)
end_define

begin_decl_stmt
specifier|extern
name|int
name|tc_coff_sizemachdep
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frag
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MEANING OF 'n_other' in the symbol record.  *  * If non-zero, the 'n_other' fields indicates either a leaf procedure or  * a system procedure, as follows:  *  *	1<= n_other<= 32 :  *		The symbol is the entry point to a system procedure.  *		'n_value' is the address of the entry, as for any other  *		procedure.  The system procedure number (which can be used in  *		a 'calls' instruction) is (n_other-1).  These entries come from  *		'.sysproc' directives.  *  *	n_other == N_CALLNAME  *		the symbol is the 'call' entry point to a leaf procedure.  *		The *next* symbol in the symbol table must be the corresponding  *		'bal' entry point to the procedure (see following).  These  *		entries come from '.leafproc' directives in which two different  *		symbols are specified (the first one is represented here).  *  *  *	n_other == N_BALNAME  *		the symbol is the 'bal' entry point to a leaf procedure.  *		These entries result from '.leafproc' directives in which only  *		one symbol is specified, or in which the same symbol is  *		specified twice.  *  * Note that an N_CALLNAME entry *must* have a corresponding N_BALNAME entry,  * but not every N_BALNAME entry must have an N_CALLNAME entry.  */
end_comment

begin_define
define|#
directive|define
name|N_CALLNAME
value|((char)-1)
end_define

begin_define
define|#
directive|define
name|N_BALNAME
value|((char)-2)
end_define

begin_comment
comment|/* i960 uses a custom relocation record.  */
end_comment

begin_comment
comment|/* let obj-aout.h know */
end_comment

begin_define
define|#
directive|define
name|CUSTOM_RELOC_FORMAT
value|1
end_define

begin_comment
comment|/* let aout_gnu.h know */
end_comment

begin_define
define|#
directive|define
name|N_RELOCATION_INFO_DECLARED
value|1
end_define

begin_struct
struct|struct
name|relocation_info
block|{
name|int
name|r_address
decl_stmt|;
comment|/* File address of item to be relocated	*/
name|unsigned
name|r_index
range|:
literal|24
decl_stmt|,
comment|/* Index of symbol on which relocation is based*/
name|r_pcrel
range|:
literal|1
decl_stmt|,
comment|/* 1 => relocate PC-relative; else absolute 				 *	On i960, pc-relative implies 24-bit 				 *	address, absolute implies 32-bit. 				 */
name|r_length
range|:
literal|2
decl_stmt|,
comment|/* Number of bytes to relocate: 				 *	0 => 1 byte 				 *	1 => 2 bytes 				 *	2 => 4 bytes -- only value used for i960 				 */
name|r_extern
range|:
literal|1
decl_stmt|,
name|r_bsr
range|:
literal|1
decl_stmt|,
comment|/* Something for the GNU NS32K assembler */
name|r_disp
range|:
literal|1
decl_stmt|,
comment|/* Something for the GNU NS32K assembler */
name|r_callj
range|:
literal|1
decl_stmt|,
comment|/* 1 if relocation target is an i960 'callj' */
name|nuthin
range|:
literal|1
decl_stmt|;
comment|/* Unused				*/
block|}
struct|;
end_struct

begin_comment
comment|/* No shared lib support, so we don't need to ensure externally    visible symbols can be overridden.  */
end_comment

begin_define
define|#
directive|define
name|EXTERN_FORCE_RELOC
value|0
end_define

begin_comment
comment|/* Makes no sense to use the difference of 2 arbitrary symbols    as the target of a call instruction.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION_SUB_SAME
parameter_list|(
name|FIX
parameter_list|,
name|SEG
parameter_list|)
define|\
value|((FIX)->fx_tcbit				\    || ! SEG_NORMAL (SEG)			\    || TC_FORCE_RELOCATION (FIX))
end_define

begin_comment
comment|/* reloc_callj() may replace a 'call' with a 'calls' or a    'bal', in which cases it modifies *fixP as appropriate.    In the case of a 'calls', no further work is required.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|reloc_callj
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION_ABS
parameter_list|(
name|FIX
parameter_list|)
define|\
value|(TC_FORCE_RELOCATION (FIX)			\    || reloc_callj (FIX))
end_define

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION_LOCAL
parameter_list|(
name|FIX
parameter_list|)
define|\
value|(!(FIX)->fx_pcrel				\    || (FIX)->fx_plt				\    || TC_FORCE_RELOCATION (FIX)		\    || reloc_callj (FIX))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_COFF
end_ifdef

begin_comment
comment|/* We store the bal information in the sy_tc field.  */
end_comment

begin_define
define|#
directive|define
name|TC_SYMFIELD_TYPE
value|symbolS *
end_define

begin_define
define|#
directive|define
name|TC_ADJUST_RELOC_COUNT
parameter_list|(
name|FIX
parameter_list|,
name|COUNT
parameter_list|)
define|\
value|{ fixS *tcfixp = (FIX); \     for (;tcfixp;tcfixp=tcfixp->fx_next) \       if (tcfixp->fx_tcbit&& tcfixp->fx_addsy != 0) \ 	++(COUNT); \   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|i960_validate_fix
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
operator|,
name|segT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_VALIDATE_FIX
parameter_list|(
name|FIX
parameter_list|,
name|SEGTYPE
parameter_list|,
name|LABEL
parameter_list|)
define|\
value|if (!i960_validate_fix (FIX, SEGTYPE)) goto LABEL
end_define

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|((FIX)->fx_bsr == 0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|OBJ_ELF
end_ifndef

begin_comment
comment|/* Values passed to md_apply_fix3 sometimes include symbol values.  */
end_comment

begin_define
define|#
directive|define
name|MD_APPLY_SYM_VALUE
parameter_list|(
name|FIX
parameter_list|)
value|tc_fix_adjustable (FIX)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Values passed to md_apply_fix3 don't include the symbol value.  */
end_comment

begin_define
define|#
directive|define
name|MD_APPLY_SYM_VALUE
parameter_list|(
name|FIX
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|brtab_emit
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_end
parameter_list|()
value|brtab_emit ()
end_define

begin_decl_stmt
specifier|extern
name|void
name|tc_set_bal_of_call
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|,
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symbol
modifier|*
name|tc_get_bal_of_call
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|i960_handle_align
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frag
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HANDLE_ALIGN
parameter_list|(
name|FRAG
parameter_list|)
value|i960_handle_align (FRAG)
end_define

begin_define
define|#
directive|define
name|NEED_FX_R_TYPE
end_define

begin_define
define|#
directive|define
name|NO_RELOC
value|-1
end_define

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|relax_type
name|md_relax_table
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_GENERIC_RELAX_TABLE
value|md_relax_table
end_define

begin_define
define|#
directive|define
name|LINKER_RELAXING_SHRINKS_ONLY
end_define

begin_define
define|#
directive|define
name|TC_FIX_TYPE
value|struct { unsigned bsr : 1; }
end_define

begin_define
define|#
directive|define
name|fx_bsr
value|tc_fix_data.bsr
end_define

begin_define
define|#
directive|define
name|TC_INIT_FIX_DATA
parameter_list|(
name|F
parameter_list|)
value|((F)->tc_fix_data.bsr = 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

