begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Yet Another Try at encapsulating bsd object files in coff.    Copyright (C) 1988, 1989, 1991 Free Software Foundation, Inc.    Written by Pace Willisson 12/9/88     This file is obsolete.  It needs to be converted to just define a bunch    of stuff that BFD can use to do coff-encapsulated files.  --gnu@cygnus.com  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/*  * We only use the coff headers to tell the kernel  * how to exec the file.  Therefore, the only fields that need to   * be filled in are the scnptr and vaddr for the text and data  * sections, and the vaddr for the bss.  As far as coff is concerned,  * there is no symbol table, relocation, or line numbers.  *  * A normal bsd header (struct exec) is placed after the coff headers,  * and before the real text.  I defined a the new fields 'a_machtype'  * and a_flags.  If a_machtype is M_386, and a_flags& A_ENCAP is  * true, then the bsd header is preceeded by a coff header.  Macros  * like N_TXTOFF and N_TXTADDR use this field to find the bsd header.  *   * The only problem is to track down the bsd exec header.  The  * macros HEADER_OFFSET, etc do this.  */
end_comment

begin_define
define|#
directive|define
name|N_FLAGS_COFF_ENCAPSULATE
value|0x20
end_define

begin_comment
comment|/* coff header precedes bsd header */
end_comment

begin_comment
comment|/* Describe the COFF header used for encapsulation.  */
end_comment

begin_struct
struct|struct
name|coffheader
block|{
comment|/* filehdr */
name|unsigned
name|short
name|f_magic
decl_stmt|;
name|unsigned
name|short
name|f_nscns
decl_stmt|;
name|long
name|f_timdat
decl_stmt|;
name|long
name|f_symptr
decl_stmt|;
name|long
name|f_nsyms
decl_stmt|;
name|unsigned
name|short
name|f_opthdr
decl_stmt|;
name|unsigned
name|short
name|f_flags
decl_stmt|;
comment|/* aouthdr */
name|short
name|magic
decl_stmt|;
name|short
name|vstamp
decl_stmt|;
name|long
name|tsize
decl_stmt|;
name|long
name|dsize
decl_stmt|;
name|long
name|bsize
decl_stmt|;
name|long
name|entry
decl_stmt|;
name|long
name|text_start
decl_stmt|;
name|long
name|data_start
decl_stmt|;
struct|struct
name|coffscn
block|{
name|char
name|s_name
index|[
literal|8
index|]
decl_stmt|;
name|long
name|s_paddr
decl_stmt|;
name|long
name|s_vaddr
decl_stmt|;
name|long
name|s_size
decl_stmt|;
name|long
name|s_scnptr
decl_stmt|;
name|long
name|s_relptr
decl_stmt|;
name|long
name|s_lnnoptr
decl_stmt|;
name|unsigned
name|short
name|s_nreloc
decl_stmt|;
name|unsigned
name|short
name|s_nlnno
decl_stmt|;
name|long
name|s_flags
decl_stmt|;
block|}
name|scns
index|[
literal|3
index|]
struct|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Describe some of the parameters of the encapsulation,    including how to find the encapsulated BSD header.  */
end_comment

begin_comment
comment|/* FIXME, this is dumb.  The same tools can't handle a.outs for different    architectures, just because COFF_MAGIC is different; so you need a    separate GNU nm for every architecture!!?  Unfortunately, it needs to    be this way, since the COFF_MAGIC value is determined by the kernel    we're trying to fool here.  */
end_comment

begin_define
define|#
directive|define
name|COFF_MAGIC_I386
value|0514
end_define

begin_comment
comment|/* I386MAGIC */
end_comment

begin_define
define|#
directive|define
name|COFF_MAGIC_M68K
value|0520
end_define

begin_comment
comment|/* MC68MAGIC */
end_comment

begin_define
define|#
directive|define
name|COFF_MAGIC_A29K
value|0x17A
end_define

begin_comment
comment|/* Used by asm29k cross-tools */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COFF_MAGIC
end_ifdef

begin_decl_stmt
name|short
name|__header_offset_temp
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HEADER_OFFSET
parameter_list|(
name|f
parameter_list|)
define|\
value|(__header_offset_temp = 0, \ 	 fread ((char *)&__header_offset_temp, sizeof (short), 1, (f)), \ 	 fseek ((f), -sizeof (short), 1), \ 	 __header_offset_temp==COFF_MAGIC ? sizeof(struct coffheader) : 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HEADER_OFFSET
parameter_list|(
name|f
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HEADER_SEEK
parameter_list|(
name|f
parameter_list|)
value|(fseek ((f), HEADER_OFFSET((f)), 1))
end_define

begin_escape
end_escape

begin_comment
comment|/* Describe the characteristics of the BSD header    that appears inside the encapsulation.  */
end_comment

begin_comment
comment|/* Encapsulated coff files that are linked ZMAGIC have a text segment    offset just past the header (and a matching TXTADDR), excluding    the headers from the text segment proper but keeping the physical    layout and the virtual memory layout page-aligned.     Non-encapsulated a.out files that are linked ZMAGIC have a text    segment that starts at 0 and an N_TXTADR similarly offset to 0.    They too are page-aligned with each other, but they include the    a.out header as part of the text.      The _N_HDROFF gets sizeof struct exec added to it, so we have    to compensate here.  See<a.out.gnu.h>.  */
end_comment

begin_undef
undef|#
directive|undef
name|_N_HDROFF
end_undef

begin_undef
undef|#
directive|undef
name|N_TXTADDR
end_undef

begin_undef
undef|#
directive|undef
name|N_DATADDR
end_undef

begin_define
define|#
directive|define
name|_N_HDROFF
parameter_list|(
name|x
parameter_list|)
value|((N_FLAGS(x)& N_FLAGS_COFF_ENCAPSULATE) ? \ 		      sizeof (struct coffheader) : 0)
end_define

begin_comment
comment|/* Address of text segment in memory after it is loaded.  */
end_comment

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|((N_FLAGS(x)& N_FLAGS_COFF_ENCAPSULATE) ? \ 	 sizeof (struct coffheader) + sizeof (struct exec) : 0)
end_define

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|0x400000
end_define

begin_define
define|#
directive|define
name|N_DATADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|((N_FLAGS(x)& N_FLAGS_COFF_ENCAPSULATE) ? \ 	 (SEGMENT_SIZE + ((N_TXTADDR(x)+(x).a_text-1)& ~(SEGMENT_SIZE-1))) : \ 	 (N_TXTADDR(x)+(x).a_text))
end_define

end_unit

