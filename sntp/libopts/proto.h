begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* -*- buffer-read-only: t -*- vi: set ro:  *  * Prototypes for autoopts  * Generated Fri Aug  8 16:09:18 PDT 2014  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTOOPTS_PROTO_H_GUARD
end_ifndef

begin_define
define|#
directive|define
name|AUTOOPTS_PROTO_H_GUARD
value|1
end_define

begin_comment
comment|/*  *  Extracted from alias.c  */
end_comment

begin_function_decl
specifier|static
name|tSuccess
name|too_many_occurrences
parameter_list|(
name|tOptions
modifier|*
name|opts
parameter_list|,
name|tOptDesc
modifier|*
name|od
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Extracted from autoopts.c  */
end_comment

begin_function_decl
specifier|static
name|void
modifier|*
name|ao_malloc
parameter_list|(
name|size_t
name|sz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
modifier|*
name|ao_realloc
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|sz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|char
modifier|*
name|ao_strdup
parameter_list|(
name|char
specifier|const
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|tSuccess
name|handle_opt
parameter_list|(
name|tOptions
modifier|*
name|opts
parameter_list|,
name|tOptState
modifier|*
name|o_st
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|tSuccess
name|next_opt
parameter_list|(
name|tOptions
modifier|*
name|opts
parameter_list|,
name|tOptState
modifier|*
name|o_st
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|tSuccess
name|regular_opts
parameter_list|(
name|tOptions
modifier|*
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Extracted from check.c  */
end_comment

begin_function_decl
specifier|static
name|bool
name|is_consistent
parameter_list|(
name|tOptions
modifier|*
name|pOpts
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Extracted from configfile.c  */
end_comment

begin_function_decl
specifier|static
name|void
name|intern_file_load
parameter_list|(
name|tOptions
modifier|*
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|char
specifier|const
modifier|*
name|parse_attrs
parameter_list|(
name|tOptions
modifier|*
name|opts
parameter_list|,
name|char
specifier|const
modifier|*
name|txt
parameter_list|,
name|tOptionLoadMode
modifier|*
name|pMode
parameter_list|,
name|tOptionValue
modifier|*
name|pType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Extracted from env.c  */
end_comment

begin_function_decl
specifier|static
name|void
name|doPrognameEnv
parameter_list|(
name|tOptions
modifier|*
name|pOpts
parameter_list|,
name|teEnvPresetType
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|env_presets
parameter_list|(
name|tOptions
modifier|*
name|pOpts
parameter_list|,
name|teEnvPresetType
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Extracted from find.c  */
end_comment

begin_function_decl
specifier|static
name|tSuccess
name|opt_find_long
parameter_list|(
name|tOptions
modifier|*
name|opts
parameter_list|,
name|char
specifier|const
modifier|*
name|opt_name
parameter_list|,
name|tOptState
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|tSuccess
name|opt_find_short
parameter_list|(
name|tOptions
modifier|*
name|pOpts
parameter_list|,
name|uint_t
name|optValue
parameter_list|,
name|tOptState
modifier|*
name|pOptState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|tSuccess
name|get_opt_arg
parameter_list|(
name|tOptions
modifier|*
name|opts
parameter_list|,
name|tOptState
modifier|*
name|o_st
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|tSuccess
name|find_opt
parameter_list|(
name|tOptions
modifier|*
name|opts
parameter_list|,
name|tOptState
modifier|*
name|o_st
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Extracted from init.c  */
end_comment

begin_function_decl
specifier|static
name|tSuccess
name|validate_struct
parameter_list|(
name|tOptions
modifier|*
name|opts
parameter_list|,
name|char
specifier|const
modifier|*
name|pname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|tSuccess
name|immediate_opts
parameter_list|(
name|tOptions
modifier|*
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bool
name|ao_initialize
parameter_list|(
name|tOptions
modifier|*
name|opts
parameter_list|,
name|int
name|a_ct
parameter_list|,
name|char
modifier|*
modifier|*
name|a_v
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Extracted from load.c  */
end_comment

begin_function_decl
specifier|static
name|void
name|munge_str
parameter_list|(
name|char
modifier|*
name|txt
parameter_list|,
name|tOptionLoadMode
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|load_opt_line
parameter_list|(
name|tOptions
modifier|*
name|opts
parameter_list|,
name|tOptState
modifier|*
name|opt_state
parameter_list|,
name|char
modifier|*
name|line
parameter_list|,
name|tDirection
name|direction
parameter_list|,
name|tOptionLoadMode
name|load_mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Extracted from makeshell.c  */
end_comment

begin_function_decl
specifier|static
name|noreturn
name|void
name|option_exits
parameter_list|(
name|int
name|exit_code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|noreturn
name|void
name|ao_bug
parameter_list|(
name|char
specifier|const
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|fserr_warn
parameter_list|(
name|char
specifier|const
modifier|*
name|prog
parameter_list|,
name|char
specifier|const
modifier|*
name|op
parameter_list|,
name|char
specifier|const
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|noreturn
name|void
name|fserr_exit
parameter_list|(
name|char
specifier|const
modifier|*
name|prog
parameter_list|,
name|char
specifier|const
modifier|*
name|op
parameter_list|,
name|char
specifier|const
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Extracted from nested.c  */
end_comment

begin_function_decl
specifier|static
name|void
name|unload_arg_list
parameter_list|(
name|tArgList
modifier|*
name|arg_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|tOptionValue
modifier|*
name|optionLoadNested
parameter_list|(
name|char
specifier|const
modifier|*
name|text
parameter_list|,
name|char
specifier|const
modifier|*
name|name
parameter_list|,
name|size_t
name|nm_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|get_special_char
parameter_list|(
name|char
specifier|const
modifier|*
modifier|*
name|ppz
parameter_list|,
name|int
modifier|*
name|ct
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|emit_special_char
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|int
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Extracted from sort.c  */
end_comment

begin_function_decl
specifier|static
name|void
name|optionSort
parameter_list|(
name|tOptions
modifier|*
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Extracted from stack.c  */
end_comment

begin_function_decl
specifier|static
name|void
name|addArgListEntry
parameter_list|(
name|void
modifier|*
modifier|*
name|ppAL
parameter_list|,
name|void
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Extracted from usage.c  */
end_comment

begin_function_decl
specifier|static
name|void
name|set_usage_flags
parameter_list|(
name|tOptions
modifier|*
name|opts
parameter_list|,
name|char
specifier|const
modifier|*
name|flg_txt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTOOPTS_PROTO_H_GUARD */
end_comment

end_unit

