begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * tunable variables  */
end_comment

begin_define
define|#
directive|define
name|NBUF
value|15
end_define

begin_comment
comment|/* size of buffer cache */
end_comment

begin_define
define|#
directive|define
name|NINODE
value|100
end_define

begin_comment
comment|/* number of in core inodes */
end_comment

begin_define
define|#
directive|define
name|NFILE
value|100
end_define

begin_comment
comment|/* number of in core file structures */
end_comment

begin_define
define|#
directive|define
name|NMOUNT
value|5
end_define

begin_comment
comment|/* number of mountable file systems */
end_comment

begin_define
define|#
directive|define
name|NEXEC
value|3
end_define

begin_comment
comment|/* number of simultaneous exec's */
end_comment

begin_define
define|#
directive|define
name|MAXMEM
value|(64*32)
end_define

begin_comment
comment|/* max core per process - first # is Kw */
end_comment

begin_define
define|#
directive|define
name|SSIZE
value|20
end_define

begin_comment
comment|/* initial stack size (*64 bytes) */
end_comment

begin_define
define|#
directive|define
name|SINCR
value|20
end_define

begin_comment
comment|/* increment of stack (*64 bytes) */
end_comment

begin_define
define|#
directive|define
name|NOFILE
value|15
end_define

begin_comment
comment|/* max open files per process */
end_comment

begin_define
define|#
directive|define
name|CANBSIZ
value|256
end_define

begin_comment
comment|/* max size of typewriter line */
end_comment

begin_define
define|#
directive|define
name|CMAPSIZ
value|100
end_define

begin_comment
comment|/* size of core allocation area */
end_comment

begin_define
define|#
directive|define
name|SMAPSIZ
value|100
end_define

begin_comment
comment|/* size of swap allocation area */
end_comment

begin_define
define|#
directive|define
name|NCALL
value|20
end_define

begin_comment
comment|/* max simultaneous time callouts */
end_comment

begin_define
define|#
directive|define
name|NPROC
value|50
end_define

begin_comment
comment|/* max number of processes */
end_comment

begin_define
define|#
directive|define
name|NTEXT
value|40
end_define

begin_comment
comment|/* max number of pure texts */
end_comment

begin_define
define|#
directive|define
name|NCLIST
value|100
end_define

begin_comment
comment|/* max total clist size */
end_comment

begin_define
define|#
directive|define
name|HZ
value|60
end_define

begin_comment
comment|/* Ticks/second of the clock */
end_comment

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
value|20
end_define

begin_define
define|#
directive|define
name|SIGHUP
value|1
end_define

begin_comment
comment|/* hangup */
end_comment

begin_define
define|#
directive|define
name|SIGINT
value|2
end_define

begin_comment
comment|/* interrupt (rubout) */
end_comment

begin_define
define|#
directive|define
name|SIGQIT
value|3
end_define

begin_comment
comment|/* quit (FS) */
end_comment

begin_define
define|#
directive|define
name|SIGINS
value|4
end_define

begin_comment
comment|/* illegal instruction */
end_comment

begin_define
define|#
directive|define
name|SIGTRC
value|5
end_define

begin_comment
comment|/* trace or breakpoint */
end_comment

begin_define
define|#
directive|define
name|SIGIOT
value|6
end_define

begin_comment
comment|/* iot */
end_comment

begin_define
define|#
directive|define
name|SIGEMT
value|7
end_define

begin_comment
comment|/* emt */
end_comment

begin_define
define|#
directive|define
name|SIGFPT
value|8
end_define

begin_comment
comment|/* floating exception */
end_comment

begin_define
define|#
directive|define
name|SIGKIL
value|9
end_define

begin_comment
comment|/* kill */
end_comment

begin_define
define|#
directive|define
name|SIGBUS
value|10
end_define

begin_comment
comment|/* bus error */
end_comment

begin_define
define|#
directive|define
name|SIGSEG
value|11
end_define

begin_comment
comment|/* segmentation violation */
end_comment

begin_define
define|#
directive|define
name|SIGSYS
value|12
end_define

begin_comment
comment|/* sys */
end_comment

begin_define
define|#
directive|define
name|SIGPIPE
value|13
end_define

begin_comment
comment|/* end of pipe */
end_comment

begin_comment
comment|/*  * fundamental constants  * cannot be changed  */
end_comment

begin_define
define|#
directive|define
name|USIZE
value|16
end_define

begin_comment
comment|/* size of user block (*64) */
end_comment

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

begin_comment
comment|/* i number of all roots */
end_comment

begin_define
define|#
directive|define
name|DIRSIZ
value|14
end_define

begin_comment
comment|/* max characters per directory */
end_comment

begin_comment
comment|/*  * structure to access an  * integer in bytes  */
end_comment

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

begin_comment
comment|/*  * structure to access an integer  */
end_comment

begin_struct
struct|struct
block|{
name|int
name|integ
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Certain processor registers  */
end_comment

begin_define
define|#
directive|define
name|PS
value|0177776
end_define

begin_define
define|#
directive|define
name|KL
value|0177560
end_define

begin_define
define|#
directive|define
name|SW
value|0177570
end_define

end_unit

