begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Ugen J.S.Antsilevich  *  * Redistribution and use in source forms, with and without modification,  * are permitted provided that this entire comment appears intact.  *  * Redistribution in binary form may occur without any restrictions.  * Obviously, it would be nice if you gave credit where credit is due  * but requiring it would be too onerous.  *  * This software is provided ``AS IS'' without any warranties of any kind.  *  * Snoop stuff.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SNOOP_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SNOOP_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/*  * Theese are snoop io controls  * SNPSTTY accepts 'struct snptty' as input.  * If ever type or  unit set to -1,snoop device  * detached from its current tty.  */
end_comment

begin_define
define|#
directive|define
name|SNPSTTY
value|_IOW('T', 90, dev_t)
end_define

begin_define
define|#
directive|define
name|SNPGTTY
value|_IOR('T', 89, dev_t)
end_define

begin_comment
comment|/*  * Theese values would be returned by FIONREAD ioctl  * instead of number of characters in buffer in case  * of specific errors.  */
end_comment

begin_define
define|#
directive|define
name|SNP_OFLOW
value|-1
end_define

begin_define
define|#
directive|define
name|SNP_TTYCLOSE
value|-2
end_define

begin_define
define|#
directive|define
name|SNP_DETACH
value|-3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SNOOP_H_ */
end_comment

end_unit

