begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* coff.h    Copyright (C) 1987, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * At this point I'm sure this file is right for i960 and I'm pretty sure it's  * right for a29k, although it hasn't been tested rigorously.  Please feel free  * to add your own machine's description here.  Without that info, it isn't  * possible to build cross development tools from elsewhere nor is it easy to  * continue to support your machines format.  *  * The TC_foo ifdef's are mine.  They are what gas uses.  The other ifdef's  * remain for documentation from other scavenged files.   xoxorich.  */
end_comment

begin_comment
comment|/********************** FILE HEADER **********************/
end_comment

begin_struct
struct|struct
name|filehdr
block|{
name|unsigned
name|short
name|f_magic
decl_stmt|;
comment|/* magic number			*/
name|unsigned
name|short
name|f_nscns
decl_stmt|;
comment|/* number of sections		*/
name|long
name|f_timdat
decl_stmt|;
comment|/* time& date stamp		*/
name|long
name|f_symptr
decl_stmt|;
comment|/* file pointer to symtab	*/
name|long
name|f_nsyms
decl_stmt|;
comment|/* number of symtab entries	*/
name|unsigned
name|short
name|f_opthdr
decl_stmt|;
comment|/* sizeof(optional hdr)		*/
name|unsigned
name|short
name|f_flags
decl_stmt|;
comment|/* flags			*/
block|}
struct|;
end_struct

begin_comment
comment|/* Bits for f_flags:  *	F_RELFLG	relocation info stripped from file  *	F_EXEC		file is executable (no unresolved externel references)  *	F_LNNO		line nunbers stripped from file  *	F_LSYMS		local symbols stripped from file  *	F_AR32WR	file has byte ordering of an AR32WR machine (e.g. vax)  */
end_comment

begin_define
define|#
directive|define
name|F_RELFLG
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|F_EXEC
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|F_LNNO
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|F_LSYMS
value|(0x0008)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TC_I960
end_ifdef

begin_define
define|#
directive|define
name|F_AR32WR
value|(0x0010)
end_define

begin_comment
comment|/* File has 32 bits per word, least 				    significant byte first. */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* TC_I960 */
end_comment

begin_define
define|#
directive|define
name|F_AR32WR
value|(0x0100)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_I960 */
end_comment

begin_define
define|#
directive|define
name|F_MINMAL
value|(0x0010)
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|F_UPDATE
value|(0x0020)
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|F_SWABD
value|(0x0040)
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|F_AR16WR
value|(0x0080)
end_define

begin_comment
comment|/* File has the byte ordering used by 				    the PDP*-11/70 processor. */
end_comment

begin_define
define|#
directive|define
name|F_AR32W
value|(0x0200)
end_define

begin_comment
comment|/* File has 32 bits per word, most 				    significant byte first. */
end_comment

begin_comment
comment|/*  *	Intel 80960 (I960) processor flags.  *	F_I960TYPE == mask for processor type field.  */
end_comment

begin_define
define|#
directive|define
name|F_I960TYPE
value|(0xf000)
end_define

begin_define
define|#
directive|define
name|F_I960CORE
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|F_I960KB
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|F_I960SB
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|F_I960MC
value|(0x3000)
end_define

begin_define
define|#
directive|define
name|F_I960XA
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|F_I960CA
value|(0x5000)
end_define

begin_define
define|#
directive|define
name|F_I960KA
value|(0x6000)
end_define

begin_define
define|#
directive|define
name|F_I960SA
value|(0x6000)
end_define

begin_comment
comment|/*  * i80960 Magic Numbers  */
end_comment

begin_define
define|#
directive|define
name|I960ROMAGIC
value|(0x160)
end_define

begin_comment
comment|/* read-only text segments */
end_comment

begin_define
define|#
directive|define
name|I960RWMAGIC
value|(0x161)
end_define

begin_comment
comment|/* read-write text segments */
end_comment

begin_define
define|#
directive|define
name|I960BADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != I960ROMAGIC)&& ((x).f_magic != I960RWMAGIC))
end_define

begin_define
define|#
directive|define
name|SIPFBOMAGIC
value|(0x17a)
end_define

begin_comment
comment|/* Am29000 (Byte 0 is MSB - Big Endian) */
end_comment

begin_define
define|#
directive|define
name|SIPRBOMAGIC
value|(0x17b)
end_define

begin_comment
comment|/* Am29000 (Byte 0 is LSB - Little Endian) */
end_comment

begin_define
define|#
directive|define
name|A29KBADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != SIPFBOMAGIC)&& ((x).f_magic != SIPRBOMAGIC))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TE_I386AIX
end_ifdef

begin_define
define|#
directive|define
name|I386MAGIC
value|(0x175)
end_define

begin_comment
comment|/* Danbury AIX C compiler 	*/
end_comment

begin_define
define|#
directive|define
name|I386SVMAGIC
value|(0x14c)
end_define

begin_comment
comment|/* System V C Compiler 		*/
end_comment

begin_define
define|#
directive|define
name|I386BADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != I386MAGIC)&& \ 			 ((x).f_magic != I386SVMAGIC))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not TE_I386AIX */
end_comment

begin_define
define|#
directive|define
name|I386MAGIC
value|0x14c
end_define

begin_define
define|#
directive|define
name|I386BADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != I386MAGIC))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not TE_I386AIX */
end_comment

begin_define
define|#
directive|define
name|FILHDR
value|struct filehdr
end_define

begin_define
define|#
directive|define
name|FILHSZ
value|sizeof(FILHDR)
end_define

begin_comment
comment|/********************** AOUT "OPTIONAL HEADER" **********************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|phys_addr
decl_stmt|;
name|unsigned
name|long
name|bitarray
decl_stmt|;
block|}
name|TAGBITS
typedef|;
end_typedef

begin_comment
comment|/*  These appear to be used only by exec(2).  I don't know who cares     about them in a cross development environment.  In any case, this     is my collection after researching the issue for a few hours.     Apparently, most have these have remained essentially unchanged     since v7 days, although a few new ones have been added.  xoxorich. */
end_comment

begin_define
define|#
directive|define
name|BAD0MAGIC
value|(0401)
end_define

begin_comment
comment|/* (?) "lpd (UNIX/RT)" */
end_comment

begin_define
define|#
directive|define
name|BAD1MAGIC
value|(0405)
end_define

begin_comment
comment|/* (?) overlay */
end_comment

begin_define
define|#
directive|define
name|OMAGIC
value|(0407)
end_define

begin_comment
comment|/* old impure format. data immediately 				  follows text. both sections are rw. */
end_comment

begin_define
define|#
directive|define
name|NMAGIC
value|(0410)
end_define

begin_comment
comment|/* split i&d, read-only text */
end_comment

begin_define
define|#
directive|define
name|A_MAGIC3
value|(0411)
end_define

begin_comment
comment|/* (?) "separated I&D" */
end_comment

begin_define
define|#
directive|define
name|ZMAGIC
value|(0413)
end_define

begin_comment
comment|/* like NMAGIC, but demand loaded */
end_comment

begin_define
define|#
directive|define
name|PAGEMAGIC2
value|(0414)
end_define

begin_comment
comment|/* (?) like ZMAGIC, but address zero 				  explicitly unmapped. */
end_comment

begin_define
define|#
directive|define
name|REGMAGIC
value|(0414)
end_define

begin_comment
comment|/* (?) a PAGEMAGIC2 alias? */
end_comment

begin_define
define|#
directive|define
name|PAGEMAGIC3
value|(0415)
end_define

begin_comment
comment|/* (?) like ZMAGIC, but address zero mapped. */
end_comment

begin_define
define|#
directive|define
name|A_MAGIC5
value|(0437)
end_define

begin_comment
comment|/* (?) "system overlay, separated I&D" */
end_comment

begin_comment
comment|/* intended for non-unix cross development */
end_comment

begin_define
define|#
directive|define
name|SASMAGIC
value|(010000)
end_define

begin_comment
comment|/* Single Address Space */
end_comment

begin_define
define|#
directive|define
name|MASMAGIC
value|(020000)
end_define

begin_comment
comment|/* (?) "Multiple (separate I& D) Address Spaces" */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|aouthdr
block|{
name|short
name|magic
decl_stmt|;
comment|/* type of file				*/
name|short
name|vstamp
decl_stmt|;
comment|/* version stamp			*/
name|unsigned
name|long
name|tsize
decl_stmt|;
comment|/* text size in bytes, padded to FW bdry*/
name|unsigned
name|long
name|dsize
decl_stmt|;
comment|/* initialized data "  "		*/
name|unsigned
name|long
name|bsize
decl_stmt|;
comment|/* uninitialized data "   "		*/
if|#
directive|if
name|U3B
name|unsigned
name|long
name|dum1
decl_stmt|;
name|unsigned
name|long
name|dum2
decl_stmt|;
comment|/* pad to entry point	*/
endif|#
directive|endif
name|unsigned
name|long
name|entry
decl_stmt|;
comment|/* entry pt.				*/
name|unsigned
name|long
name|text_start
decl_stmt|;
comment|/* base of text used for this file */
name|unsigned
name|long
name|data_start
decl_stmt|;
comment|/* base of data used for this file */
comment|/* CAREFUL: some formats omit the tagentries member. */
name|unsigned
name|long
name|tagentries
decl_stmt|;
comment|/* number of tag entries to 					   follow (always zero for i960) */
block|}
name|AOUTHDR
typedef|;
end_typedef

begin_comment
comment|/* return a pointer to the tag bits array */
end_comment

begin_define
define|#
directive|define
name|TAGPTR
parameter_list|(
name|aout
parameter_list|)
value|((TAGBITS *) (&(aout.tagentries)+1))
end_define

begin_comment
comment|/* compute size of a header */
end_comment

begin_comment
comment|/*#define AOUTSZ(aout) (sizeof(AOUTHDR)+(aout.tagentries*sizeof(TAGBITS)))*/
end_comment

begin_define
define|#
directive|define
name|AOUTSZ
value|(sizeof(AOUTHDR))
end_define

begin_comment
comment|/********************** STORAGE CLASSES **********************/
end_comment

begin_define
define|#
directive|define
name|C_EFCN
value|-1
end_define

begin_comment
comment|/* physical end of function */
end_comment

begin_define
define|#
directive|define
name|C_NULL
value|0
end_define

begin_define
define|#
directive|define
name|C_AUTO
value|1
end_define

begin_comment
comment|/* automatic variable */
end_comment

begin_define
define|#
directive|define
name|C_EXT
value|2
end_define

begin_comment
comment|/* external symbol */
end_comment

begin_define
define|#
directive|define
name|C_STAT
value|3
end_define

begin_comment
comment|/* static */
end_comment

begin_define
define|#
directive|define
name|C_REG
value|4
end_define

begin_comment
comment|/* register variable */
end_comment

begin_define
define|#
directive|define
name|C_EXTDEF
value|5
end_define

begin_comment
comment|/* external definition */
end_comment

begin_define
define|#
directive|define
name|C_LABEL
value|6
end_define

begin_comment
comment|/* label */
end_comment

begin_define
define|#
directive|define
name|C_ULABEL
value|7
end_define

begin_comment
comment|/* undefined label */
end_comment

begin_define
define|#
directive|define
name|C_MOS
value|8
end_define

begin_comment
comment|/* member of structure */
end_comment

begin_define
define|#
directive|define
name|C_ARG
value|9
end_define

begin_comment
comment|/* function argument */
end_comment

begin_define
define|#
directive|define
name|C_STRTAG
value|10
end_define

begin_comment
comment|/* structure tag */
end_comment

begin_define
define|#
directive|define
name|C_MOU
value|11
end_define

begin_comment
comment|/* member of union */
end_comment

begin_define
define|#
directive|define
name|C_UNTAG
value|12
end_define

begin_comment
comment|/* union tag */
end_comment

begin_define
define|#
directive|define
name|C_TPDEF
value|13
end_define

begin_comment
comment|/* type definition */
end_comment

begin_define
define|#
directive|define
name|C_USTATIC
value|14
end_define

begin_comment
comment|/* undefined static */
end_comment

begin_define
define|#
directive|define
name|C_ENTAG
value|15
end_define

begin_comment
comment|/* enumeration tag */
end_comment

begin_define
define|#
directive|define
name|C_MOE
value|16
end_define

begin_comment
comment|/* member of enumeration */
end_comment

begin_define
define|#
directive|define
name|C_REGPARM
value|17
end_define

begin_comment
comment|/* register parameter */
end_comment

begin_define
define|#
directive|define
name|C_FIELD
value|18
end_define

begin_comment
comment|/* bit field */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_I960
end_ifdef

begin_define
define|#
directive|define
name|C_AUTOARG
value|19
end_define

begin_comment
comment|/* auto argument */
end_comment

begin_define
define|#
directive|define
name|C_LASTENT
value|20
end_define

begin_comment
comment|/* dummy entry (end of block) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_I960 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_A29K
end_ifdef

begin_define
define|#
directive|define
name|C_GLBLREG
value|19
end_define

begin_comment
comment|/* global register */
end_comment

begin_define
define|#
directive|define
name|C_EXTREG
value|20
end_define

begin_comment
comment|/* external global register */
end_comment

begin_define
define|#
directive|define
name|C_DEFREG
value|21
end_define

begin_comment
comment|/* ext. def. of global register */
end_comment

begin_define
define|#
directive|define
name|C_STARTOF
value|22
end_define

begin_comment
comment|/* as29 $SIZEOF and $STARTOF symbols */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_A29K */
end_comment

begin_define
define|#
directive|define
name|C_BLOCK
value|100
end_define

begin_comment
comment|/* ".bb" or ".eb" */
end_comment

begin_define
define|#
directive|define
name|C_FCN
value|101
end_define

begin_comment
comment|/* ".bf" or ".ef" */
end_comment

begin_define
define|#
directive|define
name|C_EOS
value|102
end_define

begin_comment
comment|/* end of structure */
end_comment

begin_define
define|#
directive|define
name|C_FILE
value|103
end_define

begin_comment
comment|/* file name */
end_comment

begin_define
define|#
directive|define
name|C_LINE
value|104
end_define

begin_comment
comment|/* line # reformatted as symbol table entry */
end_comment

begin_define
define|#
directive|define
name|C_ALIAS
value|105
end_define

begin_comment
comment|/* duplicate tag */
end_comment

begin_define
define|#
directive|define
name|C_HIDDEN
value|106
end_define

begin_comment
comment|/* ext symbol in dmert public lib. like static, 				   used to avoid name conflicts. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_I960
end_ifdef

begin_comment
comment|/* New storage classes for 80960 */
end_comment

begin_define
define|#
directive|define
name|C_SCALL
value|107
end_define

begin_comment
comment|/* Procedure reachable via system call	*/
end_comment

begin_comment
comment|/* C_LEAFPROC is obsolete.  Use C_LEAFEXT or C_LEAFSTAT */
end_comment

begin_define
define|#
directive|define
name|C_LEAFPROC
value|108
end_define

begin_comment
comment|/* Leaf procedure, "call" via BAL */
end_comment

begin_define
define|#
directive|define
name|C_LEAFEXT
value|108
end_define

begin_define
define|#
directive|define
name|C_OPTVAR
value|109
end_define

begin_comment
comment|/* Optimized variable */
end_comment

begin_define
define|#
directive|define
name|C_DEFINE
value|110
end_define

begin_comment
comment|/* Preprocessor #define */
end_comment

begin_define
define|#
directive|define
name|C_PRAGMA
value|111
end_define

begin_comment
comment|/* Advice to compiler or linker	*/
end_comment

begin_define
define|#
directive|define
name|C_SEGMENT
value|112
end_define

begin_comment
comment|/* 80960 segment name */
end_comment

begin_define
define|#
directive|define
name|C_LEAFSTAT
value|113
end_define

begin_comment
comment|/* Static leaf */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_I960 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_A29K
end_ifdef

begin_define
define|#
directive|define
name|C_SHADOW
value|107
end_define

begin_comment
comment|/* shadow symbol */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_A29K */
end_comment

begin_comment
comment|/********************** SECTION HEADER **********************/
end_comment

begin_struct
struct|struct
name|scnhdr
block|{
name|char
name|s_name
index|[
literal|8
index|]
decl_stmt|;
comment|/* section name */
name|long
name|s_paddr
decl_stmt|;
comment|/* physical address, aliased s_nlib */
name|long
name|s_vaddr
decl_stmt|;
comment|/* virtual address */
name|long
name|s_size
decl_stmt|;
comment|/* section size */
name|long
name|s_scnptr
decl_stmt|;
comment|/* file ptr to raw data for section */
name|long
name|s_relptr
decl_stmt|;
comment|/* file ptr to relocation */
name|long
name|s_lnnoptr
decl_stmt|;
comment|/* file ptr to line numbers */
name|unsigned
name|short
name|s_nreloc
decl_stmt|;
comment|/* number of relocation entries	*/
name|unsigned
name|short
name|s_nlnno
decl_stmt|;
comment|/* number of line number entries */
name|long
name|s_flags
decl_stmt|;
comment|/* flags */
ifdef|#
directive|ifdef
name|TC_I960
name|unsigned
name|long
name|s_align
decl_stmt|;
comment|/* section alignment */
endif|#
directive|endif
comment|/* TC_I960 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCNHDR
value|struct scnhdr
end_define

begin_define
define|#
directive|define
name|SCNHSZ
value|sizeof(SCNHDR)
end_define

begin_comment
comment|/*  * names of "special" sections  */
end_comment

begin_define
define|#
directive|define
name|_TEXT
value|".text"
end_define

begin_comment
comment|/* executable code section	*/
end_comment

begin_define
define|#
directive|define
name|_DATA
value|".data"
end_define

begin_comment
comment|/* initialized data		*/
end_comment

begin_define
define|#
directive|define
name|_BSS
value|".bss"
end_define

begin_comment
comment|/* un-initialized data		*/
end_comment

begin_define
define|#
directive|define
name|_DEBUG
value|".debug"
end_define

begin_comment
comment|/* special section used by dbx	*/
end_comment

begin_define
define|#
directive|define
name|_COMMENT
value|".comment"
end_define

begin_comment
comment|/* version info			*/
end_comment

begin_define
define|#
directive|define
name|_LIB
value|".lib"
end_define

begin_comment
comment|/* shared lib info section	*/
end_comment

begin_define
define|#
directive|define
name|_TV
value|".tv"
end_define

begin_comment
comment|/*  * s_flags "type"  */
end_comment

begin_comment
comment|/*  * In instances where it is necessary for a linker to  * produce an output file which contains text or data not  * based at virtual address 0, e.g. for a ROM, then the  * linker should accept address base information as command  * input and use PAD sections to skip over unused addresses.  * (at least for a29k.  Maybe others.)  */
end_comment

begin_define
define|#
directive|define
name|STYP_REG
value|(0x0000)
end_define

begin_comment
comment|/* "regular" section: allocated, relocated, loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_DSECT
value|(0x0001)
end_define

begin_comment
comment|/* "dummy" section: not allocated, relocated, not loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_NOLOAD
value|(0x0002)
end_define

begin_comment
comment|/* "noload" section: allocated, relocated, not loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_GROUP
value|(0x0004)
end_define

begin_comment
comment|/* "grouped" section: formed of input sections */
end_comment

begin_define
define|#
directive|define
name|STYP_PAD
value|(0x0008)
end_define

begin_comment
comment|/* "padding" section: not allocated, not relocated, loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_COPY
value|(0x0010)
end_define

begin_comment
comment|/* "copy" section: for decision function used by field update;  not allocated, not relocated, 				     loaded; reloc& lineno entries processed normally */
end_comment

begin_define
define|#
directive|define
name|STYP_TEXT
value|(0x0020)
end_define

begin_comment
comment|/* section contains text only */
end_comment

begin_define
define|#
directive|define
name|S_SHRSEG
value|(0x0020)
end_define

begin_comment
comment|/* In 3b Update files (output of ogen), sections which appear in SHARED segments of the Pfile 				     will have the S_SHRSEG flag set by ogen, to inform dufr that updating 1 copy of the proc. will 				     update all process invocations. */
end_comment

begin_define
define|#
directive|define
name|STYP_DATA
value|(0x0040)
end_define

begin_comment
comment|/* section contains data only */
end_comment

begin_define
define|#
directive|define
name|STYP_BSS
value|(0x0080)
end_define

begin_comment
comment|/* section contains bss only */
end_comment

begin_define
define|#
directive|define
name|S_NEWFCN
value|(0x0100)
end_define

begin_comment
comment|/* In a minimal file or an update file, a new function (as compared with a replaced function) */
end_comment

begin_define
define|#
directive|define
name|STYP_INFO
value|(0x0200)
end_define

begin_comment
comment|/* comment section : not allocated not relocated, not loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_OVER
value|(0x0400)
end_define

begin_comment
comment|/* overlay section : relocated not allocated or loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_LIB
value|(0x0800)
end_define

begin_comment
comment|/* for .lib section : same as INFO */
end_comment

begin_define
define|#
directive|define
name|STYP_MERGE
value|(0x2000)
end_define

begin_comment
comment|/* merge section -- combines with text, data or bss sections only */
end_comment

begin_define
define|#
directive|define
name|STYP_REVERSE_PAD
value|(0x4000)
end_define

begin_comment
comment|/* section will be padded with no-op instructions wherever padding is necessary and there is a 				     word of contiguous bytes beginning on a word boundary. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_A29K
end_ifdef

begin_comment
comment|/* NOTE:  The use of STYP_BSSREG for relocation is not yet defined. */
end_comment

begin_define
define|#
directive|define
name|STYP_BSSREG
value|0x1200
end_define

begin_comment
comment|/* Global register area (like STYP_INFO) */
end_comment

begin_define
define|#
directive|define
name|STYP_ENVIR
value|0x2200
end_define

begin_comment
comment|/* Environment (like STYP_INFO) */
end_comment

begin_define
define|#
directive|define
name|STYP_ABS
value|0x4000
end_define

begin_comment
comment|/* Absolute (allocated, not reloc, loaded) */
end_comment

begin_define
define|#
directive|define
name|STYP_LIT
value|0x8020
end_define

begin_comment
comment|/* Literal data (like STYP_TEXT) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_A29K */
end_comment

begin_comment
comment|/********************** LINE NUMBERS **********************/
end_comment

begin_comment
comment|/* 1 line number entry for every "breakpointable" source line in a section.  * Line numbers are grouped on a per function basis; first entry in a function  * grouping will have l_lnno = 0 and in place of physical address will be the  * symbol table index of the function name.  */
end_comment

begin_struct
struct|struct
name|lineno
block|{
union|union
block|{
name|long
name|l_symndx
decl_stmt|;
comment|/* symbol index of function name, iff l_lnno == 0*/
name|long
name|l_paddr
decl_stmt|;
comment|/* (physical) address of line number */
block|}
name|l_addr
union|;
name|unsigned
name|short
name|l_lnno
decl_stmt|;
comment|/* line number */
ifdef|#
directive|ifdef
name|TC_I960
comment|/* not used on a29k */
name|char
name|padding
index|[
literal|2
index|]
decl_stmt|;
comment|/* force alignment */
endif|#
directive|endif
comment|/* TC_I960 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LINENO
value|struct lineno
end_define

begin_define
define|#
directive|define
name|LINESZ
value|sizeof(LINENO)
end_define

begin_comment
comment|/********************** SYMBOLS **********************/
end_comment

begin_define
define|#
directive|define
name|SYMNMLEN
value|8
end_define

begin_comment
comment|/* # characters in a symbol name */
end_comment

begin_define
define|#
directive|define
name|FILNMLEN
value|14
end_define

begin_comment
comment|/* # characters in a file name */
end_comment

begin_define
define|#
directive|define
name|DIMNUM
value|4
end_define

begin_comment
comment|/* # array dimensions in auxiliary entry */
end_comment

begin_struct
struct|struct
name|syment
block|{
union|union
block|{
name|char
name|_n_name
index|[
name|SYMNMLEN
index|]
decl_stmt|;
comment|/* old COFF version */
struct|struct
block|{
name|long
name|_n_zeroes
decl_stmt|;
comment|/* new == 0 */
name|long
name|_n_offset
decl_stmt|;
comment|/* offset into string table */
block|}
name|_n_n
struct|;
name|char
modifier|*
name|_n_nptr
index|[
literal|2
index|]
decl_stmt|;
comment|/* allows for overlaying */
block|}
name|_n
union|;
name|long
name|n_value
decl_stmt|;
comment|/* value of symbol */
name|short
name|n_scnum
decl_stmt|;
comment|/* section number */
ifdef|#
directive|ifdef
name|TC_I960
comment|/* This isn't yet used on the i960.  In some formats this 	   is two bytes of padding.  In others, it is missing entirely. */
name|unsigned
name|short
name|n_flags
decl_stmt|;
comment|/* copy of flags from filhdr */
endif|#
directive|endif
comment|/* TC_I960 */
ifdef|#
directive|ifdef
name|TC_A29K
name|unsigned
name|short
name|n_type
decl_stmt|;
comment|/* type and derived type */
else|#
directive|else
comment|/* TC_A29K */
comment|/* at least i960 uses long */
name|unsigned
name|long
name|n_type
decl_stmt|;
comment|/* type and derived type */
endif|#
directive|endif
comment|/* TC_A29K */
name|char
name|n_sclass
decl_stmt|;
comment|/* storage class */
name|char
name|n_numaux
decl_stmt|;
comment|/* number of aux. entries */
ifndef|#
directive|ifndef
name|TC_A29K
name|char
name|pad2
index|[
literal|2
index|]
decl_stmt|;
comment|/* force alignment */
endif|#
directive|endif
comment|/* TC_A29K */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SYMENT
value|struct syment
end_define

begin_define
define|#
directive|define
name|SYMESZ
value|sizeof(SYMENT)
end_define

begin_comment
comment|/* This had better also be sizeof(AUXENT) */
end_comment

begin_define
define|#
directive|define
name|n_name
value|_n._n_name
end_define

begin_define
define|#
directive|define
name|n_ptr
value|_n._n_nptr[1]
end_define

begin_define
define|#
directive|define
name|n_zeroes
value|_n._n_n._n_zeroes
end_define

begin_define
define|#
directive|define
name|n_offset
value|_n._n_n._n_offset
end_define

begin_comment
comment|/*      * Relocatable symbols have number of the section in which they are defined,      * or one of the following:      */
end_comment

begin_define
define|#
directive|define
name|N_SCNUM
value|((short) 1-65535)
end_define

begin_comment
comment|/* section num where symbol defined */
end_comment

begin_define
define|#
directive|define
name|N_UNDEF
value|((short)0)
end_define

begin_comment
comment|/* undefined symbol */
end_comment

begin_define
define|#
directive|define
name|N_ABS
value|((short)-1)
end_define

begin_comment
comment|/* value of symbol is absolute */
end_comment

begin_define
define|#
directive|define
name|N_DEBUG
value|((short)-2)
end_define

begin_comment
comment|/* debugging symbol -- symbol value is meaningless */
end_comment

begin_define
define|#
directive|define
name|N_TV
value|((short)-3)
end_define

begin_comment
comment|/* indicates symbol needs preload transfer vector */
end_comment

begin_define
define|#
directive|define
name|P_TV
value|((short)-4)
end_define

begin_comment
comment|/* indicates symbol needs transfer vector (postload) */
end_comment

begin_comment
comment|/*  * Type of a symbol, in low 4 bits of the word  */
end_comment

begin_define
define|#
directive|define
name|T_NULL
value|0
end_define

begin_comment
comment|/* type not assigned */
end_comment

begin_define
define|#
directive|define
name|T_VOID
value|1
end_define

begin_comment
comment|/* function argument (only used by compiler) (but now real void). */
end_comment

begin_define
define|#
directive|define
name|T_CHAR
value|2
end_define

begin_comment
comment|/* character */
end_comment

begin_define
define|#
directive|define
name|T_SHORT
value|3
end_define

begin_comment
comment|/* short integer */
end_comment

begin_define
define|#
directive|define
name|T_INT
value|4
end_define

begin_comment
comment|/* integer */
end_comment

begin_define
define|#
directive|define
name|T_LONG
value|5
end_define

begin_comment
comment|/* long integer */
end_comment

begin_define
define|#
directive|define
name|T_FLOAT
value|6
end_define

begin_comment
comment|/* floating point */
end_comment

begin_define
define|#
directive|define
name|T_DOUBLE
value|7
end_define

begin_comment
comment|/* double word */
end_comment

begin_define
define|#
directive|define
name|T_STRUCT
value|8
end_define

begin_comment
comment|/* structure */
end_comment

begin_define
define|#
directive|define
name|T_UNION
value|9
end_define

begin_comment
comment|/* union */
end_comment

begin_define
define|#
directive|define
name|T_ENUM
value|10
end_define

begin_comment
comment|/* enumeration */
end_comment

begin_define
define|#
directive|define
name|T_MOE
value|11
end_define

begin_comment
comment|/* member of enumeration */
end_comment

begin_define
define|#
directive|define
name|T_UCHAR
value|12
end_define

begin_comment
comment|/* unsigned character */
end_comment

begin_define
define|#
directive|define
name|T_USHORT
value|13
end_define

begin_comment
comment|/* unsigned short */
end_comment

begin_define
define|#
directive|define
name|T_UINT
value|14
end_define

begin_comment
comment|/* unsigned integer */
end_comment

begin_define
define|#
directive|define
name|T_ULONG
value|15
end_define

begin_comment
comment|/* unsigned long */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_I960
end_ifdef

begin_define
define|#
directive|define
name|T_LNGDBL
value|16
end_define

begin_comment
comment|/* long double */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_I960 */
end_comment

begin_comment
comment|/*  * derived types, in n_type  */
end_comment

begin_define
define|#
directive|define
name|DT_NON
value|(0)
end_define

begin_comment
comment|/* no derived type */
end_comment

begin_define
define|#
directive|define
name|DT_PTR
value|(1)
end_define

begin_comment
comment|/* pointer */
end_comment

begin_define
define|#
directive|define
name|DT_FCN
value|(2)
end_define

begin_comment
comment|/* function */
end_comment

begin_define
define|#
directive|define
name|DT_ARY
value|(3)
end_define

begin_comment
comment|/* array */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_I960
end_ifndef

begin_define
define|#
directive|define
name|N_BTMASK
value|(0x0f)
end_define

begin_define
define|#
directive|define
name|N_TMASK
value|(0x30)
end_define

begin_define
define|#
directive|define
name|N_BTSHFT
value|(4)
end_define

begin_define
define|#
directive|define
name|N_TSHIFT
value|(2)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* TC_I960 */
end_comment

begin_define
define|#
directive|define
name|N_BTMASK
value|(0x1f)
end_define

begin_define
define|#
directive|define
name|N_TMASK
value|(0x60)
end_define

begin_define
define|#
directive|define
name|N_BTSHFT
value|(5)
end_define

begin_define
define|#
directive|define
name|N_TSHIFT
value|(2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_I960 */
end_comment

begin_define
define|#
directive|define
name|BTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)& N_BTMASK)
end_define

begin_define
define|#
directive|define
name|ISPTR
parameter_list|(
name|x
parameter_list|)
value|(((x)& N_TMASK) == (DT_PTR<< N_BTSHFT))
end_define

begin_define
define|#
directive|define
name|ISFCN
parameter_list|(
name|x
parameter_list|)
value|(((x)& N_TMASK) == (DT_FCN<< N_BTSHFT))
end_define

begin_define
define|#
directive|define
name|ISARY
parameter_list|(
name|x
parameter_list|)
value|(((x)& N_TMASK) == (DT_ARY<< N_BTSHFT))
end_define

begin_define
define|#
directive|define
name|DECREF
parameter_list|(
name|x
parameter_list|)
value|((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
end_define

begin_union
union|union
name|auxent
block|{
struct|struct
block|{
name|long
name|x_tagndx
decl_stmt|;
comment|/* str, un, or enum tag indx */
union|union
block|{
struct|struct
block|{
name|unsigned
name|short
name|x_lnno
decl_stmt|;
comment|/* declaration line number */
name|unsigned
name|short
name|x_size
decl_stmt|;
comment|/* str/union/array size */
block|}
name|x_lnsz
struct|;
name|long
name|x_fsize
decl_stmt|;
comment|/* size of function */
block|}
name|x_misc
union|;
union|union
block|{
struct|struct
block|{
comment|/* if ISFCN, tag, or .bb */
name|long
name|x_lnnoptr
decl_stmt|;
comment|/* ptr to fcn line # */
name|long
name|x_endndx
decl_stmt|;
comment|/* entry ndx past block end */
block|}
name|x_fcn
struct|;
struct|struct
block|{
comment|/* if ISARY, up to 4 dimen. */
name|unsigned
name|short
name|x_dimen
index|[
name|DIMNUM
index|]
decl_stmt|;
block|}
name|x_ary
struct|;
block|}
name|x_fcnary
union|;
name|unsigned
name|short
name|x_tvndx
decl_stmt|;
comment|/* tv index */
block|}
name|x_sym
struct|;
comment|/* This was just a struct x_file with x_fname only in a29k.  xoxorich. */
union|union
block|{
name|char
name|x_fname
index|[
name|FILNMLEN
index|]
decl_stmt|;
struct|struct
block|{
name|long
name|x_zeroes
decl_stmt|;
name|long
name|x_offset
decl_stmt|;
block|}
name|x_n
struct|;
block|}
name|x_file
union|;
struct|struct
block|{
name|long
name|x_scnlen
decl_stmt|;
comment|/* section length */
name|unsigned
name|short
name|x_nreloc
decl_stmt|;
comment|/* # relocation entries */
name|unsigned
name|short
name|x_nlinno
decl_stmt|;
comment|/* # line numbers */
block|}
name|x_scn
struct|;
struct|struct
block|{
name|long
name|x_tvfill
decl_stmt|;
comment|/* tv fill value */
name|unsigned
name|short
name|x_tvlen
decl_stmt|;
comment|/* length of .tv */
comment|/* This field was typo'd x_tvrna on a29k. xoxorich. */
name|unsigned
name|short
name|x_tvran
index|[
literal|2
index|]
decl_stmt|;
comment|/* tv range */
block|}
name|x_tv
struct|;
comment|/* info about .tv section (in auxent of symbol .tv)) */
ifdef|#
directive|ifdef
name|TC_I960
comment|/****************************************** 	 *  I960-specific *2nd* aux. entry formats 	 ******************************************/
struct|struct
block|{
comment|/* This is a very old typo that keeps getting propogated. */
define|#
directive|define
name|x_stdindx
value|x_stindx
name|long
name|x_stindx
decl_stmt|;
comment|/* sys. table entry */
block|}
name|x_sc
struct|;
comment|/* system call entry */
struct|struct
block|{
name|unsigned
name|long
name|x_balntry
decl_stmt|;
comment|/* BAL entry point */
block|}
name|x_bal
struct|;
comment|/* BAL-callable function */
struct|struct
block|{
name|unsigned
name|long
name|x_timestamp
decl_stmt|;
comment|/* time stamp */
name|char
name|x_idstring
index|[
literal|20
index|]
decl_stmt|;
comment|/* producer identity string */
block|}
name|x_ident
struct|;
comment|/* Producer ident info */
name|char
name|a
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|syment
argument_list|)
index|]
decl_stmt|;
comment|/* force auxent/syment sizes to match */
endif|#
directive|endif
comment|/* TC_I960 */
block|}
union|;
end_union

begin_define
define|#
directive|define
name|AUXENT
value|union auxent
end_define

begin_define
define|#
directive|define
name|AUXESZ
value|sizeof(AUXENT)
end_define

begin_comment
comment|/* This had better also be sizeof(SYMENT) */
end_comment

begin_if
if|#
directive|if
name|VAX
operator|||
name|I960
end_if

begin_define
define|#
directive|define
name|_ETEXT
value|"_etext"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_ETEXT
value|"etext"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/********************** RELOCATION DIRECTIVES **********************/
end_comment

begin_struct
struct|struct
name|reloc
block|{
name|long
name|r_vaddr
decl_stmt|;
comment|/* Virtual address of reference */
name|long
name|r_symndx
decl_stmt|;
comment|/* Index into symbol table */
name|unsigned
name|short
name|r_type
decl_stmt|;
comment|/* Relocation type */
ifdef|#
directive|ifdef
name|TC_I960
comment|/* not used for a29k */
name|char
name|pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* Unused */
endif|#
directive|endif
comment|/* TC_I960 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RELOC
value|struct reloc
end_define

begin_define
define|#
directive|define
name|RELSZ
value|sizeof(RELOC)
end_define

begin_define
define|#
directive|define
name|R_ABS
value|(0x00)
end_define

begin_comment
comment|/* reference is absolute */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_I960
end_ifdef

begin_define
define|#
directive|define
name|R_RELLONG
value|(0x11)
end_define

begin_comment
comment|/* Direct 32-bit relocation */
end_comment

begin_define
define|#
directive|define
name|R_IPRSHORT
value|(0x18)
end_define

begin_define
define|#
directive|define
name|R_IPRMED
value|(0x19)
end_define

begin_comment
comment|/* 24-bit ip-relative relocation */
end_comment

begin_define
define|#
directive|define
name|R_IPRLONG
value|(0x1a)
end_define

begin_define
define|#
directive|define
name|R_OPTCALL
value|(0x1b)
end_define

begin_comment
comment|/* 32-bit optimizable call (leafproc/sysproc) */
end_comment

begin_define
define|#
directive|define
name|R_OPTCALLX
value|(0x1c)
end_define

begin_comment
comment|/* 64-bit optimizable call (leafproc/sysproc) */
end_comment

begin_define
define|#
directive|define
name|R_GETSEG
value|(0x1d)
end_define

begin_define
define|#
directive|define
name|R_GETPA
value|(0x1e)
end_define

begin_define
define|#
directive|define
name|R_TAGWORD
value|(0x1f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_I960 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_A29K
end_ifdef

begin_comment
comment|/*  * NOTE: All the "I" forms refer to Am29000 instruction  * formats.  The linker is expected to know how the numeric  * information is split and/or aligned within the  * instruction word(s).  R_BYTE works for instructions, too.  *  * If the parameter to a CONSTH instruction is a relocatable  * type, two relocation records are written.  The first has  * an r_type of R_IHIHALF (33 octal) and a normal r_vaddr  * and r_symndx.  The second relocation record has an r_type  * of R_IHCONST (34 octal), a normal r_vaddr (which is  * redundant), and an r_symndx containing the 32-bit  * constant offset to the relocation instead of the actual  * symbol table index.  This second record is always  * written, even if the constant offset is zero.  The  * constant fields of the instruction are set to zero.  */
end_comment

begin_define
define|#
directive|define
name|R_IREL
value|(0x18)
end_define

begin_comment
comment|/* instruction relative (jmp/call) */
end_comment

begin_define
define|#
directive|define
name|R_IABS
value|(0x19)
end_define

begin_comment
comment|/* instruction absolute (jmp/call) */
end_comment

begin_define
define|#
directive|define
name|R_ILOHALF
value|(0x1a)
end_define

begin_comment
comment|/* instruction low half  (const)  */
end_comment

begin_define
define|#
directive|define
name|R_IHIHALF
value|(0x1b)
end_define

begin_comment
comment|/* instruction high half (consth) part 1 */
end_comment

begin_define
define|#
directive|define
name|R_IHCONST
value|(0x1c)
end_define

begin_comment
comment|/* instruction high half (consth) part 2 				  constant offset of R_IHIHALF relocation */
end_comment

begin_define
define|#
directive|define
name|R_BYTE
value|(0x1d)
end_define

begin_comment
comment|/* relocatable byte value */
end_comment

begin_define
define|#
directive|define
name|R_HWORD
value|(0x1e)
end_define

begin_comment
comment|/* relocatable halfword value */
end_comment

begin_define
define|#
directive|define
name|R_WORD
value|(0x1f)
end_define

begin_comment
comment|/* relocatable word value */
end_comment

begin_define
define|#
directive|define
name|R_IGLBLRC
value|(0x20)
end_define

begin_comment
comment|/* instruction global register RC */
end_comment

begin_define
define|#
directive|define
name|R_IGLBLRA
value|(0x21)
end_define

begin_comment
comment|/* instruction global register RA */
end_comment

begin_define
define|#
directive|define
name|R_IGLBLRB
value|(0x22)
end_define

begin_comment
comment|/* instruction global register RB */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_A29K */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_DATA_SECTION_ALIGNMENT
value|4
end_define

begin_define
define|#
directive|define
name|DEFAULT_BSS_SECTION_ALIGNMENT
value|4
end_define

begin_define
define|#
directive|define
name|DEFAULT_TEXT_SECTION_ALIGNMENT
value|16
end_define

begin_comment
comment|/* For new sections we haven't heard of before */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SECTION_ALIGNMENT
value|4
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TC_I386
argument_list|)
end_if

begin_comment
comment|/*  * X86 generic  *	8-bit offset reference in 8-bits  *	8-bit offset reference in 16-bits  *	12-bit segment reference  *	auxiliary relocation entry  */
end_comment

begin_define
define|#
directive|define
name|R_OFF8
value|07
end_define

begin_define
define|#
directive|define
name|R_OFF16
value|010
end_define

begin_define
define|#
directive|define
name|R_SEG12
value|011
end_define

begin_define
define|#
directive|define
name|R_AUX
value|013
end_define

begin_comment
comment|/*  * B16 and X86 generics  *	16-bit direct reference  *	16-bit "relative" reference  *	16-bit "indirect" (TV) reference  */
end_comment

begin_define
define|#
directive|define
name|R_DIR16
value|01
end_define

begin_define
define|#
directive|define
name|R_REL16
value|02
end_define

begin_define
define|#
directive|define
name|R_IND16
value|03
end_define

begin_comment
comment|/*  * 3B generic  *	24-bit direct reference  *	24-bit "relative" reference  *	16-bit optimized "indirect" TV reference  *	24-bit "indirect" TV reference  *	32-bit "indirect" TV reference  */
end_comment

begin_define
define|#
directive|define
name|R_DIR24
value|04
end_define

begin_define
define|#
directive|define
name|R_REL24
value|05
end_define

begin_define
define|#
directive|define
name|R_OPT16
value|014
end_define

begin_define
define|#
directive|define
name|R_IND24
value|015
end_define

begin_define
define|#
directive|define
name|R_IND32
value|016
end_define

begin_comment
comment|/*  * XL generics  *	10-bit direct reference  *	10-bit "relative" reference  *	32-bit "relative" reference  */
end_comment

begin_define
define|#
directive|define
name|R_DIR10
value|025
end_define

begin_define
define|#
directive|define
name|R_REL10
value|026
end_define

begin_define
define|#
directive|define
name|R_REL32
value|027
end_define

begin_comment
comment|/*  * 3B and M32 generics  *	32-bit direct reference  */
end_comment

begin_define
define|#
directive|define
name|R_DIR32
value|06
end_define

begin_comment
comment|/*  * M32 generic  *	32-bit direct reference with bytes swapped  */
end_comment

begin_define
define|#
directive|define
name|R_DIR32S
value|012
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_I386 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TE_I386AIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|UINFOSIZ
value|64
end_define

begin_comment
comment|/* size of user info buffer */
end_comment

begin_typedef
typedef|typedef
name|char
name|uinfo_t
index|[
name|UINFOSIZ
index|]
typedef|;
end_typedef

begin_struct
struct|struct
name|env387
block|{
name|unsigned
name|short
name|control
decl_stmt|;
name|unsigned
name|short
name|r0
decl_stmt|;
name|unsigned
name|short
name|status
decl_stmt|;
name|unsigned
name|short
name|r1
decl_stmt|;
name|unsigned
name|short
name|tag
decl_stmt|;
name|unsigned
name|short
name|r2
decl_stmt|;
name|unsigned
name|long
name|eip
decl_stmt|;
name|unsigned
name|short
name|code_seg
decl_stmt|;
name|unsigned
name|short
name|opcode
decl_stmt|;
name|unsigned
name|long
name|operand
decl_stmt|;
name|unsigned
name|short
name|operand_seg
decl_stmt|;
name|unsigned
name|short
name|r3
decl_stmt|;
name|unsigned
name|char
name|regs
index|[
literal|8
index|]
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CD_NAMELEN
value|16
end_define

begin_comment
comment|/* length of most names in this header */
end_comment

begin_define
define|#
directive|define
name|CORHDRSIZ
value|2048
end_define

begin_comment
comment|/* size to which header is padded out */
end_comment

begin_define
define|#
directive|define
name|MAX_CORE_SEGS
value|32
end_define

begin_comment
comment|/* maximum segments in a core dump */
end_comment

begin_define
define|#
directive|define
name|NUM_FREGS
value|1
end_define

begin_comment
comment|/* # of saved FP regs */
end_comment

begin_comment
comment|/*  * These are defined such that 286 and 386 kernels can produce  * compatible dumps.  */
end_comment

begin_define
define|#
directive|define
name|CD_AX
value|0
end_define

begin_define
define|#
directive|define
name|CD_BX
value|1
end_define

begin_define
define|#
directive|define
name|CD_CX
value|2
end_define

begin_define
define|#
directive|define
name|CD_DX
value|3
end_define

begin_define
define|#
directive|define
name|CD_SI
value|4
end_define

begin_define
define|#
directive|define
name|CD_DI
value|5
end_define

begin_define
define|#
directive|define
name|CD_BP
value|6
end_define

begin_define
define|#
directive|define
name|CD_SP
value|7
end_define

begin_define
define|#
directive|define
name|CD_FL
value|8
end_define

begin_define
define|#
directive|define
name|CD_IP
value|9
end_define

begin_define
define|#
directive|define
name|CD_CS
value|10
end_define

begin_define
define|#
directive|define
name|CD_DS
value|11
end_define

begin_define
define|#
directive|define
name|CD_ES
value|12
end_define

begin_define
define|#
directive|define
name|CD_FS
value|13
end_define

begin_define
define|#
directive|define
name|CD_GS
value|14
end_define

begin_define
define|#
directive|define
name|CD_SS
value|15
end_define

begin_define
define|#
directive|define
name|NUM_REGS
value|16
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|SPATHLEN
value|16
end_define

begin_comment
comment|/* sys/param.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NSIG
end_ifndef

begin_define
define|#
directive|define
name|NSIG
value|63
end_define

begin_comment
comment|/* sys/signal.h */
end_comment

begin_define
define|#
directive|define
name|SIGSETSZ
value|((NSIG+31)/32)
end_define

begin_typedef
typedef|typedef
struct|struct
name|ksigmask
block|{
name|unsigned
name|long
name|sigs
index|[
name|SIGSETSZ
index|]
decl_stmt|;
block|}
name|ksigmask_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|corehdr
block|{
name|char
name|cd_magic
index|[
literal|4
index|]
decl_stmt|;
comment|/* COR_MAGIC = "core" */
comment|/* general information about the dump itself */
struct|struct
name|dumpseg
block|{
comment|/* table of contents for dump */
name|long
name|cs_type
decl_stmt|;
comment|/* seg. type; see below */
name|long
name|cs_len
decl_stmt|;
comment|/* length (in bytes) of segment */
name|long
name|cs_offset
decl_stmt|;
comment|/* offset (in dump) of segment */
name|long
name|cs_address
decl_stmt|;
comment|/* address segment had in mem */
block|}
name|cd_segs
index|[
name|MAX_CORE_SEGS
index|]
struct|;
comment|/* general information about the process */
name|char
name|cd_comm
index|[
name|CD_NAMELEN
index|]
decl_stmt|;
comment|/* command being run */
name|char
name|cd_mach
index|[
name|CD_NAMELEN
index|]
decl_stmt|;
comment|/* type of machine it ran on */
name|char
name|cd_site
index|[
name|CD_NAMELEN
index|]
decl_stmt|;
comment|/* name of site it ran on */
name|long
name|cd_ldtype
decl_stmt|;
comment|/* type of load module running */
name|char
name|cd_intsize
decl_stmt|;
comment|/* sizeof(int) */
name|char
name|cd_dptrsize
decl_stmt|;
comment|/* sizeof(char *) */
name|char
name|cd_tptrsize
decl_stmt|;
comment|/* sizeof(int (*)()) */
name|char
name|cd_unused
decl_stmt|;
comment|/* user-mode program state */
name|long
name|cd_regs
index|[
name|NUM_REGS
index|]
decl_stmt|;
comment|/* user-mode general registers	*/
name|struct
name|env387
name|cd_fpregs
decl_stmt|;
comment|/* user-mode floating-point state */
comment|/* kernel-mode program state */
name|int
function_decl|(
modifier|*
name|cd_sig
index|[
name|NSIG
index|]
function_decl|)
parameter_list|()
function_decl|;
comment|/* disposition of signals */
name|ksigmask_t
name|cd_sigmask
decl_stmt|;
comment|/* signals to be blocked	*/
name|ksigmask_t
name|cd_sigpend
decl_stmt|;
comment|/* signals currently pending */
name|long
name|cd_cursig
decl_stmt|;
comment|/* signal that caused the dump */
name|long
name|cd_pid
decl_stmt|;
comment|/* process ID of the corpse */
name|long
name|cd_ppid
decl_stmt|;
comment|/* parent process ID of corpse */
name|short
name|cd_uid
decl_stmt|;
comment|/* process effective user ID */
name|short
name|cd_ruid
decl_stmt|;
comment|/* process real user ID */
name|short
name|cd_gid
decl_stmt|;
comment|/* process effective group ID */
name|short
name|cd_rgid
decl_stmt|;
comment|/* process real group ID	*/
name|uinfo_t
name|cd_uinfo
decl_stmt|;
comment|/* buffer of user information	*/
name|char
name|cd_locname
index|[
literal|32
index|]
decl_stmt|;
comment|/* name of /local */
name|char
name|cd_uvers
index|[
name|CD_NAMELEN
index|]
decl_stmt|;
comment|/* user version string */
name|unsigned
name|short
name|cd_spath
index|[
name|SPATHLEN
index|]
decl_stmt|;
comment|/* sitepath */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|NOCHECKS
end_ifndef

begin_comment
comment|/* this will generate an error if sizeof(struct corehdr)> CORHDRSIZ */
end_comment

begin_struct
struct|struct
block|{
name|char
name|xxcdxx
index|[
name|CORHDRSIZ
operator|+
literal|1
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|corehdr
argument_list|)
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! NOCHECKS */
end_comment

begin_comment
comment|/*  * segment types (in cs_type)  *	each segment in the address space appears here, whether or not it  *	is actually dumped.  Read/only segments will not actually be dumped.  *	A segment that is not in the dump will have a cs_offset of zero.  */
end_comment

begin_define
define|#
directive|define
name|COR_TYPE_CODE
value|'x'
end_define

begin_comment
comment|/* process code - NOT IN DUMP	*/
end_comment

begin_define
define|#
directive|define
name|COR_TYPE_DATA
value|'d'
end_define

begin_comment
comment|/* process data segment		*/
end_comment

begin_define
define|#
directive|define
name|COR_TYPE_STACK
value|'s'
end_define

begin_comment
comment|/* process stack segment	*/
end_comment

begin_define
define|#
directive|define
name|COR_TYPE_LIBCODE
value|'X'
end_define

begin_comment
comment|/* shared lib code - NOT IN DUMP*/
end_comment

begin_define
define|#
directive|define
name|COR_TYPE_LIBDATA
value|'D'
end_define

begin_comment
comment|/* shared lib data		*/
end_comment

begin_define
define|#
directive|define
name|COR_TYPE_READ
value|'r'
end_define

begin_comment
comment|/* other read/only - NOT IN DUMP*/
end_comment

begin_define
define|#
directive|define
name|COR_TYPE_WRITE
value|'w'
end_define

begin_comment
comment|/* other writeable		*/
end_comment

begin_define
define|#
directive|define
name|COR_TYPE_MSC
value|'?'
end_define

begin_comment
comment|/* other, mapped in segment	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TE_I386AIX */
end_comment

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * End:  */
end_comment

begin_comment
comment|/* end of coff.h */
end_comment

end_unit

