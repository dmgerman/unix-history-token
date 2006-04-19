begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Filename: tag_list.h  *  * Definition of basic routines that create linux-boot tag list.  *  * Revision information:  *  * 22AUG2004	kb_admin	initial creation  *  * BEGIN_KBDD_BLOCK  * No warranty, expressed or implied, is included with this software.  It is  * provided "AS IS" and no warranty of any kind including statutory or aspects  * relating to merchantability or fitness for any purpose is provided.  All  * intellectual property rights of others is maintained with the respective  * owners.  This software is not copyrighted and is intended for reference  * only.  * END_BLOCK  *  * $FreeBSD$  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TAG_LIST_H_
end_ifndef

begin_define
define|#
directive|define
name|_TAG_LIST_H_
end_define

begin_function_decl
specifier|extern
name|void
name|InitTagList
parameter_list|(
name|char
modifier|*
name|parms
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TAG_LIST_H_ */
end_comment

end_unit

