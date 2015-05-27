begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006,2008-2011 Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: _libelf.h 3174 2015-03-27 17:13:41Z emaste $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBELF_H_
end_ifndef

begin_define
define|#
directive|define
name|__LIBELF_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|"_libelf_config.h"
end_include

begin_include
include|#
directive|include
file|"_elftc.h"
end_include

begin_comment
comment|/*  * Library-private data structures.  */
end_comment

begin_define
define|#
directive|define
name|LIBELF_MSG_SIZE
value|256
end_define

begin_struct
struct|struct
name|_libelf_globals
block|{
name|int
name|libelf_arch
decl_stmt|;
name|unsigned
name|int
name|libelf_byteorder
decl_stmt|;
name|int
name|libelf_class
decl_stmt|;
name|int
name|libelf_error
decl_stmt|;
name|int
name|libelf_fillchar
decl_stmt|;
name|unsigned
name|int
name|libelf_version
decl_stmt|;
name|unsigned
name|char
name|libelf_msg
index|[
name|LIBELF_MSG_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|_libelf_globals
name|_libelf
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LIBELF_PRIVATE
parameter_list|(
name|N
parameter_list|)
value|(_libelf.libelf_##N)
end_define

begin_define
define|#
directive|define
name|LIBELF_ELF_ERROR_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|LIBELF_OS_ERROR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|LIBELF_ERROR
parameter_list|(
name|E
parameter_list|,
name|O
parameter_list|)
value|(((E)& LIBELF_ELF_ERROR_MASK) |	\ 	((O)<< LIBELF_OS_ERROR_SHIFT))
end_define

begin_define
define|#
directive|define
name|LIBELF_SET_ERROR
parameter_list|(
name|E
parameter_list|,
name|O
parameter_list|)
value|do {					\ 		LIBELF_PRIVATE(error) = LIBELF_ERROR(ELF_E_##E, (O));	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|LIBELF_ADJUST_AR_SIZE
parameter_list|(
name|S
parameter_list|)
value|(((S) + 1U)& ~1U)
end_define

begin_comment
comment|/*  * Flags for library internal use.  These use the upper 16 bits of the  * `e_flags' field.  */
end_comment

begin_define
define|#
directive|define
name|LIBELF_F_API_MASK
value|0x00FFFFU
end_define

begin_comment
comment|/* Flags defined by the API. */
end_comment

begin_define
define|#
directive|define
name|LIBELF_F_AR_HEADER
value|0x010000U
end_define

begin_comment
comment|/* translated header available */
end_comment

begin_define
define|#
directive|define
name|LIBELF_F_AR_VARIANT_SVR4
value|0x020000U
end_define

begin_comment
comment|/* BSD style ar(1) archive */
end_comment

begin_define
define|#
directive|define
name|LIBELF_F_DATA_MALLOCED
value|0x040000U
end_define

begin_comment
comment|/* whether data was malloc'ed */
end_comment

begin_define
define|#
directive|define
name|LIBELF_F_RAWFILE_MALLOC
value|0x080000U
end_define

begin_comment
comment|/* whether e_rawfile was malloc'ed */
end_comment

begin_define
define|#
directive|define
name|LIBELF_F_RAWFILE_MMAP
value|0x100000U
end_define

begin_comment
comment|/* whether e_rawfile was mmap'ed */
end_comment

begin_define
define|#
directive|define
name|LIBELF_F_SHDRS_LOADED
value|0x200000U
end_define

begin_comment
comment|/* whether all shdrs were read in */
end_comment

begin_define
define|#
directive|define
name|LIBELF_F_SPECIAL_FILE
value|0x400000U
end_define

begin_comment
comment|/* non-regular file */
end_comment

begin_struct
struct|struct
name|_Elf
block|{
name|int
name|e_activations
decl_stmt|;
comment|/* activation count */
name|unsigned
name|int
name|e_byteorder
decl_stmt|;
comment|/* ELFDATA* */
name|int
name|e_class
decl_stmt|;
comment|/* ELFCLASS*  */
name|Elf_Cmd
name|e_cmd
decl_stmt|;
comment|/* ELF_C_* used at creation time */
name|int
name|e_fd
decl_stmt|;
comment|/* associated file descriptor */
name|unsigned
name|int
name|e_flags
decl_stmt|;
comment|/* ELF_F_*& LIBELF_F_* flags */
name|Elf_Kind
name|e_kind
decl_stmt|;
comment|/* ELF_K_* */
name|Elf
modifier|*
name|e_parent
decl_stmt|;
comment|/* non-NULL for archive members */
name|unsigned
name|char
modifier|*
name|e_rawfile
decl_stmt|;
comment|/* uninterpreted bytes */
name|size_t
name|e_rawsize
decl_stmt|;
comment|/* size of uninterpreted bytes */
name|unsigned
name|int
name|e_version
decl_stmt|;
comment|/* file version */
comment|/* 	 * Header information for archive members.  See the 	 * LIBELF_F_AR_HEADER flag. 	 */
union|union
block|{
name|Elf_Arhdr
modifier|*
name|e_arhdr
decl_stmt|;
comment|/* translated header */
name|unsigned
name|char
modifier|*
name|e_rawhdr
decl_stmt|;
comment|/* untranslated header */
block|}
name|e_hdr
union|;
union|union
block|{
struct|struct
block|{
comment|/* ar(1) archives */
name|off_t
name|e_next
decl_stmt|;
comment|/* set by elf_rand()/elf_next() */
name|int
name|e_nchildren
decl_stmt|;
name|unsigned
name|char
modifier|*
name|e_rawstrtab
decl_stmt|;
comment|/* file name strings */
name|size_t
name|e_rawstrtabsz
decl_stmt|;
name|unsigned
name|char
modifier|*
name|e_rawsymtab
decl_stmt|;
comment|/* symbol table */
name|size_t
name|e_rawsymtabsz
decl_stmt|;
name|Elf_Arsym
modifier|*
name|e_symtab
decl_stmt|;
name|size_t
name|e_symtabsz
decl_stmt|;
block|}
name|e_ar
struct|;
struct|struct
block|{
comment|/* regular ELF files */
union|union
block|{
name|Elf32_Ehdr
modifier|*
name|e_ehdr32
decl_stmt|;
name|Elf64_Ehdr
modifier|*
name|e_ehdr64
decl_stmt|;
block|}
name|e_ehdr
union|;
union|union
block|{
name|Elf32_Phdr
modifier|*
name|e_phdr32
decl_stmt|;
name|Elf64_Phdr
modifier|*
name|e_phdr64
decl_stmt|;
block|}
name|e_phdr
union|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Elf_Scn
argument_list|)
name|e_scn
expr_stmt|;
comment|/* section list */
name|size_t
name|e_nphdr
decl_stmt|;
comment|/* number of Phdr entries */
name|size_t
name|e_nscn
decl_stmt|;
comment|/* number of sections */
name|size_t
name|e_strndx
decl_stmt|;
comment|/* string table section index */
block|}
name|e_elf
struct|;
block|}
name|e_u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The internal descriptor wrapping the "Elf_Data" type.  */
end_comment

begin_struct
struct|struct
name|_Libelf_Data
block|{
name|Elf_Data
name|d_data
decl_stmt|;
comment|/* The exported descriptor. */
name|Elf_Scn
modifier|*
name|d_scn
decl_stmt|;
comment|/* The containing section */
name|unsigned
name|int
name|d_flags
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|_Libelf_Data
argument_list|)
name|d_next
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Elf_Scn
block|{
union|union
block|{
name|Elf32_Shdr
name|s_shdr32
decl_stmt|;
name|Elf64_Shdr
name|s_shdr64
decl_stmt|;
block|}
name|s_shdr
union|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Libelf_Data
argument_list|)
name|s_data
expr_stmt|;
comment|/* translated data */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Libelf_Data
argument_list|)
name|s_rawdata
expr_stmt|;
comment|/* raw data */
name|STAILQ_ENTRY
argument_list|(
argument|_Elf_Scn
argument_list|)
name|s_next
expr_stmt|;
name|struct
name|_Elf
modifier|*
name|s_elf
decl_stmt|;
comment|/* parent ELF descriptor */
name|unsigned
name|int
name|s_flags
decl_stmt|;
comment|/* flags for the section as a whole */
name|size_t
name|s_ndx
decl_stmt|;
comment|/* index# for this section */
name|uint64_t
name|s_offset
decl_stmt|;
comment|/* managed by elf_update() */
name|uint64_t
name|s_rawoff
decl_stmt|;
comment|/* original offset in the file */
name|uint64_t
name|s_size
decl_stmt|;
comment|/* managed by elf_update() */
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|ELF_TOFILE
block|,
name|ELF_TOMEMORY
block|}
enum|;
end_enum

begin_comment
comment|/*  * The LIBELF_COPY macros are used to copy fields from a GElf_*  * structure to their 32-bit counterparts, while checking for out of  * range values.  *  * - LIBELF_COPY_U32 :: copy an unsigned 32 bit field.  * - LIBELF_COPY_S32 :: copy a signed 32 bit field.  */
end_comment

begin_define
define|#
directive|define
name|LIBELF_COPY_U32
parameter_list|(
name|DST
parameter_list|,
name|SRC
parameter_list|,
name|NAME
parameter_list|)
value|do {			\ 		if ((SRC)->NAME> UINT32_MAX) {			\ 			LIBELF_SET_ERROR(RANGE, 0);		\ 			return (0);				\ 		}						\ 		(DST)->NAME = (SRC)->NAME& 0xFFFFFFFFU;	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|LIBELF_COPY_S32
parameter_list|(
name|DST
parameter_list|,
name|SRC
parameter_list|,
name|NAME
parameter_list|)
value|do {			\ 		if ((SRC)->NAME> INT32_MAX ||			\ 		    (SRC)->NAME< INT32_MIN) {			\ 			LIBELF_SET_ERROR(RANGE, 0);		\ 			return (0);				\ 		}						\ 		(DST)->NAME = (int32_t) (SRC)->NAME;		\ 	} while (0)
end_define

begin_comment
comment|/*  * Function Prototypes.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
name|struct
name|_Libelf_Data
modifier|*
name|_libelf_allocate_data
parameter_list|(
name|Elf_Scn
modifier|*
name|_s
parameter_list|)
function_decl|;
name|Elf
modifier|*
name|_libelf_allocate_elf
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|Elf_Scn
modifier|*
name|_libelf_allocate_scn
parameter_list|(
name|Elf
modifier|*
name|_e
parameter_list|,
name|size_t
name|_ndx
parameter_list|)
function_decl|;
name|Elf_Arhdr
modifier|*
name|_libelf_ar_gethdr
parameter_list|(
name|Elf
modifier|*
name|_e
parameter_list|)
function_decl|;
name|Elf
modifier|*
name|_libelf_ar_open
parameter_list|(
name|Elf
modifier|*
name|_e
parameter_list|,
name|int
name|_reporterror
parameter_list|)
function_decl|;
name|Elf
modifier|*
name|_libelf_ar_open_member
parameter_list|(
name|int
name|_fd
parameter_list|,
name|Elf_Cmd
name|_c
parameter_list|,
name|Elf
modifier|*
name|_ar
parameter_list|)
function_decl|;
name|Elf_Arsym
modifier|*
name|_libelf_ar_process_bsd_symtab
parameter_list|(
name|Elf
modifier|*
name|_ar
parameter_list|,
name|size_t
modifier|*
name|_dst
parameter_list|)
function_decl|;
name|Elf_Arsym
modifier|*
name|_libelf_ar_process_svr4_symtab
parameter_list|(
name|Elf
modifier|*
name|_ar
parameter_list|,
name|size_t
modifier|*
name|_dst
parameter_list|)
function_decl|;
name|long
name|_libelf_checksum
parameter_list|(
name|Elf
modifier|*
name|_e
parameter_list|,
name|int
name|_elfclass
parameter_list|)
function_decl|;
name|void
modifier|*
name|_libelf_ehdr
parameter_list|(
name|Elf
modifier|*
name|_e
parameter_list|,
name|int
name|_elfclass
parameter_list|,
name|int
name|_allocate
parameter_list|)
function_decl|;
name|unsigned
name|int
name|_libelf_falign
parameter_list|(
name|Elf_Type
name|_t
parameter_list|,
name|int
name|_elfclass
parameter_list|)
function_decl|;
name|size_t
name|_libelf_fsize
parameter_list|(
name|Elf_Type
name|_t
parameter_list|,
name|int
name|_elfclass
parameter_list|,
name|unsigned
name|int
name|_version
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
name|int
argument_list|(
argument|*_libelf_get_translator(Elf_Type _t, int _direction, int _elfclass)
argument_list|)
operator|(
name|unsigned
name|char
operator|*
name|_dst
operator|,
name|size_t
name|dsz
operator|,
name|unsigned
name|char
operator|*
name|_src
operator|,
name|size_t
name|_cnt
operator|,
name|int
name|_byteswap
operator|)
expr_stmt|;
name|void
modifier|*
name|_libelf_getphdr
parameter_list|(
name|Elf
modifier|*
name|_e
parameter_list|,
name|int
name|_elfclass
parameter_list|)
function_decl|;
name|void
modifier|*
name|_libelf_getshdr
parameter_list|(
name|Elf_Scn
modifier|*
name|_scn
parameter_list|,
name|int
name|_elfclass
parameter_list|)
function_decl|;
name|void
name|_libelf_init_elf
parameter_list|(
name|Elf
modifier|*
name|_e
parameter_list|,
name|Elf_Kind
name|_kind
parameter_list|)
function_decl|;
name|int
name|_libelf_load_section_headers
parameter_list|(
name|Elf
modifier|*
name|e
parameter_list|,
name|void
modifier|*
name|ehdr
parameter_list|)
function_decl|;
name|unsigned
name|int
name|_libelf_malign
parameter_list|(
name|Elf_Type
name|_t
parameter_list|,
name|int
name|_elfclass
parameter_list|)
function_decl|;
name|Elf
modifier|*
name|_libelf_memory
parameter_list|(
name|unsigned
name|char
modifier|*
name|_image
parameter_list|,
name|size_t
name|_sz
parameter_list|,
name|int
name|_reporterror
parameter_list|)
function_decl|;
name|size_t
name|_libelf_msize
parameter_list|(
name|Elf_Type
name|_t
parameter_list|,
name|int
name|_elfclass
parameter_list|,
name|unsigned
name|int
name|_version
parameter_list|)
function_decl|;
name|void
modifier|*
name|_libelf_newphdr
parameter_list|(
name|Elf
modifier|*
name|_e
parameter_list|,
name|int
name|_elfclass
parameter_list|,
name|size_t
name|_count
parameter_list|)
function_decl|;
name|Elf
modifier|*
name|_libelf_open_object
parameter_list|(
name|int
name|_fd
parameter_list|,
name|Elf_Cmd
name|_c
parameter_list|,
name|int
name|_reporterror
parameter_list|)
function_decl|;
name|struct
name|_Libelf_Data
modifier|*
name|_libelf_release_data
parameter_list|(
name|struct
name|_Libelf_Data
modifier|*
name|_d
parameter_list|)
function_decl|;
name|Elf
modifier|*
name|_libelf_release_elf
parameter_list|(
name|Elf
modifier|*
name|_e
parameter_list|)
function_decl|;
name|Elf_Scn
modifier|*
name|_libelf_release_scn
parameter_list|(
name|Elf_Scn
modifier|*
name|_s
parameter_list|)
function_decl|;
name|int
name|_libelf_setphnum
parameter_list|(
name|Elf
modifier|*
name|_e
parameter_list|,
name|void
modifier|*
name|_eh
parameter_list|,
name|int
name|_elfclass
parameter_list|,
name|size_t
name|_phnum
parameter_list|)
function_decl|;
name|int
name|_libelf_setshnum
parameter_list|(
name|Elf
modifier|*
name|_e
parameter_list|,
name|void
modifier|*
name|_eh
parameter_list|,
name|int
name|_elfclass
parameter_list|,
name|size_t
name|_shnum
parameter_list|)
function_decl|;
name|int
name|_libelf_setshstrndx
parameter_list|(
name|Elf
modifier|*
name|_e
parameter_list|,
name|void
modifier|*
name|_eh
parameter_list|,
name|int
name|_elfclass
parameter_list|,
name|size_t
name|_shstrndx
parameter_list|)
function_decl|;
name|Elf_Data
modifier|*
name|_libelf_xlate
parameter_list|(
name|Elf_Data
modifier|*
name|_d
parameter_list|,
specifier|const
name|Elf_Data
modifier|*
name|_s
parameter_list|,
name|unsigned
name|int
name|_encoding
parameter_list|,
name|int
name|_elfclass
parameter_list|,
name|int
name|_direction
parameter_list|)
function_decl|;
name|int
name|_libelf_xlate_shtype
parameter_list|(
name|uint32_t
name|_sht
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LIBELF_H_ */
end_comment

end_unit

