begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_sis_drm_public_h_
end_ifndef

begin_define
define|#
directive|define
name|_sis_drm_public_h_
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|context
decl_stmt|;
name|unsigned
name|int
name|offset
decl_stmt|;
name|unsigned
name|int
name|size
decl_stmt|;
name|unsigned
name|int
name|free
decl_stmt|;
block|}
name|drm_sis_mem_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|offset
decl_stmt|,
name|size
decl_stmt|;
block|}
name|drm_sis_agp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|left
decl_stmt|,
name|right
decl_stmt|;
block|}
name|drm_sis_flip_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_function_decl
name|int
name|sis_fb_alloc
parameter_list|(
name|DRM_OS_IOCTL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sis_fb_free
parameter_list|(
name|DRM_OS_IOCTL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sisp_agp_init
parameter_list|(
name|DRM_OS_IOCTL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sisp_agp_alloc
parameter_list|(
name|DRM_OS_IOCTL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sisp_agp_free
parameter_list|(
name|DRM_OS_IOCTL
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

end_unit

