begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)config.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
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
name|char
modifier|*
name|f_warn
decl_stmt|;
comment|/* warning message */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Types.  */
end_comment

begin_define
define|#
directive|define
name|NORMAL
value|1
end_define

begin_define
define|#
directive|define
name|INVISIBLE
value|2
end_define

begin_define
define|#
directive|define
name|PROFILING
value|3
end_define

begin_define
define|#
directive|define
name|NODEPEND
value|4
end_define

begin_define
define|#
directive|define
name|LOCAL
value|5
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
name|device
block|{
name|int
name|d_type
decl_stmt|;
comment|/* DEVICE, bus adaptor */
name|char
modifier|*
name|d_conn
decl_stmt|;
comment|/* what it is connected to */
name|int
name|d_connunit
decl_stmt|;
comment|/* unit of connection */
name|char
modifier|*
name|d_name
decl_stmt|;
comment|/* name of device (e.g. rk11) */
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
name|d_bus
decl_stmt|;
comment|/* controller bus number */
name|int
name|d_count
decl_stmt|;
comment|/* pseudo-device count */
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
name|d_flags
decl_stmt|;
comment|/* flags for device init */
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

begin_struct
struct|struct
name|config
block|{
name|char
modifier|*
name|s_sysname
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Config has a global notion of which machine type is  * being used.  It uses the name of the machine in choosing  * files and directories.  Thus if the name of the machine is ``i386'',  * it will build from ``Makefile.i386'' and use ``../i386/inline''  * in the makerules, etc.  */
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
name|MACHINE_I386
value|1
end_define

begin_define
define|#
directive|define
name|MACHINE_PC98
value|2
end_define

begin_define
define|#
directive|define
name|MACHINE_ALPHA
value|3
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
specifier|extern
name|char
modifier|*
name|ident
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|do_trace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|get_word
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|get_quoted_word
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|path
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|raisestr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|moveifchanged
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|init_dev
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|newbus_ioconf
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yyparse
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yylex
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|options
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|makefile
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|headers
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|device
modifier|*
name|dtab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|errbuf
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yyline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|file_list
modifier|*
name|ftab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|profiling
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|debugging
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxusers
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|char
name|srcdir
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* root of the kernel source tree */
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

begin_define
define|#
directive|define
name|ns
parameter_list|(
name|s
parameter_list|)
value|strdup(s)
end_define

end_unit

