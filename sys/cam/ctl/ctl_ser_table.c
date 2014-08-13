begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Silicon Graphics International Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * $Id: //depot/users/kenm/FreeBSD-test2/sys/cam/ctl/ctl_ser_table.c#1 $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * CAM Target Layer command serialization table.  *  * Author: Kim Le  */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* TABLE       ctlSerTbl                                                    */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/*  The matrix which drives the serialization algorithm. The major index    */
end_comment

begin_comment
comment|/*  (the first) into this table is the command being checked and the minor  */
end_comment

begin_comment
comment|/*  index is the command against which the first command is being checked.  */
end_comment

begin_comment
comment|/*  i.e., the major index (row) command is ahead of the minor index command */
end_comment

begin_comment
comment|/*  (column) in the queue.  This allows the code to optimize by capturing   */
end_comment

begin_comment
comment|/*  the result of the first indexing operation into a pointer.              */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/*  Whenever a new value is added to the IDX_T type, this matrix must be    */
end_comment

begin_comment
comment|/*  expanded by one row AND one column -- Because of this, some effort      */
end_comment

begin_comment
comment|/*  should be made to re-use the indexes whenever possible.                 */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|sK
value|CTL_SER_SKIP
end_define

begin_comment
comment|/* Skip */
end_comment

begin_define
define|#
directive|define
name|pS
value|CTL_SER_PASS
end_define

begin_comment
comment|/* pS */
end_comment

begin_define
define|#
directive|define
name|bK
value|CTL_SER_BLOCK
end_define

begin_comment
comment|/* Blocked */
end_comment

begin_define
define|#
directive|define
name|xT
value|CTL_SER_EXTENT
end_define

begin_comment
comment|/* Extent check */
end_comment

begin_decl_stmt
specifier|static
name|ctl_serialize_action
name|ctl_serialize_table
index|[
name|CTL_SERIDX_COUNT
index|]
index|[
name|CTL_SERIDX_COUNT
index|]
init|=
block|{
comment|/**>IDX_ :: 2nd:TUR RD  WRT UNM MDSN MDSL RQSN INQ RDCP RES LSNS FMT STR*/
comment|/*TUR     */
block|{
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|pS
block|,
name|pS
block|,
name|bK
block|,
name|pS
block|,
name|bK
block|,
name|bK
block|}
block|,
comment|/*READ    */
block|{
name|pS
block|,
name|pS
block|,
name|xT
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|pS
block|,
name|pS
block|,
name|bK
block|,
name|pS
block|,
name|bK
block|,
name|bK
block|}
block|,
comment|/*WRITE   */
block|{
name|pS
block|,
name|xT
block|,
name|xT
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|pS
block|,
name|pS
block|,
name|bK
block|,
name|pS
block|,
name|bK
block|,
name|bK
block|}
block|,
comment|/*UNMAP   */
block|{
name|pS
block|,
name|bK
block|,
name|bK
block|,
name|pS
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|pS
block|,
name|pS
block|,
name|bK
block|,
name|pS
block|,
name|bK
block|,
name|bK
block|}
block|,
comment|/*MD_SNS  */
block|{
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|pS
block|,
name|bK
block|,
name|bK
block|,
name|pS
block|,
name|pS
block|,
name|bK
block|,
name|pS
block|,
name|bK
block|,
name|bK
block|}
block|,
comment|/*MD_SEL  */
block|{
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|pS
block|,
name|pS
block|,
name|bK
block|,
name|pS
block|,
name|bK
block|,
name|bK
block|}
block|,
comment|/*RQ_SNS  */
block|{
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|bK
block|,
name|pS
block|,
name|pS
block|,
name|bK
block|,
name|pS
block|,
name|bK
block|,
name|bK
block|}
block|,
comment|/*INQ     */
block|{
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|bK
block|,
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|bK
block|,
name|bK
block|}
block|,
comment|/*RD_CAP  */
block|{
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|bK
block|,
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|bK
block|,
name|pS
block|}
block|,
comment|/*RES     */
block|{
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|pS
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|}
block|,
comment|/*LOG_SNS */
block|{
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|pS
block|,
name|bK
block|,
name|bK
block|,
name|pS
block|,
name|pS
block|,
name|bK
block|,
name|pS
block|,
name|bK
block|,
name|bK
block|}
block|,
comment|/*FORMAT  */
block|{
name|pS
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|pS
block|,
name|pS
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|}
block|,
comment|/*START   */
block|{
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|pS
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|,
name|bK
block|}
block|, }
decl_stmt|;
end_decl_stmt

end_unit

