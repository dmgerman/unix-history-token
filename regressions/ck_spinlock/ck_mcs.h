begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|LOCK_NAME
value|"ck_mcs"
end_define

begin_define
define|#
directive|define
name|LOCK_DEFINE
value|static ck_spinlock_mcs_t CK_CC_CACHELINE lock = NULL
end_define

begin_define
define|#
directive|define
name|LOCK_STATE
value|ck_spinlock_mcs_context_t node CK_CC_CACHELINE;
end_define

begin_define
define|#
directive|define
name|LOCK
value|ck_spinlock_mcs_lock(&lock,&node)
end_define

begin_define
define|#
directive|define
name|UNLOCK
value|ck_spinlock_mcs_unlock(&lock,&node)
end_define

begin_define
define|#
directive|define
name|LOCKED
value|ck_spinlock_mcs_locked(&lock)
end_define

end_unit

