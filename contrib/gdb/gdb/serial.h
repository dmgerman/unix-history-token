begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Remote serial support interface definitions for GDB, the GNU Debugger.    Copyright 1992, 1993 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_comment
comment|/* Terminal state pointer.  This is specific to each type of interface. */
end_comment

begin_typedef
typedef|typedef
name|PTR
name|serial_ttystate
typedef|;
end_typedef

begin_struct
struct|struct
name|_serial_t
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
name|serial_ttystate
name|ttystate
decl_stmt|;
comment|/* Not used (yet) */
name|int
name|bufcnt
decl_stmt|;
comment|/* Amount of data in receive buffer */
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
comment|/* (termio{s} only), last value of VTIME */
comment|/* ser-unix.c termio{,s} only, we still need to wait for this many more      seconds.  */
name|int
name|timeout_remaining
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The name of the device or host */
name|struct
name|_serial_t
modifier|*
name|next
decl_stmt|;
comment|/* Pointer to the next serial_t */
name|int
name|refcnt
decl_stmt|;
comment|/* Number of pointers to this block */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_serial_t
modifier|*
name|serial_t
typedef|;
end_typedef

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
argument_list|(
argument|*open
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|serial_t
operator|,
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*close
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|serial_t
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*readchar
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|serial_t
operator|,
name|int
name|timeout
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*write
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|serial_t
operator|,
specifier|const
name|char
operator|*
name|str
operator|,
name|int
name|len
operator|)
argument_list|)
expr_stmt|;
comment|/* Discard pending output */
name|int
argument_list|(
argument|*flush_output
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|serial_t
operator|)
argument_list|)
expr_stmt|;
comment|/* Discard pending input */
name|int
argument_list|(
argument|*flush_input
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|serial_t
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*send_break
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|serial_t
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*go_raw
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|serial_t
operator|)
argument_list|)
expr_stmt|;
name|serial_ttystate
argument_list|(
argument|*get_tty_state
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|serial_t
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*set_tty_state
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|serial_t
operator|,
name|serial_ttystate
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*print_tty_state
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|serial_t
operator|,
name|serial_ttystate
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*noflush_set_tty_state
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|serial_t
operator|,
name|serial_ttystate
operator|,
name|serial_ttystate
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*setbaudrate
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|serial_t
operator|,
name|int
name|rate
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*setstopbits
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|serial_t
operator|,
name|int
name|num
operator|)
argument_list|)
expr_stmt|;
comment|/* Wait for output to drain */
name|int
argument_list|(
argument|*drain_output
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|serial_t
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Add a new serial interface to the interface list */
end_comment

begin_decl_stmt
name|void
name|serial_add_interface
name|PARAMS
argument_list|(
operator|(
expr|struct
name|serial_ops
operator|*
name|optable
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|serial_t
name|serial_open
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|serial_t
name|serial_fdopen
name|PARAMS
argument_list|(
operator|(
specifier|const
name|int
name|fd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For most routines, if a failure is indicated, then errno should be    examined.  */
end_comment

begin_comment
comment|/* Try to open NAME.  Returns a new serial_t on success, NULL on failure.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_OPEN
parameter_list|(
name|NAME
parameter_list|)
value|serial_open(NAME)
end_define

begin_comment
comment|/* Open a new serial stream using a file handle.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_FDOPEN
parameter_list|(
name|FD
parameter_list|)
value|serial_fdopen(FD)
end_define

begin_comment
comment|/* Allow pending output to drain. */
end_comment

begin_define
define|#
directive|define
name|SERIAL_DRAIN_OUTPUT
parameter_list|(
name|SERIAL_T
parameter_list|)
define|\
value|((SERIAL_T)->ops->drain_output((SERIAL_T)))
end_define

begin_comment
comment|/* Flush (discard) pending output.  Might also flush input (if this system can't flush    only output).  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_FLUSH_OUTPUT
parameter_list|(
name|SERIAL_T
parameter_list|)
define|\
value|((SERIAL_T)->ops->flush_output((SERIAL_T)))
end_define

begin_comment
comment|/* Flush pending input.  Might also flush output (if this system can't flush    only input).  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_FLUSH_INPUT
parameter_list|(
name|SERIAL_T
parameter_list|)
define|\
value|((*(SERIAL_T)->ops->flush_input) ((SERIAL_T)))
end_define

begin_comment
comment|/* Send a break between 0.25 and 0.5 seconds long.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|serial_send_break
name|PARAMS
argument_list|(
operator|(
name|serial_t
name|scb
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SERIAL_SEND_BREAK
parameter_list|(
name|SERIAL_T
parameter_list|)
value|serial_send_break (SERIAL_T)
end_define

begin_comment
comment|/* Turn the port into raw mode. */
end_comment

begin_define
define|#
directive|define
name|SERIAL_RAW
parameter_list|(
name|SERIAL_T
parameter_list|)
value|(SERIAL_T)->ops->go_raw((SERIAL_T))
end_define

begin_comment
comment|/* Return a pointer to a newly malloc'd ttystate containing the state    of the tty.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GET_TTY_STATE
parameter_list|(
name|SERIAL_T
parameter_list|)
value|(SERIAL_T)->ops->get_tty_state((SERIAL_T))
end_define

begin_comment
comment|/* Set the state of the tty to TTYSTATE.  The change is immediate.    When changing to or from raw mode, input might be discarded.    Returns 0 for success, negative value for error (in which case errno    contains the error).  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_SET_TTY_STATE
parameter_list|(
name|SERIAL_T
parameter_list|,
name|TTYSTATE
parameter_list|)
value|(SERIAL_T)->ops->set_tty_state((SERIAL_T), (TTYSTATE))
end_define

begin_comment
comment|/* printf_filtered a user-comprehensible description of ttystate.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_PRINT_TTY_STATE
parameter_list|(
name|SERIAL_T
parameter_list|,
name|TTYSTATE
parameter_list|)
define|\
value|((*((SERIAL_T)->ops->print_tty_state)) ((SERIAL_T), (TTYSTATE)))
end_define

begin_comment
comment|/* Set the tty state to NEW_TTYSTATE, where OLD_TTYSTATE is the    current state (generally obtained from a recent call to    SERIAL_GET_TTY_STATE), but be careful not to discard any input.    This means that we never switch in or out of raw mode, even    if NEW_TTYSTATE specifies a switch.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_NOFLUSH_SET_TTY_STATE
parameter_list|(
name|SERIAL_T
parameter_list|,
name|NEW_TTYSTATE
parameter_list|,
name|OLD_TTYSTATE
parameter_list|)
define|\
value|((*((SERIAL_T)->ops->noflush_set_tty_state)) \     ((SERIAL_T), (NEW_TTYSTATE), (OLD_TTYSTATE)))
end_define

begin_comment
comment|/* Read one char from the serial device with TIMEOUT seconds to wait    or -1 to wait forever.  Use timeout of 0 to effect a poll. Returns    char if ok, else one of the following codes.  Note that all error    codes are guaranteed to be< 0.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_ERROR
value|-1
end_define

begin_comment
comment|/* General error, see errno for details */
end_comment

begin_define
define|#
directive|define
name|SERIAL_TIMEOUT
value|-2
end_define

begin_define
define|#
directive|define
name|SERIAL_EOF
value|-3
end_define

begin_decl_stmt
specifier|extern
name|int
name|serial_readchar
name|PARAMS
argument_list|(
operator|(
name|serial_t
name|scb
operator|,
name|int
name|timeout
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SERIAL_READCHAR
parameter_list|(
name|SERIAL_T
parameter_list|,
name|TIMEOUT
parameter_list|)
value|serial_readchar (SERIAL_T, TIMEOUT)
end_define

begin_comment
comment|/* Set the baudrate to the decimal value supplied.  Returns 0 for success,    -1 for failure.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_SETBAUDRATE
parameter_list|(
name|SERIAL_T
parameter_list|,
name|RATE
parameter_list|)
value|((SERIAL_T)->ops->setbaudrate((SERIAL_T), RATE))
end_define

begin_comment
comment|/* Set the number of stop bits to the value specified.  Returns 0 for success,    -1 for failure.  */
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

begin_define
define|#
directive|define
name|SERIAL_SETSTOPBITS
parameter_list|(
name|SERIAL_T
parameter_list|,
name|NUM
parameter_list|)
value|((SERIAL_T)->ops->setstopbits((SERIAL_T), NUM))
end_define

begin_comment
comment|/* Write LEN chars from STRING to the port SERIAL_T.  Returns 0 for    success, non-zero for failure.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|serial_write
name|PARAMS
argument_list|(
operator|(
name|serial_t
name|scb
operator|,
specifier|const
name|char
operator|*
name|str
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SERIAL_WRITE
parameter_list|(
name|SERIAL_T
parameter_list|,
name|STRING
parameter_list|,
name|LEN
parameter_list|)
value|serial_write (SERIAL_T, STRING, LEN)
end_define

begin_comment
comment|/* Push out all buffers, close the device and destroy SERIAL_T. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|serial_close
name|PARAMS
argument_list|(
operator|(
name|serial_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SERIAL_CLOSE
parameter_list|(
name|SERIAL_T
parameter_list|)
value|serial_close(SERIAL_T, 1)
end_define

begin_comment
comment|/* Push out all buffers and destroy SERIAL_T without closing the device.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_UN_FDOPEN
parameter_list|(
name|SERIAL_T
parameter_list|)
value|serial_close(SERIAL_T, 0)
end_define

begin_decl_stmt
specifier|extern
name|void
name|serial_printf
name|PARAMS
argument_list|(
operator|(
name|serial_t
name|desc
operator|,
specifier|const
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
literal|2
argument_list|,
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File in which to record the remote debugging session */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|serial_log_command
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SERIAL_H */
end_comment

end_unit

