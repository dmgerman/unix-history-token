begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2016 Glider bvba  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; version 2 of the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_POWER_R8A7795_SYSC_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_POWER_R8A7795_SYSC_H__
end_define

begin_comment
comment|/*  * These power domain indices match the numbers of the interrupt bits  * representing the power areas in the various Interrupt Registers  * (e.g. SYSCISR, Interrupt Status Register)  */
end_comment

begin_define
define|#
directive|define
name|R8A7795_PD_CA57_CPU0
value|0
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_CA57_CPU1
value|1
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_CA57_CPU2
value|2
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_CA57_CPU3
value|3
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_CA53_CPU0
value|5
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_CA53_CPU1
value|6
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_CA53_CPU2
value|7
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_CA53_CPU3
value|8
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_A3VP
value|9
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_CA57_SCU
value|12
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_CR7
value|13
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_A3VC
value|14
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_3DG_A
value|17
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_3DG_B
value|18
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_3DG_C
value|19
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_3DG_D
value|20
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_CA53_SCU
value|21
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_3DG_E
value|22
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_A3IR
value|24
end_define

begin_define
define|#
directive|define
name|R8A7795_PD_A2VC0
value|25
end_define

begin_comment
comment|/* ES1.x only */
end_comment

begin_define
define|#
directive|define
name|R8A7795_PD_A2VC1
value|26
end_define

begin_comment
comment|/* Always-on power area */
end_comment

begin_define
define|#
directive|define
name|R8A7795_PD_ALWAYS_ON
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_POWER_R8A7795_SYSC_H__ */
end_comment

end_unit

