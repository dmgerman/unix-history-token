begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SIS_DRM_H__
end_ifndef

begin_define
define|#
directive|define
name|__SIS_DRM_H__
end_define

begin_comment
comment|/* SiS specific ioctls */
end_comment

begin_define
define|#
directive|define
name|DRM_IOCTL_SIS_FB_ALLOC
value|DRM_IOWR(0x44, drm_sis_mem_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SIS_FB_FREE
value|DRM_IOW( 0x45, drm_sis_mem_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SIS_AGP_INIT
value|DRM_IOWR(0x53, drm_sis_agp_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SIS_AGP_ALLOC
value|DRM_IOWR(0x54, drm_sis_mem_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SIS_AGP_FREE
value|DRM_IOW( 0x55, drm_sis_mem_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SIS_FB_INIT
value|DRM_IOW( 0x56, drm_sis_fb_t)
end_define

begin_comment
comment|/* #define DRM_IOCTL_SIS_FLIP		DRM_IOW( 0x48, drm_sis_flip_t) #define DRM_IOCTL_SIS_FLIP_INIT		DRM_IO(  0x49) #define DRM_IOCTL_SIS_FLIP_FINAL	DRM_IO(  0x50) */
end_comment

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
name|long
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
name|offset
decl_stmt|,
name|size
decl_stmt|;
block|}
name|drm_sis_fb_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SIS_DRM_H__ */
end_comment

end_unit

