begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header for environment manipulation library.    Copyright 1989, 1992, 2000 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ENVIRON_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|ENVIRON_H
value|1
end_define

begin_comment
comment|/* We manipulate environments represented as these structures.  */
end_comment

begin_struct
struct|struct
name|environ
block|{
comment|/* Number of usable slots allocated in VECTOR.        VECTOR always has one slot not counted here,        to hold the terminating zero.  */
name|int
name|allocated
decl_stmt|;
comment|/* A vector of slots, ALLOCATED + 1 of them.        The first few slots contain strings "VAR=VALUE"        and the next one contains zero.        Then come some unused slots.  */
name|char
modifier|*
modifier|*
name|vector
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|struct
name|environ
modifier|*
name|make_environ
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_environ
parameter_list|(
name|struct
name|environ
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_environ
parameter_list|(
name|struct
name|environ
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_in_environ
parameter_list|(
specifier|const
name|struct
name|environ
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_in_environ
parameter_list|(
name|struct
name|environ
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unset_in_environ
parameter_list|(
name|struct
name|environ
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|environ_vector
parameter_list|(
name|struct
name|environ
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (ENVIRON_H) */
end_comment

end_unit

