begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Peter J. Nicklin.  * Copyright (c) 1991 Version Technology.  * All Rights Reserved.  *  * $License: VT.1.1 $  * Redistribution and use in source and binary forms,  with or without  * modification,  are permitted provided that the following conditions  * are met:  (1) Redistributions of source code must retain the  above  * copyright  notice,  this  list  of  conditions  and  the  following  * disclaimer.  (2) Redistributions in binary form must reproduce  the  * above  copyright notice,  this list of conditions and the following  * disclaimer in the  documentation  and/or other  materials  provided  * with  the  distribution.  (3) All advertising materials  mentioning  * features or  use  of  this  software  must  display  the  following  * acknowledgement:  ``This  product  includes  software  developed by  * Version Technology.''  Neither the name of Version  Technology  nor  * the  name  of  Peter J. Nicklin  may  be used to endorse or promote  * products derived from this software without specific prior  written  * permission.  *  * THIS SOFTWARE IS PROVIDED BY VERSION TECHNOLOGY ``AS IS''  AND  ANY  * EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT LIMITED TO, THE  * IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  VERSION  TECHNOLOGY  BE  * LIABLE  FOR ANY DIRECT,  INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY,  * OR  CONSEQUENTIAL DAMAGES   (INCLUDING,   BUT   NOT   LIMITED   TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY  * OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT LIABILITY,  OR  TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING  IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE,  EVEN  IF  ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * Report problems and direct questions to nicklin@netcom.com  *  * $Header: mksrclist.c,v 4.8 91/11/25 19:44:59 nicklin Exp $  *  * Author: Peter J. Nicklin  */
end_comment

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

begin_include
include|#
directive|include
file|"Mkmf.h"
end_include

begin_include
include|#
directive|include
file|"hash.h"
end_include

begin_include
include|#
directive|include
file|"macro.h"
end_include

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_include
include|#
directive|include
file|"path.h"
end_include

begin_include
include|#
directive|include
file|"slist.h"
end_include

begin_include
include|#
directive|include
file|"stringx.h"
end_include

begin_include
include|#
directive|include
file|"yesno.h"
end_include

begin_decl_stmt
specifier|extern
name|SLIST
modifier|*
name|SRCLIST
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source file name list */
end_comment

begin_decl_stmt
specifier|extern
name|SLIST
modifier|*
name|HEADLIST
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* header file name list */
end_comment

begin_decl_stmt
specifier|extern
name|HASH
modifier|*
name|MDEFTABLE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* macro definition table */
end_comment

begin_function_decl
specifier|static
name|int
name|addsrctable
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add file to src hash table / list */
end_comment

begin_function_decl
specifier|static
name|int
name|addvsrctable
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add virtual file to hash table */
end_comment

begin_function_decl
specifier|static
name|int
name|hashtolist
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* convert hash table file list */
end_comment

begin_decl_stmt
specifier|static
name|HASH
modifier|*
name|SRCTABLE
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source file hash table */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|stat
name|CURDIRSTAT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current directory status */
end_comment

begin_comment
comment|/*  * mksrclist() composes a list of source and header files names  * from the current directory and directories listed in VPATH.  * Return YES if successful, otherwise NO.  */
end_comment

begin_macro
name|mksrclist
argument_list|(
argument|needsrc
argument_list|,
argument|needhdr
argument_list|)
end_macro

begin_decl_stmt
name|int
name|needsrc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* need source file names */
end_comment

begin_decl_stmt
name|int
name|needhdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* need header file names */
end_comment

begin_block
block|{
name|char
modifier|*
name|getpath
parameter_list|()
function_decl|;
comment|/* get next path */
name|char
modifier|*
name|vp
decl_stmt|;
comment|/* virtual path buffer pointer */
name|char
name|vpath
index|[
name|PATHSIZE
index|]
decl_stmt|;
comment|/* virtual directory path buffer */
name|int
name|addsrclist
parameter_list|()
function_decl|;
comment|/* add file to header list */
name|int
name|read_dir
parameter_list|()
function_decl|;
comment|/* read dir for source and headers */
name|struct
name|stat
name|statbuf
decl_stmt|;
comment|/* virtual path stat buffer */
comment|/* 	 * save inode info for current directory so that we can make sure 	 * that directories in VPATH do not include the current directory. 	 */
if|if
condition|(
name|stat
argument_list|(
name|CURDIR
argument_list|,
operator|&
name|CURDIRSTAT
argument_list|)
operator|<
literal|0
condition|)
block|{
name|pperror
argument_list|(
name|CURDIR
argument_list|)
expr_stmt|;
return|return
operator|(
name|NO
operator|)
return|;
block|}
comment|/* 	 * if VPATH exists, merge the source file names from the 	 * directories in VPATH with the source files in the current 	 * directory, otherwise build source list directly. 	 */
if|if
condition|(
name|htlookup
argument_list|(
name|MVPATH
argument_list|,
name|MDEFTABLE
argument_list|)
operator|!=
name|NULL
condition|)
block|{
name|vp
operator|=
name|htdef
argument_list|(
name|MDEFTABLE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|SRCTABLE
operator|=
name|htinit
argument_list|(
name|SOURCETABLESIZE
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NO
operator|)
return|;
if|if
condition|(
name|read_dir
argument_list|(
name|CURDIR
argument_list|,
name|addsrctable
argument_list|,
name|needsrc
argument_list|,
name|needhdr
argument_list|)
operator|==
name|NO
condition|)
return|return
operator|(
name|NO
operator|)
return|;
while|while
condition|(
operator|(
name|vp
operator|=
name|getpath
argument_list|(
name|vpath
argument_list|,
name|vp
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|stat
argument_list|(
name|vpath
argument_list|,
operator|&
name|statbuf
argument_list|)
operator|<
literal|0
condition|)
block|{
name|pperror
argument_list|(
name|vpath
argument_list|)
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
operator|!
name|S_ISDIR
argument_list|(
name|statbuf
operator|.
name|st_mode
argument_list|)
condition|)
block|{
name|warns
argument_list|(
literal|"(warning) %s in VPATH not a directory"
argument_list|,
name|vpath
argument_list|)
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|CURDIRSTAT
operator|.
name|st_dev
operator|==
name|statbuf
operator|.
name|st_dev
operator|&&
name|CURDIRSTAT
operator|.
name|st_ino
operator|==
name|statbuf
operator|.
name|st_ino
condition|)
block|{
name|warns
argument_list|(
literal|"(warning) current directory %s included in VPATH"
argument_list|,
name|vpath
argument_list|)
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|read_dir
argument_list|(
name|vpath
argument_list|,
name|addvsrctable
argument_list|,
name|needsrc
argument_list|,
name|needhdr
argument_list|)
operator|==
name|NO
condition|)
return|return
operator|(
name|NO
operator|)
return|;
block|}
comment|/* 		 * convert hash table source file entries to 		 * singly-linked source list 		 */
if|if
condition|(
name|hashtolist
argument_list|(
name|SRCTABLE
argument_list|,
name|SRCLIST
argument_list|)
operator|==
name|NO
condition|)
block|{
name|htrm
argument_list|(
name|NULL
argument_list|,
name|SRCTABLE
argument_list|)
expr_stmt|;
return|return
operator|(
name|NO
operator|)
return|;
block|}
name|htrm
argument_list|(
name|NULL
argument_list|,
name|SRCTABLE
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|read_dir
argument_list|(
name|CURDIR
argument_list|,
name|addsrclist
argument_list|,
name|needsrc
argument_list|,
name|needhdr
argument_list|)
operator|==
name|NO
condition|)
return|return
operator|(
name|NO
operator|)
return|;
block|}
return|return
operator|(
name|YES
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * addsrclist() adds a file to a source/header file list. Returns YES if  * successful, otherwise NO.  */
end_comment

begin_macro
name|addsrclist
argument_list|(
argument|dirname
argument_list|,
argument|filename
argument_list|,
argument|lswitch
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|dirname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* directory name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|filename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file name to add to source list */
end_comment

begin_decl_stmt
name|int
name|lswitch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source/header list switch */
end_comment

begin_block
block|{
if|if
condition|(
name|lswitch
operator|==
literal|'s'
condition|)
return|return
operator|(
operator|(
name|slappend
argument_list|(
name|filename
argument_list|,
name|SRCLIST
argument_list|)
operator|!=
name|NULL
operator|)
condition|?
name|YES
else|:
name|NO
operator|)
return|;
else|else
return|return
operator|(
operator|(
name|slappend
argument_list|(
name|filename
argument_list|,
name|HEADLIST
argument_list|)
operator|!=
name|NULL
operator|)
condition|?
name|YES
else|:
name|NO
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * addsrctable() adds a file to a source file hash table or a header file  * singly-linked list. Returns YES if successful, otherwise NO.  */
end_comment

begin_function
specifier|static
name|int
name|addsrctable
parameter_list|(
name|dirname
parameter_list|,
name|filename
parameter_list|,
name|tswitch
parameter_list|)
name|char
modifier|*
name|dirname
decl_stmt|;
comment|/* directory name */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* file name to add to source table */
name|int
name|tswitch
decl_stmt|;
comment|/* source/header switch */
block|{
if|if
condition|(
name|tswitch
operator|==
literal|'s'
condition|)
block|{
if|if
condition|(
name|htlookup
argument_list|(
name|filename
argument_list|,
name|SRCTABLE
argument_list|)
operator|!=
name|NULL
condition|)
block|{
name|warn2
argument_list|(
literal|"(warning) duplicate file %s/%s ignored"
argument_list|,
name|dirname
argument_list|,
name|filename
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|htinstall
argument_list|(
name|filename
argument_list|,
name|dirname
argument_list|,
literal|0
argument_list|,
name|SRCTABLE
argument_list|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NO
operator|)
return|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|slappend
argument_list|(
name|filename
argument_list|,
name|HEADLIST
argument_list|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NO
operator|)
return|;
block|}
return|return
operator|(
name|YES
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * addvsrctable() adds a file to a source file hash table. Returns  * YES if successful, otherwise NO.  */
end_comment

begin_function
specifier|static
name|int
name|addvsrctable
parameter_list|(
name|dirname
parameter_list|,
name|filename
parameter_list|,
name|tswitch
parameter_list|)
name|char
modifier|*
name|dirname
decl_stmt|;
comment|/* directory name */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* file name to add to source table */
name|int
name|tswitch
decl_stmt|;
comment|/* source/header table switch */
block|{
name|HASH
modifier|*
name|table
decl_stmt|;
comment|/* pointer to source/header file table */
if|if
condition|(
name|tswitch
operator|==
literal|'s'
condition|)
block|{
if|if
condition|(
name|htlookup
argument_list|(
name|filename
argument_list|,
name|SRCTABLE
argument_list|)
operator|!=
name|NULL
condition|)
block|{
name|warn2
argument_list|(
literal|"(warning) duplicate file %s/%s ignored"
argument_list|,
name|dirname
argument_list|,
name|filename
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|htinstall
argument_list|(
name|filename
argument_list|,
name|dirname
argument_list|,
literal|0
argument_list|,
name|SRCTABLE
argument_list|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NO
operator|)
return|;
block|}
block|}
return|return
operator|(
name|YES
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * hashtolist() converts the file entries stored in a hash table to a  * singly-linked list of pathnames. Returns YES if successful, otherwise  * NO.  */
end_comment

begin_function
specifier|static
name|int
name|hashtolist
parameter_list|(
name|table
parameter_list|,
name|list
parameter_list|)
name|HASH
modifier|*
name|table
decl_stmt|;
comment|/* hash table */
name|SLIST
modifier|*
name|list
decl_stmt|;
comment|/* pointer to list head block */
block|{
name|char
name|path
index|[
name|PATHSIZE
index|]
decl_stmt|;
comment|/* path to foreign source file */
name|htrewind
argument_list|(
name|table
argument_list|)
expr_stmt|;
while|while
condition|(
name|htnext
argument_list|(
name|table
argument_list|)
condition|)
block|{
if|if
condition|(
name|htdef
argument_list|(
name|table
argument_list|)
operator|==
name|NULL
operator|||
name|EQUAL
argument_list|(
name|CURDIR
argument_list|,
name|htdef
argument_list|(
name|table
argument_list|)
argument_list|)
condition|)
block|{
comment|/* current directory */
if|if
condition|(
name|slappend
argument_list|(
name|htkey
argument_list|(
name|table
argument_list|)
argument_list|,
name|list
argument_list|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NO
operator|)
return|;
block|}
else|else
block|{
comment|/* VPATH directory */
name|pathcat
argument_list|(
name|path
argument_list|,
name|htdef
argument_list|(
name|table
argument_list|)
argument_list|,
name|htkey
argument_list|(
name|table
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|slappend
argument_list|(
name|path
argument_list|,
name|list
argument_list|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NO
operator|)
return|;
block|}
block|}
return|return
operator|(
name|YES
operator|)
return|;
block|}
end_function

end_unit

