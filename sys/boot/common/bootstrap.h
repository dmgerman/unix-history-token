begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Michael Smith<msmith@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/* XXX debugging */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|console
name|vidconsole
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MARK
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|{vidconsole.c_out(s); vidconsole.c_out(c); while (!vidconsole.c_ready()) ; vidconsole.c_in();}
end_define

begin_comment
comment|/*  * Generic device specifier; architecture-dependant   * versions may be larger, but should be allowed to  * overlap.  */
end_comment

begin_struct
struct|struct
name|devdesc
block|{
name|struct
name|devsw
modifier|*
name|d_dev
decl_stmt|;
name|int
name|d_type
decl_stmt|;
define|#
directive|define
name|DEVT_NONE
value|0
define|#
directive|define
name|DEVT_DISK
value|1
define|#
directive|define
name|DEVT_NET
value|2
block|}
struct|;
end_struct

begin_comment
comment|/* Commands and return values; nonzero return sets command_errmsg != NULL */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bootblk_cmd_t
function_decl|)
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|command_errmsg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|command_errbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX blah, length */
end_comment

begin_define
define|#
directive|define
name|CMD_OK
value|0
end_define

begin_define
define|#
directive|define
name|CMD_ERROR
value|1
end_define

begin_comment
comment|/* interp.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|interact
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|include
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* interp_parse.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|parse
parameter_list|(
name|int
modifier|*
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|argv
parameter_list|,
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* interp_forth.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|bf_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bf_run
parameter_list|(
name|char
modifier|*
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* boot.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|autoboot
parameter_list|(
name|int
name|delay
parameter_list|,
name|char
modifier|*
name|prompt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|autoboot_maybe
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* misc.c */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|unargv
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hexdump
parameter_list|(
name|caddr_t
name|region
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|strlenout
parameter_list|(
name|vm_offset_t
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strdupout
parameter_list|(
name|vm_offset_t
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* bcache.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|bcache_init
parameter_list|(
name|int
name|nblks
parameter_list|,
name|size_t
name|bsize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Disk block cache  */
end_comment

begin_struct
struct|struct
name|bcache_devdata
block|{
name|int
function_decl|(
modifier|*
name|dv_strategy
function_decl|)
parameter_list|(
name|void
modifier|*
name|devdata
parameter_list|,
name|int
name|rw
parameter_list|,
name|daddr_t
name|blk
parameter_list|,
name|size_t
name|size
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|*
name|rsize
parameter_list|)
function_decl|;
name|void
modifier|*
name|dv_devdata
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Modular console support.  */
end_comment

begin_struct
struct|struct
name|console
block|{
name|char
modifier|*
name|c_name
decl_stmt|;
name|char
modifier|*
name|c_desc
decl_stmt|;
name|int
name|c_flags
decl_stmt|;
define|#
directive|define
name|C_PRESENTIN
value|(1<<0)
define|#
directive|define
name|C_PRESENTOUT
value|(1<<1)
define|#
directive|define
name|C_ACTIVEIN
value|(1<<2)
define|#
directive|define
name|C_ACTIVEOUT
value|(1<<3)
name|void
function_decl|(
modifier|*
name|c_probe
function_decl|)
parameter_list|(
name|struct
name|console
modifier|*
name|cp
parameter_list|)
function_decl|;
comment|/* set c_flags to match hardware */
name|int
function_decl|(
modifier|*
name|c_init
function_decl|)
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
comment|/* reinit XXX may need more args */
name|void
function_decl|(
modifier|*
name|c_out
function_decl|)
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
comment|/* emit c */
name|int
function_decl|(
modifier|*
name|c_in
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* wait for and return input */
name|int
function_decl|(
modifier|*
name|c_ready
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* return nonzer if input waiting */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|console
modifier|*
name|consoles
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|cons_probe
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Plug-and-play enumerator/configurator interface.  */
end_comment

begin_struct
struct|struct
name|pnphandler
block|{
name|char
modifier|*
name|pp_name
decl_stmt|;
comment|/* handler/bus name */
name|void
function_decl|(
modifier|*
name|pp_enumerate
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* enumerate PnP devices, add to chain */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pnpident
block|{
name|char
modifier|*
name|id_ident
decl_stmt|;
comment|/* ASCII identifier, actual format varies with bus/handler */
name|STAILQ_ENTRY
argument_list|(
argument|pnpident
argument_list|)
name|id_link
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pnpinfo
block|{
name|char
modifier|*
name|pi_desc
decl_stmt|;
comment|/* ASCII description, optional */
name|int
name|pi_revision
decl_stmt|;
comment|/* optional revision (or -1) if not supported */
name|char
modifier|*
name|pi_module
decl_stmt|;
comment|/* module/args nominated to handle device */
name|int
name|pi_argc
decl_stmt|;
comment|/* module arguments */
name|char
modifier|*
modifier|*
name|pi_argv
decl_stmt|;
name|struct
name|pnphandler
modifier|*
name|pi_handler
decl_stmt|;
comment|/* handler which detected this device */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|pnpident
argument_list|)
name|pi_ident
expr_stmt|;
comment|/* list of identifiers */
name|STAILQ_ENTRY
argument_list|(
argument|pnpinfo
argument_list|)
name|pi_link
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|pnphandler
modifier|*
name|pnphandlers
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* provided by MD code */
end_comment

begin_function_decl
specifier|extern
name|void
name|pnp_addident
parameter_list|(
name|struct
name|pnpinfo
modifier|*
name|pi
parameter_list|,
name|char
modifier|*
name|ident
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|pnpinfo
modifier|*
name|pnp_allocinfo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pnp_freeinfo
parameter_list|(
name|struct
name|pnpinfo
modifier|*
name|pi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pnp_addinfo
parameter_list|(
name|struct
name|pnpinfo
modifier|*
name|pi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|pnp_eisaformat
parameter_list|(
name|u_int8_t
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *< 0	- No ISA in system  * == 0	- Maybe ISA, search for read data port  *> 0	- ISA in system, value is read data port address  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|isapnp_readport
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Module metadata header.  *  * Metadata are allocated on our heap, and copied into kernel space  * before executing the kernel.  */
end_comment

begin_struct
struct|struct
name|module_metadata
block|{
name|size_t
name|md_size
decl_stmt|;
name|u_int16_t
name|md_type
decl_stmt|;
name|struct
name|module_metadata
modifier|*
name|md_next
decl_stmt|;
name|char
name|md_data
index|[
literal|0
index|]
decl_stmt|;
comment|/* data are immediately appended */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Loaded module information.  *  * At least one module (the kernel) must be loaded in order to boot.  * The kernel is always loaded first.  *  * String fields (m_name, m_type) should be dynamically allocated.  */
end_comment

begin_struct
struct|struct
name|loaded_module
block|{
name|char
modifier|*
name|m_name
decl_stmt|;
comment|/* module name */
name|char
modifier|*
name|m_type
decl_stmt|;
comment|/* verbose module type, eg 'ELF kernel', 'pnptable', etc. */
name|char
modifier|*
name|m_args
decl_stmt|;
comment|/* arguments for the module */
name|struct
name|module_metadata
modifier|*
name|m_metadata
decl_stmt|;
comment|/* metadata that will be placed in the module directory */
name|int
name|m_loader
decl_stmt|;
comment|/* index of the loader that read the file */
name|vm_offset_t
name|m_addr
decl_stmt|;
comment|/* load address */
name|size_t
name|m_size
decl_stmt|;
comment|/* module size */
name|struct
name|loaded_module
modifier|*
name|m_next
decl_stmt|;
comment|/* next module */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|module_format
block|{
comment|/* Load function must return EFTYPE if it can't handle the module supplied */
name|int
function_decl|(
modifier|*
name|l_load
function_decl|)
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|,
name|vm_offset_t
name|dest
parameter_list|,
name|struct
name|loaded_module
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
comment|/* Only a loader that will load a kernel (first module) should have an exec handler */
name|int
function_decl|(
modifier|*
name|l_exec
function_decl|)
parameter_list|(
name|struct
name|loaded_module
modifier|*
name|mp
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|module_format
modifier|*
name|module_formats
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* supplied by consumer */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|loaded_module
modifier|*
name|loaded_modules
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|mod_load
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mod_loadobj
parameter_list|(
name|char
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|loaded_module
modifier|*
name|mod_findmodule
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mod_addmetadata
parameter_list|(
name|struct
name|loaded_module
modifier|*
name|mp
parameter_list|,
name|int
name|type
parameter_list|,
name|size_t
name|size
parameter_list|,
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|module_metadata
modifier|*
name|mod_findmetadata
parameter_list|(
name|struct
name|loaded_module
modifier|*
name|mp
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mod_discard
parameter_list|(
name|struct
name|loaded_module
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|loaded_module
modifier|*
name|mod_allocmodule
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MI module loaders */
end_comment

begin_function_decl
specifier|extern
name|int
name|aout_loadmodule
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|,
name|vm_offset_t
name|dest
parameter_list|,
name|struct
name|loaded_module
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vm_offset_t
name|aout_findsym
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|loaded_module
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|elf_loadmodule
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|,
name|vm_offset_t
name|dest
parameter_list|,
name|struct
name|loaded_module
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NEW_LINKER_SET
end_ifndef

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_comment
comment|/* XXX just for conversion's sake, until we move to the new linker set code */
end_comment

begin_define
define|#
directive|define
name|SET_FOREACH
parameter_list|(
name|pvar
parameter_list|,
name|set
parameter_list|)
define|\
value|for (pvar = set.ls_items;			\ 		 pvar< set.ls_items + set.ls_length;	\ 		 pvar++)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NEW_LINKER_SET */
end_comment

begin_comment
comment|/*  * Private macros, not to be used outside this header file.  */
end_comment

begin_define
define|#
directive|define
name|__MAKE_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
define|\
value|static void *__CONCAT(__setentry,__LINE__)			\ 	__attribute__((__section__("set_" #set),__unused__)) =&sym
end_define

begin_define
define|#
directive|define
name|__SET_BEGIN
parameter_list|(
name|set
parameter_list|)
define|\
value|({ extern void *__CONCAT(__start_set_,set);			\&__CONCAT(__start_set_,set); })
end_define

begin_define
define|#
directive|define
name|__SET_END
parameter_list|(
name|set
parameter_list|)
define|\
value|({ extern void *__CONCAT(__stop_set_,set);			\&__CONCAT(__stop_set_,set); })
end_define

begin_comment
comment|/*  * Public macros.  */
end_comment

begin_comment
comment|/* Add an entry to a set. */
end_comment

begin_define
define|#
directive|define
name|TEXT_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|__MAKE_SET(set, sym)
end_define

begin_define
define|#
directive|define
name|DATA_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|__MAKE_SET(set, sym)
end_define

begin_define
define|#
directive|define
name|BSS_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|__MAKE_SET(set, sym)
end_define

begin_define
define|#
directive|define
name|ABS_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|__MAKE_SET(set, sym)
end_define

begin_comment
comment|/*  * Iterate over all the elements of a set.  *  * Sets always contain addresses of things, and "pvar" points to words  * containing those addresses.  Thus is must be declared as "type **pvar",  * and the address of each set item is obtained inside the loop by "*pvar".  */
end_comment

begin_define
define|#
directive|define
name|SET_FOREACH
parameter_list|(
name|pvar
parameter_list|,
name|set
parameter_list|)
define|\
value|for (pvar = (__typeof__(pvar))__SET_BEGIN(set);			\ 	    pvar< (__typeof__(pvar))__SET_END(set); pvar++)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Support for commands   */
end_comment

begin_struct
struct|struct
name|bootblk_command
block|{
specifier|const
name|char
modifier|*
name|c_name
decl_stmt|;
specifier|const
name|char
modifier|*
name|c_desc
decl_stmt|;
name|bootblk_cmd_t
modifier|*
name|c_fn
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|COMMAND_SET
parameter_list|(
name|tag
parameter_list|,
name|key
parameter_list|,
name|desc
parameter_list|,
name|func
parameter_list|)
define|\
value|static bootblk_cmd_t func;						\     static struct bootblk_command _cmd_ ## tag = { key, desc, func };	\     DATA_SET(Xcommand_set, _cmd_ ## tag);
end_define

begin_decl_stmt
specifier|extern
name|struct
name|linker_set
name|Xcommand_set
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * The intention of the architecture switch is to provide a convenient  * encapsulation of the interface between the bootstrap MI and MD code.  * MD code may selectively populate the switch at runtime based on the  * actual configuration of the target system.  */
end_comment

begin_struct
struct|struct
name|arch_switch
block|{
comment|/* Automatically load modules as required by detected hardware */
name|int
function_decl|(
modifier|*
name|arch_autoload
function_decl|)
parameter_list|()
function_decl|;
comment|/* Locate the device for (name), return pointer to tail in (*path) */
name|int
function_decl|(
modifier|*
name|arch_getdev
function_decl|)
parameter_list|(
name|void
modifier|*
modifier|*
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|path
parameter_list|)
function_decl|;
comment|/* Copy from local address space to module address space, similar to bcopy() */
name|int
function_decl|(
modifier|*
name|arch_copyin
function_decl|)
parameter_list|(
name|void
modifier|*
name|src
parameter_list|,
name|vm_offset_t
name|dest
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
comment|/* Copy to local address space from module address space, similar to bcopy() */
name|int
function_decl|(
modifier|*
name|arch_copyout
function_decl|)
parameter_list|(
name|vm_offset_t
name|src
parameter_list|,
name|void
modifier|*
name|dest
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
comment|/* Read from file to module address space, same semantics as read() */
name|int
function_decl|(
modifier|*
name|arch_readin
function_decl|)
parameter_list|(
name|int
name|fd
parameter_list|,
name|vm_offset_t
name|dest
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
comment|/* Perform ISA byte port I/O (only for systems with ISA) */
name|int
function_decl|(
modifier|*
name|arch_isainb
function_decl|)
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|arch_isaoutb
function_decl|)
parameter_list|(
name|int
name|port
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|arch_switch
name|archsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This must be provided by the MD code, but should it be in the archsw? */
end_comment

begin_function_decl
specifier|extern
name|void
name|delay
parameter_list|(
name|int
name|delay
parameter_list|)
function_decl|;
end_function_decl

end_unit

