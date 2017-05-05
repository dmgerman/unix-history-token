begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $OpenPAM: openpam_strlcmp.h 938 2017-04-30 21:34:42Z des $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENPAM_STRLCMP_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|OPENPAM_STRLCMP_H_INCLUDED
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRLCMP
end_ifndef

begin_comment
comment|/* like strcmp(3), but verifies that the entirety of s1 was matched */
end_comment

begin_function
specifier|static
name|int
name|strlcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
for|for
control|(
init|;
name|len
operator|&&
operator|*
name|s1
operator|&&
operator|*
name|s2
condition|;
operator|--
name|len
operator|,
operator|++
name|s1
operator|,
operator|++
name|s2
control|)
if|if
condition|(
operator|*
name|s1
operator|!=
operator|*
name|s2
condition|)
return|return
operator|(
operator|(
name|unsigned
name|char
operator|)
operator|*
name|s1
operator|-
operator|(
name|unsigned
name|char
operator|)
operator|*
name|s2
operator|)
return|;
return|return
operator|(
operator|(
name|unsigned
name|char
operator|)
operator|*
name|s1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

