begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SH ELF support for BFD.    Copyright 1998, 2000, 2001, 2002 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_SH_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_SH_H
end_define

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_define
define|#
directive|define
name|EF_SH_MACH_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|EF_SH_UNKNOWN
value|0
end_define

begin_comment
comment|/* For backwards compatibility.  */
end_comment

begin_define
define|#
directive|define
name|EF_SH1
value|1
end_define

begin_define
define|#
directive|define
name|EF_SH2
value|2
end_define

begin_define
define|#
directive|define
name|EF_SH3
value|3
end_define

begin_define
define|#
directive|define
name|EF_SH_HAS_DSP
parameter_list|(
name|flags
parameter_list|)
value|((flags)& 4)
end_define

begin_define
define|#
directive|define
name|EF_SH_DSP
value|4
end_define

begin_define
define|#
directive|define
name|EF_SH3_DSP
value|5
end_define

begin_define
define|#
directive|define
name|EF_SH_HAS_FP
parameter_list|(
name|flags
parameter_list|)
value|((flags)& 8)
end_define

begin_define
define|#
directive|define
name|EF_SH3E
value|8
end_define

begin_define
define|#
directive|define
name|EF_SH4
value|9
end_define

begin_comment
comment|/* This one can only mix in objects from other EF_SH5 objects.  */
end_comment

begin_define
define|#
directive|define
name|EF_SH5
value|10
end_define

begin_define
define|#
directive|define
name|EF_SH_MERGE_MACH
parameter_list|(
name|mach1
parameter_list|,
name|mach2
parameter_list|)
define|\
value|(((((mach1) == EF_SH3 || (mach1) == EF_SH_UNKNOWN)&& (mach2) == EF_SH_DSP) \     || ((mach1) == EF_SH_DSP \&& ((mach2) == EF_SH3 || (mach2) == EF_SH_UNKNOWN))) \    ? EF_SH3_DSP \    : (((mach1)< EF_SH3&& (mach2) == EF_SH_UNKNOWN) \       || ((mach2)< EF_SH3&& (mach1) == EF_SH_UNKNOWN)) \    ? EF_SH3 \    : (((mach1) == EF_SH3E&& (mach2) == EF_SH_UNKNOWN) \       || ((mach2) == EF_SH3E&& (mach1) == EF_SH_UNKNOWN)) \    ? EF_SH4 \    : ((mach1)> (mach2) ? (mach1) : (mach2)))
end_define

begin_comment
comment|/* Flags for the st_other symbol field.    Keep away from the STV_ visibility flags (bit 0..1).  */
end_comment

begin_comment
comment|/* A reference to this symbol should by default add 1.  */
end_comment

begin_define
define|#
directive|define
name|STO_SH5_ISA32
value|(1<< 2)
end_define

begin_comment
comment|/* Section contains only SHmedia code (no SHcompact code).  */
end_comment

begin_define
define|#
directive|define
name|SHF_SH5_ISA32
value|0x40000000
end_define

begin_comment
comment|/* Section contains both SHmedia and SHcompact code, and possibly also    constants.  */
end_comment

begin_define
define|#
directive|define
name|SHF_SH5_ISA32_MIXED
value|0x20000000
end_define

begin_comment
comment|/* If applied to a .cranges section, marks that the section is sorted by    increasing cr_addr values.  */
end_comment

begin_define
define|#
directive|define
name|SHT_SH5_CR_SORTED
value|0x80000001
end_define

begin_comment
comment|/* Symbol should be handled as DataLabel (attached to global SHN_UNDEF    symbols).  */
end_comment

begin_define
define|#
directive|define
name|STT_DATALABEL
value|STT_LOPROC
end_define

begin_define
define|#
directive|define
name|SH64_CRANGES_SECTION_NAME
value|".cranges"
end_define

begin_enum
enum|enum
name|sh64_elf_cr_type
block|{
name|CRT_NONE
init|=
literal|0
block|,
name|CRT_DATA
init|=
literal|1
block|,
name|CRT_SH5_ISA16
init|=
literal|2
block|,
name|CRT_SH5_ISA32
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/* The official definition is this:      typedef struct {       Elf32_Addr cr_addr;       Elf32_Word cr_size;       Elf32_Half cr_type;     } Elf32_CRange;     but we have no use for that exact type.  Instead we use this struct for    the internal representation.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|bfd_vma
name|cr_addr
decl_stmt|;
name|bfd_size_type
name|cr_size
decl_stmt|;
name|enum
name|sh64_elf_cr_type
name|cr_type
decl_stmt|;
block|}
name|sh64_elf_crange
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SH64_CRANGE_SIZE
value|(4 + 4 + 2)
end_define

begin_define
define|#
directive|define
name|SH64_CRANGE_CR_ADDR_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|SH64_CRANGE_CR_SIZE_OFFSET
value|4
end_define

begin_define
define|#
directive|define
name|SH64_CRANGE_CR_TYPE_OFFSET
value|(4 + 4)
end_define

begin_comment
comment|/* Get the contents type of an arbitrary address, or return CRT_NONE.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|sh64_elf_cr_type
name|sh64_get_contents_type
name|PARAMS
argument_list|(
operator|(
name|asection
operator|*
operator|,
name|bfd_vma
operator|,
name|sh64_elf_crange
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Simpler interface.    FIXME: This seems redundant now that we export the interface above.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|sh64_address_is_shmedia
name|PARAMS
argument_list|(
operator|(
name|asection
operator|*
operator|,
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We put this in elf_section_data (section)->tdata.  */
end_comment

begin_struct
struct|struct
name|sh64_section_data
block|{
name|flagword
name|contents_flags
decl_stmt|;
comment|/* Only used in the cranges section, but we don't have an official      backend-specific bfd field.  */
name|bfd_size_type
name|cranges_growth
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sh64_elf_section_data
parameter_list|(
name|sec
parameter_list|)
define|\
value|((struct sh64_section_data *) ((elf_section_data (sec))->tdata))
end_define

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_comment
comment|/* Relocations.  */
end_comment

begin_comment
comment|/* Relocations 25ff are GNU extensions.    25..33 are used for relaxation and use the same constants as COFF uses.  */
end_comment

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_sh_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR32
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_REL32
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR8WPN
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_IND12W
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR8WPL
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR8WPZ
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR8BP
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR8W
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR8L
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_SH_FIRST_INVALID_RELOC
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_SH_LAST_INVALID_RELOC
argument_list|,
literal|24
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_SWITCH16
argument_list|,
literal|25
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_SWITCH32
argument_list|,
literal|26
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_USES
argument_list|,
literal|27
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_COUNT
argument_list|,
literal|28
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_ALIGN
argument_list|,
literal|29
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_CODE
argument_list|,
literal|30
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DATA
argument_list|,
literal|31
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_LABEL
argument_list|,
literal|32
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_SWITCH8
argument_list|,
literal|33
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GNU_VTINHERIT
argument_list|,
literal|34
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GNU_VTENTRY
argument_list|,
literal|35
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_LOOP_START
argument_list|,
literal|36
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_LOOP_END
argument_list|,
literal|37
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_SH_FIRST_INVALID_RELOC_2
argument_list|,
literal|38
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_SH_LAST_INVALID_RELOC_2
argument_list|,
literal|44
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR5U
argument_list|,
literal|45
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR6U
argument_list|,
literal|46
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR6S
argument_list|,
literal|47
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR10S
argument_list|,
literal|48
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR10SW
argument_list|,
literal|49
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR10SL
argument_list|,
literal|50
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR10SQ
argument_list|,
literal|51
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_SH_FIRST_INVALID_RELOC_3
argument_list|,
literal|52
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_SH_LAST_INVALID_RELOC_3
argument_list|,
literal|159
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOT32
argument_list|,
literal|160
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_PLT32
argument_list|,
literal|161
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_COPY
argument_list|,
literal|162
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GLOB_DAT
argument_list|,
literal|163
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_JMP_SLOT
argument_list|,
literal|164
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_RELATIVE
argument_list|,
literal|165
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTOFF
argument_list|,
literal|166
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTPC
argument_list|,
literal|167
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTPLT32
argument_list|,
literal|168
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOT_LOW16
argument_list|,
literal|169
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOT_MEDLOW16
argument_list|,
literal|170
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOT_MEDHI16
argument_list|,
literal|171
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOT_HI16
argument_list|,
literal|172
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTPLT_LOW16
argument_list|,
literal|173
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTPLT_MEDLOW16
argument_list|,
literal|174
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTPLT_MEDHI16
argument_list|,
literal|175
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTPLT_HI16
argument_list|,
literal|176
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_PLT_LOW16
argument_list|,
literal|177
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_PLT_MEDLOW16
argument_list|,
literal|178
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_PLT_MEDHI16
argument_list|,
literal|179
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_PLT_HI16
argument_list|,
literal|180
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTOFF_LOW16
argument_list|,
literal|181
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTOFF_MEDLOW16
argument_list|,
literal|182
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTOFF_MEDHI16
argument_list|,
literal|183
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTOFF_HI16
argument_list|,
literal|184
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTPC_LOW16
argument_list|,
literal|185
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTPC_MEDLOW16
argument_list|,
literal|186
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTPC_MEDHI16
argument_list|,
literal|187
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTPC_HI16
argument_list|,
literal|188
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOT10BY4
argument_list|,
literal|189
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTPLT10BY4
argument_list|,
literal|190
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOT10BY8
argument_list|,
literal|191
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTPLT10BY8
argument_list|,
literal|192
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_COPY64
argument_list|,
literal|193
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GLOB_DAT64
argument_list|,
literal|194
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_JMP_SLOT64
argument_list|,
literal|195
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_RELATIVE64
argument_list|,
literal|196
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_SH_FIRST_INVALID_RELOC_4
argument_list|,
literal|197
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_SH_LAST_INVALID_RELOC_4
argument_list|,
literal|241
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_SHMEDIA_CODE
argument_list|,
literal|242
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_PT_16
argument_list|,
literal|243
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_IMMS16
argument_list|,
literal|244
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_IMMU16
argument_list|,
literal|245
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_IMM_LOW16
argument_list|,
literal|246
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_IMM_LOW16_PCREL
argument_list|,
literal|247
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_IMM_MEDLOW16
argument_list|,
literal|248
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_IMM_MEDLOW16_PCREL
argument_list|,
literal|249
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_IMM_MEDHI16
argument_list|,
literal|250
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_IMM_MEDHI16_PCREL
argument_list|,
literal|251
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_IMM_HI16
argument_list|,
literal|252
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_IMM_HI16_PCREL
argument_list|,
literal|253
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_64
argument_list|,
literal|254
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_64_PCREL
argument_list|,
literal|255
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_SH_max
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

