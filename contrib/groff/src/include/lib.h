begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 1989-2000, 2001 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_extern
extern|extern
literal|"C"
block|{
ifndef|#
directive|ifndef
name|HAVE_STRERROR
name|char
modifier|*
name|strerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
specifier|const
name|char
modifier|*
name|i_to_a
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|if_to_a
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
end_extern

begin_comment
comment|/* stdio.h on IRIX, OSF/1, and UWIN includes getopt.h */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|__sgi
argument_list|)
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|__osf__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__alpha
argument_list|)
operator|)
expr|\
operator|||
name|defined
argument_list|(
name|_UWIN
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<groff-getopt.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|strsave
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_prime
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRINGS_H
end_ifdef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|FILE
modifier|*
name|xtmpfile
parameter_list|(
name|char
modifier|*
modifier|*
name|namep
init|=
literal|0
parameter_list|,
name|char
modifier|*
name|postfix
init|=
literal|0
parameter_list|,
name|int
name|do_unlink
init|=
literal|1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xtmptemplate
parameter_list|(
name|char
modifier|*
name|extension
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_POPEN
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
name|FILE
modifier|*
name|popen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_DECLARATION_POPEN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_PCLOSE
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
name|int
name|pclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_DECLARATION_PCLOSE */
end_comment

begin_function_decl
name|size_t
name|file_name_max
parameter_list|(
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|interpret_lf_args
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|illegal_char_table
index|[]
decl_stmt|;
end_decl_stmt

begin_function
specifier|inline
name|int
name|illegal_input_char
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|c
operator|>=
literal|0
operator|&&
name|illegal_char_table
index|[
name|c
index|]
return|;
block|}
end_function

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|sinix
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__sinix__
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRNCASECMP
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_STRNCASECMP
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
comment|// SunOS's string.h fails to declare this.
name|int
name|strncasecmp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_DECLARATION_STRNCASECMP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STRNCASECMP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_AIX&& !sinix&& !__sinix__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRCASECMP
end_ifndef

begin_define
define|#
directive|define
name|strcasecmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strcmp((a),(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRNCASECMP
end_ifndef

begin_define
define|#
directive|define
name|strncasecmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|strncmp((a),(b),(c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CC_LIMITS_H
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_CC_LIMITS_H */
end_comment

begin_define
define|#
directive|define
name|INT_MAX
value|2147483647
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_CC_LIMITS_H */
end_comment

begin_comment
comment|/* It's not safe to rely on people getting INT_MIN right (ie signed). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INT_MIN
end_ifdef

begin_undef
undef|#
directive|undef
name|INT_MIN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CFRONT_ANSI_BUG
end_ifdef

begin_comment
comment|/* This works around a bug in cfront 2.0 used with ANSI C compilers. */
end_comment

begin_define
define|#
directive|define
name|INT_MIN
value|((long)(-INT_MAX-1))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not CFRONT_ANSI_BUG */
end_comment

begin_define
define|#
directive|define
name|INT_MIN
value|(-INT_MAX-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not CFRONT_ANSI_BUG */
end_comment

begin_comment
comment|/* Maximum number of digits in the decimal representation of an int (not including the -). */
end_comment

begin_define
define|#
directive|define
name|INT_DIGITS
value|10
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PI
end_ifdef

begin_undef
undef|#
directive|undef
name|PI
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|const
name|double
name|PI
init|=
literal|3.14159265358979323846
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ad_delete deletes an array of objects with destructors; a_delete deletes an array of objects without destructors */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ARRAY_DELETE_NEEDS_SIZE
end_ifdef

begin_comment
comment|/* for 2.0 systems */
end_comment

begin_define
define|#
directive|define
name|ad_delete
parameter_list|(
name|size
parameter_list|)
value|delete [size]
end_define

begin_define
define|#
directive|define
name|a_delete
value|delete
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not ARRAY_DELETE_NEEDS_SIZE */
end_comment

begin_comment
comment|/* for ARM systems */
end_comment

begin_define
define|#
directive|define
name|ad_delete
parameter_list|(
name|size
parameter_list|)
value|delete []
end_define

begin_define
define|#
directive|define
name|a_delete
value|delete []
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not ARRAY_DELETE_NEEDS_SIZE */
end_comment

end_unit

