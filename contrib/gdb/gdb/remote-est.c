begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Remote debugging interface for EST-300 ICE, for GDB    Copyright 1995 Free Software Foundation, Inc.    Contributed by Cygnus Support.     Written by Steve Chamberlain for Cygnus Support.    Re-written by Stu Grossman of Cygnus Support  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|est_open
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

begin_function
specifier|static
name|void
name|est_supply_register
parameter_list|(
name|regname
parameter_list|,
name|regnamelen
parameter_list|,
name|val
parameter_list|,
name|vallen
parameter_list|)
name|char
modifier|*
name|regname
decl_stmt|;
name|int
name|regnamelen
decl_stmt|;
name|char
modifier|*
name|val
decl_stmt|;
name|int
name|vallen
decl_stmt|;
block|{
name|int
name|regno
decl_stmt|;
if|if
condition|(
name|regnamelen
operator|!=
literal|2
condition|)
return|return;
switch|switch
condition|(
name|regname
index|[
literal|0
index|]
condition|)
block|{
case|case
literal|'S'
case|:
if|if
condition|(
name|regname
index|[
literal|1
index|]
operator|!=
literal|'R'
condition|)
return|return;
name|regno
operator|=
name|PS_REGNUM
expr_stmt|;
break|break;
case|case
literal|'P'
case|:
if|if
condition|(
name|regname
index|[
literal|1
index|]
operator|!=
literal|'C'
condition|)
return|return;
name|regno
operator|=
name|PC_REGNUM
expr_stmt|;
break|break;
case|case
literal|'D'
case|:
if|if
condition|(
name|regname
index|[
literal|1
index|]
operator|<
literal|'0'
operator|||
name|regname
index|[
literal|1
index|]
operator|>
literal|'7'
condition|)
return|return;
name|regno
operator|=
name|regname
index|[
literal|1
index|]
operator|-
literal|'0'
operator|+
name|D0_REGNUM
expr_stmt|;
break|break;
case|case
literal|'A'
case|:
if|if
condition|(
name|regname
index|[
literal|1
index|]
operator|<
literal|'0'
operator|||
name|regname
index|[
literal|1
index|]
operator|>
literal|'7'
condition|)
return|return;
name|regno
operator|=
name|regname
index|[
literal|1
index|]
operator|-
literal|'0'
operator|+
name|A0_REGNUM
expr_stmt|;
break|break;
default|default:
return|return;
block|}
name|monitor_supply_register
argument_list|(
name|regno
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * This array of registers needs to match the indexes used by GDB. The  * whole reason this exists is because the various ROM monitors use  * different names than GDB does, and don't support all the  * registers either. So, typing "info reg sp" becomes a "r30".  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|est_regnames
index|[
name|NUM_REGS
index|]
init|=
block|{
literal|"D0"
block|,
literal|"D1"
block|,
literal|"D2"
block|,
literal|"D3"
block|,
literal|"D4"
block|,
literal|"D5"
block|,
literal|"D6"
block|,
literal|"D7"
block|,
literal|"A0"
block|,
literal|"A1"
block|,
literal|"A2"
block|,
literal|"A3"
block|,
literal|"A4"
block|,
literal|"A5"
block|,
literal|"A6"
block|,
literal|"A7"
block|,
literal|"SR"
block|,
literal|"PC"
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
name|est_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|est_inits
index|[]
init|=
block|{
literal|"he\r"
block|,
comment|/* Resets the prompt, and clears repeated cmds */
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|monitor_ops
name|est_cmds
init|=
block|{
name|MO_CLR_BREAK_USES_ADDR
operator||
name|MO_FILL_USES_ADDR
operator||
name|MO_NEED_REGDUMP_AFTER_CONT
block|,
name|est_inits
block|,
comment|/* Init strings */
literal|"go\r"
block|,
comment|/* continue command */
literal|"sidr\r"
block|,
comment|/* single step */
literal|"\003"
block|,
comment|/* ^C interrupts the program */
literal|"sb %x\r"
block|,
comment|/* set a breakpoint */
literal|"rb %x\r"
block|,
comment|/* clear a breakpoint */
literal|"rb\r"
block|,
comment|/* clear all breakpoints */
literal|"bfb %x %x %x\r"
block|,
comment|/* fill (start end val) */
block|{
literal|"smb %x %x\r"
block|,
comment|/* setmem.cmdb (addr, value) */
literal|"smw %x %x\r"
block|,
comment|/* setmem.cmdw (addr, value) */
literal|"sml %x %x\r"
block|,
comment|/* setmem.cmdl (addr, value) */
name|NULL
block|,
comment|/* setmem.cmdll (addr, value) */
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
literal|"dmb %x %x\r"
block|,
comment|/* getmem.cmdb (addr, len) */
literal|"dmw %x %x\r"
block|,
comment|/* getmem.cmdw (addr, len) */
literal|"dml %x %x\r"
block|,
comment|/* getmem.cmdl (addr, len) */
name|NULL
block|,
comment|/* getmem.cmdll (addr, len) */
literal|": "
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
block|{
literal|"sr %s %x\r"
block|,
comment|/* setreg.cmd (name, value) */
name|NULL
block|,
comment|/* setreg.resp_delim */
name|NULL
block|,
comment|/* setreg.term */
name|NULL
comment|/* setreg.term_cmd */
block|}
block|,
block|{
literal|"dr %s\r"
block|,
comment|/* getreg.cmd (name) */
literal|" = "
block|,
comment|/* getreg.resp_delim */
name|NULL
block|,
comment|/* getreg.term */
name|NULL
comment|/* getreg.term_cmd */
block|}
block|,
literal|"dr\r"
block|,
comment|/* dump_registers */
literal|"\\(\\w+\\) = \\([0-9a-fA-F]+\\)"
block|,
comment|/* register_pattern */
name|est_supply_register
block|,
comment|/* supply_register */
name|NULL
block|,
comment|/* load_routine (defaults to SRECs) */
literal|"dl\r"
block|,
comment|/* download command */
literal|"+"
block|,
comment|/* load response */
literal|">BKM>"
block|,
comment|/* monitor command prompt */
literal|"\r"
block|,
comment|/* end-of-line terminator */
name|NULL
block|,
comment|/* optional command terminator */
operator|&
name|est_ops
block|,
comment|/* target operations */
name|SERIAL_1_STOPBITS
block|,
comment|/* number of stop bits */
name|est_regnames
block|,
comment|/* registers names */
name|MONITOR_OPS_MAGIC
comment|/* magic */
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|est_open
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
name|est_cmds
argument_list|,
name|from_tty
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|_initialize_est
parameter_list|()
block|{
name|init_monitor_ops
argument_list|(
operator|&
name|est_ops
argument_list|)
expr_stmt|;
name|est_ops
operator|.
name|to_shortname
operator|=
literal|"est"
expr_stmt|;
name|est_ops
operator|.
name|to_longname
operator|=
literal|"EST background debug monitor"
expr_stmt|;
name|est_ops
operator|.
name|to_doc
operator|=
literal|"Debug via the EST BDM.\n\ Specify the serial device it is connected to (e.g. /dev/ttya)."
expr_stmt|;
name|est_ops
operator|.
name|to_open
operator|=
name|est_open
expr_stmt|;
name|add_target
argument_list|(
operator|&
name|est_ops
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

