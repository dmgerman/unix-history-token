begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* coff information for Apollo M68K     Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|DO_NOT_DEFINE_AOUTHDR
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
comment|/* Motorola 68000/68008/68010/68020 */
end_comment

begin_define
define|#
directive|define
name|MC68MAGIC
value|0520
end_define

begin_define
define|#
directive|define
name|MC68KWRMAGIC
value|0520
end_define

begin_comment
comment|/* writeable text segments */
end_comment

begin_define
define|#
directive|define
name|MC68TVMAGIC
value|0521
end_define

begin_define
define|#
directive|define
name|MC68KROMAGIC
value|0521
end_define

begin_comment
comment|/* readonly shareable text segments */
end_comment

begin_define
define|#
directive|define
name|MC68KPGMAGIC
value|0522
end_define

begin_comment
comment|/* demand paged text segments */
end_comment

begin_define
define|#
directive|define
name|M68MAGIC
value|0210
end_define

begin_define
define|#
directive|define
name|M68TVMAGIC
value|0211
end_define

begin_comment
comment|/* Apollo 68000-based machines have a different magic number. This comes  * from /usr/include/apollo/filehdr.h  */
end_comment

begin_define
define|#
directive|define
name|APOLLOM68KMAGIC
value|0627
end_define

begin_define
define|#
directive|define
name|OMAGIC
value|M68MAGIC
end_define

begin_define
define|#
directive|define
name|M68KBADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic!=MC68MAGIC)&& ((x).f_magic!=MC68KWRMAGIC)&& ((x).f_magic!=MC68TVMAGIC)&& \   ((x).f_magic!=MC68KROMAGIC)&& ((x).f_magic!=MC68KPGMAGIC)&& ((x).f_magic!=M68MAGIC)&& ((x).f_magic!=M68TVMAGIC)&& \   ((x).f_magic!=APOLLOM68KMAGIC) )
end_define

begin_comment
comment|/********************** AOUT "OPTIONAL HEADER" **********************/
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
comment|/* type of file				*/
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
name|char
name|o_sri
index|[
literal|4
index|]
decl_stmt|;
comment|/* Apollo specific - .sri data pointer */
name|char
name|o_inlib
index|[
literal|4
index|]
decl_stmt|;
comment|/* Apollo specific - .inlib data pointer */
name|char
name|vid
index|[
literal|8
index|]
decl_stmt|;
comment|/* Apollo specific - 64 bit version ID */
block|}
name|AOUTHDR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|APOLLO_COFF_VERSION_NUMBER
value|1
end_define

begin_comment
comment|/* the value of the aouthdr magic */
end_comment

begin_define
define|#
directive|define
name|AOUTHDRSZ
value|44
end_define

begin_define
define|#
directive|define
name|AOUTSZ
value|44
end_define

begin_comment
comment|/* Apollo allowa for larger section names by allowing    them to be in the string table.  */
end_comment

begin_comment
comment|/* If s_zeores is all zeroes, s_offset gives the real    location of the name in the string table.  */
end_comment

begin_define
define|#
directive|define
name|s_zeroes
value|section_name.s_name
end_define

begin_define
define|#
directive|define
name|s_offset
value|(section_name.s_name+4)
end_define

begin_comment
comment|/* More names of "special" sections.  */
end_comment

begin_define
define|#
directive|define
name|_TV
value|".tv"
end_define

begin_define
define|#
directive|define
name|_INIT
value|".init"
end_define

begin_define
define|#
directive|define
name|_FINI
value|".fini"
end_define

begin_define
define|#
directive|define
name|_LINES
value|".lines"
end_define

begin_define
define|#
directive|define
name|_BLOCKS
value|".blocks"
end_define

begin_define
define|#
directive|define
name|_SRI
value|".sri"
end_define

begin_comment
comment|/* Static Resource Information (systype,  et al.) */
end_comment

begin_define
define|#
directive|define
name|_MIR
value|".mir"
end_define

begin_comment
comment|/* Module Information Records  */
end_comment

begin_define
define|#
directive|define
name|_APTV
value|".aptv"
end_define

begin_comment
comment|/* Apollo-style transfer vectors. */
end_comment

begin_define
define|#
directive|define
name|_INLIB
value|".inlib"
end_define

begin_comment
comment|/* Shared Library information */
end_comment

begin_define
define|#
directive|define
name|_RWDI
value|".rwdi"
end_define

begin_comment
comment|/* Read/write data initialization directives for  compressed sections */
end_comment

begin_define
define|#
directive|define
name|_UNWIND
value|".unwind"
end_define

begin_comment
comment|/* Stack unwind information */
end_comment

begin_comment
comment|/********************** RELOCATION DIRECTIVES **********************/
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
name|r_type
index|[
literal|2
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|M68K_COFF_OFFSET
name|char
name|r_offset
index|[
literal|4
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RELOC
value|struct external_reloc
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|M68K_COFF_OFFSET
end_ifdef

begin_define
define|#
directive|define
name|RELSZ
value|14
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RELSZ
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Apollo specific STYP flags */
end_comment

begin_define
define|#
directive|define
name|STYP_RELOCATED_NOT_LOADED
value|0x00010000
end_define

begin_comment
comment|/* Section is relocated normally during linking, but need                                             	   not be loaded during program execution */
end_comment

begin_define
define|#
directive|define
name|STYP_DEBUG
value|0x00020000
end_define

begin_comment
comment|/* debug section */
end_comment

begin_define
define|#
directive|define
name|STYP_OVERLAY
value|0x00040000
end_define

begin_comment
comment|/* Section is overlayed */
end_comment

begin_define
define|#
directive|define
name|STYP_INSTRUCTION
value|0x00200000
end_define

begin_comment
comment|/* Section contains executable code */
end_comment

begin_define
define|#
directive|define
name|STYP_ZERO
value|0x00800000
end_define

begin_comment
comment|/* Section is initialized to zero */
end_comment

begin_define
define|#
directive|define
name|STYP_INSTALLED
value|0x02000000
end_define

begin_comment
comment|/* Section should be installable in KGT */
end_comment

begin_define
define|#
directive|define
name|STYP_LOOK_INSTALLED
value|0x04000000
end_define

begin_comment
comment|/* Look for section in KGT */
end_comment

begin_define
define|#
directive|define
name|STYP_SECALIGN1
value|0x08000000
end_define

begin_comment
comment|/* Specially aligned section */
end_comment

begin_define
define|#
directive|define
name|STYP_SECALIGN2
value|0x10000000
end_define

begin_comment
comment|/*      "       "       "    */
end_comment

begin_define
define|#
directive|define
name|STYP_COMPRESSED
value|0x20000000
end_define

begin_comment
comment|/* No section data per se (s_scnptr = 0), but there are 						   initialization directives for it in .rwdi section 						   (used in conjunction with STYP_BSS) */
end_comment

end_unit

