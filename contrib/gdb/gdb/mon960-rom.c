begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Remote target glue for the Intel 960 MON960 ROM monitor.    Copyright 1995, 1996 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_include
include|#
directive|include
file|"symfile.h"
end_include

begin_comment
comment|/* for generic_load */
end_comment

begin_define
define|#
directive|define
name|USE_GENERIC_LOAD
end_define

begin_decl_stmt
specifier|static
name|struct
name|target_ops
name|mon960_ops
decl_stmt|;
end_decl_stmt

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
name|current_monitor
operator|->
name|load
argument_list|,
name|s
operator|->
name|vma
argument_list|)
expr_stmt|;
if|if
condition|(
name|current_monitor
operator|->
name|loadresp
condition|)
name|monitor_expect
argument_list|(
name|current_monitor
operator|->
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
comment|/* USE_GENERIC_LOAD */
end_comment

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
name|full_regnames
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
block|,
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
block|,
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
block|,
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
block|,
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
block|,   }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|mon960_regnames
index|[
name|NUM_REGS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define the monitor command strings. Since these are passed directly    through to a printf style function, we may include formatting    strings. We also need a CR or LF on the end.  */
end_comment

begin_comment
comment|/* need to pause the monitor for timing reasons, so slow it down */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* FIXME: this extremely long init string causes MON960 to return two NAKS    instead of performing the autobaud recognition, at least when gdb    is running on GNU/Linux.  The short string below works on Linux, and on    SunOS using a tcp serial connection.  Must retest on SunOS using a    direct serial connection; if that works, get rid of the long string. */
end_comment

begin_else
unit|static char *mon960_inits[] = {"\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n\r\n\r\n", NULL};
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|char
modifier|*
name|mon960_inits
index|[]
init|=
block|{
literal|"\r"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|struct
name|monitor_ops
name|mon960_cmds
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|init_mon960_cmds
parameter_list|(
name|void
parameter_list|)
block|{
name|mon960_cmds
operator|.
name|flags
operator|=
name|MO_CLR_BREAK_USES_ADDR
operator||
name|MO_NO_ECHO_ON_OPEN
operator||
name|MO_SEND_BREAK_ON_STOP
operator||
name|MO_GETMEM_READ_SINGLE
expr_stmt|;
comment|/* flags */
name|mon960_cmds
operator|.
name|init
operator|=
name|mon960_inits
expr_stmt|;
comment|/* Init strings */
name|mon960_cmds
operator|.
name|cont
operator|=
literal|"go\n\r"
expr_stmt|;
comment|/* continue command */
name|mon960_cmds
operator|.
name|step
operator|=
literal|"st\n\r"
expr_stmt|;
comment|/* single step */
name|mon960_cmds
operator|.
name|stop
operator|=
name|NULL
expr_stmt|;
comment|/* break interrupts the program */
name|mon960_cmds
operator|.
name|set_break
operator|=
name|NULL
expr_stmt|;
comment|/* set a breakpoint */
name|mon960_cmds
operator|.
name|clr_break
operator|=
comment|/* can't use "br" because only 2 hw bps are supported */
name|mon960_cmds
operator|.
name|clr_all_break
operator|=
name|NULL
expr_stmt|;
comment|/* clear a breakpoint - "de" is for hw bps */
name|NULL
operator|,
comment|/* clear all breakpoints */
name|mon960_cmds
operator|.
name|fill
operator|=
name|NULL
expr_stmt|;
comment|/* fill (start end val) */
comment|/* can't use "fi" because it takes words, not bytes */
comment|/* can't use "mb", "md" or "mo" because they require interaction */
name|mon960_cmds
operator|.
name|setmem
operator|.
name|cmdb
operator|=
name|NULL
expr_stmt|;
comment|/* setmem.cmdb (addr, value) */
name|mon960_cmds
operator|.
name|setmem
operator|.
name|cmdw
operator|=
name|NULL
expr_stmt|;
comment|/* setmem.cmdw (addr, value) */
name|mon960_cmds
operator|.
name|setmem
operator|.
name|cmdl
operator|=
literal|"md %x %x\n\r"
expr_stmt|;
comment|/* setmem.cmdl (addr, value) */
name|mon960_cmds
operator|.
name|setmem
operator|.
name|cmdll
operator|=
name|NULL
expr_stmt|;
comment|/* setmem.cmdll (addr, value) */
name|mon960_cmds
operator|.
name|setmem
operator|.
name|resp_delim
operator|=
name|NULL
expr_stmt|;
comment|/* setmem.resp_delim */
name|mon960_cmds
operator|.
name|setmem
operator|.
name|term
operator|=
name|NULL
expr_stmt|;
comment|/* setmem.term */
name|mon960_cmds
operator|.
name|setmem
operator|.
name|term_cmd
operator|=
name|NULL
expr_stmt|;
comment|/* setmem.term_cmd */
comment|/* since the parsing of multiple bytes is difficult due to      interspersed addresses, we'll only read 1 value at a time,      even tho these can handle a count */
name|mon960_cmds
operator|.
name|getmem
operator|.
name|cmdb
operator|=
literal|"db %x\n\r"
expr_stmt|;
comment|/* getmem.cmdb (addr, #bytes) */
name|mon960_cmds
operator|.
name|getmem
operator|.
name|cmdw
operator|=
literal|"ds %x\n\r"
expr_stmt|;
comment|/* getmem.cmdw (addr, #swords) */
name|mon960_cmds
operator|.
name|getmem
operator|.
name|cmdl
operator|=
literal|"di %x\n\r"
expr_stmt|;
comment|/* getmem.cmdl (addr, #words) */
name|mon960_cmds
operator|.
name|getmem
operator|.
name|cmdll
operator|=
literal|"dd %x\n\r"
expr_stmt|;
comment|/* getmem.cmdll (addr, #dwords) */
name|mon960_cmds
operator|.
name|getmem
operator|.
name|resp_delim
operator|=
literal|" : "
expr_stmt|;
comment|/* getmem.resp_delim */
name|mon960_cmds
operator|.
name|getmem
operator|.
name|term
operator|=
name|NULL
expr_stmt|;
comment|/* getmem.term */
name|mon960_cmds
operator|.
name|getmem
operator|.
name|term_cmd
operator|=
name|NULL
expr_stmt|;
comment|/* getmem.term_cmd */
name|mon960_cmds
operator|.
name|setreg
operator|.
name|cmd
operator|=
literal|"md %s %x\n\r"
expr_stmt|;
comment|/* setreg.cmd (name, value) */
name|mon960_cmds
operator|.
name|setreg
operator|.
name|resp_delim
operator|=
name|NULL
expr_stmt|;
comment|/* setreg.resp_delim */
name|mon960_cmds
operator|.
name|setreg
operator|.
name|term
operator|=
name|NULL
expr_stmt|;
comment|/* setreg.term */
name|mon960_cmds
operator|.
name|setreg
operator|.
name|term_cmd
operator|=
name|NULL
operator|,
comment|/* setreg.term_cmd */
name|mon960_cmds
operator|.
name|getreg
operator|.
name|cmd
operator|=
literal|"di %s\n\r"
expr_stmt|;
comment|/* getreg.cmd (name) */
name|mon960_cmds
operator|.
name|getreg
operator|.
name|resp_delim
operator|=
literal|" : "
expr_stmt|;
comment|/* getreg.resp_delim */
name|mon960_cmds
operator|.
name|getreg
operator|.
name|term
operator|=
name|NULL
expr_stmt|;
comment|/* getreg.term */
name|mon960_cmds
operator|.
name|getreg
operator|.
name|term_cmd
operator|=
name|NULL
expr_stmt|;
comment|/* getreg.term_cmd */
name|mon960_cmds
operator|.
name|dump_registers
operator|=
literal|"re\n\r"
expr_stmt|;
comment|/* dump_registers */
name|mon960_cmds
operator|.
name|register_pattern
operator|=
literal|"\\(\\w+\\)=\\([0-9a-fA-F]+\\)"
expr_stmt|;
comment|/* register_pattern */
name|mon960_cmds
operator|.
name|supply_register
operator|=
name|NULL
expr_stmt|;
comment|/* supply_register */
ifdef|#
directive|ifdef
name|USE_GENERIC_LOAD
name|mon960_cmds
operator|.
name|load_routine
operator|=
name|NULL
expr_stmt|;
comment|/* load_routine (defaults to SRECs) */
name|mon960_cmds
operator|.
name|load
operator|=
name|NULL
expr_stmt|;
comment|/* download command */
name|mon960_cmds
operator|.
name|loadresp
operator|=
name|NULL
expr_stmt|;
comment|/* load response */
else|#
directive|else
name|mon960_cmds
operator|.
name|load_routine
operator|=
name|mon960_load
expr_stmt|;
comment|/* load_routine (defaults to SRECs) */
name|mon960_cmds
operator|.
name|load
operator|=
literal|"do\n\r"
expr_stmt|;
comment|/* download command */
name|mon960_cmds
operator|.
name|loadresp
operator|=
literal|"Downloading\n\r"
expr_stmt|;
comment|/* load response */
endif|#
directive|endif
name|mon960_cmds
operator|.
name|prompt
operator|=
literal|"=>"
expr_stmt|;
comment|/* monitor command prompt */
name|mon960_cmds
operator|.
name|line_term
operator|=
literal|"\n\r"
expr_stmt|;
comment|/* end-of-command delimitor */
name|mon960_cmds
operator|.
name|cmd_end
operator|=
name|NULL
expr_stmt|;
comment|/* optional command terminator */
name|mon960_cmds
operator|.
name|target
operator|=
operator|&
name|mon960_ops
expr_stmt|;
comment|/* target operations */
name|mon960_cmds
operator|.
name|stopbits
operator|=
name|SERIAL_1_STOPBITS
expr_stmt|;
comment|/* number of stop bits */
name|mon960_cmds
operator|.
name|regnames
operator|=
name|mon960_regnames
expr_stmt|;
comment|/* registers names */
name|mon960_cmds
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
name|buf
index|[
literal|64
index|]
decl_stmt|;
name|monitor_open
argument_list|(
name|args
argument_list|,
operator|&
name|mon960_cmds
argument_list|,
name|from_tty
argument_list|)
expr_stmt|;
comment|/* Attempt to fetch the value of the first floating point register (fp0).      If the monitor returns a string containing the word "Bad" we'll assume      this processor has no floating point registers, and nullify the       regnames entries that refer to FP registers.  */
name|monitor_printf
argument_list|(
name|mon960_cmds
operator|.
name|getreg
operator|.
name|cmd
argument_list|,
name|full_regnames
index|[
name|FP0_REGNUM
index|]
argument_list|)
expr_stmt|;
comment|/* di fp0 */
if|if
condition|(
name|monitor_expect_prompt
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|)
operator|!=
operator|-
literal|1
condition|)
if|if
condition|(
name|strstr
argument_list|(
name|buf
argument_list|,
literal|"Bad"
argument_list|)
operator|!=
name|NULL
condition|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
name|FP0_REGNUM
init|;
name|i
operator|<
name|FP0_REGNUM
operator|+
literal|4
condition|;
name|i
operator|++
control|)
name|mon960_regnames
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|_initialize_mon960
parameter_list|()
block|{
name|memcpy
argument_list|(
name|mon960_regnames
argument_list|,
name|full_regnames
argument_list|,
sizeof|sizeof
argument_list|(
name|full_regnames
argument_list|)
argument_list|)
expr_stmt|;
name|init_mon960_cmds
argument_list|()
expr_stmt|;
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
literal|"Intel 960 MON960 monitor"
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
literal|"Use an Intel 960 board running the MON960 debug monitor.\n\ Specify the serial device it is connected to (e.g. /dev/ttya)."
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

