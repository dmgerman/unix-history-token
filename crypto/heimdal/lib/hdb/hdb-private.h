begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is a generated file */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__hdb_private_h__
end_ifndef

begin_define
define|#
directive|define
name|__hdb_private_h__
end_define

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_function_decl
name|krb5_error_code
name|_hdb_fetch
parameter_list|(
name|krb5_context
comment|/*context*/
parameter_list|,
name|HDB
modifier|*
comment|/*db*/
parameter_list|,
name|unsigned
comment|/*flags*/
parameter_list|,
name|hdb_entry
modifier|*
comment|/*entry*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|_hdb_remove
parameter_list|(
name|krb5_context
comment|/*context*/
parameter_list|,
name|HDB
modifier|*
comment|/*db*/
parameter_list|,
name|hdb_entry
modifier|*
comment|/*entry*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|_hdb_store
parameter_list|(
name|krb5_context
comment|/*context*/
parameter_list|,
name|HDB
modifier|*
comment|/*db*/
parameter_list|,
name|unsigned
comment|/*flags*/
parameter_list|,
name|hdb_entry
modifier|*
comment|/*entry*/
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __hdb_private_h__ */
end_comment

end_unit

