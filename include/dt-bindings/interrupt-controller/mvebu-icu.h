begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for the MVEBU ICU driver.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_INTERRUPT_CONTROLLER_MVEBU_ICU_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_INTERRUPT_CONTROLLER_MVEBU_ICU_H
end_define

begin_comment
comment|/* interrupt specifier cell 0 */
end_comment

begin_define
define|#
directive|define
name|ICU_GRP_NSR
value|0x0
end_define

begin_define
define|#
directive|define
name|ICU_GRP_SR
value|0x1
end_define

begin_define
define|#
directive|define
name|ICU_GRP_SEI
value|0x4
end_define

begin_define
define|#
directive|define
name|ICU_GRP_REI
value|0x5
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

