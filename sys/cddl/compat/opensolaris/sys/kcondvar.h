begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * Copyright (c) 2013 iXsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_CONDVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_CONDVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|cv
name|kcondvar_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CV_DEFAULT
block|,
name|CV_DRIVER
block|}
name|kcv_type_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|zfs_cv_init
parameter_list|(
name|cv
parameter_list|,
name|name
parameter_list|,
name|type
parameter_list|,
name|arg
parameter_list|)
value|do {			\ 	const char *_name;						\ 	ASSERT((type) == CV_DEFAULT);					\ 	for (_name = #cv; *_name != '\0'; _name++) {			\ 		if (*_name>= 'a'&& *_name<= 'z')			\ 			break;						\ 	}								\ 	if (*_name == '\0')						\ 		_name = #cv;						\ 	cv_init((cv), _name);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|cv_init
parameter_list|(
name|cv
parameter_list|,
name|name
parameter_list|,
name|type
parameter_list|,
name|arg
parameter_list|)
value|zfs_cv_init((cv), (name), (type), (arg))
end_define

begin_function
specifier|static
name|clock_t
name|cv_timedwait_hires
parameter_list|(
name|kcondvar_t
modifier|*
name|cvp
parameter_list|,
name|kmutex_t
modifier|*
name|mp
parameter_list|,
name|hrtime_t
name|tim
parameter_list|,
name|hrtime_t
name|res
parameter_list|,
name|int
name|flag
parameter_list|)
block|{
comment|/* XXX real hires is not available. */
comment|/* We do not attempt to support any flags yet. */
name|ASSERT
argument_list|(
name|flag
operator|==
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|cv_timedwait
argument_list|(
name|cvp
argument_list|,
name|mp
argument_list|,
name|NSEC_TO_TICK
argument_list|(
name|tim
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPENSOLARIS_SYS_CONDVAR_H_ */
end_comment

end_unit

