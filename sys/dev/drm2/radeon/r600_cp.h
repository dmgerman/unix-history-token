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
name|__R600_CP_H__
end_ifndef

begin_define
define|#
directive|define
name|__R600_CP_H__
end_define

begin_function_decl
name|void
name|r600_cs_legacy_get_tiling_conf
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|u32
modifier|*
name|npipes
parameter_list|,
name|u32
modifier|*
name|nbanks
parameter_list|,
name|u32
modifier|*
name|group_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|r600_cs_legacy
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|filp
parameter_list|,
name|unsigned
name|family
parameter_list|,
name|u32
modifier|*
name|ib
parameter_list|,
name|int
modifier|*
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r600_cs_legacy_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(__R600_CP_H__) */
end_comment

end_unit

