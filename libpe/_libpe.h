begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Kai Wang  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: _libpe.h 3312 2016-01-10 09:23:51Z kaiwang27 $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBPE_H_
end_ifndef

begin_define
define|#
directive|define
name|__LIBPE_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|"libpe.h"
end_include

begin_include
include|#
directive|include
file|"_elftc.h"
end_include

begin_typedef
typedef|typedef
struct|struct
name|_PE_SecBuf
block|{
name|PE_Buffer
name|sb_pb
decl_stmt|;
comment|/* application buffer */
name|PE_Scn
modifier|*
name|sb_ps
decl_stmt|;
comment|/* PE_Scn pointer */
name|unsigned
name|int
name|sb_flags
decl_stmt|;
comment|/* buffer flags */
name|STAILQ_ENTRY
argument_list|(
argument|_PE_SecBuf
argument_list|)
name|sb_next
expr_stmt|;
block|}
name|PE_SecBuf
typedef|;
end_typedef

begin_struct
struct|struct
name|_PE_Scn
block|{
name|PE
modifier|*
name|ps_pe
decl_stmt|;
comment|/* PE descriptor */
name|PE_SecHdr
name|ps_sh
decl_stmt|;
comment|/* section header */
name|unsigned
name|int
name|ps_ndx
decl_stmt|;
comment|/* 1-based section index */
name|unsigned
name|int
name|ps_flags
decl_stmt|;
comment|/* section flags */
name|unsigned
name|int
name|ps_falign
decl_stmt|;
comment|/* section file alignment */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_PE_SecBuf
argument_list|)
name|ps_b
expr_stmt|;
comment|/* buffer list */
name|STAILQ_ENTRY
argument_list|(
argument|_PE_Scn
argument_list|)
name|ps_next
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_PE
block|{
name|int
name|pe_fd
decl_stmt|;
comment|/* file descriptor */
name|PE_Cmd
name|pe_cmd
decl_stmt|;
comment|/* open mode */
name|PE_Object
name|pe_obj
decl_stmt|;
comment|/* PE32/PE32+/COFF */
name|size_t
name|pe_fsize
decl_stmt|;
comment|/* file size */
name|unsigned
name|int
name|pe_flags
decl_stmt|;
comment|/* library flags */
name|PE_DosHdr
modifier|*
name|pe_dh
decl_stmt|;
comment|/* MS-DOS header */
name|char
modifier|*
name|pe_stub
decl_stmt|;
comment|/* MS-DOS stub */
name|size_t
name|pe_stub_ex
decl_stmt|;
comment|/* MS-DOS stub len (exclude hdr) */
name|char
modifier|*
name|pe_stub_app
decl_stmt|;
comment|/* MS-DOS stub (app supplied) */
name|size_t
name|pe_stub_app_sz
decl_stmt|;
comment|/* MS-DOS stub len (app supplied) */
name|PE_RichHdr
modifier|*
name|pe_rh
decl_stmt|;
comment|/* rich header */
name|char
modifier|*
name|pe_rh_start
decl_stmt|;
comment|/* pointer to rich header */
name|PE_CoffHdr
modifier|*
name|pe_ch
decl_stmt|;
comment|/* COFF header */
name|PE_OptHdr
modifier|*
name|pe_oh
decl_stmt|;
comment|/* optional header */
name|PE_DataDir
modifier|*
name|pe_dd
decl_stmt|;
comment|/* data directories */
name|unsigned
name|int
name|pe_nscn
decl_stmt|;
comment|/* num. of sections */
name|char
modifier|*
name|pe_symtab
decl_stmt|;
comment|/* COFF symbol table */
name|size_t
name|pe_symbtab_sz
decl_stmt|;
comment|/* size of symbol table */
name|unsigned
name|int
name|pe_nsym
decl_stmt|;
comment|/* num. of symbols */
name|unsigned
name|int
name|pe_rvamax
decl_stmt|;
comment|/* maximum RVA */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_PE_Scn
argument_list|)
name|pe_scn
expr_stmt|;
comment|/* section list */
block|}
struct|;
end_struct

begin_comment
comment|/* Library internal flags  */
end_comment

begin_define
define|#
directive|define
name|LIBPE_F_API_MASK
value|0x000FFFU
end_define

begin_define
define|#
directive|define
name|LIBPE_F_SPECIAL_FILE
value|0x001000U
end_define

begin_define
define|#
directive|define
name|LIBPE_F_BAD_DOS_HEADER
value|0x002000U
end_define

begin_define
define|#
directive|define
name|LIBPE_F_BAD_PE_HEADER
value|0x004000U
end_define

begin_define
define|#
directive|define
name|LIBPE_F_BAD_COFF_HEADER
value|0x008000U
end_define

begin_define
define|#
directive|define
name|LIBPE_F_BAD_OPT_HEADER
value|0x010000U
end_define

begin_define
define|#
directive|define
name|LIBPE_F_BAD_SEC_HEADER
value|0x020000U
end_define

begin_define
define|#
directive|define
name|LIBPE_F_LOAD_DOS_STUB
value|0x040000U
end_define

begin_define
define|#
directive|define
name|LIBPE_F_FD_DONE
value|0x080000U
end_define

begin_define
define|#
directive|define
name|LIBPE_F_DIRTY_DOS_HEADER
value|0x100000U
end_define

begin_define
define|#
directive|define
name|LIBPE_F_DIRTY_COFF_HEADER
value|0x200000U
end_define

begin_define
define|#
directive|define
name|LIBPE_F_DIRTY_OPT_HEADER
value|0x400000U
end_define

begin_define
define|#
directive|define
name|LIBPE_F_DIRTY_SEC_HEADER
value|0x800000U
end_define

begin_comment
comment|/* Internal section flags */
end_comment

begin_define
define|#
directive|define
name|LIBPE_F_LOAD_SECTION
value|0x1000U
end_define

begin_define
define|#
directive|define
name|LIBPE_F_STRIP_SECTION
value|0x2000U
end_define

begin_comment
comment|/* Internal buffer flags */
end_comment

begin_define
define|#
directive|define
name|LIBPE_F_BUFFER_MALLOCED
value|0x1000U
end_define

begin_comment
comment|/* Library internal defines */
end_comment

begin_define
define|#
directive|define
name|PE_DOS_MAGIC
value|0x5a4dU
end_define

begin_define
define|#
directive|define
name|PE_RICH_TEXT
value|"Rich"
end_define

begin_define
define|#
directive|define
name|PE_RICH_HIDDEN
value|0x536e6144U
end_define

begin_comment
comment|/* DanS */
end_comment

begin_define
define|#
directive|define
name|PE_SIGNATURE
value|0x4550U
end_define

begin_comment
comment|/* PE\0\0 */
end_comment

begin_define
define|#
directive|define
name|PE_COFF_OPT_SIZE_32
value|224
end_define

begin_define
define|#
directive|define
name|PE_COFF_OPT_SIZE_32P
value|240
end_define

begin_define
define|#
directive|define
name|PE_SYM_ENTRY_SIZE
value|18
end_define

begin_comment
comment|/* Encode/Decode macros */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ELFTC_NEED_BYTEORDER_EXTENSIONS
argument_list|)
end_if

begin_function
specifier|static
name|__inline
name|uint16_t
name|le16dec
parameter_list|(
specifier|const
name|void
modifier|*
name|pp
parameter_list|)
block|{
name|unsigned
name|char
specifier|const
modifier|*
name|p
init|=
operator|(
name|unsigned
name|char
specifier|const
operator|*
operator|)
name|pp
decl_stmt|;
return|return
operator|(
operator|(
name|p
index|[
literal|1
index|]
operator|<<
literal|8
operator|)
operator||
name|p
index|[
literal|0
index|]
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint32_t
name|le32dec
parameter_list|(
specifier|const
name|void
modifier|*
name|pp
parameter_list|)
block|{
name|unsigned
name|char
specifier|const
modifier|*
name|p
init|=
operator|(
name|unsigned
name|char
specifier|const
operator|*
operator|)
name|pp
decl_stmt|;
return|return
operator|(
operator|(
name|p
index|[
literal|3
index|]
operator|<<
literal|24
operator|)
operator||
operator|(
name|p
index|[
literal|2
index|]
operator|<<
literal|16
operator|)
operator||
operator|(
name|p
index|[
literal|1
index|]
operator|<<
literal|8
operator|)
operator||
name|p
index|[
literal|0
index|]
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint64_t
name|le64dec
parameter_list|(
specifier|const
name|void
modifier|*
name|pp
parameter_list|)
block|{
name|unsigned
name|char
specifier|const
modifier|*
name|p
init|=
operator|(
name|unsigned
name|char
specifier|const
operator|*
operator|)
name|pp
decl_stmt|;
return|return
operator|(
operator|(
operator|(
name|uint64_t
operator|)
name|le32dec
argument_list|(
name|p
operator|+
literal|4
argument_list|)
operator|<<
literal|32
operator|)
operator||
name|le32dec
argument_list|(
name|p
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|le16enc
parameter_list|(
name|void
modifier|*
name|pp
parameter_list|,
name|uint16_t
name|u
parameter_list|)
block|{
name|unsigned
name|char
modifier|*
name|p
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|pp
decl_stmt|;
name|p
index|[
literal|0
index|]
operator|=
name|u
operator|&
literal|0xff
expr_stmt|;
name|p
index|[
literal|1
index|]
operator|=
operator|(
name|u
operator|>>
literal|8
operator|)
operator|&
literal|0xff
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|le32enc
parameter_list|(
name|void
modifier|*
name|pp
parameter_list|,
name|uint32_t
name|u
parameter_list|)
block|{
name|unsigned
name|char
modifier|*
name|p
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|pp
decl_stmt|;
name|p
index|[
literal|0
index|]
operator|=
name|u
operator|&
literal|0xff
expr_stmt|;
name|p
index|[
literal|1
index|]
operator|=
operator|(
name|u
operator|>>
literal|8
operator|)
operator|&
literal|0xff
expr_stmt|;
name|p
index|[
literal|2
index|]
operator|=
operator|(
name|u
operator|>>
literal|16
operator|)
operator|&
literal|0xff
expr_stmt|;
name|p
index|[
literal|3
index|]
operator|=
operator|(
name|u
operator|>>
literal|24
operator|)
operator|&
literal|0xff
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|le64enc
parameter_list|(
name|void
modifier|*
name|pp
parameter_list|,
name|uint64_t
name|u
parameter_list|)
block|{
name|unsigned
name|char
modifier|*
name|p
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|pp
decl_stmt|;
name|le32enc
argument_list|(
name|p
argument_list|,
call|(
name|uint32_t
call|)
argument_list|(
name|u
operator|&
literal|0xffffffffU
argument_list|)
argument_list|)
expr_stmt|;
name|le32enc
argument_list|(
name|p
operator|+
literal|4
argument_list|,
call|(
name|uint32_t
call|)
argument_list|(
name|u
operator|>>
literal|32
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ELFTC_NEED_BYTEORDER_EXTENSIONS */
end_comment

begin_define
define|#
directive|define
name|PE_READ16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|do {			\ 	(v) = le16dec((p));			\ 	(p) += 2;				\ } while(0)
end_define

begin_define
define|#
directive|define
name|PE_READ32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|do {			\ 	(v) = le32dec((p));			\ 	(p) += 4;				\ } while(0)
end_define

begin_define
define|#
directive|define
name|PE_WRITE16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|do {			\ 	le16enc((p), (v));			\ 	(p) += 2;				\ } while(0)
end_define

begin_define
define|#
directive|define
name|PE_WRITE32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|do {			\ 	le32enc((p), (v));			\ 	(p) += 4;				\ } while(0)
end_define

begin_comment
comment|/* Internal function declarations */
end_comment

begin_function_decl
name|off_t
name|libpe_align
parameter_list|(
name|PE
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PE_SecBuf
modifier|*
name|libpe_alloc_buffer
parameter_list|(
name|PE_Scn
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PE_Scn
modifier|*
name|libpe_alloc_scn
parameter_list|(
name|PE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|libpe_load_all_sections
parameter_list|(
name|PE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|libpe_load_section
parameter_list|(
name|PE
modifier|*
parameter_list|,
name|PE_Scn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|libpe_open_object
parameter_list|(
name|PE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|libpe_pad
parameter_list|(
name|PE
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|libpe_parse_msdos_header
parameter_list|(
name|PE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|libpe_parse_coff_header
parameter_list|(
name|PE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|libpe_parse_rich_header
parameter_list|(
name|PE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|libpe_parse_section_headers
parameter_list|(
name|PE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|libpe_read_msdos_stub
parameter_list|(
name|PE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|libpe_release_buffer
parameter_list|(
name|PE_SecBuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|libpe_release_object
parameter_list|(
name|PE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|libpe_release_scn
parameter_list|(
name|PE_Scn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|libpe_resync_buffers
parameter_list|(
name|PE_Scn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|libpe_resync_sections
parameter_list|(
name|PE
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|libpe_write_buffers
parameter_list|(
name|PE_Scn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|libpe_write_coff_header
parameter_list|(
name|PE
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|libpe_write_msdos_stub
parameter_list|(
name|PE
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|libpe_write_pe_header
parameter_list|(
name|PE
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|libpe_write_sections
parameter_list|(
name|PE
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|libpe_write_section_headers
parameter_list|(
name|PE
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__LIBPE_H_ */
end_comment

end_unit

