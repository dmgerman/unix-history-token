begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Libiberty realpath.  Like realpath, but more consistent behavior.    Based on gdb_realpath from GDB.     Copyright 2003 Free Software Foundation, Inc.     This file is part of the libiberty library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/*  @deftypefn Replacement {const char*} lrealpath (const char *@var{name})  Given a pointer to a string containing a pathname, returns a canonical version of the filename.  Symlinks will be resolved, and ``.'' and ``..'' components will be simplified.  The returned value will be allocated using @code{malloc}, or @code{NULL} will be returned on a memory allocation error.  @end deftypefn  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIMITS_H
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On GNU libc systems the declaration is only visible with _GNU_SOURCE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CANONICALIZE_FILE_NAME
argument_list|)
expr|\
operator|&&
name|defined
argument_list|(
name|NEED_DECLARATION_CANONICALIZE_FILE_NAME
argument_list|)
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|canonicalize_file_name
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_REALPATH
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PATH_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|REALPATH_LIMIT
value|PATH_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MAXPATHLEN
argument_list|)
end_if

begin_define
define|#
directive|define
name|REALPATH_LIMIT
value|MAXPATHLEN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|lrealpath
parameter_list|(
name|filename
parameter_list|)
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
block|{
comment|/* Method 1: The system has a compile time upper bound on a filename      path.  Use that and realpath() to canonicalize the name.  This is      the most common case.  Note that, if there isn't a compile time      upper bound, you want to avoid realpath() at all costs.  */
if|#
directive|if
name|defined
argument_list|(
name|REALPATH_LIMIT
argument_list|)
block|{
name|char
name|buf
index|[
name|REALPATH_LIMIT
index|]
decl_stmt|;
specifier|const
name|char
modifier|*
name|rp
init|=
name|realpath
argument_list|(
name|filename
argument_list|,
name|buf
argument_list|)
decl_stmt|;
if|if
condition|(
name|rp
operator|==
name|NULL
condition|)
name|rp
operator|=
name|filename
expr_stmt|;
return|return
name|strdup
argument_list|(
name|rp
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|/* REALPATH_LIMIT */
comment|/* Method 2: The host system (i.e., GNU) has the function      canonicalize_file_name() which malloc's a chunk of memory and      returns that, use that.  */
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CANONICALIZE_FILE_NAME
argument_list|)
block|{
name|char
modifier|*
name|rp
init|=
name|canonicalize_file_name
argument_list|(
name|filename
argument_list|)
decl_stmt|;
if|if
condition|(
name|rp
operator|==
name|NULL
condition|)
return|return
name|strdup
argument_list|(
name|filename
argument_list|)
return|;
else|else
return|return
name|rp
return|;
block|}
endif|#
directive|endif
comment|/* Method 3: Now we're getting desperate!  The system doesn't have a      compile time buffer size and no alternative function.  Query the      OS, using pathconf(), for the buffer limit.  Care is needed      though, some systems do not limit PATH_MAX (return -1 for      pathconf()) making it impossible to pass a correctly sized buffer      to realpath() (it could always overflow).  On those systems, we      skip this.  */
if|#
directive|if
name|defined
argument_list|(
name|HAVE_REALPATH
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_UNISTD_H
argument_list|)
block|{
comment|/* Find out the max path size.  */
name|long
name|path_max
init|=
name|pathconf
argument_list|(
literal|"/"
argument_list|,
name|_PC_PATH_MAX
argument_list|)
decl_stmt|;
if|if
condition|(
name|path_max
operator|>
literal|0
condition|)
block|{
comment|/* PATH_MAX is bounded.  */
name|char
modifier|*
name|buf
decl_stmt|,
modifier|*
name|rp
decl_stmt|,
modifier|*
name|ret
decl_stmt|;
name|buf
operator|=
name|malloc
argument_list|(
name|path_max
argument_list|)
expr_stmt|;
if|if
condition|(
name|buf
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|rp
operator|=
name|realpath
argument_list|(
name|filename
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|ret
operator|=
name|strdup
argument_list|(
name|rp
condition|?
name|rp
else|:
name|filename
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|buf
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
block|}
endif|#
directive|endif
comment|/* This system is a lost cause, just duplicate the filename.  */
return|return
name|strdup
argument_list|(
name|filename
argument_list|)
return|;
block|}
end_function

end_unit

