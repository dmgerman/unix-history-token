begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	param.h	4.12	81/06/11	*/
end_comment

begin_comment
comment|/*  * Tunable variables which do not usually vary per system.  *  * The sizes of most system tables are configured  * into each system description.  The file system buffer  * cache size is assigned based on available memory.  * The tables whose sizes don't vary often are given here.  */
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

begin_comment
comment|/* NOFILE MUST NOT BE>= 31; SEE pte.h */
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
name|NCARGS
value|10240
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
comment|/*  * fundamental constants of the implementation--  * cannot be changed easily.  */
end_comment

begin_define
define|#
directive|define
name|NBBY
value|8
end_define

begin_comment
comment|/* number of bits in a byte */
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
name|NBPG
value|512
end_define

begin_define
define|#
directive|define
name|PGOFSET
value|(NBPG-1)
end_define

begin_comment
comment|/* byte offset into page */
end_comment

begin_define
define|#
directive|define
name|PGSHIFT
value|9
end_define

begin_comment
comment|/* LOG2(NBPG) */
end_comment

begin_define
define|#
directive|define
name|UPAGES
value|8
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
comment|/*  * Clustering of hardware pages on machines with ridiculously small  * page sizes is done here.  The paging subsystem deals with units of  * CLSIZE pte's describing NBPG (from vm.h) pages each... BSIZE must  * be CLSIZE*NBPG in the current implementation, that is the paging subsystem  * deals with the same size blocks that the file system uses.  *  * NOTE: SSIZE, SINCR and UPAGES must be multiples of CLSIZE  */
end_comment

begin_define
define|#
directive|define
name|CLSIZE
value|2
end_define

begin_define
define|#
directive|define
name|CLOFSET
value|(CLSIZE*NBPG-1)
end_define

begin_comment
comment|/* for clusters, like PGOFSET */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"../h/types.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/*  * Provide about n microseconds of delay  */
end_comment

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|n
parameter_list|)
value|{ register int N = (n); while (--N> 0); }
end_define

end_unit

