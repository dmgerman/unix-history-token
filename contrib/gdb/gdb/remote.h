begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Remote target communications for serial-line targets in custom GDB protocol    Copyright 1999 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REMOTE_H
end_ifndef

begin_define
define|#
directive|define
name|REMOTE_H
end_define

begin_comment
comment|/* FIXME?: move this interface down to tgt vector) */
end_comment

begin_comment
comment|/* Read a packet from the remote machine, with error checking, and    store it in BUF.  BUF is expected to be of size PBUFSIZ.  If    FOREVER, wait forever rather than timing out; this is used while    the target is executing user code.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|getpkt
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|long
name|sizeof_buf
parameter_list|,
name|int
name|forever
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Send a packet to the remote machine, with error checking.  The data    of the packet is in BUF.  The string in BUF can be at most PBUFSIZ    - 5 to account for the $, # and checksum, and for a possible /0 if    we are debugging (remote_debug) and want to print the sent packet    as a string */
end_comment

begin_function_decl
specifier|extern
name|int
name|putpkt
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Send HEX encoded string to the target console. (gdb_stdtarg) */
end_comment

begin_function_decl
specifier|extern
name|void
name|remote_console_output
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FIXME: cagney/1999-09-20: The remote cisco stuff in remote.c needs    to be broken out into a separate file (remote-cisco.[hc]?).  Before    that can happen, a remote protocol stack framework needs to be    implemented. */
end_comment

begin_function_decl
specifier|extern
name|void
name|remote_cisco_objfile_relocate
parameter_list|(
name|bfd_signed_vma
name|text_off
parameter_list|,
name|bfd_signed_vma
name|data_off
parameter_list|,
name|bfd_signed_vma
name|bss_off
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|async_remote_interrupt_twice
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|remote_write_bytes
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
specifier|extern
name|int
name|remote_read_bytes
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
specifier|extern
name|void
function_decl|(
modifier|*
name|target_resume_hook
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|target_wait_loop_hook
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

