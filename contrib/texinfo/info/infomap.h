begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* infomap.h -- Description of a keymap in Info and related functions. */
end_comment

begin_comment
comment|/* This file is part of GNU Info, a program for reading online documentation    stored in Info format.     Copyright (C) 1993 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFOMAP_H
end_ifndef

begin_define
define|#
directive|define
name|INFOMAP_H
end_define

begin_include
include|#
directive|include
file|"info.h"
end_include

begin_define
define|#
directive|define
name|ESC
value|'\033'
end_define

begin_define
define|#
directive|define
name|DEL
value|'\177'
end_define

begin_define
define|#
directive|define
name|TAB
value|'\011'
end_define

begin_define
define|#
directive|define
name|RET
value|'\r'
end_define

begin_define
define|#
directive|define
name|LFD
value|'\n'
end_define

begin_define
define|#
directive|define
name|SPC
value|' '
end_define

begin_define
define|#
directive|define
name|meta_character_threshold
value|(DEL + 1)
end_define

begin_define
define|#
directive|define
name|control_character_threshold
value|(SPC)
end_define

begin_define
define|#
directive|define
name|meta_character_bit
value|0x80
end_define

begin_define
define|#
directive|define
name|control_character_bit
value|0x40
end_define

begin_define
define|#
directive|define
name|Meta_p
parameter_list|(
name|c
parameter_list|)
value|(((c)> meta_character_threshold))
end_define

begin_define
define|#
directive|define
name|Control_p
parameter_list|(
name|c
parameter_list|)
value|((c)< control_character_threshold)
end_define

begin_define
define|#
directive|define
name|Meta
parameter_list|(
name|c
parameter_list|)
value|((c) | (meta_character_bit))
end_define

begin_define
define|#
directive|define
name|UnMeta
parameter_list|(
name|c
parameter_list|)
value|((c)& (~meta_character_bit))
end_define

begin_define
define|#
directive|define
name|Control
parameter_list|(
name|c
parameter_list|)
value|((toupper (c))& (~control_character_bit))
end_define

begin_define
define|#
directive|define
name|UnControl
parameter_list|(
name|c
parameter_list|)
value|(tolower ((c) | control_character_bit))
end_define

begin_comment
comment|/* A keymap contains one entry for each key in the ASCII set.    Each entry consists of a type and a pointer.    FUNCTION is the address of a function to run, or the    address of a keymap to indirect through.    TYPE says which kind of thing FUNCTION is. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|type
decl_stmt|;
name|VFunction
modifier|*
name|function
decl_stmt|;
block|}
name|KEYMAP_ENTRY
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|KEYMAP_ENTRY
modifier|*
name|Keymap
typedef|;
end_typedef

begin_comment
comment|/* The values that TYPE can have in a keymap entry. */
end_comment

begin_define
define|#
directive|define
name|ISFUNC
value|0
end_define

begin_define
define|#
directive|define
name|ISKMAP
value|1
end_define

begin_decl_stmt
specifier|extern
name|Keymap
name|info_keymap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Keymap
name|echo_area_keymap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return a new keymap which has all the uppercase letters mapped to run    the function info_do_lowercase_version (). */
end_comment

begin_function_decl
specifier|extern
name|Keymap
name|keymap_make_keymap
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return a new keymap which is a copy of MAP. */
end_comment

begin_function_decl
specifier|extern
name|Keymap
name|keymap_copy_keymap
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Free MAP and it's descendents. */
end_comment

begin_function_decl
specifier|extern
name|void
name|keymap_discard_keymap
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize the info keymaps. */
end_comment

begin_function_decl
specifier|extern
name|void
name|initialize_info_keymaps
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not INFOMAP_H */
end_comment

end_unit

