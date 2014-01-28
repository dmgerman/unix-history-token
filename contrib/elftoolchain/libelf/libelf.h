begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006,2008-2010 Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: libelf.h 2366 2011-12-29 06:12:14Z jkoshy $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBELF_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBELF_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/elf32.h>
end_include

begin_include
include|#
directive|include
file|<sys/elf64.h>
end_include

begin_comment
comment|/* Library private data structures */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_Elf
name|Elf
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_Elf_Scn
name|Elf_Scn
typedef|;
end_typedef

begin_comment
comment|/* File types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ELF_K_NONE
init|=
literal|0
block|,
name|ELF_K_AR
block|,
comment|/* `ar' archives */
name|ELF_K_COFF
block|,
comment|/* COFF files (unsupported) */
name|ELF_K_ELF
block|,
comment|/* ELF files */
name|ELF_K_NUM
block|}
name|Elf_Kind
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ELF_K_FIRST
value|ELF_K_NONE
end_define

begin_define
define|#
directive|define
name|ELF_K_LAST
value|ELF_K_NUM
end_define

begin_comment
comment|/* Data types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ELF_T_ADDR
block|,
name|ELF_T_BYTE
block|,
name|ELF_T_CAP
block|,
name|ELF_T_DYN
block|,
name|ELF_T_EHDR
block|,
name|ELF_T_HALF
block|,
name|ELF_T_LWORD
block|,
name|ELF_T_MOVE
block|,
name|ELF_T_MOVEP
block|,
name|ELF_T_NOTE
block|,
name|ELF_T_OFF
block|,
name|ELF_T_PHDR
block|,
name|ELF_T_REL
block|,
name|ELF_T_RELA
block|,
name|ELF_T_SHDR
block|,
name|ELF_T_SWORD
block|,
name|ELF_T_SXWORD
block|,
name|ELF_T_SYMINFO
block|,
name|ELF_T_SYM
block|,
name|ELF_T_VDEF
block|,
name|ELF_T_VNEED
block|,
name|ELF_T_WORD
block|,
name|ELF_T_XWORD
block|,
name|ELF_T_GNUHASH
block|,
comment|/* GNU style hash tables. */
name|ELF_T_NUM
block|}
name|Elf_Type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ELF_T_FIRST
value|ELF_T_ADDR
end_define

begin_define
define|#
directive|define
name|ELF_T_LAST
value|ELF_T_GNUHASH
end_define

begin_comment
comment|/* Commands */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ELF_C_NULL
init|=
literal|0
block|,
name|ELF_C_CLR
block|,
name|ELF_C_FDDONE
block|,
name|ELF_C_FDREAD
block|,
name|ELF_C_RDWR
block|,
name|ELF_C_READ
block|,
name|ELF_C_SET
block|,
name|ELF_C_WRITE
block|,
name|ELF_C_NUM
block|}
name|Elf_Cmd
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ELF_C_FIRST
value|ELF_C_NULL
end_define

begin_define
define|#
directive|define
name|ELF_C_LAST
value|ELF_C_NUM
end_define

begin_comment
comment|/*  * An `Elf_Data' structure describes data in an  * ELF section.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_Elf_Data
block|{
comment|/* 	 * `Public' members that are part of the ELF(3) API. 	 */
name|uint64_t
name|d_align
decl_stmt|;
name|void
modifier|*
name|d_buf
decl_stmt|;
name|uint64_t
name|d_off
decl_stmt|;
name|uint64_t
name|d_size
decl_stmt|;
name|Elf_Type
name|d_type
decl_stmt|;
name|unsigned
name|int
name|d_version
decl_stmt|;
block|}
name|Elf_Data
typedef|;
end_typedef

begin_comment
comment|/*  * An `Elf_Arhdr' structure describes an archive  * header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|time_t
name|ar_date
decl_stmt|;
name|char
modifier|*
name|ar_name
decl_stmt|;
comment|/* archive member name */
name|gid_t
name|ar_gid
decl_stmt|;
name|mode_t
name|ar_mode
decl_stmt|;
name|char
modifier|*
name|ar_rawname
decl_stmt|;
comment|/* 'raw' member name */
name|size_t
name|ar_size
decl_stmt|;
name|uid_t
name|ar_uid
decl_stmt|;
comment|/* 	 * Members that are not part of the public API. 	 */
name|int
name|ar_flags
decl_stmt|;
block|}
name|Elf_Arhdr
typedef|;
end_typedef

begin_comment
comment|/*  * An `Elf_Arsym' describes an entry in the archive  * symbol table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|off_t
name|as_off
decl_stmt|;
comment|/* byte offset to member's header */
name|unsigned
name|long
name|as_hash
decl_stmt|;
comment|/* elf_hash() value for name */
name|char
modifier|*
name|as_name
decl_stmt|;
comment|/* null terminated symbol name */
block|}
name|Elf_Arsym
typedef|;
end_typedef

begin_comment
comment|/*  * Error numbers.  */
end_comment

begin_enum
enum|enum
name|Elf_Error
block|{
name|ELF_E_NONE
block|,
comment|/* No error */
name|ELF_E_ARCHIVE
block|,
comment|/* Malformed ar(1) archive */
name|ELF_E_ARGUMENT
block|,
comment|/* Invalid argument */
name|ELF_E_CLASS
block|,
comment|/* Mismatched ELF class */
name|ELF_E_DATA
block|,
comment|/* Invalid data descriptor */
name|ELF_E_HEADER
block|,
comment|/* Missing or malformed ELF header */
name|ELF_E_IO
block|,
comment|/* I/O error */
name|ELF_E_LAYOUT
block|,
comment|/* Layout constraint violation */
name|ELF_E_MODE
block|,
comment|/* Wrong mode for ELF descriptor */
name|ELF_E_RANGE
block|,
comment|/* Value out of range */
name|ELF_E_RESOURCE
block|,
comment|/* Resource exhaustion */
name|ELF_E_SECTION
block|,
comment|/* Invalid section descriptor */
name|ELF_E_SEQUENCE
block|,
comment|/* API calls out of sequence */
name|ELF_E_UNIMPL
block|,
comment|/* Feature is unimplemented */
name|ELF_E_VERSION
block|,
comment|/* Unknown API version */
name|ELF_E_NUM
comment|/* Max error number */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Flags defined by the API.  */
end_comment

begin_define
define|#
directive|define
name|ELF_F_LAYOUT
value|0x001U
end_define

begin_comment
comment|/* application will layout the file */
end_comment

begin_define
define|#
directive|define
name|ELF_F_DIRTY
value|0x002U
end_define

begin_comment
comment|/* a section or ELF file is dirty */
end_comment

begin_comment
comment|/* ELF(3) API extensions. */
end_comment

begin_define
define|#
directive|define
name|ELF_F_ARCHIVE
value|0x100U
end_define

begin_comment
comment|/* archive creation */
end_comment

begin_define
define|#
directive|define
name|ELF_F_ARCHIVE_SYSV
value|0x200U
end_define

begin_comment
comment|/* SYSV style archive */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|Elf
modifier|*
name|elf_begin
parameter_list|(
name|int
name|_fd
parameter_list|,
name|Elf_Cmd
name|_cmd
parameter_list|,
name|Elf
modifier|*
name|_elf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elf_cntl
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|Elf_Cmd
name|_cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elf_end
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|elf_errmsg
parameter_list|(
name|int
name|_error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elf_errno
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|elf_fill
parameter_list|(
name|int
name|_fill
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|elf_flagarhdr
parameter_list|(
name|Elf_Arhdr
modifier|*
name|_arh
parameter_list|,
name|Elf_Cmd
name|_cmd
parameter_list|,
name|unsigned
name|int
name|_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|elf_flagdata
parameter_list|(
name|Elf_Data
modifier|*
name|_data
parameter_list|,
name|Elf_Cmd
name|_cmd
parameter_list|,
name|unsigned
name|int
name|_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|elf_flagehdr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|Elf_Cmd
name|_cmd
parameter_list|,
name|unsigned
name|int
name|_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|elf_flagelf
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|Elf_Cmd
name|_cmd
parameter_list|,
name|unsigned
name|int
name|_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|elf_flagphdr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|Elf_Cmd
name|_cmd
parameter_list|,
name|unsigned
name|int
name|_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|elf_flagscn
parameter_list|(
name|Elf_Scn
modifier|*
name|_scn
parameter_list|,
name|Elf_Cmd
name|_cmd
parameter_list|,
name|unsigned
name|int
name|_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|elf_flagshdr
parameter_list|(
name|Elf_Scn
modifier|*
name|_scn
parameter_list|,
name|Elf_Cmd
name|_cmd
parameter_list|,
name|unsigned
name|int
name|_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf_Arhdr
modifier|*
name|elf_getarhdr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf_Arsym
modifier|*
name|elf_getarsym
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|size_t
modifier|*
name|_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|elf_getbase
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf_Data
modifier|*
name|elf_getdata
parameter_list|(
name|Elf_Scn
modifier|*
parameter_list|,
name|Elf_Data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|elf_getident
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|size_t
modifier|*
name|_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elf_getphdrnum
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|size_t
modifier|*
name|_dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elf_getphnum
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|size_t
modifier|*
name|_dst
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Deprecated */
end_comment

begin_function_decl
name|Elf_Scn
modifier|*
name|elf_getscn
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|size_t
name|_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elf_getshdrnum
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|size_t
modifier|*
name|_dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elf_getshnum
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|size_t
modifier|*
name|_dst
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Deprecated */
end_comment

begin_function_decl
name|int
name|elf_getshdrstrndx
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|size_t
modifier|*
name|_dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elf_getshstrndx
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|size_t
modifier|*
name|_dst
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Deprecated */
end_comment

begin_function_decl
name|unsigned
name|long
name|elf_hash
parameter_list|(
specifier|const
name|char
modifier|*
name|_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf_Kind
name|elf_kind
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf
modifier|*
name|elf_memory
parameter_list|(
name|char
modifier|*
name|_image
parameter_list|,
name|size_t
name|_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|elf_ndxscn
parameter_list|(
name|Elf_Scn
modifier|*
name|_scn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf_Data
modifier|*
name|elf_newdata
parameter_list|(
name|Elf_Scn
modifier|*
name|_scn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf_Scn
modifier|*
name|elf_newscn
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf_Scn
modifier|*
name|elf_nextscn
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|Elf_Scn
modifier|*
name|_scn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf_Cmd
name|elf_next
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf
modifier|*
name|elf_open
parameter_list|(
name|int
name|_fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf
modifier|*
name|elf_openmemory
parameter_list|(
name|char
modifier|*
name|_image
parameter_list|,
name|size_t
name|_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|elf_rand
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|off_t
name|_off
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf_Data
modifier|*
name|elf_rawdata
parameter_list|(
name|Elf_Scn
modifier|*
name|_scn
parameter_list|,
name|Elf_Data
modifier|*
name|_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|elf_rawfile
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|size_t
modifier|*
name|_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elf_setshstrndx
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|size_t
name|_shnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|elf_strptr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|size_t
name|_section
parameter_list|,
name|size_t
name|_offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|elf_update
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|Elf_Cmd
name|_cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|elf_version
parameter_list|(
name|unsigned
name|int
name|_version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|elf32_checksum
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|elf32_fsize
parameter_list|(
name|Elf_Type
name|_type
parameter_list|,
name|size_t
name|_count
parameter_list|,
name|unsigned
name|int
name|_version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf32_Ehdr
modifier|*
name|elf32_getehdr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf32_Phdr
modifier|*
name|elf32_getphdr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf32_Shdr
modifier|*
name|elf32_getshdr
parameter_list|(
name|Elf_Scn
modifier|*
name|_scn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf32_Ehdr
modifier|*
name|elf32_newehdr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf32_Phdr
modifier|*
name|elf32_newphdr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|size_t
name|_count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf_Data
modifier|*
name|elf32_xlatetof
parameter_list|(
name|Elf_Data
modifier|*
name|_dst
parameter_list|,
specifier|const
name|Elf_Data
modifier|*
name|_src
parameter_list|,
name|unsigned
name|int
name|_enc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf_Data
modifier|*
name|elf32_xlatetom
parameter_list|(
name|Elf_Data
modifier|*
name|_dst
parameter_list|,
specifier|const
name|Elf_Data
modifier|*
name|_src
parameter_list|,
name|unsigned
name|int
name|_enc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|elf64_checksum
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|elf64_fsize
parameter_list|(
name|Elf_Type
name|_type
parameter_list|,
name|size_t
name|_count
parameter_list|,
name|unsigned
name|int
name|_version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf64_Ehdr
modifier|*
name|elf64_getehdr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf64_Phdr
modifier|*
name|elf64_getphdr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf64_Shdr
modifier|*
name|elf64_getshdr
parameter_list|(
name|Elf_Scn
modifier|*
name|_scn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf64_Ehdr
modifier|*
name|elf64_newehdr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf64_Phdr
modifier|*
name|elf64_newphdr
parameter_list|(
name|Elf
modifier|*
name|_elf
parameter_list|,
name|size_t
name|_count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf_Data
modifier|*
name|elf64_xlatetof
parameter_list|(
name|Elf_Data
modifier|*
name|_dst
parameter_list|,
specifier|const
name|Elf_Data
modifier|*
name|_src
parameter_list|,
name|unsigned
name|int
name|_enc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf_Data
modifier|*
name|elf64_xlatetom
parameter_list|(
name|Elf_Data
modifier|*
name|_dst
parameter_list|,
specifier|const
name|Elf_Data
modifier|*
name|_src
parameter_list|,
name|unsigned
name|int
name|_enc
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBELF_H_ */
end_comment

end_unit

