begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Nathan Whitehorn  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"partedit.h"
end_include

begin_function
specifier|const
name|char
modifier|*
name|default_scheme
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * Our loader can parse GPT, so pick that as the default for lack of 	 * a better idea. 	 */
return|return
operator|(
literal|"GPT"
operator|)
return|;
block|}
end_function

begin_function
name|int
name|is_scheme_bootable
parameter_list|(
specifier|const
name|char
modifier|*
name|part_type
parameter_list|)
block|{
comment|/* 	 * We don't know anything about this platform, so don't irritate the 	 * user by claiming the chosen partition scheme isn't bootable. 	 */
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/* No clue => no boot partition, bootcode, or partcode */
end_comment

begin_function
name|size_t
name|bootpart_size
parameter_list|(
specifier|const
name|char
modifier|*
name|part_type
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|bootpart_type
parameter_list|(
specifier|const
name|char
modifier|*
name|scheme
parameter_list|)
block|{
return|return
operator|(
literal|"freebsd-boot"
operator|)
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|bootcode_path
parameter_list|(
specifier|const
name|char
modifier|*
name|part_type
parameter_list|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|partcode_path
parameter_list|(
specifier|const
name|char
modifier|*
name|part_type
parameter_list|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

end_unit

