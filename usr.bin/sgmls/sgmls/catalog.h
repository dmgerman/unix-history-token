begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|CATALOG_H
end_ifndef

begin_define
define|#
directive|define
name|CATALOG_H
value|1
end_define

begin_enum
enum|enum
name|catalog_decl_type
block|{
name|CATALOG_NO_DECL
init|=
operator|-
literal|1
block|,
name|CATALOG_ENTITY_DECL
block|,
name|CATALOG_DOCTYPE_DECL
block|,
name|CATALOG_LINKTYPE_DECL
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|CATALOG_SYSTEM_ERROR
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_typedef
typedef|typedef
name|void
modifier|*
name|CATALOG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|CATALOG_ERROR_HANDLER
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|unsigned
name|long
name|lineno
parameter_list|,
name|int
name|error_number
parameter_list|,
name|unsigned
name|flags
parameter_list|,
name|int
name|sys_errno
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|CATALOG
name|catalog_create
parameter_list|(
name|CATALOG_ERROR_HANDLER
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|catalog_load_file
parameter_list|(
name|CATALOG
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|catalog_delete
parameter_list|(
name|CATALOG
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|catalog_lookup_entity
parameter_list|(
name|CATALOG
parameter_list|,
specifier|const
name|char
modifier|*
name|public_id
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|enum
name|catalog_decl_type
parameter_list|,
specifier|const
name|char
modifier|*
name|subst_table
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|system_id
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|catalog_file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|catalog_error_text
parameter_list|(
name|int
name|error_number
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|CATALOG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|CATALOG_ERROR_HANDLER
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_function_decl
name|CATALOG
name|catalog_create
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|catalog_load_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|catalog_delete
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|catalog_lookup_entity
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|catalog_error_text
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not CATALOG_H */
end_comment

end_unit

