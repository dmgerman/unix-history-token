begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|LOCK_NAME
value|"ck_ticket_pb"
end_define

begin_define
define|#
directive|define
name|LOCK_DEFINE
value|static ck_spinlock_ticket_t CK_CC_CACHELINE lock = CK_SPINLOCK_TICKET_INITIALIZER
end_define

begin_define
define|#
directive|define
name|LOCK
value|ck_spinlock_ticket_lock_pb(&lock, 0)
end_define

begin_define
define|#
directive|define
name|UNLOCK
value|ck_spinlock_ticket_unlock(&lock)
end_define

begin_define
define|#
directive|define
name|LOCKED
value|ck_spinlock_ticket_locked(&lock)
end_define

end_unit

