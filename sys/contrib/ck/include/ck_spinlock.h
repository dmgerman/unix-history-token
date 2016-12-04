begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2010-2015 Samy Al Bahra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_SPINLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|CK_SPINLOCK_H
end_define

begin_include
include|#
directive|include
file|"spinlock/anderson.h"
end_include

begin_include
include|#
directive|include
file|"spinlock/cas.h"
end_include

begin_include
include|#
directive|include
file|"spinlock/clh.h"
end_include

begin_include
include|#
directive|include
file|"spinlock/dec.h"
end_include

begin_include
include|#
directive|include
file|"spinlock/fas.h"
end_include

begin_include
include|#
directive|include
file|"spinlock/hclh.h"
end_include

begin_include
include|#
directive|include
file|"spinlock/mcs.h"
end_include

begin_include
include|#
directive|include
file|"spinlock/ticket.h"
end_include

begin_comment
comment|/*  * On tested x86, x86_64, PPC64 and SPARC64 targets,  * ck_spinlock_fas proved to have lowest latency  * in fast path testing or negligible degradation  * from faster but less robust implementations.  */
end_comment

begin_define
define|#
directive|define
name|CK_SPINLOCK_INITIALIZER
value|CK_SPINLOCK_FAS_INITIALIZER
end_define

begin_define
define|#
directive|define
name|ck_spinlock_t
value|ck_spinlock_fas_t
end_define

begin_define
define|#
directive|define
name|ck_spinlock_init
parameter_list|(
name|x
parameter_list|)
value|ck_spinlock_fas_init(x)
end_define

begin_define
define|#
directive|define
name|ck_spinlock_lock
parameter_list|(
name|x
parameter_list|)
value|ck_spinlock_fas_lock(x)
end_define

begin_define
define|#
directive|define
name|ck_spinlock_lock_eb
parameter_list|(
name|x
parameter_list|)
value|ck_spinlock_fas_lock_eb(x)
end_define

begin_define
define|#
directive|define
name|ck_spinlock_unlock
parameter_list|(
name|x
parameter_list|)
value|ck_spinlock_fas_unlock(x)
end_define

begin_define
define|#
directive|define
name|ck_spinlock_locked
parameter_list|(
name|x
parameter_list|)
value|ck_spinlock_fas_locked(x)
end_define

begin_define
define|#
directive|define
name|ck_spinlock_trylock
parameter_list|(
name|x
parameter_list|)
value|ck_spinlock_fas_trylock(x)
end_define

begin_macro
name|CK_ELIDE_PROTOTYPE
argument_list|(
argument|ck_spinlock
argument_list|,
argument|ck_spinlock_t
argument_list|,
argument|ck_spinlock_locked
argument_list|,
argument|ck_spinlock_lock
argument_list|,
argument|ck_spinlock_locked
argument_list|,
argument|ck_spinlock_unlock
argument_list|)
end_macro

begin_macro
name|CK_ELIDE_TRYLOCK_PROTOTYPE
argument_list|(
argument|ck_spinlock
argument_list|,
argument|ck_spinlock_t
argument_list|,
argument|ck_spinlock_locked
argument_list|,
argument|ck_spinlock_trylock
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_SPINLOCK_H */
end_comment

end_unit

