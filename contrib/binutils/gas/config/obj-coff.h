begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* coff object file format    Copyright 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000, 2002    Free Software Foundation, Inc.     This file is part of GAS.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OBJ_FORMAT_H
end_ifndef

begin_define
define|#
directive|define
name|OBJ_FORMAT_H
end_define

begin_define
define|#
directive|define
name|OBJ_COFF
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|WARN_SIGNED_OVERFLOW_WORD
end_define

begin_define
define|#
directive|define
name|OBJ_COFF_OMIT_OPTIONAL_HEADER
end_define

begin_define
define|#
directive|define
name|BFD_HEADERS
end_define

begin_define
define|#
directive|define
name|BFD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"targ-cpu.h"
end_include

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_comment
comment|/* This internal_lineno crap is to stop namespace pollution from the    bfd internal coff headerfile.  */
end_comment

begin_define
define|#
directive|define
name|internal_lineno
value|bfd_internal_lineno
end_define

begin_include
include|#
directive|include
file|"coff/internal.h"
end_include

begin_undef
undef|#
directive|undef
name|internal_lineno
end_undef

begin_comment
comment|/* CPU-specific setup:  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_ARM
end_ifdef

begin_include
include|#
directive|include
file|"coff/arm.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_FORMAT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-arm"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_PPC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TE_PE
end_ifdef

begin_include
include|#
directive|include
file|"coff/powerpc.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"coff/rs6000.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_SPARC
end_ifdef

begin_include
include|#
directive|include
file|"coff/sparc.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_I386
end_ifdef

begin_include
include|#
directive|include
file|"coff/i386.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TE_PE
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"pe-i386"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_FORMAT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-i386"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_M68K
end_ifdef

begin_include
include|#
directive|include
file|"coff/m68k.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_FORMAT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-m68k"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_A29K
end_ifdef

begin_include
include|#
directive|include
file|"coff/a29k.h"
end_include

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-a29k-big"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_OR32
end_ifdef

begin_include
include|#
directive|include
file|"coff/or32.h"
end_include

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-or32-big"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_I960
end_ifdef

begin_include
include|#
directive|include
file|"coff/i960.h"
end_include

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-Intel-little"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_Z8K
end_ifdef

begin_include
include|#
directive|include
file|"coff/z8k.h"
end_include

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-z8k"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_H8300
end_ifdef

begin_include
include|#
directive|include
file|"coff/h8300.h"
end_include

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-h8300"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_H8500
end_ifdef

begin_include
include|#
directive|include
file|"coff/h8500.h"
end_include

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-h8500"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_SH
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TE_PE
end_ifdef

begin_define
define|#
directive|define
name|COFF_WITH_PE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"coff/sh.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TE_PE
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"pe-shl"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_FORMAT
define|\
value|(!target_big_endian					\    ? (sh_small ? "coff-shl-small" : "coff-shl")		\    : (sh_small ? "coff-sh-small" : "coff-sh"))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_MIPS
end_ifdef

begin_define
define|#
directive|define
name|COFF_WITH_PE
end_define

begin_include
include|#
directive|include
file|"coff/mipspe.h"
end_include

begin_undef
undef|#
directive|undef
name|TARGET_FORMAT
end_undef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"pe-mips"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_M88K
end_ifdef

begin_include
include|#
directive|include
file|"coff/m88k.h"
end_include

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-m88kbcs"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_W65
end_ifdef

begin_include
include|#
directive|include
file|"coff/w65.h"
end_include

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-w65"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_TIC30
end_ifdef

begin_include
include|#
directive|include
file|"coff/tic30.h"
end_include

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-tic30"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_TIC54X
end_ifdef

begin_include
include|#
directive|include
file|"coff/tic54x.h"
end_include

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff1-c54x"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_TIC80
end_ifdef

begin_include
include|#
directive|include
file|"coff/tic80.h"
end_include

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-tic80"
end_define

begin_define
define|#
directive|define
name|ALIGNMENT_IN_S_FLAGS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_MCORE
end_ifdef

begin_include
include|#
directive|include
file|"coff/mcore.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_FORMAT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"pe-mcore"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Targets may also set this.  Also, if BFD_ASSEMBLER is defined, this    will already have been defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|SYMBOLS_NEED_BACKPOINTERS
end_undef

begin_define
define|#
directive|define
name|SYMBOLS_NEED_BACKPOINTERS
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|OBJ_COFF_MAX_AUXENTRIES
end_ifndef

begin_define
define|#
directive|define
name|OBJ_COFF_MAX_AUXENTRIES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJ_COFF_MAX_AUXENTRIES */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|coff_obj_symbol_new_hook
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|obj_symbol_new_hook
value|coff_obj_symbol_new_hook
end_define

begin_decl_stmt
specifier|extern
name|void
name|coff_obj_read_begin_hook
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
name|obj_read_begin_hook
value|coff_obj_read_begin_hook
end_define

begin_comment
comment|/* This file really contains two implementations of the COFF back end.    They are in the process of being merged, but this is only a    preliminary, mechanical merging.  Many definitions that are    identical between the two are still found in both versions.     The first version, with BFD_ASSEMBLER defined, uses high-level BFD    interfaces and data structures.  The second version, with    BFD_ASSEMBLER not defined, also uses BFD, but mostly for swapping    data structures and for doing the actual I/O.  The latter defines    the preprocessor symbols BFD and BFD_HEADERS.  Try not to let this    confuse you.     These two are in the process of being merged, and eventually the    BFD_ASSEMBLER version should take over completely.  Release timing    issues and namespace problems convinced me to merge the two    together in this fashion, a little sooner than I would have liked.    The real merge should be much better done by the time the next    release comes out.     For now, the structure of this file is:<common> 	#ifdef BFD_ASSEMBLER<one version> 	#else<other version> 	#endif<common>    Unfortunately, the common portions are very small at the moment,    and many declarations or definitions are duplicated.  The structure    of obj-coff.c is similar.     See doc/internals.texi for a brief discussion of the history, if    you care.     Ken Raeburn, 5 May 1994.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_include
include|#
directive|include
file|"bfd/libcoff.h"
end_include

begin_define
define|#
directive|define
name|OUTPUT_FLAVOR
value|bfd_target_coff_flavour
end_define

begin_comment
comment|/* SYMBOL TABLE */
end_comment

begin_comment
comment|/* Alter the field names, for now, until we've fixed up the other    references to use the new name.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_I960
end_ifdef

begin_define
define|#
directive|define
name|TC_SYMFIELD_TYPE
value|symbolS *
end_define

begin_define
define|#
directive|define
name|sy_tc
value|bal
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OBJ_SYMFIELD_TYPE
value|unsigned long
end_define

begin_define
define|#
directive|define
name|sy_obj
value|sy_flags
end_define

begin_define
define|#
directive|define
name|SYM_AUXENT
parameter_list|(
name|S
parameter_list|)
define|\
value|(&coffsymbol (symbol_get_bfdsym (S))->native[1].u.auxent)
end_define

begin_define
define|#
directive|define
name|SYM_AUXINFO
parameter_list|(
name|S
parameter_list|)
define|\
value|(&coffsymbol (symbol_get_bfdsym (S))->native[1])
end_define

begin_define
define|#
directive|define
name|DO_NOT_STRIP
value|0
end_define

begin_decl_stmt
specifier|extern
name|void
name|obj_coff_section
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of auxiliary entries.  */
end_comment

begin_define
define|#
directive|define
name|S_GET_NUMBER_AUXILIARY
parameter_list|(
name|s
parameter_list|)
define|\
value|(coffsymbol (symbol_get_bfdsym (s))->native->u.syment.n_numaux)
end_define

begin_comment
comment|/* The number of auxiliary entries.  */
end_comment

begin_define
define|#
directive|define
name|S_SET_NUMBER_AUXILIARY
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(S_GET_NUMBER_AUXILIARY (s) = (v))
end_define

begin_comment
comment|/* True if a symbol name is in the string table, i.e. its length is> 8.  */
end_comment

begin_define
define|#
directive|define
name|S_IS_STRING
parameter_list|(
name|s
parameter_list|)
value|(strlen(S_GET_NAME(s))> 8 ? 1 : 0)
end_define

begin_decl_stmt
specifier|extern
name|int
name|S_SET_DATA_TYPE
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|S_SET_STORAGE_CLASS
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|S_GET_STORAGE_CLASS
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
name|SA_SET_SYM_ENDNDX
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

begin_comment
comment|/* Auxiliary entry macros. SA_ stands for symbol auxiliary.  */
end_comment

begin_comment
comment|/* Omit the tv related fields.  */
end_comment

begin_comment
comment|/* Accessors.  */
end_comment

begin_define
define|#
directive|define
name|SA_GET_SYM_TAGNDX
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_tagndx.l)
end_define

begin_define
define|#
directive|define
name|SA_GET_SYM_LNNO
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_misc.x_lnsz.x_lnno)
end_define

begin_define
define|#
directive|define
name|SA_GET_SYM_SIZE
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_misc.x_lnsz.x_size)
end_define

begin_define
define|#
directive|define
name|SA_GET_SYM_FSIZE
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_misc.x_fsize)
end_define

begin_define
define|#
directive|define
name|SA_GET_SYM_LNNOPTR
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_fcnary.x_fcn.x_lnnoptr)
end_define

begin_define
define|#
directive|define
name|SA_GET_SYM_ENDNDX
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_fcnary.x_fcn.x_endndx)
end_define

begin_define
define|#
directive|define
name|SA_GET_SYM_DIMEN
parameter_list|(
name|s
parameter_list|,
name|i
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_fcnary.x_ary.x_dimen[(i)])
end_define

begin_define
define|#
directive|define
name|SA_GET_FILE_FNAME
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_file.x_fname)
end_define

begin_define
define|#
directive|define
name|SA_GET_SCN_SCNLEN
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_scn.x_scnlen)
end_define

begin_define
define|#
directive|define
name|SA_GET_SCN_NRELOC
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_scn.x_nreloc)
end_define

begin_define
define|#
directive|define
name|SA_GET_SCN_NLINNO
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_scn.x_nlinno)
end_define

begin_define
define|#
directive|define
name|SA_SET_SYM_LNNO
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_misc.x_lnsz.x_lnno=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_SYM_SIZE
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_misc.x_lnsz.x_size=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_SYM_FSIZE
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_misc.x_fsize=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_SYM_LNNOPTR
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_fcnary.x_fcn.x_lnnoptr=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_SYM_DIMEN
parameter_list|(
name|s
parameter_list|,
name|i
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_fcnary.x_ary.x_dimen[(i)]=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_FILE_FNAME
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|strncpy(SYM_AUXENT (s)->x_file.x_fname,(v),FILNMLEN)
end_define

begin_define
define|#
directive|define
name|SA_SET_SCN_SCNLEN
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_scn.x_scnlen=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_SCN_NRELOC
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_scn.x_nreloc=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_SCN_NLINNO
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_scn.x_nlinno=(v))
end_define

begin_comment
comment|/* Internal use only definitions. SF_ stands for symbol flags.       These values can be assigned to sy_symbol.ost_flags field of a symbolS.       You'll break i960 if you shift the SYSPROC bits anywhere else.  for    more on the balname/callname hack, see tc-i960.h.  b.out is done    differently.  */
end_comment

begin_define
define|#
directive|define
name|SF_I960_MASK
value|(0x000001ff)
end_define

begin_comment
comment|/* Bits 0-8 are used by the i960 port.  */
end_comment

begin_define
define|#
directive|define
name|SF_SYSPROC
value|(0x0000003f)
end_define

begin_comment
comment|/* bits 0-5 are used to store the sysproc number */
end_comment

begin_define
define|#
directive|define
name|SF_IS_SYSPROC
value|(0x00000040)
end_define

begin_comment
comment|/* bit 6 marks symbols that are sysprocs */
end_comment

begin_define
define|#
directive|define
name|SF_BALNAME
value|(0x00000080)
end_define

begin_comment
comment|/* bit 7 marks BALNAME symbols */
end_comment

begin_define
define|#
directive|define
name|SF_CALLNAME
value|(0x00000100)
end_define

begin_comment
comment|/* bit 8 marks CALLNAME symbols */
end_comment

begin_define
define|#
directive|define
name|SF_NORMAL_MASK
value|(0x0000ffff)
end_define

begin_comment
comment|/* bits 12-15 are general purpose.  */
end_comment

begin_define
define|#
directive|define
name|SF_STATICS
value|(0x00001000)
end_define

begin_comment
comment|/* Mark the .text& all symbols */
end_comment

begin_define
define|#
directive|define
name|SF_DEFINED
value|(0x00002000)
end_define

begin_comment
comment|/* Symbol is defined in this file */
end_comment

begin_define
define|#
directive|define
name|SF_STRING
value|(0x00004000)
end_define

begin_comment
comment|/* Symbol name length> 8 */
end_comment

begin_define
define|#
directive|define
name|SF_LOCAL
value|(0x00008000)
end_define

begin_comment
comment|/* Symbol must not be emitted */
end_comment

begin_define
define|#
directive|define
name|SF_DEBUG_MASK
value|(0xffff0000)
end_define

begin_comment
comment|/* bits 16-31 are debug info */
end_comment

begin_define
define|#
directive|define
name|SF_FUNCTION
value|(0x00010000)
end_define

begin_comment
comment|/* The symbol is a function */
end_comment

begin_define
define|#
directive|define
name|SF_PROCESS
value|(0x00020000)
end_define

begin_comment
comment|/* Process symbol before write */
end_comment

begin_define
define|#
directive|define
name|SF_TAGGED
value|(0x00040000)
end_define

begin_comment
comment|/* Is associated with a tag */
end_comment

begin_define
define|#
directive|define
name|SF_TAG
value|(0x00080000)
end_define

begin_comment
comment|/* Is a tag */
end_comment

begin_define
define|#
directive|define
name|SF_DEBUG
value|(0x00100000)
end_define

begin_comment
comment|/* Is in debug or abs section */
end_comment

begin_define
define|#
directive|define
name|SF_GET_SEGMENT
value|(0x00200000)
end_define

begin_comment
comment|/* Get the section of the forward symbol.  */
end_comment

begin_comment
comment|/* All other bits are unused.  */
end_comment

begin_comment
comment|/* Accessors.  */
end_comment

begin_define
define|#
directive|define
name|SF_GET
parameter_list|(
name|s
parameter_list|)
value|(*symbol_get_obj (s))
end_define

begin_define
define|#
directive|define
name|SF_GET_DEBUG
parameter_list|(
name|s
parameter_list|)
value|(symbol_get_bfdsym (s)->flags& BSF_DEBUGGING)
end_define

begin_define
define|#
directive|define
name|SF_SET_DEBUG
parameter_list|(
name|s
parameter_list|)
value|(symbol_get_bfdsym (s)->flags |= BSF_DEBUGGING)
end_define

begin_define
define|#
directive|define
name|SF_GET_NORMAL_FIELD
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_NORMAL_MASK)
end_define

begin_define
define|#
directive|define
name|SF_GET_DEBUG_FIELD
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_DEBUG_MASK)
end_define

begin_define
define|#
directive|define
name|SF_GET_FILE
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_FILE)
end_define

begin_define
define|#
directive|define
name|SF_GET_STATICS
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_STATICS)
end_define

begin_define
define|#
directive|define
name|SF_GET_DEFINED
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_DEFINED)
end_define

begin_define
define|#
directive|define
name|SF_GET_STRING
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_STRING)
end_define

begin_define
define|#
directive|define
name|SF_GET_LOCAL
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_LOCAL)
end_define

begin_define
define|#
directive|define
name|SF_GET_FUNCTION
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_FUNCTION)
end_define

begin_define
define|#
directive|define
name|SF_GET_PROCESS
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_PROCESS)
end_define

begin_define
define|#
directive|define
name|SF_GET_TAGGED
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_TAGGED)
end_define

begin_define
define|#
directive|define
name|SF_GET_TAG
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_TAG)
end_define

begin_define
define|#
directive|define
name|SF_GET_GET_SEGMENT
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_GET_SEGMENT)
end_define

begin_define
define|#
directive|define
name|SF_GET_I960
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_I960_MASK)
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_define
define|#
directive|define
name|SF_GET_BALNAME
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_BALNAME)
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_define
define|#
directive|define
name|SF_GET_CALLNAME
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_CALLNAME)
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_define
define|#
directive|define
name|SF_GET_IS_SYSPROC
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_IS_SYSPROC)
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_define
define|#
directive|define
name|SF_GET_SYSPROC
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_SYSPROC)
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_comment
comment|/* Modifiers.  */
end_comment

begin_define
define|#
directive|define
name|SF_SET
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SF_GET (s) = (v))
end_define

begin_define
define|#
directive|define
name|SF_SET_NORMAL_FIELD
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SF_GET (s) |= ((v)& SF_NORMAL_MASK))
end_define

begin_define
define|#
directive|define
name|SF_SET_DEBUG_FIELD
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SF_GET (s) |= ((v)& SF_DEBUG_MASK))
end_define

begin_define
define|#
directive|define
name|SF_SET_FILE
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_FILE)
end_define

begin_define
define|#
directive|define
name|SF_SET_STATICS
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_STATICS)
end_define

begin_define
define|#
directive|define
name|SF_SET_DEFINED
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_DEFINED)
end_define

begin_define
define|#
directive|define
name|SF_SET_STRING
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_STRING)
end_define

begin_define
define|#
directive|define
name|SF_SET_LOCAL
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_LOCAL)
end_define

begin_define
define|#
directive|define
name|SF_CLEAR_LOCAL
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)&= ~SF_LOCAL)
end_define

begin_define
define|#
directive|define
name|SF_SET_FUNCTION
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_FUNCTION)
end_define

begin_define
define|#
directive|define
name|SF_SET_PROCESS
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_PROCESS)
end_define

begin_define
define|#
directive|define
name|SF_SET_TAGGED
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_TAGGED)
end_define

begin_define
define|#
directive|define
name|SF_SET_TAG
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_TAG)
end_define

begin_define
define|#
directive|define
name|SF_SET_GET_SEGMENT
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_GET_SEGMENT)
end_define

begin_define
define|#
directive|define
name|SF_SET_I960
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SF_GET (s) |= ((v)& SF_I960_MASK))
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_define
define|#
directive|define
name|SF_SET_BALNAME
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_BALNAME)
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_define
define|#
directive|define
name|SF_SET_CALLNAME
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_CALLNAME)
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_define
define|#
directive|define
name|SF_SET_IS_SYSPROC
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_IS_SYSPROC)
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_define
define|#
directive|define
name|SF_SET_SYSPROC
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SF_GET (s) |= ((v)& SF_SYSPROC))
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_comment
comment|/* --------------  Line number handling ------- */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|text_lineno_number
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|coff_line_base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|coff_n_line_nos
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|obj_emit_lineno
parameter_list|(
name|WHERE
parameter_list|,
name|LINE
parameter_list|,
name|FILE_START
parameter_list|)
value|abort ()
end_define

begin_decl_stmt
specifier|extern
name|void
name|coff_add_linesym
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
name|void
name|c_dot_file_symbol
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|obj_app_file
value|c_dot_file_symbol
end_define

begin_decl_stmt
specifier|extern
name|void
name|coff_frob_symbol
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|coff_adjust_symtab
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|coff_frob_section
name|PARAMS
argument_list|(
operator|(
name|segT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|coff_adjust_section_syms
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|coff_frob_file_after_relocs
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
name|obj_frob_symbol
parameter_list|(
name|S
parameter_list|,
name|P
parameter_list|)
value|coff_frob_symbol(S,&P)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|obj_adjust_symtab
end_ifndef

begin_define
define|#
directive|define
name|obj_adjust_symtab
parameter_list|()
value|coff_adjust_symtab()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|obj_frob_section
parameter_list|(
name|S
parameter_list|)
value|coff_frob_section (S)
end_define

begin_define
define|#
directive|define
name|obj_frob_file_after_relocs
parameter_list|()
value|coff_frob_file_after_relocs ()
end_define

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|coff_last_function
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Forward the segment of a forwarded symbol, handle assignments that    just copy symbol values, etc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OBJ_COPY_SYMBOL_ATTRIBUTES
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|TE_I386AIX
end_ifndef

begin_define
define|#
directive|define
name|OBJ_COPY_SYMBOL_ATTRIBUTES
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
define|\
value|(SF_GET_GET_SEGMENT (dest) \    ? (S_SET_SEGMENT (dest, S_GET_SEGMENT (src)), 0) \    : 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OBJ_COPY_SYMBOL_ATTRIBUTES
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
define|\
value|(SF_GET_GET_SEGMENT (dest)&& S_GET_SEGMENT (dest) == SEG_UNKNOWN \    ? (S_SET_SEGMENT (dest, S_GET_SEGMENT (src)), 0) \    : 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sanity check.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_I960
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|C_LEAFSTAT
end_ifndef

begin_expr_stmt
name|hey
operator|!
name|Where
name|is
name|the
name|C_LEAFSTAT
name|definition
condition|?
name|i960
operator|-
name|coff
name|support
name|is
name|depending
name|on
name|it
operator|.
endif|#
directive|endif
comment|/* no C_LEAFSTAT */
endif|#
directive|endif
comment|/* TC_I960 */
else|#
directive|else
comment|/* not BFD_ASSEMBLER */
if|#
directive|if
name|defined
name|TC_A29K
operator|||
name|defined
name|TC_OR32
comment|/* Allow translate from aout relocs to coff relocs.  */
define|#
directive|define
name|NO_RELOC
value|20
define|#
directive|define
name|RELOC_32
value|1
define|#
directive|define
name|RELOC_8
value|2
define|#
directive|define
name|RELOC_CONST
value|3
define|#
directive|define
name|RELOC_CONSTH
value|4
define|#
directive|define
name|RELOC_JUMPTARG
value|5
define|#
directive|define
name|RELOC_BASE22
value|6
define|#
directive|define
name|RELOC_HI22
value|7
define|#
directive|define
name|RELOC_LO10
value|8
define|#
directive|define
name|RELOC_BASE13
value|9
define|#
directive|define
name|RELOC_WDISP22
value|10
define|#
directive|define
name|RELOC_WDISP30
value|11
endif|#
directive|endif
expr|extern
specifier|const
name|segT
name|N_TYPE_seg
index|[]
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Magic number of paged executable.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_MAGIC_NUMBER_FOR_OBJECT_FILE
value|0x8300
end_define

begin_comment
comment|/* SYMBOL TABLE */
end_comment

begin_comment
comment|/* Symbol table entry data type.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Basic symbol */
name|struct
name|internal_syment
name|ost_entry
decl_stmt|;
comment|/* Auxiliary entry.  */
name|union
name|internal_auxent
name|ost_auxent
index|[
name|OBJ_COFF_MAX_AUXENTRIES
index|]
decl_stmt|;
comment|/* obj_coff internal use only flags.  */
name|unsigned
name|int
name|ost_flags
decl_stmt|;
block|}
name|obj_symbol_type
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|DO_NOT_STRIP
end_ifndef

begin_define
define|#
directive|define
name|DO_NOT_STRIP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Symbol table macros and constants.  */
end_comment

begin_comment
comment|/* Possible and usefull section number in symbol table    The values of TEXT, DATA and BSS may not be portable.  */
end_comment

begin_define
define|#
directive|define
name|C_ABS_SECTION
value|N_ABS
end_define

begin_define
define|#
directive|define
name|C_UNDEF_SECTION
value|N_UNDEF
end_define

begin_define
define|#
directive|define
name|C_DEBUG_SECTION
value|N_DEBUG
end_define

begin_define
define|#
directive|define
name|C_NTV_SECTION
value|N_TV
end_define

begin_define
define|#
directive|define
name|C_PTV_SECTION
value|P_TV
end_define

begin_define
define|#
directive|define
name|C_REGISTER_SECTION
value|50
end_define

begin_comment
comment|/* Macros to extract information from a symbol table entry.    This syntaxic indirection allows independence regarding a.out or coff.    The argument (s) of all these macros is a pointer to a symbol table entry.  */
end_comment

begin_comment
comment|/* Predicates.  */
end_comment

begin_comment
comment|/* True if the symbol is external.  */
end_comment

begin_define
define|#
directive|define
name|S_IS_EXTERNAL
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_scnum == C_UNDEF_SECTION)
end_define

begin_comment
comment|/* True if symbol has been defined, ie :    section> 0 (DATA, TEXT or BSS)    section == 0 and value> 0 (external bss symbol).  */
end_comment

begin_define
define|#
directive|define
name|S_IS_DEFINED
parameter_list|(
name|s
parameter_list|)
define|\
value|((s)->sy_symbol.ost_entry.n_scnum> C_UNDEF_SECTION \    || ((s)->sy_symbol.ost_entry.n_scnum == C_UNDEF_SECTION \&& S_GET_VALUE (s)> 0) \    || ((s)->sy_symbol.ost_entry.n_scnum == C_ABS_SECTION))
end_define

begin_comment
comment|/* True if a debug special symbol entry.  */
end_comment

begin_define
define|#
directive|define
name|S_IS_DEBUG
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_scnum == C_DEBUG_SECTION)
end_define

begin_comment
comment|/* True if a symbol is local symbol name.  */
end_comment

begin_comment
comment|/* A symbol name whose name includes ^A is a gas internal pseudo symbol.  */
end_comment

begin_define
define|#
directive|define
name|S_IS_LOCAL
parameter_list|(
name|s
parameter_list|)
define|\
value|((s)->sy_symbol.ost_entry.n_scnum == C_REGISTER_SECTION \    || (S_LOCAL_NAME(s)&& ! flag_keep_locals&& ! S_IS_DEBUG (s)) \    || strchr (S_GET_NAME (s), '\001') != NULL \    || strchr (S_GET_NAME (s), '\002') != NULL \    || (flag_strip_local_absolute \&& !S_IS_EXTERNAL(s) \&& (s)->sy_symbol.ost_entry.n_scnum == C_ABS_SECTION))
end_define

begin_comment
comment|/* True if a symbol is not defined in this file.  */
end_comment

begin_define
define|#
directive|define
name|S_IS_EXTERN
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_scnum == 0 \&& S_GET_VALUE (s) == 0)
end_define

begin_comment
comment|/* True if a symbol can be multiply defined (bss symbols have this def    though it is bad practice).  */
end_comment

begin_define
define|#
directive|define
name|S_IS_COMMON
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_scnum == 0 \&& S_GET_VALUE (s) != 0)
end_define

begin_comment
comment|/* True if a symbol name is in the string table, i.e. its length is> 8.  */
end_comment

begin_define
define|#
directive|define
name|S_IS_STRING
parameter_list|(
name|s
parameter_list|)
value|(strlen(S_GET_NAME(s))> 8 ? 1 : 0)
end_define

begin_comment
comment|/* True if a symbol is defined as weak.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TE_PE
end_ifdef

begin_define
define|#
directive|define
name|S_IS_WEAK
parameter_list|(
name|s
parameter_list|)
define|\
value|((s)->sy_symbol.ost_entry.n_sclass == C_NT_WEAK \    || (s)->sy_symbol.ost_entry.n_sclass == C_WEAKEXT)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_IS_WEAK
parameter_list|(
name|s
parameter_list|)
define|\
value|((s)->sy_symbol.ost_entry.n_sclass == C_WEAKEXT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Accessors.  */
end_comment

begin_comment
comment|/* The name of the symbol.  */
end_comment

begin_define
define|#
directive|define
name|S_GET_NAME
parameter_list|(
name|s
parameter_list|)
value|((char*) (s)->sy_symbol.ost_entry.n_offset)
end_define

begin_comment
comment|/* The pointer to the string table.  */
end_comment

begin_define
define|#
directive|define
name|S_GET_OFFSET
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_offset)
end_define

begin_comment
comment|/* The numeric value of the segment.  */
end_comment

begin_define
define|#
directive|define
name|S_GET_SEGMENT
parameter_list|(
name|s
parameter_list|)
value|s_get_segment(s)
end_define

begin_comment
comment|/* The data type.  */
end_comment

begin_define
define|#
directive|define
name|S_GET_DATA_TYPE
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_type)
end_define

begin_comment
comment|/* The storage class.  */
end_comment

begin_define
define|#
directive|define
name|S_GET_STORAGE_CLASS
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_sclass)
end_define

begin_comment
comment|/* The number of auxiliary entries.  */
end_comment

begin_define
define|#
directive|define
name|S_GET_NUMBER_AUXILIARY
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_numaux)
end_define

begin_comment
comment|/* Modifiers.  */
end_comment

begin_comment
comment|/* Set the name of the symbol.  */
end_comment

begin_define
define|#
directive|define
name|S_SET_NAME
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_offset = (unsigned long) (v))
end_define

begin_comment
comment|/* Set the offset of the symbol.  */
end_comment

begin_define
define|#
directive|define
name|S_SET_OFFSET
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_offset = (v))
end_define

begin_comment
comment|/* The numeric value of the segment.  */
end_comment

begin_define
define|#
directive|define
name|S_SET_SEGMENT
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_scnum = SEGMENT_TO_SYMBOL_TYPE(v))
end_define

begin_comment
comment|/* The data type.  */
end_comment

begin_define
define|#
directive|define
name|S_SET_DATA_TYPE
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_type = (v))
end_define

begin_comment
comment|/* The storage class.  */
end_comment

begin_define
define|#
directive|define
name|S_SET_STORAGE_CLASS
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_sclass = (v))
end_define

begin_comment
comment|/* The number of auxiliary entries.  */
end_comment

begin_define
define|#
directive|define
name|S_SET_NUMBER_AUXILIARY
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_numaux = (v))
end_define

begin_comment
comment|/* Additional modifiers.  */
end_comment

begin_comment
comment|/* The symbol is external (does not mean undefined).  */
end_comment

begin_define
define|#
directive|define
name|S_SET_EXTERNAL
parameter_list|(
name|s
parameter_list|)
value|{ S_SET_STORAGE_CLASS(s, C_EXT) ; SF_CLEAR_LOCAL(s); }
end_define

begin_comment
comment|/* Auxiliary entry macros. SA_ stands for symbol auxiliary.  */
end_comment

begin_comment
comment|/* Omit the tv related fields.  */
end_comment

begin_comment
comment|/* Accessors.  */
end_comment

begin_define
define|#
directive|define
name|SYM_AUXENT
parameter_list|(
name|S
parameter_list|)
value|(&(S)->sy_symbol.ost_auxent[0])
end_define

begin_define
define|#
directive|define
name|SA_GET_SYM_TAGNDX
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_tagndx.l)
end_define

begin_define
define|#
directive|define
name|SA_GET_SYM_LNNO
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_misc.x_lnsz.x_lnno)
end_define

begin_define
define|#
directive|define
name|SA_GET_SYM_SIZE
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_misc.x_lnsz.x_size)
end_define

begin_define
define|#
directive|define
name|SA_GET_SYM_FSIZE
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_misc.x_fsize)
end_define

begin_define
define|#
directive|define
name|SA_GET_SYM_LNNOPTR
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_fcnary.x_fcn.x_lnnoptr)
end_define

begin_define
define|#
directive|define
name|SA_GET_SYM_ENDNDX
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_fcnary.x_fcn.x_endndx.l)
end_define

begin_define
define|#
directive|define
name|SA_GET_SYM_DIMEN
parameter_list|(
name|s
parameter_list|,
name|i
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_fcnary.x_ary.x_dimen[(i)])
end_define

begin_define
define|#
directive|define
name|SA_GET_FILE_FNAME
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_file.x_fname)
end_define

begin_define
define|#
directive|define
name|SA_GET_FILE_FNAME_OFFSET
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_file.x_n.x_offset)
end_define

begin_define
define|#
directive|define
name|SA_GET_FILE_FNAME_ZEROS
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_file.x_n.x_zeroes)
end_define

begin_define
define|#
directive|define
name|SA_GET_SCN_SCNLEN
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_scn.x_scnlen)
end_define

begin_define
define|#
directive|define
name|SA_GET_SCN_NRELOC
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_scn.x_nreloc)
end_define

begin_define
define|#
directive|define
name|SA_GET_SCN_NLINNO
parameter_list|(
name|s
parameter_list|)
value|(SYM_AUXENT (s)->x_scn.x_nlinno)
end_define

begin_comment
comment|/* Modifiers.  */
end_comment

begin_define
define|#
directive|define
name|SA_SET_SYM_TAGNDX
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_tagndx.l=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_SYM_LNNO
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_misc.x_lnsz.x_lnno=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_SYM_SIZE
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_misc.x_lnsz.x_size=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_SYM_FSIZE
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_misc.x_fsize=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_SYM_LNNOPTR
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_fcnary.x_fcn.x_lnnoptr=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_SYM_ENDNDX
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_fcnary.x_fcn.x_endndx.l=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_SYM_DIMEN
parameter_list|(
name|s
parameter_list|,
name|i
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_sym.x_fcnary.x_ary.x_dimen[(i)]=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_FILE_FNAME
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|strncpy(SYM_AUXENT (s)->x_file.x_fname,(v),FILNMLEN)
end_define

begin_define
define|#
directive|define
name|SA_SET_FILE_FNAME_OFFSET
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_file.x_n.x_offset=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_FILE_FNAME_ZEROS
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_file.x_n.x_zeroes=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_SCN_SCNLEN
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_scn.x_scnlen=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_SCN_NRELOC
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_scn.x_nreloc=(v))
end_define

begin_define
define|#
directive|define
name|SA_SET_SCN_NLINNO
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SYM_AUXENT (s)->x_scn.x_nlinno=(v))
end_define

begin_comment
comment|/* Internal use only definitions. SF_ stands for symbol flags.       These values can be assigned to sy_symbol.ost_flags field of a symbolS.       You'll break i960 if you shift the SYSPROC bits anywhere else.  for    more on the balname/callname hack, see tc-i960.h.  b.out is done    differently.  */
end_comment

begin_define
define|#
directive|define
name|SF_I960_MASK
value|(0x000001ff)
end_define

begin_comment
comment|/* Bits 0-8 are used by the i960 port.  */
end_comment

begin_define
define|#
directive|define
name|SF_SYSPROC
value|(0x0000003f)
end_define

begin_comment
comment|/* bits 0-5 are used to store the sysproc number */
end_comment

begin_define
define|#
directive|define
name|SF_IS_SYSPROC
value|(0x00000040)
end_define

begin_comment
comment|/* bit 6 marks symbols that are sysprocs */
end_comment

begin_define
define|#
directive|define
name|SF_BALNAME
value|(0x00000080)
end_define

begin_comment
comment|/* bit 7 marks BALNAME symbols */
end_comment

begin_define
define|#
directive|define
name|SF_CALLNAME
value|(0x00000100)
end_define

begin_comment
comment|/* bit 8 marks CALLNAME symbols */
end_comment

begin_define
define|#
directive|define
name|SF_NORMAL_MASK
value|(0x0000ffff)
end_define

begin_comment
comment|/* bits 12-15 are general purpose.  */
end_comment

begin_define
define|#
directive|define
name|SF_STATICS
value|(0x00001000)
end_define

begin_comment
comment|/* Mark the .text& all symbols */
end_comment

begin_define
define|#
directive|define
name|SF_DEFINED
value|(0x00002000)
end_define

begin_comment
comment|/* Symbol is defined in this file */
end_comment

begin_define
define|#
directive|define
name|SF_STRING
value|(0x00004000)
end_define

begin_comment
comment|/* Symbol name length> 8 */
end_comment

begin_define
define|#
directive|define
name|SF_LOCAL
value|(0x00008000)
end_define

begin_comment
comment|/* Symbol must not be emitted */
end_comment

begin_define
define|#
directive|define
name|SF_DEBUG_MASK
value|(0xffff0000)
end_define

begin_comment
comment|/* bits 16-31 are debug info */
end_comment

begin_define
define|#
directive|define
name|SF_FUNCTION
value|(0x00010000)
end_define

begin_comment
comment|/* The symbol is a function */
end_comment

begin_define
define|#
directive|define
name|SF_PROCESS
value|(0x00020000)
end_define

begin_comment
comment|/* Process symbol before write */
end_comment

begin_define
define|#
directive|define
name|SF_TAGGED
value|(0x00040000)
end_define

begin_comment
comment|/* Is associated with a tag */
end_comment

begin_define
define|#
directive|define
name|SF_TAG
value|(0x00080000)
end_define

begin_comment
comment|/* Is a tag */
end_comment

begin_define
define|#
directive|define
name|SF_DEBUG
value|(0x00100000)
end_define

begin_comment
comment|/* Is in debug or abs section */
end_comment

begin_define
define|#
directive|define
name|SF_GET_SEGMENT
value|(0x00200000)
end_define

begin_comment
comment|/* Get the section of the forward symbol.  */
end_comment

begin_define
define|#
directive|define
name|SF_ADJ_LNNOPTR
value|(0x00400000)
end_define

begin_comment
comment|/* Has a lnnoptr */
end_comment

begin_comment
comment|/* All other bits are unused.  */
end_comment

begin_comment
comment|/* Accessors.  */
end_comment

begin_define
define|#
directive|define
name|SF_GET
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags)
end_define

begin_define
define|#
directive|define
name|SF_GET_NORMAL_FIELD
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_NORMAL_MASK)
end_define

begin_define
define|#
directive|define
name|SF_GET_DEBUG_FIELD
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_DEBUG_MASK)
end_define

begin_define
define|#
directive|define
name|SF_GET_FILE
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_FILE)
end_define

begin_define
define|#
directive|define
name|SF_GET_STATICS
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_STATICS)
end_define

begin_define
define|#
directive|define
name|SF_GET_DEFINED
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_DEFINED)
end_define

begin_define
define|#
directive|define
name|SF_GET_STRING
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_STRING)
end_define

begin_define
define|#
directive|define
name|SF_GET_LOCAL
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_LOCAL)
end_define

begin_define
define|#
directive|define
name|SF_GET_FUNCTION
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_FUNCTION)
end_define

begin_define
define|#
directive|define
name|SF_GET_PROCESS
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_PROCESS)
end_define

begin_define
define|#
directive|define
name|SF_GET_DEBUG
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_DEBUG)
end_define

begin_define
define|#
directive|define
name|SF_GET_TAGGED
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_TAGGED)
end_define

begin_define
define|#
directive|define
name|SF_GET_TAG
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_TAG)
end_define

begin_define
define|#
directive|define
name|SF_GET_GET_SEGMENT
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_GET_SEGMENT)
end_define

begin_define
define|#
directive|define
name|SF_GET_ADJ_LNNOPTR
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_ADJ_LNNOPTR)
end_define

begin_define
define|#
directive|define
name|SF_GET_I960
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_I960_MASK)
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_define
define|#
directive|define
name|SF_GET_BALNAME
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_BALNAME)
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_define
define|#
directive|define
name|SF_GET_CALLNAME
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_CALLNAME)
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_define
define|#
directive|define
name|SF_GET_IS_SYSPROC
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_IS_SYSPROC)
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_define
define|#
directive|define
name|SF_GET_SYSPROC
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)& SF_SYSPROC)
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_comment
comment|/* Modifiers.  */
end_comment

begin_define
define|#
directive|define
name|SF_SET
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SF_GET (s) = (v))
end_define

begin_define
define|#
directive|define
name|SF_SET_NORMAL_FIELD
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SF_GET (s) |= ((v)& SF_NORMAL_MASK))
end_define

begin_define
define|#
directive|define
name|SF_SET_DEBUG_FIELD
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SF_GET (s) |= ((v)& SF_DEBUG_MASK))
end_define

begin_define
define|#
directive|define
name|SF_SET_FILE
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_FILE)
end_define

begin_define
define|#
directive|define
name|SF_SET_STATICS
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_STATICS)
end_define

begin_define
define|#
directive|define
name|SF_SET_DEFINED
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_DEFINED)
end_define

begin_define
define|#
directive|define
name|SF_SET_STRING
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_STRING)
end_define

begin_define
define|#
directive|define
name|SF_SET_LOCAL
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_LOCAL)
end_define

begin_define
define|#
directive|define
name|SF_CLEAR_LOCAL
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s)&= ~SF_LOCAL)
end_define

begin_define
define|#
directive|define
name|SF_SET_FUNCTION
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_FUNCTION)
end_define

begin_define
define|#
directive|define
name|SF_SET_PROCESS
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_PROCESS)
end_define

begin_define
define|#
directive|define
name|SF_SET_DEBUG
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_DEBUG)
end_define

begin_define
define|#
directive|define
name|SF_SET_TAGGED
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_TAGGED)
end_define

begin_define
define|#
directive|define
name|SF_SET_TAG
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_TAG)
end_define

begin_define
define|#
directive|define
name|SF_SET_GET_SEGMENT
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_GET_SEGMENT)
end_define

begin_define
define|#
directive|define
name|SF_SET_ADJ_LNNOPTR
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_ADJ_LNNOPTR)
end_define

begin_define
define|#
directive|define
name|SF_SET_I960
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SF_GET (s) |= ((v)& SF_I960_MASK))
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_define
define|#
directive|define
name|SF_SET_BALNAME
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_BALNAME)
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_define
define|#
directive|define
name|SF_SET_CALLNAME
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_CALLNAME)
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_define
define|#
directive|define
name|SF_SET_IS_SYSPROC
parameter_list|(
name|s
parameter_list|)
value|(SF_GET (s) |= SF_IS_SYSPROC)
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_define
define|#
directive|define
name|SF_SET_SYSPROC
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SF_GET (s) |= ((v)& SF_SYSPROC))
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_comment
comment|/* File header macro and type definition.  */
end_comment

begin_comment
comment|/* File position calculators. Beware to use them when all the    appropriate fields are set in the header.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_COFF_OMIT_OPTIONAL_HEADER
end_ifdef

begin_define
define|#
directive|define
name|OBJ_COFF_AOUTHDRSZ
value|(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OBJ_COFF_AOUTHDRSZ
value|(AOUTHDRSZ)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJ_COFF_OMIT_OPTIONAL_HEADER */
end_comment

begin_define
define|#
directive|define
name|H_GET_FILE_SIZE
parameter_list|(
name|h
parameter_list|)
define|\
value|(long) (FILHSZ + OBJ_COFF_AOUTHDRSZ + \ 	   H_GET_NUMBER_OF_SECTIONS(h) * SCNHSZ + \ 	   H_GET_TEXT_SIZE(h) + H_GET_DATA_SIZE(h) + \ 	   H_GET_RELOCATION_SIZE(h) + H_GET_LINENO_SIZE(h) + \ 	   H_GET_SYMBOL_TABLE_SIZE(h) + \ 	   (h)->string_table_size)
end_define

begin_define
define|#
directive|define
name|H_GET_TEXT_FILE_OFFSET
parameter_list|(
name|h
parameter_list|)
define|\
value|(long) (FILHSZ + OBJ_COFF_AOUTHDRSZ + \ 	   H_GET_NUMBER_OF_SECTIONS(h) * SCNHSZ)
end_define

begin_define
define|#
directive|define
name|H_GET_DATA_FILE_OFFSET
parameter_list|(
name|h
parameter_list|)
define|\
value|(long) (FILHSZ + OBJ_COFF_AOUTHDRSZ + \ 	   H_GET_NUMBER_OF_SECTIONS(h) * SCNHSZ + \ 	   H_GET_TEXT_SIZE(h))
end_define

begin_define
define|#
directive|define
name|H_GET_BSS_FILE_OFFSET
parameter_list|(
name|h
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|H_GET_RELOCATION_FILE_OFFSET
parameter_list|(
name|h
parameter_list|)
define|\
value|(long) (FILHSZ + OBJ_COFF_AOUTHDRSZ + \ 	   H_GET_NUMBER_OF_SECTIONS(h) * SCNHSZ + \ 	   H_GET_TEXT_SIZE(h) + H_GET_DATA_SIZE(h))
end_define

begin_define
define|#
directive|define
name|H_GET_LINENO_FILE_OFFSET
parameter_list|(
name|h
parameter_list|)
define|\
value|(long) (FILHSZ + OBJ_COFF_AOUTHDRSZ + \ 	   H_GET_NUMBER_OF_SECTIONS(h) * SCNHSZ + \ 	   H_GET_TEXT_SIZE(h) + H_GET_DATA_SIZE(h) + \ 	   H_GET_RELOCATION_SIZE(h))
end_define

begin_define
define|#
directive|define
name|H_GET_SYMBOL_TABLE_FILE_OFFSET
parameter_list|(
name|h
parameter_list|)
define|\
value|(long) (FILHSZ + OBJ_COFF_AOUTHDRSZ + \ 	   H_GET_NUMBER_OF_SECTIONS(h) * SCNHSZ + \ 	   H_GET_TEXT_SIZE(h) + H_GET_DATA_SIZE(h) + \ 	   H_GET_RELOCATION_SIZE(h) + H_GET_LINENO_SIZE(h))
end_define

begin_comment
comment|/* Accessors.  */
end_comment

begin_comment
comment|/* aouthdr.  */
end_comment

begin_define
define|#
directive|define
name|H_GET_MAGIC_NUMBER
parameter_list|(
name|h
parameter_list|)
value|((h)->aouthdr.magic)
end_define

begin_define
define|#
directive|define
name|H_GET_VERSION_STAMP
parameter_list|(
name|h
parameter_list|)
value|((h)->aouthdr.vstamp)
end_define

begin_define
define|#
directive|define
name|H_GET_TEXT_SIZE
parameter_list|(
name|h
parameter_list|)
value|((h)->aouthdr.tsize)
end_define

begin_define
define|#
directive|define
name|H_GET_DATA_SIZE
parameter_list|(
name|h
parameter_list|)
value|((h)->aouthdr.dsize)
end_define

begin_define
define|#
directive|define
name|H_GET_BSS_SIZE
parameter_list|(
name|h
parameter_list|)
value|((h)->aouthdr.bsize)
end_define

begin_define
define|#
directive|define
name|H_GET_ENTRY_POINT
parameter_list|(
name|h
parameter_list|)
value|((h)->aouthdr.entry)
end_define

begin_define
define|#
directive|define
name|H_GET_TEXT_START
parameter_list|(
name|h
parameter_list|)
value|((h)->aouthdr.text_start)
end_define

begin_define
define|#
directive|define
name|H_GET_DATA_START
parameter_list|(
name|h
parameter_list|)
value|((h)->aouthdr.data_start)
end_define

begin_comment
comment|/* filehdr.  */
end_comment

begin_define
define|#
directive|define
name|H_GET_FILE_MAGIC_NUMBER
parameter_list|(
name|h
parameter_list|)
value|((h)->filehdr.f_magic)
end_define

begin_define
define|#
directive|define
name|H_GET_NUMBER_OF_SECTIONS
parameter_list|(
name|h
parameter_list|)
value|((h)->filehdr.f_nscns)
end_define

begin_define
define|#
directive|define
name|H_GET_TIME_STAMP
parameter_list|(
name|h
parameter_list|)
value|((h)->filehdr.f_timdat)
end_define

begin_define
define|#
directive|define
name|H_GET_SYMBOL_TABLE_POINTER
parameter_list|(
name|h
parameter_list|)
value|((h)->filehdr.f_symptr)
end_define

begin_define
define|#
directive|define
name|H_GET_SYMBOL_COUNT
parameter_list|(
name|h
parameter_list|)
value|((h)->filehdr.f_nsyms)
end_define

begin_define
define|#
directive|define
name|H_GET_SYMBOL_TABLE_SIZE
parameter_list|(
name|h
parameter_list|)
value|(H_GET_SYMBOL_COUNT(h) * SYMESZ)
end_define

begin_define
define|#
directive|define
name|H_GET_SIZEOF_OPTIONAL_HEADER
parameter_list|(
name|h
parameter_list|)
value|((h)->filehdr.f_opthdr)
end_define

begin_define
define|#
directive|define
name|H_GET_FLAGS
parameter_list|(
name|h
parameter_list|)
value|((h)->filehdr.f_flags)
end_define

begin_comment
comment|/* Extra fields to achieve bsd a.out compatibility and for convenience.  */
end_comment

begin_define
define|#
directive|define
name|H_GET_RELOCATION_SIZE
parameter_list|(
name|h
parameter_list|)
value|((h)->relocation_size)
end_define

begin_define
define|#
directive|define
name|H_GET_STRING_SIZE
parameter_list|(
name|h
parameter_list|)
value|((h)->string_table_size)
end_define

begin_define
define|#
directive|define
name|H_GET_LINENO_SIZE
parameter_list|(
name|h
parameter_list|)
value|((h)->lineno_size)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|OBJ_COFF_OMIT_OPTIONAL_HEADER
end_ifndef

begin_define
define|#
directive|define
name|H_GET_HEADER_SIZE
parameter_list|(
name|h
parameter_list|)
value|(sizeof (FILHDR) \ 					 + sizeof (AOUTHDR)\ 					 + (H_GET_NUMBER_OF_SECTIONS(h) * SCNHSZ))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* OBJ_COFF_OMIT_OPTIONAL_HEADER */
end_comment

begin_define
define|#
directive|define
name|H_GET_HEADER_SIZE
parameter_list|(
name|h
parameter_list|)
value|(sizeof (FILHDR) \ 					 + (H_GET_NUMBER_OF_SECTIONS(h) * SCNHSZ))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJ_COFF_OMIT_OPTIONAL_HEADER */
end_comment

begin_define
define|#
directive|define
name|H_GET_TEXT_RELOCATION_SIZE
parameter_list|(
name|h
parameter_list|)
value|(text_section_header.s_nreloc * RELSZ)
end_define

begin_define
define|#
directive|define
name|H_GET_DATA_RELOCATION_SIZE
parameter_list|(
name|h
parameter_list|)
value|(data_section_header.s_nreloc * RELSZ)
end_define

begin_comment
comment|/* Modifiers.  */
end_comment

begin_comment
comment|/* aouthdr.  */
end_comment

begin_define
define|#
directive|define
name|H_SET_MAGIC_NUMBER
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->aouthdr.magic = (v))
end_define

begin_define
define|#
directive|define
name|H_SET_VERSION_STAMP
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->aouthdr.vstamp = (v))
end_define

begin_define
define|#
directive|define
name|H_SET_TEXT_SIZE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->aouthdr.tsize = (v))
end_define

begin_define
define|#
directive|define
name|H_SET_DATA_SIZE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->aouthdr.dsize = (v))
end_define

begin_define
define|#
directive|define
name|H_SET_BSS_SIZE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->aouthdr.bsize = (v))
end_define

begin_define
define|#
directive|define
name|H_SET_ENTRY_POINT
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->aouthdr.entry = (v))
end_define

begin_define
define|#
directive|define
name|H_SET_TEXT_START
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->aouthdr.text_start = (v))
end_define

begin_define
define|#
directive|define
name|H_SET_DATA_START
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->aouthdr.data_start = (v))
end_define

begin_comment
comment|/* filehdr.  */
end_comment

begin_define
define|#
directive|define
name|H_SET_FILE_MAGIC_NUMBER
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->filehdr.f_magic = (v))
end_define

begin_define
define|#
directive|define
name|H_SET_NUMBER_OF_SECTIONS
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->filehdr.f_nscns = (v))
end_define

begin_define
define|#
directive|define
name|H_SET_TIME_STAMP
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->filehdr.f_timdat = (v))
end_define

begin_define
define|#
directive|define
name|H_SET_SYMBOL_TABLE_POINTER
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->filehdr.f_symptr = (v))
end_define

begin_define
define|#
directive|define
name|H_SET_SYMBOL_TABLE_SIZE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->filehdr.f_nsyms = (v))
end_define

begin_define
define|#
directive|define
name|H_SET_SIZEOF_OPTIONAL_HEADER
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->filehdr.f_opthdr = (v))
end_define

begin_define
define|#
directive|define
name|H_SET_FLAGS
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->filehdr.f_flags = (v))
end_define

begin_comment
comment|/* Extra fields to achieve bsd a.out compatibility and for convinience.  */
end_comment

begin_define
define|#
directive|define
name|H_SET_RELOCATION_SIZE
parameter_list|(
name|h
parameter_list|,
name|t
parameter_list|,
name|d
parameter_list|)
value|((h)->relocation_size = (t)+(d))
end_define

begin_define
define|#
directive|define
name|H_SET_STRING_SIZE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->string_table_size = (v))
end_define

begin_define
define|#
directive|define
name|H_SET_LINENO_SIZE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->lineno_size = (v))
end_define

begin_comment
comment|/* Segment flipping.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|internal_aouthdr
name|aouthdr
decl_stmt|;
comment|/* a.out header */
name|struct
name|internal_filehdr
name|filehdr
decl_stmt|;
comment|/* File header, not machine dep.  */
name|long
name|string_table_size
decl_stmt|;
comment|/* names + '\0' + sizeof (int) */
name|long
name|relocation_size
decl_stmt|;
comment|/* Cumulated size of relocation 					   information for all sections in 					   bytes.  */
name|long
name|lineno_size
decl_stmt|;
comment|/* Size of the line number information 					   table in bytes.  */
block|}
name|object_headers
typedef|;
end_typedef

begin_struct
struct|struct
name|lineno_list
block|{
name|struct
name|bfd_internal_lineno
name|line
decl_stmt|;
name|char
modifier|*
name|frag
decl_stmt|;
comment|/* Frag to which the line number is related.  */
name|struct
name|lineno_list
modifier|*
name|next
decl_stmt|;
comment|/* Forward chain pointer.  */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|obj_segment_name
parameter_list|(
name|i
parameter_list|)
value|(segment_info[(int) (i)].scnhdr.s_name)
end_define

begin_define
define|#
directive|define
name|obj_add_segment
parameter_list|(
name|s
parameter_list|)
value|obj_coff_add_segment (s)
end_define

begin_decl_stmt
specifier|extern
name|segT
name|obj_coff_add_segment
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|obj_coff_section
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|c_dot_file_symbol
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|obj_app_file
value|c_dot_file_symbol
end_define

begin_decl_stmt
specifier|extern
name|void
name|obj_extra_stuff
name|PARAMS
argument_list|(
operator|(
name|object_headers
operator|*
name|headers
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|segT
name|s_get_segment
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
name|ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|c_section_header
name|PARAMS
argument_list|(
operator|(
expr|struct
name|internal_scnhdr
operator|*
name|header
operator|,
name|char
operator|*
name|name
operator|,
name|long
name|core_address
operator|,
name|long
name|size
operator|,
name|long
name|data_ptr
operator|,
name|long
name|reloc_ptr
operator|,
name|long
name|lineno_ptr
operator|,
name|long
name|reloc_number
operator|,
name|long
name|lineno_number
operator|,
name|long
name|alignment
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|tc_coff_symbol_emit_hook
end_ifndef

begin_decl_stmt
name|void
name|tc_coff_symbol_emit_hook
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sanity check.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_I960
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|C_LEAFSTAT
end_ifndef

begin_expr_stmt
name|hey
operator|!
name|Where
name|is
name|the
name|C_LEAFSTAT
name|definition
condition|?
name|i960
operator|-
name|coff
name|support
name|is
name|depending
name|on
name|it
operator|.
endif|#
directive|endif
comment|/* no C_LEAFSTAT */
endif|#
directive|endif
comment|/* TC_I960 */
expr|extern struct
name|internal_scnhdr
name|data_section_header
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|internal_scnhdr
name|text_section_header
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Forward the segment of a forwarded symbol.  */
end_comment

begin_define
define|#
directive|define
name|OBJ_COPY_SYMBOL_ATTRIBUTES
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
define|\
value|(SF_GET_GET_SEGMENT (dest) \    ? (S_SET_SEGMENT (dest, S_GET_SEGMENT (src)), 0) \    : 0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TE_PE
end_ifdef

begin_define
define|#
directive|define
name|obj_handle_link_once
parameter_list|(
name|t
parameter_list|)
value|obj_coff_pe_handle_link_once (t)
end_define

begin_function_decl
specifier|extern
name|void
name|obj_coff_pe_handle_link_once
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not BFD_ASSEMBLER */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|pseudo_typeS
name|coff_pseudo_table
index|[]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|obj_pop_insert
end_ifndef

begin_define
define|#
directive|define
name|obj_pop_insert
parameter_list|()
value|pop_insert (coff_pseudo_table)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In COFF, if a symbol is defined using .def/.val SYM/.endef, it's OK    to redefine the symbol later on.  This can happen if C symbols use    a prefix, and a symbol is defined both with and without the prefix,    as in start/_start/__start in gcc/libgcc1-test.c.  */
end_comment

begin_define
define|#
directive|define
name|RESOLVE_SYMBOL_REDEFINITION
parameter_list|(
name|sym
parameter_list|)
define|\
value|(SF_GET_GET_SEGMENT (sym)				\  ? (sym->sy_frag = frag_now,				\     S_SET_VALUE (sym, frag_now_fix ()),			\     S_SET_SEGMENT (sym, now_seg),			\     0)							\  : 0)
end_define

begin_comment
comment|/* Stabs in a coff file go into their own section.  */
end_comment

begin_define
define|#
directive|define
name|SEPARATE_STAB_SECTIONS
value|1
end_define

begin_comment
comment|/* We need 12 bytes at the start of the section to hold some initial    information.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|obj_coff_init_stab_section
name|PARAMS
argument_list|(
operator|(
name|segT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|INIT_STAB_SECTION
parameter_list|(
name|seg
parameter_list|)
value|obj_coff_init_stab_section (seg)
end_define

begin_comment
comment|/* Store the number of relocations in the section aux entry.  */
end_comment

begin_define
define|#
directive|define
name|SET_SECTION_RELOCS
parameter_list|(
name|sec
parameter_list|,
name|relocs
parameter_list|,
name|n
parameter_list|)
define|\
value|SA_SET_SCN_NRELOC (section_symbol (sec), n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJ_FORMAT_H */
end_comment

end_unit

