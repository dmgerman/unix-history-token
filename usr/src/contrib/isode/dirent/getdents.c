begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	getdents -- get directory entries in a file system independent format 			(SVR3 system call emulation)  	last edit:	06-Jul-1987	D A Gwyn  	This single source file supports several different methods of 	getting directory entries from the operating system.  Define 	whichever one of the following describes your system:  	GETDENTS getdents() system call native, this library is unnecessary  	UFS	original UNIX filesystem (14-character name limit) 	BFS	4.2BSD (also 4.3BSD) native filesystem (long names) 	NFS	getdirentries() system call  	Also define any of the following that are pertinent:  	ATT_SPEC	check user buffer address for longword alignment 	BSD_SYSV	BRL UNIX System V emulation environment on 4.nBSD 	UNK		have _getdents() system call, but kernel may not 			support it  	If your C library has a getdents() system call interface, but you 	can't count on all kernels on which your application binaries may 	run to support it, change the system call interface name to 	_getdents() and define "UNK" to enable the system-call validity 	test in this "wrapper" around _getdents().  	If your system has a getdents() system call that is guaranteed  	to always work, you shouldn't be using this source file at all. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_comment
comment|/* for strings... */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: /f/osi/dirent/RCS/getdents.c,v 7.2 91/02/22 09:17:25 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SVR3
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|apollo
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|GETDENTS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BSD_SYSV
end_ifdef

begin_include
include|#
directive|include
file|"sys._dir.h"
end_include

begin_comment
comment|/* BSD flavor, not System V */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|AIX
end_ifndef

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"/usr/include/sys/dir.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|MAXNAMLEN
end_undef

begin_comment
comment|/* avoid conflict with SVR3 */
end_comment

begin_comment
comment|/* Good thing we don't need to use the DIRSIZ() macro! */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|d_ino
end_ifdef

begin_comment
comment|/* 4.3BSD/NFS using d_fileno */
end_comment

begin_undef
undef|#
directive|undef
name|d_ino
end_undef

begin_comment
comment|/* (not absolutely necessary) */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|d_fileno
value|d_ino
end_define

begin_comment
comment|/* (struct direct) member */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sys.dirent.h"
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NFS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|BSD42
end_ifdef

begin_define
define|#
directive|define
name|BFS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNK
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|UFS
end_ifndef

begin_include
include|#
directive|include
file|"***** ERROR ***** UNK applies only to UFS"
end_include

begin_comment
comment|/* One could do something similar for getdirentries(), but I didn't bother. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UFS
argument_list|)
operator|+
name|defined
argument_list|(
name|BFS
argument_list|)
operator|+
name|defined
argument_list|(
name|NFS
argument_list|)
operator|!=
literal|1
end_if

begin_comment
comment|/* sanity check */
end_comment

begin_include
include|#
directive|include
file|"***** ERROR ***** exactly one of UFS, BFS, or NFS must be defined"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UFS
end_ifdef

begin_define
define|#
directive|define
name|RecLen
parameter_list|(
name|dp
parameter_list|)
value|(sizeof(struct direct))
end_define

begin_comment
comment|/* fixed-length entries */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BFS || NFS */
end_comment

begin_define
define|#
directive|define
name|RecLen
parameter_list|(
name|dp
parameter_list|)
value|((dp)->d_reclen)
end_define

begin_comment
comment|/* variable-length entries */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NFS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|BSD_SYSV
end_ifdef

begin_define
define|#
directive|define
name|getdirentries
value|_getdirentries
end_define

begin_comment
comment|/* package hides this system call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|getdirentries
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|long
name|dummy
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* getdirentries() needs basep */
end_comment

begin_define
define|#
directive|define
name|GetBlock
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
value|getdirentries( fd, buf, (int)n,&dummy )
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* UFS || BFS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD_SYSV
end_ifdef

begin_define
define|#
directive|define
name|read
value|_read
end_define

begin_comment
comment|/* avoid emulation overhead */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|read
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GetBlock
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
value|read( fd, buf, (unsigned)n )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNK
end_ifdef

begin_function_decl
specifier|extern
name|int
name|_getdents
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* actual system call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|strncpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fstat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|off_t
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|DIRBLKSIZ
end_ifndef

begin_define
define|#
directive|define
name|DIRBLKSIZ
value|4096
end_define

begin_comment
comment|/* directory file read buffer size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_CUR
end_ifndef

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_comment
comment|/* macro to test for directory file */
end_comment

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UFS
end_ifdef

begin_comment
comment|/* 	The following routine is necessary to handle DIRSIZ-long entry names. 	Thanks to Richard Todd for pointing this out. */
end_comment

begin_function
specifier|static
name|int
name|NameLen
parameter_list|(
name|name
parameter_list|)
comment|/* return # chars in embedded name */
name|char
name|name
index|[]
decl_stmt|;
comment|/* -> name embedded in struct direct */
block|{
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
comment|/* -> name[.] */
specifier|register
name|char
modifier|*
name|stop
init|=
operator|&
name|name
index|[
name|DIRSIZ
index|]
decl_stmt|;
comment|/* -> past end of name field */
for|for
control|(
name|s
operator|=
operator|&
name|name
index|[
literal|1
index|]
init|;
comment|/* (empty names are impossible) */
operator|*
name|s
operator|!=
literal|'\0'
comment|/* not NUL terminator */
operator|&&
operator|++
name|s
operator|<
name|stop
condition|;
comment|/*< DIRSIZ characters scanned */
control|)
empty_stmt|;
return|return
name|s
operator|-
name|name
return|;
comment|/* # valid characters in name */
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BFS || NFS */
end_comment

begin_function_decl
specifier|extern
name|int
name|strlen
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NameLen
parameter_list|(
name|name
parameter_list|)
value|strlen( name )
end_define

begin_comment
comment|/* names are always NUL-terminated */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNK
end_ifdef

begin_enum
specifier|static
enum|enum
block|{
name|maybe
block|,
name|no
block|,
name|yes
block|}
name|state
init|=
name|maybe
enum|;
end_enum

begin_comment
comment|/* does _getdents() work? */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
specifier|static
name|void
name|sig_catch
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
comment|/* must be SIGSYS */
block|{
name|state
operator|=
name|no
expr_stmt|;
comment|/* attempted _getdents() faulted */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|getdents
parameter_list|(
name|fildes
parameter_list|,
name|buf
parameter_list|,
name|nbyte
parameter_list|)
comment|/* returns # bytes read; 					   0 on EOF, -1 on error */
name|int
name|fildes
decl_stmt|;
comment|/* directory file descriptor */
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* where to put the (struct dirent)s */
name|unsigned
name|nbyte
decl_stmt|;
comment|/* size of buf[] */
block|{
name|int
name|serrno
decl_stmt|;
comment|/* entry errno */
name|off_t
name|offset
decl_stmt|;
comment|/* initial directory file offset */
name|struct
name|stat
name|statb
decl_stmt|;
comment|/* fstat() info */
union|union
block|{
name|char
name|dblk
index|[
name|DIRBLKSIZ
index|]
decl_stmt|;
comment|/* directory file block buffer */
name|struct
name|direct
name|dummy
decl_stmt|;
comment|/* just for alignment */
block|}
name|u
union|;
comment|/* (avoids having to malloc()) */
specifier|register
name|struct
name|direct
modifier|*
name|dp
decl_stmt|;
comment|/* -> u.dblk[.] */
specifier|register
name|struct
name|dirent
modifier|*
name|bp
decl_stmt|;
comment|/* -> buf[.] */
ifdef|#
directive|ifdef
name|UNK
switch|switch
condition|(
name|state
condition|)
block|{
name|void
function_decl|(
modifier|*
name|shdlr
function_decl|)
parameter_list|()
function_decl|;
comment|/* entry SIGSYS handler */
specifier|register
name|int
name|retval
decl_stmt|;
comment|/* return from _getdents() if any */
case|case
name|yes
case|:
comment|/* _getdents() is known to work */
return|return
name|_getdents
argument_list|(
name|fildes
argument_list|,
name|buf
argument_list|,
name|nbyte
argument_list|)
return|;
case|case
name|maybe
case|:
comment|/* first time only */
name|shdlr
operator|=
name|signal
argument_list|(
name|SIGSYS
argument_list|,
name|sig_catch
argument_list|)
expr_stmt|;
name|retval
operator|=
name|_getdents
argument_list|(
name|fildes
argument_list|,
name|buf
argument_list|,
name|nbyte
argument_list|)
expr_stmt|;
comment|/* try it */
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGSYS
argument_list|,
name|shdlr
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|==
name|maybe
condition|)
comment|/* SIGSYS did not occur */
block|{
name|state
operator|=
name|yes
expr_stmt|;
comment|/* so _getdents() must have worked */
return|return
name|retval
return|;
block|}
comment|/* else fall through into emulation */
comment|/*	case no:	/* fall through into emulation */
block|}
endif|#
directive|endif
if|if
condition|(
name|buf
operator|==
name|NULL
ifdef|#
directive|ifdef
name|ATT_SPEC
operator|||
operator|(
name|unsigned
name|long
operator|)
name|buf
operator|%
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|!=
literal|0
comment|/* ugh */
endif|#
directive|endif
condition|)
block|{
name|errno
operator|=
name|EFAULT
expr_stmt|;
comment|/* invalid pointer */
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|fstat
argument_list|(
name|fildes
argument_list|,
operator|&
name|statb
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|-
literal|1
return|;
comment|/* errno set by fstat() */
if|if
condition|(
operator|!
name|S_ISDIR
argument_list|(
name|statb
operator|.
name|st_mode
argument_list|)
condition|)
block|{
name|errno
operator|=
name|ENOTDIR
expr_stmt|;
comment|/* not a directory */
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
operator|(
name|offset
operator|=
name|lseek
argument_list|(
name|fildes
argument_list|,
operator|(
name|off_t
operator|)
literal|0
argument_list|,
name|SEEK_CUR
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
comment|/* errno set by lseek() */
ifdef|#
directive|ifdef
name|BFS
comment|/* no telling what remote hosts do */
if|if
condition|(
operator|(
name|unsigned
name|long
operator|)
name|offset
operator|%
name|DIRBLKSIZ
operator|!=
literal|0
condition|)
block|{
name|errno
operator|=
name|ENOENT
expr_stmt|;
comment|/* file pointer probably misaligned */
return|return
operator|-
literal|1
return|;
block|}
endif|#
directive|endif
name|serrno
operator|=
name|errno
expr_stmt|;
comment|/* save entry errno */
for|for
control|(
name|bp
operator|=
operator|(
expr|struct
name|dirent
operator|*
operator|)
name|buf
init|;
name|bp
operator|==
operator|(
expr|struct
name|dirent
operator|*
operator|)
name|buf
condition|;
control|)
block|{
comment|/* convert next directory block */
name|int
name|size
decl_stmt|;
do|do
name|size
operator|=
name|GetBlock
argument_list|(
name|fildes
argument_list|,
name|u
operator|.
name|dblk
argument_list|,
name|DIRBLKSIZ
argument_list|)
expr_stmt|;
do|while
condition|(
name|size
operator|==
operator|-
literal|1
operator|&&
name|errno
operator|==
name|EINTR
condition|)
do|;
if|if
condition|(
name|size
operator|<=
literal|0
condition|)
return|return
name|size
return|;
comment|/* EOF or error (EBADF) */
for|for
control|(
name|dp
operator|=
operator|(
expr|struct
name|direct
operator|*
operator|)
name|u
operator|.
name|dblk
init|;
operator|(
name|char
operator|*
operator|)
name|dp
operator|<
operator|&
name|u
operator|.
name|dblk
index|[
name|size
index|]
condition|;
name|dp
operator|=
operator|(
expr|struct
name|direct
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
name|dp
operator|+
name|RecLen
argument_list|(
name|dp
argument_list|)
operator|)
control|)
block|{
ifndef|#
directive|ifndef
name|UFS
if|if
condition|(
name|dp
operator|->
name|d_reclen
operator|<=
literal|0
condition|)
block|{
name|errno
operator|=
name|EIO
expr_stmt|;
comment|/* corrupted directory */
return|return
operator|-
literal|1
return|;
block|}
endif|#
directive|endif
if|if
condition|(
name|dp
operator|->
name|d_fileno
operator|!=
literal|0
condition|)
block|{
comment|/* non-empty; copy to user buffer */
specifier|register
name|int
name|reclen
init|=
name|DIRENTSIZ
argument_list|(
name|NameLen
argument_list|(
name|dp
operator|->
name|d_name
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|char
operator|*
operator|)
name|bp
operator|+
name|reclen
operator|>
operator|&
name|buf
index|[
name|nbyte
index|]
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
comment|/* buf too small */
block|}
name|bp
operator|->
name|d_ino
operator|=
name|dp
operator|->
name|d_fileno
expr_stmt|;
name|bp
operator|->
name|d_off
operator|=
name|offset
operator|+
operator|(
operator|(
name|char
operator|*
operator|)
name|dp
operator|-
name|u
operator|.
name|dblk
operator|)
expr_stmt|;
name|bp
operator|->
name|d_reclen
operator|=
name|reclen
expr_stmt|;
operator|(
name|void
operator|)
name|strncpy
argument_list|(
name|bp
operator|->
name|d_name
argument_list|,
name|dp
operator|->
name|d_name
argument_list|,
ifdef|#
directive|ifdef
name|UFS
name|DIRSIZ
argument_list|)
expr_stmt|;
comment|/* be sure d_name is NULL-terminated */
name|bp
operator|->
name|d_name
index|[
name|DIRSIZ
index|]
operator|=
name|NULL
expr_stmt|;
else|#
directive|else
name|reclen
operator|-
name|DIRENTBASESIZ
block|)
empty_stmt|;
comment|/* adds NUL padding */
endif|#
directive|endif
name|bp
operator|=
operator|(
expr|struct
name|dirent
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
name|bp
operator|+
name|reclen
operator|)
expr_stmt|;
block|}
block|}
ifndef|#
directive|ifndef
name|BFS
comment|/* 4.2BSD screwed up; fixed in 4.3BSD */
if|if
condition|(
operator|(
name|char
operator|*
operator|)
name|dp
operator|>
operator|&
name|u
operator|.
name|dblk
index|[
name|size
index|]
condition|)
block|{
name|errno
operator|=
name|EIO
expr_stmt|;
comment|/* corrupted directory */
return|return
operator|-
literal|1
return|;
block|}
endif|#
directive|endif
block|}
end_function

begin_expr_stmt
name|errno
operator|=
name|serrno
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* restore entry errno */
end_comment

begin_return
return|return
operator|(
name|char
operator|*
operator|)
name|bp
operator|-
name|buf
return|;
end_return

begin_comment
comment|/* return # bytes read */
end_comment

begin_else
unit|}
else|#
directive|else
end_else

begin_macro
unit|int
name|_getdents_stub
argument_list|()
end_macro

begin_block
block|{}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

