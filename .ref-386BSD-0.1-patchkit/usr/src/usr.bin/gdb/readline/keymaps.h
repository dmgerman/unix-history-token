begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* keymaps.h -- Manipulation of readline keymaps. */
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

begin_include
include|#
directive|include
file|<readline/chardefs.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__FUNCTION_DEF
end_ifndef

begin_typedef
typedef|typedef
name|int
name|Function
parameter_list|()
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|__FUNCTION_DEF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A keymap contains one entry for each key in the ASCII set.    Each entry consists of a type and a pointer.    POINTER is the address of a function to run, or the    address of a keymap to indirect through.    TYPE says which kind of thing POINTER is. */
end_comment

begin_typedef
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
end_typedef

begin_comment
comment|/* I wanted to make the above structure contain a union of:    union { Function *function; struct _keymap_entry *keymap; } value;    but this made it impossible for me to create a static array.    Maybe I need C lessons. */
end_comment

begin_typedef
typedef|typedef
name|KEYMAP_ENTRY
name|KEYMAP_ENTRY_ARRAY
index|[
literal|128
index|]
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

begin_define
define|#
directive|define
name|ISMACR
value|2
end_define

begin_decl_stmt
specifier|extern
name|KEYMAP_ENTRY_ARRAY
name|emacs_standard_keymap
decl_stmt|,
name|emacs_meta_keymap
decl_stmt|,
name|emacs_ctlx_keymap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KEYMAP_ENTRY_ARRAY
name|vi_insertion_keymap
decl_stmt|,
name|vi_movement_keymap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return a new, empty keymap.    Free it with free() when you are done. */
end_comment

begin_function_decl
name|Keymap
name|rl_make_bare_keymap
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return a new keymap which is a copy of MAP. */
end_comment

begin_function_decl
name|Keymap
name|rl_copy_keymap
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return a new keymap with the printing characters bound to rl_insert,    the lowercase Meta characters bound to run their equivalents, and    the Meta digits bound to produce numeric arguments. */
end_comment

begin_function_decl
name|Keymap
name|rl_make_keymap
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KEYMAPS_H_ */
end_comment

end_unit

