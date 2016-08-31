begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2014 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from the Free Software Foundation, Inc. GNU utilities.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/libamu/strstr.c  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CONFIG_H */
end_comment

begin_include
include|#
directive|include
file|<am_defs.h>
end_include

begin_include
include|#
directive|include
file|<amu.h>
end_include

begin_comment
comment|/* strstr.c -- return the offset of one string within another    Copyright (C) 1989, 1990 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Author: 	Mike Rendell			Department of Computer Science 	michael@garfield.mun.edu	Memorial University of Newfoundland 	..!uunet!garfield!michael	St. John's, Nfld., Canada 	(709) 737-4550			A1C 5S7 */
end_comment

begin_comment
comment|/*  * Return the starting address of string S2 in S1;  * return 0 if it is not found.  */
end_comment

begin_function
name|char
modifier|*
name|strstr
parameter_list|(
name|char
modifier|*
name|s1
parameter_list|,
name|char
modifier|*
name|s2
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|char
modifier|*
name|p1
decl_stmt|;
name|char
modifier|*
name|p2
decl_stmt|;
name|char
modifier|*
name|s
init|=
name|s1
decl_stmt|;
for|for
control|(
name|p2
operator|=
name|s2
operator|,
name|i
operator|=
literal|0
init|;
operator|*
name|s
condition|;
name|p2
operator|=
name|s2
operator|,
name|i
operator|++
operator|,
name|s
operator|++
control|)
block|{
for|for
control|(
name|p1
operator|=
name|s
init|;
operator|*
name|p1
operator|&&
operator|*
name|p2
operator|&&
operator|*
name|p1
operator|==
operator|*
name|p2
condition|;
name|p1
operator|++
operator|,
name|p2
operator|++
control|)
empty_stmt|;
if|if
condition|(
operator|!
operator|*
name|p2
condition|)
break|break;
block|}
if|if
condition|(
operator|!
operator|*
name|p2
condition|)
return|return
name|s1
operator|+
name|i
return|;
return|return
literal|0
return|;
block|}
end_function

end_unit

