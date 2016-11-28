begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|LOCK_NAME
value|"ck_cohort"
end_define

begin_define
define|#
directive|define
name|LOCK_DEFINE
define|\
value|static ck_spinlock_fas_t global_fas_lock = CK_SPINLOCK_FAS_INITIALIZER;		\ 	static ck_spinlock_fas_t local_fas_lock = CK_SPINLOCK_FAS_INITIALIZER;		\ 	static void									\ 	ck_spinlock_fas_lock_with_context(ck_spinlock_fas_t *lock, void *context)	\ 	{										\ 		(void)context;								\ 		ck_spinlock_fas_lock(lock);						\ 	}										\ 											\ 	static void									\ 	ck_spinlock_fas_unlock_with_context(ck_spinlock_fas_t *lock, void *context)	\ 	{										\ 		(void)context;								\ 		ck_spinlock_fas_unlock(lock);						\ 	}										\ 											\ 	static bool									\ 	ck_spinlock_fas_locked_with_context(ck_spinlock_fas_t *lock, void *context)	\ 	{										\ 		(void)context;								\ 		return ck_spinlock_fas_locked(lock);					\ 	}										\ 	CK_COHORT_PROTOTYPE(fas_fas,							\ 	    ck_spinlock_fas_lock_with_context, ck_spinlock_fas_unlock_with_context,	\ 	    ck_spinlock_fas_locked_with_context, ck_spinlock_fas_lock_with_context,	\ 	    ck_spinlock_fas_unlock_with_context, ck_spinlock_fas_locked_with_context)	\ 	static CK_COHORT_INSTANCE(fas_fas) CK_CC_CACHELINE cohort = CK_COHORT_INITIALIZER
end_define

begin_define
define|#
directive|define
name|LOCK_INIT
value|CK_COHORT_INIT(fas_fas,&cohort,&global_fas_lock,&local_fas_lock,   \ 	CK_COHORT_DEFAULT_LOCAL_PASS_LIMIT)
end_define

begin_define
define|#
directive|define
name|LOCK
value|CK_COHORT_LOCK(fas_fas,&cohort, NULL, NULL)
end_define

begin_define
define|#
directive|define
name|UNLOCK
value|CK_COHORT_UNLOCK(fas_fas,&cohort, NULL, NULL)
end_define

end_unit

