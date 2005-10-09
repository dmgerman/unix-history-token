begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Common definitions for remote server for GDB.    Copyright 1993, 1995, 1997, 1998, 1999, 2000, 2002, 2003, 2004    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_STRERROR
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|strerror
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* X3.159-1989  4.11.6.2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ATTR_NORETURN
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|>
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|7
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|ATTR_NORETURN
value|__attribute__ ((noreturn))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTR_NORETURN
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ATTR_FORMAT
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|>
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|4
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|ATTR_FORMAT
parameter_list|(
name|type
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|__attribute__ ((format(type, x, y)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTR_FORMAT
parameter_list|(
name|type
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FIXME: This should probably be autoconf'd for.  It's an integer type at    least the size of a (void *).  */
end_comment

begin_typedef
typedef|typedef
name|long
name|long
name|CORE_ADDR
typedef|;
end_typedef

begin_comment
comment|/* Generic information for tracking a list of ``inferiors'' - threads,    processes, etc.  */
end_comment

begin_struct
struct|struct
name|inferior_list
block|{
name|struct
name|inferior_list_entry
modifier|*
name|head
decl_stmt|;
name|struct
name|inferior_list_entry
modifier|*
name|tail
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|inferior_list_entry
block|{
name|int
name|id
decl_stmt|;
name|struct
name|inferior_list_entry
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Opaque type for user-visible threads.  */
end_comment

begin_struct_decl
struct_decl|struct
name|thread_info
struct_decl|;
end_struct_decl

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
file|"target.h"
end_include

begin_include
include|#
directive|include
file|"mem-break.h"
end_include

begin_comment
comment|/* Target-specific functions */
end_comment

begin_function_decl
name|void
name|initialize_low
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* From inferiors.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|inferior_list
name|all_threads
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|add_inferior_to_list
parameter_list|(
name|struct
name|inferior_list
modifier|*
name|list
parameter_list|,
name|struct
name|inferior_list_entry
modifier|*
name|new_inferior
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|for_each_inferior
parameter_list|(
name|struct
name|inferior_list
modifier|*
name|list
parameter_list|,
name|void
function_decl|(
modifier|*
name|action
function_decl|)
parameter_list|(
name|struct
name|inferior_list_entry
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|thread_info
modifier|*
name|current_inferior
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|remove_inferior
parameter_list|(
name|struct
name|inferior_list
modifier|*
name|list
parameter_list|,
name|struct
name|inferior_list_entry
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|remove_thread
parameter_list|(
name|struct
name|thread_info
modifier|*
name|thread
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_thread
parameter_list|(
name|int
name|thread_id
parameter_list|,
name|void
modifier|*
name|target_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clear_inferiors
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inferior_list_entry
modifier|*
name|find_inferior
parameter_list|(
name|struct
name|inferior_list
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|struct
name|inferior_list_entry
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inferior_list_entry
modifier|*
name|find_inferior_id
parameter_list|(
name|struct
name|inferior_list
modifier|*
name|list
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|inferior_target_data
parameter_list|(
name|struct
name|thread_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_inferior_target_data
parameter_list|(
name|struct
name|thread_info
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|inferior_regcache_data
parameter_list|(
name|struct
name|thread_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_inferior_regcache_data
parameter_list|(
name|struct
name|thread_info
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|change_inferior_id
parameter_list|(
name|struct
name|inferior_list
modifier|*
name|list
parameter_list|,
name|int
name|new_id
parameter_list|)
function_decl|;
end_function_decl

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
name|step_thread
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
name|int
name|server_waiting
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|jmp_buf
name|toplevel
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
name|unblock_async_io
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|block_async_io
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
name|new_thread_notify
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dead_thread_notify
parameter_list|(
name|int
name|id
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

begin_function_decl
name|int
name|unhexify
parameter_list|(
name|char
modifier|*
name|bin
parameter_list|,
specifier|const
name|char
modifier|*
name|hex
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hexify
parameter_list|(
name|char
modifier|*
name|hex
parameter_list|,
specifier|const
name|char
modifier|*
name|bin
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|look_up_one_symbol
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|CORE_ADDR
modifier|*
name|addrp
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

begin_decl_stmt
name|void
name|error
argument_list|(
specifier|const
name|char
operator|*
name|string
argument_list|,
operator|...
argument_list|)
name|ATTR_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fatal
argument_list|(
specifier|const
name|char
operator|*
name|string
argument_list|,
operator|...
argument_list|)
name|ATTR_NORETURN
decl_stmt|;
end_decl_stmt

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
comment|/* Functions from the register cache definition.  */
end_comment

begin_function_decl
name|void
name|init_registers
parameter_list|(
name|void
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

