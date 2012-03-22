begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Portions Copyright (c) 2010 Apple Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SELECT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"heimqueue.h"
end_include

begin_include
include|#
directive|include
file|"heim_threads.h"
end_include

begin_include
include|#
directive|include
file|"heimbase.h"
end_include

begin_include
include|#
directive|include
file|"heimbasepriv.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DISPATCH_DISPATCH_H
end_ifdef

begin_include
include|#
directive|include
file|<dispatch/dispatch.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE___SYNC_ADD_AND_FETCH
argument_list|)
end_if

begin_define
define|#
directive|define
name|heim_base_atomic_inc
parameter_list|(
name|x
parameter_list|)
value|__sync_add_and_fetch((x), 1)
end_define

begin_define
define|#
directive|define
name|heim_base_atomic_dec
parameter_list|(
name|x
parameter_list|)
value|__sync_sub_and_fetch((x), 1)
end_define

begin_define
define|#
directive|define
name|heim_base_atomic_type
value|unsigned int
end_define

begin_define
define|#
directive|define
name|heim_base_atomic_max
value|UINT_MAX
end_define

begin_define
define|#
directive|define
name|heim_base_exchange_pointer
parameter_list|(
name|t
parameter_list|,
name|v
parameter_list|)
value|__sync_lock_test_and_set((t), (v))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_elif

begin_define
define|#
directive|define
name|heim_base_atomic_inc
parameter_list|(
name|x
parameter_list|)
value|InterlockedIncrement(x)
end_define

begin_define
define|#
directive|define
name|heim_base_atomic_dec
parameter_list|(
name|x
parameter_list|)
value|InterlockedDecrement(x)
end_define

begin_define
define|#
directive|define
name|heim_base_atomic_type
value|LONG
end_define

begin_define
define|#
directive|define
name|heim_base_atomic_max
value|MAXLONG
end_define

begin_define
define|#
directive|define
name|heim_base_exchange_pointer
parameter_list|(
name|t
parameter_list|,
name|v
parameter_list|)
value|InterlockedExchangePointer((t),(v))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HEIM_BASE_NEED_ATOMIC_MUTEX
value|1
end_define

begin_decl_stmt
specifier|extern
name|HEIMDAL_MUTEX
name|_heim_base_mutex
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|heim_base_atomic_type
value|unsigned int
end_define

begin_function
specifier|static
specifier|inline
name|heim_base_atomic_type
name|heim_base_atomic_inc
parameter_list|(
name|heim_base_atomic_type
modifier|*
name|x
parameter_list|)
block|{
name|heim_base_atomic_type
name|t
decl_stmt|;
name|HEIMDAL_MUTEX_lock
argument_list|(
operator|&
name|_heim_base_mutex
argument_list|)
expr_stmt|;
name|t
operator|=
operator|++
operator|(
operator|*
name|x
operator|)
expr_stmt|;
name|HEIMDAL_MUTEX_unlock
argument_list|(
operator|&
name|_heim_base_mutex
argument_list|)
expr_stmt|;
return|return
name|t
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|heim_base_atomic_type
name|heim_base_atomic_dec
parameter_list|(
name|heim_base_atomic_type
modifier|*
name|x
parameter_list|)
block|{
name|heim_base_atomic_type
name|t
decl_stmt|;
name|HEIMDAL_MUTEX_lock
argument_list|(
operator|&
name|_heim_base_mutex
argument_list|)
expr_stmt|;
name|t
operator|=
operator|--
operator|(
operator|*
name|x
operator|)
expr_stmt|;
name|HEIMDAL_MUTEX_unlock
argument_list|(
operator|&
name|_heim_base_mutex
argument_list|)
expr_stmt|;
return|return
name|t
return|;
block|}
end_function

begin_define
define|#
directive|define
name|heim_base_atomic_max
value|UINT_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tagged strings/object/XXX */
end_comment

begin_define
define|#
directive|define
name|heim_base_is_tagged
parameter_list|(
name|x
parameter_list|)
value|(((uintptr_t)(x))& 0x3)
end_define

begin_define
define|#
directive|define
name|heim_base_is_tagged_object
parameter_list|(
name|x
parameter_list|)
value|((((uintptr_t)(x))& 0x3) == 1)
end_define

begin_define
define|#
directive|define
name|heim_base_make_tagged_object
parameter_list|(
name|x
parameter_list|,
name|tid
parameter_list|)
define|\
value|((heim_object_t)((((uintptr_t)(x))<< 5) | ((tid)<< 2) | 0x1))
end_define

begin_define
define|#
directive|define
name|heim_base_tagged_object_tid
parameter_list|(
name|x
parameter_list|)
value|((((uintptr_t)(x))& 0x1f)>> 2)
end_define

begin_define
define|#
directive|define
name|heim_base_tagged_object_value
parameter_list|(
name|x
parameter_list|)
value|(((uintptr_t)(x))>> 5)
end_define

begin_comment
comment|/*  *  */
end_comment

begin_undef
undef|#
directive|undef
name|HEIMDAL_NORETURN_ATTRIBUTE
end_undef

begin_define
define|#
directive|define
name|HEIMDAL_NORETURN_ATTRIBUTE
end_define

begin_undef
undef|#
directive|undef
name|HEIMDAL_PRINTF_ATTRIBUTE
end_undef

begin_define
define|#
directive|define
name|HEIMDAL_PRINTF_ATTRIBUTE
parameter_list|(
name|x
parameter_list|)
end_define

end_unit

