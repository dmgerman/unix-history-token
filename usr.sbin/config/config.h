begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)config.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_comment
comment|/*  * Config.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|NODEV
value|((dev_t)-1)
end_define

begin_struct
struct|struct
name|file_list
block|{
name|struct
name|file_list
modifier|*
name|f_next
decl_stmt|;
name|char
modifier|*
name|f_fn
decl_stmt|;
comment|/* the name */
name|int
name|f_type
decl_stmt|;
comment|/* type or count */
name|u_char
name|f_flags
decl_stmt|;
comment|/* see below */
name|char
modifier|*
name|f_special
decl_stmt|;
comment|/* special make rule if present */
name|char
modifier|*
name|f_depends
decl_stmt|;
comment|/* additional dependancies */
name|char
modifier|*
name|f_clean
decl_stmt|;
comment|/* File list to add to clean rule */
name|char
modifier|*
name|f_needs
decl_stmt|;
comment|/* 	 * Random values: 	 *	swap space parameters for swap areas 	 *	root device, etc. for system specifications 	 */
union|union
block|{
struct|struct
block|{
comment|/* when swap specification */
name|dev_t
name|fuw_swapdev
decl_stmt|;
name|int
name|fuw_swapsize
decl_stmt|;
name|int
name|fuw_swapflag
decl_stmt|;
block|}
name|fuw
struct|;
struct|struct
block|{
comment|/* when system specification */
name|dev_t
name|fus_rootdev
decl_stmt|;
name|dev_t
name|fus_dumpdev
decl_stmt|;
block|}
name|fus
struct|;
struct|struct
block|{
comment|/* when component dev specification */
name|dev_t
name|fup_compdev
decl_stmt|;
name|int
name|fup_compinfo
decl_stmt|;
block|}
name|fup
struct|;
block|}
name|fun
union|;
define|#
directive|define
name|f_swapdev
value|fun.fuw.fuw_swapdev
define|#
directive|define
name|f_swapsize
value|fun.fuw.fuw_swapsize
define|#
directive|define
name|f_swapflag
value|fun.fuw.fuw_swapflag
define|#
directive|define
name|f_rootdev
value|fun.fus.fus_rootdev
define|#
directive|define
name|f_dumpdev
value|fun.fus.fus_dumpdev
define|#
directive|define
name|f_compdev
value|fun.fup.fup_compdev
define|#
directive|define
name|f_compinfo
value|fun.fup.fup_compinfo
block|}
struct|;
end_struct

begin_comment
comment|/*  * Types.  */
end_comment

begin_define
define|#
directive|define
name|DRIVER
value|1
end_define

begin_define
define|#
directive|define
name|NORMAL
value|2
end_define

begin_define
define|#
directive|define
name|INVISIBLE
value|3
end_define

begin_define
define|#
directive|define
name|PROFILING
value|4
end_define

begin_define
define|#
directive|define
name|SYSTEMSPEC
value|5
end_define

begin_define
define|#
directive|define
name|SWAPSPEC
value|6
end_define

begin_define
define|#
directive|define
name|COMPDEVICE
value|7
end_define

begin_define
define|#
directive|define
name|COMPSPEC
value|8
end_define

begin_define
define|#
directive|define
name|DEVDONE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TYPEMASK
value|0x7fffffff
end_define

begin_comment
comment|/*  * Attributes (flags).  */
end_comment

begin_define
define|#
directive|define
name|CONFIGDEP
value|1
end_define

begin_define
define|#
directive|define
name|NO_IMPLCT_RULE
value|2
end_define

begin_define
define|#
directive|define
name|NO_OBJ
value|4
end_define

begin_define
define|#
directive|define
name|BEFORE_DEPEND
value|8
end_define

begin_struct
struct|struct
name|idlst
block|{
name|char
modifier|*
name|id
decl_stmt|;
name|struct
name|idlst
modifier|*
name|id_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|device
block|{
name|int
name|d_type
decl_stmt|;
comment|/* CONTROLLER, DEVICE, bus adaptor */
name|struct
name|device
modifier|*
name|d_conn
decl_stmt|;
comment|/* what it is connected to */
name|char
modifier|*
name|d_name
decl_stmt|;
comment|/* name of device (e.g. rk11) */
name|struct
name|idlst
modifier|*
name|d_vec
decl_stmt|;
comment|/* interrupt vectors */
name|int
name|d_pri
decl_stmt|;
comment|/* interrupt priority */
name|int
name|d_addr
decl_stmt|;
comment|/* address of csr */
name|int
name|d_unit
decl_stmt|;
comment|/* unit number */
name|int
name|d_drive
decl_stmt|;
comment|/* drive number */
name|int
name|d_target
decl_stmt|;
comment|/* target number */
name|int
name|d_lun
decl_stmt|;
comment|/* unit number */
name|int
name|d_slave
decl_stmt|;
comment|/* slave number */
define|#
directive|define
name|QUES
value|-1
comment|/* -1 means '?' */
define|#
directive|define
name|UNKNOWN
value|-2
comment|/* -2 means not set yet */
name|int
name|d_dk
decl_stmt|;
comment|/* if init 1 set to number for iostat */
name|int
name|d_flags
decl_stmt|;
comment|/* flags for device init */
name|int
name|d_conflicts
decl_stmt|;
comment|/* I'm allowed to conflict */
name|int
name|d_disabled
decl_stmt|;
comment|/* nonzero to skip probe/attach */
name|char
modifier|*
name|d_port
decl_stmt|;
comment|/* io port base manifest constant */
name|int
name|d_portn
decl_stmt|;
comment|/* io port base (if number not manifest) */
name|char
modifier|*
name|d_mask
decl_stmt|;
comment|/* interrupt mask */
name|int
name|d_maddr
decl_stmt|;
comment|/* io memory base */
name|int
name|d_msize
decl_stmt|;
comment|/* io memory size */
name|int
name|d_drq
decl_stmt|;
comment|/* DMA request  */
name|int
name|d_irq
decl_stmt|;
comment|/* interrupt request  */
name|struct
name|device
modifier|*
name|d_next
decl_stmt|;
comment|/* Next one in list */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TO_NEXUS
value|(struct device *)-1
end_define

begin_define
define|#
directive|define
name|TO_VBA
value|(struct device *)-2
end_define

begin_struct
struct|struct
name|config
block|{
name|char
modifier|*
name|c_dev
decl_stmt|;
name|char
modifier|*
name|s_sysname
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Config has a global notion of which machine type is  * being used.  It uses the name of the machine in choosing  * files and directories.  Thus if the name of the machine is ``vax'',  * it will build from ``Makefile.vax'' and use ``../vax/inline''  * in the makerules, etc.  */
end_comment

begin_decl_stmt
name|int
name|machine
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|machinename
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MACHINE_VAX
value|1
end_define

begin_define
define|#
directive|define
name|MACHINE_TAHOE
value|2
end_define

begin_define
define|#
directive|define
name|MACHINE_HP300
value|3
end_define

begin_define
define|#
directive|define
name|MACHINE_I386
value|4
end_define

begin_define
define|#
directive|define
name|MACHINE_MIPS
value|5
end_define

begin_define
define|#
directive|define
name|MACHINE_PMAX
value|6
end_define

begin_define
define|#
directive|define
name|MACHINE_LUNA68K
value|7
end_define

begin_define
define|#
directive|define
name|MACHINE_NEWS3400
value|8
end_define

begin_comment
comment|/*  * For each machine, a set of CPU's may be specified as supported.  * These and the options (below) are put in the C flags in the makefile.  */
end_comment

begin_struct
struct|struct
name|cputype
block|{
name|char
modifier|*
name|cpu_name
decl_stmt|;
name|struct
name|cputype
modifier|*
name|cpu_next
decl_stmt|;
block|}
modifier|*
name|cputype
struct|;
end_struct

begin_comment
comment|/*  * A set of options may also be specified which are like CPU types,  * but which may also specify values for the options.  * A separate set of options may be defined for make-style options.  */
end_comment

begin_struct
struct|struct
name|opt
block|{
name|char
modifier|*
name|op_name
decl_stmt|;
name|char
modifier|*
name|op_value
decl_stmt|;
name|int
name|op_line
decl_stmt|;
comment|/* line number for error-reporting */
name|int
name|op_ownfile
decl_stmt|;
comment|/* true = own file, false = makefile */
name|struct
name|opt
modifier|*
name|op_next
decl_stmt|;
block|}
modifier|*
name|opt
struct|,
modifier|*
name|mkopt
struct|;
end_struct

begin_struct
struct|struct
name|opt_list
block|{
name|char
modifier|*
name|o_name
decl_stmt|;
name|char
modifier|*
name|o_file
decl_stmt|;
name|struct
name|opt_list
modifier|*
name|o_next
decl_stmt|;
block|}
modifier|*
name|otab
struct|;
end_struct

begin_decl_stmt
name|char
modifier|*
name|ident
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|ns
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|qu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_word
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_quoted_word
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|path
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|raise
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|moveifchanged
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|do_trace
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|MACHINE_VAX
end_if

begin_decl_stmt
name|int
name|seen_mba
decl_stmt|,
name|seen_uba
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MACHINE_TAHOE
end_if

begin_decl_stmt
name|int
name|seen_vba
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MACHINE_I386
end_if

begin_decl_stmt
name|int
name|seen_isa
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|seen_scbus
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|seen_cd
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|device
modifier|*
name|connect
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|device
modifier|*
name|dtab
decl_stmt|;
end_decl_stmt

begin_function_decl
name|dev_t
name|nametodev
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|devtoname
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
name|errbuf
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yyline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|file_list
modifier|*
name|ftab
decl_stmt|,
modifier|*
name|conf_list
decl_stmt|,
modifier|*
modifier|*
name|confp
decl_stmt|,
modifier|*
name|comp_list
decl_stmt|,
modifier|*
modifier|*
name|compp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|profiling
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|debugging
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|maxusers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|loadaddress
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|old_config_present
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Old config/build directory still there */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|PREFIX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Config file name - for error messages */
end_comment

begin_define
define|#
directive|define
name|eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(!strcmp(a,b))
end_define

end_unit

