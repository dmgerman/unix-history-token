begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * This header provides constants for the phy framework  *  * Copyright (C) 2014 STMicroelectronics  * Author: Gabriel Fernandez<gabriel.fernandez@st.com>  * License terms:  GNU General Public License (GPL), version 2  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_PHY
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_PHY
end_define

begin_define
define|#
directive|define
name|PHY_NONE
value|0
end_define

begin_define
define|#
directive|define
name|PHY_TYPE_SATA
value|1
end_define

begin_define
define|#
directive|define
name|PHY_TYPE_PCIE
value|2
end_define

begin_define
define|#
directive|define
name|PHY_TYPE_USB2
value|3
end_define

begin_define
define|#
directive|define
name|PHY_TYPE_USB3
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_PHY */
end_comment

end_unit

