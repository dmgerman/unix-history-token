begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Mike Karels at Berkeley Software Design, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)sysctl.h	7.17 (Berkeley) %G%  */
end_comment

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
comment|/*  * Each subsystem defined by sysctl defines a list of variables  * for that subsystem. Each name is either a node with further   * levels defined below it, or it is a leaf of some particular  * type given below. Each sysctl level defines a set of name/type  * pairs to be used by sysctl(1) in manipulating the subsystem.  */
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
name|CTL_MAXID
value|8
end_define

begin_comment
comment|/* number of valid top-level ids */
end_comment

begin_define
define|#
directive|define
name|CTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "kern", CTLTYPE_NODE }, \ 	{ "vm", CTLTYPE_NODE }, \ 	{ "fs", CTLTYPE_NODE }, \ 	{ "net", CTLTYPE_NODE }, \ 	{ "debug", CTLTYPE_NODE }, \ 	{ "hw", CTLTYPE_NODE }, \ 	{ "machdep", CTLTYPE_NODE }, \ }
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
name|KERN_POSIX1
value|5
end_define

begin_comment
comment|/* int: POSIX.1 version */
end_comment

begin_define
define|#
directive|define
name|KERN_MAXPROC
value|6
end_define

begin_comment
comment|/* int: max simultaneous processes */
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
comment|/* struct clockrate */
end_comment

begin_define
define|#
directive|define
name|KERN_VNODE
value|13
end_define

begin_comment
comment|/* vnode structures */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC
value|14
end_define

begin_comment
comment|/* process entries */
end_comment

begin_define
define|#
directive|define
name|KERN_FILE
value|15
end_define

begin_comment
comment|/* file entries */
end_comment

begin_define
define|#
directive|define
name|KERN_MAXID
value|16
end_define

begin_comment
comment|/* number of valid kern ids */
end_comment

begin_define
define|#
directive|define
name|CTL_KERN_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "ostype", CTLTYPE_STRING }, \ 	{ "osrelease", CTLTYPE_STRING }, \ 	{ "osrevision", CTLTYPE_INT }, \ 	{ "version", CTLTYPE_STRING }, \ 	{ "posix1version", CTLTYPE_INT }, \ 	{ "maxproc", CTLTYPE_INT }, \ 	{ "maxfiles", CTLTYPE_INT }, \ 	{ "argmax", CTLTYPE_INT }, \ 	{ "securelevel", CTLTYPE_INT }, \ 	{ "hostname", CTLTYPE_STRING }, \ 	{ "hostid", CTLTYPE_INT }, \ 	{ "clockrate", CTLTYPE_STRUCT }, \ 	{ "vnode", CTLTYPE_STRUCT }, \ 	{ "proc", CTLTYPE_STRUCT }, \ 	{ "file", CTLTYPE_STRUCT }, \ }
end_define

begin_comment
comment|/*   * KERN_PROC subtypes  */
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
name|HW_CPUSPEED
value|4
end_define

begin_comment
comment|/* int: relative cpuspeed */
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
comment|/* diskstats[] */
end_comment

begin_define
define|#
directive|define
name|HW_MAXID
value|10
end_define

begin_comment
comment|/* number of valid hw ids */
end_comment

begin_define
define|#
directive|define
name|CTL_HW_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "machine", CTLTYPE_STRING }, \ 	{ "model", CTLTYPE_STRING }, \ 	{ "ncpu", CTLTYPE_INT }, \ 	{ "cpuspeed", CTLTYPE_INT }, \ 	{ "physmem", CTLTYPE_INT }, \ 	{ "usermem", CTLTYPE_INT }, \ 	{ "pagesize", CTLTYPE_INT }, \ 	{ "disknames", CTLTYPE_STRUCT }, \ 	{ "diskstats", CTLTYPE_STRUCT }, \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Internal sysctl function calling convention:  *  *	(*sysctlfn)(name, namelen, oldval, oldlenp, newval, newlen);  *  * The name parameter points at the next component of the name to be  * interpreted.  The namelen parameter is the number of integers in  * the name.  */
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

end_unit

