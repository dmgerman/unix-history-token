begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 2009 Gabor Kovesdan<gabor@FreeBSD.org>  * Copyright (C) 2012 Oleg Moskalenko<mom040267@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__SORT_FILE_H__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__SORT_FILE_H__
end_define

begin_include
include|#
directive|include
file|"coll.h"
end_include

begin_include
include|#
directive|include
file|"sort.h"
end_include

begin_define
define|#
directive|define
name|SORT_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|SORT_QSORT
value|1
end_define

begin_define
define|#
directive|define
name|SORT_MERGESORT
value|2
end_define

begin_define
define|#
directive|define
name|SORT_HEAPSORT
value|3
end_define

begin_define
define|#
directive|define
name|SORT_RADIXSORT
value|4
end_define

begin_define
define|#
directive|define
name|DEFAULT_SORT_ALGORITHM
value|SORT_HEAPSORT
end_define

begin_define
define|#
directive|define
name|DEFAULT_SORT_FUNC
value|heapsort
end_define

begin_comment
comment|/*  * List of data to be sorted.  */
end_comment

begin_struct
struct|struct
name|sort_list
block|{
name|struct
name|sort_list_item
modifier|*
modifier|*
name|list
decl_stmt|;
name|unsigned
name|long
name|long
name|memsize
decl_stmt|;
name|size_t
name|count
decl_stmt|;
name|size_t
name|size
decl_stmt|;
name|size_t
name|sub_list_pos
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * File reader object   */
end_comment

begin_struct_decl
struct_decl|struct
name|file_reader
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * List of files to be sorted  */
end_comment

begin_struct
struct|struct
name|file_list
block|{
name|char
modifier|*
modifier|*
name|fns
decl_stmt|;
name|size_t
name|count
decl_stmt|;
name|size_t
name|sz
decl_stmt|;
name|bool
name|tmp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure for zero-separated file reading (for input files list)  */
end_comment

begin_struct
struct|struct
name|file0_reader
block|{
name|char
modifier|*
name|current_line
decl_stmt|;
name|FILE
modifier|*
name|f
decl_stmt|;
name|size_t
name|current_sz
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* memory */
end_comment

begin_comment
comment|/**/
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|long
name|free_memory
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|long
name|available_free_memory
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we using mmap ? */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|use_mmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temporary file dir */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|tmpdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Max number of simultaneously open files (including the output file).  */
end_comment

begin_decl_stmt
specifier|extern
name|size_t
name|max_open_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Compress program  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|compress_program
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* funcs */
end_comment

begin_function_decl
name|struct
name|file_reader
modifier|*
name|file_reader_init
parameter_list|(
specifier|const
name|char
modifier|*
name|fsrc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bwstring
modifier|*
name|file_reader_readline
parameter_list|(
name|struct
name|file_reader
modifier|*
name|fr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|file_reader_free
parameter_list|(
name|struct
name|file_reader
modifier|*
name|fr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|read_file0_line
parameter_list|(
name|struct
name|file0_reader
modifier|*
name|f0r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_tmp_files
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clear_tmp_files
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|new_tmp_file_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tmp_file_atexit
parameter_list|(
specifier|const
name|char
modifier|*
name|tmp_file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|file_list_init
parameter_list|(
name|struct
name|file_list
modifier|*
name|fl
parameter_list|,
name|bool
name|tmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|file_list_add
parameter_list|(
name|struct
name|file_list
modifier|*
name|fl
parameter_list|,
name|char
modifier|*
name|fn
parameter_list|,
name|bool
name|allocate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|file_list_populate
parameter_list|(
name|struct
name|file_list
modifier|*
name|fl
parameter_list|,
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|bool
name|allocate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|file_list_clean
parameter_list|(
name|struct
name|file_list
modifier|*
name|fl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|check
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|merge_files
parameter_list|(
name|struct
name|file_list
modifier|*
name|fl
parameter_list|,
specifier|const
name|char
modifier|*
name|fn_out
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|openfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closefile
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfile
parameter_list|(
specifier|const
name|char
modifier|*
name|fn
parameter_list|,
name|struct
name|sort_list
modifier|*
name|list
parameter_list|,
name|struct
name|file_list
modifier|*
name|fl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sort_list_init
parameter_list|(
name|struct
name|sort_list
modifier|*
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sort_list_add
parameter_list|(
name|struct
name|sort_list
modifier|*
name|l
parameter_list|,
name|struct
name|bwstring
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sort_list_clean
parameter_list|(
name|struct
name|sort_list
modifier|*
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sort_list_dump
parameter_list|(
name|struct
name|sort_list
modifier|*
name|l
parameter_list|,
specifier|const
name|char
modifier|*
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sort_list_to_file
parameter_list|(
name|struct
name|sort_list
modifier|*
name|list
parameter_list|,
specifier|const
name|char
modifier|*
name|outfile
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SORT_FILE_H__ */
end_comment

end_unit

