begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|LOCK_NAME
value|"ck_anderson"
end_define

begin_define
define|#
directive|define
name|LOCK_DEFINE
value|static ck_spinlock_anderson_t lock CK_CC_CACHELINE
end_define

begin_define
define|#
directive|define
name|LOCK_STATE
value|ck_spinlock_anderson_thread_t *nad = NULL
end_define

begin_define
define|#
directive|define
name|LOCK
value|ck_spinlock_anderson_lock(&lock,&nad)
end_define

begin_define
define|#
directive|define
name|UNLOCK
value|ck_spinlock_anderson_unlock(&lock, nad)
end_define

begin_define
define|#
directive|define
name|LOCK_INIT
value|ck_spinlock_anderson_init(&lock, malloc(MAX(64,sizeof(ck_spinlock_anderson_thread_t)) * nthr), nthr)
end_define

begin_define
define|#
directive|define
name|LOCKED
value|ck_spinlock_anderson_locked(&lock)
end_define

begin_define
define|#
directive|define
name|NO_LOCAL
end_define

end_unit

