begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1993-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * @(#)ipf.h	1.12 6/5/96  * $Id: ipf.h,v 2.9.2.6 2002/01/03 08:00:12 darrenr Exp $  */
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
name|OPT_OUTQUE
value|FR_OUTQUE
end_define

begin_comment
comment|/* 0x00004 */
end_comment

begin_define
define|#
directive|define
name|OPT_INQUE
value|FR_INQUE
end_define

begin_comment
comment|/* 0x00008 */
end_comment

begin_define
define|#
directive|define
name|OPT_LOG
value|FR_LOG
end_define

begin_comment
comment|/* 0x00010 */
end_comment

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
value|0x004000
end_define

begin_define
define|#
directive|define
name|OPT_PRINTFR
value|0x008000
end_define

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
name|OPT_AUTHSTATS
value|0x040000
end_define

begin_define
define|#
directive|define
name|OPT_RAW
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
name|OPT_NODO
value|0x80000000
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

begin_struct_decl
struct_decl|struct
name|ipstate
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|frpcmp
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ipnat
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nat
struct_decl|;
end_struct_decl

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
operator|,
name|int
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
name|int
name|portnum
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|u_short
operator|*
operator|,
name|int
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
name|char
modifier|*
name|proto
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|flagset
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|flags
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|tcp_flags
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|countbits
name|__P
argument_list|(
operator|(
name|u_32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ratoi
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ratoui
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|u_int
operator|*
operator|,
name|u_int
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hostmask
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|*
operator|,
name|u_32_t
operator|*
operator|,
name|u_32_t
operator|*
operator|,
name|u_short
operator|*
operator|,
name|int
operator|*
operator|,
name|u_short
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ports
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
operator|,
name|int
operator|*
operator|,
name|u_short
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|portname
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|int
name|genmask
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|u_32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hostnum
name|__P
argument_list|(
operator|(
name|u_32_t
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
operator|,
name|int
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

begin_decl_stmt
specifier|extern
name|void
name|printpacket6
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|printportcmp
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|frpcmp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|printhostmask
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_32_t
operator|*
operator|,
name|u_32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|printbuf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hostname
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ipstate
modifier|*
name|printstate
name|__P
argument_list|(
operator|(
expr|struct
name|ipstate
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|printnat
name|__P
argument_list|(
operator|(
expr|struct
name|ipnat
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|printactivenat
name|__P
argument_list|(
operator|(
expr|struct
name|nat
operator|*
operator|,
name|int
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

begin_decl_stmt
specifier|extern
name|int
name|gethostname
name|__P
argument_list|(
operator|(
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
name|void
name|sync
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

