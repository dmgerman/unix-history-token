begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * @(#)dlfcn.h	1.4 revision of 95/04/25  09:36:52  * This is an unpublished work copyright (c) 1992 HELIOS Software GmbH  * 30159 Hannover, Germany  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__dlfcn_h__
end_ifndef

begin_define
define|#
directive|define
name|__dlfcn_h__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  * Mode flags for the dlopen routine.  */
define|#
directive|define
name|RTLD_LAZY
value|1
comment|/* lazy function call binding */
define|#
directive|define
name|RTLD_NOW
value|2
comment|/* immediate function call binding */
define|#
directive|define
name|RTLD_GLOBAL
value|0x100
comment|/* allow symbols to be global */
comment|/*  * To be able to intialize, a library may provide a dl_info structure  * that contains functions to be called to initialize and terminate.  */
struct|struct
name|dl_info
block|{
name|void
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|fini
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
struct|;
if|#
directive|if
name|__STDC__
operator|||
name|defined
argument_list|(
name|_IBMR2
argument_list|)
name|void
modifier|*
name|dlopen
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
name|void
modifier|*
name|dlsym
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
name|symbol
parameter_list|)
function_decl|;
name|char
modifier|*
name|dlerror
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|dlclose
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
else|#
directive|else
name|void
modifier|*
name|dlopen
parameter_list|()
function_decl|;
name|void
modifier|*
name|dlsym
parameter_list|()
function_decl|;
name|char
modifier|*
name|dlerror
parameter_list|()
function_decl|;
name|int
name|dlclose
parameter_list|()
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __dlfcn_h__ */
end_comment

end_unit

