begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Mike Karels at Berkeley Software Design, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)sysctl.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SYSCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SYSCTL_H_
end_define

begin_comment
comment|/*  * These are for the eproc structure defined below.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Definitions for sysctl call.  The sysctl call uses a hierarchical name  * for objects that can be examined or modified.  The name is expressed as  * a sequence of integers.  Like a file path name, the meaning of each  * component depends on its place in the hierarchy.  The top-level and kern  * identifiers are defined here, and other identifiers are defined in the  * respective subsystem header files.  */
end_comment

begin_define
define|#
directive|define
name|CTL_MAXNAME
value|12
end_define

begin_comment
comment|/* largest number of components supported */
end_comment

begin_comment
comment|/*  * Each subsystem defined by sysctl defines a list of variables  * for that subsystem. Each name is either a node with further  * levels defined below it, or it is a leaf of some particular  * type given below. Each sysctl level defines a set of name/type  * pairs to be used by sysctl(1) in manipulating the subsystem.  */
end_comment

begin_struct
struct|struct
name|ctlname
block|{
name|char
modifier|*
name|ctl_name
decl_stmt|;
comment|/* subsystem name */
name|int
name|ctl_type
decl_stmt|;
comment|/* type of name */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CTLTYPE_NODE
value|1
end_define

begin_comment
comment|/* name is a node */
end_comment

begin_define
define|#
directive|define
name|CTLTYPE_INT
value|2
end_define

begin_comment
comment|/* name describes an integer */
end_comment

begin_define
define|#
directive|define
name|CTLTYPE_STRING
value|3
end_define

begin_comment
comment|/* name describes a string */
end_comment

begin_define
define|#
directive|define
name|CTLTYPE_QUAD
value|4
end_define

begin_comment
comment|/* name describes a 64-bit number */
end_comment

begin_define
define|#
directive|define
name|CTLTYPE_STRUCT
value|5
end_define

begin_comment
comment|/* name describes a structure */
end_comment

begin_comment
comment|/*  * Top-level identifiers  */
end_comment

begin_define
define|#
directive|define
name|CTL_UNSPEC
value|0
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|CTL_KERN
value|1
end_define

begin_comment
comment|/* "high kernel": proc, limits */
end_comment

begin_define
define|#
directive|define
name|CTL_VM
value|2
end_define

begin_comment
comment|/* virtual memory */
end_comment

begin_define
define|#
directive|define
name|CTL_FS
value|3
end_define

begin_comment
comment|/* file system, mount type is next */
end_comment

begin_define
define|#
directive|define
name|CTL_NET
value|4
end_define

begin_comment
comment|/* network, see socket.h */
end_comment

begin_define
define|#
directive|define
name|CTL_DEBUG
value|5
end_define

begin_comment
comment|/* debugging parameters */
end_comment

begin_define
define|#
directive|define
name|CTL_HW
value|6
end_define

begin_comment
comment|/* generic cpu/io */
end_comment

begin_define
define|#
directive|define
name|CTL_MACHDEP
value|7
end_define

begin_comment
comment|/* machine dependent */
end_comment

begin_define
define|#
directive|define
name|CTL_USER
value|8
end_define

begin_comment
comment|/* user-level */
end_comment

begin_define
define|#
directive|define
name|CTL_MAXID
value|9
end_define

begin_comment
comment|/* number of valid top-level ids */
end_comment

begin_define
define|#
directive|define
name|CTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "kern", CTLTYPE_NODE }, \ 	{ "vm", CTLTYPE_NODE }, \ 	{ "fs", CTLTYPE_NODE }, \ 	{ "net", CTLTYPE_NODE }, \ 	{ "debug", CTLTYPE_NODE }, \ 	{ "hw", CTLTYPE_NODE }, \ 	{ "machdep", CTLTYPE_NODE }, \ 	{ "user", CTLTYPE_NODE }, \ }
end_define

begin_comment
comment|/*  * CTL_KERN identifiers  */
end_comment

begin_define
define|#
directive|define
name|KERN_OSTYPE
value|1
end_define

begin_comment
comment|/* string: system version */
end_comment

begin_define
define|#
directive|define
name|KERN_OSRELEASE
value|2
end_define

begin_comment
comment|/* string: system release */
end_comment

begin_define
define|#
directive|define
name|KERN_OSREV
value|3
end_define

begin_comment
comment|/* int: system revision */
end_comment

begin_define
define|#
directive|define
name|KERN_VERSION
value|4
end_define

begin_comment
comment|/* string: compile time info */
end_comment

begin_define
define|#
directive|define
name|KERN_MAXVNODES
value|5
end_define

begin_comment
comment|/* int: max vnodes */
end_comment

begin_define
define|#
directive|define
name|KERN_MAXPROC
value|6
end_define

begin_comment
comment|/* int: max processes */
end_comment

begin_define
define|#
directive|define
name|KERN_MAXFILES
value|7
end_define

begin_comment
comment|/* int: max open files */
end_comment

begin_define
define|#
directive|define
name|KERN_ARGMAX
value|8
end_define

begin_comment
comment|/* int: max arguments to exec */
end_comment

begin_define
define|#
directive|define
name|KERN_SECURELVL
value|9
end_define

begin_comment
comment|/* int: system security level */
end_comment

begin_define
define|#
directive|define
name|KERN_HOSTNAME
value|10
end_define

begin_comment
comment|/* string: hostname */
end_comment

begin_define
define|#
directive|define
name|KERN_HOSTID
value|11
end_define

begin_comment
comment|/* int: host identifier */
end_comment

begin_define
define|#
directive|define
name|KERN_CLOCKRATE
value|12
end_define

begin_comment
comment|/* struct: struct clockrate */
end_comment

begin_define
define|#
directive|define
name|KERN_VNODE
value|13
end_define

begin_comment
comment|/* struct: vnode structures */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC
value|14
end_define

begin_comment
comment|/* struct: process entries */
end_comment

begin_define
define|#
directive|define
name|KERN_FILE
value|15
end_define

begin_comment
comment|/* struct: file entries */
end_comment

begin_define
define|#
directive|define
name|KERN_PROF
value|16
end_define

begin_comment
comment|/* node: kernel profiling info */
end_comment

begin_define
define|#
directive|define
name|KERN_POSIX1
value|17
end_define

begin_comment
comment|/* int: POSIX.1 version */
end_comment

begin_define
define|#
directive|define
name|KERN_NGROUPS
value|18
end_define

begin_comment
comment|/* int: # of supplemental group ids */
end_comment

begin_define
define|#
directive|define
name|KERN_JOB_CONTROL
value|19
end_define

begin_comment
comment|/* int: is job control available */
end_comment

begin_define
define|#
directive|define
name|KERN_SAVED_IDS
value|20
end_define

begin_comment
comment|/* int: saved set-user/group-ID */
end_comment

begin_define
define|#
directive|define
name|KERN_BOOTTIME
value|21
end_define

begin_comment
comment|/* struct: time kernel was booted */
end_comment

begin_define
define|#
directive|define
name|KERN_DOMAINNAME
value|22
end_define

begin_comment
comment|/* string: YP domain name */
end_comment

begin_define
define|#
directive|define
name|KERN_UPDATEINTERVAL
value|23
end_define

begin_comment
comment|/* int: update process sleep time */
end_comment

begin_define
define|#
directive|define
name|KERN_OSRELDATE
value|24
end_define

begin_comment
comment|/* int: OS release date */
end_comment

begin_define
define|#
directive|define
name|KERN_NTP_PLL
value|25
end_define

begin_comment
comment|/* node: NTP PLL control */
end_comment

begin_define
define|#
directive|define
name|KERN_BOOTFILE
value|26
end_define

begin_comment
comment|/* string: name of booted kernel */
end_comment

begin_define
define|#
directive|define
name|KERN_MAXFILESPERPROC
value|27
end_define

begin_comment
comment|/* int: max open files per proc */
end_comment

begin_define
define|#
directive|define
name|KERN_MAXPROCPERUID
value|28
end_define

begin_comment
comment|/* int: max processes per uid */
end_comment

begin_define
define|#
directive|define
name|KERN_DUMPDEV
value|29
end_define

begin_comment
comment|/* dev_t: device to dump on */
end_comment

begin_define
define|#
directive|define
name|KERN_SOMAXCONN
value|30
end_define

begin_comment
comment|/* int: max connections in listen q */
end_comment

begin_define
define|#
directive|define
name|KERN_MAXSOCKBUF
value|31
end_define

begin_comment
comment|/* int: max size of a socket buffer */
end_comment

begin_define
define|#
directive|define
name|KERN_PS_STRINGS
value|32
end_define

begin_comment
comment|/* int: address of PS_STRINGS */
end_comment

begin_define
define|#
directive|define
name|KERN_USRSTACK
value|33
end_define

begin_comment
comment|/* int: address of USRSTACK */
end_comment

begin_define
define|#
directive|define
name|KERN_SOCKBUF_WASTE
value|34
end_define

begin_comment
comment|/* int: reserved sockbuf space */
end_comment

begin_define
define|#
directive|define
name|KERN_SOMINQUEUE
value|35
end_define

begin_comment
comment|/* int: override socket listen() */
end_comment

begin_define
define|#
directive|define
name|KERN_MAXID
value|36
end_define

begin_comment
comment|/* number of valid kern ids */
end_comment

begin_define
define|#
directive|define
name|CTL_KERN_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "ostype", CTLTYPE_STRING }, \ 	{ "osrelease", CTLTYPE_STRING }, \ 	{ "osrevision", CTLTYPE_INT }, \ 	{ "version", CTLTYPE_STRING }, \ 	{ "maxvnodes", CTLTYPE_INT }, \ 	{ "maxproc", CTLTYPE_INT }, \ 	{ "maxfiles", CTLTYPE_INT }, \ 	{ "argmax", CTLTYPE_INT }, \ 	{ "securelevel", CTLTYPE_INT }, \ 	{ "hostname", CTLTYPE_STRING }, \ 	{ "hostid", CTLTYPE_INT }, \ 	{ "clockrate", CTLTYPE_STRUCT }, \ 	{ "vnode", CTLTYPE_STRUCT }, \ 	{ "proc", CTLTYPE_STRUCT }, \ 	{ "file", CTLTYPE_STRUCT }, \ 	{ "profiling", CTLTYPE_NODE }, \ 	{ "posix1version", CTLTYPE_INT }, \ 	{ "ngroups", CTLTYPE_INT }, \ 	{ "job_control", CTLTYPE_INT }, \ 	{ "saved_ids", CTLTYPE_INT }, \ 	{ "boottime", CTLTYPE_STRUCT }, \ 	{ "domainname", CTLTYPE_STRING }, \ 	{ "update", CTLTYPE_INT }, \ 	{ "osreldate", CTLTYPE_INT }, \         { "ntp_pll", CTLTYPE_NODE }, \ 	{ "bootfile", CTLTYPE_STRING }, \ 	{ "maxfilesperproc", CTLTYPE_INT }, \ 	{ "maxprocperuid", CTLTYPE_INT }, \ 	{ "dumpdev", CTLTYPE_STRUCT },
comment|/* we lie; don't print as int */
value|\ 	{ "somaxconn", CTLTYPE_INT }, \ 	{ "maxsockbuf", CTLTYPE_INT }, \ 	{ "ps_strings", CTLTYPE_INT }, \ 	{ "usrstack", CTLTYPE_INT }, \ 	{ "sockbuf_waste_factor", CTLTYPE_INT }, \ 	{ "sominqueue", CTLTYPE_INT }, \ }
end_define

begin_comment
comment|/*  * CTL_FS identifiers  */
end_comment

begin_define
define|#
directive|define
name|FS_VFSCONF
value|0
end_define

begin_comment
comment|/* get configured filesystems */
end_comment

begin_define
define|#
directive|define
name|FS_MAXID
value|1
end_define

begin_comment
comment|/* number of items */
end_comment

begin_define
define|#
directive|define
name|CTL_FS_NAMES
value|{ \ 	{ "vfsconf", CTLTYPE_STRUCT }, \ }
end_define

begin_comment
comment|/*  * KERN_PROC subtypes  */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_ALL
value|0
end_define

begin_comment
comment|/* everything */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_PID
value|1
end_define

begin_comment
comment|/* by process id */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_PGRP
value|2
end_define

begin_comment
comment|/* by process group id */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_SESSION
value|3
end_define

begin_comment
comment|/* by session of pid */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_TTY
value|4
end_define

begin_comment
comment|/* by controlling tty */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_UID
value|5
end_define

begin_comment
comment|/* by effective uid */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_RUID
value|6
end_define

begin_comment
comment|/* by real uid */
end_comment

begin_comment
comment|/*  * KERN_PROC subtype ops return arrays of augmented proc structures:  */
end_comment

begin_struct
struct|struct
name|kinfo_proc
block|{
name|struct
name|proc
name|kp_proc
decl_stmt|;
comment|/* proc structure */
struct|struct
name|eproc
block|{
name|struct
name|proc
modifier|*
name|e_paddr
decl_stmt|;
comment|/* address of proc */
name|struct
name|session
modifier|*
name|e_sess
decl_stmt|;
comment|/* session pointer */
name|struct
name|pcred
name|e_pcred
decl_stmt|;
comment|/* process credentials */
name|struct
name|ucred
name|e_ucred
decl_stmt|;
comment|/* current credentials */
ifdef|#
directive|ifdef
name|sparc
struct|struct
block|{
name|segsz_t
name|vm_rssize
decl_stmt|;
comment|/* resident set size */
name|segsz_t
name|vm_tsize
decl_stmt|;
comment|/* text size */
name|segsz_t
name|vm_dsize
decl_stmt|;
comment|/* data size */
name|segsz_t
name|vm_ssize
decl_stmt|;
comment|/* stack size */
block|}
name|e_vm
struct|;
else|#
directive|else
name|struct
name|vmspace
name|e_vm
decl_stmt|;
comment|/* address space */
endif|#
directive|endif
name|pid_t
name|e_ppid
decl_stmt|;
comment|/* parent process id */
name|pid_t
name|e_pgid
decl_stmt|;
comment|/* process group id */
name|short
name|e_jobc
decl_stmt|;
comment|/* job control counter */
name|dev_t
name|e_tdev
decl_stmt|;
comment|/* controlling tty dev */
name|pid_t
name|e_tpgid
decl_stmt|;
comment|/* tty process group id */
name|struct
name|session
modifier|*
name|e_tsess
decl_stmt|;
comment|/* tty session pointer */
define|#
directive|define
name|WMESGLEN
value|7
name|char
name|e_wmesg
index|[
name|WMESGLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* wchan message */
name|segsz_t
name|e_xsize
decl_stmt|;
comment|/* text size */
name|short
name|e_xrssize
decl_stmt|;
comment|/* text rss */
name|short
name|e_xccount
decl_stmt|;
comment|/* text references */
name|short
name|e_xswrss
decl_stmt|;
name|long
name|e_flag
decl_stmt|;
define|#
directive|define
name|EPROC_CTTY
value|0x01
comment|/* controlling tty vnode active */
define|#
directive|define
name|EPROC_SLEADER
value|0x02
comment|/* session leader */
name|char
name|e_login
index|[
name|MAXLOGNAME
index|]
decl_stmt|;
comment|/* setlogin() name */
name|long
name|e_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
name|kp_eproc
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * CTL_HW identifiers  */
end_comment

begin_define
define|#
directive|define
name|HW_MACHINE
value|1
end_define

begin_comment
comment|/* string: machine class */
end_comment

begin_define
define|#
directive|define
name|HW_MODEL
value|2
end_define

begin_comment
comment|/* string: specific machine model */
end_comment

begin_define
define|#
directive|define
name|HW_NCPU
value|3
end_define

begin_comment
comment|/* int: number of cpus */
end_comment

begin_define
define|#
directive|define
name|HW_BYTEORDER
value|4
end_define

begin_comment
comment|/* int: machine byte order */
end_comment

begin_define
define|#
directive|define
name|HW_PHYSMEM
value|5
end_define

begin_comment
comment|/* int: total memory */
end_comment

begin_define
define|#
directive|define
name|HW_USERMEM
value|6
end_define

begin_comment
comment|/* int: non-kernel memory */
end_comment

begin_define
define|#
directive|define
name|HW_PAGESIZE
value|7
end_define

begin_comment
comment|/* int: software page size */
end_comment

begin_define
define|#
directive|define
name|HW_DISKNAMES
value|8
end_define

begin_comment
comment|/* strings: disk drive names */
end_comment

begin_define
define|#
directive|define
name|HW_DISKSTATS
value|9
end_define

begin_comment
comment|/* struct: diskstats[] */
end_comment

begin_define
define|#
directive|define
name|HW_FLOATINGPT
value|10
end_define

begin_comment
comment|/* int: has HW floating point? */
end_comment

begin_define
define|#
directive|define
name|HW_DEVCONF
value|11
end_define

begin_comment
comment|/* node: device configuration */
end_comment

begin_define
define|#
directive|define
name|HW_MAXID
value|12
end_define

begin_comment
comment|/* number of valid hw ids */
end_comment

begin_define
define|#
directive|define
name|CTL_HW_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "machine", CTLTYPE_STRING }, \ 	{ "model", CTLTYPE_STRING }, \ 	{ "ncpu", CTLTYPE_INT }, \ 	{ "byteorder", CTLTYPE_INT }, \ 	{ "physmem", CTLTYPE_INT }, \ 	{ "usermem", CTLTYPE_INT }, \ 	{ "pagesize", CTLTYPE_INT }, \ 	{ "disknames", CTLTYPE_STRUCT }, \ 	{ "diskstats", CTLTYPE_STRUCT }, \ 	{ "floatingpoint", CTLTYPE_INT }, \ 	{ "devconf", CTLTYPE_NODE }, \ }
end_define

begin_comment
comment|/*  * CTL_USER definitions  */
end_comment

begin_define
define|#
directive|define
name|USER_CS_PATH
value|1
end_define

begin_comment
comment|/* string: _CS_PATH */
end_comment

begin_define
define|#
directive|define
name|USER_BC_BASE_MAX
value|2
end_define

begin_comment
comment|/* int: BC_BASE_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_BC_DIM_MAX
value|3
end_define

begin_comment
comment|/* int: BC_DIM_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_BC_SCALE_MAX
value|4
end_define

begin_comment
comment|/* int: BC_SCALE_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_BC_STRING_MAX
value|5
end_define

begin_comment
comment|/* int: BC_STRING_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_COLL_WEIGHTS_MAX
value|6
end_define

begin_comment
comment|/* int: COLL_WEIGHTS_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_EXPR_NEST_MAX
value|7
end_define

begin_comment
comment|/* int: EXPR_NEST_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_LINE_MAX
value|8
end_define

begin_comment
comment|/* int: LINE_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_RE_DUP_MAX
value|9
end_define

begin_comment
comment|/* int: RE_DUP_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_VERSION
value|10
end_define

begin_comment
comment|/* int: POSIX2_VERSION */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_C_BIND
value|11
end_define

begin_comment
comment|/* int: POSIX2_C_BIND */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_C_DEV
value|12
end_define

begin_comment
comment|/* int: POSIX2_C_DEV */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_CHAR_TERM
value|13
end_define

begin_comment
comment|/* int: POSIX2_CHAR_TERM */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_FORT_DEV
value|14
end_define

begin_comment
comment|/* int: POSIX2_FORT_DEV */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_FORT_RUN
value|15
end_define

begin_comment
comment|/* int: POSIX2_FORT_RUN */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_LOCALEDEF
value|16
end_define

begin_comment
comment|/* int: POSIX2_LOCALEDEF */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_SW_DEV
value|17
end_define

begin_comment
comment|/* int: POSIX2_SW_DEV */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_UPE
value|18
end_define

begin_comment
comment|/* int: POSIX2_UPE */
end_comment

begin_define
define|#
directive|define
name|USER_STREAM_MAX
value|19
end_define

begin_comment
comment|/* int: POSIX2_STREAM_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_TZNAME_MAX
value|20
end_define

begin_comment
comment|/* int: POSIX2_TZNAME_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_MAXID
value|21
end_define

begin_comment
comment|/* number of valid user ids */
end_comment

begin_define
define|#
directive|define
name|CTL_USER_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "cs_path", CTLTYPE_STRING }, \ 	{ "bc_base_max", CTLTYPE_INT }, \ 	{ "bc_dim_max", CTLTYPE_INT }, \ 	{ "bc_scale_max", CTLTYPE_INT }, \ 	{ "bc_string_max", CTLTYPE_INT }, \ 	{ "coll_weights_max", CTLTYPE_INT }, \ 	{ "expr_nest_max", CTLTYPE_INT }, \ 	{ "line_max", CTLTYPE_INT }, \ 	{ "re_dup_max", CTLTYPE_INT }, \ 	{ "posix2_version", CTLTYPE_INT }, \ 	{ "posix2_c_bind", CTLTYPE_INT }, \ 	{ "posix2_c_dev", CTLTYPE_INT }, \ 	{ "posix2_char_term", CTLTYPE_INT }, \ 	{ "posix2_fort_dev", CTLTYPE_INT }, \ 	{ "posix2_fort_run", CTLTYPE_INT }, \ 	{ "posix2_localedef", CTLTYPE_INT }, \ 	{ "posix2_sw_dev", CTLTYPE_INT }, \ 	{ "posix2_upe", CTLTYPE_INT }, \ 	{ "stream_max", CTLTYPE_INT }, \ 	{ "tzname_max", CTLTYPE_INT }, \ }
end_define

begin_comment
comment|/*  * CTL_DEBUG definitions  *  * Second level identifier specifies which debug variable.  * Third level identifier specifies which stucture component.  */
end_comment

begin_define
define|#
directive|define
name|CTL_DEBUG_NAME
value|0
end_define

begin_comment
comment|/* string: variable name */
end_comment

begin_define
define|#
directive|define
name|CTL_DEBUG_VALUE
value|1
end_define

begin_comment
comment|/* int: variable value */
end_comment

begin_define
define|#
directive|define
name|CTL_DEBUG_MAXID
value|20
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG
argument_list|)
operator|||
name|defined
argument_list|(
name|DIAGNOSTIC
argument_list|)
end_if

begin_comment
comment|/*  * CTL_DEBUG variables.  *  * These are declared as separate variables so that they can be  * individually initialized at the location of their associated  * variable. The loader prevents multiple use by issuing errors  * if a variable is initialized in more than one place. They are  * aggregated into an array in debug_sysctl(), so that it can  * conveniently locate them when querried. If more debugging  * variables are added, they must also be declared here and also  * entered into the array.  */
end_comment

begin_struct
struct|struct
name|ctldebug
block|{
name|char
modifier|*
name|debugname
decl_stmt|;
comment|/* name of debugging variable */
name|int
modifier|*
name|debugvar
decl_stmt|;
comment|/* pointer to debugging variable */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ctldebug
name|debug0
decl_stmt|,
name|debug1
decl_stmt|,
name|debug2
decl_stmt|,
name|debug3
decl_stmt|,
name|debug4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ctldebug
name|debug5
decl_stmt|,
name|debug6
decl_stmt|,
name|debug7
decl_stmt|,
name|debug8
decl_stmt|,
name|debug9
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ctldebug
name|debug10
decl_stmt|,
name|debug11
decl_stmt|,
name|debug12
decl_stmt|,
name|debug13
decl_stmt|,
name|debug14
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ctldebug
name|debug15
decl_stmt|,
name|debug16
decl_stmt|,
name|debug17
decl_stmt|,
name|debug18
decl_stmt|,
name|debug19
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|cpu_model
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hw_float
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|machine
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|osrelease
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ostype
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Internal sysctl function calling convention:  *  *	(*sysctlfn)(name, namelen, oldval, oldlenp, newval, newlen, p);  *  * The name parameter points at the next component of the name to be  * interpreted.  The namelen parameter is the number of integers in  * the name.  */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|sysctlfn
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|u_int
operator|,
name|void
operator|*
operator|,
name|size_t
operator|*
operator|,
name|void
operator|*
operator|,
name|size_t
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
name|sysctlfn
name|cpu_sysctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|sysctlfn
name|dev_sysctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|sysctlfn
name|fs_sysctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|sysctlfn
name|hw_sysctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|sysctlfn
name|kern_sysctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|sysctlfn
name|net_sysctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|sysctlfn
name|ntp_sysctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|sysctlfn
name|vm_sysctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sysctl_int
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|*
operator|,
name|void
operator|*
operator|,
name|size_t
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sysctl_rdint
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|*
operator|,
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sysctl_string
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|*
operator|,
name|void
operator|*
operator|,
name|size_t
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sysctl_rdstring
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|*
operator|,
name|void
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sysctl_rdstruct
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|*
operator|,
name|void
operator|*
operator|,
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sysctl_struct
name|__P
argument_list|(
operator|(
name|void
operator|*
name|oldp
operator|,
name|size_t
operator|*
operator|,
name|void
operator|*
operator|,
name|size_t
operator|,
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fill_eproc
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|eproc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sysctl_clockrate
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sysctl_vnode
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sysctl_file
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sysctl_doproc
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|u_int
operator|,
name|char
operator|*
operator|,
name|size_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sysctl_doprof
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|u_int
operator|,
name|void
operator|*
operator|,
name|size_t
operator|*
operator|,
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|sysctl
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|u_int
operator|,
name|void
operator|*
operator|,
name|size_t
operator|*
operator|,
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SYSCTL_H_ */
end_comment

end_unit

