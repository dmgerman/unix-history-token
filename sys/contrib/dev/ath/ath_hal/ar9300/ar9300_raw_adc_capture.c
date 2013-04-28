begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Qualcomm Atheros, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR  * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2002-2009 Atheros Communications, Inc.   * All Rights Reserved.  *   * Copyright (c) 2011 Qualcomm Atheros, Inc.  * All Rights Reserved.  * Qualcomm Atheros Confidential and Proprietary.  *   */
end_comment

begin_include
include|#
directive|include
file|"opt_ah.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|AH_SUPPORT_AR9300
end_ifdef

begin_include
include|#
directive|include
file|"ah.h"
end_include

begin_include
include|#
directive|include
file|"ah_desc.h"
end_include

begin_include
include|#
directive|include
file|"ah_internal.h"
end_include

begin_include
include|#
directive|include
file|"ar9300/ar9300phy.h"
end_include

begin_include
include|#
directive|include
file|"ar9300/ar9300.h"
end_include

begin_include
include|#
directive|include
file|"ar9300/ar9300reg.h"
end_include

begin_include
include|#
directive|include
file|"ar9300/ar9300desc.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Raw capture mode not enabled - insert dummy code to keep the compiler happy  */
end_comment

begin_typedef
typedef|typedef
name|int
name|ar9300_dummy_adc_capture
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AH_SUPPORT_AR9300*/
end_comment

end_unit

