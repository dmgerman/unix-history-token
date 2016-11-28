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
value|static ck_spinlock_hclh_t CK_CC_CACHELINE *glob_lock; \ 		    static ck_spinlock_hclh_t CK_CC_CACHELINE *local_lock[CORES / 2]
end_define

begin_define
define|#
directive|define
name|LOCK_STATE
value|ck_spinlock_hclh_t *na = malloc(MAX(sizeof(ck_spinlock_hclh_t), 64))
end_define

begin_define
define|#
directive|define
name|LOCK
value|ck_spinlock_hclh_lock(&glob_lock,&local_lock[(core % CORES) / 2], na)
end_define

begin_define
define|#
directive|define
name|UNLOCK
value|ck_spinlock_hclh_unlock(&na)
end_define

begin_define
define|#
directive|define
name|LOCK_INIT
value|do {							\ 	int _i;								\ 	ck_spinlock_hclh_init(&glob_lock, malloc(MAX(sizeof(ck_spinlock_hclh_t), 64)), -1); \ 	for (_i = 0; _i< CORES / 2; _i++) {				\ 		ck_spinlock_hclh_init(&local_lock[_i], malloc(MAX(sizeof(ck_spinlock_hclh_t), 64)), _i);	} \ } while (0)
end_define

begin_define
define|#
directive|define
name|LOCKED
value|ck_spinlock_hclh_locked(&glob_lock)
end_define

end_unit

