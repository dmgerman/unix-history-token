begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_comment
comment|/*  * This header provides constants for configuring the I.MX25 ADC  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_IIO_ADC_FS_IMX25_GCQ_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_IIO_ADC_FS_IMX25_GCQ_H
end_define

begin_define
define|#
directive|define
name|MX25_ADC_REFP_YP
value|0
end_define

begin_comment
comment|/* YP voltage reference */
end_comment

begin_define
define|#
directive|define
name|MX25_ADC_REFP_XP
value|1
end_define

begin_comment
comment|/* XP voltage reference */
end_comment

begin_define
define|#
directive|define
name|MX25_ADC_REFP_EXT
value|2
end_define

begin_comment
comment|/* External voltage reference */
end_comment

begin_define
define|#
directive|define
name|MX25_ADC_REFP_INT
value|3
end_define

begin_comment
comment|/* Internal voltage reference */
end_comment

begin_define
define|#
directive|define
name|MX25_ADC_REFN_XN
value|0
end_define

begin_comment
comment|/* XN ground reference */
end_comment

begin_define
define|#
directive|define
name|MX25_ADC_REFN_YN
value|1
end_define

begin_comment
comment|/* YN ground reference */
end_comment

begin_define
define|#
directive|define
name|MX25_ADC_REFN_NGND
value|2
end_define

begin_comment
comment|/* Internal ground reference */
end_comment

begin_define
define|#
directive|define
name|MX25_ADC_REFN_NGND2
value|3
end_define

begin_comment
comment|/* External ground reference */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

