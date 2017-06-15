begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_HOOKS_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_HOOKS_H
end_define

begin_function_decl
specifier|extern
name|JEMALLOC_EXPORT
name|void
function_decl|(
modifier|*
name|hooks_arena_new_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|JEMALLOC_EXPORT
name|void
function_decl|(
modifier|*
name|hooks_libc_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|JEMALLOC_HOOK
parameter_list|(
name|fn
parameter_list|,
name|hook
parameter_list|)
value|((void)(hook != NULL&& (hook(), 0)), fn)
end_define

begin_comment
comment|/* Note that this is undef'd and re-define'd in src/prof.c. */
end_comment

begin_define
define|#
directive|define
name|_Unwind_Backtrace
value|JEMALLOC_HOOK(_Unwind_Backtrace, hooks_libc_hook)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_HOOKS_H */
end_comment

end_unit

