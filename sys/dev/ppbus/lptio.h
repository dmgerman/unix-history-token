begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright (C) 1994 Geoffrey M. Rehmet  *  *  This program is free software; you may redistribute it and/or  *  modify it, provided that it retain the above copyright notice  *  and the following disclaimer.  *  *  This program is distributed in the hope that it will be useful,  *  but WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  *	Geoff Rehmet, Rhodes University, South Africa<csgr@cs.ru.ac.za>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_PPBUS_LPT_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_PPBUS_LPT_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|LPT_IRQ
value|_IOW('p', 1, long)
end_define

begin_comment
comment|/* set interrupt status */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DEV_PPBUS_LPT_H_ */
end_comment

end_unit

