begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  * Contributed by Exactis.com, Inc.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|id
index|[]
init|=
literal|"@(#)$Id: bf_portable.c,v 8.25.4.6 2001/05/03 17:24:01 gshapiro Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! lint */
end_comment

begin_if
if|#
directive|if
name|SFIO
end_if

begin_include
include|#
directive|include
file|<sfio/stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SFIO */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
operator|!
name|SFIO
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SFIO */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BF_STANDALONE
end_ifdef

begin_define
define|#
directive|define
name|sm_free
value|free
end_define

begin_define
define|#
directive|define
name|xalloc
value|malloc
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BF_STANDALONE */
end_comment

begin_include
include|#
directive|include
file|"sendmail.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BF_STANDALONE */
end_comment

begin_include
include|#
directive|include
file|"bf_portable.h"
end_include

begin_include
include|#
directive|include
file|"bf.h"
end_include

begin_escape
end_escape

begin_comment
comment|/* **  BFOPEN -- create a new buffered file ** **	Parameters: **		filename -- the file's name **		fmode -- what mode the file should be created as **		bsize -- amount of buffer space to allocate (may be 0) **		flags -- if running under sendmail, passed directly to safeopen ** **	Returns: **		a FILE * which may then be used with stdio functions, or NULL **		on failure. FILE * is opened for writing (mode "w+"). ** **	Side Effects: **		none. ** **	Sets errno: **		ENOMEM -- out of memory **		ENOENT -- illegal empty filename specified **		any value of errno specified by open() **		any value of errno specified by fdopen() **		any value of errno specified by funopen() */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BF_STANDALONE
end_ifdef

begin_define
define|#
directive|define
name|OPEN
parameter_list|(
name|fn
parameter_list|,
name|omode
parameter_list|,
name|cmode
parameter_list|,
name|sff
parameter_list|)
value|open(fn, omode, cmode)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BF_STANDALONE */
end_comment

begin_define
define|#
directive|define
name|OPEN
parameter_list|(
name|fn
parameter_list|,
name|omode
parameter_list|,
name|cmode
parameter_list|,
name|sff
parameter_list|)
value|safeopen(fn, omode, cmode, sff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BF_STANDALONE */
end_comment

begin_comment
comment|/* List of currently-open buffered files */
end_comment

begin_decl_stmt
name|struct
name|bf
modifier|*
name|bflist
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_function
name|FILE
modifier|*
name|bfopen
parameter_list|(
name|filename
parameter_list|,
name|fmode
parameter_list|,
name|bsize
parameter_list|,
name|flags
parameter_list|)
name|char
modifier|*
name|filename
decl_stmt|;
name|int
name|fmode
decl_stmt|;
name|size_t
name|bsize
decl_stmt|;
name|long
name|flags
decl_stmt|;
block|{
name|struct
name|bf
modifier|*
name|bfp
decl_stmt|;
name|FILE
modifier|*
name|retval
decl_stmt|;
name|int
name|fd
decl_stmt|,
name|l
decl_stmt|;
name|fd
operator|=
name|OPEN
argument_list|(
name|filename
argument_list|,
name|O_RDWR
operator||
name|O_CREAT
operator||
name|O_TRUNC
argument_list|,
name|fmode
argument_list|,
name|flags
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* errno is set implicitly by open */
return|return
name|NULL
return|;
block|}
name|retval
operator|=
name|fdopen
argument_list|(
name|fd
argument_list|,
literal|"w+"
argument_list|)
expr_stmt|;
comment|/* If failure, return immediately */
if|if
condition|(
name|retval
operator|==
name|NULL
condition|)
block|{
comment|/* errno is set implicitly by fdopen */
return|return
name|NULL
return|;
block|}
comment|/* Allocate memory */
name|bfp
operator|=
operator|(
expr|struct
name|bf
operator|*
operator|)
name|xalloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|bf
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|bfp
operator|==
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|retval
argument_list|)
expr_stmt|;
comment|/* don't care about errors */
operator|(
name|void
operator|)
name|unlink
argument_list|(
name|filename
argument_list|)
expr_stmt|;
name|errno
operator|=
name|ENOMEM
expr_stmt|;
return|return
name|NULL
return|;
block|}
if|if
condition|(
name|tTd
argument_list|(
literal|58
argument_list|,
literal|8
argument_list|)
condition|)
name|dprintf
argument_list|(
literal|"bfopen(%s): malloced %ld\n"
argument_list|,
name|filename
argument_list|,
operator|(
name|long
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|bf
argument_list|)
argument_list|)
expr_stmt|;
name|l
operator|=
name|strlen
argument_list|(
name|filename
argument_list|)
operator|+
literal|1
expr_stmt|;
name|bfp
operator|->
name|bf_filename
operator|=
operator|(
name|char
operator|*
operator|)
name|xalloc
argument_list|(
name|l
argument_list|)
expr_stmt|;
if|if
condition|(
name|bfp
operator|->
name|bf_filename
operator|==
name|NULL
condition|)
block|{
name|sm_free
argument_list|(
name|bfp
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|retval
argument_list|)
expr_stmt|;
comment|/* don't care about errors */
operator|(
name|void
operator|)
name|unlink
argument_list|(
name|filename
argument_list|)
expr_stmt|;
name|errno
operator|=
name|ENOMEM
expr_stmt|;
return|return
name|NULL
return|;
block|}
operator|(
name|void
operator|)
name|strlcpy
argument_list|(
name|bfp
operator|->
name|bf_filename
argument_list|,
name|filename
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|/* Fill in the other fields, then add it to the list */
name|bfp
operator|->
name|bf_key
operator|=
name|retval
expr_stmt|;
name|bfp
operator|->
name|bf_committed
operator|=
name|FALSE
expr_stmt|;
name|bfp
operator|->
name|bf_refcount
operator|=
literal|1
expr_stmt|;
name|bfinsert
argument_list|(
name|bfp
argument_list|)
expr_stmt|;
comment|/* Whew. Nothing bad happened. We're okay. */
return|return
name|retval
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  BFDUP -- increase refcount on buffered file ** **	Parameters: **		fp -- FILE * to "duplicate" ** **	Returns: **		fp with increased refcount */
end_comment

begin_function
name|FILE
modifier|*
name|bfdup
parameter_list|(
name|fp
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
name|struct
name|bf
modifier|*
name|bfp
decl_stmt|;
comment|/* Get associated bf structure */
name|bfp
operator|=
name|bflookup
argument_list|(
name|fp
argument_list|)
expr_stmt|;
if|if
condition|(
name|bfp
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
comment|/* Increase the refcount */
name|bfp
operator|->
name|bf_refcount
operator|++
expr_stmt|;
return|return
name|fp
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  BFCOMMIT -- "commits" the buffered file ** **	Parameters: **		fp -- FILE * to commit to disk ** **	Returns: **		0 on success, -1 on error ** **	Side Effects: **		Forces the given FILE * to be written to disk if it is not **		already, and ensures that it will be kept after closing. If **		fp is not a buffered file, this is a no-op. ** **	Sets errno: **		any value of errno specified by open() **		any value of errno specified by write() **		any value of errno specified by lseek() */
end_comment

begin_function
name|int
name|bfcommit
parameter_list|(
name|fp
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
name|struct
name|bf
modifier|*
name|bfp
decl_stmt|;
comment|/* Get associated bf structure */
name|bfp
operator|=
name|bflookup
argument_list|(
name|fp
argument_list|)
expr_stmt|;
comment|/* If called on a normal FILE *, noop */
if|if
condition|(
name|bfp
operator|!=
name|NULL
condition|)
name|bfp
operator|->
name|bf_committed
operator|=
name|TRUE
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  BFREWIND -- rewinds the FILE * ** **	Parameters: **		fp -- FILE * to rewind ** **	Returns: **		0 on success, -1 on error ** **	Side Effects: **		rewinds the FILE * and puts it into read mode. Normally one **		would bfopen() a file, write to it, then bfrewind() and **		fread(). If fp is not a buffered file, this is equivalent to **		rewind(). ** **	Sets errno: **		any value of errno specified by fseek() */
end_comment

begin_function
name|int
name|bfrewind
parameter_list|(
name|fp
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
comment|/* check to see if there is an error on the stream */
name|err
operator|=
name|ferror
argument_list|(
name|fp
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|fp
argument_list|)
expr_stmt|;
comment|/* 	**  Clear error if tried to fflush() 	**  a read-only file pointer and 	**  there wasn't a previous error. 	*/
if|if
condition|(
name|err
operator|==
literal|0
condition|)
name|clearerr
argument_list|(
name|fp
argument_list|)
expr_stmt|;
comment|/* errno is set implicitly by fseek() before return */
return|return
name|fseek
argument_list|(
name|fp
argument_list|,
literal|0
argument_list|,
name|SEEK_SET
argument_list|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  BFTRUNCATE -- rewinds and truncates the FILE * ** **	Parameters: **		fp -- FILE * to truncate ** **	Returns: **		0 on success, -1 on error ** **	Side Effects: **		rewinds the FILE *, truncates it to zero length, and puts it **		into write mode. If fp is not a buffered file, this is **		equivalent to a rewind() and then an ftruncate(fileno(fp), 0). ** **	Sets errno: **		any value of errno specified by fseek() **		any value of errno specified by ftruncate() */
end_comment

begin_function
name|int
name|bftruncate
parameter_list|(
name|fp
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
name|int
name|ret
decl_stmt|;
if|if
condition|(
name|bfrewind
argument_list|(
name|fp
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* errno is set implicitly by bfrewind() */
return|return
operator|-
literal|1
return|;
block|}
if|#
directive|if
name|NOFTRUNCATE
comment|/* XXX */
name|errno
operator|=
name|EINVAL
expr_stmt|;
name|ret
operator|=
operator|-
literal|1
expr_stmt|;
else|#
directive|else
comment|/* NOFTRUNCATE */
comment|/* errno is set implicitly by ftruncate() before return */
name|ret
operator|=
name|ftruncate
argument_list|(
name|fileno
argument_list|(
name|fp
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOFTRUNCATE */
return|return
name|ret
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  BFFSYNC -- fsync the fd associated with the FILE * ** **	Parameters: **		fp -- FILE * to fsync ** **	Returns: **		0 on success, -1 on error ** **	Sets errno: **		EINVAL if FILE * not bfcommitted yet. **		any value of errno specified by fsync() */
end_comment

begin_function
name|int
name|bffsync
parameter_list|(
name|fp
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
name|int
name|fd
decl_stmt|;
name|struct
name|bf
modifier|*
name|bfp
decl_stmt|;
comment|/* Get associated bf structure */
name|bfp
operator|=
name|bflookup
argument_list|(
name|fp
argument_list|)
expr_stmt|;
comment|/* If called on a normal FILE *, noop */
if|if
condition|(
name|bfp
operator|!=
name|NULL
operator|&&
operator|!
name|bfp
operator|->
name|bf_committed
condition|)
name|fd
operator|=
operator|-
literal|1
expr_stmt|;
else|else
name|fd
operator|=
name|fileno
argument_list|(
name|fp
argument_list|)
expr_stmt|;
if|if
condition|(
name|tTd
argument_list|(
literal|58
argument_list|,
literal|10
argument_list|)
condition|)
name|dprintf
argument_list|(
literal|"bffsync: fd = %d\n"
argument_list|,
name|fd
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
block|{
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
return|return
name|fsync
argument_list|(
name|fd
argument_list|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  BFCLOSE -- close a buffered file ** **	Parameters: **		fp -- FILE * to close ** **	Returns: **		0 on success, EOF on failure ** **	Side Effects: **		Closes fp. If fp is a buffered file, unlink it if it has not **		already been committed. If fp is not a buffered file, this is **		equivalent to fclose(). ** **	Sets errno: **		any value of errno specified by fclose() */
end_comment

begin_function
name|int
name|bfclose
parameter_list|(
name|fp
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
name|int
name|retval
decl_stmt|;
name|struct
name|bf
modifier|*
name|bfp
init|=
name|NULL
decl_stmt|;
comment|/* Get associated bf structure */
name|bfp
operator|=
name|bflookup
argument_list|(
name|fp
argument_list|)
expr_stmt|;
comment|/* Decrement and check refcount */
if|if
condition|(
name|bfp
operator|!=
name|NULL
operator|&&
operator|--
name|bfp
operator|->
name|bf_refcount
operator|>
literal|0
condition|)
return|return
literal|0
return|;
comment|/* If bf, get bf structure and remove from list */
if|if
condition|(
name|bfp
operator|!=
name|NULL
condition|)
name|bfp
operator|=
name|bfdelete
argument_list|(
name|fp
argument_list|)
expr_stmt|;
if|if
condition|(
name|fclose
argument_list|(
name|fp
argument_list|)
operator|==
name|EOF
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|58
argument_list|,
literal|8
argument_list|)
condition|)
name|dprintf
argument_list|(
literal|"bfclose: fclose failed\n"
argument_list|)
expr_stmt|;
comment|/* errno is set implicitly by fclose() */
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|bfp
operator|==
name|NULL
condition|)
return|return
literal|0
return|;
comment|/* Success unless we determine otherwise in next block */
name|retval
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|bfp
operator|!=
name|NULL
condition|)
block|{
comment|/* Might have to unlink; certainly will have to deallocate */
if|if
condition|(
operator|!
name|bfp
operator|->
name|bf_committed
condition|)
name|retval
operator|=
name|unlink
argument_list|(
name|bfp
operator|->
name|bf_filename
argument_list|)
expr_stmt|;
name|sm_free
argument_list|(
name|bfp
operator|->
name|bf_filename
argument_list|)
expr_stmt|;
name|sm_free
argument_list|(
name|bfp
argument_list|)
expr_stmt|;
if|if
condition|(
name|tTd
argument_list|(
literal|58
argument_list|,
literal|8
argument_list|)
condition|)
name|dprintf
argument_list|(
literal|"bfclose: freed %ld\n"
argument_list|,
operator|(
name|long
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|bf
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|58
argument_list|,
literal|8
argument_list|)
condition|)
name|dprintf
argument_list|(
literal|"bfclose: bfp was NULL\n"
argument_list|)
expr_stmt|;
block|}
return|return
name|retval
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  BFTEST -- test if a FILE * is a buffered file ** **	Parameters: **		fp -- FILE * to test ** **	Returns: **		TRUE if fp is a buffered file, FALSE otherwise. ** **	Side Effects: **		none. ** **	Sets errno: **		never. */
end_comment

begin_function
name|bool
name|bftest
parameter_list|(
name|fp
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
return|return
operator|(
name|bflookup
argument_list|(
name|fp
argument_list|)
operator|!=
name|NULL
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  BFINSERT -- insert item in linking list ** **	Parameters: **		datum -- item to insert ** **	Returns: **		none. ** **	Side Effects: **		none. ** **	Sets errno: **		never. */
end_comment

begin_function
name|void
name|bfinsert
parameter_list|(
name|datum
parameter_list|)
name|struct
name|bf
modifier|*
name|datum
decl_stmt|;
block|{
name|datum
operator|->
name|bf_cdr
operator|=
name|bflist
expr_stmt|;
name|bflist
operator|=
name|datum
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  BFLOOKUP -- lookup FILE * in list ** **	Parameters: **		fp -- FILE * to lookup ** **	Returns: **		bf struct for the FILE *, NULL if not found ** **	Side Effects: **		none. ** **	Sets errno: **		never. */
end_comment

begin_function
name|struct
name|bf
modifier|*
name|bflookup
parameter_list|(
name|key
parameter_list|)
name|FILE
modifier|*
name|key
decl_stmt|;
block|{
name|struct
name|bf
modifier|*
name|t
decl_stmt|;
for|for
control|(
name|t
operator|=
name|bflist
init|;
name|t
operator|!=
name|NULL
condition|;
name|t
operator|=
name|t
operator|->
name|bf_cdr
control|)
block|{
if|if
condition|(
name|t
operator|->
name|bf_key
operator|==
name|key
condition|)
block|{
return|return
name|t
return|;
block|}
block|}
comment|/* If we got this far, we didn't find it */
return|return
name|NULL
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  BFDELETE -- delete a FILE * in list ** **	Parameters: **		fp -- FILE * to delete ** **	Returns: **		bf struct for deleted FILE *, NULL if not found, ** **	Side Effects: **		none. ** **	Sets errno: **		never. */
end_comment

begin_function
name|struct
name|bf
modifier|*
name|bfdelete
parameter_list|(
name|key
parameter_list|)
name|FILE
modifier|*
name|key
decl_stmt|;
block|{
name|struct
name|bf
modifier|*
name|t
decl_stmt|,
modifier|*
name|u
decl_stmt|;
if|if
condition|(
name|bflist
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
comment|/* if first element, special case */
if|if
condition|(
name|bflist
operator|->
name|bf_key
operator|==
name|key
condition|)
block|{
name|u
operator|=
name|bflist
expr_stmt|;
name|bflist
operator|=
name|bflist
operator|->
name|bf_cdr
expr_stmt|;
return|return
name|u
return|;
block|}
for|for
control|(
name|t
operator|=
name|bflist
init|;
name|t
operator|->
name|bf_cdr
operator|!=
name|NULL
condition|;
name|t
operator|=
name|t
operator|->
name|bf_cdr
control|)
block|{
if|if
condition|(
name|t
operator|->
name|bf_cdr
operator|->
name|bf_key
operator|==
name|key
condition|)
block|{
name|u
operator|=
name|t
operator|->
name|bf_cdr
expr_stmt|;
name|t
operator|->
name|bf_cdr
operator|=
name|u
operator|->
name|bf_cdr
expr_stmt|;
return|return
name|u
return|;
block|}
block|}
comment|/* If we got this far, we didn't find it */
return|return
name|NULL
return|;
block|}
end_function

end_unit

