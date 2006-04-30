begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1993-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * @(#)ip_fil.h	1.35 6/5/96  * Id: ip_scan.h,v 2.9 2003/07/25 22:05:01 darrenr Exp  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IP_SCAN_H__
end_ifndef

begin_define
define|#
directive|define
name|__IP_SCAN_H__
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IPSCAN_NAME
value|"/dev/ipscan"
end_define

begin_define
define|#
directive|define
name|IPL_SCAN
value|IPSCAN_NAME
end_define

begin_define
define|#
directive|define
name|ISC_TLEN
value|16
end_define

begin_struct_decl
struct_decl|struct
name|fr_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|frentry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ip
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ipstate
struct_decl|;
end_struct_decl

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
name|SIOCADSCA
value|_IOWR('r', 60, struct ipscan *)
end_define

begin_define
define|#
directive|define
name|SIOCRMSCA
value|_IOWR('r', 61, struct ipscan *)
end_define

begin_define
define|#
directive|define
name|SIOCGSCST
value|_IOWR('r', 62, struct ipscan *)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIOCADSCA
value|_IOWR(r, 60, struct ipscan *)
end_define

begin_define
define|#
directive|define
name|SIOCRMSCA
value|_IOWR(r, 61, struct ipscan *)
end_define

begin_define
define|#
directive|define
name|SIOCGSCST
value|_IOWR(r, 62, struct ipscan *)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|action
block|{
name|int
name|act_val
decl_stmt|;
comment|/* what to do */
name|struct
name|in_addr
name|act_ip
decl_stmt|;
comment|/* redirect IP# */
name|u_short
name|act_port
decl_stmt|;
comment|/* redirect port number */
name|int
name|act_else
decl_stmt|;
comment|/* what to do */
name|struct
name|in_addr
name|act_eip
decl_stmt|;
comment|/* redirect IP# */
name|u_short
name|act_eport
decl_stmt|;
comment|/* redirect port number */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|sinfo
block|{
name|char
name|s_txt
index|[
name|ISC_TLEN
index|]
decl_stmt|;
comment|/* text to match */
name|char
name|s_msk
index|[
name|ISC_TLEN
index|]
decl_stmt|;
comment|/* mask of the above to check */
name|int
name|s_len
decl_stmt|;
comment|/* length of server text */
block|}
name|sinfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ipscan
block|{
name|struct
name|ipscan
modifier|*
name|ipsc_next
decl_stmt|;
name|struct
name|ipscan
modifier|*
modifier|*
name|ipsc_pnext
decl_stmt|;
name|char
name|ipsc_tag
index|[
name|ISC_TLEN
index|]
decl_stmt|;
comment|/* table entry protocol tag */
name|sinfo_t
name|ipsc_si
index|[
literal|2
index|]
decl_stmt|;
comment|/* client/server side information */
name|int
name|ipsc_hits
decl_stmt|;
comment|/* times this has been matched */
name|int
name|ipsc_active
decl_stmt|;
comment|/* # of active matches */
name|int
name|ipsc_fref
decl_stmt|;
comment|/* # of references from filter rules */
name|int
name|ipsc_sref
decl_stmt|;
comment|/* # of references from state entries */
name|struct
name|action
name|ipsc_act
decl_stmt|;
block|}
name|ipscan_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ipsc_cl
value|ipsc_si[0]
end_define

begin_define
define|#
directive|define
name|ipsc_sl
value|ipsc_si[1]
end_define

begin_define
define|#
directive|define
name|ipsc_ctxt
value|ipsc_cl.s_txt
end_define

begin_define
define|#
directive|define
name|ipsc_cmsk
value|ipsc_cl.s_msk
end_define

begin_define
define|#
directive|define
name|ipsc_clen
value|ipsc_cl.s_len
end_define

begin_define
define|#
directive|define
name|ipsc_stxt
value|ipsc_sl.s_txt
end_define

begin_define
define|#
directive|define
name|ipsc_smsk
value|ipsc_sl.s_msk
end_define

begin_define
define|#
directive|define
name|ipsc_slen
value|ipsc_sl.s_len
end_define

begin_define
define|#
directive|define
name|ipsc_action
value|ipsc_act.act_val
end_define

begin_define
define|#
directive|define
name|ipsc_ip
value|ipsc_act.act_ip
end_define

begin_define
define|#
directive|define
name|ipsc_port
value|ipsc_act.act_port
end_define

begin_define
define|#
directive|define
name|ipsc_else
value|ipsc_act.act_else
end_define

begin_define
define|#
directive|define
name|ipsc_eip
value|ipsc_act.act_eip
end_define

begin_define
define|#
directive|define
name|ipsc_eport
value|ipsc_act.act_eport
end_define

begin_define
define|#
directive|define
name|ISC_A_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ISC_A_TRACK
value|1
end_define

begin_define
define|#
directive|define
name|ISC_A_CLOSE
value|2
end_define

begin_define
define|#
directive|define
name|ISC_A_REDIRECT
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
name|ipscanstat
block|{
name|struct
name|ipscan
modifier|*
name|iscs_list
decl_stmt|;
name|u_long
name|iscs_acted
decl_stmt|;
name|u_long
name|iscs_else
decl_stmt|;
name|int
name|iscs_entries
decl_stmt|;
block|}
name|ipscanstat_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|fr_scan_ioctl
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|ioctlcmd_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsc_init
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
name|ipsc_attachis
name|__P
argument_list|(
operator|(
expr|struct
name|ipstate
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsc_attachfr
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
name|int
name|ipsc_detachis
name|__P
argument_list|(
operator|(
expr|struct
name|ipstate
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsc_detachfr
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
name|int
name|ipsc_packet
name|__P
argument_list|(
operator|(
expr|struct
name|fr_info
operator|*
operator|,
expr|struct
name|ipstate
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_scanunload
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

begin_comment
comment|/* __IP_SCAN_H__ */
end_comment

end_unit

