begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013-2017 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_SPINLOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_SPINLOCK_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
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
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/kdb.h>
end_include

begin_include
include|#
directive|include
file|<linux/compiler.h>
end_include

begin_include
include|#
directive|include
file|<linux/rwlock.h>
end_include

begin_include
include|#
directive|include
file|<linux/bottom_half.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|mtx
name|m
decl_stmt|;
block|}
name|spinlock_t
typedef|;
end_typedef

begin_comment
comment|/*  * By defining CONFIG_SPIN_SKIP LinuxKPI spinlocks and asserts will be  * skipped during panic(). By default it is disabled due to  * performance reasons.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_SPIN_SKIP
end_ifdef

begin_define
define|#
directive|define
name|SPIN_SKIP
parameter_list|(
name|void
parameter_list|)
value|unlikely(SCHEDULER_STOPPED() || kdb_active)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SPIN_SKIP
parameter_list|(
name|void
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|spin_lock
parameter_list|(
name|_l
parameter_list|)
value|do {			\ 	if (SPIN_SKIP())			\ 		break;				\ 	mtx_lock(&(_l)->m);			\ 	local_bh_disable();			\ } while (0)
end_define

begin_define
define|#
directive|define
name|spin_lock_bh
parameter_list|(
name|_l
parameter_list|)
value|do {			\ 	spin_lock(_l);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|spin_lock_irq
parameter_list|(
name|_l
parameter_list|)
value|do {			\ 	spin_lock(_l);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|spin_unlock
parameter_list|(
name|_l
parameter_list|)
value|do {			\ 	if (SPIN_SKIP())			\ 		break;				\ 	local_bh_enable();			\ 	mtx_unlock(&(_l)->m);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|spin_unlock_bh
parameter_list|(
name|_l
parameter_list|)
value|do {			\ 	spin_unlock(_l);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|spin_unlock_irq
parameter_list|(
name|_l
parameter_list|)
value|do {		\ 	spin_unlock(_l);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|spin_trylock
parameter_list|(
name|_l
parameter_list|)
value|({			\ 	int __ret;				\ 	if (SPIN_SKIP()) {			\ 		__ret = 1;			\ 	} else {				\ 		__ret = mtx_trylock(&(_l)->m);	\ 		if (likely(__ret != 0))		\ 			local_bh_disable();	\ 	}					\ 	__ret;					\ })
end_define

begin_define
define|#
directive|define
name|spin_lock_nested
parameter_list|(
name|_l
parameter_list|,
name|_n
parameter_list|)
value|do {		\ 	if (SPIN_SKIP())			\ 		break;				\ 	mtx_lock_flags(&(_l)->m, MTX_DUPOK);	\ 	local_bh_disable();			\ } while (0)
end_define

begin_define
define|#
directive|define
name|spin_lock_irqsave
parameter_list|(
name|_l
parameter_list|,
name|flags
parameter_list|)
value|do {	\ 	(flags) = 0;				\ 	spin_lock(_l);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|spin_lock_irqsave_nested
parameter_list|(
name|_l
parameter_list|,
name|flags
parameter_list|,
name|_n
parameter_list|)
value|do {	\ 	(flags) = 0;					\ 	spin_lock_nested(_l, _n);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|spin_unlock_irqrestore
parameter_list|(
name|_l
parameter_list|,
name|flags
parameter_list|)
value|do {		\ 	spin_unlock(_l);				\ } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WITNESS_ALL
end_ifdef

begin_comment
comment|/* NOTE: the maximum WITNESS name is 64 chars */
end_comment

begin_define
define|#
directive|define
name|__spin_lock_name
parameter_list|(
name|name
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|(((const char *){file ":" #line "-" name}) + 	\ 	(sizeof(file)> 16 ? sizeof(file) - 16 : 0))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__spin_lock_name
parameter_list|(
name|name
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_spin_lock_name
parameter_list|(
modifier|...
parameter_list|)
value|__spin_lock_name(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|spin_lock_name
parameter_list|(
name|name
parameter_list|)
value|_spin_lock_name(name, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|spin_lock_init
parameter_list|(
name|lock
parameter_list|)
value|linux_spin_lock_init(lock, spin_lock_name("lnxspin"))
end_define

begin_function
specifier|static
specifier|inline
name|void
name|linux_spin_lock_init
parameter_list|(
name|spinlock_t
modifier|*
name|lock
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|memset
argument_list|(
name|lock
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|lock
argument_list|)
argument_list|)
expr_stmt|;
name|mtx_init
argument_list|(
operator|&
name|lock
operator|->
name|m
argument_list|,
name|name
argument_list|,
name|NULL
argument_list|,
name|MTX_DEF
operator||
name|MTX_NOWITNESS
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|spin_lock_destroy
parameter_list|(
name|spinlock_t
modifier|*
name|lock
parameter_list|)
block|{
name|mtx_destroy
argument_list|(
operator|&
name|lock
operator|->
name|m
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|DEFINE_SPINLOCK
parameter_list|(
name|lock
parameter_list|)
define|\
value|spinlock_t lock;					\ 	MTX_SYSINIT(lock,&(lock).m, spin_lock_name("lnxspin"), MTX_DEF)
end_define

begin_define
define|#
directive|define
name|assert_spin_locked
parameter_list|(
name|_l
parameter_list|)
value|do {		\ 	if (SPIN_SKIP())			\ 		break;				\ 	mtx_assert(&(_l)->m, MA_OWNED);		\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_SPINLOCK_H_ */
end_comment

end_unit

