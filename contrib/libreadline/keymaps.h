begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* keymaps.h -- Manipulation of readline keymaps. */
end_comment

begin_comment
comment|/* Copyright (C) 1987, 1989, 1992 Free Software Foundation, Inc.     This file is part of the GNU Readline Library, a library for    reading lines of text with interactive input and history editing.     The GNU Readline Library is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License    as published by the Free Software Foundation; either version 2, or    (at your option) any later version.     The GNU Readline Library is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KEYMAPS_H_
end_ifndef

begin_define
define|#
directive|define
name|_KEYMAPS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|READLINE_LIBRARY
argument_list|)
include|#
directive|include
file|"rlstdc.h"
include|#
directive|include
file|"chardefs.h"
else|#
directive|else
include|#
directive|include
file|<readline/rlstdc.h>
include|#
directive|include
file|<readline/chardefs.h>
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_FUNCTION_DEF
argument_list|)
define|#
directive|define
name|_FUNCTION_DEF
typedef|typedef
name|int
name|Function
parameter_list|()
function_decl|;
typedef|typedef
name|void
name|VFunction
parameter_list|()
function_decl|;
typedef|typedef
name|char
modifier|*
name|CPFunction
parameter_list|()
function_decl|;
typedef|typedef
name|char
modifier|*
modifier|*
name|CPPFunction
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|/* A keymap contains one entry for each key in the ASCII set.    Each entry consists of a type and a pointer.    FUNCTION is the address of a function to run, or the    address of a keymap to indirect through.    TYPE says which kind of thing FUNCTION is. */
typedef|typedef
struct|struct
name|_keymap_entry
block|{
name|char
name|type
decl_stmt|;
name|Function
modifier|*
name|function
decl_stmt|;
block|}
name|KEYMAP_ENTRY
typedef|;
comment|/* This must be large enough to hold bindings for all of the characters    in a desired character set (e.g, 128 for ASCII, 256 for ISO Latin-x,    and so on). */
define|#
directive|define
name|KEYMAP_SIZE
value|256
comment|/* I wanted to make the above structure contain a union of:    union { Function *function; struct _keymap_entry *keymap; } value;    but this made it impossible for me to create a static array.    Maybe I need C lessons. */
typedef|typedef
name|KEYMAP_ENTRY
name|KEYMAP_ENTRY_ARRAY
index|[
name|KEYMAP_SIZE
index|]
typedef|;
typedef|typedef
name|KEYMAP_ENTRY
modifier|*
name|Keymap
typedef|;
comment|/* The values that TYPE can have in a keymap entry. */
define|#
directive|define
name|ISFUNC
value|0
define|#
directive|define
name|ISKMAP
value|1
define|#
directive|define
name|ISMACR
value|2
specifier|extern
name|KEYMAP_ENTRY_ARRAY
name|emacs_standard_keymap
decl_stmt|,
name|emacs_meta_keymap
decl_stmt|,
name|emacs_ctlx_keymap
decl_stmt|;
specifier|extern
name|KEYMAP_ENTRY_ARRAY
name|vi_insertion_keymap
decl_stmt|,
name|vi_movement_keymap
decl_stmt|;
comment|/* Return a new, empty keymap.    Free it with free() when you are done. */
specifier|extern
name|Keymap
name|rl_make_bare_keymap
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
comment|/* Return a new keymap which is a copy of MAP. */
specifier|extern
name|Keymap
name|rl_copy_keymap
name|__P
argument_list|(
operator|(
name|Keymap
operator|)
argument_list|)
decl_stmt|;
comment|/* Return a new keymap with the printing characters bound to rl_insert,    the lowercase Meta characters bound to run their equivalents, and    the Meta digits bound to produce numeric arguments. */
specifier|extern
name|Keymap
name|rl_make_keymap
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
comment|/* Free the storage associated with a keymap. */
specifier|extern
name|void
name|rl_discard_keymap
name|__P
argument_list|(
operator|(
name|Keymap
operator|)
argument_list|)
decl_stmt|;
comment|/* These functions actually appear in bind.c */
comment|/* Return the keymap corresponding to a given name.  Names look like    `emacs' or `emacs-meta' or `vi-insert'.  */
specifier|extern
name|Keymap
name|rl_get_keymap_by_name
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Return the current keymap. */
specifier|extern
name|Keymap
name|rl_get_keymap
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
comment|/* Set the current keymap to MAP. */
specifier|extern
name|void
name|rl_set_keymap
name|__P
argument_list|(
operator|(
name|Keymap
operator|)
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KEYMAPS_H_ */
end_comment

end_unit

