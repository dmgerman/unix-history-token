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
file|<sys/time.h>
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
file|<linux/sched.h>
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

begin_include
include|#
directive|include
file|<machine/stdarg.h>
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
name|U8_MAX
value|((u8)~0U)
end_define

begin_define
define|#
directive|define
name|S8_MAX
value|((s8)(U8_MAX>> 1))
end_define

begin_define
define|#
directive|define
name|S8_MIN
value|((s8)(-S8_MAX - 1))
end_define

begin_define
define|#
directive|define
name|U16_MAX
value|((u16)~0U)
end_define

begin_define
define|#
directive|define
name|S16_MAX
value|((s16)(U16_MAX>> 1))
end_define

begin_define
define|#
directive|define
name|S16_MIN
value|((s16)(-S16_MAX - 1))
end_define

begin_define
define|#
directive|define
name|U32_MAX
value|((u32)~0U)
end_define

begin_define
define|#
directive|define
name|S32_MAX
value|((s32)(U32_MAX>> 1))
end_define

begin_define
define|#
directive|define
name|S32_MIN
value|((s32)(-S32_MAX - 1))
end_define

begin_define
define|#
directive|define
name|U64_MAX
value|((u64)~0ULL)
end_define

begin_define
define|#
directive|define
name|S64_MAX
value|((s64)(U64_MAX>> 1))
end_define

begin_define
define|#
directive|define
name|S64_MIN
value|((s64)(-S64_MAX - 1))
end_define

begin_define
define|#
directive|define
name|S8_C
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|U8_C
parameter_list|(
name|x
parameter_list|)
value|x ## U
end_define

begin_define
define|#
directive|define
name|S16_C
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|U16_C
parameter_list|(
name|x
parameter_list|)
value|x ## U
end_define

begin_define
define|#
directive|define
name|S32_C
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|U32_C
parameter_list|(
name|x
parameter_list|)
value|x ## U
end_define

begin_define
define|#
directive|define
name|S64_C
parameter_list|(
name|x
parameter_list|)
value|x ## LL
end_define

begin_define
define|#
directive|define
name|U64_C
parameter_list|(
name|x
parameter_list|)
value|x ## ULL
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
name|BUILD_BUG_ON_MSG
parameter_list|(
name|x
parameter_list|,
name|msg
parameter_list|)
value|BUILD_BUG_ON(x)
end_define

begin_define
define|#
directive|define
name|BUILD_BUG_ON_NOT_POWER_OF_2
parameter_list|(
name|x
parameter_list|)
value|BUILD_BUG_ON(!powerof2(x))
end_define

begin_define
define|#
directive|define
name|BUG
parameter_list|()
value|panic("BUG at %s:%d", __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|BUG_ON
parameter_list|(
name|cond
parameter_list|)
value|do {				\ 	if (cond) {						\ 		panic("BUG ON %s failed at %s:%d",		\ 		    __stringify(cond), __FILE__, __LINE__);	\ 	}							\ } while (0)
end_define

begin_define
define|#
directive|define
name|WARN_ON
parameter_list|(
name|cond
parameter_list|)
value|({					\       bool __ret = (cond);					\       if (__ret) {						\ 		printf("WARNING %s failed at %s:%d\n",		\ 		    __stringify(cond), __FILE__, __LINE__);	\       }								\       unlikely(__ret);						\ })
end_define

begin_define
define|#
directive|define
name|WARN_ON_SMP
parameter_list|(
name|cond
parameter_list|)
value|WARN_ON(cond)
end_define

begin_define
define|#
directive|define
name|WARN_ON_ONCE
parameter_list|(
name|cond
parameter_list|)
value|({					\       static bool __warn_on_once;				\       bool __ret = (cond);					\       if (__ret&& !__warn_on_once) {				\ 		__warn_on_once = 1;				\ 		printf("WARNING %s failed at %s:%d\n",		\ 		    __stringify(cond), __FILE__, __LINE__);	\       }								\       unlikely(__ret);						\ })
end_define

begin_define
define|#
directive|define
name|oops_in_progress
value|SCHEDULER_STOPPED()
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
modifier|...
parameter_list|)
value|printf(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|vprintk
parameter_list|(
name|f
parameter_list|,
name|a
parameter_list|)
value|vprintf(f, a)
end_define

begin_struct
struct|struct
name|va_format
block|{
specifier|const
name|char
modifier|*
name|fmt
decl_stmt|;
name|va_list
modifier|*
name|va
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|int
name|vscnprintf
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|args
parameter_list|)
block|{
name|ssize_t
name|ssize
init|=
name|size
decl_stmt|;
name|int
name|i
decl_stmt|;
name|i
operator|=
name|vsnprintf
argument_list|(
name|buf
argument_list|,
name|size
argument_list|,
name|fmt
argument_list|,
name|args
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|i
operator|>=
name|ssize
operator|)
condition|?
operator|(
name|ssize
operator|-
literal|1
operator|)
else|:
name|i
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|scnprintf
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|args
decl_stmt|;
name|int
name|i
decl_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|i
operator|=
name|vscnprintf
argument_list|(
name|buf
argument_list|,
name|size
argument_list|,
name|fmt
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
return|return
operator|(
name|i
operator|)
return|;
block|}
end_function

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
value|do {		\ 	static bool __log_once;			\ 						\ 	if (unlikely(!__log_once)) {		\ 		__log_once = true;		\ 		log(level, __VA_ARGS__);	\ 	}					\ } while (0)
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
parameter_list|(
modifier|...
parameter_list|)
define|\
value|pr_warning(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|pr_warn_once
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|log_once(LOG_WARNING, pr_fmt(fmt), ##__VA_ARGS__)
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

begin_define
define|#
directive|define
name|pr_warn_ratelimited
parameter_list|(
modifier|...
parameter_list|)
value|do {		\ 	static linux_ratelimit_t __ratelimited;	\ 	if (linux_ratelimited(&__ratelimited))	\ 		pr_warning(__VA_ARGS__);	\ } while (0)
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
modifier|...
parameter_list|)
value|({			\         bool __ret_warn_on = (condition);	\         if (unlikely(__ret_warn_on))		\                 pr_warning(__VA_ARGS__);	\         unlikely(__ret_warn_on);		\ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WARN_ONCE
end_ifndef

begin_define
define|#
directive|define
name|WARN_ONCE
parameter_list|(
name|condition
parameter_list|,
modifier|...
parameter_list|)
value|({		\         bool __ret_warn_on = (condition);	\         if (unlikely(__ret_warn_on))		\                 pr_warn_once(__VA_ARGS__);	\         unlikely(__ret_warn_on);		\ })
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
value|({								\ 	const __typeof(((type *)0)->member) *__p = (ptr);	\ 	(type *)((uintptr_t)__p - offsetof(type, member));	\ })
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

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|long
name|simple_strtoull
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|char
modifier|*
modifier|*
name|endp
parameter_list|,
name|unsigned
name|int
name|base
parameter_list|)
block|{
return|return
operator|(
name|strtouq
argument_list|(
name|cp
argument_list|,
name|endp
argument_list|,
name|base
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|long
name|long
name|simple_strtoll
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|char
modifier|*
modifier|*
name|endp
parameter_list|,
name|unsigned
name|int
name|base
parameter_list|)
block|{
return|return
operator|(
name|strtoq
argument_list|(
name|cp
argument_list|,
name|endp
argument_list|,
name|base
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|simple_strtoul
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|char
modifier|*
modifier|*
name|endp
parameter_list|,
name|unsigned
name|int
name|base
parameter_list|)
block|{
return|return
operator|(
name|strtoul
argument_list|(
name|cp
argument_list|,
name|endp
argument_list|,
name|base
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|long
name|simple_strtol
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|char
modifier|*
modifier|*
name|endp
parameter_list|,
name|unsigned
name|int
name|base
parameter_list|)
block|{
return|return
operator|(
name|strtol
argument_list|(
name|cp
argument_list|,
name|endp
argument_list|,
name|base
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|kstrtoul
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|unsigned
name|int
name|base
parameter_list|,
name|unsigned
name|long
modifier|*
name|res
parameter_list|)
block|{
name|char
modifier|*
name|end
decl_stmt|;
operator|*
name|res
operator|=
name|strtoul
argument_list|(
name|cp
argument_list|,
operator|&
name|end
argument_list|,
name|base
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|cp
operator|==
literal|0
operator|||
operator|*
name|end
operator|!=
literal|0
condition|)
return|return
operator|(
operator|-
name|EINVAL
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|kstrtol
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|unsigned
name|int
name|base
parameter_list|,
name|long
modifier|*
name|res
parameter_list|)
block|{
name|char
modifier|*
name|end
decl_stmt|;
operator|*
name|res
operator|=
name|strtol
argument_list|(
name|cp
argument_list|,
operator|&
name|end
argument_list|,
name|base
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|cp
operator|==
literal|0
operator|||
operator|*
name|end
operator|!=
literal|0
condition|)
return|return
operator|(
operator|-
name|EINVAL
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|kstrtoint
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|unsigned
name|int
name|base
parameter_list|,
name|int
modifier|*
name|res
parameter_list|)
block|{
name|char
modifier|*
name|end
decl_stmt|;
name|long
name|temp
decl_stmt|;
operator|*
name|res
operator|=
name|temp
operator|=
name|strtol
argument_list|(
name|cp
argument_list|,
operator|&
name|end
argument_list|,
name|base
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|cp
operator|==
literal|0
operator|||
operator|*
name|end
operator|!=
literal|0
condition|)
return|return
operator|(
operator|-
name|EINVAL
operator|)
return|;
if|if
condition|(
name|temp
operator|!=
operator|(
name|int
operator|)
name|temp
condition|)
return|return
operator|(
operator|-
name|ERANGE
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|kstrtouint
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|unsigned
name|int
name|base
parameter_list|,
name|unsigned
name|int
modifier|*
name|res
parameter_list|)
block|{
name|char
modifier|*
name|end
decl_stmt|;
name|unsigned
name|long
name|temp
decl_stmt|;
operator|*
name|res
operator|=
name|temp
operator|=
name|strtoul
argument_list|(
name|cp
argument_list|,
operator|&
name|end
argument_list|,
name|base
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|cp
operator|==
literal|0
operator|||
operator|*
name|end
operator|!=
literal|0
condition|)
return|return
operator|(
operator|-
name|EINVAL
operator|)
return|;
if|if
condition|(
name|temp
operator|!=
operator|(
name|unsigned
name|int
operator|)
name|temp
condition|)
return|return
operator|(
operator|-
name|ERANGE
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|kstrtou32
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|unsigned
name|int
name|base
parameter_list|,
name|u32
modifier|*
name|res
parameter_list|)
block|{
name|char
modifier|*
name|end
decl_stmt|;
name|unsigned
name|long
name|temp
decl_stmt|;
operator|*
name|res
operator|=
name|temp
operator|=
name|strtoul
argument_list|(
name|cp
argument_list|,
operator|&
name|end
argument_list|,
name|base
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|cp
operator|==
literal|0
operator|||
operator|*
name|end
operator|!=
literal|0
condition|)
return|return
operator|(
operator|-
name|EINVAL
operator|)
return|;
if|if
condition|(
name|temp
operator|!=
operator|(
name|u32
operator|)
name|temp
condition|)
return|return
operator|(
operator|-
name|ERANGE
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

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
name|x
parameter_list|,
name|y
parameter_list|)
value|({			\ 	type __min1 = (x);			\ 	type __min2 = (y);			\ 	__min1< __min2 ? __min1 : __min2; })
end_define

begin_define
define|#
directive|define
name|max_t
parameter_list|(
name|type
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|({			\ 	type __max1 = (x);			\ 	type __max2 = (y);			\ 	__max1> __max2 ? __max1 : __max2; })
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

begin_define
define|#
directive|define
name|clamp_val
parameter_list|(
name|val
parameter_list|,
name|lo
parameter_list|,
name|hi
parameter_list|)
value|clamp_t(typeof(val), val, lo, hi)
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|bool
name|linux_cpu_has_clflush
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|cpu_has_clflush
value|linux_cpu_has_clflush
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|DIV_ROUND_CLOSEST_ULL
parameter_list|(
name|x
parameter_list|,
name|divisor
parameter_list|)
value|({		\ 	__typeof(divisor) __d = (divisor);		\ 	unsigned long long __ret = (x) + (__d) / 2;	\ 	__ret /= __d;					\ 	__ret;						\ })
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

begin_typedef
typedef|typedef
struct|struct
name|linux_ratelimit
block|{
name|struct
name|timeval
name|lasttime
decl_stmt|;
name|int
name|counter
decl_stmt|;
block|}
name|linux_ratelimit_t
typedef|;
end_typedef

begin_function
specifier|static
specifier|inline
name|bool
name|linux_ratelimited
parameter_list|(
name|linux_ratelimit_t
modifier|*
name|rl
parameter_list|)
block|{
return|return
operator|(
name|ppsratecheck
argument_list|(
operator|&
name|rl
operator|->
name|lasttime
argument_list|,
operator|&
name|rl
operator|->
name|counter
argument_list|,
literal|1
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
comment|/* _LINUX_KERNEL_H_ */
end_comment

end_unit

