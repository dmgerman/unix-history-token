begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: hpux.h 1.33 93/08/05$  *  *	@(#)hpux.h	8.4 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<hp/hpux/hpux_exec.h>
end_include

begin_comment
comment|/* HP-UX style UTSNAME struct used by uname syscall */
end_comment

begin_struct
struct|struct
name|hpuxutsname
block|{
name|char
name|sysname
index|[
literal|9
index|]
decl_stmt|;
name|char
name|nodename
index|[
literal|9
index|]
decl_stmt|;
name|char
name|release
index|[
literal|9
index|]
decl_stmt|;
name|char
name|version
index|[
literal|9
index|]
decl_stmt|;
name|char
name|machine
index|[
literal|9
index|]
decl_stmt|;
name|char
name|idnumber
index|[
literal|15
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* HP-UX style "old" IOCTLs */
end_comment

begin_struct
struct|struct
name|hpuxsgttyb
block|{
name|char
name|sg_ispeed
decl_stmt|;
name|char
name|sg_ospeed
decl_stmt|;
name|char
name|sg_erase
decl_stmt|;
name|char
name|sg_kill
decl_stmt|;
name|int
name|sg_flags
decl_stmt|;
comment|/* only a short in BSD */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|V7_HUPCL
value|00001
end_define

begin_define
define|#
directive|define
name|V7_XTABS
value|00002
end_define

begin_define
define|#
directive|define
name|V7_NOAL
value|04000
end_define

begin_define
define|#
directive|define
name|HPUXTIOCGETP
value|_IOR('t', 8, struct hpuxsgttyb)
end_define

begin_define
define|#
directive|define
name|HPUXTIOCSETP
value|_IOW('t', 9, struct hpuxsgttyb)
end_define

begin_comment
comment|/* 6.5 job control related ioctls which need to be mapped */
end_comment

begin_define
define|#
directive|define
name|HPUXTIOCSLTC
value|_IOW('T', 23, struct ltchars)
end_define

begin_define
define|#
directive|define
name|HPUXTIOCGLTC
value|_IOR('T', 24, struct ltchars)
end_define

begin_define
define|#
directive|define
name|HPUXTIOCLBIS
value|_IOW('T', 25, int)
end_define

begin_define
define|#
directive|define
name|HPUXTIOCLBIC
value|_IOW('T', 26, int)
end_define

begin_define
define|#
directive|define
name|HPUXTIOCLSET
value|_IOW('T', 27, int)
end_define

begin_define
define|#
directive|define
name|HPUXTIOCLGET
value|_IOR('T', 28, int)
end_define

begin_define
define|#
directive|define
name|HPUXLTOSTOP
value|0000001
end_define

begin_define
define|#
directive|define
name|HPUXTIOCSPGRP
value|_IOW('T', 29, int)
end_define

begin_define
define|#
directive|define
name|HPUXTIOCGPGRP
value|_IOR('T', 30, int)
end_define

begin_define
define|#
directive|define
name|HPUXTIOCCONS
value|_IO('t', 104)
end_define

begin_define
define|#
directive|define
name|HPUXTIOCSWINSZ
value|_IOW('t', 106, struct winsize)
end_define

begin_define
define|#
directive|define
name|HPUXTIOCGWINSZ
value|_IOR('t', 107, struct winsize)
end_define

begin_comment
comment|/* non-blocking IO--doesn't interfere with O_NDELAY */
end_comment

begin_define
define|#
directive|define
name|HPUXFIOSNBIO
value|_IOW('f', 126, int)
end_define

begin_comment
comment|/* HP-UX stat structure */
end_comment

begin_define
define|#
directive|define
name|bsdtohpuxdev
parameter_list|(
name|d
parameter_list|)
value|((major(d)<< 24) | minor(d))
end_define

begin_struct
struct|struct
name|hpuxstat
block|{
name|long
name|hst_dev
decl_stmt|;
name|u_long
name|hst_ino
decl_stmt|;
name|u_short
name|hst_mode
decl_stmt|;
name|short
name|hst_nlink
decl_stmt|;
name|u_short
name|hst_uid
decl_stmt|;
name|u_short
name|hst_gid
decl_stmt|;
name|long
name|hst_rdev
decl_stmt|;
name|long
name|hst_size
decl_stmt|;
name|time_t
name|hst_atime
decl_stmt|;
name|int
name|hst_spare1
decl_stmt|;
name|time_t
name|hst_mtime
decl_stmt|;
name|int
name|hst_spare2
decl_stmt|;
name|time_t
name|hst_ctime
decl_stmt|;
name|int
name|hst_spare3
decl_stmt|;
name|long
name|hst_blksize
decl_stmt|;
name|long
name|hst_blocks
decl_stmt|;
name|u_int
name|hst_remote
decl_stmt|;
name|long
name|hst_netdev
decl_stmt|;
name|u_long
name|hst_netino
decl_stmt|;
name|long
name|hst_spare4
index|[
literal|9
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Skeletal 6.X HP-UX user structure info for ptrace() mapping.  * Yes, this is as bogus as it gets...  */
end_comment

begin_comment
comment|/* 6.0/6.2 offsets */
end_comment

begin_define
define|#
directive|define
name|ooHU_AROFF
value|0x004
end_define

begin_define
define|#
directive|define
name|ooHU_TSOFF
value|0x092
end_define

begin_define
define|#
directive|define
name|ooHU_EDOFF
value|0x91E
end_define

begin_define
define|#
directive|define
name|ooHU_FPOFF
value|0xA66
end_define

begin_comment
comment|/* 6.5 offsets */
end_comment

begin_define
define|#
directive|define
name|oHU_AROFF
value|0x004
end_define

begin_define
define|#
directive|define
name|oHU_TSOFF
value|0x0B2
end_define

begin_define
define|#
directive|define
name|oHU_EDOFF
value|0x93A
end_define

begin_define
define|#
directive|define
name|oHU_FPOFF
value|0xA86
end_define

begin_comment
comment|/* 7.X offsets */
end_comment

begin_define
define|#
directive|define
name|HU_AROFF
value|0x004
end_define

begin_define
define|#
directive|define
name|HU_TSOFF
value|0x0B4
end_define

begin_define
define|#
directive|define
name|HU_EDOFF
value|0x8C8
end_define

begin_define
define|#
directive|define
name|HU_FPOFF
value|0xA28
end_define

begin_define
define|#
directive|define
name|HU_PAD1
value|(HU_AROFF)
end_define

begin_define
define|#
directive|define
name|HU_PAD2
value|(HU_TSOFF-HU_AROFF-4)
end_define

begin_define
define|#
directive|define
name|HU_PAD3
value|(HU_EDOFF-HU_TSOFF-12)
end_define

begin_define
define|#
directive|define
name|HU_PAD4
value|(HU_FPOFF-HU_EDOFF-sizeof(struct hpux_exec))
end_define

begin_struct
struct|struct
name|hpuxuser
block|{
name|u_char
name|whocares1
index|[
name|HU_PAD1
index|]
decl_stmt|;
comment|/* +0x000 */
name|int
modifier|*
name|hpuxu_ar0
decl_stmt|;
comment|/* +0x004 */
name|u_char
name|whocares2
index|[
name|HU_PAD2
index|]
decl_stmt|;
comment|/* +0x008 */
name|int
name|hpuxu_tsize
decl_stmt|;
comment|/* +0x0B2 */
name|int
name|hpuxu_dsize
decl_stmt|;
comment|/* +0x0B6 */
name|int
name|hpuxu_ssize
decl_stmt|;
comment|/* +0x0BA */
name|u_char
name|whocares3
index|[
name|HU_PAD3
index|]
decl_stmt|;
comment|/* +0x0BE */
name|struct
name|hpux_exec
name|hpuxu_exdata
decl_stmt|;
comment|/* +0x93A */
name|u_char
name|whocares4
index|[
name|HU_PAD4
index|]
decl_stmt|;
comment|/* +0x95E */
struct|struct
name|hpuxfp
block|{
comment|/* +0xA66 */
name|int
name|hpfp_save
index|[
literal|54
index|]
decl_stmt|;
name|int
name|hpfp_ctrl
index|[
literal|3
index|]
decl_stmt|;
name|int
name|hpfp_reg
index|[
literal|24
index|]
decl_stmt|;
block|}
name|hpuxu_fp
struct|;
name|short
name|hpuxu_dragon
decl_stmt|;
comment|/* +0xBCA */
block|}
struct|;
end_struct

begin_comment
comment|/* HP-UX compat file flags */
end_comment

begin_define
define|#
directive|define
name|HPUXNDELAY
value|00000004
end_define

begin_define
define|#
directive|define
name|HPUXFCREAT
value|00000400
end_define

begin_define
define|#
directive|define
name|HPUXFTRUNC
value|00001000
end_define

begin_define
define|#
directive|define
name|HPUXFEXCL
value|00002000
end_define

begin_define
define|#
directive|define
name|HPUXFSYNCIO
value|00100000
end_define

begin_define
define|#
directive|define
name|HPUXNONBLOCK
value|00200000
end_define

begin_define
define|#
directive|define
name|HPUXFREMOTE
value|01000000
end_define

begin_comment
comment|/* HP-UX fcntl file locking */
end_comment

begin_struct
struct|struct
name|hpuxflock
block|{
name|short
name|hl_type
decl_stmt|;
name|short
name|hl_whence
decl_stmt|;
name|long
name|hl_start
decl_stmt|;
name|long
name|hl_len
decl_stmt|;
name|long
name|hl_pid
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HPUXF_GETLK
value|7
end_define

begin_define
define|#
directive|define
name|HPUXF_SETLK
value|8
end_define

begin_define
define|#
directive|define
name|HPUXF_SETLKW
value|9
end_define

begin_define
define|#
directive|define
name|HPUXF_RDLCK
value|1
end_define

begin_define
define|#
directive|define
name|HPUXF_WRLCK
value|2
end_define

begin_define
define|#
directive|define
name|HPUXF_UNLCK
value|3
end_define

begin_comment
comment|/* HP-UX only sysV shmctl() commands */
end_comment

begin_define
define|#
directive|define
name|SHM_LOCK
value|3
end_define

begin_comment
comment|/* Lock segment in core */
end_comment

begin_define
define|#
directive|define
name|SHM_UNLOCK
value|4
end_define

begin_comment
comment|/* Unlock segment */
end_comment

begin_comment
comment|/* SHM stuff reflecting POSIX types */
end_comment

begin_struct
struct|struct
name|hpuxipc_perm
block|{
name|long
name|uid
decl_stmt|;
comment|/* owner's user id */
name|long
name|gid
decl_stmt|;
comment|/* owner's group id */
name|long
name|cuid
decl_stmt|;
comment|/* creator's user id */
name|long
name|cgid
decl_stmt|;
comment|/* creator's group id */
name|u_short
name|mode
decl_stmt|;
comment|/* access modes */
name|u_short
name|seq
decl_stmt|;
comment|/* slot usage sequence number */
name|long
name|key
decl_stmt|;
comment|/* key */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hpuxshmid_ds
block|{
name|struct
name|hpuxipc_perm
name|shm_perm
decl_stmt|;
comment|/* operation permission struct */
name|int
name|shm_segsz
decl_stmt|;
comment|/* segment size (bytes) */
name|struct
name|pte
modifier|*
name|shm_ptbl
decl_stmt|;
comment|/* ptr to associated page table */
name|long
name|shm_lpid
decl_stmt|;
comment|/* pid of last shmop */
name|long
name|shm_cpid
decl_stmt|;
comment|/* pid of creator */
name|u_short
name|shm_nattch
decl_stmt|;
comment|/* current # attached */
name|u_short
name|shm_cnattch
decl_stmt|;
comment|/* in memory # attached */
name|time_t
name|shm_atime
decl_stmt|;
comment|/* last shmat time */
name|time_t
name|shm_dtime
decl_stmt|;
comment|/* last shmdt time */
name|time_t
name|shm_ctime
decl_stmt|;
comment|/* last change time */
comment|/* actually longer */
block|}
struct|;
end_struct

begin_comment
comment|/* HP-UX rtprio values */
end_comment

begin_define
define|#
directive|define
name|RTPRIO_MIN
value|0
end_define

begin_define
define|#
directive|define
name|RTPRIO_MAX
value|127
end_define

begin_define
define|#
directive|define
name|RTPRIO_NOCHG
value|1000
end_define

begin_define
define|#
directive|define
name|RTPRIO_RTOFF
value|1001
end_define

begin_comment
comment|/* HP-UX only sigvec sv_flags values */
end_comment

begin_define
define|#
directive|define
name|HPUXSV_RESET
value|000000004
end_define

begin_comment
comment|/*  * HP-UX returns SIGILL instead of SIGFPE for the CHK and TRAPV exceptions.  * It also returns different u_code values for certain illegal instruction  * and floating point exceptions.  Here are the proper HP-UX u_code values  * (numbers from hpux 6.2 manual pages).  */
end_comment

begin_comment
comment|/* SIGILL codes */
end_comment

begin_define
define|#
directive|define
name|HPUX_ILL_ILLINST_TRAP
value|0
end_define

begin_comment
comment|/* T_ILLINST+USER */
end_comment

begin_define
define|#
directive|define
name|HPUX_ILL_CHK_TRAP
value|6
end_define

begin_comment
comment|/* T_CHKINST+USER */
end_comment

begin_define
define|#
directive|define
name|HPUX_ILL_TRAPV_TRAP
value|7
end_define

begin_comment
comment|/* T_TRAPVINST+USER */
end_comment

begin_define
define|#
directive|define
name|HPUX_ILL_PRIV_TRAP
value|8
end_define

begin_comment
comment|/* T_PRIVINST+USER */
end_comment

begin_comment
comment|/* SIGFPE codes */
end_comment

begin_define
define|#
directive|define
name|HPUX_FPE_INTDIV_TRAP
value|5
end_define

begin_comment
comment|/* T_ZERODIV+USER */
end_comment

begin_comment
comment|/* HP-UX POSIX signal stuff implementation */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__hpuxsigset_t
block|{
name|long
name|sigset
index|[
literal|8
index|]
decl_stmt|;
block|}
name|hpuxsigset_t
typedef|;
end_typedef

begin_struct
struct|struct
name|hpuxsigaction
block|{
name|void
function_decl|(
modifier|*
name|sa_handler
function_decl|)
parameter_list|()
function_decl|;
name|hpuxsigset_t
name|sa_mask
decl_stmt|;
name|int
name|sa_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HPUXSA_ONSTACK
value|1
end_define

begin_define
define|#
directive|define
name|HPUXSA_RESETHAND
value|4
end_define

begin_define
define|#
directive|define
name|HPUXSA_NOCLDSTOP
value|8
end_define

begin_define
define|#
directive|define
name|HPUXSIG_BLOCK
value|0
end_define

begin_comment
comment|/* block specified signal set */
end_comment

begin_define
define|#
directive|define
name|HPUXSIG_UNBLOCK
value|1
end_define

begin_comment
comment|/* unblock specified signal set */
end_comment

begin_define
define|#
directive|define
name|HPUXSIG_SETMASK
value|2
end_define

begin_comment
comment|/* set specified signal set */
end_comment

begin_comment
comment|/* sysconf stuff */
end_comment

begin_define
define|#
directive|define
name|HPUX_SYSCONF_CLKTICK
value|2
end_define

begin_define
define|#
directive|define
name|HPUX_SYSCONF_OPENMAX
value|4
end_define

begin_define
define|#
directive|define
name|HPUX_SYSCONF_CPUTYPE
value|10001
end_define

begin_define
define|#
directive|define
name|HPUX_SYSCONF_CPUM020
value|0x20C
end_define

begin_define
define|#
directive|define
name|HPUX_SYSCONF_CPUM030
value|0x20D
end_define

begin_define
define|#
directive|define
name|HPUX_SYSCONF_CPUM040
value|0x20E
end_define

begin_define
define|#
directive|define
name|HPUX_SYSCONF_CPUPA10
value|0x20B
end_define

begin_define
define|#
directive|define
name|HPUX_SYSCONF_CPUPA11
value|0x210
end_define

begin_comment
comment|/* mmap stuff */
end_comment

begin_define
define|#
directive|define
name|HPUXMAP_FIXED
value|0x04
end_define

begin_define
define|#
directive|define
name|HPUXMAP_REPLACE
value|0x08
end_define

begin_define
define|#
directive|define
name|HPUXMAP_ANON
value|0x10
end_define

begin_comment
comment|/* rlimit stuff */
end_comment

begin_define
define|#
directive|define
name|HPUXRLIMIT_NOFILE
value|6
end_define

begin_comment
comment|/*  * In BSD EAGAIN and EWOULDBLOCK are the same error code.  * However, for HP-UX we must split them out to seperate codes.  * The easiest way to do this was to check the return value of  * BSD routines which are known to return EAGAIN (but never  * EWOULDBLOCK) and change it to the pseudo-code OEAGAIN when  * we see it.  The error translation table will them map that  * code to the HP-UX EAGAIN value.  */
end_comment

begin_define
define|#
directive|define
name|OEAGAIN
value|82
end_define

end_unit

