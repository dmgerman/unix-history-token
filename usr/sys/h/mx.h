begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|NGROUPS
value|10
end_define

begin_comment
comment|/* number of mpx files permitted at one time */
end_comment

begin_define
define|#
directive|define
name|NCHANS
value|20
end_define

begin_comment
comment|/* number of channel structures */
end_comment

begin_define
define|#
directive|define
name|NPORTS
value|30
end_define

begin_comment
comment|/* number of channels to i/o ports */
end_comment

begin_define
define|#
directive|define
name|CNTLSIZ
value|10
end_define

begin_define
define|#
directive|define
name|NLEVELS
value|4
end_define

begin_define
define|#
directive|define
name|NMSIZE
value|50
end_define

begin_comment
comment|/* max size of mxlstn file name */
end_comment

begin_comment
comment|/*  * header returned on read of mpx  */
end_comment

begin_struct
struct|struct
name|rh
block|{
name|short
name|index
decl_stmt|;
name|short
name|count
decl_stmt|;
name|short
name|ccount
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * head expected on write of mpx  */
end_comment

begin_struct
struct|struct
name|wh
block|{
name|short
name|index
decl_stmt|;
name|short
name|count
decl_stmt|;
name|short
name|ccount
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mx_args
block|{
name|char
modifier|*
name|m_name
decl_stmt|;
name|int
name|m_cmd
decl_stmt|;
name|int
name|m_arg
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * internal structure for channel  */
end_comment

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
name|c_line
decl_stmt|;
name|struct
name|group
modifier|*
name|c_group
decl_stmt|;
name|struct
name|file
modifier|*
name|c_fy
decl_stmt|;
name|struct
name|tty
modifier|*
name|c_ttyp
decl_stmt|;
name|struct
name|clist
name|c_ctlx
decl_stmt|;
name|int
name|c_pgrp
decl_stmt|;
name|struct
name|tty
modifier|*
name|c_ottyp
decl_stmt|;
name|char
name|c_oline
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
name|c_ctly
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|schan
block|{
name|short
name|c_flags
decl_stmt|;
name|char
name|c_index
decl_stmt|;
name|char
name|c_line
decl_stmt|;
name|struct
name|group
modifier|*
name|c_group
decl_stmt|;
name|struct
name|file
modifier|*
name|c_fy
decl_stmt|;
name|struct
name|tty
modifier|*
name|c_ttyp
decl_stmt|;
name|struct
name|clist
name|c_ctlx
decl_stmt|;
name|int
name|c_pgrp
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
name|ISGRP
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
name|EOTMARK
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
name|NMBUF
value|010000
end_define

begin_define
define|#
directive|define
name|PORT
value|020000
end_define

begin_define
define|#
directive|define
name|ALT
value|040000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * mpxchan command codes  */
end_comment

begin_define
define|#
directive|define
name|MPX
value|5
end_define

begin_define
define|#
directive|define
name|MPXN
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
name|M_WATCH
value|1
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
name|M_EOT
value|3
end_define

begin_define
define|#
directive|define
name|M_OPEN
value|4
end_define

begin_define
define|#
directive|define
name|M_BLK
value|5
end_define

begin_define
define|#
directive|define
name|M_UBLK
value|6
end_define

begin_define
define|#
directive|define
name|DO_BLK
value|7
end_define

begin_define
define|#
directive|define
name|DO_UBLK
value|8
end_define

begin_define
define|#
directive|define
name|M_IOCTL
value|12
end_define

begin_define
define|#
directive|define
name|M_SIG
value|14
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

end_unit

