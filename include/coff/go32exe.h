begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* COFF information for PC running go32.     Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|STUBSIZE
value|2048
end_define

begin_struct
struct|struct
name|external_filehdr_go32_exe
block|{
name|char
name|stub
index|[
name|STUBSIZE
index|]
decl_stmt|;
comment|/* the stub to load the image	*/
comment|/* the standard COFF header     */
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
block|}
struct|;
end_struct

begin_undef
undef|#
directive|undef
name|FILHDR
end_undef

begin_define
define|#
directive|define
name|FILHDR
value|struct external_filehdr_go32_exe
end_define

begin_undef
undef|#
directive|undef
name|FILHSZ
end_undef

begin_define
define|#
directive|define
name|FILHSZ
value|STUBSIZE+20
end_define

end_unit

