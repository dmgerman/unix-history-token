begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for remote debugging interface for ROM monitors.    Copyright 1990, 1991, 1992, 1996 Free Software Foundation, Inc.    Contributed by Cygnus Support. Written by Rob Savoye for Cygnus.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"serial.h"
end_include

begin_comment
comment|/* This structure describes the strings necessary to give small command    sequences to the monitor, and parse the response.     CMD is the actual command typed at the monitor.  Usually this has    embedded sequences ala printf, which are substituted with the    arguments appropriate to that type of command.  Ie: to examine a    register, we substitute the register name for the first arg.  To    modify memory, we substitute the memory location and the new    contents for the first and second args, etc...     RESP_DELIM used to home in on the response string, and is used to    disambiguate the answer within the pile of text returned by the    monitor.  This should be a unique string that immediately precedes    the answer.  Ie: if your monitor prints out `PC: 00000001= ' in    response to asking for the PC, you should use `: ' as the    RESP_DELIM.  RESP_DELIM may be NULL if the res- ponse is going to    be ignored, or has no particular leading text.     TERM is the string that the monitor outputs to indicate that it is    idle, and waiting for input.  This is usually a prompt of some    sort.  In the previous example, it would be `= '.  It is important    that TERM really means that the monitor is idle, otherwise GDB may    try to type at it when it isn't ready for input.  This is a problem    because many monitors cannot deal with type-ahead.  TERM may be    NULL if the normal prompt is output.     TERM_CMD is used to quit out of the subcommand mode and get back to    the main prompt.  TERM_CMD may be NULL if it isn't necessary.  It    will also be ignored if TERM is NULL.  */
end_comment

begin_struct
struct|struct
name|memrw_cmd
block|{
name|char
modifier|*
name|cmdb
decl_stmt|;
comment|/* Command to send for byte read/write */
name|char
modifier|*
name|cmdw
decl_stmt|;
comment|/* Command for word (16 bit) read/write */
name|char
modifier|*
name|cmdl
decl_stmt|;
comment|/* Command for long (32 bit) read/write */
name|char
modifier|*
name|cmdll
decl_stmt|;
comment|/* Command for long long (64 bit) read/write */
name|char
modifier|*
name|resp_delim
decl_stmt|;
comment|/* String just prior to the desired value */
name|char
modifier|*
name|term
decl_stmt|;
comment|/* Terminating string to search for */
name|char
modifier|*
name|term_cmd
decl_stmt|;
comment|/* String to get out of sub-mode (if necessary) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|regrw_cmd
block|{
name|char
modifier|*
name|cmd
decl_stmt|;
comment|/* Command to send for reg read/write */
name|char
modifier|*
name|resp_delim
decl_stmt|;
comment|/* String (actually a regexp if getmem) just 				   prior to the desired value */
name|char
modifier|*
name|term
decl_stmt|;
comment|/* Terminating string to search for */
name|char
modifier|*
name|term_cmd
decl_stmt|;
comment|/* String to get out of sub-mode (if necessary) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|monitor_ops
block|{
name|int
name|flags
decl_stmt|;
comment|/* See below */
name|char
modifier|*
modifier|*
name|init
decl_stmt|;
comment|/* List of init commands.  NULL terminated. */
name|char
modifier|*
name|cont
decl_stmt|;
comment|/* continue command */
name|char
modifier|*
name|step
decl_stmt|;
comment|/* single step */
name|char
modifier|*
name|stop
decl_stmt|;
comment|/* Interrupt program string */
name|char
modifier|*
name|set_break
decl_stmt|;
comment|/* set a breakpoint. If NULL, monitor implementation 				   sets its own to_insert_breakpoint method. */
name|char
modifier|*
name|clr_break
decl_stmt|;
comment|/* clear a breakpoint */
name|char
modifier|*
name|clr_all_break
decl_stmt|;
comment|/* Clear all breakpoints */
name|char
modifier|*
name|fill
decl_stmt|;
comment|/* Memory fill cmd (addr len val) */
name|struct
name|memrw_cmd
name|setmem
decl_stmt|;
comment|/* set memory to a value */
name|struct
name|memrw_cmd
name|getmem
decl_stmt|;
comment|/* display memory */
name|struct
name|regrw_cmd
name|setreg
decl_stmt|;
comment|/* set a register */
name|struct
name|regrw_cmd
name|getreg
decl_stmt|;
comment|/* get a register */
comment|/* Some commands can dump a bunch of registers        at once.  This comes as a set of REG=VAL        pairs.  This should be called for each pair        of registers that we can parse to supply        GDB with the value of a register.  */
name|char
modifier|*
name|dump_registers
decl_stmt|;
comment|/* Command to dump all regs at once */
name|char
modifier|*
name|register_pattern
decl_stmt|;
comment|/* Pattern that picks out register from reg dump */
name|void
argument_list|(
argument|*supply_register
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|int
name|namelen
operator|,
name|char
operator|*
name|val
operator|,
name|int
name|vallen
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*load_routine
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|serial_t
name|desc
operator|,
name|char
operator|*
name|file
operator|,
name|int
name|hashmark
operator|)
argument_list|)
expr_stmt|;
comment|/* Download routine */
name|int
argument_list|(
argument|*dumpregs
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* routine to dump all registers */
name|int
argument_list|(
argument|*continue_hook
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* Emit the continue command */
name|int
argument_list|(
argument|*wait_filter
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
comment|/* Maybe contains registers */
name|int
name|bufmax
operator|,
name|int
operator|*
name|response_length
operator|,
expr|struct
name|target_waitstatus
operator|*
name|status
operator|)
argument_list|)
expr_stmt|;
name|char
modifier|*
name|load
decl_stmt|;
comment|/* load command */
name|char
modifier|*
name|loadresp
decl_stmt|;
comment|/* Response to load command */
name|char
modifier|*
name|prompt
decl_stmt|;
comment|/* monitor command prompt */
name|char
modifier|*
name|line_term
decl_stmt|;
comment|/* end-of-command delimitor */
name|char
modifier|*
name|cmd_end
decl_stmt|;
comment|/* optional command terminator */
name|struct
name|target_ops
modifier|*
name|target
decl_stmt|;
comment|/* target operations */
name|int
name|stopbits
decl_stmt|;
comment|/* number of stop bits */
name|char
modifier|*
modifier|*
name|regnames
decl_stmt|;
comment|/* array of register names in ascii */
name|int
name|num_breakpoints
decl_stmt|;
comment|/* If set_break != NULL, number of supported 				   breakpoints */
name|int
name|magic
decl_stmt|;
comment|/* Check value */
block|}
struct|;
end_struct

begin_comment
comment|/* The monitor ops magic number, used to detect if an ops structure doesn't    have the right number of entries filled in. */
end_comment

begin_define
define|#
directive|define
name|MONITOR_OPS_MAGIC
value|600925
end_define

begin_comment
comment|/* Flag definitions. */
end_comment

begin_comment
comment|/* If set, then clear breakpoint command uses address, otherwise it    uses an index returned by the monitor.  */
end_comment

begin_define
define|#
directive|define
name|MO_CLR_BREAK_USES_ADDR
value|0x1
end_define

begin_comment
comment|/* If set, then memory fill command uses STARTADDR, ENDADDR+1, VALUE    as args, else it uses STARTADDR, LENGTH, VALUE as args. */
end_comment

begin_define
define|#
directive|define
name|MO_FILL_USES_ADDR
value|0x2
end_define

begin_comment
comment|/* If set, then monitor doesn't automatically supply register dump    when coming back after a continue.  */
end_comment

begin_define
define|#
directive|define
name|MO_NEED_REGDUMP_AFTER_CONT
value|0x4
end_define

begin_comment
comment|/* getmem needs start addr and end addr */
end_comment

begin_define
define|#
directive|define
name|MO_GETMEM_NEEDS_RANGE
value|0x8
end_define

begin_comment
comment|/* getmem can only read one loc at a time */
end_comment

begin_define
define|#
directive|define
name|MO_GETMEM_READ_SINGLE
value|0x10
end_define

begin_comment
comment|/* handle \r\n combinations */
end_comment

begin_define
define|#
directive|define
name|MO_HANDLE_NL
value|0x20
end_define

begin_comment
comment|/* don't expect echos in monitor_open */
end_comment

begin_define
define|#
directive|define
name|MO_NO_ECHO_ON_OPEN
value|0x40
end_define

begin_comment
comment|/* If set, send break to stop monitor */
end_comment

begin_define
define|#
directive|define
name|MO_SEND_BREAK_ON_STOP
value|0x80
end_define

begin_comment
comment|/* If set, target sends an ACK after each S-record */
end_comment

begin_define
define|#
directive|define
name|MO_SREC_ACK
value|0x100
end_define

begin_comment
comment|/* Allow 0x prefix on addresses retured from monitor */
end_comment

begin_define
define|#
directive|define
name|MO_HEX_PREFIX
value|0x200
end_define

begin_comment
comment|/* Some monitors require a different command when starting a program */
end_comment

begin_define
define|#
directive|define
name|MO_RUN_FIRST_TIME
value|0x400
end_define

begin_comment
comment|/* Don't expect echos when getting memory */
end_comment

begin_define
define|#
directive|define
name|MO_NO_ECHO_ON_SETMEM
value|0x800
end_define

begin_comment
comment|/* If set, then register store command expects value BEFORE regname */
end_comment

begin_define
define|#
directive|define
name|MO_REGISTER_VALUE_FIRST
value|0x1000
end_define

begin_comment
comment|/* If set, then the monitor displays registers as pairs.  */
end_comment

begin_define
define|#
directive|define
name|MO_32_REGS_PAIRED
value|0x2000
end_define

begin_comment
comment|/* If set, then register setting happens interactively.  */
end_comment

begin_define
define|#
directive|define
name|MO_SETREG_INTERACTIVE
value|0x4000
end_define

begin_comment
comment|/* If set, then memory setting happens interactively.  */
end_comment

begin_define
define|#
directive|define
name|MO_SETMEM_INTERACTIVE
value|0x8000
end_define

begin_comment
comment|/* If set, then memory dumps are always on 16-byte boundaries, even    when less is desired.  */
end_comment

begin_define
define|#
directive|define
name|MO_GETMEM_16_BOUNDARY
value|0x10000
end_define

begin_comment
comment|/* If set, then the monitor numbers its breakpoints starting from 1.  */
end_comment

begin_define
define|#
directive|define
name|MO_CLR_BREAK_1_BASED
value|0x20000
end_define

begin_comment
comment|/* If set, then the monitor acks srecords with a plus sign.  */
end_comment

begin_define
define|#
directive|define
name|MO_SREC_ACK_PLUS
value|0x40000
end_define

begin_comment
comment|/* If set, then the monitor "acks" srecords with rotating lines.  */
end_comment

begin_define
define|#
directive|define
name|MO_SREC_ACK_ROTATE
value|0x80000
end_define

begin_comment
comment|/* If set, then remove useless address bits from memory addresses.  */
end_comment

begin_define
define|#
directive|define
name|MO_ADDR_BITS_REMOVE
value|0x100000
end_define

begin_comment
comment|/* If set, then display target program output if prefixed by ^O.  */
end_comment

begin_define
define|#
directive|define
name|MO_PRINT_PROGRAM_OUTPUT
value|0x200000
end_define

begin_comment
comment|/* Some dump bytes commands align the first data with the preceeding    16 byte boundary. Some print blanks and start at the exactly the    requested boundary. */
end_comment

begin_define
define|#
directive|define
name|MO_EXACT_DUMPADDR
value|0x400000
end_define

begin_comment
comment|/* Rather entering and exiting the write memory dialog for each word byte,    we can save time by transferring the whole block without exiting    the memory editing mode. You only need to worry about this    if you are doing memory downloading.    This engages a new write function registered with dcache.  */
end_comment

begin_define
define|#
directive|define
name|MO_HAS_BLOCKWRITES
value|0x800000
end_define

begin_define
define|#
directive|define
name|SREC_SIZE
value|160
end_define

begin_decl_stmt
specifier|extern
name|void
name|monitor_open
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|args
operator|,
expr|struct
name|monitor_ops
operator|*
name|ops
operator|,
name|int
name|from_tty
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|monitor_close
name|PARAMS
argument_list|(
operator|(
name|int
name|quitting
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|monitor_supply_register
name|PARAMS
argument_list|(
operator|(
name|int
name|regno
operator|,
name|char
operator|*
name|valstr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|monitor_expect
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|prompt
operator|,
name|char
operator|*
name|buf
operator|,
name|int
name|buflen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|monitor_expect_prompt
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
name|int
name|buflen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|monitor_printf
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|ATTR_FORMAT
argument_list|(
name|printf
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|monitor_printf_noecho
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|ATTR_FORMAT
argument_list|(
name|printf
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|monitor_write
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
name|int
name|buflen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|monitor_readchar
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|monitor_get_dev_name
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_monitor_ops
name|PARAMS
argument_list|(
operator|(
expr|struct
name|target_ops
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|monitor_dump_reg_block
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|dump_cmd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|flush_monitor_dcache
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

