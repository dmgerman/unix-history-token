begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Kai Wang  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD: users/kaiwang27/elftc/libelftc.h 392 2009-05-31 19:17:46Z kaiwang27 $  * $Id: libelftc.h 2863 2013-01-06 03:18:32Z jkoshy $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBELFTC_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBELFTC_H_
end_define

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<libelf.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|_Elftc_Bfd_Target
name|Elftc_Bfd_Target
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_Elftc_String_Table
name|Elftc_String_Table
typedef|;
end_typedef

begin_comment
comment|/* Target types. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ETF_NONE
block|,
name|ETF_ELF
block|,
name|ETF_BINARY
block|,
name|ETF_SREC
block|,
name|ETF_IHEX
block|}
name|Elftc_Bfd_Target_Flavor
typedef|;
end_typedef

begin_comment
comment|/*  * Demangler flags.  */
end_comment

begin_comment
comment|/* Name mangling style. */
end_comment

begin_define
define|#
directive|define
name|ELFTC_DEM_UNKNOWN
value|0x00000000U
end_define

begin_comment
comment|/* Not specified. */
end_comment

begin_define
define|#
directive|define
name|ELFTC_DEM_ARM
value|0x00000001U
end_define

begin_comment
comment|/* C++ Ann. Ref. Manual. */
end_comment

begin_define
define|#
directive|define
name|ELFTC_DEM_GNU2
value|0x00000002U
end_define

begin_comment
comment|/* GNU version 2. */
end_comment

begin_define
define|#
directive|define
name|ELFTC_DEM_GNU3
value|0x00000004U
end_define

begin_comment
comment|/* GNU version 3. */
end_comment

begin_comment
comment|/* Demangling behaviour control. */
end_comment

begin_define
define|#
directive|define
name|ELFTC_DEM_NOPARAM
value|0x00010000U
end_define

begin_function_decl
name|__BEGIN_DECLS
name|Elftc_Bfd_Target
modifier|*
name|elftc_bfd_find_target
parameter_list|(
specifier|const
name|char
modifier|*
name|_tgt_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elftc_Bfd_Target_Flavor
name|elftc_bfd_target_flavor
parameter_list|(
name|Elftc_Bfd_Target
modifier|*
name|_tgt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|elftc_bfd_target_byteorder
parameter_list|(
name|Elftc_Bfd_Target
modifier|*
name|_tgt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|elftc_bfd_target_class
parameter_list|(
name|Elftc_Bfd_Target
modifier|*
name|_tgt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|elftc_bfd_target_machine
parameter_list|(
name|Elftc_Bfd_Target
modifier|*
name|_tgt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elftc_copyfile
parameter_list|(
name|int
name|_srcfd
parameter_list|,
name|int
name|_dstfd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elftc_demangle
parameter_list|(
specifier|const
name|char
modifier|*
name|_mangledname
parameter_list|,
name|char
modifier|*
name|_buffer
parameter_list|,
name|size_t
name|_bufsize
parameter_list|,
name|unsigned
name|int
name|_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elftc_set_timestamps
parameter_list|(
specifier|const
name|char
modifier|*
name|_filename
parameter_list|,
name|struct
name|stat
modifier|*
name|_sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elftc_String_Table
modifier|*
name|elftc_string_table_create
parameter_list|(
name|int
name|_hint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|elftc_string_table_destroy
parameter_list|(
name|Elftc_String_Table
modifier|*
name|_table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elftc_String_Table
modifier|*
name|elftc_string_table_from_section
parameter_list|(
name|Elf_Scn
modifier|*
name|_scn
parameter_list|,
name|int
name|_hint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|elftc_string_table_image
parameter_list|(
name|Elftc_String_Table
modifier|*
name|_table
parameter_list|,
name|size_t
modifier|*
name|_sz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|elftc_string_table_insert
parameter_list|(
name|Elftc_String_Table
modifier|*
name|_table
parameter_list|,
specifier|const
name|char
modifier|*
name|_string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|elftc_string_table_lookup
parameter_list|(
name|Elftc_String_Table
modifier|*
name|_table
parameter_list|,
specifier|const
name|char
modifier|*
name|_string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elftc_string_table_remove
parameter_list|(
name|Elftc_String_Table
modifier|*
name|_table
parameter_list|,
specifier|const
name|char
modifier|*
name|_string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|elftc_string_table_to_string
parameter_list|(
name|Elftc_String_Table
modifier|*
name|_table
parameter_list|,
name|size_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|elftc_version
parameter_list|(
name|void
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
comment|/* _LIBELFTC_H_ */
end_comment

end_unit

