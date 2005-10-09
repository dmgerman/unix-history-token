begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * Id: opts.h,v 2.12 2003/08/14 14:24:27 darrenr Exp  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OPTS_H__
end_ifndef

begin_define
define|#
directive|define
name|__OPTS_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SOLARIS
end_ifndef

begin_define
define|#
directive|define
name|SOLARIS
value|(defined(sun)&& (defined(__svr4__) || defined(__SVR4)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OPT_REMOVE
value|0x000001
end_define

begin_define
define|#
directive|define
name|OPT_DEBUG
value|0x000002
end_define

begin_define
define|#
directive|define
name|OPT_AUTHSTATS
value|0x000004
end_define

begin_define
define|#
directive|define
name|OPT_RAW
value|0x000008
end_define

begin_define
define|#
directive|define
name|OPT_LOG
value|0x000010
end_define

begin_define
define|#
directive|define
name|OPT_SHOWLIST
value|0x000020
end_define

begin_define
define|#
directive|define
name|OPT_VERBOSE
value|0x000040
end_define

begin_define
define|#
directive|define
name|OPT_DONOTHING
value|0x000080
end_define

begin_define
define|#
directive|define
name|OPT_HITS
value|0x000100
end_define

begin_define
define|#
directive|define
name|OPT_BRIEF
value|0x000200
end_define

begin_define
define|#
directive|define
name|OPT_ACCNT
value|0x000400
end_define

begin_define
define|#
directive|define
name|OPT_FRSTATES
value|0x000800
end_define

begin_define
define|#
directive|define
name|OPT_SHOWLINENO
value|0x001000
end_define

begin_define
define|#
directive|define
name|OPT_PRINTFR
value|0x002000
end_define

begin_define
define|#
directive|define
name|OPT_OUTQUE
value|FR_OUTQUE
end_define

begin_comment
comment|/* 0x4000 */
end_comment

begin_define
define|#
directive|define
name|OPT_INQUE
value|FR_INQUE
end_define

begin_comment
comment|/* 0x8000 */
end_comment

begin_define
define|#
directive|define
name|OPT_ZERORULEST
value|0x010000
end_define

begin_define
define|#
directive|define
name|OPT_SAVEOUT
value|0x020000
end_define

begin_define
define|#
directive|define
name|OPT_IPSTATES
value|0x040000
end_define

begin_define
define|#
directive|define
name|OPT_INACTIVE
value|0x080000
end_define

begin_define
define|#
directive|define
name|OPT_NAT
value|0x100000
end_define

begin_define
define|#
directive|define
name|OPT_GROUPS
value|0x200000
end_define

begin_define
define|#
directive|define
name|OPT_STATETOP
value|0x400000
end_define

begin_define
define|#
directive|define
name|OPT_FLUSH
value|0x800000
end_define

begin_define
define|#
directive|define
name|OPT_CLEAR
value|0x1000000
end_define

begin_define
define|#
directive|define
name|OPT_HEX
value|0x2000000
end_define

begin_define
define|#
directive|define
name|OPT_ASCII
value|0x4000000
end_define

begin_define
define|#
directive|define
name|OPT_NORESOLVE
value|0x8000000
end_define

begin_define
define|#
directive|define
name|OPT_STAT
value|OPT_FRSTATES
end_define

begin_define
define|#
directive|define
name|OPT_LIST
value|OPT_SHOWLIST
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|SOLARIS
end_if

begin_define
define|#
directive|define
name|STRERROR
parameter_list|(
name|x
parameter_list|)
value|sys_errlist[x]
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STRERROR
parameter_list|(
name|x
parameter_list|)
value|strerror(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|opts
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OPTS_H__ */
end_comment

end_unit

