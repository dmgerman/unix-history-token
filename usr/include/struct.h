begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	struct.h	4.1	83/05/03	*/
end_comment

begin_comment
comment|/*  * access to information relating to the fields of a structure  */
end_comment

begin_define
define|#
directive|define
name|fldoff
parameter_list|(
name|str
parameter_list|,
name|fld
parameter_list|)
value|((int)&(((struct str *)0)->fld))
end_define

begin_define
define|#
directive|define
name|fldsiz
parameter_list|(
name|str
parameter_list|,
name|fld
parameter_list|)
value|(sizeof(((struct str *)0)->fld))
end_define

begin_define
define|#
directive|define
name|strbase
parameter_list|(
name|str
parameter_list|,
name|ptr
parameter_list|,
name|fld
parameter_list|)
value|((struct str *)((char *)(ptr)-fldoff(str, fld)))
end_define

end_unit

