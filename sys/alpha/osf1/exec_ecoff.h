begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: exec_ecoff.h,v 1.10 1996/09/26 22:39:14 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994 Adam Glass  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Adam Glass.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_EXEC_ECOFF_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_EXEC_ECOFF_H_
end_define

begin_define
define|#
directive|define
name|ECOFF_LDPGSZ
value|4096
end_define

begin_define
define|#
directive|define
name|ECOFF_PAD
define|\
value|u_short bldrev;
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|ECOFF_MACHDEP
define|\
value|u_int   gprmask; \ 	u_int   fprmask; \ 	u_long  gp_value
end_define

begin_define
define|#
directive|define
name|ECOFF_MAGIC_ALPHA
value|0603
end_define

begin_define
define|#
directive|define
name|ECOFF_MAGIC_NETBSD_ALPHA
value|0605
end_define

begin_define
define|#
directive|define
name|ECOFF_BADMAG
parameter_list|(
name|ep
parameter_list|)
value|((ep)->f.f_magic != ECOFF_MAGIC_ALPHA)
end_define

begin_define
define|#
directive|define
name|ECOFF_FLAG_EXEC
value|0002
end_define

begin_define
define|#
directive|define
name|ECOFF_SEGMENT_ALIGNMENT
parameter_list|(
name|ep
parameter_list|)
define|\
value|(((ep)->f.f_flags& ECOFF_FLAG_EXEC) == 0 ? 8 : 16)
end_define

begin_struct
struct|struct
name|ecoff_symhdr
block|{
name|int16_t
name|magic
decl_stmt|;
name|int16_t
name|vstamp
decl_stmt|;
name|int32_t
name|lineMax
decl_stmt|;
name|int32_t
name|densenumMax
decl_stmt|;
name|int32_t
name|procMax
decl_stmt|;
name|int32_t
name|lsymMax
decl_stmt|;
name|int32_t
name|optsymMax
decl_stmt|;
name|int32_t
name|auxsymMax
decl_stmt|;
name|int32_t
name|lstrMax
decl_stmt|;
name|int32_t
name|estrMax
decl_stmt|;
name|int32_t
name|fdMax
decl_stmt|;
name|int32_t
name|rfdMax
decl_stmt|;
name|int32_t
name|esymMax
decl_stmt|;
name|long
name|linesize
decl_stmt|;
name|long
name|cbLineOffset
decl_stmt|;
name|long
name|cbDnOffset
decl_stmt|;
name|long
name|cbPdOffset
decl_stmt|;
name|long
name|cbSymOffset
decl_stmt|;
name|long
name|cbOptOffset
decl_stmt|;
name|long
name|cbAuxOffset
decl_stmt|;
name|long
name|cbSsOffset
decl_stmt|;
name|long
name|cbSsExtOffset
decl_stmt|;
name|long
name|cbFdOffset
decl_stmt|;
name|long
name|cbRfdOffset
decl_stmt|;
name|long
name|cbExtOffset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecoff_extsym
block|{
name|long
name|es_value
decl_stmt|;
name|int
name|es_strindex
decl_stmt|;
name|unsigned
name|es_type
range|:
literal|6
decl_stmt|;
name|unsigned
name|es_class
range|:
literal|5
decl_stmt|;
name|unsigned
label|:
literal|1
expr_stmt|;
name|unsigned
name|es_symauxindex
range|:
literal|20
decl_stmt|;
name|unsigned
name|es_jmptbl
range|:
literal|1
decl_stmt|;
name|unsigned
name|es_cmain
range|:
literal|1
decl_stmt|;
name|unsigned
name|es_weakext
range|:
literal|1
decl_stmt|;
name|unsigned
label|:
literal|29
expr_stmt|;
name|int
name|es_indexfld
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecoff_filehdr
block|{
name|u_short
name|f_magic
decl_stmt|;
comment|/* magic number */
name|u_short
name|f_nscns
decl_stmt|;
comment|/* # of sections */
name|u_int
name|f_timdat
decl_stmt|;
comment|/* time and date stamp */
name|u_long
name|f_symptr
decl_stmt|;
comment|/* file offset of symbol table */
name|u_int
name|f_nsyms
decl_stmt|;
comment|/* # of symbol table entries */
name|u_short
name|f_opthdr
decl_stmt|;
comment|/* sizeof the optional header */
name|u_short
name|f_flags
decl_stmt|;
comment|/* flags??? */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecoff_aouthdr
block|{
name|u_short
name|magic
decl_stmt|;
name|u_short
name|vstamp
decl_stmt|;
name|ECOFF_PAD
name|u_long
name|tsize
decl_stmt|;
name|u_long
name|dsize
decl_stmt|;
name|u_long
name|bsize
decl_stmt|;
name|u_long
name|entry
decl_stmt|;
name|u_long
name|text_start
decl_stmt|;
name|u_long
name|data_start
decl_stmt|;
name|u_long
name|bss_start
decl_stmt|;
name|ECOFF_MACHDEP
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecoff_scnhdr
block|{
comment|/* needed for size info */
name|char
name|s_name
index|[
literal|8
index|]
decl_stmt|;
comment|/* name */
name|u_long
name|s_paddr
decl_stmt|;
comment|/* physical addr? for ROMing?*/
name|u_long
name|s_vaddr
decl_stmt|;
comment|/* virtual addr? */
name|u_long
name|s_size
decl_stmt|;
comment|/* size */
name|u_long
name|s_scnptr
decl_stmt|;
comment|/* file offset of raw data */
name|u_long
name|s_relptr
decl_stmt|;
comment|/* file offset of reloc data */
name|u_long
name|s_lnnoptr
decl_stmt|;
comment|/* file offset of line data */
name|u_short
name|s_nreloc
decl_stmt|;
comment|/* # of relocation entries */
name|u_short
name|s_nlnno
decl_stmt|;
comment|/* # of line entries */
name|u_int
name|s_flags
decl_stmt|;
comment|/* flags */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecoff_exechdr
block|{
name|struct
name|ecoff_filehdr
name|f
decl_stmt|;
name|struct
name|ecoff_aouthdr
name|a
decl_stmt|;
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

begin_define
define|#
directive|define
name|ECOFF_HDR_SIZE
value|(sizeof(struct ecoff_exechdr))
end_define

begin_define
define|#
directive|define
name|ECOFF_OMAGIC
value|0407
end_define

begin_define
define|#
directive|define
name|ECOFF_NMAGIC
value|0410
end_define

begin_define
define|#
directive|define
name|ECOFF_ZMAGIC
value|0413
end_define

begin_define
define|#
directive|define
name|ECOFF_ROUND
parameter_list|(
name|value
parameter_list|,
name|by
parameter_list|)
define|\
value|(((value) + (by) - 1)& ~((by) - 1))
end_define

begin_define
define|#
directive|define
name|ECOFF_BLOCK_ALIGN
parameter_list|(
name|ep
parameter_list|,
name|value
parameter_list|)
define|\
value|((ep)->a.magic == ECOFF_ZMAGIC ? ECOFF_ROUND((value), ECOFF_LDPGSZ) :  \ 	(value))
end_define

begin_define
define|#
directive|define
name|ECOFF_TXTOFF
parameter_list|(
name|ep
parameter_list|)
define|\
value|((ep)->a.magic == ECOFF_ZMAGIC ? 0 :				\ 	ECOFF_ROUND(ECOFF_HDR_SIZE + (ep)->f.f_nscns *			\ 	sizeof(struct ecoff_scnhdr), ECOFF_SEGMENT_ALIGNMENT(ep)))
end_define

begin_define
define|#
directive|define
name|ECOFF_DATOFF
parameter_list|(
name|ep
parameter_list|)
define|\
value|(ECOFF_BLOCK_ALIGN((ep), ECOFF_TXTOFF(ep) + (ep)->a.tsize))
end_define

begin_define
define|#
directive|define
name|ECOFF_SEGMENT_ALIGN
parameter_list|(
name|ep
parameter_list|,
name|value
parameter_list|)
define|\
value|(ECOFF_ROUND((value), ((ep)->a.magic == ECOFF_ZMAGIC ? ECOFF_LDPGSZ :  \ 	ECOFF_SEGMENT_ALIGNMENT(ep))))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|loader
decl_stmt|;
name|char
name|exec_path
index|[
name|PATH_MAX
index|]
decl_stmt|;
name|char
modifier|*
name|executable
decl_stmt|;
name|struct
name|nameidata
modifier|*
name|ndp
decl_stmt|;
block|}
name|Osf_Auxargs
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OSF1_EXEC_NAME
value|(1001)
end_define

begin_define
define|#
directive|define
name|OSF1_LOADER_NAME
value|(1002)
end_define

begin_define
define|#
directive|define
name|OSF1_LOADER_FLAGS
value|(1003)
end_define

begin_define
define|#
directive|define
name|DYNAMIC_FLAG
value|0x3000
end_define

begin_define
define|#
directive|define
name|DEFAULT_LOADER
value|"/sbin/loader"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_EXEC_ECOFF_H_ */
end_comment

end_unit

