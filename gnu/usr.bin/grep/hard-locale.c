begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* hard-locale.c -- Determine whether a locale is hard.    Copyright 1997, 1998, 1999 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ALLOCA_H
end_ifdef

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|alloca
end_pragma

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_function_decl
name|char
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_LOCALE_H
end_if

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STRING_H
end_if

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
comment|/* Return nonzero if the current CATEGORY locale is hard, i.e. if you    can't get away with assuming traditional C or POSIX behavior.  */
end_comment

begin_function
name|int
name|hard_locale
parameter_list|(
name|int
name|category
parameter_list|)
block|{
if|#
directive|if
operator|!
name|HAVE_SETLOCALE
return|return
literal|0
return|;
else|#
directive|else
name|int
name|hard
init|=
literal|1
decl_stmt|;
name|char
specifier|const
modifier|*
name|p
init|=
name|setlocale
argument_list|(
name|category
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|p
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
operator|(
name|defined
name|__GLIBC__
operator|&&
name|__GLIBC__
operator|>=
literal|2
operator|)
if|if
condition|(
name|strcmp
argument_list|(
name|p
argument_list|,
literal|"C"
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|p
argument_list|,
literal|"POSIX"
argument_list|)
operator|==
literal|0
condition|)
name|hard
operator|=
literal|0
expr_stmt|;
else|#
directive|else
name|char
modifier|*
name|locale
init|=
name|alloca
argument_list|(
name|strlen
argument_list|(
name|p
argument_list|)
operator|+
literal|1
argument_list|)
decl_stmt|;
name|strcpy
argument_list|(
name|locale
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|/* Temporarily set the locale to the "C" and "POSIX" locales to 	 find their names, so that we can determine whether one or the 	 other is the caller's locale.  */
if|if
condition|(
operator|(
operator|(
name|p
operator|=
name|setlocale
argument_list|(
name|category
argument_list|,
literal|"C"
argument_list|)
operator|)
operator|&&
name|strcmp
argument_list|(
name|p
argument_list|,
name|locale
argument_list|)
operator|==
literal|0
operator|)
operator|||
operator|(
operator|(
name|p
operator|=
name|setlocale
argument_list|(
name|category
argument_list|,
literal|"POSIX"
argument_list|)
operator|)
operator|&&
name|strcmp
argument_list|(
name|p
argument_list|,
name|locale
argument_list|)
operator|==
literal|0
operator|)
condition|)
name|hard
operator|=
literal|0
expr_stmt|;
comment|/* Restore the caller's locale.  */
name|setlocale
argument_list|(
name|category
argument_list|,
name|locale
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
return|return
name|hard
return|;
endif|#
directive|endif
block|}
end_function

end_unit

