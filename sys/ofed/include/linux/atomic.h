begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_COMPAT_LINUX_ATOMIC_H
end_ifndef

begin_define
define|#
directive|define
name|_COMPAT_LINUX_ATOMIC_H
value|1
end_define

begin_comment
comment|/* #include<linux/version.h>  #if (LINUX_VERSION_CODE> KERNEL_VERSION(2,6,36)) #include_next<linux/atomic.h> #else */
end_comment

begin_include
include|#
directive|include
file|<asm/atomic.h>
end_include

begin_comment
comment|/* Shahar Klein: atomic_inc_not_zero_hint do we need it? */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/**  * atomic_inc_not_zero_hint - increment if not null  * @v: pointer of type atomic_t  * @hint: probable value of the atomic before the increment  *  * This version of atomic_inc_not_zero() gives a hint of probable  * value of the atomic. This helps processor to not read the memory  * before doing the atomic read/modify/write cycle, lowering  * number of bus transactions on some arches.  *  * Returns: 0 if increment was not done, 1 otherwise.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|atomic_inc_not_zero_hint
end_ifndef

begin_comment
unit|static inline int atomic_inc_not_zero_hint(atomic_t *v, int hint) { 	int val, c = hint;
comment|/* sanity test, should be removed by compiler if hint is a constant */
end_comment

begin_endif
unit|if (!hint) 		return atomic_inc_not_zero(v);  	do { 		val = atomic_cmpxchg(v, c, c + 1); 		if (val == c) 			return 1; 		c = val; 	} while (c);  	return 0; }
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//#endif /* (LINUX_VERSION_CODE> KERNEL_VERSION(2,6,36)) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _COMPAT_LINUX_ATOMIC_H */
end_comment

end_unit

