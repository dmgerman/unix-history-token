begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vp.h	4.1	11/9/80	*/
end_comment

begin_comment
comment|/*  * Is there a versatec?  */
end_comment

begin_define
define|#
directive|define
name|NVP
value|1
end_define

begin_comment
comment|/*  * UNIBUS address of versatec  */
end_comment

begin_define
define|#
directive|define
name|VPADDR
value|((struct vpregs *)(UBA0_DEV + 0177500))
end_define

end_unit

