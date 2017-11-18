begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_comment
comment|/*  * This header provides constants for most input bindings.  *  * Most input bindings include key code, matrix key code format.  * In most cases, key code and matrix key code format uses  * the standard values/macro defined in this header.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_INPUT_INPUT_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_INPUT_INPUT_H
end_define

begin_include
include|#
directive|include
file|"linux-event-codes.h"
end_include

begin_define
define|#
directive|define
name|MATRIX_KEY
parameter_list|(
name|row
parameter_list|,
name|col
parameter_list|,
name|code
parameter_list|)
define|\
value|((((row)& 0xFF)<< 24) | (((col)& 0xFF)<< 16) | ((code)& 0xFFFF))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_INPUT_INPUT_H */
end_comment

end_unit

