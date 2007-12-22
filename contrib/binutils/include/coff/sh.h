begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* coff information for Renesas SH        Copyright 2001, 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COFF_WITH_PE
end_ifdef

begin_define
define|#
directive|define
name|L_LNNO_SIZE
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|L_LNNO_SIZE
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INCLUDE_COMDAT_FIELDS_IN_AUXENT
end_define

begin_include
include|#
directive|include
file|"coff/external.h"
end_include

begin_define
define|#
directive|define
name|SH_ARCH_MAGIC_BIG
value|0x0500
end_define

begin_define
define|#
directive|define
name|SH_ARCH_MAGIC_LITTLE
value|0x0550
end_define

begin_comment
comment|/* Little endian SH */
end_comment

begin_define
define|#
directive|define
name|SH_ARCH_MAGIC_WINCE
value|0x01a2
end_define

begin_comment
comment|/* Windows CE - little endian */
end_comment

begin_define
define|#
directive|define
name|SH_PE_MAGIC
value|0x010b
end_define

begin_define
define|#
directive|define
name|SHBADMAG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x).f_magic != SH_ARCH_MAGIC_BIG)&& \   ((x).f_magic != SH_ARCH_MAGIC_WINCE)&& \   ((x).f_magic != SH_ARCH_MAGIC_LITTLE))
end_define

begin_comment
comment|/* Define some NT default values.  */
end_comment

begin_comment
comment|/*  #define NT_IMAGE_BASE        0x400000 moved to internal.h */
end_comment

begin_define
define|#
directive|define
name|NT_SECTION_ALIGNMENT
value|0x1000
end_define

begin_define
define|#
directive|define
name|NT_FILE_ALIGNMENT
value|0x200
end_define

begin_define
define|#
directive|define
name|NT_DEF_RESERVE
value|0x100000
end_define

begin_define
define|#
directive|define
name|NT_DEF_COMMIT
value|0x1000
end_define

begin_comment
comment|/********************** RELOCATION DIRECTIVES **********************/
end_comment

begin_comment
comment|/* The external reloc has an offset field, because some of the reloc    types on the h8 don't have room in the instruction for the entire    offset - eg the strange jump and high page addressing modes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COFF_WITH_PE
end_ifndef

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
name|r_offset
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
name|char
name|r_stuff
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

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
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RELOC
value|struct external_reloc
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|COFF_WITH_PE
end_ifdef

begin_define
define|#
directive|define
name|RELSZ
value|10
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RELSZ
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SH relocation types.  Not all of these are actually used.  */
end_comment

begin_define
define|#
directive|define
name|R_SH_UNUSED
value|0
end_define

begin_comment
comment|/* only used internally */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM32CE
value|2
end_define

begin_comment
comment|/* 32 bit immediate for WinCE */
end_comment

begin_define
define|#
directive|define
name|R_SH_PCREL8
value|3
end_define

begin_comment
comment|/*  8 bit pcrel 	*/
end_comment

begin_define
define|#
directive|define
name|R_SH_PCREL16
value|4
end_define

begin_comment
comment|/* 16 bit pcrel 	*/
end_comment

begin_define
define|#
directive|define
name|R_SH_HIGH8
value|5
end_define

begin_comment
comment|/* high 8 bits of 24 bit address */
end_comment

begin_define
define|#
directive|define
name|R_SH_LOW16
value|7
end_define

begin_comment
comment|/* low 16 bits of 24 bit immediate */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM24
value|6
end_define

begin_comment
comment|/* 24 bit immediate */
end_comment

begin_define
define|#
directive|define
name|R_SH_PCDISP8BY4
value|9
end_define

begin_comment
comment|/* PC rel 8 bits *4 +ve */
end_comment

begin_define
define|#
directive|define
name|R_SH_PCDISP8BY2
value|10
end_define

begin_comment
comment|/* PC rel 8 bits *2 +ve */
end_comment

begin_define
define|#
directive|define
name|R_SH_PCDISP8
value|11
end_define

begin_comment
comment|/* 8 bit branch */
end_comment

begin_define
define|#
directive|define
name|R_SH_PCDISP
value|12
end_define

begin_comment
comment|/* 12 bit branch */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM32
value|14
end_define

begin_comment
comment|/* 32 bit immediate */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM8
value|16
end_define

begin_comment
comment|/* 8 bit immediate */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMAGEBASE
value|16
end_define

begin_comment
comment|/* Windows CE */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM8BY2
value|17
end_define

begin_comment
comment|/* 8 bit immediate *2 */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM8BY4
value|18
end_define

begin_comment
comment|/* 8 bit immediate *4 */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM4
value|19
end_define

begin_comment
comment|/* 4 bit immediate */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM4BY2
value|20
end_define

begin_comment
comment|/* 4 bit immediate *2 */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM4BY4
value|21
end_define

begin_comment
comment|/* 4 bit immediate *4 */
end_comment

begin_define
define|#
directive|define
name|R_SH_PCRELIMM8BY2
value|22
end_define

begin_comment
comment|/* PC rel 8 bits *2 unsigned */
end_comment

begin_define
define|#
directive|define
name|R_SH_PCRELIMM8BY4
value|23
end_define

begin_comment
comment|/* PC rel 8 bits *4 unsigned */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM16
value|24
end_define

begin_comment
comment|/* 16 bit immediate */
end_comment

begin_comment
comment|/* The switch table reloc types are used for relaxing.  They are    generated for expressions such as      .word L1 - L2    The r_offset field holds the difference between the reloc address    and L2.  */
end_comment

begin_define
define|#
directive|define
name|R_SH_SWITCH8
value|33
end_define

begin_comment
comment|/* 8 bit switch table entry */
end_comment

begin_define
define|#
directive|define
name|R_SH_SWITCH16
value|25
end_define

begin_comment
comment|/* 16 bit switch table entry */
end_comment

begin_define
define|#
directive|define
name|R_SH_SWITCH32
value|26
end_define

begin_comment
comment|/* 32 bit switch table entry */
end_comment

begin_comment
comment|/* The USES reloc type is used for relaxing.  The compiler will    generate .uses pseudo-ops when it finds a function call which it    can relax.  The r_offset field of the USES reloc holds the PC    relative offset to the instruction which loads the register used in    the function call.  */
end_comment

begin_define
define|#
directive|define
name|R_SH_USES
value|27
end_define

begin_comment
comment|/* .uses pseudo-op */
end_comment

begin_comment
comment|/* The COUNT reloc type is used for relaxing.  The assembler will    generate COUNT relocs for addresses referred to by the register    loads associated with USES relocs.  The r_offset field of the COUNT    reloc holds the number of times the address is referenced in the    object file.  */
end_comment

begin_define
define|#
directive|define
name|R_SH_COUNT
value|28
end_define

begin_comment
comment|/* Count of constant pool uses */
end_comment

begin_comment
comment|/* The ALIGN reloc type is used for relaxing.  The r_offset field is    the power of two to which subsequent portions of the object file    must be aligned.  */
end_comment

begin_define
define|#
directive|define
name|R_SH_ALIGN
value|29
end_define

begin_comment
comment|/* .align pseudo-op */
end_comment

begin_comment
comment|/* The CODE and DATA reloc types are used for aligning load and store    instructions.  The assembler will generate a CODE reloc before a    block of instructions.  It will generate a DATA reloc before data.    A section should be processed assuming it contains data, unless a    CODE reloc is seen.  The only relevant pieces of information in the    CODE and DATA relocs are the section and the address.  The symbol    and offset are meaningless.  */
end_comment

begin_define
define|#
directive|define
name|R_SH_CODE
value|30
end_define

begin_comment
comment|/* start of code */
end_comment

begin_define
define|#
directive|define
name|R_SH_DATA
value|31
end_define

begin_comment
comment|/* start of data */
end_comment

begin_comment
comment|/* The LABEL reloc type is used for aligning load and store    instructions.  The assembler will generate a LABEL reloc for each    label within a block of instructions.  This permits the linker to    avoid swapping instructions which are the targets of branches.  */
end_comment

begin_define
define|#
directive|define
name|R_SH_LABEL
value|32
end_define

begin_comment
comment|/* label */
end_comment

begin_comment
comment|/* NB: R_SH_SWITCH8 is 33 */
end_comment

begin_define
define|#
directive|define
name|R_SH_LOOP_START
value|34
end_define

begin_define
define|#
directive|define
name|R_SH_LOOP_END
value|35
end_define

end_unit

