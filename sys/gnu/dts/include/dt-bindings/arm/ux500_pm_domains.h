begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2014 Linaro Ltd.  *  * Author: Ulf Hansson<ulf.hansson@linaro.org>  * License terms: GNU General Public License (GPL) version 2  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_ARM_UX500_PM_DOMAINS_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_ARM_UX500_PM_DOMAINS_H
end_define

begin_define
define|#
directive|define
name|DOMAIN_VAPE
value|0
end_define

begin_comment
comment|/* Number of PM domains. */
end_comment

begin_define
define|#
directive|define
name|NR_DOMAINS
value|(DOMAIN_VAPE + 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

