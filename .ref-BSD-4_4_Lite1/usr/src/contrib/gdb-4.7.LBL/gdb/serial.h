begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Remote serial support interface definitions for GDB, the GNU Debugger.    Copyright 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TERMIO
end_ifdef

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_struct
struct|struct
name|ttystate
block|{
name|int
name|flags
decl_stmt|;
comment|/* Flags from fcntl F_GETFL */
name|struct
name|termios
name|termios
decl_stmt|;
comment|/* old tty driver settings */
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_TERMIO */
end_comment

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_struct
struct|struct
name|ttystate
block|{
name|int
name|flags
decl_stmt|;
comment|/* Flags from fcntl F_GETFL */
name|struct
name|sgttyb
name|sgttyb
decl_stmt|;
comment|/* old tty driver settings */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_TERMIO */
end_comment

begin_comment
comment|/* Return a sensible default name for a serial device, something which    can be used as an argument to serial_open.  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|serial_default_name
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Try to open the serial device "name", return 1 if ok, 0 if not.  */
end_comment

begin_decl_stmt
name|int
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

begin_comment
comment|/* Turn the port into raw mode.  */
end_comment

begin_decl_stmt
name|void
name|serial_raw
name|PARAMS
argument_list|(
operator|(
name|int
name|fd
operator|,
expr|struct
name|ttystate
operator|*
name|oldstate
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Turn the port into normal mode.  */
end_comment

begin_decl_stmt
name|void
name|serial_normal
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read one char from the serial device with<TO>-second timeout.    Returns char if ok, else EOF, -2 for timeout, -3 for anything else  */
end_comment

begin_decl_stmt
name|int
name|serial_readchar
name|PARAMS
argument_list|(
operator|(
name|int
name|to
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the baudrate to the decimal value supplied, and return 1, or fail and    return 0.  */
end_comment

begin_decl_stmt
name|int
name|serial_setbaudrate
name|PARAMS
argument_list|(
operator|(
name|int
name|rate
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the next rate in the sequence, or return 0 for failure.  */
end_comment

begin_comment
comment|/* Write some chars to the device, returns 0 for failure.  See errno for    details. */
end_comment

begin_decl_stmt
name|int
name|serial_write
name|PARAMS
argument_list|(
operator|(
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

begin_comment
comment|/* Close the serial port */
end_comment

begin_decl_stmt
name|void
name|serial_close
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

