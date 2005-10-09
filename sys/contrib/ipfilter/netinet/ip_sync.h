begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1993-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * @(#)ip_fil.h	1.35 6/5/96  * Id: ip_sync.h,v 2.11.2.2 2004/11/04 19:29:07 darrenr Exp  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IP_SYNC_H__
end_ifndef

begin_define
define|#
directive|define
name|__IP_SYNC_H__
end_define

begin_typedef
typedef|typedef
struct|struct
name|synchdr
block|{
name|u_32_t
name|sm_magic
decl_stmt|;
comment|/* magic */
name|u_char
name|sm_v
decl_stmt|;
comment|/* version: 4,6 */
name|u_char
name|sm_p
decl_stmt|;
comment|/* protocol */
name|u_char
name|sm_cmd
decl_stmt|;
comment|/* command */
name|u_char
name|sm_table
decl_stmt|;
comment|/* NAT, STATE, etc */
name|u_int
name|sm_num
decl_stmt|;
comment|/* table entry number */
name|int
name|sm_rev
decl_stmt|;
comment|/* forward/reverse */
name|int
name|sm_len
decl_stmt|;
comment|/* length of the data section */
name|struct
name|synclist
modifier|*
name|sm_sl
decl_stmt|;
comment|/* back pointer to parent */
block|}
name|synchdr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SYNHDRMAGIC
value|0x0FF51DE5
end_define

begin_comment
comment|/*  * Commands  * No delete required as expirey will take care of that!  */
end_comment

begin_define
define|#
directive|define
name|SMC_CREATE
value|0
end_define

begin_comment
comment|/* pass ipstate_t after synchdr_t */
end_comment

begin_define
define|#
directive|define
name|SMC_UPDATE
value|1
end_define

begin_define
define|#
directive|define
name|SMC_MAXCMD
value|1
end_define

begin_comment
comment|/*  * Tables  */
end_comment

begin_define
define|#
directive|define
name|SMC_NAT
value|0
end_define

begin_define
define|#
directive|define
name|SMC_STATE
value|1
end_define

begin_define
define|#
directive|define
name|SMC_MAXTBL
value|1
end_define

begin_comment
comment|/*  * Only TCP requires "more" information than just a reference to the entry  * for which an update is being made.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|synctcp_update
block|{
name|u_long
name|stu_age
decl_stmt|;
name|tcpdata_t
name|stu_data
index|[
literal|2
index|]
decl_stmt|;
name|int
name|stu_state
index|[
literal|2
index|]
decl_stmt|;
block|}
name|synctcp_update_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|synclist
block|{
name|struct
name|synclist
modifier|*
name|sl_next
decl_stmt|;
name|struct
name|synclist
modifier|*
modifier|*
name|sl_pnext
decl_stmt|;
name|int
name|sl_idx
decl_stmt|;
comment|/* update index */
name|struct
name|synchdr
name|sl_hdr
decl_stmt|;
union|union
block|{
name|struct
name|ipstate
modifier|*
name|slu_ips
decl_stmt|;
name|struct
name|nat
modifier|*
name|slu_ipn
decl_stmt|;
name|void
modifier|*
name|slu_ptr
decl_stmt|;
block|}
name|sl_un
union|;
block|}
name|synclist_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sl_ptr
value|sl_un.slu_ptr
end_define

begin_define
define|#
directive|define
name|sl_ips
value|sl_un.slu_ips
end_define

begin_define
define|#
directive|define
name|sl_ipn
value|sl_un.slu_ipn
end_define

begin_define
define|#
directive|define
name|sl_magic
value|sl_hdr.sm_magic
end_define

begin_define
define|#
directive|define
name|sl_v
value|sl_hdr.sm_v
end_define

begin_define
define|#
directive|define
name|sl_p
value|sl_hdr.sm_p
end_define

begin_define
define|#
directive|define
name|sl_cmd
value|sl_hdr.sm_cmd
end_define

begin_define
define|#
directive|define
name|sl_rev
value|sl_hdr.sm_rev
end_define

begin_define
define|#
directive|define
name|sl_table
value|sl_hdr.sm_table
end_define

begin_define
define|#
directive|define
name|sl_num
value|sl_hdr.sm_num
end_define

begin_define
define|#
directive|define
name|sl_len
value|sl_hdr.sm_len
end_define

begin_comment
comment|/*  * NOTE: SYNCLOG_SZ is defined *low*.  It should be the next power of two  * up for whatever number of packets per second you expect to see.  Be  * warned: this index's a table of large elements (upto 272 bytes in size  * each), and thus a size of 8192, for example, results in a 2MB table.  * The lesson here is not to use small machines for running fast firewalls  * (100BaseT) in sync, where you might have upwards of 10k pps.  */
end_comment

begin_define
define|#
directive|define
name|SYNCLOG_SZ
value|256
end_define

begin_typedef
typedef|typedef
struct|struct
name|synclogent
block|{
name|struct
name|synchdr
name|sle_hdr
decl_stmt|;
union|union
block|{
name|struct
name|ipstate
name|sleu_ips
decl_stmt|;
name|struct
name|nat
name|sleu_ipn
decl_stmt|;
block|}
name|sle_un
union|;
block|}
name|synclogent_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|syncupdent
block|{
comment|/* 28 or 32 bytes */
name|struct
name|synchdr
name|sup_hdr
decl_stmt|;
name|struct
name|synctcp_update
name|sup_tcp
decl_stmt|;
block|}
name|syncupdent_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|synclogent_t
name|synclog
index|[
name|SYNCLOG_SZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_sync_ioctl
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
name|synclist_t
modifier|*
name|ipfsync_new
name|__P
argument_list|(
operator|(
name|int
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
name|void
name|ipfsync_del
name|__P
argument_list|(
operator|(
name|synclist_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipfsync_update
name|__P
argument_list|(
operator|(
name|int
operator|,
name|fr_info_t
operator|*
operator|,
name|synclist_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipfsync_init
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
name|ipfsync_nat
name|__P
argument_list|(
operator|(
name|synchdr_t
operator|*
name|sp
operator|,
name|void
operator|*
name|data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipfsync_state
name|__P
argument_list|(
operator|(
name|synchdr_t
operator|*
name|sp
operator|,
name|void
operator|*
name|data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipfsync_read
name|__P
argument_list|(
operator|(
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipfsync_write
name|__P
argument_list|(
operator|(
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IP_SYNC */
end_comment

end_unit

