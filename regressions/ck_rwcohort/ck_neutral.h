begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|LOCK_PROTOTYPE
value|CK_RWCOHORT_NEUTRAL_PROTOTYPE
end_define

begin_define
define|#
directive|define
name|LOCK_INSTANCE
value|CK_RWCOHORT_NEUTRAL_INSTANCE
end_define

begin_define
define|#
directive|define
name|LOCK_INITIALIZER
value|CK_RWCOHORT_NEUTRAL_INITIALIZER
end_define

begin_define
define|#
directive|define
name|LOCK_INIT
parameter_list|(
name|N
parameter_list|,
name|C
parameter_list|,
name|W
parameter_list|)
value|CK_RWCOHORT_NEUTRAL_INIT(N, C)
end_define

begin_define
define|#
directive|define
name|READ_LOCK
value|CK_RWCOHORT_NEUTRAL_READ_LOCK
end_define

begin_define
define|#
directive|define
name|WRITE_LOCK
value|CK_RWCOHORT_NEUTRAL_WRITE_LOCK
end_define

begin_define
define|#
directive|define
name|READ_UNLOCK
value|CK_RWCOHORT_NEUTRAL_READ_UNLOCK
end_define

begin_define
define|#
directive|define
name|WRITE_UNLOCK
value|CK_RWCOHORT_NEUTRAL_WRITE_UNLOCK
end_define

end_unit

