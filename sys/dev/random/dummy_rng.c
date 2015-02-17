begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Arthur Mesh<arthurmesh@gmail.com>  * Copyright (c) 2013 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"opt_random.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/random.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<dev/random/randomdev.h>
end_include

begin_include
include|#
directive|include
file|<dev/random/random_adaptors.h>
end_include

begin_function
specifier|static
name|int
name|dummy_random_zero
parameter_list|(
name|void
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
specifier|static
name|void
name|dummy_random
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|void
name|dummy_random_init
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|RANDOM_DEBUG
name|printf
argument_list|(
literal|"random: %s\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|randomdev_init_reader
argument_list|(
name|dummy_random_read_phony
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* This is used only by the internal read_random(9) call, and then only  * if no entropy processor is loaded.  *  * Make a token effort to provide _some_ kind of output. No warranty of  * the quality of this output is made, mainly because its lousy.  *  * This is only used by the internal read_random(9) call when no other  * adaptor is active.  *  * It has external scope due to the way things work in  * randomdev_[de]init_reader() that the rest of the world doesn't need to  * know about.  *  * Caveat Emptor.  */
end_comment

begin_function
name|void
name|dummy_random_read_phony
parameter_list|(
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|u_int
name|count
parameter_list|)
block|{
comment|/* If no entropy device is loaded, don't spam the console with warnings */
name|u_long
name|randval
decl_stmt|;
name|size_t
name|size
decl_stmt|,
name|i
decl_stmt|;
comment|/* srandom() is called in kern/init_main.c:proc0_post() */
comment|/* Fill buf[] with random(9) output */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
name|i
operator|+=
sizeof|sizeof
argument_list|(
name|randval
argument_list|)
control|)
block|{
name|randval
operator|=
name|random
argument_list|()
expr_stmt|;
name|size
operator|=
name|MIN
argument_list|(
name|count
operator|-
name|i
argument_list|,
sizeof|sizeof
argument_list|(
name|randval
argument_list|)
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|buf
operator|+
name|i
argument_list|,
operator|&
name|randval
argument_list|,
operator|(
name|size_t
operator|)
name|size
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_decl_stmt
name|struct
name|random_adaptor
name|randomdev_dummy
init|=
block|{
operator|.
name|ra_ident
operator|=
literal|"Dummy"
block|,
operator|.
name|ra_priority
operator|=
literal|1
block|,
comment|/* Bottom priority, so goes to last position */
operator|.
name|ra_reseed
operator|=
name|dummy_random
block|,
operator|.
name|ra_seeded
operator|=
operator|(
name|random_adaptor_seeded_func_t
operator|*
operator|)
name|dummy_random_zero
block|,
operator|.
name|ra_read
operator|=
operator|(
name|random_adaptor_read_func_t
operator|*
operator|)
name|dummy_random_zero
block|,
operator|.
name|ra_write
operator|=
operator|(
name|random_adaptor_write_func_t
operator|*
operator|)
name|dummy_random_zero
block|,
operator|.
name|ra_init
operator|=
name|dummy_random_init
block|,
operator|.
name|ra_deinit
operator|=
name|dummy_random
block|, }
decl_stmt|;
end_decl_stmt

end_unit

