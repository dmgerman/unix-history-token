begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file is part of the Chelsio T4 Ethernet driver for Linux.  *  * Copyright (c) 2003-2015 Chelsio Communications, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__T4_CHIP_TYPE_H__
end_ifndef

begin_define
define|#
directive|define
name|__T4_CHIP_TYPE_H__
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4
value|0x4
end_define

begin_define
define|#
directive|define
name|CHELSIO_T5
value|0x5
end_define

begin_define
define|#
directive|define
name|CHELSIO_T6
value|0x6
end_define

begin_comment
comment|/* We code the Chelsio T4 Family "Chip Code" as a tuple:  *  *     (Chip Version, Chip Revision)  *  * where:  *  *     Chip Version: is T4, T5, etc.  *     Chip Revision: is the FAB "spin" of the Chip Version.  */
end_comment

begin_define
define|#
directive|define
name|CHELSIO_CHIP_CODE
parameter_list|(
name|version
parameter_list|,
name|revision
parameter_list|)
value|(((version)<< 4) | (revision))
end_define

begin_define
define|#
directive|define
name|CHELSIO_CHIP_VERSION
parameter_list|(
name|code
parameter_list|)
value|(((code)>> 4)& 0xf)
end_define

begin_define
define|#
directive|define
name|CHELSIO_CHIP_RELEASE
parameter_list|(
name|code
parameter_list|)
value|((code)& 0xf)
end_define

begin_enum
enum|enum
name|chip_type
block|{
name|T4_A1
init|=
name|CHELSIO_CHIP_CODE
argument_list|(
name|CHELSIO_T4
argument_list|,
literal|1
argument_list|)
block|,
name|T4_A2
init|=
name|CHELSIO_CHIP_CODE
argument_list|(
name|CHELSIO_T4
argument_list|,
literal|2
argument_list|)
block|,
name|T4_FIRST_REV
init|=
name|T4_A1
block|,
name|T4_LAST_REV
init|=
name|T4_A2
block|,
name|T5_A0
init|=
name|CHELSIO_CHIP_CODE
argument_list|(
name|CHELSIO_T5
argument_list|,
literal|0
argument_list|)
block|,
name|T5_A1
init|=
name|CHELSIO_CHIP_CODE
argument_list|(
name|CHELSIO_T5
argument_list|,
literal|1
argument_list|)
block|,
name|T5_FIRST_REV
init|=
name|T5_A0
block|,
name|T5_LAST_REV
init|=
name|T5_A1
block|,
name|T6_A0
init|=
name|CHELSIO_CHIP_CODE
argument_list|(
name|CHELSIO_T6
argument_list|,
literal|0
argument_list|)
block|,
name|T6_FIRST_REV
init|=
name|T6_A0
block|,
name|T6_LAST_REV
init|=
name|T6_A0
block|, }
enum|;
end_enum

begin_function
specifier|static
specifier|inline
name|int
name|is_t4
parameter_list|(
name|enum
name|chip_type
name|chip
parameter_list|)
block|{
return|return
operator|(
name|CHELSIO_CHIP_VERSION
argument_list|(
name|chip
argument_list|)
operator|==
name|CHELSIO_T4
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|is_t5
parameter_list|(
name|enum
name|chip_type
name|chip
parameter_list|)
block|{
return|return
operator|(
name|CHELSIO_CHIP_VERSION
argument_list|(
name|chip
argument_list|)
operator|==
name|CHELSIO_T5
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|is_t6
parameter_list|(
name|enum
name|chip_type
name|chip
parameter_list|)
block|{
return|return
operator|(
name|CHELSIO_CHIP_VERSION
argument_list|(
name|chip
argument_list|)
operator|==
name|CHELSIO_T6
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __T4_CHIP_TYPE_H__ */
end_comment

end_unit

