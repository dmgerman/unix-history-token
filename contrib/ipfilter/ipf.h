begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1993-1997 by Darren Reed.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and due credit is given  * to the original author and the contributors.  *  * @(#)ipf.h	1.12 6/5/96  * $Id: ipf.h,v 2.0.2.12 1997/09/28 07:11:50 darrenr Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IPF_H__
end_ifndef

begin_define
define|#
directive|define
name|__IPF_H__
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
value|0x00001
end_define

begin_define
define|#
directive|define
name|OPT_DEBUG
value|0x00002
end_define

begin_define
define|#
directive|define
name|OPT_OUTQUE
value|FR_OUTQUE
end_define

begin_comment
comment|/* 0x0004 */
end_comment

begin_define
define|#
directive|define
name|OPT_INQUE
value|FR_INQUE
end_define

begin_comment
comment|/* 0x0008 */
end_comment

begin_define
define|#
directive|define
name|OPT_LOG
value|FR_LOG
end_define

begin_comment
comment|/* 0x0010 */
end_comment

begin_define
define|#
directive|define
name|OPT_SHOWLIST
value|0x00020
end_define

begin_define
define|#
directive|define
name|OPT_VERBOSE
value|0x00040
end_define

begin_define
define|#
directive|define
name|OPT_DONOTHING
value|0x00080
end_define

begin_define
define|#
directive|define
name|OPT_HITS
value|0x00100
end_define

begin_define
define|#
directive|define
name|OPT_BRIEF
value|0x00200
end_define

begin_define
define|#
directive|define
name|OPT_ACCNT
value|FR_ACCOUNT
end_define

begin_comment
comment|/* 0x0400 */
end_comment

begin_define
define|#
directive|define
name|OPT_FRSTATES
value|FR_KEEPFRAG
end_define

begin_comment
comment|/* 0x0800 */
end_comment

begin_define
define|#
directive|define
name|OPT_IPSTATES
value|FR_KEEPSTATE
end_define

begin_comment
comment|/* 0x1000 */
end_comment

begin_define
define|#
directive|define
name|OPT_INACTIVE
value|FR_INACTIVE
end_define

begin_comment
comment|/* 0x2000 */
end_comment

begin_define
define|#
directive|define
name|OPT_SHOWLINENO
value|0x04000
end_define

begin_define
define|#
directive|define
name|OPT_PRINTFR
value|0x08000
end_define

begin_define
define|#
directive|define
name|OPT_ZERORULEST
value|0x10000
end_define

begin_define
define|#
directive|define
name|OPT_SAVEOUT
value|0x20000
end_define

begin_define
define|#
directive|define
name|OPT_AUTHSTATS
value|0x40000
end_define

begin_define
define|#
directive|define
name|OPT_RAW
value|0x80000
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

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strdup
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|frentry
modifier|*
name|parse
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|printfr
name|__P
argument_list|(
operator|(
expr|struct
name|frentry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|binprint
name|__P
argument_list|(
operator|(
expr|struct
name|frentry
operator|*
operator|)
argument_list|)
decl_stmt|,
name|initparse
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|portnum
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|ipopt_names
block|{
name|int
name|on_value
decl_stmt|;
name|int
name|on_bit
decl_stmt|;
name|int
name|on_siz
decl_stmt|;
name|char
modifier|*
name|on_name
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|u_32_t
name|buildopts
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_32_t
name|hostnum
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_32_t
name|optname
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|*
operator|,
name|u_short
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|printpacket
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|SOLARIS
end_if

begin_decl_stmt
specifier|extern
name|int
name|inet_aton
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

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

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (b) : (a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IPF_H__ */
end_comment

end_unit

