begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, 2000  * Intel Corporation.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *   *    This product includes software developed by Intel Corporation and  *    its contributors.  *   * 4. Neither the name of Intel Corporation or its contributors may be  *    used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY INTEL CORPORATION AND CONTRIBUTORS ``AS IS''  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL INTEL CORPORATION OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* // Accurate only for the past couple of centuries; // that will probably do. // // (#defines From FreeBSD 3.2 lib/libc/stdtime/tzfile.h) */
end_comment

begin_define
define|#
directive|define
name|isleap
parameter_list|(
name|y
parameter_list|)
value|(((y) % 4) == 0&& (((y) % 100) != 0 || ((y) % 400) == 0))
end_define

begin_define
define|#
directive|define
name|SECSPERHOUR
value|( 60*60 )
end_define

begin_define
define|#
directive|define
name|SECSPERDAY
value|(24 * SECSPERHOUR)
end_define

begin_function
name|time_t
name|time
parameter_list|(
name|time_t
modifier|*
name|tloc
parameter_list|)
block|{
return|return
literal|0
return|;
comment|/* XXX */
block|}
end_function

end_unit

