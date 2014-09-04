begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for AT91 pmc status.  *  * The constants defined in this header are being used in dts.  *  * Licensed under GPLv2 or later.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_AT91_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_AT91_H
end_define

begin_define
define|#
directive|define
name|AT91_PMC_MOSCS
value|0
end_define

begin_comment
comment|/* MOSCS Flag */
end_comment

begin_define
define|#
directive|define
name|AT91_PMC_LOCKA
value|1
end_define

begin_comment
comment|/* PLLA Lock */
end_comment

begin_define
define|#
directive|define
name|AT91_PMC_LOCKB
value|2
end_define

begin_comment
comment|/* PLLB Lock */
end_comment

begin_define
define|#
directive|define
name|AT91_PMC_MCKRDY
value|3
end_define

begin_comment
comment|/* Master Clock */
end_comment

begin_define
define|#
directive|define
name|AT91_PMC_LOCKU
value|6
end_define

begin_comment
comment|/* UPLL Lock */
end_comment

begin_define
define|#
directive|define
name|AT91_PMC_PCKRDY
parameter_list|(
name|id
parameter_list|)
value|(8 + (id))
end_define

begin_comment
comment|/* Programmable Clock */
end_comment

begin_define
define|#
directive|define
name|AT91_PMC_MOSCSELS
value|16
end_define

begin_comment
comment|/* Main Oscillator Selection */
end_comment

begin_define
define|#
directive|define
name|AT91_PMC_MOSCRCS
value|17
end_define

begin_comment
comment|/* Main On-Chip RC */
end_comment

begin_define
define|#
directive|define
name|AT91_PMC_CFDEV
value|18
end_define

begin_comment
comment|/* Clock Failure Detector Event */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

