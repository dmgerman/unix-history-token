begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/random.c - thread safe random generator, which is reasonably secure.  *   * Copyright (c) 2007, NLnet Labs. All rights reserved.  *   * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  * Thread safe random functions. Similar to arc4random() with an explicit  * initialisation routine.  *  * The code in this file is based on arc4random from  * openssh-4.0p1/openbsd-compat/bsd-arc4random.c  * That code is also BSD licensed. Here is their statement:  *  * Copyright (c) 1996, David Mazieres<dm@uun.org>  * Copyright (c) 2008, Damien Miller<djm@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"util/random.h"
end_include

begin_include
include|#
directive|include
file|"util/log.h"
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NSS
end_ifdef

begin_comment
comment|/* nspr4 */
end_comment

begin_include
include|#
directive|include
file|"prerror.h"
end_include

begin_comment
comment|/* nss3 */
end_comment

begin_include
include|#
directive|include
file|"secport.h"
end_include

begin_include
include|#
directive|include
file|"pk11pub.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**   * Max random value.  Similar to RAND_MAX, but more portable  * (mingw uses only 15 bits random).  */
end_comment

begin_define
define|#
directive|define
name|MAX_VALUE
value|0x7fffffff
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_NSS
end_ifndef

begin_decl_stmt
name|void
name|ub_systemseed
argument_list|(
name|unsigned
name|int
name|ATTR_UNUSED
argument_list|(
name|seed
argument_list|)
argument_list|)
block|{
comment|/* arc4random_uniform does not need seeds, it gets kernel entropy */
block|}
end_decl_stmt

begin_decl_stmt
name|struct
name|ub_randstate
modifier|*
name|ub_initstate
argument_list|(
name|unsigned
name|int
name|ATTR_UNUSED
argument_list|(
name|seed
argument_list|)
argument_list|,
expr|struct
name|ub_randstate
operator|*
name|ATTR_UNUSED
argument_list|(
name|from
argument_list|)
argument_list|)
block|{
name|struct
name|ub_randstate
modifier|*
name|s
init|=
operator|(
expr|struct
name|ub_randstate
operator|*
operator|)
name|malloc
argument_list|(
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|s
condition|)
block|{
name|log_err
argument_list|(
literal|"malloc failure in random init"
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
return|return
name|s
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|long
name|int
name|ub_random
argument_list|(
expr|struct
name|ub_randstate
operator|*
name|ATTR_UNUSED
argument_list|(
name|s
argument_list|)
argument_list|)
block|{
comment|/* This relies on MAX_VALUE being 0x7fffffff. */
return|return
operator|(
name|long
operator|)
name|arc4random
argument_list|()
operator|&
name|MAX_VALUE
return|;
block|}
end_decl_stmt

begin_function
name|long
name|int
name|ub_random_max
parameter_list|(
name|struct
name|ub_randstate
modifier|*
name|state
parameter_list|,
name|long
name|int
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|state
expr_stmt|;
comment|/* on OpenBSD, this does not need _seed(), or _stir() calls */
return|return
operator|(
name|long
operator|)
name|arc4random_uniform
argument_list|(
operator|(
name|uint32_t
operator|)
name|x
argument_list|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not much to remember for NSS since we use its pk11_random, placeholder */
end_comment

begin_struct
struct|struct
name|ub_randstate
block|{
name|int
name|ready
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|ub_systemseed
argument_list|(
name|unsigned
name|int
name|ATTR_UNUSED
argument_list|(
name|seed
argument_list|)
argument_list|)
block|{ }
end_decl_stmt

begin_decl_stmt
name|struct
name|ub_randstate
modifier|*
name|ub_initstate
argument_list|(
name|unsigned
name|int
name|ATTR_UNUSED
argument_list|(
name|seed
argument_list|)
argument_list|,
expr|struct
name|ub_randstate
operator|*
name|ATTR_UNUSED
argument_list|(
name|from
argument_list|)
argument_list|)
block|{
name|struct
name|ub_randstate
modifier|*
name|s
init|=
operator|(
expr|struct
name|ub_randstate
operator|*
operator|)
name|calloc
argument_list|(
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|s
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|s
condition|)
block|{
name|log_err
argument_list|(
literal|"malloc failure in random init"
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
return|return
name|s
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|long
name|int
name|ub_random
argument_list|(
expr|struct
name|ub_randstate
operator|*
name|ATTR_UNUSED
argument_list|(
name|state
argument_list|)
argument_list|)
block|{
name|long
name|int
name|x
decl_stmt|;
comment|/* random 31 bit value. */
name|SECStatus
name|s
init|=
name|PK11_GenerateRandom
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
operator|&
name|x
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
name|x
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|s
operator|!=
name|SECSuccess
condition|)
block|{
name|log_err
argument_list|(
literal|"PK11_GenerateRandom error: %s"
argument_list|,
name|PORT_ErrorToString
argument_list|(
name|PORT_GetError
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|x
operator|&
name|MAX_VALUE
return|;
block|}
end_decl_stmt

begin_function
name|long
name|int
name|ub_random_max
parameter_list|(
name|struct
name|ub_randstate
modifier|*
name|state
parameter_list|,
name|long
name|int
name|x
parameter_list|)
block|{
comment|/* make sure we fetch in a range that is divisible by x. ignore 	 * values from d .. MAX_VALUE, instead draw a new number */
name|long
name|int
name|d
init|=
name|MAX_VALUE
operator|-
operator|(
name|MAX_VALUE
operator|%
name|x
operator|)
decl_stmt|;
comment|/* d is divisible by x */
name|long
name|int
name|v
init|=
name|ub_random
argument_list|(
name|state
argument_list|)
decl_stmt|;
while|while
condition|(
name|d
operator|<=
name|v
condition|)
name|v
operator|=
name|ub_random
argument_list|(
name|state
argument_list|)
expr_stmt|;
return|return
operator|(
name|v
operator|%
name|x
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NSS */
end_comment

begin_function
name|void
name|ub_randfree
parameter_list|(
name|struct
name|ub_randstate
modifier|*
name|s
parameter_list|)
block|{
if|if
condition|(
name|s
condition|)
name|free
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|/* user app must do RAND_cleanup(); */
block|}
end_function

end_unit

