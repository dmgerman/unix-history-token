begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is aout_gnu.h     Copyright (C) 1987-1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__A_OUT_GNU_H__
end_ifndef

begin_define
define|#
directive|define
name|__A_OUT_GNU_H__
end_define

begin_comment
comment|/* There are two main flavours of a.out, one which uses the standard    relocations, and one which uses extended relocations.     Today, the extended reloc uses are    TC_SPARC, TC_A29K     each must define the enum reloc_type  */
end_comment

begin_define
define|#
directive|define
name|USE_EXTENDED_RELOC
value|(defined(TC_SPARC) || defined(TC_A29K))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TC_SPARC
argument_list|)
operator|||
name|defined
argument_list|(
name|TC_A29K
argument_list|)
end_if

begin_enum
enum|enum
name|reloc_type
block|{
name|RELOC_8
block|,
name|RELOC_16
block|,
name|RELOC_32
block|,
comment|/* simple relocations */
name|RELOC_DISP8
block|,
name|RELOC_DISP16
block|,
name|RELOC_DISP32
block|,
comment|/* pc-rel displacement */
name|RELOC_WDISP30
block|,
name|RELOC_WDISP22
block|,
name|RELOC_HI22
block|,
name|RELOC_22
block|,
name|RELOC_13
block|,
name|RELOC_LO10
block|,
name|RELOC_SFA_BASE
block|,
name|RELOC_SFA_OFF13
block|,
name|RELOC_BASE10
block|,
name|RELOC_BASE13
block|,
name|RELOC_BASE22
block|,
comment|/* P.I.C. (base-relative) */
name|RELOC_PC10
block|,
name|RELOC_PC22
block|,
comment|/* for some sort of pc-rel P.I.C. (?) */
name|RELOC_JMP_TBL
block|,
comment|/* P.I.C. jump table */
name|RELOC_SEGOFF16
block|,
comment|/* reputedly for shared libraries somehow */
name|RELOC_GLOB_DAT
block|,
name|RELOC_JMP_SLOT
block|,
name|RELOC_RELATIVE
block|,
name|RELOC_10
block|,
name|RELOC_11
block|,
name|RELOC_WDISP2_14
block|,
name|RELOC_WDISP19
block|,
name|RELOC_HHI22
block|,
name|RELOC_HLO10
block|,
comment|/* 29K relocation types */
name|RELOC_JUMPTARG
block|,
name|RELOC_CONST
block|,
name|RELOC_CONSTH
block|,
name|RELOC_WDISP14
block|,
name|RELOC_WDISP21
block|,
name|NO_RELOC
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_SPARC or TC_A29K */
end_comment

begin_define
define|#
directive|define
name|__GNU_EXEC_MACROS__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__STRUCT_EXEC_OVERRIDE__
end_ifndef

begin_comment
comment|/* This is the layout on disk of a Unix V7, Berkeley, SunOS, Vax Ultrix    "struct exec".  Don't assume that on this machine, the "struct exec"    will lay out the same sizes or alignments.  */
end_comment

begin_struct
struct|struct
name|exec_bytes
block|{
name|unsigned
name|char
name|a_info
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_text
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_data
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_bss
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_syms
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_entry
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_trsize
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_drsize
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* How big the "struct exec" is on disk */
end_comment

begin_define
define|#
directive|define
name|EXEC_BYTES_SIZE
value|(8 * 4)
end_define

begin_comment
comment|/* This is the layout in memory of a "struct exec" while we process it.  */
end_comment

begin_struct
struct|struct
name|exec
block|{
name|unsigned
name|long
name|a_info
decl_stmt|;
comment|/* Use macros N_MAGIC, etc for access */
name|unsigned
name|a_text
decl_stmt|;
comment|/* length of text, in bytes */
name|unsigned
name|a_data
decl_stmt|;
comment|/* length of data, in bytes */
name|unsigned
name|a_bss
decl_stmt|;
comment|/* length of uninitialized data area for file, in bytes */
name|unsigned
name|a_syms
decl_stmt|;
comment|/* length of symbol table data in file, in bytes */
name|unsigned
name|a_entry
decl_stmt|;
comment|/* start address */
name|unsigned
name|a_trsize
decl_stmt|;
comment|/* length of relocation info for text, in bytes */
name|unsigned
name|a_drsize
decl_stmt|;
comment|/* length of relocation info for data, in bytes */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STRUCT_EXEC_OVERRIDE__ */
end_comment

begin_comment
comment|/* these go in the N_MACHTYPE field */
end_comment

begin_comment
comment|/* These symbols could be defined by code from Suns...punt 'em */
end_comment

begin_undef
undef|#
directive|undef
name|M_UNKNOWN
end_undef

begin_undef
undef|#
directive|undef
name|M_68010
end_undef

begin_undef
undef|#
directive|undef
name|M_68020
end_undef

begin_undef
undef|#
directive|undef
name|M_SPARC
end_undef

begin_enum
enum|enum
name|machine_type
block|{
name|M_UNKNOWN
init|=
literal|0
block|,
name|M_68010
init|=
literal|1
block|,
name|M_68020
init|=
literal|2
block|,
name|M_SPARC
init|=
literal|3
block|,
comment|/* skip a bunch so we don't run into any of sun's numbers */
name|M_386
init|=
literal|100
block|,
name|M_29K
init|=
literal|101
block|,
name|M_RS6000
init|=
literal|102
block|,
comment|/* IBM RS/6000 */
comment|/* HP/BSD formats */
name|M_HP200
init|=
literal|200
block|,
comment|/* hp200 (68010) BSD binary */
name|M_HP300
init|=
literal|300
block|,
comment|/* hp300 (68020+68881) BSD binary */
name|M_HPUX23
init|=
literal|0x020C
comment|/* hp200/300 HPUX binary */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|N_MAGIC
parameter_list|(
name|exec
parameter_list|)
value|((exec).a_info& 0xffff)
end_define

begin_define
define|#
directive|define
name|N_MACHTYPE
parameter_list|(
name|exec
parameter_list|)
value|((enum machine_type)(((exec).a_info>> 16)& 0xff))
end_define

begin_define
define|#
directive|define
name|N_FLAGS
parameter_list|(
name|exec
parameter_list|)
value|(((exec).a_info>> 24)& 0xff)
end_define

begin_define
define|#
directive|define
name|N_SET_INFO
parameter_list|(
name|exec
parameter_list|,
name|magic
parameter_list|,
name|type
parameter_list|,
name|flags
parameter_list|)
define|\
value|((exec).a_info = ((magic)& 0xffff) \      | (((int)(type)& 0xff)<< 16) \      | (((flags)& 0xff)<< 24))
end_define

begin_define
define|#
directive|define
name|N_SET_MAGIC
parameter_list|(
name|exec
parameter_list|,
name|magic
parameter_list|)
define|\
value|((exec).a_info = (((exec).a_info& 0xffff0000) | ((magic)& 0xffff)))
end_define

begin_define
define|#
directive|define
name|N_SET_MACHTYPE
parameter_list|(
name|exec
parameter_list|,
name|machtype
parameter_list|)
define|\
value|((exec).a_info = \      ((exec).a_info&0xff00ffff) | ((((int)(machtype))&0xff)<< 16))
end_define

begin_define
define|#
directive|define
name|N_SET_FLAGS
parameter_list|(
name|exec
parameter_list|,
name|flags
parameter_list|)
define|\
value|((exec).a_info = \      ((exec).a_info&0x00ffffff) | (((flags)& 0xff)<< 24))
end_define

begin_comment
comment|/* Code indicating object file or impure executable.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OMAGIC
end_ifndef

begin_define
define|#
directive|define
name|OMAGIC
value|0407
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Code indicating pure executable.  */
end_comment

begin_define
define|#
directive|define
name|NMAGIC
value|0410
end_define

begin_comment
comment|/* Code indicating demand-paged executable.  */
end_comment

begin_define
define|#
directive|define
name|ZMAGIC
value|0413
end_define

begin_comment
comment|/* Virtual Address of text segment from the a.out file.  For OMAGIC,    (almost always "unlinked .o's" these days), should be zero.    For linked files, should reflect reality if we know it.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_TXTADDR
end_ifndef

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|x
parameter_list|)
value|(N_MAGIC(x)==OMAGIC? 0 : TEXT_START_ADDR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_BADMAG
end_ifndef

begin_define
define|#
directive|define
name|N_BADMAG
parameter_list|(
name|x
parameter_list|)
value|(N_MAGIC(x) != OMAGIC		\&& N_MAGIC(x) != NMAGIC		\&& N_MAGIC(x) != ZMAGIC)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* By default, segment size is constant.  But on some machines, it can    be a function of the a.out header (e.g. machine type).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_SEGSIZE
end_ifndef

begin_define
define|#
directive|define
name|N_SEGSIZE
parameter_list|(
name|x
parameter_list|)
value|SEGMENT_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This complexity is for encapsulated COFF support */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_N_HDROFF
end_ifndef

begin_define
define|#
directive|define
name|_N_HDROFF
parameter_list|(
name|x
parameter_list|)
value|(N_SEGSIZE(x) - sizeof (struct exec))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_TXTOFF
end_ifndef

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|x
parameter_list|)
value|(N_MAGIC(x) == ZMAGIC ?	\ 			 _N_HDROFF((x)) + sizeof (struct exec) :	\ 			 sizeof (struct exec))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_DATOFF
end_ifndef

begin_define
define|#
directive|define
name|N_DATOFF
parameter_list|(
name|x
parameter_list|)
value|( N_TXTOFF(x) + (x).a_text )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_TRELOFF
end_ifndef

begin_define
define|#
directive|define
name|N_TRELOFF
parameter_list|(
name|x
parameter_list|)
value|( N_DATOFF(x) + (x).a_data )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_DRELOFF
end_ifndef

begin_define
define|#
directive|define
name|N_DRELOFF
parameter_list|(
name|x
parameter_list|)
value|( N_TRELOFF(x) + (x).a_trsize )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_SYMOFF
end_ifndef

begin_define
define|#
directive|define
name|N_SYMOFF
parameter_list|(
name|x
parameter_list|)
value|( N_DRELOFF(x) + (x).a_drsize )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_STROFF
end_ifndef

begin_define
define|#
directive|define
name|N_STROFF
parameter_list|(
name|x
parameter_list|)
value|( N_SYMOFF(x) + (x).a_syms )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Address of text segment in memory after it is loaded.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_TXTADDR
end_ifndef

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_DATADDR
end_ifndef

begin_define
define|#
directive|define
name|N_DATADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(N_MAGIC(x)==OMAGIC? (N_TXTADDR(x)+(x).a_text) \      :  (N_SEGSIZE(x) + ((N_TXTADDR(x)+(x).a_text-1)& ~(N_SEGSIZE(x)-1))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Address of bss segment in memory after it is loaded.  */
end_comment

begin_define
define|#
directive|define
name|N_BSSADDR
parameter_list|(
name|x
parameter_list|)
value|(N_DATADDR(x) + (x).a_data)
end_define

begin_escape
end_escape

begin_struct
struct|struct
name|nlist
block|{
union|union
block|{
name|char
modifier|*
name|n_name
decl_stmt|;
name|struct
name|nlist
modifier|*
name|n_next
decl_stmt|;
name|long
name|n_strx
decl_stmt|;
block|}
name|n_un
union|;
name|unsigned
name|char
name|n_type
decl_stmt|;
name|char
name|n_other
decl_stmt|;
name|short
name|n_desc
decl_stmt|;
name|unsigned
name|long
name|n_value
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|N_UNDF
value|0
end_define

begin_define
define|#
directive|define
name|N_ABS
value|2
end_define

begin_define
define|#
directive|define
name|N_TEXT
value|4
end_define

begin_define
define|#
directive|define
name|N_DATA
value|6
end_define

begin_define
define|#
directive|define
name|N_BSS
value|8
end_define

begin_define
define|#
directive|define
name|N_COMM
value|0x12
end_define

begin_comment
comment|/* common (visible in shared lib commons) */
end_comment

begin_define
define|#
directive|define
name|N_FN
value|0x1F
end_define

begin_comment
comment|/* File name of a .o file */
end_comment

begin_comment
comment|/* Note: N_EXT can only usefully be OR-ed with N_UNDF, N_ABS, N_TEXT,    N_DATA, or N_BSS.  When the low-order bit of other types is set,    (e.g. N_WARNING versus N_FN), they are two different types.  */
end_comment

begin_define
define|#
directive|define
name|N_EXT
value|1
end_define

begin_define
define|#
directive|define
name|N_TYPE
value|036
end_define

begin_define
define|#
directive|define
name|N_STAB
value|0340
end_define

begin_comment
comment|/* The following type indicates the definition of a symbol as being    an indirect reference to another symbol.  The other symbol    appears as an undefined reference, immediately following this symbol.     Indirection is asymmetrical.  The other symbol's value will be used    to satisfy requests for the indirect symbol, but not vice versa.    If the other symbol does not have a definition, libraries will    be searched to find a definition.  */
end_comment

begin_define
define|#
directive|define
name|N_INDR
value|0xa
end_define

begin_comment
comment|/* The following symbols refer to set elements.    All the N_SET[ATDB] symbols with the same name form one set.    Space is allocated for the set in the text section, and each set    element's value is stored into one word of the space.    The first word of the space is the length of the set (number of elements).     The address of the set is made into an N_SETV symbol    whose name is the same as the name of the set.    This symbol acts like a N_DATA global symbol    in that it can satisfy undefined external references.  */
end_comment

begin_comment
comment|/* These appear as input to LD, in a .o file.  */
end_comment

begin_define
define|#
directive|define
name|N_SETA
value|0x14
end_define

begin_comment
comment|/* Absolute set element symbol */
end_comment

begin_define
define|#
directive|define
name|N_SETT
value|0x16
end_define

begin_comment
comment|/* Text set element symbol */
end_comment

begin_define
define|#
directive|define
name|N_SETD
value|0x18
end_define

begin_comment
comment|/* Data set element symbol */
end_comment

begin_define
define|#
directive|define
name|N_SETB
value|0x1A
end_define

begin_comment
comment|/* Bss set element symbol */
end_comment

begin_comment
comment|/* This is output from LD.  */
end_comment

begin_define
define|#
directive|define
name|N_SETV
value|0x1C
end_define

begin_comment
comment|/* Pointer to set vector in data area.  */
end_comment

begin_comment
comment|/* Warning symbol. The text gives a warning message, the next symbol    in the table will be undefined. When the symbol is referenced, the    message is printed.  */
end_comment

begin_define
define|#
directive|define
name|N_WARNING
value|0x1e
end_define

begin_comment
comment|/* Weak symbols.  These are a GNU extension to the a.out format.  The    semantics are those of ELF weak symbols.  Weak symbols are always    externally visible.  The N_WEAK? values are squeezed into the    available slots.  The value of a N_WEAKU symbol is 0.  The values    of the other types are the definitions.  */
end_comment

begin_define
define|#
directive|define
name|N_WEAKU
value|0x0d
end_define

begin_comment
comment|/* Weak undefined symbol.  */
end_comment

begin_define
define|#
directive|define
name|N_WEAKA
value|0x0e
end_define

begin_comment
comment|/* Weak absolute symbol.  */
end_comment

begin_define
define|#
directive|define
name|N_WEAKT
value|0x0f
end_define

begin_comment
comment|/* Weak text symbol.  */
end_comment

begin_define
define|#
directive|define
name|N_WEAKD
value|0x10
end_define

begin_comment
comment|/* Weak data symbol.  */
end_comment

begin_define
define|#
directive|define
name|N_WEAKB
value|0x11
end_define

begin_comment
comment|/* Weak bss symbol.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* This structure describes a single relocation to be performed.    The text-relocation section of the file is a vector of these structures,    all of which apply to the text section.    Likewise, the data-relocation section applies to the data section.  */
end_comment

begin_comment
comment|/* The following enum and struct were borrowed from SunOS's    /usr/include/sun4/a.out.h  and extended to handle    other machines.  It is currently used on SPARC and AMD 29000.     reloc_ext_bytes is how it looks on disk.  reloc_info_extended is    how we might process it on a native host.  */
end_comment

begin_if
if|#
directive|if
name|USE_EXTENDED_RELOC
end_if

begin_struct
struct|struct
name|reloc_ext_bytes
block|{
name|unsigned
name|char
name|r_address
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|r_index
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|char
name|r_bits
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|r_addend
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_EXTERN_BIG
value|0x80
end_define

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_EXTERN_LITTLE
value|0x01
end_define

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_TYPE_BIG
value|0x1F
end_define

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_TYPE_SH_BIG
value|0
end_define

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_TYPE_LITTLE
value|0xF8
end_define

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_TYPE_SH_LITTLE
value|3
end_define

begin_define
define|#
directive|define
name|RELOC_EXT_SIZE
value|12
end_define

begin_comment
comment|/* Bytes per relocation entry */
end_comment

begin_struct
struct|struct
name|reloc_info_extended
block|{
name|unsigned
name|long
name|r_address
decl_stmt|;
name|unsigned
name|int
name|r_index
range|:
literal|24
decl_stmt|;
define|#
directive|define
name|r_symbolnum
value|r_index
name|unsigned
name|r_extern
range|:
literal|1
decl_stmt|;
name|unsigned
label|:
literal|2
expr_stmt|;
comment|/*  RS/6000 compiler does not support enum bitfield 	    enum reloc_type r_type:5; */
name|enum
name|reloc_type
name|r_type
decl_stmt|;
name|long
name|int
name|r_addend
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* The standard, old-fashioned, Berkeley compatible relocation struct */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_I860
end_ifdef

begin_comment
comment|/* NOTE: three bits max, see struct reloc_info_i860.r_type */
end_comment

begin_enum
enum|enum
name|i860_reloc_type
block|{
name|NO_RELOC
init|=
literal|0
block|,
name|BRADDR
block|,
name|LOW0
block|,
name|LOW1
block|,
name|LOW2
block|,
name|LOW3
block|,
name|LOW4
block|,
name|SPLIT0
block|,
name|SPLIT1
block|,
name|SPLIT2
block|,
name|RELOC_32
block|,   }
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|i860_reloc_type
name|reloc_type
typedef|;
end_typedef

begin_comment
comment|/* NOTE: two bits max, see reloc_info_i860.r_type */
end_comment

begin_enum
enum|enum
name|highlow_type
block|{
name|NO_SPEC
init|=
literal|0
block|,
name|PAIR
block|,
name|HIGH
block|,
name|HIGHADJ
block|,   }
enum|;
end_enum

begin_struct
struct|struct
name|reloc_info_i860
block|{
name|unsigned
name|long
name|r_address
decl_stmt|;
comment|/* 	 * Using bit fields here is a bad idea because the order is not portable. :-( 	 */
name|unsigned
name|int
name|r_symbolnum
range|:
literal|24
decl_stmt|;
name|unsigned
name|int
name|r_pcrel
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|r_extern
range|:
literal|1
decl_stmt|;
comment|/* combining the two field simplifies the argument passing in "new_fix()" */
comment|/* and is compatible with the existing Sparc #ifdef's */
comment|/* r_type:  highlow_type - bits 5,4; reloc_type - bits 3-0 */
name|unsigned
name|int
name|r_type
range|:
literal|6
decl_stmt|;
name|long
name|r_addend
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_I860 */
end_comment

begin_struct
struct|struct
name|reloc_std_bytes
block|{
name|unsigned
name|char
name|r_address
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|r_index
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|char
name|r_bits
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RELOC_STD_BITS_PCREL_BIG
value|0x80
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_PCREL_LITTLE
value|0x01
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_LENGTH_BIG
value|0x60
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_LENGTH_SH_BIG
value|5
end_define

begin_comment
comment|/* To shift to units place */
end_comment

begin_define
define|#
directive|define
name|RELOC_STD_BITS_LENGTH_LITTLE
value|0x06
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_LENGTH_SH_LITTLE
value|1
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_EXTERN_BIG
value|0x10
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_EXTERN_LITTLE
value|0x08
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_BASEREL_BIG
value|0x08
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_BASEREL_LITTLE
value|0x08
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_JMPTABLE_BIG
value|0x04
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_JMPTABLE_LITTLE
value|0x04
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_RELATIVE_BIG
value|0x02
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_RELATIVE_LITTLE
value|0x02
end_define

begin_define
define|#
directive|define
name|RELOC_STD_SIZE
value|8
end_define

begin_comment
comment|/* Bytes per relocation entry */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_EXTENDED_RELOC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CUSTOM_RELOC_FORMAT
end_ifndef

begin_struct
struct|struct
name|relocation_info
block|{
comment|/* Address (within segment) to be relocated.  */
name|int
name|r_address
decl_stmt|;
comment|/* The meaning of r_symbolnum depends on r_extern.  */
name|unsigned
name|int
name|r_symbolnum
range|:
literal|24
decl_stmt|;
comment|/* Nonzero means value is a pc-relative offset 	   and it should be relocated for changes in its own address 	   as well as for changes in the symbol or section specified.  */
name|unsigned
name|int
name|r_pcrel
range|:
literal|1
decl_stmt|;
comment|/* Length (as exponent of 2) of the field to be relocated. 	   Thus, a value of 2 indicates 1<<2 bytes.  */
name|unsigned
name|int
name|r_length
range|:
literal|2
decl_stmt|;
comment|/* 1 => relocate with value of symbol. 	   r_symbolnum is the index of the symbol 	   in file's the symbol table. 	   0 => relocate with the address of a segment. 	   r_symbolnum is N_TEXT, N_DATA, N_BSS or N_ABS 	   (the N_EXT bit may be set also, but signifies nothing).  */
name|unsigned
name|int
name|r_extern
range|:
literal|1
decl_stmt|;
comment|/* The next three bits are for SunOS shared libraries, and seem to 	   be undocumented.  */
ifdef|#
directive|ifdef
name|TC_NS32K
name|unsigned
name|int
name|r_bsr
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|r_disp
range|:
literal|2
decl_stmt|;
else|#
directive|else
name|unsigned
name|int
name|r_baserel
range|:
literal|1
decl_stmt|;
comment|/* Linkage table relative */
name|unsigned
name|int
name|r_jmptable
range|:
literal|1
decl_stmt|;
comment|/* pc-relative to jump table */
name|unsigned
name|int
name|r_relative
range|:
literal|1
decl_stmt|;
comment|/* "relative relocation" */
endif|#
directive|endif
comment|/* TC_NS32K */
comment|/* unused */
name|unsigned
name|int
name|r_pad
range|:
literal|1
decl_stmt|;
comment|/* Padding -- set to zero */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CUSTOM_RELOC_FORMAT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __A_OUT_GNU_H__ */
end_comment

begin_comment
comment|/* end of aout_gnu.h */
end_comment

end_unit

