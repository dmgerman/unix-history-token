begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_TYPES
end_ifdef

begin_typedef
typedef|typedef
enum|enum
block|{
name|dss_prec_disabled
init|=
literal|0
block|,
name|dss_prec_primary
init|=
literal|1
block|,
name|dss_prec_secondary
init|=
literal|2
block|,
name|dss_prec_limit
init|=
literal|3
block|}
name|dss_prec_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DSS_PREC_DEFAULT
value|dss_prec_secondary
end_define

begin_define
define|#
directive|define
name|DSS_DEFAULT
value|"secondary"
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

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|dss_prec_names
index|[]
decl_stmt|;
end_decl_stmt

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
name|dss_prec_t
name|chunk_dss_prec_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|chunk_dss_prec_set
parameter_list|(
name|dss_prec_t
name|dss_prec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|chunk_alloc_dss
parameter_list|(
name|size_t
name|size
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
modifier|*
name|zero
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|chunk_in_dss
parameter_list|(
name|void
modifier|*
name|chunk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|chunk_dss_boot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chunk_dss_prefork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chunk_dss_postfork_parent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chunk_dss_postfork_child
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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

