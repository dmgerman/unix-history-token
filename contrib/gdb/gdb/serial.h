begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Remote serial support interface definitions for GDB, the GNU Debugger.    Copyright 1992, 1993, 1994, 1995, 1996, 1998, 1999, 2000    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SERIAL_H
end_ifndef

begin_define
define|#
directive|define
name|SERIAL_H
end_define

begin_struct_decl
struct_decl|struct
name|ui_file
struct_decl|;
end_struct_decl

begin_comment
comment|/* For most routines, if a failure is indicated, then errno should be    examined.  */
end_comment

begin_comment
comment|/* Terminal state pointer.  This is specific to each type of    interface. */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|serial_ttystate
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|serial
struct_decl|;
end_struct_decl

begin_comment
comment|/* Try to open NAME.  Returns a new `struct serial *' on success, NULL    on failure. Note that some open calls can block and, if possible,     should be  written to be non-blocking, with calls to ui_look_hook     so they can be cancelled. An async interface for open could be    added to GDB if necessary. */
end_comment

begin_function_decl
specifier|extern
name|struct
name|serial
modifier|*
name|serial_open
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Open a new serial stream using a file handle.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|serial
modifier|*
name|serial_fdopen
parameter_list|(
specifier|const
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Push out all buffers, close the device and destroy SCB. */
end_comment

begin_function_decl
specifier|extern
name|void
name|serial_close
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Push out all buffers and destroy SCB without closing the device.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|serial_un_fdopen
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read one char from the serial device with TIMEOUT seconds to wait    or -1 to wait forever.  Use timeout of 0 to effect a poll.    Infinite waits are not permitted. Returns unsigned char if ok, else    one of the following codes.  Note that all error return-codes are    guaranteed to be< 0. */
end_comment

begin_enum
enum|enum
name|serial_rc
block|{
name|SERIAL_ERROR
init|=
operator|-
literal|1
block|,
comment|/* General error. */
name|SERIAL_TIMEOUT
init|=
operator|-
literal|2
block|,
comment|/* Timeout or data-not-ready during read. 			   Unfortunately, through ui_loop_hook(), this 			   can also be a QUIT indication.  */
name|SERIAL_EOF
init|=
operator|-
literal|3
comment|/* General end-of-file or remote target 			   connection closed, indication.  Includes 			   things like the line dropping dead. */
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|int
name|serial_readchar
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|,
name|int
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write LEN chars from STRING to the port SCB.  Returns 0 for    success, non-zero for failure.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|serial_write
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write a printf style string onto the serial port. */
end_comment

begin_function_decl
specifier|extern
name|void
name|serial_printf
parameter_list|(
name|struct
name|serial
modifier|*
name|desc
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTR_FORMAT
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Allow pending output to drain. */
end_comment

begin_function_decl
specifier|extern
name|int
name|serial_drain_output
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Flush (discard) pending output.  Might also flush input (if this    system can't flush only output).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|serial_flush_output
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Flush pending input.  Might also flush output (if this system can't    flush only input).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|serial_flush_input
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Send a break between 0.25 and 0.5 seconds long.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|serial_send_break
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Turn the port into raw mode. */
end_comment

begin_function_decl
specifier|extern
name|void
name|serial_raw
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a pointer to a newly malloc'd ttystate containing the state    of the tty.  */
end_comment

begin_function_decl
specifier|extern
name|serial_ttystate
name|serial_get_tty_state
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the state of the tty to TTYSTATE.  The change is immediate.    When changing to or from raw mode, input might be discarded.    Returns 0 for success, negative value for error (in which case    errno contains the error).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|serial_set_tty_state
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|,
name|serial_ttystate
name|ttystate
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* printf_filtered a user-comprehensible description of ttystate on    the specified STREAM. FIXME: At present this sends output to the    default stream - GDB_STDOUT. */
end_comment

begin_function_decl
specifier|extern
name|void
name|serial_print_tty_state
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|,
name|serial_ttystate
name|ttystate
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the tty state to NEW_TTYSTATE, where OLD_TTYSTATE is the    current state (generally obtained from a recent call to    serial_get_tty_state()), but be careful not to discard any input.    This means that we never switch in or out of raw mode, even if    NEW_TTYSTATE specifies a switch.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|serial_noflush_set_tty_state
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|,
name|serial_ttystate
name|new_ttystate
parameter_list|,
name|serial_ttystate
name|old_ttystate
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the baudrate to the decimal value supplied.  Returns 0 for    success, -1 for failure.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|serial_setbaudrate
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|,
name|int
name|rate
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the number of stop bits to the value specified.  Returns 0 for    success, -1 for failure.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_1_STOPBITS
value|1
end_define

begin_define
define|#
directive|define
name|SERIAL_1_AND_A_HALF_STOPBITS
value|2
end_define

begin_comment
comment|/* 1.5 bits, snicker... */
end_comment

begin_define
define|#
directive|define
name|SERIAL_2_STOPBITS
value|3
end_define

begin_function_decl
specifier|extern
name|int
name|serial_setstopbits
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|,
name|int
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Asynchronous serial interface: */
end_comment

begin_comment
comment|/* Can the serial device support asynchronous mode? */
end_comment

begin_function_decl
specifier|extern
name|int
name|serial_can_async_p
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Has the serial device been put in asynchronous mode? */
end_comment

begin_function_decl
specifier|extern
name|int
name|serial_is_async_p
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For ASYNC enabled devices, register a callback and enable    asynchronous mode.  To disable asynchronous mode, register a NULL    callback. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|serial_event_ftype
function_decl|)
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|serial_async
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|,
name|serial_event_ftype
modifier|*
name|handler
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Provide direct access to the underlying FD (if any) used to    implement the serial device.  This interface is clearly    deprecated. Will call internal_error() if the operation isn't    applicable to the current serial device. */
end_comment

begin_function_decl
specifier|extern
name|int
name|deprecated_serial_fd
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Trace/debug mechanism.     serial_debug() enables/disables internal debugging.    serial_debug_p() indicates the current debug state. */
end_comment

begin_function_decl
specifier|extern
name|void
name|serial_debug
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|,
name|int
name|debug_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|serial_debug_p
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Details of an instance of a serial object */
end_comment

begin_struct
struct|struct
name|serial
block|{
name|int
name|fd
decl_stmt|;
comment|/* File descriptor */
name|struct
name|serial_ops
modifier|*
name|ops
decl_stmt|;
comment|/* Function vector */
name|void
modifier|*
name|state
decl_stmt|;
comment|/* Local context info for open FD */
name|serial_ttystate
name|ttystate
decl_stmt|;
comment|/* Not used (yet) */
name|int
name|bufcnt
decl_stmt|;
comment|/* Amount of data remaining in receive 				   buffer.  -ve for sticky errors. */
name|unsigned
name|char
modifier|*
name|bufp
decl_stmt|;
comment|/* Current byte */
name|unsigned
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* Da buffer itself */
name|int
name|current_timeout
decl_stmt|;
comment|/* (ser-unix.c termio{,s} only), last 				   value of VTIME */
name|int
name|timeout_remaining
decl_stmt|;
comment|/* (ser-unix.c termio{,s} only), we 				   still need to wait for this many 				   more seconds.  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The name of the device or host */
name|struct
name|serial
modifier|*
name|next
decl_stmt|;
comment|/* Pointer to the next `struct serial *' */
name|int
name|refcnt
decl_stmt|;
comment|/* Number of pointers to this block */
name|int
name|debug_p
decl_stmt|;
comment|/* Trace this serial devices operation. */
name|int
name|async_state
decl_stmt|;
comment|/* Async internal state. */
name|void
modifier|*
name|async_context
decl_stmt|;
comment|/* Async event thread's context */
name|serial_event_ftype
modifier|*
name|async_handler
decl_stmt|;
comment|/* Async event handler */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|serial_ops
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|serial_ops
modifier|*
name|next
decl_stmt|;
name|int
function_decl|(
modifier|*
name|open
function_decl|)
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|close
function_decl|)
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|readchar
function_decl|)
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|,
name|int
name|timeout
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|write
function_decl|)
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
comment|/* Discard pending output */
name|int
function_decl|(
modifier|*
name|flush_output
function_decl|)
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|)
function_decl|;
comment|/* Discard pending input */
name|int
function_decl|(
modifier|*
name|flush_input
function_decl|)
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|send_break
function_decl|)
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|go_raw
function_decl|)
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|)
function_decl|;
name|serial_ttystate
function_decl|(
modifier|*
name|get_tty_state
function_decl|)
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|set_tty_state
function_decl|)
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|,
name|serial_ttystate
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|print_tty_state
function_decl|)
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|,
name|serial_ttystate
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|noflush_set_tty_state
function_decl|)
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|,
name|serial_ttystate
parameter_list|,
name|serial_ttystate
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|setbaudrate
function_decl|)
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|,
name|int
name|rate
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|setstopbits
function_decl|)
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|,
name|int
name|num
parameter_list|)
function_decl|;
comment|/* Wait for output to drain */
name|int
function_decl|(
modifier|*
name|drain_output
function_decl|)
parameter_list|(
name|struct
name|serial
modifier|*
parameter_list|)
function_decl|;
comment|/* Change the serial device into/out of asynchronous mode, call        the specified function when ever there is something        interesting. */
name|void
function_decl|(
modifier|*
name|async
function_decl|)
parameter_list|(
name|struct
name|serial
modifier|*
name|scb
parameter_list|,
name|int
name|async_p
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* Add a new serial interface to the interface list */
end_comment

begin_function_decl
specifier|extern
name|void
name|serial_add_interface
parameter_list|(
name|struct
name|serial_ops
modifier|*
name|optable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* File in which to record the remote debugging session */
end_comment

begin_function_decl
specifier|extern
name|void
name|serial_log_command
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SERIAL_H */
end_comment

end_unit

