begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	dh.h	4.1	11/9/80	*/
end_comment

begin_comment
comment|/*  * Number of DH lines  */
end_comment

begin_define
define|#
directive|define
name|NDH11
value|32
end_define

begin_comment
comment|/*  * Address of first DH11  */
end_comment

begin_define
define|#
directive|define
name|DHADDR
value|((struct device *)(UBA0_DEV + 0160020))
end_define

end_unit

