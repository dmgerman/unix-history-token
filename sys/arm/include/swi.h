begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: swi.h,v 1.1 2002/01/13 15:03:06 bjh21 Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * This file is in the Public Domain.  * Ben Harris, 2002.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SWI_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SWI_H_
end_define

begin_define
define|#
directive|define
name|SWI_OS_MASK
value|0xf00000
end_define

begin_define
define|#
directive|define
name|SWI_OS_RISCOS
value|0x000000
end_define

begin_define
define|#
directive|define
name|SWI_OS_RISCIX
value|0x800000
end_define

begin_define
define|#
directive|define
name|SWI_OS_LINUX
value|0x900000
end_define

begin_define
define|#
directive|define
name|SWI_OS_NETBSD
value|0xa00000
end_define

begin_define
define|#
directive|define
name|SWI_OS_ARM
value|0xf00000
end_define

begin_define
define|#
directive|define
name|SWI_IMB
value|0xf00000
end_define

begin_define
define|#
directive|define
name|SWI_IMBrange
value|0xf00001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SWI_H_ */
end_comment

end_unit

