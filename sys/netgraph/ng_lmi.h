begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_lmi.h  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@freebsd.org>  *  * $FreeBSD$  * $Whistle: ng_lmi.h,v 1.9 1999/01/20 00:22:13 archie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_LMI_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_LMI_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_LMI_NODE_TYPE
value|"lmi"
end_define

begin_define
define|#
directive|define
name|NGM_LMI_COOKIE
value|867184133
end_define

begin_comment
comment|/* My hook names */
end_comment

begin_define
define|#
directive|define
name|NG_LMI_HOOK_DEBUG
value|"debug"
end_define

begin_define
define|#
directive|define
name|NG_LMI_HOOK_ANNEXA
value|"annexA"
end_define

begin_define
define|#
directive|define
name|NG_LMI_HOOK_ANNEXD
value|"annexD"
end_define

begin_define
define|#
directive|define
name|NG_LMI_HOOK_GROUPOF4
value|"group4"
end_define

begin_define
define|#
directive|define
name|NG_LMI_HOOK_AUTO0
value|"auto0"
end_define

begin_define
define|#
directive|define
name|NG_LMI_HOOK_AUTO1023
value|"auto1023"
end_define

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_LMI_GET_STATUS
init|=
literal|1
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|NGM_LMI_STAT_ARYSIZE
value|(1024/8)
end_define

begin_struct
struct|struct
name|nglmistat
block|{
name|u_char
name|proto
index|[
literal|12
index|]
decl_stmt|;
comment|/* Active proto (same as hook name) */
name|u_char
name|hook
index|[
literal|12
index|]
decl_stmt|;
comment|/* Active hook */
name|u_char
name|fixed
decl_stmt|;
comment|/* Set to fixed LMI mode */
name|u_char
name|autod
decl_stmt|;
comment|/* Currently auto-detecting */
name|u_char
name|seen
index|[
name|NGM_LMI_STAT_ARYSIZE
index|]
decl_stmt|;
comment|/* DLCIs ever seen */
name|u_char
name|up
index|[
name|NGM_LMI_STAT_ARYSIZE
index|]
decl_stmt|;
comment|/* DLCIs currently up */
block|}
struct|;
end_struct

begin_comment
comment|/* Some default values */
end_comment

begin_define
define|#
directive|define
name|NG_LMI_KEEPALIVE_RATE
value|10
end_define

begin_comment
comment|/* seconds per keepalive */
end_comment

begin_define
define|#
directive|define
name|NG_LMI_POLL_RATE
value|3
end_define

begin_comment
comment|/* faster when AUTO polling */
end_comment

begin_define
define|#
directive|define
name|NG_LMI_SEQ_PER_FULL
value|5
end_define

begin_comment
comment|/* keepalives per full status */
end_comment

begin_define
define|#
directive|define
name|NG_LMI_LMI_PRIORITY
value|64
end_define

begin_comment
comment|/* priority for LMI data */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_LMI_H_ */
end_comment

end_unit

