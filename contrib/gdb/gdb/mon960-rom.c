begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Remote target glue for the Intel 960 ROM monitor.    Copyright 1995, 1996 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|"srec.h"
end_include

begin_include
include|#
directive|include
file|"xmodem.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_TERMIOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_TERMIO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SGTTY
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SGTTY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SGTTY
end_ifdef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Needed by file.h on Sys V */
end_comment

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_define
define|#
directive|define
name|USE_GENERIC_LOAD
end_define

begin_decl_stmt
name|int
name|quiet
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 => stifle unnecessary messages */
end_comment

begin_decl_stmt
name|serial_t
name|mon960_serial
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mon960_ttyname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of tty to talk to mon960 on, or null */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|monitor_ops
name|mon960_cmds
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_GENERIC_LOAD
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|generic_load
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|filename
operator|,
name|int
name|from_tty
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|void
name|mon960_open
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

begin_ifdef
ifdef|#
directive|ifdef
name|USE_GENERIC_LOAD
end_ifdef

begin_function
specifier|static
name|void
name|mon960_load_gen
parameter_list|(
name|filename
parameter_list|,
name|from_tty
parameter_list|)
name|char
modifier|*
name|filename
decl_stmt|;
name|int
name|from_tty
decl_stmt|;
block|{
specifier|extern
name|int
name|inferior_pid
decl_stmt|;
name|generic_load
argument_list|(
name|filename
argument_list|,
name|from_tty
argument_list|)
expr_stmt|;
comment|/* Finally, make the PC point at the start address */
if|if
condition|(
name|exec_bfd
condition|)
name|write_pc
argument_list|(
name|bfd_get_start_address
argument_list|(
name|exec_bfd
argument_list|)
argument_list|)
expr_stmt|;
name|inferior_pid
operator|=
literal|0
expr_stmt|;
comment|/* No process now */
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|void
name|mon960_load
parameter_list|(
name|desc
parameter_list|,
name|file
parameter_list|,
name|hashmark
parameter_list|)
name|serial_t
name|desc
decl_stmt|;
name|char
modifier|*
name|file
decl_stmt|;
name|int
name|hashmark
decl_stmt|;
block|{
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|asection
modifier|*
name|s
decl_stmt|;
name|char
modifier|*
name|buffer
decl_stmt|;
name|int
name|i
decl_stmt|;
name|buffer
operator|=
name|alloca
argument_list|(
name|XMODEM_PACKETSIZE
argument_list|)
expr_stmt|;
name|abfd
operator|=
name|bfd_openr
argument_list|(
name|file
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|abfd
condition|)
block|{
name|printf_filtered
argument_list|(
literal|"Unable to open file %s\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|bfd_check_format
argument_list|(
name|abfd
argument_list|,
name|bfd_object
argument_list|)
operator|==
literal|0
condition|)
block|{
name|printf_filtered
argument_list|(
literal|"File is not an object file\n"
argument_list|)
expr_stmt|;
return|return;
block|}
for|for
control|(
name|s
operator|=
name|abfd
operator|->
name|sections
init|;
name|s
condition|;
name|s
operator|=
name|s
operator|->
name|next
control|)
if|if
condition|(
name|s
operator|->
name|flags
operator|&
name|SEC_LOAD
condition|)
block|{
name|bfd_size_type
name|section_size
decl_stmt|;
name|printf_filtered
argument_list|(
literal|"%s\t: 0x%4x .. 0x%4x  "
argument_list|,
name|s
operator|->
name|name
argument_list|,
name|s
operator|->
name|vma
argument_list|,
name|s
operator|->
name|vma
operator|+
name|s
operator|->
name|_raw_size
argument_list|)
expr_stmt|;
name|gdb_flush
argument_list|(
name|gdb_stdout
argument_list|)
expr_stmt|;
name|monitor_printf
argument_list|(
name|mon960_cmds
operator|.
name|load
argument_list|,
name|s
operator|->
name|vma
argument_list|)
expr_stmt|;
if|if
condition|(
name|mon960_cmds
operator|.
name|loadresp
condition|)
name|monitor_expect
argument_list|(
name|mon960_cmds
operator|.
name|loadresp
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|xmodem_init_xfer
argument_list|(
name|desc
argument_list|)
expr_stmt|;
name|section_size
operator|=
name|bfd_section_size
argument_list|(
name|abfd
argument_list|,
name|s
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|section_size
condition|;
name|i
operator|+=
name|XMODEM_DATASIZE
control|)
block|{
name|int
name|numbytes
decl_stmt|;
name|numbytes
operator|=
name|min
argument_list|(
name|XMODEM_DATASIZE
argument_list|,
name|section_size
operator|-
name|i
argument_list|)
expr_stmt|;
name|bfd_get_section_contents
argument_list|(
name|abfd
argument_list|,
name|s
argument_list|,
name|buffer
operator|+
name|XMODEM_DATAOFFSET
argument_list|,
name|i
argument_list|,
name|numbytes
argument_list|)
expr_stmt|;
name|xmodem_send_packet
argument_list|(
name|desc
argument_list|,
name|buffer
argument_list|,
name|numbytes
argument_list|,
name|hashmark
argument_list|)
expr_stmt|;
if|if
condition|(
name|hashmark
condition|)
block|{
name|putchar_unfiltered
argument_list|(
literal|'#'
argument_list|)
expr_stmt|;
name|gdb_flush
argument_list|(
name|gdb_stdout
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* Per-packet (or S-record) loop */
name|xmodem_finish_xfer
argument_list|(
name|desc
argument_list|)
expr_stmt|;
name|monitor_expect_prompt
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|putchar_unfiltered
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
comment|/* Loadable sections */
if|if
condition|(
name|hashmark
condition|)
name|putchar_unfiltered
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This array of registers need to match the indexes used by GDB.    This exists because the various ROM monitors use different strings    than does GDB, and don't necessarily support all the registers    either. So, typing "info reg sp" becomes a "r30".  */
end_comment

begin_comment
comment|/* these correspond to the offsets from tm-* files from config directories */
end_comment

begin_comment
comment|/* g0-g14, fp, pfp, sp, rip,r3-15, pc, ac, tc, fp0-3 */
end_comment

begin_comment
comment|/* NOTE: "ip" is documented as "ir" in the Mon960 UG. */
end_comment

begin_comment
comment|/* NOTE: "ir" can't be accessed... but there's an ip and rip. */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|mon960_regnames
index|[
name|NUM_REGS
index|]
init|=
block|{
comment|/*  0 */
literal|"pfp"
block|,
literal|"sp"
block|,
literal|"rip"
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
block|, \
comment|/*  8 */
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
block|,\
comment|/* 16 */
literal|"g0"
block|,
literal|"g1"
block|,
literal|"g2"
block|,
literal|"g3"
block|,
literal|"g4"
block|,
literal|"g5"
block|,
literal|"g6"
block|,
literal|"g7"
block|, \
comment|/* 24 */
literal|"g8"
block|,
literal|"g9"
block|,
literal|"g10"
block|,
literal|"g11"
block|,
literal|"g12"
block|,
literal|"g13"
block|,
literal|"g14"
block|,
literal|"fp"
block|, \
comment|/* 32 */
literal|"pc"
block|,
literal|"ac"
block|,
literal|"tc"
block|,
literal|"ip"
block|,
literal|"fp0"
block|,
literal|"fp1"
block|,
literal|"fp2"
block|,
literal|"fp3"
block|,\   }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define the monitor command strings. Since these are passed directly    through to a printf style function, we may include formatting    strings. We also need a CR or LF on the end.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|target_ops
name|mon960_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* need to pause the monitor for timing reasons, so slow it down */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|mon960_inits
index|[]
init|=
block|{
literal|"\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n\r\n\r\n"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Exits sub-command mode& download cmds */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|monitor_ops
name|mon960_cmds
init|=
block|{
name|MO_CLR_BREAK_USES_ADDR
operator||
name|MO_NO_ECHO_ON_OPEN
operator||
name|MO_SEND_BREAK_ON_STOP
operator||
name|MO_GETMEM_READ_SINGLE
block|,
comment|/* flags */
name|mon960_inits
block|,
comment|/* Init strings */
literal|"go\n\r"
block|,
comment|/* continue command */
literal|"st\n\r"
block|,
comment|/* single step */
literal|"\n\r"
block|,
comment|/* break interrupts the program */
name|NULL
block|,
comment|/* set a breakpoint */
comment|/* can't use "br" because only 2 hw bps are supported */
name|NULL
block|,
comment|/* clear a breakpoint - "de" is for hw bps */
name|NULL
block|,
comment|/* clear all breakpoints */
name|NULL
block|,
comment|/* fill (start end val) */
comment|/* can't use "fi" because it takes words, not bytes */
block|{
comment|/* can't use "mb", "md" or "mo" because they require interaction */
name|NULL
block|,
comment|/* setmem.cmdb (addr, value) */
literal|"md %x %x\n\r"
block|,
comment|/* setmem.cmdw (addr, value) */
name|NULL
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
block|{
comment|/* since the parsing of multiple bytes is difficult due to        interspersed addresses, we'll only read 1 value at a time,         even tho these can handle a count */
literal|"db %x\n\r"
block|,
comment|/* getmem.cmdb (addr, #bytes) */
literal|"ds %x\n\r"
block|,
comment|/* getmem.cmdw (addr, #swords) */
literal|"di %x\n\r"
block|,
comment|/* getmem.cmdl (addr, #words) */
literal|"dd %x\n\r"
block|,
comment|/* getmem.cmdll (addr, #dwords) */
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
block|{
literal|"md %s %x\n\r"
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
literal|"di %s\n\r"
block|,
comment|/* getreg.cmd (name) */
literal|" : "
block|,
comment|/* getreg.resp_delim */
name|NULL
block|,
comment|/* getreg.term */
name|NULL
block|,
comment|/* getreg.term_cmd */
block|}
block|,
literal|"re\n\r"
block|,
comment|/* dump_registers */
literal|"\\(\\w+\\)=\\([0-9a-fA-F]+\\)"
block|,
comment|/* register_pattern */
name|NULL
block|,
comment|/* supply_register */
ifdef|#
directive|ifdef
name|USE_GENERIC_LOAD
name|NULL
block|,
comment|/* load_routine (defaults to SRECs) */
name|NULL
block|,
comment|/* download command */
name|NULL
block|,
comment|/* load response */
else|#
directive|else
name|mon960_load
block|,
comment|/* load_routine (defaults to SRECs) */
literal|"do\n\r"
block|,
comment|/* download command */
literal|"Downloading\n\r"
block|,
comment|/* load response */
endif|#
directive|endif
literal|"=>"
block|,
comment|/* monitor command prompt */
literal|"\n\r"
block|,
comment|/* end-of-command delimitor */
name|NULL
block|,
comment|/* optional command terminator */
operator|&
name|mon960_ops
block|,
comment|/* target operations */
name|SERIAL_1_STOPBITS
block|,
comment|/* number of stop bits */
name|mon960_regnames
block|,
comment|/* registers names */
name|MONITOR_OPS_MAGIC
comment|/* magic */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* invoked from monitor.c - opens the serial port */
end_comment

begin_function
specifier|static
name|void
name|mon960_open
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
name|char
modifier|*
name|serial_port_name
init|=
name|args
decl_stmt|;
if|if
condition|(
name|args
condition|)
block|{
name|char
modifier|*
name|cursor
init|=
name|serial_port_name
operator|=
name|strsave
argument_list|(
name|args
argument_list|)
decl_stmt|;
while|while
condition|(
operator|*
name|cursor
operator|&&
operator|*
name|cursor
operator|!=
literal|' '
condition|)
name|cursor
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|cursor
condition|)
operator|*
name|cursor
operator|++
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|*
name|cursor
operator|==
literal|' '
condition|)
name|cursor
operator|++
expr_stmt|;
block|}
name|monitor_open
argument_list|(
name|serial_port_name
argument_list|,
operator|&
name|mon960_cmds
argument_list|,
name|from_tty
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|_initialize_mon960
parameter_list|()
block|{
name|init_monitor_ops
argument_list|(
operator|&
name|mon960_ops
argument_list|)
expr_stmt|;
name|mon960_ops
operator|.
name|to_shortname
operator|=
literal|"mon960"
expr_stmt|;
comment|/* for the target command */
name|mon960_ops
operator|.
name|to_longname
operator|=
literal|"Intel 960 rom monitor"
expr_stmt|;
ifdef|#
directive|ifdef
name|USE_GENERIC_LOAD
name|mon960_ops
operator|.
name|to_load
operator|=
name|mon960_load_gen
expr_stmt|;
comment|/* FIXME - should go back and try "do" */
endif|#
directive|endif
comment|/* use SW breaks; target only supports 2 HW breakpoints */
name|mon960_ops
operator|.
name|to_insert_breakpoint
operator|=
name|memory_insert_breakpoint
expr_stmt|;
name|mon960_ops
operator|.
name|to_remove_breakpoint
operator|=
name|memory_remove_breakpoint
expr_stmt|;
name|mon960_ops
operator|.
name|to_doc
operator|=
literal|"Debug on an Intel 960 eval board running the Mon960 rom monitor.\n"
literal|"Specify the serial device it is connected to (e.g. /dev/ttya)."
expr_stmt|;
name|mon960_ops
operator|.
name|to_open
operator|=
name|mon960_open
expr_stmt|;
name|add_target
argument_list|(
operator|&
name|mon960_ops
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

