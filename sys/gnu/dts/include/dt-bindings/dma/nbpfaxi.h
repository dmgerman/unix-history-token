begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2013-2014 Renesas Electronics Europe Ltd.  * Author: Guennadi Liakhovetski<g.liakhovetski@gmx.de>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DT_BINDINGS_NBPFAXI_H
end_ifndef

begin_define
define|#
directive|define
name|DT_BINDINGS_NBPFAXI_H
end_define

begin_comment
comment|/**  * Use "#dma-cells =<2>;" with the second integer defining slave DMA flags:  */
end_comment

begin_define
define|#
directive|define
name|NBPF_SLAVE_RQ_HIGH
value|1
end_define

begin_define
define|#
directive|define
name|NBPF_SLAVE_RQ_LOW
value|2
end_define

begin_define
define|#
directive|define
name|NBPF_SLAVE_RQ_LEVEL
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

