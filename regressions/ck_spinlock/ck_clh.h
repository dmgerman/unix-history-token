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
value|"ck_clh"
end_define

begin_define
define|#
directive|define
name|LOCK_DEFINE
value|static ck_spinlock_clh_t CK_CC_CACHELINE *lock = NULL
end_define

begin_define
define|#
directive|define
name|LOCK_STATE
value|ck_spinlock_clh_t *na = malloc(MAX(sizeof(ck_spinlock_clh_t), 64))
end_define

begin_define
define|#
directive|define
name|LOCK
value|ck_spinlock_clh_lock(&lock, na)
end_define

begin_define
define|#
directive|define
name|UNLOCK
value|ck_spinlock_clh_unlock(&na)
end_define

begin_define
define|#
directive|define
name|LOCK_INIT
value|ck_spinlock_clh_init(&lock, malloc(MAX(sizeof(ck_spinlock_clh_t), 64)))
end_define

begin_define
define|#
directive|define
name|LOCKED
value|ck_spinlock_clh_locked(&lock)
end_define

end_unit

