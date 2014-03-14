begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__RADEON_GEM_H__
end_ifndef

begin_define
define|#
directive|define
name|__RADEON_GEM_H__
end_define

begin_include
include|#
directive|include
file|<dev/drm2/drmP.h>
end_include

begin_function_decl
name|int
name|radeon_gem_object_init
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|radeon_gem_object_free
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|radeon_gem_object_open
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|radeon_gem_object_close
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(__RADEON_GEM_H__) */
end_comment

end_unit

