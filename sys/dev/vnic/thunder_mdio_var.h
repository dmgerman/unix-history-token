begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Semihalf under  * the sponsorship of the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__THUNDER_MDIO_VAR_H__
end_ifndef

begin_define
define|#
directive|define
name|__THUNDER_MDIO_VAR_H__
end_define

begin_define
define|#
directive|define
name|THUNDER_MDIO_DEVSTR
value|"Cavium ThunderX SMI/MDIO driver"
end_define

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|thunder_mdio_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_enum
enum|enum
name|thunder_mdio_mode
block|{
name|MODE_NONE
init|=
literal|0
block|,
name|MODE_IEEE_C22
block|,
name|MODE_IEEE_C45
block|}
enum|;
end_enum

begin_struct
struct|struct
name|phy_desc
block|{
name|device_t
name|miibus
decl_stmt|;
comment|/* One miibus per LMAC */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* Fake ifp to satisfy miibus */
name|int
name|lmacid
decl_stmt|;
comment|/* ID number of LMAC connected */
name|TAILQ_ENTRY
argument_list|(
argument|phy_desc
argument_list|)
name|phy_desc_list
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|thunder_mdio_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
name|struct
name|resource
modifier|*
name|reg_base
decl_stmt|;
name|enum
name|thunder_mdio_mode
name|mode
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|phy_desc
argument_list|)
name|phy_desc_head
expr_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|thunder_mdio_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

