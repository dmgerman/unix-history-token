begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_TSD_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_TSD_TYPES_H
end_define

begin_define
define|#
directive|define
name|MALLOC_TSD_CLEANUPS_MAX
value|2
end_define

begin_typedef
typedef|typedef
name|struct
name|tsd_s
name|tsd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|tsdn_s
name|tsdn_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|bool
function_decl|(
modifier|*
name|malloc_tsd_cleanup_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_TSD_TYPES_H */
end_comment

end_unit

