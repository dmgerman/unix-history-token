begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	up.h	4.1	11/9/80	*/
end_comment

begin_comment
comment|/*  * UNIBUS address of disk controller (e.g. EMULEX SC-21)  */
end_comment

begin_define
define|#
directive|define
name|UPADDR
value|((struct device *)(UBA0_DEV + 0176700))
end_define

begin_comment
comment|/*  * Number of drives  */
end_comment

begin_define
define|#
directive|define
name|NUP
value|2
end_define

begin_comment
comment|/*  * Drive numbers assigned for iostat/vmstat  * Currently drives on hp are 0 and 1, drives on up are 2 and 3.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DK_N
end_ifndef

begin_define
define|#
directive|define
name|DK_N
value|2
end_define

begin_define
define|#
directive|define
name|DK_NMAX
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

