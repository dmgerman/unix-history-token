begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *  Turns on byte packing, which is necessary for passing information from  *	system to system over a network to ensure no padding by the compiler has  *	taken place.  */
end_comment

begin_comment
comment|/****h* Component Library/Structure Packing * NAME *	Structure Packing * * DESCRIPTION *	The structure packing header files allow packing structures on byte *	boundaries. * *	Structure packing should be used whenever a structure is transmitted *	between systems, as different platforms pad structures differently if *	they are not packed.  Packing a structure that is not transmitted between *	systems can be detrimental to performance, as fields in the structure may *	not align properly for some platforms. Care must be taken when creating *	packed structures that the alignment rules for all platforms are followed. * *	To pack a structure, include cl_packon.h before defining the structure, and *	include cl_packoff.h after the structure definition.  Multiple structures *	can be packed between the two include statements if desired. * *	The structure definition itself must use the PACK_SUFFIX keyword. * * EXAMPLE *	#include<complib/cl_packon.h> * *	typedef _my_struct_t *	{ *	    uint64 large; *	    uint32 medium; *	    uint16 small; * *	} PACK_SUFFIX my_struct_t; *	#include<complib/cl_packoff.h> *********/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PACK_SUFFIX
end_ifndef

begin_define
define|#
directive|define
name|PACK_SUFFIX
value|__attribute__((packed))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

