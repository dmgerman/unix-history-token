begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Remote target glue for the Oki op50n based eval board.     Copyright 1995 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"gdbcore.h"
end_include

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_include
include|#
directive|include
file|"monitor.h"
end_include

begin_include
include|#
directive|include
file|"serial.h"
end_include

begin_decl_stmt
specifier|static
name|void
name|op50n_open
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|args
operator|,
name|int
name|from_tty
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * this array of registers need to match the indexes used by GDB. The  * whole reason this exists is cause the various ROM monitors use  * different strings than GDB does, and doesn't support all the  * registers either. So, typing "info reg sp" becomes a "r30".  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|op50n_regnames
index|[
name|NUM_REGS
index|]
init|=
block|{
literal|"r0"
block|,
literal|"r1"
block|,
literal|"r2"
block|,
literal|"r3"
block|,
literal|"r4"
block|,
literal|"r5"
block|,
literal|"r6"
block|,
literal|"r7"
block|,
literal|"r8"
block|,
literal|"r9"
block|,
literal|"r10"
block|,
literal|"r11"
block|,
literal|"r12"
block|,
literal|"r13"
block|,
literal|"r14"
block|,
literal|"r15"
block|,
literal|"r16"
block|,
literal|"r17"
block|,
literal|"r18"
block|,
literal|"r19"
block|,
literal|"r20"
block|,
literal|"r21"
block|,
literal|"r22"
block|,
literal|"r23"
block|,
literal|"r24"
block|,
literal|"r25"
block|,
literal|"r26"
block|,
literal|"r27"
block|,
literal|"r28"
block|,
literal|"r29"
block|,
literal|"r30"
block|,
literal|"r31"
block|,
literal|"cr11"
block|,
literal|"p"
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
literal|"cr15"
block|,
literal|"cr19"
block|,
literal|"cr20"
block|,
literal|"cr21"
block|,
literal|"cr22"
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
literal|"cr0"
block|,
literal|"cr8"
block|,
literal|"cr9"
block|,
literal|"cr10"
block|,
literal|"cr12"
block|,
literal|"cr13"
block|,
literal|"cr24"
block|,
literal|"cr25"
block|,
literal|"cr26"
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Define the monitor command strings. Since these are passed directly  * through to a printf style function, we need can include formatting  * strings. We also need a CR or LF on the end.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|target_ops
name|op50n_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|op50n_inits
index|[]
init|=
block|{
literal|".\r"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|monitor_ops
name|op50n_cmds
init|=
block|{
name|MO_CLR_BREAK_USES_ADDR
comment|/*| MO_GETMEM_READ_SINGLE*/
block|,
comment|/* flags */
name|op50n_inits
block|,
comment|/* Init strings */
literal|"g\r"
block|,
comment|/* continue command */
literal|"t\r"
block|,
comment|/* single step */
literal|"\003.\r"
block|,
comment|/* Interrupt char */
literal|"b %x\r"
block|,
comment|/* set a breakpoint */
literal|"b %x,0\r"
block|,
comment|/* clear breakpoint at addr */
literal|"bx\r"
block|,
comment|/* clear all breakpoints */
literal|"fx %x s%x %x\r"
block|,
comment|/* memory fill cmd (addr, len, val) */
block|{
literal|"sx %x %x\r"
block|,
comment|/* setmem.cmdb (addr, value) */
literal|"sh %x %x\r"
block|,
comment|/* setmem.cmdw (addr, value) */
literal|"s %x %x\r"
block|,
comment|/* setmem.cmdl (addr, value) */
name|NULL
block|,
comment|/* setmem.cmdll (addr, value) */
name|NULL
block|,
comment|/* setmem.resp_delim */
name|NULL
block|,
comment|/* setmem.term */
name|NULL
block|,
comment|/* setmem.term_cmd */
block|}
block|,
if|#
directive|if
literal|0
block|{     "sx %x\r",
comment|/* getmem.cmdb (addr, len) */
block|"sh %x\r",
comment|/* getmem.cmdw (addr, len) */
block|"s %x\r",
comment|/* getmem.cmdl (addr, len) */
block|NULL,
comment|/* getmem.cmdll (addr, len) */
block|" : ",
comment|/* getmem.resp_delim */
block|" ",
comment|/* getmem.term */
block|".\r",
comment|/* getmem.term_cmd */
block|},
else|#
directive|else
block|{
literal|"dx %x s%x\r"
block|,
comment|/* getmem.cmdb (addr, len) */
name|NULL
block|,
comment|/* getmem.cmdw (addr, len) */
name|NULL
block|,
comment|/* getmem.cmdl (addr, len) */
name|NULL
block|,
comment|/* getmem.cmdll (addr, len) */
literal|" : "
block|,
comment|/* getmem.resp_delim */
name|NULL
block|,
comment|/* getmem.term */
name|NULL
block|,
comment|/* getmem.term_cmd */
block|}
block|,
endif|#
directive|endif
block|{
literal|"x %s %x\r"
block|,
comment|/* setreg.cmd (name, value) */
name|NULL
block|,
comment|/* setreg.resp_delim */
name|NULL
block|,
comment|/* setreg.term */
name|NULL
block|,
comment|/* setreg.term_cmd */
block|}
block|,
block|{
literal|"x %s\r"
block|,
comment|/* getreg.cmd (name) */
literal|"="
block|,
comment|/* getreg.resp_delim */
literal|" "
block|,
comment|/* getreg.term */
literal|".\r"
block|,
comment|/* getreg.term_cmd */
block|}
block|,
name|NULL
block|,
comment|/* dump_registers */
name|NULL
block|,
comment|/* register_pattern */
name|NULL
block|,
comment|/* supply_register */
name|NULL
block|,
comment|/* load routine */
literal|"r 0\r"
block|,
comment|/* download command */
name|NULL
block|,
comment|/* load response */
literal|"\n#"
block|,
comment|/* monitor command prompt */
literal|"\r"
block|,
comment|/* end-of-command delimitor */
name|NULL
block|,
comment|/* optional command terminator */
operator|&
name|op50n_ops
block|,
comment|/* target operations */
name|SERIAL_1_STOPBITS
block|,
comment|/* number of stop bits */
name|op50n_regnames
block|,
comment|/* register names */
name|MONITOR_OPS_MAGIC
comment|/* magic */
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|op50n_open
parameter_list|(
name|args
parameter_list|,
name|from_tty
parameter_list|)
name|char
modifier|*
name|args
decl_stmt|;
name|int
name|from_tty
decl_stmt|;
block|{
name|monitor_open
argument_list|(
name|args
argument_list|,
operator|&
name|op50n_cmds
argument_list|,
name|from_tty
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|_initialize_op50n
parameter_list|()
block|{
name|init_monitor_ops
argument_list|(
operator|&
name|op50n_ops
argument_list|)
expr_stmt|;
name|op50n_ops
operator|.
name|to_shortname
operator|=
literal|"op50n"
expr_stmt|;
name|op50n_ops
operator|.
name|to_longname
operator|=
literal|"Oki's debug monitor for the Op50n Eval board"
expr_stmt|;
name|op50n_ops
operator|.
name|to_doc
operator|=
literal|"Debug on a Oki OP50N eval board.\n\ Specify the serial device it is connected to (e.g. /dev/ttya)."
expr_stmt|;
name|op50n_ops
operator|.
name|to_open
operator|=
name|op50n_open
expr_stmt|;
name|add_target
argument_list|(
operator|&
name|op50n_ops
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

