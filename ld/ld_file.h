begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2013 Kai Wang  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ld_file.h 2930 2013-03-17 22:54:26Z kaiwang27 $  */
end_comment

begin_enum
enum|enum
name|ld_file_type
block|{
name|LFT_UNKNOWN
block|,
name|LFT_RELOCATABLE
block|,
name|LFT_DSO
block|,
name|LFT_ARCHIVE
block|,
name|LFT_BINARY
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ld_archive_member
block|{
name|char
modifier|*
name|lam_ar_name
decl_stmt|;
comment|/* archive name */
name|char
modifier|*
name|lam_name
decl_stmt|;
comment|/* archive member name */
name|off_t
name|lam_off
decl_stmt|;
comment|/* archive member offset */
name|struct
name|ld_input
modifier|*
name|lam_input
decl_stmt|;
comment|/* input object */
name|UT_hash_handle
name|hh
decl_stmt|;
comment|/* hash handle */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ld_archive
block|{
name|struct
name|ld_archive_member
modifier|*
name|la_m
decl_stmt|;
comment|/* extracted member list. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ld_file
block|{
name|char
modifier|*
name|lf_name
decl_stmt|;
comment|/* input file name */
name|enum
name|ld_file_type
name|lf_type
decl_stmt|;
comment|/* input file type */
name|void
modifier|*
name|lf_mmap
decl_stmt|;
comment|/* input file image */
name|size_t
name|lf_size
decl_stmt|;
comment|/* input file size */
name|Elf
modifier|*
name|lf_elf
decl_stmt|;
comment|/* input file ELF descriptor */
name|struct
name|ld_archive
modifier|*
name|lf_ar
decl_stmt|;
comment|/* input archive */
name|struct
name|ld_input
modifier|*
name|lf_input
decl_stmt|;
comment|/* input object */
name|unsigned
name|lf_whole_archive
decl_stmt|;
comment|/* include whole archive */
name|unsigned
name|lf_as_needed
decl_stmt|;
comment|/* DT_NEEDED */
name|unsigned
name|lf_group_level
decl_stmt|;
comment|/* archive group level */
name|unsigned
name|lf_search_dir
decl_stmt|;
comment|/* search library directories */
name|TAILQ_ENTRY
argument_list|(
argument|ld_file
argument_list|)
name|lf_next
expr_stmt|;
comment|/* next input file */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ld_file_add
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|enum
name|ld_file_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_file_add_first
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|enum
name|ld_file_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_file_add_after
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|enum
name|ld_file_type
parameter_list|,
name|struct
name|ld_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_file_cleanup
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_file_load
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_file_unload
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
name|struct
name|ld_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

