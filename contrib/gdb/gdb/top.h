begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Top level stuff for GDB, the GNU debugger.    Copyright 1986, 1987, 1988, 1989, 1990, 1991, 1992, 1993, 1994    Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* From top.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|linesize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|instream
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|gdb_dirbuf
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inhibit_gdbinit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|epoch_interface
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|gdbinit
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generally one should use catch_errors rather than manipulating these    directly.  The exception is main().  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SIGSETJMP
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIGJMP_BUF
value|sigjmp_buf
end_define

begin_define
define|#
directive|define
name|SIGSETJMP
parameter_list|(
name|buf
parameter_list|)
value|sigsetjmp(buf, 1)
end_define

begin_define
define|#
directive|define
name|SIGLONGJMP
parameter_list|(
name|buf
parameter_list|,
name|val
parameter_list|)
value|siglongjmp(buf,val)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIGJMP_BUF
value|jmp_buf
end_define

begin_define
define|#
directive|define
name|SIGSETJMP
parameter_list|(
name|buf
parameter_list|)
value|setjmp(buf)
end_define

begin_define
define|#
directive|define
name|SIGLONGJMP
parameter_list|(
name|buf
parameter_list|,
name|val
parameter_list|)
value|longjmp(buf,val)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|SIGJMP_BUF
name|error_return
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SIGJMP_BUF
name|quit_return
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_gdb_version
name|PARAMS
argument_list|(
operator|(
name|GDB_FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|source_command
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cd_command
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|read_command_file
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_history
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
name|command_loop
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
name|int
name|quit_confirm
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
name|quit_force
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|quit_command
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function returns a pointer to the string that is used    by gdb for its command prompt. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|get_prompt
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function copies the specified string into the string that    is used by gdb for its command prompt. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|set_prompt
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From random places.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mapped_symbol_files
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|readnow_symbol_files
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ALL_CLEANUPS
value|((struct cleanup *)0)
end_define

end_unit

