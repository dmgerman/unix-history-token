begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 by  * Sean Eric Fagan<sef@kithrup.com>  * David Nugent<davidn@blaze.net.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, is permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. This work was done expressly for inclusion into FreeBSD.  Other use  *    is permitted provided this notation is included.  * 4. Absolutely no warranty of function or purpose is made by the authors.  * 5. Modifications may be freely made to this file providing the above  *    conditions are met.  *  * Low-level routines relating to the user capabilities database  *  *	Was login_cap.h,v 1.9 1997/05/07 20:00:01 eivind Exp  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOGIN_CAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_LOGIN_CAP_H_
end_define

begin_define
define|#
directive|define
name|LOGIN_DEFCLASS
value|"default"
end_define

begin_define
define|#
directive|define
name|LOGIN_DEFROOTCLASS
value|"root"
end_define

begin_define
define|#
directive|define
name|LOGIN_MECLASS
value|"me"
end_define

begin_define
define|#
directive|define
name|LOGIN_DEFSTYLE
value|"passwd"
end_define

begin_define
define|#
directive|define
name|LOGIN_DEFSERVICE
value|"login"
end_define

begin_define
define|#
directive|define
name|LOGIN_DEFUMASK
value|022
end_define

begin_define
define|#
directive|define
name|LOGIN_DEFPRI
value|0
end_define

begin_define
define|#
directive|define
name|_PATH_LOGIN_CONF
value|"/etc/login.conf"
end_define

begin_define
define|#
directive|define
name|_FILE_LOGIN_CONF
value|".login_conf"
end_define

begin_define
define|#
directive|define
name|_PATH_AUTHPROG
value|"/usr/libexec/login_"
end_define

begin_define
define|#
directive|define
name|LOGIN_SETGROUP
value|0x0001
end_define

begin_comment
comment|/* set group */
end_comment

begin_define
define|#
directive|define
name|LOGIN_SETLOGIN
value|0x0002
end_define

begin_comment
comment|/* set login (via setlogin) */
end_comment

begin_define
define|#
directive|define
name|LOGIN_SETPATH
value|0x0004
end_define

begin_comment
comment|/* set path */
end_comment

begin_define
define|#
directive|define
name|LOGIN_SETPRIORITY
value|0x0008
end_define

begin_comment
comment|/* set priority */
end_comment

begin_define
define|#
directive|define
name|LOGIN_SETRESOURCES
value|0x0010
end_define

begin_comment
comment|/* set resources (cputime, etc.) */
end_comment

begin_define
define|#
directive|define
name|LOGIN_SETUMASK
value|0x0020
end_define

begin_comment
comment|/* set umask, obviously */
end_comment

begin_define
define|#
directive|define
name|LOGIN_SETUSER
value|0x0040
end_define

begin_comment
comment|/* set user (via setuid) */
end_comment

begin_define
define|#
directive|define
name|LOGIN_SETENV
value|0x0080
end_define

begin_comment
comment|/* set user environment */
end_comment

begin_define
define|#
directive|define
name|LOGIN_SETALL
value|0x00ff
end_define

begin_comment
comment|/* set everything */
end_comment

begin_define
define|#
directive|define
name|BI_AUTH
value|"authorize"
end_define

begin_comment
comment|/* accepted authentication */
end_comment

begin_define
define|#
directive|define
name|BI_REJECT
value|"reject"
end_define

begin_comment
comment|/* rejected authentication */
end_comment

begin_define
define|#
directive|define
name|BI_CHALLENG
value|"reject challenge"
end_define

begin_comment
comment|/* reject with a challenge */
end_comment

begin_define
define|#
directive|define
name|BI_SILENT
value|"reject silent"
end_define

begin_comment
comment|/* reject silently */
end_comment

begin_define
define|#
directive|define
name|BI_REMOVE
value|"remove"
end_define

begin_comment
comment|/* remove file on error */
end_comment

begin_define
define|#
directive|define
name|BI_ROOTOKAY
value|"authorize root"
end_define

begin_comment
comment|/* root authenticated */
end_comment

begin_define
define|#
directive|define
name|BI_SECURE
value|"authorize secure"
end_define

begin_comment
comment|/* okay on non-secure line */
end_comment

begin_define
define|#
directive|define
name|BI_SETENV
value|"setenv"
end_define

begin_comment
comment|/* set environment variable */
end_comment

begin_define
define|#
directive|define
name|BI_VALUE
value|"value"
end_define

begin_comment
comment|/* set local variable */
end_comment

begin_define
define|#
directive|define
name|AUTH_OKAY
value|0x01
end_define

begin_comment
comment|/* user authenticated */
end_comment

begin_define
define|#
directive|define
name|AUTH_ROOTOKAY
value|0x02
end_define

begin_comment
comment|/* root login okay */
end_comment

begin_define
define|#
directive|define
name|AUTH_SECURE
value|0x04
end_define

begin_comment
comment|/* secure login */
end_comment

begin_define
define|#
directive|define
name|AUTH_SILENT
value|0x08
end_define

begin_comment
comment|/* silent rejection */
end_comment

begin_define
define|#
directive|define
name|AUTH_CHALLENGE
value|0x10
end_define

begin_comment
comment|/* a chellenge was given */
end_comment

begin_define
define|#
directive|define
name|AUTH_ALLOW
value|(AUTH_OKAY | AUTH_ROOTOKAY | AUTH_SECURE)
end_define

begin_typedef
typedef|typedef
struct|struct
name|login_cap
block|{
name|char
modifier|*
name|lc_class
decl_stmt|;
name|char
modifier|*
name|lc_cap
decl_stmt|;
name|char
modifier|*
name|lc_style
decl_stmt|;
block|}
name|login_cap_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|login_time
block|{
name|u_short
name|lt_start
decl_stmt|;
comment|/* Start time */
name|u_short
name|lt_end
decl_stmt|;
comment|/* End time */
define|#
directive|define
name|LTM_NONE
value|0x00
define|#
directive|define
name|LTM_SUN
value|0x01
define|#
directive|define
name|LTM_MON
value|0x02
define|#
directive|define
name|LTM_TUE
value|0x04
define|#
directive|define
name|LTM_WED
value|0x08
define|#
directive|define
name|LTM_THU
value|0x10
define|#
directive|define
name|LTM_FRI
value|0x20
define|#
directive|define
name|LTM_SAT
value|0x40
define|#
directive|define
name|LTM_ANY
value|0x7F
define|#
directive|define
name|LTM_WK
value|0x3E
define|#
directive|define
name|LTM_WD
value|0x41
name|u_char
name|lt_dow
decl_stmt|;
comment|/* Days of week */
block|}
name|login_time_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LC_MAXTIMES
value|64
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct_decl
struct_decl|struct
name|passwd
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|login_close
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|login_cap_t
modifier|*
name|login_getclassbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|passwd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|login_cap_t
modifier|*
name|login_getclass
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|login_cap_t
modifier|*
name|login_getpwclass
parameter_list|(
specifier|const
name|struct
name|passwd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|login_cap_t
modifier|*
name|login_getuserclass
parameter_list|(
specifier|const
name|struct
name|passwd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|login_getcapstr
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|login_getcaplist
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|login_getstyle
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rlim_t
name|login_getcaptime
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|rlim_t
parameter_list|,
name|rlim_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rlim_t
name|login_getcapnum
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|rlim_t
parameter_list|,
name|rlim_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rlim_t
name|login_getcapsize
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|rlim_t
parameter_list|,
name|rlim_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|login_getpath
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|login_getcapbool
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|login_setcryptfmt
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setclasscontext
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setusercontext
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|passwd
modifier|*
parameter_list|,
name|uid_t
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setclassresources
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setclassenvironment
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|passwd
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Most of these functions are deprecated */
end_comment

begin_function_decl
name|int
name|auth_approve
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_check
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|auth_env
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|auth_mkvalue
parameter_list|(
specifier|const
name|char
modifier|*
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_response
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|auth_rmfiles
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_scan
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_script
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_script_data
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|auth_valud
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_setopt
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|auth_clropts
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|auth_checknologin
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_cat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_ttyok
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_hostok
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_timeok
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|tm
struct_decl|;
end_struct_decl

begin_function_decl
name|login_time_t
name|parse_lt
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_ltm
parameter_list|(
specifier|const
name|login_time_t
modifier|*
parameter_list|,
name|struct
name|tm
modifier|*
parameter_list|,
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_ltms
parameter_list|(
specifier|const
name|login_time_t
modifier|*
parameter_list|,
name|struct
name|tm
modifier|*
parameter_list|,
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* helper functions */
end_comment

begin_function_decl
name|int
name|login_strinlist
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|login_str2inlist
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|login_time_t
modifier|*
name|login_timelist
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|login_time_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|login_ttyok
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|login_hostok
parameter_list|(
name|login_cap_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LOGIN_CAP_H_ */
end_comment

end_unit

