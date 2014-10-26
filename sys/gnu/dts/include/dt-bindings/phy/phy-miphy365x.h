begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for the phy framework  * based on the STMicroelectronics MiPHY365x.  *  * Author: Lee Jones<lee.jones@linaro.org>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_PHY_MIPHY
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_PHY_MIPHY
end_define

begin_define
define|#
directive|define
name|MIPHY_TYPE_SATA
value|1
end_define

begin_define
define|#
directive|define
name|MIPHY_TYPE_PCIE
value|2
end_define

begin_define
define|#
directive|define
name|MIPHY_TYPE_USB
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_PHY_MIPHY */
end_comment

end_unit

