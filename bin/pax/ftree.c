begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Keith Muller.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: ftree.c,v 1.8 1997/08/29 16:12:24 sos Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
specifier|const
name|sccsid
index|[]
init|=
literal|"@(#)ftree.c	8.2 (Berkeley) 4/18/94"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<fts.h>
end_include

begin_include
include|#
directive|include
file|"pax.h"
end_include

begin_include
include|#
directive|include
file|"ftree.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_comment
comment|/*  * routines to interface with the fts library function.  *  * file args supplied to pax are stored on a single linked list (of type FTREE)  * and given to fts to be processed one at a time. pax "selects" files from  * the expansion of each arg into the corresponding file tree (if the arg is a  * directory, otherwise the node itself is just passed to pax). The selection  * is modified by the -n and -u flags. The user is informed when a specific  * file arg does not generate any selected files. -n keeps expanding the file  * tree arg until one of its files is selected, then skips to the next file  * arg. when the user does not supply the file trees as command line args to  * pax, they are read from stdin  */
end_comment

begin_decl_stmt
specifier|static
name|FTS
modifier|*
name|ftsp
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* curent FTS handle */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ftsopts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* options to be used on fts_open */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|farray
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* array for passing each arg to fts */
end_comment

begin_decl_stmt
specifier|static
name|FTREE
modifier|*
name|fthead
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of linked list of file args */
end_comment

begin_decl_stmt
specifier|static
name|FTREE
modifier|*
name|fttail
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tail of linked list of file args */
end_comment

begin_decl_stmt
specifier|static
name|FTREE
modifier|*
name|ftcur
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current file arg being processed */
end_comment

begin_decl_stmt
specifier|static
name|FTSENT
modifier|*
name|ftent
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current file tree entry */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ftree_skip
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when set skip to next file arg */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ftree_arg
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * ftree_start()  *	initialize the options passed to fts_open() during this run of pax  *	options are based on the selection of pax options by the user  *	fts_start() also calls fts_arg() to open the first valid file arg. We  *	also attempt to reset directory access times when -t (tflag) is set.  * Return:  *	0 if there is at least one valid file arg to process, -1 otherwise  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_decl_stmt
name|int
name|ftree_start
argument_list|(
name|void
argument_list|)
else|#
directive|else
name|int
name|ftree_start
argument_list|()
endif|#
directive|endif
block|{
comment|/* 	 * set up the operation mode of fts, open the first file arg. We must 	 * use FTS_NOCHDIR, as the user may have to open multiple archives and 	 * if fts did a chdir off into the boondocks, we may create an archive 	 * volume in an place where the user did not expect to. 	 */
name|ftsopts
operator|=
name|FTS_NOCHDIR
expr_stmt|;
comment|/* 	 * optional user flags that effect file traversal 	 * -H command line symlink follow only (half follow) 	 * -L follow sylinks (logical) 	 * -P do not follow sylinks (physical). This is the default. 	 * -X do not cross over mount points 	 * -t preserve access times on files read. 	 * -n select only the first member of a file tree when a match is found 	 * -d do not extract subtrees rooted at a directory arg. 	 */
if|if
condition|(
name|Lflag
condition|)
name|ftsopts
operator||=
name|FTS_LOGICAL
expr_stmt|;
else|else
name|ftsopts
operator||=
name|FTS_PHYSICAL
expr_stmt|;
if|if
condition|(
name|Hflag
condition|)
ifdef|#
directive|ifdef
name|NET2_FTS
name|pax_warn
argument_list|(
literal|0
argument_list|,
literal|"The -H flag is not supported on this version"
argument_list|)
expr_stmt|;
else|#
directive|else
name|ftsopts
operator||=
name|FTS_COMFOLLOW
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|Xflag
condition|)
name|ftsopts
operator||=
name|FTS_XDEV
expr_stmt|;
if|if
condition|(
operator|(
name|fthead
operator|==
name|NULL
operator|)
operator|&&
operator|(
operator|(
name|farray
index|[
literal|0
index|]
operator|=
name|malloc
argument_list|(
name|PAXPATHLEN
operator|+
literal|2
argument_list|)
operator|)
operator|==
name|NULL
operator|)
condition|)
block|{
name|pax_warn
argument_list|(
literal|1
argument_list|,
literal|"Unable to allocate memory for file name buffer"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|ftree_arg
argument_list|()
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|tflag
operator|&&
operator|(
name|atdir_start
argument_list|()
operator|<
literal|0
operator|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/*  * ftree_add()  *	add the arg to the linked list of files to process. Each will be  *	processed by fts one at a time  * Return:  *	0 if added to the linked list, -1 if failed  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_decl_stmt
name|int
name|ftree_add
argument_list|(
specifier|register
name|char
operator|*
name|str
argument_list|)
else|#
directive|else
name|int
name|ftree_add
argument_list|(
name|str
argument_list|)
decl|register
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|FTREE
modifier|*
name|ft
decl_stmt|;
specifier|register
name|int
name|len
decl_stmt|;
comment|/* 	 * simple check for bad args 	 */
if|if
condition|(
operator|(
name|str
operator|==
name|NULL
operator|)
operator|||
operator|(
operator|*
name|str
operator|==
literal|'\0'
operator|)
condition|)
block|{
name|pax_warn
argument_list|(
literal|0
argument_list|,
literal|"Invalid file name arguement"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* 	 * allocate FTREE node and add to the end of the linked list (args are 	 * processed in the same order they were passed to pax). Get rid of any 	 * trailing / the user may pass us. (watch out for / by itself). 	 */
if|if
condition|(
operator|(
name|ft
operator|=
operator|(
name|FTREE
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|FTREE
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|pax_warn
argument_list|(
literal|0
argument_list|,
literal|"Unable to allocate memory for filename"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
operator|(
operator|(
name|len
operator|=
name|strlen
argument_list|(
name|str
argument_list|)
operator|-
literal|1
operator|)
operator|>
literal|0
operator|)
operator|&&
operator|(
name|str
index|[
name|len
index|]
operator|==
literal|'/'
operator|)
condition|)
name|str
index|[
name|len
index|]
operator|=
literal|'\0'
expr_stmt|;
name|ft
operator|->
name|fname
operator|=
name|str
expr_stmt|;
name|ft
operator|->
name|refcnt
operator|=
literal|0
expr_stmt|;
name|ft
operator|->
name|fow
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|fthead
operator|==
name|NULL
condition|)
block|{
name|fttail
operator|=
name|fthead
operator|=
name|ft
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|fttail
operator|->
name|fow
operator|=
name|ft
expr_stmt|;
name|fttail
operator|=
name|ft
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * ftree_sel()  *	this entry has been selected by pax. bump up reference count and handle  *	-n and -d processing.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_decl_stmt
name|void
name|ftree_sel
argument_list|(
specifier|register
name|ARCHD
operator|*
name|arcn
argument_list|)
else|#
directive|else
name|void
name|ftree_sel
argument_list|(
name|arcn
argument_list|)
decl|register
name|ARCHD
modifier|*
name|arcn
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
comment|/* 	 * set reference bit for this pattern. This linked list is only used 	 * when file trees are supplied pax as args. The list is not used when 	 * the trees are read from stdin. 	 */
if|if
condition|(
name|ftcur
operator|!=
name|NULL
condition|)
name|ftcur
operator|->
name|refcnt
operator|=
literal|1
expr_stmt|;
comment|/* 	 * if -n we are done with this arg, force a skip to the next arg when 	 * pax asks for the next file in next_file(). 	 * if -d we tell fts only to match the directory (if the arg is a dir) 	 * and not the entire file tree rooted at that point. 	 */
if|if
condition|(
name|nflag
condition|)
name|ftree_skip
operator|=
literal|1
expr_stmt|;
if|if
condition|(
operator|!
name|dflag
operator|||
operator|(
name|arcn
operator|->
name|type
operator|!=
name|PAX_DIR
operator|)
condition|)
return|return;
if|if
condition|(
name|ftent
operator|!=
name|NULL
condition|)
operator|(
name|void
operator|)
name|fts_set
argument_list|(
name|ftsp
argument_list|,
name|ftent
argument_list|,
name|FTS_SKIP
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * ftree_chk()  *	called at end on pax execution. Prints all those file args that did not  *	have a selected member (reference count still 0)  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_decl_stmt
name|void
name|ftree_chk
argument_list|(
name|void
argument_list|)
else|#
directive|else
name|void
name|ftree_chk
argument_list|()
endif|#
directive|endif
block|{
specifier|register
name|FTREE
modifier|*
name|ft
decl_stmt|;
specifier|register
name|int
name|wban
init|=
literal|0
decl_stmt|;
comment|/* 	 * make sure all dir access times were reset. 	 */
if|if
condition|(
name|tflag
condition|)
name|atdir_end
argument_list|()
expr_stmt|;
comment|/* 	 * walk down list and check reference count. Print out those members 	 * that never had a match 	 */
for|for
control|(
name|ft
operator|=
name|fthead
init|;
name|ft
operator|!=
name|NULL
condition|;
name|ft
operator|=
name|ft
operator|->
name|fow
control|)
block|{
if|if
condition|(
name|ft
operator|->
name|refcnt
operator|>
literal|0
condition|)
continue|continue;
if|if
condition|(
name|wban
operator|==
literal|0
condition|)
block|{
name|pax_warn
argument_list|(
literal|1
argument_list|,
literal|"WARNING! These file names were not selected:"
argument_list|)
expr_stmt|;
operator|++
name|wban
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|ft
operator|->
name|fname
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|/*  * ftree_arg()  *	Get the next file arg for fts to process. Can be from either the linked  *	list or read from stdin when the user did not them as args to pax. Each  *	arg is processed until the first successful fts_open().  * Return:  *	0 when the next arg is ready to go, -1 if out of file args (or EOF on  *	stdin).  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_decl_stmt
specifier|static
name|int
name|ftree_arg
argument_list|(
name|void
argument_list|)
else|#
directive|else
decl|static
name|int
name|ftree_arg
argument_list|()
endif|#
directive|endif
block|{
specifier|register
name|char
modifier|*
name|pt
decl_stmt|;
comment|/* 	 * close off the current file tree 	 */
if|if
condition|(
name|ftsp
operator|!=
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|fts_close
argument_list|(
name|ftsp
argument_list|)
expr_stmt|;
name|ftsp
operator|=
name|NULL
expr_stmt|;
block|}
comment|/* 	 * keep looping until we get a valid file tree to process. Stop when we 	 * reach the end of the list (or get an eof on stdin) 	 */
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|fthead
operator|==
name|NULL
condition|)
block|{
comment|/* 			 * the user didn't supply any args, get the file trees 			 * to process from stdin; 			 */
if|if
condition|(
name|fgets
argument_list|(
name|farray
index|[
literal|0
index|]
argument_list|,
name|PAXPATHLEN
operator|+
literal|1
argument_list|,
name|stdin
argument_list|)
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
operator|(
name|pt
operator|=
name|strchr
argument_list|(
name|farray
index|[
literal|0
index|]
argument_list|,
literal|'\n'
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
operator|*
name|pt
operator|=
literal|'\0'
expr_stmt|;
block|}
else|else
block|{
comment|/* 			 * the user supplied the file args as arguements to pax 			 */
if|if
condition|(
name|ftcur
operator|==
name|NULL
condition|)
name|ftcur
operator|=
name|fthead
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|ftcur
operator|=
name|ftcur
operator|->
name|fow
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|farray
index|[
literal|0
index|]
operator|=
name|ftcur
operator|->
name|fname
expr_stmt|;
block|}
comment|/* 		 * watch it, fts wants the file arg stored in a array of char 		 * ptrs, with the last one a null. we use a two element array 		 * and set farray[0] to point at the buffer with the file name 		 * in it. We cannnot pass all the file args to fts at one shot 		 * as we need to keep a handle on which file arg generates what 		 * files (the -n and -d flags need this). If the open is 		 * successful, return a 0. 		 */
if|if
condition|(
operator|(
name|ftsp
operator|=
name|fts_open
argument_list|(
name|farray
argument_list|,
name|ftsopts
argument_list|,
name|NULL
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
break|break;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/*  * next_file()  *	supplies the next file to process in the supplied archd structure.  * Return:  *	0 when contents of arcn have been set with the next file, -1 when done.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_decl_stmt
name|int
name|next_file
argument_list|(
specifier|register
name|ARCHD
operator|*
name|arcn
argument_list|)
else|#
directive|else
name|int
name|next_file
argument_list|(
name|arcn
argument_list|)
decl|register
name|ARCHD
modifier|*
name|arcn
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|int
name|cnt
decl_stmt|;
name|time_t
name|atime
decl_stmt|;
name|time_t
name|mtime
decl_stmt|;
comment|/* 	 * ftree_sel() might have set the ftree_skip flag if the user has the 	 * -n option and a file was selected from this file arg tree. (-n says 	 * only one member is matched for each pattern) ftree_skip being 1 	 * forces us to go to the next arg now. 	 */
if|if
condition|(
name|ftree_skip
condition|)
block|{
comment|/* 		 * clear and go to next arg 		 */
name|ftree_skip
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|ftree_arg
argument_list|()
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* 	 * loop until we get a valid file to process 	 */
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
operator|(
name|ftent
operator|=
name|fts_read
argument_list|(
name|ftsp
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
comment|/* 			 * out of files in this tree, go to next arg, if none 			 * we are done 			 */
if|if
condition|(
name|ftree_arg
argument_list|()
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
continue|continue;
block|}
comment|/* 		 * handle each type of fts_read() flag 		 */
switch|switch
condition|(
name|ftent
operator|->
name|fts_info
condition|)
block|{
case|case
name|FTS_D
case|:
case|case
name|FTS_DEFAULT
case|:
case|case
name|FTS_F
case|:
case|case
name|FTS_SL
case|:
case|case
name|FTS_SLNONE
case|:
comment|/* 			 * these are all ok 			 */
break|break;
case|case
name|FTS_DP
case|:
comment|/* 			 * already saw this directory. If the user wants file 			 * access times reset, we use this to restore the 			 * access time for this directory since this is the 			 * last time we will see it in this file subtree 			 * remember to force the time (this is -t on a read 			 * directory, not a created directory). 			 */
ifdef|#
directive|ifdef
name|NET2_FTS
if|if
condition|(
operator|!
name|tflag
operator|||
operator|(
name|get_atdir
argument_list|(
name|ftent
operator|->
name|fts_statb
operator|.
name|st_dev
argument_list|,
name|ftent
operator|->
name|fts_statb
operator|.
name|st_ino
argument_list|,
operator|&
name|mtime
argument_list|,
operator|&
name|atime
argument_list|)
operator|<
literal|0
operator|)
condition|)
else|#
directive|else
if|if
condition|(
operator|!
name|tflag
operator|||
operator|(
name|get_atdir
argument_list|(
name|ftent
operator|->
name|fts_statp
operator|->
name|st_dev
argument_list|,
name|ftent
operator|->
name|fts_statp
operator|->
name|st_ino
argument_list|,
operator|&
name|mtime
argument_list|,
operator|&
name|atime
argument_list|)
operator|<
literal|0
operator|)
condition|)
endif|#
directive|endif
continue|continue;
name|set_ftime
argument_list|(
name|ftent
operator|->
name|fts_path
argument_list|,
name|mtime
argument_list|,
name|atime
argument_list|,
literal|1
argument_list|)
expr_stmt|;
continue|continue;
case|case
name|FTS_DC
case|:
comment|/* 			 * fts claims a file system cycle 			 */
name|pax_warn
argument_list|(
literal|1
argument_list|,
literal|"File system cycle found at %s"
argument_list|,
name|ftent
operator|->
name|fts_path
argument_list|)
expr_stmt|;
continue|continue;
case|case
name|FTS_DNR
case|:
ifdef|#
directive|ifdef
name|NET2_FTS
name|sys_warn
argument_list|(
literal|1
argument_list|,
argument|errno
argument_list|,
else|#
directive|else
argument|sys_warn(
literal|1
argument|, ftent->fts_errno,
endif|#
directive|endif
literal|"Unable to read directory %s"
argument|, ftent->fts_path); 			continue; 		case FTS_ERR:
ifdef|#
directive|ifdef
name|NET2_FTS
argument|sys_warn(
literal|1
argument|, errno,
else|#
directive|else
argument|sys_warn(
literal|1
argument|, ftent->fts_errno,
endif|#
directive|endif
literal|"File system traversal error"
argument|); 			continue; 		case FTS_NS: 		case FTS_NSOK:
ifdef|#
directive|ifdef
name|NET2_FTS
argument|sys_warn(
literal|1
argument|, errno,
else|#
directive|else
argument|sys_warn(
literal|1
argument|, ftent->fts_errno,
endif|#
directive|endif
literal|"Unable to access %s"
argument|, ftent->fts_path); 			continue; 		}
comment|/* 		 * ok got a file tree node to process. copy info into arcn 		 * structure (initialize as required) 		 */
argument|arcn->skip =
literal|0
argument|; 		arcn->pad =
literal|0
argument|; 		arcn->ln_nlen =
literal|0
argument|; 		arcn->ln_name[
literal|0
argument|] =
literal|'\0'
argument|;
ifdef|#
directive|ifdef
name|NET2_FTS
argument|arcn->sb = ftent->fts_statb;
else|#
directive|else
argument|arcn->sb = *(ftent->fts_statp);
endif|#
directive|endif
comment|/* 		 * file type based set up and copy into the arcn struct 		 * SIDE NOTE: 		 * we try to reset the access time on all files and directories 		 * we may read when the -t flag is specified. files are reset 		 * when we close them after copying. we reset the directories 		 * when we are done with their file tree (we also clean up at 		 * end in case we cut short a file tree traversal). However 		 * there is no way to reset access times on symlinks. 		 */
argument|switch(S_IFMT& arcn->sb.st_mode) { 		case S_IFDIR: 			arcn->type = PAX_DIR; 			if (!tflag) 				break; 			add_atdir(ftent->fts_path, arcn->sb.st_dev, 			    arcn->sb.st_ino, arcn->sb.st_mtime, 			    arcn->sb.st_atime); 			break; 		case S_IFCHR: 			arcn->type = PAX_CHR; 			break; 		case S_IFBLK: 			arcn->type = PAX_BLK; 			break; 		case S_IFREG:
comment|/* 			 * only regular files with have data to store on the 			 * archive. all others will store a zero length skip. 			 * the skip field is used by pax for actual data it has 			 * to read (or skip over). 			 */
argument|arcn->type = PAX_REG; 			arcn->skip = arcn->sb.st_size; 			break; 		case S_IFLNK: 			arcn->type = PAX_SLK;
comment|/* 			 * have to read the symlink path from the file 			 */
argument|if ((cnt = readlink(ftent->fts_path, arcn->ln_name, 			    PAXPATHLEN))<
literal|0
argument|) { 				sys_warn(
literal|1
argument|, errno,
literal|"Unable to read symlink %s"
argument|, 				    ftent->fts_path); 				continue; 			}
comment|/* 			 * set link name length, watch out readlink does not 			 * allways null terminate the link path 			 */
argument|arcn->ln_name[cnt] =
literal|'\0'
argument|; 			arcn->ln_nlen = cnt; 			break; 		case S_IFSOCK:
comment|/* 			 * under BSD storing a socket is senseless but we will 			 * let the format specific write function make the 			 * decision of what to do with it. 			 */
argument|arcn->type = PAX_SCK; 			break; 		case S_IFIFO: 			arcn->type = PAX_FIF; 			break; 		} 		break; 	}
comment|/* 	 * copy file name, set file name length 	 */
argument|arcn->nlen = l_strncpy(arcn->name, ftent->fts_path, PAXPATHLEN+
literal|1
argument|); 	arcn->name[arcn->nlen] =
literal|'\0'
argument|; 	arcn->org_name = ftent->fts_path; 	return(
literal|0
argument|); }
end_block

end_unit

