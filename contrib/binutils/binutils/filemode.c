begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* filemode.c -- make a string describing file modes    Copyright 1985, 1990, 1991, 1994, 1995, 1997    Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_escape
end_escape

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"bucomm.h"
end_include

begin_decl_stmt
specifier|static
name|char
name|ftypelet
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|setst
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* filemodestring - fill in string STR with an ls-style ASCII    representation of the st_mode field of file stats block STATP.    10 characters are stored in STR; no terminating null is added.    The characters stored in STR are:     0	File type.  'd' for directory, 'c' for character 	special, 'b' for block special, 'm' for multiplex, 	'l' for symbolic link, 's' for socket, 'p' for fifo, 	'-' for any other file type     1	'r' if the owner may read, '-' otherwise.     2	'w' if the owner may write, '-' otherwise.     3	'x' if the owner may execute, 's' if the file is 	set-user-id, '-' otherwise. 	'S' if the file is set-user-id, but the execute 	bit isn't set.     4	'r' if group members may read, '-' otherwise.     5	'w' if group members may write, '-' otherwise.     6	'x' if group members may execute, 's' if the file is 	set-group-id, '-' otherwise. 	'S' if it is set-group-id but not executable.     7	'r' if any user may read, '-' otherwise.     8	'w' if any user may write, '-' otherwise.     9	'x' if any user may execute, 't' if the file is "sticky" 	(will be retained in swap space after execution), '-' 	otherwise. 	'T' if the file is sticky but not executable. */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* This is not used; only mode_string is used.  */
end_comment

begin_endif
unit|void filemodestring (statp, str)      struct stat *statp;      char *str; {   mode_string ((unsigned long) statp->st_mode, str); }
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get definitions for the file permission bits.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRWXU
end_ifndef

begin_define
define|#
directive|define
name|S_IRWXU
value|0700
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IRUSR
value|0400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IWUSR
value|0200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IXUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IXUSR
value|0100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRWXG
end_ifndef

begin_define
define|#
directive|define
name|S_IRWXG
value|0070
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRGRP
end_ifndef

begin_define
define|#
directive|define
name|S_IRGRP
value|0040
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWGRP
end_ifndef

begin_define
define|#
directive|define
name|S_IWGRP
value|0020
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IXGRP
end_ifndef

begin_define
define|#
directive|define
name|S_IXGRP
value|0010
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRWXO
end_ifndef

begin_define
define|#
directive|define
name|S_IRWXO
value|0007
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IROTH
end_ifndef

begin_define
define|#
directive|define
name|S_IROTH
value|0004
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWOTH
end_ifndef

begin_define
define|#
directive|define
name|S_IWOTH
value|0002
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IXOTH
end_ifndef

begin_define
define|#
directive|define
name|S_IXOTH
value|0001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Like filemodestring, but only the relevant part of the `struct stat'    is given as an argument. */
end_comment

begin_function
name|void
name|mode_string
parameter_list|(
name|mode
parameter_list|,
name|str
parameter_list|)
name|unsigned
name|long
name|mode
decl_stmt|;
name|char
modifier|*
name|str
decl_stmt|;
block|{
name|str
index|[
literal|0
index|]
operator|=
name|ftypelet
argument_list|(
operator|(
name|unsigned
name|long
operator|)
name|mode
argument_list|)
expr_stmt|;
name|str
index|[
literal|1
index|]
operator|=
operator|(
name|mode
operator|&
name|S_IRUSR
operator|)
operator|!=
literal|0
condition|?
literal|'r'
else|:
literal|'-'
expr_stmt|;
name|str
index|[
literal|2
index|]
operator|=
operator|(
name|mode
operator|&
name|S_IWUSR
operator|)
operator|!=
literal|0
condition|?
literal|'w'
else|:
literal|'-'
expr_stmt|;
name|str
index|[
literal|3
index|]
operator|=
operator|(
name|mode
operator|&
name|S_IXUSR
operator|)
operator|!=
literal|0
condition|?
literal|'x'
else|:
literal|'-'
expr_stmt|;
name|str
index|[
literal|4
index|]
operator|=
operator|(
name|mode
operator|&
name|S_IRGRP
operator|)
operator|!=
literal|0
condition|?
literal|'r'
else|:
literal|'-'
expr_stmt|;
name|str
index|[
literal|5
index|]
operator|=
operator|(
name|mode
operator|&
name|S_IWGRP
operator|)
operator|!=
literal|0
condition|?
literal|'w'
else|:
literal|'-'
expr_stmt|;
name|str
index|[
literal|6
index|]
operator|=
operator|(
name|mode
operator|&
name|S_IXGRP
operator|)
operator|!=
literal|0
condition|?
literal|'x'
else|:
literal|'-'
expr_stmt|;
name|str
index|[
literal|7
index|]
operator|=
operator|(
name|mode
operator|&
name|S_IROTH
operator|)
operator|!=
literal|0
condition|?
literal|'r'
else|:
literal|'-'
expr_stmt|;
name|str
index|[
literal|8
index|]
operator|=
operator|(
name|mode
operator|&
name|S_IWOTH
operator|)
operator|!=
literal|0
condition|?
literal|'w'
else|:
literal|'-'
expr_stmt|;
name|str
index|[
literal|9
index|]
operator|=
operator|(
name|mode
operator|&
name|S_IXOTH
operator|)
operator|!=
literal|0
condition|?
literal|'x'
else|:
literal|'-'
expr_stmt|;
name|setst
argument_list|(
operator|(
name|unsigned
name|long
operator|)
name|mode
argument_list|,
name|str
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Return a character indicating the type of file described by    file mode BITS:    'd' for directories    'b' for block special files    'c' for character special files    'm' for multiplexor files    'l' for symbolic links    's' for sockets    'p' for fifos    '-' for any other file type. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFDIR
end_ifdef

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|i
parameter_list|)
value|(((i)& S_IFMT) == S_IFDIR)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (S_IFDIR) */
end_comment

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|i
parameter_list|)
value|(((i)& 0170000) == 040000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (S_IFDIR) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (S_ISDIR) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISBLK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFBLK
end_ifdef

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|i
parameter_list|)
value|(((i)& S_IFMT) == S_IFBLK)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (S_IFBLK) */
end_comment

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|i
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (S_IFBLK) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (S_ISBLK) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISCHR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFCHR
end_ifdef

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|i
parameter_list|)
value|(((i)& S_IFMT) == S_IFCHR)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (S_IFCHR) */
end_comment

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|i
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (S_IFCHR) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (S_ISCHR) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISFIFO
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFIFO
end_ifdef

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|i
parameter_list|)
value|(((i)& S_IFMT) == S_IFIFO)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (S_IFIFO) */
end_comment

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|i
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (S_IFIFO) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (S_ISFIFO) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISSOCK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFSOCK
end_ifdef

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|i
parameter_list|)
value|(((i)& S_IFMT) == S_IFSOCK)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (S_IFSOCK) */
end_comment

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|i
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (S_IFSOCK) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (S_ISSOCK) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISLNK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFLNK
end_ifdef

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|i
parameter_list|)
value|(((i)& S_IFMT) == S_IFLNK)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (S_IFLNK) */
end_comment

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|i
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (S_IFLNK) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (S_ISLNK) */
end_comment

begin_function
specifier|static
name|char
name|ftypelet
parameter_list|(
name|bits
parameter_list|)
name|unsigned
name|long
name|bits
decl_stmt|;
block|{
if|if
condition|(
name|S_ISDIR
argument_list|(
name|bits
argument_list|)
condition|)
return|return
literal|'d'
return|;
if|if
condition|(
name|S_ISLNK
argument_list|(
name|bits
argument_list|)
condition|)
return|return
literal|'l'
return|;
if|if
condition|(
name|S_ISBLK
argument_list|(
name|bits
argument_list|)
condition|)
return|return
literal|'b'
return|;
if|if
condition|(
name|S_ISCHR
argument_list|(
name|bits
argument_list|)
condition|)
return|return
literal|'c'
return|;
if|if
condition|(
name|S_ISSOCK
argument_list|(
name|bits
argument_list|)
condition|)
return|return
literal|'s'
return|;
if|if
condition|(
name|S_ISFIFO
argument_list|(
name|bits
argument_list|)
condition|)
return|return
literal|'p'
return|;
ifdef|#
directive|ifdef
name|S_IFMT
ifdef|#
directive|ifdef
name|S_IFMPC
if|if
condition|(
operator|(
name|bits
operator|&
name|S_IFMT
operator|)
operator|==
name|S_IFMPC
operator|||
operator|(
name|bits
operator|&
name|S_IFMT
operator|)
operator|==
name|S_IFMPB
condition|)
return|return
literal|'m'
return|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|S_IFNWK
if|if
condition|(
operator|(
name|bits
operator|&
name|S_IFMT
operator|)
operator|==
name|S_IFNWK
condition|)
return|return
literal|'n'
return|;
endif|#
directive|endif
endif|#
directive|endif
return|return
literal|'-'
return|;
block|}
end_function

begin_comment
comment|/* Set the 's' and 't' flags in file attributes string CHARS,    according to the file mode BITS. */
end_comment

begin_function
specifier|static
name|void
name|setst
parameter_list|(
name|bits
parameter_list|,
name|chars
parameter_list|)
name|unsigned
name|long
name|bits
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|char
modifier|*
name|chars
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|S_ISUID
if|if
condition|(
name|bits
operator|&
name|S_ISUID
condition|)
block|{
if|if
condition|(
name|chars
index|[
literal|3
index|]
operator|!=
literal|'x'
condition|)
comment|/* Set-uid, but not executable by owner. */
name|chars
index|[
literal|3
index|]
operator|=
literal|'S'
expr_stmt|;
else|else
name|chars
index|[
literal|3
index|]
operator|=
literal|'s'
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|S_ISGID
if|if
condition|(
name|bits
operator|&
name|S_ISGID
condition|)
block|{
if|if
condition|(
name|chars
index|[
literal|6
index|]
operator|!=
literal|'x'
condition|)
comment|/* Set-gid, but not executable by group. */
name|chars
index|[
literal|6
index|]
operator|=
literal|'S'
expr_stmt|;
else|else
name|chars
index|[
literal|6
index|]
operator|=
literal|'s'
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|S_ISVTX
if|if
condition|(
name|bits
operator|&
name|S_ISVTX
condition|)
block|{
if|if
condition|(
name|chars
index|[
literal|9
index|]
operator|!=
literal|'x'
condition|)
comment|/* Sticky, but not executable by others. */
name|chars
index|[
literal|9
index|]
operator|=
literal|'T'
expr_stmt|;
else|else
name|chars
index|[
literal|9
index|]
operator|=
literal|'t'
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function

end_unit

