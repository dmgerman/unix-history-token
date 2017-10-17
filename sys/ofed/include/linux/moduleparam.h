begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013-2016 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD: head/sys/compat/linuxkpi/common/include/linux/moduleparam.h 300721 2016-05-26 09:04:14Z hselasky $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_MODULEPARAM_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_MODULEPARAM_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LINUXKPI_PARAM_PARENT
end_ifndef

begin_define
define|#
directive|define
name|LINUXKPI_PARAM_PARENT
value|_compat_linuxkpi
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LINUXKPI_PARAM_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|LINUXKPI_PARAM_PREFIX
end_define

begin_comment
comment|/* empty prefix is the default */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LINUXKPI_PARAM_PERM
end_ifndef

begin_define
define|#
directive|define
name|LINUXKPI_PARAM_PERM
parameter_list|(
name|perm
parameter_list|)
value|(((perm)& 0222) ? CTLFLAG_RWTUN : CTLFLAG_RDTUN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINUXKPI_PARAM_CONCAT_SUB
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|a##b##c##d
end_define

begin_define
define|#
directive|define
name|LINUXKPI_PARAM_CONCAT
parameter_list|(
modifier|...
parameter_list|)
value|LINUXKPI_PARAM_CONCAT_SUB(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|LINUXKPI_PARAM_PASS
parameter_list|(
modifier|...
parameter_list|)
value|__VA_ARGS__
end_define

begin_define
define|#
directive|define
name|LINUXKPI_PARAM_DESC
parameter_list|(
name|name
parameter_list|)
value|LINUXKPI_PARAM_CONCAT(linuxkpi_,LINUXKPI_PARAM_PREFIX,name,_desc)
end_define

begin_define
define|#
directive|define
name|LINUXKPI_PARAM_NAME
parameter_list|(
name|name
parameter_list|)
value|LINUXKPI_PARAM_CONCAT(LINUXKPI_PARAM_PREFIX,name,,)
end_define

begin_define
define|#
directive|define
name|LINUXKPI_PARAM_bool
parameter_list|(
name|name
parameter_list|,
name|var
parameter_list|,
name|perm
parameter_list|)
define|\
value|extern const char LINUXKPI_PARAM_DESC(name)[];			\ 	LINUXKPI_PARAM_PASS(SYSCTL_BOOL(LINUXKPI_PARAM_PARENT, OID_AUTO,\ 	LINUXKPI_PARAM_NAME(name), LINUXKPI_PARAM_PERM(perm),&(var), 0, \ 	LINUXKPI_PARAM_DESC(name)))
end_define

begin_define
define|#
directive|define
name|LINUXKPI_PARAM_byte
parameter_list|(
name|name
parameter_list|,
name|var
parameter_list|,
name|perm
parameter_list|)
define|\
value|extern const char LINUXKPI_PARAM_DESC(name)[];			\ 	LINUXKPI_PARAM_PASS(SYSCTL_U8(LINUXKPI_PARAM_PARENT, OID_AUTO,	\ 	LINUXKPI_PARAM_NAME(name), LINUXKPI_PARAM_PERM(perm),&(var), 0, \ 	LINUXKPI_PARAM_DESC(name)))
end_define

begin_define
define|#
directive|define
name|LINUXKPI_PARAM_short
parameter_list|(
name|name
parameter_list|,
name|var
parameter_list|,
name|perm
parameter_list|)
define|\
value|extern const char LINUXKPI_PARAM_DESC(name)[];			\ 	LINUXKPI_PARAM_PASS(SYSCTL_S16(LINUXKPI_PARAM_PARENT, OID_AUTO,	\ 	LINUXKPI_PARAM_NAME(name), LINUXKPI_PARAM_PERM(perm),&(var), 0, \ 	LINUXKPI_PARAM_DESC(name)))
end_define

begin_define
define|#
directive|define
name|LINUXKPI_PARAM_ushort
parameter_list|(
name|name
parameter_list|,
name|var
parameter_list|,
name|perm
parameter_list|)
define|\
value|extern const char LINUXKPI_PARAM_DESC(name)[];			\ 	LINUXKPI_PARAM_PASS(SYSCTL_U16(LINUXKPI_PARAM_PARENT, OID_AUTO,	\ 	LINUXKPI_PARAM_NAME(name), LINUXKPI_PARAM_PERM(perm),&(var), 0, \ 	LINUXKPI_PARAM_DESC(name)))
end_define

begin_define
define|#
directive|define
name|LINUXKPI_PARAM_int
parameter_list|(
name|name
parameter_list|,
name|var
parameter_list|,
name|perm
parameter_list|)
define|\
value|extern const char LINUXKPI_PARAM_DESC(name)[];			\ 	LINUXKPI_PARAM_PASS(SYSCTL_INT(LINUXKPI_PARAM_PARENT, OID_AUTO,	\ 	LINUXKPI_PARAM_NAME(name), LINUXKPI_PARAM_PERM(perm),&(var), 0,\ 	LINUXKPI_PARAM_DESC(name)))
end_define

begin_define
define|#
directive|define
name|LINUXKPI_PARAM_uint
parameter_list|(
name|name
parameter_list|,
name|var
parameter_list|,
name|perm
parameter_list|)
define|\
value|extern const char LINUXKPI_PARAM_DESC(name)[];			\ 	LINUXKPI_PARAM_PASS(SYSCTL_UINT(LINUXKPI_PARAM_PARENT, OID_AUTO, \ 	LINUXKPI_PARAM_NAME(name), LINUXKPI_PARAM_PERM(perm),&(var), 0, \ 	LINUXKPI_PARAM_DESC(name)))
end_define

begin_define
define|#
directive|define
name|LINUXKPI_PARAM_long
parameter_list|(
name|name
parameter_list|,
name|var
parameter_list|,
name|perm
parameter_list|)
define|\
value|extern const char LINUXKPI_PARAM_DESC(name)[];			\ 	LINUXKPI_PARAM_PASS(SYSCTL_LONG(LINUXKPI_PARAM_PARENT, OID_AUTO, \ 	LINUXKPI_PARAM_NAME(name), LINUXKPI_PARAM_PERM(perm),&(var), 0, \ 	LINUXKPI_PARAM_DESC(name)))
end_define

begin_define
define|#
directive|define
name|LINUXKPI_PARAM_ulong
parameter_list|(
name|name
parameter_list|,
name|var
parameter_list|,
name|perm
parameter_list|)
define|\
value|extern const char LINUXKPI_PARAM_DESC(name)[];			\ 	LINUXKPI_PARAM_PASS(SYSCTL_ULONG(LINUXKPI_PARAM_PARENT, OID_AUTO, \ 	LINUXKPI_PARAM_NAME(name), LINUXKPI_PARAM_PERM(perm),&(var), 0, \ 	LINUXKPI_PARAM_DESC(name)))
end_define

begin_define
define|#
directive|define
name|module_param_string
parameter_list|(
name|name
parameter_list|,
name|str
parameter_list|,
name|len
parameter_list|,
name|perm
parameter_list|)
define|\
value|extern const char LINUXKPI_PARAM_DESC(name)[];			\ 	LINUXKPI_PARAM_PASS(SYSCTL_STRING(LINUXKPI_PARAM_PARENT, OID_AUTO, \ 	LINUXKPI_PARAM_NAME(name), LINUXKPI_PARAM_PERM(perm), (str), (len), \ 	LINUXKPI_PARAM_DESC(name)))
end_define

begin_define
define|#
directive|define
name|module_param_named
parameter_list|(
name|name
parameter_list|,
name|var
parameter_list|,
name|type
parameter_list|,
name|mode
parameter_list|)
define|\
value|LINUXKPI_PARAM_##type(name, var, mode)
end_define

begin_define
define|#
directive|define
name|module_param
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|,
name|mode
parameter_list|)
define|\
value|LINUXKPI_PARAM_##type(var, var, mode)
end_define

begin_define
define|#
directive|define
name|module_param_named_unsafe
parameter_list|(
name|name
parameter_list|,
name|var
parameter_list|,
name|type
parameter_list|,
name|mode
parameter_list|)
define|\
value|LINUXKPI_PARAM_##type(name, var, mode)
end_define

begin_define
define|#
directive|define
name|module_param_unsafe
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|,
name|mode
parameter_list|)
define|\
value|LINUXKPI_PARAM_##type(var, var, mode)
end_define

begin_define
define|#
directive|define
name|module_param_array
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|,
name|addr_argc
parameter_list|,
name|mode
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MODULE_PARM_DESC
parameter_list|(
name|name
parameter_list|,
name|desc
parameter_list|)
define|\
value|const char LINUXKPI_PARAM_DESC(name)[] = { desc }
end_define

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_compat_linuxkpi
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_MODULEPARAM_H_ */
end_comment

end_unit

