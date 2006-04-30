begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Remote debugging interface for Renesas HMS Monitor Version 1.0    Copyright 1995, 1996, 1998, 1999, 2000, 2001    Free Software Foundation, Inc.    Contributed by Cygnus Support.  Written by Steve Chamberlain    (sac@cygnus.com).     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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

begin_function_decl
specifier|static
name|void
name|hms_open
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
name|hms_supply_register
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
if|if
condition|(
name|regname
index|[
literal|0
index|]
operator|!=
literal|'P'
condition|)
return|return;
comment|/* We scan off all the registers in one go */
name|val
operator|=
name|monitor_supply_register
argument_list|(
name|PC_REGNUM
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Skip the ccr string */
while|while
condition|(
operator|*
name|val
operator|!=
literal|'='
operator|&&
operator|*
name|val
condition|)
name|val
operator|++
expr_stmt|;
name|val
operator|=
name|monitor_supply_register
argument_list|(
name|CCR_REGNUM
argument_list|,
name|val
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|/* Skip up to rest of regs */
while|while
condition|(
operator|*
name|val
operator|!=
literal|'='
operator|&&
operator|*
name|val
condition|)
name|val
operator|++
expr_stmt|;
for|for
control|(
name|regno
operator|=
literal|0
init|;
name|regno
operator|<
literal|7
condition|;
name|regno
operator|++
control|)
block|{
name|val
operator|=
name|monitor_supply_register
argument_list|(
name|regno
argument_list|,
name|val
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * This array of registers needs to match the indexes used by GDB. The  * whole reason this exists is because the various ROM monitors use  * different names than GDB does, and don't support all the  * registers either. So, typing "info reg sp" becomes a "r30".  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hms_regnames
index|[]
init|=
block|{
literal|"R0"
block|,
literal|"R1"
block|,
literal|"R2"
block|,
literal|"R3"
block|,
literal|"R4"
block|,
literal|"R5"
block|,
literal|"R6"
block|,
literal|"R7"
block|,
literal|"CCR"
block|,
literal|"PC"
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Define the monitor command strings. Since these are passed directly  * through to a printf style function, we need can include formatting  * strings. We also need a CR or LF on the end.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|target_ops
name|hms_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|hms_inits
index|[]
init|=
block|{
literal|"\003"
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
name|hms_cmds
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|init_hms_cmds
parameter_list|(
name|void
parameter_list|)
block|{
name|hms_cmds
operator|.
name|flags
operator|=
name|MO_CLR_BREAK_USES_ADDR
operator||
name|MO_FILL_USES_ADDR
operator||
name|MO_GETMEM_NEEDS_RANGE
expr_stmt|;
name|hms_cmds
operator|.
name|init
operator|=
name|hms_inits
expr_stmt|;
comment|/* Init strings */
name|hms_cmds
operator|.
name|cont
operator|=
literal|"g\r"
expr_stmt|;
comment|/* continue command */
name|hms_cmds
operator|.
name|step
operator|=
literal|"s\r"
expr_stmt|;
comment|/* single step */
name|hms_cmds
operator|.
name|stop
operator|=
literal|"\003"
expr_stmt|;
comment|/* ^C interrupts the program */
name|hms_cmds
operator|.
name|set_break
operator|=
literal|"b %x\r"
expr_stmt|;
comment|/* set a breakpoint */
name|hms_cmds
operator|.
name|clr_break
operator|=
literal|"b - %x\r"
expr_stmt|;
comment|/* clear a breakpoint */
name|hms_cmds
operator|.
name|clr_all_break
operator|=
literal|"b -\r"
expr_stmt|;
comment|/* clear all breakpoints */
name|hms_cmds
operator|.
name|fill
operator|=
literal|"f %x %x %x\r"
expr_stmt|;
comment|/* fill (start end val) */
name|hms_cmds
operator|.
name|setmem
operator|.
name|cmdb
operator|=
literal|"m.b %x=%x\r"
expr_stmt|;
comment|/* setmem.cmdb (addr, value) */
name|hms_cmds
operator|.
name|setmem
operator|.
name|cmdw
operator|=
literal|"m.w %x=%x\r"
expr_stmt|;
comment|/* setmem.cmdw (addr, value) */
name|hms_cmds
operator|.
name|setmem
operator|.
name|cmdl
operator|=
name|NULL
expr_stmt|;
comment|/* setmem.cmdl (addr, value) */
name|hms_cmds
operator|.
name|setmem
operator|.
name|cmdll
operator|=
name|NULL
expr_stmt|;
comment|/* setmem.cmdll (addr, value) */
name|hms_cmds
operator|.
name|setmem
operator|.
name|resp_delim
operator|=
name|NULL
expr_stmt|;
comment|/* setreg.resp_delim */
name|hms_cmds
operator|.
name|setmem
operator|.
name|term
operator|=
name|NULL
expr_stmt|;
comment|/* setreg.term */
name|hms_cmds
operator|.
name|setmem
operator|.
name|term_cmd
operator|=
name|NULL
expr_stmt|;
comment|/* setreg.term_cmd */
name|hms_cmds
operator|.
name|getmem
operator|.
name|cmdb
operator|=
literal|"m.b %x %x\r"
expr_stmt|;
comment|/* getmem.cmdb (addr, addr) */
name|hms_cmds
operator|.
name|getmem
operator|.
name|cmdw
operator|=
literal|"m.w %x %x\r"
expr_stmt|;
comment|/* getmem.cmdw (addr, addr) */
name|hms_cmds
operator|.
name|getmem
operator|.
name|cmdl
operator|=
name|NULL
expr_stmt|;
comment|/* getmem.cmdl (addr, addr) */
name|hms_cmds
operator|.
name|getmem
operator|.
name|cmdll
operator|=
name|NULL
expr_stmt|;
comment|/* getmem.cmdll (addr, addr) */
name|hms_cmds
operator|.
name|getmem
operator|.
name|resp_delim
operator|=
literal|": "
expr_stmt|;
comment|/* getmem.resp_delim */
name|hms_cmds
operator|.
name|getmem
operator|.
name|term
operator|=
literal|">"
expr_stmt|;
comment|/* getmem.term */
name|hms_cmds
operator|.
name|getmem
operator|.
name|term_cmd
operator|=
literal|"\003"
expr_stmt|;
comment|/* getmem.term_cmd */
name|hms_cmds
operator|.
name|setreg
operator|.
name|cmd
operator|=
literal|"r %s=%x\r"
expr_stmt|;
comment|/* setreg.cmd (name, value) */
name|hms_cmds
operator|.
name|setreg
operator|.
name|resp_delim
operator|=
name|NULL
expr_stmt|;
comment|/* setreg.resp_delim */
name|hms_cmds
operator|.
name|setreg
operator|.
name|term
operator|=
name|NULL
expr_stmt|;
comment|/* setreg.term */
name|hms_cmds
operator|.
name|setreg
operator|.
name|term_cmd
operator|=
name|NULL
expr_stmt|;
comment|/* setreg.term_cmd */
name|hms_cmds
operator|.
name|getreg
operator|.
name|cmd
operator|=
literal|"r %s\r"
expr_stmt|;
comment|/* getreg.cmd (name) */
name|hms_cmds
operator|.
name|getreg
operator|.
name|resp_delim
operator|=
literal|" ("
expr_stmt|;
comment|/* getreg.resp_delim */
name|hms_cmds
operator|.
name|getreg
operator|.
name|term
operator|=
literal|":"
expr_stmt|;
comment|/* getreg.term */
name|hms_cmds
operator|.
name|getreg
operator|.
name|term_cmd
operator|=
literal|"\003"
expr_stmt|;
comment|/* getreg.term_cmd */
name|hms_cmds
operator|.
name|dump_registers
operator|=
literal|"r\r"
expr_stmt|;
comment|/* dump_registers */
name|hms_cmds
operator|.
name|register_pattern
operator|=
literal|"\\(\\w+\\)=\\([0-9a-fA-F]+\\)"
expr_stmt|;
comment|/* register_pattern */
name|hms_cmds
operator|.
name|supply_register
operator|=
name|hms_supply_register
expr_stmt|;
comment|/* supply_register */
name|hms_cmds
operator|.
name|load_routine
operator|=
name|NULL
expr_stmt|;
comment|/* load_routine (defaults to SRECs) */
name|hms_cmds
operator|.
name|load
operator|=
literal|"tl\r"
expr_stmt|;
comment|/* download command */
name|hms_cmds
operator|.
name|loadresp
operator|=
name|NULL
expr_stmt|;
comment|/* load response */
name|hms_cmds
operator|.
name|prompt
operator|=
literal|">"
expr_stmt|;
comment|/* monitor command prompt */
name|hms_cmds
operator|.
name|line_term
operator|=
literal|"\r"
expr_stmt|;
comment|/* end-of-command delimitor */
name|hms_cmds
operator|.
name|cmd_end
operator|=
name|NULL
expr_stmt|;
comment|/* optional command terminator */
name|hms_cmds
operator|.
name|target
operator|=
operator|&
name|hms_ops
expr_stmt|;
comment|/* target operations */
name|hms_cmds
operator|.
name|stopbits
operator|=
name|SERIAL_1_STOPBITS
expr_stmt|;
comment|/* number of stop bits */
name|hms_cmds
operator|.
name|regnames
operator|=
name|hms_regnames
expr_stmt|;
comment|/* registers names */
name|hms_cmds
operator|.
name|magic
operator|=
name|MONITOR_OPS_MAGIC
expr_stmt|;
comment|/* magic */
block|}
end_function

begin_comment
comment|/* init_hms-cmds */
end_comment

begin_function
specifier|static
name|void
name|hms_open
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
name|hms_cmds
argument_list|,
name|from_tty
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|int
name|write_dos_tick_delay
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|initialize_file_ftype
name|_initialize_remote_hms
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -Wmissing-prototypes */
end_comment

begin_function
name|void
name|_initialize_remote_hms
parameter_list|(
name|void
parameter_list|)
block|{
name|init_hms_cmds
argument_list|()
expr_stmt|;
name|init_monitor_ops
argument_list|(
operator|&
name|hms_ops
argument_list|)
expr_stmt|;
name|hms_ops
operator|.
name|to_shortname
operator|=
literal|"hms"
expr_stmt|;
name|hms_ops
operator|.
name|to_longname
operator|=
literal|"Renesas Microsystems H8/300 debug monitor"
expr_stmt|;
name|hms_ops
operator|.
name|to_doc
operator|=
literal|"Debug via the HMS monitor.\n\ Specify the serial device it is connected to (e.g. /dev/ttya)."
expr_stmt|;
name|hms_ops
operator|.
name|to_open
operator|=
name|hms_open
expr_stmt|;
comment|/* By trial and error I've found that this delay doesn't break things */
name|write_dos_tick_delay
operator|=
literal|1
expr_stmt|;
name|add_target
argument_list|(
operator|&
name|hms_ops
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

