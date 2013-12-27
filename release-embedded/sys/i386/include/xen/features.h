begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * features.h  *  * Query the features reported by Xen.  *  * Copyright (c) 2006, Ian Campbell  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASM_XEN_FEATURES_H__
end_ifndef

begin_define
define|#
directive|define
name|__ASM_XEN_FEATURES_H__
end_define

begin_include
include|#
directive|include
file|<xen/interface/version.h>
end_include

begin_function_decl
specifier|extern
name|void
name|setup_xen_features
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|uint8_t
name|xen_features
index|[
name|XENFEAT_NR_SUBMAPS
operator|*
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|xen_feature
parameter_list|(
name|flag
parameter_list|)
value|(xen_features[flag])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASM_XEN_FEATURES_H__ */
end_comment

end_unit

