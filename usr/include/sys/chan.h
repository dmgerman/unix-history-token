begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|NGROUPS
value|10
end_define

begin_define
define|#
directive|define
name|NCHANS
value|20
end_define

begin_define
define|#
directive|define
name|DCHAN
value|1
end_define

begin_define
define|#
directive|define
name|CCHAN
value|0
end_define

begin_struct
struct|struct
name|chan
block|{
name|short
name|c_flags
decl_stmt|;
name|char
name|c_index
decl_stmt|;
name|char
name|c_msg
decl_stmt|;
name|struct
name|group
modifier|*
name|c_group
decl_stmt|;
name|struct
name|tty
modifier|*
name|c_ttyp
decl_stmt|;
name|struct
name|file
modifier|*
name|c_fy
decl_stmt|;
name|int
name|c_pgrp
decl_stmt|;
union|union
block|{
name|struct
name|clist
name|datq
decl_stmt|;
block|}
name|cx
union|;
union|union
block|{
name|struct
name|clist
name|datq
decl_stmt|;
name|struct
name|chan
modifier|*
name|c_chan
decl_stmt|;
block|}
name|cy
union|;
name|struct
name|clist
name|c_ctlx
decl_stmt|;
name|struct
name|clist
name|c_ctly
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|group
block|{
name|short
name|g_state
decl_stmt|;
name|char
name|g_mindex
decl_stmt|;
name|short
name|g_index
decl_stmt|;
name|short
name|g_count
decl_stmt|;
name|struct
name|inode
modifier|*
name|g_inode
decl_stmt|;
name|struct
name|group
modifier|*
name|g_master
decl_stmt|;
name|struct
name|clist
name|g_cntl
decl_stmt|;
name|struct
name|clist
name|g_datq
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * flags  */
end_comment

begin_define
define|#
directive|define
name|INUSE
value|01
end_define

begin_define
define|#
directive|define
name|COPEN
value|02
end_define

begin_define
define|#
directive|define
name|XGRP
value|04
end_define

begin_define
define|#
directive|define
name|YGRP
value|010
end_define

begin_define
define|#
directive|define
name|WCLOSE
value|020
end_define

begin_define
define|#
directive|define
name|TTYO
value|040
end_define

begin_define
define|#
directive|define
name|SUBGRP
value|0100
end_define

begin_define
define|#
directive|define
name|BLOCK
value|0200
end_define

begin_define
define|#
directive|define
name|BLOCK1
value|0400
end_define

begin_define
define|#
directive|define
name|SIGBLK
value|01000
end_define

begin_define
define|#
directive|define
name|BLKMSG
value|01000
end_define

begin_define
define|#
directive|define
name|ENAMSG
value|02000
end_define

begin_define
define|#
directive|define
name|WFLUSH
value|04000
end_define

begin_define
define|#
directive|define
name|RZERO
value|010000
end_define

begin_comment
comment|/*  * mpxchan command codes  */
end_comment

begin_define
define|#
directive|define
name|GROUP
value|5
end_define

begin_define
define|#
directive|define
name|GROUPN
value|6
end_define

begin_define
define|#
directive|define
name|CHAN
value|1
end_define

begin_define
define|#
directive|define
name|JOIN
value|2
end_define

begin_define
define|#
directive|define
name|EXTR
value|3
end_define

begin_define
define|#
directive|define
name|ATTACH
value|4
end_define

begin_define
define|#
directive|define
name|CONNECT
value|7
end_define

begin_define
define|#
directive|define
name|DETACH
value|8
end_define

begin_define
define|#
directive|define
name|DISCON
value|9
end_define

begin_define
define|#
directive|define
name|DEBUG
value|10
end_define

begin_define
define|#
directive|define
name|NPGRP
value|11
end_define

begin_define
define|#
directive|define
name|CSIG
value|12
end_define

begin_define
define|#
directive|define
name|PACK
value|13
end_define

begin_define
define|#
directive|define
name|NDEBUGS
value|30
end_define

begin_comment
comment|/*  * control channel message codes  */
end_comment

begin_define
define|#
directive|define
name|WATTCH
value|1
end_define

begin_define
define|#
directive|define
name|M_WATCH
value|1
end_define

begin_define
define|#
directive|define
name|SCLOSE
value|2
end_define

begin_define
define|#
directive|define
name|M_CLOSE
value|2
end_define

begin_define
define|#
directive|define
name|M_ATTACH
value|3
end_define

begin_define
define|#
directive|define
name|M_BLK
value|4
end_define

begin_define
define|#
directive|define
name|M_UBLK
value|5
end_define

begin_define
define|#
directive|define
name|DO_BLK
value|6
end_define

begin_define
define|#
directive|define
name|DO_UBLK
value|7
end_define

begin_define
define|#
directive|define
name|M_XINT
value|8
end_define

begin_define
define|#
directive|define
name|M_RINT
value|9
end_define

begin_define
define|#
directive|define
name|M_ACK
value|10
end_define

begin_define
define|#
directive|define
name|M_NAK
value|11
end_define

begin_comment
comment|/*  * debug codes other than mpxchan cmds  */
end_comment

begin_define
define|#
directive|define
name|MCCLOSE
value|29
end_define

begin_define
define|#
directive|define
name|MCOPEN
value|28
end_define

begin_define
define|#
directive|define
name|ALL
value|27
end_define

begin_define
define|#
directive|define
name|SCON
value|26
end_define

begin_define
define|#
directive|define
name|MSREAD
value|25
end_define

begin_define
define|#
directive|define
name|SDATA
value|24
end_define

begin_define
define|#
directive|define
name|MCREAD
value|23
end_define

begin_define
define|#
directive|define
name|MCWRITE
value|22
end_define

begin_comment
comment|/* HDRSIZE == NLEVELS + sizeof (short) */
end_comment

begin_define
define|#
directive|define
name|HDRSIZE
value|4
end_define

begin_define
define|#
directive|define
name|NLEVELS
value|2
end_define

begin_union
union|union
name|u_index
block|{
name|short
name|val
decl_stmt|;
name|char
name|bytes
index|[
name|NLEVELS
index|]
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|u_index
name|index_t
typedef|;
end_typedef

end_unit

