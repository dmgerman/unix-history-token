begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * gawkmisc.c --- miscellanious gawk routines that are OS specific.  */
end_comment

begin_comment
comment|/*   * Copyright (C) 1986, 1988, 1989, 1991-2000 the Free Software Foundation, Inc.  *   * This file is part of GAWK, the GNU implementation of the  * AWK Programming Language.  *   * GAWK is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *   * GAWK is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA  */
end_comment

begin_include
include|#
directive|include
file|"awk.h"
end_include

begin_comment
comment|/* some old compilers don't grok #elif. sigh */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|OS2
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_include
include|#
directive|include
file|"gawkmisc.pc"
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_include
include|#
directive|include
file|"vms/gawkmisc.vms"
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|atarist
argument_list|)
end_if

begin_include
include|#
directive|include
file|"atari/gawkmisc.atr"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"posix/gawkmisc.c"
end_include

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

begin_comment
comment|/* xmalloc --- provide this so that other GNU library routines work */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_typedef
typedef|typedef
name|void
modifier|*
name|pointer
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|pointer
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|pointer
name|xmalloc
name|P
argument_list|(
operator|(
name|size_t
name|bytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get rid of gcc warning */
end_comment

begin_function
name|pointer
name|xmalloc
parameter_list|(
name|bytes
parameter_list|)
name|size_t
name|bytes
decl_stmt|;
block|{
name|pointer
name|p
decl_stmt|;
name|emalloc
argument_list|(
name|p
argument_list|,
name|pointer
argument_list|,
name|bytes
argument_list|,
literal|"xmalloc"
argument_list|)
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

end_unit

