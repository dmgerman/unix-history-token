begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998-1999 Andrew Gallatin  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$   */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sysent
name|osf1_sysent
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bsd_to_osf1_sig
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bsd_to_osf1_errno
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|OSF1_MINSIGSTKSZ
value|4096
end_define

begin_comment
comment|/* osf/1 ioctls */
end_comment

begin_define
define|#
directive|define
name|OSF1_IOCPARM_MASK
value|0x1fff
end_define

begin_comment
comment|/* parameter length, at most 13 bits */
end_comment

begin_define
define|#
directive|define
name|OSF1_IOCPARM_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& OSF1_IOCPARM_MASK)
end_define

begin_define
define|#
directive|define
name|OSF1_IOCGROUP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|OSF1_IOCPARM_MAX
value|NBPG
end_define

begin_comment
comment|/* max size of ioctl */
end_comment

begin_define
define|#
directive|define
name|OSF1_IOC_VOID
value|0x20000000
end_define

begin_comment
comment|/* no parameters */
end_comment

begin_define
define|#
directive|define
name|OSF1_IOC_OUT
value|0x40000000
end_define

begin_comment
comment|/* copy out parameters */
end_comment

begin_define
define|#
directive|define
name|OSF1_IOC_IN
value|0x80000000
end_define

begin_comment
comment|/* copy in parameters */
end_comment

begin_define
define|#
directive|define
name|OSF1_IOC_INOUT
value|(OSF1_IOC_IN|OSF1_IOC_OUT)
end_define

begin_define
define|#
directive|define
name|OSF1_IOC_DIRMASK
value|0xe0000000
end_define

begin_comment
comment|/* mask for IN/OUT/VOID */
end_comment

begin_define
define|#
directive|define
name|OSF1_IOCCMD
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_comment
comment|/* for get sysinfo */
end_comment

begin_define
define|#
directive|define
name|OSF_GET_MAX_UPROCS
value|2
end_define

begin_define
define|#
directive|define
name|OSF_GET_PHYSMEM
value|19
end_define

begin_define
define|#
directive|define
name|OSF_GET_MAX_CPU
value|30
end_define

begin_define
define|#
directive|define
name|OSF_GET_IEEE_FP_CONTROL
value|45
end_define

begin_define
define|#
directive|define
name|OSF_GET_CPUS_IN_BOX
value|55
end_define

begin_define
define|#
directive|define
name|OSF_GET_CPU_INFO
value|59
end_define

begin_define
define|#
directive|define
name|OSF_GET_PROC_TYPE
value|60
end_define

begin_define
define|#
directive|define
name|OSF_GET_HWRPB
value|101
end_define

begin_define
define|#
directive|define
name|OSF_GET_PLATFORM_NAME
value|103
end_define

begin_struct
struct|struct
name|osf1_cpu_info
block|{
name|int
name|current_cpu
decl_stmt|;
name|int
name|cpus_in_box
decl_stmt|;
name|int
name|cpu_type
decl_stmt|;
name|int
name|ncpus
decl_stmt|;
name|u_int64_t
name|cpus_present
decl_stmt|;
name|u_int64_t
name|cpus_running
decl_stmt|;
name|u_int64_t
name|cpu_binding
decl_stmt|;
name|u_int64_t
name|cpu_ex_binding
decl_stmt|;
name|int
name|mhz
decl_stmt|;
name|int
name|unused
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* for set sysinfo */
end_comment

begin_define
define|#
directive|define
name|OSF_SET_IEEE_FP_CONTROL
value|14
end_define

begin_comment
comment|/* for rlimit */
end_comment

begin_define
define|#
directive|define
name|OSF1_RLIMIT_LASTCOMMON
value|5
end_define

begin_comment
comment|/* last one that's common */
end_comment

begin_define
define|#
directive|define
name|OSF1_RLIMIT_NOFILE
value|6
end_define

begin_comment
comment|/* OSF1's RLIMIT_NOFILE */
end_comment

begin_define
define|#
directive|define
name|OSF1_RLIMIT_NLIMITS
value|8
end_define

begin_comment
comment|/* Number of OSF1 rlimits */
end_comment

begin_comment
comment|/* mmap flags */
end_comment

begin_define
define|#
directive|define
name|OSF1_MAP_SHARED
value|0x001
end_define

begin_define
define|#
directive|define
name|OSF1_MAP_PRIVATE
value|0x002
end_define

begin_define
define|#
directive|define
name|OSF1_MAP_ANONYMOUS
value|0x010
end_define

begin_define
define|#
directive|define
name|OSF1_MAP_FILE
value|0x000
end_define

begin_define
define|#
directive|define
name|OSF1_MAP_TYPE
value|0x0f0
end_define

begin_define
define|#
directive|define
name|OSF1_MAP_FIXED
value|0x100
end_define

begin_define
define|#
directive|define
name|OSF1_MAP_HASSEMAPHORE
value|0x200
end_define

begin_define
define|#
directive|define
name|OSF1_MAP_INHERIT
value|0x400
end_define

begin_define
define|#
directive|define
name|OSF1_MAP_UNALIGNED
value|0x800
end_define

begin_comment
comment|/* msync flags */
end_comment

begin_define
define|#
directive|define
name|OSF1_MS_ASYNC
value|1
end_define

begin_define
define|#
directive|define
name|OSF1_MS_SYNC
value|2
end_define

begin_define
define|#
directive|define
name|OSF1_MS_INVALIDATE
value|4
end_define

begin_define
define|#
directive|define
name|OSF1_F_DUPFD
value|0
end_define

begin_define
define|#
directive|define
name|OSF1_F_GETFD
value|1
end_define

begin_define
define|#
directive|define
name|OSF1_F_SETFD
value|2
end_define

begin_define
define|#
directive|define
name|OSF1_F_GETFL
value|3
end_define

begin_define
define|#
directive|define
name|OSF1_F_SETFL
value|4
end_define

begin_define
define|#
directive|define
name|_OSF1_PC_CHOWN_RESTRICTED
value|10
end_define

begin_define
define|#
directive|define
name|_OSF1_PC_LINK_MAX
value|11
end_define

begin_define
define|#
directive|define
name|_OSF1_PC_MAX_CANON
value|12
end_define

begin_define
define|#
directive|define
name|_OSF1_PC_MAX_INPUT
value|13
end_define

begin_define
define|#
directive|define
name|_OSF1_PC_NAME_MAX
value|14
end_define

begin_define
define|#
directive|define
name|_OSF1_PC_NO_TRUNC
value|15
end_define

begin_define
define|#
directive|define
name|_OSF1_PC_PATH_MAX
value|16
end_define

begin_define
define|#
directive|define
name|_OSF1_PC_PIPE_BUF
value|17
end_define

begin_define
define|#
directive|define
name|_OSF1_PC_VDISABLE
value|18
end_define

begin_define
define|#
directive|define
name|OSF1_FNONBLOCK
value|0x00004
end_define

begin_comment
comment|/* XXX OSF1_O_NONBLOCK */
end_comment

begin_define
define|#
directive|define
name|OSF1_FAPPEND
value|0x00008
end_define

begin_comment
comment|/* XXX OSF1_O_APPEND */
end_comment

begin_define
define|#
directive|define
name|OSF1_FDEFER
value|0x00020
end_define

begin_define
define|#
directive|define
name|OSF1_FASYNC
value|0x00040
end_define

begin_define
define|#
directive|define
name|OSF1_FCREAT
value|0x00200
end_define

begin_define
define|#
directive|define
name|OSF1_FTRUNC
value|0x00400
end_define

begin_define
define|#
directive|define
name|OSF1_FEXCL
value|0x00800
end_define

begin_define
define|#
directive|define
name|OSF1_FSYNC
value|0x04000
end_define

begin_comment
comment|/* XXX OSF1_O_SYNC */
end_comment

begin_define
define|#
directive|define
name|OSF1_FNDELAY
value|0x08000
end_define

begin_define
define|#
directive|define
name|OSF1_RB_ASKNAME
value|0x001
end_define

begin_define
define|#
directive|define
name|OSF1_RB_SINGLE
value|0x002
end_define

begin_define
define|#
directive|define
name|OSF1_RB_NOSYNC
value|0x004
end_define

begin_define
define|#
directive|define
name|OSF1_RB_HALT
value|0x008
end_define

begin_define
define|#
directive|define
name|OSF1_RB_INITNAME
value|0x010
end_define

begin_define
define|#
directive|define
name|OSF1_RB_DFLTROOT
value|0x020
end_define

begin_define
define|#
directive|define
name|OSF1_RB_ALTBOOT
value|0x040
end_define

begin_define
define|#
directive|define
name|OSF1_RB_UNIPROC
value|0x080
end_define

begin_define
define|#
directive|define
name|OSF1_RB_ALLFLAGS
value|0x0ff
end_define

begin_comment
comment|/* all of the above */
end_comment

begin_comment
comment|/*  * osf/1 uses ints in its struct timeval, this means that  * any syscalls which means that any system calls using   * timevals need to be intercepted.  */
end_comment

begin_struct
struct|struct
name|osf1_timeval
block|{
name|int
name|tv_sec
decl_stmt|;
comment|/* seconds */
name|int
name|tv_usec
decl_stmt|;
comment|/* microseconds */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|osf1_itimerval
block|{
name|struct
name|osf1_timeval
name|it_interval
decl_stmt|;
comment|/* timer interval */
name|struct
name|osf1_timeval
name|it_value
decl_stmt|;
comment|/* current value */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TV_CP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|{dst.tv_usec = src.tv_usec; dst.tv_sec = src.tv_sec;}
end_define

begin_define
define|#
directive|define
name|timersub
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|vvp
parameter_list|)
define|\
value|do {								\ 		(vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;		\ 		(vvp)->tv_usec = (tvp)->tv_usec - (uvp)->tv_usec;	\ 		if ((vvp)->tv_usec< 0) {				\ 			(vvp)->tv_sec--;				\ 			(vvp)->tv_usec += 1000000;			\ 		}							\ 	} while (0)
end_define

begin_struct
struct|struct
name|osf1_rusage
block|{
name|struct
name|osf1_timeval
name|ru_utime
decl_stmt|;
comment|/* user time used */
name|struct
name|osf1_timeval
name|ru_stime
decl_stmt|;
comment|/* system time used */
name|long
name|ru_maxrss
decl_stmt|;
comment|/* max resident set size */
define|#
directive|define
name|ru_first
value|ru_ixrss
name|long
name|ru_ixrss
decl_stmt|;
comment|/* integral shared memory size */
name|long
name|ru_idrss
decl_stmt|;
comment|/* integral unshared data " */
name|long
name|ru_isrss
decl_stmt|;
comment|/* integral unshared stack " */
name|long
name|ru_minflt
decl_stmt|;
comment|/* page reclaims */
name|long
name|ru_majflt
decl_stmt|;
comment|/* page faults */
name|long
name|ru_nswap
decl_stmt|;
comment|/* swaps */
name|long
name|ru_inblock
decl_stmt|;
comment|/* block input operations */
name|long
name|ru_oublock
decl_stmt|;
comment|/* block output operations */
name|long
name|ru_msgsnd
decl_stmt|;
comment|/* messages sent */
name|long
name|ru_msgrcv
decl_stmt|;
comment|/* messages received */
name|long
name|ru_nsignals
decl_stmt|;
comment|/* signals received */
name|long
name|ru_nvcsw
decl_stmt|;
comment|/* voluntary context switches */
name|long
name|ru_nivcsw
decl_stmt|;
comment|/* involuntary " */
define|#
directive|define
name|ru_last
value|ru_nivcsw
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OSF1_USC_GET
value|1
end_define

begin_define
define|#
directive|define
name|OSF1_USC_SET
value|2
end_define

begin_define
define|#
directive|define
name|OSF1_USW_NULLP
value|0x100
end_define

begin_comment
comment|/* File system type numbers. */
end_comment

begin_define
define|#
directive|define
name|OSF1_MOUNT_NONE
value|0
end_define

begin_define
define|#
directive|define
name|OSF1_MOUNT_UFS
value|1
end_define

begin_define
define|#
directive|define
name|OSF1_MOUNT_NFS
value|2
end_define

begin_define
define|#
directive|define
name|OSF1_MOUNT_MFS
value|3
end_define

begin_define
define|#
directive|define
name|OSF1_MOUNT_PC
value|4
end_define

begin_define
define|#
directive|define
name|OSF1_MOUNT_S5FS
value|5
end_define

begin_define
define|#
directive|define
name|OSF1_MOUNT_CDFS
value|6
end_define

begin_define
define|#
directive|define
name|OSF1_MOUNT_DFS
value|7
end_define

begin_define
define|#
directive|define
name|OSF1_MOUNT_EFS
value|8
end_define

begin_define
define|#
directive|define
name|OSF1_MOUNT_PROCFS
value|9
end_define

begin_define
define|#
directive|define
name|OSF1_MOUNT_MSFS
value|10
end_define

begin_define
define|#
directive|define
name|OSF1_MOUNT_FFM
value|11
end_define

begin_define
define|#
directive|define
name|OSF1_MOUNT_FDFS
value|12
end_define

begin_define
define|#
directive|define
name|OSF1_MOUNT_ADDON
value|13
end_define

begin_define
define|#
directive|define
name|OSF1_MOUNT_MAXTYPE
value|OSF1_MOUNT_ADDON
end_define

begin_define
define|#
directive|define
name|OSF1_MNT_WAIT
value|0x1
end_define

begin_define
define|#
directive|define
name|OSF1_MNT_NOWAIT
value|0x2
end_define

begin_define
define|#
directive|define
name|OSF1_MNT_FORCE
value|0x1
end_define

begin_define
define|#
directive|define
name|OSF1_MNT_NOFORCE
value|0x2
end_define

begin_comment
comment|/* acceptable flags for various calls */
end_comment

begin_define
define|#
directive|define
name|OSF1_GETFSSTAT_FLAGS
value|(OSF1_MNT_WAIT|OSF1_MNT_NOWAIT)
end_define

begin_define
define|#
directive|define
name|OSF1_MOUNT_FLAGS
value|0xffffffff
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|OSF1_UNMOUNT_FLAGS
value|(OSF1_MNT_FORCE|OSF1_MNT_NOFORCE)
end_define

begin_struct
struct|struct
name|osf1_statfs
block|{
name|int16_t
name|f_type
decl_stmt|;
comment|/*   0 */
name|int16_t
name|f_flags
decl_stmt|;
comment|/*   2 */
name|int32_t
name|f_fsize
decl_stmt|;
comment|/*   4 */
name|int32_t
name|f_bsize
decl_stmt|;
comment|/*   8 */
name|int32_t
name|f_blocks
decl_stmt|;
comment|/*  12 */
name|int32_t
name|f_bfree
decl_stmt|;
comment|/*  16 */
name|int32_t
name|f_bavail
decl_stmt|;
comment|/*  20 */
name|int32_t
name|f_files
decl_stmt|;
comment|/*  24 */
name|int32_t
name|f_ffree
decl_stmt|;
comment|/*  28 */
name|int64_t
name|f_fsid
decl_stmt|;
comment|/*  32 */
name|int32_t
name|f_spare
index|[
literal|9
index|]
decl_stmt|;
comment|/*  40 (36 bytes) */
name|char
name|f_mntonname
index|[
literal|90
index|]
decl_stmt|;
comment|/*  76 (90 bytes) */
name|char
name|f_mntfromname
index|[
literal|90
index|]
decl_stmt|;
comment|/* 166 (90 bytes) */
name|char
name|f_xxx
index|[
literal|80
index|]
decl_stmt|;
comment|/* 256 (80 bytes) XXX */
block|}
struct|;
end_struct

begin_comment
comment|/* Arguments to mount() for various FS types. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_comment
comment|/* XXX */
end_comment

begin_struct
struct|struct
name|osf1_ufs_args
block|{
name|char
modifier|*
name|fspec
decl_stmt|;
name|int32_t
name|exflags
decl_stmt|;
name|u_int32_t
name|exroot
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|osf1_cdfs_args
block|{
name|char
modifier|*
name|fspec
decl_stmt|;
name|int32_t
name|exflags
decl_stmt|;
name|u_int32_t
name|exroot
decl_stmt|;
name|int32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|osf1_mfs_args
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|caddr_t
name|base
decl_stmt|;
name|u_int
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|osf1_nfs_args
block|{
name|struct
name|sockaddr_in
modifier|*
name|addr
decl_stmt|;
name|void
modifier|*
name|fh
decl_stmt|;
name|int32_t
name|flags
decl_stmt|;
name|int32_t
name|wsize
decl_stmt|;
name|int32_t
name|rsize
decl_stmt|;
name|int32_t
name|timeo
decl_stmt|;
name|int32_t
name|retrans
decl_stmt|;
name|char
modifier|*
name|hostname
decl_stmt|;
name|int32_t
name|acregmin
decl_stmt|;
name|int32_t
name|acregmax
decl_stmt|;
name|int32_t
name|acdirmin
decl_stmt|;
name|int32_t
name|acdirmax
decl_stmt|;
name|char
modifier|*
name|netname
decl_stmt|;
name|void
modifier|*
name|pathconf
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OSF1_NFSMNT_SOFT
value|0x00001
end_define

begin_define
define|#
directive|define
name|OSF1_NFSMNT_WSIZE
value|0x00002
end_define

begin_define
define|#
directive|define
name|OSF1_NFSMNT_RSIZE
value|0x00004
end_define

begin_define
define|#
directive|define
name|OSF1_NFSMNT_TIMEO
value|0x00008
end_define

begin_define
define|#
directive|define
name|OSF1_NFSMNT_RETRANS
value|0x00010
end_define

begin_define
define|#
directive|define
name|OSF1_NFSMNT_HOSTNAME
value|0x00020
end_define

begin_define
define|#
directive|define
name|OSF1_NFSMNT_INT
value|0x00040
end_define

begin_define
define|#
directive|define
name|OSF1_NFSMNT_NOCONN
value|0x00080
end_define

begin_define
define|#
directive|define
name|OSF1_NFSMNT_NOAC
value|0x00100
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|OSF1_NFSMNT_ACREGMIN
value|0x00200
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|OSF1_NFSMNT_ACREGMAX
value|0x00400
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|OSF1_NFSMNT_ACDIRMIN
value|0x00800
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|OSF1_NFSMNT_ACDIRMAX
value|0x01000
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|OSF1_NFSMNT_NOCTO
value|0x02000
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|OSF1_NFSMNT_POSIX
value|0x04000
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|OSF1_NFSMNT_AUTO
value|0x08000
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|OSF1_NFSMNT_FLAGS
define|\
value|(OSF1_NFSMNT_SOFT|OSF1_NFSMNT_WSIZE|OSF1_NFSMNT_RSIZE|		\ 	OSF1_NFSMNT_TIMEO|OSF1_NFSMNT_RETRANS|OSF1_NFSMNT_HOSTNAME|	\ 	OSF1_NFSMNT_INT|OSF1_NFSMNT_NOCONN)
end_define

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|bzero((x),(z))
end_define

end_unit

