begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* coff information for M68K        Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GNU_COFF_M68K_H
end_ifndef

begin_define
define|#
directive|define
name|GNU_COFF_M68K_H
value|1
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
comment|/* This is the magic of the Bull dpx/2 */
end_comment

begin_define
define|#
directive|define
name|MC68KBCSMAGIC
value|0526
end_define

begin_comment
comment|/* This is Lynx's all-platform magic number for executables. */
end_comment

begin_define
define|#
directive|define
name|LYNXCOFFMAGIC
value|0415
end_define

begin_define
define|#
directive|define
name|OMAGIC
value|M68MAGIC
end_define

begin_comment
comment|/* This intentionally does not include MC68KBCSMAGIC; it only includes    magic numbers which imply that names do not have underscores.  */
end_comment

begin_define
define|#
directive|define
name|M68KBADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != MC68MAGIC) \&& ((x).f_magic != MC68KWRMAGIC) \&& ((x).f_magic != MC68TVMAGIC) \&& ((x).f_magic != MC68KROMAGIC) \&& ((x).f_magic != MC68KPGMAGIC) \&& ((x).f_magic != M68MAGIC) \&& ((x).f_magic != M68TVMAGIC) \&& ((x).f_magic != LYNXCOFFMAGIC))
end_define

begin_comment
comment|/* Magic numbers for the a.out header.  */
end_comment

begin_define
define|#
directive|define
name|PAGEMAGICEXECSWAPPED
value|0407
end_define

begin_comment
comment|/* executable (swapped) */
end_comment

begin_define
define|#
directive|define
name|PAGEMAGICPEXECSWAPPED
value|0410
end_define

begin_comment
comment|/* pure executable (swapped) */
end_comment

begin_define
define|#
directive|define
name|PAGEMAGICPEXECTSHLIB
value|0443
end_define

begin_comment
comment|/* pure executable (target shared library) */
end_comment

begin_define
define|#
directive|define
name|PAGEMAGICPEXECPAGED
value|0413
end_define

begin_comment
comment|/* pure executable (paged) */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GNU_COFF_M68K_H */
end_comment

end_unit

