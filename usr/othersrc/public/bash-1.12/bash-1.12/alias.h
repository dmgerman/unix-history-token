begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* alias.h -- structure definitions. */
end_comment

begin_comment
comment|/* Copyright (C) 1987,1991 Free Software Foundation, Inc.     This file is part of GNU Bash, the Bourne Again SHell.     Bash is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 1, or (at your option)    any later version.     Bash is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with Bash; see the file COPYING.  If not, write to the Free    Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ALIAS_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_ALIAS_
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xmalloc
argument_list|()
decl_stmt|,
modifier|*
name|malloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|whitespace
end_ifndef

begin_define
define|#
directive|define
name|whitespace
parameter_list|(
name|c
parameter_list|)
value|(((c) == ' ') || ((c) == '\t'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|savestring
end_ifndef

begin_define
define|#
directive|define
name|savestring
parameter_list|(
name|x
parameter_list|)
value|(char *)strcpy (xmalloc (1 + strlen (x)), (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|value
decl_stmt|;
block|}
name|ASSOC
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0x0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The list of known aliases. */
end_comment

begin_decl_stmt
specifier|extern
name|ASSOC
modifier|*
modifier|*
name|aliases
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Scan the list of aliases looking for one with NAME.  Return NULL    if the alias doesn't exist, else a pointer to the assoc. */
end_comment

begin_function_decl
specifier|extern
name|ASSOC
modifier|*
name|find_alias
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the value of the alias for NAME, or NULL if there is none. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_alias_value
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Make a new alias from NAME and VALUE.  If NAME can be found,    then replace its value. */
end_comment

begin_function_decl
specifier|extern
name|void
name|add_alias
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Remove the alias with name NAME from the alias list.  Returns    the index of the removed alias, or -1 if the alias didn't exist. */
end_comment

begin_function_decl
specifier|extern
name|int
name|remove_alias
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return a new line, with any aliases substituted. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|alias_substitute
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALIAS_ */
end_comment

end_unit

