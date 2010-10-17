begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* coff information for TI TMS320C80 (MVP)        Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|DO_NOT_DEFINE_FILHDR
end_define

begin_define
define|#
directive|define
name|DO_NOT_DEFINE_SCNHDR
end_define

begin_define
define|#
directive|define
name|L_LNNO_SIZE
value|2
end_define

begin_include
include|#
directive|include
file|"coff/external.h"
end_include

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
comment|/* target id (TIc80 specific)	*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TIC80_ARCH_MAGIC
value|0x0C1
end_define

begin_comment
comment|/* Goes in the file header magic number field */
end_comment

begin_define
define|#
directive|define
name|TIC80_TARGET_ID
value|0x95
end_define

begin_comment
comment|/* Goes in the target id field */
end_comment

begin_define
define|#
directive|define
name|TIC80BADMAG
parameter_list|(
name|x
parameter_list|)
value|((x).f_magic != TIC80_ARCH_MAGIC)
end_define

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
name|TIC80_AOUTHDR_MAGIC
value|0x108
end_define

begin_comment
comment|/* Goes in the optional file header magic number field */
end_comment

begin_comment
comment|/********************** SECTION HEADER **********************/
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
comment|/* section size			*/
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
comment|/* reserved (TIc80 specific)	*/
name|char
name|s_mempage
index|[
literal|1
index|]
decl_stmt|;
comment|/* memory page number (TIc80)	*/
block|}
struct|;
end_struct

begin_comment
comment|/* Names of "special" sections.  */
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

begin_define
define|#
directive|define
name|_CONST
value|".const"
end_define

begin_define
define|#
directive|define
name|_SWITCH
value|".switch"
end_define

begin_define
define|#
directive|define
name|_STACK
value|".stack"
end_define

begin_define
define|#
directive|define
name|_SYSMEM
value|".sysmem"
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
name|SCNHSZ
value|40
end_define

begin_comment
comment|/* FIXME - need to correlate external_auxent with    TIc80 Code Generation Tools User's Guide, CG:A-25 */
end_comment

begin_comment
comment|/********************** RELOCATION DIRECTIVES **********************/
end_comment

begin_comment
comment|/* The external reloc has an offset field, because some of the reloc    types on the h8 don't have room in the instruction for the entire    offset - eg the strange jump and high page addressing modes.  */
end_comment

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
name|RELSZ
value|12
end_define

begin_comment
comment|/* TIc80 relocation types. */
end_comment

begin_define
define|#
directive|define
name|R_ABS
value|0x00
end_define

begin_comment
comment|/* Absolute address - no relocation */
end_comment

begin_define
define|#
directive|define
name|R_RELLONGX
value|0x11
end_define

begin_comment
comment|/* PP: 32 bits, direct */
end_comment

begin_define
define|#
directive|define
name|R_PPBASE
value|0x34
end_define

begin_comment
comment|/* PP: Global base address type */
end_comment

begin_define
define|#
directive|define
name|R_PPLBASE
value|0x35
end_define

begin_comment
comment|/* PP: Local base address type */
end_comment

begin_define
define|#
directive|define
name|R_PP15
value|0x38
end_define

begin_comment
comment|/* PP: Global 15 bit offset */
end_comment

begin_define
define|#
directive|define
name|R_PP15W
value|0x39
end_define

begin_comment
comment|/* PP: Global 15 bit offset divided by 4 */
end_comment

begin_define
define|#
directive|define
name|R_PP15H
value|0x3A
end_define

begin_comment
comment|/* PP: Global 15 bit offset divided by 2 */
end_comment

begin_define
define|#
directive|define
name|R_PP16B
value|0x3B
end_define

begin_comment
comment|/* PP: Global 16 bit offset for bytes */
end_comment

begin_define
define|#
directive|define
name|R_PPL15
value|0x3C
end_define

begin_comment
comment|/* PP: Local 15 bit offset */
end_comment

begin_define
define|#
directive|define
name|R_PPL15W
value|0x3D
end_define

begin_comment
comment|/* PP: Local 15 bit offset divided by 4 */
end_comment

begin_define
define|#
directive|define
name|R_PPL15H
value|0x3E
end_define

begin_comment
comment|/* PP: Local 15 bit offset divided by 2 */
end_comment

begin_define
define|#
directive|define
name|R_PPL16B
value|0x3F
end_define

begin_comment
comment|/* PP: Local 16 bit offset for bytes */
end_comment

begin_define
define|#
directive|define
name|R_PPN15
value|0x40
end_define

begin_comment
comment|/* PP: Global 15 bit negative offset */
end_comment

begin_define
define|#
directive|define
name|R_PPN15W
value|0x41
end_define

begin_comment
comment|/* PP: Global 15 bit negative offset divided by 4 */
end_comment

begin_define
define|#
directive|define
name|R_PPN15H
value|0x42
end_define

begin_comment
comment|/* PP: Global 15 bit negative offset divided by 2 */
end_comment

begin_define
define|#
directive|define
name|R_PPN16B
value|0x43
end_define

begin_comment
comment|/* PP: Global 16 bit negative byte offset */
end_comment

begin_define
define|#
directive|define
name|R_PPLN15
value|0x44
end_define

begin_comment
comment|/* PP: Local 15 bit negative offset */
end_comment

begin_define
define|#
directive|define
name|R_PPLN15W
value|0x45
end_define

begin_comment
comment|/* PP: Local 15 bit negative offset divided by 4 */
end_comment

begin_define
define|#
directive|define
name|R_PPLN15H
value|0x46
end_define

begin_comment
comment|/* PP: Local 15 bit negative offset divided by 2 */
end_comment

begin_define
define|#
directive|define
name|R_PPLN16B
value|0x47
end_define

begin_comment
comment|/* PP: Local 16 bit negative byte offset */
end_comment

begin_define
define|#
directive|define
name|R_MPPCR15W
value|0x4E
end_define

begin_comment
comment|/* MP: 15 bit PC-relative divided by 4 */
end_comment

begin_define
define|#
directive|define
name|R_MPPCR
value|0x4F
end_define

begin_comment
comment|/* MP: 32 bit PC-relative divided by 4 */
end_comment

end_unit

