begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ztype.h - character classification macros  *  * This file is part of zsh, the Z shell.  *  * This software is Copyright 1992 by Paul Falstad  *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   *  */
end_comment

begin_define
define|#
directive|define
name|IDIGIT
value|1
end_define

begin_define
define|#
directive|define
name|IALNUM
value|2
end_define

begin_define
define|#
directive|define
name|IBLANK
value|4
end_define

begin_define
define|#
directive|define
name|INBLANK
value|8
end_define

begin_define
define|#
directive|define
name|ITOK
value|16
end_define

begin_define
define|#
directive|define
name|ISEP
value|32
end_define

begin_define
define|#
directive|define
name|IALPHA
value|64
end_define

begin_define
define|#
directive|define
name|IIDENT
value|128
end_define

begin_define
define|#
directive|define
name|IUSER
value|256
end_define

begin_define
define|#
directive|define
name|ICNTRL
value|512
end_define

begin_define
define|#
directive|define
name|IWORD
value|1024
end_define

begin_define
define|#
directive|define
name|ISPECIAL
value|2048
end_define

begin_define
define|#
directive|define
name|_icom
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|(typtab[(int) (unsigned char) (X)]& Y)
end_define

begin_define
define|#
directive|define
name|idigit
parameter_list|(
name|X
parameter_list|)
value|_icom(X,IDIGIT)
end_define

begin_define
define|#
directive|define
name|ialnum
parameter_list|(
name|X
parameter_list|)
value|_icom(X,IALNUM)
end_define

begin_define
define|#
directive|define
name|iblank
parameter_list|(
name|X
parameter_list|)
value|_icom(X,IBLANK)
end_define

begin_comment
comment|/* blank, not including \n */
end_comment

begin_define
define|#
directive|define
name|inblank
parameter_list|(
name|X
parameter_list|)
value|_icom(X,INBLANK)
end_define

begin_comment
comment|/* blank or \n */
end_comment

begin_define
define|#
directive|define
name|itok
parameter_list|(
name|X
parameter_list|)
value|_icom(X,ITOK)
end_define

begin_define
define|#
directive|define
name|isep
parameter_list|(
name|X
parameter_list|)
value|_icom(X,ISEP)
end_define

begin_define
define|#
directive|define
name|ialpha
parameter_list|(
name|X
parameter_list|)
value|_icom(X,IALPHA)
end_define

begin_define
define|#
directive|define
name|iident
parameter_list|(
name|X
parameter_list|)
value|_icom(X,IIDENT)
end_define

begin_define
define|#
directive|define
name|iuser
parameter_list|(
name|X
parameter_list|)
value|_icom(X,IUSER)
end_define

begin_comment
comment|/* username char */
end_comment

begin_define
define|#
directive|define
name|icntrl
parameter_list|(
name|X
parameter_list|)
value|_icom(X,ICNTRL)
end_define

begin_define
define|#
directive|define
name|iword
parameter_list|(
name|X
parameter_list|)
value|_icom(X,IWORD)
end_define

begin_define
define|#
directive|define
name|ispecial
parameter_list|(
name|X
parameter_list|)
value|_icom(X,ISPECIAL)
end_define

begin_decl_stmt
name|EXTERN
name|short
name|int
name|typtab
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

end_unit

