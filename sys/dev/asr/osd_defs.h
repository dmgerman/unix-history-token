begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996-1999 Distributed Processing Technology Corporation  * All rights reserved.  *  * Redistribution and use in source form, with or without modification, are  * permitted provided that redistributions of source code must retain the  * above copyright notice, this list of conditions and the following disclaimer.  *  * This software is provided `as is' by Distributed Processing Technology and  * any express or implied warranties, including, but not limited to, the  * implied warranties of merchantability and fitness for a particular purpose,  * are disclaimed. In no event shall Distributed Processing Technology be  * liable for any direct, indirect, incidental, special, exemplary or  * consequential damages (including, but not limited to, procurement of  * substitute goods or services; loss of use, data, or profits; or business  * interruptions) however caused and on any theory of liability, whether in  * contract, strict liability, or tort (including negligence or otherwise)  * arising in any way out of the use of this driver software, even if advised  * of the possibility of such damage.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSD_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|_OSD_DEFS_H
end_define

begin_comment
comment|/*File - OSD_DEFS.H  ****************************************************************************  *  *Description:  *  *	This file contains the OS dependent defines.  This file is included  *in osd_util.h and provides the OS specific defines for that file.  *  *Copyright Distributed Processing Technology, Corp.  *	  140 Candace Dr.  *	  Maitland, Fl.	32751   USA  *	  Phone: (407) 830-5522  Fax: (407) 260-5366  *	  All Rights Reserved  *  *Author:	Doug Anderson  *Date:		1/31/94  *  *Editors:  *  *Remarks:  *  *  *****************************************************************************/
end_comment

begin_comment
comment|/*Definitions - Defines& Constants ----------------------------------------- */
end_comment

begin_comment
comment|/* Define the operating system */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|_DPT_LINUX
end_define

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|)
end_elif

begin_define
define|#
directive|define
name|_DPT_BSDI
end_define

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|)
end_elif

begin_undef
undef|#
directive|undef
name|_DPT_FREE_BSD
end_undef

begin_define
define|#
directive|define
name|_DPT_FREE_BSD
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_DPT_SCO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ZIL_CURSES
argument_list|)
end_if

begin_define
define|#
directive|define
name|_DPT_CURSES
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_DPT_MOTIF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Redefine 'far' to nothing - no far pointer type required in UNIX */
end_comment

begin_define
define|#
directive|define
name|far
end_define

begin_comment
comment|/* Define the mutually exclusive semaphore type */
end_comment

begin_define
define|#
directive|define
name|SEMAPHORE_T
value|unsigned int *
end_define

begin_comment
comment|/* Define a handle to a DLL */
end_comment

begin_define
define|#
directive|define
name|DLL_HANDLE_T
value|unsigned int *
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

