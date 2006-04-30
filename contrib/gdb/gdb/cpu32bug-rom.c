begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Remote debugging interface for CPU32Bug Rom monitor for GDB, the GNU debugger.    Copyright 1995, 1996, 1998, 1999, 2000, 2001    Free Software Foundation, Inc.     Written by Stu Grossman of Cygnus Support     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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

begin_include
include|#
directive|include
file|"regcache.h"
end_include

begin_include
include|#
directive|include
file|"m68k-tdep.h"
end_include

begin_function_decl
specifier|static
name|void
name|cpu32bug_open
parameter_list|(
name|char
modifier|*
name|args
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|cpu32bug_supply_register
parameter_list|(
name|char
modifier|*
name|regname
parameter_list|,
name|int
name|regnamelen
parameter_list|,
name|char
modifier|*
name|val
parameter_list|,
name|int
name|vallen
parameter_list|)
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
name|M68K_D0_REGNUM
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
name|M68K_A0_REGNUM
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
comment|/*  * This array of registers needs to match the indexes used by GDB. The  * whole reason this exists is because the various ROM monitors use  * different names than GDB does, and don't support all the  * registers either. So, typing "info reg sp" becomes an "A7".  */
end_comment

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|cpu32bug_regname
parameter_list|(
name|int
name|index
parameter_list|)
block|{
specifier|static
name|char
modifier|*
name|regnames
index|[]
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
block|}
decl_stmt|;
if|if
condition|(
operator|(
name|index
operator|>=
operator|(
sizeof|sizeof
argument_list|(
name|regnames
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|regnames
index|[
literal|0
index|]
argument_list|)
operator|)
operator|)
operator|||
operator|(
name|index
operator|<
literal|0
operator|)
operator|||
operator|(
name|index
operator|>=
name|NUM_REGS
operator|)
condition|)
return|return
name|NULL
return|;
else|else
return|return
name|regnames
index|[
name|index
index|]
return|;
block|}
end_function

begin_comment
comment|/*  * Define the monitor command strings. Since these are passed directly  * through to a printf style function, we need can include formatting  * strings. We also need a CR or LF on the end.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|target_ops
name|cpu32bug_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|cpu32bug_inits
index|[]
init|=
block|{
literal|"\r"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|monitor_ops
name|cpu32bug_cmds
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|init_cpu32bug_cmds
parameter_list|(
name|void
parameter_list|)
block|{
name|cpu32bug_cmds
operator|.
name|flags
operator|=
name|MO_CLR_BREAK_USES_ADDR
expr_stmt|;
name|cpu32bug_cmds
operator|.
name|init
operator|=
name|cpu32bug_inits
expr_stmt|;
comment|/* Init strings */
name|cpu32bug_cmds
operator|.
name|cont
operator|=
literal|"g\r"
expr_stmt|;
comment|/* continue command */
name|cpu32bug_cmds
operator|.
name|step
operator|=
literal|"t\r"
expr_stmt|;
comment|/* single step */
name|cpu32bug_cmds
operator|.
name|stop
operator|=
name|NULL
expr_stmt|;
comment|/* interrupt command */
name|cpu32bug_cmds
operator|.
name|set_break
operator|=
literal|"br %x\r"
expr_stmt|;
comment|/* set a breakpoint */
name|cpu32bug_cmds
operator|.
name|clr_break
operator|=
literal|"nobr %x\r"
expr_stmt|;
comment|/* clear a breakpoint */
name|cpu32bug_cmds
operator|.
name|clr_all_break
operator|=
literal|"nobr\r"
expr_stmt|;
comment|/* clear all breakpoints */
name|cpu32bug_cmds
operator|.
name|fill
operator|=
literal|"bf %x:%x %x;b\r"
expr_stmt|;
comment|/* fill (start count val) */
name|cpu32bug_cmds
operator|.
name|setmem
operator|.
name|cmdb
operator|=
literal|"ms %x %02x\r"
expr_stmt|;
comment|/* setmem.cmdb (addr, value) */
name|cpu32bug_cmds
operator|.
name|setmem
operator|.
name|cmdw
operator|=
literal|"ms %x %04x\r"
expr_stmt|;
comment|/* setmem.cmdw (addr, value) */
name|cpu32bug_cmds
operator|.
name|setmem
operator|.
name|cmdl
operator|=
literal|"ms %x %08x\r"
expr_stmt|;
comment|/* setmem.cmdl (addr, value) */
name|cpu32bug_cmds
operator|.
name|setmem
operator|.
name|cmdll
operator|=
name|NULL
expr_stmt|;
comment|/* setmem.cmdll (addr, value) */
name|cpu32bug_cmds
operator|.
name|setmem
operator|.
name|resp_delim
operator|=
name|NULL
expr_stmt|;
comment|/* setreg.resp_delim */
name|cpu32bug_cmds
operator|.
name|setmem
operator|.
name|term
operator|=
name|NULL
expr_stmt|;
comment|/* setreg.term */
name|cpu32bug_cmds
operator|.
name|setmem
operator|.
name|term_cmd
operator|=
name|NULL
expr_stmt|;
comment|/* setreg.term_cmd */
name|cpu32bug_cmds
operator|.
name|getmem
operator|.
name|cmdb
operator|=
literal|"md %x:%x;b\r"
expr_stmt|;
comment|/* getmem.cmdb (addr, len) */
name|cpu32bug_cmds
operator|.
name|getmem
operator|.
name|cmdw
operator|=
literal|"md %x:%x;b\r"
expr_stmt|;
comment|/* getmem.cmdw (addr, len) */
name|cpu32bug_cmds
operator|.
name|getmem
operator|.
name|cmdl
operator|=
literal|"md %x:%x;b\r"
expr_stmt|;
comment|/* getmem.cmdl (addr, len) */
name|cpu32bug_cmds
operator|.
name|getmem
operator|.
name|cmdll
operator|=
name|NULL
expr_stmt|;
comment|/* getmem.cmdll (addr, len) */
name|cpu32bug_cmds
operator|.
name|getmem
operator|.
name|resp_delim
operator|=
literal|" "
expr_stmt|;
comment|/* getmem.resp_delim */
name|cpu32bug_cmds
operator|.
name|getmem
operator|.
name|term
operator|=
name|NULL
expr_stmt|;
comment|/* getmem.term */
name|cpu32bug_cmds
operator|.
name|getmem
operator|.
name|term_cmd
operator|=
name|NULL
expr_stmt|;
comment|/* getmem.term_cmd */
name|cpu32bug_cmds
operator|.
name|setreg
operator|.
name|cmd
operator|=
literal|"rs %s %x\r"
expr_stmt|;
comment|/* setreg.cmd (name, value) */
name|cpu32bug_cmds
operator|.
name|setreg
operator|.
name|resp_delim
operator|=
name|NULL
expr_stmt|;
comment|/* setreg.resp_delim */
name|cpu32bug_cmds
operator|.
name|setreg
operator|.
name|term
operator|=
name|NULL
expr_stmt|;
comment|/* setreg.term */
name|cpu32bug_cmds
operator|.
name|setreg
operator|.
name|term_cmd
operator|=
name|NULL
expr_stmt|;
comment|/* setreg.term_cmd */
name|cpu32bug_cmds
operator|.
name|getreg
operator|.
name|cmd
operator|=
literal|"rs %s\r"
expr_stmt|;
comment|/* getreg.cmd (name) */
name|cpu32bug_cmds
operator|.
name|getreg
operator|.
name|resp_delim
operator|=
literal|"="
expr_stmt|;
comment|/* getreg.resp_delim */
name|cpu32bug_cmds
operator|.
name|getreg
operator|.
name|term
operator|=
name|NULL
expr_stmt|;
comment|/* getreg.term */
name|cpu32bug_cmds
operator|.
name|getreg
operator|.
name|term_cmd
operator|=
name|NULL
expr_stmt|;
comment|/* getreg.term_cmd */
name|cpu32bug_cmds
operator|.
name|dump_registers
operator|=
literal|"rd\r"
expr_stmt|;
comment|/* dump_registers */
name|cpu32bug_cmds
operator|.
name|register_pattern
operator|=
literal|"\\(\\w+\\) +=\\([0-9a-fA-F]+\\b\\)"
expr_stmt|;
comment|/* register_pattern */
name|cpu32bug_cmds
operator|.
name|supply_register
operator|=
name|cpu32bug_supply_register
expr_stmt|;
comment|/* supply_register */
name|cpu32bug_cmds
operator|.
name|load_routine
operator|=
name|NULL
expr_stmt|;
comment|/* load_routine (defaults to SRECs) */
name|cpu32bug_cmds
operator|.
name|load
operator|=
literal|"lo\r"
expr_stmt|;
comment|/* download command */
name|cpu32bug_cmds
operator|.
name|loadresp
operator|=
literal|"\n"
expr_stmt|;
comment|/* load response */
name|cpu32bug_cmds
operator|.
name|prompt
operator|=
literal|"CPU32Bug>"
expr_stmt|;
comment|/* monitor command prompt */
name|cpu32bug_cmds
operator|.
name|line_term
operator|=
literal|"\r"
expr_stmt|;
comment|/* end-of-line terminator */
name|cpu32bug_cmds
operator|.
name|cmd_end
operator|=
name|NULL
expr_stmt|;
comment|/* optional command terminator */
name|cpu32bug_cmds
operator|.
name|target
operator|=
operator|&
name|cpu32bug_ops
expr_stmt|;
comment|/* target operations */
name|cpu32bug_cmds
operator|.
name|stopbits
operator|=
name|SERIAL_1_STOPBITS
expr_stmt|;
comment|/* number of stop bits */
name|cpu32bug_cmds
operator|.
name|regnames
operator|=
name|NULL
expr_stmt|;
comment|/* registers names */
name|cpu32bug_cmds
operator|.
name|regname
operator|=
name|cpu32bug_regname
expr_stmt|;
name|cpu32bug_cmds
operator|.
name|magic
operator|=
name|MONITOR_OPS_MAGIC
expr_stmt|;
comment|/* magic */
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* init_cpu32bug_cmds */
end_comment

begin_function
specifier|static
name|void
name|cpu32bug_open
parameter_list|(
name|char
modifier|*
name|args
parameter_list|,
name|int
name|from_tty
parameter_list|)
block|{
name|monitor_open
argument_list|(
name|args
argument_list|,
operator|&
name|cpu32bug_cmds
argument_list|,
name|from_tty
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_cpu32bug_rom
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -Wmissing-prototypes */
end_comment

begin_function
name|void
name|_initialize_cpu32bug_rom
parameter_list|(
name|void
parameter_list|)
block|{
name|init_cpu32bug_cmds
argument_list|()
expr_stmt|;
name|init_monitor_ops
argument_list|(
operator|&
name|cpu32bug_ops
argument_list|)
expr_stmt|;
name|cpu32bug_ops
operator|.
name|to_shortname
operator|=
literal|"cpu32bug"
expr_stmt|;
name|cpu32bug_ops
operator|.
name|to_longname
operator|=
literal|"CPU32Bug monitor"
expr_stmt|;
name|cpu32bug_ops
operator|.
name|to_doc
operator|=
literal|"Debug via the CPU32Bug monitor.\n\ Specify the serial device it is connected to (e.g. /dev/ttya)."
expr_stmt|;
name|cpu32bug_ops
operator|.
name|to_open
operator|=
name|cpu32bug_open
expr_stmt|;
name|add_target
argument_list|(
operator|&
name|cpu32bug_ops
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

