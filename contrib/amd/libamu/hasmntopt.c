begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-1999 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without n * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: hasmntopt.c,v 1.2 1999/01/10 21:54:37 ezk Exp $  *  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|MNTMAXSTR
end_ifndef

begin_define
define|#
directive|define
name|MNTMAXSTR
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTMAXSTR */
end_comment

begin_comment
comment|/*  * Some systems don't provide these to the user,  * but amd needs them, so...  *  * From: Piete Brooks<pb@cl.cam.ac.uk>  */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|nextmntopt
parameter_list|(
name|char
modifier|*
modifier|*
name|p
parameter_list|)
block|{
name|char
modifier|*
name|cp
init|=
operator|*
name|p
decl_stmt|;
name|char
modifier|*
name|rp
decl_stmt|;
comment|/*    * Skip past white space    */
while|while
condition|(
operator|*
name|cp
operator|&&
name|isspace
argument_list|(
operator|*
name|cp
argument_list|)
condition|)
name|cp
operator|++
expr_stmt|;
comment|/*    * Word starts here    */
name|rp
operator|=
name|cp
expr_stmt|;
comment|/*    * Scan to send of string or separator    */
while|while
condition|(
operator|*
name|cp
operator|&&
operator|*
name|cp
operator|!=
literal|','
condition|)
name|cp
operator|++
expr_stmt|;
comment|/*    * If separator found the overwrite with null char.    */
if|if
condition|(
operator|*
name|cp
condition|)
block|{
operator|*
name|cp
operator|=
literal|'\0'
expr_stmt|;
name|cp
operator|++
expr_stmt|;
block|}
comment|/*    * Return value for next call    */
operator|*
name|p
operator|=
name|cp
expr_stmt|;
return|return
name|rp
return|;
block|}
end_function

begin_comment
comment|/*  * replacement for hasmntopt if the system does not have it.  */
end_comment

begin_function
name|char
modifier|*
name|hasmntopt
parameter_list|(
name|mntent_t
modifier|*
name|mnt
parameter_list|,
name|char
modifier|*
name|opt
parameter_list|)
block|{
name|char
name|t
index|[
name|MNTMAXSTR
index|]
decl_stmt|;
name|char
modifier|*
name|f
decl_stmt|;
name|char
modifier|*
name|o
init|=
name|t
decl_stmt|;
name|int
name|l
init|=
name|strlen
argument_list|(
name|opt
argument_list|)
decl_stmt|;
name|strcpy
argument_list|(
name|t
argument_list|,
name|mnt
operator|->
name|mnt_opts
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
operator|(
name|f
operator|=
name|nextmntopt
argument_list|(
operator|&
name|o
argument_list|)
operator|)
condition|)
if|if
condition|(
name|NSTREQ
argument_list|(
name|opt
argument_list|,
name|f
argument_list|,
name|l
argument_list|)
condition|)
return|return
name|f
operator|-
name|t
operator|+
name|mnt
operator|->
name|mnt_opts
return|;
return|return
literal|0
return|;
block|}
end_function

end_unit

