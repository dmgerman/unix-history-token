begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * variables  */
end_comment

begin_define
define|#
directive|define
name|NBUF
value|15
end_define

begin_define
define|#
directive|define
name|NINODE
value|100
end_define

begin_define
define|#
directive|define
name|NFILE
value|100
end_define

begin_define
define|#
directive|define
name|NMOUNT
value|5
end_define

begin_define
define|#
directive|define
name|NEXEC
value|4
end_define

begin_define
define|#
directive|define
name|MAXMEM
value|(32*32)
end_define

begin_define
define|#
directive|define
name|SSIZE
value|20
end_define

begin_define
define|#
directive|define
name|SINCR
value|20
end_define

begin_define
define|#
directive|define
name|NOFILE
value|15
end_define

begin_define
define|#
directive|define
name|CANBSIZ
value|256
end_define

begin_define
define|#
directive|define
name|CMAPSIZ
value|100
end_define

begin_define
define|#
directive|define
name|SMAPSIZ
value|100
end_define

begin_define
define|#
directive|define
name|NCALL
value|20
end_define

begin_define
define|#
directive|define
name|NPROC
value|50
end_define

begin_define
define|#
directive|define
name|NTEXT
value|20
end_define

begin_define
define|#
directive|define
name|NCLIST
value|100
end_define

begin_comment
comment|/*  * priorities  * probably should not be  * altered too much  */
end_comment

begin_define
define|#
directive|define
name|PSWP
value|-100
end_define

begin_define
define|#
directive|define
name|PINOD
value|-90
end_define

begin_define
define|#
directive|define
name|PRIBIO
value|-50
end_define

begin_define
define|#
directive|define
name|PPIPE
value|1
end_define

begin_define
define|#
directive|define
name|PWAIT
value|40
end_define

begin_define
define|#
directive|define
name|PSLEP
value|90
end_define

begin_define
define|#
directive|define
name|PUSER
value|100
end_define

begin_comment
comment|/*  * signals  * dont change  */
end_comment

begin_define
define|#
directive|define
name|NSIG
value|13
end_define

begin_define
define|#
directive|define
name|SIGHUP
value|1
end_define

begin_define
define|#
directive|define
name|SIGINT
value|2
end_define

begin_define
define|#
directive|define
name|SIGQIT
value|3
end_define

begin_define
define|#
directive|define
name|SIGINS
value|4
end_define

begin_define
define|#
directive|define
name|SIGTRC
value|5
end_define

begin_define
define|#
directive|define
name|SIGIOT
value|6
end_define

begin_define
define|#
directive|define
name|SIGEMT
value|7
end_define

begin_define
define|#
directive|define
name|SIGFPT
value|8
end_define

begin_define
define|#
directive|define
name|SIGKIL
value|9
end_define

begin_define
define|#
directive|define
name|SIGBUS
value|10
end_define

begin_define
define|#
directive|define
name|SIGSEG
value|11
end_define

begin_define
define|#
directive|define
name|SIGSYS
value|12
end_define

begin_comment
comment|/*  * fundamental constants  * cannot be changed  */
end_comment

begin_define
define|#
directive|define
name|USIZE
value|16
end_define

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_define
define|#
directive|define
name|NODEV
value|(-1)
end_define

begin_define
define|#
directive|define
name|ROOTINO
value|1
end_define

begin_define
define|#
directive|define
name|DIRSIZ
value|14
end_define

begin_struct
struct|struct
block|{
name|char
name|lobyte
decl_stmt|;
name|char
name|hibyte
decl_stmt|;
block|}
struct|;
end_struct

end_unit

