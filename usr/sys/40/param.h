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
value|20
end_define

begin_comment
comment|/* number of in core inodes */
end_comment

begin_define
define|#
directive|define
name|NFILE
value|20
end_define

begin_comment
comment|/* number of in core file structures */
end_comment

begin_define
define|#
directive|define
name|NMOUNT
value|2
end_define

begin_comment
comment|/* number of mountable file systems */
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
name|MAXUPRC
value|15
end_define

begin_comment
comment|/* max processes per user */
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
value|20
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
value|20
end_define

begin_comment
comment|/* size of core allocation area */
end_comment

begin_define
define|#
directive|define
name|SMAPSIZ
value|20
end_define

begin_comment
comment|/* size of swap allocation area */
end_comment

begin_define
define|#
directive|define
name|NCALL
value|10
end_define

begin_comment
comment|/* max simultaneous time callouts */
end_comment

begin_define
define|#
directive|define
name|NPROC
value|20
end_define

begin_comment
comment|/* max number of processes */
end_comment

begin_define
define|#
directive|define
name|NTEXT
value|10
end_define

begin_comment
comment|/* max number of pure texts */
end_comment

begin_define
define|#
directive|define
name|NCLIST
value|40
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

begin_define
define|#
directive|define
name|TIMEZONE
value|(5*60)
end_define

begin_comment
comment|/* Minutes westward from Greenwich */
end_comment

begin_define
define|#
directive|define
name|DSTFLAG
value|1
end_define

begin_comment
comment|/* Daylight Saving Time applies in this locality */
end_comment

begin_define
define|#
directive|define
name|MSGBUFS
value|128
end_define

begin_comment
comment|/* Characters saved from error messages */
end_comment

begin_define
define|#
directive|define
name|NCARGS
value|5120
end_define

begin_comment
comment|/* # characters in exec arglist */
end_comment

begin_comment
comment|/*  * priorities  * probably should not be  * altered too much  */
end_comment

begin_define
define|#
directive|define
name|PSWP
value|0
end_define

begin_define
define|#
directive|define
name|PINOD
value|10
end_define

begin_define
define|#
directive|define
name|PRIBIO
value|20
end_define

begin_define
define|#
directive|define
name|PZERO
value|25
end_define

begin_define
define|#
directive|define
name|NZERO
value|20
end_define

begin_define
define|#
directive|define
name|PPIPE
value|26
end_define

begin_define
define|#
directive|define
name|PWAIT
value|30
end_define

begin_define
define|#
directive|define
name|PSLEP
value|40
end_define

begin_define
define|#
directive|define
name|PUSER
value|50
end_define

begin_comment
comment|/*  * signals  * dont change  */
end_comment

begin_define
define|#
directive|define
name|NSIG
value|17
end_define

begin_comment
comment|/*  * No more than 16 signals (1-16) because they are  * stored in bits in a word.  */
end_comment

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
name|SIGQUIT
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
comment|/* kill, uncatchable termination */
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
comment|/* bad system call */
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

begin_define
define|#
directive|define
name|SIGCLK
value|14
end_define

begin_comment
comment|/* alarm clock */
end_comment

begin_define
define|#
directive|define
name|SIGTRM
value|15
end_define

begin_comment
comment|/* Catchable termination */
end_comment

begin_comment
comment|/*  * fundamental constants of the implementation--  * cannot be changed easily  */
end_comment

begin_define
define|#
directive|define
name|NBPW
value|sizeof(int)
end_define

begin_comment
comment|/* number of bytes in an integer */
end_comment

begin_define
define|#
directive|define
name|BSIZE
value|512
end_define

begin_comment
comment|/* size of secondary block (bytes) */
end_comment

begin_comment
comment|/* BSLOP can be 0 unless you have a TIU/Spider */
end_comment

begin_define
define|#
directive|define
name|BSLOP
value|2
end_define

begin_comment
comment|/* In case some device needs bigger buffers */
end_comment

begin_define
define|#
directive|define
name|NINDIR
value|(BSIZE/sizeof(daddr_t))
end_define

begin_define
define|#
directive|define
name|BMASK
value|0777
end_define

begin_comment
comment|/* BSIZE-1 */
end_comment

begin_define
define|#
directive|define
name|BSHIFT
value|9
end_define

begin_comment
comment|/* LOG2(BSIZE) */
end_comment

begin_define
define|#
directive|define
name|NMASK
value|0177
end_define

begin_comment
comment|/* NINDIR-1 */
end_comment

begin_define
define|#
directive|define
name|NSHIFT
value|7
end_define

begin_comment
comment|/* LOG2(NINDIR) */
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
name|UBASE
value|0140000
end_define

begin_comment
comment|/* abs. addr of user block */
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
name|CMASK
value|0
end_define

begin_comment
comment|/* default mask for file creation */
end_comment

begin_define
define|#
directive|define
name|NODEV
value|(dev_t)(-1)
end_define

begin_define
define|#
directive|define
name|ROOTINO
value|((ino_t)2)
end_define

begin_comment
comment|/* i number of all roots */
end_comment

begin_define
define|#
directive|define
name|SUPERB
value|((daddr_t)1)
end_define

begin_comment
comment|/* block number of the super block */
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

begin_define
define|#
directive|define
name|NICINOD
value|100
end_define

begin_comment
comment|/* number of superblock inodes */
end_comment

begin_define
define|#
directive|define
name|NICFREE
value|50
end_define

begin_comment
comment|/* number of superblock free blocks */
end_comment

begin_define
define|#
directive|define
name|INFSIZE
value|138
end_define

begin_comment
comment|/* size of per-proc info for users */
end_comment

begin_define
define|#
directive|define
name|CBSIZE
value|6
end_define

begin_comment
comment|/* number of chars in a clist block */
end_comment

begin_define
define|#
directive|define
name|CROUND
value|07
end_define

begin_comment
comment|/* clist rounding: sizeof(int *) + CBSIZE - 1*/
end_comment

begin_comment
comment|/*  * Some macros for units conversion  */
end_comment

begin_comment
comment|/* Core clicks (64 bytes) to segments and vice versa */
end_comment

begin_define
define|#
directive|define
name|ctos
parameter_list|(
name|x
parameter_list|)
value|((x+127)/128)
end_define

begin_define
define|#
directive|define
name|stoc
parameter_list|(
name|x
parameter_list|)
value|((x)*128)
end_define

begin_comment
comment|/* Core clicks (64 bytes) to disk blocks */
end_comment

begin_define
define|#
directive|define
name|ctod
parameter_list|(
name|x
parameter_list|)
value|((x+7)>>3)
end_define

begin_comment
comment|/* inumber to disk address */
end_comment

begin_define
define|#
directive|define
name|itod
parameter_list|(
name|x
parameter_list|)
value|(daddr_t)((((unsigned)x+15)>>3))
end_define

begin_comment
comment|/* inumber to disk offset */
end_comment

begin_define
define|#
directive|define
name|itoo
parameter_list|(
name|x
parameter_list|)
value|(int)((x+15)&07)
end_define

begin_comment
comment|/* clicks to bytes */
end_comment

begin_define
define|#
directive|define
name|ctob
parameter_list|(
name|x
parameter_list|)
value|(x<<6)
end_define

begin_comment
comment|/* bytes to clicks */
end_comment

begin_define
define|#
directive|define
name|btoc
parameter_list|(
name|x
parameter_list|)
value|((((unsigned)x+63)>>6))
end_define

begin_comment
comment|/* major part of a device */
end_comment

begin_define
define|#
directive|define
name|major
parameter_list|(
name|x
parameter_list|)
value|(int)(((unsigned)x>>8))
end_define

begin_comment
comment|/* minor part of a device */
end_comment

begin_define
define|#
directive|define
name|minor
parameter_list|(
name|x
parameter_list|)
value|(int)(x&0377)
end_define

begin_comment
comment|/* make a device number */
end_comment

begin_define
define|#
directive|define
name|makedev
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(dev_t)((x)<<8 | (y))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|r
index|[
literal|1
index|]
decl_stmt|;
block|}
typedef|*
name|physadr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|daddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|caddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ino_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|label_t
index|[
literal|6
index|]
typedef|;
end_typedef

begin_comment
comment|/* regs 2-7 */
end_comment

begin_typedef
typedef|typedef
name|int
name|dev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|off_t
typedef|;
end_typedef

begin_comment
comment|/*  * Machine-dependent bits and macros  */
end_comment

begin_define
define|#
directive|define
name|UMODE
value|0170000
end_define

begin_comment
comment|/* usermode bits */
end_comment

begin_define
define|#
directive|define
name|USERMODE
parameter_list|(
name|ps
parameter_list|)
value|((ps& UMODE)==UMODE)
end_define

begin_define
define|#
directive|define
name|INTPRI
value|0340
end_define

begin_comment
comment|/* Priority bits */
end_comment

begin_define
define|#
directive|define
name|BASEPRI
parameter_list|(
name|ps
parameter_list|)
value|((ps& INTPRI) != 0)
end_define

end_unit

