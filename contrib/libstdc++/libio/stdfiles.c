begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1993, 1994, 1996, 1997, 1999, 2000 Free Software Foundation, Inc.    This file is part of the GNU IO Library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2, or (at    your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this library; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330, Boston,    MA 02111-1307, USA.     As a special exception, if you link this library with files    compiled with a GNU compiler to produce an executable, this does    not cause the resulting executable to be covered by the GNU General    Public License.  This exception does not however invalidate any    other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_comment
comment|/* This file provides definitions of _IO_stdin, _IO_stdout, and _IO_stderr    for C code.  Compare stdstreams.cc.    (The difference is that here the vtable field is set to 0,    so the objects defined are not valid C++ objects.  On the other    hand, we don't need a C++ compiler to build this file.) */
end_comment

begin_include
include|#
directive|include
file|"libioP.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_IO_MTSAFE_IO
end_ifdef

begin_if
if|#
directive|if
name|defined
name|_LIBC
operator|||
name|defined
name|_GLIBCPP_USE_WCHAR_T
end_if

begin_define
define|#
directive|define
name|DEF_STDFILE
parameter_list|(
name|NAME
parameter_list|,
name|FD
parameter_list|,
name|CHAIN
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|static _IO_lock_t _IO_stdfile_##FD##_lock = _IO_lock_initializer; \   static struct _IO_wide_data _IO_wide_data_##FD \     = { ._wide_vtable =&_IO_wfile_jumps }; \   struct _IO_FILE_plus NAME \     = {FILEBUF_LITERAL(CHAIN, FLAGS, FD,&_IO_wide_data_##FD), \&_IO_file_jumps};
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEF_STDFILE
parameter_list|(
name|NAME
parameter_list|,
name|FD
parameter_list|,
name|CHAIN
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|static _IO_lock_t _IO_stdfile_##FD##_lock = _IO_lock_initializer; \   struct _IO_FILE_plus NAME \     = {FILEBUF_LITERAL(CHAIN, FLAGS, FD, NULL), \&_IO_file_jumps};
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
name|_LIBC
operator|||
name|defined
name|_GLIBCPP_USE_WCHAR_T
end_if

begin_define
define|#
directive|define
name|DEF_STDFILE
parameter_list|(
name|NAME
parameter_list|,
name|FD
parameter_list|,
name|CHAIN
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|static struct _IO_wide_data _IO_wide_data_##FD \     = { ._wide_vtable =&_IO_wfile_jumps }; \   struct _IO_FILE_plus NAME \     = {FILEBUF_LITERAL(CHAIN, FLAGS, FD,&_IO_wide_data_##FD), \&_IO_file_jumps};
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEF_STDFILE
parameter_list|(
name|NAME
parameter_list|,
name|FD
parameter_list|,
name|CHAIN
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|struct _IO_FILE_plus NAME \     = {FILEBUF_LITERAL(CHAIN, FLAGS, FD, NULL), \&_IO_file_jumps};
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|DEF_STDFILE
argument_list|(
name|_IO_2_1_stdin_
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|_IO_NO_WRITES
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_STDFILE
argument_list|(
name|_IO_2_1_stdout_
argument_list|,
literal|1
argument_list|,
operator|&
name|_IO_2_1_stdin_
argument_list|,
name|_IO_NO_READS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_STDFILE
argument_list|(
name|_IO_2_1_stderr_
argument_list|,
literal|2
argument_list|,
operator|&
name|_IO_2_1_stdout_
argument_list|,
name|_IO_NO_READS
operator|+
name|_IO_UNBUFFERED
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|_IO_FILE_plus
modifier|*
name|_IO_list_all
init|=
operator|&
name|_IO_2_1_stderr_
decl_stmt|;
end_decl_stmt

end_unit

