begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992, 2000 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
name|int
name|run_pipeline
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* run_pipeline can handle at most this many commands */
end_comment

begin_define
define|#
directive|define
name|MAX_COMMANDS
value|10
end_define

begin_comment
comment|/* Children exit with this status if execvp fails. */
end_comment

begin_define
define|#
directive|define
name|EXEC_FAILED_EXIT_STATUS
value|0xff
end_define

end_unit

