begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Parameters to vadvise() to tell system of particular paging  * behaviour:  *	VA_NORM		Normal strategy  *	VA_ANOM		Sampling page behaviour is not a win, don't bother  *			Suitable during GCs in LISP, or sequential or random  *			page referencing.  */
end_comment

begin_define
define|#
directive|define
name|VA_NORM
value|0
end_define

begin_define
define|#
directive|define
name|VA_ANOM
value|1
end_define

end_unit

