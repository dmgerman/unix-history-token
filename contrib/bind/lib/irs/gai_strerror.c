begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<port_before.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<port_after.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DO_PTHREADS
end_ifdef

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|gai_errlist
index|[]
init|=
block|{
literal|"no error"
block|,
literal|"address family not supported for name"
block|,
comment|/* EAI_ADDRFAMILY */
literal|"temporary failure"
block|,
comment|/* EAI_AGAIN */
literal|"invalid flags"
block|,
comment|/* EAI_BADFLAGS */
literal|"permanent failure"
block|,
comment|/* EAI_FAIL */
literal|"address family not supported"
block|,
comment|/* EAI_FAMILY */
literal|"memory failure"
block|,
comment|/* EAI_MEMORY */
literal|"no address"
block|,
comment|/* EAI_NODATA */
literal|"unknown name or service"
block|,
comment|/* EAI_NONAME */
literal|"service not supported for socktype"
block|,
comment|/* EAI_SERVICE */
literal|"socktype not supported"
block|,
comment|/* EAI_SOCKTYPE */
literal|"system failure"
block|,
comment|/* EAI_SYSTEM */
literal|"bad hints"
block|,
comment|/* EAI_BADHINTS */
literal|"bad protocol"
block|,
comment|/* EAI_PROTOCOL */
literal|"unknown error"
comment|/* Must be last. */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|gai_nerr
init|=
operator|(
sizeof|sizeof
argument_list|(
name|gai_errlist
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
operator|*
name|gai_errlist
argument_list|)
operator|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|EAI_BUFSIZE
value|128
end_define

begin_function
specifier|const
name|char
modifier|*
name|gai_strerror
parameter_list|(
name|int
name|ecode
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|DO_PTHREADS
specifier|static
name|char
name|buf
index|[
name|EAI_BUFSIZE
index|]
decl_stmt|;
else|#
directive|else
comment|/* DO_PTHREADS */
specifier|static
name|pthread_mutex_t
name|lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
specifier|static
name|pthread_key_t
name|key
decl_stmt|;
specifier|static
name|int
name|once
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|ecode
operator|>=
literal|0
operator|&&
name|ecode
operator|<
operator|(
name|gai_nerr
operator|-
literal|1
operator|)
condition|)
return|return
operator|(
name|gai_errlist
index|[
name|ecode
index|]
operator|)
return|;
ifdef|#
directive|ifdef
name|DO_PTHREADS
if|if
condition|(
operator|!
name|once
condition|)
block|{
name|pthread_mutex_lock
argument_list|(
operator|&
name|lock
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|once
operator|++
condition|)
name|pthread_key_create
argument_list|(
operator|&
name|key
argument_list|,
name|free
argument_list|)
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|lock
argument_list|)
expr_stmt|;
block|}
name|buf
operator|=
name|pthread_getspecific
argument_list|(
name|key
argument_list|)
expr_stmt|;
if|if
condition|(
name|buf
operator|==
name|NULL
condition|)
block|{
name|buf
operator|=
name|malloc
argument_list|(
name|EAI_BUFSIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|buf
operator|==
name|NULL
condition|)
return|return
operator|(
literal|"unknown error"
operator|)
return|;
name|pthread_setspecific
argument_list|(
name|key
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/*  	 * XXX This really should be snprintf(buf, EAI_BUFSIZE, ...). 	 * It is safe until message catalogs are used. 	 */
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s: %d"
argument_list|,
name|gai_errlist
index|[
name|gai_nerr
operator|-
literal|1
index|]
argument_list|,
name|ecode
argument_list|)
expr_stmt|;
return|return
operator|(
name|buf
operator|)
return|;
block|}
end_function

end_unit

