begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry.  *  * %sccs.include.redist.c%  *  *	@(#)bsd_openprom.h	7.2 (Berkeley) %G%  *  * from: $Header: bsd_openprom.h,v 1.3 92/09/09 00:41:33 leres Exp $  */
end_comment

begin_comment
comment|/*  * This file defines the interface between the kernel and the Openboot PROM.  * N.B.: this has been tested only on interface versions 0 and 2 (we have  * never seen interface version 1).  */
end_comment

begin_comment
comment|/*  * The v0 interface tells us what virtual memory to scan to avoid PMEG  * conflicts, but the v2 interface fails to do so, and we must `magically'  * know where the OPENPROM lives in virtual space.  */
end_comment

begin_define
define|#
directive|define
name|OPENPROM_STARTVADDR
value|0xffd00000
end_define

begin_define
define|#
directive|define
name|OPENPROM_ENDVADDR
value|0xfff00000
end_define

begin_define
define|#
directive|define
name|OPENPROM_MAGIC
value|0x10010407
end_define

begin_comment
comment|/*  * Version 0 PROM vector device operations (collected here to emphasise that  * they are deprecated).  Open and close are obvious.  Read and write are  * segregated according to the device type (block, network, or character);  * this is unnecessary and was eliminated from the v2 device operations, but  * we are stuck with it.  *  * Seek is probably only useful on tape devices, since the only character  * devices are the serial ports.  *  * Note that a v0 device name is always exactly two characters ("sd", "le",  * and so forth).  */
end_comment

begin_struct
struct|struct
name|v0devops
block|{
name|int
function_decl|(
modifier|*
name|v0_open
function_decl|)
parameter_list|(
name|char
modifier|*
name|dev
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|v0_close
function_decl|)
parameter_list|(
name|int
name|d
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|v0_rbdev
function_decl|)
parameter_list|(
name|int
name|d
parameter_list|,
name|int
name|nblks
parameter_list|,
name|int
name|blkno
parameter_list|,
name|caddr_t
name|addr
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|v0_wbdev
function_decl|)
parameter_list|(
name|int
name|d
parameter_list|,
name|int
name|nblks
parameter_list|,
name|int
name|blkno
parameter_list|,
name|caddr_t
name|addr
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|v0_wnet
function_decl|)
parameter_list|(
name|int
name|d
parameter_list|,
name|int
name|nbytes
parameter_list|,
name|caddr_t
name|addr
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|v0_rnet
function_decl|)
parameter_list|(
name|int
name|d
parameter_list|,
name|int
name|nbytes
parameter_list|,
name|caddr_t
name|addr
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|v0_rcdev
function_decl|)
parameter_list|(
name|int
name|d
parameter_list|,
name|int
name|nbytes
parameter_list|,
name|int
parameter_list|,
name|caddr_t
name|addr
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|v0_wcdev
function_decl|)
parameter_list|(
name|int
name|d
parameter_list|,
name|int
name|nbytes
parameter_list|,
name|int
parameter_list|,
name|caddr_t
name|addr
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|v0_seek
function_decl|)
parameter_list|(
name|int
name|d
parameter_list|,
name|long
name|offset
parameter_list|,
name|int
name|whence
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Version 2 device operations.  Open takes a device `path' such as  * /sbus/le@0,c00000,0 or /sbus/esp@.../sd@0,0, which means it can open  * anything anywhere, without any magic translation.  *  * The memory allocator and map functions are included here even though  * they relate only indirectly to devices (e.g., mmap is good for mapping  * device memory, and drivers need to allocate space in which to record  * the device state).  */
end_comment

begin_struct
struct|struct
name|v2devops
block|{
name|int
function_decl|(
modifier|*
name|v2_xxx1
function_decl|)
parameter_list|(
name|int
name|d
parameter_list|)
function_decl|;
comment|/* ??? convert fd to something */
comment|/* Memory allocation and release. */
name|caddr_t
function_decl|(
modifier|*
name|v2_malloc
function_decl|)
parameter_list|(
name|caddr_t
name|va
parameter_list|,
name|u_int
name|sz
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|v2_free
function_decl|)
parameter_list|(
name|caddr_t
name|va
parameter_list|,
name|u_int
name|sz
parameter_list|)
function_decl|;
comment|/* Device memory mapper. */
name|caddr_t
function_decl|(
modifier|*
name|v2_mmap
function_decl|)
parameter_list|(
name|caddr_t
name|va
parameter_list|,
name|int
name|asi
parameter_list|,
name|u_int
name|pa
parameter_list|,
name|u_int
name|sz
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|v2_munmap
function_decl|)
parameter_list|(
name|caddr_t
name|va
parameter_list|,
name|u_int
name|sz
parameter_list|)
function_decl|;
comment|/* Device open, close, etc. */
name|int
function_decl|(
modifier|*
name|v2_open
function_decl|)
parameter_list|(
name|char
modifier|*
name|devpath
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|v2_close
function_decl|)
parameter_list|(
name|int
name|d
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|v2_read
function_decl|)
parameter_list|(
name|int
name|d
parameter_list|,
name|caddr_t
name|buf
parameter_list|,
name|int
name|nbytes
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|v2_write
function_decl|)
parameter_list|(
name|int
name|d
parameter_list|,
name|caddr_t
name|buf
parameter_list|,
name|int
name|nbytes
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|v2_seek
function_decl|)
parameter_list|(
name|int
name|d
parameter_list|,
name|int
name|hi
parameter_list|,
name|int
name|lo
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|v2_xxx2
function_decl|)
parameter_list|()
function_decl|;
comment|/* ??? */
name|void
function_decl|(
modifier|*
name|v2_xxx3
function_decl|)
parameter_list|()
function_decl|;
comment|/* ??? */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The v0 interface describes memory regions with these linked lists.  * (The !$&@#+ v2 interface reformats these as properties, so that we  * have to extract them into local temporary memory and reinterpret them.)  */
end_comment

begin_struct
struct|struct
name|v0mlist
block|{
name|struct
name|v0mlist
modifier|*
name|next
decl_stmt|;
name|caddr_t
name|addr
decl_stmt|;
name|u_int
name|nbytes
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * V0 gives us three memory lists:  Total physical memory, VM reserved to  * the PROM, and available physical memory (which, presumably, is just the  * total minus any pages mapped in the PROM's VM region).  We can find the  * reserved PMEGs by scanning the taken VM.  Unfortunately, the V2 prom  * forgot to provide taken VM, and we are stuck with scanning ``magic''  * addresses.  */
end_comment

begin_struct
struct|struct
name|v0mem
block|{
name|struct
name|v0mlist
modifier|*
modifier|*
name|v0_phystot
decl_stmt|;
comment|/* physical memory */
name|struct
name|v0mlist
modifier|*
modifier|*
name|v0_vmprom
decl_stmt|;
comment|/* VM used by PROM */
name|struct
name|v0mlist
modifier|*
modifier|*
name|v0_physavail
decl_stmt|;
comment|/* available physical memory */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The version 0 PROM breaks up the string given to the boot command and  * leaves the decoded version behind.  */
end_comment

begin_struct
struct|struct
name|v0bootargs
block|{
name|char
modifier|*
name|ba_argv
index|[
literal|8
index|]
decl_stmt|;
comment|/* argv format for boot string */
name|char
name|ba_args
index|[
literal|100
index|]
decl_stmt|;
comment|/* string space */
name|char
name|ba_bootdev
index|[
literal|2
index|]
decl_stmt|;
comment|/* e.g., "sd" for `b sd(...' */
name|int
name|ba_ctlr
decl_stmt|;
comment|/* controller # */
name|int
name|ba_unit
decl_stmt|;
comment|/* unit # */
name|int
name|ba_part
decl_stmt|;
comment|/* partition # */
name|char
modifier|*
name|ba_kernel
decl_stmt|;
comment|/* kernel to boot, e.g., "vmunix" */
name|void
modifier|*
name|ba_spare0
decl_stmt|;
comment|/* not decoded here	XXX */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The version 2 PROM interface uses the more general, if less convenient,  * approach of passing the boot strings unchanged.  We also get open file  * numbers for stdin and stdout (keyboard and screen, or whatever), for use  * with the v2 device ops.  */
end_comment

begin_struct
struct|struct
name|v2bootargs
block|{
name|char
modifier|*
modifier|*
name|v2_bootpath
decl_stmt|;
comment|/* V2: Path to boot device */
name|char
modifier|*
modifier|*
name|v2_bootargs
decl_stmt|;
comment|/* V2: Boot args */
name|int
modifier|*
name|v2_fd0
decl_stmt|;
comment|/* V2: Stdin descriptor */
name|int
modifier|*
name|v2_fd1
decl_stmt|;
comment|/* V2: Stdout descriptor */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines the primary PROM vector interface.  * The Boot PROM hands the kernel a pointer to this structure in %o0.  * There are numerous substructures defined below.  */
end_comment

begin_struct
struct|struct
name|promvec
block|{
comment|/* Version numbers. */
name|u_int
name|pv_magic
decl_stmt|;
comment|/* Magic number */
name|u_int
name|pv_romvec_vers
decl_stmt|;
comment|/* interface version (0, 2) */
name|u_int
name|pv_plugin_vers
decl_stmt|;
comment|/* ??? */
name|u_int
name|pv_printrev
decl_stmt|;
comment|/* PROM rev # (* 10, e.g 1.9 = 19) */
comment|/* Version 0 memory descriptors (see below). */
name|struct
name|v0mem
name|pv_v0mem
decl_stmt|;
comment|/* V0: Memory description lists. */
comment|/* Node operations (see below). */
name|struct
name|nodeops
modifier|*
name|pv_nodeops
decl_stmt|;
comment|/* node functions */
name|char
modifier|*
modifier|*
name|pv_bootstr
decl_stmt|;
comment|/* Boot command, eg sd(0,0,0)vmunix */
name|struct
name|v0devops
name|pv_v0devops
decl_stmt|;
comment|/* V0: device ops */
comment|/* 	 * PROMDEV_* cookies.  I fear these may vanish in lieu of fd0/fd1 	 * (see below) in future PROMs, but for now they work fine. 	 */
name|char
modifier|*
name|pv_stdin
decl_stmt|;
comment|/* stdin cookie */
name|char
modifier|*
name|pv_stdout
decl_stmt|;
comment|/* stdout cookie */
define|#
directive|define
name|PROMDEV_KBD
value|0
comment|/* input from keyboard */
define|#
directive|define
name|PROMDEV_SCREEN
value|0
comment|/* output to screen */
define|#
directive|define
name|PROMDEV_TTYA
value|1
comment|/* in/out to ttya */
define|#
directive|define
name|PROMDEV_TTYB
value|2
comment|/* in/out to ttyb */
comment|/* Blocking getchar/putchar.  NOT REENTRANT! (grr) */
name|int
function_decl|(
modifier|*
name|pv_getchar
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pv_putchar
function_decl|)
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
comment|/* Non-blocking variants that return -1 on error. */
name|int
function_decl|(
modifier|*
name|pv_nbgetchar
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pv_nbputchar
function_decl|)
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
comment|/* Put counted string (can be very slow). */
name|void
function_decl|(
modifier|*
name|pv_putstr
function_decl|)
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
comment|/* Miscellany. */
name|void
function_decl|(
modifier|*
name|pv_reboot
function_decl|)
parameter_list|(
name|char
modifier|*
name|bootstr
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pv_printf
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pv_abort
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* L1-A abort */
name|int
modifier|*
name|pv_ticks
decl_stmt|;
comment|/* Ticks since last reset */
name|__dead
name|void
function_decl|(
modifier|*
name|pv_halt
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Halt! */
name|void
function_decl|(
modifier|*
modifier|*
name|pv_synchook
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* "sync" command hook */
comment|/* 	 * This eval's a FORTH string.  Unfortunately, its interface 	 * changed between V0 and V2, which gave us much pain. 	 */
union|union
block|{
name|void
function_decl|(
modifier|*
name|v0_eval
function_decl|)
parameter_list|(
name|int
name|len
parameter_list|,
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|v2_eval
function_decl|)
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
block|}
name|pv_fortheval
union|;
name|struct
name|v0bootargs
modifier|*
modifier|*
name|pv_v0bootargs
decl_stmt|;
comment|/* V0: Boot args */
comment|/* Extract Ethernet address from network device. */
name|u_int
function_decl|(
modifier|*
name|pv_enaddr
function_decl|)
parameter_list|(
name|int
name|d
parameter_list|,
name|char
modifier|*
name|enaddr
parameter_list|)
function_decl|;
name|struct
name|v2bootargs
name|pv_v2bootargs
decl_stmt|;
comment|/* V2: Boot args + std in/out */
name|struct
name|v2devops
name|pv_v2devops
decl_stmt|;
comment|/* V2: device operations */
name|int
name|pv_spare
index|[
literal|15
index|]
decl_stmt|;
comment|/* 	 * The following is machine-dependent. 	 * 	 * The sun4c needs a PROM function to set a PMEG for another 	 * context, so that the kernel can map itself in all contexts. 	 * It is not possible simply to set the context register, because 	 * contexts 1 through N may have invalid translations for the 	 * current program counter.  The hardware has a mode in which 	 * all memory references go to the PROM, so the PROM can do it 	 * easily. 	 */
name|void
function_decl|(
modifier|*
name|pv_setctxt
function_decl|)
parameter_list|(
name|int
name|ctxt
parameter_list|,
name|caddr_t
name|va
parameter_list|,
name|int
name|pmeg
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * In addition to the global stuff defined in the PROM vectors above,  * the PROM has quite a collection of `nodes'.  A node is described by  * an integer---these seem to be internal pointers, actually---and the  * nodes are arranged into an N-ary tree.  Each node implements a fixed  * set of functions, as described below.  The first two deal with the tree  * structure, allowing traversals in either breadth- or depth-first fashion.  * The rest deal with `properties'.  *  * A node property is simply a name/value pair.  The names are C strings  * (NUL-terminated); the values are arbitrary byte strings (counted strings).  * Many values are really just C strings.  Sometimes these are NUL-terminated,  * sometimes not, depending on the the interface version; v0 seems to  * terminate and v2 not.  Many others are simply integers stored as four  * bytes in machine order: you just get them and go.  The third popular  * format is an `address', which is made up of one or more sets of three  * integers as defined below.  *  * N.B.: for the `next' functions, next(0) = first, and next(last) = 0.  * Whoever designed this part had good taste.  On the other hand, these  * operation vectors are global, rather than per-node, yet the pointers  * are not in the openprom vectors but rather found by indirection from  * there.  So the taste balances out.  */
end_comment

begin_struct
struct|struct
name|openprom_addr
block|{
name|int
name|oa_space
decl_stmt|;
comment|/* address space (may be relative) */
name|u_int
name|oa_base
decl_stmt|;
comment|/* address within space */
name|u_int
name|oa_size
decl_stmt|;
comment|/* extent (number of bytes) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nodeops
block|{
comment|/* 	 * Tree traversal. 	 */
name|int
function_decl|(
modifier|*
name|no_nextnode
function_decl|)
parameter_list|(
name|int
name|node
parameter_list|)
function_decl|;
comment|/* next(node) */
name|int
function_decl|(
modifier|*
name|no_child
function_decl|)
parameter_list|(
name|int
name|node
parameter_list|)
function_decl|;
comment|/* first child */
comment|/* 	 * Property functions.  Proper use of getprop requires calling 	 * proplen first to make sure it fits.  Kind of a pain, but no 	 * doubt more convenient for the PROM coder. 	 */
name|int
function_decl|(
modifier|*
name|no_proplen
function_decl|)
parameter_list|(
name|int
name|node
parameter_list|,
name|caddr_t
name|name
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|no_getprop
function_decl|)
parameter_list|(
name|int
name|node
parameter_list|,
name|caddr_t
name|name
parameter_list|,
name|caddr_t
name|val
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|no_setprop
function_decl|)
parameter_list|(
name|int
name|node
parameter_list|,
name|caddr_t
name|name
parameter_list|,
name|caddr_t
name|val
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
name|caddr_t
function_decl|(
modifier|*
name|no_nextprop
function_decl|)
parameter_list|(
name|int
name|node
parameter_list|,
name|caddr_t
name|name
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

end_unit

