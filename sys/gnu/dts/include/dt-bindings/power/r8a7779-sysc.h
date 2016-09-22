begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2016 Glider bvba  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; version 2 of the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_POWER_R8A7779_SYSC_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_POWER_R8A7779_SYSC_H__
end_define

begin_comment
comment|/*  * These power domain indices match the numbers of the interrupt bits  * representing the power areas in the various Interrupt Registers  * (e.g. SYSCISR, Interrupt Status Register)  */
end_comment

begin_define
define|#
directive|define
name|R8A7779_PD_ARM1
value|1
end_define

begin_define
define|#
directive|define
name|R8A7779_PD_ARM2
value|2
end_define

begin_define
define|#
directive|define
name|R8A7779_PD_ARM3
value|3
end_define

begin_define
define|#
directive|define
name|R8A7779_PD_SGX
value|20
end_define

begin_define
define|#
directive|define
name|R8A7779_PD_VDP
value|21
end_define

begin_define
define|#
directive|define
name|R8A7779_PD_IMP
value|24
end_define

begin_comment
comment|/* Always-on power area */
end_comment

begin_define
define|#
directive|define
name|R8A7779_PD_ALWAYS_ON
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_POWER_R8A7779_SYSC_H__ */
end_comment

end_unit

