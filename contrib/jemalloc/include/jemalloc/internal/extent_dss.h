begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_EXTENT_DSS_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_EXTENT_DSS_H
end_define

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

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|dss_prec_names
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|opt_dss
decl_stmt|;
end_decl_stmt

begin_function_decl
name|dss_prec_t
name|extent_dss_prec_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|extent_dss_prec_set
parameter_list|(
name|dss_prec_t
name|dss_prec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|extent_alloc_dss
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|,
name|void
modifier|*
name|new_addr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
modifier|*
name|zero
parameter_list|,
name|bool
modifier|*
name|commit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|extent_in_dss
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|extent_dss_mergeable
parameter_list|(
name|void
modifier|*
name|addr_a
parameter_list|,
name|void
modifier|*
name|addr_b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|extent_dss_boot
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
comment|/* JEMALLOC_INTERNAL_EXTENT_DSS_H */
end_comment

end_unit

