begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Mike Karels at Berkeley Software Design, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)sysctl.h	8.1 (Berkeley) 6/2/93  * $Id: sysctl.h,v 1.57 1997/09/07 16:53:52 bde Exp $  */
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
name|CTLTYPE
value|0xf
end_define

begin_comment
comment|/* Mask for the type */
end_comment

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
name|CTLTYPE_OPAQUE
value|5
end_define

begin_comment
comment|/* name describes a structure */
end_comment

begin_define
define|#
directive|define
name|CTLTYPE_STRUCT
value|CTLTYPE_OPAQUE
end_define

begin_comment
comment|/* name describes a structure */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_RD
value|0x80000000
end_define

begin_comment
comment|/* Allow reads of variable */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_WR
value|0x40000000
end_define

begin_comment
comment|/* Allow writes to the variable */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_RW
value|(CTLFLAG_RD|CTLFLAG_WR)
end_define

begin_define
define|#
directive|define
name|CTLFLAG_NOLOCK
value|0x20000000
end_define

begin_comment
comment|/* XXX Don't Lock */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_ANYBODY
value|0x10000000
end_define

begin_comment
comment|/* All users can set this var */
end_comment

begin_comment
comment|/*  * USE THIS instead of a hardwired number from the categories below  * to get dynamically assigned sysctl entries using the linker-set  * technology. This is the way nearly all new sysctl variables should  * be implimented.  * e.g. SYSCTL_INT(_parent, OID_AUTO, name, CTLFLAG_RW,&variable, 0, "");  */
end_comment

begin_define
define|#
directive|define
name|OID_AUTO
value|(-1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|SYSCTL_HANDLER_ARGS
value|(struct sysctl_oid *oidp, void *arg1, int arg2, \ 	struct sysctl_req *req)
end_define

begin_comment
comment|/*  * This describes the access space for a sysctl request.  This is needed  * so that we can use the interface from the kernel or from user-space.  */
end_comment

begin_struct
struct|struct
name|sysctl_req
block|{
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
name|int
name|lock
decl_stmt|;
name|void
modifier|*
name|oldptr
decl_stmt|;
name|int
name|oldlen
decl_stmt|;
name|int
name|oldidx
decl_stmt|;
name|int
function_decl|(
modifier|*
name|oldfunc
function_decl|)
parameter_list|(
name|struct
name|sysctl_req
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
modifier|*
name|newptr
decl_stmt|;
name|int
name|newlen
decl_stmt|;
name|int
name|newidx
decl_stmt|;
name|int
function_decl|(
modifier|*
name|newfunc
function_decl|)
parameter_list|(
name|struct
name|sysctl_req
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This describes one "oid" in the MIB tree.  Potentially more nodes can  * be hidden behind it, expanded by the handler.  */
end_comment

begin_struct
struct|struct
name|sysctl_oid
block|{
name|int
name|oid_number
decl_stmt|;
name|int
name|oid_kind
decl_stmt|;
name|void
modifier|*
name|oid_arg1
decl_stmt|;
name|int
name|oid_arg2
decl_stmt|;
specifier|const
name|char
modifier|*
name|oid_name
decl_stmt|;
name|int
argument_list|(
argument|*oid_handler
argument_list|)
name|SYSCTL_HANDLER_ARGS
expr_stmt|;
specifier|const
name|char
modifier|*
name|oid_fmt
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SYSCTL_IN
parameter_list|(
name|r
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|)
value|(r->newfunc)(r, p, l)
end_define

begin_define
define|#
directive|define
name|SYSCTL_OUT
parameter_list|(
name|r
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|)
value|(r->oldfunc)(r, p, l)
end_define

begin_decl_stmt
name|int
name|sysctl_handle_int
name|SYSCTL_HANDLER_ARGS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sysctl_handle_string
name|SYSCTL_HANDLER_ARGS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sysctl_handle_opaque
name|SYSCTL_HANDLER_ARGS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is the "raw" function for a mib-oid */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_OID
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|kind
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|handler
parameter_list|,
name|fmt
parameter_list|,
name|descr
parameter_list|)
define|\
value|static const struct sysctl_oid sysctl__##parent##_##name = { \ 		nbr, kind, a1, a2, #name, handler, fmt }; \ 	TEXT_SET(sysctl_##parent, sysctl__##parent##_##name)
end_define

begin_comment
comment|/* This makes a node from which other oids can hang */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_NODE
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|handler
parameter_list|,
name|descr
parameter_list|)
define|\
value|extern struct linker_set sysctl_##parent##_##name; \ 	SYSCTL_OID(parent, nbr, name, CTLTYPE_NODE|access, \ 		(void*)&sysctl_##parent##_##name, 0, handler, "N", descr); \ 	TEXT_SET(sysctl_##parent##_##name, sysctl__##parent##_##name)
end_define

begin_comment
comment|/* This is a string len can be 0 to indicate '\0' termination */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_STRING
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|arg
parameter_list|,
name|len
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name, CTLTYPE_STRING|access, \ 		arg, len, sysctl_handle_string, "A", descr)
end_define

begin_comment
comment|/* This is a integer, if ptr is NULL, val is returned */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_INT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name, CTLTYPE_INT|access, \ 		ptr, val, sysctl_handle_int, "I", descr)
end_define

begin_comment
comment|/* This is anything, specified by a pointer and a lenth */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_OPAQUE
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|len
parameter_list|,
name|fmt
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name, CTLTYPE_OPAQUE|access, \ 		ptr, len, sysctl_handle_opaque, fmt, descr)
end_define

begin_comment
comment|/* This is a struct, specified by a pointer and type */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_STRUCT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|type
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name, CTLTYPE_OPAQUE|access, \ 		ptr, sizeof(struct type), sysctl_handle_opaque, \ 		"S," #type, descr)
end_define

begin_comment
comment|/* Needs a proc.  Specify by pointer and arg */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_PROC
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|arg
parameter_list|,
name|handler
parameter_list|,
name|fmt
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name, access, \ 		ptr, arg, handler, fmt, descr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
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
name|CTL_VFS
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

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX4
end_ifdef

begin_define
define|#
directive|define
name|CTL_POSIX4
value|9
end_define

begin_comment
comment|/* user-level */
end_comment

begin_define
define|#
directive|define
name|CTL_MAXID
value|10
end_define

begin_comment
comment|/* number of valid top-level ids */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_NAME
value|{ "posix4", CTLTYPE_NODE },
end_define

begin_else
else|#
directive|else
end_else

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
name|CTL_POSIX4_NAME
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX4 */
end_comment

begin_define
define|#
directive|define
name|CTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "kern", CTLTYPE_NODE }, \ 	{ "vm", CTLTYPE_NODE }, \ 	{ "vfs", CTLTYPE_NODE }, \ 	{ "net", CTLTYPE_NODE }, \ 	{ "debug", CTLTYPE_NODE }, \ 	{ "hw", CTLTYPE_NODE }, \ 	{ "machdep", CTLTYPE_NODE }, \ 	{ "user", CTLTYPE_NODE }, \ 	CTL_POSIX4_NAME \ }
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
name|KERN_NISDOMAINNAME
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
name|KERN_IPC
value|30
end_define

begin_comment
comment|/* node: anything related to IPC */
end_comment

begin_define
define|#
directive|define
name|KERN_DUMMY
value|31
end_define

begin_comment
comment|/* unused */
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
name|KERN_MAXID
value|34
end_define

begin_comment
comment|/* number of valid kern ids */
end_comment

begin_define
define|#
directive|define
name|CTL_KERN_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "ostype", CTLTYPE_STRING }, \ 	{ "osrelease", CTLTYPE_STRING }, \ 	{ "osrevision", CTLTYPE_INT }, \ 	{ "version", CTLTYPE_STRING }, \ 	{ "maxvnodes", CTLTYPE_INT }, \ 	{ "maxproc", CTLTYPE_INT }, \ 	{ "maxfiles", CTLTYPE_INT }, \ 	{ "argmax", CTLTYPE_INT }, \ 	{ "securelevel", CTLTYPE_INT }, \ 	{ "hostname", CTLTYPE_STRING }, \ 	{ "hostid", CTLTYPE_INT }, \ 	{ "clockrate", CTLTYPE_STRUCT }, \ 	{ "vnode", CTLTYPE_STRUCT }, \ 	{ "proc", CTLTYPE_STRUCT }, \ 	{ "file", CTLTYPE_STRUCT }, \ 	{ "profiling", CTLTYPE_NODE }, \ 	{ "posix1version", CTLTYPE_INT }, \ 	{ "ngroups", CTLTYPE_INT }, \ 	{ "job_control", CTLTYPE_INT }, \ 	{ "saved_ids", CTLTYPE_INT }, \ 	{ "boottime", CTLTYPE_STRUCT }, \ 	{ "nisdomainname", CTLTYPE_STRING }, \ 	{ "update", CTLTYPE_INT }, \ 	{ "osreldate", CTLTYPE_INT }, \         { "ntp_pll", CTLTYPE_NODE }, \ 	{ "bootfile", CTLTYPE_STRING }, \ 	{ "maxfilesperproc", CTLTYPE_INT }, \ 	{ "maxprocperuid", CTLTYPE_INT }, \ 	{ "dumpdev", CTLTYPE_STRUCT },
comment|/* we lie; don't print as int */
value|\ 	{ "ipc", CTLTYPE_NODE }, \ 	{ "dummy", CTLTYPE_INT }, \ 	{ "ps_strings", CTLTYPE_INT }, \ 	{ "usrstack", CTLTYPE_INT }, \ }
end_define

begin_comment
comment|/*  * CTL_VFS identifiers  */
end_comment

begin_define
define|#
directive|define
name|CTL_VFS_NAMES
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
comment|/*  * KERN_IPC identifiers  */
end_comment

begin_define
define|#
directive|define
name|KIPC_MAXSOCKBUF
value|1
end_define

begin_comment
comment|/* int: max size of a socket buffer */
end_comment

begin_define
define|#
directive|define
name|KIPC_SOCKBUF_WASTE
value|2
end_define

begin_comment
comment|/* int: wastage factor in sockbuf */
end_comment

begin_define
define|#
directive|define
name|KIPC_SOMAXCONN
value|3
end_define

begin_comment
comment|/* int: max length of connection q */
end_comment

begin_define
define|#
directive|define
name|KIPC_MAX_LINKHDR
value|4
end_define

begin_comment
comment|/* int: max length of link header */
end_comment

begin_define
define|#
directive|define
name|KIPC_MAX_PROTOHDR
value|5
end_define

begin_comment
comment|/* int: max length of network header */
end_comment

begin_define
define|#
directive|define
name|KIPC_MAX_HDR
value|6
end_define

begin_comment
comment|/* int: max total length of headers */
end_comment

begin_define
define|#
directive|define
name|KIPC_MAX_DATALEN
value|7
end_define

begin_comment
comment|/* int: max length of data? */
end_comment

begin_define
define|#
directive|define
name|KIPC_MBSTAT
value|8
end_define

begin_comment
comment|/* struct: mbuf usage statistics */
end_comment

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
name|HW_MACHINE_ARCH
value|11
end_define

begin_comment
comment|/* string: machine architecture */
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
value|{ \ 	{ 0, 0 }, \ 	{ "machine", CTLTYPE_STRING }, \ 	{ "model", CTLTYPE_STRING }, \ 	{ "ncpu", CTLTYPE_INT }, \ 	{ "byteorder", CTLTYPE_INT }, \ 	{ "physmem", CTLTYPE_INT }, \ 	{ "usermem", CTLTYPE_INT }, \ 	{ "pagesize", CTLTYPE_INT }, \ 	{ "disknames", CTLTYPE_STRUCT }, \ 	{ "diskstats", CTLTYPE_STRUCT }, \ 	{ "floatingpoint", CTLTYPE_INT }, \ }
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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

begin_function_decl
name|int
name|kernel_sysctl
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
modifier|*
name|name
parameter_list|,
name|u_int
name|namelen
parameter_list|,
name|void
modifier|*
name|old
parameter_list|,
name|size_t
modifier|*
name|oldlenp
parameter_list|,
name|void
modifier|*
name|new
parameter_list|,
name|size_t
name|newlen
parameter_list|,
name|int
modifier|*
name|retval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|userland_sysctl
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
modifier|*
name|name
parameter_list|,
name|u_int
name|namelen
parameter_list|,
name|void
modifier|*
name|old
parameter_list|,
name|size_t
modifier|*
name|oldlenp
parameter_list|,
name|int
name|inkernel
parameter_list|,
name|void
modifier|*
name|new
parameter_list|,
name|size_t
name|newlen
parameter_list|,
name|int
modifier|*
name|retval
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* int	sysctl_clockrate __P((char *, size_t*)); int	sysctl_file __P((char *, size_t*)); int	sysctl_doproc __P((int *, u_int, char *, size_t*)); int	sysctl_doprof __P((int *, u_int, void *, size_t *, void *, size_t)); */
end_comment

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

begin_decl_stmt
name|int
name|sysctlbyname
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
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

