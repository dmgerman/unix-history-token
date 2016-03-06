begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013-2016 Mellanox Technologies, Ltd.  * Copyright (c) 2014-2015 FranÃ§ois Tigeot  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_KERNEL_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_KERNEL_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<sys/stddef.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<linux/bitops.h>
end_include

begin_include
include|#
directive|include
file|<linux/compiler.h>
end_include

begin_include
include|#
directive|include
file|<linux/errno.h>
end_include

begin_include
include|#
directive|include
file|<linux/kthread.h>
end_include

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<linux/jiffies.h>
end_include

begin_include
include|#
directive|include
file|<linux/wait.h>
end_include

begin_include
include|#
directive|include
file|<linux/log2.h>
end_include

begin_include
include|#
directive|include
file|<asm/byteorder.h>
end_include

begin_define
define|#
directive|define
name|KERN_CONT
value|""
end_define

begin_define
define|#
directive|define
name|KERN_EMERG
value|"<0>"
end_define

begin_define
define|#
directive|define
name|KERN_ALERT
value|"<1>"
end_define

begin_define
define|#
directive|define
name|KERN_CRIT
value|"<2>"
end_define

begin_define
define|#
directive|define
name|KERN_ERR
value|"<3>"
end_define

begin_define
define|#
directive|define
name|KERN_WARNING
value|"<4>"
end_define

begin_define
define|#
directive|define
name|KERN_NOTICE
value|"<5>"
end_define

begin_define
define|#
directive|define
name|KERN_INFO
value|"<6>"
end_define

begin_define
define|#
directive|define
name|KERN_DEBUG
value|"<7>"
end_define

begin_define
define|#
directive|define
name|BUILD_BUG_ON
parameter_list|(
name|x
parameter_list|)
value|CTASSERT(!(x))
end_define

begin_define
define|#
directive|define
name|BUG
parameter_list|()
value|panic("BUG")
end_define

begin_define
define|#
directive|define
name|BUG_ON
parameter_list|(
name|condition
parameter_list|)
value|do { if (condition) BUG(); } while(0)
end_define

begin_define
define|#
directive|define
name|WARN_ON
value|BUG_ON
end_define

begin_undef
undef|#
directive|undef
name|ALIGN
end_undef

begin_define
define|#
directive|define
name|ALIGN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|roundup2((x), (y))
end_define

begin_undef
undef|#
directive|undef
name|PTR_ALIGN
end_undef

begin_define
define|#
directive|define
name|PTR_ALIGN
parameter_list|(
name|p
parameter_list|,
name|a
parameter_list|)
value|((__typeof(p))ALIGN((uintptr_t)(p), (a)))
end_define

begin_define
define|#
directive|define
name|DIV_ROUND_UP
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|howmany(x, n)
end_define

begin_define
define|#
directive|define
name|DIV_ROUND_UP_ULL
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|DIV_ROUND_UP((unsigned long long)(x), (n))
end_define

begin_define
define|#
directive|define
name|FIELD_SIZEOF
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|)
value|sizeof(((t *)0)->f)
end_define

begin_define
define|#
directive|define
name|printk
parameter_list|(
name|X
modifier|...
parameter_list|)
value|printf(X)
end_define

begin_comment
comment|/*  * The "pr_debug()" and "pr_devel()" macros should produce zero code  * unless DEBUG is defined:  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|pr_debug
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|log(LOG_DEBUG, fmt, ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pr_devel
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|log(LOG_DEBUG, pr_fmt(fmt), ##__VA_ARGS__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|pr_debug
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|({ if (0) log(LOG_DEBUG, fmt, ##__VA_ARGS__); 0; })
end_define

begin_define
define|#
directive|define
name|pr_devel
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|({ if (0) log(LOG_DEBUG, pr_fmt(fmt), ##__VA_ARGS__); 0; })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|pr_fmt
end_ifndef

begin_define
define|#
directive|define
name|pr_fmt
parameter_list|(
name|fmt
parameter_list|)
value|fmt
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Print a one-time message (analogous to WARN_ONCE() et al):  */
end_comment

begin_define
define|#
directive|define
name|printk_once
parameter_list|(
modifier|...
parameter_list|)
value|do {			\ 	static bool __print_once;		\ 						\ 	if (!__print_once) {			\ 		__print_once = true;		\ 		printk(__VA_ARGS__);		\ 	}					\ } while (0)
end_define

begin_comment
comment|/*  * Log a one-time message (analogous to WARN_ONCE() et al):  */
end_comment

begin_define
define|#
directive|define
name|log_once
parameter_list|(
name|level
parameter_list|,
modifier|...
parameter_list|)
value|do {		\ 	static bool __log_once;			\ 						\ 	if (!__log_once) {			\ 		__log_once = true;		\ 		log(level, __VA_ARGS__);	\ 	}					\ } while (0)
end_define

begin_define
define|#
directive|define
name|pr_emerg
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|log(LOG_EMERG, pr_fmt(fmt), ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pr_alert
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|log(LOG_ALERT, pr_fmt(fmt), ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pr_crit
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|log(LOG_CRIT, pr_fmt(fmt), ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pr_err
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|log(LOG_ERR, pr_fmt(fmt), ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pr_warning
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|log(LOG_WARNING, pr_fmt(fmt), ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pr_warn
value|pr_warning
end_define

begin_define
define|#
directive|define
name|pr_notice
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|log(LOG_NOTICE, pr_fmt(fmt), ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pr_info
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|log(LOG_INFO, pr_fmt(fmt), ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pr_info_once
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|log_once(LOG_INFO, pr_fmt(fmt), ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pr_cont
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|printk(KERN_CONT fmt, ##__VA_ARGS__)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|WARN
end_ifndef

begin_define
define|#
directive|define
name|WARN
parameter_list|(
name|condition
parameter_list|,
name|format
modifier|...
parameter_list|)
value|({                                   \         int __ret_warn_on = !!(condition);                              \         if (unlikely(__ret_warn_on))                                    \                 pr_warning(format);                                     \         unlikely(__ret_warn_on);                                        \ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|container_of
parameter_list|(
name|ptr
parameter_list|,
name|type
parameter_list|,
name|member
parameter_list|)
define|\
value|({								\ 	__typeof(((type *)0)->member) *_p = (ptr);		\ 	(type *)((char *)_p - offsetof(type, member));		\ })
end_define

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|x
parameter_list|)
value|(sizeof(x) / sizeof((x)[0]))
end_define

begin_define
define|#
directive|define
name|simple_strtoul
parameter_list|(
modifier|...
parameter_list|)
value|strtoul(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|simple_strtol
parameter_list|(
modifier|...
parameter_list|)
value|strtol(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|kstrtol
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|({*(c) = strtol(a,0,b); 0;})
end_define

begin_define
define|#
directive|define
name|kstrtoint
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|({*(c) = strtol(a,0,b); 0;})
end_define

begin_define
define|#
directive|define
name|kstrtouint
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|({*(c) = strtol(a,0,b); 0;})
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)< (y) ? (x) : (y))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)> (y) ? (x) : (y))
end_define

begin_define
define|#
directive|define
name|min3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|min(a, min(b,c))
end_define

begin_define
define|#
directive|define
name|max3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|max(a, max(b,c))
end_define

begin_define
define|#
directive|define
name|min_t
parameter_list|(
name|type
parameter_list|,
name|_x
parameter_list|,
name|_y
parameter_list|)
value|((type)(_x)< (type)(_y) ? (type)(_x) : (type)(_y))
end_define

begin_define
define|#
directive|define
name|max_t
parameter_list|(
name|type
parameter_list|,
name|_x
parameter_list|,
name|_y
parameter_list|)
value|((type)(_x)> (type)(_y) ? (type)(_x) : (type)(_y))
end_define

begin_define
define|#
directive|define
name|clamp_t
parameter_list|(
name|type
parameter_list|,
name|_x
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|)
value|min_t(type, max_t(type, _x, min), max)
end_define

begin_define
define|#
directive|define
name|clamp
parameter_list|(
name|x
parameter_list|,
name|lo
parameter_list|,
name|hi
parameter_list|)
value|min( max(x,lo), hi)
end_define

begin_comment
comment|/*  * This looks more complex than it should be. But we need to  * get the type for the ~ right in round_down (it needs to be  * as wide as the result!), and we want to evaluate the macro  * arguments just once each.  */
end_comment

begin_define
define|#
directive|define
name|__round_mask
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((__typeof__(x))((y)-1))
end_define

begin_define
define|#
directive|define
name|round_up
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((((x)-1) | __round_mask(x, y))+1)
end_define

begin_define
define|#
directive|define
name|round_down
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)& ~__round_mask(x, y))
end_define

begin_define
define|#
directive|define
name|smp_processor_id
parameter_list|()
value|PCPU_GET(cpuid)
end_define

begin_define
define|#
directive|define
name|num_possible_cpus
parameter_list|()
value|mp_ncpus
end_define

begin_define
define|#
directive|define
name|num_online_cpus
parameter_list|()
value|mp_ncpus
end_define

begin_typedef
typedef|typedef
struct|struct
name|pm_message
block|{
name|int
name|event
decl_stmt|;
block|}
name|pm_message_t
typedef|;
end_typedef

begin_comment
comment|/* Swap values of a and b */
end_comment

begin_define
define|#
directive|define
name|swap
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|do {			\ 	typeof(a) _swap_tmp = a;	\ 	a = b;				\ 	b = _swap_tmp;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|DIV_ROUND_CLOSEST
parameter_list|(
name|x
parameter_list|,
name|divisor
parameter_list|)
value|(((x) + ((divisor) / 2)) / (divisor))
end_define

begin_function
specifier|static
specifier|inline
name|uintmax_t
name|mult_frac
parameter_list|(
name|uintmax_t
name|x
parameter_list|,
name|uintmax_t
name|multiplier
parameter_list|,
name|uintmax_t
name|divisor
parameter_list|)
block|{
name|uintmax_t
name|q
init|=
operator|(
name|x
operator|/
name|divisor
operator|)
decl_stmt|;
name|uintmax_t
name|r
init|=
operator|(
name|x
operator|%
name|divisor
operator|)
decl_stmt|;
return|return
operator|(
operator|(
name|q
operator|*
name|multiplier
operator|)
operator|+
operator|(
operator|(
name|r
operator|*
name|multiplier
operator|)
operator|/
name|divisor
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int64_t
name|abs64
parameter_list|(
name|int64_t
name|x
parameter_list|)
block|{
return|return
operator|(
name|x
operator|<
literal|0
condition|?
operator|-
name|x
else|:
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
comment|/* _LINUX_KERNEL_H_ */
end_comment

end_unit

