begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stdc.h -- macros to make source compile on both ANSI C and K&R C    compilers. */
end_comment

begin_comment
comment|/* Copyright (C) 1993 Free Software Foundation, Inc.     This file is part of GNU Bash, the Bourne Again SHell.     Bash is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     Bash is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with Bash; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_RL_STDC_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_RL_STDC_H_
end_define

begin_comment
comment|/* Adapted from BSD /usr/include/sys/cdefs.h. */
end_comment

begin_comment
comment|/* A function can be defined using prototypes and compile on both ANSI C    and traditional C compilers with something like this: 	extern char *func __P((char *, char *, int)); */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__P
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|protos
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|()
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

begin_comment
comment|/* !_RL_STDC_H_ */
end_comment

end_unit

