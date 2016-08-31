begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2014 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/libamu/memcmp.c  *  */
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
comment|/*  * compare two strings for up to length "len".  * this will normally be included on systems that either have no memcmp()  * and no bcmp(), or on systems that have both but the memcmp() is not 8-bit  * clean (such as SunOS 4.1.3).  *  * SunOS 4.x with gcc requires prototype of (const voidp, const voidp, size_t)  */
end_comment

begin_function
name|int
name|am_memcmp
parameter_list|(
specifier|const
name|voidp
name|s1
parameter_list|,
specifier|const
name|voidp
name|s2
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
name|unsigned
name|char
modifier|*
name|ucp1
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|s1
decl_stmt|;
name|unsigned
name|char
modifier|*
name|ucp2
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|s2
decl_stmt|;
name|int
name|i
init|=
name|len
decl_stmt|;
while|while
condition|(
name|i
operator|--
operator|>
literal|0
condition|)
if|if
condition|(
operator|*
name|ucp1
operator|++
operator|!=
operator|*
name|ucp2
operator|++
condition|)
return|return
operator|(
name|ucp1
index|[
operator|-
literal|1
index|]
operator|>=
name|ucp2
index|[
operator|-
literal|1
index|]
condition|?
literal|1
else|:
operator|-
literal|1
operator|)
return|;
return|return
literal|0
return|;
block|}
end_function

end_unit

