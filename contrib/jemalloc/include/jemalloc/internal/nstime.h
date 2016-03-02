begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_TYPES
end_ifdef

begin_define
define|#
directive|define
name|JEMALLOC_CLOCK_GETTIME
value|defined(_POSIX_MONOTONIC_CLOCK) \&& _POSIX_MONOTONIC_CLOCK>= 0
end_define

begin_typedef
typedef|typedef
name|struct
name|nstime_s
name|nstime_t
typedef|;
end_typedef

begin_comment
comment|/* Maximum supported number of seconds (~584 years). */
end_comment

begin_define
define|#
directive|define
name|NSTIME_SEC_MAX
value|18446744072
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_TYPES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_STRUCTS
end_ifdef

begin_struct
struct|struct
name|nstime_s
block|{
name|uint64_t
name|ns
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_STRUCTS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_EXTERNS
end_ifdef

begin_function_decl
name|void
name|nstime_init
parameter_list|(
name|nstime_t
modifier|*
name|time
parameter_list|,
name|uint64_t
name|ns
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nstime_init2
parameter_list|(
name|nstime_t
modifier|*
name|time
parameter_list|,
name|uint64_t
name|sec
parameter_list|,
name|uint64_t
name|nsec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|nstime_ns
parameter_list|(
specifier|const
name|nstime_t
modifier|*
name|time
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|nstime_sec
parameter_list|(
specifier|const
name|nstime_t
modifier|*
name|time
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|nstime_nsec
parameter_list|(
specifier|const
name|nstime_t
modifier|*
name|time
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nstime_copy
parameter_list|(
name|nstime_t
modifier|*
name|time
parameter_list|,
specifier|const
name|nstime_t
modifier|*
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nstime_compare
parameter_list|(
specifier|const
name|nstime_t
modifier|*
name|a
parameter_list|,
specifier|const
name|nstime_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nstime_add
parameter_list|(
name|nstime_t
modifier|*
name|time
parameter_list|,
specifier|const
name|nstime_t
modifier|*
name|addend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nstime_subtract
parameter_list|(
name|nstime_t
modifier|*
name|time
parameter_list|,
specifier|const
name|nstime_t
modifier|*
name|subtrahend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nstime_imultiply
parameter_list|(
name|nstime_t
modifier|*
name|time
parameter_list|,
name|uint64_t
name|multiplier
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nstime_idivide
parameter_list|(
name|nstime_t
modifier|*
name|time
parameter_list|,
name|uint64_t
name|divisor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|nstime_divide
parameter_list|(
specifier|const
name|nstime_t
modifier|*
name|time
parameter_list|,
specifier|const
name|nstime_t
modifier|*
name|divisor
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_JET
end_ifdef

begin_typedef
typedef|typedef
name|bool
function_decl|(
name|nstime_update_t
function_decl|)
parameter_list|(
name|nstime_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|nstime_update_t
modifier|*
name|nstime_update
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
name|bool
name|nstime_update
parameter_list|(
name|nstime_t
modifier|*
name|time
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_EXTERNS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_INLINES
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_INLINES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

end_unit

