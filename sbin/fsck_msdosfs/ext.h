begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997 Wolfgang Solfrank  * Copyright (c) 1995 Martin Husemann  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Martin Husemann  *	and Wolfgang Solfrank.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *	$NetBSD: ext.h,v 1.6 2000/04/25 23:02:51 jdolecek Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXT_H
end_ifndef

begin_define
define|#
directive|define
name|EXT_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"dosfs.h"
end_include

begin_define
define|#
directive|define
name|LOSTDIR
value|"LOST.DIR"
end_define

begin_comment
comment|/*  * Options:  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|alwaysno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* assume "no" for all questions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|alwaysyes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* assume "yes" for all questions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|preen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* we are preening */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rdonly
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* device is opened read only (supersedes above) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* filesystem currently checked */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|dosDirEntry
modifier|*
name|rootDir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * function declarations  */
end_comment

begin_function_decl
name|int
name|ask
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Check filesystem given as arg  */
end_comment

begin_function_decl
name|int
name|checkfilesys
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return values of various functions  */
end_comment

begin_define
define|#
directive|define
name|FSOK
value|0
end_define

begin_comment
comment|/* Check was OK */
end_comment

begin_define
define|#
directive|define
name|FSBOOTMOD
value|1
end_define

begin_comment
comment|/* Boot block was modified */
end_comment

begin_define
define|#
directive|define
name|FSDIRMOD
value|2
end_define

begin_comment
comment|/* Some directory was modified */
end_comment

begin_define
define|#
directive|define
name|FSFATMOD
value|4
end_define

begin_comment
comment|/* The FAT was modified */
end_comment

begin_define
define|#
directive|define
name|FSERROR
value|8
end_define

begin_comment
comment|/* Some unrecovered error remains */
end_comment

begin_define
define|#
directive|define
name|FSFATAL
value|16
end_define

begin_comment
comment|/* Some unrecoverable error occured */
end_comment

begin_define
define|#
directive|define
name|FSDIRTY
value|32
end_define

begin_comment
comment|/* File system is dirty */
end_comment

begin_define
define|#
directive|define
name|FSFIXFAT
value|64
end_define

begin_comment
comment|/* Fix file system FAT */
end_comment

begin_comment
comment|/*  * read a boot block in a machine independend fashion and translate  * it into our struct bootblock.  */
end_comment

begin_function_decl
name|int
name|readboot
parameter_list|(
name|int
parameter_list|,
name|struct
name|bootblock
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Correct the FSInfo block.  */
end_comment

begin_function_decl
name|int
name|writefsinfo
parameter_list|(
name|int
parameter_list|,
name|struct
name|bootblock
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Read one of the FAT copies and return a pointer to the new  * allocated array holding our description of it.  */
end_comment

begin_function_decl
name|int
name|readfat
parameter_list|(
name|int
parameter_list|,
name|struct
name|bootblock
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|fatEntry
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Check two FAT copies for consistency and merge changes into the  * first if neccessary.  */
end_comment

begin_function_decl
name|int
name|comparefat
parameter_list|(
name|struct
name|bootblock
modifier|*
parameter_list|,
name|struct
name|fatEntry
modifier|*
parameter_list|,
name|struct
name|fatEntry
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Check a FAT  */
end_comment

begin_function_decl
name|int
name|checkfat
parameter_list|(
name|struct
name|bootblock
modifier|*
parameter_list|,
name|struct
name|fatEntry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Write back FAT entries  */
end_comment

begin_function_decl
name|int
name|writefat
parameter_list|(
name|int
parameter_list|,
name|struct
name|bootblock
modifier|*
parameter_list|,
name|struct
name|fatEntry
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Read a directory  */
end_comment

begin_function_decl
name|int
name|resetDosDirSection
parameter_list|(
name|struct
name|bootblock
modifier|*
parameter_list|,
name|struct
name|fatEntry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finishDosDirSection
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|handleDirTree
parameter_list|(
name|int
parameter_list|,
name|struct
name|bootblock
modifier|*
parameter_list|,
name|struct
name|fatEntry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Cross-check routines run after everything is completely in memory  */
end_comment

begin_comment
comment|/*  * Check for lost cluster chains  */
end_comment

begin_function_decl
name|int
name|checklost
parameter_list|(
name|int
parameter_list|,
name|struct
name|bootblock
modifier|*
parameter_list|,
name|struct
name|fatEntry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Try to reconnect a lost cluster chain  */
end_comment

begin_function_decl
name|int
name|reconnect
parameter_list|(
name|int
parameter_list|,
name|struct
name|bootblock
modifier|*
parameter_list|,
name|struct
name|fatEntry
modifier|*
parameter_list|,
name|cl_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finishlf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Small helper functions  */
end_comment

begin_comment
comment|/*  * Return the type of a reserved cluster as text  */
end_comment

begin_function_decl
name|char
modifier|*
name|rsrvdcltype
parameter_list|(
name|cl_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Clear a cluster chain in a FAT  */
end_comment

begin_function_decl
name|void
name|clearchain
parameter_list|(
name|struct
name|bootblock
modifier|*
parameter_list|,
name|struct
name|fatEntry
modifier|*
parameter_list|,
name|cl_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

