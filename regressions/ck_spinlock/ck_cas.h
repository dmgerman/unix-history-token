begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|LOCK_NAME
value|"ck_cas"
end_define

begin_define
define|#
directive|define
name|LOCK_DEFINE
value|static ck_spinlock_cas_t CK_CC_CACHELINE lock = CK_SPINLOCK_CAS_INITIALIZER
end_define

begin_define
define|#
directive|define
name|LOCK
value|ck_spinlock_cas_lock_eb(&lock)
end_define

begin_define
define|#
directive|define
name|UNLOCK
value|ck_spinlock_cas_unlock(&lock)
end_define

begin_define
define|#
directive|define
name|LOCKED
value|ck_spinlock_cas_locked(&lock)
end_define

end_unit

