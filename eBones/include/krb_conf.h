begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  * This file contains configuration information for the Kerberos library  * which is machine specific; currently, this file contains  * configuration information for the vax, the "ibm032" (RT), and the  * "PC8086" (IBM PC).  *  * Note:  cross-compiled targets must appear BEFORE their corresponding  * cross-compiler host.  Otherwise, both will be defined when running  * the native compiler on the programs that construct cross-compiled  * sources.  *  *	from: krb_conf.h,v 4.0 89/01/23 09:59:27 jtkohl Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KRB_CONF_DEFS
end_ifndef

begin_define
define|#
directive|define
name|KRB_CONF_DEFS
end_define

begin_comment
comment|/* Byte ordering */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|krbONE
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|(* (char *)&krbONE)
end_define

begin_define
define|#
directive|define
name|MSB_FIRST
value|0
end_define

begin_comment
comment|/* 68000, IBM RT/PC */
end_comment

begin_define
define|#
directive|define
name|LSB_FIRST
value|1
end_define

begin_comment
comment|/* Vax, PC8086 */
end_comment

begin_endif
endif|#
directive|endif
endif|KRB_CONF_DEFS
end_endif

end_unit

