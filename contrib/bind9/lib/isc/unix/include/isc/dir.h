begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: dir.h,v 1.15.12.3 2004/03/08 09:04:57 marka Exp $ */
end_comment

begin_comment
comment|/* Principal Authors: DCL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_DIR_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_DIR_H
value|1
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Required on some systems. */
end_comment

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_define
define|#
directive|define
name|ISC_DIR_NAMEMAX
value|256
end_define

begin_define
define|#
directive|define
name|ISC_DIR_PATHMAX
value|1024
end_define

begin_typedef
typedef|typedef
struct|struct
name|isc_direntry
block|{
comment|/* 	 * Ideally, this should be NAME_MAX, but AIX does not define it by 	 * default and dynamically allocating the space based on pathconf() 	 * complicates things undesirably, as does adding special conditionals 	 * just for AIX.  So a comfortably sized buffer is chosen instead. 	 */
name|char
name|name
index|[
name|ISC_DIR_NAMEMAX
index|]
decl_stmt|;
name|unsigned
name|int
name|length
decl_stmt|;
block|}
name|isc_direntry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|isc_dir
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
comment|/* 	 * As with isc_direntry_t->name, making this "right" for all systems 	 * is slightly problematic because AIX does not define PATH_MAX. 	 */
name|char
name|dirname
index|[
name|ISC_DIR_PATHMAX
index|]
decl_stmt|;
name|isc_direntry_t
name|entry
decl_stmt|;
name|DIR
modifier|*
name|handle
decl_stmt|;
block|}
name|isc_dir_t
typedef|;
end_typedef

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|void
name|isc_dir_init
parameter_list|(
name|isc_dir_t
modifier|*
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_dir_open
parameter_list|(
name|isc_dir_t
modifier|*
name|dir
parameter_list|,
specifier|const
name|char
modifier|*
name|dirname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_dir_read
parameter_list|(
name|isc_dir_t
modifier|*
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_dir_reset
parameter_list|(
name|isc_dir_t
modifier|*
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_dir_close
parameter_list|(
name|isc_dir_t
modifier|*
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_dir_chdir
parameter_list|(
specifier|const
name|char
modifier|*
name|dirname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_dir_chroot
parameter_list|(
specifier|const
name|char
modifier|*
name|dirname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_dir_createunique
parameter_list|(
name|char
modifier|*
name|templet
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Use a templet (such as from isc_file_mktemplate()) to create a uniquely  * named, empty directory.  The templet string is modified in place.  * If result == ISC_R_SUCCESS, it is the name of the directory that was  * created.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_DIR_H */
end_comment

end_unit

