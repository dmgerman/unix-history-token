begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for Intel 960 running NINDY monitor, for GDB, the GNU debugger.    Copyright (C) 1990-1991 Free Software Foundation, Inc.    Contributed by Intel Corporation and Cygnus Support.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*****************************************************************************  * Definitions to target GDB to an i960 debugged over a serial line.  ******************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"tm-i960.h"
end_include

begin_comment
comment|/* Override the standard gdb prompt when compiled for this target.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PROMPT
value|"(gdb960) "
end_define

begin_comment
comment|/* Additional command line options accepted by nindy gdb's, for handling    the remote-nindy.c interface.  These should really be target-specific    rather than architecture-specific.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nindy_old_protocol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nonzero if old NINDY serial protocol */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nindy_initial_brk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Send a BREAK to reset board first */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|nindy_ttyname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of serial port to talk to nindy */
end_comment

begin_define
define|#
directive|define
name|ADDITIONAL_OPTIONS
define|\
value|{"O", no_argument,&nindy_old_protocol, 1},	\ 	{"brk", no_argument,&nindy_initial_brk, 1},	\ 	{"ser", required_argument, 0, 1004},
end_define

begin_comment
comment|/* 1004 is magic cookie for ADDL_CASES */
end_comment

begin_define
define|#
directive|define
name|ADDITIONAL_OPTION_CASES
define|\
value|case 1004:
comment|/* -ser option:  remote nindy auto-start */
value|\ 	  nindy_ttyname = optarg;	\ 	  break;
end_define

begin_define
define|#
directive|define
name|ADDITIONAL_OPTION_HELP
define|\
value|"\   -O                Use old protocol to talk to a Nindy target\n\   -brk              Send a break to a Nindy target to reset it.\n\   -ser SERIAL       Open remote Nindy session to SERIAL port.\n\ "
end_define

begin_comment
comment|/* If specified on the command line, open tty for talking to nindy,    and download the executable file if one was specified.  */
end_comment

begin_define
define|#
directive|define
name|ADDITIONAL_OPTION_HANDLER
define|\
value|if (!setjmp (to_top_level)&& nindy_ttyname) {		\ 	  nindy_open (nindy_ttyname, !batch);			\ 	  if ( !setjmp(to_top_level)&& execarg ) {		\ 		target_load (execarg, !batch);			\ 	  }							\ 	}
end_define

begin_comment
comment|/* If configured for i960 target, we take control before main loop    and demand that we configure for a nindy target.  */
end_comment

begin_define
define|#
directive|define
name|BEFORE_MAIN_LOOP_HOOK
define|\
value|nindy_before_main_loop();
end_define

begin_comment
comment|/* Address of end of stack space.  *	This probably doesn't matter for nindy, because it's only used  *	in manipulation of core files, which we don't support.  */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|(0xfe000000)
end_define

begin_comment
comment|/* FRAME_CHAIN_VALID returns zero if the given frame is the outermost one    and has no caller.     On the i960, each various target system type defines FRAME_CHAIN_VALID,    since it differs between NINDY and VxWorks, the two currently supported    targets types.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN_VALID
parameter_list|(
name|chain
parameter_list|,
name|thisframe
parameter_list|)
define|\
value|nindy_frame_chain_valid (chain, thisframe)
end_define

begin_function_decl
specifier|extern
name|int
name|nindy_frame_chain_valid
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* See nindy-tdep.c */
end_comment

begin_comment
comment|/* Sequence of bytes for breakpoint instruction */
end_comment

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0x00, 0x3e, 0x00, 0x66}
end_define

begin_comment
comment|/* Amount ip must be decremented by after a breakpoint.  * This is often the number of bytes in BREAKPOINT but not always.  */
end_comment

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|0
end_define

end_unit

