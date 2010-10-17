begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* COFF spec for AMD 290*0      Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.        Contributed by David Wood @ New York University. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMD
end_ifndef

begin_define
define|#
directive|define
name|AMD
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* ** Magic numbers for Am29000  **	(AT&T will assign the "real" magic number)   */
end_comment

begin_define
define|#
directive|define
name|SIPFBOMAGIC
value|0572
end_define

begin_comment
comment|/* Am29000 (Byte 0 is MSB) */
end_comment

begin_define
define|#
directive|define
name|SIPRBOMAGIC
value|0573
end_define

begin_comment
comment|/* Am29000 (Byte 0 is LSB) */
end_comment

begin_define
define|#
directive|define
name|A29K_MAGIC_BIG
value|SIPFBOMAGIC
end_define

begin_define
define|#
directive|define
name|A29K_MAGIC_LITTLE
value|SIPRBOMAGIC
end_define

begin_define
define|#
directive|define
name|A29KBADMAG
parameter_list|(
name|x
parameter_list|)
value|( ((x).f_magic != A29K_MAGIC_BIG)&& \ 			  ((x).f_magic != A29K_MAGIC_LITTLE))
end_define

begin_define
define|#
directive|define
name|OMAGIC
value|A29K_MAGIC_BIG
end_define

begin_comment
comment|/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
end_comment

begin_comment
comment|/* ** File header flags currently known to us. ** ** Am29000 will use the F_AR32WR and F_AR32W flags to indicate ** the byte ordering in the file. */
end_comment

begin_comment
comment|/*--------------------------------------------------------------*/
end_comment

begin_comment
comment|/* aouthdr magic numbers */
end_comment

begin_define
define|#
directive|define
name|NMAGIC
value|0410
end_define

begin_comment
comment|/* separate i/d executable */
end_comment

begin_define
define|#
directive|define
name|SHMAGIC
value|0406
end_define

begin_comment
comment|/* NYU/Ultra3 shared data executable  				   (writable text) */
end_comment

begin_undef
undef|#
directive|undef
name|_ETEXT
end_undef

begin_define
define|#
directive|define
name|_ETEXT
value|"_etext"
end_define

begin_comment
comment|/*--------------------------------------------------------------*/
end_comment

begin_comment
comment|/* More names of "special" sections.  */
end_comment

begin_define
define|#
directive|define
name|_LIT
value|".lit"
end_define

begin_comment
comment|/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
end_comment

begin_comment
comment|/* ** Section types - with additional section type for global  ** registers which will be relocatable for the Am29000. ** ** In instances where it is necessary for a linker to produce an ** output file which contains text or data not based at virtual ** address 0, e.g. for a ROM, then the linker should accept ** address base information as command input and use PAD sections ** to skip over unused addresses. */
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

begin_comment
comment|/*--------------------------------------------------------------*/
end_comment

begin_comment
comment|/* ** Relocation information declaration and related definitions */
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
comment|/* (virtual) address of reference */
name|char
name|r_symndx
index|[
literal|4
index|]
decl_stmt|;
comment|/* index into symbol table */
name|char
name|r_type
index|[
literal|2
index|]
decl_stmt|;
comment|/* relocation type */
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
value|10
end_define

begin_comment
comment|/* sizeof (RELOC) */
end_comment

begin_comment
comment|/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
end_comment

begin_comment
comment|/* ** Relocation types for the Am29000  */
end_comment

begin_define
define|#
directive|define
name|R_ABS
value|0
end_define

begin_comment
comment|/* reference is absolute */
end_comment

begin_define
define|#
directive|define
name|R_IREL
value|030
end_define

begin_comment
comment|/* instruction relative (jmp/call) */
end_comment

begin_define
define|#
directive|define
name|R_IABS
value|031
end_define

begin_comment
comment|/* instruction absolute (jmp/call) */
end_comment

begin_define
define|#
directive|define
name|R_ILOHALF
value|032
end_define

begin_comment
comment|/* instruction low half  (const)  */
end_comment

begin_define
define|#
directive|define
name|R_IHIHALF
value|033
end_define

begin_comment
comment|/* instruction high half (consth) part 1 */
end_comment

begin_define
define|#
directive|define
name|R_IHCONST
value|034
end_define

begin_comment
comment|/* instruction high half (consth) part 2 */
end_comment

begin_comment
comment|/* constant offset of R_IHIHALF relocation */
end_comment

begin_define
define|#
directive|define
name|R_BYTE
value|035
end_define

begin_comment
comment|/* relocatable byte value */
end_comment

begin_define
define|#
directive|define
name|R_HWORD
value|036
end_define

begin_comment
comment|/* relocatable halfword value */
end_comment

begin_define
define|#
directive|define
name|R_WORD
value|037
end_define

begin_comment
comment|/* relocatable word value */
end_comment

begin_define
define|#
directive|define
name|R_IGLBLRC
value|040
end_define

begin_comment
comment|/* instruction global register RC */
end_comment

begin_define
define|#
directive|define
name|R_IGLBLRA
value|041
end_define

begin_comment
comment|/* instruction global register RA */
end_comment

begin_define
define|#
directive|define
name|R_IGLBLRB
value|042
end_define

begin_comment
comment|/* instruction global register RB */
end_comment

begin_comment
comment|/* NOTE: All the "I" forms refer to 29000 instruction formats.  The linker is  expected to know how the numeric information is split and/or aligned within the instruction word(s).  R_BYTE works for instructions, too.  If the parameter to a CONSTH instruction is a relocatable type, two  relocation records are written.  The first has an r_type of R_IHIHALF  (33 octal) and a normal r_vaddr and r_symndx.  The second relocation  record has an r_type of R_IHCONST (34 octal), a normal r_vaddr (which  is redundant), and an r_symndx containing the 32-bit constant offset  to the relocation instead of the actual symbol table index.  This  second record is always written, even if the constant offset is zero. The constant fields of the instruction are set to zero. */
end_comment

begin_comment
comment|/*--------------------------------------------------------------*/
end_comment

begin_comment
comment|/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
end_comment

begin_comment
comment|/* ** Storage class definitions - new classes for global registers. */
end_comment

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

end_unit

