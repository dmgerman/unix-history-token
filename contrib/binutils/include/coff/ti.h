begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* COFF information for TI COFF support.  Definitions in this file should be    customized in a target-specific file, and then this file included (see    tic54x.h for an example).        Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COFF_TI_H
end_ifndef

begin_define
define|#
directive|define
name|COFF_TI_H
end_define

begin_comment
comment|/********************** FILE HEADER **********************/
end_comment

begin_struct
struct|struct
name|external_filehdr
block|{
name|char
name|f_magic
index|[
literal|2
index|]
decl_stmt|;
comment|/* magic number			*/
name|char
name|f_nscns
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of sections		*/
name|char
name|f_timdat
index|[
literal|4
index|]
decl_stmt|;
comment|/* time& date stamp		*/
name|char
name|f_symptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* file pointer to symtab	*/
name|char
name|f_nsyms
index|[
literal|4
index|]
decl_stmt|;
comment|/* number of symtab entries	*/
name|char
name|f_opthdr
index|[
literal|2
index|]
decl_stmt|;
comment|/* sizeof(optional hdr)		*/
name|char
name|f_flags
index|[
literal|2
index|]
decl_stmt|;
comment|/* flags			*/
name|char
name|f_target_id
index|[
literal|2
index|]
decl_stmt|;
comment|/* magic no. (TI COFF-specific) */
block|}
struct|;
end_struct

begin_comment
comment|/* COFF0 has magic number in f_magic, and omits f_target_id from the file    header; for later versions, f_magic is 0xC1 for COFF1 and 0xC2 for COFF2    and the target-specific magic number is found in f_target_id */
end_comment

begin_define
define|#
directive|define
name|TICOFF0MAGIC
value|TI_TARGET_ID
end_define

begin_define
define|#
directive|define
name|TICOFF1MAGIC
value|0x00C1
end_define

begin_define
define|#
directive|define
name|TICOFF2MAGIC
value|0x00C2
end_define

begin_define
define|#
directive|define
name|TICOFF_AOUT_MAGIC
value|0x0108
end_define

begin_comment
comment|/* magic number in optional header */
end_comment

begin_define
define|#
directive|define
name|TICOFF
value|1
end_define

begin_comment
comment|/* customize coffcode.h */
end_comment

begin_comment
comment|/* The target_id field changes depending on the particular CPU target */
end_comment

begin_comment
comment|/* for COFF0, the target id appeared in f_magic, where COFFX magic is now */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TI_TARGET_ID
end_ifndef

begin_error
error|#
directive|error
literal|"TI_TARGET_ID needs to be defined for your CPU"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Which bfd_arch to use... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TICOFF_TARGET_ARCH
end_ifndef

begin_error
error|#
directive|error
literal|"TICOFF_TARGET_ARCH needs to be defined for your CPU"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default to COFF2 for file output */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TICOFF_DEFAULT_MAGIC
end_ifndef

begin_define
define|#
directive|define
name|TICOFF_DEFAULT_MAGIC
value|TICOFF2MAGIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This value is made available in the rare case where a bfd is unavailable */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OCTETS_PER_BYTE_POWER
end_ifndef

begin_error
error|#
directive|error
literal|"OCTETS_PER_BYTE_POWER not defined for this CPU"
end_error

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OCTETS_PER_BYTE
value|(1<<OCTETS_PER_BYTE_POWER)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* default alignment is on a byte (not octet!) boundary */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COFF_DEFAULT_SECTION_ALIGNMENT_POWER
end_ifndef

begin_define
define|#
directive|define
name|COFF_DEFAULT_SECTION_ALIGNMENT_POWER
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TI COFF encodes the section alignment in the section header flags */
end_comment

begin_define
define|#
directive|define
name|COFF_ALIGN_IN_SECTION_HEADER
value|1
end_define

begin_define
define|#
directive|define
name|COFF_ALIGN_IN_S_FLAGS
value|1
end_define

begin_comment
comment|/* requires a power-of-two argument */
end_comment

begin_define
define|#
directive|define
name|COFF_ENCODE_ALIGNMENT
parameter_list|(
name|S
parameter_list|,
name|X
parameter_list|)
value|((S).s_flags |= (((unsigned)(X)&0xF)<<8))
end_define

begin_comment
comment|/* result is a power of two */
end_comment

begin_define
define|#
directive|define
name|COFF_DECODE_ALIGNMENT
parameter_list|(
name|X
parameter_list|)
value|(((X)>>8)&0xF)
end_define

begin_define
define|#
directive|define
name|COFF0_P
parameter_list|(
name|ABFD
parameter_list|)
value|(bfd_coff_filhsz(ABFD) == FILHSZ_V0)
end_define

begin_define
define|#
directive|define
name|COFF2_P
parameter_list|(
name|ABFD
parameter_list|)
value|(bfd_coff_scnhsz(ABFD) != SCNHSZ_V01)
end_define

begin_define
define|#
directive|define
name|COFF0_BADMAG
parameter_list|(
name|x
parameter_list|)
value|((x).f_magic != TICOFF0MAGIC)
end_define

begin_define
define|#
directive|define
name|COFF1_BADMAG
parameter_list|(
name|x
parameter_list|)
value|((x).f_magic != TICOFF1MAGIC || (x).f_target_id != TI_TARGET_ID)
end_define

begin_define
define|#
directive|define
name|COFF2_BADMAG
parameter_list|(
name|x
parameter_list|)
value|((x).f_magic != TICOFF2MAGIC || (x).f_target_id != TI_TARGET_ID)
end_define

begin_comment
comment|/* we need to read/write an extra field in the coff file header */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COFF_ADJUST_FILEHDR_IN_POST
end_ifndef

begin_define
define|#
directive|define
name|COFF_ADJUST_FILEHDR_IN_POST
parameter_list|(
name|abfd
parameter_list|,
name|src
parameter_list|,
name|dst
parameter_list|)
define|\
value|do { ((struct internal_filehdr *)(dst))->f_target_id = \ bfd_h_get_16(abfd, (bfd_byte *)(((FILHDR *)(src))->f_target_id)); \ } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|COFF_ADJUST_FILEHDR_OUT_POST
end_ifndef

begin_define
define|#
directive|define
name|COFF_ADJUST_FILEHDR_OUT_POST
parameter_list|(
name|abfd
parameter_list|,
name|src
parameter_list|,
name|dst
parameter_list|)
define|\
value|do { bfd_h_put_16(abfd, ((struct internal_filehdr *)(src))->f_target_id, \              (bfd_byte *)(((FILHDR *)(dst))->f_target_id)); \ } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FILHDR
value|struct external_filehdr
end_define

begin_define
define|#
directive|define
name|FILHSZ
value|22
end_define

begin_define
define|#
directive|define
name|FILHSZ_V0
value|20
end_define

begin_comment
comment|/* COFF0 omits target_id field */
end_comment

begin_comment
comment|/* File header flags */
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

begin_comment
comment|/* F_LSYMS needs to be redefined in your source file */
end_comment

begin_define
define|#
directive|define
name|F_LSYMS_TICOFF
value|(0x0010)
end_define

begin_comment
comment|/* normal COFF is 0x8 */
end_comment

begin_define
define|#
directive|define
name|F_10
value|0x00
end_define

begin_comment
comment|/* file built for TMS320C1x devices */
end_comment

begin_define
define|#
directive|define
name|F_20
value|0x10
end_define

begin_comment
comment|/* file built for TMS320C2x devices */
end_comment

begin_define
define|#
directive|define
name|F_25
value|0x20
end_define

begin_comment
comment|/* file built for TMS320C2x/C5x devices */
end_comment

begin_define
define|#
directive|define
name|F_LENDIAN
value|0x0100
end_define

begin_comment
comment|/* 16 bits/word, LSB first */
end_comment

begin_define
define|#
directive|define
name|F_SYMMERGE
value|0x1000
end_define

begin_comment
comment|/* duplicate symbols were removed */
end_comment

begin_comment
comment|/********************** OPTIONAL HEADER **********************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|magic
index|[
literal|2
index|]
decl_stmt|;
comment|/* type of file (0x108) 		*/
name|char
name|vstamp
index|[
literal|2
index|]
decl_stmt|;
comment|/* version stamp			*/
name|char
name|tsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* text size in bytes, padded to FW bdry*/
name|char
name|dsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* initialized data "  "		*/
name|char
name|bsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* uninitialized data "   "		*/
name|char
name|entry
index|[
literal|4
index|]
decl_stmt|;
comment|/* entry pt.				*/
name|char
name|text_start
index|[
literal|4
index|]
decl_stmt|;
comment|/* base of text used for this file */
name|char
name|data_start
index|[
literal|4
index|]
decl_stmt|;
comment|/* base of data used for this file */
block|}
name|AOUTHDR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AOUTHDRSZ
value|28
end_define

begin_define
define|#
directive|define
name|AOUTSZ
value|28
end_define

begin_comment
comment|/********************** SECTION HEADER **********************/
end_comment

begin_comment
comment|/* COFF0, COFF1 */
end_comment

begin_struct
struct|struct
name|external_scnhdr_v01
block|{
name|char
name|s_name
index|[
literal|8
index|]
decl_stmt|;
comment|/* section name			*/
name|char
name|s_paddr
index|[
literal|4
index|]
decl_stmt|;
comment|/* physical address, aliased s_nlib */
name|char
name|s_vaddr
index|[
literal|4
index|]
decl_stmt|;
comment|/* virtual address		*/
name|char
name|s_size
index|[
literal|4
index|]
decl_stmt|;
comment|/* section size (in WORDS)      */
name|char
name|s_scnptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* file ptr to raw data for section */
name|char
name|s_relptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* file ptr to relocation	*/
name|char
name|s_lnnoptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* file ptr to line numbers	*/
name|char
name|s_nreloc
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of relocation entries	*/
name|char
name|s_nlnno
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of line number entries*/
name|char
name|s_flags
index|[
literal|2
index|]
decl_stmt|;
comment|/* flags			*/
name|char
name|s_reserved
index|[
literal|1
index|]
decl_stmt|;
comment|/* reserved                     */
name|char
name|s_page
index|[
literal|1
index|]
decl_stmt|;
comment|/* section page number (LOAD)   */
block|}
struct|;
end_struct

begin_comment
comment|/* COFF2 */
end_comment

begin_struct
struct|struct
name|external_scnhdr
block|{
name|char
name|s_name
index|[
literal|8
index|]
decl_stmt|;
comment|/* section name			*/
name|char
name|s_paddr
index|[
literal|4
index|]
decl_stmt|;
comment|/* physical address, aliased s_nlib */
name|char
name|s_vaddr
index|[
literal|4
index|]
decl_stmt|;
comment|/* virtual address		*/
name|char
name|s_size
index|[
literal|4
index|]
decl_stmt|;
comment|/* section size (in WORDS)      */
name|char
name|s_scnptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* file ptr to raw data for section */
name|char
name|s_relptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* file ptr to relocation	*/
name|char
name|s_lnnoptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* file ptr to line numbers	*/
name|char
name|s_nreloc
index|[
literal|4
index|]
decl_stmt|;
comment|/* number of relocation entries	*/
name|char
name|s_nlnno
index|[
literal|4
index|]
decl_stmt|;
comment|/* number of line number entries*/
name|char
name|s_flags
index|[
literal|4
index|]
decl_stmt|;
comment|/* flags			*/
name|char
name|s_reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* reserved                     */
name|char
name|s_page
index|[
literal|2
index|]
decl_stmt|;
comment|/* section page number (LOAD)   */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Special section flags  */
end_comment

begin_comment
comment|/* TI COFF defines these flags;     STYP_CLINK: the section should be excluded from the final    linker output if there are no references found to any symbol in the section    STYP_BLOCK: the section should be blocked, i.e. if the section would cross    a page boundary, it is started at a page boundary instead.    TI COFF puts the section alignment power of two in the section flags    e.g. 2**N is alignment, flags |= (N& 0xF)<< 8 */
end_comment

begin_define
define|#
directive|define
name|STYP_CLINK
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|STYP_BLOCK
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|STYP_ALIGN
value|(0x0F00)
end_define

begin_comment
comment|/* TI COFF stores section alignment here */
end_comment

begin_define
define|#
directive|define
name|SCNHDR_V01
value|struct external_scnhdr_v01
end_define

begin_define
define|#
directive|define
name|SCNHDR
value|struct external_scnhdr
end_define

begin_define
define|#
directive|define
name|SCNHSZ_V01
value|40
end_define

begin_comment
comment|/* for v0 and v1 */
end_comment

begin_define
define|#
directive|define
name|SCNHSZ
value|48
end_define

begin_comment
comment|/* COFF2 changes the offsets and sizes of these fields     Assume we're dealing with the COFF2 scnhdr structure, and adjust    accordingly   */
end_comment

begin_define
define|#
directive|define
name|GET_SCNHDR_NRELOC
parameter_list|(
name|ABFD
parameter_list|,
name|PTR
parameter_list|)
define|\
value|(COFF2_P(ABFD) ? bfd_h_get_32 (ABFD,PTR) : bfd_h_get_16 (ABFD, PTR))
end_define

begin_define
define|#
directive|define
name|PUT_SCNHDR_NRELOC
parameter_list|(
name|ABFD
parameter_list|,
name|VAL
parameter_list|,
name|PTR
parameter_list|)
define|\
value|(COFF2_P(ABFD) ? bfd_h_put_32 (ABFD,VAL,PTR) : bfd_h_put_16 (ABFD,VAL,PTR))
end_define

begin_define
define|#
directive|define
name|GET_SCNHDR_NLNNO
parameter_list|(
name|ABFD
parameter_list|,
name|PTR
parameter_list|)
define|\
value|(COFF2_P(ABFD) ? bfd_h_get_32 (ABFD,PTR) : bfd_h_get_16 (ABFD, (PTR)-2))
end_define

begin_define
define|#
directive|define
name|PUT_SCNHDR_NLNNO
parameter_list|(
name|ABFD
parameter_list|,
name|VAL
parameter_list|,
name|PTR
parameter_list|)
define|\
value|(COFF2_P(ABFD) ? bfd_h_put_32 (ABFD,VAL,PTR) : bfd_h_put_16 (ABFD,VAL,(PTR)-2))
end_define

begin_define
define|#
directive|define
name|GET_SCNHDR_FLAGS
parameter_list|(
name|ABFD
parameter_list|,
name|PTR
parameter_list|)
define|\
value|(COFF2_P(ABFD) ? bfd_h_get_32 (ABFD,PTR) : bfd_h_get_16 (ABFD, (PTR)-4))
end_define

begin_define
define|#
directive|define
name|PUT_SCNHDR_FLAGS
parameter_list|(
name|ABFD
parameter_list|,
name|VAL
parameter_list|,
name|PTR
parameter_list|)
define|\
value|(COFF2_P(ABFD) ? bfd_h_put_32 (ABFD,VAL,PTR) : bfd_h_put_16 (ABFD,VAL,(PTR)-4))
end_define

begin_define
define|#
directive|define
name|GET_SCNHDR_PAGE
parameter_list|(
name|ABFD
parameter_list|,
name|PTR
parameter_list|)
define|\
value|(COFF2_P(ABFD) ? bfd_h_get_16 (ABFD,PTR) : bfd_h_get_8 (ABFD, (PTR)-7))
end_define

begin_comment
comment|/* on output, make sure that the "reserved" field is zero */
end_comment

begin_define
define|#
directive|define
name|PUT_SCNHDR_PAGE
parameter_list|(
name|ABFD
parameter_list|,
name|VAL
parameter_list|,
name|PTR
parameter_list|)
define|\
value|(COFF2_P(ABFD) ? bfd_h_put_16 (ABFD,VAL,PTR) : \ bfd_h_put_8 (ABFD,VAL,(PTR)-7), bfd_h_put_8 (ABFD, 0, (PTR)-8))
end_define

begin_comment
comment|/* TI COFF stores section size as number of bytes (address units, not octets),    so adjust to be number of octets, which is what BFD expects */
end_comment

begin_define
define|#
directive|define
name|GET_SCNHDR_SIZE
parameter_list|(
name|ABFD
parameter_list|,
name|SZP
parameter_list|)
define|\
value|(bfd_h_get_32(ABFD,SZP)*bfd_octets_per_byte(ABFD))
end_define

begin_define
define|#
directive|define
name|PUT_SCNHDR_SIZE
parameter_list|(
name|ABFD
parameter_list|,
name|SZ
parameter_list|,
name|SZP
parameter_list|)
define|\
value|bfd_h_put_32(ABFD,(SZ)/bfd_octets_per_byte(ABFD),SZP)
end_define

begin_define
define|#
directive|define
name|COFF_ADJUST_SCNHDR_IN_POST
parameter_list|(
name|ABFD
parameter_list|,
name|EXT
parameter_list|,
name|INT
parameter_list|)
define|\
value|do { ((struct internal_scnhdr *)(INT))->s_page = \ GET_SCNHDR_PAGE(ABFD,(bfd_byte *)((SCNHDR *)(EXT))->s_page); \ } while(0)
end_define

begin_comment
comment|/* The line number and reloc overflow checking in coff_swap_scnhdr_out in    coffswap.h doesn't use PUT_X for s_nlnno and s_nreloc.    Due to different sized v0/v1/v2 section headers, we have to re-write these    fields.  */
end_comment

begin_define
define|#
directive|define
name|COFF_ADJUST_SCNHDR_OUT_POST
parameter_list|(
name|ABFD
parameter_list|,
name|INT
parameter_list|,
name|EXT
parameter_list|)
define|\
value|do { \ PUT_SCNHDR_NLNNO(ABFD,((struct internal_scnhdr *)(INT))->s_nlnno,\                 (bfd_byte *)((SCNHDR *)(EXT))->s_nlnno); \ PUT_SCNHDR_NRELOC(ABFD,((struct internal_scnhdr *)(INT))->s_nreloc,\                 (bfd_byte *)((SCNHDR *)(EXT))->s_nreloc); \ PUT_SCNHDR_FLAGS(ABFD,((struct internal_scnhdr *)(INT))->s_flags, \                 (bfd_byte *)((SCNHDR *)(EXT))->s_flags); \ PUT_SCNHDR_PAGE(ABFD,((struct internal_scnhdr *)(INT))->s_page, \                 (bfd_byte *)((SCNHDR *)(EXT))->s_page); \ } while(0)
end_define

begin_comment
comment|/* Page macros     The first GDB port requires flags in its remote memory access commands to    distinguish between data/prog space.  Hopefully we can make this go away    eventually.  Stuff the page in the upper bits of a 32-bit address, since    the c5x family only uses 16 or 23 bits.     c2x, c5x and most c54x devices have 16-bit addresses, but the c548 has    23-bit program addresses.  Make sure the page flags don't interfere.    These flags are used by GDB to identify the destination page for    addresses.  */
end_comment

begin_comment
comment|/* recognized load pages */
end_comment

begin_define
define|#
directive|define
name|PG_PROG
value|0x0
end_define

begin_comment
comment|/* PROG page */
end_comment

begin_define
define|#
directive|define
name|PG_DATA
value|0x1
end_define

begin_comment
comment|/* DATA page */
end_comment

begin_define
define|#
directive|define
name|ADDR_MASK
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|PG_TO_FLAG
parameter_list|(
name|p
parameter_list|)
value|(((unsigned long)(p)& 0xFF)<< 24)
end_define

begin_define
define|#
directive|define
name|FLAG_TO_PG
parameter_list|(
name|f
parameter_list|)
value|(((f)>> 24)& 0xFF)
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

begin_define
define|#
directive|define
name|_DATA
value|".data"
end_define

begin_define
define|#
directive|define
name|_BSS
value|".bss"
end_define

begin_define
define|#
directive|define
name|_CINIT
value|".cinit"
end_define

begin_comment
comment|/* initialized C data */
end_comment

begin_define
define|#
directive|define
name|_SCONST
value|".const"
end_define

begin_comment
comment|/* constants */
end_comment

begin_define
define|#
directive|define
name|_SWITCH
value|".switch"
end_define

begin_comment
comment|/* switch tables */
end_comment

begin_define
define|#
directive|define
name|_STACK
value|".stack"
end_define

begin_comment
comment|/* C stack */
end_comment

begin_define
define|#
directive|define
name|_SYSMEM
value|".sysmem"
end_define

begin_comment
comment|/* used for malloc et al. syscalls */
end_comment

begin_comment
comment|/********************** LINE NUMBERS **********************/
end_comment

begin_comment
comment|/* 1 line number entry for every "breakpointable" source line in a section.  * Line numbers are grouped on a per function basis; first entry in a function  * grouping will have l_lnno = 0 and in place of physical address will be the  * symbol table index of the function name.  */
end_comment

begin_struct
struct|struct
name|external_lineno
block|{
union|union
block|{
name|char
name|l_symndx
index|[
literal|4
index|]
decl_stmt|;
comment|/* function name symbol index, iff l_lnno == 0*/
name|char
name|l_paddr
index|[
literal|4
index|]
decl_stmt|;
comment|/* (physical) address of line number	*/
block|}
name|l_addr
union|;
name|char
name|l_lnno
index|[
literal|2
index|]
decl_stmt|;
comment|/* line number		*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LINENO
value|struct external_lineno
end_define

begin_define
define|#
directive|define
name|LINESZ
value|6
end_define

begin_comment
comment|/********************** SYMBOLS **********************/
end_comment

begin_comment
comment|/* NOTE: this is what a local label looks like in assembly source; what it    looks like in COFF output is undefined */
end_comment

begin_define
define|#
directive|define
name|TICOFF_LOCAL_LABEL_P
parameter_list|(
name|NAME
parameter_list|)
define|\
value|((NAME[0] == '$'&& NAME[1]>= '0'&& NAME[1]<= '9'&& NAME[2] == '\0') \  || NAME[strlen(NAME)-1] == '?')
end_define

begin_define
define|#
directive|define
name|E_SYMNMLEN
value|8
end_define

begin_comment
comment|/* # characters in a symbol name	*/
end_comment

begin_define
define|#
directive|define
name|E_FILNMLEN
value|14
end_define

begin_comment
comment|/* # characters in a file name		*/
end_comment

begin_define
define|#
directive|define
name|E_DIMNUM
value|4
end_define

begin_comment
comment|/* # array dimensions in auxiliary entry */
end_comment

begin_struct
struct|struct
name|external_syment
block|{
union|union
block|{
name|char
name|e_name
index|[
name|E_SYMNMLEN
index|]
decl_stmt|;
struct|struct
block|{
name|char
name|e_zeroes
index|[
literal|4
index|]
decl_stmt|;
name|char
name|e_offset
index|[
literal|4
index|]
decl_stmt|;
block|}
name|e
struct|;
block|}
name|e
union|;
name|char
name|e_value
index|[
literal|4
index|]
decl_stmt|;
name|char
name|e_scnum
index|[
literal|2
index|]
decl_stmt|;
name|char
name|e_type
index|[
literal|2
index|]
decl_stmt|;
name|char
name|e_sclass
index|[
literal|1
index|]
decl_stmt|;
name|char
name|e_numaux
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
name|N_BTMASK
value|(017)
end_define

begin_define
define|#
directive|define
name|N_TMASK
value|(060)
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

begin_union
union|union
name|external_auxent
block|{
struct|struct
block|{
name|char
name|x_tagndx
index|[
literal|4
index|]
decl_stmt|;
comment|/* str, un, or enum tag indx */
union|union
block|{
struct|struct
block|{
name|char
name|x_lnno
index|[
literal|2
index|]
decl_stmt|;
comment|/* declaration line number */
name|char
name|x_size
index|[
literal|2
index|]
decl_stmt|;
comment|/* str/union/array size */
block|}
name|x_lnsz
struct|;
name|char
name|x_fsize
index|[
literal|4
index|]
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
name|char
name|x_lnnoptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* ptr to fcn line # */
name|char
name|x_endndx
index|[
literal|4
index|]
decl_stmt|;
comment|/* entry ndx past block end */
block|}
name|x_fcn
struct|;
struct|struct
block|{
comment|/* if ISARY, up to 4 dimen. */
name|char
name|x_dimen
index|[
name|E_DIMNUM
index|]
index|[
literal|2
index|]
decl_stmt|;
block|}
name|x_ary
struct|;
block|}
name|x_fcnary
union|;
name|char
name|x_tvndx
index|[
literal|2
index|]
decl_stmt|;
comment|/* tv index */
block|}
name|x_sym
struct|;
union|union
block|{
name|char
name|x_fname
index|[
name|E_FILNMLEN
index|]
decl_stmt|;
struct|struct
block|{
name|char
name|x_zeroes
index|[
literal|4
index|]
decl_stmt|;
name|char
name|x_offset
index|[
literal|4
index|]
decl_stmt|;
block|}
name|x_n
struct|;
block|}
name|x_file
union|;
struct|struct
block|{
name|char
name|x_scnlen
index|[
literal|4
index|]
decl_stmt|;
comment|/* section length */
name|char
name|x_nreloc
index|[
literal|2
index|]
decl_stmt|;
comment|/* # relocation entries */
name|char
name|x_nlinno
index|[
literal|2
index|]
decl_stmt|;
comment|/* # line numbers */
block|}
name|x_scn
struct|;
struct|struct
block|{
name|char
name|x_tvfill
index|[
literal|4
index|]
decl_stmt|;
comment|/* tv fill value */
name|char
name|x_tvlen
index|[
literal|2
index|]
decl_stmt|;
comment|/* length of .tv */
name|char
name|x_tvran
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|;
comment|/* tv range */
block|}
name|x_tv
struct|;
comment|/* info about .tv section (in auxent of symbol .tv)) */
block|}
union|;
end_union

begin_define
define|#
directive|define
name|SYMENT
value|struct external_syment
end_define

begin_define
define|#
directive|define
name|SYMESZ
value|18
end_define

begin_define
define|#
directive|define
name|AUXENT
value|union external_auxent
end_define

begin_define
define|#
directive|define
name|AUXESZ
value|18
end_define

begin_comment
comment|/* section lengths are in target bytes (not host bytes) */
end_comment

begin_define
define|#
directive|define
name|GET_SCN_SCNLEN
parameter_list|(
name|ABFD
parameter_list|,
name|EXT
parameter_list|)
define|\
value|(bfd_h_get_32(ABFD,(bfd_byte *)(EXT)->x_scn.x_scnlen)*bfd_octets_per_byte(ABFD))
end_define

begin_define
define|#
directive|define
name|PUT_SCN_SCNLEN
parameter_list|(
name|ABFD
parameter_list|,
name|INT
parameter_list|,
name|EXT
parameter_list|)
define|\
value|bfd_h_put_32(ABFD,(INT)/bfd_octets_per_byte(ABFD),\              (bfd_byte *)(EXT)->x_scn.x_scnlen)
end_define

begin_comment
comment|/* lnsz size is in bits in COFF file, in bytes in BFD */
end_comment

begin_define
define|#
directive|define
name|GET_LNSZ_SIZE
parameter_list|(
name|abfd
parameter_list|,
name|ext
parameter_list|)
define|\
value|(bfd_h_get_16(abfd, (bfd_byte *)ext->x_sym.x_misc.x_lnsz.x_size) / \  (class != C_FIELD ? 8 : 1))
end_define

begin_define
define|#
directive|define
name|PUT_LNSZ_SIZE
parameter_list|(
name|abfd
parameter_list|,
name|in
parameter_list|,
name|ext
parameter_list|)
define|\
value|bfd_h_put_16(abfd, ((class != C_FIELD) ? (in)*8 : (in)), \               (bfd_byte*) ext->x_sym.x_misc.x_lnsz.x_size)
end_define

begin_comment
comment|/* TI COFF stores offsets for MOS and MOU in bits; BFD expects bytes */
end_comment

begin_define
define|#
directive|define
name|COFF_ADJUST_SYM_IN_POST
parameter_list|(
name|ABFD
parameter_list|,
name|EXT
parameter_list|,
name|INT
parameter_list|)
define|\
value|do { struct internal_syment *dst = (struct internal_syment *)(INT); \ if (dst->n_sclass == C_MOS || dst->n_sclass == C_MOU) dst->n_value /= 8; \ } while (0)
end_define

begin_define
define|#
directive|define
name|COFF_ADJUST_SYM_OUT_POST
parameter_list|(
name|ABFD
parameter_list|,
name|INT
parameter_list|,
name|EXT
parameter_list|)
define|\
value|do { struct internal_syment *src = (struct internal_syment *)(INT); \ SYMENT *dst = (SYMENT *)(EXT); \ if(src->n_sclass == C_MOU || src->n_sclass == C_MOS) \ bfd_h_put_32(abfd,src->n_value * 8,(bfd_byte *)dst->e_value); \ } while (0)
end_define

begin_comment
comment|/* Detect section-relative absolute symbols so they get flagged with a sym    index of -1. */
end_comment

begin_define
define|#
directive|define
name|SECTION_RELATIVE_ABSOLUTE_SYMBOL_P
parameter_list|(
name|RELOC
parameter_list|,
name|SECT
parameter_list|)
define|\
value|((*(RELOC)->sym_ptr_ptr)->section->output_section == (SECT) \&& (RELOC)->howto->name[0] == 'A')
end_define

begin_comment
comment|/********************** RELOCATION DIRECTIVES **********************/
end_comment

begin_struct
struct|struct
name|external_reloc_v0
block|{
name|char
name|r_vaddr
index|[
literal|4
index|]
decl_stmt|;
name|char
name|r_symndx
index|[
literal|2
index|]
decl_stmt|;
name|char
name|r_reserved
index|[
literal|2
index|]
decl_stmt|;
name|char
name|r_type
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|external_reloc
block|{
name|char
name|r_vaddr
index|[
literal|4
index|]
decl_stmt|;
name|char
name|r_symndx
index|[
literal|4
index|]
decl_stmt|;
name|char
name|r_reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* extended pmad byte for COFF2 */
name|char
name|r_type
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RELOC
value|struct external_reloc
end_define

begin_define
define|#
directive|define
name|RELSZ_V0
value|10
end_define

begin_comment
comment|/* FIXME -- coffcode.h needs fixing */
end_comment

begin_define
define|#
directive|define
name|RELSZ
value|12
end_define

begin_comment
comment|/* for COFF1/2 */
end_comment

begin_comment
comment|/* various relocation types.  */
end_comment

begin_define
define|#
directive|define
name|R_ABS
value|0x0000
end_define

begin_comment
comment|/* no relocation */
end_comment

begin_define
define|#
directive|define
name|R_REL13
value|0x002A
end_define

begin_comment
comment|/* 13-bit direct reference (???) */
end_comment

begin_define
define|#
directive|define
name|R_PARTLS7
value|0x0028
end_define

begin_comment
comment|/* 7 LSBs of an address */
end_comment

begin_define
define|#
directive|define
name|R_PARTMS9
value|0x0029
end_define

begin_comment
comment|/* 9MSBs of an address */
end_comment

begin_define
define|#
directive|define
name|R_EXTWORD
value|0x002B
end_define

begin_comment
comment|/* 23-bit direct reference */
end_comment

begin_define
define|#
directive|define
name|R_EXTWORD16
value|0x002C
end_define

begin_comment
comment|/* 16-bit direct reference to 23-bit addr*/
end_comment

begin_define
define|#
directive|define
name|R_EXTWORDMS7
value|0x002D
end_define

begin_comment
comment|/* upper 7 bits of 23-bit address */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COFF_TI_H */
end_comment

end_unit

