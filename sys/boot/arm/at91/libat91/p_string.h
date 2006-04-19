begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Filename: p_string.h  *  * Definition of basic, private, string operations to prevent inclusion of full  *  * Revision information:  *  * 20AUG2004	kb_admin	initial creation  *  * BEGIN_KBDD_BLOCK  * No warranty, expressed or implied, is included with this software.  It is  * provided "AS IS" and no warranty of any kind including statutory or aspects  * relating to merchantability or fitness for any purpose is provided.  All  * intellectual property rights of others is maintained with the respective  * owners.  This software is not copyrighted and is intended for reference  * only.  * END_BLOCK  *  * $FreeBSD$  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_P_STRING_H_
end_ifndef

begin_define
define|#
directive|define
name|_P_STRING_H_
end_define

begin_define
define|#
directive|define
name|ToASCII
parameter_list|(
name|x
parameter_list|)
value|((x> 9) ? (x + 'A' - 0xa) : (x + '0'))
end_define

begin_function_decl
name|int
name|p_IsWhiteSpace
parameter_list|(
name|char
name|cValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|p_HexCharValue
parameter_list|(
name|char
name|cValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|p_memset
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|char
name|value
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p_strlen
parameter_list|(
specifier|const
name|char
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|p_strcpy
parameter_list|(
name|char
modifier|*
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|p_ASCIIToHex
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|p_ASCIIToDec
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|p_memcpy
parameter_list|(
name|char
modifier|*
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|,
name|unsigned
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p_memcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|,
name|unsigned
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p_strcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _P_STRING_H_ */
end_comment

end_unit

