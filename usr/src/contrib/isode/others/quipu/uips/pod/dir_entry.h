begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|ENTRYSEQ
end_ifndef

begin_define
define|#
directive|define
name|ENTRYSEQ
end_define

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<X11/Intrinsic.h>
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|QUIPU_MALLOC
end_ifdef

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|smalloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|mod_vals
block|{
name|char
modifier|*
name|value
decl_stmt|;
name|char
modifier|*
name|new_value
decl_stmt|;
name|Widget
name|text_widg
decl_stmt|;
name|bool
name|mod_flag
decl_stmt|;
name|struct
name|dir_attrs
modifier|*
name|attr
decl_stmt|;
name|struct
name|mod_vals
modifier|*
name|next
decl_stmt|;
block|}
name|mod_vals
operator|,
typedef|*
name|modVals
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dir_attrs
block|{
name|char
modifier|*
name|attr_name
decl_stmt|;
name|modVals
name|val_seq
decl_stmt|;
name|bool
name|mod_flag
decl_stmt|;
name|bool
name|in_flag
decl_stmt|;
name|bool
name|hidden_flag
decl_stmt|;
name|struct
name|dir_attrs
modifier|*
name|next
decl_stmt|;
block|}
name|dir_attrs
operator|,
typedef|*
name|dirAttrs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dir_entry
block|{
name|char
modifier|*
name|entry_name
decl_stmt|;
name|dirAttrs
name|attrs
decl_stmt|;
name|bool
name|mod_flag
decl_stmt|;
block|}
name|dir_entry
operator|,
typedef|*
name|dirEntry
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLDIRENTRY
value|((dirEntry) 0)
end_define

begin_function_decl
name|int
name|free_dir_entry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|free_ent_attrs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|free_mod_vals
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

