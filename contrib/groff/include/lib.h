begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_extern
extern|extern
literal|"C"
block|{
ifndef|#
directive|ifndef
name|strerror
name|char
modifier|*
name|strerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|__BORLANDC__
specifier|const
name|char
modifier|*
name|itoa
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|iftoa
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* __BORLANDC__ */
block|}
end_extern

begin_ifdef
ifdef|#
directive|ifdef
name|STDLIB_H_DECLARES_GETOPT
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not STDLIB_H_DECLARES_GETOPT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNISTD_H_DECLARES_GETOPT
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not UNISTD_H_DECLARES_GETOPT */
end_comment

begin_extern
extern|extern
literal|"C"
block|{
name|int
name|getopt
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
specifier|const
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
comment|/* not UNISTD_H_DECLARES_GETOPT */
end_comment

begin_extern
extern|extern
literal|"C"
block|{
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
specifier|extern
name|int
name|optind
decl_stmt|;
specifier|extern
name|int
name|opterr
decl_stmt|;
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not STDLIB_H_DECLARES_GETOPT */
end_comment

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

begin_function_decl
name|FILE
modifier|*
name|xtmpfile
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|STDIO_H_DECLARES_POPEN
end_ifndef

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
comment|/* not STDIO_H_DECLARES_POPEN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STDIO_H_DECLARES_PCLOSE
end_ifndef

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
comment|/* not STDIO_H_DECLARES_PCLOSE */
end_comment

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

