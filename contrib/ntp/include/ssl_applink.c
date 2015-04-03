begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * include/ssl_applink.c -- common NTP code for openssl/applink.c  *  * Each program which uses OpenSSL should include this file in _one_  * of its source files and call ssl_applink() before any OpenSSL  * functions.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OPENSSL
argument_list|)
operator|&&
name|defined
argument_list|(
name|SYS_WINNT
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4152
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<openssl/applink.c>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OPENSSL
argument_list|)
operator|&&
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|defined
argument_list|(
name|_DEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|WRAP_DBG_MALLOC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WRAP_DBG_MALLOC
end_ifdef

begin_function_decl
name|void
modifier|*
name|wrap_dbg_malloc
parameter_list|(
name|size_t
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|f
parameter_list|,
name|int
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|wrap_dbg_realloc
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|f
parameter_list|,
name|int
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wrap_dbg_free
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OPENSSL
argument_list|)
operator|&&
name|defined
argument_list|(
name|SYS_WINNT
argument_list|)
end_if

begin_function_decl
name|void
name|ssl_applink
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|ssl_applink
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|WRAP_DBG_MALLOC
name|CRYPTO_set_mem_ex_functions
argument_list|(
name|wrap_dbg_malloc
argument_list|,
name|wrap_dbg_realloc
argument_list|,
name|wrap_dbg_free
argument_list|)
expr_stmt|;
else|#
directive|else
name|CRYPTO_malloc_init
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !OPENSSL || !SYS_WINNT */
end_comment

begin_define
define|#
directive|define
name|ssl_applink
parameter_list|()
value|do {} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WRAP_DBG_MALLOC
end_ifdef

begin_comment
comment|/*  * OpenSSL malloc overriding uses different parameters  * for DEBUG malloc/realloc/free (lacking block type).  * Simple wrappers convert.  */
end_comment

begin_function
name|void
modifier|*
name|wrap_dbg_malloc
parameter_list|(
name|size_t
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|f
parameter_list|,
name|int
name|l
parameter_list|)
block|{
name|void
modifier|*
name|ret
decl_stmt|;
name|ret
operator|=
name|_malloc_dbg
argument_list|(
name|s
argument_list|,
name|_NORMAL_BLOCK
argument_list|,
name|f
argument_list|,
name|l
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|wrap_dbg_realloc
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|f
parameter_list|,
name|int
name|l
parameter_list|)
block|{
name|void
modifier|*
name|ret
decl_stmt|;
name|ret
operator|=
name|_realloc_dbg
argument_list|(
name|p
argument_list|,
name|s
argument_list|,
name|_NORMAL_BLOCK
argument_list|,
name|f
argument_list|,
name|l
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
name|void
name|wrap_dbg_free
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
name|_free_dbg
argument_list|(
name|p
argument_list|,
name|_NORMAL_BLOCK
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WRAP_DBG_MALLOC */
end_comment

end_unit

