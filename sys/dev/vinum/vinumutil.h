begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999  *	Nan Yang Computer Services Limited.  All rights reserved.  *  *  Written by Greg Lehey  *  *  This software is distributed under the so-called ``Berkeley  *  License'':  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Nan Yang Computer  *      Services Limited.  * 4. Neither the name of the Company nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * This software is provided ``as is'', and any express or implied  * warranties, including, but not limited to, the implied warranties of  * merchantability and fitness for a particular purpose are disclaimed.  * In no event shall the company or contributors be liable for any  * direct, indirect, incidental, special, exemplary, or consequential  * damages (including, but not limited to, procurement of substitute  * goods or services; loss of use, data, or profits; or business  * interruption) however caused and on any theory of liability, whether  * in contract, strict liability, or tort (including negligence or  * otherwise) arising in any way out of the use of this software, even if  * advised of the possibility of such damage.  *  * $Id: vinumutil.h,v 1.1 2001/05/22 04:07:22 grog Exp grog $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Functions defined in vinumutil.c, which is used both in userland  * and in the kernel.  */
end_comment

begin_function_decl
name|char
modifier|*
name|drive_state
parameter_list|(
name|enum
name|drivestate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|volume_state
parameter_list|(
name|enum
name|volumestate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|plex_state
parameter_list|(
name|enum
name|plexstate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|plex_org
parameter_list|(
name|enum
name|plexorg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|sd_state
parameter_list|(
name|enum
name|sdstate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|drivestate
name|DriveState
parameter_list|(
name|char
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|sdstate
name|SdState
parameter_list|(
name|char
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|plexstate
name|PlexState
parameter_list|(
name|char
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|volumestate
name|VolState
parameter_list|(
name|char
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

end_unit

