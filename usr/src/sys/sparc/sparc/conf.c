begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)conf.c	7.5 (Berkeley) %G%  *  * from: $Header: conf.c,v 1.15 93/05/05 09:43:29 torek Exp $ (LBL)  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_decl_stmt
name|int
name|rawread
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

begin_decl_stmt
name|int
name|rawwrite
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

begin_decl_stmt
name|int
name|swstrategy
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttselect
name|__P
argument_list|(
operator|(
name|dev_t
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

begin_define
define|#
directive|define
name|dev_type_open
parameter_list|(
name|n
parameter_list|)
value|int n __P((dev_t, int, int, struct proc *))
end_define

begin_define
define|#
directive|define
name|dev_type_close
parameter_list|(
name|n
parameter_list|)
value|int n __P((dev_t, int, int, struct proc *))
end_define

begin_define
define|#
directive|define
name|dev_type_strategy
parameter_list|(
name|n
parameter_list|)
value|int n __P((struct buf *))
end_define

begin_define
define|#
directive|define
name|dev_type_ioctl
parameter_list|(
name|n
parameter_list|)
define|\
value|int n __P((dev_t, int, caddr_t, int, struct proc *))
end_define

begin_comment
comment|/* bdevsw-specific types */
end_comment

begin_comment
comment|/*	dev_type_dump(n)	int n __P((dev_t, daddr_t, caddr_t, int))*/
end_comment

begin_define
define|#
directive|define
name|dev_type_dump
parameter_list|(
name|n
parameter_list|)
value|int n ()
end_define

begin_define
define|#
directive|define
name|dev_type_size
parameter_list|(
name|n
parameter_list|)
value|int n __P((dev_t))
end_define

begin_comment
comment|/* error/nullop functions */
end_comment

begin_define
define|#
directive|define
name|error_open
value|((dev_type_open((*))) enodev)
end_define

begin_define
define|#
directive|define
name|error_close
value|((dev_type_close((*))) enodev)
end_define

begin_define
define|#
directive|define
name|error_ioctl
value|((dev_type_ioctl((*))) enodev)
end_define

begin_define
define|#
directive|define
name|error_dump
value|((dev_type_dump((*))) enodev)
end_define

begin_define
define|#
directive|define
name|null_open
value|((dev_type_open((*))) nullop)
end_define

begin_define
define|#
directive|define
name|null_close
value|((dev_type_close((*))) nullop)
end_define

begin_define
define|#
directive|define
name|dev_decl
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|)
value|__CONCAT(dev_type_,t)(__CONCAT(n,t))
end_define

begin_define
define|#
directive|define
name|dev_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
define|\
value|(c> 0 ? __CONCAT(n,t) : (__CONCAT(dev_type_,t)((*))) enxio)
end_define

begin_comment
comment|/* bdevsw-specific initializations */
end_comment

begin_define
define|#
directive|define
name|dev_size_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|(c> 0 ? __CONCAT(n,size) : 0)
end_define

begin_define
define|#
directive|define
name|bdev_decl
parameter_list|(
name|n
parameter_list|)
define|\
value|dev_decl(n,open); dev_decl(n,close); dev_decl(n,strategy); \ 	dev_decl(n,ioctl); dev_decl(n,dump); dev_decl(n,size)
end_define

begin_define
define|#
directive|define
name|bdev_disk_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), \ 	dev_init(c,n,strategy), dev_init(c,n,ioctl), \ 	dev_init(c,n,dump), dev_size_init(c,n), 0 }
end_define

begin_define
define|#
directive|define
name|bdev_tape_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), \ 	dev_init(c,n,strategy), dev_init(c,n,ioctl), \ 	dev_init(c,n,dump), 0, B_TAPE }
end_define

begin_define
define|#
directive|define
name|bdev_swap_init
parameter_list|()
value|{ \ 	error_open, error_close, swstrategy, error_ioctl, error_dump, 0, 0 }
end_define

begin_define
define|#
directive|define
name|bdev_notdef
parameter_list|()
value|bdev_tape_init(0,no)
end_define

begin_expr_stmt
name|bdev_decl
argument_list|(
name|no
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* dummy declarations */
end_comment

begin_include
include|#
directive|include
file|"sd.h"
end_include

begin_expr_stmt
name|bdev_decl
argument_list|(
name|sd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|bdevsw
name|bdevsw
index|[]
init|=
block|{
name|bdev_notdef
argument_list|()
block|,
comment|/* 0 */
name|bdev_notdef
argument_list|()
block|,
comment|/* 1 */
name|bdev_notdef
argument_list|()
block|,
comment|/* 2 */
name|bdev_swap_init
argument_list|()
block|,
comment|/* 3 */
name|bdev_notdef
argument_list|()
block|,
comment|/* 4 */
name|bdev_notdef
argument_list|()
block|,
comment|/* 5 */
name|bdev_notdef
argument_list|()
block|,
comment|/* 6 */
name|bdev_disk_init
argument_list|(
name|NSD
argument_list|,
name|sd
argument_list|)
block|,
comment|/* 7: scsi disk */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nblkdev
init|=
sizeof|sizeof
argument_list|(
name|bdevsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|bdevsw
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cdevsw-specific types */
end_comment

begin_define
define|#
directive|define
name|dev_type_read
parameter_list|(
name|n
parameter_list|)
value|int n __P((dev_t, struct uio *, int))
end_define

begin_define
define|#
directive|define
name|dev_type_write
parameter_list|(
name|n
parameter_list|)
value|int n __P((dev_t, struct uio *, int))
end_define

begin_define
define|#
directive|define
name|dev_type_select
parameter_list|(
name|n
parameter_list|)
value|int n __P((dev_t, int, struct proc *))
end_define

begin_define
define|#
directive|define
name|dev_type_map
parameter_list|(
name|n
parameter_list|)
value|int n __P(())
end_define

begin_define
define|#
directive|define
name|error_read
value|((dev_type_read((*))) enodev)
end_define

begin_define
define|#
directive|define
name|error_write
value|((dev_type_write((*))) enodev)
end_define

begin_define
define|#
directive|define
name|error_select
value|((dev_type_select((*))) enodev)
end_define

begin_define
define|#
directive|define
name|cdev_decl
parameter_list|(
name|n
parameter_list|)
define|\
value|dev_decl(n,open); dev_decl(n,close); dev_decl(n,read); \ 	dev_decl(n,write); dev_decl(n,ioctl); dev_decl(n,select); \ 	dev_decl(n,map); dev_decl(n,strategy); \ 	extern struct tty __CONCAT(n,_tty)[]
end_define

begin_define
define|#
directive|define
name|dev_tty_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|(c> 0 ? __CONCAT(n,_tty) : 0)
end_define

begin_comment
comment|/* open, close, read, write, ioctl, strategy */
end_comment

begin_define
define|#
directive|define
name|cdev_disk_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), rawread, rawwrite, \ 	dev_init(c,n,ioctl), 0, 0, 0, seltrue, 0, dev_init(c,n,strategy) }
end_define

begin_comment
comment|/* open, close, read, write, ioctl, strategy */
end_comment

begin_define
define|#
directive|define
name|cdev_tape_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), 0, 0, 0, seltrue, 0, \ 	dev_init(c,n,strategy) }
end_define

begin_comment
comment|/* open, close, read, write, ioctl, tty */
end_comment

begin_define
define|#
directive|define
name|cdev_tty_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), 0, 0, dev_tty_init(c,n), \ 	ttselect, 0, 0 }
end_define

begin_comment
comment|/* open, close, read, write, ioctl, select */
end_comment

begin_define
define|#
directive|define
name|cdev_gen_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), 0, 0, 0, \ 	dev_init(c,n,select), 0, 0 }
end_define

begin_comment
comment|/* open, close, ioctl, mmap */
end_comment

begin_define
define|#
directive|define
name|cdev_fb_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), error_read, error_write, \ 	dev_init(c,n,ioctl), 0, 0, 0, seltrue, dev_init(c,n,map), 0 }
end_define

begin_define
define|#
directive|define
name|cdev_notdef
parameter_list|()
value|{ \ 	error_open, error_close, error_read, error_write, \ 	error_ioctl, 0, 0, 0, seltrue, 0, 0 }
end_define

begin_expr_stmt
name|cdev_decl
argument_list|(
name|no
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* dummy declarations */
end_comment

begin_expr_stmt
name|cdev_decl
argument_list|(
name|cn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open, close, read, write, ioctl, select -- XXX should be a tty */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|tty
name|cons
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|cdev_cn_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), 0, 0,&cons, \ 	dev_init(c,n,select), 0, 0 }
end_define

begin_expr_stmt
name|cdev_decl
argument_list|(
name|ctty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open, read, write, ioctl, select -- XXX should be a tty */
end_comment

begin_define
define|#
directive|define
name|cdev_ctty_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), null_close, dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), 0, 0, 0, \ 	dev_init(c,n,select), 0, 0 }
end_define

begin_expr_stmt
name|dev_type_read
argument_list|(
name|mmrw
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* read/write */
end_comment

begin_define
define|#
directive|define
name|cdev_mm_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	null_open, null_close, mmrw, mmrw, error_ioctl, 0, 0, 0, \ 	seltrue, 0, 0 }
end_define

begin_comment
comment|/* read, write, strategy */
end_comment

begin_define
define|#
directive|define
name|cdev_swap_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	null_open, null_close, rawread, rawwrite, error_ioctl, 0, 0, 0, \ 	seltrue, 0, dev_init(c,n,strategy) }
end_define

begin_include
include|#
directive|include
file|"pty.h"
end_include

begin_define
define|#
directive|define
name|pts_tty
value|pt_tty
end_define

begin_define
define|#
directive|define
name|ptsioctl
value|ptyioctl
end_define

begin_expr_stmt
name|cdev_decl
argument_list|(
name|pts
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|ptc_tty
value|pt_tty
end_define

begin_define
define|#
directive|define
name|ptcioctl
value|ptyioctl
end_define

begin_expr_stmt
name|cdev_decl
argument_list|(
name|ptc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open, close, read, write, ioctl, tty, select */
end_comment

begin_define
define|#
directive|define
name|cdev_ptc_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), 0, 0, dev_tty_init(c,n), \ 	dev_init(c,n,select), 0, 0 }
end_define

begin_expr_stmt
name|cdev_decl
argument_list|(
name|log
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open, close, read, ioctl, select -- XXX should be a generic device */
end_comment

begin_define
define|#
directive|define
name|cdev_log_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	error_write, dev_init(c,n,ioctl), 0, 0, 0, dev_init(c,n,select), 0, 0 }
end_define

begin_expr_stmt
name|dev_type_open
argument_list|(
name|fdopen
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open */
end_comment

begin_define
define|#
directive|define
name|cdev_fd_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), error_close, error_read, error_write, \ 	error_ioctl, 0, 0, 0, error_select, 0, 0 }
end_define

begin_include
include|#
directive|include
file|"zs.h"
end_include

begin_expr_stmt
name|cdev_decl
argument_list|(
name|zs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cdev_decl
argument_list|(
name|kbd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cdev_decl
argument_list|(
name|ms
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cdev_decl
argument_list|(
name|fb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"bwtwo.h"
end_include

begin_expr_stmt
name|cdev_decl
argument_list|(
name|bwtwo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"cgthree.h"
end_include

begin_expr_stmt
name|cdev_decl
argument_list|(
name|cgthree
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"bsdaudio.h"
end_include

begin_expr_stmt
name|cdev_decl
argument_list|(
name|audio
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cdev_decl
argument_list|(
name|openprom
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open, close, ioctl */
end_comment

begin_define
define|#
directive|define
name|cdev_openprom_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), error_read, error_write, \ 	dev_init(c,n,ioctl), 0, 0, 0, error_select, 0, 0 }
end_define

begin_include
include|#
directive|include
file|"bpfilter.h"
end_include

begin_expr_stmt
name|cdev_decl
argument_list|(
name|bpf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open, close, read, write, ioctl, select -- XXX should be generic device */
end_comment

begin_define
define|#
directive|define
name|cdev_bpf_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), 0, 0, 0, \ 	dev_init(c,n,select), 0, 0 }
end_define

begin_comment
comment|/* prototype sun-equivalent cdevsw[] */
end_comment

begin_decl_stmt
name|struct
name|cdevsw
name|cdevsw
index|[]
init|=
block|{
name|cdev_cn_init
argument_list|(
literal|1
argument_list|,
name|cn
argument_list|)
block|,
comment|/* 0: virtual console */
name|cdev_notdef
argument_list|()
block|,
comment|/* 1 */
name|cdev_ctty_init
argument_list|(
literal|1
argument_list|,
name|ctty
argument_list|)
block|,
comment|/* 2: controlling terminal */
name|cdev_mm_init
argument_list|(
literal|1
argument_list|,
name|mm
argument_list|)
block|,
comment|/* 3: /dev/{null,mem,kmem,...} */
name|cdev_notdef
argument_list|()
block|,
comment|/* 4 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 5 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 6 */
name|cdev_swap_init
argument_list|(
literal|1
argument_list|,
name|sw
argument_list|)
block|,
comment|/* 7: /dev/drum (swap pseudo-device) */
name|cdev_notdef
argument_list|()
block|,
comment|/* 8 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 9 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 10 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 11 */
name|cdev_tty_init
argument_list|(
name|NZS
argument_list|,
name|zs
argument_list|)
block|,
comment|/* 12: zs serial */
name|cdev_gen_init
argument_list|(
literal|1
argument_list|,
name|ms
argument_list|)
block|,
comment|/* 13: /dev/mouse */
name|cdev_notdef
argument_list|()
block|,
comment|/* 14 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 15: sun /dev/winNNN */
name|cdev_log_init
argument_list|(
literal|1
argument_list|,
name|log
argument_list|)
block|,
comment|/* 16: /dev/klog */
name|cdev_disk_init
argument_list|(
name|NSD
argument_list|,
name|sd
argument_list|)
block|,
comment|/* 17: scsi disk */
name|cdev_notdef
argument_list|()
block|,
comment|/* 18: should be scsi tape */
name|cdev_notdef
argument_list|()
block|,
comment|/* 19 */
name|cdev_ptc_init
argument_list|(
name|NPTY
argument_list|,
name|ptc
argument_list|)
block|,
comment|/* 20: pseudo-tty master */
name|cdev_tty_init
argument_list|(
name|NPTY
argument_list|,
name|pts
argument_list|)
block|,
comment|/* 21: pseudo-tty slave */
name|cdev_fb_init
argument_list|(
literal|1
argument_list|,
name|fb
argument_list|)
block|,
comment|/* 22: /dev/fb indirect driver */
name|cdev_notdef
argument_list|()
block|,
comment|/* 23 */
name|cdev_fd_init
argument_list|(
literal|1
argument_list|,
name|fd
argument_list|)
block|,
comment|/* 24: /dev/std{in,out,err} */
name|cdev_notdef
argument_list|()
block|,
comment|/* 25 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 26 */
name|cdev_fb_init
argument_list|(
name|NBWTWO
argument_list|,
name|bwtwo
argument_list|)
block|,
comment|/* 27: /dev/bwtwo */
name|cdev_notdef
argument_list|()
block|,
comment|/* 28 */
name|cdev_gen_init
argument_list|(
literal|1
argument_list|,
name|kbd
argument_list|)
block|,
comment|/* 29: /dev/kbd */
name|cdev_notdef
argument_list|()
block|,
comment|/* 30 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 31: should be /dev/cgtwo */
name|cdev_notdef
argument_list|()
block|,
comment|/* 32: should be /dev/gpone */
name|cdev_notdef
argument_list|()
block|,
comment|/* 33 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 34 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 35 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 36 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 37 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 38 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 39 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 40 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 41 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 42 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 43 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 44 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 45 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 46 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 47 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 48 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 49 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 50 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 51 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 52 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 53 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 54 */
name|cdev_fb_init
argument_list|(
name|NCGTHREE
argument_list|,
name|cgthree
argument_list|)
block|,
comment|/* 55: /dev/cgthree */
name|cdev_notdef
argument_list|()
block|,
comment|/* 56 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 57 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 58 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 59 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 60 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 61 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 62 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 63 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 64 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 65 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 66 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 67 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 68 */
name|cdev_gen_init
argument_list|(
name|NBSDAUDIO
argument_list|,
name|audio
argument_list|)
block|,
comment|/* 69: /dev/audio */
name|cdev_openprom_init
argument_list|(
literal|1
argument_list|,
name|openprom
argument_list|)
block|,
comment|/* 70: /dev/openprom */
name|cdev_notdef
argument_list|()
block|,
comment|/* 71 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 72 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 73 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 74 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 75 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 76 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 77 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 78 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 79 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 80 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 81 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 82 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 83 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 84 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 85 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 86 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 87 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 88 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 89 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 90 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 91 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 92 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 93 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 94 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 95 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 96 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 97 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 98 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 99 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 100 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 101 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 102 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 103 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 104 */
name|cdev_bpf_init
argument_list|(
name|NBPFILTER
argument_list|,
name|bpf
argument_list|)
block|,
comment|/* 105: packet filter */
name|cdev_notdef
argument_list|()
block|,
comment|/* 106 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 107 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 108 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 109 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nchrdev
init|=
sizeof|sizeof
argument_list|(
name|cdevsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|cdevsw
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Swapdev is a fake device implemented  * in sw.c used only internally to get to swstrategy.  * It cannot be provided to the users, because the  * swstrategy routine munches the b_dev and b_blkno entries  * before calling the appropriate driver.  This would horribly  * confuse, e.g. the hashing routines. Instead, /dev/drum is  * provided as a character (raw) device.  */
end_comment

begin_decl_stmt
name|dev_t
name|swapdev
init|=
name|makedev
argument_list|(
literal|3
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Routine that identifies /dev/mem and /dev/kmem.  *  * A minimal stub routine can always return 0.  */
end_comment

begin_macro
name|iskmemdev
argument_list|(
argument|dev
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|major
argument_list|(
name|dev
argument_list|)
operator|==
literal|3
operator|&&
name|minor
argument_list|(
name|dev
argument_list|)
operator|<
literal|2
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Routine to determine if a device is a disk.  *  * A minimal stub routine can always return 0.  */
end_comment

begin_macro
name|isdisk
argument_list|(
argument|dev
argument_list|,
argument|type
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|notyet
comment|/* someday, something like this, perhaps */
name|dev
operator|=
name|devtab
index|[
name|major
argument_list|(
name|dev
argument_list|)
index|]
expr_stmt|;
return|return
operator|(
name|dev
operator|!=
name|NULL
operator|&&
name|dev
operator|->
name|dv_class
operator|==
name|DV_DISK
operator|)
return|;
else|#
directive|else
switch|switch
condition|(
name|major
argument_list|(
name|dev
argument_list|)
condition|)
block|{
case|case
literal|7
case|:
if|if
condition|(
name|type
operator|==
name|VBLK
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|17
case|:
if|if
condition|(
name|type
operator|==
name|VCHR
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* fall through */
default|default:
return|return
operator|(
literal|0
operator|)
return|;
block|}
endif|#
directive|endif
block|}
end_block

begin_comment
comment|/*  * Routine to convert from character to block device number.  *  * A minimal stub routine can always return NODEV.  */
end_comment

begin_macro
name|chrtoblk
argument_list|(
argument|dev
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|major
argument_list|(
name|dev
argument_list|)
operator|!=
literal|17
condition|)
return|return
operator|(
name|NODEV
operator|)
return|;
return|return
operator|(
name|makedev
argument_list|(
literal|7
argument_list|,
name|minor
argument_list|(
name|dev
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

