begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_CHIPC_CHIPCVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_CHIPC_CHIPCVAR_H_
end_define

begin_include
include|#
directive|include
file|"chipc.h"
end_include

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|bhnd_chipc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|bhnd_chipc_devclass
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CHIPC_MAX_RES
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_MAX_RSPEC
value|(CHIPC_MAX_RES+1)
end_define

begin_comment
comment|/*   * ChipCommon device quirks / features  */
end_comment

begin_enum
enum|enum
block|{
comment|/** No quirks */
name|CHIPC_QUIRK_NONE
init|=
literal|0
block|,
comment|/** 	 * The device always provides an external SROM. 	 */
name|CHIPC_QUIRK_ALWAYS_HAS_SPROM
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|/** 	 * SROM availability must be determined through chip-specific 	 * ChipStatus flags. 	 */
name|CHIPC_QUIRK_SPROM_CHECK_CHIPST
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
comment|/** 	 * Use the rev22 chipstatus register format when determining SPROM 	 * availability. 	 */
name|CHIPC_QUIRK_SPROM_CHECK_CST_R22
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
operator||
name|CHIPC_QUIRK_SPROM_CHECK_CHIPST
block|,
comment|/** 	 * Use the rev23 chipstatus register format when determining SPROM 	 * availability. 	 */
name|CHIPC_QUIRK_SPROM_CHECK_CST_R23
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
operator||
name|CHIPC_QUIRK_SPROM_CHECK_CHIPST
block|,
comment|/** 	 * External NAND NVRAM is supported, along with the CHIPC_CAP_NFLASH 	 * capability flag. 	 */
name|CHIPC_QUIRK_SUPPORTS_NFLASH
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|chipc_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|resource_spec
name|rspec
index|[
name|CHIPC_MAX_RSPEC
index|]
decl_stmt|;
name|struct
name|bhnd_resource
modifier|*
name|res
index|[
name|CHIPC_MAX_RES
index|]
decl_stmt|;
name|struct
name|bhnd_resource
modifier|*
name|core
decl_stmt|;
comment|/**< core registers. */
name|struct
name|bhnd_chipid
name|ccid
decl_stmt|;
comment|/**< chip identification */
name|uint32_t
name|quirks
decl_stmt|;
comment|/**< CHIPC_QUIRK_* quirk flags */
name|uint32_t
name|caps
decl_stmt|;
comment|/**< CHIPC_CAP_* capability register flags */
name|uint32_t
name|cst
decl_stmt|;
comment|/**< CHIPC_CST* status register flags */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_CHIPC_CHIPCVAR_H_ */
end_comment

end_unit

