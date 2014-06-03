begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- clang-c/CXString.h - C Index strings  --------------------*- C -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header provides the interface to C Index strings.                     *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CLANG_CXSTRING_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CXSTRING_H
end_define

begin_include
include|#
directive|include
file|"clang-c/Platform.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/**  * \defgroup CINDEX_STRING String manipulation routines  * \ingroup CINDEX  *  * @{  */
comment|/**  * \brief A character string.  *  * The \c CXString type is used to return strings from the interface when  * the ownership of that string might different from one call to the next.  * Use \c clang_getCString() to retrieve the string data and, once finished  * with the string data, call \c clang_disposeString() to free the string.  */
typedef|typedef
struct|struct
block|{
specifier|const
name|void
modifier|*
name|data
decl_stmt|;
name|unsigned
name|private_flags
decl_stmt|;
block|}
name|CXString
typedef|;
comment|/**  * \brief Retrieve the character data associated with the given string.  */
name|CINDEX_LINKAGE
specifier|const
name|char
modifier|*
name|clang_getCString
parameter_list|(
name|CXString
name|string
parameter_list|)
function_decl|;
comment|/**  * \brief Free the given string.  */
name|CINDEX_LINKAGE
name|void
name|clang_disposeString
parameter_list|(
name|CXString
name|string
parameter_list|)
function_decl|;
comment|/**  * @}  */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

