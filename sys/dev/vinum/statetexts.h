begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Created by ./makestatetext on Wed Jan 5 10:05:30 CST 2000. Do not edit */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997, 1998  *	Nan Yang Computer Services Limited.  All rights reserved.  *  *  This software is distributed under the so-called ``Berkeley  *  License'':  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Nan Yang Computer  *      Services Limited.  * 4. Neither the name of the Company nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * This software is provided ``as is'', and any express or implied  * warranties, including, but not limited to, the implied warranties of  * merchantability and fitness for a particular purpose are disclaimed.  * In no event shall the company or contributors be liable for any  * direct, indirect, incidental, special, exemplary, or consequential  * damages (including, but not limited to, procurement of substitute  * goods or services; loss of use, data, or profits; or business  * interruption) however caused and on any theory of liability, whether  * in contract, strict liability, or tort (including negligence or  * otherwise) arising in any way out of the use of this software, even if  * advised of the possibility of such damage.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Drive state texts */
end_comment

begin_decl_stmt
name|char
modifier|*
name|drivestatetext
index|[]
init|=
block|{
literal|"unallocated"
block|,
literal|"referenced"
block|,
literal|"down"
block|,
literal|"up"
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Subdisk state texts */
end_comment

begin_decl_stmt
name|char
modifier|*
name|sdstatetext
index|[]
init|=
block|{
literal|"unallocated"
block|,
literal|"uninit"
block|,
literal|"referenced"
block|,
literal|"init"
block|,
literal|"empty"
block|,
literal|"initializing"
block|,
literal|"initialized"
block|,
literal|"obsolete"
block|,
literal|"stale"
block|,
literal|"crashed"
block|,
literal|"down"
block|,
literal|"reviving"
block|,
literal|"reborn"
block|,
literal|"up"
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Plex state texts */
end_comment

begin_decl_stmt
name|char
modifier|*
name|plexstatetext
index|[]
init|=
block|{
literal|"unallocated"
block|,
literal|"referenced"
block|,
literal|"init"
block|,
literal|"faulty"
block|,
literal|"down"
block|,
literal|"initializing"
block|,
literal|"corrupt"
block|,
literal|"degraded"
block|,
literal|"flaky"
block|,
literal|"up"
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Volume state texts */
end_comment

begin_decl_stmt
name|char
modifier|*
name|volstatetext
index|[]
init|=
block|{
literal|"unallocated"
block|,
literal|"uninit"
block|,
literal|"down"
block|,
literal|"up"
block|, }
decl_stmt|;
end_decl_stmt

end_unit

