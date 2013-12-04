begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* -*- buffer-read-only: t -*- vi: set ro:  *  * Prototypes for autoopts  * Generated Fri Apr 29 15:44:06 PDT 2011  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|LOCAL
end_ifndef

begin_define
define|#
directive|define
name|LOCAL
value|extern
end_define

begin_define
define|#
directive|define
name|REDEF_LOCAL
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|REDEF_LOCAL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  Extracted from autoopts.c  */
end_comment

begin_function_decl
name|LOCAL
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
name|LOCAL
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
name|LOCAL
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
name|LOCAL
name|tSuccess
name|handle_opt
parameter_list|(
name|tOptions
modifier|*
name|pOpts
parameter_list|,
name|tOptState
modifier|*
name|pOptState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LOCAL
name|tSuccess
name|longOptionFind
parameter_list|(
name|tOptions
modifier|*
name|pOpts
parameter_list|,
name|char
modifier|*
name|pzOptName
parameter_list|,
name|tOptState
modifier|*
name|pOptState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LOCAL
name|tSuccess
name|shortOptionFind
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
name|LOCAL
name|tSuccess
name|doImmediateOpts
parameter_list|(
name|tOptions
modifier|*
name|pOpts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LOCAL
name|tSuccess
name|doRegularOpts
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
name|LOCAL
name|void
name|internalFileLoad
parameter_list|(
name|tOptions
modifier|*
name|pOpts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LOCAL
name|char
modifier|*
name|parseAttributes
parameter_list|(
name|tOptions
modifier|*
name|pOpts
parameter_list|,
name|char
modifier|*
name|pzText
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

begin_function_decl
name|LOCAL
name|tSuccess
name|validateOptionsStruct
parameter_list|(
name|tOptions
modifier|*
name|pOpts
parameter_list|,
name|char
specifier|const
modifier|*
name|pzProgram
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Extracted from environment.c  */
end_comment

begin_function_decl
name|LOCAL
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
name|LOCAL
name|void
name|doEnvPresets
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
comment|/*  *  Extracted from load.c  */
end_comment

begin_function_decl
name|LOCAL
name|void
name|mungeString
parameter_list|(
name|char
modifier|*
name|pzTxt
parameter_list|,
name|tOptionLoadMode
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LOCAL
name|void
name|loadOptionLine
parameter_list|(
name|tOptions
modifier|*
name|pOpts
parameter_list|,
name|tOptState
modifier|*
name|pOS
parameter_list|,
name|char
modifier|*
name|pzLine
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
comment|/*  *  Extracted from nested.c  */
end_comment

begin_function_decl
name|LOCAL
name|void
name|unload_arg_list
parameter_list|(
name|tArgList
modifier|*
name|pAL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LOCAL
name|tOptionValue
modifier|*
name|optionLoadNested
parameter_list|(
name|char
specifier|const
modifier|*
name|pzTxt
parameter_list|,
name|char
specifier|const
modifier|*
name|pzName
parameter_list|,
name|size_t
name|nameLen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LOCAL
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
name|LOCAL
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
name|LOCAL
name|void
name|optionSort
parameter_list|(
name|tOptions
modifier|*
name|pOpts
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Extracted from stack.c  */
end_comment

begin_function_decl
name|LOCAL
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

begin_ifdef
ifdef|#
directive|ifdef
name|REDEF_LOCAL
end_ifdef

begin_undef
undef|#
directive|undef
name|LOCAL
end_undef

begin_define
define|#
directive|define
name|LOCAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTOOPTS_PROTO_H_GUARD */
end_comment

end_unit

