begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* memory_.h */
end_comment

begin_comment
comment|/* Generic substitute for Unix memory.h */
end_comment

begin_comment
comment|/****** Note: the System V bcmp routine only returns zero or non-zero, ******/
end_comment

begin_comment
comment|/****** unlike memcmp which returns -1, 0, or 1. ******/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__TURBOC__
end_ifdef

begin_comment
comment|/* The Turbo C implementation of memset swaps the arguments and calls */
end_comment

begin_comment
comment|/* the non-standard routine setmem.  We may as well do it in advance. */
end_comment

begin_undef
undef|#
directive|undef
name|memset
end_undef

begin_comment
comment|/* just in case */
end_comment

begin_include
include|#
directive|include
file|<mem.h>
end_include

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|dest
parameter_list|,
name|chr
parameter_list|,
name|cnt
parameter_list|)
value|setmem(dest,cnt,chr)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|memcpy
argument_list|()
decl_stmt|,
modifier|*
name|memset
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|memcmp
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD4_2
argument_list|)
operator|||
name|defined
argument_list|(
name|UTEK
argument_list|)
end_if

begin_extern
extern|extern bcopy(
end_extern

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|bcmp
argument_list|()
operator|,
name|bzero
argument_list|()
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|len
parameter_list|)
value|bcopy(src,dest,len)
end_define

begin_define
define|#
directive|define
name|memcmp
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|len
parameter_list|)
value|bcmp(b1,b2,len)
end_define

begin_comment
comment|/* Define our own version of memset */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|UTEK
argument_list|)
end_if

begin_function
specifier|static
name|void
name|memset
parameter_list|(
name|void
modifier|*
name|dest
parameter_list|,
specifier|register
name|char
name|ch
parameter_list|,
name|unsigned
name|len
parameter_list|)
else|#
directive|else
function|static void memset
parameter_list|(
name|dest
parameter_list|,
name|ch
parameter_list|,
name|len
parameter_list|)
name|char
modifier|*
name|dest
decl_stmt|;
specifier|register
name|char
name|ch
decl_stmt|;
name|unsigned
name|len
decl_stmt|;
endif|#
directive|endif
comment|/* (!)__STDC__, ... */
block|{
if|if
condition|(
name|ch
operator|==
literal|0
condition|)
name|bzero
argument_list|(
name|dest
argument_list|,
name|len
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|len
operator|>
literal|0
condition|)
block|{
specifier|register
name|char
modifier|*
name|p
init|=
operator|(
name|char
operator|*
operator|)
name|dest
decl_stmt|;
specifier|register
name|unsigned
name|count
init|=
name|len
decl_stmt|;
do|do
block|{
operator|*
name|p
operator|++
operator|=
name|ch
expr_stmt|;
block|}
do|while
condition|(
operator|--
name|count
condition|)
do|;
block|}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !BSD4_2 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
operator|||
name|defined
argument_list|(
name|_HPUX_SOURCE
argument_list|)
operator|||
name|defined
argument_list|(
name|__WATCOMC__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_SOURCE, ... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !BSD4_2, ... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !VMS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__MSDOS__ */
end_comment

begin_comment
comment|/* memswab is not a standard routine.  It swaps bytes in 16-bit words. */
end_comment

begin_comment
comment|/* We thought we would come out ahead by using the Watcom C `swab' */
end_comment

begin_comment
comment|/* library routine, but it's slower than the C routine in gsmisc.c! */
end_comment

begin_comment
comment|/* Note that the arguments are declared char *, */
end_comment

begin_comment
comment|/* but the implementation may assume they are int-aligned. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__PROTOTYPES__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|memswab
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|char
modifier|*
name|dest
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|memswab
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* memflip8x8 transposes an 8 x 8 block of bits. */
end_comment

begin_comment
comment|/* line_size is the raster of the input data; */
end_comment

begin_comment
comment|/* dist is the distance between output bytes. */
end_comment

begin_comment
comment|/* Dot matrix printers need this.  The C code is in gsmisc.c. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__PROTOTYPES__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|memflip8x8
parameter_list|(
specifier|const
name|byte
modifier|*
name|inp
parameter_list|,
name|int
name|line_size
parameter_list|,
name|byte
modifier|*
name|outp
parameter_list|,
name|int
name|dist
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|memflip8x8
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

