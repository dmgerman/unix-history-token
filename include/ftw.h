begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003 by Joel Baker.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the Author nor the names of any contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FTW_H
end_ifndef

begin_define
define|#
directive|define
name|_FTW_H
end_define

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
comment|/* Enumerated values for 'flag' when calling [n]ftw */
name|enum
type|{
name|FTW_D
decl_stmt|,
comment|/* Directories */
name|FTW_DNR
decl_stmt|,
comment|/* Unreadable directory */
name|FTW_F
decl_stmt|,
comment|/* Regular files */
name|FTW_SL
decl_stmt|,
comment|/* Symbolic link */
name|FTW_NS
decl_stmt|,
comment|/* stat(2) failed */
if|#
directive|if
name|__XSI_VISIBLE
comment|/* X/Open */
comment|/* Flags for nftw only */
name|FTW_DP
decl_stmt|,
comment|/* Directory, subdirs visited */
name|FTW_SLN
decl_stmt|,
end_decl_stmt

begin_comment
comment|/* Dangling symlink */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XSI_VISIBLE */
end_comment

begin_if
unit|};
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_comment
comment|/* X/Open */
end_comment

begin_comment
comment|/* Enumerated values for 'flags' when calling nftw */
end_comment

begin_enum
enum|enum
block|{
name|FTW_CHDIR
init|=
literal|1
block|,
comment|/* Do a chdir(2) when entering a directory */
name|FTW_DEPTH
init|=
literal|2
block|,
comment|/* Report files first (before directory) */
name|FTW_MOUNT
init|=
literal|4
block|,
comment|/* Single filesystem */
name|FTW_PHYS
init|=
literal|8
comment|/* Physical walk; ignore symlinks */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|FTW_PHYS
value|FTW_PHYS
end_define

begin_define
define|#
directive|define
name|FTW_MOUNT
value|FTW_MOUNT
end_define

begin_define
define|#
directive|define
name|FTW_CHDIR
value|FTW_CHDIR
end_define

begin_define
define|#
directive|define
name|FTW_DEPTH
value|FTW_DEPTH
end_define

begin_comment
comment|/* FTW struct for callbacks from nftw */
end_comment

begin_struct
struct|struct
name|FTW
block|{
name|int
name|base
decl_stmt|;
name|int
name|level
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XSI_VISIBLE */
end_comment

begin_comment
comment|/* Typecasts for callback functions */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|__ftw_func_t
function_decl|) \
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
specifier|const
name|struct
name|stat
modifier|*
name|status
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* ftw: walk a directory tree, calling a function for each element */
end_comment

begin_function_decl
specifier|extern
name|int
name|ftw
parameter_list|(
specifier|const
name|char
modifier|*
name|dir
parameter_list|,
name|__ftw_func_t
name|func
parameter_list|,
name|int
name|descr
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_comment
comment|/* X/Open */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|__nftw_func_t
function_decl|) \
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
specifier|const
name|struct
name|stat
modifier|*
name|status
parameter_list|,
name|int
name|flag
parameter_list|,
name|struct
name|FTW
modifier|*
name|detail
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* nftw: walk a directory tree, calling a function for each element; much  * like ftw, but with behavior flags and minty freshness.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|nftw
parameter_list|(
specifier|const
name|char
modifier|*
name|dir
parameter_list|,
name|__nftw_func_t
name|func
parameter_list|,
name|int
name|descr
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XSI_VISIBLE */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FTW_H */
end_comment

end_unit

