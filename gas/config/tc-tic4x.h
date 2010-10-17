begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-tic4x.h -- Assemble for the Texas TMS320C[34]X.    Copyright (C) 1997, 2002, 2003 Free Software Foundation.        Contributed by Michael P. Hayes (m.hayes@elec.canterbury.ac.nz)     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_TIC4X
end_define

begin_define
define|#
directive|define
name|TIC4X
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_error
error|#
directive|error
error|TMS320C4x requires BFD_ASSEMBLER
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_tic4x
end_define

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_comment
comment|/* There are a number of different formats used for local labels.  gas    expects local labels either of the form `10$:' or `n:', where n is    a single digit.  When LOCAL_LABEL_DOLLARS is defined labels of the    form `10$:' are expected.  When LOCAL_LABEL_FB is defined labels of    the form `n:' are expected.  The latter are expected to be referred    to using `nf' for a forward reference of `nb' for a backward    reference.     The local labels expected by the TI tools are of the form `$n:',    where the colon is optional.  Now the $ character is considered to    be valid symbol name character, so gas doesn't recognise our local    symbols by default.  Defining LEX_DOLLAR to be 1 means that gas    won't allow labels starting with $ and thus the hook    tc_unrecognized_line() will be called from read.c.  We can thus    parse lines starting with $n as having local labels.     The other problem is the forward reference of local labels.  If a    symbol is undefined, symbol_make() calls the md_undefined_symbol()    hook where we create a local label if recognised.  */
end_comment

begin_comment
comment|/* Don't stick labels starting with 'L' into symbol table of COFF file. */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABEL
parameter_list|(
name|name
parameter_list|)
value|((name)[0] == '$' || (name)[0] == 'L')
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|OCTETS_PER_BYTE_POWER
value|2
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_tic4x
end_define

begin_define
define|#
directive|define
name|BFD_ARCH
value|TARGET_ARCH
end_define

begin_define
define|#
directive|define
name|TC_COUNT_RELOC
parameter_list|(
name|x
parameter_list|)
value|(x->fx_addsy)
end_define

begin_define
define|#
directive|define
name|TC_CONS_RELOC
value|RELOC_32
end_define

begin_define
define|#
directive|define
name|TC_COFF_FIX2RTYPE
parameter_list|(
name|fixP
parameter_list|)
value|tc_coff_fix2rtype (fixP)
end_define

begin_define
define|#
directive|define
name|TC_COFF_SIZEMACHDEP
parameter_list|(
name|frag
parameter_list|)
value|tc_coff_sizemachdep (frag)
end_define

begin_define
define|#
directive|define
name|NEED_FX_R_TYPE
end_define

begin_define
define|#
directive|define
name|NOP_OPCODE
value|0x0c800000
end_define

begin_define
define|#
directive|define
name|reloc_type
value|int
end_define

begin_define
define|#
directive|define
name|NO_RELOC
value|0
end_define

begin_comment
comment|/* '||' denotes parallel instruction */
end_comment

begin_define
define|#
directive|define
name|DOUBLEBAR_PARALLEL
value|1
end_define

begin_comment
comment|/* Labels are not required to have a colon for a suffix.  */
end_comment

begin_define
define|#
directive|define
name|LABELS_WITHOUT_COLONS
value|1
end_define

begin_comment
comment|/* Use $ as the section program counter (SPC). */
end_comment

begin_define
define|#
directive|define
name|DOLLAR_DOT
end_define

begin_comment
comment|/* Accept numbers with a suffix, e.g. 0ffffh, 1010b.  */
end_comment

begin_define
define|#
directive|define
name|NUMBERS_WITH_SUFFIX
value|1
end_define

begin_decl_stmt
specifier|extern
name|int
name|tic4x_unrecognized_line
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_unrecognized_line
parameter_list|(
name|c
parameter_list|)
value|tic4x_unrecognized_line (c)
end_define

begin_define
define|#
directive|define
name|md_number_to_chars
value|number_to_chars_littleendian
end_define

begin_decl_stmt
specifier|extern
name|int
name|tic4x_do_align
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_do_align
parameter_list|(
name|n
parameter_list|,
name|fill
parameter_list|,
name|len
parameter_list|,
name|max
parameter_list|,
name|label
parameter_list|)
value|if( tic4x_do_align (n,fill,len,max) ) goto label;
end_define

begin_comment
comment|/* Start of line hook to remove parallel instruction operator || */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|tic4x_start_line
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
name|md_start_line_hook
parameter_list|()
value|tic4x_start_line()
end_define

begin_decl_stmt
specifier|extern
name|void
name|tic4x_cleanup
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
name|md_cleanup
parameter_list|()
value|tic4x_cleanup()
end_define

begin_decl_stmt
specifier|extern
name|void
name|tic4x_end
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
value|tic4x_end()
end_define

end_unit

