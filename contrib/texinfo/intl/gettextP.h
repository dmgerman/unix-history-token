begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header describing internals of gettext library    Copyright (C) 1995, 1996, 1997 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GETTEXTP_H
end_ifndef

begin_define
define|#
directive|define
name|_GETTEXTP_H
end_define

begin_include
include|#
directive|include
file|"loadinfo.h"
end_include

begin_comment
comment|/* @@ end of prolog @@ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|args
parameter_list|)
value|args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|args
parameter_list|)
value|()
end_define

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
name|W
end_ifndef

begin_define
define|#
directive|define
name|W
parameter_list|(
name|flag
parameter_list|,
name|data
parameter_list|)
value|((flag) ? SWAP (data) : (data))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|nls_uint32
name|SWAP
name|PARAMS
argument_list|(
operator|(
name|nls_uint32
name|i
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|nls_uint32
name|SWAP
parameter_list|(
name|i
parameter_list|)
name|nls_uint32
name|i
decl_stmt|;
block|{
return|return
operator|(
name|i
operator|<<
literal|24
operator|)
operator||
operator|(
operator|(
name|i
operator|&
literal|0xff00
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|i
operator|>>
literal|8
operator|)
operator|&
literal|0xff00
operator|)
operator||
operator|(
name|i
operator|>>
literal|24
operator|)
return|;
block|}
end_function

begin_struct
struct|struct
name|loaded_domain
block|{
specifier|const
name|char
modifier|*
name|data
decl_stmt|;
name|int
name|must_swap
decl_stmt|;
name|nls_uint32
name|nstrings
decl_stmt|;
name|struct
name|string_desc
modifier|*
name|orig_tab
decl_stmt|;
name|struct
name|string_desc
modifier|*
name|trans_tab
decl_stmt|;
name|nls_uint32
name|hash_size
decl_stmt|;
name|nls_uint32
modifier|*
name|hash_tab
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|binding
block|{
name|struct
name|binding
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|domainname
decl_stmt|;
name|char
modifier|*
name|dirname
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|loaded_l10nfile
modifier|*
name|_nl_find_domain
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|__dirname
operator|,
name|char
operator|*
name|__locale
operator|,
specifier|const
name|char
operator|*
name|__domainname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_nl_load_domain
name|PARAMS
argument_list|(
operator|(
expr|struct
name|loaded_l10nfile
operator|*
name|__domain
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* @@ begin of epilog @@ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gettextP.h  */
end_comment

end_unit

