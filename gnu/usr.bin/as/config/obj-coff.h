begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* coff object file format    Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|OBJ_COFF
value|1
end_define

begin_include
include|#
directive|include
file|"targ-cpu.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_HEADERS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TC_A29K
end_ifdef

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"coff/a29k.h"
end_include

begin_comment
comment|/* This internal_lineno crap is to stop namespace pollution from the bfd internal    coff headerfile. */
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
comment|/*   #undef RELOC   #undef SYMENT   #undef AUXENT   #undef LINENO   #undef FILHDR   #undef SCNHDR   #define RELOC struct internal_reloc   #define SYMENT struct internal_syment   #define AUXENT union internal_auxent   #define SCNHDR struct internal_scnhdr   #define LINENO struct bfd_internal_lineno   #define AOUTHDR struct internal_aouthdr   #define FILHDR struct internal_filehdr   #define AOUTHDRSZ sizeof(struct external_aouthdr)   */
end_comment

begin_comment
comment|/*#define x_endndx x_endndx.l   #define x_tagndx x_tagndx.l*/
end_comment

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-a29k-big"
end_define

begin_decl_stmt
specifier|extern
name|bfd
modifier|*
name|stdoutput
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not TC_A29K */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_I386
end_ifdef

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"coff/i386.h"
end_include

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

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-i386"
end_define

begin_decl_stmt
specifier|extern
name|bfd
modifier|*
name|stdoutput
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not TC_I386 */
end_comment

begin_error
error|#
directive|error
error|help me
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not TC_I386 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not TC_A29K */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not BFD_HEADERS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_NATIVE_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|<filehdr.h>
end_include

begin_include
include|#
directive|include
file|<aouthdr.h>
end_include

begin_include
include|#
directive|include
file|<scnhdr.h>
end_include

begin_include
include|#
directive|include
file|<storclass.h>
end_include

begin_include
include|#
directive|include
file|<linenum.h>
end_include

begin_include
include|#
directive|include
file|<syms.h>
end_include

begin_include
include|#
directive|include
file|<reloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not USE_NATIVE_HEADERS */
end_comment

begin_include
include|#
directive|include
file|"coff.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not USE_NATIVE_HEADERS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not BFD_HEADERS */
end_comment

begin_comment
comment|/* Define some processor dependent values according to the processor we are on. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_M68K
end_ifdef

begin_define
define|#
directive|define
name|BYTE_ORDERING
value|F_AR32W
end_define

begin_comment
comment|/* See filehdr.h for more info. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILE_HEADER_MAGIC
end_ifndef

begin_define
define|#
directive|define
name|FILE_HEADER_MAGIC
value|MC68MAGIC
end_define

begin_comment
comment|/* ... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FILE_HEADER_MAGIC */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|TC_I386
argument_list|)
end_elif

begin_define
define|#
directive|define
name|BYTE_ORDERING
value|F_AR32WR
end_define

begin_comment
comment|/* See filehdr.h for more info. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILE_HEADER_MAGIC
end_ifndef

begin_define
define|#
directive|define
name|FILE_HEADER_MAGIC
value|I386MAGIC
end_define

begin_comment
comment|/* ... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FILE_HEADER_MAGIC */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|TC_I960
argument_list|)
end_elif

begin_define
define|#
directive|define
name|BYTE_ORDERING
value|F_AR32WR
end_define

begin_comment
comment|/* See filehdr.h for more info. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILE_HEADER_MAGIC
end_ifndef

begin_define
define|#
directive|define
name|FILE_HEADER_MAGIC
value|I960ROMAGIC
end_define

begin_comment
comment|/* ... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FILE_HEADER_MAGIC */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|TC_A29K
argument_list|)
end_elif

begin_define
define|#
directive|define
name|BYTE_ORDERING
value|F_AR32W
end_define

begin_comment
comment|/* big endian. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILE_HEADER_MAGIC
end_ifndef

begin_define
define|#
directive|define
name|FILE_HEADER_MAGIC
value|SIPFBOMAGIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FILE_HEADER_MAGIC */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|you
name|lose
endif|#
directive|endif
ifndef|#
directive|ifndef
name|OBJ_COFF_MAX_AUXENTRIES
define|#
directive|define
name|OBJ_COFF_MAX_AUXENTRIES
value|1
endif|#
directive|endif
comment|/* OBJ_COFF_MAX_AUXENTRIES */
specifier|extern
specifier|const
name|short
name|seg_N_TYPE
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|segT
name|N_TYPE_seg
index|[]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_HEADERS
end_ifndef

begin_comment
comment|/* Add these definitions to have a consistent convention for all the    types used in COFF format. */
end_comment

begin_define
define|#
directive|define
name|AOUTHDR
value|struct aouthdr
end_define

begin_define
define|#
directive|define
name|AOUTHDRSZ
value|sizeof(AOUTHDR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYMBOL TABLE */
end_comment

begin_comment
comment|/* targets may also set this */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYMBOLS_NEED_BACKPOINTERS
end_ifndef

begin_define
define|#
directive|define
name|SYMBOLS_NEED_BACKPOINTERS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYMBOLS_NEED_BACKPOINTERS */
end_comment

begin_comment
comment|/* Symbol table entry data type */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
ifdef|#
directive|ifdef
name|BFD_HEADERS
name|struct
name|internal_syment
name|ost_entry
decl_stmt|;
comment|/* Basic symbol */
name|union
name|internal_auxent
name|ost_auxent
index|[
name|OBJ_COFF_MAX_AUXENTRIES
index|]
decl_stmt|;
comment|/* Auxiliary entry. */
else|#
directive|else
name|SYMENT
name|ost_entry
decl_stmt|;
comment|/* Basic symbol */
name|AUXENT
name|ost_auxent
index|[
name|OBJ_COFF_MAX_AUXENTRIES
index|]
decl_stmt|;
comment|/* Auxiliary entry. */
endif|#
directive|endif
name|unsigned
name|int
name|ost_flags
decl_stmt|;
comment|/* obj_coff internal use only flags */
block|}
name|obj_symbol_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DO_NOT_STRIP
value|0
end_define

begin_define
define|#
directive|define
name|DO_STRIP
value|1
end_define

begin_comment
comment|/* Symbol table macros and constants */
end_comment

begin_comment
comment|/* Possible and usefull section number in symbol table  * The values of TEXT, DATA and BSS may not be portable.  */
end_comment

begin_define
define|#
directive|define
name|C_TEXT_SECTION
value|((short)1)
end_define

begin_define
define|#
directive|define
name|C_DATA_SECTION
value|((short)2)
end_define

begin_define
define|#
directive|define
name|C_BSS_SECTION
value|((short)3)
end_define

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
value|4
end_define

begin_comment
comment|/*  *  Macros to extract information from a symbol table entry.  *  This syntaxic indirection allows independence regarding a.out or coff.  *  The argument (s) of all these macros is a pointer to a symbol table entry.  */
end_comment

begin_comment
comment|/* Predicates */
end_comment

begin_comment
comment|/* True if the symbol is external */
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
comment|/* True if symbol has been defined, ie :    section> 0 (DATA, TEXT or BSS)    section == 0 and value> 0 (external bss symbol) */
end_comment

begin_define
define|#
directive|define
name|S_IS_DEFINED
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_scnum> C_UNDEF_SECTION || \ 				 ((s)->sy_symbol.ost_entry.n_scnum == C_UNDEF_SECTION&& \ 				  (s)->sy_symbol.ost_entry.n_value> 0))
end_define

begin_comment
comment|/* True if a debug special symbol entry */
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
comment|/* True if a symbol is local symbol name */
end_comment

begin_comment
comment|/* A symbol name whose name begin with ^A is a gas internal pseudo symbol */
end_comment

begin_define
define|#
directive|define
name|S_IS_LOCAL
parameter_list|(
name|s
parameter_list|)
value|(S_GET_NAME(s)[0] == '\001' || \ 				 (s)->sy_symbol.ost_entry.n_scnum == C_REGISTER_SECTION || \ 				 (S_LOCAL_NAME(s)&& !flagseen['L']))
end_define

begin_comment
comment|/* True if a symbol is not defined in this file */
end_comment

begin_define
define|#
directive|define
name|S_IS_EXTERN
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_scnum == 0&& (s)->sy_symbol.ost_entry.n_value == 0)
end_define

begin_comment
comment|/*  * True if a symbol can be multiply defined (bss symbols have this def  * though it is bad practice)  */
end_comment

begin_define
define|#
directive|define
name|S_IS_COMMON
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_scnum == 0&& (s)->sy_symbol.ost_entry.n_value != 0)
end_define

begin_comment
comment|/* True if a symbol name is in the string table, i.e. its length is> 8. */
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
comment|/* Accessors */
end_comment

begin_comment
comment|/* The name of the symbol */
end_comment

begin_define
define|#
directive|define
name|S_GET_NAME
parameter_list|(
name|s
parameter_list|)
value|((char*)(s)->sy_symbol.ost_entry.n_offset)
end_define

begin_comment
comment|/* The pointer to the string table */
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
comment|/* The zeroes if symbol name is longer than 8 chars */
end_comment

begin_define
define|#
directive|define
name|S_GET_ZEROES
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_zeroes)
end_define

begin_comment
comment|/* The value of the symbol */
end_comment

begin_define
define|#
directive|define
name|S_GET_VALUE
parameter_list|(
name|s
parameter_list|)
value|((unsigned) ((s)->sy_symbol.ost_entry.n_value))
end_define

begin_comment
comment|/* The numeric value of the segment */
end_comment

begin_define
define|#
directive|define
name|S_GET_SEGMENT
parameter_list|(
name|s
parameter_list|)
value|(N_TYPE_seg[(s)->sy_symbol.ost_entry.n_scnum+4])
end_define

begin_comment
comment|/* The data type */
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
comment|/* The storage class */
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
comment|/* The number of auxiliary entries */
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
comment|/* Modifiers */
end_comment

begin_comment
comment|/* Set the name of the symbol */
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
value|((s)->sy_symbol.ost_entry.n_offset = (unsigned long)(v))
end_define

begin_comment
comment|/* Set the offset of the symbol */
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
comment|/* The zeroes if symbol name is longer than 8 chars */
end_comment

begin_define
define|#
directive|define
name|S_SET_ZEROES
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_zeroes = (v))
end_define

begin_comment
comment|/* Set the value of the symbol */
end_comment

begin_define
define|#
directive|define
name|S_SET_VALUE
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.ost_entry.n_value = (v))
end_define

begin_comment
comment|/* The numeric value of the segment */
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
comment|/* The data type */
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
comment|/* The storage class */
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
comment|/* The number of auxiliary entries */
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
comment|/* Additional modifiers */
end_comment

begin_comment
comment|/* The symbol is external (does not mean undefined) */
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
comment|/* Auxiliary entry macros. SA_ stands for symbol auxiliary */
end_comment

begin_comment
comment|/* Omit the tv related fields */
end_comment

begin_comment
comment|/* Accessors */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_HEADERS
end_ifdef

begin_define
define|#
directive|define
name|SA_GET_SYM_TAGNDX
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_tagndx.l)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SA_GET_SYM_TAGNDX
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_tagndx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SA_GET_SYM_LNNO
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_misc.x_lnsz.x_lnno)
end_define

begin_define
define|#
directive|define
name|SA_GET_SYM_SIZE
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_misc.x_lnsz.x_size)
end_define

begin_define
define|#
directive|define
name|SA_GET_SYM_FSIZE
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_misc.x_fsize)
end_define

begin_define
define|#
directive|define
name|SA_GET_SYM_LNNOPTR
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_fcnary.x_fcn.x_lnnoptr)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_HEADERS
end_ifdef

begin_define
define|#
directive|define
name|SA_GET_SYM_ENDNDX
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_fcnary.x_fcn.x_endndx.l)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SA_GET_SYM_ENDNDX
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_fcnary.x_fcn.x_endndx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SA_GET_SYM_DIMEN
parameter_list|(
name|s
parameter_list|,
name|i
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_fcnary.x_ary.x_dimen[(i)])
end_define

begin_define
define|#
directive|define
name|SA_GET_FILE_FNAME
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_file.x_fname)
end_define

begin_define
define|#
directive|define
name|SA_GET_SCN_SCNLEN
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_scn.x_scnlen)
end_define

begin_define
define|#
directive|define
name|SA_GET_SCN_NRELOC
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_scn.x_nreloc)
end_define

begin_define
define|#
directive|define
name|SA_GET_SCN_NLINNO
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_scn.x_nlinno)
end_define

begin_comment
comment|/* Modifiers */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_HEADERS
end_ifdef

begin_define
define|#
directive|define
name|SA_SET_SYM_TAGNDX
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_tagndx.l=(v))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SA_SET_SYM_TAGNDX
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_tagndx=(v))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SA_SET_SYM_LNNO
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_misc.x_lnsz.x_lnno=(v))
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
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_misc.x_lnsz.x_size=(v))
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
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_misc.x_fsize=(v))
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
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_fcnary.x_fcn.x_lnnoptr=(v))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_HEADERS
end_ifdef

begin_define
define|#
directive|define
name|SA_SET_SYM_ENDNDX
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_fcnary.x_fcn.x_endndx.l=(v))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SA_SET_SYM_ENDNDX
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_fcnary.x_fcn.x_endndx=(v))
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|((s)->sy_symbol.ost_auxent[0].x_sym.x_fcnary.x_ary.x_dimen[(i)]=(v))
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
value|strncpy((s)->sy_symbol.ost_auxent[0].x_file.x_fname,(v),FILNMLEN)
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
value|((s)->sy_symbol.ost_auxent[0].x_scn.x_scnlen=(v))
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
value|((s)->sy_symbol.ost_auxent[0].x_scn.x_nreloc=(v))
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
value|((s)->sy_symbol.ost_auxent[0].x_scn.x_nlinno=(v))
end_define

begin_comment
comment|/*  * Internal use only definitions. SF_ stands for symbol flags.  *  * These values can be assigned to sy_symbol.ost_flags field of a symbolS.  *  * You'll break i960 if you shift the SYSPROC bits anywhere else.  for  * more on the balname/callname hack, see tc-i960.h.  b.out is done  * differently.  */
end_comment

begin_define
define|#
directive|define
name|SF_I960_MASK
value|(0x000001ff)
end_define

begin_comment
comment|/* Bits 0-8 are used by the i960 port. */
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
comment|/* bits 12-15 are general purpose. */
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
comment|/* Get the section of the forward symbol. */
end_comment

begin_comment
comment|/* All other bits are unused. */
end_comment

begin_comment
comment|/* Accessors */
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
value|((s)->sy_symbol.ost_flags& SF_NORMAL_MASK)
end_define

begin_define
define|#
directive|define
name|SF_GET_DEBUG_FIELD
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags& SF_DEBUG_MASK)
end_define

begin_define
define|#
directive|define
name|SF_GET_FILE
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags& SF_FILE)
end_define

begin_define
define|#
directive|define
name|SF_GET_STATICS
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags& SF_STATICS)
end_define

begin_define
define|#
directive|define
name|SF_GET_DEFINED
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags& SF_DEFINED)
end_define

begin_define
define|#
directive|define
name|SF_GET_STRING
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags& SF_STRING)
end_define

begin_define
define|#
directive|define
name|SF_GET_LOCAL
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags& SF_LOCAL)
end_define

begin_define
define|#
directive|define
name|SF_GET_FUNCTION
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags& SF_FUNCTION)
end_define

begin_define
define|#
directive|define
name|SF_GET_PROCESS
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags& SF_PROCESS)
end_define

begin_define
define|#
directive|define
name|SF_GET_DEBUG
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags& SF_DEBUG)
end_define

begin_define
define|#
directive|define
name|SF_GET_TAGGED
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags& SF_TAGGED)
end_define

begin_define
define|#
directive|define
name|SF_GET_TAG
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags& SF_TAG)
end_define

begin_define
define|#
directive|define
name|SF_GET_GET_SEGMENT
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags& SF_GET_SEGMENT)
end_define

begin_define
define|#
directive|define
name|SF_GET_I960
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags& SF_I960_MASK)
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
value|((s)->sy_symbol.ost_flags& SF_BALNAME)
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
value|((s)->sy_symbol.ost_flags& SF_CALLNAME)
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
value|((s)->sy_symbol.ost_flags& SF_IS_SYSPROC)
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
value|((s)->sy_symbol.ost_flags& SF_SYSPROC)
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_comment
comment|/* Modifiers */
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
value|((s)->sy_symbol.ost_flags = (v))
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
value|((s)->sy_symbol.ost_flags |= ((v)& SF_NORMAL_MASK))
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
value|((s)->sy_symbol.ost_flags |= ((v)& SF_DEBUG_MASK))
end_define

begin_define
define|#
directive|define
name|SF_SET_FILE
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags |= SF_FILE)
end_define

begin_define
define|#
directive|define
name|SF_SET_STATICS
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags |= SF_STATICS)
end_define

begin_define
define|#
directive|define
name|SF_SET_DEFINED
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags |= SF_DEFINED)
end_define

begin_define
define|#
directive|define
name|SF_SET_STRING
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags |= SF_STRING)
end_define

begin_define
define|#
directive|define
name|SF_SET_LOCAL
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags |= SF_LOCAL)
end_define

begin_define
define|#
directive|define
name|SF_CLEAR_LOCAL
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags&= ~SF_LOCAL)
end_define

begin_define
define|#
directive|define
name|SF_SET_FUNCTION
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags |= SF_FUNCTION)
end_define

begin_define
define|#
directive|define
name|SF_SET_PROCESS
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags |= SF_PROCESS)
end_define

begin_define
define|#
directive|define
name|SF_SET_DEBUG
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags |= SF_DEBUG)
end_define

begin_define
define|#
directive|define
name|SF_SET_TAGGED
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags |= SF_TAGGED)
end_define

begin_define
define|#
directive|define
name|SF_SET_TAG
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags |= SF_TAG)
end_define

begin_define
define|#
directive|define
name|SF_SET_GET_SEGMENT
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_flags |= SF_GET_SEGMENT)
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
value|((s)->sy_symbol.ost_flags |= ((v)& SF_I960_MASK))
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
value|((s)->sy_symbol.ost_flags |= SF_BALNAME)
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
value|((s)->sy_symbol.ost_flags |= SF_CALLNAME)
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
value|((s)->sy_symbol.ost_flags |= SF_IS_SYSPROC)
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
value|((s)->sy_symbol.ost_flags |= ((v)& SF_SYSPROC))
end_define

begin_comment
comment|/* used by i960 */
end_comment

begin_comment
comment|/* File header macro and type definition */
end_comment

begin_comment
comment|/*  * File position calculators. Beware to use them when all the  * appropriate fields are set in the header.  */
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
value|(long)(FILHSZ + OBJ_COFF_AOUTHDRSZ + \ 	   H_GET_NUMBER_OF_SECTIONS(h) * SCNHSZ + \ 	   H_GET_TEXT_SIZE(h) + H_GET_DATA_SIZE(h) + \ 	   H_GET_RELOCATION_SIZE(h) + H_GET_LINENO_SIZE(h) + \ 	   H_GET_SYMBOL_TABLE_SIZE(h) + \ 	   (h)->string_table_size)
end_define

begin_define
define|#
directive|define
name|H_GET_TEXT_FILE_OFFSET
parameter_list|(
name|h
parameter_list|)
define|\
value|(long)(FILHSZ + OBJ_COFF_AOUTHDRSZ + \ 	   H_GET_NUMBER_OF_SECTIONS(h) * SCNHSZ)
end_define

begin_define
define|#
directive|define
name|H_GET_DATA_FILE_OFFSET
parameter_list|(
name|h
parameter_list|)
define|\
value|(long)(FILHSZ + OBJ_COFF_AOUTHDRSZ + \ 	   H_GET_NUMBER_OF_SECTIONS(h) * SCNHSZ + \ 	   H_GET_TEXT_SIZE(h))
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
value|(long)(FILHSZ + OBJ_COFF_AOUTHDRSZ + \ 	   H_GET_NUMBER_OF_SECTIONS(h) * SCNHSZ + \ 	   H_GET_TEXT_SIZE(h) + H_GET_DATA_SIZE(h))
end_define

begin_define
define|#
directive|define
name|H_GET_LINENO_FILE_OFFSET
parameter_list|(
name|h
parameter_list|)
define|\
value|(long)(FILHSZ + OBJ_COFF_AOUTHDRSZ + \ 	   H_GET_NUMBER_OF_SECTIONS(h) * SCNHSZ + \ 	   H_GET_TEXT_SIZE(h) + H_GET_DATA_SIZE(h) + \ 	   H_GET_RELOCATION_SIZE(h))
end_define

begin_define
define|#
directive|define
name|H_GET_SYMBOL_TABLE_FILE_OFFSET
parameter_list|(
name|h
parameter_list|)
define|\
value|(long)(FILHSZ + OBJ_COFF_AOUTHDRSZ + \ 	   H_GET_NUMBER_OF_SECTIONS(h) * SCNHSZ + \ 	   H_GET_TEXT_SIZE(h) + H_GET_DATA_SIZE(h) + \ 	   H_GET_RELOCATION_SIZE(h) + H_GET_LINENO_SIZE(h))
end_define

begin_comment
comment|/* Accessors */
end_comment

begin_comment
comment|/* aouthdr */
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
comment|/* filehdr */
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
comment|/* Extra fields to achieve bsd a.out compatibility and for convenience */
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
value|(sizeof(FILHDR) \ 					 + sizeof(AOUTHDR)\ 					 + (H_GET_NUMBER_OF_SECTIONS(h) * SCNHSZ))
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
value|(sizeof(FILHDR) \ 					 + (H_GET_NUMBER_OF_SECTIONS(h) * SCNHSZ))
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
comment|/* Modifiers */
end_comment

begin_comment
comment|/* aouthdr */
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
comment|/* filehdr */
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
comment|/* Extra fields to achieve bsd a.out compatibility and for convinience */
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
comment|/* Segment flipping */
end_comment

begin_define
define|#
directive|define
name|segment_name
parameter_list|(
name|v
parameter_list|)
value|(seg_name[(int) (v)])
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
ifdef|#
directive|ifdef
name|BFD_HEADERS
name|struct
name|internal_aouthdr
name|aouthdr
decl_stmt|;
comment|/* a.out header */
name|struct
name|internal_filehdr
name|filehdr
decl_stmt|;
comment|/* File header, not machine dep. */
else|#
directive|else
name|AOUTHDR
name|aouthdr
decl_stmt|;
comment|/* a.out header */
name|FILHDR
name|filehdr
decl_stmt|;
comment|/* File header, not machine dep. */
endif|#
directive|endif
name|long
name|string_table_size
decl_stmt|;
comment|/* names + '\0' + sizeof(int) */
name|long
name|relocation_size
decl_stmt|;
comment|/* Cumulated size of relocation 					   information for all sections in 					   bytes. */
name|long
name|lineno_size
decl_stmt|;
comment|/* Size of the line number information 					   table in bytes */
block|}
name|object_headers
typedef|;
end_typedef

begin_comment
comment|/* --------------  Line number handling ------- */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|text_lineno_number
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line numbering stuff. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|internal_lineno
block|{
ifdef|#
directive|ifdef
name|BFD_HEADERS
name|struct
name|bfd_internal_lineno
name|line
decl_stmt|;
else|#
directive|else
name|LINENO
name|line
decl_stmt|;
comment|/* The lineno structure itself */
endif|#
directive|endif
name|char
modifier|*
name|frag
decl_stmt|;
comment|/* Frag to which the line number is related */
name|struct
name|internal_lineno
modifier|*
name|next
decl_stmt|;
comment|/* Forward chain pointer */
block|}
name|lineno
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|lineno
modifier|*
name|lineno_lastP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|lineno
modifier|*
name|lineno_rootP
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|OBJ_EMIT_LINENO
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|obj_emit_lineno((a),(b),(c))
end_define

begin_if
if|#
directive|if
name|__STDC__
operator|==
literal|1
end_if

begin_function_decl
name|void
name|obj_emit_lineno
parameter_list|(
name|char
modifier|*
modifier|*
name|where
parameter_list|,
name|lineno
modifier|*
name|line
parameter_list|,
name|char
modifier|*
name|file_start
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_function_decl
name|void
name|obj_emit_lineno
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ */
end_comment

begin_comment
comment|/* stack stuff */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|chunk_size
decl_stmt|;
name|unsigned
name|long
name|element_size
decl_stmt|;
name|unsigned
name|long
name|size
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
name|unsigned
name|long
name|pointer
decl_stmt|;
block|}
name|stack
typedef|;
end_typedef

begin_if
if|#
directive|if
name|__STDC__
operator|==
literal|1
end_if

begin_function_decl
name|char
modifier|*
name|stack_pop
parameter_list|(
name|stack
modifier|*
name|st
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|stack_push
parameter_list|(
name|stack
modifier|*
name|st
parameter_list|,
name|char
modifier|*
name|element
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|stack_top
parameter_list|(
name|stack
modifier|*
name|st
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|stack
modifier|*
name|stack_init
parameter_list|(
name|unsigned
name|long
name|chunk_size
parameter_list|,
name|unsigned
name|long
name|element_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|c_dot_file_symbol
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obj_extra_stuff
parameter_list|(
name|object_headers
modifier|*
name|headers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stack_delete
parameter_list|(
name|stack
modifier|*
name|st
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|tc_headers_hook
end_ifndef

begin_function_decl
name|void
name|tc_headers_hook
parameter_list|(
name|object_headers
modifier|*
name|headers
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tc_headers_hook */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|tc_coff_symbol_emit_hook
end_ifndef

begin_function_decl
name|void
name|tc_coff_symbol_emit_hook
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* really tc_coff_symbol_emit_hook(symbolS *symbolP) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tc_coff_symbol_emit_hook */
end_comment

begin_function_decl
name|void
name|c_section_header
parameter_list|(
ifdef|#
directive|ifdef
name|BFD_HEADERS
name|struct
name|internal_scnhdr
modifier|*
name|header
parameter_list|,
else|#
directive|else
name|SCNHDR
modifier|*
name|header
parameter_list|,
endif|#
directive|endif
name|char
modifier|*
name|name
parameter_list|,
name|long
name|core_address
parameter_list|,
name|long
name|size
parameter_list|,
name|long
name|data_ptr
parameter_list|,
name|long
name|reloc_ptr
parameter_list|,
name|long
name|lineno_ptr
parameter_list|,
name|long
name|reloc_number
parameter_list|,
name|long
name|lineno_number
parameter_list|,
name|long
name|alignment
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_function_decl
name|char
modifier|*
name|stack_pop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|stack_push
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|stack_top
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|stack
modifier|*
name|stack_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|c_dot_file_symbol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|c_section_header
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obj_extra_stuff
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stack_delete
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tc_headers_hook
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tc_coff_symbol_emit_hook
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ */
end_comment

begin_comment
comment|/* sanity check */
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
ifdef|#
directive|ifdef
name|BFD_HEADERS
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

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|SCNHDR
name|data_section_header
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SCNHDR
name|text_section_header
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of obj-coff.h */
end_comment

end_unit

