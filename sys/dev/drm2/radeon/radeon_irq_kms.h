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
name|__RADEON_IRQ_KMS_H__
end_ifndef

begin_define
define|#
directive|define
name|__RADEON_IRQ_KMS_H__
end_define

begin_function_decl
name|irqreturn_t
name|radeon_driver_irq_handler_kms
parameter_list|(
name|DRM_IRQ_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|radeon_driver_irq_preinstall_kms
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|radeon_driver_irq_postinstall_kms
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|radeon_driver_irq_uninstall_kms
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|radeon_msi_ok
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|long
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(__RADEON_IRQ_KMS_H__) */
end_comment

end_unit

