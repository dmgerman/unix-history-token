begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Qualcomm Atheros vendor specific attribute definitions  * Copyright (c) 2014, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QCA_VENDOR_ATTR_H
end_ifndef

begin_define
define|#
directive|define
name|QCA_VENDOR_ATTR_H
end_define

begin_comment
comment|/*  * This file defines some of the attributes used with Qualcomm Atheros OUI  * 00:13:74 in a way that is not suitable for qca-vendor.h, e.g., due to  * compiler dependencies.  */
end_comment

begin_struct
struct|struct
name|qca_avoid_freq_range
block|{
name|u32
name|start_freq
decl_stmt|;
name|u32
name|end_freq
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|qca_avoid_freq_list
block|{
name|u32
name|count
decl_stmt|;
name|struct
name|qca_avoid_freq_range
name|range
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* QCA_VENDOR_ATTR_H */
end_comment

end_unit

