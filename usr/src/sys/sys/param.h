begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	param.h	3.10	%G%	*/
end_comment

begin_comment
comment|/*  * tunable variables  *  * NB: NBUF is well known in locore.s  */
end_comment

begin_define
define|#
directive|define
name|NBUF
value|62
end_define

begin_comment
comment|/* size of buffer cache */
end_comment

begin_define
define|#
directive|define
name|NINODE
value|400
end_define

begin_comment
comment|/* number of in core inodes */
end_comment

begin_define
define|#
directive|define
name|NFILE
value|350
end_define

begin_comment
comment|/* number of in core file structures */
end_comment

begin_define
define|#
directive|define
name|NMOUNT
value|15
end_define

begin_comment
comment|/* number of mountable file systems */
end_comment

begin_define
define|#
directive|define
name|MSWAPX
value|15
end_define

begin_comment
comment|/* pseudo mount table index for swapdev */
end_comment

begin_define
define|#
directive|define
name|MAXUPRC
value|25
end_define

begin_comment
comment|/* max processes per user */
end_comment

begin_define
define|#
directive|define
name|SSIZE
value|4
end_define

begin_comment
comment|/* initial stack size (*512 bytes) */
end_comment

begin_define
define|#
directive|define
name|SINCR
value|4
end_define

begin_comment
comment|/* increment of stack (*512 bytes) */
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
name|SMAPSIZ
value|(4*NPROC)
end_define

begin_comment
comment|/* size of swap allocation area */
end_comment

begin_define
define|#
directive|define
name|NCALL
value|40
end_define

begin_comment
comment|/* max simultaneous time callouts */
end_comment

begin_define
define|#
directive|define
name|NPROC
value|250
end_define

begin_comment
comment|/* max number of processes */
end_comment

begin_define
define|#
directive|define
name|NTEXT
value|60
end_define

begin_comment
comment|/* max number of pure texts */
end_comment

begin_define
define|#
directive|define
name|NCLIST
value|500
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
value|(8*60)
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
name|PRIUBA
value|24
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

begin_define
define|#
directive|define
name|NZERO
value|20
end_define

begin_comment
comment|/*  * signals  * dont change  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NSIG
end_ifndef

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Return values from tsleep().  */
end_comment

begin_define
define|#
directive|define
name|TS_OK
value|0
end_define

begin_comment
comment|/* normal wakeup */
end_comment

begin_define
define|#
directive|define
name|TS_TIME
value|1
end_define

begin_comment
comment|/* timed-out wakeup */
end_comment

begin_define
define|#
directive|define
name|TS_SIG
value|2
end_define

begin_comment
comment|/* asynchronous signal wakeup */
end_comment

begin_comment
comment|/*  * fundamental constants of the implementation--  * cannot be changed easily.  * note: UPAGES is well known in locore.s  */
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
name|UPAGES
value|6
end_define

begin_comment
comment|/* pages of u-area */
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

begin_comment
comment|/*  * Clustering of hardware pages on machines with ridiculously small  * page sizes is done here.  The paging subsystem deals with units of  * CLSIZE pte's describing NBPG (from vm.h) pages each... BSIZE must  * be CLSIZE*NBPG in the current implementation, that is the paging subsystem  * deals with the same size blocks that the file system uses.  *  * NOTE: SSIZE, SINCR and UPAGES must be multiples of CLSIZE  *  * NB: CLSIZE is well known in locore.s.  */
end_comment

begin_define
define|#
directive|define
name|CLSIZE
value|2
end_define

begin_comment
comment|/* give the base virtual address (first of CLSIZE) */
end_comment

begin_define
define|#
directive|define
name|clbase
parameter_list|(
name|i
parameter_list|)
value|((i)&~ (CLSIZE-1))
end_define

begin_comment
comment|/* round a number of clicks up to a whole cluster */
end_comment

begin_define
define|#
directive|define
name|clrnd
parameter_list|(
name|i
parameter_list|)
value|(((i) + (CLSIZE-1))&~ (CLSIZE-1))
end_define

begin_if
if|#
directive|if
name|CLSIZE
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|BSIZE
value|512
end_define

begin_comment
comment|/* size of secondary block (bytes) */
end_comment

begin_define
define|#
directive|define
name|INOPB
value|8
end_define

begin_comment
comment|/* 8 inodes per block */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|CLSIZE
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|BSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|INOPB
value|16
end_define

begin_define
define|#
directive|define
name|BMASK
value|01777
end_define

begin_define
define|#
directive|define
name|BSHIFT
value|10
end_define

begin_define
define|#
directive|define
name|NMASK
value|0377
end_define

begin_define
define|#
directive|define
name|NSHIFT
value|8
end_define

begin_define
define|#
directive|define
name|NICINOD
value|100
end_define

begin_define
define|#
directive|define
name|NICFREE
value|178
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|CLSIZE
operator|==
literal|4
end_if

begin_define
define|#
directive|define
name|BSIZE
value|2048
end_define

begin_define
define|#
directive|define
name|INOPB
value|32
end_define

begin_define
define|#
directive|define
name|BMASK
value|03777
end_define

begin_define
define|#
directive|define
name|BSHIFT
value|11
end_define

begin_define
define|#
directive|define
name|NMASK
value|0777
end_define

begin_define
define|#
directive|define
name|NSHIFT
value|9
end_define

begin_define
define|#
directive|define
name|NICINOD
value|100
end_define

begin_define
define|#
directive|define
name|NICFREE
value|434
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INTRLVE
end_ifndef

begin_comment
comment|/* macros replacing interleaving functions */
end_comment

begin_define
define|#
directive|define
name|dkblock
parameter_list|(
name|bp
parameter_list|)
value|((bp)->b_blkno)
end_define

begin_define
define|#
directive|define
name|dkunit
parameter_list|(
name|bp
parameter_list|)
value|(minor((bp)->b_dev)>> 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* inumber to disk address and inumber to disk offset */
end_comment

begin_define
define|#
directive|define
name|itod
parameter_list|(
name|x
parameter_list|)
value|((daddr_t)((((unsigned)(x)+2*INOPB-1)/INOPB)))
end_define

begin_define
define|#
directive|define
name|itoo
parameter_list|(
name|x
parameter_list|)
value|((int)(((x)+2*INOPB-1)%INOPB))
end_define

begin_comment
comment|/* file system blocks to disk blocks and back */
end_comment

begin_define
define|#
directive|define
name|fsbtodb
parameter_list|(
name|b
parameter_list|)
value|((b)*CLSIZE)
end_define

begin_define
define|#
directive|define
name|dbtofsb
parameter_list|(
name|b
parameter_list|)
value|((b)/CLSIZE)
end_define

begin_define
define|#
directive|define
name|NINDIR
value|(BSIZE/sizeof(daddr_t))
end_define

begin_define
define|#
directive|define
name|CBSIZE
value|28
end_define

begin_comment
comment|/* number of chars in a clist block */
end_comment

begin_define
define|#
directive|define
name|CROUND
value|0x1F
end_define

begin_comment
comment|/* clist rounding; sizeof(int *) + CBSIZE -1*/
end_comment

begin_define
define|#
directive|define
name|CLKTICK
value|(1000000/(HZ))
end_define

begin_comment
comment|/* microseconds in a clock tick */
end_comment

begin_comment
comment|/*  * Macros for fast min/max  */
end_comment

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)<(b))?(a):(b))
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)>(b))?(a):(b))
end_define

begin_comment
comment|/*  * Some macros for units conversion  */
end_comment

begin_comment
comment|/* Core clicks (512 bytes) to segments and vice versa */
end_comment

begin_define
define|#
directive|define
name|ctos
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|stoc
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_comment
comment|/* Core clicks (512 bytes) to disk blocks */
end_comment

begin_define
define|#
directive|define
name|ctod
parameter_list|(
name|x
parameter_list|)
value|(x)
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
value|((x)<<9)
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
value|((((unsigned)(x)+511)>>9))
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
value|((int)(((unsigned)(x)>>8)&0377))
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
value|((int)((x)&0377))
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
value|((dev_t)(((x)<<8) | (y)))
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
name|int
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
name|short
name|ino_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|swblk_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|label_t
index|[
literal|14
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|dev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|off_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u_char
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u_short
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|u_long
typedef|;
end_typedef

begin_comment
comment|/*  * Machine-dependent bits and macros  */
end_comment

begin_define
define|#
directive|define
name|UMODE
value|PSL_CURMOD
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
value|(((ps)& UMODE) == UMODE)
end_define

begin_define
define|#
directive|define
name|BASEPRI
parameter_list|(
name|ps
parameter_list|)
value|(((ps)& PSL_IPL) != 0)
end_define

end_unit

