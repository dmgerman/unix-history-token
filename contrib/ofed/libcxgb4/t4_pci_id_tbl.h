begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file is part of the Chelsio T4/T5 Ethernet driver for Linux.  *  * Copyright (c) 2003-2014 Chelsio Communications, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__T4_PCI_ID_TBL_H__
end_ifndef

begin_define
define|#
directive|define
name|__T4_PCI_ID_TBL_H__
end_define

begin_comment
comment|/* The code can defined cpp macros for creating a PCI Device ID Table. This is  * useful because it allows the PCI ID Table to be maintained in a single place.  *  * The macros are:  *  * CH_PCI_DEVICE_ID_TABLE_DEFINE_BEGIN  *   -- Used to start the definition of the PCI ID Table.  *  * CH_PCI_DEVICE_ID_FUNCTION  *   -- The PCI Function Number to use in the PCI Device ID Table.  "0"  *   -- for drivers attaching to PF0-3, "4" for drivers attaching to PF4,  *   -- "8" for drivers attaching to SR-IOV Virtual Functions, etc.  *  * CH_PCI_DEVICE_ID_FUNCTION2 [optional]  *   -- If defined, create a PCI Device ID Table with both  *   -- CH_PCI_DEVICE_ID_FUNCTION and CH_PCI_DEVICE_ID_FUNCTION2 populated.  *  * CH_PCI_ID_TABLE_ENTRY(DeviceID)  *   -- Used for the individual PCI Device ID entries.  Note that we will  *   -- be adding a trailing comma (",") after all of the entries (and  *   -- between the pairs of entries if CH_PCI_DEVICE_ID_FUNCTION2 is defined).  *  * CH_PCI_DEVICE_ID_TABLE_DEFINE_END  *   -- Used to finish the definition of the PCI ID Table.  Note that we  *   -- will be adding a trailing semi-colon (";") here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CH_PCI_DEVICE_ID_FUNCTION
end_ifndef

begin_error
error|#
directive|error
error|CH_PCI_DEVICE_ID_FUNCTION not defined!
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CH_PCI_ID_TABLE_ENTRY
end_ifndef

begin_error
error|#
directive|error
error|CH_PCI_ID_TABLE_ENTRY not defined!
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CH_PCI_DEVICE_ID_TABLE_DEFINE_END
end_ifndef

begin_error
error|#
directive|error
error|CH_PCI_DEVICE_ID_TABLE_DEFINE_END not defined!
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* T4 and later ASICs use a PCI Device ID scheme of 0xVFPP where:  *  *   V  = "4" for T4; "5" for T5, etc.  *   F  = "0" for PF 0..3; "4".."7" for PF4..7; and "8" for VFs  *   PP = adapter product designation  *  * We use this consistency in order to create the proper PCI Device IDs  * for the specified CH_PCI_DEVICE_ID_FUNCTION.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CH_PCI_DEVICE_ID_FUNCTION2
end_ifndef

begin_define
define|#
directive|define
name|CH_PCI_ID_TABLE_FENTRY
parameter_list|(
name|devid
parameter_list|)
define|\
value|CH_PCI_ID_TABLE_ENTRY((devid) | \ 			      ((CH_PCI_DEVICE_ID_FUNCTION)<< 8))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CH_PCI_ID_TABLE_FENTRY
parameter_list|(
name|devid
parameter_list|)
define|\
value|CH_PCI_ID_TABLE_ENTRY((devid) | \ 			      ((CH_PCI_DEVICE_ID_FUNCTION)<< 8)), \ 	CH_PCI_ID_TABLE_ENTRY((devid) | \ 			      ((CH_PCI_DEVICE_ID_FUNCTION2)<< 8))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|CH_PCI_DEVICE_ID_TABLE_DEFINE_BEGIN
comment|/* T4 adapters: 	 */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4000
argument_list|)
decl_stmt|,
comment|/* T440-dbg */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4001
argument_list|)
decl_stmt|,
comment|/* T420-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4002
argument_list|)
decl_stmt|,
comment|/* T422-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4003
argument_list|)
decl_stmt|,
comment|/* T440-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4004
argument_list|)
decl_stmt|,
comment|/* T420-bch */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4005
argument_list|)
decl_stmt|,
comment|/* T440-bch */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4006
argument_list|)
decl_stmt|,
comment|/* T440-ch */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4007
argument_list|)
decl_stmt|,
comment|/* T420-so */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4008
argument_list|)
decl_stmt|,
comment|/* T420-cx */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4009
argument_list|)
decl_stmt|,
comment|/* T420-bt */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x400a
argument_list|)
decl_stmt|,
comment|/* T404-bt */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x400b
argument_list|)
decl_stmt|,
comment|/* B420-sr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x400c
argument_list|)
decl_stmt|,
comment|/* B404-bt */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x400d
argument_list|)
decl_stmt|,
comment|/* T480-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x400e
argument_list|)
decl_stmt|,
comment|/* T440-LP-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4080
argument_list|)
decl_stmt|,
comment|/* Custom T480-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4081
argument_list|)
decl_stmt|,
comment|/* Custom T440-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4082
argument_list|)
decl_stmt|,
comment|/* Custom T420-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4083
argument_list|)
decl_stmt|,
comment|/* Custom T420-xaui */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4084
argument_list|)
decl_stmt|,
comment|/* Custom T440-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4085
argument_list|)
decl_stmt|,
comment|/* Custom T420-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4086
argument_list|)
decl_stmt|,
comment|/* Custom T440-bt */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4087
argument_list|)
decl_stmt|,
comment|/* Custom T440-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x4088
argument_list|)
decl_stmt|,
comment|/* Custom T440 2-xaui, 2-xfi */
comment|/* T5 adapters: 	 */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5000
argument_list|)
decl_stmt|,
comment|/* T580-dbg */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5001
argument_list|)
decl_stmt|,
comment|/* T520-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5002
argument_list|)
decl_stmt|,
comment|/* T522-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5003
argument_list|)
decl_stmt|,
comment|/* T540-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5004
argument_list|)
decl_stmt|,
comment|/* T520-bch */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5005
argument_list|)
decl_stmt|,
comment|/* T540-bch */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5006
argument_list|)
decl_stmt|,
comment|/* T540-ch */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5007
argument_list|)
decl_stmt|,
comment|/* T520-so */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5008
argument_list|)
decl_stmt|,
comment|/* T520-cx */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5009
argument_list|)
decl_stmt|,
comment|/* T520-bt */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x500a
argument_list|)
decl_stmt|,
comment|/* T504-bt */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x500b
argument_list|)
decl_stmt|,
comment|/* B520-sr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x500c
argument_list|)
decl_stmt|,
comment|/* B504-bt */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x500d
argument_list|)
decl_stmt|,
comment|/* T580-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x500e
argument_list|)
decl_stmt|,
comment|/* T540-LP-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5010
argument_list|)
decl_stmt|,
comment|/* T580-LP-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5011
argument_list|)
decl_stmt|,
comment|/* T520-LL-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5012
argument_list|)
decl_stmt|,
comment|/* T560-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5013
argument_list|)
decl_stmt|,
comment|/* T580-chr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5014
argument_list|)
decl_stmt|,
comment|/* T580-so */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5015
argument_list|)
decl_stmt|,
comment|/* T502-bt */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5016
argument_list|)
decl_stmt|,
comment|/* T580-OCP-SO */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5017
argument_list|)
decl_stmt|,
comment|/* T520-OCP-SO */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5018
argument_list|)
decl_stmt|,
comment|/* T540-BT */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5080
argument_list|)
decl_stmt|,
comment|/* Custom T540-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5081
argument_list|)
decl_stmt|,
comment|/* Custom T540-LL-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5082
argument_list|)
decl_stmt|,
comment|/* Custom T504-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5083
argument_list|)
decl_stmt|,
comment|/* Custom T540-LP-CR */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5084
argument_list|)
decl_stmt|,
comment|/* Custom T580-cr */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5085
argument_list|)
decl_stmt|,
comment|/* Custom 3x T580-CR */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5086
argument_list|)
decl_stmt|,
comment|/* Custom 2x T580-CR */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5087
argument_list|)
decl_stmt|,
comment|/* Custom T580-CR */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5088
argument_list|)
decl_stmt|,
comment|/* Custom T570-CR */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5089
argument_list|)
decl_stmt|,
comment|/* Custom T520-CR */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5090
argument_list|)
decl_stmt|,
comment|/* Custom T540-CR */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5091
argument_list|)
decl_stmt|,
comment|/* Custom T522-CR */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5092
argument_list|)
decl_stmt|,
comment|/* Custom T520-CR */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5093
argument_list|)
decl_stmt|,
comment|/* Custom T580-LP-CR */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5094
argument_list|)
decl_stmt|,
comment|/* Custom T540-CR */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5095
argument_list|)
decl_stmt|,
comment|/* Custom T540-CR-SO */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5096
argument_list|)
decl_stmt|,
comment|/* Custom T580-CR */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5097
argument_list|)
decl_stmt|,
comment|/* Custom T520-KR */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5098
argument_list|)
decl_stmt|,
comment|/* Custom 2x40G QSFP */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x5099
argument_list|)
decl_stmt|,
comment|/* Custom 2x40G QSFP */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x509a
argument_list|)
decl_stmt|,
comment|/* Custom T520-CR */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x509b
argument_list|)
decl_stmt|,
comment|/* Custom T540-CR LOM */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x509c
argument_list|)
decl_stmt|,
comment|/* Custom T520-CR*/
comment|/* T6 adapters: 	 */
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x6001
argument_list|)
decl_stmt|,
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x6002
argument_list|)
decl_stmt|,
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x6003
argument_list|)
decl_stmt|,
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x6004
argument_list|)
decl_stmt|,
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x6005
argument_list|)
decl_stmt|,
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x6006
argument_list|)
decl_stmt|,
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x6007
argument_list|)
decl_stmt|,
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x6009
argument_list|)
decl_stmt|,
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x600d
argument_list|)
decl_stmt|,
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x6010
argument_list|)
decl_stmt|,
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x6011
argument_list|)
decl_stmt|,
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x6014
argument_list|)
decl_stmt|,
name|CH_PCI_ID_TABLE_FENTRY
argument_list|(
literal|0x6015
argument_list|)
decl_stmt|,
name|CH_PCI_DEVICE_ID_TABLE_DEFINE_END
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __T4_PCI_ID_TBL_H__ */
end_comment

end_unit

