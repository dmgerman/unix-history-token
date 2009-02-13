begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* FRV ELF support for BFD.    Copyright (C) 2002 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_FRV_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_FRV_H
end_define

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_comment
comment|/* Relocations.  */
end_comment

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_frv_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_32
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_LABEL16
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_LABEL24
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_LO16
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_HI16
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_GPREL12
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_GPRELU12
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_GPREL32
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_GPRELHI
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_GPRELLO
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_GOT12
argument_list|,
literal|11
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_GOTHI
argument_list|,
literal|12
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_GOTLO
argument_list|,
literal|13
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_FUNCDESC
argument_list|,
literal|14
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_FUNCDESC_GOT12
argument_list|,
literal|15
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_FUNCDESC_GOTHI
argument_list|,
literal|16
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_FUNCDESC_GOTLO
argument_list|,
literal|17
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_FUNCDESC_VALUE
argument_list|,
literal|18
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_FUNCDESC_GOTOFF12
argument_list|,
literal|19
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_FUNCDESC_GOTOFFHI
argument_list|,
literal|20
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_FUNCDESC_GOTOFFLO
argument_list|,
literal|21
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_GOTOFF12
argument_list|,
literal|22
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_GOTOFFHI
argument_list|,
literal|23
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_GOTOFFLO
argument_list|,
literal|24
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_GNU_VTINHERIT
argument_list|,
literal|200
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_FRV_GNU_VTENTRY
argument_list|,
literal|201
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_FRV_max
argument_list|)
end_macro

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_comment
comment|/* gpr support */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_GPR_MASK
value|0x00000003
end_define

begin_comment
comment|/* mask for # of gprs */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_GPR_32
value|0x00000001
end_define

begin_comment
comment|/* -mgpr-32 */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_GPR_64
value|0x00000002
end_define

begin_comment
comment|/* -mgpr-64 */
end_comment

begin_comment
comment|/* fpr support */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_FPR_MASK
value|0x0000000c
end_define

begin_comment
comment|/* mask for # of fprs */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_FPR_32
value|0x00000004
end_define

begin_comment
comment|/* -mfpr-32 */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_FPR_64
value|0x00000008
end_define

begin_comment
comment|/* -mfpr-64 */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_FPR_NONE
value|0x0000000c
end_define

begin_comment
comment|/* -msoft-float */
end_comment

begin_comment
comment|/* double word support */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_DWORD_MASK
value|0x00000030
end_define

begin_comment
comment|/* mask for dword support */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_DWORD_YES
value|0x00000010
end_define

begin_comment
comment|/* use double word insns */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_DWORD_NO
value|0x00000020
end_define

begin_comment
comment|/* don't use double word insn*/
end_comment

begin_define
define|#
directive|define
name|EF_FRV_DOUBLE
value|0x00000040
end_define

begin_comment
comment|/* -mdouble */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_MEDIA
value|0x00000080
end_define

begin_comment
comment|/* -mmedia */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_PIC
value|0x00000100
end_define

begin_comment
comment|/* -fpic */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_NON_PIC_RELOCS
value|0x00000200
end_define

begin_comment
comment|/* used non pic safe relocs */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_MULADD
value|0x00000400
end_define

begin_comment
comment|/* -mmuladd */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_BIGPIC
value|0x00000800
end_define

begin_comment
comment|/* -fPIC */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_LIBPIC
value|0x00001000
end_define

begin_comment
comment|/* -mlibrary-pic */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_G0
value|0x00002000
end_define

begin_comment
comment|/* -G 0, no small data ptr */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_NOPACK
value|0x00004000
end_define

begin_comment
comment|/* -mnopack */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_FDPIC
value|0x00008000
end_define

begin_comment
comment|/* -mfdpic */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_CPU_MASK
value|0xff000000
end_define

begin_comment
comment|/* specific cpu bits */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_CPU_GENERIC
value|0x00000000
end_define

begin_comment
comment|/* generic FRV */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_CPU_FR500
value|0x01000000
end_define

begin_comment
comment|/* FRV500 */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_CPU_FR300
value|0x02000000
end_define

begin_comment
comment|/* FRV300 */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_CPU_SIMPLE
value|0x03000000
end_define

begin_comment
comment|/* SIMPLE */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_CPU_TOMCAT
value|0x04000000
end_define

begin_comment
comment|/* Tomcat, FR500 prototype */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_CPU_FR400
value|0x05000000
end_define

begin_comment
comment|/* FRV400 */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_CPU_FR550
value|0x06000000
end_define

begin_comment
comment|/* FRV550 */
end_comment

begin_comment
comment|/* Mask of PIC related bits */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_PIC_FLAGS
value|(EF_FRV_PIC | EF_FRV_LIBPIC | EF_FRV_BIGPIC \ 				 | EF_FRV_FDPIC)
end_define

begin_comment
comment|/* Mask of all flags */
end_comment

begin_define
define|#
directive|define
name|EF_FRV_ALL_FLAGS
value|(EF_FRV_GPR_MASK | \ 				 EF_FRV_FPR_MASK | \ 				 EF_FRV_DWORD_MASK | \ 				 EF_FRV_DOUBLE | \ 				 EF_FRV_MEDIA | \ 				 EF_FRV_PIC_FLAGS | \ 				 EF_FRV_NON_PIC_RELOCS | \ 				 EF_FRV_MULADD | \ 				 EF_FRV_G0 | \ 				 EF_FRV_NOPACK | \ 				 EF_FRV_CPU_MASK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_FRV_H */
end_comment

end_unit

