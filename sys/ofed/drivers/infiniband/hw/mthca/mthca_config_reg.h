begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Topspin Communications.  All rights reserved.  * Copyright (c) 2005 Mellanox Technologies. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MTHCA_CONFIG_REG_H
end_ifndef

begin_define
define|#
directive|define
name|MTHCA_CONFIG_REG_H
end_define

begin_include
include|#
directive|include
file|<linux/page.h>
end_include

begin_define
define|#
directive|define
name|MTHCA_HCR_BASE
value|0x80680
end_define

begin_define
define|#
directive|define
name|MTHCA_HCR_SIZE
value|0x0001c
end_define

begin_define
define|#
directive|define
name|MTHCA_ECR_BASE
value|0x80700
end_define

begin_define
define|#
directive|define
name|MTHCA_ECR_SIZE
value|0x00008
end_define

begin_define
define|#
directive|define
name|MTHCA_ECR_CLR_BASE
value|0x80708
end_define

begin_define
define|#
directive|define
name|MTHCA_ECR_CLR_SIZE
value|0x00008
end_define

begin_define
define|#
directive|define
name|MTHCA_MAP_ECR_SIZE
value|(MTHCA_ECR_SIZE + MTHCA_ECR_CLR_SIZE)
end_define

begin_define
define|#
directive|define
name|MTHCA_CLR_INT_BASE
value|0xf00d8
end_define

begin_define
define|#
directive|define
name|MTHCA_CLR_INT_SIZE
value|0x00008
end_define

begin_define
define|#
directive|define
name|MTHCA_EQ_SET_CI_SIZE
value|(8 * 32)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MTHCA_CONFIG_REG_H */
end_comment

end_unit

