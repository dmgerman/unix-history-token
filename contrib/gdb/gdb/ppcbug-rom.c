begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Remote debugging interface for PPCbug (PowerPC) Rom monitor    for GDB, the GNU debugger.    Copyright 1995 Free Software Foundation, Inc.     Written by Stu Grossman of Cygnus Support  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|ppcbug_open
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
name|ppcbug_supply_register
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
init|=
literal|0
decl_stmt|,
name|base
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|regnamelen
operator|<
literal|2
operator|||
name|regnamelen
operator|>
literal|4
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
literal|'R'
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
literal|'9'
condition|)
return|return;
if|if
condition|(
name|regnamelen
operator|==
literal|2
condition|)
name|regno
operator|=
name|regname
index|[
literal|1
index|]
operator|-
literal|'0'
expr_stmt|;
elseif|else
if|if
condition|(
name|regnamelen
operator|==
literal|3
operator|&&
name|regname
index|[
literal|2
index|]
operator|>=
literal|'0'
operator|&&
name|regname
index|[
literal|2
index|]
operator|<=
literal|'9'
condition|)
name|regno
operator|=
operator|(
name|regname
index|[
literal|1
index|]
operator|-
literal|'0'
operator|)
operator|*
literal|10
operator|+
operator|(
name|regname
index|[
literal|2
index|]
operator|-
literal|'0'
operator|)
expr_stmt|;
else|else
return|return;
break|break;
case|case
literal|'F'
case|:
if|if
condition|(
name|regname
index|[
literal|1
index|]
operator|!=
literal|'R'
operator|||
name|regname
index|[
literal|2
index|]
operator|<
literal|'0'
operator|||
name|regname
index|[
literal|2
index|]
operator|>
literal|'9'
condition|)
return|return;
if|if
condition|(
name|regnamelen
operator|==
literal|3
condition|)
name|regno
operator|=
literal|32
operator|+
name|regname
index|[
literal|2
index|]
operator|-
literal|'0'
expr_stmt|;
elseif|else
if|if
condition|(
name|regnamelen
operator|==
literal|4
operator|&&
name|regname
index|[
literal|3
index|]
operator|>=
literal|'0'
operator|&&
name|regname
index|[
literal|3
index|]
operator|<=
literal|'9'
condition|)
name|regno
operator|=
literal|32
operator|+
operator|(
name|regname
index|[
literal|2
index|]
operator|-
literal|'0'
operator|)
operator|*
literal|10
operator|+
operator|(
name|regname
index|[
literal|3
index|]
operator|-
literal|'0'
operator|)
expr_stmt|;
else|else
return|return;
break|break;
case|case
literal|'I'
case|:
if|if
condition|(
name|regnamelen
operator|!=
literal|2
operator|||
name|regname
index|[
literal|1
index|]
operator|!=
literal|'P'
condition|)
return|return;
name|regno
operator|=
literal|64
expr_stmt|;
break|break;
case|case
literal|'M'
case|:
if|if
condition|(
name|regnamelen
operator|!=
literal|3
operator|||
name|regname
index|[
literal|1
index|]
operator|!=
literal|'S'
operator|||
name|regname
index|[
literal|2
index|]
operator|!=
literal|'R'
condition|)
return|return;
name|regno
operator|=
literal|65
expr_stmt|;
break|break;
case|case
literal|'C'
case|:
if|if
condition|(
name|regnamelen
operator|!=
literal|2
operator|||
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
literal|66
expr_stmt|;
break|break;
case|case
literal|'S'
case|:
if|if
condition|(
name|regnamelen
operator|!=
literal|4
operator|||
name|regname
index|[
literal|1
index|]
operator|!=
literal|'P'
operator|||
name|regname
index|[
literal|2
index|]
operator|!=
literal|'R'
condition|)
return|return;
elseif|else
if|if
condition|(
name|regname
index|[
literal|3
index|]
operator|==
literal|'8'
condition|)
name|regno
operator|=
literal|67
expr_stmt|;
elseif|else
if|if
condition|(
name|regname
index|[
literal|3
index|]
operator|==
literal|'9'
condition|)
name|regno
operator|=
literal|68
expr_stmt|;
elseif|else
if|if
condition|(
name|regname
index|[
literal|3
index|]
operator|==
literal|'1'
condition|)
name|regno
operator|=
literal|69
expr_stmt|;
elseif|else
if|if
condition|(
name|regname
index|[
literal|3
index|]
operator|==
literal|'0'
condition|)
name|regno
operator|=
literal|70
expr_stmt|;
else|else
return|return;
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

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ppcbug_regnames
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
literal|"fr0"
block|,
literal|"fr1"
block|,
literal|"fr2"
block|,
literal|"fr3"
block|,
literal|"fr4"
block|,
literal|"fr5"
block|,
literal|"fr6"
block|,
literal|"fr7"
block|,
literal|"fr8"
block|,
literal|"fr9"
block|,
literal|"fr10"
block|,
literal|"fr11"
block|,
literal|"fr12"
block|,
literal|"fr13"
block|,
literal|"fr14"
block|,
literal|"fr15"
block|,
literal|"fr16"
block|,
literal|"fr17"
block|,
literal|"fr18"
block|,
literal|"fr19"
block|,
literal|"fr20"
block|,
literal|"fr21"
block|,
literal|"fr22"
block|,
literal|"fr23"
block|,
literal|"fr24"
block|,
literal|"fr25"
block|,
literal|"fr26"
block|,
literal|"fr27"
block|,
literal|"fr28"
block|,
literal|"fr29"
block|,
literal|"fr30"
block|,
literal|"fr31"
block|,
comment|/* pc      ps      cnd     lr      cnt     xer     mq */
literal|"ip"
block|,
literal|"msr"
block|,
literal|"cr"
block|,
literal|"spr8"
block|,
literal|"spr9"
block|,
literal|"spr1"
block|,
literal|"spr0"
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
name|ppcbug_ops0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|target_ops
name|ppcbug_ops1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ppcbug_inits
index|[]
init|=
block|{
literal|"\r"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PPC_CMDS
parameter_list|(
name|LOAD_CMD
parameter_list|,
name|OPS
parameter_list|)
define|\
value|{									\   MO_CLR_BREAK_USES_ADDR | MO_HANDLE_NL,				\   ppcbug_inits,
comment|/* Init strings */
value|\   "g\r",
comment|/* continue command */
value|\   "t\r",
comment|/* single step */
value|\   NULL,
comment|/* interrupt command */
value|\   "br %x\r",
comment|/* set a breakpoint */
value|\   "nobr %x\r",
comment|/* clear a breakpoint */
value|\   "nobr\r",
comment|/* clear all breakpoints */
value|\   "bf %x:%x %x;b\r",
comment|/* fill (start count val) */
value|\   {									\     "ms %x %02x\r",
comment|/* setmem.cmdb (addr, value) */
value|\     "ms %x %04x\r",
comment|/* setmem.cmdw (addr, value) */
value|\     "ms %x %08x\r",
comment|/* setmem.cmdl (addr, value) */
value|\     NULL,
comment|/* setmem.cmdll (addr, value) */
value|\     NULL,
comment|/* setreg.resp_delim */
value|\     NULL,
comment|/* setreg.term */
value|\     NULL,
comment|/* setreg.term_cmd */
value|\   },									\   {									\     "md %x:%x;b\r",
comment|/* getmem.cmdb (addr, len) */
value|\     "md %x:%x;b\r",
comment|/* getmem.cmdw (addr, len) */
value|\     "md %x:%x;b\r",
comment|/* getmem.cmdl (addr, len) */
value|\     NULL,
comment|/* getmem.cmdll (addr, len) */
value|\     " ",
comment|/* getmem.resp_delim */
value|\     NULL,
comment|/* getmem.term */
value|\     NULL,
comment|/* getmem.term_cmd */
value|\   },									\   {									\     "rs %s %x\r",
comment|/* setreg.cmd (name, value) */
value|\     NULL,
comment|/* setreg.resp_delim */
value|\     NULL,
comment|/* setreg.term */
value|\     NULL
comment|/* setreg.term_cmd */
value|\   },									\   {									\     "rs %s\r",
comment|/* getreg.cmd (name) */
value|\     "=",
comment|/* getreg.resp_delim */
value|\     NULL,
comment|/* getreg.term */
value|\     NULL
comment|/* getreg.term_cmd */
value|\   },									\   "rd\r",
comment|/* dump_registers */
value|\   "\\(\\w+\\) +=\\([0-9a-fA-F]+\\b\\)",
comment|/* register_pattern */
value|\   ppcbug_supply_register,
comment|/* supply_register */
value|\   NULL,
comment|/* load_routine (defaults to SRECs) */
value|\   LOAD_CMD,
comment|/* download command */
value|\   NULL,
comment|/* load response */
value|\   "PPC1-Bug>",
comment|/* monitor command prompt */
value|\   "\r",
comment|/* end-of-line terminator */
value|\   NULL,
comment|/* optional command terminator */
value|\&OPS,
comment|/* target operations */
value|\   SERIAL_1_STOPBITS,
comment|/* number of stop bits */
value|\   ppcbug_regnames,
comment|/* registers names */
value|\   MONITOR_OPS_MAGIC
comment|/* magic */
value|\ }
end_define

begin_decl_stmt
specifier|static
name|struct
name|monitor_ops
name|ppcbug_cmds0
init|=
name|PPC_CMDS
argument_list|(
literal|"lo 0\r"
argument_list|,
name|ppcbug_ops0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|monitor_ops
name|ppcbug_cmds1
init|=
name|PPC_CMDS
argument_list|(
literal|"lo 1\r"
argument_list|,
name|ppcbug_ops1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|ppcbug_open0
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
name|ppcbug_cmds0
argument_list|,
name|from_tty
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|ppcbug_open1
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
name|ppcbug_cmds1
argument_list|,
name|from_tty
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|_initialize_ppcbug_rom
parameter_list|()
block|{
name|init_monitor_ops
argument_list|(
operator|&
name|ppcbug_ops0
argument_list|)
expr_stmt|;
name|ppcbug_ops0
operator|.
name|to_shortname
operator|=
literal|"ppcbug"
expr_stmt|;
name|ppcbug_ops0
operator|.
name|to_longname
operator|=
literal|"PowerPC PPCBug monitor on port 0"
expr_stmt|;
name|ppcbug_ops0
operator|.
name|to_doc
operator|=
literal|"Debug via the PowerPC PPCBug monitor using port 0.\n\ Specify the serial device it is connected to (e.g. /dev/ttya)."
expr_stmt|;
name|ppcbug_ops0
operator|.
name|to_open
operator|=
name|ppcbug_open0
expr_stmt|;
name|add_target
argument_list|(
operator|&
name|ppcbug_ops0
argument_list|)
expr_stmt|;
name|init_monitor_ops
argument_list|(
operator|&
name|ppcbug_ops1
argument_list|)
expr_stmt|;
name|ppcbug_ops1
operator|.
name|to_shortname
operator|=
literal|"ppcbug1"
expr_stmt|;
name|ppcbug_ops1
operator|.
name|to_longname
operator|=
literal|"PowerPC PPCBug monitor on port 1"
expr_stmt|;
name|ppcbug_ops1
operator|.
name|to_doc
operator|=
literal|"Debug via the PowerPC PPCBug monitor using port 1.\n\ Specify the serial device it is connected to (e.g. /dev/ttya)."
expr_stmt|;
name|ppcbug_ops1
operator|.
name|to_open
operator|=
name|ppcbug_open1
expr_stmt|;
name|add_target
argument_list|(
operator|&
name|ppcbug_ops1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

