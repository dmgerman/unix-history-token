begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ck_cc.h>
end_include

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|spin_lock
parameter_list|(
specifier|volatile
name|unsigned
name|int
modifier|*
name|lock
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|__x86_64__
asm|__asm__
specifier|__volatile__
asm|(                     "\n1:\t"                     "lock ; decl %0\n\t"                     "jns 2f\n"                     "3:\n"                     "rep;nop\n\t"                     "cmpl $0,%0\n\t"                     "jle 3b\n\t"                     "jmp 1b\n"                     "2:\t" : "=m" (*lock) : : "memory");
else|#
directive|else
operator|*
name|lock
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|spin_unlock
parameter_list|(
specifier|volatile
name|unsigned
name|int
modifier|*
name|lock
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|__x86_64__
asm|__asm__
specifier|__volatile__
asm|("movl $1,%0" :"=m" (*lock) :: "memory");
else|#
directive|else
operator|*
name|lock
operator|=
literal|0
expr_stmt|;
return|return;
endif|#
directive|endif
block|}
end_function

begin_define
define|#
directive|define
name|LOCK_NAME
value|"linux_spinlock"
end_define

begin_define
define|#
directive|define
name|LOCK_DEFINE
value|volatile unsigned int lock = 1
end_define

begin_define
define|#
directive|define
name|LOCK
value|spin_lock(&lock)
end_define

begin_define
define|#
directive|define
name|UNLOCK
value|spin_unlock(&lock)
end_define

end_unit

