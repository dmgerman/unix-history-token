begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1993-1997 by Darren Reed.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and due credit is given  * to the original author and the contributors.  *  * @(#)ip_fil.h	1.35 6/5/96  * $Id: ip_fil.h,v 2.0.2.39.2.4 1997/11/12 10:50:02 darrenr Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IP_FIL_H__
end_ifndef

begin_define
define|#
directive|define
name|__IP_FIL_H__
end_define

begin_comment
comment|/*  * Pathnames for various IP Filter control devices.  Used by LKM  * and userland, so defined here.  */
end_comment

begin_define
define|#
directive|define
name|IPNAT_NAME
value|"/dev/ipnat"
end_define

begin_define
define|#
directive|define
name|IPSTATE_NAME
value|"/dev/ipstate"
end_define

begin_define
define|#
directive|define
name|IPAUTH_NAME
value|"/dev/ipauth"
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_KERNEL
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIOCADAFR
value|_IOW('r', 60, struct frentry)
end_define

begin_define
define|#
directive|define
name|SIOCRMAFR
value|_IOW('r', 61, struct frentry)
end_define

begin_define
define|#
directive|define
name|SIOCSETFF
value|_IOW('r', 62, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCGETFF
value|_IOR('r', 63, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCGETFS
value|_IOR('r', 64, struct friostat)
end_define

begin_define
define|#
directive|define
name|SIOCIPFFL
value|_IOWR('r', 65, int)
end_define

begin_define
define|#
directive|define
name|SIOCIPFFB
value|_IOR('r', 66, int)
end_define

begin_define
define|#
directive|define
name|SIOCADIFR
value|_IOW('r', 67, struct frentry)
end_define

begin_define
define|#
directive|define
name|SIOCRMIFR
value|_IOW('r', 68, struct frentry)
end_define

begin_define
define|#
directive|define
name|SIOCSWAPA
value|_IOR('r', 69, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCINAFR
value|_IOW('r', 70, struct frentry)
end_define

begin_define
define|#
directive|define
name|SIOCINIFR
value|_IOW('r', 71, struct frentry)
end_define

begin_define
define|#
directive|define
name|SIOCFRENB
value|_IOW('r', 72, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCFRSYN
value|_IOW('r', 73, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCFRZST
value|_IOWR('r', 74, struct friostat)
end_define

begin_define
define|#
directive|define
name|SIOCZRLST
value|_IOWR('r', 75, struct frentry)
end_define

begin_define
define|#
directive|define
name|SIOCAUTHW
value|_IOWR('r', 76, struct fr_info)
end_define

begin_define
define|#
directive|define
name|SIOCAUTHR
value|_IOWR('r', 77, struct fr_info)
end_define

begin_define
define|#
directive|define
name|SIOCATHST
value|_IOWR('r', 78, struct fr_authstat)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIOCADAFR
value|_IOW(r, 60, struct frentry)
end_define

begin_define
define|#
directive|define
name|SIOCRMAFR
value|_IOW(r, 61, struct frentry)
end_define

begin_define
define|#
directive|define
name|SIOCSETFF
value|_IOW(r, 62, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCGETFF
value|_IOR(r, 63, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCGETFS
value|_IOR(r, 64, struct friostat)
end_define

begin_define
define|#
directive|define
name|SIOCIPFFL
value|_IOWR(r, 65, int)
end_define

begin_define
define|#
directive|define
name|SIOCIPFFB
value|_IOR(r, 66, int)
end_define

begin_define
define|#
directive|define
name|SIOCADIFR
value|_IOW(r, 67, struct frentry)
end_define

begin_define
define|#
directive|define
name|SIOCRMIFR
value|_IOW(r, 68, struct frentry)
end_define

begin_define
define|#
directive|define
name|SIOCSWAPA
value|_IOR(r, 69, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCINAFR
value|_IOW(r, 70, struct frentry)
end_define

begin_define
define|#
directive|define
name|SIOCINIFR
value|_IOW(r, 71, struct frentry)
end_define

begin_define
define|#
directive|define
name|SIOCFRENB
value|_IOW(r, 72, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCFRSYN
value|_IOW(r, 73, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCFRZST
value|_IOWR(r, 74, struct friostat)
end_define

begin_define
define|#
directive|define
name|SIOCZRLST
value|_IOWR(r, 75, struct frentry)
end_define

begin_define
define|#
directive|define
name|SIOCAUTHW
value|_IOWR(r, 76, struct fr_info)
end_define

begin_define
define|#
directive|define
name|SIOCAUTHR
value|_IOWR(r, 77, struct fr_info)
end_define

begin_define
define|#
directive|define
name|SIOCATHST
value|_IOWR(r, 78, struct fr_authstat)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIOCADDFR
value|SIOCADAFR
end_define

begin_define
define|#
directive|define
name|SIOCDELFR
value|SIOCRMAFR
end_define

begin_define
define|#
directive|define
name|SIOCINSFR
value|SIOCINAFR
end_define

begin_typedef
typedef|typedef
struct|struct
name|fr_ip
block|{
name|u_char
name|fi_v
range|:
literal|4
decl_stmt|;
comment|/* IP version */
name|u_char
name|fi_fl
range|:
literal|4
decl_stmt|;
comment|/* packet flags */
name|u_char
name|fi_tos
decl_stmt|;
name|u_char
name|fi_ttl
decl_stmt|;
name|u_char
name|fi_p
decl_stmt|;
name|struct
name|in_addr
name|fi_src
decl_stmt|;
name|struct
name|in_addr
name|fi_dst
decl_stmt|;
name|u_32_t
name|fi_optmsk
decl_stmt|;
comment|/* bitmask composed from IP options */
name|u_short
name|fi_secmsk
decl_stmt|;
comment|/* bitmask composed from IP security options */
name|u_short
name|fi_auth
decl_stmt|;
block|}
name|fr_ip_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FI_OPTIONS
value|0x01
end_define

begin_define
define|#
directive|define
name|FI_TCPUDP
value|0x02
end_define

begin_comment
comment|/* TCP/UCP implied comparison involved */
end_comment

begin_define
define|#
directive|define
name|FI_FRAG
value|0x04
end_define

begin_define
define|#
directive|define
name|FI_SHORT
value|0x08
end_define

begin_typedef
typedef|typedef
struct|struct
name|fr_info
block|{
name|struct
name|fr_ip
name|fin_fi
decl_stmt|;
name|u_short
name|fin_data
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|fin_out
decl_stmt|;
name|u_short
name|fin_hlen
decl_stmt|;
name|u_char
name|fin_tcpf
decl_stmt|;
name|u_char
name|fin_icode
decl_stmt|;
comment|/* From here on is packet specific */
name|u_short
name|fin_rule
decl_stmt|;
name|u_short
name|fin_group
decl_stmt|;
name|u_short
name|fin_dlen
decl_stmt|;
name|u_short
name|fin_id
decl_stmt|;
name|void
modifier|*
name|fin_ifp
decl_stmt|;
name|struct
name|frentry
modifier|*
name|fin_fr
decl_stmt|;
name|char
modifier|*
name|fin_dp
decl_stmt|;
comment|/* start of data past IP header */
name|void
modifier|*
name|fin_mp
decl_stmt|;
block|}
name|fr_info_t
typedef|;
end_typedef

begin_comment
comment|/*  * Size for compares on fr_info structures  */
end_comment

begin_define
define|#
directive|define
name|FI_CSIZE
value|(sizeof(struct fr_ip) + sizeof(u_short) * 4 + \ 			 sizeof(u_char))
end_define

begin_comment
comment|/*  * Size for copying cache fr_info structure  */
end_comment

begin_define
define|#
directive|define
name|FI_COPYSIZE
value|(sizeof(fr_info_t) - sizeof(void *) * 2)
end_define

begin_typedef
typedef|typedef
struct|struct
name|frdest
block|{
name|void
modifier|*
name|fd_ifp
decl_stmt|;
name|struct
name|in_addr
name|fd_ip
decl_stmt|;
name|char
name|fd_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
name|frdest_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|frentry
block|{
name|struct
name|frentry
modifier|*
name|fr_next
decl_stmt|;
name|u_short
name|fr_group
decl_stmt|;
comment|/* group to which this rule belongs */
name|u_short
name|fr_grhead
decl_stmt|;
comment|/* group # which this rule starts */
name|struct
name|frentry
modifier|*
name|fr_grp
decl_stmt|;
name|int
name|fr_ref
decl_stmt|;
comment|/* reference count - for grouping */
name|void
modifier|*
name|fr_ifa
decl_stmt|;
comment|/* 	 * These are only incremented when a packet  matches this rule and 	 * it is the last match 	 */
name|U_QUAD_T
name|fr_hits
decl_stmt|;
name|U_QUAD_T
name|fr_bytes
decl_stmt|;
comment|/* 	 * Fields after this may not change whilst in the kernel. 	 */
name|struct
name|fr_ip
name|fr_ip
decl_stmt|;
name|struct
name|fr_ip
name|fr_mip
decl_stmt|;
comment|/* mask structure */
name|u_char
name|fr_tcpfm
decl_stmt|;
comment|/* tcp flags mask */
name|u_char
name|fr_tcpf
decl_stmt|;
comment|/* tcp flags */
name|u_short
name|fr_icmpm
decl_stmt|;
comment|/* data for ICMP packets (mask) */
name|u_short
name|fr_icmp
decl_stmt|;
name|u_char
name|fr_scmp
decl_stmt|;
comment|/* data for port comparisons */
name|u_char
name|fr_dcmp
decl_stmt|;
name|u_short
name|fr_dport
decl_stmt|;
name|u_short
name|fr_sport
decl_stmt|;
name|u_short
name|fr_stop
decl_stmt|;
comment|/* top port for<> and>< */
name|u_short
name|fr_dtop
decl_stmt|;
comment|/* top port for<> and>< */
name|u_32_t
name|fr_flags
decl_stmt|;
comment|/* per-rule flags&& options (see below) */
name|int
name|fr_skip
decl_stmt|;
comment|/* # of rules to skip */
name|int
argument_list|(
argument|*fr_func
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|,
name|ip_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* call this function */
name|char
name|fr_icode
decl_stmt|;
comment|/* return ICMP code */
name|char
name|fr_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|struct
name|frdest
name|fr_tif
decl_stmt|;
comment|/* "to" interface */
name|struct
name|frdest
name|fr_dif
decl_stmt|;
comment|/* duplicate packet interfaces */
block|}
name|frentry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fr_proto
value|fr_ip.fi_p
end_define

begin_define
define|#
directive|define
name|fr_ttl
value|fr_ip.fi_ttl
end_define

begin_define
define|#
directive|define
name|fr_tos
value|fr_ip.fi_tos
end_define

begin_define
define|#
directive|define
name|fr_dst
value|fr_ip.fi_dst
end_define

begin_define
define|#
directive|define
name|fr_src
value|fr_ip.fi_src
end_define

begin_define
define|#
directive|define
name|fr_dmsk
value|fr_mip.fi_dst
end_define

begin_define
define|#
directive|define
name|fr_smsk
value|fr_mip.fi_src
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|offsetof
end_ifndef

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|)
value|(int)((&((t *)0L)->m))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FR_CMPSIZ
value|(sizeof(struct frentry) - offsetof(frentry_t, fr_ip))
end_define

begin_comment
comment|/*  * fr_flags  */
end_comment

begin_define
define|#
directive|define
name|FR_BLOCK
value|0x00001
end_define

begin_comment
comment|/* do not allow packet to pass */
end_comment

begin_define
define|#
directive|define
name|FR_PASS
value|0x00002
end_define

begin_comment
comment|/* allow packet to pass */
end_comment

begin_define
define|#
directive|define
name|FR_OUTQUE
value|0x00004
end_define

begin_comment
comment|/* outgoing packets */
end_comment

begin_define
define|#
directive|define
name|FR_INQUE
value|0x00008
end_define

begin_comment
comment|/* ingoing packets */
end_comment

begin_define
define|#
directive|define
name|FR_LOG
value|0x00010
end_define

begin_comment
comment|/* Log */
end_comment

begin_define
define|#
directive|define
name|FR_LOGB
value|0x00011
end_define

begin_comment
comment|/* Log-fail */
end_comment

begin_define
define|#
directive|define
name|FR_LOGP
value|0x00012
end_define

begin_comment
comment|/* Log-pass */
end_comment

begin_define
define|#
directive|define
name|FR_LOGBODY
value|0x00020
end_define

begin_comment
comment|/* Log the body */
end_comment

begin_define
define|#
directive|define
name|FR_LOGFIRST
value|0x00040
end_define

begin_comment
comment|/* Log the first byte if state held */
end_comment

begin_define
define|#
directive|define
name|FR_RETRST
value|0x00080
end_define

begin_comment
comment|/* Return TCP RST packet - reset connection */
end_comment

begin_define
define|#
directive|define
name|FR_RETICMP
value|0x00100
end_define

begin_comment
comment|/* Return ICMP unreachable packet */
end_comment

begin_define
define|#
directive|define
name|FR_NOMATCH
value|0x00200
end_define

begin_comment
comment|/* no match occured */
end_comment

begin_define
define|#
directive|define
name|FR_ACCOUNT
value|0x00400
end_define

begin_comment
comment|/* count packet bytes */
end_comment

begin_define
define|#
directive|define
name|FR_KEEPFRAG
value|0x00800
end_define

begin_comment
comment|/* keep fragment information */
end_comment

begin_define
define|#
directive|define
name|FR_KEEPSTATE
value|0x01000
end_define

begin_comment
comment|/* keep `connection' state information */
end_comment

begin_define
define|#
directive|define
name|FR_INACTIVE
value|0x02000
end_define

begin_define
define|#
directive|define
name|FR_QUICK
value|0x04000
end_define

begin_comment
comment|/* match& stop processing list */
end_comment

begin_define
define|#
directive|define
name|FR_FASTROUTE
value|0x08000
end_define

begin_comment
comment|/* bypass normal routing */
end_comment

begin_define
define|#
directive|define
name|FR_CALLNOW
value|0x10000
end_define

begin_comment
comment|/* call another function (fr_func) if matches */
end_comment

begin_define
define|#
directive|define
name|FR_DUP
value|0x20000
end_define

begin_comment
comment|/* duplicate packet */
end_comment

begin_define
define|#
directive|define
name|FR_LOGORBLOCK
value|0x40000
end_define

begin_comment
comment|/* block the packet if it can't be logged */
end_comment

begin_define
define|#
directive|define
name|FR_NOTSRCIP
value|0x80000
end_define

begin_comment
comment|/* not the src IP# */
end_comment

begin_define
define|#
directive|define
name|FR_NOTDSTIP
value|0x100000
end_define

begin_comment
comment|/* not the dst IP# */
end_comment

begin_define
define|#
directive|define
name|FR_AUTH
value|0x200000
end_define

begin_comment
comment|/* use authentication */
end_comment

begin_define
define|#
directive|define
name|FR_PREAUTH
value|0x400000
end_define

begin_comment
comment|/* require preauthentication */
end_comment

begin_define
define|#
directive|define
name|FR_LOGMASK
value|(FR_LOG|FR_LOGP|FR_LOGB)
end_define

begin_comment
comment|/*  * These correspond to #define's for FI_* and are stored in fr_flags  */
end_comment

begin_define
define|#
directive|define
name|FF_OPTIONS
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FF_TCPUDP
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FF_FRAG
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FF_SHORT
value|0x08000000
end_define

begin_comment
comment|/*  * recognized flags for SIOCGETFF and SIOCSETFF, and get put in fr_flags  */
end_comment

begin_define
define|#
directive|define
name|FF_LOGPASS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FF_LOGBLOCK
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FF_LOGNOMATCH
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FF_LOGGING
value|(FF_LOGPASS|FF_LOGBLOCK|FF_LOGNOMATCH)
end_define

begin_define
define|#
directive|define
name|FF_BLOCKNONIP
value|0x80000000
end_define

begin_comment
comment|/* Solaris2 Only */
end_comment

begin_define
define|#
directive|define
name|FR_NONE
value|0
end_define

begin_define
define|#
directive|define
name|FR_EQUAL
value|1
end_define

begin_define
define|#
directive|define
name|FR_NEQUAL
value|2
end_define

begin_define
define|#
directive|define
name|FR_LESST
value|3
end_define

begin_define
define|#
directive|define
name|FR_GREATERT
value|4
end_define

begin_define
define|#
directive|define
name|FR_LESSTE
value|5
end_define

begin_define
define|#
directive|define
name|FR_GREATERTE
value|6
end_define

begin_define
define|#
directive|define
name|FR_OUTRANGE
value|7
end_define

begin_define
define|#
directive|define
name|FR_INRANGE
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
name|filterstats
block|{
name|u_long
name|fr_pass
decl_stmt|;
comment|/* packets allowed */
name|u_long
name|fr_block
decl_stmt|;
comment|/* packets denied */
name|u_long
name|fr_nom
decl_stmt|;
comment|/* packets which don't match any rule */
name|u_long
name|fr_ppkl
decl_stmt|;
comment|/* packets allowed and logged */
name|u_long
name|fr_bpkl
decl_stmt|;
comment|/* packets denied and logged */
name|u_long
name|fr_npkl
decl_stmt|;
comment|/* packets unmatched and logged */
name|u_long
name|fr_pkl
decl_stmt|;
comment|/* packets logged */
name|u_long
name|fr_skip
decl_stmt|;
comment|/* packets to be logged but buffer full */
name|u_long
name|fr_ret
decl_stmt|;
comment|/* packets for which a return is sent */
name|u_long
name|fr_acct
decl_stmt|;
comment|/* packets for which counting was performed */
name|u_long
name|fr_bnfr
decl_stmt|;
comment|/* bad attempts to allocate fragment state */
name|u_long
name|fr_nfr
decl_stmt|;
comment|/* new fragment state kept */
name|u_long
name|fr_cfr
decl_stmt|;
comment|/* add new fragment state but complete pkt */
name|u_long
name|fr_bads
decl_stmt|;
comment|/* bad attempts to allocate packet state */
name|u_long
name|fr_ads
decl_stmt|;
comment|/* new packet state kept */
name|u_long
name|fr_chit
decl_stmt|;
comment|/* cached hit */
name|u_long
name|fr_tcpbad
decl_stmt|;
comment|/* TCP checksum check failures */
name|u_long
name|fr_pull
index|[
literal|2
index|]
decl_stmt|;
comment|/* good and bad pullup attempts */
if|#
directive|if
name|SOLARIS
name|u_long
name|fr_bad
decl_stmt|;
comment|/* bad IP packets to the filter */
name|u_long
name|fr_notip
decl_stmt|;
comment|/* packets passed through no on ip queue */
name|u_long
name|fr_drop
decl_stmt|;
comment|/* packets dropped - no info for them! */
endif|#
directive|endif
block|}
name|filterstats_t
typedef|;
end_typedef

begin_comment
comment|/*  * For SIOCGETFS  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|friostat
block|{
name|struct
name|filterstats
name|f_st
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|frentry
modifier|*
name|f_fin
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|frentry
modifier|*
name|f_fout
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|frentry
modifier|*
name|f_acctin
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|frentry
modifier|*
name|f_acctout
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|frentry
modifier|*
name|f_auth
decl_stmt|;
name|u_long
name|f_froute
index|[
literal|2
index|]
decl_stmt|;
name|int
name|f_active
decl_stmt|;
block|}
name|friostat_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|optlist
block|{
name|u_short
name|ol_val
decl_stmt|;
name|int
name|ol_bit
decl_stmt|;
block|}
name|optlist_t
typedef|;
end_typedef

begin_comment
comment|/*  * Group list structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|frgroup
block|{
name|u_short
name|fg_num
decl_stmt|;
name|struct
name|frgroup
modifier|*
name|fg_next
decl_stmt|;
name|struct
name|frentry
modifier|*
name|fg_head
decl_stmt|;
name|struct
name|frentry
modifier|*
modifier|*
name|fg_start
decl_stmt|;
block|}
name|frgroup_t
typedef|;
end_typedef

begin_comment
comment|/*  * Log structure.  Each packet header logged is prepended by one of these.  * Following this in the log records read from the device will be an ipflog  * structure which is then followed by any packet data.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|iplog
block|{
name|u_long
name|ipl_magic
decl_stmt|;
name|u_long
name|ipl_sec
decl_stmt|;
name|u_long
name|ipl_usec
decl_stmt|;
name|u_int
name|ipl_len
decl_stmt|;
name|u_int
name|ipl_count
decl_stmt|;
name|size_t
name|ipl_dsize
decl_stmt|;
name|struct
name|iplog
modifier|*
name|ipl_next
decl_stmt|;
block|}
name|iplog_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPL_MAGIC
value|0x49504c4d
end_define

begin_comment
comment|/* 'IPLM' */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ipflog
block|{
if|#
directive|if
operator|(
name|defined
argument_list|(
name|NetBSD
argument_list|)
operator|&&
operator|(
name|NetBSD
operator|<=
literal|1991011
operator|)
operator|&&
operator|(
name|NetBSD
operator|>=
literal|199603
operator|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|OpenBSD
argument_list|)
operator|&&
operator|(
name|OpenBSD
operator|>=
literal|199603
operator|)
operator|)
name|u_char
name|fl_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
else|#
directive|else
name|u_int
name|fl_unit
decl_stmt|;
name|u_char
name|fl_ifname
index|[
literal|4
index|]
decl_stmt|;
endif|#
directive|endif
name|u_char
name|fl_plen
decl_stmt|;
comment|/* extra data after hlen */
name|u_char
name|fl_hlen
decl_stmt|;
comment|/* length of IP headers saved */
name|u_short
name|fl_rule
decl_stmt|;
comment|/* assume never more than 64k rules, total */
name|u_short
name|fl_group
decl_stmt|;
name|u_32_t
name|fl_flags
decl_stmt|;
block|}
name|ipflog_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_FILTER
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_FILTER
value|13
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPF_LOGGING
end_ifndef

begin_define
define|#
directive|define
name|IPF_LOGGING
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPF_DEFAULT_PASS
end_ifndef

begin_define
define|#
directive|define
name|IPF_DEFAULT_PASS
value|FR_PASS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IPMINLEN
parameter_list|(
name|i
parameter_list|,
name|h
parameter_list|)
value|((i)->ip_len>= ((i)->ip_hl * 4 + sizeof(struct h)))
end_define

begin_define
define|#
directive|define
name|IPLLOGSIZE
value|8192
end_define

begin_comment
comment|/*  * Device filenames for reading log information.  Use ipf on Solaris2 because  * ipl is already a name used by something else.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IPL_NAME
end_ifndef

begin_if
if|#
directive|if
name|SOLARIS
end_if

begin_define
define|#
directive|define
name|IPL_NAME
value|"/dev/ipf"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IPL_NAME
value|"/dev/ipl"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IPL_NAT
value|IPNAT_NAME
end_define

begin_define
define|#
directive|define
name|IPL_STATE
value|IPSTATE_NAME
end_define

begin_define
define|#
directive|define
name|IPL_AUTH
value|IPAUTH_NAME
end_define

begin_define
define|#
directive|define
name|IPL_LOGIPF
value|0
end_define

begin_comment
comment|/* Minor device #'s for accessing logs */
end_comment

begin_define
define|#
directive|define
name|IPL_LOGNAT
value|1
end_define

begin_define
define|#
directive|define
name|IPL_LOGSTATE
value|2
end_define

begin_define
define|#
directive|define
name|IPL_LOGAUTH
value|3
end_define

begin_define
define|#
directive|define
name|IPL_LOGMAX
value|3
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CDEV_MAJOR
argument_list|)
operator|&&
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
expr|\
operator|(
name|__FreeBSD_version
operator|>=
literal|220000
operator|)
end_if

begin_define
define|#
directive|define
name|CDEV_MAJOR
value|79
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|fr_check
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|mb_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern	int	(*fr_checkp
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|mb_t
operator|*
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|send_reset
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|icmp_error
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_log
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
name|void
name|ipfr_fastroute
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|,
name|frdest_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ifnet
modifier|*
name|get_unit
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FR_SCANLIST
parameter_list|(
name|p
parameter_list|,
name|ip
parameter_list|,
name|fi
parameter_list|,
name|m
parameter_list|)
value|fr_scanlist(p, ip, fi, m)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|u_long
operator|,
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|caddr_t
operator|,
name|int
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
name|int
name|iplopen
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplclose
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* #ifndef _KERNEL */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|PFIL_HOOKS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|ipfilterattach
name|__P
argument_list|(
operator|(
name|int
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
name|int
name|iplattach
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
name|ipl_enable
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
name|ipl_disable
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
name|void
name|ipflog_init
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
name|ipflog_clear
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipflog_read
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|uio
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipflog
name|__P
argument_list|(
operator|(
name|u_int
operator|,
name|ip_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|,
name|mb_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipllog
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_long
operator|,
name|void
operator|*
operator|*
operator|,
name|size_t
operator|*
operator|,
name|int
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
name|fr_check
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|qif_t
operator|*
operator|,
name|mb_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern	int	(*fr_checkp
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|qif_t
operator|*
operator|,
name|mb_t
operator|*
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|icmp_error
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|qif_t
operator|*
operator|,
expr|struct
name|in_addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|cred_t
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
name|int
name|iplopen
name|__P
argument_list|(
operator|(
name|dev_t
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|cred_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplclose
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|int
operator|,
name|cred_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipfsync
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
name|send_reset
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|qif_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipfr_fastroute
name|__P
argument_list|(
operator|(
name|qif_t
operator|*
operator|,
name|ip_t
operator|*
operator|,
name|mblk_t
operator|*
operator|,
name|mblk_t
operator|*
operator|*
operator|,
name|fr_info_t
operator|*
operator|,
name|frdest_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|copyin_mblk
name|__P
argument_list|(
operator|(
name|mblk_t
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|copyout_mblk
name|__P
argument_list|(
operator|(
name|mblk_t
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_qin
name|__P
argument_list|(
operator|(
name|queue_t
operator|*
operator|,
name|mblk_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_qout
name|__P
argument_list|(
operator|(
name|queue_t
operator|*
operator|,
name|mblk_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|IPFILTER_LOG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|iplread
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
expr|struct
name|uio
operator|*
operator|,
name|cred_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SOLARIS */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fr_check
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|mb_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern	int	(*fr_checkp
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|mb_t
operator|*
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|send_reset
name|__P
argument_list|(
operator|(
expr|struct
name|tcpiphdr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipfr_fastroute
name|__P
argument_list|(
operator|(
name|mb_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|,
name|frdest_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|mbufchainlen
name|__P
argument_list|(
operator|(
name|mb_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__sgi
end_ifdef

begin_include
include|#
directive|include
file|<sys/cred.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|caddr_t
operator|,
name|int
operator|,
name|cred_t
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
name|int
name|iplopen
name|__P
argument_list|(
operator|(
name|dev_t
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|cred_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplclose
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|int
operator|,
name|cred_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplread
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
expr|struct
name|uio
operator|*
operator|,
name|cred_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipfsync
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
name|ipfilter_sgi_attach
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
name|void
name|ipfilter_sgi_detach
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
name|void
name|ipfilter_sgi_intfsync
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|IPFILTER_LKM
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|iplidentify
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

begin_if
if|#
directive|if
operator|(
name|_BSDI_VERSION
operator|>=
literal|199510
operator|)
operator|||
operator|(
name|__FreeBSD_version
operator|>=
literal|220000
operator|)
operator|||
expr|\
operator|(
name|NetBSD
operator|>=
literal|199511
operator|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|u_long
operator|,
name|caddr_t
operator|,
name|int
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|caddr_t
operator|,
name|int
operator|,
expr|struct
name|proc
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
name|int
name|iplopen
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplclose
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|u_long
operator|,
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __OpenBSD__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|linux
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|int
name|iplioctl
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|file
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OpenBSD__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|linux
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|iplopen
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplclose
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|iplopen
name|__P
argument_list|(
operator|(
expr|struct
name|inode
operator|*
operator|,
expr|struct
name|file
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|iplclose
name|__P
argument_list|(
operator|(
expr|struct
name|inode
operator|*
operator|,
expr|struct
name|file
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !linux */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (_BSDI_VERSION>= 199510) */
end_comment

begin_if
if|#
directive|if
name|BSD
operator|>=
literal|199306
end_if

begin_decl_stmt
specifier|extern
name|int
name|iplread
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
expr|struct
name|uio
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|linux
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|iplread
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
expr|struct
name|uio
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|int
name|iplread
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|file
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !linux */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD>= 199306 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ sgi */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _KERNEL */
end_comment

begin_comment
comment|/*  * Post NetBSD 1.2 has the PFIL interface for packet filters.  This turns  * on those hooks.  We don't need any special mods in non-IP Filter code  * with this!  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|NetBSD
argument_list|)
operator|&&
operator|(
name|NetBSD
operator|>
literal|199609
operator|)
operator|&&
operator|(
name|NetBSD
operator|<=
literal|1991011
operator|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|NetBSD1_2
argument_list|)
operator|&&
name|NetBSD1_2
operator|>
literal|1
operator|)
end_if

begin_define
define|#
directive|define
name|NETBSD_PF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|ipldetach
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
name|fr_tcpsum
name|__P
argument_list|(
operator|(
name|mb_t
operator|*
operator|,
name|ip_t
operator|*
operator|,
name|tcphdr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FR_SCANLIST
parameter_list|(
name|p
parameter_list|,
name|ip
parameter_list|,
name|fi
parameter_list|,
name|m
parameter_list|)
value|fr_scanlist(p, ip, fi, m)
end_define

begin_decl_stmt
specifier|extern
name|int
name|fr_scanlist
name|__P
argument_list|(
operator|(
name|int
operator|,
name|ip_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|ipf_cksum
name|__P
argument_list|(
operator|(
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
name|fr_copytolog
name|__P
argument_list|(
operator|(
name|int
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
name|void
name|frflush
name|__P
argument_list|(
operator|(
name|int
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|frgroup_t
modifier|*
name|fr_addgroup
name|__P
argument_list|(
operator|(
name|u_short
operator|,
name|frentry_t
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
name|frgroup_t
modifier|*
name|fr_findgroup
name|__P
argument_list|(
operator|(
name|u_short
operator|,
name|u_32_t
operator|,
name|int
operator|,
name|int
operator|,
name|frgroup_t
operator|*
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_delgroup
name|__P
argument_list|(
operator|(
name|u_short
operator|,
name|u_32_t
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
name|ipl_unreach
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipl_inited
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|ipl_frouteok
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_pass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_active
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fr_info_t
name|frcache
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|IPFILTER_LOG
end_ifdef

begin_decl_stmt
specifier|extern
name|iplog_t
modifier|*
modifier|*
name|iplh
index|[
name|IPL_LOGMAX
operator|+
literal|1
index|]
decl_stmt|,
modifier|*
name|iplt
index|[
name|IPL_LOGMAX
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplused
index|[
name|IPL_LOGMAX
operator|+
literal|1
index|]
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
name|ipfilter
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|,
modifier|*
name|ipacct
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|frgroup
modifier|*
name|ipfgroups
index|[
literal|3
index|]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|filterstats
name|frstats
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IP_FIL_H__ */
end_comment

end_unit

