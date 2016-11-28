begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ck_spinlock.h>
end_include

begin_define
define|#
directive|define
name|LOCK_NAME
value|"ck_ticket"
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
value|ck_spinlock_ticket_lock(&lock)
end_define

begin_define
define|#
directive|define
name|UNLOCK
value|ck_spinlock_ticket_unlock(&lock)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CK_F_SPINLOCK_TICKET_TRYLOCK
end_ifdef

begin_define
define|#
directive|define
name|TRYLOCK
value|ck_spinlock_ticket_trylock(&lock)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LOCKED
value|ck_spinlock_ticket_locked(&lock)
end_define

end_unit

