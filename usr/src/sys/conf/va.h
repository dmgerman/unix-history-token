begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	va.h	4.1	11/9/80	*/
end_comment

begin_comment
comment|/*  * Is there a varian?  */
end_comment

begin_define
define|#
directive|define
name|NVA
value|1
end_define

begin_comment
comment|/*  * UNIBUS address of varian  */
end_comment

begin_define
define|#
directive|define
name|VAADDR
value|((struct varegs *)(UBA0_DEV + 0164000))
end_define

end_unit

