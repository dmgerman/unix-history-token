begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1990 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.uucp)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file LICENSE.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|REQUEST_FUNCP
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_decl_stmt
name|class
name|macro
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|request_or_macro
range|:
name|public
name|object
block|{
name|public
operator|:
name|request_or_macro
argument_list|()
block|;
name|virtual
name|void
name|invoke
argument_list|(
argument|symbol s
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|macro
operator|*
name|to_macro
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|request
range|:
name|public
name|request_or_macro
block|{
name|REQUEST_FUNCP
name|p
block|;
name|public
operator|:
name|void
name|invoke
argument_list|(
name|symbol
argument_list|)
block|;
name|request
argument_list|(
name|REQUEST_FUNCP
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|delete_request_or_macro
parameter_list|(
name|request_or_macro
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|object_dictionary
name|request_dictionary
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|macro_header
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|node
struct_decl|;
end_struct_decl

begin_decl_stmt
name|class
name|macro
range|:
name|public
name|request_or_macro
block|{
name|macro_header
operator|*
name|p
block|;
specifier|const
name|char
operator|*
name|filename
block|;
comment|// where was it defined?
name|int
name|lineno
block|;
name|int
name|length
block|;
name|public
operator|:
name|macro
argument_list|()
block|;
operator|~
name|macro
argument_list|()
block|;
name|macro
argument_list|(
specifier|const
name|macro
operator|&
argument_list|)
block|;
name|macro
operator|&
name|operator
operator|=
operator|(
specifier|const
name|macro
operator|&
operator|)
block|;
name|void
name|append
argument_list|(
argument|unsigned char
argument_list|)
block|;
name|void
name|append
argument_list|(
name|node
operator|*
argument_list|)
block|;
name|void
name|invoke
argument_list|(
name|symbol
argument_list|)
block|;
name|macro
operator|*
name|to_macro
argument_list|()
block|;
name|void
name|print_size
argument_list|()
block|;
name|friend
name|class
name|string_iterator
block|;
name|friend
name|void
name|chop_macro
argument_list|()
block|;
name|friend
name|int
name|operator
operator|==
operator|(
specifier|const
name|macro
operator|&
expr|,
specifier|const
name|macro
operator|&
operator|)
block|; }
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|init_input_requests
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_div_requests
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_node_requests
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_reg_requests
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_env_requests
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_hyphen_requests
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_request
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|REQUEST_FUNCP
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|no_break_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|// indicates whether request was invoked with . or '
end_comment

begin_decl_stmt
name|class
name|charinfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|environment
decl_stmt|;
end_decl_stmt

begin_function_decl
name|node
modifier|*
name|charinfo_to_node
parameter_list|(
name|charinfo
modifier|*
parameter_list|,
specifier|const
name|environment
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

