begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: ftw.h,v 1.1 2003/07/21 21:13:18 millert Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2003 Todd C. Miller<Todd.Miller@courtesan.com>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Sponsored in part by the Defense Advanced Research Projects  * Agency (DARPA) and Air Force Research Laboratory, Air Force  * Materiel Command, USAF, under agreement number F39502-99-1-0512.  *  * $FreeBSD$  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_comment
comment|/*  * Valid flags for the 3rd argument to the function that is passed as the  * second argument to ftw(3) and nftw(3).  Say it three times fast!  */
end_comment

begin_define
define|#
directive|define
name|FTW_F
value|0
end_define

begin_comment
comment|/* File.  */
end_comment

begin_define
define|#
directive|define
name|FTW_D
value|1
end_define

begin_comment
comment|/* Directory.  */
end_comment

begin_define
define|#
directive|define
name|FTW_DNR
value|2
end_define

begin_comment
comment|/* Directory without read permission.  */
end_comment

begin_define
define|#
directive|define
name|FTW_DP
value|3
end_define

begin_comment
comment|/* Directory with subdirectories visited.  */
end_comment

begin_define
define|#
directive|define
name|FTW_NS
value|4
end_define

begin_comment
comment|/* Unknown type; stat() failed.  */
end_comment

begin_define
define|#
directive|define
name|FTW_SL
value|5
end_define

begin_comment
comment|/* Symbolic link.  */
end_comment

begin_define
define|#
directive|define
name|FTW_SLN
value|6
end_define

begin_comment
comment|/* Sym link that names a nonexistent file.  */
end_comment

begin_comment
comment|/*  * Flags for use as the 4th argument to nftw(3).  These may be ORed together.  */
end_comment

begin_define
define|#
directive|define
name|FTW_PHYS
value|0x01
end_define

begin_comment
comment|/* Physical walk, don't follow sym links.  */
end_comment

begin_define
define|#
directive|define
name|FTW_MOUNT
value|0x02
end_define

begin_comment
comment|/* The walk does not cross a mount point.  */
end_comment

begin_define
define|#
directive|define
name|FTW_DEPTH
value|0x04
end_define

begin_comment
comment|/* Subdirs visited before the dir itself. */
end_comment

begin_define
define|#
directive|define
name|FTW_CHDIR
value|0x08
end_define

begin_comment
comment|/* Change to a directory before reading it. */
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

begin_function_decl
name|__BEGIN_DECLS
name|int
name|ftw
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|stat
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nftw
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|stat
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|FTW
modifier|*
parameter_list|)
parameter_list|,
name|int
parameter_list|,
name|int
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
comment|/* !_FTW_H */
end_comment

end_unit

