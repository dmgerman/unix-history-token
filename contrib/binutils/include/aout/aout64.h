begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* `a.out' object-file definitions, including extensions to 64-bit fields     Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__A_OUT_64_H__
end_ifndef

begin_define
define|#
directive|define
name|__A_OUT_64_H__
end_define

begin_comment
comment|/* This is the layout on disk of the 32-bit or 64-bit exec header. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|external_exec
end_ifndef

begin_struct
struct|struct
name|external_exec
block|{
name|bfd_byte
name|e_info
index|[
literal|4
index|]
decl_stmt|;
comment|/* magic number and stuff		*/
name|bfd_byte
name|e_text
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* length of text section in bytes	*/
name|bfd_byte
name|e_data
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* length of data section in bytes	*/
name|bfd_byte
name|e_bss
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* length of bss area in bytes 		*/
name|bfd_byte
name|e_syms
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* length of symbol table in bytes 	*/
name|bfd_byte
name|e_entry
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* start address 			*/
name|bfd_byte
name|e_trsize
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* length of text relocation info	*/
name|bfd_byte
name|e_drsize
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* length of data relocation info 	*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EXEC_BYTES_SIZE
value|(4 + BYTES_IN_WORD * 7)
end_define

begin_comment
comment|/* Magic numbers for a.out files */
end_comment

begin_if
if|#
directive|if
name|ARCH_SIZE
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|OMAGIC
value|0x1001
end_define

begin_comment
comment|/* Code indicating object file  */
end_comment

begin_define
define|#
directive|define
name|ZMAGIC
value|0x1002
end_define

begin_comment
comment|/* Code indicating demand-paged executable.  */
end_comment

begin_define
define|#
directive|define
name|NMAGIC
value|0x1003
end_define

begin_comment
comment|/* Code indicating pure executable.  */
end_comment

begin_comment
comment|/* There is no 64-bit QMAGIC as far as I know.  */
end_comment

begin_define
define|#
directive|define
name|N_BADMAG
parameter_list|(
name|x
parameter_list|)
value|(N_MAGIC(x) != OMAGIC		\&& N_MAGIC(x) != NMAGIC		\&& N_MAGIC(x) != ZMAGIC)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OMAGIC
value|0407
end_define

begin_comment
comment|/* ...object file or impure executable.  */
end_comment

begin_define
define|#
directive|define
name|NMAGIC
value|0410
end_define

begin_comment
comment|/* Code indicating pure executable.  */
end_comment

begin_define
define|#
directive|define
name|ZMAGIC
value|0413
end_define

begin_comment
comment|/* Code indicating demand-paged executable.  */
end_comment

begin_define
define|#
directive|define
name|BMAGIC
value|0415
end_define

begin_comment
comment|/* Used by a b.out object.  */
end_comment

begin_comment
comment|/* This indicates a demand-paged executable with the header in the text.    It is used by 386BSD (and variants) and Linux, at least.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QMAGIC
end_ifndef

begin_define
define|#
directive|define
name|QMAGIC
value|0314
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
value|(N_MAGIC(x) != OMAGIC		\&& N_MAGIC(x) != NMAGIC		\&& N_MAGIC(x) != ZMAGIC \&& N_MAGIC(x) != QMAGIC)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* N_BADMAG */
end_comment

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
name|QMAGIC
end_ifdef

begin_define
define|#
directive|define
name|N_IS_QMAGIC
parameter_list|(
name|x
parameter_list|)
value|(N_MAGIC (x) == QMAGIC)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|N_IS_QMAGIC
parameter_list|(
name|x
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The difference between TARGET_PAGE_SIZE and N_SEGSIZE is that TARGET_PAGE_SIZE is    the finest granularity at which you can page something, thus it    controls the padding (if any) before the text segment of a ZMAGIC    file.  N_SEGSIZE is the resolution at which things can be marked as    read-only versus read/write, so it controls the padding between the    text segment and the data segment (in memory; on disk the padding    between them is TARGET_PAGE_SIZE).  TARGET_PAGE_SIZE and N_SEGSIZE are the same    for most machines, but different for sun3.  */
end_comment

begin_comment
comment|/* By default, segment size is constant.  But some machines override this    to be a function of the a.out header (e.g. machine type).  */
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

begin_escape
end_escape

begin_comment
comment|/* Virtual memory address of the text section.    This is getting very complicated.  A good reason to discard a.out format    for something that specifies these fields explicitly.  But til then...     * OMAGIC and NMAGIC files:        (object files: text for "relocatable addr 0" right after the header)        start at 0, offset is EXEC_BYTES_SIZE, size as stated.    * The text address, offset, and size of ZMAGIC files depend      on the entry point of the file:      * entry point below TEXT_START_ADDR:        (hack for SunOS shared libraries)        start at 0, offset is 0, size as stated.      * If N_HEADER_IN_TEXT(x) is true (which defaults to being the        case when the entry point is EXEC_BYTES_SIZE or further into a page):        no padding is needed; text can start after exec header.  Sun        considers the text segment of such files to include the exec header;        for BFD's purposes, we don't, which makes more work for us.        start at TEXT_START_ADDR + EXEC_BYTES_SIZE, offset is EXEC_BYTES_SIZE,        size as stated minus EXEC_BYTES_SIZE.      * If N_HEADER_IN_TEXT(x) is false (which defaults to being the case when        the entry point is less than EXEC_BYTES_SIZE into a page (e.g. page        aligned)): (padding is needed so that text can start at a page boundary)        start at TEXT_START_ADDR, offset TARGET_PAGE_SIZE, size as stated.      Specific configurations may want to hardwire N_HEADER_IN_TEXT,     for efficiency or to allow people to play games with the entry point.     In that case, you would #define N_HEADER_IN_TEXT(x) as 1 for sunos,     and as 0 for most other hosts (Sony News, Vax Ultrix, etc).     (Do this in the appropriate bfd target file.)     (The default is a heuristic that will break if people try changing     the entry point, perhaps with the ld -e flag.)      * QMAGIC is always like a ZMAGIC for which N_HEADER_IN_TEXT is true,     and for which the starting address is TARGET_PAGE_SIZE (or should this be     SEGMENT_SIZE?) (TEXT_START_ADDR only applies to ZMAGIC, not to QMAGIC).     */
end_comment

begin_comment
comment|/* This macro is only relevant for ZMAGIC files; QMAGIC always has the header    in the text.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_HEADER_IN_TEXT
end_ifndef

begin_define
define|#
directive|define
name|N_HEADER_IN_TEXT
parameter_list|(
name|x
parameter_list|)
value|(((x).a_entry& (TARGET_PAGE_SIZE-1))>= EXEC_BYTES_SIZE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sun shared libraries, not linux.  This macro is only relevant for ZMAGIC    files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_SHARED_LIB
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TEXT_START_ADDR
argument_list|)
operator|&&
name|TEXT_START_ADDR
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|N_SHARED_LIB
parameter_list|(
name|x
parameter_list|)
value|(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|N_SHARED_LIB
parameter_list|(
name|x
parameter_list|)
value|((x).a_entry< TEXT_START_ADDR)
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
comment|/* Returning 0 not TEXT_START_ADDR for OMAGIC and NMAGIC is based on    the assumption that we are dealing with a .o file, not an    executable.  This is necessary for OMAGIC (but means we don't work    right on the output from ld -N); more questionable for NMAGIC.  */
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
define|\
value|(
comment|/* The address of a QMAGIC file is always one page in, */
value|\
comment|/* with the header in the text.  */
value|\      N_IS_QMAGIC (x) ? TARGET_PAGE_SIZE + EXEC_BYTES_SIZE : \      N_MAGIC(x) != ZMAGIC ? 0 :
comment|/* object file or NMAGIC */
value|\      N_SHARED_LIB(x) ? 0 :	\      N_HEADER_IN_TEXT(x)  ?	\ 	    TEXT_START_ADDR + EXEC_BYTES_SIZE :
comment|/* no padding */
value|\ 	    TEXT_START_ADDR
comment|/* a page of padding */
value|\     )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If N_HEADER_IN_TEXT is not true for ZMAGIC, there is some padding    to make the text segment start at a certain boundary.  For most    systems, this boundary is TARGET_PAGE_SIZE.  But for Linux, in the    time-honored tradition of crazy ZMAGIC hacks, it is 1024 which is    not what TARGET_PAGE_SIZE needs to be for QMAGIC.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ZMAGIC_DISK_BLOCK_SIZE
end_ifndef

begin_define
define|#
directive|define
name|ZMAGIC_DISK_BLOCK_SIZE
value|TARGET_PAGE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|N_DISK_BLOCK_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(N_MAGIC(x) == ZMAGIC ? ZMAGIC_DISK_BLOCK_SIZE : TARGET_PAGE_SIZE)
end_define

begin_comment
comment|/* Offset in an a.out of the start of the text section. */
end_comment

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
define|\
value|(
comment|/* For {O,N,Q}MAGIC, no padding.  */
value|\      N_MAGIC(x) != ZMAGIC ? EXEC_BYTES_SIZE : \      N_SHARED_LIB(x) ? 0 : \      N_HEADER_IN_TEXT(x) ?	\ 	    EXEC_BYTES_SIZE :
comment|/* no padding */
value|\ 	    ZMAGIC_DISK_BLOCK_SIZE
comment|/* a page of padding */
value|\     )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Size of the text section.  It's always as stated, except that we    offset it to `undo' the adjustment to N_TXTADDR and N_TXTOFF    for ZMAGIC files that nominally include the exec header    as part of the first page of text.  (BFD doesn't consider the    exec header to be part of the text segment.)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_TXTSIZE
end_ifndef

begin_define
define|#
directive|define
name|N_TXTSIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(
comment|/* For QMAGIC, we don't consider the header part of the text section.  */
value|\      N_IS_QMAGIC (x) ? (x).a_text - EXEC_BYTES_SIZE : \      (N_MAGIC(x) != ZMAGIC || N_SHARED_LIB(x)) ? (x).a_text : \      N_HEADER_IN_TEXT(x)  ?	\ 	    (x).a_text - EXEC_BYTES_SIZE:
comment|/* no padding */
value|\ 	    (x).a_text
comment|/* a page of padding */
value|\     )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The address of the data segment in virtual memory.    It is the text segment address, plus text segment size, rounded    up to a N_SEGSIZE boundary for pure or pageable files. */
end_comment

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
value|(N_MAGIC(x)==OMAGIC? (N_TXTADDR(x)+N_TXTSIZE(x)) \      :  (N_SEGSIZE(x) + ((N_TXTADDR(x)+N_TXTSIZE(x)-1)& ~(N_SEGSIZE(x)-1))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The address of the BSS segment -- immediately after the data segment.  */
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

begin_comment
comment|/* Offsets of the various portions of the file after the text segment.  */
end_comment

begin_comment
comment|/* For {Q,Z}MAGIC, there is padding to make the data segment start on    a page boundary.  Most of the time the a_text field (and thus    N_TXTSIZE) already contains this padding.  It is possible that for    BSDI and/or 386BSD it sometimes doesn't contain the padding, and    perhaps we should be adding it here.  But this seems kind of    questionable and probably should be BSDI/386BSD-specific if we do    do it.     For NMAGIC (at least for hp300 BSD, probably others), there is    padding in memory only, not on disk, so we must *not* ever pad here    for NMAGIC.  */
end_comment

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
define|\
value|(N_TXTOFF(x) + N_TXTSIZE(x))
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

begin_escape
end_escape

begin_comment
comment|/* Symbols */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|external_nlist
end_ifndef

begin_struct
struct|struct
name|external_nlist
block|{
name|bfd_byte
name|e_strx
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* index into string table of name */
name|bfd_byte
name|e_type
index|[
literal|1
index|]
decl_stmt|;
comment|/* type of symbol */
name|bfd_byte
name|e_other
index|[
literal|1
index|]
decl_stmt|;
comment|/* misc info (usually empty) */
name|bfd_byte
name|e_desc
index|[
literal|2
index|]
decl_stmt|;
comment|/* description field */
name|bfd_byte
name|e_value
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* value of symbol */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EXTERNAL_NLIST_SIZE
value|(BYTES_IN_WORD+4+BYTES_IN_WORD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|internal_nlist
block|{
name|unsigned
name|long
name|n_strx
decl_stmt|;
comment|/* index into string table of name */
name|unsigned
name|char
name|n_type
decl_stmt|;
comment|/* type of symbol */
name|unsigned
name|char
name|n_other
decl_stmt|;
comment|/* misc info (usually empty) */
name|unsigned
name|short
name|n_desc
decl_stmt|;
comment|/* description field */
name|bfd_vma
name|n_value
decl_stmt|;
comment|/* value of symbol */
block|}
struct|;
end_struct

begin_comment
comment|/* The n_type field is the symbol type, containing:  */
end_comment

begin_define
define|#
directive|define
name|N_UNDF
value|0
end_define

begin_comment
comment|/* Undefined symbol */
end_comment

begin_define
define|#
directive|define
name|N_ABS
value|2
end_define

begin_comment
comment|/* Absolute symbol -- defined at particular addr */
end_comment

begin_define
define|#
directive|define
name|N_TEXT
value|4
end_define

begin_comment
comment|/* Text sym -- defined at offset in text seg */
end_comment

begin_define
define|#
directive|define
name|N_DATA
value|6
end_define

begin_comment
comment|/* Data sym -- defined at offset in data seg */
end_comment

begin_define
define|#
directive|define
name|N_BSS
value|8
end_define

begin_comment
comment|/* BSS  sym -- defined at offset in zero'd seg */
end_comment

begin_define
define|#
directive|define
name|N_COMM
value|0x12
end_define

begin_comment
comment|/* Common symbol (visible after shared lib dynlink) */
end_comment

begin_define
define|#
directive|define
name|N_FN
value|0x1f
end_define

begin_comment
comment|/* File name of .o file */
end_comment

begin_define
define|#
directive|define
name|N_FN_SEQ
value|0x0C
end_define

begin_comment
comment|/* N_FN from Sequent compilers (sigh) */
end_comment

begin_comment
comment|/* Note: N_EXT can only be usefully OR-ed with N_UNDF, N_ABS, N_TEXT,    N_DATA, or N_BSS.  When the low-order bit of other types is set,    (e.g. N_WARNING versus N_FN), they are two different types.  */
end_comment

begin_define
define|#
directive|define
name|N_EXT
value|1
end_define

begin_comment
comment|/* External symbol (as opposed to local-to-this-file) */
end_comment

begin_define
define|#
directive|define
name|N_TYPE
value|0x1e
end_define

begin_define
define|#
directive|define
name|N_STAB
value|0xe0
end_define

begin_comment
comment|/* If any of these bits are on, it's a debug symbol */
end_comment

begin_define
define|#
directive|define
name|N_INDR
value|0x0a
end_define

begin_comment
comment|/* The following symbols refer to set elements.    All the N_SET[ATDB] symbols with the same name form one set.    Space is allocated for the set in the text section, and each set    elements value is stored into one word of the space.    The first word of the space is the length of the set (number of elements).     The address of the set is made into an N_SETV symbol    whose name is the same as the name of the set.    This symbol acts like a N_DATA global symbol    in that it can satisfy undefined external references.  */
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

begin_comment
comment|/* Relocations     There	are two types of relocation flavours for a.out systems,   standard and extended. The standard form is used on systems where the   instruction has room for all the bits of an offset to the operand, whilst   the extended form is used when an address operand has to be split over n   instructions. Eg, on the 68k, each move instruction can reference   the target with a displacement of 16 or 32 bits. On the sparc, move   instructions use an offset of 14 bits, so the offset is stored in   the reloc field, and the data in the section is ignored. */
end_comment

begin_comment
comment|/* This structure describes a single relocation to be performed.    The text-relocation section of the file is a vector of these structures,    all of which apply to the text section.    Likewise, the data-relocation section applies to the data section.  */
end_comment

begin_struct
struct|struct
name|reloc_std_external
block|{
name|bfd_byte
name|r_address
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* offset of of data to relocate 	*/
name|bfd_byte
name|r_index
index|[
literal|3
index|]
decl_stmt|;
comment|/* symbol table index of symbol 	*/
name|bfd_byte
name|r_type
index|[
literal|1
index|]
decl_stmt|;
comment|/* relocation type			*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RELOC_STD_BITS_PCREL_BIG
value|((unsigned int) 0x80)
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_PCREL_LITTLE
value|((unsigned int) 0x01)
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_LENGTH_BIG
value|((unsigned int) 0x60)
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_LENGTH_SH_BIG
value|5
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_LENGTH_LITTLE
value|((unsigned int) 0x06)
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
value|((unsigned int) 0x10)
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_EXTERN_LITTLE
value|((unsigned int) 0x08)
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_BASEREL_BIG
value|((unsigned int) 0x08)
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_BASEREL_LITTLE
value|((unsigned int) 0x10)
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_JMPTABLE_BIG
value|((unsigned int) 0x04)
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_JMPTABLE_LITTLE
value|((unsigned int) 0x20)
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_RELATIVE_BIG
value|((unsigned int) 0x02)
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_RELATIVE_LITTLE
value|((unsigned int) 0x40)
end_define

begin_define
define|#
directive|define
name|RELOC_STD_SIZE
value|(BYTES_IN_WORD + 3 + 1)
end_define

begin_comment
comment|/* Bytes per relocation entry */
end_comment

begin_struct
struct|struct
name|reloc_std_internal
block|{
name|bfd_vma
name|r_address
decl_stmt|;
comment|/* Address (within segment) to be relocated.  */
comment|/* The meaning of r_symbolnum depends on r_extern.  */
name|unsigned
name|int
name|r_symbolnum
range|:
literal|24
decl_stmt|;
comment|/* Nonzero means value is a pc-relative offset      and it should be relocated for changes in its own address      as well as for changes in the symbol or section specified.  */
name|unsigned
name|int
name|r_pcrel
range|:
literal|1
decl_stmt|;
comment|/* Length (as exponent of 2) of the field to be relocated.      Thus, a value of 2 indicates 1<<2 bytes.  */
name|unsigned
name|int
name|r_length
range|:
literal|2
decl_stmt|;
comment|/* 1 => relocate with value of symbol.      r_symbolnum is the index of the symbol      in files the symbol table.      0 => relocate with the address of a segment.      r_symbolnum is N_TEXT, N_DATA, N_BSS or N_ABS      (the N_EXT bit may be set also, but signifies nothing).  */
name|unsigned
name|int
name|r_extern
range|:
literal|1
decl_stmt|;
comment|/* The next three bits are for SunOS shared libraries, and seem to      be undocumented.  */
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

begin_comment
comment|/* EXTENDED RELOCS  */
end_comment

begin_struct
struct|struct
name|reloc_ext_external
block|{
name|bfd_byte
name|r_address
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* offset of of data to relocate 	*/
name|bfd_byte
name|r_index
index|[
literal|3
index|]
decl_stmt|;
comment|/* symbol table index of symbol 	*/
name|bfd_byte
name|r_type
index|[
literal|1
index|]
decl_stmt|;
comment|/* relocation type			*/
name|bfd_byte
name|r_addend
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* datum addend				*/
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|RELOC_EXT_BITS_EXTERN_BIG
end_ifndef

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_EXTERN_BIG
value|((unsigned int) 0x80)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RELOC_EXT_BITS_EXTERN_LITTLE
end_ifndef

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_EXTERN_LITTLE
value|((unsigned int) 0x01)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RELOC_EXT_BITS_TYPE_BIG
end_ifndef

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_TYPE_BIG
value|((unsigned int) 0x1F)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RELOC_EXT_BITS_TYPE_SH_BIG
end_ifndef

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_TYPE_SH_BIG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RELOC_EXT_BITS_TYPE_LITTLE
end_ifndef

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_TYPE_LITTLE
value|((unsigned int) 0xF8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RELOC_EXT_BITS_TYPE_SH_LITTLE
end_ifndef

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_TYPE_SH_LITTLE
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Bytes per relocation entry */
end_comment

begin_define
define|#
directive|define
name|RELOC_EXT_SIZE
value|(BYTES_IN_WORD + 3 + 1 + BYTES_IN_WORD)
end_define

begin_enum
enum|enum
name|reloc_type
block|{
comment|/* simple relocations */
name|RELOC_8
block|,
comment|/* data[0:7] = addend + sv 		*/
name|RELOC_16
block|,
comment|/* data[0:15] = addend + sv 		*/
name|RELOC_32
block|,
comment|/* data[0:31] = addend + sv 		*/
comment|/* pc-rel displacement */
name|RELOC_DISP8
block|,
comment|/* data[0:7] = addend - pc + sv 	*/
name|RELOC_DISP16
block|,
comment|/* data[0:15] = addend - pc + sv 	*/
name|RELOC_DISP32
block|,
comment|/* data[0:31] = addend - pc + sv 	*/
comment|/* Special */
name|RELOC_WDISP30
block|,
comment|/* data[0:29] = (addend + sv - pc)>>2 	*/
name|RELOC_WDISP22
block|,
comment|/* data[0:21] = (addend + sv - pc)>>2 	*/
name|RELOC_HI22
block|,
comment|/* data[0:21] = (addend + sv)>>10 	*/
name|RELOC_22
block|,
comment|/* data[0:21] = (addend + sv) 		*/
name|RELOC_13
block|,
comment|/* data[0:12] = (addend + sv)		*/
name|RELOC_LO10
block|,
comment|/* data[0:9] = (addend + sv)		*/
name|RELOC_SFA_BASE
block|,
name|RELOC_SFA_OFF13
block|,
comment|/* P.I.C. (base-relative) */
name|RELOC_BASE10
block|,
comment|/* Not sure - maybe we can do this the */
name|RELOC_BASE13
block|,
comment|/* right way now */
name|RELOC_BASE22
block|,
comment|/* for some sort of pc-rel P.I.C. (?) */
name|RELOC_PC10
block|,
name|RELOC_PC22
block|,
comment|/* P.I.C. jump table */
name|RELOC_JMP_TBL
block|,
comment|/* reputedly for shared libraries somehow */
name|RELOC_SEGOFF16
block|,
name|RELOC_GLOB_DAT
block|,
name|RELOC_JMP_SLOT
block|,
name|RELOC_RELATIVE
block|,
name|RELOC_11
block|,
name|RELOC_WDISP2_14
block|,
name|RELOC_WDISP19
block|,
name|RELOC_HHI22
block|,
comment|/* data[0:21] = (addend + sv)>> 42     */
name|RELOC_HLO10
block|,
comment|/* data[0:9] = (addend + sv)>> 32      */
comment|/* 29K relocation types */
name|RELOC_JUMPTARG
block|,
name|RELOC_CONST
block|,
name|RELOC_CONSTH
block|,
comment|/* All the new ones I can think of, for sparc v9 */
name|RELOC_64
block|,
comment|/* data[0:63] = addend + sv 		*/
name|RELOC_DISP64
block|,
comment|/* data[0:63] = addend - pc + sv 	*/
name|RELOC_WDISP21
block|,
comment|/* data[0:20] = (addend + sv - pc)>>2 	*/
name|RELOC_DISP21
block|,
comment|/* data[0:20] = addend - pc + sv        */
name|RELOC_DISP14
block|,
comment|/* data[0:13] = addend - pc + sv 	*/
comment|/* Q .      What are the other ones,      Since this is a clean slate, can we throw away the ones we dont      understand ? Should we sort the values ? What about using a      microcode format like the 68k ?      */
name|NO_RELOC
block|}
enum|;
end_enum

begin_struct
struct|struct
name|reloc_internal
block|{
name|bfd_vma
name|r_address
decl_stmt|;
comment|/* offset of of data to relocate 	*/
name|long
name|r_index
decl_stmt|;
comment|/* symbol table index of symbol 	*/
name|enum
name|reloc_type
name|r_type
decl_stmt|;
comment|/* relocation type			*/
name|bfd_vma
name|r_addend
decl_stmt|;
comment|/* datum addend				*/
block|}
struct|;
end_struct

begin_comment
comment|/* Q.    Should the length of the string table be 4 bytes or 8 bytes ?     Q.    What about archive indexes ?   */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __A_OUT_64_H__ */
end_comment

end_unit

