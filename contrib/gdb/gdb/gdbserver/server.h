begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Common definitions for remote server for GDB.    Copyright 1993, 1995, 1997, 1998, 1999, 2000, 2002    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SERVER_H
end_ifndef

begin_define
define|#
directive|define
name|SERVER_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* FIXME:  Both of these should be autoconf'd for.  */
end_comment

begin_define
define|#
directive|define
name|NORETURN
end_define

begin_typedef
typedef|typedef
name|long
name|long
name|CORE_ADDR
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"regcache.h"
end_include

begin_include
include|#
directive|include
file|"gdb/signals.h"
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_comment
comment|/* Target-specific functions */
end_comment

begin_function_decl
name|int
name|create_inferior
parameter_list|(
name|char
modifier|*
name|program
parameter_list|,
name|char
modifier|*
modifier|*
name|allargs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kill_inferior
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fetch_inferior_registers
parameter_list|(
name|int
name|regno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|store_inferior_registers
parameter_list|(
name|int
name|regno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mythread_alive
parameter_list|(
name|int
name|pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|myresume
parameter_list|(
name|int
name|step
parameter_list|,
name|int
name|signo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
name|mywait
parameter_list|(
name|char
modifier|*
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_inferior_memory
parameter_list|(
name|CORE_ADDR
name|memaddr
parameter_list|,
name|char
modifier|*
name|myaddr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write_inferior_memory
parameter_list|(
name|CORE_ADDR
name|memaddr
parameter_list|,
name|char
modifier|*
name|myaddr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|create_inferior
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|initialize_low
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Target-specific variables */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|registers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Public variables in server.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cont_thread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|general_thread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|thread_from_wait
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|old_thread_from_wait
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|jmp_buf
name|toplevel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inferior_pid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions from remote-utils.c */
end_comment

begin_function_decl
name|int
name|putpkt
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getpkt
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|remote_open
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|remote_close
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_ok
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_enn
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|enable_async_io
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|disable_async_io
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|convert_ascii_to_int
parameter_list|(
name|char
modifier|*
name|from
parameter_list|,
name|char
modifier|*
name|to
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|convert_int_to_ascii
parameter_list|(
name|char
modifier|*
name|from
parameter_list|,
name|char
modifier|*
name|to
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prepare_resume_reply
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|char
name|status
parameter_list|,
name|unsigned
name|char
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|decode_m_packet
parameter_list|(
name|char
modifier|*
name|from
parameter_list|,
name|CORE_ADDR
modifier|*
name|mem_addr_ptr
parameter_list|,
name|unsigned
name|int
modifier|*
name|len_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|decode_M_packet
parameter_list|(
name|char
modifier|*
name|from
parameter_list|,
name|CORE_ADDR
modifier|*
name|mem_addr_ptr
parameter_list|,
name|unsigned
name|int
modifier|*
name|len_ptr
parameter_list|,
name|char
modifier|*
name|to
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions from ``signals.c''.  */
end_comment

begin_function_decl
name|enum
name|target_signal
name|target_signal_from_host
parameter_list|(
name|int
name|hostsig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|target_signal_to_host_p
parameter_list|(
name|enum
name|target_signal
name|oursig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|target_signal_to_host
parameter_list|(
name|enum
name|target_signal
name|oursig
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions from utils.c */
end_comment

begin_function_decl
name|void
name|perror_with_name
parameter_list|(
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|error
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatal
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|warning
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Maximum number of bytes to read/write at once.  The value here    is chosen to fill up a packet (the headers account for the 32).  */
end_comment

begin_define
define|#
directive|define
name|MAXBUFBYTES
parameter_list|(
name|N
parameter_list|)
value|(((N)-32)/2)
end_define

begin_comment
comment|/* Buffer sizes for transferring memory, registers, etc.  Round up PBUFSIZ to    hold all the registers, at least.  */
end_comment

begin_define
define|#
directive|define
name|PBUFSIZ
value|((registers_length () + 32> 2000) \ 		 ? (registers_length () + 32) \ 		 : 2000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SERVER_H */
end_comment

end_unit

