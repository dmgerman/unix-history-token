begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2013 Kai Wang  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: elfcopy.h 3134 2014-12-23 10:43:59Z kaiwang27 $  */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<gelf.h>
end_include

begin_include
include|#
directive|include
file|<libelftc.h>
end_include

begin_include
include|#
directive|include
file|"_elftc.h"
end_include

begin_comment
comment|/*  * User specified symbol operation (strip, keep, localize, globalize,  * weaken, rename, etc).  */
end_comment

begin_struct
struct|struct
name|symop
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
name|newname
decl_stmt|;
define|#
directive|define
name|SYMOP_KEEP
value|0x0001U
define|#
directive|define
name|SYMOP_STRIP
value|0x0002U
define|#
directive|define
name|SYMOP_GLOBALIZE
value|0x0004U
define|#
directive|define
name|SYMOP_LOCALIZE
value|0x0008U
define|#
directive|define
name|SYMOP_KEEPG
value|0x0010U
define|#
directive|define
name|SYMOP_WEAKEN
value|0x0020U
define|#
directive|define
name|SYMOP_REDEF
value|0x0040U
name|unsigned
name|int
name|op
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|symop
argument_list|)
name|symop_list
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* File containing symbol list. */
end_comment

begin_struct
struct|struct
name|symfile
block|{
name|dev_t
name|dev
decl_stmt|;
name|ino_t
name|ino
decl_stmt|;
name|size_t
name|size
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
name|unsigned
name|int
name|op
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|symfile
argument_list|)
name|symfile_list
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Sections to copy/remove/rename/... */
end_comment

begin_struct
struct|struct
name|sec_action
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
name|addopt
decl_stmt|;
specifier|const
name|char
modifier|*
name|newname
decl_stmt|;
specifier|const
name|char
modifier|*
name|string
decl_stmt|;
name|uint64_t
name|lma
decl_stmt|;
name|uint64_t
name|vma
decl_stmt|;
name|int64_t
name|lma_adjust
decl_stmt|;
name|int64_t
name|vma_adjust
decl_stmt|;
define|#
directive|define
name|SF_ALLOC
value|0x0001U
define|#
directive|define
name|SF_LOAD
value|0x0002U
define|#
directive|define
name|SF_NOLOAD
value|0x0004U
define|#
directive|define
name|SF_READONLY
value|0x0008U
define|#
directive|define
name|SF_DEBUG
value|0x0010U
define|#
directive|define
name|SF_CODE
value|0x0020U
define|#
directive|define
name|SF_DATA
value|0x0040U
define|#
directive|define
name|SF_ROM
value|0x0080U
define|#
directive|define
name|SF_SHARED
value|0X0100U
define|#
directive|define
name|SF_CONTENTS
value|0x0200U
name|int
name|flags
decl_stmt|;
name|int
name|add
decl_stmt|;
name|int
name|append
decl_stmt|;
name|int
name|compress
decl_stmt|;
name|int
name|copy
decl_stmt|;
name|int
name|print
decl_stmt|;
name|int
name|remove
decl_stmt|;
name|int
name|rename
decl_stmt|;
name|int
name|setflags
decl_stmt|;
name|int
name|setlma
decl_stmt|;
name|int
name|setvma
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|sec_action
argument_list|)
name|sac_list
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Sections to add from file. */
end_comment

begin_struct
struct|struct
name|sec_add
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|content
decl_stmt|;
name|size_t
name|size
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|sec_add
argument_list|)
name|sadd_list
expr_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|segment
struct_decl|;
end_struct_decl

begin_comment
comment|/* Internal data structure for sections. */
end_comment

begin_struct
struct|struct
name|section
block|{
name|struct
name|segment
modifier|*
name|seg
decl_stmt|;
comment|/* containing segment */
name|struct
name|segment
modifier|*
name|seg_tls
decl_stmt|;
comment|/* tls segment */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* section name */
name|char
modifier|*
name|newname
decl_stmt|;
comment|/* new section name */
name|Elf_Scn
modifier|*
name|is
decl_stmt|;
comment|/* input scn */
name|Elf_Scn
modifier|*
name|os
decl_stmt|;
comment|/* output scn */
name|void
modifier|*
name|buf
decl_stmt|;
comment|/* section content */
name|uint8_t
modifier|*
name|pad
decl_stmt|;
comment|/* section padding */
name|uint64_t
name|off
decl_stmt|;
comment|/* section offset */
name|uint64_t
name|sz
decl_stmt|;
comment|/* section size */
name|uint64_t
name|cap
decl_stmt|;
comment|/* section capacity */
name|uint64_t
name|align
decl_stmt|;
comment|/* section alignment */
name|uint64_t
name|type
decl_stmt|;
comment|/* section type */
name|uint64_t
name|vma
decl_stmt|;
comment|/* section virtual addr */
name|uint64_t
name|lma
decl_stmt|;
comment|/* section load addr */
name|uint64_t
name|pad_sz
decl_stmt|;
comment|/* section padding size */
name|int
name|loadable
decl_stmt|;
comment|/* whether loadable */
name|int
name|pseudo
decl_stmt|;
name|int
name|nocopy
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|section
argument_list|)
name|sec_list
expr_stmt|;
comment|/* next section */
block|}
struct|;
end_struct

begin_comment
comment|/* Internal data structure for segments. */
end_comment

begin_struct
struct|struct
name|segment
block|{
name|uint64_t
name|addr
decl_stmt|;
comment|/* load addr */
name|uint64_t
name|off
decl_stmt|;
comment|/* file offset */
name|uint64_t
name|fsz
decl_stmt|;
comment|/* file size */
name|uint64_t
name|msz
decl_stmt|;
comment|/* memory size */
name|uint64_t
name|type
decl_stmt|;
comment|/* segment type */
name|int
name|remove
decl_stmt|;
comment|/* whether remove */
name|int
name|nsec
decl_stmt|;
comment|/* number of sections contained */
name|struct
name|section
modifier|*
modifier|*
name|v_sec
decl_stmt|;
comment|/* list of sections contained */
name|STAILQ_ENTRY
argument_list|(
argument|segment
argument_list|)
name|seg_list
expr_stmt|;
comment|/* next segment */
block|}
struct|;
end_struct

begin_comment
comment|/*  * In-memory representation of ar(1) archive member(object).  */
end_comment

begin_struct
struct|struct
name|ar_obj
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* member name */
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* member content */
name|void
modifier|*
name|maddr
decl_stmt|;
comment|/* mmap start address */
name|uid_t
name|uid
decl_stmt|;
comment|/* user id */
name|gid_t
name|gid
decl_stmt|;
comment|/* group id */
name|mode_t
name|md
decl_stmt|;
comment|/* octal file permissions */
name|size_t
name|size
decl_stmt|;
comment|/* member size */
name|time_t
name|mtime
decl_stmt|;
comment|/* modification time */
name|STAILQ_ENTRY
argument_list|(
argument|ar_obj
argument_list|)
name|objs
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure encapsulates the "global" data for "elfcopy" program.  */
end_comment

begin_struct
struct|struct
name|elfcopy
block|{
specifier|const
name|char
modifier|*
name|progname
decl_stmt|;
comment|/* program name */
name|int
name|iec
decl_stmt|;
comment|/* elfclass of input object */
name|Elftc_Bfd_Target_Flavor
name|itf
decl_stmt|;
comment|/* flavour of input object */
name|Elftc_Bfd_Target_Flavor
name|otf
decl_stmt|;
comment|/* flavour of output object */
specifier|const
name|char
modifier|*
name|otgt
decl_stmt|;
comment|/* output target name */
name|int
name|oec
decl_stmt|;
comment|/* elfclass of output object */
name|unsigned
name|char
name|oed
decl_stmt|;
comment|/* endianess of output object */
name|int
name|oem
decl_stmt|;
comment|/* EM_XXX of output object */
name|int
name|abi
decl_stmt|;
comment|/* OSABI of output object */
name|Elf
modifier|*
name|ein
decl_stmt|;
comment|/* ELF descriptor of input object */
name|Elf
modifier|*
name|eout
decl_stmt|;
comment|/* ELF descriptor of output object */
name|int
name|iphnum
decl_stmt|;
comment|/* num. of input object phdr entries */
name|int
name|ophnum
decl_stmt|;
comment|/* num. of output object phdr entries */
name|int
name|nos
decl_stmt|;
comment|/* num. of output object sections */
enum|enum
block|{
name|STRIP_NONE
init|=
literal|0
block|,
name|STRIP_ALL
block|,
name|STRIP_DEBUG
block|,
name|STRIP_NONDEBUG
block|,
name|STRIP_UNNEEDED
block|}
name|strip
enum|;
define|#
directive|define
name|EXECUTABLE
value|0x00000001U
define|#
directive|define
name|DYNAMIC
value|0x00000002U
define|#
directive|define
name|RELOCATABLE
value|0x00000004U
define|#
directive|define
name|SYMTAB_EXIST
value|0x00000010U
define|#
directive|define
name|SYMTAB_INTACT
value|0x00000020U
define|#
directive|define
name|KEEP_GLOBAL
value|0x00000040U
define|#
directive|define
name|DISCARD_LOCAL
value|0x00000080U
define|#
directive|define
name|WEAKEN_ALL
value|0x00000100U
define|#
directive|define
name|PRESERVE_DATE
value|0x00001000U
define|#
directive|define
name|SREC_FORCE_S3
value|0x00002000U
define|#
directive|define
name|SREC_FORCE_LEN
value|0x00004000U
define|#
directive|define
name|SET_START
value|0x00008000U
define|#
directive|define
name|GAP_FILL
value|0x00010000U
define|#
directive|define
name|WILDCARD
value|0x00020000U
define|#
directive|define
name|NO_CHANGE_WARN
value|0x00040000U
define|#
directive|define
name|SEC_ADD
value|0x00080000U
define|#
directive|define
name|SEC_APPEND
value|0x00100000U
define|#
directive|define
name|SEC_COMPRESS
value|0x00200000U
define|#
directive|define
name|SEC_PRINT
value|0x00400000U
define|#
directive|define
name|SEC_REMOVE
value|0x00800000U
define|#
directive|define
name|SEC_COPY
value|0x01000000U
define|#
directive|define
name|DISCARD_LLABEL
value|0x02000000U
name|int
name|flags
decl_stmt|;
comment|/* elfcopy run control flags. */
name|int64_t
name|change_addr
decl_stmt|;
comment|/* Section address adjustment. */
name|int64_t
name|change_start
decl_stmt|;
comment|/* Entry point adjustment. */
name|uint64_t
name|set_start
decl_stmt|;
comment|/* Entry point value. */
name|unsigned
name|long
name|srec_len
decl_stmt|;
comment|/* S-Record length. */
name|uint64_t
name|pad_to
decl_stmt|;
comment|/* load address padding. */
name|uint8_t
name|fill
decl_stmt|;
comment|/* gap fill value. */
name|char
modifier|*
name|prefix_sec
decl_stmt|;
comment|/* section prefix. */
name|char
modifier|*
name|prefix_alloc
decl_stmt|;
comment|/* alloc section prefix. */
name|char
modifier|*
name|prefix_sym
decl_stmt|;
comment|/* symbol prefix. */
name|char
modifier|*
name|debuglink
decl_stmt|;
comment|/* GNU debuglink file. */
name|struct
name|section
modifier|*
name|symtab
decl_stmt|;
comment|/* .symtab section. */
name|struct
name|section
modifier|*
name|strtab
decl_stmt|;
comment|/* .strtab section. */
name|struct
name|section
modifier|*
name|shstrtab
decl_stmt|;
comment|/* .shstrtab section. */
name|uint64_t
modifier|*
name|secndx
decl_stmt|;
comment|/* section index map. */
name|uint64_t
modifier|*
name|symndx
decl_stmt|;
comment|/* symbol index map. */
name|unsigned
name|char
modifier|*
name|v_rel
decl_stmt|;
comment|/* symbols needed by relocation. */
name|unsigned
name|char
modifier|*
name|v_secsym
decl_stmt|;
comment|/* sections with section symbol. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|segment
argument_list|)
name|v_seg
expr_stmt|;
comment|/* list of segments. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|sec_action
argument_list|)
name|v_sac
expr_stmt|;
comment|/* list of section operations. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|sec_add
argument_list|)
name|v_sadd
expr_stmt|;
comment|/* list of sections to add. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|symop
argument_list|)
name|v_symop
expr_stmt|;
comment|/* list of symbols operations. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|symfile
argument_list|)
name|v_symfile
expr_stmt|;
comment|/* list of symlist files. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|section
argument_list|)
name|v_sec
expr_stmt|;
comment|/* list of sections. */
comment|/* 	 * Fields for the ar(1) archive. 	 */
name|char
modifier|*
name|as
decl_stmt|;
comment|/* buffer for archive string table. */
name|size_t
name|as_sz
decl_stmt|;
comment|/* current size of as table. */
name|size_t
name|as_cap
decl_stmt|;
comment|/* capacity of as table buffer. */
name|uint32_t
name|s_cnt
decl_stmt|;
comment|/* current number of symbols. */
name|uint32_t
modifier|*
name|s_so
decl_stmt|;
comment|/* symbol offset table. */
name|size_t
name|s_so_cap
decl_stmt|;
comment|/* capacity of so table buffer. */
name|char
modifier|*
name|s_sn
decl_stmt|;
comment|/* symbol name table */
name|size_t
name|s_sn_cap
decl_stmt|;
comment|/* capacity of sn table buffer. */
name|size_t
name|s_sn_sz
decl_stmt|;
comment|/* current size of sn table. */
name|off_t
name|rela_off
decl_stmt|;
comment|/* offset relative to pseudo members. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|ar_obj
argument_list|)
name|v_arobj
expr_stmt|;
comment|/* archive object(member) list. */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|add_section
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
specifier|const
name|char
modifier|*
name|_optarg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_to_shstrtab
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
specifier|const
name|char
modifier|*
name|_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_to_symop_list
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
specifier|const
name|char
modifier|*
name|_name
parameter_list|,
specifier|const
name|char
modifier|*
name|_newname
parameter_list|,
name|unsigned
name|int
name|_op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_to_symtab
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
specifier|const
name|char
modifier|*
name|_name
parameter_list|,
name|uint64_t
name|_st_value
parameter_list|,
name|uint64_t
name|_st_size
parameter_list|,
name|uint16_t
name|_st_shndx
parameter_list|,
name|unsigned
name|char
name|_st_info
parameter_list|,
name|unsigned
name|char
name|_st_other
parameter_list|,
name|int
name|_ndx_known
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|add_to_inseg_list
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
name|struct
name|section
modifier|*
name|_sec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adjust_addr
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|copy_content
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|copy_data
parameter_list|(
name|struct
name|section
modifier|*
name|_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|copy_phdr
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|copy_shdr
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
name|struct
name|section
modifier|*
name|_s
parameter_list|,
specifier|const
name|char
modifier|*
name|_name
parameter_list|,
name|int
name|_copy
parameter_list|,
name|int
name|_sec_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|create_binary
parameter_list|(
name|int
name|_ifd
parameter_list|,
name|int
name|_ofd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|create_elf
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|create_elf_from_binary
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
name|int
name|_ifd
parameter_list|,
specifier|const
name|char
modifier|*
name|ifn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|create_elf_from_ihex
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
name|int
name|_ifd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|create_elf_from_srec
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
name|int
name|_ifd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|section
modifier|*
name|create_external_section
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
specifier|const
name|char
modifier|*
name|_name
parameter_list|,
name|char
modifier|*
name|_newname
parameter_list|,
name|void
modifier|*
name|_buf
parameter_list|,
name|uint64_t
name|_size
parameter_list|,
name|uint64_t
name|_off
parameter_list|,
name|uint64_t
name|_stype
parameter_list|,
name|Elf_Type
name|_dtype
parameter_list|,
name|uint64_t
name|flags
parameter_list|,
name|uint64_t
name|_align
parameter_list|,
name|uint64_t
name|_vma
parameter_list|,
name|int
name|_loadable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|create_external_symtab
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|create_ihex
parameter_list|(
name|int
name|_ifd
parameter_list|,
name|int
name|_ofd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|create_scn
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|create_srec
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
name|int
name|_ifd
parameter_list|,
name|int
name|_ofd
parameter_list|,
specifier|const
name|char
modifier|*
name|_ofn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|create_symtab
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|create_symtab_data
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|create_tempfile
parameter_list|(
name|char
modifier|*
modifier|*
name|_fn
parameter_list|,
name|int
modifier|*
name|_fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finalize_external_symtab
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_elf
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_sec_act
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_sec_add
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_symtab
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_shstrtab
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|insert_to_sec_list
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
name|struct
name|section
modifier|*
name|_sec
parameter_list|,
name|int
name|_tail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|section
modifier|*
name|insert_shtab
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
name|int
name|tail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_remove_reloc_sec
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
name|uint32_t
name|_sh_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_remove_section
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
specifier|const
name|char
modifier|*
name|_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sec_action
modifier|*
name|lookup_sec_act
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
specifier|const
name|char
modifier|*
name|_name
parameter_list|,
name|int
name|_add
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|symop
modifier|*
name|lookup_symop_list
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
specifier|const
name|char
modifier|*
name|_name
parameter_list|,
name|unsigned
name|int
name|_op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|resync_sections
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_shstrtab
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setup_phdr
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|update_shdr
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
name|int
name|_update_link
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|LIBELF_AR
end_ifndef

begin_function_decl
name|int
name|ac_detect_ar
parameter_list|(
name|int
name|_ifd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ac_create_ar
parameter_list|(
name|struct
name|elfcopy
modifier|*
name|_ecp
parameter_list|,
name|int
name|_ifd
parameter_list|,
name|int
name|_ofd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LIBELF_AR */
end_comment

end_unit

