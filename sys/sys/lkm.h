begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Header file used by loadable kernel modules and loadable kernel module  * utilities.  *  * 23 Jan 93	Terry Lambert		Original  *  * Copyright (c) 1992 Terrence R. Lambert.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Terrence R. Lambert.  * 4. The name Terrence R. Lambert may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY TERRENCE R. LAMBERT ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE TERRENCE R. LAMBERT BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: lkm.h,v 1.16 1997/04/06 11:14:12 dufault Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_LKM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_LKM_H_
end_define

begin_comment
comment|/*  * Supported module types  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|loadmod
block|{
name|LM_SYSCALL
block|,
name|LM_VFS
block|,
name|LM_DEV
block|,
name|LM_STRMOD
block|,
name|LM_EXEC
block|,
name|LM_MISC
block|}
name|MODTYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LKM_VERSION
value|1
end_define

begin_comment
comment|/* version of module loader */
end_comment

begin_define
define|#
directive|define
name|MAXLKMNAME
value|32
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Loadable system call  */
end_comment

begin_struct
struct|struct
name|lkm_syscall
block|{
name|MODTYPE
name|lkm_type
decl_stmt|;
name|int
name|lkm_ver
decl_stmt|;
specifier|const
name|char
modifier|*
name|lkm_name
decl_stmt|;
name|u_long
name|lkm_offset
decl_stmt|;
comment|/* save/assign area */
name|struct
name|sysent
modifier|*
name|lkm_sysent
decl_stmt|;
name|struct
name|sysent
name|lkm_oldent
decl_stmt|;
comment|/* save area for unload */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Loadable file system  */
end_comment

begin_struct
struct|struct
name|lkm_vfs
block|{
name|MODTYPE
name|lkm_type
decl_stmt|;
name|int
name|lkm_ver
decl_stmt|;
specifier|const
name|char
modifier|*
name|lkm_name
decl_stmt|;
name|u_long
name|lkm_offset
decl_stmt|;
name|struct
name|linker_set
modifier|*
name|lkm_vnodeops
decl_stmt|;
name|struct
name|vfsconf
modifier|*
name|lkm_vfsconf
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Supported device module types  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|devtype
block|{
name|LM_DT_BLOCK
block|,
name|LM_DT_CHAR
block|}
name|DEVTYPE
typedef|;
end_typedef

begin_comment
comment|/*  * Loadable device driver  */
end_comment

begin_struct
struct|struct
name|lkm_dev
block|{
name|MODTYPE
name|lkm_type
decl_stmt|;
name|int
name|lkm_ver
decl_stmt|;
specifier|const
name|char
modifier|*
name|lkm_name
decl_stmt|;
name|u_long
name|lkm_offset
decl_stmt|;
name|DEVTYPE
name|lkm_devtype
decl_stmt|;
union|union
block|{
name|void
modifier|*
name|anon
decl_stmt|;
name|struct
name|bdevsw
modifier|*
name|bdev
decl_stmt|;
name|struct
name|cdevsw
modifier|*
name|cdev
decl_stmt|;
block|}
name|lkm_dev
union|;
union|union
block|{
name|struct
name|bdevsw
modifier|*
name|bdev
decl_stmt|;
name|struct
name|cdevsw
modifier|*
name|cdev
decl_stmt|;
block|}
name|lkm_olddev
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Loadable streams module  */
end_comment

begin_struct
struct|struct
name|lkm_strmod
block|{
name|MODTYPE
name|lkm_type
decl_stmt|;
name|int
name|lkm_ver
decl_stmt|;
specifier|const
name|char
modifier|*
name|lkm_name
decl_stmt|;
name|u_long
name|lkm_offset
decl_stmt|;
comment|/* 	 * Removed: future release 	 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Exec loader  */
end_comment

begin_struct
struct|struct
name|lkm_exec
block|{
name|MODTYPE
name|lkm_type
decl_stmt|;
name|int
name|lkm_ver
decl_stmt|;
specifier|const
name|char
modifier|*
name|lkm_name
decl_stmt|;
name|u_long
name|lkm_offset
decl_stmt|;
specifier|const
name|struct
name|execsw
modifier|*
name|lkm_exec
decl_stmt|;
name|struct
name|execsw
name|lkm_oldexec
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Miscellaneous module (complex load/unload, potentially complex stat  */
end_comment

begin_struct
struct|struct
name|lkm_misc
block|{
name|MODTYPE
name|lkm_type
decl_stmt|;
name|int
name|lkm_ver
decl_stmt|;
specifier|const
name|char
modifier|*
name|lkm_name
decl_stmt|;
name|u_long
name|lkm_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Any module (to get type and name info without knowing type)  */
end_comment

begin_struct
struct|struct
name|lkm_any
block|{
name|MODTYPE
name|lkm_type
decl_stmt|;
name|int
name|lkm_ver
decl_stmt|;
specifier|const
name|char
modifier|*
name|lkm_name
decl_stmt|;
name|u_long
name|lkm_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Generic reference ala XEvent to allow single entry point in the xxxinit()  * routine.  */
end_comment

begin_union
union|union
name|lkm_generic
block|{
name|struct
name|lkm_any
modifier|*
name|lkm_any
decl_stmt|;
name|struct
name|lkm_syscall
modifier|*
name|lkm_syscall
decl_stmt|;
name|struct
name|lkm_vfs
modifier|*
name|lkm_vfs
decl_stmt|;
name|struct
name|lkm_dev
modifier|*
name|lkm_dev
decl_stmt|;
name|struct
name|lkm_strmod
modifier|*
name|lkm_strmod
decl_stmt|;
name|struct
name|lkm_exec
modifier|*
name|lkm_exec
decl_stmt|;
name|struct
name|lkm_misc
modifier|*
name|lkm_misc
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|lkm_all
block|{
name|struct
name|lkm_any
name|lkm_any
decl_stmt|;
name|struct
name|lkm_syscall
name|lkm_syscall
decl_stmt|;
name|struct
name|lkm_vfs
name|lkm_vfs
decl_stmt|;
name|struct
name|lkm_dev
name|lkm_dev
decl_stmt|;
name|struct
name|lkm_strmod
name|lkm_strmod
decl_stmt|;
name|struct
name|lkm_exec
name|lkm_exec
decl_stmt|;
name|struct
name|lkm_misc
name|lkm_misc
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Per module information structure  */
end_comment

begin_struct
struct|struct
name|lkm_table
block|{
name|int
name|type
decl_stmt|;
name|u_long
name|size
decl_stmt|;
name|u_long
name|offset
decl_stmt|;
name|u_long
name|area
decl_stmt|;
name|char
name|used
decl_stmt|;
name|int
name|ver
decl_stmt|;
comment|/* version (INIT) */
name|int
name|refcnt
decl_stmt|;
comment|/* reference count (INIT) */
name|int
name|depcnt
decl_stmt|;
comment|/* dependency count (INIT) */
name|int
name|id
decl_stmt|;
comment|/* identifier (INIT) */
name|int
argument_list|(
argument|*entry
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|lkm_table
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* entry function */
name|union
name|lkm_generic
name|private
decl_stmt|;
comment|/* module private data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LKM_E_LOAD
value|1
end_define

begin_define
define|#
directive|define
name|LKM_E_UNLOAD
value|2
end_define

begin_define
define|#
directive|define
name|LKM_E_STAT
value|3
end_define

begin_comment
comment|/* Flag to indicate that LKM should select the slot, etc. Supported by:  *  devslot in MOD_DEV  */
end_comment

begin_define
define|#
directive|define
name|LKM_ANON
value|((u_long)-1)
end_define

begin_comment
comment|/* XXX wcd.c pokes around in the lkm private structure, so until that  * is fixed here is a way to export the structure name.  */
end_comment

begin_define
define|#
directive|define
name|MOD_PRIVATE
parameter_list|(
name|name
parameter_list|)
value|name ## _mod_struct
end_define

begin_define
define|#
directive|define
name|MOD_DECL
parameter_list|(
name|name
parameter_list|)
define|\
value|static int name ## _load __P((struct lkm_table *lkmtp, int cmd));   \ 	static int name ## _unload __P((struct lkm_table *lkmtp, int cmd)); \ 	int name ## _mod __P((struct lkm_table *lkmtp, int cmd,	int ver))
end_define

begin_define
define|#
directive|define
name|MOD_SYSCALL
parameter_list|(
name|name
parameter_list|,
name|callslot
parameter_list|,
name|sysentp
parameter_list|)
define|\
value|static struct lkm_syscall MOD_PRIVATE(name) = {	\ 		LM_SYSCALL,			\ 		LKM_VERSION,			\ 		#name,				\ 		callslot,			\ 		sysentp				\ 	}
end_define

begin_define
define|#
directive|define
name|MOD_VFS
parameter_list|(
name|name
parameter_list|,
name|vnodeops
parameter_list|,
name|vfsconf
parameter_list|)
define|\
value|static struct lkm_vfs MOD_PRIVATE(name) = {	\ 		LM_VFS,				\ 		LKM_VERSION,			\ 		#name,				\ 		0,				\ 		vnodeops,			\ 		vfsconf				\ 	}
end_define

begin_define
define|#
directive|define
name|MOD_DEV
parameter_list|(
name|name
parameter_list|,
name|devtype
parameter_list|,
name|devslot
parameter_list|,
name|devp
parameter_list|)
define|\
value|MOD_DECL(name);				\ 	static struct lkm_dev MOD_PRIVATE(name) = {	\ 		LM_DEV,				\ 		LKM_VERSION,			\ 		#name ## "_mod",		\ 		devslot,			\ 		devtype,			\ 		{ (void *)devp }		\ 	}
end_define

begin_define
define|#
directive|define
name|MOD_EXEC
parameter_list|(
name|name
parameter_list|,
name|execslot
parameter_list|,
name|execsw
parameter_list|)
define|\
value|MOD_DECL(name);				\ 	static struct lkm_exec MOD_PRIVATE(name) = {	\ 		LM_EXEC,			\ 		LKM_VERSION,			\ 		#name ## "_mod",		\ 		execslot,			\ 		execsw				\ 	}
end_define

begin_define
define|#
directive|define
name|MOD_MISC
parameter_list|(
name|name
parameter_list|)
define|\
value|MOD_DECL(name);				\ 	static struct lkm_misc MOD_PRIVATE(name) = {	\ 		LM_MISC,			\ 		LKM_VERSION,			\ 		#name ## "_mod"			\ 	}
end_define

begin_comment
comment|/*  * MOD_DISPATCH -- body function for use in module entry point function;  * generally, the function body will consist entirely of a single  * MOD_DISPATCH line.  *  * Call load/unload/stat on each corresponding entry instance.  "cmd" is  * passed to each function so that a single function can be used if desired.  *  */
end_comment

begin_define
define|#
directive|define
name|MOD_DISPATCH
parameter_list|(
name|name
parameter_list|,
name|lkmtp
parameter_list|,
name|cmd
parameter_list|,
name|ver
parameter_list|,
name|load
parameter_list|,
name|unload
parameter_list|,
name|stat
parameter_list|)
define|\
value|if (ver != LKM_VERSION)						\ 		return EINVAL;
comment|/* version mismatch */
value|\ 	switch (cmd) {							\ 	int	error;							\ 	case LKM_E_LOAD:						\ 		lkmtp->private.lkm_any =				\ 			(struct lkm_any *)& MOD_PRIVATE(name) ;		\ 		if (lkmexists(lkmtp))
comment|/* !!! */
value|\ 			return EEXIST;					\ 		if ((error = load(lkmtp, cmd)))				\ 			return error;					\ 		break;							\ 	case LKM_E_UNLOAD:						\ 		if ((error = unload(lkmtp, cmd)))			\ 			return error;					\ 		break;							\ 	case LKM_E_STAT:						\ 		if ((error = stat(lkmtp, cmd)))				\ 			return error;					\ 		break;							\ 	}								\ 	return lkmdispatch(lkmtp, cmd);
end_define

begin_comment
comment|/* Provide a backward compatible stub that will generate compile time errors.  * When fixing, prefer MOD_DISPATCH to be consistent with the others.  */
end_comment

begin_define
define|#
directive|define
name|DISPATCH
parameter_list|(
name|name
parameter_list|,
name|lkmtp
parameter_list|,
name|cmd
parameter_list|,
name|ver
parameter_list|,
name|load
parameter_list|,
name|unload
parameter_list|,
name|stat
parameter_list|)
define|\
value|MOD_DISPATCH(name,lkmtp,cmd,ver,load,unload,stat)
end_define

begin_decl_stmt
name|int
name|lkmdispatch
name|__P
argument_list|(
operator|(
expr|struct
name|lkm_table
operator|*
name|lkmtp
operator|,
name|int
name|cmd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lkmexists
name|__P
argument_list|(
operator|(
expr|struct
name|lkm_table
operator|*
name|lkmtp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lkm_nullcmd
name|__P
argument_list|(
operator|(
expr|struct
name|lkm_table
operator|*
name|lkmtp
operator|,
name|int
name|cmd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  * IOCTL's recognized by /dev/lkm  */
end_comment

begin_define
define|#
directive|define
name|LMRESERV
value|_IOWR('K', 0, struct lmc_resrv)
end_define

begin_define
define|#
directive|define
name|LMLOADBUF
value|_IOW('K', 1, struct lmc_loadbuf)
end_define

begin_define
define|#
directive|define
name|LMUNRESRV
value|_IO('K', 2)
end_define

begin_define
define|#
directive|define
name|LMREADY
value|_IOW('K', 3, int)
end_define

begin_define
define|#
directive|define
name|LMLOAD
value|_IOW('K', 9, struct lmc_load)
end_define

begin_define
define|#
directive|define
name|LMUNLOAD
value|_IOWR('K', 10, struct lmc_unload)
end_define

begin_define
define|#
directive|define
name|LMSTAT
value|_IOWR('K', 11, struct lmc_stat)
end_define

begin_define
define|#
directive|define
name|MODIOBUF
value|512
end_define

begin_comment
comment|/* # of bytes at a time to loadbuf */
end_comment

begin_comment
comment|/*  * IOCTL arguments  */
end_comment

begin_comment
comment|/*  * Reserve a page-aligned block of kernel memory for the module  */
end_comment

begin_struct
struct|struct
name|lmc_resrv
block|{
name|u_long
name|size
decl_stmt|;
comment|/* IN: size of module to reserve */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* IN: name (must be provided */
name|int
name|slot
decl_stmt|;
comment|/* OUT: allocated slot (module ID) */
name|u_long
name|addr
decl_stmt|;
comment|/* OUT: Link-to address */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Copy a buffer at a time into the allocated area in the kernel; writes  * are assumed to occur contiguously.  */
end_comment

begin_struct
struct|struct
name|lmc_loadbuf
block|{
name|int
name|cnt
decl_stmt|;
comment|/* IN: # of chars pointed to by data */
name|char
modifier|*
name|data
decl_stmt|;
comment|/* IN: pointer to data buffer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Load a module (assumes it's been mmapped to address before call)  */
end_comment

begin_struct
struct|struct
name|lmc_load
block|{
name|caddr_t
name|address
decl_stmt|;
comment|/* IN: user space mmap address */
name|int
name|status
decl_stmt|;
comment|/* OUT: status of operation */
name|int
name|id
decl_stmt|;
comment|/* OUT: module ID if loaded */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Unload a module (by name/id)  */
end_comment

begin_struct
struct|struct
name|lmc_unload
block|{
name|int
name|id
decl_stmt|;
comment|/* IN: module ID to unload */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* IN: module name to unload if id -1 */
name|int
name|status
decl_stmt|;
comment|/* OUT: status of operation */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Get module information for a given id (or name if id == -1).  */
end_comment

begin_struct
struct|struct
name|lmc_stat
block|{
name|int
name|id
decl_stmt|;
comment|/* IN: module ID to unload */
name|char
name|name
index|[
name|MAXLKMNAME
index|]
decl_stmt|;
comment|/* IN/OUT: name of module */
name|u_long
name|offset
decl_stmt|;
comment|/* OUT: target table offset */
name|MODTYPE
name|type
decl_stmt|;
comment|/* OUT: type of module */
name|u_long
name|area
decl_stmt|;
comment|/* OUT: kernel load addr */
name|u_long
name|size
decl_stmt|;
comment|/* OUT: module size (pages) */
name|u_long
name|private
decl_stmt|;
comment|/* OUT: module private data */
name|int
name|ver
decl_stmt|;
comment|/* OUT: lkm compile version */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_LKM_H_ */
end_comment

end_unit

