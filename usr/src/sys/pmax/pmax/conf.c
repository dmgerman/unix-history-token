begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)conf.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_include
include|#
directive|include
file|"tty.h"
end_include

begin_include
include|#
directive|include
file|"conf.h"
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

begin_define
define|#
directive|define
name|dev_type_dump
parameter_list|(
name|n
parameter_list|)
value|int n __P((dev_t))
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
value|{ \ 	dev_init(c,n,open), (dev_type_close((*))) nullop, \ 	dev_init(c,n,strategy), dev_init(c,n,ioctl), \ 	dev_init(c,n,dump), dev_size_init(c,n), 0 }
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
value|{ \ 	(dev_type_open((*))) enodev, (dev_type_close((*))) enodev, \ 	swstrategy, (dev_type_ioctl((*))) enodev, \ 	(dev_type_dump((*))) enodev, 0, 0 }
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
file|"rz.h"
end_include

begin_include
include|#
directive|include
file|"vn.h"
end_include

begin_expr_stmt
name|bdev_decl
argument_list|(
name|rz
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bdev_decl
argument_list|(
name|vn
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
name|bdev_disk_init
argument_list|(
name|NRZ
argument_list|,
name|rz
argument_list|)
block|,
comment|/* 0: SCSI disk */
name|bdev_swap_init
argument_list|()
block|,
comment|/* 1: swap pseudo-device */
name|bdev_disk_init
argument_list|(
name|NVN
argument_list|,
name|vn
argument_list|)
block|,
comment|/* 2: vnode disk driver (swap to files) */
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
name|dev_type_stop
parameter_list|(
name|n
parameter_list|)
value|int n __P((struct tty *, int))
end_define

begin_define
define|#
directive|define
name|dev_type_reset
parameter_list|(
name|n
parameter_list|)
value|int n __P((int))
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
name|cdev_decl
parameter_list|(
name|n
parameter_list|)
define|\
value|dev_decl(n,open); dev_decl(n,close); dev_decl(n,read); \ 	dev_decl(n,write); dev_decl(n,ioctl); dev_decl(n,stop); \ 	dev_decl(n,reset); dev_decl(n,select); dev_decl(n,map); \ 	dev_decl(n,strategy); extern struct tty __CONCAT(n,_tty)[]
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
comment|/* open, read, write, ioctl, strategy */
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
value|{ \ 	dev_init(c,n,open), (dev_type_close((*))) nullop, dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), (dev_type_stop((*))) enodev, \ 	(dev_type_reset((*))) nullop, 0, seltrue, (dev_type_map((*))) enodev, \ 	dev_init(c,n,strategy) }
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
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), (dev_type_stop((*))) enodev, \ 	(dev_type_reset((*))) nullop, 0, seltrue, (dev_type_map((*))) enodev, \ 	dev_init(c,n,strategy) }
end_define

begin_comment
comment|/* open, close, read, write, ioctl, stop, tty */
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
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), dev_init(c,n,stop), \ 	(dev_type_reset((*))) nullop, dev_tty_init(c,n), ttselect, \ 	(dev_type_map((*))) enodev, 0 }
end_define

begin_define
define|#
directive|define
name|cdev_notdef
parameter_list|()
value|{ \ 	(dev_type_open((*))) enodev, (dev_type_close((*))) enodev, \ 	(dev_type_read((*))) enodev, (dev_type_write((*))) enodev, \ 	(dev_type_ioctl((*))) enodev, (dev_type_stop((*))) enodev, \ 	(dev_type_reset((*))) nullop, 0, seltrue, \ 	(dev_type_map((*))) enodev, 0 }
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
name|dc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open, close, read, write, ioctl, select -- XXX should be a tty */
end_comment

begin_define
define|#
directive|define
name|cdev_dc_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), (dev_type_stop((*))) nullop, \ 	(dev_type_reset((*))) nullop, 0, ttselect, \ 	(dev_type_map((*))) enodev, 0 }
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
value|{ \ 	dev_init(c,n,open), (dev_type_close((*))) nullop, dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), (dev_type_stop((*))) nullop, \ 	(dev_type_reset((*))) nullop, 0, dev_init(c,n,select), \ 	(dev_type_map((*))) enodev, 0 }
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
value|{ \ 	(dev_type_open((*))) nullop, (dev_type_close((*))) nullop, mmrw, \ 	mmrw, (dev_type_ioctl((*))) enodev, (dev_type_stop((*))) nullop, \ 	(dev_type_reset((*))) nullop, 0, seltrue, (dev_type_map((*))) enodev, 0 }
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
value|{ \ 	(dev_type_open((*))) nullop, (dev_type_close((*))) nullop, rawread, \ 	rawwrite, (dev_type_ioctl((*))) enodev, (dev_type_stop((*))) enodev, \ 	(dev_type_reset((*))) nullop, 0, (dev_type_select((*))) enodev, \ 	(dev_type_map((*))) enodev, dev_init(c,n,strategy) }
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
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), (dev_type_stop((*))) nullop, \ 	(dev_type_reset((*))) nullop, dev_tty_init(c,n), dev_init(c,n,select), \ 	(dev_type_map((*))) enodev, 0 }
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
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	(dev_type_write((*))) enodev, dev_init(c,n,ioctl), \ 	(dev_type_stop((*))) enodev, (dev_type_reset((*))) nullop, 0, \ 	dev_init(c,n,select), (dev_type_map((*))) enodev, 0 }
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
value|{ \ 	dev_init(c,n,open), (dev_type_close((*))) enodev, \ 	(dev_type_read((*))) enodev, (dev_type_write((*))) enodev, \ 	(dev_type_ioctl((*))) enodev, (dev_type_stop((*))) enodev, \ 	(dev_type_reset((*))) enodev, 0, (dev_type_select((*))) enodev, \ 	(dev_type_map((*))) enodev, 0 }
end_define

begin_include
include|#
directive|include
file|"pm.h"
end_include

begin_expr_stmt
name|cdev_decl
argument_list|(
name|pm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|cdev_pm_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), \ 	(dev_type_read((*))) enodev, (dev_type_write((*))) enodev, \ 	dev_init(c,n,ioctl), (dev_type_stop((*))) enodev, \ 	(dev_type_reset((*))) enodev, 0, dev_init(c,n,select), \ 	(dev_type_map((*))) enodev, 0 }
end_define

begin_expr_stmt
name|cdev_decl
argument_list|(
name|rz
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"tz.h"
end_include

begin_expr_stmt
name|cdev_decl
argument_list|(
name|tz
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cdev_decl
argument_list|(
name|vn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open, read, write, ioctl -- XXX should be a disk */
end_comment

begin_define
define|#
directive|define
name|cdev_vn_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), (dev_type_close((*))) nullop, dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), (dev_type_stop((*))) enodev, \ 	(dev_type_reset((*))) nullop, 0, seltrue, (dev_type_map((*))) enodev, \ 	0 }
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
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), (dev_type_stop((*))) enodev, \ 	(dev_type_reset((*))) enodev, 0, dev_init(c,n,select), \ 	(dev_type_map((*))) enodev, 0 }
end_define

begin_decl_stmt
name|struct
name|cdevsw
name|cdevsw
index|[]
init|=
block|{
name|cdev_dc_init
argument_list|(
literal|1
argument_list|,
name|dc
argument_list|)
block|,
comment|/* 0: virtual console */
name|cdev_ctty_init
argument_list|(
literal|1
argument_list|,
name|ctty
argument_list|)
block|,
comment|/* 1: controlling terminal */
name|cdev_mm_init
argument_list|(
literal|1
argument_list|,
name|mm
argument_list|)
block|,
comment|/* 2: /dev/{null,mem,kmem,...} */
name|cdev_swap_init
argument_list|(
literal|1
argument_list|,
name|sw
argument_list|)
block|,
comment|/* 3: /dev/drum (swap pseudo-device) */
name|cdev_tty_init
argument_list|(
name|NPTY
argument_list|,
name|pts
argument_list|)
block|,
comment|/* 4: pseudo-tty slave */
name|cdev_ptc_init
argument_list|(
name|NPTY
argument_list|,
name|ptc
argument_list|)
block|,
comment|/* 5: pseudo-tty master */
name|cdev_log_init
argument_list|(
literal|1
argument_list|,
name|log
argument_list|)
block|,
comment|/* 6: /dev/klog */
name|cdev_fd_init
argument_list|(
literal|1
argument_list|,
name|fd
argument_list|)
block|,
comment|/* 7: file descriptor pseudo-dev */
name|cdev_pm_init
argument_list|(
name|NPM
argument_list|,
name|pm
argument_list|)
block|,
comment|/* 8: frame buffer */
name|cdev_disk_init
argument_list|(
name|NRZ
argument_list|,
name|rz
argument_list|)
block|,
comment|/* 9: SCSI disk */
name|cdev_tape_init
argument_list|(
name|NTZ
argument_list|,
name|tz
argument_list|)
block|,
comment|/* 10: SCSI tape */
name|cdev_vn_init
argument_list|(
name|NVN
argument_list|,
name|vn
argument_list|)
block|,
comment|/* 11: vnode disk */
name|cdev_bpf_init
argument_list|(
name|NBPFILTER
argument_list|,
name|bpf
argument_list|)
block|,
comment|/* 12: berkeley packet filter */
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

begin_decl_stmt
name|int
name|mem_no
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* major device number of memory special file */
end_comment

begin_comment
comment|/*  * Swapdev is a fake device implemented  * in sw.c used only internally to get to swstrategy.  * It cannot be provided to the users, because the  * swstrategy routine munches the b_dev and b_blkno entries  * before calling the appropriate driver.  This would horribly  * confuse, e.g. the hashing routines. Instead, /dev/drum is  * provided as a character (raw) device.  */
end_comment

begin_decl_stmt
name|dev_t
name|swapdev
init|=
name|makedev
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

