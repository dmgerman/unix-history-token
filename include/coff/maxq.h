begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* COFF spec for MAXQ     Copyright 2004, 2005 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by the Free     Software Foundation; either version 2 of the License, or (at your option)    any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY     or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation, Inc.,    51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.     Contributed by Vineet Sharma(vineets@noida.hcltech.com) Inderpreet    S.(inderpreetb@noida.hcltech.com) HCL Technologies Ltd.  */
end_comment

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
comment|/* Bits for f_flags: F_RELFLG relocation info stripped from file F_EXEC file    is executable (no unresolved external references) F_LNNO line numbers    stripped from file F_LSYMS local symbols stripped from file.  */
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

begin_comment
comment|/* Variant Specific Flags for MAXQ10 and MAXQ20.  */
end_comment

begin_define
define|#
directive|define
name|F_MAXQ10
value|(0x0030)
end_define

begin_define
define|#
directive|define
name|F_MAXQ20
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|F_MACHMASK
value|(0x00F0)
end_define

begin_comment
comment|/* Magic numbers for maxq.  */
end_comment

begin_define
define|#
directive|define
name|MAXQ20MAGIC
value|0xa0
end_define

begin_define
define|#
directive|define
name|MAXQ20BADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != MAXQ20MAGIC))
end_define

begin_define
define|#
directive|define
name|BADMAG
parameter_list|(
name|x
parameter_list|)
value|MAXQ20BADMAG (x)
end_define

begin_comment
comment|/* Relocation information declaration and related definitions.  */
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
comment|/* (Virtual) address of reference.  */
name|char
name|r_symndx
index|[
literal|4
index|]
decl_stmt|;
comment|/* Index into symbol table.  */
name|char
name|r_type
index|[
literal|2
index|]
decl_stmt|;
comment|/* Relocation type.  */
name|char
name|r_offset
index|[
literal|2
index|]
decl_stmt|;
comment|/* Addend.  */
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
value|(10 + 2)
end_define

begin_comment
comment|/* sizeof (RELOC) */
end_comment

end_unit

