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

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|krb5_error_code
name|_hdb_fetch
name|__P
argument_list|(
operator|(
name|krb5_context
name|context
operator|,
name|HDB
operator|*
name|db
operator|,
name|unsigned
name|flags
operator|,
name|hdb_entry
operator|*
name|entry
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|krb5_error_code
name|_hdb_remove
name|__P
argument_list|(
operator|(
name|krb5_context
name|context
operator|,
name|HDB
operator|*
name|db
operator|,
name|hdb_entry
operator|*
name|entry
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|krb5_error_code
name|_hdb_store
name|__P
argument_list|(
operator|(
name|krb5_context
name|context
operator|,
name|HDB
operator|*
name|db
operator|,
name|unsigned
name|flags
operator|,
name|hdb_entry
operator|*
name|entry
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __hdb_private_h__ */
end_comment

end_unit

