begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 Sean Eric Fagan  * Copyright (c) 1994 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COFF_H
end_ifndef

begin_define
define|#
directive|define
name|_COFF_H
end_define

begin_struct
struct|struct
name|filehdr
block|{
name|unsigned
name|short
name|f_magic
decl_stmt|;
comment|/* magic number */
name|unsigned
name|short
name|f_nscns
decl_stmt|;
comment|/* # of sections */
name|long
name|f_timdat
decl_stmt|;
comment|/* time stamp */
name|long
name|f_symptr
decl_stmt|;
comment|/* symbol table offset */
name|long
name|f_nsyms
decl_stmt|;
comment|/* # of symbols */
name|unsigned
name|short
name|f_opthdr
decl_stmt|;
comment|/* size of system header */
name|unsigned
name|short
name|f_flags
decl_stmt|;
comment|/* flags, see below */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|filehdr_flags
block|{
name|F_RELFLG
init|=
literal|0x01
block|,
comment|/* relocs have been stripped */
name|F_EXEC
init|=
literal|0x02
block|,
comment|/* executable file (or shlib) */
name|F_LNNO
init|=
literal|0x04
block|,
comment|/* line numbers have been stripped */
name|F_LSYMS
init|=
literal|0x08
block|,
comment|/* symbols have been stripped */
name|F_SWABD
init|=
literal|0x40
block|,
comment|/* swabbed byte names */
name|F_AR16WR
init|=
literal|0x80
block|,
comment|/* 16-bit, byte reversed words */
name|F_AR32WR
init|=
literal|0x100
comment|/* 32-bit, byte reversed words */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|aouthdr
block|{
name|short
name|magic
decl_stmt|;
comment|/* magic number -- see below */
name|short
name|vstamp
decl_stmt|;
comment|/* artifacts from a by-gone day */
name|long
name|tsize
decl_stmt|;
comment|/* */
name|long
name|dsize
decl_stmt|;
comment|/* */
name|long
name|bsize
decl_stmt|;
comment|/* */
name|long
name|entry
decl_stmt|;
comment|/* Entry point -- offset into file */
name|long
name|tstart
decl_stmt|;
comment|/* artifacts from a by-gone day */
name|long
name|dstart
decl_stmt|;
comment|/* */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I386_COFF
value|0x14c
end_define

begin_define
define|#
directive|define
name|COFF_OMAGIC
value|0407
end_define

begin_comment
comment|/* impure format */
end_comment

begin_define
define|#
directive|define
name|COFF_NMAGIC
value|0410
end_define

begin_comment
comment|/* read-only text */
end_comment

begin_define
define|#
directive|define
name|COFF_ZMAGIC
value|0413
end_define

begin_comment
comment|/* pagable from disk */
end_comment

begin_define
define|#
directive|define
name|COFF_SHLIB
value|0443
end_define

begin_comment
comment|/* a shared library */
end_comment

begin_struct
struct|struct
name|scnhdr
block|{
name|char
name|s_name
index|[
literal|8
index|]
decl_stmt|;
comment|/* name of section (e.g., ".text") */
name|long
name|s_paddr
decl_stmt|;
comment|/* physical addr, used for standalone */
name|long
name|s_vaddr
decl_stmt|;
comment|/* virtual address */
name|long
name|s_size
decl_stmt|;
comment|/* size of section */
name|long
name|s_scnptr
decl_stmt|;
comment|/* file offset of section */
name|long
name|s_relptr
decl_stmt|;
comment|/* points to relocs for section */
name|long
name|s_lnnoptr
decl_stmt|;
comment|/* points to line numbers for section */
name|unsigned
name|short
name|s_nreloc
decl_stmt|;
comment|/* # of relocs */
name|unsigned
name|short
name|s_nlnno
decl_stmt|;
comment|/* # of line no's */
name|long
name|s_flags
decl_stmt|;
comment|/* section flags -- see below */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|scnhdr_flags
block|{
name|STYP_REG
init|=
literal|0x00
block|,
comment|/* regular (alloc'ed, reloc'ed, loaded) */
name|STYP_DSECT
init|=
literal|0x01
block|,
comment|/* dummy   (reloc'd) */
name|STYP_NOLOAD
init|=
literal|0x02
block|,
comment|/* no-load (reloc'd) */
name|STYP_GROUP
init|=
literal|0x04
block|,
comment|/* grouped */
name|STYP_PAD
init|=
literal|0x08
block|,
comment|/* padding (loaded) */
name|STYP_COPY
init|=
literal|0x10
block|,
comment|/* ??? */
name|STYP_TEXT
init|=
literal|0x20
block|,
comment|/* text */
name|STYP_DATA
init|=
literal|0x40
block|,
comment|/* data */
name|STYP_BSS
init|=
literal|0x80
block|,
comment|/* bss */
name|STYP_INFO
init|=
literal|0x200
block|,
comment|/* comment (!loaded, !alloc'ed, !reloc'd) */
name|STYP_OVER
init|=
literal|0x400
block|,
comment|/* overlay (!allocated, reloc'd, !loaded) */
name|STYP_LIB
init|=
literal|0x800
comment|/* lists shared library files */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|slhdr
block|{
name|long
name|entry_length
decl_stmt|;
name|long
name|path_index
decl_stmt|;
name|char
modifier|*
name|shlib_name
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _COFF_H */
end_comment

end_unit

