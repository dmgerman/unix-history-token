begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Buffer primitives for comparison operations.     Copyright (C) 1993, 1995, 1998, 2001, 2002 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SA_RESTART
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SA_INTERRUPT
end_ifdef

begin_comment
comment|/* e.g. SunOS 4.1.x */
end_comment

begin_define
define|#
directive|define
name|SA_RESTART
value|SA_INTERRUPT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SA_RESTART
value|0
end_define

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
name|HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_INTTYPES_H
end_if

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"cmpbuf.h"
end_include

begin_comment
comment|/* Determine whether an integer type is signed, and its bounds.    This code assumes two's (or one's!) complement with no holes.  */
end_comment

begin_comment
comment|/* The extra casts work around common compiler bugs,    e.g. Cray C 5.0.3.0 when t == time_t.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_SIGNED
end_ifndef

begin_define
define|#
directive|define
name|TYPE_SIGNED
parameter_list|(
name|t
parameter_list|)
value|(! ((t) 0< (t) -1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_MINIMUM
end_ifndef

begin_define
define|#
directive|define
name|TYPE_MINIMUM
parameter_list|(
name|t
parameter_list|)
value|((t) (TYPE_SIGNED (t) \ 			       ? ~ (t) 0<< (sizeof (t) * CHAR_BIT - 1) \ 			       : (t) 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_MAXIMUM
end_ifndef

begin_define
define|#
directive|define
name|TYPE_MAXIMUM
parameter_list|(
name|t
parameter_list|)
value|((t) (~ (t) 0 - TYPE_MINIMUM (t)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTRDIFF_MAX
end_ifndef

begin_define
define|#
directive|define
name|PTRDIFF_MAX
value|TYPE_MAXIMUM (ptrdiff_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_MAX
end_ifndef

begin_define
define|#
directive|define
name|SIZE_MAX
value|TYPE_MAXIMUM (size_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SSIZE_MAX
end_ifndef

begin_define
define|#
directive|define
name|SSIZE_MAX
value|TYPE_MAXIMUM (ssize_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|MIN
end_undef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)<= (b) ? (a) : (b))
end_define

begin_comment
comment|/* Read NBYTES bytes from descriptor FD into BUF.    NBYTES must not be SIZE_MAX.    Return the number of characters successfully read.    On error, return SIZE_MAX, setting errno.    The number returned is always NBYTES unless end-of-file or error.  */
end_comment

begin_function
name|size_t
name|block_read
parameter_list|(
name|int
name|fd
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|nbytes
parameter_list|)
block|{
name|char
modifier|*
name|bp
init|=
name|buf
decl_stmt|;
name|char
specifier|const
modifier|*
name|buflim
init|=
name|buf
operator|+
name|nbytes
decl_stmt|;
name|size_t
name|readlim
init|=
name|SSIZE_MAX
decl_stmt|;
do|do
block|{
name|size_t
name|bytes_to_read
init|=
name|MIN
argument_list|(
name|buflim
operator|-
name|bp
argument_list|,
name|readlim
argument_list|)
decl_stmt|;
name|ssize_t
name|nread
init|=
name|read
argument_list|(
name|fd
argument_list|,
name|bp
argument_list|,
name|bytes_to_read
argument_list|)
decl_stmt|;
if|if
condition|(
name|nread
operator|<=
literal|0
condition|)
block|{
if|if
condition|(
name|nread
operator|==
literal|0
condition|)
break|break;
comment|/* Accommodate Tru64 5.1, which can't read more than INT_MAX 	     bytes at a time.  They call that a 64-bit OS?  */
if|if
condition|(
name|errno
operator|==
name|EINVAL
operator|&&
name|INT_MAX
operator|<
name|bytes_to_read
condition|)
block|{
name|readlim
operator|=
name|INT_MAX
expr_stmt|;
continue|continue;
block|}
comment|/* This is needed for programs that have signal handlers on 	     older hosts without SA_RESTART.  It also accommodates 	     ancient AIX hosts that set errno to EINTR after uncaught 	     SIGCONT.  See<news:1r77ojINN85n@ftp.UU.NET> 	     (1993-04-22).  */
if|if
condition|(
operator|!
name|SA_RESTART
operator|&&
name|errno
operator|==
name|EINTR
condition|)
continue|continue;
return|return
name|SIZE_MAX
return|;
block|}
name|bp
operator|+=
name|nread
expr_stmt|;
block|}
do|while
condition|(
name|bp
operator|<
name|buflim
condition|)
do|;
return|return
name|bp
operator|-
name|buf
return|;
block|}
end_function

begin_comment
comment|/* Least common multiple of two buffer sizes A and B.  However, if    either A or B is zero, or if the multiple is greater than LCM_MAX,    return a reasonable buffer size.  */
end_comment

begin_function
name|size_t
name|buffer_lcm
parameter_list|(
name|size_t
name|a
parameter_list|,
name|size_t
name|b
parameter_list|,
name|size_t
name|lcm_max
parameter_list|)
block|{
name|size_t
name|lcm
decl_stmt|,
name|m
decl_stmt|,
name|n
decl_stmt|,
name|q
decl_stmt|,
name|r
decl_stmt|;
comment|/* Yield reasonable values if buffer sizes are zero.  */
if|if
condition|(
operator|!
name|a
condition|)
return|return
name|b
condition|?
name|b
else|:
literal|8
operator|*
literal|1024
return|;
if|if
condition|(
operator|!
name|b
condition|)
return|return
name|a
return|;
comment|/* n = gcd (a, b) */
for|for
control|(
name|m
operator|=
name|a
operator|,
name|n
operator|=
name|b
init|;
operator|(
name|r
operator|=
name|m
operator|%
name|n
operator|)
operator|!=
literal|0
condition|;
name|m
operator|=
name|n
operator|,
name|n
operator|=
name|r
control|)
continue|continue;
comment|/* Yield a if there is an overflow.  */
name|q
operator|=
name|a
operator|/
name|n
expr_stmt|;
name|lcm
operator|=
name|q
operator|*
name|b
expr_stmt|;
return|return
name|lcm
operator|<=
name|lcm_max
operator|&&
name|lcm
operator|/
name|b
operator|==
name|q
condition|?
name|lcm
else|:
name|a
return|;
block|}
end_function

end_unit

